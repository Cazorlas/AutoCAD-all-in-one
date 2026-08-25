//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////



/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AcSmNavigator_i_h__
#define __AcSmNavigator_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IAcSmSheetSetProperties_FWD_DEFINED__
#define __IAcSmSheetSetProperties_FWD_DEFINED__
typedef interface IAcSmSheetSetProperties IAcSmSheetSetProperties;

#endif 	/* __IAcSmSheetSetProperties_FWD_DEFINED__ */


#ifndef __IAcSmSheetProperties_FWD_DEFINED__
#define __IAcSmSheetProperties_FWD_DEFINED__
typedef interface IAcSmSheetProperties IAcSmSheetProperties;

#endif 	/* __IAcSmSheetProperties_FWD_DEFINED__ */


#ifndef __IAcSmSubsetProperties_FWD_DEFINED__
#define __IAcSmSubsetProperties_FWD_DEFINED__
typedef interface IAcSmSubsetProperties IAcSmSubsetProperties;

#endif 	/* __IAcSmSubsetProperties_FWD_DEFINED__ */


#ifndef __IAcSmBrowseFileDialog_FWD_DEFINED__
#define __IAcSmBrowseFileDialog_FWD_DEFINED__
typedef interface IAcSmBrowseFileDialog IAcSmBrowseFileDialog;

#endif 	/* __IAcSmBrowseFileDialog_FWD_DEFINED__ */


#ifndef __IAcSmIsASheetSet_FWD_DEFINED__
#define __IAcSmIsASheetSet_FWD_DEFINED__
typedef interface IAcSmIsASheetSet IAcSmIsASheetSet;

#endif 	/* __IAcSmIsASheetSet_FWD_DEFINED__ */


#ifndef __IAcSmIsASheet_FWD_DEFINED__
#define __IAcSmIsASheet_FWD_DEFINED__
typedef interface IAcSmIsASheet IAcSmIsASheet;

#endif 	/* __IAcSmIsASheet_FWD_DEFINED__ */


#ifndef __IAcSmIsASubset_FWD_DEFINED__
#define __IAcSmIsASubset_FWD_DEFINED__
typedef interface IAcSmIsASubset IAcSmIsASubset;

#endif 	/* __IAcSmIsASubset_FWD_DEFINED__ */


#ifndef __IAcSmNavTempExp_FWD_DEFINED__
#define __IAcSmNavTempExp_FWD_DEFINED__
typedef interface IAcSmNavTempExp IAcSmNavTempExp;

#endif 	/* __IAcSmNavTempExp_FWD_DEFINED__ */


#ifndef __IAcSmNavTempExp2_FWD_DEFINED__
#define __IAcSmNavTempExp2_FWD_DEFINED__
typedef interface IAcSmNavTempExp2 IAcSmNavTempExp2;

#endif 	/* __IAcSmNavTempExp2_FWD_DEFINED__ */


#ifndef __IAcSmNavTest_FWD_DEFINED__
#define __IAcSmNavTest_FWD_DEFINED__
typedef interface IAcSmNavTest IAcSmNavTest;

#endif 	/* __IAcSmNavTest_FWD_DEFINED__ */


#ifndef __AcSmNotificationHandler_FWD_DEFINED__
#define __AcSmNotificationHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcSmNotificationHandler AcSmNotificationHandler;
#else
typedef struct AcSmNotificationHandler AcSmNotificationHandler;
#endif /* __cplusplus */

#endif 	/* __AcSmNotificationHandler_FWD_DEFINED__ */


#ifndef __AcSmSheetSetProperties_FWD_DEFINED__
#define __AcSmSheetSetProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcSmSheetSetProperties AcSmSheetSetProperties;
#else
typedef struct AcSmSheetSetProperties AcSmSheetSetProperties;
#endif /* __cplusplus */

#endif 	/* __AcSmSheetSetProperties_FWD_DEFINED__ */


#ifndef __AcSmSheetProperties_FWD_DEFINED__
#define __AcSmSheetProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcSmSheetProperties AcSmSheetProperties;
#else
typedef struct AcSmSheetProperties AcSmSheetProperties;
#endif /* __cplusplus */

#endif 	/* __AcSmSheetProperties_FWD_DEFINED__ */


#ifndef __AcSmBrowseFileDialog_FWD_DEFINED__
#define __AcSmBrowseFileDialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcSmBrowseFileDialog AcSmBrowseFileDialog;
#else
typedef struct AcSmBrowseFileDialog AcSmBrowseFileDialog;
#endif /* __cplusplus */

