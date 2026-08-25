//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2026 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////


#pragma once
#include "aduiPathname.h"
#include "AcCoreDefs.h"
#include "aduipathenums.h"

#pragma pack (push, 8)

//Forward declarations.
class AFILE;

class CAcUiPathname : public CAdUiPathname {

public:

    friend class AcSearchPathBase;

// methods
        // constructor (initializes private data)
        ACCORE_PORT CAcUiPathname(void);
        ACCORE_PORT CAcUiPathname(const CAcUiPathname&);

        // destructor (frees allocated storage)
        ACCORE_PORT ~CAcUiPathname(void);

        // parse a string, validate the format and fill in the data
        //  This routine actually calls ParseRelative() with the app's
        //  "start in" directory as the relpath arg
        //
        ACCORE_PORT PathErr Parse(const wchar_t*, bool wildcard_ok = false,
                                  bool skipIO = false) override;

        // check status for the path
        //  the returned values are defined in aduipathenums.h
        ACCORE_PORT int Status(void);

        // takes a path and tries to open it.  Return TRUE if
        //  the open succeeded, FALSE otherwise.  Note that
        //  these routines set the current directory to the
        //  appropriate place before opening, and reset it
        //  afterward.
        ACCORE_PORT bool Open(AFILE** fdp, const wchar_t *openmode);

        // create an assignment operator that does the right thing.
        const CAcUiPathname& operator=(const CAcUiPathname& pathSrc);
        const CAcUiPathname& operator=(const CAcUiPathname* pathSrc);
        
protected:
        // the guts of the assignment operator
        ACCORE_PORT virtual void AssignCopy( const CAcUiPathname& );
    
};

inline const CAcUiPathname& CAcUiPathname::operator=(const CAcUiPathname& pathSrc)
{
    AssignCopy( pathSrc);

    return *this;
}

inline const CAcUiPathname& CAcUiPathname::operator=(const CAcUiPathname* pathSrc)
{
    AssignCopy( *pathSrc);

    return *this;
}

// Legacy deprecated buffer-based path split.  Will be removed eventually.
// Clients should use the AcString-based function in aduiPathname.h
// or better yet, use std::filename::path::parent_path(), stem() and extension()
//
inline bool acedFNSplit(const wchar_t *pathToSplit,
                        wchar_t *prebuf, size_t nPreBufLen,
                        wchar_t *namebuf, size_t nNameBufLen,
                        wchar_t *extbuf, size_t nExtBufLen)
{
    AcString sPrefix, sName, sExt;
    if (!acutFNSplit(pathToSplit, prebuf ? &sPrefix : nullptr,
                     namebuf ? &sName : nullptr, extbuf ? &sExt : nullptr))
        return false;

    auto pCopyToBuf = [](AcString & str, wchar_t *pBuf, size_t nBufLen)
    {
        if (pBuf == nullptr)            // if buf ptr arg is null
            return (nBufLen == 0);      // then we expect size arg to be zero
        for (int i = 0; ; i++) {        // basically just do a wcscpy here
            if (i >= nBufLen)
                return false;           // path component doesn't fit in buffer
            pBuf[i] = str[i];
            if (pBuf[i] == 0)
                return true;            // done copying
        }
    };
    return pCopyToBuf(sPrefix, prebuf, nPreBufLen) &&
        pCopyToBuf(sName, namebuf, nNameBufLen) && pCopyToBuf(sExt, extbuf, nExtBufLen);
}

// Templates for using the legacy buffer-based API.  Deprecated.
// Please migrate away from these to using AcStrings or std::filesystem::path
//

template<size_t nPreBufLen, size_t nNameBufLen, size_t nExtBufLen> inline int
        acedFNSplit(const wchar_t *pathToSplit,
                    wchar_t (& prebuf) [nPreBufLen],
                    wchar_t (& namebuf)[nNameBufLen],
                    wchar_t (& extbuf) [nExtBufLen])
{
    return ::acedFNSplit(pathToSplit, prebuf, nPreBufLen, namebuf, nNameBufLen,
                         extbuf, nExtBufLen);
}

// Invoked by acedFNSplit(path, nullptr, nullptr, extbuf);
template<size_t nExtBufLen> inline bool acedFNSplit(const wchar_t *pathToSplit,
                                size_t nPre,
                                size_t nName,
                                wchar_t (& extbuf)[nExtBufLen])
{
    return ::acedFNSplit(pathToSplit, nullptr, nPre, nullptr, nName, extbuf, nExtBufLen);
}

// Invoked by acedFNSplit(path, nullptr, namebuf, extbuf);
template<size_t nNameBufLen, size_t nExtBufLen> inline bool acedFNSplit(
                                const wchar_t *pathToSplit,
                                size_t nPre,
                                wchar_t (& namebuf)[nNameBufLen],
                                wchar_t (& extbuf)[nExtBufLen])
{
    return ::acedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, extbuf, nExtBufLen);
}

// Invoked by acedFNSplit(path, prebuf, nullptr, nullptr);
template<size_t nPreBufLen> inline bool acedFNSplit(const wchar_t *pathToSplit,
                                wchar_t (& prebuf)[nPreBufLen],
                                size_t nName,
                                size_t nExt)
{
    return ::acedFNSplit(pathToSplit, prebuf, nPreBufLen, nullptr, nName, nullptr, nExt);
}
#pragma pack (pop)

