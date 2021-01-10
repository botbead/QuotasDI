// ---------------------------------------------------------------------------

#ifndef MainGUIH
#define MainGUIH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TMemo *Memo1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TTimer *Timer1;

	void __fastcall N1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
