//---------------------------------------------------------------------------

#include <vcl.h>
#include <UniGUIVars.hpp>


USEFORM("ProjKPIQuota.cpp", UniForm2); /* TUniForm: File Type */
USEFORM("ProjInfoFrame.cpp", UniFrame1); /* TUniFrame: File Type */
USEFORM("UserMng.cpp", UniForm4); /* TUniForm: File Type */
USEFORM("ServerModule.cpp", UniServerModule); /* TUniGUIServerModule: File Type */
USEFORM("SalarySum.cpp", UniForm3); /* TUniForm: File Type */
USEFORM("Login.cpp", UniLoginForm1); /* TUniLoginForm: File Type */
USEFORM("NewProj.cpp", UniForm1); /* TUniForm: File Type */
USEFORM("MainModule.cpp", UniMainModule); /* TUniGUIMainModule: File Type */
USEFORM("Main.cpp", MainForm); /* TUniForm: File Type */
USEFORM("Staff.cpp", UniForm7); /* TUniForm: File Type */
USEFORM("FixedExpenses.cpp", UniForm8); /* TUniForm: File Type */
//---------------------------------------------------------------------------
#ifdef _WIN64
	#pragma link "UniGUIVars.o"
#else
	#pragma link "UniGUIVars.obj"
#endif

#pragma QuotasDI0

//---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
  	{
		Forms::Application->Initialize();
		Uniguivars::CreateServerModule(__classid(TUniServerModule));
		Forms::Application->Run();
	}
	catch (Exception &exception)
	{

	}
	return 0;
}
//---------------------------------------------------------------------------
