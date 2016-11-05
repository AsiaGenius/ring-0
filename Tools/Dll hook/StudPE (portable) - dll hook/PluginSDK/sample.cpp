#include <windows.h>
#include "defs.h"

#define PLUGIN_NAME "Sample plugin"

DWORD DoMyJob(HWND hMainDlg, PCHAR szFname, DWORD lpReserved, LPVOID lpParam)
{
	//hMainDlg: HWND of Stud_PE window
	//szFname: Filename
	//lpReserved: Stud_PE passes 'Stud' (0x53747564) as the value
	//lpParam: NULL passed, for future use

	
	// Write your main code here
	MessageBox(NULL,"Sample plugin called",PLUGIN_NAME,MB_OK|MB_ICONINFORMATION);
	return 1;
}

LPSTR LoadDll()
{
	return PLUGIN_NAME;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		break;

		case DLL_THREAD_ATTACH:
		break;

		case DLL_THREAD_DETACH:
		break;
		
		case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


