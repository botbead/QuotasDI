//---------------------------------------------------------------------------

#ifndef NewProjH
#define NewProjH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniEdit.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniLabel.hpp"
#include "uniButton.hpp"
#include "uniBasicGrid.hpp"
#include "uniDBGrid.hpp"
//---------------------------------------------------------------------------
class TUniForm1 : public TUniForm
{
__published:	// IDE-managed Components
	TUniLabel *UniLabel1;
	TUniEdit *UniEdit1;
	TUniLabel *UniLabel2;
	TUniEdit *UniEdit2;
	TUniLabel *UniLabel3;
	TUniEdit *UniEdit3;
	TUniLabel *UniLabel4;
	TUniEdit *UniEdit4;
	TUniLabel *UniLabel5;
	TUniEdit *UniEdit5;
	TUniButton *UniButton1;
	void __fastcall UniButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUniForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
