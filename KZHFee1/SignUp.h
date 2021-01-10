// ---------------------------------------------------------------------------

#ifndef SignUpH
#define SignUpH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniPanel.hpp"
#include "uniImage.hpp"
#include <Vcl.Imaging.jpeg.hpp>
#include "uniButton.hpp"
#include "uniBitBtn.hpp"
#include "uniSpeedButton.hpp"
#include "uniEdit.hpp"
#include "uniLabel.hpp"
#include <IdBaseComponent.hpp>
#include <IdCoder.hpp>
#include <IdCoder3to4.hpp>
#include <IdCoderMIME.hpp>
#include "uniCheckBox.hpp"
#include "MainModule.h"

// ---------------------------------------------------------------------------
class TUniFormSignUp : public TUniForm {
__published: // IDE-managed Components
	TUniContainerPanel *UniContainerPanel2;
	TUniImage *UniImage1;
	TUniContainerPanel *UniContainerPanel3;
	TUniImage *UniImage2;
	TUniEdit *UniEdit1;
	TUniLabel *UniLabel1;
	TUniLabel *UniLabel2;
	TUniEdit *UniEdit2;
	TUniLabel *UniLabel3;
	TUniEdit *UniEdit3;
	TUniLabel *UniLabel4;
	TUniButton *UniButton1;
	TUniLabel *UniLabel5;
	TUniLabel *UniLabel6;
	TUniCheckBox *UniCheckBox2;
	TUniCheckBox *UniCheckBox1;

	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniImage2Click(TObject *Sender);
	void __fastcall UniButton1Click(TObject *Sender);
	void __fastcall UniLabel5Click(TObject *Sender);
	void __fastcall UniLabel6Click(TObject *Sender);
	void __fastcall UniCheckBox2Click(TObject *Sender);
	void __fastcall UniCheckBox1Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniFormSignUp(TComponent* Owner);

	TUniMainModule *mmodule;
};
// ---------------------------------------------------------------------------
#endif
