//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include <uniGUIRegClasses.hpp>
#include "uniButton.hpp"
#include "uniEdit.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniLabel.hpp"
//---------------------------------------------------------------------------
class TUniLoginForm1 : public TUniLoginForm
{
__published:	// IDE-managed Components
	TUniLabel *UniLabel1;
	TUniEdit *UniEdit1;
	TUniLabel *UniLabel2;
	TUniEdit *UniEdit2;
	TUniButton *UniButton1;
	TUniButton *UniButton2;
	void __fastcall UniButton2Click(TObject *Sender);
	void __fastcall UniButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUniLoginForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
TUniLoginForm1 *UniLoginForm1(void);
//---------------------------------------------------------------------------
#endif
