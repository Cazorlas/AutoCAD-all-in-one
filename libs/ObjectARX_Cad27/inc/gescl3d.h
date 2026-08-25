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
// DESCRIPTION:
//
// This file contains the class AcGeScale3d - a mathematical entity used to
// represents scaling transformations in 3-space.
// Contract:  The scale vector components must never be set to zero
// (or near zero within floating point tolerances).

#ifndef AC_GESCL3D_H
#define AC_GESCL3D_H

#include "adesk.h"
#include "gegbl.h"
#pragma pack (push, 8)

class AcGeMatrix3d;

class 
AcGeScale3d
{
public:
                    AcGeScale3d() = default;
                    AcGeScale3d(const AcGeScale3d& src) = default;
    GE_DLLEXPIMPORT AcGeScale3d(double factor);
    GE_DLLEXPIMPORT AcGeScale3d(double xFact, double yFact, double zFact);

    // The identity scaling operation.
    //
    GE_DLLDATAEXIMP static const   AcGeScale3d kIdentity;
             static AcGeScale3d    identity();

    // Multiplication.
    //
                    AcGeScale3d    operator *  (const AcGeScale3d& sclVec) const;
    GE_DLLEXPIMPORT AcGeScale3d&   operator *= (const AcGeScale3d& scl);
    GE_DLLEXPIMPORT AcGeScale3d&   preMultBy   (const AcGeScale3d& leftSide);
    GE_DLLEXPIMPORT AcGeScale3d&   postMultBy  (const AcGeScale3d& rightSide);
    GE_DLLEXPIMPORT AcGeScale3d&   setToProduct(const AcGeScale3d& sclVec1, const AcGeScale3d& sclVec2);
                    AcGeScale3d    operator *  (double factor) const;
    GE_DLLEXPIMPORT AcGeScale3d&   operator *= (double s);
    GE_DLLEXPIMPORT AcGeScale3d&   setToProduct(const AcGeScale3d& sclVec, double s);

    // Multiplicative inverse.
    //
                    AcGeScale3d    inverse        () const;
    GE_DLLEXPIMPORT AcGeScale3d&   invert         ();

    GE_DLLEXPIMPORT Adesk::Boolean isProportional(const AcGeTol& tol = AcGeContext::gTol) const;

    // Tests for equivalence using the infinity norm.
    //
                    bool operator == (const AcGeScale3d& sclVec) const;
                    bool operator != (const AcGeScale3d& sclVec) const;
    GE_DLLEXPIMPORT bool isEqualTo   (const AcGeScale3d& scaleVec,
                      const AcGeTol& tol = AcGeContext::gTol) const;

    // For convenient access to the data.
    //
                    double         operator [] (unsigned int i) const;
                    double&        operator [] (unsigned int i);
    GE_DLLEXPIMPORT AcGeScale3d&   set         (double sc0, double sc1, double sc2);

    // Conversion to/from matrix form.
    //
    GE_DLLEXPIMPORT operator       AcGeMatrix3d   () const;
    GE_DLLEXPIMPORT void getMatrix(AcGeMatrix3d& mat) const;
    GE_DLLEXPIMPORT AcGeScale3d&   extractScale   ( const AcGeMatrix3d& mat );
    GE_DLLEXPIMPORT AcGeScale3d&   removeScale    ( AcGeMatrix3d& mat );

    // The scale components in x, y and z.
    //
    double         sx {1.0}, sy {1.0}, sz {1.0};
};

// Same as default ctor, creates the identity scale vector.
//
inline AcGeScale3d AcGeScale3d::identity()
{
    return AcGeScale3d();
}

// Returns a scale vector that is equal to `this vector' times `s'.
//
inline AcGeScale3d AcGeScale3d::operator * (const AcGeScale3d& s) const
{
    return AcGeScale3d(s.sx * sx, s.sy * sy, s.sz * sz);
}

inline AcGeScale3d AcGeScale3d::operator *  (double factor) const
{
    return AcGeScale3d(factor * sx, factor * sy, factor * sz);
}

// global operator
inline AcGeScale3d operator * (double factor, const AcGeScale3d& scl)
{
    return AcGeScale3d(factor * scl.sx, factor * scl.sy, factor * scl.sz);
}

inline AcGeScale3d AcGeScale3d ::inverse() const
{
    return AcGeScale3d(1.0 / sx, 1.0 / sy, 1.0 / sz);
}

inline bool
AcGeScale3d::operator == (const AcGeScale3d& s) const
{
    return this->isEqualTo(s);
}

// This operator is the logical negation of the `==' operator.
//
inline bool
AcGeScale3d::operator != (const AcGeScale3d& s) const
{
    return !(this->isEqualTo(s));
}

// Indexes the scale vector as if it were an array.  `sx' is index `0',
// `sy' is index `1' and `sz' is index `2'.
//
inline double
AcGeScale3d::operator [] (unsigned int i) const
{
    return *(&sx+i);
}

inline double&
AcGeScale3d::operator [] (unsigned int i)
{
    return *(&sx+i);
}

#pragma pack (pop)
#endif
