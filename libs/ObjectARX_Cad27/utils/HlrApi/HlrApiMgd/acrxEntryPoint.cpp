///////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("asdk")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CHlrApiMgdApp : public AcRxDbxApp {

public:
    CHlrApiMgdApp () : AcRxDbxApp () {}

    virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
        // TODO: Load dependencies here

        // You *must* call On_kInitAppMsg here
        AcRx::AppRetCode retCode =AcRxDbxApp::On_kInitAppMsg (pkt) ;
        
        // TODO: Add your initialization code here

        return (retCode) ;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
        // TODO: Add your code here

        // You *must* call On_kUnloadAppMsg here
        AcRx::AppRetCode retCode =AcRxDbxApp::On_kUnloadAppMsg (pkt) ;

        // TODO: Unload dependencies here

        return (retCode) ;
    }

    virtual void RegisterServerComponents () {
    }

} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CHlrApiMgdApp)

