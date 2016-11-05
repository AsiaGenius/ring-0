
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../moleapi.h"

int __stdcall DllMain(void *, unsigned reason, void *)
  {
    return 1;
  }

extern "C" __declspec(dllexport) int __stdcall Activate(MOLEBOX_API *api)
  {
    wchar_t const *args[] = { L"hello world!" };
    api->CmdLine_InsertArgs(0,args,sizeof(args)/sizeof(args[0]));
    return 1;
  }
