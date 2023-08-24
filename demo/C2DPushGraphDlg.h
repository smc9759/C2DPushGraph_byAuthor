// C2DPushGraphDlg.h : header file
//

#if !defined(AFX_C2DPUSHGRAPHDLG_H__5DA8DE2F_4425_4D78_9F70_9B7A07C12ABB__INCLUDED_)
#define AFX_C2DPUSHGRAPHDLG_H__5DA8DE2F_4425_4D78_9F70_9B7A07C12ABB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "2DPushGraph.h"

/////////////////////////////////////////////////////////////////////////////
// CC2DPushGraphDlg dialog

class CC2DPushGraphDlg : public CDialog
{
// Construction
public:
	CC2DPushGraphDlg(CWnd* pParent = NULL);	// standard constructor	


// Dialog Data
	//{{AFX_DATA(CC2DPushGraphDlg)
	enum { IDD = IDD_C2DPUSHGRAPH_DIALOG };
	int		m_nGridSize;
	BOOL	m_bShowGrid;
	BOOL	m_bShowLabels;
	short	m_sInterval;
	int		m_nWaitTime;
	CString	m_strMaxLabel;
	int		m_nMaxPeek;
	CString	m_strMinLabel;
	int		m_nMinPeek;
	BOOL	m_bLine0AsBar;
	BOOL	m_bLine1AsBar;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC2DPushGraphDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CC2DPushGraphDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnOK();
	afx_msg void OnTextColor();
	afx_msg void OnGridColor();
	afx_msg void OnBGColor();
	afx_msg void OnLine0Color();
	afx_msg void OnLine1Color();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	C2DPushGraph m_PushGraph;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C2DPUSHGRAPHDLG_H__5DA8DE2F_4425_4D78_9F70_9B7A07C12ABB__INCLUDED_)
