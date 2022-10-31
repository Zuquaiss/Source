#include "pch.h"

//-- Hound --//
int HoundWC = 0;
int HoundHP = 0;
int HoundMA = 0;
int HoundCL = 0;
int HoundXR = 0;
int HoundAS = 0;
int HoundSC = 0;
int HoundFS = 0;
int HoundBH = 0;
int HoundSZ = 0;
int HoundOB = 0;
int HoundRA = 0;
//-- Bypass --//
int BypassSC = 0;
int BypassCD = 0;
int BypassJMP = 0;
int BypassBH = 0;
int BypassOB = 0;
int BypassR1 = 0;
int BypassR2 = 0;
//-- Delite --//
int DeliteSC = 0;
int DeliteXR = 0;
int DeliteCD = 0;
int DeliteZL = 0;
int DeliteFS = 0;
int DeliteJMP = 0;
int DeliteWC = 0;



void Error() {
	exit(0);
	MessageBoxA(NULL, DLL.Error, DLL.Title, MB_SERVICE_NOTIFICATION | MB_ICONERROR);
}

__declspec(dllexport) void AntiCheatOffset()
{
	//-- Bypass --//
	BypassSC = (int)*reinterpret_cast<bool*>(0x043DADC);
	BypassCD = (int)*reinterpret_cast<bool*>(0x04DF043);
	BypassJMP = (int)*reinterpret_cast<bool*>(0x0560EFC);
	BypassBH = (int)*reinterpret_cast<bool*>(0x058FD80);
	BypassOB = (int)*reinterpret_cast<bool*>(0x04382BA);
	BypassR1 = (int)*reinterpret_cast<bool*>(0x043FCE6);
	BypassR2 = (int)*reinterpret_cast<bool*>(0x21FE5F2);
	if (BypassSC != 57) { Error(); }
	if (BypassCD != 139) { Error(); }
	if (BypassJMP != 59) { Error(); }
	if (BypassBH != 131) { Error(); }
	if (BypassOB != 232) { Error(); }
	//if (BypassR1 != 116) { Error(); }
	//if (BypassR2 >= 6) { Error(); }

	//-- Delite --//
	DeliteSC = (int)*reinterpret_cast<bool*>(0x043DAE8);
	DeliteXR = (int)*reinterpret_cast<bool*>(0x04CC279);
	DeliteCD = (int)*reinterpret_cast<bool*>(0x04DF048);
	DeliteZL = (int)*reinterpret_cast<bool*>(0x04397DB);
	DeliteFS = (int)*reinterpret_cast<bool*>(0x0561CEE);
	DeliteJMP = (int)*reinterpret_cast<bool*>(0x0560F02);
	DeliteWC = (int)*reinterpret_cast<bool*>(0x442990);
	if (DeliteSC != 139) { Error(); }
	if (DeliteXR != 199) { Error(); }
	if (DeliteCD != 116) { Error(); }
	if (DeliteZL != 133) { Error(); }
	if (DeliteFS != 116) { Error(); }
	if (DeliteJMP != 15) { Error(); }
	if (DeliteWC != 15) { Error(); }

	//-- Hound --//
	HoundWC = (int)*reinterpret_cast<bool*>(0x442996);
	HoundHP = (int)*reinterpret_cast<bool*>(0x50C0BF);
	HoundMA = (int)*reinterpret_cast<bool*>(0x441DEE);
	HoundCL = (int)*reinterpret_cast<bool*>(0x4397DB);
	HoundXR = (int)*reinterpret_cast<bool*>(0x4CC274);
	HoundAS = (int)*reinterpret_cast<bool*>(0x598B8A);
	HoundSC = (int)*reinterpret_cast<bool*>(0x413EA7);
	HoundFS = (int)*reinterpret_cast<bool*>(0x561CCB);
	HoundBH = (int)*reinterpret_cast<bool*>(0x58FD88);
	HoundSZ = (int)*reinterpret_cast<bool*>(0x4402EB);
	HoundOB = (int)*reinterpret_cast<bool*>(0x4382BF);
	HoundRA = (int)*reinterpret_cast<bool*>(0x4407C3);
	if (HoundWC != 217) { Error(); }
	if (HoundHP != 133) { Error(); }
	if (HoundMA != 131) { Error(); }
	if (HoundCL != 133) { Error(); }
	if (HoundXR != 128) { Error(); }
	if (HoundAS != 255) { Error(); }
	if (HoundSC != 15) { Error(); }
	if (HoundFS != 138) { Error(); }
	if (HoundBH != 106) { Error(); }
	if (HoundSZ != 133) { Error(); }
	if (HoundOB != 132) { Error(); }
	//if (HoundRA != 116) { Error(); }
}


void CheckOffset() {
	while (true)
	{
		AntiCheatOffset();
		Sleep(5000);
	}
}

void AntiCheat() {
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(CheckOffset), NULL, 0, 0);
}

