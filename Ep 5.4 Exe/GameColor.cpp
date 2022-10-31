#include "pch.h"

int Speed = 1000;

DWORD nameReturn1 = 0x44BA8D;
DWORD nameReturn2 = 0x50C669;
DWORD skillcolorReturn = 0x4A2850;
DWORD Color = 0xFF29ffa6;

void RGBColorLoop() {

	while (true) {
		Color = 0xFFff2929;
		Sleep(Speed);
		Color = 0xFFff294c;
		Sleep(Speed);
		Color = 0xFFff2970;
		Sleep(Speed);
		Color = 0xFFff2994;
		Sleep(Speed);
		Color = 0xFFff29b8;
		Sleep(Speed);
		Color = 0xFFff29db;
		Sleep(Speed);
		Color = 0xFFff29ff;
		Sleep(Speed);
		Color = 0xFFdb29ff;
		Sleep(Speed);
		Color = 0xFFb829ff;
		Sleep(Speed);
		Color = 0xFF9429ff;
		Sleep(Speed);
		Color = 0xFF7029ff;
		Sleep(Speed);
		Color = 0xFF4d29ff;
		Sleep(Speed);
		Color = 0xFF2929ff;
		Sleep(Speed);
		Color = 0xFF294dff;
		Sleep(Speed);
		Color = 0xFF2970ff;
		Sleep(Speed);
		Color = 0xFF2994ff;
		Sleep(Speed);
		Color = 0xFF29b8ff;
		Sleep(Speed);
		Color = 0xFF29dbff;
		Sleep(Speed);
		Color = 0xFF29ffff;
		Sleep(Speed);
		Color = 0xFF29ffdb;
		Sleep(Speed);
		Color = 0xFF29ffb8;
		Sleep(Speed);
		Color = 0xFF29ff94;
		Sleep(Speed);
		Color = 0xFF29ff70;
		Sleep(Speed);
		Color = 0xFF29ff4d;
		Sleep(Speed);
		Color = 0xFF29ff29;
		Sleep(Speed);
		Color = 0xFF4dff29;
		Sleep(Speed);
		Color = 0xFF70ff29;
		Sleep(Speed);
		Color = 0xFF94ff29;
		Sleep(Speed);
		Color = 0xFFb8ff29;
		Sleep(Speed);
		Color = 0xFFdbff29;
		Sleep(Speed);
		Color = 0xFFffff29;
		Sleep(Speed);
		Color = 0xFFffdb29;
		Sleep(Speed);
		Color = 0xFFffb829;
		Sleep(Speed);
		Color = 0xFFff9429;
		Sleep(Speed);
		Color = 0xFFff7029;
		Sleep(Speed);
		Color = 0xFFff4c29;
		Sleep(Speed);
	}
}


DWORD SkillTimer = 0xF029ffa6;
void TransparentColorLoop() {

	while (true) {
		SkillTimer = 0xF0ff2929;
		Sleep(Speed);
		SkillTimer = 0xF0ff294c;
		Sleep(Speed);
		SkillTimer = 0xF0ff2970;
		Sleep(Speed);
		SkillTimer = 0xF0ff2994;
		Sleep(Speed);
		SkillTimer = 0xF0ff29b8;
		Sleep(Speed);
		SkillTimer = 0xF0ff29db;
		Sleep(Speed);
		SkillTimer = 0xF0ff29ff;
		Sleep(Speed);
		SkillTimer = 0xF0db29ff;
		Sleep(Speed);
		SkillTimer = 0xF0b829ff;
		Sleep(Speed);
		SkillTimer = 0xF09429ff;
		Sleep(Speed);
		SkillTimer = 0xF07029ff;
		Sleep(Speed);
		SkillTimer = 0xF04d29ff;
		Sleep(Speed);
		SkillTimer = 0xF02929ff;
		Sleep(Speed);
		SkillTimer = 0xF0294dff;
		Sleep(Speed);
		SkillTimer = 0xF02970ff;
		Sleep(Speed);
		SkillTimer = 0xF02994ff;
		Sleep(Speed);
		SkillTimer = 0xF029b8ff;
		Sleep(Speed);
		SkillTimer = 0xF029dbff;
		Sleep(Speed);
		SkillTimer = 0xF029ffff;
		Sleep(Speed);
		SkillTimer = 0xF029ffdb;
		Sleep(Speed);
		SkillTimer = 0xF029ffb8;
		Sleep(Speed);
		SkillTimer = 0xF029ff94;
		Sleep(Speed);
		SkillTimer = 0xF029ff70;
		Sleep(Speed);
		SkillTimer = 0xF029ff4d;
		Sleep(Speed);
		SkillTimer = 0xF029ff29;
		Sleep(Speed);
		SkillTimer = 0xF04dff29;
		Sleep(Speed);
		SkillTimer = 0xF070ff29;
		Sleep(Speed);
		SkillTimer = 0xF094ff29;
		Sleep(Speed);
		SkillTimer = 0xF0b8ff29;
		Sleep(Speed);
		SkillTimer = 0xF0dbff29;
		Sleep(Speed);
		SkillTimer = 0xF0ffff29;
		Sleep(Speed);
		SkillTimer = 0xF0ffdb29;
		Sleep(Speed);
		SkillTimer = 0xF0ffb829;
		Sleep(Speed);
		SkillTimer = 0xF0ff9429;
		Sleep(Speed);
		SkillTimer = 0xF0ff7029;
		Sleep(Speed);
		SkillTimer = 0xF0ff4c29;
		Sleep(Speed);
	}
}

DWORD BuffColorRetn = 0x4C04A4;

__declspec(naked) void BuffColor()
{
	__asm {

		push SkillTimer
		jmp BuffColorRetn

	}
}

__declspec(naked) void SkillColor()
{
	__asm {

		mov eax, 0xF0424242
		jmp skillcolorReturn

	}
}

__declspec(naked) void nameHook1()
{
	_asm
	{
		mov eax, Color
		mov dword ptr ds : [esp + 0x18] , eax
		jmp nameReturn1
	}
}

__declspec(naked) void nameHook2()
{
	_asm
	{
		mov ebx, Color
		jmp nameReturn2
	}
}


unsigned char IconTimerSize[] = { 0x6A ,0x04 };


void GameColor()
{

	Hook((void*)0x44BA85, nameHook1, 8);
	Hook((void*)0x50C664, nameHook2, 5);
	Hook((void*)0x4A284B, SkillColor, 5);
	Hook((void*)0x4C049F, BuffColor, 5);
	memcpy((void*)0x4A2FD9, IconTimerSize, sizeof(IconTimerSize));
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(RGBColorLoop), NULL, 0, 0);
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(TransparentColorLoop), NULL, 0, 0);
}