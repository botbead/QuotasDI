//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UserMng.h"
#include "MainModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniBasicGrid"
#pragma link "uniDBGrid"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniComboBox"
#pragma link "uniMultiItem"
#pragma link "uniPanel"
#pragma link "uniButton"
#pragma link "uniDBNavigator"
#pragma link "uniEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TUniForm4::TUniForm4(TComponent* Owner)
		: TUniForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TUniForm4::UniButton1Click(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

