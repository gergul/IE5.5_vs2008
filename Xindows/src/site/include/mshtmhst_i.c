

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sat Apr 18 14:10:42 2009
 */
/* Compiler settings for mshtmhst.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ITridentAPI,0x53DEC138,0xA51E,0x11d2,0x86,0x1E,0x00,0xC0,0x4F,0xA3,0x5C,0x89);


MIDL_DEFINE_GUID(CLSID, CLSID_TridentAPI,0x429AF92C,0xA51F,0x11d2,0x86,0x1E,0x00,0xC0,0x4F,0xA3,0x5C,0x89);


MIDL_DEFINE_GUID(IID, IID_IDocHostUIHandler,0xbd3f23c0,0xd43e,0x11cf,0x89,0x3b,0x00,0xaa,0x00,0xbd,0xce,0x1a);


MIDL_DEFINE_GUID(IID, IID_ICustomDoc,0x3050f3f0,0x98b5,0x11cf,0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b);


MIDL_DEFINE_GUID(IID, IID_IDocHostShowUI,0xc4d244b0,0xd43e,0x11cf,0x89,0x3b,0x00,0xaa,0x00,0xbd,0xce,0x1a);


MIDL_DEFINE_GUID(IID, IID_IClassFactoryEx,0x342D1EA0,0xAE25,0x11D1,0x89,0xC5,0x00,0x60,0x08,0xC3,0xFB,0xFC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



