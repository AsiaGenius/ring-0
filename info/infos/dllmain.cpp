//////////////////////////////////////////////////////////////////////////
///////			 WELCOME TO RING-0 CONFIG CPP!		//////////////////////
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"



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

//////////////////////////////////////////////////////////////////////////
// Files CRC Check //////////////////	RING-0		//////////////////////
//////////////////////////////////////////////////////////////////////////

//List here all protected files, eg.: #define ProtectA "my_CRC:filename"
//Max number of protect file is 10
//All file type allowed

carrega.NumberOfPrt = 1;		//Number  of protected files Default: 3 (only 3 file protected in this case)	//DISABLED TEMPORARY

carrega.ProtectA = "0x5339965e:data.grf";	//DISABLED TEMPORARY
carrega.ProtectB =  "0x5339965e:my_ro.exe";	//DISABLED TEMPORARY
carrega.ProtectC = "0x5339965e:my_ro.grf";	//DISABLED TEMPORARY
carrega.ProtectD = "0x5339965e:DATA.INI";	//DISABLED TEMPORARY
carrega.ProtectE = "0x5339965e:files.grf";	//DISABLED TEMPORARY
carrega.ProtectF = "0x5339965e:palleta.grf";	//DISABLED TEMPORARY
carrega.ProtectG = "0x5339965e:jobs.grf";	//DISABLED TEMPORARY
carrega.ProtectH = "0x5339965e:cps.dll";	//DISABLED TEMPORARY
carrega.ProtectI = "0x5339965e:GameGuard/ring.dll";		//    <<<---  IMPORTANT!!!!! IMPORTANT!!!!!!!!! ATTENTION!!!  GameGuard/ring.dll
carrega.ProtectJ = "0x5339965e:BGM/1.mp3";	//DISABLED TEMPORARY

//Attention! Max 10 protected file allowed, if you dont need protect 10 files, set NumberOfPrt to you number of protected file


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
__declspec(dllexport) char* hexed(void)
{	
	loadConf();
	return carrega.UserHex;
}

__declspec(dllexport) int client()
{	loadConf();
    return 2;
}
__declspec(dllexport) int getinst()
{	loadConf();
	return carrega.MaxAllowedInstances;
}
__declspec(dllexport) char* CRCGRF(int type)
{
	loadConf();
	if (type == 1){
	return carrega.ProtectA;
	} else if (type == 2){
	return carrega.ProtectB;
	} else if (type == 3){
	return carrega.ProtectC;
	} else if (type == 4){
	return carrega.ProtectD;
	} else if (type == 5){
	return carrega.ProtectE;
	} else if (type == 6){
	return carrega.ProtectF;
	} else if (type == 7){
	return carrega.ProtectG;
	} else if (type == 8){
	return carrega.ProtectH;
	} else if (type == 9){
	return carrega.ProtectI;
	} else if (type == 10){
	return carrega.ProtectJ;
	}    
}


#ifdef __cplusplus
}
#endif 
