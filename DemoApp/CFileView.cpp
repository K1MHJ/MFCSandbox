// CFileView.cpp : implementation file
//

#include "pch.h"
#include "DemoApp.h"
#include "CFileView.h"


// CFileView

IMPLEMENT_DYNCREATE(CFileView, CFormView)

CFileView::CFileView()
	: CFormView(IDD_FILE_VIEW)
{

}

CFileView::~CFileView()
{
}

void CFileView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileView, CFormView)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CFileView diagnostics

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFileView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFileView message handlers


void CFileView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	TRACE("FileView OnSize %d %d\n", cx, cy);
}


BOOL CFileView::OnEraseBkgnd(CDC* pDC)
{
	//CRect rt;
	//pDC->GetClipBox(rt);
	//CBrush* oldbrush = (CBrush*)pDC->SelectStockObject(BLACK_BRUSH);
	//pDC->Rectangle(rt);
	//pDC->SelectObject(oldbrush);
	//return TRUE;
	return CFormView::OnEraseBkgnd(pDC);
}


BOOL CFileView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFileView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}
