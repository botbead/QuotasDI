// ---------------------------------------------------------------------------
#include <vcl.h>
#include <uniGUIVars.hpp>
#pragma hdrstop

#include "Main.h"

#include "Profile.h"
#include "protocols.h"
#include "ServerModule.h"
#include "PagePayment.h"
#include <process.h>
#include "OrdersQuery.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniButton"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniImage"
#pragma link "uniPanel"
#pragma link "uniLabel"
#pragma link "uniCheckBox"
#pragma link "uniHTMLFrame"
#pragma link "uniTimer"
#pragma resource "*.dfm"

// extern void build_post_params(TList *, UnicodeString *, UnicodeString*, UnicodeString *);

// bool agree_values[3];
wchar_t descr_pen[] = {0x4E00, 0x677F, 0x901A, 0x6570, 0x7801, 0x7B14, 0xFF08, 0x5E26, 0x7B14, 0x82AF, 0xFF09, 0x0};
wchar_t purchase_hint2[] = {
	0x7528, 0x6237, 0x7F34, 0x7EB3, 0x670D, 0x52A1, 0x8D39, 0x540E, 0x5373, 0x53EF, 0x5728, 0x6709, 0x6548, 0x671F,
	0x5185, 0x4EAB, 0x53D7, 0x300A, 0x4E00, 0x677F, 0x901A, 0x300B, 0x5404, 0x7C7B, 0x670D, 0x52A1, 0x0};
wchar_t full_amount[] = {0x4E00, 0x6B21, 0x6027, 0x5168, 0x989D, 0x652F, 0x4ED8, 0x0};
wchar_t has_discount_full[] = {0xFF08, 0x6709, 0x6298, 0x6263, 0x4F18, 0x60E0, 0xFF09, 0x0};
wchar_t total_after_discount[] = {0x4F18, 0x60E0, 0x603B, 0x989D, 0xFF1A, 0x33, 0x30, 0x30, 0x30, 0x5143, 0x0};
wchar_t full_amount_hint[] = {
	0x60A8, 0x5C06, 0x8D2D, 0x4E70, 0x7684, 0x4E00, 0x6B21, 0x6027, 0x5168, 0x989D, 0x652F, 0x4ED8, 0x670D, 0x52A1,
	0x6709, 0x6548, 0x671F, 0x9650, 0x4E3A, 0xFF1A, 0x0};
wchar_t accept_term[] = {0x540C, 0x610F, 0x5E76, 0x63A5, 0x53D7, 0x300A, 0x670D, 0x52A1, 0x6761, 0x6B3E, 0x300B, 0x0};
wchar_t annual[] = {0x670D, 0x52A1, 0x5E74, 0x8D39, 0xFF08, 0x4E00, 0x5E74, 0xFF09, 0x0};
wchar_t annual_fee[] = {0x37, 0x32, 0x30, 0x5143, 0x0};
wchar_t amount_annual_fee[] = {0x7F34, 0x8D39, 0x91D1, 0x989D, 0xFF1A, 0x37, 0x32, 0x30, 0x5143, 0x0};
wchar_t annual_hint[] = {
	0x60A8, 0x5C06, 0x8D2D, 0x4E70, 0x7684, 0x6309, 0x5E74, 0x7F34, 0x8D39, 0x670D, 0x52A1, 0x6709, 0x6548, 0x671F,
	0x9650, 0x4E3A, 0xFF1A, 0x0};
wchar_t zero[] = {0x30, 0x5143, 0x8D2D, 0x0};
wchar_t recommendation[] = {0x63A8, 0x8350, 0x0};
wchar_t amount_zero[] = {0x7F34, 0x8D39, 0x91D1, 0x989D, 0xFF1A, 0x33, 0x38, 0x30, 0x30, 0x5143, 0x0};
wchar_t zero_hint[] = {
	0x60A8, 0x53EF, 0x5728, 0x670D, 0x52A1, 0x671F, 0x7ED3, 0x675F, 0x540E, 0x4E00, 0x4E2A, 0x6708, 0x5185, 0x7533,
	0x8BF7, 0x5168, 0x989D, 0x9000, 0x6B3E, 0xFF1A, 0x0};
wchar_t srv_purchase[] = {0x8D2D, 0x4E70, 0x670D, 0x52A1, 0x0000};
wchar_t dev_purchase[] = {0x8D2D, 0x4E70, 0x8BBE, 0x5907, 0x0000};
wchar_t menu_title[8] = {0x4e00, 0x677f, 0x901a, 0x670d, 0x52a1, 0x5e73, 0x53f0, 0x0000};
wchar_t icpfiling[] = {
	0x9C81, 0x49, 0x43, 0x50, 0x5907, 0x31, 0x39, 0x30, 0x36, 0x32, 0x35, 0x31, 0x31, 0x53F7, 0x2D, 0x31, 0x0};
wchar_t copyright[] = {
	0xA9, 0x32, 0x30, 0x32, 0x30, 0x20, 0x5C71, 0x4E1C, 0x5EFA, 0x4EAB, 0x6559, 0x80B2, 0x79D1, 0x6280, 0x6709, 0x9650,
	0x516C, 0x53F8, 0x20, 0x7248, 0x6743, 0x6240, 0x6709, 0x0};
