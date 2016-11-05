

/**

  Copyright (C) 2010-2011, Alexéy Sudáchen, Teggo Software Ltd.
  http://www.molebox.com/

MOLEBOX VIRTUALIZATION CORE API

*/

#if !defined _MOLEBOX_API_H_
#define _MOLEBOX_API_H_

#if defined __cplusplus
#define PWCHART_CONST wchar_t const *
#define _MOLEBOX_API_INLINE inline
#else
#define PWCHART_CONST wchar_t *
#define _MOLEBOX_API_INLINE static
#endif

/*
  Molebox Core Public API. 
  passing to activator Activate@4 function
  also available via GetEnvironmentVariable("molebox;api",&MOLEBOX_API_ptr,sizeof(MOLEBOX_API_ptr))
*/
struct MOLEBOX_API
  {
    /* molebox core build number */
    int buildno;
    
    /* base address of activator */
    void *activator_base_address;
    
    /* COMMANDLINE */
    void (__stdcall *CmdLine_Set)(PWCHART_CONST cmdl);
    void (__stdcall *CmdLine_Parse)(/*out*/ int *argc, /*out*/ wchar_t ***argv);
    
    /* do not release memory allocated by Parse_ComandLine! */
    
    /** 
      RSA ENCRYPTION 
      a,e,n,r - unsigned[] with space enough to store bitcount bits;
      a - aka text
      e - RSA key
      n - RSA module
      r - result
    */
    void (__stdcall *Expmod)(void *a, void *e, void *n, /*out*/ void *R, int bitcount);
    
    /**
      MD5 DIGEST
      digest should be equal char[16]
    */
    void (__stdcall *Digest)(void *data, unsigned len, /*out*/ void *digest);
    
    /* IDENTIFICATION */
    unsigned (__stdcall *PcId)();

    void (__stdcall *CmdLine_SetArgs)(PWCHART_CONST *args, int count);
    void (__stdcall *CmdLine_InsertArgs)(int after, PWCHART_CONST *args, int count);

    void *reserved_0;
    void *reserved_1;
    void *reserved_2;
    
  };

typedef struct MOLEBOX_API MOLEBOX_API;

#if defined _MOLEBOX_API_SUGAR || defined __cplusplus

_MOLEBOX_API_INLINE unsigned Molebox_BuildNo()
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      return p->buildno;
    return 0;
  }

_MOLEBOX_API_INLINE void Molebox_CmdLine_Set(PWCHART_CONST cmdl)
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      p->CmdLine_Set(cmdl);
  }

_MOLEBOX_API_INLINE void Molebox_CmdLine_Parse(int *argc, wchar_t ***argv)
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      p->CmdLine_Parse(argc,argv);
  }

_MOLEBOX_API_INLINE void Molebox_CmdLine_SetArgs(PWCHART_CONST *args, int count)
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      p->CmdLine_SetArgs(args,count);
  }

_MOLEBOX_API_INLINE void Molebox_CmdLine_InsertArgs(int after, PWCHART_CONST *args, int count)
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      p->CmdLine_InsertArgs(after,args,count);
  }

_MOLEBOX_API_INLINE void Molebox_Expmod(void *a, void *e, void *n, void *R, int bitcount)
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      p->Expmod(a,e,n,R,bitcount);
  }

_MOLEBOX_API_INLINE void Molebox_Digest(void *data, int len, void *digest)
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      p->Digest(data,len,digest);
  }

_MOLEBOX_API_INLINE unsigned Molebox_PcId()
  {
    MOLEBOX_API *p = 0;
    if ( sizeof(p) == GetEnvironmentVariableW(L"molebox;api",(LPWSTR)&p,sizeof(p)) )
      return p->PcId();
    return 0;
  }

#endif // _MOLEBOX_API_SUGAR

#endif // _MOLEBOX_API_H_
