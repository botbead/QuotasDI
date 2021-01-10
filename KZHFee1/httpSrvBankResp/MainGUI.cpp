// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainGUI.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender) {
	Memo1->Lines->Clear();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	Memo1->Lines->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormClick(TObject *Sender) {
	Timer1->Enabled = !Timer1->Enabled;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	Timer1->Enabled = false;
	Memo1->ScrollBars = ssBoth;
}
// ---------------------------------------------------------------------------
