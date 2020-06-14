//---------------------------------------------------------------------------

#ifndef ProjKPIQuotaH
#define ProjKPIQuotaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIForm.hpp>
#include "uniBasicGrid.hpp"
#include "uniButton.hpp"
#include "uniDBGrid.hpp"
#include "uniGUIBaseClasses.hpp"
#include "uniGUIClasses.hpp"
#include "uniLabel.hpp"
#include "uniDBNavigator.hpp"
//---------------------------------------------------------------------------
class TUniForm2 : public TUniForm
{
__published:	// IDE-managed Components
	TUniDBGrid *UniDBGrid1;
	TUniButton *UniButton1;
	TUniLabel *UniLabel1;
	TUniDBNavigator *UniDBNavigator1;
	void __fastcall UniButton1Click(TObject *Sender);
	void __fastcall UniFormShow(TObject *Sender);
	void __fastcall UniDBGrid1ColumnSummaryResult(TUniDBGridColumn *Column, Variant &GroupFieldValue,
          TUniCellAttribs *Attribs, UnicodeString &Result);
	void __fastcall UniDBGrid1ColumnSummary(TUniDBGridColumn *Column, Variant &GroupFieldValue);


private:	// User declarations
public:		// User declarations
	__fastcall TUniForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
