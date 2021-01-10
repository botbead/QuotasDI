// ---------------------------------------------------------------------------

#ifndef MainH
#define MainH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include <uniGUIRegClasses.hpp>
#include "uniButton.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniImage.hpp"
#include <Vcl.Imaging.jpeg.hpp>
#include "uniPanel.hpp"
#include "uniLabel.hpp"
#include <Vcl.Imaging.pngimage.hpp>
#include "uniCheckBox.hpp"
#include "uniHTMLFrame.hpp"
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>
#include <System.Net.URLClient.hpp>
#include "uniTimer.hpp"
#include "MainModule.h"

typedef String bank_feedback[5];

// ---------------------------------------------------------------------------
class TMainForm : public TUniForm {
__published: // IDE-managed Components
	TUniPanel *UniPanel1;
	TUniPanel *UniPanel2;
	TUniPanel *UniPanel3;
	TUniLabel *UniLabel1;
	TUniLabel *UniLabel2;
	TUniLabel *UniLabel3;
	TUniContainerPanel *UniContainerPanel1;
	TUniContainerPanel *UniContainerPanel2;
	TUniLabel *UniLabel4;
	TUniLabel *UniLabel5;
	TUniLabel *UniLabel6;
	TUniLabel *UniLabel7;
	TUniContainerPanel *UniContainerPanel3;
	TUniImage *UniImage2;
	TUniContainerPanel *UniContainerPanel4;
	TUniContainerPanel *UniContainerPanel5;
	TUniContainerPanel *UniContainerPanel6;
	TUniContainerPanel *UniContainerPanel7;
	TUniContainerPanel *UniContainerPanel8;
	TUniContainerPanel *UniContainerPanel9;
	TUniLabel *UniLabel9;
	TUniLabel *UniLabel8;
	TUniLabel *UniLabel10;
	TUniLabel *UniLabel11;
	TUniLabel *UniLabel12;
	TUniLabel *UniLabel13;
	TUniLabel *UniLabel14;
	TUniLabel *UniLabel15;
	TUniLabel *UniLabel16;
	TUniContainerPanel *UniContainerPanel10;
	TUniPanel *UniPanel4;
	TUniPanel *UniPanel5;
	TUniContainerPanel *UniContainerPanel11;
	TUniContainerPanel *UniContainerPanel12;
	TUniImage *UniImage1;
	TUniLabel *UniLabel17;
	TUniContainerPanel *UniContainerPanel13;
	TUniLabel *UniLabel18;
	TUniContainerPanel *UniContainerPanel14;
	TUniButton *UniButton1;
	TUniLabel *UniLabel19;
	TUniLabel *UniLabel20;
	TUniLabel *UniLabel21;
	TUniCheckBox *UniCheckBox1;
	TUniCheckBox *UniCheckBox2;
	TUniImage *UniImage3;
	TUniContainerPanel *UniContainerPanel18;
	TUniContainerPanel *UniContainerPanel15;
	TUniLabel *UniLabel22;
	TUniContainerPanel *UniContainerPanel16;
	TUniLabel *UniLabel23;
	TUniLabel *UniLabel24;
	TUniLabel *UniLabel25;
	TUniLabel *UniLabel26;
	TUniContainerPanel *UniContainerPanel17;
	TUniCheckBox *UniCheckBox3;
	TUniCheckBox *UniCheckBox4;
	TUniButton *UniButton2;
	TUniLabel *UniLabel27;
	TUniContainerPanel *UniContainerPanel19;
	TUniPanel *UniPanel6;
	TUniPanel *UniPanel7;
	TUniPanel *UniPanel8;
	TUniLabel *UniLabel28;
	TUniLabel *UniLabel29;
	TUniLabel *UniLabel30;
	TUniLabel *UniLabel31;
	TUniLabel *UniLabel32;
	TUniContainerPanel *UniContainerPanel20;
	TUniCheckBox *UniCheckBox5;
	TUniButton *UniButton3;
	TUniLabel *UniLabel33;
	TUniLabel *UniLabel34;
	TUniLabel *UniLabel35;
	TUniLabel *UniLabel36;
	TUniLabel *UniLabel37;
	TUniContainerPanel *UniContainerPanel21;
	TUniCheckBox *UniCheckBox6;
	TUniButton *UniButton4;
	TUniLabel *UniLabel38;
	TUniLabel *UniLabel39;
	TUniLabel *UniLabel40;
	TUniLabel *UniLabel41;
	TUniLabel *UniLabel42;
	TUniContainerPanel *UniContainerPanel22;
	TUniCheckBox *UniCheckBox7;
	TUniButton *UniButton5;
	TUniLabel *UniLabel43;
	TUniLabel *UniLabel44;
	TUniLabel *UniLabel45;
	TNetHTTPClient *NetHTTPClient1;
	TNetHTTPRequest *NetHTTPRequest1;
	TUniTimer *UniTimer1;

	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniFormBeforeShow(TObject *Sender);
	void __fastcall UniCheckBox5Click(TObject *Sender);
	void __fastcall UniCheckBox6Click(TObject *Sender);
	void __fastcall UniCheckBox7Click(TObject *Sender);
	void __fastcall UniLabel43Click(TObject *Sender);
	void __fastcall UniLabel44Click(TObject *Sender);
	void __fastcall UniLabel45Click(TObject *Sender);
	void __fastcall UniCheckBox1Change(TObject *Sender);
	void __fastcall UniCheckBox2Change(TObject *Sender);
	void __fastcall UniCheckBox3Click(TObject *Sender);
	void __fastcall UniCheckBox4Click(TObject *Sender);
	void __fastcall UniButton1Click(TObject *Sender);
	void __fastcall UniButton2Click(TObject *Sender);
	void __fastcall UniButton5Click(TObject *Sender);
	void __fastcall UniButton4Click(TObject *Sender);
	void __fastcall UniButton3Click(TObject *Sender);
	void __fastcall UniTimer1Timer(TObject *Sender);
	void __fastcall UniLabel6Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TMainForm(TComponent* Owner);

	UnicodeString order_num;
	UnicodeString prodc_name;

	TUniMainModule *mmodule;
};

// ---------------------------------------------------------------------------
TMainForm *MainForm(void);
// ---------------------------------------------------------------------------
#endif
