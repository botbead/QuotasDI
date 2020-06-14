//---------------------------------------------------------------------------

#ifndef FixedExpensesH
#define FixedExpensesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniBasicGrid.hpp"
#include "uniButton.hpp"
#include "uniDBGrid.hpp"
#include "uniDBNavigator.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniEdit.hpp"
#include "uniPanel.hpp"
//---------------------------------------------------------------------------
class TUniForm8 : public TUniForm
{
__published:	// IDE-managed Components
	TUniDBGrid *UniDBGrid1;
	TUniDBNavigator *UniDBNavigator1;
	TUniButton *¹Ø±Õ;
	TUniHiddenPanel *UniHiddenPanel1;
	TUniEdit *UniEdit1;
	void __fastcall ¹Ø±ÕClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUniForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
