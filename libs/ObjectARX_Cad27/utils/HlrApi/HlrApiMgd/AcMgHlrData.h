//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------
using namespace System;
using namespace System::Runtime;
using namespace System::Runtime::InteropServices;
using namespace Autodesk::AutoCAD::Runtime;
using namespace Autodesk::AutoCAD::DatabaseServices;

//---------------------------------------------------------------------
namespace Autodesk {
 namespace AutoCAD {
  namespace HLR {

//---------------------------------------------------------------------
    [Autodesk::AutoCAD::Runtime::Wrapper("AsdkHlrData::Visibility")]
    public enum class Visibility {
        Visible = AsdkHlrData::kVisible,                     //- Not hidden by anything
        Hidden = AsdkHlrData::kHidden,                       //- Hidden by a face
        Occluded = AsdkHlrData::kOccluded,                   //- Hidden by another edge
        InternallyHidden = AsdkHlrData::kInternallyHidden,   //- Hidden because of entity internal visibility of a edge
                                                             //- (i.e. AcDbPolyFaceMesh / ACIS internal common edge)
        Undefined =AsdkHlrData::kUndefined                   //- Visibility not yet defined
    };

    [Autodesk::AutoCAD::Runtime::Wrapper("AsdkHlrData")]
    public ref class Data : public DisposableWrapper
    {
    internal:
        //- Returns the unmanaged ARX Object
        inline AsdkHlrData* GetImpObj()
        {
            return static_cast<AsdkHlrData*>(__super::UnmanagedObject.ToPointer());
        }

    protected:
        virtual void DeleteUnmanagedObject() override {};
        Data() : DisposableWrapper(System::IntPtr(new AsdkHlrData()), true) {}

    public:
        Data(System::IntPtr unmanagedPointer) : DisposableWrapper(unmanagedPointer, true) {}
        Data(System::IntPtr unmanagedPointer, bool autoDelete) : DisposableWrapper(unmanagedPointer, autoDelete) {}

        property Entity^ RootEntity
        {
            Entity^ get(); //- Gets entity causing this curve
        }
        property ObjectIdCollection^ ObjectIds
        {
            ObjectIdCollection^ get(); //- Gets ObjectIds causing this curve
        }
        property Entity^ ResultEntity
        {
            Entity^ get(); //- Curve itself. This is the actual curve stored by the class.
                             //- !In case of point, the resulting entity would be a point and not a curve!
            void set(Entity^ pEntity);
        }
        property Visibility EntityVisibility
        {
            Visibility get(); //- Obtains visiblity of this curve
        }
        property Visibility HlrVisibility
        {
            Visibility get();
        }
        property SubentityId SubentId
        {
            SubentityId get(); //- Obtains the subentities of the curve
        }
    } ;

//---------------------------------------------------------------------
  }
 }
}
