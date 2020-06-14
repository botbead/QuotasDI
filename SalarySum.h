// ---------------------------------------------------------------------------

#ifndef SalarySumH
#define SalarySumH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniBasicGrid.hpp"
#include "uniButton.hpp"
#include "uniDBGrid.hpp"
#include "uniDBNavigator.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include <Vcl.Dialogs.hpp>
#include <VCL.FlexCel.Core.hpp>
#include <FlexCel.XlsAdapter.hpp>

// ---------------------------------------------------------------------------
struct col_sum {
	int col;
	UnicodeString sum;

};

class TUniForm3 : public TUniForm {
__published: // IDE-managed Components

	TUniDBGrid *UniDBGrid1;
	TUniDBNavigator *UniDBNavigator1;
	TUniButton *UniButton1;
	TUniButton *UniButton2;

	void __fastcall UniFormShow(TObject *Sender);
	void __fastcall UniButton1Click(TObject *Sender);
	void __fastcall UniDBGrid1ColumnSummary(TUniDBGridColumn *Column,
		Variant &GroupFieldValue);
	void __fastcall UniDBGrid1ColumnSummaryResult(TUniDBGridColumn *Column,
		Variant &GroupFieldValue, TUniCellAttribs *Attribs,
		UnicodeString &Result);
	void __fastcall UniFormCreate(TObject *Sender);
	void __fastcall UniButton2Click(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TUniForm3(TComponent* Owner);
};
// ---------------------------------------------------------------------------
#endif
