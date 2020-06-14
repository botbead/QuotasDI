// ---------------------------------------------------------------------------

#include <vcl.h>
#include <UniGUIApplication.hpp>
#include <UniGUIVars.hpp>
#pragma hdrstop

#include "MainModule.h"
#include <vector>
#include <map>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DAScript"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "SQLiteUniProvider"
#pragma link "Uni"
#pragma link "UniProvider"
#pragma link "UniScript"
#pragma resource "*.dfm"

// int frameNo;
UnicodeString crtProj, crtTask;
UnicodeString dir_name;

std::map<UnicodeString, double>eq_map;

// ---------------------------------------------------------------------------
TUniMainModule *UniMainModule(void) {
	return ((TUniMainModule*)UniApplication()->UniMainModule_);
}

// ---------------------------------------------------------------------------
__fastcall TUniMainModule::TUniMainModule(TComponent* Owner,
	TComponent* AUniApplication) : TUniGUIMainModule(Owner, AUniApplication) {

}
// ---------------------------------------------------------------------------

void __RegisterMainModuleClass() {
	Uniguivars::RegisterMainModuleClass(__classid(TUniMainModule));
}

#pragma startup __RegisterMainModuleClass

// ---------------------------------------------------------------------------
void __fastcall TUniMainModule::UniGUIMainModuleCreate(TObject *Sender) {
	// frameNo = 0;
	UniConnection1->ProviderName = "SQLite";
	UniConnection1->SpecificOptions->Values["Direct"] = "True";
	UniConnection1->SpecificOptions->Values["ForceCreateDatabase"] = "True";
	UniConnection1->Database = ExtractFilePath(Application->ExeName) +
		"Quotas.db";
	UniConnection1->Connect();
	UniScript1->Connection = UniConnection1;
	UniQuery1->Connection = UniConnection1;
	UniScript1->SQL->Clear();
	UniScript1->SQL->Add("CREATE TABLE IF NOT EXISTS user_info (\
usrNo INTEGER NOT NULL,\
name TEXT NOT NULL,\
password TEXT NOT NULL DEFAULT '123456',\
department TEXT DEFAULT '',\
priority INTEGER NOT NULL CHECK (-1 < priority AND priority < 6) DEFAULT 3,\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (usrNo));CREATE TABLE IF NOT EXISTS proj_info (\
projNo TEXT NOT NULL,\
blueprintNo TEXT NOT NULL,\
stage TEXT NOT NULL,\
achievement TEXT NOT NULL,\
amount REAL NOT NULL,\
pay_for_performance REAL NOT NULL,\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (projNo));CREATE TABLE IF NOT EXISTS quotas_info (\
projNo TEXT,\
task TEXT,\
work TEXT,\
employee TEXT NOT NULL,\
work_employee_quota REAL NOT NULL,\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (projNo, task, work, employee));CREATE TABLE IF NOT EXISTS tasks_info (\
projNo TEXT,\
task TEXT NOT NULL,\
task_quota REAL NOT NULL,\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (projNo, task));CREATE TABLE IF NOT EXISTS quotas_sum (\
projNo TEXT NOT NULL,\
employee TEXT NOT NULL,\
employee_quota_sum REAL NOT NULL,\
pay_for_performance REAL NOT NULL,\
extra_reward REAL,\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (projNo, employee));CREATE TABLE IF NOT EXISTS staff (\
empno TEXT NOT NULL,\
name TEXT NOT NULL,\
kpi_current REAL NOT NULL,\
department TEXT DEFAULT '',\
speciality TEXT DEFAULT '',\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (empno));CREATE TABLE IF NOT EXISTS fixed_expenses (\
item_name TEXT NOT NULL,\
item_expense REAL NOT NULL,\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (item_name));CREATE TABLE IF NOT EXISTS salaries_sum (\
projNo TEXT NOT NULL,\
amount REAL NOT NULL,\
employee_salary0 REAL NOT NULL DEFAULT 0.0,\
employee_salary1 REAL NOT NULL DEFAULT 0.0,\
employee_salary2 REAL NOT NULL DEFAULT 0.0,\
employee_salary3 REAL NOT NULL DEFAULT 0.0,\
employee_salary4 REAL NOT NULL DEFAULT 0.0,\
employee_salary5 REAL NOT NULL DEFAULT 0.0,\
employee_salary6 REAL NOT NULL DEFAULT 0.0,\
employee_salary7 REAL NOT NULL DEFAULT 0.0,\
employee_salary8 REAL NOT NULL DEFAULT 0.0,\
employee_salary9 REAL NOT NULL DEFAULT 0.0,\
employee_salary10 REAL NOT NULL DEFAULT 0.0,\
employee_salary11 REAL NOT NULL DEFAULT 0.0,\
employee_salary12 REAL NOT NULL DEFAULT 0.0,\
employee_salary13 REAL NOT NULL DEFAULT 0.0,\
employee_salary14 REAL NOT NULL DEFAULT 0.0,\
employee_salary15 REAL NOT NULL DEFAULT 0.0,\
employee_salary16 REAL NOT NULL DEFAULT 0.0,\
employee_salary17 REAL NOT NULL DEFAULT 0.0,\
employee_salary18 REAL NOT NULL DEFAULT 0.0,\
employee_salary19 REAL NOT NULL DEFAULT 0.0,\
employee_salary20 REAL NOT NULL DEFAULT 0.0,\
employee_salary21 REAL NOT NULL DEFAULT 0.0,\
employee_salary22 REAL NOT NULL DEFAULT 0.0,\
employee_salary23 REAL NOT NULL DEFAULT 0.0,\
employee_salary24 REAL NOT NULL DEFAULT 0.0,\
employee_salary25 REAL NOT NULL DEFAULT 0.0,\
employee_salary26 REAL NOT NULL DEFAULT 0.0,\
employee_salary27 REAL NOT NULL DEFAULT 0.0,\
employee_salary28 REAL NOT NULL DEFAULT 0.0,\
employee_salary29 REAL NOT NULL DEFAULT 0.0,\
employee_salary30 REAL NOT NULL DEFAULT 0.0,\
employee_salary31 REAL NOT NULL DEFAULT 0.0,\
employee_salary32 REAL NOT NULL DEFAULT 0.0,\
employee_salary33 REAL NOT NULL DEFAULT 0.0,\
employee_salary34 REAL NOT NULL DEFAULT 0.0,\
employee_salary35 REAL NOT NULL DEFAULT 0.0,\
employee_salary36 REAL NOT NULL DEFAULT 0.0,\
employee_salary37 REAL NOT NULL DEFAULT 0.0,\
employee_salary38 REAL NOT NULL DEFAULT 0.0,\
employee_salary39 REAL NOT NULL DEFAULT 0.0,\
employee_salary40 REAL NOT NULL DEFAULT 0.0,\
employee_salary41 REAL NOT NULL DEFAULT 0.0,\
employee_salary42 REAL NOT NULL DEFAULT 0.0,\
employee_salary43 REAL NOT NULL DEFAULT 0.0,\
employee_salary44 REAL NOT NULL DEFAULT 0.0,\
employee_salary45 REAL NOT NULL DEFAULT 0.0,\
employee_salary46 REAL NOT NULL DEFAULT 0.0,\
employee_salary47 REAL NOT NULL DEFAULT 0.0,\
employee_salary48 REAL NOT NULL DEFAULT 0.0,\
employee_salary49 REAL NOT NULL DEFAULT 0.0,\
employee_salary50 REAL NOT NULL DEFAULT 0.0,\
employee_salary51 REAL NOT NULL DEFAULT 0.0,\
employee_salary52 REAL NOT NULL DEFAULT 0.0,\
employee_salary53 REAL NOT NULL DEFAULT 0.0,\
employee_salary54 REAL NOT NULL DEFAULT 0.0,\
employee_salary55 REAL NOT NULL DEFAULT 0.0,\
employee_salary56 REAL NOT NULL DEFAULT 0.0,\
employee_salary57 REAL NOT NULL DEFAULT 0.0,\
employee_salary58 REAL NOT NULL DEFAULT 0.0,\
employee_salary59 REAL NOT NULL DEFAULT 0.0,\
employee_salary60 REAL NOT NULL DEFAULT 0.0,\
employee_salary61 REAL NOT NULL DEFAULT 0.0,\
employee_salary62 REAL NOT NULL DEFAULT 0.0,\
employee_salary63 REAL NOT NULL DEFAULT 0.0,\
employee_salary64 REAL NOT NULL DEFAULT 0.0,\
employee_salary65 REAL NOT NULL DEFAULT 0.0,\
employee_salary66 REAL NOT NULL DEFAULT 0.0,\
employee_salary67 REAL NOT NULL DEFAULT 0.0,\
employee_salary68 REAL NOT NULL DEFAULT 0.0,\
employee_salary69 REAL NOT NULL DEFAULT 0.0,\
employee_salary70 REAL NOT NULL DEFAULT 0.0,\
employee_salary71 REAL NOT NULL DEFAULT 0.0,\
employee_salary72 REAL NOT NULL DEFAULT 0.0,\
employee_salary73 REAL NOT NULL DEFAULT 0.0,\
employee_salary74 REAL NOT NULL DEFAULT 0.0,\
employee_salary75 REAL NOT NULL DEFAULT 0.0,\
employee_salary76 REAL NOT NULL DEFAULT 0.0,\
employee_salary77 REAL NOT NULL DEFAULT 0.0,\
employee_salary78 REAL NOT NULL DEFAULT 0.0,\
employee_salary79 REAL NOT NULL DEFAULT 0.0,\
employee_salary80 REAL NOT NULL DEFAULT 0.0,\
rowid_2th INTEGER PRIMARY KEY AUTOINCREMENT,\
UNIQUE (projNo));");
	UniScript1->Execute();

	crtProj.SetLength(0);
	crtTask.SetLength(0);

	dir_name = ExtractFileDir(Application->ExeName) +
		"\\SalariesDir";
	if (DirectoryExists(dir_name));
	else
		ForceDirectories(dir_name);
}
// ---------------------------------------------------------------------------

