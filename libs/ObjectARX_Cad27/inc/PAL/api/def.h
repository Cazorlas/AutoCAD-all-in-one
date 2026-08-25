//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license
//  agreement provided at the time of installation or download, or which
//  otherwise accompanies this software in either electronic or hard copy form

#pragma once

#ifndef ACPAL_DEF_H
#define ACPAL_DEF_H
#include "adesk.h"

#ifdef  ACPAL_API
#define   ACPAL_PORT ADESK_EXPORT
#else
//don't use __declspec(dllimport) so that we can use the .objs with both static and dynamc linking
#define   ACPAL_PORT
#endif
    
// AcPal [defined(ACPAL_API)] will implement some non cross platform
//      API for vertical [!defined(_ADESK_CROSS_PLATFORM_)] convenience.
// Cross platform code or Fabric [defined(_ADESK_CROSS_PLATFORM_) in
//      .cmake by default] should not use these APIs.
// AcPal unit test [defined(ACPAL_TEST)] need test these APIs.
#if defined(ACPAL_API) || !defined(_ADESK_CROSS_PLATFORM_) || defined(ACPAL_TEST)
#define AC_NON_CROSS_PLATFORM_API
#endif



#endif
