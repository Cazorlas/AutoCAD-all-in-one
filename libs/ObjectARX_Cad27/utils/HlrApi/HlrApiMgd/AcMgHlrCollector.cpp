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
#include "AcMgHlrCollector.h"

//---------------------------------------------------------------------
namespace Autodesk {
    namespace AutoCAD {
        namespace HLR {

            //---------------------------------------------------------------------
            Collector::Collector(ObjectIdCollection ids) :
                DisposableWrapper(System::IntPtr(new AsdkHlrCollector(
                    *static_cast<AcDbObjectIdArray*>(ids.UnmanagedObject.ToPointer()))), true)
            {}
            
            Collector::Collector(DBObjectCollection ^entities, bool deleteInDestructor) :
                DisposableWrapper(System::IntPtr (new AsdkHlrCollector(
                    *static_cast<AcArray<AcDbEntity*> *>(entities->UnmanagedObject.ToPointer()),
                    deleteInDestructor)), true)
            {}

            void Collector::DeleteUnmanagedObject()
            {
                delete GetImpObj();
            }

            int Collector::OutputDataLength::get() {
                return (GetImpObj()->mOutputData.logicalLength());
            }

            Data^ Collector::OutputData(int index) {
                Data^ tmp = gcnew Data((System::IntPtr)(GetImpObj()->mOutputData[index]), true);
                return (tmp);
            }

            bool Collector::DeleteState::get() {
                return (GetImpObj()->getDeleteState());
            }

            void Collector::DeleteState::set(bool deleteState) {
                GetImpObj()->setDeleteState(deleteState);
            }

            DBObjectCollection^ Collector::InputEntities::get() {
                DBObjectCollection^ tmp = gcnew DBObjectCollection();
                *static_cast<AcArray<AcDbEntity*> *>(tmp->UnmanagedObject.ToPointer()) = GetImpObj()->getInputEntities();
                return (tmp);
            }

            ObjectIdCollection^ Collector::InputEntityIds::get() {
                ObjectIdCollection^ tmp = gcnew ObjectIdCollection();
                *static_cast<AcDbObjectIdArray *>(tmp->UnmanagedObject.ToPointer()) = GetImpObj()->getInputEntityIds();
                return (tmp);
            }

            void Collector::AddEntity(Entity ^pEnt) {
                GetImpObj()->addEntity(static_cast<AcDbEntity*>(pEnt->UnmanagedObject.ToPointer()));
            }

            void Collector::AddEntities(DBObjectCollection ^pEnts) {
                AcArray<AcDbEntity*> ents = *static_cast<AcArray<AcDbEntity*> *>(pEnts->UnmanagedObject.ToPointer());
                GetImpObj()->addEntities(ents);
            }

            void Collector::AddEntity(ObjectId id) {
                GetImpObj()->addEntity((*reinterpret_cast<AcDbObjectId*>(&(id))));
            }

            void Collector::AddEntities(ObjectIdCollection ^ids) {
                AcDbObjectIdArray list = *static_cast<AcDbObjectIdArray *>(ids->UnmanagedObject.ToPointer());
                GetImpObj()->addEntities(list);
            }

            void Collector::RemoveEntity(Entity ^pEnt) {
                GetImpObj()->removeEntity(static_cast<AcDbEntity*>(pEnt->UnmanagedObject.ToPointer()));
            }

            void Collector::RemoveEntities(DBObjectCollection ^pEnts) {
                AcArray<AcDbEntity*> ents = *static_cast<AcArray<AcDbEntity*> *>(pEnts->UnmanagedObject.ToPointer());
                GetImpObj()->removeEntities(ents);
            }

            void Collector::RemoveEntity(ObjectId id) {
                GetImpObj()->removeEntity((*reinterpret_cast<AcDbObjectId*>(&(id))));
            }

            void Collector::RemoveEntities(ObjectIdCollection ^ids) {
                AcDbObjectIdArray list = *static_cast<AcDbObjectIdArray *>(ids->UnmanagedObject.ToPointer());
                GetImpObj()->removeEntities(list);
            }

            void Collector::Clear() {
                GetImpObj()->clear();
            }

            //---------------------------------------------------------------------
        }
    }
}
