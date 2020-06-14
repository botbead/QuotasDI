//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Staff.h"
#include "MainModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniBasicGrid"
#pragma link "uniButton"
#pragma link "uniDBGrid"
#pragma link "uniDBNavigator"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniEdit"
#pragma link "uniPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TUniForm7::TUniForm7(TComponent* Owner)
		: TUniForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TUniForm7::UniButton1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
