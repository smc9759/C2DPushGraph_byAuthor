// C2DPushGraph.h : main header file for the C2DPUSHGRAPH application
//

#if !defined(AFX_C2DPUSHGRAPH_H__9D7E4264_F5DC_49F8_8A95_B0ADB62CFEDC__INCLUDED_)
#define AFX_C2DPUSHGRAPH_H__9D7E4264_F5DC_49F8_8A95_B0ADB62CFEDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CC2DPushGraphApp:
// See C2DPushGraph.cpp for the implementation of this class
//

class CC2DPushGraphApp : public CWinApp
{
public:
	CC2DPushGraphApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC2DPushGraphApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CC2DPushGraphApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C2DPUSHGRAPH_H__9D7E4264_F5DC_49F8_8A95_B0ADB62CFEDC__INCLUDED_)
