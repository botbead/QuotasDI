// ---------------------------------------------------------------------------
#include <vcl.h>
#include <uniGUIVars.hpp>
#pragma hdrstop

#include "Main.h"
#include "MainModule.h"
#include "NewProj.h"
#include "ProjKPIQuota.h"
#include "SalarySum.h"
#include "UserMng.h"
#include "InitSalary.h"
#include "Staff.h"
#include "FixedExpenses.h"
// #include <stack>
// using namespace std;
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniButton"
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniTreeMenu"
#pragma link "uniTreeView"
#pragma link "uniMainMenu"
#pragma link "uniPanel"
#pragma link "uniTabControl"
#pragma link "uniStatusBar"
#pragma link "uniPageControl"
#pragma link "uniBasicGrid"
#pragma link "uniDBGrid"
#pragma link "uniDBNavigator"
#pragma link "uniEdit"
#pragma resource "*.dfm"

// TUniForm2 *new_quotas_list;

// ---------------------------------------------------------------------------
TMainForm *MainForm(void) {
	return ((TMainForm*)UniMainModule()->GetFormInstance(__classid(TMainForm)));
}

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TUniForm(Owner) {
}

// ---------------------------------------------------------------------------
void TAA2D407A351E4989924C53159756DAA9__RegisterFormClass() {
	Uniguivars::RegisterAppFormClass(__classid(TMainForm));
	Uniguiregclasses::CPPInit();
}

#pragma startup TAA2D407A351E4989924C53159756DAA9__RegisterFormClass

