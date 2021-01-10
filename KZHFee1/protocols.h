// ---------------------------------------------------------------------------

#ifndef protocolsH
#define protocolsH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniImage.hpp"
#include "uniMemo.hpp"
#include "MainModule.h"

// ---------------------------------------------------------------------------
class TUniForm1 : public TUniForm {
__published: // IDE-managed Components
	TUniImage *UniImage2;
	TUniMemo *UniMemo1;

	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniImage2Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniForm1(TComponent* Owner);

	TUniMainModule *mmodule;
};
// ---------------------------------------------------------------------------
#endif
