// C2DPushGraphDlg.cpp : implementation file
//

#include "stdafx.h"
#include "C2DPushGraph.h"
#include "C2DPushGraphDlg.h"
#include "CpuUsage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PUSHGRAPH_SYSTEM_LINE    0
#define PUSHGRAPH_PROCESS_LINE   1

/////////////////////////////////////////////////////////////////////////////
// CC2DPushGraphDlg dialog

CC2DPushGraphDlg::CC2DPushGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CC2DPushGraphDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC2DPushGraphDlg)
	m_nGridSize = 15;
	m_bShowGrid = TRUE;
	m_bShowLabels = TRUE;
	m_sInterval = 5;
	m_nWaitTime = 250;
	m_strMaxLabel = _T("100%");
	m_nMaxPeek = 100;
	m_strMinLabel = _T("0%");
	m_nMinPeek = 0;
	m_bLine0AsBar = FALSE;
	m_bLine1AsBar = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC2DPushGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC2DPushGraphDlg)
	DDX_Text(pDX, IDC_GRIDSIZE, m_nGridSize);
	DDX_Check(pDX, IDC_SHOWGRID, m_bShowGrid);
	DDX_Check(pDX, IDC_SHOWLABELS, m_bShowLabels);
	DDX_Text(pDX, IDC_INTERVAL, m_sInterval);
	DDX_Text(pDX, IDC_WAITTIME, m_nWaitTime);
	DDV_MinMaxInt(pDX, m_nWaitTime, 25, 10000);
	DDX_Text(pDX, IDC_MAXLABEL, m_strMaxLabel);
	DDX_Text(pDX, IDC_MAXPEEK, m_nMaxPeek);
	DDX_Text(pDX, IDC_MINLABEL, m_strMinLabel);
	DDX_Text(pDX, IDC_MINPEEK, m_nMinPeek);
	DDX_Check(pDX, IDC_LINE0_BAR, m_bLine0AsBar);
	DDX_Check(pDX, IDC_LINE1_BAR, m_bLine1AsBar);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CC2DPushGraphDlg, CDialog)
	//{{AFX_MSG_MAP(CC2DPushGraphDlg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_TEXTCOLOR, OnTextColor)
	ON_BN_CLICKED(IDC_GRIDCOLOR, OnGridColor)
	ON_BN_CLICKED(IDC_BGCOLOR, OnBGColor)
	ON_BN_CLICKED(IDC_LINE0_COLOR, OnLine0Color)
	ON_BN_CLICKED(IDC_LINE1_COLOR, OnLine1Color)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC2DPushGraphDlg message handlers

BOOL CC2DPushGraphDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_PushGraph.CreateFromStatic(IDC_STATICGRAPH, this);	
	m_PushGraph.ModifyStyle(0, WS_THICKFRAME);	
	
	m_PushGraph.AddLine( PUSHGRAPH_SYSTEM_LINE,  RGB(0, 255, 0));
	m_PushGraph.AddLine( PUSHGRAPH_PROCESS_LINE, RGB(255, 255, 0));


	OnOK(); // Emulate an Update click

	return TRUE;
}


// ===================================================================

void CC2DPushGraphDlg::OnTimer(UINT nIDEvent) 
{
	static CCpuUsage cpu, cpu2;

	int nSystem_CPU_Usage  = cpu.GetCpuUsage();
	int nProcess_CPU_Usage = cpu2.GetCpuUsage(GetCurrentProcessId());

	m_PushGraph.Push(nSystem_CPU_Usage,  PUSHGRAPH_SYSTEM_LINE);
	m_PushGraph.Push(nProcess_CPU_Usage, PUSHGRAPH_PROCESS_LINE);	
	m_PushGraph.Update();

	CDialog::OnTimer(nIDEvent);
}


// ===================================================================

void CC2DPushGraphDlg::OnOK() 
{
	UpdateData();

	KillTimer(0);
	SetTimer(0, m_nWaitTime, NULL);
	
	m_PushGraph.ShowGrid( m_bShowGrid ? true : false );
	m_PushGraph.ShowLabels( m_bShowLabels ? true : false  );

	m_PushGraph.ShowAsBar(0, m_bLine0AsBar ? true : false );
	m_PushGraph.ShowAsBar(1, m_bLine1AsBar ? true : false );

	m_PushGraph.SetInterval( m_sInterval );
	m_PushGraph.SetGridSize( (USHORT)m_nGridSize );

	m_PushGraph.SetLabelForMax( m_strMaxLabel );
	m_PushGraph.SetLabelForMin( m_strMinLabel );

	m_PushGraph.SetPeekRange( m_nMinPeek, m_nMaxPeek );	
	
	
	m_PushGraph.RedrawWindow();
}


// ===================================================================

void CC2DPushGraphDlg::OnTextColor() 
{
	CColorDialog dlg(m_PushGraph.GetTextColor());

	if (dlg.DoModal() == IDOK)
	{
		m_PushGraph.SetTextColor(dlg.GetColor());
		m_PushGraph.RedrawWindow();
	}
}


// ===================================================================

void CC2DPushGraphDlg::OnGridColor() 
{
	CColorDialog dlg(m_PushGraph.GetGridColor());

	if (dlg.DoModal() == IDOK)
	{
		m_PushGraph.SetGridColor(dlg.GetColor());
		m_PushGraph.RedrawWindow();
	}
}


// ===================================================================

void CC2DPushGraphDlg::OnBGColor() 
{
	CColorDialog dlg(m_PushGraph.GetBGColor());

	if (dlg.DoModal() == IDOK)
	{
		m_PushGraph.SetBGColor(dlg.GetColor());
		m_PushGraph.RedrawWindow();
	}
}


// ===================================================================

void CC2DPushGraphDlg::OnLine0Color() 
{
	CColorDialog dlg(m_PushGraph.GetLineColor(0));

	if (dlg.DoModal() == IDOK)
	{
		m_PushGraph.SetLineColor(dlg.GetColor(), 0);
		m_PushGraph.RedrawWindow();
	}
}


// ===================================================================

void CC2DPushGraphDlg::OnLine1Color() 
{
	CColorDialog dlg(m_PushGraph.GetLineColor(1));

	if (dlg.DoModal() == IDOK)
	{
		m_PushGraph.SetLineColor(dlg.GetColor(), 1);
		m_PushGraph.RedrawWindow();
	}
}
