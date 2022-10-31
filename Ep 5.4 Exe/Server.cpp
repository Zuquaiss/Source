#include "pch.h"

const char* NameServer = AY_OBFUSCATE("Shaiya");
const char* Address = AY_OBFUSCATE("127.0.0.1");
unsigned char ServerVersion[] = { 0x68, 0x88, 0x22, 0x33, 0x88 }; // 88332288
unsigned char LoginPort[] = { 0x68, 0x50, 0x78, 0x00, 0x00 }; // 30800
unsigned char GamePort[] = { 0x68, 0x5A, 0x78, 0x00, 0x00 }; // 30810

char ServerName[7];
char IPAddress[13];

void ShaiyaServer() {
	strcpy_s(ServerName, NameServer);
	strcpy_s(IPAddress, Address);
	writeBytes((void*)0x6BBCE0, ServerName, sizeof(ServerName));
	writeBytes((void*)0x6BBC14, IPAddress, sizeof(IPAddress));
	writeBytes((void*)0x4EB135, ServerVersion, sizeof(ServerVersion));
	writeBytes((void*)0x40B46B, LoginPort, sizeof(LoginPort));
	writeBytes((void*)0x47DB9E, LoginPort, sizeof(LoginPort));
	writeBytes((void*)0x4BDED7, LoginPort, sizeof(LoginPort));
	writeBytes((void*)0x42F1AE, GamePort, sizeof(GamePort));
	writeBytes((void*)0x46C9C4, GamePort, sizeof(GamePort));
	writeBytes((void*)0x4EB296, GamePort, sizeof(GamePort));

}