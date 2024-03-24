// MainView.cpp : implementation file
//

#include "pch.h"
#include "DemoApp.h"
#include "MainView.h"


// MainView

IMPLEMENT_DYNCREATE(MainView, CFormView)

MainView::MainView()
	: CFormView(IDD_FORMVIEW)
{

}

MainView::~MainView()
{
}

void MainView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MainView, CFormView)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// MainView diagnostics

#ifdef _DEBUG
void MainView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void MainView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// MainView message handlers


void MainView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	
}


void MainView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	TRACE("MainView OnSize %d %d\n", cx, cy);
}


BOOL MainView::OnEraseBkgnd(CDC* pDC)
{
	//CRect rt;
	//pDC->GetClipBox(rt);
	//CBrush* oldbrush = (CBrush*)pDC->SelectStockObject(WHITE_BRUSH);
	//pDC->Rectangle(rt);
	//pDC->SelectObject(oldbrush);
	//return TRUE;
	return CFormView::OnEraseBkgnd(pDC);
}


BOOL MainView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
