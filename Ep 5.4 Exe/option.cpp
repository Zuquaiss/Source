#include "pch.h"

DWORD dwBindCall = 0x5272A0;
DWORD dwBindRetn = 0x4FA9B6;

DWORD dwRenderCall = 0x528B00;
DWORD dwRenderRetn = 0x4FB197;

DWORD dwClickCall = 0x527450;
DWORD dwClickRetn = 0x4FD6B7;
DWORD dwClickJump = 0x4FD724;

DWORD dwSaveRetn = 0x4F90A0;
DWORD dwControlRetn = 0x4F8D54;

void SettingsKey() 
{
	//--> SETTINGS <--//
	GetPrivateProfileStringA("VIDEO", DLL.ccICT, "", DLL.cICT, 255, ".\\CONFIG.ini");
	if (DLL.cICT == DLL.stTRUE) {
		_asm {	mov byte ptr[DLL.ICT], 0x1	}
	}
	else {
		_asm {	mov byte ptr[DLL.ICT], 0x0	}
	}

	GetPrivateProfileStringA("VIDEO", DLL.ccICO, "", DLL.cICO, 255, ".\\CONFIG.ini");
	if (DLL.cICO == DLL.stTRUE) {
		_asm {	mov byte ptr[DLL.ICO], 0x1	}
	}
	else {
		_asm {	mov byte ptr[DLL.ICO], 0x0	}
	}
}




__declspec(naked) void Bind()
{
	__asm {

		//fps
		push 0x1DB
		push 0x23
		lea ecx, [esi + 0xDE5C]
		call dwBindCall
		//skillwindlock
		push 0x1C3
		push 0x9C
		lea ecx, [esi + 0xEA0C]
		call dwBindCall

		push 0x1DB
		push 0x9C
		lea ecx, [esi + 0x00F5BC]
		call dwBindCall

		push 0x194
		jmp dwBindRetn
	}
}

__declspec(naked) void Click()
{
	__asm {

		//fps
		call dwClickCall
		mov edx, [esi + 0xBF0]
		mov eax, [esi + 0xBEC]
		push edx
		push eax
		lea ecx, [esi + 0xDE5C]

		//skillwindlock
		call dwClickCall
		mov edx, [esi + 0xBF0]
		mov eax, [esi + 0xBEC]
		push edx
		push eax
		lea ecx, [esi + 0xEA0C]
		call dwClickCall

		mov edx, [esi + 0x000BF0]
		mov eax, [esi + 0x000BEC]
		push edx
		push eax
		lea ecx, [esi + 0x00F5BC]
		call dwClickCall


		mov edx, [esi + 0xBF0]
		jmp dwClickRetn
		jmp dwClickJump
	}
}

__declspec(naked) void Render()
{
	__asm {
		//fps
		call dwRenderCall
		mov edx, [esi + 0xBF0]
		mov eax, [esi + 0xBEC]
		push edx
		push eax
		lea ecx, [esi + 0xDE5C]
		//skillwindlock
		call dwRenderCall


		mov edx, [esi + 0xBF0]
		mov eax, [esi + 0xBEC]
		push edx
		push eax
		lea ecx, [esi + 0xEA0C]
		call dwRenderCall


		mov edx, [esi + 0x000BF0]
		mov eax, [esi + 0x000BEC]
		push edx
		push eax
		lea ecx, [esi + 0x00F5BC]
		call dwRenderCall

		jmp dwRenderRetn
	}
}


__declspec(naked) void Save()
{
	__asm {
		mov eax, 0x71986C
		mov[eax], ecx

		cmp[esi + 0xDEFF], dx
		setne cl
		mov byte ptr[DLL.ICT], cl

		cmp[esi + 0x00F65F], dx
		setne cl
		mov byte ptr[DLL.ICO], cl

		cmp[esi + 0x0000EAAF], bl
		sete cl
		mov edx, 0x7198FC
		mov[edx], ecx
		xor edx, edx
		cmp[esi + 0x0000C1C7], bl

		pushad
		cmp byte ptr[DLL.ICT], 0x0
		push 0x7191E0
		mov esi, [0x6BB2C4]
		mov esi, [esi]
		je disabled1
		push 0x6C0260 // True
		push DLL.ccICT
		push 0x6BB6E8 // Video
		jmp end1
		disabled1 :
		push 0x6BB724 // False
		push DLL.ccICT
		push 0x6BB6E8 // Video
		end1 :
		call esi
		popad

		pushad
		mov esi, 0x7198FC
		cmp byte ptr[esi], 00
		push 0x7191E0
		mov esi, [0x6BB2C4]
		mov esi, [esi]
		je False3
		push 0x6C0260 // True
		push 0x6BB65C // skillwindlock
		push 0x6BB6E8 // Video
		jmp Jump3
		False3 :
		push 0x6BB724 // False
		push 0x6BB65C // skillwindlock
		push 0x6BB6E8 // Video
		Jump3 :
		call esi
		popad


		pushad
		cmp byte ptr[DLL.ICO], 0x0
		push 0x7191E0
		mov esi, [0x6BB2C4]
		mov esi, [esi]
		je disabled2
		push 0x6C0260 // True
		push DLL.ccICO
		push 0x6BB6E8 // Video
		jmp end2
		disabled2 :
		push 0x6BB724 // False
		push DLL.ccICO
		push 0x6BB6E8 // Video
		end2:
		call esi
		popad
	
		jmp dwSaveRetn
	}
}

__declspec(naked) void Control()
{
	__asm {

		mov[esi + 0x00D34F], al
		cmp byte ptr[DLL.ICT], 0x0
		setne dl
		mov[esi + 0xDEFF], dl

		cmp byte ptr[DLL.ICO], 00
		setne dl
		mov[esi + 0x00F65F], dl

		mov[esi + 0xD34F], al
		mov eax, 0x7198FC
		movzx eax, byte ptr[eax]
		test eax, eax
		setne al
		mov[esi + 0xEAAF], al

		jmp dwControlRetn
	}
}

DWORD dwSkillRetn = 0x4F9095;

//skillwindlock
__declspec(naked) void skillwindlock()
{

	__asm {

		cmp[esi + 0xEAAF], bl
		sete cl
		mov edx, 0x7198FC
		mov[edx], ecx
		xor edx, edx
		cmp[esi + 0xC1C7], bl
		jmp dwSkillRetn

	}
}

unsigned char Custom[] = { 0xFF, 0x24, 0x85, 0xCC, 0x9B, 0x4F, 0x00 };
UINT OptionGraphicsY[] = { 0x249 };


void Settings() {
	SettingsKey();
	Hook((LPVOID)0x4FA9B1, Bind, 5);
	Hook((LPVOID)0x4FD6B2, Click, 5);
	Hook((LPVOID)0x4FB192, Render, 5);
	//Hook((LPVOID)(0x4F908F), skillwindlock, 6);
	Hook((LPVOID)0x4F909A, Save, 6);
	Hook((LPVOID)0x4F8D4E, Control, 6);
	writeBytes((void*)0x4F9117, Custom, sizeof(Custom));
	writeBytes((void*)0x4F7598, OptionGraphicsY, sizeof(OptionGraphicsY));
}