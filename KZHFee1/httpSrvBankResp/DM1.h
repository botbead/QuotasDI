// ---------------------------------------------------------------------------

#ifndef DM1H
#define DM1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomHTTPServer.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdHTTPServer.hpp>
#include <IdContext.hpp>
#include <map>

// ---------------------------------------------------------------------------

enum required_params {
	retcode, trade_state, transaction_id, total_fee, time_end, out_trade_no
};

typedef String bank_feedback[out_trade_no];

// ---------------------------------------------------------------------------
class TDataModule2 : public TDataModule {
__published: // IDE-managed Components
	TIdHTTPServer *IdHTTPServer1;

	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall IdHTTPServer1CommandGet(TIdContext *AContext, TIdHTTPRequestInfo *ARequestInfo,
		TIdHTTPResponseInfo *AResponseInfo);

private: // User declarations
public: // User declarations
	__fastcall TDataModule2(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TDataModule2 *DataModule2;
// ---------------------------------------------------------------------------
#endif
