// ---------------------------------------------------------------------------

#include <vcl.h>
#include <UniGUIVars.hpp>

#pragma hdrstop

#include <debugapi.h>
#include "ServerModule.h"
#include "MainModule.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DAScript"
#pragma link "DBAccess"
#pragma link "MySQLUniProvider"
#pragma link "Uni"
#pragma link "UniProvider"
#pragma link "UniScript"
#pragma resource "*.dfm"

// 改为你自己的数据库名
#define DBNAME "db_kz_fee0"

wchar_t app_title[] = {0x5EFA, 0x4EAB, 0x4E00, 0x677F, 0x901A, 0x670D, 0x52A1, 0x5E73, 0x53F0, 0x0};

// ---------------------------------------------------------------------------
TUniServerModule *UniServerModule(void) {
	return ((TUniServerModule*)UniGUIServerInstance());
}
// ---------------------------------------------------------------------------

__fastcall TUniServerModule::TUniServerModule(TComponent* Owner) : TUniGUIServerModule(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TUniServerModule::FirstInit() {
	Uniguivars::InitServerModule(this);
}
// ---------------------------------------------------------------------------

void __RegisterServerModuleClass() {
	Uniguivars::RegisterServerModuleClass(__classid(TUniServerModule));
}

#pragma startup __RegisterServerModuleClass

void __fastcall TUniServerModule::UniGUIServerModuleCreate(TObject *Sender) {
	// MainFormDisplayMode = mfPage;
	MainFormDisplayMode = mfWindow;
	Title = app_title;

	UniConnection1->ProviderName = L"MySQL";
	// If the Server property is empty for MySQL, UniDAC will try to connect to localhost.
	// UniConnection1->Server = L"localhost";
	// The default value is 3306.
	// UniConnection1->Port = 3306;
	UniConnection1->Username = L"root";
	// 修改为你自己的密码
	UniConnection1->Password = L"why1983316";
	// By default, Direct is set to True.
	// UniConnection1->SpecificOptions->Values["Direct"] = L"True";
	UniConnection1->LoginPrompt = false;
	UniConnection1->Connect();
	UniScript1->Connection = UniConnection1;
	UniScript1->SQL->Clear();
	UniScript1->SQL->Add
		(Sysutils::Format(L"create database if not exists %s character set utf8mb4 collate utf8mb4_general_ci;",
		ARRAYOFCONST((DBNAME))));
	UniScript1->Execute();
	// MySQL's Database value can be changed when the connection is active without reconnect.
	UniConnection1->Database = DBNAME;
	UniScript1->SQL->Clear();
	UniScript1->SQL->Add("create table if not exists usr_type( \
utype tinyint not null unique, \
descr varchar(30), \
rowid_2th integer primary key auto_increment \
);create table if not exists usr_weight( \
level integer not null unique, \
descr text, \
rowid_2th integer primary key auto_increment \
);create table if not exists agent(\
aid integer primary key,\
name varchar(64) not null,\
password varchar(128) not null,\
email varchar(100) not null unique,\
mobile char(15) not null unique,\
address varchar(100) not null, \
reseller_level integer not null,\
wholesale varchar(11),\
superior integer\
);create table if not exists school( \
scid integer primary key, \
school_name varchar(64) not null unique, \
contact varchar(20) not null, \
password varchar(128) not null, \
email varchar(100) not null,\
mobile varchar(15) not null, \
address varchar(100) not null, \
phase1 tinyint not null default 0, \
phase2 tinyint not null default 0, \
phase3 tinyint not null default 0, \
school_students_table varchar(110) not null, \
aid integer, \
foreign key(aid) references agent(aid) \
);create table if not exists plan( \
plan_id integer primary key auto_increment, \
cts datetime default current_timestamp, \
plan_presetting_date date as (date(cts)), \
fee varchar(11) not null, \
plan_start_with varchar(30), \
plan_end_with varchar(30), \
for_phase tinyint not null, \
kit_num integer, \
scid integer not null, \
foreign key(scid) references school(scid) \
);create table if not exists signup_step1( \
usr_id integer primary key auto_increment, \
signup_ts datetime default current_timestamp, \
pwd varchar(128) not null, \
usr_name varchar(64) not null unique, \
archived tinyint default 0, \
usr_type tinyint default 2,\
schl_id integer default 0\
)auto_increment = 100001;create table if not exists orders(\
oid integer primary key auto_increment,\
stuid integer not null,\
sclid integer not null,\
order_num char(32) not null,\
payment_status tinyint not null,\
payment_status_chinese varchar(10) not null default '支付正在处理中',\
trade_num char(32) not null,\
money varchar(11) not null,\
time_end char(20) not null,\
product_descr varchar(100) not null,\
post_addr tinyint default 0, \
foreign key(sclid) references school(scid)\
)auto_increment=1000001;create table if not exists orders_trial(\
oid integer primary key auto_increment,\
stuid integer not null,\
sclid integer not null,\
order_num char(32) not null,\
cts datetime default current_timestamp, \
money varchar(11) not null,\
product_descr varchar(100) not null,\
foreign key(sclid) references school(scid)\
)auto_increment=1000001;");
	UniScript1->Execute();
	UniConnection1->Disconnect();
}
// ---------------------------------------------------------------------------

// void __fastcall TUniServerModule::UniGUIServerModuleHTTPCommand(TIdHTTPRequestInfo *ARequestInfo,
// TIdHTTPResponseInfo *AResponseInfo, bool &Handled) {
// // int i, j;
// // if (hcGET == ARequestInfo->CommandType && UnicodeString(L"/files/result.html") == ARequestInfo->Document) {
// // for (i = 0; i < ARequestInfo->Params->Count; ++i) {
// // // UniMainModule()->params_from_bank.insert
// // // (std::pair<UnicodeString, UnicodeString>(ARequestInfo->Params->Names[i],
// // // ARequestInfo->Params->Values[ARequestInfo->Params->Names[i]]));
// // //UnicodeString xo =  ARequestInfo->UnparsedParams;
// // }
// // UniSession()-->GetUniGUISession()
// // j = ARequestInfo->UnparsedParams.Length();
// // UniMainModule()->rawQueryString.SetLength(j++);
// // for (i = 1; i < j; ++i) {
// // UniMainModule()->rawQueryString[i] = ARequestInfo->UnparsedParams[i];
// // }
// //
// // Handled = true;
// // }
// }