void __fastcall TUniMainModule::uniq_proj_taskAfterInsert(TDataSet *DataSet) {
	//
	/*
	 if (UniConnection1->InTransaction);
	 else {
	 UniConnection1->StartTransaction();
	 uniq_proj_task->SQL->Clear();
	 }
	 */

}

// ---------------------------------------------------------------------------
void __fastcall TUniMainModule::uniq_proj_infoAfterInsert(TDataSet *DataSet) {
	//

}
// ---------------------------------------------------------------------------

void __fastcall TUniMainModule::uniq_proj_taskBeforeInsert(TDataSet *DataSet) {
	//
	// DataSet->FieldByName("projNo")->Text = crtProj;
	// MainForm()->edit_projNo_task->Text = crtProj;
}

// ---------------------------------------------------------------------------
void __fastcall TUniMainModule::uniq_proj_taskAfterExecute(TObject *Sender,
	bool Result) {
	/*
	 if (UniConnection1->InTransaction);
	 else {
	 UniConnection1->StartTransaction();
	 UniQuery1->SQL->Clear();
	 UniQuery1->SQL->Add
	 (Sysutils::Format
	 ("update tasks_info set projNo = '%s' where rowid = (select max(rowid) from tasks_info);",
	 ARRAYOFCONST((crtProj))));
	 try {
	 UniQuery1->Execute();
	 UniConnection1->Commit();
	 }
	 catch (...) {
	 UniConnection1->Rollback();
	 }
	 }
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TUniMainModule::uniq_proj_taskAfterUpdateExecute
	(TDataSet *Sender, TStatementTypes StatementTypes, TDAParams *Params) {
	if (UniConnection1->InTransaction);
	else {
		UniConnection1->StartTransaction();
		UniQuery1->SQL->Clear();
		UniQuery1->SQL->Add
			(Sysutils::Format
			("update tasks_info set projNo = '%s' where rowid = (select max(rowid) from tasks_info);",
			ARRAYOFCONST((crtProj))));
		try {
			UniQuery1->Execute();
			UniConnection1->Commit();
		}
		catch (...) {
			UniConnection1->Rollback();
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TUniMainModule::uniq_quotasAfterUpdateExecute(TDataSet *Sender,
	TStatementTypes StatementTypes, TDAParams *Params) {
	if (UniConnection1->InTransaction);
	else {
		UniConnection1->StartTransaction();
		UniQuery1->SQL->Clear();
		UniQuery1->SQL->Add
			(Sysutils::Format
			("update quotas_info set projNo = '%s', task = '%s' where rowid = (select max(rowid) from quotas_info);",
			ARRAYOFCONST((crtProj, crtTask))));
		try {
			UniQuery1->Execute();
			UniConnection1->Commit();
		}
		catch (...) {
			UniConnection1->Rollback();
		}
	}
}
// ---------------------------------------------------------------------------
