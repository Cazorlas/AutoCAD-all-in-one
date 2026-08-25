//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
using namespace System ;
using namespace System::Runtime ;
using namespace System::Runtime::InteropServices ;
using namespace Autodesk::AutoCAD::Runtime ;
using namespace Autodesk::AutoCAD::DatabaseServices ;
using namespace Autodesk::AutoCAD::Geometry;

#include "AcMgHlrCollector.h"


//-----------------------------------------------------------------------------
namespace Autodesk {
 namespace AutoCAD {
  namespace HLR {

//-----------------------------------------------------------------------------
    [Autodesk::AutoCAD::Runtime::Wrapper("AsdkHlrControl")]
    public enum class Control {
        Project         =/*AsdkHlrControl::*/kProject,          // Should the curves be projected to a plane?
        ShowAll         =/*AsdkHlrControl::*/kShowAll,          // Should all curves be returned, or just visible ones?
        Entity          =/*AsdkHlrControl::*/kEntity,           // Is it required to return the entity which caused
                                                                // a particular curve to be created?
        Block           =/*AsdkHlrControl::*/kBlock,            // Are the objectIds for the generating entities
                                                                // required, including those of the nested blocks?
        Subentity       =/*AsdkHlrControl::*/kSubentity,        // Should the subentity information be returned for solids or graphic
                                                                // primitives?
        HideTangents    =/*AsdkHlrControl::*/kHideTangents,     // Should tangent edges be suppressed?
        Cleanup         =/*AsdkHlrControl::*/kCleanup,          // Should stored data be cleaned after use?
        Isolines        =/*AsdkHlrControl::*/kIsolines,         // Should isolines be shown (same as would be seen in AutoCAD)?
        Unite           =/*AsdkHlrControl::*/kUnite,            // Should the entities be united before hidden lines?
                                                                // Will be much slower, but more accurate for intersecting entities.
        Reuse           =/*AsdkHlrControl::*/kReuse,            // Should the algorithm use the data which were created previously?
        Progress        =/*AsdkHlrControl::*/kProgress,         // Should the progress & abort callbacks be called?
        HandlePoints    =/*AsdkHlrControl::*/kHandlePoints,     // Should we show single points (requires bit more processing)?
        ProcessAll      =/*AsdkHlrControl::*/kProcessAll,       // Process all entities without looking at their layer state
                                                                // on which they lie on.
        HonorInternals  =/*AsdkHlrControl::*/kHonorInternals,
                                                                // Should we process internal edges' visibility (i.e. AcDbPolyFaceMesh /
                                                                // ACIS internal common edge / custom entity mesh/shell promitives)
                                                                // Will be much slower, but more accurate for internal edges' visibility
                                                                // processing.
        MeshSilhouettes =/*AsdkHlrControl::*/kMeshSilhouettes,  // Should we generate silhouettes for AcDbPolyFaceMesh
        SingleCacheVp   =/*AsdkHlrControl::*/kSingleCacheVp     // The HLR object cache is unique for all viewports
    } ;

    [Autodesk::AutoCAD::Runtime::Wrapper("AsdkHlrEngine")]
    public ref class Engine : public DisposableWrapper {
    internal:
        //- Returns the unmanaged ARX Object
        inline AsdkHlrEngine* GetImpObj () {
            return (static_cast<AsdkHlrEngine *>(__super::UnmanagedObject.ToPointer ())) ;
        }

        Engine(System::IntPtr unmanagedPointer, bool autoDelete) : DisposableWrapper (unmanagedPointer, autoDelete) {}

    protected:
        virtual void DeleteUnmanagedObject() override;

    public:
        Engine() : DisposableWrapper(System::IntPtr (new AsdkHlrData() ), true) {}
        Engine(int ctrl /*=kShowAll | kEntity | kBlock | kSubentity | kReuse*/);
        Engine(ObjectId id, int ctrl /*=kShowAll | kEntity | kBlock | kSubentity | kReuse*/);
        Engine(Viewport ^pViewport, int ctrl /*=kShowAll | kEntity | kBlock | kSubentity | kReuse*/);
        Engine(Point3d viewTarget, Vector3d viewDirection, int ctrl /*=kShowAll | kEntity | kBlock | kSubentity | kReuse*/);

        int Run(Collector ^collector);

//      void setAbortCallback (_AbortCallbackFct fct) ;

        //void setAcisConversionProgressCallBack (ProgressCallback ^callback);
        //void setAhlProgressCallBack            (ProgressCallback ^callback);
        //void setAcadConversionProgressCallBack (ProgressCallback ^callback);

        static void CleanHlrCache();
        static void CleanHlrCache(Entity ^pEnt, Viewport ^pVp);
        static void CleanHlrCache(Entity ^pEnt, Point3d viewTarget, Vector3d viewDir);

    } ;

//-----------------------------------------------------------------------------
  }
 }
}
