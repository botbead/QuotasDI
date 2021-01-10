// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Profile.h"
#include "Main.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uniGUIBaseClasses"
#pragma link "uniGUIClasses"
#pragma link "uniLabel"
#pragma link "uniImage"
#pragma link "uniPanel"
#pragma link "uniRadioGroup"
#pragma link "uniButton"
#pragma link "uniComboBox"
#pragma link "uniDBComboBox"
#pragma link "uniMultiItem"
#pragma link "uniEdit"
#pragma link "uniCheckBox"
#pragma link "uniListBox"
#pragma resource "*.dfm"

extern wchar_t preferential_price_prefix[];
extern wchar_t preferential_price_suffix[];

extern wchar_t confirmation[];
const wchar_t agent_name[] = {0x4EE3, 0x7406, 0x540D, 0x0};
const wchar_t agent_level[] = {0x4EE3, 0x7406, 0x7B49, 0x7EA7, 0x0};
const wchar_t agent_level_items[][5] = { {0x4E00, 0x7EA7, 0x4EE3, 0x7406, 0x0}, {0x4E8C, 0x7EA7, 0x4EE3, 0x7406, 0x0}};
const wchar_t school_phase[] = {0x5B66, 0x6BB5, 0x0};
const wchar_t school_duration[] = {0x5B66, 0x5236, 0x0};
const wchar_t school_duration_items[][6] = {
	{0x5C0F, 0x5B66, 0x4E94, 0x5E74, 0x5236, 0x0}, {0x5C0F, 0x5B66, 0x516D, 0x5E74, 0x5236, 0x0},
	{0x521D, 0x4E2D, 0x4E09, 0x5E74, 0x5236, 0x0}, {0x521D, 0x4E2D, 0x56DB, 0x5E74, 0x5236, 0x0}};
const wchar_t school_phase_items[][3] = { {0x5C0F, 0x5B66, 0x0}, {0x521D, 0x4E2D, 0x0}, {0x9AD8, 0x4E2D, 0x0}};
const wchar_t school_name[] = {0x5B66, 0x6821, 0x540D, 0x0};
const wchar_t accept_terms[] = {0x540C, 0x610F, 0x5E76, 0x63A5, 0x53D7, 0x670D, 0x52A1, 0x6761, 0x6B3E, 0x0};
const wchar_t mobile[] = {0x624B, 0x673A, 0x0};
const wchar_t postcode[] = {0x90AE, 0x7F16, 0x0};
const wchar_t shipping_address[] = {0x5730, 0x5740, 0x0};
const wchar_t contact[] = {0x8054, 0x7CFB, 0x4EBA, 0x0};
const wchar_t primary_school_items[][6] = {
	{0x5C0F, 0x5B66, 0x4E00, 0x5E74, 0x7EA7, 0x0}, {0x5C0F, 0x5B66, 0x4E8C, 0x5E74, 0x7EA7, 0x0},
	{0x5C0F, 0x5B66, 0x4E09, 0x5E74, 0x7EA7, 0x0}, {0x5C0F, 0x5B66, 0x56DB, 0x5E74, 0x7EA7, 0x0},
	{0x5C0F, 0x5B66, 0x4E94, 0x5E74, 0x7EA7, 0x0}, {0x5C0F, 0x5B66, 0x516D, 0x5E74, 0x7EA7, 0x0}};
const wchar_t junior_middle_school_items[][6] = {
	{0x521D, 0x4E2D, 0x4E00, 0x5E74, 0x7EA7, 0x0}, {0x521D, 0x4E2D, 0x4E8C, 0x5E74, 0x7EA7, 0x0},
	{0x521D, 0x4E2D, 0x4E09, 0x5E74, 0x7EA7, 0x0}, {0x521D, 0x4E2D, 0x56DB, 0x5E74, 0x7EA7, 0x0}};
const wchar_t senior_middle_school_items[][6] = {
	{0x9AD8, 0x4E2D, 0x4E00, 0x5E74, 0x7EA7, 0x0}, {0x9AD8, 0x4E2D, 0x4E8C, 0x5E74, 0x7EA7, 0x0},
	{0x9AD8, 0x4E2D, 0x4E09, 0x5E74, 0x7EA7, 0x0}};
