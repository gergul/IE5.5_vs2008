
#ifndef __XINDOWSUTIL_DEBUG_H__
#define __XINDOWSUTIL_DEBUG_H__

#include <crtdbg.h>

//--------------------------------------------------------------------------
// Assert, Verify && WHEN_DBG
//--------------------------------------------------------------------------
#ifdef _DEBUG
XINDOWS_PUBLIC BOOL XindowsAssertFailedLine(LPCSTR lpszFileName, int nLine, LPCSTR lpszExpression);
XINDOWS_PUBLIC void XindowsTrace(LPCTSTR lpszFormat, ...);

#define THIS_FILE	   __FILE__
#define Assert(f) \
	do \
{ \
	if(!(f) && XindowsAssertFailedLine(THIS_FILE, __LINE__, #f)) \
		_CrtDbgBreak(); \
} while(0)

#define AssertSz(f, sz) \
	do \
{ \
	if(!(f) && XindowsAssertFailedLine(THIS_FILE, __LINE__, sz)) \
	_CrtDbgBreak(); \
} while(0)

#define AssertLocSz(f, File, Line, sz) \
	do \
{ \
	if(!(f) && XindowsAssertFailedLine(File, Line, sz)) \
		_CrtDbgBreak(); \
} while (0)

#define Verify(f)				Assert(f)
#define DEBUG_ONLY(f)			f
#define Trace(x)				XindowsTrace x
#define Trace0(sz)				XindowsTrace(TEXT("%s"), TEXT(sz))
#define Trace1(sz, p1)			XindowsTrace(TEXT(sz), p1)
#define Trace2(sz, p1, p2)      XindowsTrace(TEXT(sz), p1, p2)
#define Trace3(sz, p1, p2, p3)  XindowsTrace(TEXT(sz), p1, p2, p3)
#else // !_DEBUG
#define Assert(f)
#define AssertSz(x, sz)
#define AssertLocSz(f, File, Line, sz)
#define Verify(f)				(f)
#define DEBUG_ONLY(f)
#define Trace(x)                0
#define Trace0(sz)
#define Trace1(sz, p1)
#define Trace2(sz, p1, p2)
#define Trace3(sz, p1, p2, p3)
#endif // _DEBUG

//+-------------------------------------------------------------------------
//  Return tracing
//--------------------------------------------------------------------------
#ifdef _DEBUG
XINDOWS_PUBLIC HRESULT __cdecl DbgExCheckAndReturnResult(HRESULT hr, BOOL fTrace, LPSTR pstrFile, UINT line, int cHResult, ...);

#define SRETURN(hr) \
    return DbgExCheckAndReturnResult((hr), TRUE, __FILE__, __LINE__, -1)
#define RRETURN(hr) \
	return DbgExCheckAndReturnResult((hr), TRUE, __FILE__, __LINE__, 0)
#define RRETURN1(hr, s1) \
	return DbgExCheckAndReturnResult((hr), TRUE, __FILE__, __LINE__, 1, (s1))
#define RRETURN2(hr, s1, s2) \
	return DbgExCheckAndReturnResult((hr), TRUE, __FILE__, __LINE__, 2, (s1), (s2))
#define RRETURN3(hr, s1, s2, s3) \
	return DbgExCheckAndReturnResult((hr), TRUE, __FILE__, __LINE__, 3, (s1), (s2), (s3))
#define RRETURN4(hr, s1, s2, s3, s4) \
	return DbgExCheckAndReturnResult((hr), TRUE, __FILE__, __LINE__, 4, (s1), (s2), (s3), (s4))

#define SRETURN_NOTRACE(hr) \
	return DbgExCheckAndReturnResult((hr), FALSE, __FILE__, __LINE__, -1)
#define RRETURN_NOTRACE(hr) \
	return DbgExCheckAndReturnResult((hr), FALSE, __FILE__, __LINE__, 0)
#define RRETURN1_NOTRACE(hr, s1) \
	return DbgExCheckAndReturnResult((hr), FALSE, __FILE__, __LINE__, 1, (s1))
#define RRETURN2_NOTRACE(hr, s1, s2) \
	return DbgExCheckAndReturnResult((hr), FALSE, __FILE__, __LINE__, 2, (s1), (s2))
#define RRETURN3_NOTRACE(hr, s1, s2, s3) \
	return DbgExCheckAndReturnResult((hr), FALSE, __FILE__, __LINE__, 3, (s1), (s2), (s3))
#define RRETURN4_NOTRACE(hr, s1, s2, s3, s4) \
	return DbgExCheckAndReturnResult((hr), FALSE, __FILE__, __LINE__, 4, (s1), (s2), (s3), (s4))
#else // !_DEBUG
#define SRETURN(hr)								return (hr)
#define RRETURN(hr)								return (hr)
#define RRETURN1(hr, s1)						return (hr)
#define RRETURN2(hr, s1, s2)					return (hr)
#define RRETURN3(hr, s1, s2, s3)				return (hr)
#define RRETURN4(hr, s1, s2, s3, s4)			return (hr)

#define SRETURN_NOTRACE(hr)						return (hr)
#define RRETURN_NOTRACE(hr)						return (hr)
#define RRETURN1_NOTRACE(hr, s1)				return (hr)
#define RRETURN2_NOTRACE(hr, s1, s2)			return (hr)
#define RRETURN3_NOTRACE(hr, s1, s2, s3)		return (hr)
#define RRETURN4_NOTRACE(hr, s1, s2, s3, s4)	return (hr)
#endif // _DEBUG

#endif //__XINDOWSUTIL_DEBUG_H__