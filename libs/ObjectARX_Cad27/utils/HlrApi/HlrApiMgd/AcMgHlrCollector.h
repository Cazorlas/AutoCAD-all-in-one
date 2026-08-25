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

#include "AcMgHlrData.h"

//-----------------------------------------------------------------------------
namespace Autodesk {
 namespace AutoCAD {
  namespace HLR {

//-----------------------------------------------------------------------------
    [Autodesk::AutoCAD::Runtime::Wrapper("AsdkHlrCollector")]
    public ref class Collector : public DisposableWrapper {
    internal:
        //- Returns the unmanaged ARX Object
        inline AsdkHlrCollector* GetImpObj () {
            return (static_cast<AsdkHlrCollector *>(UnmanagedObject.ToPointer ()));
        }

    protected:
        virtual void DeleteUnmanagedObject() override;

    public:
        Collector() : DisposableWrapper(System::IntPtr(new AsdkHlrCollector()), true) {}
        Collector(ObjectIdCollection ids);
        Collector(DBObjectCollection ^entities, bool deleteInDestructor);

    public:
        property int OutputDataLength
        {
            int get();
        }

        Data^ OutputData(int index);

        property bool DeleteState {
            bool get() ;
            void set(bool) ;
        }

        property DBObjectCollection^ InputEntities
        {
            DBObjectCollection^ get();
        }

        property ObjectIdCollection^ InputEntityIds
        {
            ObjectIdCollection^ get();
        }

        void AddEntity(Entity ^pEnt);
        void AddEntities (DBObjectCollection ^pEnts);
        void AddEntity(ObjectId id);
        void AddEntities(ObjectIdCollection ^ids);
        void RemoveEntity(Entity ^pEnt);
        void RemoveEntities(DBObjectCollection ^pEnts);
        void RemoveEntity(ObjectId id) ;
        void RemoveEntities(ObjectIdCollection ^ids);

        void Clear();

    } ;

//-----------------------------------------------------------------------------
  }
 }
}
