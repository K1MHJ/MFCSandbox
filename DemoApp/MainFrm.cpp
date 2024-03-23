
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "DemoApp.h"
#include "MainFrm.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a view to occupy the client area of the frame
	m_commonSetBar.Create(this, MAKEINTRESOURCE(IDD_DIALOGBAR), CBRS_TOP, IDD_DIALOGBAR);
	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_commonSetBar))
	{
		TRACE0("failed to create rebar\n");
		return -1;      // fail to create
	}
	ShowControlBar(&m_wndReBar, TRUE, FALSE);

	//m_wndDlgBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndDlgBar);
	m_menuBar.Create(this, MAKEINTRESOURCE(IDD_MENUBAR), CBRS_LEFT, IDD_MENUBAR);
	ShowControlBar(&m_menuBar, TRUE, FALSE);

	CCreateContext ccx;
	ccx.m_pNewViewClass = RUNTIME_CLASS(MainView);
	CWnd* wnd = this->CreateView(&ccx);
	m_pMainView = DYNAMIC_DOWNCAST(MainView, wnd);
	m_pMainView->ShowWindow(SW_SHOW);
	m_pMainView->OnInitialUpdate();
	SetActiveView(m_pMainView);
	m_pMainView->ResizeParentToFit(FALSE);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.cx = 600;
	cs.cy = 400;
	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_SYSMENU;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
	m_pMainView->SetFocus();
}
