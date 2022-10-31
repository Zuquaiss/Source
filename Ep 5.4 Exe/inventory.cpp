#include "pch.h"


DWORD GoldPosReturn = 0x4F6D4C;


__declspec(naked) void GoldPos()
{

	__asm {

		add edx, 0x1BD
		sub ecx, eax
		push edx
		add ecx, 0x69
		jmp GoldPosReturn

	}
}


DWORD invenReturn = 0x4F676B;
int inven1;
int inven2;


__declspec(naked) void InventoryNpcs()
{

	__asm {

		pushad
		mov eax, [edi + 0x04]
		mov ecx, [edi + 0x08]
		mov[inven1], eax
		mov[inven2], ecx
		mov eax, [inven1]
		add eax, 0x0B
		cmp[DLL.MouseX], eax
		jle _one
		mov ecx, [inven1]
		add ecx, 0x4A
		cmp[DLL.MouseX], ecx
		jnl _one
		mov edx, [inven2]
		add edx, 0x0001D1
		cmp[DLL.MouseY], edx
		jle _one
		mov eax, [inven2]
		add eax, 0x0001E5
		cmp[DLL.MouseY], eax
		jnl _one
		push 0x01
		call GetAsyncKeyState
		movsx ecx, ax
		and ecx, 0x008000
		je _one
		push ebx
		mov ebx, 0x86DE30
		mov byte ptr[ebx], 0x00
		mov ebx, 0x86DE2C
		mov byte ptr[ebx], 0x00
		mov ebx, 0x868DD4
		mov byte ptr[ebx], 0x65
		mov ebx, 0x21FED2C
		mov[ebx], 0x01046A
		pop ebx
		_one :
		mov edx, [inven1]
			add edx, 0x60
			cmp[DLL.MouseX], edx
			jle _two
			mov eax, [inven1]
			add eax, 0xA1
			cmp[DLL.MouseX], eax
			jnl _two
			mov ecx, [inven2]
			add ecx, 0x0001D1
			cmp[DLL.MouseY], ecx
			jle _two
			mov edx, [inven2]
			add edx, 0x0001E5
			cmp[DLL.MouseY], edx
			jnl _two
			push 0x01
			call GetAsyncKeyState
			cwde
			and eax, 0x008000
			je _two
			push ebx
			mov ebx, 0x86DE30
			mov byte ptr[ebx], 0x00
			mov ebx, 0x86DE2C
			mov byte ptr[ebx], 0x00
			mov ebx, 0x868DD4
			mov byte ptr[ebx], 0x66
			mov ebx, 0x21FED2C
			mov[ebx], 0x01046A
			pop ebx
			_two :
		mov ecx, [inven1]
			add ecx, 0xB6
			cmp[DLL.MouseX], ecx
			jle _three
			mov edx, [inven1]
			add edx, 0xF6
			cmp[DLL.MouseX], edx
			jnl _three
			mov eax, [inven2]
			add eax, 0x0001D1
			cmp[DLL.MouseY], eax
			jle _three
			mov ecx, [inven2]
			add ecx, 0x0001E5
			cmp[DLL.MouseY], ecx
			jnl _three
			push 0x01
			call GetAsyncKeyState
			movsx edx, ax
			and edx, 0x008000
			je _three
			push ebx
			mov ebx, 0x86DE30
			mov byte ptr[ebx], 0x01
			mov ebx, 0x86DE2C
			mov byte ptr[ebx], 0xF8
			mov ebx, 0x868DD4
			mov byte ptr[ebx], 0x79
			mov ebx, 0x21FED2C
			mov[ebx], 0x01046A
			pop ebx
			_three :
		mov eax, 0x708598
			cmp dword ptr[eax], 0x04
			popad
			jmp invenReturn

	}
}

DWORD _inventoryReturn1 = 0X4434F3;
DWORD _inventoryReturn2 = 0X4435D5;


//saved memory
__declspec(naked) void InventorySaveMemory()
{

	__asm {

		push eax
		mov eax, 0x21FED2C
		cmp[eax], 0x01046A
		pop eax
		je _inventory_je
		mov eax, 0x868DD4
		mov eax, [eax]
		jmp _inventoryReturn1
		_inventory_je :
		jmp _inventoryReturn2


	}
}


void InventoryInit()
{
	Hook((void*)(0x4F6D3D), GoldPos, 15);
	Hook((void*)(0x4F6764), InventoryNpcs, 7);
	Hook((void*)(0x4434EE), InventorySaveMemory, 5);
}

