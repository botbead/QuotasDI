// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
// ---------------------------------------------------------------------------
USEFORM("MainGUI.cpp", Form1);
USEFORM("DM1.cpp", DataModule2); /* TDataModule: File Type */

// ---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int) {
	try {
		Application->Initialize();

		Application->Title = L"BotbeadOrg";
		CreateMutex(0, 0, L"BotbeadOrg");
		if (ERROR_ALREADY_EXISTS == GetLastError()) {
			MessageBox(Application->Handle, L"The HTTP Server is running!", L"Warning", MB_OK | MB_ICONWARNING);
			return 0;
		}

		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TDataModule2), &DataModule2);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
// ---------------------------------------------------------------------------
