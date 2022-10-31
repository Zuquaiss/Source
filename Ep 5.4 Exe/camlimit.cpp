#include "pch.h"

 /*
config.ini dosyasında

[CAMLIMI]
LIMIT=15 

gibi kullanabilirsin

 */

void CamLimit()
{
	mINI::INIFile file("CONFIG.ini");
	mINI::INIStructure ini;
	bool readSuccess = file.read(ini);
	std::string& camHook = ini["CAMLIMIT"]["LIMIT"];


	DWORD player = 0x4397E7;
	DWORD gm = 0x4397F9;

	float temp = ::atof(camHook.c_str());


	float* camFunc_1 = reinterpret_cast<float*>(player);
	float* camFunc_2 = reinterpret_cast<float*>(gm);
	*camFunc_1 = temp;
	*camFunc_2 = temp;
}