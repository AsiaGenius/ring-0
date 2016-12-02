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
carrega.UserHex =  "my-RO.exe";	//hexed name
carrega.MaxAllowedInstances =  2;	//Number of max game client, MAX: 99 (Recomended: 2)

//////////////////////////////////////////////////////////////////////////
// Files CRC Check //////////////////	RING-0		//////////////////////
//////////////////////////////////////////////////////////////////////////

//List here all protected files, eg.: #define ProtectA "my_CRC:filename"
//Max number of protect file is 5
//All file type allowed

carrega.NumberOfPrt = 4;		//Number  of protected files 

carrega.ProtectA = "de140b0ff23168b45e8867b058bac31c";	//CRIPTO COD
carrega.ProtectB = "clientinfo.grf";	//FILE NAME

carrega.ProtectC = "48c5c6bf2f6ab3d0054738dc30179193";	//CRIPTO COD
carrega.ProtectD = "new.grf";	//FILE NAME

carrega.ProtectE = "e3aa7d74d98b55382b2da31bdb19eae1";	//CRIPTO COD
carrega.ProtectF = "palette.grf";	//FILE NAME

carrega.ProtectG = "666db5146a5ae14f7c21293e17da573f";	//CRIPTO COD
carrega.ProtectH = "my-RO.exe";	//FILE NAME



//Attention! Max 5 protected file allowed, if you dont need protect > 5 files, set NumberOfPrt to you number of protected file


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

__declspec(dllexport) int getprt()
{	loadConf();
	return carrega.NumberOfPrt;
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
