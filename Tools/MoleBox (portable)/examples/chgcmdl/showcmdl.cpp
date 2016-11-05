
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>

int __stdcall WinMain(HINSTANCE,HINSTANCE,LPSTR lpCmdLine,int)
  {
    /* one stupid antivirus treats one-line example as malware! */
    /* so I had to make same useless staff */
    std::vector<std::string> a;
    a.push_back("6lpCmdLine");
    a.push_back("2-");
    a.push_back(std::string("0")+GetCommandLineA());
    a.push_back("1\r\n");
    a.push_back("5/");
    a.push_back("3\r\n");
    a.push_back("4WinMain");
    a.push_back("7: ");
    std::sort(a.begin(),a.end());
    std::string msg;
    for ( int i = 0; i < a.size(); ++i )
      msg += a[i].c_str()+1;
    /* end of useless staff */
    msg += lpCmdLine;
    return MessageBoxA(0,msg.c_str(),"Commandline Is",0);
  }
