#include "pch.h"

using namespace std;

char Description[200];

void ClasseWindow(LPCSTR WindowClasse)
{
	HWND WinClasse = FindWindowExA(NULL, NULL, WindowClasse, NULL);
	if (WinClasse >0)
	{
		{
			exit(0);
			strcpy_s(Description, WindowClasse);
			strcat_s(Description, " dedected.");
			strcat_s(Description, "\n");
			strcat_s(Description, DLL.Error);
			SendMessageA(WinClasse, WM_CLOSE, 0, 0);
			MessageBoxA(NULL, Description, DLL.Title, MB_SERVICE_NOTIFICATION | MB_ICONERROR);



		}
	}
}



__declspec(dllexport) void ClasseCheckWindow()
{
	ClasseWindow(AY_OBFUSCATE("Somethin")); // Process Haxor
	ClasseWindow(AY_OBFUSCATE("CurrPorts")); // CurrPorts
	ClasseWindow(AY_OBFUSCATE("WindowsForms10.Window.8.app.0.378734a")); // Process Haxor
	ClasseWindow(AY_OBFUSCATE("WindowsForms10.Window.8.app.0.2bf8098_r15_ad1")); // CurrPorts
	ClasseWindow(AY_OBFUSCATE("WindowsForms10.Window.8.app.0.141b42a_r14_ad1")); // Process Haxor
	ClasseWindow(AY_OBFUSCATE("WindowsForms10.Window.8.app.0.3b95145_r14_ad1")); // CurrPorts

}

void CheckClass()
{
	while (true)
	{
		ClasseCheckWindow();
		Sleep(5000);
	}
}

void ClassScan() {
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(CheckClass), NULL, 0, 0);
}

