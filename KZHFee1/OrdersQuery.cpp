// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "OrdersQuery.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniBasicGrid"
#pragma link "uniDBGrid"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniImage"
#pragma link "uniDBNavigator"
#pragma link "uniButton"
#pragma link "uniStringGrid"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "Uni"
#pragma resource "*.dfm"

wchar_t title_order_num[] = {0x8BA2, 0x5355, 0x53F7, 0x0};
wchar_t title_payment_status[] = {0x652F, 0x4ED8, 0x72B6, 0x6001, 0x0};
wchar_t title_trade_num[] = {0x5E73, 0x53F0, 0x4EA4, 0x6613, 0x53F7, 0x0};
wchar_t title_money[] = {0x91D1, 0x989D, 0x0};
wchar_t title_time_end[] = {0x4EA4, 0x6613, 0x7ED3, 0x675F, 0x65F6, 0x95F4, 0x0};
wchar_t title_product_descr[] = {0x5546, 0x54C1, 0x540D, 0x79F0, 0x0};

// ---------------------------------------------------------------------------
__fastcall TUniForm2::TUniForm2(TComponent* Owner) : TUniForm(Owner) {
	mmodule = UniMainModule();
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm2::UniFormCreate(TObject *Sender) {
	// TUniMainModule *mmodule = 0;
	// mmodule = UniMainModule();
	// UniDBGrid1->DataSource = mmodule->UniQueryOrders->DataSource;
	// UniDBNavigator1->DataSource = mmodule->UniQueryOrders->DataSource;
	// mmodule->UniQueryOrders->SQL->Clear();
	// mmodule->UniQueryOrders->SQL->Add
	// (Sysutils::Format
	// (L"select order_num, payment_status, trade_num, money, time_end, product_descr from orders where stuid = %d;",
	// ARRAYOFCONST((usr_id))));

	UniDBGrid1->DataSource = mmodule->UniDataSource1;
	UniDBGrid1->Columns->operator[](0)->Title->Caption = title_order_num;
	UniDBGrid1->Columns->operator[](0)->FieldName = L"order_num";
	UniDBGrid1->Columns->operator[](1)->Title->Caption = title_product_descr;
	UniDBGrid1->Columns->operator[](1)->FieldName = L"product_descr";
	UniDBGrid1->Columns->operator[](2)->Title->Caption = title_payment_status;
	UniDBGrid1->Columns->operator[](2)->FieldName = L"payment_status_chinese";
	UniDBGrid1->Columns->operator[](3)->Title->Caption = title_money;
	UniDBGrid1->Columns->operator[](3)->FieldName = L"money";
	UniDBGrid1->Columns->operator[](4)->Title->Caption = title_trade_num;
	UniDBGrid1->Columns->operator[](4)->FieldName = L"trade_num";
	UniDBGrid1->Columns->operator[](5)->Title->Caption = title_time_end;
	UniDBGrid1->Columns->operator[](5)->FieldName = L"time_end";
	UniDBGrid1->ForceFit = true;
}
// ---------------------------------------------------------------------------

void __fastcall TUniForm2::UniImage2Click(TObject *Sender) {
	ModalResult = mrCancel;
}

// ---------------------------------------------------------------------------
void __fastcall TUniForm2::UniFormShow(TObject *Sender) {
	mmodule->UniQueryOrders->SQL->Clear();
	mmodule->UniQueryOrders->SQL->Add
		(Sysutils::Format
		(L"select order_num, payment_status, payment_status_chinese, trade_num, money, time_end, product_descr from orders where stuid = %d;",
		ARRAYOFCONST((mmodule->usr_id))));
	mmodule->UniQueryOrders->Execute();
}
// ---------------------------------------------------------------------------