const wchar_t email[] = {0x90AE, 0x7BB1, 0x0};
const wchar_t grade[] = {0x5E74, 0x7EA7, 0x0};
const wchar_t name[] = {0x59D3, 0x540D, 0x0};
const wchar_t welcome[] = {0x6B22, 0x8FCE, 0x4F7F, 0x7528, 0x5EFA, 0x4EAB, 0x4E00, 0x677F, 0x901A, 0x670D, 0x52A1, 0x0};
const wchar_t welcome_hint[] = {
	0x9996, 0x6B21, 0x767B, 0x5F55, 0x9700, 0x8981, 0x8BBE, 0x7F6E, 0x60A8, 0x7684, 0x8D26, 0x6237, 0x4FE1, 0x606F, 0x0
};
const wchar_t choose_usr_type[] = {0x8BF7, 0x9009, 0x62E9, 0x60A8, 0x7684, 0x8D26, 0x6237, 0x7C7B, 0x578B, 0x0};
const wchar_t student[] = {0x5B66, 0x751F, 0x0};
const wchar_t school[] = {0x5B66, 0x6821, 0x0};
const wchar_t agent[] = {0x4EE3, 0x7406, 0x0};
const wchar_t cancel_hint[] = {
	0x7531, 0x4E8E, 0x60A8, 0x662F, 0x9996, 0x6B21, 0x767B, 0x5F55, 0xFF0C, 0x8BF7, 0x52A1, 0x5FC5, 0x5B8C, 0x6210,
	0x60A8, 0x7684, 0x4FE1, 0x606F, 0x0};
const wchar_t school_name_empty[] = {0x8BF7, 0x6DFB, 0x52A0, 0x6821, 0x540D, 0x0};
const wchar_t school_phase_empty[] = {0x8BF7, 0x786E, 0x8BA4, 0x5B66, 0x6BB5, 0x0};
const wchar_t school_duration_empty[] = {0x8BF7, 0x9009, 0x62E9, 0x6709, 0x6548, 0x7684, 0x5B66, 0x5236, 0x0};
const wchar_t contact_information_invalid[] = {
	0x8BF7, 0x586B, 0x5199, 0x6709, 0x6548, 0x7684, 0x8054, 0x7CFB, 0x4FE1, 0x606F, 0x0};
const wchar_t agent_name_empty[] = {0x8BF7, 0x586B, 0x5199, 0x6709, 0x6548, 0x7684, 0x4EE3, 0x7406, 0x540D, 0x0};
const wchar_t agent_level_empty[] = {0x8BF7, 0x9009, 0x62E9, 0x6709, 0x6548, 0x7684, 0x4EE3, 0x7406, 0x7EA7, 0x522B, 0x0
};
const wchar_t agent_object_empty[] = {0x8BF7, 0x9009, 0x62E9, 0x60A8, 0x4EE3, 0x7406, 0x7684, 0x5B66, 0x6821, 0x0};
const wchar_t school_pinyin[] = {0x5B66, 0x6821, 0x62FC, 0x97F3, 0x5168, 0x62FC, 0x0};
const wchar_t superior_agent_empty[] = {0x8BF7, 0x9009, 0x62E9, 0x60A8, 0x7684, 0x4E0A, 0x7EA7, 0x4EE3, 0x7406, 0x0};
const wchar_t school_details_insert_completed[] = {
	0x60A8, 0x7684, 0x5B66, 0x6821, 0x4FE1, 0x606F, 0x767B, 0x8BB0, 0x6210, 0x529F, 0x0};
const wchar_t school_details_insert_failed[] = {
	0x60A8, 0x7684, 0x5B66, 0x6821, 0x4FE1, 0x606F, 0x767B, 0x8BB0, 0x5931, 0x8D25, 0x0};
const wchar_t student_details_insert_completed[] = {
	0x60A8, 0x7684, 0x5B66, 0x751F, 0x4FE1, 0x606F, 0x767B, 0x8BB0, 0x6210, 0x529F, 0x0};
const wchar_t student_details_insert_failed[] = {
	0x60A8, 0x7684, 0x5B66, 0x751F, 0x4FE1, 0x606F, 0x767B, 0x8BB0, 0x5931, 0x8D25, 0x0};
const wchar_t grade_empty[] = {0x8BF7, 0x9009, 0x62E9, 0x60A8, 0x7684, 0x5E74, 0x7EA7, 0x0};
const wchar_t superior_agent[] = {0x4E0A, 0x7EA7, 0x4EE3, 0x7406, 0x0};
const wchar_t class_then[] = {0x73ED, 0x7EA7, 0x0};
const wchar_t sno_then[] = {0x5B66, 0x53F7, 0x0};
const wchar_t required_field[] = {0x5FC5, 0x586B, 0x0};
const wchar_t choice_required_field[] = {0x5FC5, 0x9009, 0x0};

