// ---------------------------------------------------------------------------

#ifndef PagePaymentH
#define PagePaymentH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniURLFrame.hpp"
#include "uniPanel.hpp"
#include "uniLabel.hpp"
#include "uniImage.hpp"

// ---------------------------------------------------------------------------
class TUniPagePayment : public TUniForm {
__published: // IDE-managed Components
	TUniURLFrame *UniURLFrame1;
	TUniContainerPanel *UniContainerPanel1;
	TUniLabel *UniLabel1;
	TUniImage *UniImage2;

	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniImage2Click(TObject *Sender);
	void __fastcall UniURLFrame1FrameLoaded(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniPagePayment(TComponent* Owner);

	int frame_loading_counter;
};
// ---------------------------------------------------------------------------
#endif
