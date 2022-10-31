#include "pch.h"

DWORD returnStatpoint = 0x5038CC;

__declspec(naked) void dwStatPoints()
{
	_asm
	{

		cmp ecx,0x14
		jb originalcode
		push eax
		push ecx
		push 0x10
		call GetAsyncKeyState
		test ah,ah
		pop ecx
		pop eax
		jge originalcode

		sub ecx,0x14
		mov dword ptr ds : [esi + 0x48] , ecx
		add word ptr ds : [esi + eax * 2 + 0x3C] , 0x14
		jmp returnStatpoint

		originalcode:
		dec ecx
		mov dword ptr ds : [esi + 0x48] , ecx
		inc word ptr ds : [esi + eax * 2 + 0x3C]
		jmp returnStatpoint


	}
}


void StatPoints() {
	Hook((void*)(0x5038C3), dwStatPoints, 9);
}