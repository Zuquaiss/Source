#include "pch.h"
Shaiya DLL;
extern  "C"  __declspec(dllexport) void __cdecl Main()
{
    DLL.Title = AY_OBFUSCATE("Shaiya AC");
    DLL.Error = AY_OBFUSCATE("Security validation failed.");
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        // DLL INJECTION 
        Main();

        // FEATURES PART
        StatPoints();
        SkillBarFunc(); 
        effFunc(); 
        Settings(); 
        FpsSettings();
        ShaiyaServer(); 
        Init();
        MiniIcon();
        Discord();
        TitleInit();
        CamLimit();
        InventoryInit();
        GameColor();
        Protect();
        BuffInit();

        // ANTI CHEAT PART
        MemoryScan(); 
        CloseGame();
        ClassScan();
        AntiCheat();
        YProtectionMain();

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
