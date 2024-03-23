#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.

#include "CMMTopView.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMMTopView

IMPLEMENT_DYNCREATE(CMMTopView, CFormView)

BEGIN_MESSAGE_MAP(CMMTopView, CFormView)
END_MESSAGE_MAP()

// CMMTopView construction/destruction

CMMTopView::CMMTopView() noexcept
	: CFormView(101)
{
	// TODO: add construction code here

}

CMMTopView::~CMMTopView()
{
}

void CMMTopView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMMTopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMMTopView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	
}


// CMMTopView diagnostics

#ifdef _DEBUG
void CMMTopView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMMTopView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CMMTopView message handlers
