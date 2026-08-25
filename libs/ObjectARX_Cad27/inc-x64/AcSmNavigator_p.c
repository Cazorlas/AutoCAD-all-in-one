

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for idlsource\AcSmNavigator.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


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
#endif /* __RPCPROXY_H_VERSION__ */


#include "AcSmNavigator_i.h"

#define TYPE_FORMAT_STRING_SIZE   71                                
#define PROC_FORMAT_STRING_SIZE   1445                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _AcSmNavigator_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } AcSmNavigator_MIDL_TYPE_FORMAT_STRING;

typedef struct _AcSmNavigator_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } AcSmNavigator_MIDL_PROC_FORMAT_STRING;

typedef struct _AcSmNavigator_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } AcSmNavigator_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax_2_0 = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

#if defined(_CONTROL_FLOW_GUARD_XFG)
#define XFG_TRAMPOLINES(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree(pFlags, (ObjectType *)pObject);\
}
#define XFG_TRAMPOLINES64(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize64_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize64(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree64_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree64(pFlags, (ObjectType *)pObject);\
}
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)\
static void* ObjectType ## _bind_XFG(HandleType pObject)\
{\
return ObjectType ## _bind((ObjectType) pObject);\
}\
static void ObjectType ## _unbind_XFG(HandleType pObject, handle_t ServerHandle)\
{\
ObjectType ## _unbind((ObjectType) pObject, ServerHandle);\
}
#define XFG_TRAMPOLINE_FPTR(Function) Function ## _XFG
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol ## _XFG
#else
#define XFG_TRAMPOLINES(ObjectType)
#define XFG_TRAMPOLINES64(ObjectType)
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)
#define XFG_TRAMPOLINE_FPTR(Function) Function
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol
#endif


extern const AcSmNavigator_MIDL_TYPE_FORMAT_STRING AcSmNavigator__MIDL_TypeFormatString;
extern const AcSmNavigator_MIDL_PROC_FORMAT_STRING AcSmNavigator__MIDL_ProcFormatString;
extern const AcSmNavigator_MIDL_EXPR_FORMAT_STRING AcSmNavigator__MIDL_ExprFormatString;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IAcSmSheetSetProperties_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAcSmSheetSetProperties_ProxyInfo;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IAcSmSheetProperties_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAcSmSheetProperties_ProxyInfo;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IAcSmSubsetProperties_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAcSmSubsetProperties_ProxyInfo;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IAcSmBrowseFileDialog_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAcSmBrowseFileDialog_ProxyInfo;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IAcSmIsASheetSet_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAcSmIsASheetSet_ProxyInfo;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IAcSmIsASheet_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAcSmIsASheet_ProxyInfo;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IAcSmIsASubset_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAcSmIsASubset_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   forced complex structure or array, new range semantics, compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const AcSmNavigator_MIDL_PROC_FORMAT_STRING AcSmNavigator__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_SubsetName */


	/* Procedure get_SheetTitle */


	/* Procedure get_SheetSetName */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 18 */	NdrFcShort( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 26 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 28 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SubsetName */


	/* Procedure put_SheetTitle */


	/* Procedure put_SheetSetName */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x1 ),	/* 1 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */


	/* Parameter newVal */

/* 64 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 66 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 68 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SheetNumber */


	/* Procedure get_SheetSetDataFile */

/* 76 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x9 ),	/* 9 */
/* 84 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 92 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 94 */	NdrFcShort( 0x1 ),	/* 1 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 102 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SheetNumber */


	/* Procedure put_SheetSetDataFile */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 130 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x1 ),	/* 1 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 144 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 148 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SheetDescription */


	/* Procedure get_SheetSetDescription */

/* 152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0xb ),	/* 11 */
/* 160 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 166 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 168 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 170 */	NdrFcShort( 0x1 ),	/* 1 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 178 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 180 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 182 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 186 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SheetDescription */


	/* Procedure put_SheetSetDescription */

