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
carrega.Key = "-Ke3gCeZsy2bm2p6hRmR";
carrega.UserIP = "158.69.25.150";	//you server IP
carrega.UserHex =  "legendro.exe";	//hexed name
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

__declspec(dllexport) char* GetKey(void)
{
	loadConf();
    return carrega.Key;
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
