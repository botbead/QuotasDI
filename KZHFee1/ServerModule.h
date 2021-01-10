// ---------------------------------------------------------------------------

#ifndef ServerModuleH
#define ServerModuleH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIServer.hpp>
#include "DAScript.hpp"
#include "DBAccess.hpp"
#include "MySQLUniProvider.hpp"
#include "Uni.hpp"
#include "UniProvider.hpp"
#include "UniScript.hpp"
#include <Data.DB.hpp>
// #include <System.Net.HttpClient.hpp>
// #include <System.Net.HttpClientComponent.hpp>
// #include <System.Net.URLClient.hpp>
// #include <IdBaseComponent.hpp>
// #include <IdComponent.hpp>
// #include <IdCustomHTTPServer.hpp>
// #include <IdCustomTCPServer.hpp>
// #include <IdHTTPServer.hpp>
// #include <IdContext.hpp>

// ---------------------------------------------------------------------------
class TUniServerModule : public TUniGUIServerModule {
__published: // IDE-managed Components
	TMySQLUniProvider *MySQLUniProvider1;
	TUniConnection *UniConnection1;
	TUniScript *UniScript1;

	void __fastcall UniGUIServerModuleCreate(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TUniServerModule(TComponent* Owner);
	virtual void __fastcall FirstInit(void);

};

// ---------------------------------------------------------------------------
TUniServerModule *UniServerModule(void);
// ---------------------------------------------------------------------------
#endif
