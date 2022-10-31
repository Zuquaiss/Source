#include "pch.h"
#include <fstream>
#include <string>

void MessageBoxChecked(LPCSTR WindowTitle) {
	HWND WinTitle = FindWindowA(NULL, WindowTitle);
	if (WinTitle > 0) {

		{
			exit(0);
			Sleep(2000);
		}
	}
}


void MessageBoxCheck() {
	MessageBoxChecked(DLL.Error);
	MessageBoxChecked(DLL.Title);
}

void ClosingGame()
{
	while (true)
	{
		MessageBoxCheck();
		Sleep(1000);
		return;
	}


}

void CloseGame() {
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(ClosingGame), NULL, 0, 0);
}
