#include "pch.h"


void LocationConfig() {
	GetPrivateProfileStringA("VIDEO", "LOCATION_X", "", DLL.szLocationX, 255, ".\\CONFIG.ini");
	GetPrivateProfileStringA("VIDEO", "LOCATION_Y", "", DLL.szLocationY, 255, ".\\CONFIG.ini");
	DLL.LocationX = atoi(DLL.szLocationX);
	DLL.LocationY = atoi(DLL.szLocationY);
	DLL.oldLocationX = atoi(DLL.szLocationX);
	DLL.oldLocationY = atoi(DLL.szLocationY);
}

void SaveLocation() {
	_itoa_s(DLL.LocationX, DLL.newLocationX, 10);
	_itoa_s(DLL.LocationY, DLL.newLocationY, 10);

	if (DLL.oldLocationX != DLL.LocationX) {
		WritePrivateProfileStringA("VIDEO", "LOCATION_X", DLL.newLocationX, ".\\CONFIG.ini");
		WritePrivateProfileStringA("VIDEO", "LOCATION_Y", DLL.newLocationY, ".\\CONFIG.ini");
	}
}

DWORD locationReturn1 = 0x4C0463;

__declspec(naked) void Mouse()
{
	_asm
	{
		push ebx
		mov ebx, 0x71C2A4
		mov ebx, [ebx]
		mov[DLL.MouseX], ebx
		mov ebx, 0x71C2A8
		mov ebx, [ebx]
		mov[DLL.MouseY], ebx
		pop ebx
		sar edi, 0x01
		mov edi, [DLL.LocationX]
		cmp eax, ecx
		mov ebx, [DLL.LocationY]
		jmp locationReturn1

	}
}

__declspec(naked) void GetLocation()
{
	_asm
	{
		push esi
		mov esi, GetAsyncKeyState
		push edi
		mov edi, 0x008000
		lea eax, [ecx + 0x00]
		locationReturn2:
		push 0x10
			call esi
			test di, ax
			je locationReturn2
			push 0x02
			call esi
			test di, ax
			je locationReturn2
			mov eax, [DLL.MouseX]
			mov[DLL.LocationX], eax
			mov eax, [DLL.MouseY]
			mov[DLL.LocationY], eax
			jmp locationReturn2
	}
}

DWORD locationReturn3 = 0x4C058E;

__declspec(naked) void NewLocation()
{
	_asm
	{
		mov edi, [DLL.LocationX]
		jmp locationReturn3
	}
}


void UpdateLocations() {
	while (true) {
		SaveLocation();
		Sleep(1000);
	}
}

void BuffInit() {
	SaveLocation();
	LocationConfig();
	Hook((LPVOID)0x4C0456, Mouse, 6);
	Hook((LPVOID)0x4C0588, NewLocation, 6);
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(GetLocation), NULL, 0, 0);
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(UpdateLocations), NULL, 0, 0);
}