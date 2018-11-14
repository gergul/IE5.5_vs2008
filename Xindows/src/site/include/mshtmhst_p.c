

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "mshtmhst.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _mshtmhst_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } mshtmhst_MIDL_TYPE_FORMAT_STRING;

typedef struct _mshtmhst_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } mshtmhst_MIDL_PROC_FORMAT_STRING;

typedef struct _mshtmhst_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } mshtmhst_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const mshtmhst_MIDL_TYPE_FORMAT_STRING mshtmhst__MIDL_TypeFormatString;
extern const mshtmhst_MIDL_PROC_FORMAT_STRING mshtmhst__MIDL_ProcFormatString;
extern const mshtmhst_MIDL_EXPR_FORMAT_STRING mshtmhst__MIDL_ExprFormatString;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const mshtmhst_MIDL_PROC_FORMAT_STRING mshtmhst__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const mshtmhst_MIDL_TYPE_FORMAT_STRING mshtmhst__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_mshtmhst_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ITridentAPI, ver. 0.0,
   GUID={0x53DEC138,0xA51E,0x11d2,{0x86,0x1E,0x00,0xC0,0x4F,0xA3,0x5C,0x89}} */


/* Standard interface: __MIDL_itf_mshtmhst_0000_0001, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IDocHostUIHandler, ver. 0.0,
   GUID={0xbd3f23c0,0xd43e,0x11cf,{0x89,0x3b,0x00,0xaa,0x00,0xbd,0xce,0x1a}} */


/* Standard interface: __MIDL_itf_mshtmhst_0000_0002, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: ICustomDoc, ver. 0.0,
   GUID={0x3050f3f0,0x98b5,0x11cf,{0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b}} */


/* Object interface: IDocHostShowUI, ver. 0.0,
   GUID={0xc4d244b0,0xd43e,0x11cf,{0x89,0x3b,0x00,0xaa,0x00,0xbd,0xce,0x1a}} */


/* Standard interface: __MIDL_itf_mshtmhst_0000_0004, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IClassFactory, ver. 0.0,
   GUID={0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IClassFactoryEx, ver. 0.0,
   GUID={0x342D1EA0,0xAE25,0x11D1,{0x89,0xC5,0x00,0x60,0x08,0xC3,0xFB,0xFC}} */


/* Standard interface: __MIDL_itf_mshtmhst_0000_0005, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    mshtmhst__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _mshtmhst_ProxyVtblList[] = 
{
    0
};

const CInterfaceStubVtbl * _mshtmhst_StubVtblList[] = 
{
    0
};

PCInterfaceName const _mshtmhst_InterfaceNamesList[] = 
{
    0
};


#define _mshtmhst_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _mshtmhst, pIID, n)

int __stdcall _mshtmhst_IID_Lookup( const IID * pIID, int * pIndex )
{
    return 0;
}

const ExtendedProxyFileInfo mshtmhst_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _mshtmhst_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _mshtmhst_StubVtblList,
    (const PCInterfaceName * ) & _mshtmhst_InterfaceNamesList,
    0, // no delegation
    & _mshtmhst_IID_Lookup, 
    0,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

