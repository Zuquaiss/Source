#include "pch.h"

DWORD lock_1 = 0x5272A0;
DWORD lock_2 = 0x4FA9B6;
DWORD lock_3 = 0x527450;
DWORD lock_4 = 0x4FD6B7;
DWORD lock_5 = 0x528B00;
DWORD lock_6 = 0x4FB197;
DWORD lock_7 = 0x7198FC;
DWORD lock_8 = 0x4F9095;
DWORD lock_9 = 0x4F8D54;



__declspec(naked) void skillock()
{

	__asm {

		push 0x000001C3
		push 0x0000009C
		lea ecx, [esi + 0x0000EA0C]
		call lock_1
		push 0x00000194
		jmp lock_2

	}
}


__declspec(naked) void skillock2()
{

	__asm {

		call lock_3
		mov edx, [esi + 0x00000BF0]
		mov eax, [esi + 0x00000BEC]
		push edx
		push eax
		lea ecx, [esi + 0x0000EA0C]
		call lock_3
		jmp lock_4

	}
}


//skillwindlock
__declspec(naked) void skillock3()
{

	__asm {

		call lock_5
		mov edx, [esi + 0x00000BF0]
		mov eax, [esi + 0x00000BEC]
		push edx
		push eax
		lea ecx, [esi + 0x0000EA0C]
		call lock_5
		jmp lock_6

	}
}


//skillwindlock
__declspec(naked) void skillock4()
{

	__asm {

		cmp[esi + 0x0000EAAF], bl
		sete cl
		mov edx, lock_7
		mov[edx], ecx
		xor edx, edx
		cmp[esi + 0x0000C1C7], bl
		jmp lock_8

	}
}

//skillwindlock
__declspec(naked) void skillock5()
{

	__asm {

		mov[esi + 0x0000D34F], al
		mov eax, lock_7
		movzx eax, byte ptr[eax]
		test eax, eax
		setne al
		mov[esi + 0x0000EAAF], al
		jmp lock_9


	}
}



void skillFunc() {
	Hook((void*)(0x4FA9B1), skillock, 5);
	Hook((void*)(0x4FD6B2), skillock2, 5);
	Hook((void*)(0x4FB192), skillock3, 5);
	Hook((void*)(0x4F908F), skillock4, 6); // nop oldugu i�in 5 giri�ten 6 ya y�kseltiyorum
	Hook((void*)(0x4F8D4E), skillock5, 6);
}



