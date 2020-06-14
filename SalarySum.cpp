// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SalarySum.h"
#include "MainModule.h"
#include <map>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniBasicGrid"
#pragma link "uniDBGrid"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniDBNavigator"
#pragma link "uniButton"
#pragma link "uniBasicGrid"
#pragma link "uniButton"
#pragma link "uniDBGrid"
#pragma link "uniDBNavigator"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma resource "*.dfm"
std::map<UnicodeString, double>e_s_map;
std::map<UnicodeString, int>e_c_map;
std::map<UnicodeString, col_sum>e_c_map2;

// ---------------------------------------------------------------------------
__fastcall TUniForm3::TUniForm3(TComponent* Owner) : TUniForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm3::UniFormShow(TObject *Sender) {
	//
	// TUniBaseDBGridColumn* x= UniDBGrid1->Columns->Add();
	// x->Title->Caption = "你好";
	// ShowMessage(x->Index);
	int i, j, insert_flag = 0;
	TUniBaseDBGridColumn* one_column = 0;
	double proj_total_pay_amount, employee_pay_amount, employee_extra_reward;
	UnicodeString proj_no, employee_name;
	std::map<UnicodeString, double>::iterator e_s_map_iter;
	std::map<UnicodeString, int>::iterator e_c_map_iter;
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		try {
			UniMainModule()->UniQuery1->SQL->Clear();
			UniMainModule()->UniQuery1->SQL->Add("DELETE FROM salaries_sum");
			UniMainModule()->UniQuery1->Execute();

			UniMainModule()->UniQuery1->SQL->Clear();
			UniMainModule()->UniQuery1->SQL->Add
				("SELECT projNo, pay_for_performance FROM proj_info");
			UniMainModule()->UniQuery1->Execute();
			i = 0;
			while (i < UniMainModule()->UniQuery1->RecordCount) {
				proj_no = UniMainModule()->UniQuery1->FieldByName("projNo")
					->AsString;
				proj_total_pay_amount = UniMainModule()->UniQuery1->FieldByName
					("pay_for_performance")->AsFloat;

				UniMainModule()->uniq_salary_sum->SQL->Clear();
				UniMainModule()->uniq_salary_sum->SQL->Add
					(Sysutils::Format
					("INSERT INTO salaries_sum (projNo, amount) VALUES('%s', %20.9f);",
					ARRAYOFCONST((proj_no, proj_total_pay_amount))));
				UniMainModule()->uniq_salary_sum->Execute();

				UniMainModule()->UniQuery2->SQL->Clear();
				UniMainModule()->UniQuery2->SQL->Add
					(Sysutils::Format
					("SELECT employee,pay_for_performance,extra_reward FROM quotas_sum WHERE projNo = '%s';",
					ARRAYOFCONST((proj_no))));
				UniMainModule()->UniQuery2->Execute();
				j = 0;
				while (j < UniMainModule()->UniQuery2->RecordCount) {
					employee_name = UniMainModule()->UniQuery2->FieldByName
						("employee")->AsString;
					employee_pay_amount =
						UniMainModule()->UniQuery2->FieldByName
						("pay_for_performance")->AsFloat;
					if (UniMainModule()->UniQuery2->FieldByName("extra_reward")
						->IsNull) {
						employee_extra_reward = 0.0;
					}
					else {
						employee_extra_reward =
							UniMainModule()->UniQuery2->FieldByName
							("extra_reward")->AsFloat;
					}
					e_s_map_iter = e_s_map.find(employee_name);
					if (e_s_map_iter != e_s_map.end());
					else {
						e_s_map.insert
							(std::pair<UnicodeString, double>(employee_name,
							employee_pay_amount + employee_extra_reward));

						e_c_map_iter = e_c_map.find(employee_name);
						if (e_c_map_iter != e_c_map.end());
						else {
							one_column = UniDBGrid1->Columns->Add();
							one_column->Title->Caption = employee_name;
							one_column->Width = 110;
							one_column->FieldName =
								"employee_salary" +
								IntToStr((int)one_column->Index - 2);
							one_column->ReadOnly = true;
							one_column->ShowSummary = true;
							e_c_map.insert
								(std::pair<UnicodeString, int>(employee_name,
								one_column->Index));
						}
					}
					UniMainModule()->UniQuery2->Next();
					j++;
				}

				// UniDBGrid1->Columns->operator [](1)->FieldName;
				UnicodeString e;
				int ii;
				UniMainModule()->uniq_salary_sum->SQL->Clear();
				for (std::map<UnicodeString, double>::iterator it =
					e_s_map.begin(); it != e_s_map.end(); ++it) {
					e = it->first;
					e_c_map_iter = e_c_map.find(e);
					if (e_c_map_iter != e_c_map.end()) {
						ii = e_c_map_iter->second;
						one_column = UniDBGrid1->Columns->operator[](ii);
						e = one_column->FieldName;

						UniMainModule()->uniq_salary_sum->SQL->Add
							(Sysutils::Format
							("update salaries_sum set %s = %20.9f where projNo = '%s';",
							ARRAYOFCONST((e, it->second, proj_no))));
					}
				}
				UniMainModule()->uniq_salary_sum->Execute();
				e_s_map.clear();
				UniMainModule()->UniQuery1->Next();
				i++;
			}
			UniMainModule()->uniq_salary_sum->SQL->Clear();
			UniMainModule()->uniq_salary_sum->SQL->Add
				("SELECT * FROM salaries_sum");
			UniMainModule()->uniq_salary_sum->Execute();
			UniMainModule()->UniConnection1->Commit();
			e_c_map.clear();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm3::UniButton1Click(TObject *Sender) {
	this->Close();
}
// ---------------------------------------------------------------------------

void __fastcall TUniForm3::UniDBGrid1ColumnSummary(TUniDBGridColumn *Column,
	Variant &GroupFieldValue)

{
	if (!Sysutils::SameText(Column->FieldName, UnicodeString("projNo"))) {
		if (VarIsNull(Column->AuxValue)) {
			Column->AuxValue = 0.0;
		}
		Column->AuxValue = Column->AuxValue + Column->Field->AsFloat;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TUniForm3::UniDBGrid1ColumnSummaryResult
	(TUniDBGridColumn *Column, Variant &GroupFieldValue,
	TUniCellAttribs *Attribs, UnicodeString &Result)

{
	int col;
	col_sum cs;
	UnicodeString title_name;

	std::map<UnicodeString, col_sum>::iterator e_c_map_iter2;
	Attribs->Font->Style = Attribs->Font->Style << fsBold;
	Attribs->Font->Size = 11;
	if (!Sysutils::SameText(Column->FieldName, UnicodeString("projNo"))) {
		Attribs->Font->Color = clRed;
		Result = VarToStr(Column->AuxValue);
		title_name = Column->Title->Caption;

		e_c_map_iter2 = e_c_map2.find(title_name);
		if (e_c_map_iter2 != e_c_map2.end());
		else {
			cs.sum.SetLength(0);
			cs.sum.operator += (Result);
			cs.col = Column->Index;
			e_c_map2.insert(std::pair<UnicodeString, col_sum>(title_name, cs));
		}
	}
	else {
		Attribs->Font->Color = clBlue;
		Result = "合计";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TUniForm3::UniFormCreate(TObject *Sender) {
	UniDBGrid1->Summary->Enabled = true;
	// SaveDialog1->DefaultExt = "xlsx";
	// SaveDialog1->Filter = "表格文件(*.xlsx)|*.xlsx|表格文件(*.xls)|*.xls|所有文件(*.*)|*.*";
}

// ---------------------------------------------------------------------------

void __fastcall TUniForm3::UniButton2Click(TObject *Sender) {
	//
	int row, col, i;
	__int64 crt_ts;
	col_sum cs;
	UnicodeString xls_file_name;
	TExcelFile *xls = new TXlsFile(true);
	xls->NewFile(1);
	row = 1;
	col = 0;
	while (col < UniDBGrid1->Columns->Count) {
		xls->SetCellValue(row, col + 1,
			TCellValue::Create(UniDBGrid1->Columns->operator[](col)
			->Title->Caption));
		col++;
	}
	row = 2;
	UniMainModule()->uniq_salary_sum->First();
	i = 0;
	while (i < UniMainModule()->uniq_salary_sum->RecordCount) {
		col = 1;
		// while (col <= UniMainModule()->uniq_salary_sum->FieldCount) {
		while (col <= UniDBGrid1->Columns->Count) {
			if (1 != col) {
				xls->SetCellValue(row, col,
					TCellValue::Create
					(UniMainModule()->uniq_salary_sum->Fields->FieldByNumber
					(col)->AsFloat));
			}
			else {
				xls->SetCellValue(row, col,
					TCellValue::Create
					(UniMainModule()->uniq_salary_sum->Fields->FieldByNumber
					(col)->AsString));
			}

			col++;
		}
		UniMainModule()->uniq_salary_sum->Next();
		row++;
		i++;
	}
	// UniDBGrid1->

	row += 1;
	for (std::map<UnicodeString, col_sum>::iterator it = e_c_map2.begin();
	it != e_c_map2.end(); ++it) {
		cs = it->second;
		xls->SetCellValue(row, cs.col + 1,
			TCellValue::Create(cs.sum.ToDouble()));
	}
	xls->SetCellValue(row, 1, TCellValue::Create(UnicodeString("合计")));
	e_c_map2.clear();

	DateSeparator = '-';
	TimeSeparator = '-';
	// crt_ts = System::Dateutils::DateTimeToUnix(Now());
	// xls_file_name = dir_name + "\\" + IntToStr((__int64)crt_ts) + ".xlsx";
	xls_file_name = dir_name + "\\" + "绩效" + DateTimeToStr(Now()) + ".xlsx";
	xls->Save(xls_file_name);
	UniSession->SendFile(xls_file_name);
}
// ---------------------------------------------------------------------------