#endif 	/* __AcSmBrowseFileDialog_FWD_DEFINED__ */


#ifndef __AcSmSubsetProperties_FWD_DEFINED__
#define __AcSmSubsetProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class AcSmSubsetProperties AcSmSubsetProperties;
#else
typedef struct AcSmSubsetProperties AcSmSubsetProperties;
#endif /* __cplusplus */

#endif 	/* __AcSmSubsetProperties_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AcSmNavigator_0000_0000 */
/* [local] */ 

#pragma once
typedef wchar_t ACHAR;



extern RPC_IF_HANDLE __MIDL_itf_AcSmNavigator_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AcSmNavigator_0000_0000_v0_0_s_ifspec;

#ifndef __IAcSmSheetSetProperties_INTERFACE_DEFINED__
#define __IAcSmSheetSetProperties_INTERFACE_DEFINED__

/* interface IAcSmSheetSetProperties */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcSmSheetSetProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("02C32A9E-CFCC-4EF8-B015-B33FD010C8B4")
    IAcSmSheetSetProperties : public IDispatch
    {
    public:
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetSetName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetSetName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetSetDataFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetSetDataFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetSetDescription( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetSetDescription( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResourceFileLocations( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_ResourceFileLocations( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultLabelBlocks( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultLabelBlocks( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_CalloutBlocks( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_CalloutBlocks( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetStorageLocation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetStorageLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultSheetTemplate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultSheetTemplate( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_PromptForTemplate( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_PromptForTemplate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_AlternativePageSetup( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_AlternativePageSetup( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProjectNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProjectName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectPhase( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProjectPhase( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProjectMilestone( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProjectMilestone( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmSheetSetPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmSheetSetProperties * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmSheetSetProperties * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcSmSheetSetProperties * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcSmSheetSetProperties * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_SheetSetName)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetSetName )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_SheetSetName)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetSetName )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_SheetSetDataFile)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetSetDataFile )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_SheetSetDataFile)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetSetDataFile )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_SheetSetDescription)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetSetDescription )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_SheetSetDescription)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetSetDescription )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_ResourceFileLocations)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResourceFileLocations )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_ResourceFileLocations)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ResourceFileLocations )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_DefaultLabelBlocks)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultLabelBlocks )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_DefaultLabelBlocks)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultLabelBlocks )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_CalloutBlocks)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CalloutBlocks )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_CalloutBlocks)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CalloutBlocks )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_SheetStorageLocation)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetStorageLocation )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_SheetStorageLocation)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetStorageLocation )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_DefaultSheetTemplate)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultSheetTemplate )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_DefaultSheetTemplate)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultSheetTemplate )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_PromptForTemplate)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PromptForTemplate )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_PromptForTemplate)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PromptForTemplate )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_AlternativePageSetup)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AlternativePageSetup )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_AlternativePageSetup)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AlternativePageSetup )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_ProjectNumber)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectNumber )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_ProjectNumber)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProjectNumber )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_ProjectName)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectName )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_ProjectName)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProjectName )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_ProjectPhase)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectPhase )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_ProjectPhase)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProjectPhase )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, get_ProjectMilestone)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectMilestone )( 
            IAcSmSheetSetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetSetProperties, put_ProjectMilestone)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProjectMilestone )( 
            IAcSmSheetSetProperties * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IAcSmSheetSetPropertiesVtbl;

    interface IAcSmSheetSetProperties
    {
        CONST_VTBL struct IAcSmSheetSetPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmSheetSetProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmSheetSetProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmSheetSetProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcSmSheetSetProperties_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcSmSheetSetProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcSmSheetSetProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcSmSheetSetProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcSmSheetSetProperties_get_SheetSetName(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetSetName(This,pVal) ) 

#define IAcSmSheetSetProperties_put_SheetSetName(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetSetName(This,newVal) ) 

#define IAcSmSheetSetProperties_get_SheetSetDataFile(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetSetDataFile(This,pVal) ) 

#define IAcSmSheetSetProperties_put_SheetSetDataFile(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetSetDataFile(This,newVal) ) 

#define IAcSmSheetSetProperties_get_SheetSetDescription(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetSetDescription(This,pVal) ) 

#define IAcSmSheetSetProperties_put_SheetSetDescription(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetSetDescription(This,newVal) ) 

#define IAcSmSheetSetProperties_get_ResourceFileLocations(This,pVal)	\
    ( (This)->lpVtbl -> get_ResourceFileLocations(This,pVal) ) 

#define IAcSmSheetSetProperties_put_ResourceFileLocations(This,newVal)	\
    ( (This)->lpVtbl -> put_ResourceFileLocations(This,newVal) ) 

#define IAcSmSheetSetProperties_get_DefaultLabelBlocks(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultLabelBlocks(This,pVal) ) 

#define IAcSmSheetSetProperties_put_DefaultLabelBlocks(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultLabelBlocks(This,newVal) ) 

#define IAcSmSheetSetProperties_get_CalloutBlocks(This,pVal)	\
    ( (This)->lpVtbl -> get_CalloutBlocks(This,pVal) ) 

#define IAcSmSheetSetProperties_put_CalloutBlocks(This,newVal)	\
    ( (This)->lpVtbl -> put_CalloutBlocks(This,newVal) ) 

#define IAcSmSheetSetProperties_get_SheetStorageLocation(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetStorageLocation(This,pVal) ) 

#define IAcSmSheetSetProperties_put_SheetStorageLocation(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetStorageLocation(This,newVal) ) 

#define IAcSmSheetSetProperties_get_DefaultSheetTemplate(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultSheetTemplate(This,pVal) ) 

#define IAcSmSheetSetProperties_put_DefaultSheetTemplate(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultSheetTemplate(This,newVal) ) 

#define IAcSmSheetSetProperties_get_PromptForTemplate(This,pVal)	\
    ( (This)->lpVtbl -> get_PromptForTemplate(This,pVal) ) 

#define IAcSmSheetSetProperties_put_PromptForTemplate(This,newVal)	\
    ( (This)->lpVtbl -> put_PromptForTemplate(This,newVal) ) 

#define IAcSmSheetSetProperties_get_AlternativePageSetup(This,pVal)	\
    ( (This)->lpVtbl -> get_AlternativePageSetup(This,pVal) ) 

#define IAcSmSheetSetProperties_put_AlternativePageSetup(This,newVal)	\
    ( (This)->lpVtbl -> put_AlternativePageSetup(This,newVal) ) 

#define IAcSmSheetSetProperties_get_ProjectNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ProjectNumber(This,pVal) ) 

#define IAcSmSheetSetProperties_put_ProjectNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ProjectNumber(This,newVal) ) 

#define IAcSmSheetSetProperties_get_ProjectName(This,pVal)	\
    ( (This)->lpVtbl -> get_ProjectName(This,pVal) ) 

#define IAcSmSheetSetProperties_put_ProjectName(This,newVal)	\
    ( (This)->lpVtbl -> put_ProjectName(This,newVal) ) 

#define IAcSmSheetSetProperties_get_ProjectPhase(This,pVal)	\
    ( (This)->lpVtbl -> get_ProjectPhase(This,pVal) ) 

#define IAcSmSheetSetProperties_put_ProjectPhase(This,newVal)	\
    ( (This)->lpVtbl -> put_ProjectPhase(This,newVal) ) 

#define IAcSmSheetSetProperties_get_ProjectMilestone(This,pVal)	\
    ( (This)->lpVtbl -> get_ProjectMilestone(This,pVal) ) 

#define IAcSmSheetSetProperties_put_ProjectMilestone(This,newVal)	\
    ( (This)->lpVtbl -> put_ProjectMilestone(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmSheetSetProperties_INTERFACE_DEFINED__ */


#ifndef __IAcSmSheetProperties_INTERFACE_DEFINED__
#define __IAcSmSheetProperties_INTERFACE_DEFINED__

/* interface IAcSmSheetProperties */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcSmSheetProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4895E373-0408-44CF-A086-7F45635E8BB9")
    IAcSmSheetProperties : public IDispatch
    {
    public:
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetTitle( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetTitle( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetDescription( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetDescription( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_IncludeForPublish( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_IncludeForPublish( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExpectedLocation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExpectedLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_FoundLocation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_FoundLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetSetName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetSetName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_RevisionNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_RevisionNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_RevisionDate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_RevisionDate( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_IssuePurpose( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_IssuePurpose( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Category( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Category( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmSheetPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmSheetProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmSheetProperties * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmSheetProperties * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcSmSheetProperties * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcSmSheetProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcSmSheetProperties * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcSmSheetProperties * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_SheetTitle)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetTitle )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_SheetTitle)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetTitle )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_SheetNumber)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetNumber )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_SheetNumber)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetNumber )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_SheetDescription)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetDescription )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_SheetDescription)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetDescription )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_IncludeForPublish)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IncludeForPublish )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_IncludeForPublish)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IncludeForPublish )( 
            IAcSmSheetProperties * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_ExpectedLocation)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExpectedLocation )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_ExpectedLocation)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExpectedLocation )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_FoundLocation)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FoundLocation )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_FoundLocation)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FoundLocation )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_SheetSetName)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetSetName )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_SheetSetName)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetSetName )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_RevisionNumber)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RevisionNumber )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_RevisionNumber)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RevisionNumber )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_RevisionDate)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RevisionDate )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_RevisionDate)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RevisionDate )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_IssuePurpose)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IssuePurpose )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_IssuePurpose)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IssuePurpose )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, get_Category)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IAcSmSheetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSheetProperties, put_Category)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Category )( 
            IAcSmSheetProperties * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IAcSmSheetPropertiesVtbl;

    interface IAcSmSheetProperties
    {
        CONST_VTBL struct IAcSmSheetPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmSheetProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmSheetProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmSheetProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcSmSheetProperties_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcSmSheetProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcSmSheetProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcSmSheetProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcSmSheetProperties_get_SheetTitle(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetTitle(This,pVal) ) 

#define IAcSmSheetProperties_put_SheetTitle(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetTitle(This,newVal) ) 

#define IAcSmSheetProperties_get_SheetNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetNumber(This,pVal) ) 

#define IAcSmSheetProperties_put_SheetNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetNumber(This,newVal) ) 

#define IAcSmSheetProperties_get_SheetDescription(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetDescription(This,pVal) ) 

#define IAcSmSheetProperties_put_SheetDescription(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetDescription(This,newVal) ) 

#define IAcSmSheetProperties_get_IncludeForPublish(This,pVal)	\
    ( (This)->lpVtbl -> get_IncludeForPublish(This,pVal) ) 

#define IAcSmSheetProperties_put_IncludeForPublish(This,newVal)	\
    ( (This)->lpVtbl -> put_IncludeForPublish(This,newVal) ) 

#define IAcSmSheetProperties_get_ExpectedLocation(This,pVal)	\
    ( (This)->lpVtbl -> get_ExpectedLocation(This,pVal) ) 

#define IAcSmSheetProperties_put_ExpectedLocation(This,newVal)	\
    ( (This)->lpVtbl -> put_ExpectedLocation(This,newVal) ) 

#define IAcSmSheetProperties_get_FoundLocation(This,pVal)	\
    ( (This)->lpVtbl -> get_FoundLocation(This,pVal) ) 

#define IAcSmSheetProperties_put_FoundLocation(This,newVal)	\
    ( (This)->lpVtbl -> put_FoundLocation(This,newVal) ) 

#define IAcSmSheetProperties_get_SheetSetName(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetSetName(This,pVal) ) 

#define IAcSmSheetProperties_put_SheetSetName(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetSetName(This,newVal) ) 

#define IAcSmSheetProperties_get_RevisionNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_RevisionNumber(This,pVal) ) 

#define IAcSmSheetProperties_put_RevisionNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_RevisionNumber(This,newVal) ) 

#define IAcSmSheetProperties_get_RevisionDate(This,pVal)	\
    ( (This)->lpVtbl -> get_RevisionDate(This,pVal) ) 

#define IAcSmSheetProperties_put_RevisionDate(This,newVal)	\
    ( (This)->lpVtbl -> put_RevisionDate(This,newVal) ) 

#define IAcSmSheetProperties_get_IssuePurpose(This,pVal)	\
    ( (This)->lpVtbl -> get_IssuePurpose(This,pVal) ) 

#define IAcSmSheetProperties_put_IssuePurpose(This,newVal)	\
    ( (This)->lpVtbl -> put_IssuePurpose(This,newVal) ) 

#define IAcSmSheetProperties_get_Category(This,pVal)	\
    ( (This)->lpVtbl -> get_Category(This,pVal) ) 

#define IAcSmSheetProperties_put_Category(This,newVal)	\
    ( (This)->lpVtbl -> put_Category(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmSheetProperties_INTERFACE_DEFINED__ */


#ifndef __IAcSmSubsetProperties_INTERFACE_DEFINED__
#define __IAcSmSubsetProperties_INTERFACE_DEFINED__

/* interface IAcSmSubsetProperties */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcSmSubsetProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A04CE508-C167-4AAD-A75C-5628D25162A8")
    IAcSmSubsetProperties : public IDispatch
    {
    public:
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubsetName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubsetName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreateRelativeFolders( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_CreateRelativeFolders( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverrideSheetPublishValues( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverrideSheetPublishValues( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_NewSheetLocation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_NewSheetLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_SheetTemplate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_SheetTemplate( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstringcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_PromptForTemplate( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstringcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_PromptForTemplate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmSubsetPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmSubsetProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmSubsetProperties * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmSubsetProperties * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcSmSubsetProperties * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcSmSubsetProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcSmSubsetProperties * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcSmSubsetProperties * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, get_SubsetName)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubsetName )( 
            IAcSmSubsetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, put_SubsetName)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SubsetName )( 
            IAcSmSubsetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, get_CreateRelativeFolders)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreateRelativeFolders )( 
            IAcSmSubsetProperties * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, put_CreateRelativeFolders)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CreateRelativeFolders )( 
            IAcSmSubsetProperties * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, get_OverrideSheetPublishValues)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverrideSheetPublishValues )( 
            IAcSmSubsetProperties * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, put_OverrideSheetPublishValues)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverrideSheetPublishValues )( 
            IAcSmSubsetProperties * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, get_NewSheetLocation)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NewSheetLocation )( 
            IAcSmSubsetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, put_NewSheetLocation)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NewSheetLocation )( 
            IAcSmSubsetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, get_SheetTemplate)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SheetTemplate )( 
            IAcSmSubsetProperties * This,
            /* [retval][out] */ BSTR *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, put_SheetTemplate)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SheetTemplate )( 
            IAcSmSubsetProperties * This,
            /* [in] */ BSTR newVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, get_PromptForTemplate)
        /* [helpstringcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PromptForTemplate )( 
            IAcSmSubsetProperties * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        DECLSPEC_XFGVIRT(IAcSmSubsetProperties, put_PromptForTemplate)
        /* [helpstringcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PromptForTemplate )( 
            IAcSmSubsetProperties * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IAcSmSubsetPropertiesVtbl;

    interface IAcSmSubsetProperties
    {
        CONST_VTBL struct IAcSmSubsetPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmSubsetProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmSubsetProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmSubsetProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcSmSubsetProperties_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcSmSubsetProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcSmSubsetProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcSmSubsetProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAcSmSubsetProperties_get_SubsetName(This,pVal)	\
    ( (This)->lpVtbl -> get_SubsetName(This,pVal) ) 

#define IAcSmSubsetProperties_put_SubsetName(This,newVal)	\
    ( (This)->lpVtbl -> put_SubsetName(This,newVal) ) 

#define IAcSmSubsetProperties_get_CreateRelativeFolders(This,pVal)	\
    ( (This)->lpVtbl -> get_CreateRelativeFolders(This,pVal) ) 

#define IAcSmSubsetProperties_put_CreateRelativeFolders(This,newVal)	\
    ( (This)->lpVtbl -> put_CreateRelativeFolders(This,newVal) ) 

#define IAcSmSubsetProperties_get_OverrideSheetPublishValues(This,pVal)	\
    ( (This)->lpVtbl -> get_OverrideSheetPublishValues(This,pVal) ) 

#define IAcSmSubsetProperties_put_OverrideSheetPublishValues(This,newVal)	\
    ( (This)->lpVtbl -> put_OverrideSheetPublishValues(This,newVal) ) 

#define IAcSmSubsetProperties_get_NewSheetLocation(This,pVal)	\
    ( (This)->lpVtbl -> get_NewSheetLocation(This,pVal) ) 

#define IAcSmSubsetProperties_put_NewSheetLocation(This,newVal)	\
    ( (This)->lpVtbl -> put_NewSheetLocation(This,newVal) ) 

#define IAcSmSubsetProperties_get_SheetTemplate(This,pVal)	\
    ( (This)->lpVtbl -> get_SheetTemplate(This,pVal) ) 

#define IAcSmSubsetProperties_put_SheetTemplate(This,newVal)	\
    ( (This)->lpVtbl -> put_SheetTemplate(This,newVal) ) 

#define IAcSmSubsetProperties_get_PromptForTemplate(This,pVal)	\
    ( (This)->lpVtbl -> get_PromptForTemplate(This,pVal) ) 

#define IAcSmSubsetProperties_put_PromptForTemplate(This,newVal)	\
    ( (This)->lpVtbl -> put_PromptForTemplate(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmSubsetProperties_INTERFACE_DEFINED__ */


