// ---------------------------------------------------------------------------

#include <vcl.h>
#include <UniGUIApplication.hpp>
#include <UniGUIVars.hpp>
#pragma hdrstop

#include "MainModule.h"
#include <System.SysUtils.hpp>
#include <System.Hash.hpp>
#include "ServerModule.h"
#include "PagePayment.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MySQLUniProvider"
#pragma link "UniProvider"
#pragma link "DBAccess"
#pragma link "Uni"
#pragma link "DAScript"
#pragma link "UniScript"
#pragma link "MemDS"
#pragma resource "*.dfm"

using namespace std;

// 改为你自己的数据库名
#define DBNAME "db_kz_fee0"

const UnicodeString params_name[] = {
	L"service", L"service_version", L"input_charset", L"partner", L"out_trade_no", L"fee_type", L"total_fee",
	L"subject", L"body", L"show_url", L"spbill_create_ip", L"trade_mode", L"trans_channel", L"return_url",
	L"secret_key", L"sign", L"sign_type", L"request_url"};

// L"http://localhost:38361/files/result.html"
#ifdef _DEBUG
const UnicodeString params_value[] = {
	L"pay_service", L"1.0", L"utf-8", L"12093446", L"", L"1", L"", L"", L"", L"http://pay.jianxiangjiaoyu.com", L"",
	L"0002", L"pc", L"http://localhost:38361/files/result.html", L"jxjy1123", L"", L"MD5",
	L"https://epay.qsbank.cc/epaygate/pay.htm"};
#else
const UnicodeString params_value[] = {
	L"pay_service", L"1.0", L"utf-8", L"12093446", L"", L"1", L"", L"", L"", L"http://pay.jianxiangjiaoyu.com", L"",
	L"0002", L"pc", L"http://pay.jianxiangjiaoyu.com:38361/files/result.html", L"jxjy1123", L"", L"MD5",
	L"https://epay.qsbank.cc/epaygate/pay.htm"};
#endif
// L"http://pay.jianxiangjiaoyu.com/files/result.html"

// ---------------------------------------------------------------------------
TUniMainModule *UniMainModule(void) {
	return ((TUniMainModule*)UniApplication()->UniMainModule_);
}

// ---------------------------------------------------------------------------
__fastcall TUniMainModule::TUniMainModule(TComponent* Owner, TComponent* AUniApplication)
	: TUniGUIMainModule(Owner, AUniApplication) {
	encd = TEncoding::GetEncoding(65001);
	stu_grade = 0;
	schl_id = 0;
	key = "EncryptionPassword";
}
// ---------------------------------------------------------------------------

void __RegisterMainModuleClass() {
	Uniguivars::RegisterMainModuleClass(__classid(TUniMainModule));
}

#pragma startup __RegisterMainModuleClass

// ---------------------------------------------------------------------------
void __fastcall TUniMainModule::UniGUIMainModuleCreate(TObject *Sender) {

	UniConnection1->ProviderName = L"MySQL";
	// If the Server property is empty for MySQL, UniDAC will try to connect to localhost.
	// UniConnection1->Server = L"localhost";
	// The default value is 3306.
	// UniConnection1->Port = 3306;
	UniConnection1->Username = L"root";
	// 修改为你自己的密码
	UniConnection1->Password = L"MyPassword";
	// By default, Direct is set to True.
	// UniConnection1->SpecificOptions->Values["Direct"] = L"True";
	UniConnection1->LoginPrompt = false;
	UniConnection1->Database = DBNAME;
	UniScript1->Connection = UniConnection1;
	UniConnection1->Connect();
}

// ---------------------------------------------------------------------------

void __fastcall TUniMainModule::generate_guid(UnicodeString *str_guid) {
	int i;
	TGUID id;
	if (CreateGUID(id))
		goto end;
	else
		*str_guid = GUIDToString(id);
	while (i = str_guid->Pos(L"-")) {
		str_guid->Delete(i, 1);
	}
	str_guid->Delete(str_guid->Length(), 1);
	str_guid->Delete(1, 1);
end: ;
}

void __fastcall TUniMainModule::generate_md5(UnicodeString *md5_str, UnicodeString *original) {
	*md5_str = THashMD5::GetHashString(*original);
}

void __fastcall TUniMainModule::build_post_params(TList *post_params, UnicodeString *fee, UnicodeString *pn,
	UnicodeString *pd) {
	int i, j, k;
	TStringList *sl = new TStringList();
	TStringList *p_str_list = (TStringList*)post_params;
	UnicodeString temps;
	UnicodeString md5;

	int sequence[request_url + 1] = {0};
	PAY_PARAMS temp_p;
	PAY_PARAMS temp_p1;

	for (i = srv_type; i < secret_key; ++i) {
		temp_p[i] = params_value[i];
	}

	temp_p[total_fee] = *fee;
	temp_p[prod_name] = *pn;
	temp_p[prod_desc] = *pd;
	temp_p[client_ip] = UniSession()->RemoteIP;
	generate_guid(&temps);
	temp_p[order_no] = temps;

	for (i = srv_type; i < secret_key; ++i) {
		sl->Add(params_name[i]);
	}

	sl->Sort();
	k = 0;
	for (i = 0; i < sl->Count; i++) {
		for (j = srv_type; j < secret_key; j++) {
			if (sl->operator[](i) != params_name[j]);
			else
				break;
		}
		sequence[k++] = j;
	}

	for (i = 0; i < k; ++i) {
		temp_p1[i] = params_name[sequence[i]] + UnicodeString(L"=") + temp_p[sequence[i]];
	}

	temps = L"";
	for (i = 0; i < k; ++i) {
		temps += temp_p1[i] + UnicodeString(L"&");
	}
	temps.Delete(temps.Length(), 1);

	temps += params_value[secret_key];

	generate_md5(&md5, &temps);

	p_str_list->Clear();

	for (i = 0; i < k; ++i) {
		p_str_list->AddPair(params_name[sequence[i]], temp_p[sequence[i]]);
	}
	p_str_list->AddPair(params_name[signature], md5);
	p_str_list->AddPair(params_name[signature_type], params_value[signature_type]);
	delete sl;
}

void __fastcall TUniMainModule::try_to_buy(UnicodeString *order_num, UnicodeString *money, UnicodeString *product_descr)
{
	UniSQL1->SQL->Clear();
	UniSQL1->SQL->Add
		(Sysutils::Format
		(L"insert into orders_trial(stuid, sclid, order_num, money, product_descr) values(%d, %d, '%s', '%s', '%s');",
		ARRAYOFCONST((usr_id, schl_id, *order_num, *money, *product_descr))));

	if (UniConnection1->InTransaction);
	else {
		UniConnection1->StartTransaction();
		try {
			UniSQL1->Execute();
			UniConnection1->Commit();
		}
		catch (...) {
			UniConnection1->Rollback();
		}
	}
}
