//---------------------------------------------------------------------------

#ifndef ProjInfoFrameH
#define ProjInfoFrameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <UniGUIFrame.hpp>
#include "uniEdit.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniLabel.hpp"
#include "uniButton.hpp"
#include "uniBasicGrid.hpp"
#include "uniDBGrid.hpp"
#include "uniDBTreeGrid.hpp"
#include "uniDBNavigator.hpp"
#include "uniMemo.hpp"
#include "uniDBEdit.hpp"
//---------------------------------------------------------------------------
class TUniFrame1 : public TUniFrame
{
__published:	// IDE-managed Components
	TUniLabel *UniLabel1;
	TUniLabel *UniLabel2;
	TUniLabel *UniLabel3;
	TUniLabel *UniLabel4;
	TUniLabel *UniLabel5;
	TUniButton *UniButton1;
	TUniDBGrid *UniDBGrid1;
	TUniDBNavigator *UniDBNavigator1;
	TUniEdit *UniEdit6;
	TUniEdit *UniEdit1;
	TUniEdit *UniEdit2;
	TUniEdit *UniEdit3;
	TUniEdit *UniEdit4;
	TUniEdit *UniEdit5;
	TUniDBGrid *UniDBGrid2;
	TUniDBNavigator *UniDBNavigator2;
	void __fastcall UniFrameCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUniFrame1(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
