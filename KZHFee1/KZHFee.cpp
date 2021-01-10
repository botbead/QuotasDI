// ---------------------------------------------------------------------------

#include <vcl.h>
#include <UniGUIVars.hpp>

USEFORM("SignUp.cpp", UniFormSignUp); /* TUniForm: File Type */
USEFORM("ServerModule.cpp", UniServerModule); /* TUniGUIServerModule: File Type */
USEFORM("protocols.cpp", UniForm1); /* TUniForm: File Type */
USEFORM("Profile.cpp", UniFormSignUp_1); /* TUniForm: File Type */
USEFORM("Main.cpp", MainForm); /* TUniForm: File Type */
USEFORM("Login.cpp", UniLoginForm1); /* TUniLoginForm: File Type */
USEFORM("PagePayment.cpp", UniPagePayment); /* TUniForm: File Type */
USEFORM("OrdersQuery.cpp", UniForm2); /* TUniForm: File Type */
USEFORM("MainModule.cpp", UniMainModule); /* TUniGUIMainModule: File Type */
// ---------------------------------------------------------------------------
#ifdef _WIN64
#pragma link "UniGUIVars.o"
#else
#pragma link "UniGUIVars.obj"
#endif

#pragma KZHFee

// ---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	try {
		Forms::Application->Initialize();
		Uniguivars::CreateServerModule(__classid(TUniServerModule));
		Forms::Application->Run();
	}
	catch (Exception &exception) {

	}
	return 0;
}
// ---------------------------------------------------------------------------