void __fastcall TMainForm::N2Click(TObject *Sender) {
	//
	/*
	 TUniForm1 * newproj_form = new TUniForm1(UniApplication);
	 newproj_form->Show();
	 */
	/*
	 if (new_quotas_list);
	 else {
	 new_quotas_list = new TUniForm2(UniApplication);
	 }

	 new_quotas_list->Show();
	 */
	TUniForm2 *new_quotas_list = (TUniForm2*)UniMainModule()->GetFormInstance
		(__classid(TUniForm2));
	new_quotas_list->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender) {
	TUniForm3 *sum_salaries = (TUniForm3*)UniMainModule()->GetFormInstance
		(__classid(TUniForm3));
	sum_salaries->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniFormCreate(TObject *Sender) {
	/*
	 int record_num = 0;
	 TUniTreeNode *treenode = 0;
	 if (UniMainModule()->UniConnection1->InTransaction);
	 else {
	 UniMainModule()->UniConnection1->StartTransaction();
	 UniMainModule()->UniQuery1->SQL->Clear();
	 UniMainModule()->UniQuery1->SQL->Add("SELECT projNo from proj_info;");
	 try {
	 UniMainModule()->UniQuery1->Execute();
	 UniMainModule()->UniConnection1->Commit();
	 while (record_num < UniMainModule()->UniQuery1->RecordCount) {
	 treenode = this->UniTreeView1->Items->AddChild
	 (this->UniTreeView1->Items->operator[](0),
	 UniMainModule()->UniQuery1->FieldByName("projNo")
	 ->AsString);
	 UniMainModule()->UniQuery1->Next();
	 record_num++;
	 }

	 }
	 catch (...) {
	 UniMainModule()->UniConnection1->Rollback();
	 }
	 }
	 */
	/*
	 edit_projNo = new TUniEdit(this);
	 UniDBGrid3->ColumnByName("projNo")->Editor = edit_projNo;
	 edit_blueprintNo = new TUniEdit(this);
	 UniDBGrid3->ColumnByName("blueprintNo")->Editor = edit_blueprintNo;
	 edit_stage = new TUniEdit(this);
	 UniDBGrid3->ColumnByName("stage")->Editor = edit_stage;
	 edit_achievement = new TUniEdit(this);
	 UniDBGrid3->ColumnByName("achievement")->Editor = edit_achievement;
	 edit_task = new TUniEdit(this);
	 UniDBGrid1->ColumnByName("task")->Editor = edit_task;
	 edit_employee = new TUniEdit(this);
	 UniDBGrid2->ColumnByName("employee")->Editor = edit_employee;
	 edit_work = new TUniEdit(this);
	 UniDBGrid2->ColumnByName("work")->Editor = edit_work;
	 */
	UniDBGrid3->ColumnByName("projNo")->Editor = UniEdit1;
	UniDBGrid3->ColumnByName("blueprintNo")->Editor = UniEdit1;
	UniDBGrid3->ColumnByName("stage")->Editor = UniEdit1;
	UniDBGrid3->ColumnByName("achievement")->Editor = UniEdit1;
	UniDBGrid1->ColumnByName("task")->Editor = UniEdit1;
	UniDBGrid2->ColumnByName("employee")->Editor = UniEdit1;
	UniDBGrid2->ColumnByName("work")->Editor = UniEdit1;
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniFormShow(TObject *Sender) {
	// UniTreeView1->FullExpand();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniTreeView1DblClick(TObject *Sender) {
	/*
	 // int level2 = 0;
	 // stack<TUniTreeNode*>node_stack;
	 int level_num = 0;
	 int level_index;
	 TUniTreeNode *level_ary[8] = {0};
	 TUniTreeNode *treenode = 0;
	 TUniTreeNode *treenode1 = 0;
	 int cur_level = UniTreeView1->Selected->Level;
	 treenode1 = treenode = UniTreeView1->Selected;
	 // node_stack.push(treenode1);
	 level_ary[level_num++] = treenode1;

	 while (cur_level > 0) {
	 treenode1 = treenode1->Parent;
	 level_ary[level_num++] = treenode1;
	 cur_level--;
	 }

	 level_index = 0;
	 while (level_index < level_num) {
	 if (1 == level_ary[level_index]->Level) {
	 }
	 else if (2 == level_ary[level_index]->Level) {
	 }
	 level_index++;
	 }
	 */

	/*
	 while (!node_stack.empty()) {
	 treenode1 = node_stack.top();
	 node_stack.pop();
	 if(treenode1->Level == 1){

	 }
	 }
	 */

}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniFormDestroy(TObject *Sender) {
	/*
	 delete edit_projNo;
	 delete edit_blueprintNo;
	 delete edit_stage;
	 delete edit_achievement;
	 delete edit_task;
	 delete edit_employee;
	 delete edit_work;
	 */
	// if (new_quotas_list)
	// delete new_quotas_list;
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::UniDBGrid3SelectionChange(TObject *Sender) {
	//
	// ShowMessage("11");
	crtProj = UniDBGrid3->DataSource->DataSet->FieldByName("projNo")->AsString;
	UniStatusBar1->Panels->operator[](0)->Text = "工程：" + crtProj;
	if (UniDBGrid3->DataSource->DataSet->RecordCount);
	else {
		crtProj.SetLength(0);
		UniStatusBar1->Panels->operator[](0)->Text = "";
	}
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		UniMainModule()->uniq_proj_task->SQL->Clear();
		UniMainModule()->uniq_proj_task->SQL->Add
			(Sysutils::Format("SELECT * FROM tasks_info WHERE projNo = '%s';",
			ARRAYOFCONST((crtProj))));
		try {
			UniMainModule()->uniq_proj_task->Execute();
			UniMainModule()->UniConnection1->Commit();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::UniDBGrid1SelectionChange(TObject *Sender) {
	//
	crtTask = UniDBGrid1->DataSource->DataSet->FieldByName("task")->AsString;
	UniStatusBar1->Panels->operator[](1)->Text = "作业：" + crtTask;
	if (UniDBGrid1->DataSource->DataSet->RecordCount);
	else {
		crtTask.SetLength(0);
		UniStatusBar1->Panels->operator[](1)->Text = "";
	}
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		UniMainModule()->uniq_quotas->SQL->Clear();
		UniMainModule()->uniq_quotas->SQL->Add
			(Sysutils::Format
			("SELECT * FROM quotas_info WHERE projNo = '%s' AND task = '%s';",
			ARRAYOFCONST((crtProj, crtTask))));
		try {
			UniMainModule()->uniq_quotas->Execute();
			UniMainModule()->UniConnection1->Commit();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::N14Click(TObject *Sender) {
	//
	TUniForm4 *form_user_mng = (TUniForm4*)UniMainModule()->GetFormInstance
		(__classid(TUniForm4));
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		UniMainModule()->uniq_users->SQL->Clear();
		UniMainModule()->uniq_users->SQL->Add
			("SELECT * FROM user_info WHERE priority != 0;");
		try {
			UniMainModule()->uniq_users->Execute();
			UniMainModule()->UniConnection1->Commit();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
	}
	form_user_mng->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::N4Click(TObject *Sender) {
	TUniForm7 *form_staff = (TUniForm7*)UniMainModule()->GetFormInstance
		(__classid(TUniForm7));
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		UniMainModule()->uniq_emp->SQL->Clear();
		UniMainModule()->uniq_emp->SQL->Add("SELECT * FROM staff;");
		try {
			UniMainModule()->uniq_emp->Execute();
			UniMainModule()->UniConnection1->Commit();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
	}
	form_staff->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender) {
	TUniForm8 *form_fixed_expenses =
		(TUniForm8*)UniMainModule()->GetFormInstance(__classid(TUniForm8));
	if (UniMainModule()->UniConnection1->InTransaction);
	else {
		UniMainModule()->UniConnection1->StartTransaction();
		UniMainModule()->uniq_fixed_expenses->SQL->Clear();
		UniMainModule()->uniq_fixed_expenses->SQL->Add
			("SELECT * FROM fixed_expenses;");
		try {
			UniMainModule()->uniq_fixed_expenses->Execute();
			UniMainModule()->UniConnection1->Commit();
		}
		catch (...) {
			UniMainModule()->UniConnection1->Rollback();
		}
	}
	form_fixed_expenses->ShowModal();
}
// ---------------------------------------------------------------------------
