//---------------------------------------------------------------------------

#ifndef StaffH
#define StaffH
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
class TUniForm7 : public TUniForm
{
__published:	// IDE-managed Components
	TUniDBGrid *UniDBGrid1;
	TUniDBNavigator *UniDBNavigator1;
	TUniButton *UniButton1;
	TUniHiddenPanel *UniHiddenPanel1;
	TUniEdit *UniEdit1;
	void __fastcall UniButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUniForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
