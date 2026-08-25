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
#include "StdAfx.h"
#include "AcMgHlrData.h"

//---------------------------------------------------------------------
namespace Autodesk {
    namespace AutoCAD {
        namespace HLR {

            //-----------------------------------------------------------------------------
            Entity^ Data::RootEntity::get() {
                Entity^ pEntity = safe_cast<Entity^>(Entity::Create(System::IntPtr(GetImpObj()->getEntity()), false));
                return (pEntity);
            }

            ObjectIdCollection^ Data::ObjectIds::get() {
                ObjectIdCollection^ tmp = gcnew ObjectIdCollection();
                *static_cast<AcDbObjectIdArray *>(tmp->UnmanagedObject.ToPointer()) = GetImpObj()->getObjectIds();
                return (tmp);
            }

            Entity^ Data::ResultEntity::get() {
                Entity^ pEntity = safe_cast<Entity^>(Entity::Create(System::IntPtr(GetImpObj()->getResultEntity()), false));
                return (pEntity);
            }

            void Data::ResultEntity::set(Entity^ pEntity) {
                AcDbEntity *entity;

                if (pEntity)
                    entity = static_cast<AcDbEntity *>(pEntity->UnmanagedObject.ToPointer());
                else
                    entity = NULL;

                GetImpObj()->setResultEntity(entity);
            }

            Visibility Data::EntityVisibility::get() {
                return (static_cast<Visibility>(GetImpObj()->getVisibility()));
            }

            Visibility Data::HlrVisibility::get() {
                return (static_cast<Visibility>(GetImpObj()->getHlrVisibility()));
            }

            SubentityId Data::SubentId::get() {
                SubentityId tmp;
                pin_ptr<SubentityId> pinner = &tmp;
                GETSUBENTITYID(*pinner) = GetImpObj()->getSubentId();
                return (tmp);
            }

            //---------------------------------------------------------------------
        }
    }
}
