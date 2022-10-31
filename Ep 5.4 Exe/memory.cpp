#include "pch.h"

#ifdef _MANAGED
#pragma managed(push, off)
#endif
char NameProcess[100] = { 0 };

ANITHACK_PROCDUMP g_ProcessesDumps[MAX_PROCESS_DUMP] = {

{0x1C4D48, { 0xE8, 0x0F, 0x05, 0x00, 0x00, 0xE9, 0x85, 0xFE}},// Shaiya Motion Hack
{0x724D48, { 0xE8, 0x0F, 0x05, 0x00, 0x00, 0xE9, 0x85, 0xFE}} // Shaiya Motion Hack
};

void SystemProcessesScan() {
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(hProcessSnap, &pe32))
		{
			do
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
				if (hProcess != NULL)
				{
					if (ScanProcessMemory(hProcess))
					{
						{
							MessageBoxA(NULL, DLL.Error, DLL.Title , MB_SERVICE_NOTIFICATION | MB_ICONERROR);
							exit(0);
						}
					}
				}
			} while (Process32Next(hProcessSnap, &pe32));
		}
	}
	CloseHandle(hProcessSnap);
}

bool ScanProcessMemory(HANDLE hProcess) {
	for (int i = 0; i < MAX_PROCESS_DUMP; i++)
	{
		char aTmpBuffer[MAX_DUMP_SIZE];
		SIZE_T aBytesRead = 0;
		ReadProcessMemory(hProcess, (LPCVOID)g_ProcessesDumps[i].m_aOffset, (LPVOID)aTmpBuffer, sizeof(aTmpBuffer), &aBytesRead);

		if (memcmp(aTmpBuffer, g_ProcessesDumps[i].m_aMemDump, MAX_DUMP_SIZE) == 0)
		{
			return true;
			break;
		}
	}
	return false;
}

void DumpScanning() {
	while (true)
	{
		SystemProcessesScan();
		Sleep(5000);

	}


}

void MemoryScan(){
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(DumpScanning), NULL, 0, 0);
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