/* 190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0xc ),	/* 12 */
/* 198 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 206 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x1 ),	/* 1 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 216 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 218 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 220 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NewSheetLocation */


	/* Procedure get_ResourceFileLocations */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0xd ),	/* 13 */
/* 236 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 242 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 246 */	NdrFcShort( 0x1 ),	/* 1 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 254 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 256 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 258 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 262 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NewSheetLocation */


	/* Procedure put_ResourceFileLocations */

/* 266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0xe ),	/* 14 */
/* 274 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 280 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 282 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x1 ),	/* 1 */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 292 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 296 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 300 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SheetTemplate */


	/* Procedure get_ExpectedLocation */


	/* Procedure get_DefaultLabelBlocks */

/* 304 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0xf ),	/* 15 */
/* 312 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x8 ),	/* 8 */
/* 318 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 320 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 322 */	NdrFcShort( 0x1 ),	/* 1 */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 330 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SheetTemplate */


	/* Procedure put_ExpectedLocation */


	/* Procedure put_DefaultLabelBlocks */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x10 ),	/* 16 */
/* 350 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 358 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x1 ),	/* 1 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */


	/* Parameter newVal */

/* 368 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 370 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 372 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 376 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FoundLocation */


	/* Procedure get_CalloutBlocks */

/* 380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x11 ),	/* 17 */
/* 388 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x8 ),	/* 8 */
/* 394 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 396 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 398 */	NdrFcShort( 0x1 ),	/* 1 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 406 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 408 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 410 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 414 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FoundLocation */


	/* Procedure put_CalloutBlocks */

/* 418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x12 ),	/* 18 */
/* 426 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 432 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 434 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x1 ),	/* 1 */
/* 440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 444 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 448 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 452 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SheetSetName */


	/* Procedure get_SheetStorageLocation */

/* 456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x13 ),	/* 19 */
/* 464 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 470 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 472 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 474 */	NdrFcShort( 0x1 ),	/* 1 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 482 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 486 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 490 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SheetSetName */


	/* Procedure put_SheetStorageLocation */

/* 494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x14 ),	/* 20 */
/* 502 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 508 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 510 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcShort( 0x1 ),	/* 1 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 520 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 524 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 528 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RevisionNumber */


	/* Procedure get_DefaultSheetTemplate */

/* 532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x15 ),	/* 21 */
/* 540 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 546 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 548 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 550 */	NdrFcShort( 0x1 ),	/* 1 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 558 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 562 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 566 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RevisionNumber */


	/* Procedure put_DefaultSheetTemplate */

/* 570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x16 ),	/* 22 */
/* 578 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x8 ),	/* 8 */
/* 584 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 586 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x1 ),	/* 1 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 596 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 600 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 604 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_PromptForTemplate */

/* 608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x17 ),	/* 23 */
/* 616 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x22 ),	/* 34 */
/* 622 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 624 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 634 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 638 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 642 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_PromptForTemplate */

/* 646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x18 ),	/* 24 */
/* 654 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 656 */	NdrFcShort( 0x6 ),	/* 6 */
/* 658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 660 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 662 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 672 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 676 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 680 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IssuePurpose */


	/* Procedure get_AlternativePageSetup */

/* 684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x19 ),	/* 25 */
/* 692 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x8 ),	/* 8 */
/* 698 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 700 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 702 */	NdrFcShort( 0x1 ),	/* 1 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 710 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 712 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 714 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 718 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IssuePurpose */


	/* Procedure put_AlternativePageSetup */

/* 722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x1a ),	/* 26 */
/* 730 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 736 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 738 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x1 ),	/* 1 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 748 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 750 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 752 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 756 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Category */


	/* Procedure get_ProjectNumber */

/* 760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x1b ),	/* 27 */
/* 768 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 774 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 776 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 778 */	NdrFcShort( 0x1 ),	/* 1 */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 786 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */


	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Category */


	/* Procedure put_ProjectNumber */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x1c ),	/* 28 */
