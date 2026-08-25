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
#include "accmd.h"
#include  <tchar.h>
#include "AcMgHlrEngine.h"


using namespace System::Runtime::InteropServices;

namespace Autodesk 
{
    namespace AutoCAD
    {
        namespace HLR
        {
            //Wrapping Callback in managed
            
            public delegate void Delegate_AcisCallback(int);
            void  AcisCallback(int p)
            {
                acutPrintf(_T("Percent :%d\n"), p);
            }
            public delegate void Delegate_AhlCallback(int);
            void  AhlCallback(int p)
            {
                acutPrintf(_T("Percent :%d\n"), p);
            }
            public delegate void Delegate_AcadCallback(int);
            void  AcadCallback(int p)
            {
                acutPrintf(_T("Percent :%d\n"), p);
            }


            
            Engine::Engine(int ctrl) :
                DisposableWrapper(System::IntPtr (new AsdkHlrEngine(ctrl) ), true) {}

            Engine::Engine(ObjectId id, int ctrl) :
                DisposableWrapper(System::IntPtr (new AsdkHlrEngine((*reinterpret_cast<AcDbObjectId*>(&(id))), ctrl)), true)
            {}

            Engine::Engine(Viewport ^pViewport, int ctrl) :
                DisposableWrapper(System::IntPtr (new AsdkHlrEngine(static_cast<AcDbViewport*>(pViewport->UnmanagedObject.ToPointer()), ctrl)), true)
            {}

            Engine::Engine(Point3d viewTarget, Vector3d viewDirection, int ctrl) :
                DisposableWrapper(System::IntPtr (new AsdkHlrEngine(*reinterpret_cast<AcGePoint3d*>(&(viewTarget)),
                                                          *reinterpret_cast<AcGeVector3d*>(&(viewDirection)), ctrl)), true)
            {}

            void Engine::DeleteUnmanagedObject()
            {
                delete GetImpObj();
            }

            //typedef void (__cdecl * ProgressCB) (int percent_completed);
            int Engine::Run(Collector ^collector)
            {
                AsdkHlrEngine    *pEngine    = GetImpObj();
                AsdkHlrCollector *pCollector = static_cast<AsdkHlrCollector*>(collector->UnmanagedObject.ToPointer());
                Delegate_AcisCallback^ fpAcis = gcnew Delegate_AcisCallback(&AcisCallback);
                Delegate_AcadCallback^ fpAcad = gcnew Delegate_AcadCallback(&AcadCallback);
                Delegate_AhlCallback^ fpAhl =   gcnew Delegate_AhlCallback(&AhlCallback);
                GCHandle gch1 = GCHandle::Alloc(fpAcis);
                GCHandle gch2 = GCHandle::Alloc(fpAcad);
                GCHandle gch3 = GCHandle::Alloc(fpAhl);

                IntPtr ip = Marshal::GetFunctionPointerForDelegate(fpAcis);
                _ProgressCallbackFct pcbfpAcis = static_cast<_ProgressCallbackFct>(ip.ToPointer());
                
                 ip = Marshal::GetFunctionPointerForDelegate(fpAcad);
                _ProgressCallbackFct pcbfpAcad = static_cast<_ProgressCallbackFct>(ip.ToPointer());

                ip = Marshal::GetFunctionPointerForDelegate(fpAhl);
                _ProgressCallbackFct pcbfpAhl = static_cast<_ProgressCallbackFct>(ip.ToPointer());

                pEngine->setAcisConversionProgressCallBack(pcbfpAcis);
                pEngine->setAcadConversionProgressCallBack(pcbfpAcad);
                pEngine->setAhlProgressCallBack(pcbfpAhl);
                    
                
            
                //force garbage collection cycle to prove that the delegate doesn't get disposed, so that our objects are kept alive until we come back to managed stack
                GC::Collect();
                Acad::ErrorStatus es =  pEngine->run(*pCollector);
                gch1.Free();
                gch2.Free();
                gch3.Free();
                return es;
                //return HlrRun(pEngine, pCollector);
            }

            void Engine::CleanHlrCache()
            {
                AsdkHlrEngine::cleanHlrCache();
            }

            void Engine::CleanHlrCache(Entity ^pEnt, Viewport ^pVp)
            {
                AsdkHlrEngine::cleanHlrCache(static_cast<AcDbEntity*>(pEnt->UnmanagedObject.ToPointer()),
                                             static_cast<AcDbViewport*>(pVp->UnmanagedObject.ToPointer()));
            }

            void Engine::CleanHlrCache(Entity ^pEnt, Point3d viewTarget, Vector3d viewDir)
            {
                AsdkHlrEngine::cleanHlrCache(static_cast<AcDbEntity*>(pEnt->UnmanagedObject.ToPointer()),
                                             *reinterpret_cast<AcGePoint3d*>(&(viewTarget)),
                                             *reinterpret_cast<AcGeVector3d*>(&(viewDir)));
            }
        }
    }
}
