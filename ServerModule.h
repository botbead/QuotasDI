//---------------------------------------------------------------------------

#ifndef ServerModuleH
#define ServerModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <uniGUIServer.hpp>
//---------------------------------------------------------------------------
class TUniServerModule : public TUniGUIServerModule
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TUniServerModule(TComponent* Owner);
	virtual void __fastcall FirstInit(void);

};
//---------------------------------------------------------------------------
TUniServerModule *UniServerModule(void);
//---------------------------------------------------------------------------
#endif
