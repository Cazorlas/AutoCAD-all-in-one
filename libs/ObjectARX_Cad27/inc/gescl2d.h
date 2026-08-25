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
// This file contains the class AcGeScale2d - a mathematical entity used
// to represent scaling transformations in 2-space.
// Contract:  The scale vector components must never be set to zero
// (or near zero within floating point tolerances).

#ifndef AC_GESCL2D_H
#define AC_GESCL2D_H

#include "adesk.h"
#include "gegbl.h"
#pragma pack (push, 8)

class AcGeMatrix2d;
class AcGeScale3d;

class 
AcGeScale2d
{
public:
                    AcGeScale2d() = default;
                    AcGeScale2d(const AcGeScale2d& src) = default;
    GE_DLLEXPIMPORT AcGeScale2d(double factor);
    GE_DLLEXPIMPORT AcGeScale2d(double xFactor, double yFactor);

    // The identity scaling operation.
    //
    GE_DLLDATAEXIMP static const   AcGeScale2d kIdentity;
             static AcGeScale2d    identity();

    // Multiplication.
    //
                    AcGeScale2d    operator *  (const AcGeScale2d& sclVec) const;
    GE_DLLEXPIMPORT AcGeScale2d&   operator *= (const AcGeScale2d& scl);
    GE_DLLEXPIMPORT AcGeScale2d&   preMultBy   (const AcGeScale2d& leftSide);
    GE_DLLEXPIMPORT AcGeScale2d&   postMultBy  (const AcGeScale2d& rightSide);
    GE_DLLEXPIMPORT AcGeScale2d&   setToProduct(const AcGeScale2d& sclVec1, const AcGeScale2d& sclVec2);
                    AcGeScale2d    operator *  (double s) const;
    GE_DLLEXPIMPORT AcGeScale2d&   operator *= (double s);
    GE_DLLEXPIMPORT AcGeScale2d&   setToProduct(const AcGeScale2d& sclVec, double s);

    // Multiplicative inverse.
    //
                    AcGeScale2d    inverse        () const;
    GE_DLLEXPIMPORT AcGeScale2d&   invert         ();

    GE_DLLEXPIMPORT Adesk::Boolean isProportional(const AcGeTol& tol = AcGeContext::gTol) const;

    // Tests for equivalence using the infinity norm.
    //
                    bool operator == (const AcGeScale2d& sclVec) const;
                    bool operator != (const AcGeScale2d& sclVec) const;
    GE_DLLEXPIMPORT bool isEqualTo   (const AcGeScale2d& scaleVec,
                      const AcGeTol& tol = AcGeContext::gTol) const;

     // For convenient access to the data.
    //
                    double         operator [] (unsigned int i) const;
                    double&        operator [] (unsigned int i);
    GE_DLLEXPIMPORT AcGeScale2d&   set         (double sc0, double sc1);

    // Conversion to/from matrix form.
    //
    GE_DLLEXPIMPORT operator       AcGeMatrix2d   () const;
    GE_DLLEXPIMPORT void           getMatrix      (AcGeMatrix2d& mat) const;
    GE_DLLEXPIMPORT AcGeScale2d&   extractScale   ( const AcGeMatrix2d& mat );
    GE_DLLEXPIMPORT AcGeScale2d&   removeScale    ( AcGeMatrix2d& mat );

    // Cast up to 3d scale.
    //
    GE_DLLEXPIMPORT operator       AcGeScale3d    () const;

    // The scale components in x and y.
    //
    double         sx {1.0}, sy {1.0};
};

// Same as default ctor, creates the identity scale vector.
//
inline AcGeScale2d AcGeScale2d::identity()
{
    return AcGeScale2d();
}

// Returns a scale vector that is equal to `this vector' times `s'.
//
inline AcGeScale2d AcGeScale2d::operator * (const AcGeScale2d& s) const
{
    return AcGeScale2d(s.sx * sx, s.sy * sy);
}

inline AcGeScale2d AcGeScale2d::operator * (double factor) const
{
    return AcGeScale2d(factor * sx, factor * sy);
}

inline double
AcGeScale2d::operator [] (unsigned int i) const
{
    return *(&sx+i);
}

inline double&
AcGeScale2d::operator [] (unsigned int i)
{
    return *(&sx+i);
}

inline AcGeScale2d AcGeScale2d::inverse() const
{
    return AcGeScale2d(1.0 / sx, 1.0 / sy);
}

inline bool
AcGeScale2d::operator == (const AcGeScale2d& s) const
{
    return this->isEqualTo(s);
}

// This operator is the logical negation of the `==' operator.
//
inline bool
AcGeScale2d::operator != (const AcGeScale2d& s) const
{
    return !this->isEqualTo(s);
}

// Global operator
//
inline AcGeScale2d operator * (double factor, const AcGeScale2d& scl)
{
    return AcGeScale2d(factor * scl.sx, factor * scl.sy);
}

#pragma pack (pop)
#endif
