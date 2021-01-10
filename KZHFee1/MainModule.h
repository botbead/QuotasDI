// ---------------------------------------------------------------------------

#ifndef MainModuleH
#define MainModuleH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <UniGUIMainModule.hpp>
#include "MySQLUniProvider.hpp"
#include "UniProvider.hpp"
#include "DBAccess.hpp"
#include "Uni.hpp"
#include <Data.DB.hpp>
#include "DAScript.hpp"
#include "UniScript.hpp"
#include "MemDS.hpp"

enum pay_params_index {
	srv_type, srv_v, charset, account, order_no, currency, total_fee, prod_name, prod_desc, prod_show_url, client_ip,
	pay_mode, pay_dev, return_url, secret_key, signature, signature_type, request_url
};

enum chinese_school_grade {
	senior_middle_school1 = 1, senior_middle_school2, senior_middle_school3, junior_middle_school31 = 31,
	junior_middle_school32, junior_middle_school33, junior_middle_school41 = 41, junior_middle_school42,
	junior_middle_school43, junior_middle_school44, primary_school51 = 51, primary_school52, primary_school53,
	primary_school54, primary_school55, primary_school61 = 61, primary_school62, primary_school63, primary_school64,
	primary_school65, primary_school66, university
};

typedef UnicodeString PAY_PARAMS[request_url + 1];

// ---------------------------------------------------------------------------
class TUniMainModule : public TUniGUIMainModule {
__published: // IDE-managed Components
	TUniConnection *UniConnection1;
	TUniScript *UniScript1;
	TUniSQL *UniSQL1;
	TUniQuery *UniQuery1;
	TUniQuery *UniQueryOrders;
	TUniDataSource *UniDataSource1;

	void __fastcall UniGUIMainModuleCreate(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniMainModule(TComponent* Owner, TComponent* AUniApplication);

	// TStringList *params_from_bank;
	// UnicodeString rawQueryString;
	TEncoding *encd;

	const char *key;

	bool archived;
	int usr_type;
	int usr_id;
	UnicodeString login_name;
	UnicodeString pwd;

	int stu_grade;
	int schl_id;

	UnicodeString fee_presetting;

	int protocol_flag;

	void __fastcall generate_guid(UnicodeString *);
	void __fastcall generate_md5(UnicodeString *, UnicodeString *);
	void __fastcall build_post_params(TList *, UnicodeString *, UnicodeString*, UnicodeString *);
};

// ---------------------------------------------------------------------------
TUniMainModule *UniMainModule(void);
// ---------------------------------------------------------------------------
#endif
