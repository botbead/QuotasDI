//---------------------------------------------------------------------------

#ifndef MainModuleH
#define MainModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <UniGUIMainModule.hpp>
#include "DAScript.hpp"
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "SQLiteUniProvider.hpp"
#include "Uni.hpp"
#include "UniProvider.hpp"
#include "UniScript.hpp"
#include <Data.DB.hpp>
//---------------------------------------------------------------------------
struct employee_quota
{
	UnicodeString name;
	double quota;
};

class TUniMainModule : public TUniGUIMainModule
{
__published:	// IDE-managed Components
	TSQLiteUniProvider *SQLiteUniProvider1;
	TUniConnection *UniConnection1;
	TUniQuery *UniQuery1;
	TUniScript *UniScript1;
	TUniQuery *uniq_proj_task;
	TUniDataSource *ds_proj_task;
	TUniQuery *uniq_proj_info;
	TUniDataSource *ds_proj_info;
	TUniQuery *uniq_quotas;
	TUniDataSource *ds_quotas;
	TUniQuery *uniq_sum_quotas;
	TUniDataSource *ds_sum_quotas;
	TUniQuery *UniQuery2;
	TUniQuery *uniq_all_quotas;
	TUniDataSource *ds_all_quotas;
	TUniQuery *uniq_salary_sum;
	TUniDataSource *ds_salary_sum;
	TUniQuery *uniq_users;
	TUniDataSource *ds_users;
	TUniQuery *uniq_emp;
	TUniDataSource *ds_emp;
	TUniQuery *uniq_fixed_expenses;
	TUniDataSource *ds_fixed_expense;
	void __fastcall UniGUIMainModuleCreate(TObject *Sender);
	void __fastcall uniq_proj_taskAfterInsert(TDataSet *DataSet);
	void __fastcall uniq_proj_infoAfterInsert(TDataSet *DataSet);
	void __fastcall uniq_proj_taskBeforeInsert(TDataSet *DataSet);
	void __fastcall uniq_proj_taskAfterExecute(TObject *Sender, bool Result);
	void __fastcall uniq_proj_taskAfterUpdateExecute(TDataSet *Sender, TStatementTypes StatementTypes,
          TDAParams *Params);
	void __fastcall uniq_quotasAfterUpdateExecute(TDataSet *Sender, TStatementTypes StatementTypes,
          TDAParams *Params);
private:	// User declarations
public:		// User declarations
	__fastcall TUniMainModule(TComponent* Owner, TComponent* AUniApplication);
	UnicodeString user_name, user_pwd;
	int user_priority;
};
//---------------------------------------------------------------------------
//extern int frameNo;
extern UnicodeString crtProj, crtTask;
extern UnicodeString dir_name;
TUniMainModule *UniMainModule(void);
//---------------------------------------------------------------------------
#endif
