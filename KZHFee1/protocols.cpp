// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "protocols.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniImage"
#pragma link "uniMemo"
#pragma resource "*.dfm"

extern wchar_t usr_register_protocol[];
extern wchar_t privacy_policy[];

// ---------------------------------------------------------------------------
__fastcall TUniForm1::TUniForm1(TComponent* Owner) : TUniForm(Owner) {
	mmodule = UniMainModule();
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm1::UniFormCreate(TObject *Sender) {

	if (1000 == mmodule->protocol_flag) {
		UniMemo1->Lines->LoadFromFile(L"files\\usr_register_protocol.txt");
	}
	else if (2000 == mmodule->protocol_flag) {
		UniMemo1->Lines->LoadFromFile(L"files\\privacy_policy.txt");
	}
	else if (3000 == mmodule->protocol_flag) {
		UniMemo1->Lines->LoadFromFile(L"files\\annual_buy_protocol.txt");
	}
	else if (4000 == mmodule->protocol_flag) {
		UniMemo1->Lines->LoadFromFile(L"files\\annual_buy_protocol.txt");
	}
	else if (5000 == mmodule->protocol_flag) {
		UniMemo1->Lines->LoadFromFile(L"files\\zero_to_buy_protocol.txt");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm1::UniImage2Click(TObject *Sender) {
	ModalResult = mrCancel;
}
// ---------------------------------------------------------------------------