// ---------------------------------------------------------------------------
__fastcall TUniFormSignUp_1::TUniFormSignUp_1(TComponent* Owner) : TUniForm(Owner) {
	mmodule = UniMainModule();
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniFormCreate(TObject *Sender) {
	int i;
	school_details * sd = 0;

	UniRadioGroup1->Items->Add(student);
	UniRadioGroup1->Items->Add(school);
	UniRadioGroup1->Items->Add(agent);

	UniRadioGroup1->Columns = 3;

	UniRadioGroup1->Caption = choose_usr_type;

	UniRadioGroup1->ItemIndex = 0;

	UniLabel1->Caption = welcome;
	UniLabel1->Font->Size = 33;
	UniLabel1->Font->Style = UniLabel1->Font->Style << fsItalic;
	UniLabel2->Caption = welcome_hint;
	UniLabel2->Font->Size = 17;
	UniLabel1->Font->Style = UniLabel1->Font->Style << fsBold;
	UniLabel3->Caption = school;
	UniLabel4->Caption = grade;
	UniLabel5->Caption = name;
	UniLabel6->Caption = email;

	// for (i = 0; i < 3; ++i) {
	// UniComboBox4->Items->Add(senior_middle_school_items[i]);
	// }

	UniLabel7->Caption = mobile;
	UniLabel8->Caption = class_then;
	UniLabel9->Caption = shipping_address;

	UniButton1->Caption = confirmation;

	UniLabel10->Caption = sno_then;
	UniLabel11->Caption = school_name;

	UniCheckBox2->Caption = school_phase_items[0];
	UniCheckBox3->Caption = school_phase_items[1];
	UniCheckBox4->Caption = school_phase_items[2];

	UniCheckBox5->Caption = school_duration_items[0];
	UniCheckBox6->Caption = school_duration_items[1];
	UniCheckBox7->Caption = school_duration_items[2];
	UniCheckBox8->Caption = school_duration_items[3];

	UniLabel18->Caption = choose_usr_type;
	UniLabel18->Font->Size = 15;
	UniCheckBox9->Caption = student;
	UniCheckBox9->Checked = true;
	UniCheckBox10->Caption = school;
	UniCheckBox11->Caption = agent;

	UniLabel14->Caption = contact;
	UniLabel15->Caption = email;
	UniLabel16->Caption = mobile;
	// UniLabel17->Caption = postcode;
	UniLabel19->Caption = shipping_address;

	UniLabel12->Caption = school_phase;
	UniLabel13->Caption = school_duration;

	UniContainerPanel_student->Visible = true;
	UniContainerPanel_school->Visible = false;
	UniContainerPanel_school->Visible = false;

	UniLabel20->Caption = agent_name;
	UniLabel21->Caption = agent_level;
	UniComboBox6->Items->Add(agent_level_items[0]);
	UniComboBox6->Items->Add(agent_level_items[1]);

	UniLabel22->Caption = email;
	UniLabel23->Caption = mobile;
	// UniLabel24->Caption = postcode;
	UniLabel25->Caption = shipping_address;

	UniLabel27->Caption = superior_agent;

	UniEdit4->EmptyText = required_field;
	UniEdit10->EmptyText = required_field;
	UniEdit1->EmptyText = required_field;
	UniEdit2->EmptyText = required_field;
	UniEdit3->EmptyText = required_field;
	UniEdit5->EmptyText = required_field;
	UniComboBox1->EmptyText = choice_required_field;
	UniComboBox2->EmptyText = choice_required_field;
	UniComboBox3->EmptyText = choice_required_field;
	UniComboBox4->EmptyText = choice_required_field;

	mmodule->UniQuery1->SQL->Clear();
	mmodule->UniQuery1->SQL->Add
		(L"select scid, school_name, phase1, phase2, phase3, school_students_table from school;");
	mmodule->UniQuery1->Execute();
	mmodule->UniQuery1->First();
	for (i = 0; i < mmodule->UniQuery1->RecordCount; ++i) {
		sd = new school_details;
		sd->scid = mmodule->UniQuery1->FieldByName("scid")->AsInteger;
		sd->phase[0] = mmodule->UniQuery1->FieldByName("phase1")->AsInteger;
		sd->phase[1] = mmodule->UniQuery1->FieldByName("phase2")->AsInteger;
		sd->phase[2] = mmodule->UniQuery1->FieldByName("phase3")->AsInteger;
		sd->school_name = mmodule->UniQuery1->FieldByName("school_name")->AsString;
		UniComboBox1->Items->Add(sd->school_name);
		sd->school_students_table = mmodule->UniQuery1->FieldByName("school_students_table")->AsString;

		school_map.insert(std::pair<int, school_details*>(i, sd));

		mmodule->UniQuery1->Next();
	}

}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniImage2Click(TObject *Sender) {
	this->ShowToast(cancel_hint);
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniRadioGroup1ChangeValue(TObject *Sender) {

	// this->ShowToast(UniRadioGroup1->ItemIndex);

	// if (UniRadioGroup1->ItemIndex ==0) {
	// UniContainerPanel_student->Visible = true;
	// UniContainerPanel_school->Visible = false;
	// }
	// else if (UniRadioGroup1->ItemIndex ==1) {
	// UniContainerPanel_student->Visible = false;
	// UniContainerPanel_school->Visible = true;
	// }
	// UniSimplePanel1->Repaint();

}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniCheckBox9Click(TObject *Sender) {
	// UniCheckBox9->Checked = !(UniCheckBox9->Checked);
	// if (ck) {
	// UniCheckBox10->Checked = false;
	// UniCheckBox11->Checked = false;
	//
	// }
	// else {
	// UniCheckBox10->Checked = false;
	// UniCheckBox11->Checked = false;
	// }
	UniCheckBox10->Checked = false;
	UniCheckBox11->Checked = false;

	if (UniCheckBox9->Checked) {
		UniContainerPanel_student->Visible = true;
		UniContainerPanel_school->Visible = false;
		UniContainerPanel_agent->Visible = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TUniFormSignUp_1::UniCheckBox10Click(TObject *Sender) {
	// UniCheckBox10->Checked = !(UniCheckBox10->Checked);
	// if (ck) {
	// UniCheckBox9->Checked = false;
	// UniCheckBox11->Checked = false;
	//
	// }
	// else {
	// UniCheckBox9->Checked = false;
	// UniCheckBox11->Checked = false;
	// }
	UniCheckBox9->Checked = false;
	UniCheckBox11->Checked = false;
	if (UniCheckBox10->Checked) {
		UniContainerPanel_student->Visible = false;
		UniContainerPanel_school->Visible = true;
		UniContainerPanel_agent->Visible = false;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TUniFormSignUp_1::UniCheckBox11Click(TObject *Sender) {
	// UniCheckBox11->Checked = !(UniCheckBox11->Checked);

	// if (ck) {
	// UniCheckBox9->Checked = false;
	// UniCheckBox10->Checked = false;
	// }
	// else {
	// UniCheckBox9->Checked = false;
	// UniCheckBox10->Checked = false;
	// }
	UniCheckBox9->Checked = false;
	UniCheckBox10->Checked = false;

	if (UniCheckBox11->Checked) {
		UniContainerPanel_agent->Visible = true;
		UniContainerPanel_student->Visible = false;
		UniContainerPanel_school->Visible = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniButton1Click(TObject *Sender) {
	int i, j, k, q;
	school_details *sd = 0;
	UnicodeString t_str0, t_str1;
	TMainForm *mainform = (TMainForm*)UniMainModule()->GetFormInstance(__classid(TMainForm));
	std::map<int, school_details*>::iterator iter_sd_map;
	if (UniCheckBox9->Checked) {
		if (UniComboBox1->ItemIndex == -1) {
			this->ShowToast(school_name_empty);
			goto end;
		}
		if ((-1 == UniComboBox2->ItemIndex) && (-1 == UniComboBox3->ItemIndex) && (-1 == UniComboBox4->ItemIndex)) {
			this->ShowToast(grade_empty);
			goto end;
		}

		if (UniEdit1->Text.Trim().Length() && UniEdit2->Text.Trim().Length() && UniEdit3->Text.Trim().Length()
			&& UniEdit5->Text.Trim().Length());
		else {
			this->ShowToast(contact_information_invalid);
			goto end;
		}

		iter_sd_map = school_map.find(UniComboBox1->ItemIndex);
		if (school_map.end() == iter_sd_map)
			goto end;
		sd = iter_sd_map->second;
		i = sd->scid;
		if ((UniComboBox2->Enabled) && (-1 != UniComboBox2->ItemIndex)) {
			if (5 != sd->phase[0]) {
				j = 60 + UniComboBox2->ItemIndex + 1;
			}
			else {
				j = 50 + UniComboBox2->ItemIndex + 1;
			}
		}
		if ((UniComboBox3->Enabled) && (-1 != UniComboBox3->ItemIndex)) {
			if (4 != sd->phase[1]) {
				j = 30 + UniComboBox3->ItemIndex + 1;
			}
			else {
				j = 40 + UniComboBox3->ItemIndex + 1;
			}
		}
		if ((UniComboBox4->Enabled) && (-1 != UniComboBox4->ItemIndex)) {
			j = UniComboBox4->ItemIndex + 1;
		}

		mmodule->schl_id = i;
		mmodule->stu_grade = j;

		mmodule->UniSQL1->SQL->Clear();
		mmodule->UniSQL1->SQL->Add
			(Sysutils::Format
			(L"insert into %s (stid, name, password, email, mobile, address, school_id, grade, class_then, sno_then) values(%d, '%s', '%s', '%s', '%s', '%s', %d, %d, '%s', '%s');",
			ARRAYOFCONST((sd->school_students_table, mmodule->usr_id, Trim(UniEdit1->Text), Trim(mmodule->pwd),
			Trim(UniEdit2->Text), Trim(UniEdit3->Text), Trim(UniEdit5->Text), i, j, Trim(UniEdit4->Text),
			Trim(UniEdit10->Text)))));
		mmodule->UniSQL1->SQL->Add
			(Sysutils::Format(L"update signup_step1 set archived = 1, schl_id = %d  where usr_id = %d;",
			ARRAYOFCONST((i, mmodule->usr_id))));
		i = 0;
		if (mmodule->UniConnection1->InTransaction);
		else {
			mmodule->UniConnection1->StartTransaction();
			try {
				mmodule->UniSQL1->Execute();
				mmodule->UniConnection1->Commit();
				i = 1;
			}
			catch (...) {
				i = 0;
				mmodule->UniConnection1->Rollback();
			}
		}

		t_str0 = L"students_" + UnicodeString(mmodule->schl_id);

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
					mainform->UniLabel30->Caption = UnicodeString(preferential_price_prefix) + mmodule->fee_presetting +
						UnicodeString(preferential_price_suffix);
					// mainform->Show();
					break;
				}
			}

			mmodule->UniQuery1->Next();
		}

		if (i)
			this->ShowToast(student_details_insert_completed);
		else
			this->ShowToast(student_details_insert_failed);

		ModalResult = mrOk;

	}
	else if (UniCheckBox10->Checked) {
		if (UniEdit6->Text.operator == (L"")) {
			this->ShowToast(school_name_empty);
			goto end;
		}
		if (!(UniCheckBox2->Checked || UniCheckBox3->Checked || UniCheckBox4->Checked)) {
			this->ShowToast(school_phase_empty);
			goto end;
		}
		if ((UniCheckBox2->Checked || UniCheckBox3->Checked) && !(UniCheckBox5->Checked || UniCheckBox6->Checked ||
			UniCheckBox7->Checked || UniCheckBox8->Checked)) {
			this->ShowToast(school_duration_empty);
			goto end;
		}
		if (UniEdit7->Text.Trim().Length() && UniEdit8->Text.Trim().Length() && UniEdit9->Text.Length()
			&& UniEdit11->Text.Length());
		else {
			this->ShowToast(contact_information_invalid);
			goto end;
		}
		// str = UniEdit6->Text.Trim();
		// str3 = L"students_";
		// j = str.Length() + 1;
		// q = str3.Length();
		// str1.SetLength(q + j*4 + 1);
		// k = 10;
		// for (i = 1; i < j; ++i) {
		// str2 = IntToHex(int(str[i]), 2);
		// n = str2.Length() + 1;
		// for (m = 1; m < n; ++m) {
		// str1[k] = str2[m];
		// ++k;
		// }
		// }
		// str1[k] = L'\0';
		// ++q;
		// for (i = 1; i < q; i++) {
		// str1[i] = str3[i];
		// }

		t_str0 = UnicodeString(L"students_") + IntToStr((int)(mmodule->usr_id));
		i = j = k = 0;
		if (UniCheckBox5->Checked)
			i = 5;
		if (UniCheckBox6->Checked)
			i = 6;
		if (UniCheckBox8->Checked)
			j = 4;
		if (UniCheckBox7->Checked)
			j = 3;
		k = (UniCheckBox4->Checked) ? 3 : 0;

		mmodule->UniSQL1->SQL->Clear();
		mmodule->UniSQL1->SQL->Add
			(Sysutils::Format
			(L"insert into school (scid, school_name, contact, password, email, mobile, address, phase1, phase2, phase3, school_students_table) values(%d, '%s', '%s', '%s', '%s', '%s', '%s', %d, %d, %d, '%s');",
			ARRAYOFCONST((mmodule->usr_id, Trim(UniEdit6->Text), Trim(UniEdit7->Text), mmodule->pwd,
			Trim(UniEdit8->Text), Trim(UniEdit9->Text), Trim(UniEdit11->Text), i, j, k, t_str0))));
		mmodule->UniSQL1->SQL->Add
			(Sysutils::Format(L"update signup_step1 set archived = 1, usr_type = 3 where usr_id = %d;",
			ARRAYOFCONST((mmodule->usr_id))));
		t_str1 = Sysutils::Format(L"create table if not exists %s( \
stid integer primary key, \
name varchar(64) not null, \
password varchar(128) not null, \
email varchar(100) not null, \
mobile varchar(15) not null, \
address varchar(100) not null, \
school_id integer not null, \
grade tinyint not null, \
class_then varchar(50) not null, \
sno_then varchar(50) not null, \
foreign key(school_id) references school(scid) \
);", ARRAYOFCONST((t_str0)));
		mmodule->UniScript1->SQL->Clear();
		mmodule->UniScript1->SQL->Add(t_str1);
		i = 0;
		if (mmodule->UniConnection1->InTransaction);
		else {
			mmodule->UniConnection1->StartTransaction();
			try {
				mmodule->UniSQL1->Execute();
				mmodule->UniScript1->Execute();
				mmodule->UniConnection1->Commit();
				i = 1;
			}
			catch (...) {
				i = 0;
				mmodule->UniConnection1->Rollback();
			}
		}
		if (i)
			this->ShowToast(school_details_insert_completed);
		else
			this->ShowToast(school_details_insert_failed);

		ModalResult = mrOk;

	}
	else {
		if (UniEdit16->Text.operator == (L"")) {
			this->ShowToast(agent_name_empty);
			goto end;
		}
		if (-1 == UniComboBox6->ItemIndex) {
			this->ShowToast(agent_level_empty);
			goto end;
		}
		if (UniEdit12->Text.Trim().Length() && UniEdit13->Text.Trim().Length() && UniEdit15->Text.Trim().Length());
		else {
			this->ShowToast(contact_information_invalid);
			goto end;
		}
		if (UniListBox1->SelCount);
		else {
			this->ShowToast(agent_object_empty);
			goto end;
		}
		if (1 == UniComboBox6->ItemIndex && (-1 == UniComboBox4->ItemIndex)) {
			this->ShowToast(superior_agent_empty);
		}
	}
end: ;
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniCheckBox5Click(TObject *Sender) {
	if (UniCheckBox5->Checked) {
		UniCheckBox2->Checked = true;
		UniCheckBox6->Checked = false;
		if (UniCheckBox3->Checked) {
			UniCheckBox7->Checked = false;
			UniCheckBox8->Checked = true;
		}
	}
	else {
		UniCheckBox2->Checked = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TUniFormSignUp_1::UniCheckBox6Click(TObject *Sender) {
	if (UniCheckBox6->Checked) {
		UniCheckBox2->Checked = true;
		UniCheckBox5->Checked = false;
		if (UniCheckBox3->Checked) {
			UniCheckBox7->Checked = true;
			UniCheckBox8->Checked = false;
		}
	}
	else {
		UniCheckBox2->Checked = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniCheckBox8Click(TObject *Sender) {
	if (UniCheckBox8->Checked) {
		UniCheckBox3->Checked = true;
		UniCheckBox7->Checked = false;
		if (UniCheckBox2->Checked) {
			UniCheckBox5->Checked = true;
			UniCheckBox6->Checked = false;
		}
	}
	else {
		UniCheckBox3->Checked = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniCheckBox7Click(TObject *Sender) {
	if (UniCheckBox7->Checked) {
		UniCheckBox3->Checked = true;
		UniCheckBox8->Checked = false;
		if (UniCheckBox2->Checked) {
			UniCheckBox5->Checked = false;
			UniCheckBox6->Checked = true;
		}
	}
	else {
		UniCheckBox3->Checked = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniCheckBox2Click(TObject *Sender) {
	if (!UniCheckBox2->Checked) {
		UniCheckBox5->Checked = false;
		UniCheckBox6->Checked = false;
	}
	else {
		if (UniCheckBox8->Checked) {
			UniCheckBox5->Checked = true;
		}
		else if (UniCheckBox7->Checked) {
			UniCheckBox6->Checked = true;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TUniFormSignUp_1::UniCheckBox3Click(TObject *Sender) {
	if (!UniCheckBox3->Checked) {
		UniCheckBox7->Checked = false;
		UniCheckBox8->Checked = false;
	}
	else {
		if (UniCheckBox5->Checked) {
			UniCheckBox8->Checked = true;
		}
		else if (UniCheckBox6->Checked) {
			UniCheckBox7->Checked = true;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniCheckBox4Click(TObject *Sender) {
	// if(UniCheckBox4->Checked){
	// UniCheckBox2->Checked = false;
	// UniCheckBox3->Checked = false;
	// UniCheckBox5->Checked = false;
	// UniCheckBox6->Checked = false;
	// UniCheckBox8->Checked = false;
	// UniCheckBox7->Checked = false;
	//
	// }
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniComboBox2Change(TObject *Sender) {
	//
}
// ---------------------------------------------------------------------------

void __fastcall TUniFormSignUp_1::UniComboBox1Select(TObject *Sender) {

	school_details *sd = 0;
	int i, j, k, q;

	if (-1 == UniComboBox1->ItemIndex) {
		UniComboBox2->Items->Clear();
		UniComboBox2->Enabled = true;
		UniComboBox3->Items->Clear();
		UniComboBox3->Enabled = true;
		UniComboBox4->Items->Clear();
		UniComboBox4->Enabled = true;
		return;
	}

	std::map<int, school_details*>::iterator iter_sd_map;
	iter_sd_map = school_map.find(UniComboBox1->ItemIndex);
	if (school_map.end() != iter_sd_map) {
		sd = iter_sd_map->second;
		i = sd->phase[0];
		j = sd->phase[1];
		k = sd->phase[2];
		if (i) {
			UniComboBox2->Enabled = true;
			UniComboBox2->Items->Clear();
			for (q = 0; q < i; ++q) {
				UniComboBox2->Items->Add(primary_school_items[q]);
			}
		}
		else
			UniComboBox2->Enabled = false;
		if (j) {
			UniComboBox3->Enabled = true;
			UniComboBox3->Items->Clear();
			for (q = 0; q < j; ++q) {
				UniComboBox3->Items->Add(junior_middle_school_items[q]);
			}
		}
		else
			UniComboBox3->Enabled = false;
		if (k) {
			UniComboBox4->Enabled = true;
			UniComboBox4->Items->Clear();
			for (q = 0; q < k; ++q) {
				UniComboBox4->Items->Add(senior_middle_school_items[q]);
			}
		}
		else
			UniComboBox4->Enabled = false;
	}

}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniComboBox1Change(TObject *Sender) {
	/*
	 school_details *sd = 0;
	 int i, j, k;
	 std::map<int, school_details*>::iterator iter_sd_map;
	 iter_sd_map = school_map.find(UniComboBox1->ItemIndex);
	 if (school_map.end() != iter_sd_map);
	 else {
	 sd = iter_sd_map->second;
	 i = sd->phase[0];
	 j = sd->phase[1];
	 k = sd->phase[2];
	 if (i)
	 UniComboBox2->Enabled = true;
	 else
	 UniComboBox2->Enabled = false;
	 if (j)
	 UniComboBox3->Enabled = true;
	 else
	 UniComboBox3->Enabled = false;
	 if (k)
	 UniComboBox4->Enabled = true;
	 else
	 UniComboBox4->Enabled = false;
	 }
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TUniFormSignUp_1::UniFormDestroy(TObject *Sender) {
	school_details *sd = 0;
	std::map<int, school_details*>::iterator iter_sd_map;
	for (iter_sd_map = school_map.begin(); iter_sd_map != school_map.end(); ++iter_sd_map) {
		sd = iter_sd_map->second;
		delete sd;
	}
	school_map.clear();
}
// ---------------------------------------------------------------------------