wchar_t hotline[] = {
	0x670D, 0x52A1, 0x70ED, 0x7EBF, 0xFF1A, 0x30, 0x35, 0x33, 0x33, 0x2D, 0x38, 0x37, 0x39, 0x35, 0x32, 0x33, 0x37, 0x0
};
wchar_t menuitem_home[3] = {0x9996, 0x9875, 0x0000};
wchar_t menuitem_pay_record[5] = {0x652f, 0x4ed8, 0x8bb0, 0x5f55, 0x0000};
wchar_t menuitem_help[3] = {0x5e2e, 0x52a9, 0x0000};
wchar_t purchase_hint1[] = {
	0x6B22, 0x8FCE, 0x60A8, 0x4F7F, 0x7528, 0x4E00, 0x677F, 0x901A, 0x670D, 0x52A1, 0x5E73, 0x53F0, 0x63D0, 0x4F9B,
	0x7684, 0x652F, 0x4ED8, 0x670D, 0x52A1, 0x3002, 0x8BF7, 0x6839, 0x636E, 0x7CFB, 0x7EDF, 0x63D0, 0x793A, 0x9009,
	0x62E9, 0x9879, 0x76EE, 0x548C, 0x652F, 0x4ED8, 0x3002, 0x6240, 0x6709, 0x5546, 0x54C1, 0x4E00, 0x7ECF, 0x552E,
	0x51FA, 0xFF0C, 0x6982, 0x4E0D, 0x9000, 0x8FD8, 0xFF0C, 0x8BF7, 0x4ED4, 0x7EC6, 0x786E, 0x8BA4, 0x3002, 0x0};
wchar_t org_price_dev[] = {0x539F, 0x4EF7, 0xFFE5, 0x31, 0x30, 0x38, 0x30, 0x0};
wchar_t instant_cash[] = {0x7ACB, 0x5373, 0x652F, 0x4ED8, 0x0};
wchar_t preferential_price_dev[] = {0x4F18, 0x60E0, 0x4EF7, 0x0};
wchar_t new_price_dev[] = {0x37, 0x39, 0x39, 0x0};
wchar_t m_unit[] = {0x5143, 0x2F, 0x53F0, 0x0};
wchar_t descr_board[] = {
	0x4E00, 0x677F, 0x901A, 0x624B, 0x5199, 0x677F, 0xFF08, 0x5E26, 0x6570, 0x7801, 0x7B14, 0xFF09, 0x0};
wchar_t receiving_agent[] = {0x5B66, 0x6821, 0x4EE3, 0x6536, 0x0};
wchar_t direct_receipt[] = {0x5BC4, 0x5230, 0x4E2A, 0x4EBA, 0x5730, 0x5740, 0x0};
wchar_t org_price_pen[] = {0x539F, 0x4EF7, 0xFFE5, 0x36, 0x38, 0x0};
wchar_t new_price_pen[] = {0x36, 0x30, 0x0};
wchar_t zero_to_buy_protocol[] = {
	0x540C, 0x610F, 0x5E76, 0x63A5, 0x53D7, 0x300A, 0x4E00, 0x677F, 0x901A, 0x670D, 0x52A1, 0x534F, 0x8BAE, 0xFF08,
	0x30, 0x5143, 0x8D2D, 0x534F, 0x8BAE, 0xFF09, 0x300B, 0x0};
wchar_t annual_buy_protocol[] = {
	0x540C, 0x610F, 0x5E76, 0x63A5, 0x53D7, 0x300A, 0x4E00, 0x677F, 0x901A, 0x670D, 0x52A1, 0x534F, 0x8BAE, 0xFF08,
	0x4E00, 0x6B21, 0x4ED8, 0x8D39, 0x6216, 0x5E74, 0x8D39, 0xFF09, 0x300B, 0x0};
wchar_t alipay_hint[] = {
	0x7531, 0x4E8E, 0x94F6, 0x884C, 0x652F, 0x4ED8, 0x63A5, 0x53E3, 0x95EE, 0x9898, 0xFF0C, 0x8BF7, 0x9009, 0x62E9,
	0x201C, 0x5FAE, 0x4FE1, 0x626B, 0x63CF, 0x6216, 0x652F, 0x4ED8, 0x5B9D, 0x626B, 0x7801, 0x201D, 0x652F, 0x4ED8,
	0x65B9, 0x5F0F, 0xFF0C, 0x5176, 0x5B83, 0x652F, 0x4ED8, 0x65B9, 0x5F0F, 0x6682, 0x4E0D, 0x652F, 0x6301, 0x0};
wchar_t experience_hint[] = {
	0x5EFA, 0x8BAE, 0x4F7F, 0x7528, 0x50, 0x43, 0x7248, 0x6D4F, 0x89C8, 0x5668, 0x8BBF, 0x95EE, 0x672C, 0x7AD9, 0x0};
wchar_t preferential_price_prefix[] = {0x4F18, 0x60E0, 0x4EF7, 0x683C, 0xFF1A, 0x0};
wchar_t preferential_price_suffix[] = {0x5143, 0x0};
wchar_t payment_completion_hint[] = {
	0x652F, 0x4ED8, 0x5B8C, 0x6210, 0xFF0C, 0x8BF7, 0x5728, 0x652F, 0x4ED8, 0x8BB0, 0x5F55, 0x4E2D, 0x67E5, 0x770B,
	0x60A8, 0x7684, 0x652F, 0x4ED8, 0x4FE1, 0x606F, 0x0};
wchar_t payment_failure_hint[] = {0x652F, 0x4ED8, 0x5931, 0x8D25, 0x0};
wchar_t payment_pending_hint[] = {0x4EA4, 0x6613, 0x6B63, 0x5728, 0x5904, 0x7406, 0x4E2D, 0x0};
wchar_t welcome_prefix[] = {0x6B22, 0x8FCE, 0xFF0C, 0x0};

// ---------------------------------------------------------------------------
TMainForm *MainForm(void) {
	return ((TMainForm*)UniMainModule()->GetFormInstance(__classid(TMainForm)));
}

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent * Owner) : TUniForm(Owner) {
	mmodule = UniMainModule();
}

// ---------------------------------------------------------------------------
void T2799C99E6E95479E9FCCF3D19CA896C0__RegisterFormClass() {
	Uniguivars::RegisterAppFormClass(__classid(TMainForm));
	Uniguiregclasses::CPPInit();
}

#pragma startup T2799C99E6E95479E9FCCF3D19CA896C0__RegisterFormClass

