
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "MainView.h"
#include "TitleDlgBar.h"
#include "MenuBar.h"
class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame() noexcept;
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CReBar      m_wndReBar;
	CTitleDlgBar  m_commonSetBar;
	CMenuBar m_menuBar;

	CStatusBar m_wndStatusBar;
	MainView* m_pMainView;
// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

};


