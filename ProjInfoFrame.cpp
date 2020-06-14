// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProjInfoFrame.h"
#include "MainModule.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniEdit"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniLabel"
#pragma link "uniButton"
#pragma link "uniBasicGrid"
#pragma link "uniDBGrid"
#pragma link "uniDBTreeGrid"
#pragma link "uniDBNavigator"
#pragma link "uniMemo"
#pragma link "uniDBEdit"
#pragma resource "*.dfm"

// ---------------------------------------------------------------------------
__fastcall TUniFrame1::TUniFrame1(TComponent* Owner) : TUniFrame(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TUniFrame1::UniFrameCreate(TObject *Sender) { /*
	 TUniEdit * edt = new TUniEdit(this);
	 UniDBGrid1->ColumnByName("task")->Editor = edt;
	 */

}
// ---------------------------------------------------------------------------
