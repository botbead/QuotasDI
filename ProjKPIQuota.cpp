// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ProjKPIQuota.h"
#include "MainModule.h"
#include <map>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniBasicGrid"
#pragma link "uniButton"
#pragma link "uniDBGrid"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniLabel"
#pragma link "uniDBNavigator"
#pragma resource "*.dfm"
extern std::map<UnicodeString, double>eq_map;

// ---------------------------------------------------------------------------
__fastcall TUniForm2::TUniForm2(TComponent* Owner) : TUniForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm2::UniButton1Click(TObject *Sender) {
	this->Close();
}
// ---------------------------------------------------------------------------

void __fastcall TUniForm2::UniFormShow(TObject *Sender) {
	int rcd_num;
	double total_pay_for_performance, temp_pay_for_performance;
	UnicodeString projno, task, emp;
	std::map<UnicodeString, double>::iterator eq_map_iter;
	double task_quota, emp_quota, emp_single_item_quota;
	UniLabel1->Caption = "工程序号：" + crtProj;
	total_pay_for_performance = 0;
	temp_pay_for_performance = 0;
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		try {
			UniMainModule()->uniq_sum_quotas->SQL->Clear();
			UniMainModule()->uniq_sum_quotas->SQL->Add
				(Sysutils::Format
				("SELECT * FROM quotas_sum WHERE projNo = '%s';",
				ARRAYOFCONST((crtProj))));
			UniMainModule()->uniq_sum_quotas->Execute();

			// UniMainModule()->uniq_sum_quotas->SQL->Clear();
			// UniMainModule()->uniq_sum_quotas->SQL->Add
			// ("DELETE FROM quotas_sum;");
			// UniMainModule()->uniq_sum_quotas->Execute();

			if (UniMainModule()->uniq_sum_quotas->RecordCount);
			else {
				UniMainModule()->UniQuery1->SQL->Clear();
				UniMainModule()->UniQuery1->SQL->Add
					(Sysutils::Format
					("SELECT * FROM proj_info WHERE projNo = '%s';",
					ARRAYOFCONST((crtProj))));
				UniMainModule()->UniQuery1->Execute();
				total_pay_for_performance =
					UniMainModule()->UniQuery1->FieldByName
					("pay_for_performance")->AsFloat;

				UniMainModule()->UniQuery1->SQL->Clear();
				UniMainModule()->UniQuery1->SQL->Add
					(Sysutils::Format
					("SELECT * FROM quotas_info WHERE projNo = '%s';",
					ARRAYOFCONST((crtProj))));
				UniMainModule()->UniQuery1->Execute();
				rcd_num = UniMainModule()->UniQuery1->RecordCount;
				while (rcd_num) {
					// projno =
					projno = UniMainModule()->UniQuery1->FieldByName("projNo")
						->AsString;
					task = UniMainModule()->UniQuery1->FieldByName("task")
						->AsString;
					emp = UniMainModule()->UniQuery1->FieldByName("employee")
						->AsString;
					emp_quota = UniMainModule()->UniQuery1->FieldByName
						("work_employee_quota")->AsFloat;
					UniMainModule()->UniQuery2->SQL->Clear();
					UniMainModule()->UniQuery2->SQL->Add
						(Sysutils::Format
						("SELECT * FROM tasks_info WHERE projNo = '%s' AND task = '%s';",
						ARRAYOFCONST((crtProj, task))));
					UniMainModule()->UniQuery2->Execute();
					task_quota = UniMainModule()->UniQuery2->FieldByName
						("task_quota")->AsFloat;
					emp_single_item_quota = (emp_quota / 100) * task_quota;
					eq_map_iter = eq_map.find(emp);
					if (eq_map_iter != eq_map.end()) {
						eq_map_iter->second += emp_single_item_quota;
					}
					else {
						eq_map.insert(std::pair<UnicodeString, double>(emp,
							emp_single_item_quota));
					}
					UniMainModule()->UniQuery1->Next();
					rcd_num--;
				}
				UniMainModule()->UniQuery1->SQL->Clear();

				for (eq_map_iter = eq_map.begin(); eq_map_iter != eq_map.end();
				++eq_map_iter) {
					temp_pay_for_performance =
						total_pay_for_performance * (eq_map_iter->second / 100);
					UniMainModule()->UniQuery1->SQL->Add
						(Sysutils::Format
						("INSERT INTO quotas_sum (projNo, employee, employee_quota_sum, pay_for_performance) VALUES('%s', '%s', %20.9f, %20.4f);",
						ARRAYOFCONST((crtProj, eq_map_iter->first,
						eq_map_iter->second, temp_pay_for_performance))));
				}
				UniMainModule()->UniQuery1->Execute();
				UniMainModule()->uniq_sum_quotas->SQL->Clear();
				UniMainModule()->uniq_sum_quotas->SQL->Add
					(Sysutils::Format
					("SELECT * FROM quotas_sum WHERE projNo = '%s';",
					ARRAYOFCONST((crtProj))));
				UniMainModule()->uniq_sum_quotas->Execute();
			}

			UniMainModule()->UniConnection1->Commit();
			eq_map.clear();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm2::UniDBGrid1ColumnSummaryResult
	(TUniDBGridColumn *Column, Variant &GroupFieldValue,
	TUniCellAttribs *Attribs, UnicodeString &Result) {
	Attribs->Font->Style = Attribs->Font->Style << fsBold;
	Attribs->Font->Size = 11;
	if (!Sysutils::SameText(Column->FieldName, UnicodeString("employee"))) {
		Attribs->Font->Color = clRed;
		Result = VarToStr(Column->AuxValue);
	}
	else {
		Attribs->Font->Color = clBlue;
		Result = "总计";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TUniForm2::UniDBGrid1ColumnSummary(TUniDBGridColumn *Column,
	Variant &GroupFieldValue) {
	if (!Sysutils::SameText(Column->FieldName, UnicodeString("employee"))) {
		if (VarIsNull(Column->AuxValue)) {
			Column->AuxValue = 0.0;
		}
		Column->AuxValue = Column->AuxValue + Column->Field->AsFloat;
	}
}
// ---------------------------------------------------------------------------
