// ---------------------------------------------------------------------------

#pragma hdrstop

#include <map>
#include "DM1.h"
#include "MainGUI.h"
#include "SimpleThreads.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule2 *DataModule2;

UnicodeString trade_num;
bank_feedback keys;
std::map<UnicodeString, UnicodeString*>bank_response;
SPIN_LOCK map_lock;

// ---------------------------------------------------------------------------
__fastcall TDataModule2::TDataModule2(TComponent* Owner) : TDataModule(Owner) {
	keys[total_fee] = L"total_fee";
	keys[time_end] = L"time_end";
	keys[transaction_id] = L"transaction_id";
	keys[retcode] = L"retcode";
	keys[trade_state] = L"trade_state";
	trade_num = L"out_trade_no";
	init_spin_lock(&map_lock);
}

// ---------------------------------------------------------------------------
void __fastcall TDataModule2::DataModuleCreate(TObject *Sender) {
	IdHTTPServer1->DefaultPort = 38361;
	IdHTTPServer1->Active = true;
}

// ---------------------------------------------------------------------------
void __fastcall TDataModule2::DataModuleDestroy(TObject *Sender) {
	IdHTTPServer1->Active = false;
}

// ---------------------------------------------------------------------------
void __fastcall TDataModule2::IdHTTPServer1CommandGet(TIdContext *AContext, TIdHTTPRequestInfo *ARequestInfo,
	TIdHTTPResponseInfo *AResponseInfo)

{
	int i;
	UnicodeString *values;
	UnicodeString the_trade_num;
	UnicodeString bank_r = L"BANK_R:";
	std::map<UnicodeString, UnicodeString*>::iterator it_map;
	UnicodeString cmd = ARequestInfo->Command;
	// if (hcGET == ARequestInfo->CommandType);
	TStrings* paras = ARequestInfo->Params;

	Form1->Memo1->Lines->Add(L"cmd\t" + cmd);
	if (paras->Count) {
		Form1->Memo1->Lines->Add(UnicodeString(L"count\t") + paras->Count);
		if (1 != paras->Count) {
			values = new UnicodeString[out_trade_no];
			for (int i = 0; i < paras->Count; i++) {
				if (paras->Names[i] == keys[total_fee]) {
					values[total_fee] = paras->Values[paras->Names[i]];
				}
				else if (paras->Names[i] == keys[time_end]) {
					values[time_end] = paras->Values[paras->Names[i]];
				}
				else if (paras->Names[i] == keys[transaction_id]) {
					values[transaction_id] = paras->Values[paras->Names[i]];
				}
				else if (paras->Names[i] == keys[retcode]) {
					values[retcode] = paras->Values[paras->Names[i]];
				}
				else if (paras->Names[i] == keys[trade_state]) {
					values[trade_state] = paras->Values[paras->Names[i]];
				}
				else if (paras->Names[i] == trade_num) {
					the_trade_num = paras->Values[paras->Names[i]];
				}

				Form1->Memo1->Lines->Add(L"name\t" + paras->Names[i] + L"\tvalue:" + paras->Values[paras->Names[i]]);
			}
#ifdef _DEBUG
			for (i = retcode; i < out_trade_no; ++i) {
				Form1->Memo1->Lines->Add(values[retcode]);
				Form1->Memo1->Lines->Add(values[trade_state]);
				Form1->Memo1->Lines->Add(values[transaction_id]);
				Form1->Memo1->Lines->Add(values[total_fee]);
				Form1->Memo1->Lines->Add(values[time_end]);
			}
#endif
			lock(&map_lock);
			it_map = bank_response.find(the_trade_num);
			if (bank_response.end() != it_map);
			else
				bank_response.insert(std::pair<UnicodeString, UnicodeString *>(the_trade_num, values));
			unlock(&map_lock);
		}
		else {
			Form1->Memo1->Lines->Add(L"name\t" + paras->Names[0] + L"\tvalue:" + paras->Values[paras->Names[0]]);
			lock(&map_lock);
			it_map = bank_response.find(paras->Values[paras->Names[0]]);
			if (it_map != bank_response.end()) {
				values = it_map->second;
				for (i = retcode; i < out_trade_no; ++i) {
					bank_r += values[i];
					bank_r += L",";
				}
				delete[]values;
				bank_response.erase(it_map);
			}
			unlock(&map_lock);
		}
	}
	Form1->Memo1->Lines->Add(L"UnparsedParams\t" + ARequestInfo->UnparsedParams);
	Form1->Memo1->Lines->Add(L"Document\t" + ARequestInfo->Document);
	AResponseInfo->ContentText = bank_r;
}
// ---------------------------------------------------------------------------
