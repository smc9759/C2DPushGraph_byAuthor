// C2DPushGraph.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "C2DPushGraph.h"
#include "C2DPushGraphDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC2DPushGraphApp

BEGIN_MESSAGE_MAP(CC2DPushGraphApp, CWinApp)
	//{{AFX_MSG_MAP(CC2DPushGraphApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC2DPushGraphApp construction

CC2DPushGraphApp::CC2DPushGraphApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CC2DPushGraphApp object

CC2DPushGraphApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CC2DPushGraphApp initialization

BOOL CC2DPushGraphApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CC2DPushGraphDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

