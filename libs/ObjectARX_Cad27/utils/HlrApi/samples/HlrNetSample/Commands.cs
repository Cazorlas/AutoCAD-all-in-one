//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Text;

using Autodesk.AutoCAD.Runtime;
using Autodesk.AutoCAD.ApplicationServices;
using Autodesk.AutoCAD.DatabaseServices;
using Autodesk.AutoCAD.EditorInput;
using Autodesk.AutoCAD.Geometry;
using Autodesk.AutoCAD.HLR;

[assembly: ExtensionApplication(null)]
[assembly: CommandClass(typeof(HlrNetSample.MyCommands))]

namespace HlrNetSample {

    
    public class MyCommands {

        [CommandMethod("test")]
        public void Test() {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("Hello World!\n");
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;

            PromptSelectionResult res = Application.DocumentManager.MdiActiveDocument.Editor.GetSelection();
            if (res.Status != PromptStatus.OK )
                return ;

            Collector collector = new Collector
            {
                DeleteState = true
            };
            ObjectId [] ids =res.Value.GetObjectIds ();
            for ( int i =0 ; i < ids.Length ; i++ )
                collector.AddEntity (ids [0]) ;

            // Get current viewport settings
            Point3d tmpt = (Point3d)Application.GetSystemVariable("viewdir"); //new Vector3d(1,1,1);
            //transform UCS to WCS;
            Vector3d viewdir = tmpt.TransformBy(ed.CurrentUserCoordinateSystem).GetAsVector();
            Point3d target = (Point3d)Application.GetSystemVariable("target"); //new Point3d(0, 0, 0);
            //transform UCS to WCS
            target = target.TransformBy(ed.CurrentUserCoordinateSystem);


            // Process hidden line removal

            Engine hlr =new Engine (
                target, viewdir,
                (int)(Control.Entity | Control.Block| Control.Subentity | Control.ShowAll | Control.MeshSilhouettes | Control.Progress)
            ) ;
            hlr.Run (collector) ;

            //- Assign color to the resulting entities
            //- red for visible edges
            //- blue for non-visible edges
            //- yellow for internal edges
            Database db =Application.DocumentManager.MdiActiveDocument.Database ;
            Transaction tr =Application.DocumentManager.MdiActiveDocument.TransactionManager.StartTransaction () ;
            try {
                BlockTable bt = (BlockTable)tr.GetObject (db.BlockTableId, OpenMode.ForRead) ;
                BlockTableRecord ms = (BlockTableRecord)tr.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForWrite) ;

                int n =collector.OutputDataLength ;
                for (int i = 0; i < n; i++) {
                    Data p = collector.OutputData(i);

                    Entity pEnt = p.ResultEntity;
                    Autodesk.AutoCAD.HLR.Visibility vis = p.EntityVisibility;
                    if (vis == Autodesk.AutoCAD.HLR.Visibility.Visible) {
                        pEnt.ColorIndex = 1; //----- Red
                    } else if (vis == Autodesk.AutoCAD.HLR.Visibility.InternallyHidden) {
                        if ( p.HlrVisibility == Autodesk.AutoCAD.HLR.Visibility.Visible)
                            pEnt.ColorIndex = 2; //----- Yellow
                        else
                            pEnt.ColorIndex = 3; //----- Green
                    } else {
                        pEnt.ColorIndex = 5; //----- Blue
                    }

                    ms.AppendEntity (pEnt) ; 
                    tr.AddNewlyCreatedDBObject (pEnt, true) ;

                }
                tr.Commit () ;
            } catch (System.Exception) {
                tr.Abort () ;
            } finally {
                tr.Dispose () ;
            }
        }

    }

}