void __fastcall TMainForm::UniFormCreate(TObject * Sender) {

	int i, j, k, m;
	UnicodeString str;
	Layout = L"vbox";

	UniPanel1->BorderStyle = ubsNone;
	UniPanel2->BorderStyle = ubsNone;
	UniPanel3->BorderStyle = ubsNone;
	UniPanel1->Caption = L"";
	UniPanel2->Caption = L"";
	UniPanel3->Caption = L"";

	UniPanel1->LayoutConfig->Width = L"100%";
	UniPanel2->LayoutConfig->Width = L"100%";
	UniPanel3->LayoutConfig->Width = L"100%";

	UniPanel1->Color = Graphics::clNone;
	UniPanel2->Color = Graphics::clNone;

	UniPanel3->Height = 35;
	UniPanel1->Height = 60;

	UniPanel3->Color = clBlack;

	UniPanel3->Layout = L"hbox";

	UniLabel1->LayoutConfig->Flex = 1;
	UniLabel1->LayoutConfig->Height = L"100%";
	UniLabel1->LayoutConfig->Padding = L"7 0"; // top|bottom left|right
	UniLabel1->Font->Color = 0xD0D0D0;
	UniLabel2->LayoutConfig->Flex = 1;
	UniLabel2->LayoutConfig->Height = L"100%";
	UniLabel2->LayoutConfig->Padding = L"7 0";
	UniLabel2->Font->Color = 0xD0D0D0;
	UniLabel3->LayoutConfig->Flex = 1;
	UniLabel3->LayoutConfig->Height = L"100%";
	UniLabel3->LayoutConfig->Padding = L"7 0";
	UniLabel3->Font->Color = 0xD0D0D0;

	UniLabel1->Caption = icpfiling;
	UniLabel2->Caption = copyright;
	// UniLabel3->Caption = hotline;
	UniLabel3->Caption = experience_hint;

	UniLabel1->Alignment = taCenter;
	UniLabel2->Alignment = taCenter;
	UniLabel3->Alignment = taCenter;

	UniLabel1->Font->Size = 11;
	UniLabel2->Font->Size = 11;
	UniLabel3->Font->Size = 11;

	UniPanel1->Layout = L"hbox";
	UniContainerPanel1->LayoutConfig->Height = L"100%";
	UniContainerPanel1->LayoutConfig->Flex = 1;
	UniContainerPanel1->Layout = L"fit";
	UniContainerPanel1->LayoutConfig->Padding = L"17 0 17 50"; // top right bottom left

	UniContainerPanel2->LayoutConfig->Height = L"100%";
	UniContainerPanel2->LayoutAttribs->Pack = L"end";
	UniContainerPanel2->Layout = L"hbox";
	UniContainerPanel2->Width = 400;
	UniContainerPanel2->LayoutConfig->Padding = L"17 0 17 50";

	UniContainerPanel3->LayoutConfig->Height = L"100%";
	UniContainerPanel3->LayoutAttribs->Pack = L"end";
	UniContainerPanel3->LayoutConfig->Margin = L"0 30 0 0";

	UniLabel4->Caption = menu_title;
	UniLabel4->Font->Color = clWhite;
	UniLabel4->Font->Size = 15;

	UniImage2->LayoutConfig->Height = L"90%";

	UniLabel5->LayoutConfig->Flex = 1;
	UniLabel6->LayoutConfig->Flex = 1;
	UniLabel7->LayoutConfig->Flex = 1;
	UniLabel5->LayoutConfig->Height = L"90%";
	UniLabel6->LayoutConfig->Height = L"90%";
	UniLabel7->LayoutConfig->Height = L"90%";

	UniLabel5->Font->Color = clWhite;
	UniLabel5->Font->Size = 15;
	// UniLabel5->Caption = menuitem_home;
	UniLabel5->Caption = UnicodeString(welcome_prefix) + mmodule->login_name;
	UniLabel6->Font->Color = clWhite;
	UniLabel6->Font->Size = 15;
	UniLabel6->Caption = menuitem_pay_record;
	UniLabel7->Font->Color = clWhite;
	UniLabel7->Font->Size = 15;
	UniLabel7->Caption = menuitem_help;

	UniPanel2->Layout = L"vbox";
	UniContainerPanel4->LayoutConfig->Width = L"100%";
	UniContainerPanel4->LayoutConfig->Flex = 1;
	UniContainerPanel4->LayoutConfig->Margin = L"0 0 15 0";
	UniContainerPanel4->Color = 0xf3f4f8;
	UniContainerPanel5->LayoutConfig->Width = L"100%";
	UniContainerPanel5->LayoutConfig->Flex = 1;
	UniContainerPanel5->LayoutConfig->Margin = L"15 0 0 0";
	UniContainerPanel5->Color = 0xf3f4f8;

	UniContainerPanel4->Layout = L"hbox";
	UniContainerPanel6->LayoutConfig->Height = L"100%";
	UniContainerPanel6->Width = 100;
	UniContainerPanel6->Layout = L"vbox";
	UniLabel8->Caption = dev_purchase[0];
	UniLabel10->Caption = dev_purchase[1];
	UniLabel11->Caption = dev_purchase[2];
	UniLabel12->Caption = dev_purchase[3];
	// UniLabel8->LayoutConfig->Flex = 1;
	UniLabel8->LayoutConfig->Flex = 3;
	UniLabel8->LayoutConfig->Width = L"100%";
	UniLabel12->LayoutConfig->Flex = 3;
	UniLabel12->LayoutConfig->Width = L"100%";
	UniLabel10->LayoutConfig->Flex = 1;
	UniLabel10->LayoutConfig->Width = L"100%";
	UniLabel11->LayoutConfig->Flex = 1;
	UniLabel11->LayoutConfig->Width = L"100%";

	UniLabel8->Font->Color = clWhite;
	UniLabel10->Font->Color = clWhite;
	UniLabel11->Font->Color = clWhite;
	UniLabel12->Font->Color = clWhite;

	UniLabel8->Font->Size = 30;
	UniLabel10->Font->Size = 30;
	UniLabel11->Font->Size = 30;
	UniLabel12->Font->Size = 30;

	// UniLabel8->LayoutConfig->Padding = L"30 0 0 25";
	UniLabel8->LayoutConfig->Padding = L"80 0 0 30";
	UniLabel10->LayoutConfig->Padding = L"0 0 0 30";
	// UniLabel10->LayoutConfig->Padding = L"0 0 0 25";
	UniLabel11->LayoutConfig->Padding = L"0 0 0 30";
	UniLabel12->LayoutConfig->Padding = L"0 0 0 30";

	UniContainerPanel8->LayoutConfig->Height = L"100%";
	UniContainerPanel8->LayoutConfig->Flex = 1;

	UniContainerPanel5->Layout = L"hbox";
	UniContainerPanel7->LayoutConfig->Height = L"100%";
	UniContainerPanel7->Width = 100;

	UniContainerPanel9->LayoutConfig->Height = L"100%";
	UniContainerPanel9->LayoutConfig->Flex = 1;

	UniContainerPanel7->Layout = L"vbox";

	UniLabel9->Caption = srv_purchase[0];
	UniLabel13->Caption = srv_purchase[1];
	UniLabel14->Caption = srv_purchase[2];
	UniLabel15->Caption = srv_purchase[3];
	// UniLabel15->Caption = login_name;
	UniLabel9->LayoutConfig->Flex = 3;
	UniLabel9->LayoutConfig->Width = L"100%";
	UniLabel13->LayoutConfig->Flex = 1;
	UniLabel13->LayoutConfig->Width = L"100%";
	UniLabel14->LayoutConfig->Flex = 1;
	UniLabel14->LayoutConfig->Width = L"100%";
	UniLabel15->LayoutConfig->Flex = 3;
	UniLabel15->LayoutConfig->Width = L"100%";

	UniLabel9->Font->Color = clWhite;
	UniLabel13->Font->Color = clWhite;
	UniLabel14->Font->Color = clWhite;
	UniLabel15->Font->Color = clWhite;

	UniLabel9->Font->Size = 30;
	UniLabel13->Font->Size = 30;
	UniLabel14->Font->Size = 30;
	UniLabel15->Font->Size = 30;

	UniLabel9->LayoutConfig->Padding = L"80 0 0 30";
	UniLabel13->LayoutConfig->Padding = L"0 0 0 30";
	UniLabel14->LayoutConfig->Padding = L"0 0 0 30";
	UniLabel15->LayoutConfig->Padding = L"0 0 0 30";

	UniContainerPanel8->Layout = L"vbox";
	UniContainerPanel8->LayoutConfig->Padding = L"10 30";

	UniLabel16->Caption = purchase_hint1;
	UniContainerPanel10->LayoutConfig->Flex = 1;
	UniContainerPanel10->LayoutConfig->Width = L"100%";

	UniContainerPanel10->Layout = L"hbox";
	UniContainerPanel10->LayoutConfig->Padding = L"15 0";
	UniPanel4->LayoutConfig->Height = L"100%";
	UniPanel4->LayoutConfig->Flex = 1;
	UniPanel5->LayoutConfig->Height = L"100%";
	UniPanel5->LayoutConfig->Flex = 1;
	UniPanel4->LayoutConfig->Margin = L"10 5 10 10";
	UniPanel5->LayoutConfig->Margin = L"10 10 10 5";

	UniPanel4->Layout = L"hbox";
	UniContainerPanel12->LayoutConfig->Flex = 6;
	UniContainerPanel11->LayoutConfig->Flex = 4;
	UniContainerPanel12->LayoutConfig->Height = L"100%";
	UniContainerPanel11->LayoutConfig->Height = L"100%";

	UniContainerPanel11->Layout = L"fit";
	UniContainerPanel11->LayoutConfig->Padding = L"40";
	UniImage1->Center = true;
	UniImage1->Proportional = true;
	UniImage1->Stretch = true;

	UniContainerPanel12->Layout = L"vbox";
	UniLabel17->Caption = org_price_dev;
	UniLabel17->LayoutConfig->Flex = 1;
	UniContainerPanel12->LayoutConfig->Padding = L"30";
	UniContainerPanel13->LayoutConfig->Flex = 2;
	UniButton1->Caption = instant_cash;
	UniContainerPanel13->Layout = L"hbox";
	UniLabel20->LayoutConfig->Flex = 1;
	UniLabel19->Text = preferential_price_dev;
	UniLabel20->Text = new_price_dev;
	UniLabel20->Font->Size = 30;
	UniLabel20->Font->Color = clHighlight;
	UniLabel21->Text = m_unit;
	UniLabel18->Text = descr_board;
	UniLabel18->LayoutConfig->Flex = 1;
	UniLabel18->Font->Size = 12;
	UniLabel18->Font->Style = UniLabel18->Font->Style << fsBold;
	UniLabel19->LayoutConfig->Margin = L"25% 0 0 0";
	UniLabel21->LayoutConfig->Margin = L"25% 0 0 0";
	UniContainerPanel14->Layout = L"hbox";
	UniContainerPanel14->LayoutConfig->Padding = L"0";
	UniContainerPanel14->LayoutConfig->Flex = 1;
	UniContainerPanel14->LayoutConfig->Margin = L"0 0 5 0";
	UniContainerPanel14->LayoutConfig->Width = L"100%";
	UniCheckBox1->Caption = receiving_agent;
	UniCheckBox2->Caption = direct_receipt;
	UniCheckBox1->LayoutConfig->Flex = 1;
	UniCheckBox1->LayoutConfig->Height = L"100%";
	UniCheckBox2->LayoutConfig->Flex = 1;
	UniCheckBox2->LayoutConfig->Height = L"100%";

	UniPanel5->Layout = L"hbox";
	UniImage3->LayoutConfig->Flex = 1;
	UniContainerPanel18->LayoutConfig->Flex = 4;
	UniContainerPanel18->LayoutConfig->Height = L"100%";
	UniContainerPanel18->Layout = L"fit";

	UniContainerPanel15->LayoutConfig->Flex = 6;
	UniContainerPanel15->LayoutConfig->Height = L"100%";
	UniContainerPanel18->LayoutConfig->Padding = L"40";

	UniContainerPanel15->Layout = L"vbox";
	UniContainerPanel15->LayoutConfig->Padding = L"30";
	UniLabel22->Caption = org_price_pen;
	UniLabel22->Font->Size = 12;
	UniLabel23->Caption = preferential_price_dev;
	UniLabel24->Caption = new_price_pen;
	UniLabel25->Caption = m_unit;
	UniLabel26->Caption = descr_pen;
	UniCheckBox3->Caption = receiving_agent;
	UniCheckBox4->Caption = direct_receipt;
	UniButton2->Caption = instant_cash;

	UniLabel22->LayoutConfig->Flex = 1;
	UniContainerPanel16->LayoutConfig->Flex = 2;
	UniContainerPanel16->Layout = L"hbox";
	UniLabel26->LayoutConfig->Flex = 1;
	UniContainerPanel17->LayoutConfig->Flex = 1;
	UniContainerPanel17->Layout = L"hbox";
	UniCheckBox3->LayoutConfig->Flex = 1;
	UniCheckBox4->LayoutConfig->Flex = 1;
	UniCheckBox3->LayoutConfig->Height = L"100%";
	UniCheckBox4->LayoutConfig->Height = L"100%";
	UniLabel26->Font->Size = 12;
	UniLabel26->Font->Style = UniLabel18->Font->Style << fsBold;
	UniLabel24->LayoutConfig->Flex = 1;
	UniLabel24->Font->Size = 30;
	UniLabel24->Font->Color = clHighlight;

	UniLabel24->LayoutConfig->Flex = 1;
	UniLabel25->LayoutConfig->Margin = L"25% 0 0 0";
	UniLabel23->LayoutConfig->Margin = L"25% 0 0 0";

	UniLabel27->Caption = purchase_hint2;
	UniContainerPanel9->Layout = L"vbox";
	UniContainerPanel9->LayoutConfig->Padding = L"10 30";
	UniContainerPanel19->Layout = L"hbox";
	UniContainerPanel19->LayoutConfig->Flex = 1;
	UniContainerPanel19->LayoutConfig->Width = L"100%";
	UniContainerPanel19->LayoutConfig->Padding = L"15 0";

	UniPanel6->LayoutConfig->Height = L"100%";
	UniPanel7->LayoutConfig->Height = L"100%";
	UniPanel8->LayoutConfig->Height = L"100%";

	UniPanel6->LayoutConfig->Flex = 1;
	UniPanel7->LayoutConfig->Flex = 1;
	UniPanel8->LayoutConfig->Flex = 1;
	UniPanel6->LayoutConfig->Margin = L"10";
	UniPanel7->LayoutConfig->Margin = L"10";
	UniPanel8->LayoutConfig->Margin = L"10";

	UniPanel6->LayoutConfig->Padding = L"15";
	UniPanel7->LayoutConfig->Padding = L"15";
	UniPanel8->LayoutConfig->Padding = L"15";

	UniLabel28->Caption = full_amount;
	UniLabel28->Font->Size = 22;
	UniLabel28->Font->Style = UniLabel28->Font->Style << fsBold;

	UniLabel29->Caption = has_discount_full;
	UniLabel29->Font->Size = 16;
	UniLabel29->Font->Style = UniLabel29->Font->Style << fsItalic;
	UniLabel30->Caption = total_after_discount;
	UniLabel30->Font->Size = 17;
	UniLabel30->Font->Style = UniLabel30->Font->Style << fsUnderline;
	UniLabel30->Font->Color = clHotLight;
	UniLabel31->Caption = full_amount_hint;
	UniLabel31->Font->Size = 10;
	UniLabel32->Caption = L"";
	// UniCheckBox5->Caption = accept_term;
	// UniCheckBox5->Caption = annual_buy_protocol;
	UniCheckBox5->Caption = L"";
	UniLabel43->Caption = annual_buy_protocol;
	UniButton3->Caption = instant_cash;

	// UniCheckBox6->Caption = accept_term;
	// UniCheckBox6->Caption = annual_buy_protocol;
	UniCheckBox6->Caption = L"";
	UniLabel44->Caption = annual_buy_protocol;
	UniButton4->Caption = instant_cash;
	UniLabel33->Caption = annual;
	UniLabel34->Caption = annual_fee;
	UniLabel35->Caption = amount_annual_fee;
	UniLabel37->Caption = L"";
	UniLabel36->Caption = annual_hint;
	UniLabel33->Font->Size = 22;
	UniLabel33->Font->Style = UniLabel33->Font->Style << fsBold;
	UniLabel34->Font->Size = 16;
	UniLabel34->Font->Style = UniLabel34->Font->Style << fsItalic;
	UniLabel35->Font->Size = 17;
	UniLabel35->Font->Style = UniLabel35->Font->Style << fsUnderline;
	UniLabel35->Font->Color = clHotLight;
	UniLabel36->Font->Size = 10;

	UniButton5->Caption = instant_cash;
	// UniCheckBox7->Caption = accept_term;
	// UniCheckBox7->Caption = zero_to_buy_protocol;
	UniCheckBox7->Caption = L"";
	UniLabel45->Caption = zero_to_buy_protocol;
	UniLabel42->Caption = L"";
	UniLabel38->Caption = zero;
	UniLabel38->Font->Size = 22;
	UniLabel38->Font->Style = UniLabel38->Font->Style << fsBold;
	UniLabel39->Font->Size = 16;
	UniLabel39->Font->Style = UniLabel39->Font->Style << fsItalic;
	UniLabel39->Caption = recommendation;
	UniLabel40->Caption = amount_zero;
	UniLabel40->Font->Size = 17;
	UniLabel40->Font->Style = UniLabel40->Font->Style << fsUnderline;
	UniLabel40->Font->Color = clHotLight;
	UniLabel41->Caption = zero_hint;
	UniLabel41->Font->Size = 10;

	UniButton3->Enabled = false;
	UniButton4->Enabled = false;
	UniButton5->Enabled = false;

	UniCheckBox1->Checked = false;
	UniCheckBox2->Checked = true;
	UniCheckBox3->Checked = false;
	UniCheckBox4->Checked = true;

	if (mmodule->schl_id) {
		str = L"students_" + UnicodeString(mmodule->schl_id);

		mmodule->UniQuery1->SQL->Clear();
		mmodule->UniQuery1->SQL->Add(Sysutils::Format(L"select grade from %s where stid = %d;",
			ARRAYOFCONST((str, mmodule->usr_id))));

		mmodule->UniQuery1->Execute();

		if (1 == mmodule->UniQuery1->RecordCount) {
			mmodule->stu_grade = mmodule->UniQuery1->FieldByName(L"grade")->AsInteger;
			mmodule->UniQuery1->SQL->Clear();
			mmodule->UniQuery1->SQL->Add(Sysutils::Format(L"select fee, for_phase from plan where scid = %d;",
				ARRAYOFCONST((mmodule->schl_id))));

			mmodule->UniQuery1->Execute();
			mmodule->UniQuery1->First();
			for (j = 0; j < mmodule->UniQuery1->RecordCount; ++j) {

				k = mmodule->UniQuery1->FieldByName(L"for_phase")->AsInteger;

				if (k < 10) {
					if (mmodule->stu_grade != k);
					else {
						mmodule->fee_presetting = mmodule->UniQuery1->FieldByName(L"fee")->AsString;
						UniLabel30->Caption = UnicodeString(preferential_price_prefix) + mmodule->fee_presetting +
							UnicodeString(preferential_price_suffix);
						break;
					}
				}

				mmodule->UniQuery1->Next();
			}
		}
	}

	// NetHTTPRequest1->Client = UniServerModule()->NetHTTPClient1;
	NetHTTPRequest1->Client = NetHTTPClient1;
	NetHTTPRequest1->Asynchronous = false;
}

