//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include <uniGUIRegClasses.hpp>
#include "uniButton.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniTreeMenu.hpp"
#include "uniTreeView.hpp"
#include "uniMainMenu.hpp"
#include <Vcl.Menus.hpp>
#include "uniPanel.hpp"
#include "uniTabControl.hpp"
#include "uniStatusBar.hpp"
#include "uniPageControl.hpp"
#include "uniBasicGrid.hpp"
#include "uniDBGrid.hpp"
#include "uniDBNavigator.hpp"
#include "uniEdit.hpp"
//---------------------------------------------------------------------------
class TMainForm : public TUniForm
{
__published:	// IDE-managed Components
	TUniMainMenu *UniMainMenu1;
	TUniMenuItem *N1;
	TUniMenuItem *N2;
	TUniStatusBar *UniStatusBar1;
	TUniPanel *UniPanel1;
	TUniPanel *UniPanel2;
	TUniTreeView *UniTreeView1;
	TUniPageControl *UniPageControl1;
	TUniMenuItem *N13;
	TUniMenuItem *N14;
	TUniDBNavigator *UniDBNavigator2;
	TUniDBGrid *UniDBGrid2;
	TUniDBNavigator *UniDBNavigator1;
	TUniDBGrid *UniDBGrid1;
	TUniDBGrid *UniDBGrid3;
	TUniDBNavigator *UniDBNavigator3;
	TUniHiddenPanel *UniHiddenPanel1;
	TUniEdit *UniEdit1;
	TUniMenuItem *N3;
	TUniMenuItem *N4;
	TUniMenuItem *N5;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniFormShow(TObject *Sender);
	void __fastcall UniTreeView1DblClick(TObject *Sender);
	void __fastcall UniFormDestroy(TObject *Sender);
	void __fastcall UniDBGrid3SelectionChange(TObject *Sender);
	void __fastcall UniDBGrid1SelectionChange(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
TMainForm *MainForm(void);
//---------------------------------------------------------------------------
#endif