#ifndef __IAcSmBrowseFileDialog_INTERFACE_DEFINED__
#define __IAcSmBrowseFileDialog_INTERFACE_DEFINED__

/* interface IAcSmBrowseFileDialog */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcSmBrowseFileDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1267B246-65F3-4FFC-871C-04F1EC106E11")
    IAcSmBrowseFileDialog : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmBrowseFileDialogVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmBrowseFileDialog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmBrowseFileDialog * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmBrowseFileDialog * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAcSmBrowseFileDialog * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAcSmBrowseFileDialog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAcSmBrowseFileDialog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAcSmBrowseFileDialog * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAcSmBrowseFileDialogVtbl;

    interface IAcSmBrowseFileDialog
    {
        CONST_VTBL struct IAcSmBrowseFileDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmBrowseFileDialog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmBrowseFileDialog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmBrowseFileDialog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcSmBrowseFileDialog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAcSmBrowseFileDialog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAcSmBrowseFileDialog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAcSmBrowseFileDialog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmBrowseFileDialog_INTERFACE_DEFINED__ */


#ifndef __IAcSmIsASheetSet_INTERFACE_DEFINED__
#define __IAcSmIsASheetSet_INTERFACE_DEFINED__

/* interface IAcSmIsASheetSet */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcSmIsASheetSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("41C49911-EE8E-435D-ABC0-3F957AEA1C54")
    IAcSmIsASheetSet : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmIsASheetSetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmIsASheetSet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmIsASheetSet * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmIsASheetSet * This);
        
        END_INTERFACE
    } IAcSmIsASheetSetVtbl;

    interface IAcSmIsASheetSet
    {
        CONST_VTBL struct IAcSmIsASheetSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmIsASheetSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmIsASheetSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmIsASheetSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmIsASheetSet_INTERFACE_DEFINED__ */


#ifndef __IAcSmIsASheet_INTERFACE_DEFINED__
#define __IAcSmIsASheet_INTERFACE_DEFINED__

/* interface IAcSmIsASheet */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcSmIsASheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18431D76-8851-4050-9C01-490D05311E8A")
    IAcSmIsASheet : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmIsASheetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmIsASheet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmIsASheet * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmIsASheet * This);
        
        END_INTERFACE
    } IAcSmIsASheetVtbl;

    interface IAcSmIsASheet
    {
        CONST_VTBL struct IAcSmIsASheetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmIsASheet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmIsASheet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmIsASheet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmIsASheet_INTERFACE_DEFINED__ */


#ifndef __IAcSmIsASubset_INTERFACE_DEFINED__
#define __IAcSmIsASubset_INTERFACE_DEFINED__

/* interface IAcSmIsASubset */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAcSmIsASubset;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA7381A6-CF0B-454F-ACC1-3AFB6B9CB6AE")
    IAcSmIsASubset : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmIsASubsetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmIsASubset * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmIsASubset * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmIsASubset * This);
        
        END_INTERFACE
    } IAcSmIsASubsetVtbl;

    interface IAcSmIsASubset
    {
        CONST_VTBL struct IAcSmIsASubsetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmIsASubset_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmIsASubset_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmIsASubset_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmIsASubset_INTERFACE_DEFINED__ */



#ifndef __AcSmNavigatorLib_LIBRARY_DEFINED__
#define __AcSmNavigatorLib_LIBRARY_DEFINED__

/* library AcSmNavigatorLib */
/* [custom][helpstring][helpstringdll][version][uuid] */ 

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("C5224F70-99CB-45E6-B5A4-7B525A5E3292") 
enum AcSmUiFilter
    {
        acSmUiTypeNone	= 0,
        acSmUiSheetsTree	= 0x1,
        acSmUiSheetsThumbList	= 0x2,
        acSmUiSheetsDetail	= 0x4,
        acSmUiSheetsPreview	= 0x8,
        acSmUiViewsTree	= 0x10,
        acSmUiViewsThumbList	= 0x20,
        acSmUiViewsDetail	= 0x40,
        acSmUiViewsPreview	= 0x80,
        acSmUiModelFolderTree	= 0x100,
        acSmUiModelFolderThumbList	= 0x200,
        acSmUiModelViewsTree	= 0x400,
        acSmUiModelViewsThumbList	= 0x800,
        acSmUiModelDetail	= 0x1000,
        acSmUiModelPreview	= 0x2000
    } 	AcSmUiFilter;


EXTERN_C const IID LIBID_AcSmNavigatorLib;

#ifndef __IAcSmNavTempExp_INTERFACE_DEFINED__
#define __IAcSmNavTempExp_INTERFACE_DEFINED__

/* interface IAcSmNavTempExp */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IAcSmNavTempExp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94BF9B27-B8C4-4BF0-A856-774E154308D9")
    IAcSmNavTempExp : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetNavActiveSheetSet( 
            /* [out] */ /* external definition not present */ IAcSmDatabase **ppActiveSS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNavActiveSheetSet( 
            /* [in] */ /* external definition not present */ IAcSmDatabase *pActiveSS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNavActiveSheetSetInWeb( 
            /* [in] */ BSTR bstrSS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNavActiveSheetSetInClassic( 
            /* [in] */ /* external definition not present */ IAcSmDatabase *pActiveSS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenSheetSetInNav( 
            /* [in] */ BSTR bstrSS) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNavSheetSets( 
            /* [out] */ SAFEARRAY * *dbs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BrowserOpenSheetSetInNav( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ToggleSSMNavigator( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmNavTempExpVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmNavTempExp * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmNavTempExp * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmNavTempExp * This);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, GetNavActiveSheetSet)
        HRESULT ( STDMETHODCALLTYPE *GetNavActiveSheetSet )( 
            IAcSmNavTempExp * This,
            /* [out] */ /* external definition not present */ IAcSmDatabase **ppActiveSS);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, SetNavActiveSheetSet)
        HRESULT ( STDMETHODCALLTYPE *SetNavActiveSheetSet )( 
            IAcSmNavTempExp * This,
            /* [in] */ /* external definition not present */ IAcSmDatabase *pActiveSS);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, SetNavActiveSheetSetInWeb)
        HRESULT ( STDMETHODCALLTYPE *SetNavActiveSheetSetInWeb )( 
            IAcSmNavTempExp * This,
            /* [in] */ BSTR bstrSS);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, SetNavActiveSheetSetInClassic)
        HRESULT ( STDMETHODCALLTYPE *SetNavActiveSheetSetInClassic )( 
            IAcSmNavTempExp * This,
            /* [in] */ /* external definition not present */ IAcSmDatabase *pActiveSS);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, OpenSheetSetInNav)
        HRESULT ( STDMETHODCALLTYPE *OpenSheetSetInNav )( 
            IAcSmNavTempExp * This,
            /* [in] */ BSTR bstrSS);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, GetNavSheetSets)
        HRESULT ( STDMETHODCALLTYPE *GetNavSheetSets )( 
            IAcSmNavTempExp * This,
            /* [out] */ SAFEARRAY * *dbs);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, BrowserOpenSheetSetInNav)
        HRESULT ( STDMETHODCALLTYPE *BrowserOpenSheetSetInNav )( 
            IAcSmNavTempExp * This);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp, ToggleSSMNavigator)
        HRESULT ( STDMETHODCALLTYPE *ToggleSSMNavigator )( 
            IAcSmNavTempExp * This);
        
        END_INTERFACE
    } IAcSmNavTempExpVtbl;

    interface IAcSmNavTempExp
    {
        CONST_VTBL struct IAcSmNavTempExpVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmNavTempExp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmNavTempExp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmNavTempExp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcSmNavTempExp_GetNavActiveSheetSet(This,ppActiveSS)	\
    ( (This)->lpVtbl -> GetNavActiveSheetSet(This,ppActiveSS) ) 

#define IAcSmNavTempExp_SetNavActiveSheetSet(This,pActiveSS)	\
    ( (This)->lpVtbl -> SetNavActiveSheetSet(This,pActiveSS) ) 

#define IAcSmNavTempExp_SetNavActiveSheetSetInWeb(This,bstrSS)	\
    ( (This)->lpVtbl -> SetNavActiveSheetSetInWeb(This,bstrSS) ) 

#define IAcSmNavTempExp_SetNavActiveSheetSetInClassic(This,pActiveSS)	\
    ( (This)->lpVtbl -> SetNavActiveSheetSetInClassic(This,pActiveSS) ) 

#define IAcSmNavTempExp_OpenSheetSetInNav(This,bstrSS)	\
    ( (This)->lpVtbl -> OpenSheetSetInNav(This,bstrSS) ) 

#define IAcSmNavTempExp_GetNavSheetSets(This,dbs)	\
    ( (This)->lpVtbl -> GetNavSheetSets(This,dbs) ) 

#define IAcSmNavTempExp_BrowserOpenSheetSetInNav(This)	\
    ( (This)->lpVtbl -> BrowserOpenSheetSetInNav(This) ) 

#define IAcSmNavTempExp_ToggleSSMNavigator(This)	\
    ( (This)->lpVtbl -> ToggleSSMNavigator(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmNavTempExp_INTERFACE_DEFINED__ */


#ifndef __IAcSmNavTempExp2_INTERFACE_DEFINED__
#define __IAcSmNavTempExp2_INTERFACE_DEFINED__

/* interface IAcSmNavTempExp2 */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IAcSmNavTempExp2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("146BD655-A5A5-44AB-B6EA-8EBB30ADDDC4")
    IAcSmNavTempExp2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ImportLayoutsAsSheets( 
            /* [in] */ BSTR bstrDWG,
            /* [in] */ SAFEARRAY * LayoutNames) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmNavTempExp2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmNavTempExp2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmNavTempExp2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmNavTempExp2 * This);
        
        DECLSPEC_XFGVIRT(IAcSmNavTempExp2, ImportLayoutsAsSheets)
        HRESULT ( STDMETHODCALLTYPE *ImportLayoutsAsSheets )( 
            IAcSmNavTempExp2 * This,
            /* [in] */ BSTR bstrDWG,
            /* [in] */ SAFEARRAY * LayoutNames);
        
        END_INTERFACE
    } IAcSmNavTempExp2Vtbl;

    interface IAcSmNavTempExp2
    {
        CONST_VTBL struct IAcSmNavTempExp2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmNavTempExp2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmNavTempExp2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmNavTempExp2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcSmNavTempExp2_ImportLayoutsAsSheets(This,bstrDWG,LayoutNames)	\
    ( (This)->lpVtbl -> ImportLayoutsAsSheets(This,bstrDWG,LayoutNames) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmNavTempExp2_INTERFACE_DEFINED__ */


#ifndef __IAcSmNavTest_INTERFACE_DEFINED__
#define __IAcSmNavTest_INTERFACE_DEFINED__

/* interface IAcSmNavTest */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IAcSmNavTest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("474895E3-98E3-40B5-B2F8-135FC03384E4")
    IAcSmNavTest : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ActivateComponentInAcad( 
            /* [in] */ /* external definition not present */ IAcSmComponent *pComponent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateCurrentSheetSetInNav( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseSheetSetInNav( 
            /* [in] */ /* external definition not present */ IAcSmDatabase *pActiveSS) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAcSmNavTestVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAcSmNavTest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAcSmNavTest * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAcSmNavTest * This);
        
        DECLSPEC_XFGVIRT(IAcSmNavTest, ActivateComponentInAcad)
        HRESULT ( STDMETHODCALLTYPE *ActivateComponentInAcad )( 
            IAcSmNavTest * This,
            /* [in] */ /* external definition not present */ IAcSmComponent *pComponent);
        
        DECLSPEC_XFGVIRT(IAcSmNavTest, UpdateCurrentSheetSetInNav)
        HRESULT ( STDMETHODCALLTYPE *UpdateCurrentSheetSetInNav )( 
            IAcSmNavTest * This);
        
        DECLSPEC_XFGVIRT(IAcSmNavTest, CloseSheetSetInNav)
        HRESULT ( STDMETHODCALLTYPE *CloseSheetSetInNav )( 
            IAcSmNavTest * This,
            /* [in] */ /* external definition not present */ IAcSmDatabase *pActiveSS);
        
        END_INTERFACE
    } IAcSmNavTestVtbl;

    interface IAcSmNavTest
    {
        CONST_VTBL struct IAcSmNavTestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcSmNavTest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcSmNavTest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcSmNavTest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcSmNavTest_ActivateComponentInAcad(This,pComponent)	\
    ( (This)->lpVtbl -> ActivateComponentInAcad(This,pComponent) ) 

#define IAcSmNavTest_UpdateCurrentSheetSetInNav(This)	\
    ( (This)->lpVtbl -> UpdateCurrentSheetSetInNav(This) ) 

#define IAcSmNavTest_CloseSheetSetInNav(This,pActiveSS)	\
    ( (This)->lpVtbl -> CloseSheetSetInNav(This,pActiveSS) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcSmNavTest_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AcSmNotificationHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("1B275645-8011-4233-B22A-91ACF646ACF1")
AcSmNotificationHandler;
#endif

EXTERN_C const CLSID CLSID_AcSmSheetSetProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("CE94D81D-86A7-494F-9732-E6882575AC20")
AcSmSheetSetProperties;
#endif

EXTERN_C const CLSID CLSID_AcSmSheetProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("ABB43FA9-12BA-4F9A-A188-F7EB7EEA370E")
AcSmSheetProperties;
#endif

EXTERN_C const CLSID CLSID_AcSmBrowseFileDialog;

#ifdef __cplusplus

class DECLSPEC_UUID("04474775-FC2C-4D5C-A37A-5F91A17EBFC6")
AcSmBrowseFileDialog;
#endif

EXTERN_C const CLSID CLSID_AcSmSubsetProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("1F20E969-C60E-4ABB-B202-DBFD2A11ED6E")
AcSmSubsetProperties;
#endif
#endif /* __AcSmNavigatorLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