/* 806 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 814 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x1 ),	/* 1 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 824 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 826 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 828 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */


	/* Return value */

/* 830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 832 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ProjectName */

/* 836 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x1d ),	/* 29 */
/* 844 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 850 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 852 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 862 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 866 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */

/* 868 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 870 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ProjectName */

/* 874 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 880 */	NdrFcShort( 0x1e ),	/* 30 */
/* 882 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 888 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 890 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x1 ),	/* 1 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 900 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 904 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ProjectPhase */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x1f ),	/* 31 */
/* 920 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 928 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 930 */	NdrFcShort( 0x1 ),	/* 1 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 938 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 940 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 942 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */

/* 944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 946 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ProjectPhase */

/* 950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x20 ),	/* 32 */
/* 958 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 964 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 966 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x1 ),	/* 1 */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 976 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 978 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 980 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */

/* 982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 984 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ProjectMilestone */

/* 988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x21 ),	/* 33 */
/* 996 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1002 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1004 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1006 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1014 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1018 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ProjectMilestone */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1034 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1042 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1052 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1054 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1056 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */

/* 1058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1060 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IncludeForPublish */

/* 1064 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1070 */	NdrFcShort( 0xd ),	/* 13 */
/* 1072 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1078 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1080 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1090 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1092 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1094 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1096 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1098 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IncludeForPublish */

/* 1102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1108 */	NdrFcShort( 0xe ),	/* 14 */
/* 1110 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1112 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1116 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1118 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1128 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1136 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RevisionDate */

/* 1140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1148 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1156 */	0xa,		/* 10 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 1158 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1166 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1170 */	NdrFcShort( 0x2a ),	/* Type Offset=42 */

	/* Return value */

/* 1172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1174 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RevisionDate */

/* 1178 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1184 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1186 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1192 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1194 */	0xa,		/* 10 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1204 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1208 */	NdrFcShort( 0x38 ),	/* Type Offset=56 */

	/* Return value */

/* 1210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1212 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CreateRelativeFolders */

/* 1216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1222 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1224 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1230 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1232 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1240 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1242 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1244 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1246 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1250 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CreateRelativeFolders */

/* 1254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0xa ),	/* 10 */
/* 1262 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1264 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1268 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1270 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1280 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1284 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1286 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1288 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OverrideSheetPublishValues */

/* 1292 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1294 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1298 */	NdrFcShort( 0xb ),	/* 11 */
/* 1300 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1306 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1308 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1318 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1322 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1326 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OverrideSheetPublishValues */

/* 1330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1336 */	NdrFcShort( 0xc ),	/* 12 */
/* 1338 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1340 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1344 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1346 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1358 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1360 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1364 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_PromptForTemplate */

/* 1368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1376 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1380 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1382 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1384 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1394 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1396 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1398 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1400 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1402 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_PromptForTemplate */

/* 1406 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1408 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1414 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1416 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1418 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1420 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1422 */	0xa,		/* 10 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1436 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1440 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const AcSmNavigator_MIDL_TYPE_FORMAT_STRING AcSmNavigator__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x26 ),	/* Offset= 38 (42) */
/*  6 */	
			0x13, 0x0,	/* FC_OP */
/*  8 */	NdrFcShort( 0x18 ),	/* Offset= 24 (32) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 20 */	0x0 , 
			0x0,		/* 0 */
/* 22 */	NdrFcLong( 0x0 ),	/* 0 */
/* 26 */	NdrFcLong( 0x0 ),	/* 0 */
/* 30 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 32 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (10) */
/* 38 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 40 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 42 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 44 */	NdrFcShort( 0x0 ),	/* 0 */
/* 46 */	NdrFcShort( 0x8 ),	/* 8 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (6) */
/* 52 */	
			0x12, 0x0,	/* FC_UP */
