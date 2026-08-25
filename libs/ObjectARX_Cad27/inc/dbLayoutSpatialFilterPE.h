//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////
//
// dbLayoutSpatialFilterPE.H
//
// DESCRIPTION: Protocol extension classe
//              AcDbLayoutSpatialFilterPE
//
#pragma once

#include "acdb.h"
#include "dbmain.h"


#pragma pack (push, 8)

/// <summary>
/// This protocol extension interface can be implemented for any entity that
/// wants to change the way the LAYOUTSPATIALFILTERS feature works with it.
/// </summary>
///
class AcDbLayoutSpatialFilterPE : public AcRxObject
{
public:

    ACRX_DECLARE_MEMBERS(AcDbLayoutSpatialFilterPE);

    /// <summary>
    /// Serves as an override for the LAYOUTSPATIALFILTERS feature to use the entityExtents returned here
    /// instead of using the extents cached in the object's graphics data.
    /// </summary>
    ///
    /// <param name="pEntity">
    /// The AcDbEntity to get the property from.
    /// </param>
    /// 
    /// <param name="entityExtents">
    /// Output AcDbExtents used by the LAYOUTSPATIALFILTERS feature to check for containmant in layout viewports
    /// </param>
    ///
    /// <returns>
    /// Returns an Acad::ErrorStatus, where Acad::eOk indicates success (and the provided entityExtents will be used),
    /// or (other ErrorStatus returned) this entity will not participate in the LAYOUTSPATIALFILTERS feature and will
    /// always be regenerated on layout switches.
    /// </returns>
    ///
    virtual Acad::ErrorStatus getGeomExtents(const AcDbEntity* pEntity, AcDbExtents& entityExtents) const {
        ADESK_UNREFED_PARAM(pEntity);
        ADESK_UNREFED_PARAM(entityExtents);
        return Acad::eInvalidExtents;
    }
};

#pragma pack (pop)
