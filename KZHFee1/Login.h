// ---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include <uniGUIRegClasses.hpp>
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniImage.hpp"
#include <Vcl.Imaging.jpeg.hpp>
#include "uniPanel.hpp"
#include "uniLabel.hpp"
#include "uniEdit.hpp"
#include "uniButton.hpp"
#include "MainModule.h"

// ---------------------------------------------------------------------------
class TUniLoginForm1 : public TUniLoginForm {
__published: // IDE-managed Components
	TUniPanel *UniPanel1;
	TUniPanel *UniPanel2;
	TUniLabel *UniLabel1;
	TUniLabel *UniLabel2;
	TUniPanel *UniPanel3;
	TUniEdit *UniEdit1;
	TUniImage *UniImage1;
	TUniPanel *UniPanel4;
	TUniImage *UniImage2;
	TUniEdit *UniEdit2;
	TUniButton *UniButton1;
	TUniLabel *UniLabel4;
	TUniLabel *UniLabel3;
	TUniImage *UniImage3;
	TUniLabel *UniLabel5;
	TUniLabel *UniLabel6;
	TUniPanel *UniPanel5;
	TUniLabel *UniLabel8;
	TUniLabel *UniLabel7;

	void __fastcall UniButton1Click(TObject *Sender);
	void __fastcall UniLabel4Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniLoginForm1(TComponent* Owner);

	TUniMainModule *mmodule;
};

// ---------------------------------------------------------------------------
TUniLoginForm1 *UniLoginForm1(void);
// ---------------------------------------------------------------------------
#endif
