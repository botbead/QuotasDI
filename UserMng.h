//---------------------------------------------------------------------------

#ifndef UserMngH
#define UserMngH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniBasicGrid.hpp"
#include "uniDBGrid.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniComboBox.hpp"
#include "uniMultiItem.hpp"
#include "uniPanel.hpp"
#include "uniButton.hpp"
#include "uniDBNavigator.hpp"
#include "uniEdit.hpp"
//---------------------------------------------------------------------------
class TUniForm4 : public TUniForm
{
__published:	// IDE-managed Components
	TUniDBGrid *UniDBGrid1;
	TUniHiddenPanel *UniHiddenPanel1;
	TUniComboBox *UniComboBox1;
	TUniDBNavigator *UniDBNavigator1;
	TUniButton *UniButton1;
	TUniEdit *UniEdit1;
	void __fastcall UniButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUniForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
