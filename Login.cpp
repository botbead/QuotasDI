// ---------------------------------------------------------------------------
#include <vcl.h>
#include <uniGUIVars.hpp>
#pragma hdrstop

#include "Login.h"
#include "MainModule.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniButton"
#pragma link "uniEdit"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniLabel"
#pragma resource "*.dfm"

// ---------------------------------------------------------------------------
TUniLoginForm1 *UniLoginForm1(void) {
	return ((TUniLoginForm1*)UniMainModule()->GetFormInstance
		(__classid(TUniLoginForm1)));
}

// ---------------------------------------------------------------------------
__fastcall TUniLoginForm1::TUniLoginForm1(TComponent* Owner)
	: TUniLoginForm(Owner) {
}

// ---------------------------------------------------------------------------
void T8955C443EB1249A2958F6B9E70EE2234__RegisterFormClass() {
	Uniguivars::RegisterAppFormClass(__classid(TUniLoginForm1));
	Uniguiregclasses::CPPInit();
}

#pragma startup T8955C443EB1249A2958F6B9E70EE2234__RegisterFormClass

void __fastcall TUniLoginForm1::UniButton2Click(TObject *Sender) {
	ModalResult = mrCancel;
}
// ---------------------------------------------------------------------------

void __fastcall TUniLoginForm1::UniButton1Click(TObject *Sender) {
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		UniMainModule()->UniQuery1->SQL->Clear();
		UniMainModule()->UniQuery1->SQL->Add
			(Sysutils::Format
			("select priority from user_info where name = '%s' and password = '%s';",
			ARRAYOFCONST((UniEdit1->Text, UniEdit2->Text))));
		UniMainModule()->uniq_proj_info->SQL->Clear();
		UniMainModule()->uniq_proj_info->SQL->Add("SELECT * FROM proj_info;");
		try {
			UniMainModule()->UniQuery1->Execute();
			UniMainModule()->uniq_proj_info->Execute();
			UniMainModule()->UniConnection1->Commit();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
		if (1 != UniMainModule()->UniQuery1->RecordCount) {
			UniEdit1->Text = "";
			UniEdit2->Text = "";
			ShowMessage("错误的用户名或密码，请重试");
		}
		else {
			UniMainModule()->user_name = UniEdit1->Text;
			UniMainModule()->user_pwd = UniEdit2->Text;
			UniMainModule()->user_priority =
				UniMainModule()->UniQuery1->FieldByName("priority")->AsInteger;
			ModalResult = mrOk;
		}
	}
}
// ---------------------------------------------------------------------------
