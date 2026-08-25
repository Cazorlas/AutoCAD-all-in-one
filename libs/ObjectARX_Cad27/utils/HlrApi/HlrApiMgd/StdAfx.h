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
//- StdAfx.h : include file for standard system include files,
//-      or project specific include files that are used frequently,
//-      but are changed infrequently
//-----------------------------------------------------------------------------
#pragma once

#pragma pack (push, 8)
#pragma warning(disable: 4786 4996)
//#pragma warning(disable: 4098)

//-----------------------------------------------------------------------------
#include <windows.h>

//- ObjectARX and OMF headers needs this
#include <map>

//-----------------------------------------------------------------------------
#using <mscorlib.dll>
#using <System.dll>
#using <System.Core.dll>
#using <AcDbMgd.dll>

#include <vcclr.h>

//-----------------------------------------------------------------------------
//- Include ObjectDBX/ObjectARX headers
//- Uncomment one of the following lines to bring a given library in your project.
//#define _BREP_SUPPORT_            //- Support for the BRep API
#define _HLR_SUPPORT_               //- Support for the Hidden Line Removal API
//#define _AMODELER_SUPPORT_        //- Support for the AModeler API
#include "dbxHeaders.h"

#pragma pack (pop)

