//////////////////////////////////////////////////////////////////////////
///////			 WELCOME TO RING-0 CONFIG CPP!		//////////////////////
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "infos.h"


#ifdef __cplusplus
extern "C" {
#endif
//


void loadConf() 
{

//////////////////////////////////////////////////////////////////////////
// Connection and Client Config	///////	RING-0		//////////////////////
//////////////////////////////////////////////////////////////////////////

carrega.UserIP = "127.0.0.1";	//you server IP
carrega.UserHex =  "my_ro.exe";	//hexed name
carrega.MaxAllowedInstances =  2;	//Number of max game client, MAX: 99 (Recomended: 2)



}



//////////////////////////////////////////////////////////////////////////
//							END OF CONFIG!								//
//						No edit this functions							//
//////////////////////////////////////////////////////////////////////////


__declspec(dllexport) char* GetText(void)
{
	loadConf();
    return carrega.UserIP;
}


__declspec(dllexport) int getinst()
{	loadConf();
	return carrega.MaxAllowedInstances;
}

__declspec(dllexport) int getprt()
{	loadConf();
	return carrega.NumberOfPrt;
}



#ifdef __cplusplus
}
#endif 
