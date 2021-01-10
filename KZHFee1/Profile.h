// ---------------------------------------------------------------------------

#ifndef ProfileH
#define ProfileH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniLabel.hpp"
#include "uniImage.hpp"
#include "uniPanel.hpp"
#include "uniRadioGroup.hpp"
#include "uniButton.hpp"
#include "uniComboBox.hpp"
#include "uniDBComboBox.hpp"
#include "uniMultiItem.hpp"
#include "uniEdit.hpp"
#include "uniCheckBox.hpp"
#include "uniListBox.hpp"
#include "MainModule.h"
#include <map>

struct school_details {
	int scid;
	int phase[3];
	UnicodeString school_name;
	UnicodeString school_students_table;
};

// ---------------------------------------------------------------------------
class TUniFormSignUp_1 : public TUniForm {
__published: // IDE-managed Components
	TUniImage *UniImage2;
	TUniLabel *UniLabel1;
	TUniLabel *UniLabel2;
	TUniRadioGroup *UniRadioGroup1;
	TUniSimplePanel *UniSimplePanel1;
	TUniButton *UniButton1;
	TUniComboBox *UniComboBox1;
	TUniComboBox *UniComboBox2;
	TUniLabel *UniLabel4;
	TUniComboBox *UniComboBox3;
	TUniComboBox *UniComboBox4;
	TUniLabel *UniLabel5;
	TUniEdit *UniEdit1;
	TUniLabel *UniLabel6;
	TUniEdit *UniEdit2;
	TUniLabel *UniLabel7;
	TUniEdit *UniEdit3;
	TUniContainerPanel *UniContainerPanel_student;
	TUniLabel *UniLabel3;
	TUniLabel *UniLabel9;
	TUniEdit *UniEdit5;
	TUniContainerPanel *UniContainerPanel_school;
	TUniEdit *UniEdit6;
	TUniEdit *UniEdit7;
	TUniEdit *UniEdit8;
	TUniLabel *UniLabel11;
	TUniLabel *UniLabel14;
	TUniLabel *UniLabel15;
	TUniLabel *UniLabel16;
	TUniEdit *UniEdit9;
	TUniCheckBox *UniCheckBox2;
	TUniCheckBox *UniCheckBox3;
	TUniCheckBox *UniCheckBox4;
	TUniLabel *UniLabel13;
	TUniCheckBox *UniCheckBox5;
	TUniCheckBox *UniCheckBox6;
	TUniCheckBox *UniCheckBox7;
	TUniCheckBox *UniCheckBox8;
	TUniLabel *UniLabel12;
	TUniLabel *UniLabel18;
	TUniCheckBox *UniCheckBox9;
	TUniCheckBox *UniCheckBox10;
	TUniCheckBox *UniCheckBox11;
	TUniLabel *UniLabel19;
	TUniEdit *UniEdit11;
	TUniContainerPanel *UniContainerPanel_agent;
	TUniComboBox *UniComboBox6;
	TUniEdit *UniEdit12;
	TUniEdit *UniEdit13;
	TUniLabel *UniLabel20;
	TUniLabel *UniLabel21;
	TUniLabel *UniLabel22;
	TUniLabel *UniLabel23;
	TUniLabel *UniLabel25;
	TUniEdit *UniEdit15;
	TUniEdit *UniEdit16;
	TUniListBox *UniListBox1;
	TUniLabel *UniLabel27;
	TUniComboBox *UniComboBox5;
	TUniEdit *UniEdit4;
	TUniLabel *UniLabel8;
	TUniEdit *UniEdit10;
	TUniLabel *UniLabel10;

	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniImage2Click(TObject *Sender);
	void __fastcall UniRadioGroup1ChangeValue(TObject *Sender);
	void __fastcall UniCheckBox9Click(TObject *Sender);
	void __fastcall UniCheckBox10Click(TObject *Sender);
	void __fastcall UniCheckBox11Click(TObject *Sender);
	void __fastcall UniButton1Click(TObject *Sender);
	void __fastcall UniCheckBox5Click(TObject *Sender);
	void __fastcall UniCheckBox6Click(TObject *Sender);
	void __fastcall UniCheckBox8Click(TObject *Sender);
	void __fastcall UniCheckBox7Click(TObject *Sender);
	void __fastcall UniCheckBox2Click(TObject *Sender);
	void __fastcall UniCheckBox3Click(TObject *Sender);
	void __fastcall UniCheckBox4Click(TObject *Sender);
	void __fastcall UniComboBox2Change(TObject *Sender);
	void __fastcall UniComboBox1Select(TObject *Sender);
	void __fastcall UniComboBox1Change(TObject *Sender);
	void __fastcall UniFormDestroy(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniFormSignUp_1(TComponent* Owner);

	TUniMainModule *mmodule;

	std::map<int, school_details*>school_map;
};
// ---------------------------------------------------------------------------
#endif
