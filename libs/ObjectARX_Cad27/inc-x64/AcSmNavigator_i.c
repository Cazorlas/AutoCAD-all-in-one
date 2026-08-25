//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IAcSmSheetSetProperties,0x02C32A9E,0xCFCC,0x4EF8,0xB0,0x15,0xB3,0x3F,0xD0,0x10,0xC8,0xB4);


MIDL_DEFINE_GUID(IID, IID_IAcSmSheetProperties,0x4895E373,0x0408,0x44CF,0xA0,0x86,0x7F,0x45,0x63,0x5E,0x8B,0xB9);


MIDL_DEFINE_GUID(IID, IID_IAcSmSubsetProperties,0xA04CE508,0xC167,0x4AAD,0xA7,0x5C,0x56,0x28,0xD2,0x51,0x62,0xA8);


MIDL_DEFINE_GUID(IID, IID_IAcSmBrowseFileDialog,0x1267B246,0x65F3,0x4FFC,0x87,0x1C,0x04,0xF1,0xEC,0x10,0x6E,0x11);


MIDL_DEFINE_GUID(IID, IID_IAcSmIsASheetSet,0x41C49911,0xEE8E,0x435D,0xAB,0xC0,0x3F,0x95,0x7A,0xEA,0x1C,0x54);


MIDL_DEFINE_GUID(IID, IID_IAcSmIsASheet,0x18431D76,0x8851,0x4050,0x9C,0x01,0x49,0x0D,0x05,0x31,0x1E,0x8A);


MIDL_DEFINE_GUID(IID, IID_IAcSmIsASubset,0xBA7381A6,0xCF0B,0x454F,0xAC,0xC1,0x3A,0xFB,0x6B,0x9C,0xB6,0xAE);


MIDL_DEFINE_GUID(IID, LIBID_AcSmNavigatorLib,0xF473451E,0x5FE5,0x4181,0xAF,0x0B,0x8F,0x4F,0xDB,0xA3,0x2A,0xF7);


MIDL_DEFINE_GUID(IID, IID_IAcSmNavTempExp,0x94BF9B27,0xB8C4,0x4BF0,0xA8,0x56,0x77,0x4E,0x15,0x43,0x08,0xD9);


MIDL_DEFINE_GUID(IID, IID_IAcSmNavTempExp2,0x146BD655,0xA5A5,0x44AB,0xB6,0xEA,0x8E,0xBB,0x30,0xAD,0xDD,0xC4);


MIDL_DEFINE_GUID(IID, IID_IAcSmNavTest,0x474895E3,0x98E3,0x40B5,0xB2,0xF8,0x13,0x5F,0xC0,0x33,0x84,0xE4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcSmNotificationHandler,0x1B275645,0x8011,0x4233,0xB2,0x2A,0x91,0xAC,0xF6,0x46,0xAC,0xF1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcSmSheetSetProperties,0xCE94D81D,0x86A7,0x494F,0x97,0x32,0xE6,0x88,0x25,0x75,0xAC,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_AcSmSheetProperties,0xABB43FA9,0x12BA,0x4F9A,0xA1,0x88,0xF7,0xEB,0x7E,0xEA,0x37,0x0E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcSmBrowseFileDialog,0x04474775,0xFC2C,0x4D5C,0xA3,0x7A,0x5F,0x91,0xA1,0x7E,0xBF,0xC6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcSmSubsetProperties,0x1F20E969,0xC60E,0x4ABB,0xB2,0x02,0xDB,0xFD,0x2A,0x11,0xED,0x6E);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



