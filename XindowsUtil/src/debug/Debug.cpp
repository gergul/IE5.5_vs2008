
#include "stdafx.h"
#include "Debug.h"

#include <OleCtl.h>
#include <atlbase.h>

#ifdef _DEBUG
BOOL XindowsAssertFailedLine(LPCSTR lpszFileName, int nLine, LPCSTR lpszExpression)
{
	MSG msg;
	BOOL bQuit = PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
	BOOL bResult = _CrtDbgReport(_CRT_ASSERT, lpszFileName, nLine, NULL, "%s", lpszExpression);
	if(bQuit)
	{
#pragma warning(push)
#pragma warning(disable : 4244)
		PostQuitMessage(msg.wParam);
#pragma warning(pop)
	}
	return bResult;
}

void XindowsTrace(LPCTSTR lpszFormat, ...)
{
	va_list args;
	va_start(args, lpszFormat);

	int nBuf;
	TCHAR szBuffer[512];

#pragma warning(push)
#pragma warning(disable : 4996)
	nBuf = _vsntprintf(szBuffer, ARRAYSIZE(szBuffer), lpszFormat, args);
#pragma warning(pop)

	// was there an error? was the expanded string too long?
	Assert(nBuf >= 0);

	OutputDebugString(szBuffer);

	va_end(args);
}

//+---------------------------------------------------------------------------
//
//  Function:   DbgExCheckAndReturnResultList
//
//  Synopsis:   Issues a warning if the HRESULT indicates failure, and asserts
//              if the HRESULT is not a permitted success code.
//
//  Arguments:  [hr]        -- the HRESULT to be checked.
//              [pstrFile]  -- the file where the HRESULT is being checked.
//              [line]      -- the line in the file where the HRESULT is
//                                  being checked.
//              [cSuccess]  -- the number of permitted non-zero success codes
//                               or failure SCODES that should not be traced.
//              [...]       -- list of HRESULTS.
//
//  Returns:    The return value is exactly the HRESULT passed in.
//
//  Notes:      This function should not be used directly.  Use
//              the SRETURN and RRETURN macros instead.
//
// HRESULTs passed in should either be permitted success codes, permitted
// non-OLE error codes, or expected OLE error codes.  Expected OLE error codes
// prevent a warning from being printed to the debugger, while the rest cause
// asserts if they're not given as an argument.
//
// An OLE error code has a facility not equal to FACILITY_ITF or is equal to
// FACILITY_ITF and the code is less than the current maximum value used.
//
//----------------------------------------------------------------------------
HRESULT DbgExCheckAndReturnResultList(HRESULT hr, BOOL fTrace, LPSTR pstrFile, UINT line, int cHResult, va_list va)
{
	BOOL    fOLEError;
	BOOL    fOLEDBError;
	BOOL    fOKReturnCode;
	int     i;
	HRESULT hrArg;

	// These xxx_E_LAST hresults are the highest-valued ones in FACILITY_ITF
	// currently (at the time of coding).  These asserts should alert us if
	// the numbers change, and our usage of CONNECT_E_LAST is no longer valid.
	Assert(HRESULT_CODE(CONNECT_E_LAST) == HRESULT_CODE(SELFREG_E_LAST));
	Assert(HRESULT_CODE(CONNECT_E_LAST) == HRESULT_CODE(PERPROP_E_LAST));

	// Check if code is a permitted error or success.
	fOLEError = (hr<0 &&
		(HRESULT_FACILITY(hr)!=FACILITY_ITF || HRESULT_CODE(hr)<HRESULT_CODE(CONNECT_E_LAST)));

	// Codes 0x0e00-0x0eff are reserved for the OLE DB group of
	// interfaces.  (So sayeth <oledberr.h>)
	fOLEDBError = HRESULT_FACILITY(hr)==FACILITY_ITF &&
		0x0E00<=HRESULT_CODE(hr) && HRESULT_CODE(hr)<=0x0EFF;

	fOKReturnCode = ((cHResult==-1) || fOLEError || fOLEDBError || (hr==S_OK));

	if(cHResult > 0)
	{
		for(i=0; i<cHResult; i++)
		{
			hrArg = va_arg(va, HRESULT);
			if(hr == hrArg)
			{
				fOKReturnCode = TRUE;

				if(fOLEError)
				{
					fTrace = FALSE;
				}

				break;
			}
		}
	}

    USES_CONVERSION;

	// Assert on non-permitted success code.
	if(!fOKReturnCode)
	{
		Trace3("%s:%d returned unpermitted HRESULT hr=%x\n", A2T(pstrFile), line, hr);
		AssertLocSz(hr<=0, pstrFile, line,
			"An unpermitted success code was returned.\n");
		AssertLocSz(!(HRESULT_FACILITY(hr)==FACILITY_ITF && HRESULT_CODE(hr)>=0x0200), pstrFile, line,
			"An unpermitted FACILITY_ITF HRESULT was returned.\n");
	}

	// Warn on error result.
	if(fTrace && FAILED(hr))
	{
		Trace3("RRETURN: %s:%d returned hr=%x\n", A2T(pstrFile), line, hr);
	}

	return hr;
}

HRESULT __cdecl DbgExCheckAndReturnResult(HRESULT hr, BOOL fTrace, LPSTR pstrFile, UINT line, int cHResult, ...)
{
	HRESULT hrResult;
	va_list va;

	va_start(va, cHResult);
	hrResult = DbgExCheckAndReturnResultList(hr, fTrace, pstrFile, line, cHResult, va);
	va_end(va);

	return hrResult;
}
#endif //_DEBUG