// ---------------------------------------------------------------------------
/*
 int i;
 int l = Edit1->Text.Length();
 String x = Edit1->Text;
 UnicodeString r(L"");
 for (i = 1; i <= l; ++i) {
 r += UnicodeString(L"0x") + IntToHex(int(x[i]), 2) + String(L",");
 }
 Byte();
 r += L"0x0";
 Edit2->Text = r;
 */
void __fastcall TMainForm::UniFormBeforeShow(TObject *Sender) {
	if (!mmodule->archived) {
		TUniFormSignUp_1 *form_signup1 = (TUniFormSignUp_1*)UniMainModule()->GetFormInstance
			(__classid(TUniFormSignUp_1));
		form_signup1->ShowModal();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniCheckBox5Click(TObject *Sender) {
	// protocol_flag = 3000;
	// TUniForm2 *form_orders_protocol = (TUniForm2*)UniMainModule()->GetFormInstance(__classid(TUniForm2));
	// form_orders_protocol->ShowModal();
	// // if (form_orders_protocol->Tag) {
	// // UniCheckBox5->Checked = true;
	// // }
	// // else {
	// // UniCheckBox5->Checked = false;
	// // }
	// // if (form_orders_protocol->ModalResult == mrOk) {
	// // UniCheckBox5->Checked = true;
	// // }
	// // else {
	// // UniCheckBox5->Checked = false;
	// // }
	// if (agree_values[0]) {
	// UniCheckBox5->Checked = true;
	// }
	// else {
	// UniCheckBox5->Checked = false;
	// }

	if (UniCheckBox5->Checked) {
		UniButton3->Enabled = true;
		UniCheckBox6->Checked = false;
		UniButton4->Enabled = false;
		UniCheckBox7->Checked = false;
		UniButton5->Enabled = false;
	}
	else {
		UniButton3->Enabled = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniCheckBox6Click(TObject *Sender) {
	// protocol_flag = 3000;
	// TUniForm2 *form_orders_protocol = (TUniForm2*)UniMainModule()->GetFormInstance(__classid(TUniForm2));
	// form_orders_protocol->ShowModal();
	// if (form_orders_protocol->ModalResult == mrOk) {
	// UniCheckBox6->Checked = true;
	// }
	// else {
	// UniCheckBox6->Checked = false;
	// }
	if (UniCheckBox6->Checked) {
		UniButton4->Enabled = true;
		UniCheckBox5->Checked = false;
		UniButton3->Enabled = false;
		UniCheckBox7->Checked = false;
		UniButton5->Enabled = false;
	}
	else {
		UniButton4->Enabled = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniCheckBox7Click(TObject *Sender) {
	// protocol_flag = 4000;
	// TUniForm2 *form_orders_protocol = (TUniForm2*)UniMainModule()->GetFormInstance(__classid(TUniForm2));
	// form_orders_protocol->ShowModal();
	// if (form_orders_protocol->ModalResult == mrOk) {
	// UniCheckBox7->Checked = true;
	// }
	// else {
	// UniCheckBox7->Checked = false;
	// }
	if (UniCheckBox7->Checked) {
		UniButton5->Enabled = true;
		UniCheckBox5->Checked = false;
		UniButton3->Enabled = false;
		UniCheckBox6->Checked = false;
		UniButton4->Enabled = false;

	}
	else {
		UniButton5->Enabled = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniLabel43Click(TObject *Sender) {
	mmodule->protocol_flag = 3000;
	TUniForm1 *form_protocol = (TUniForm1*)UniMainModule()->GetFormInstance(__classid(TUniForm1));
	form_protocol->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniLabel44Click(TObject *Sender) {
	mmodule->protocol_flag = 4000;
	TUniForm1 *form_protocol = (TUniForm1*)UniMainModule()->GetFormInstance(__classid(TUniForm1));
	form_protocol->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniLabel45Click(TObject *Sender) {
	mmodule->protocol_flag = 5000;
	TUniForm1 *form_protocol = (TUniForm1*)UniMainModule()->GetFormInstance(__classid(TUniForm1));
	form_protocol->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniCheckBox1Change(TObject *Sender) {

	if (UniCheckBox1->Checked) {
		UniCheckBox2->Checked = false;
	}
	else {
		UniCheckBox2->Checked = true;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniCheckBox2Change(TObject *Sender) {
	if (UniCheckBox2->Checked) {
		UniCheckBox1->Checked = false;
	}
	else {
		UniCheckBox1->Checked = true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniCheckBox3Click(TObject *Sender) {
	if (UniCheckBox3->Checked) {
		UniCheckBox4->Checked = false;
	}
	else {
		UniCheckBox4->Checked = true;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniCheckBox4Click(TObject *Sender) {
	if (UniCheckBox4->Checked) {
		UniCheckBox3->Checked = false;
	}
	else {
		UniCheckBox3->Checked = true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniButton1Click(TObject *Sender) {
	// ShowMessage(alipay_hint);
	TStringList *sl = new TStringList();
	TStringList *sl1 = new TStringList();
	int i;
	TUniPagePayment *pagepay;
	UnicodeString ts;
	UnicodeString r;
#ifdef _DEBUG
	UnicodeString amount = L"0.01";
#else
	UnicodeString amount = L"799";
#endif
	UnicodeString product_name = descr_board;
	prodc_name = descr_board;
	mmodule->build_post_params((TList *)sl, &amount, &product_name, &product_name);

	r = NetHTTPRequest1->Post(L"https://epay.qsbank.cc/epaygate/pay.htm", sl, 0, mmodule->encd)->ContentAsString
		(mmodule->encd);

	ts = L"action=";
	i = r.Pos(ts);
	if (i) {
		r.Delete(1, i + ts.Length());
		ts = L"\"";
		i = r.Pos(ts);
		r = r.SubString(1, i - 1);
		// UniSession()->BrowserWindow(r, 1024, 768, L"_blank");
		// session->BrowserWindow(r, 1024, 768, L"_blank");
		// UniSession()->AddJS(Sysutils::Format(L"location.href=\"%s\"", ARRAYOFCONST((r))));
		// UniSession()->UrlRedirect(r);
		// session->UrlRedirect(L"https:\\www.google.com");

		sl->Find(L"out_trade_no", i);
		ts = sl->Values[sl->Names[i]];

		order_num = ts;

		pagepay = (TUniPagePayment*)UniMainModule()->GetFormInstance(__classid(TUniPagePayment));
		pagepay->UniURLFrame1->URL = r;
		pagepay->ShowModalN();
	}
	delete sl1;
	delete sl;

	// // TStringStream * fs = new TStringStream();
	// // fs->LoadFromStream(AResponse->GetContentStream());
	// // fs->SaveToFile(L"files\\abc.html");
	// // UnicodeString ww =UniServerModule()->FilesFolderURL + L"abc.html";
	// // UnicodeString r = AResponse->ContentAsString(encd);
	// // //UniSession()->BrowserWindow(L"files\\abc.html", 400, 300, L"_blank");
	// // session->BrowserWindow(ww, 400, 300, L"_blank");
	// // delete fs;
	// // -------------------------try--------------------------------------------
	// int i;
	// TUniPagePayment *pagepay;
	// UnicodeString ts;
	// UnicodeString r = AResponse->ContentAsString(encd);
	// ts = L"action=";
	// i = r.Pos(ts);
	// if (i) {
	// r.Delete(1, i + ts.Length());
	// ts = L"\"";
	// i = r.Pos(ts);
	// r = r.SubString(1, i - 1);
	// // UniSession()->BrowserWindow(r, 1024, 768, L"_blank");
	// // session->BrowserWindow(r, 1024, 768, L"_blank");
	// // UniSession()->AddJS(Sysutils::Format(L"location.href=\"%s\"", ARRAYOFCONST((r))));
	// // UniSession()->UrlRedirect(r);
	// // session->UrlRedirect(L"https:\\www.google.com");
	// pagepay = (TUniPagePayment*)UniMainModule()->GetFormInstance(__classid(TUniPagePayment));
	// pagepay->UniURLFrame1->URL = r;
	// }
	// // -------------------------try--------------------------------------------
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniButton2Click(TObject *Sender) {
	// ShowMessage(alipay_hint);
	TStringList *sl = new TStringList();
	int i;
	TUniPagePayment *pagepay;
	UnicodeString ts;
	UnicodeString r;
	UnicodeString amount = L"60";
	UnicodeString product_name = descr_pen;
	prodc_name = descr_pen;
	mmodule->build_post_params((TList *)sl, &amount, &product_name, &product_name);

	r = NetHTTPRequest1->Post(L"https://epay.qsbank.cc/epaygate/pay.htm", sl, 0, mmodule->encd)->ContentAsString
		(mmodule->encd);

	ts = L"action=";
	i = r.Pos(ts);
	if (i) {
		r.Delete(1, i + ts.Length());
		ts = L"\"";
		i = r.Pos(ts);
		r = r.SubString(1, i - 1);

		sl->Find(L"out_trade_no", i);
		ts = sl->Values[sl->Names[i]];

		order_num = ts;

		pagepay = (TUniPagePayment*)UniMainModule()->GetFormInstance(__classid(TUniPagePayment));
		pagepay->UniURLFrame1->URL = r;
		pagepay->ShowModalN();
	}
	delete sl;

}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniButton5Click(TObject *Sender) {
	// ShowMessage(alipay_hint);
	TStringList *sl = new TStringList();
	int i;
	TUniPagePayment *pagepay;
	UnicodeString ts;
	UnicodeString r;
	UnicodeString amount = L"3800";
	UnicodeString product_name = zero;
	prodc_name = zero;
	mmodule->build_post_params((TList *)sl, &amount, &product_name, &product_name);

	r = NetHTTPRequest1->Post(L"https://epay.qsbank.cc/epaygate/pay.htm", sl, 0, mmodule->encd)->ContentAsString
		(mmodule->encd);

	ts = L"action=";
	i = r.Pos(ts);
	if (i) {
		r.Delete(1, i + ts.Length());
		ts = L"\"";
		i = r.Pos(ts);
		r = r.SubString(1, i - 1);

		sl->Find(L"out_trade_no", i);
		ts = sl->Values[sl->Names[i]];

		order_num = ts;

		pagepay = (TUniPagePayment*)UniMainModule()->GetFormInstance(__classid(TUniPagePayment));
		pagepay->UniURLFrame1->URL = r;
		pagepay->ShowModalN();
	}
	delete sl;
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniButton4Click(TObject *Sender) {
	// ShowMessage(alipay_hint);
	TStringList *sl = new TStringList();
	int i;
	TUniPagePayment *pagepay;
	UnicodeString ts;
	UnicodeString r;
	UnicodeString amount = L"720";
	UnicodeString product_name = annual;
	prodc_name = annual;
	mmodule->build_post_params((TList *)sl, &amount, &product_name, &product_name);

	r = NetHTTPRequest1->Post(L"https://epay.qsbank.cc/epaygate/pay.htm", sl, 0, mmodule->encd)->ContentAsString
		(mmodule->encd);

	ts = L"action=";
	i = r.Pos(ts);
	if (i) {
		r.Delete(1, i + ts.Length());
		ts = L"\"";
		i = r.Pos(ts);
		r = r.SubString(1, i - 1);

		sl->Find(L"out_trade_no", i);
		ts = sl->Values[sl->Names[i]];

		order_num = ts;

		pagepay = (TUniPagePayment*)UniMainModule()->GetFormInstance(__classid(TUniPagePayment));
		pagepay->UniURLFrame1->URL = r;
		pagepay->ShowModalN();
	}
	delete sl;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniButton3Click(TObject *Sender) {
	// ShowMessage(alipay_hint);
	TStringList *sl = new TStringList();
	int i;
	TUniPagePayment *pagepay;
	UnicodeString ts;
	UnicodeString r;
	UnicodeString amount = mmodule->fee_presetting;
	UnicodeString product_name = full_amount;
	prodc_name = full_amount;
	mmodule->build_post_params((TList *)sl, &amount, &product_name, &product_name);

	r = NetHTTPRequest1->Post(L"https://epay.qsbank.cc/epaygate/pay.htm", sl, 0, mmodule->encd)->ContentAsString
		(mmodule->encd);

	ts = L"action=";
	i = r.Pos(ts);
	if (i) {
		r.Delete(1, i + ts.Length());
		ts = L"\"";
		i = r.Pos(ts);
		r = r.SubString(1, i - 1);

		sl->Find(L"out_trade_no", i);
		ts = sl->Values[sl->Names[i]];

		order_num = ts;

		pagepay = (TUniPagePayment*)UniMainModule()->GetFormInstance(__classid(TUniPagePayment));
		pagepay->UniURLFrame1->URL = r;
		pagepay->ShowModalN();
	}
	delete sl;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniTimer1Timer(TObject *Sender) {
	int i, j;
	UnicodeString r;
	UnicodeString prefix = L"BANK_R:";
	UnicodeString url = L"http://localhost:38361/?out_trade_no=" + order_num;
	bank_feedback bf;
	NetHTTPRequest1->URL = url;
	NetHTTPRequest1->MethodString = "GET";
	r = NetHTTPRequest1->Execute()->ContentAsString();
	if (r.Length() > prefix.Length()) {
		r = r.SubString(prefix.Length() + 1, r.Length() - prefix.Length());
		j = 0;
		while (i = r.Pos(L",")) {
			bf[j++] = r.SubString(1, i - 1);
			r.Delete(1, i);
		}
		i = StrToInt(bf[1]);
		if (!i) {
			prefix = L"支付成功";
		}
		else if (1 == i) {
			prefix = L"支付失败";
		}
		else if (3 == i) {
			prefix = L"支付正在处理中";
		}
		mmodule->UniSQL1->SQL->Clear();
		mmodule->UniSQL1->SQL->Add
			(Sysutils::Format
			(L"insert into orders(stuid, sclid, order_num, payment_status, payment_status_chinese, trade_num, money, time_end, product_descr) values(%d, %d, '%s', %d, '%s', '%s', '%s', '%s', '%s');",
			ARRAYOFCONST((mmodule->usr_id, mmodule->schl_id, order_num, i, prefix, bf[2], bf[3], bf[4], prodc_name))));

		if (mmodule->UniConnection1->InTransaction);
		else {
			mmodule->UniConnection1->StartTransaction();
			try {
				mmodule->UniSQL1->Execute();
				mmodule->UniConnection1->Commit();
			}
			catch (...) {
				mmodule->UniConnection1->Rollback();
			}
		}

		UniTimer1->Enabled = false;

		if (!i) {
			this->ShowToast(payment_completion_hint);
		}
		else if (1 == i) {
			this->ShowToast(payment_failure_hint);
		}
		else if (3 == i) {
			this->ShowToast(payment_pending_hint);
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniLabel6Click(TObject *Sender) {
	TUniForm2 *orders = (TUniForm2*)UniMainModule()->GetFormInstance(__classid(TUniForm2));
	orders->ShowModalN();
}
// ---------------------------------------------------------------------------
