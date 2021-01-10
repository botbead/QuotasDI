// ---------------------------------------------------------------------------
#include <vcl.h>
#include <UniGUIApplication.hpp>
#include <uniGUIVars.hpp>
#pragma hdrstop

#include "Login.h"
#include "SignUp.h"
#include "XXTEA.h"
#include <System.NetEncoding.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniImage"
#pragma link "uniPanel"
#pragma link "uniLabel"
#pragma link "uniEdit"
#pragma link "uniButton"
#pragma resource "*.dfm"

/*
 student--2
 school--3
 agent--4

 admin--1
 god--0
 */

wchar_t login_success[5] = {0x767B, 0x5F55, 0x6210, 0x529F, 0x0};
wchar_t wrong_pwd[] = {0x5BC6, 0x7801, 0x9519, 0x8BEF, 0x0};
wchar_t invalid_usr_or_pwd[] = {0x65E0, 0x6548, 0x7684, 0x7528, 0x6237, 0x540D, 0x6216, 0x5BC6, 0x7801, 0x0};
wchar_t empty_usr[] = {0x7528, 0x6237, 0x540D, 0x4E0D, 0x80FD, 0x4E3A, 0x7A7A, 0x0};
wchar_t empty_pwd[] = {0x7A7A, 0x7684, 0x5BC6, 0x7801, 0x0};

// ---------------------------------------------------------------------------
TUniLoginForm1 *UniLoginForm1(void) {
	return ((TUniLoginForm1*)UniMainModule()->GetFormInstance(__classid(TUniLoginForm1)));
}

// ---------------------------------------------------------------------------
__fastcall TUniLoginForm1::TUniLoginForm1(TComponent* Owner) : TUniLoginForm(Owner) {
	mmodule = UniMainModule();
}

// ---------------------------------------------------------------------------
void T8913E11864894A76990BE73421A25103__RegisterFormClass() {
	Uniguivars::RegisterAppFormClass(__classid(TUniLoginForm1));
	Uniguiregclasses::CPPInit();
}

#pragma startup T8913E11864894A76990BE73421A25103__RegisterFormClass

void __fastcall TUniLoginForm1::UniButton1Click(TObject *Sender) {

	char *encrypt_data;
	unsigned len;
	UnicodeString x;

#ifdef _DEBUG
	// UniEdit1->Text = L"abc";
	// UniEdit2->Text = L"abc";
#else
	if (L"" == UniEdit1->Text) {
		this->ShowToast(empty_usr);
		goto end;
	}
	else if (L"" == UniEdit2->Text) {
		this->ShowToast(empty_pwd);
		goto end;
	}
#endif

	x = UniEdit1->Text.Trim();
	mmodule->UniQuery1->SQL->Clear();
	mmodule->UniQuery1->SQL->Add(Sysutils::Format("select * from signup_step1 where usr_name = '%s';",
		ARRAYOFCONST((x))));

	mmodule->UniQuery1->Execute();

	if (1 == mmodule->UniQuery1->RecordCount) {
		mmodule->pwd = UniEdit2->Text.Trim();
		encrypt_data = (char *)xxtea_encrypt(AnsiString(mmodule->pwd).c_str(), AnsiString(mmodule->pwd).Length(),
			mmodule->key, &len);
		x = TNetEncoding::Base64->EncodeBytesToString(encrypt_data, len);
		if (x == mmodule->UniQuery1->FieldByName(L"pwd")->AsString) {
			mmodule->archived = (bool)mmodule->UniQuery1->FieldByName(L"archived")->AsInteger;
			mmodule->usr_type = mmodule->UniQuery1->FieldByName(L"usr_type")->AsInteger;
			mmodule->login_name = UniEdit1->Text.Trim();
			mmodule->usr_id = mmodule->UniQuery1->FieldByName(L"usr_id")->AsInteger;
			mmodule->schl_id = mmodule->UniQuery1->FieldByName(L"schl_id")->AsInteger;
			this->ShowToast(login_success);
			ModalResult = mrOk;
		}

		else
			// ShowMessage(wrong_pwd);
				this->ShowToast(wrong_pwd);
	}
	else {
		// ShowMessage(invalid_usr_or_pwd);
		this->ShowToast(invalid_usr_or_pwd);
	}
end: ;
}

// ---------------------------------------------------------------------------
void __fastcall TUniLoginForm1::UniLabel4Click(TObject *Sender) {
	TUniFormSignUp *form_signup = (TUniFormSignUp*)UniMainModule()->GetFormInstance(__classid(TUniFormSignUp));
	form_signup->ShowModal();
	// redirect to another website;
	// UniSession->AddJS(L"location.href=\"http://google.com\"");
	// get client's ip address
	// this->ShowToast(UniSession->RemoteIP);
}

// ---------------------------------------------------------------------------