/* 54 */	NdrFcShort( 0xffea ),	/* Offset= -22 (32) */
/* 56 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x8 ),	/* 8 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (52) */
/* 66 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 68 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

XFG_TRAMPOLINES(BSTR)

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            (USER_MARSHAL_SIZING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserSize)
            ,(USER_MARSHAL_MARSHALLING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserMarshal)
            ,(USER_MARSHAL_UNMARSHALLING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserUnmarshal)
            ,(USER_MARSHAL_FREEING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserFree)
            
            }
            

        };



/* Standard interface: __MIDL_itf_AcSmNavigator_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAcSmSheetSetProperties, ver. 0.0,
   GUID={0x02C32A9E,0xCFCC,0x4EF8,{0xB0,0x15,0xB3,0x3F,0xD0,0x10,0xC8,0xB4}} */

#pragma code_seg(".orpc")
static const unsigned short IAcSmSheetSetProperties_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38,
    76,
    114,
    152,
    190,
    228,
    266,
    304,
    342,
    380,
    418,
    456,
    494,
    532,
    570,
    608,
    646,
    684,
    722,
    760,
    798,
    836,
    874,
    912,
    950,
    988,
    1026
    };

static const MIDL_STUBLESS_PROXY_INFO IAcSmSheetSetProperties_ProxyInfo =
    {
    &Object_StubDesc,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmSheetSetProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAcSmSheetSetProperties_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmSheetSetProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(35) _IAcSmSheetSetPropertiesProxyVtbl = 
{
    &IAcSmSheetSetProperties_ProxyInfo,
    &IID_IAcSmSheetSetProperties,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_SheetSetName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_SheetSetName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_SheetSetDataFile */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_SheetSetDataFile */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_SheetSetDescription */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_SheetSetDescription */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_ResourceFileLocations */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_ResourceFileLocations */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_DefaultLabelBlocks */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_DefaultLabelBlocks */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_CalloutBlocks */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_CalloutBlocks */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_SheetStorageLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_SheetStorageLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_DefaultSheetTemplate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_DefaultSheetTemplate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_PromptForTemplate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_PromptForTemplate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_AlternativePageSetup */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_AlternativePageSetup */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_ProjectNumber */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_ProjectNumber */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_ProjectName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_ProjectName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_ProjectPhase */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_ProjectPhase */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::get_ProjectMilestone */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetSetProperties::put_ProjectMilestone */
};


EXTERN_C DECLSPEC_SELECTANY const PRPC_STUB_FUNCTION IAcSmSheetSetProperties_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAcSmSheetSetPropertiesStubVtbl =
{
    &IID_IAcSmSheetSetProperties,
    &IAcSmSheetSetProperties_ServerInfo,
    35,
    &IAcSmSheetSetProperties_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAcSmSheetProperties, ver. 0.0,
   GUID={0x4895E373,0x0408,0x44CF,{0xA0,0x86,0x7F,0x45,0x63,0x5E,0x8B,0xB9}} */

#pragma code_seg(".orpc")
static const unsigned short IAcSmSheetProperties_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38,
    76,
    114,
    152,
    190,
    1064,
    1102,
    304,
    342,
    380,
    418,
    456,
    494,
    532,
    570,
    1140,
    1178,
    684,
    722,
    760,
    798
    };

static const MIDL_STUBLESS_PROXY_INFO IAcSmSheetProperties_ProxyInfo =
    {
    &Object_StubDesc,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmSheetProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAcSmSheetProperties_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmSheetProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(29) _IAcSmSheetPropertiesProxyVtbl = 
{
    &IAcSmSheetProperties_ProxyInfo,
    &IID_IAcSmSheetProperties,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_SheetTitle */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_SheetTitle */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_SheetNumber */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_SheetNumber */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_SheetDescription */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_SheetDescription */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_IncludeForPublish */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_IncludeForPublish */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_ExpectedLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_ExpectedLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_FoundLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_FoundLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_SheetSetName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_SheetSetName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_RevisionNumber */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_RevisionNumber */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_RevisionDate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_RevisionDate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_IssuePurpose */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_IssuePurpose */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::get_Category */ ,
    (void *) (INT_PTR) -1 /* IAcSmSheetProperties::put_Category */
};


EXTERN_C DECLSPEC_SELECTANY const PRPC_STUB_FUNCTION IAcSmSheetProperties_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAcSmSheetPropertiesStubVtbl =
{
    &IID_IAcSmSheetProperties,
    &IAcSmSheetProperties_ServerInfo,
    29,
    &IAcSmSheetProperties_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAcSmSubsetProperties, ver. 0.0,
   GUID={0xA04CE508,0xC167,0x4AAD,{0xA7,0x5C,0x56,0x28,0xD2,0x51,0x62,0xA8}} */

#pragma code_seg(".orpc")
static const unsigned short IAcSmSubsetProperties_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38,
    1216,
    1254,
    1292,
    1330,
    228,
    266,
    304,
    342,
    1368,
    1406
    };

static const MIDL_STUBLESS_PROXY_INFO IAcSmSubsetProperties_ProxyInfo =
    {
    &Object_StubDesc,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmSubsetProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAcSmSubsetProperties_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmSubsetProperties_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IAcSmSubsetPropertiesProxyVtbl = 
{
    &IAcSmSubsetProperties_ProxyInfo,
    &IID_IAcSmSubsetProperties,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::get_SubsetName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::put_SubsetName */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::get_CreateRelativeFolders */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::put_CreateRelativeFolders */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::get_OverrideSheetPublishValues */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::put_OverrideSheetPublishValues */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::get_NewSheetLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::put_NewSheetLocation */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::get_SheetTemplate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::put_SheetTemplate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::get_PromptForTemplate */ ,
    (void *) (INT_PTR) -1 /* IAcSmSubsetProperties::put_PromptForTemplate */
};


EXTERN_C DECLSPEC_SELECTANY const PRPC_STUB_FUNCTION IAcSmSubsetProperties_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAcSmSubsetPropertiesStubVtbl =
{
    &IID_IAcSmSubsetProperties,
    &IAcSmSubsetProperties_ServerInfo,
    19,
    &IAcSmSubsetProperties_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAcSmBrowseFileDialog, ver. 0.0,
   GUID={0x1267B246,0x65F3,0x4FFC,{0x87,0x1C,0x04,0xF1,0xEC,0x10,0x6E,0x11}} */

#pragma code_seg(".orpc")
static const unsigned short IAcSmBrowseFileDialog_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IAcSmBrowseFileDialog_ProxyInfo =
    {
    &Object_StubDesc,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmBrowseFileDialog_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAcSmBrowseFileDialog_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmBrowseFileDialog_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IAcSmBrowseFileDialogProxyVtbl = 
{
    0,
    &IID_IAcSmBrowseFileDialog,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


EXTERN_C DECLSPEC_SELECTANY const PRPC_STUB_FUNCTION IAcSmBrowseFileDialog_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IAcSmBrowseFileDialogStubVtbl =
{
    &IID_IAcSmBrowseFileDialog,
    &IAcSmBrowseFileDialog_ServerInfo,
    7,
    &IAcSmBrowseFileDialog_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAcSmIsASheetSet, ver. 0.0,
   GUID={0x41C49911,0xEE8E,0x435D,{0xAB,0xC0,0x3F,0x95,0x7A,0xEA,0x1C,0x54}} */

#pragma code_seg(".orpc")
static const unsigned short IAcSmIsASheetSet_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IAcSmIsASheetSet_ProxyInfo =
    {
    &Object_StubDesc,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmIsASheetSet_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAcSmIsASheetSet_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmIsASheetSet_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IAcSmIsASheetSetProxyVtbl = 
{
    0,
    &IID_IAcSmIsASheetSet,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IAcSmIsASheetSetStubVtbl =
{
    &IID_IAcSmIsASheetSet,
    &IAcSmIsASheetSet_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IAcSmIsASheet, ver. 0.0,
   GUID={0x18431D76,0x8851,0x4050,{0x9C,0x01,0x49,0x0D,0x05,0x31,0x1E,0x8A}} */

#pragma code_seg(".orpc")
static const unsigned short IAcSmIsASheet_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IAcSmIsASheet_ProxyInfo =
    {
    &Object_StubDesc,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmIsASheet_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAcSmIsASheet_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmIsASheet_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IAcSmIsASheetProxyVtbl = 
{
    0,
    &IID_IAcSmIsASheet,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IAcSmIsASheetStubVtbl =
{
    &IID_IAcSmIsASheet,
    &IAcSmIsASheet_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IAcSmIsASubset, ver. 0.0,
   GUID={0xBA7381A6,0xCF0B,0x454F,{0xAC,0xC1,0x3A,0xFB,0x6B,0x9C,0xB6,0xAE}} */

#pragma code_seg(".orpc")
static const unsigned short IAcSmIsASubset_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IAcSmIsASubset_ProxyInfo =
    {
    &Object_StubDesc,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmIsASubset_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAcSmIsASubset_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AcSmNavigator__MIDL_ProcFormatString.Format,
    &IAcSmIsASubset_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _IAcSmIsASubsetProxyVtbl = 
{
    0,
    &IID_IAcSmIsASubset,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _IAcSmIsASubsetStubVtbl =
{
    &IID_IAcSmIsASubset,
    &IAcSmIsASubset_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

#ifdef __cplusplus
namespace {
#endif
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
    AcSmNavigator__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x8010274, /* MIDL Version 8.1.628 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#ifdef __cplusplus
}
#endif

const CInterfaceProxyVtbl * const _AcSmNavigator_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IAcSmSubsetPropertiesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAcSmIsASheetSetProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAcSmBrowseFileDialogProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAcSmSheetPropertiesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAcSmIsASheetProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAcSmSheetSetPropertiesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAcSmIsASubsetProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _AcSmNavigator_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IAcSmSubsetPropertiesStubVtbl,
    ( CInterfaceStubVtbl *) &_IAcSmIsASheetSetStubVtbl,
    ( CInterfaceStubVtbl *) &_IAcSmBrowseFileDialogStubVtbl,
    ( CInterfaceStubVtbl *) &_IAcSmSheetPropertiesStubVtbl,
    ( CInterfaceStubVtbl *) &_IAcSmIsASheetStubVtbl,
    ( CInterfaceStubVtbl *) &_IAcSmSheetSetPropertiesStubVtbl,
    ( CInterfaceStubVtbl *) &_IAcSmIsASubsetStubVtbl,
    0
};

PCInterfaceName const _AcSmNavigator_InterfaceNamesList[] = 
{
    "IAcSmSubsetProperties",
    "IAcSmIsASheetSet",
    "IAcSmBrowseFileDialog",
    "IAcSmSheetProperties",
    "IAcSmIsASheet",
    "IAcSmSheetSetProperties",
    "IAcSmIsASubset",
    0
};

const IID *  const _AcSmNavigator_BaseIIDList[] = 
{
    &IID_IDispatch,
    0,
    &IID_IDispatch,
    &IID_IDispatch,
    0,
    &IID_IDispatch,
    0,
    0
};


#define _AcSmNavigator_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _AcSmNavigator, pIID, n)

int __stdcall _AcSmNavigator_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _AcSmNavigator, 7, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _AcSmNavigator, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _AcSmNavigator, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _AcSmNavigator, 7, *pIndex )
    
}

EXTERN_C const ExtendedProxyFileInfo AcSmNavigator_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _AcSmNavigator_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _AcSmNavigator_StubVtblList,
    (const PCInterfaceName * ) & _AcSmNavigator_InterfaceNamesList,
    (const IID ** ) & _AcSmNavigator_BaseIIDList,
    & _AcSmNavigator_IID_Lookup, 
    7,
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


#endif /* defined(_M_AMD64)*/

