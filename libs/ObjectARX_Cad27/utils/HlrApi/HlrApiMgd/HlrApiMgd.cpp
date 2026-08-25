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
//- HlrApiMgd.cpp : Initialization functions
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
//- DLL Entry Point
#pragma managed(push, off)
extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
    //- Remove this if you use lpReserved
    UNREFERENCED_PARAMETER(lpReserved) ;

    if ( dwReason == DLL_PROCESS_ATTACH ) {
        _hdllInstance =hInstance ;
    } else if ( dwReason == DLL_PROCESS_DETACH ) {
    }
    return (TRUE) ;
}
#pragma managed(pop)

