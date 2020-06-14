// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "NewProj.h"
#include "MainModule.h"
#include "Main.h"
#include "ProjInfoFrame.h"
#include <System.DateUtils.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniEdit"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniLabel"
#pragma link "uniButton"
#pragma link "uniBasicGrid"
#pragma link "uniDBGrid"
#pragma resource "*.dfm"

// ---------------------------------------------------------------------------
__fastcall TUniForm1::TUniForm1(TComponent* Owner) : TUniForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm1::UniButton1Click(TObject *Sender) {

	TMainForm * mainform = 0;
	TUniTreeNode *treenode = 0;
	TUniTabSheet * tabsheet;
	TUniPageControl *pagecontrol;
	TUniFrame1 *projframe;
	double amount_money = UniEdit5->Text.ToDouble();
	__int64 crt_ts;
	UnicodeString sheet_name("");
	UnicodeString temp_str("");
	//sheet_name = "Sheet" + frameNo;
	//frameNo++;
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		UniMainModule()->UniQuery1->SQL->Clear();
		crt_ts = System::Dateutils::DateTimeToUnix(Now());
		temp_str = "proj_" + IntToStr(crt_ts);
		UniMainModule()->UniQuery1->SQL->Add(Sysutils::Format("INSERT INTO proj_info (projNo, blueprintNo, stage, achievement, amount) \
			VALUES ('%s','%s', '%s', '%s',  %20.9f);",
			ARRAYOFCONST((UniEdit1->Text, UniEdit2->Text, UniEdit3->Text,
			UniEdit4->Text, amount_money))));
		UniMainModule()->uniq_proj_task->SQL->Clear();
		/*
		 UniMainModule()->uniq_proj_task->SQL->Add
		 (Sysutils::Format
		 ("INSERT INTO %s (SerialNo, task, proportion) VALUES (%u,'%s', %u);"
		 , ARRAYOFCONST((temp_str, 3, "gogod", 30)))

		 );

		 */
		UniMainModule()->uniq_proj_task->SQL->Add("select * from tasks_info;");
		try {
			UniMainModule()->UniQuery1->Execute();
			UniMainModule()->uniq_proj_task->Execute();
			// UniMainModule()->UniConnection1->Commit();
			mainform = MainForm();
			treenode = mainform->UniTreeView1->Items->AddChild
				(mainform->UniTreeView1->Items->operator[](0), UniEdit1->Text);
			if (mainform->UniTreeView1->Items->operator[](0)->Expanded);
			else
				mainform->UniTreeView1->Items->operator[](0)->Expand(true);

			treenode->Selected = true;
			pagecontrol = mainform->UniPageControl1;

			tabsheet = (TUniTabSheet*)pagecontrol->FindChildControl(sheet_name);
			if (tabsheet);
			else {

				tabsheet = new TUniTabSheet(pagecontrol);
				tabsheet->PageControl = pagecontrol;
				tabsheet->Name = sheet_name;
				tabsheet->Caption = UniEdit1->Text;
				tabsheet->Closable = true;
				tabsheet->AlignmentControl = uniAlignmentClient;
				tabsheet->Layout = "fit";
				// tabsheet->Alignment = alClient;
				pagecontrol->ActivePage = tabsheet;
				projframe = new TUniFrame1(tabsheet);
				projframe->Parent = tabsheet;
				sheet_name =
					Sysutils::Format
					("SELECT * FROM proj_info WHERE projNo = '%s';",
					ARRAYOFCONST((UniEdit1->Text)));

				UniMainModule()->uniq_proj_info->SQL->Clear();
				UniMainModule()->uniq_proj_info->SQL->Add(sheet_name);

				UniMainModule()->uniq_proj_info->Execute();
				UniMainModule()->UniConnection1->Commit();

				if (1 != UniMainModule()->uniq_proj_info->RecordCount);
				else {

					projframe->UniEdit1->Text =
						UniMainModule()->uniq_proj_info->FieldByName("projNo")
						->AsString;
					projframe->UniEdit2->Text =
						UniMainModule()->uniq_proj_info->FieldByName
						("blueprintNo")->AsString;
					projframe->UniEdit3->Text =
						UniMainModule()->uniq_proj_info->FieldByName("stage")
						->AsString;
					projframe->UniEdit4->Text =
						UniMainModule()->uniq_proj_info->FieldByName
						("achievement")->AsString;
					projframe->UniEdit5->Text =
						UniMainModule()->uniq_proj_info->FieldByName("amount")
						->AsString;
				}

			}
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
			/*
			 mainform = MainForm();
			 pagecontrol = mainform->UniPageControl1;
			 tabsheet = (TUniTabSheet*)pagecontrol->FindChildControl(sheet_name);
			 if (tabsheet){
			 pagecontrol->ActivePage = tabsheet;
			 }
			 */
		}
		this->Close();
	}
}
// ---------------------------------------------------------------------------
