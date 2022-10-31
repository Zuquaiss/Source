#include "pch.h"


DWORD sett1 = 0x7198F8;
DWORD sett2 = 0x2209400;
DWORD sett3 = 0x55B66C;
DWORD sett4 = 0x55C02C;
DWORD sett5 = 0x220FCE4;
DWORD sett6 = 0x220FE10;
DWORD sett7 = 0x220F834;
DWORD set1 = 0x220FCE4;
DWORD set2 = 0x220FE10;
DWORD set3 = 0x220F834;
DWORD set4 = 0x55B20C;
DWORD set5 = 0x55B645;


__declspec(naked) void effsettings1()
{

	__asm {

		cmp[esp + 0x000000F4], offset sett5
		je _eff1
		cmp[esp + 0x000000F4], offset sett6
		je _eff1
		cmp[esp + 0x000000F4], offset sett7
		je _eff1
		push eax
		mov eax, sett1
		cmp dword ptr[eax], 0x00
		pop eax
		je _eff2
		_eff1 :
		mov eax, sett2
			mov eax, [eax]
			jmp sett3
			_eff2 :
		jmp sett4

	}
}



//settings
__declspec(naked) void effsettings2()
{

	__asm {

		cmp[esp + 0x00000150], offset set1
		je _eff_1
		cmp[esp + 0x00000150], offset set2
		je _eff_1
		cmp[esp + 0x00000150], offset set3
		je _eff_1
		push eax
		mov eax, sett1
		cmp dword ptr[eax], 0x00
		pop eax
		je _eff_2
		_eff_1 :
		mov eax, sett2
			mov eax, [eax]
			jmp set4
			_eff_2 :
		jmp set5

	}
}



void effFunc() 
{
	Hook((void*)(0x55B667), effsettings1, 5);
	Hook((void*)(0x55B207), effsettings2, 5);
}