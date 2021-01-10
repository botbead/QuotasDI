// ---------------------------------------------------------------------------

#ifndef OrdersQueryH
#define OrdersQueryH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniBasicGrid.hpp"
#include "uniDBGrid.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniImage.hpp"
#include "uniDBNavigator.hpp"
#include "uniButton.hpp"
#include "uniStringGrid.hpp"
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "Uni.hpp"
#include <Data.DB.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "MainModule.h"

// ---------------------------------------------------------------------------
class TUniForm2 : public TUniForm {
__published: // IDE-managed Components
	TUniImage *UniImage2;
	TUniDBGrid *UniDBGrid1;

	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniImage2Click(TObject *Sender);
	void __fastcall UniFormShow(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniForm2(TComponent* Owner);

	TUniMainModule *mmodule;
};
// ---------------------------------------------------------------------------
#endif
