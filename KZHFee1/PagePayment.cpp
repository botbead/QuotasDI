// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PagePayment.h"
#include "MainModule.h"
#include "Main.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniURLFrame"
#pragma link "uniPanel"
#pragma link "uniLabel"
#pragma link "uniImage"
#pragma resource "*.dfm"

wchar_t payment_hint[] = {
	0x7531, 0x4E8E, 0x94F6, 0x884C, 0x652F, 0x4ED8, 0x63A5, 0x53E3, 0x95EE, 0x9898, 0xFF0C, 0x8BF7, 0x9009, 0x62E9,
	0x652F, 0x4ED8, 0x5B9D, 0x626B, 0x7801, 0x6216, 0x5FAE, 0x4FE1, 0x626B, 0x7801, 0x4ED8, 0x6B3E, 0x65B9, 0x5F0F, 0x0
};

// ---------------------------------------------------------------------------
__fastcall TUniPagePayment::TUniPagePayment(TComponent* Owner) : TUniForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TUniPagePayment::UniFormCreate(TObject *Sender) {
	UniLabel1->Caption = payment_hint;
	// UniLabel1->Caption = L"";
	UniLabel1->Font->Size = 20;
	UniLabel1->Font->Style = UniLabel1->Font->Style << fsBold;
	frame_loading_counter = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TUniPagePayment::UniImage2Click(TObject *Sender) {
	ModalResult = mrCancel;
}

// ---------------------------------------------------------------------------
void __fastcall TUniPagePayment::UniURLFrame1FrameLoaded(TObject *Sender) {

	TMainForm *mainform = 0;
	++frame_loading_counter;
	// if (frame_loading_counter == 3) {
	// ShowMessage(UniURLFrame1->URL);
	// frame_loading_counter = 0;
	// }
	// UniURLFrame1->HTML->SaveToFile(UnicodeString(frame_loading_counter));
	// int i = UniURLFrame1->QueryParams->Count;
	// UnicodeString x;
	// x = UniURLFrame1->HTML->Text;
	// OutputDebugStringW(UniURLFrame1->URL.w_str());
	// OutputDebugStringW(UnicodeString(frame_loading_counter).w_str());
	// UniURLFrame1->
	if (3 == frame_loading_counter) {
		// OutputDebugStringW(UniMainModule()->rawQueryString.w_str());
		frame_loading_counter = 0;
		mainform = (TMainForm*)UniMainModule()->GetFormInstance(__classid(TMainForm));
		mainform->UniTimer1->Enabled = true;
		ModalResult = mrCancel;
	}

}
// ---------------------------------------------------------------------------
