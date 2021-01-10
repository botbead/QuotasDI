// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SignUp.h"
#include "XXTEA.h"
#include <System.NetEncoding.hpp>
#include "protocols.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniPanel"
#pragma link "uniImage"
#pragma link "uniButton"
#pragma link "uniBitBtn"
#pragma link "uniSpeedButton"
#pragma link "uniEdit"
#pragma link "uniLabel"
#pragma link "uniCheckBox"
#pragma resource "*.dfm"

wchar_t signup_success_hint[] = {0x6CE8, 0x518C, 0x6210, 0x529F, 0xFF0C, 0x8BF7, 0x767B, 0x9646, 0x7CFB, 0x7EDF, 0x0};
wchar_t name_repeat[] = {
	0x7528, 0x6237, 0x540D, 0x5DF2, 0x5B58, 0x5728, 0xFF0C, 0x8BF7, 0x9009, 0x62E9, 0x53E6, 0x5916, 0x7684, 0x540D,
	0x5B57, 0x0};
wchar_t pwd_empty[] = {0x5BC6, 0x7801, 0x4E0D, 0x5F97, 0x4E3A, 0x7A7A, 0x0};
wchar_t pwd_mismatching[] = {0x5BC6, 0x7801, 0x4E0D, 0x5339, 0x914D, 0x0};
wchar_t usr_name[] = {0x7528, 0x6237, 0x540D, 0xFF1A, 0x0};
wchar_t usr_pwd[] = {0x5BC6, 0x7801, 0xFF1A, 0x0};
wchar_t usr_pwd1[] = {0x786E, 0x8BA4, 0x5BC6, 0x7801, 0xFF1A, 0x0};
wchar_t signup[] = {0x6CE8, 0x518C, 0x0};
wchar_t confirmation[] = {0x786E, 0x5B9A, 0x0};
wchar_t usr_empty_warning[] = {
	0x7528, 0x6237, 0x540D, 0x4E3A, 0x7A7A, 0xFF0C, 0x8BF7, 0x8F93, 0x5165, 0x7528, 0x6237, 0x540D, 0xFF01, 0x0};
wchar_t usr_register_protocol[] = {
	0x540C, 0x610F, 0x5E76, 0x63A5, 0x53D7, 0x300A, 0x7528, 0x6237, 0x6CE8, 0x518C, 0x534F, 0x8BAE, 0x300B, 0x0};
wchar_t privacy_policy[] = {0x540C, 0x610F, 0x5E76, 0x63A5, 0x53D7, 0x300A, 0x9690, 0x79C1, 0x534F, 0x8BAE, 0x300B, 0x0
};

// ---------------------------------------------------------------------------
__fastcall TUniFormSignUp::TUniFormSignUp(TComponent* Owner) : TUniForm(Owner) {
	mmodule = UniMainModule();
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp::UniFormCreate(TObject *Sender) {
	UniLabel1->Caption = usr_name;
	UniLabel2->Caption = usr_pwd;
	UniLabel3->Caption = usr_pwd1;

	UniLabel4->Caption = signup;
	UniLabel4->Font->Size = 25;

	UniButton1->Caption = confirmation;
	UniButton1->Enabled = false;
	UniLabel5->Caption = usr_register_protocol;
	UniLabel6->Caption = privacy_policy;
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp::UniImage2Click(TObject *Sender) {
	ModalResult = mrCancel;
}
// ---------------------------------------------------------------------------

void __fastcall TUniFormSignUp::UniButton1Click(TObject *Sender) {
	unsigned len;
	char *encrypt_data = 0;
	UnicodeString x;
	if (UniEdit1->Text == L"") {
		this->ShowToast(usr_empty_warning);
		// ShowMessage(usr_empty_warning);
		goto end;
	}
	else if (UniEdit2->Text != UniEdit3->Text) {
		// ShowMessage(pwd_mismatching);
		this->ShowToast(pwd_mismatching);
		goto end;
	}
	else if (UniEdit2->Text == L"") {
		// ShowMessage(pwd_empty);
		this->ShowToast(pwd_empty);
		goto end;
	}

	mmodule->UniQuery1->SQL->Clear();
	mmodule->UniQuery1->SQL->Add(Sysutils::Format(L"select * from signup_step1 where usr_name = '%s';",
		ARRAYOFCONST((UniEdit1->Text))));
	mmodule->UniQuery1->Execute();
	if (mmodule->UniQuery1->RecordCount) {
		// ShowMessage(name_repeat);
		this->ShowToast(name_repeat);
		goto end;
	}
	encrypt_data = (char *)xxtea_encrypt(AnsiString(UniEdit2->Text).c_str(), AnsiString(UniEdit2->Text).Length(),
		mmodule->key, &len);
	x = TNetEncoding::Base64->EncodeBytesToString(encrypt_data, len);

	// ms = new TMemoryStream;
	// ms->WriteBuffer(encrypt_data,len);
	// x = IdEncoderMIME1->EncodeStream(ms);

	// delete ms;

	mmodule->UniSQL1->SQL->Clear();
	mmodule->UniSQL1->SQL->Add(Sysutils::Format(L"insert into signup_step1 (usr_name, pwd) values('%s', '%s');",
		ARRAYOFCONST((UniEdit1->Text, x))));
	mmodule->UniSQL1->Execute();
	free(encrypt_data);
	// ShowMessage(signup_success_hint);
	this->ShowToast(signup_success_hint);

	ModalResult = mrOk;
end: ;
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp::UniLabel5Click(TObject *Sender) {
	mmodule->protocol_flag = 1000;
	TUniForm1 *form_protocol = (TUniForm1*)UniMainModule()->GetFormInstance(__classid(TUniForm1));
	form_protocol->ShowModal();

}
// ---------------------------------------------------------------------------

void __fastcall TUniFormSignUp::UniLabel6Click(TObject *Sender) {
	mmodule->protocol_flag = 2000;
	TUniForm1 *form_protocol = (TUniForm1*)UniMainModule()->GetFormInstance(__classid(TUniForm1));
	form_protocol->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp::UniCheckBox2Click(TObject *Sender) {
	if (UniCheckBox2->Checked && UniCheckBox1->Checked) {
		UniButton1->Enabled = true;
	}
	else {
		UniButton1->Enabled = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp::UniCheckBox1Click(TObject *Sender) {
	if (UniCheckBox1->Checked && UniCheckBox2->Checked) {
		UniButton1->Enabled = true;
	}
	else {
		UniButton1->Enabled = false;
	}
}
// ---------------------------------------------------------------------------
