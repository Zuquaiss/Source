#include "pch.h"

DWORD dwVersionRetn = 0x599472;
DWORD dwVersionCall = 0x597F60;
UINT32 ServerVersion[] = { 0x44211221 };


__declspec(naked) void Version()
{
	_asm
	{
		mov ecx, ServerVersion
		mov[esp + 0xB], ecx
		call dwVersionCall
		jmp dwVersionRetn
	}
}

DWORD data_1 = 0x40E2DD;


__declspec(naked) void data1()
{

	__asm {

		push 0x00008000
		jmp data_1
	}
}

DWORD data_2 = 0x40D3AB;

__declspec(naked) void data2()
{

	__asm {

		push 0x00004000
		jmp data_2
	}
}

DWORD dwSahXorKeys = 0x40E166;


__declspec(naked) void SahXorKeys()
{

	__asm {

		pushad
		mov esi, [esp + 0x24]
		mov ebx, [esi]
		xor ebx, 0x74
		xor ebx, 0x61
		xor ebx, 0x68
		xor ebx, 0x25
		mov[esi], ebx
		popad
		mov eax, [esp + 0x1C]
		add esp, 0x0C
		jmp dwSahXorKeys


	}
}

unsigned char Part3[] = "fff";

void Protect() 
{
	Hook((void*)(0x40E2D8), data1, 5);
	Hook((void*)(0x40D3A6), data2, 5);
	Hook((void*)(0x40E15F), SahXorKeys, 7);
	memcpy((void*)0x6BC810, Part3, sizeof(Part3));
	Hook((LPVOID)0x599469, Version, 8);
}

