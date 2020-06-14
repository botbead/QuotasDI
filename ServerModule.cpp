//---------------------------------------------------------------------------

#include <vcl.h>
#include <UniGUIVars.hpp>

#pragma hdrstop

#include "ServerModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TUniServerModule *UniServerModule(void)
{
   return( (TUniServerModule *)UniGUIServerInstance() );
}
//---------------------------------------------------------------------------

__fastcall TUniServerModule::TUniServerModule(TComponent* Owner)
		: TUniGUIServerModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TUniServerModule::FirstInit()
{
  Uniguivars::InitServerModule(this);
}
//---------------------------------------------------------------------------

void __RegisterServerModuleClass() {
  Uniguivars::RegisterServerModuleClass(__classid(TUniServerModule));
}

#pragma startup __RegisterServerModuleClass
