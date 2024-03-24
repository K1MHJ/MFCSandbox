#include "pch.h"
#include "CMMMenuButton.h"
BEGIN_MESSAGE_MAP(CMMMenuButton, CButton)
	ON_WM_DRAWITEM()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()

CMMMenuButton::CMMMenuButton()
{
    m_bChecked = FALSE;
}
CMMMenuButton::~CMMMenuButton()
{

}
void CMMMenuButton::SetCheck(BOOL check)
{
    m_bChecked = check;
}

void CMMMenuButton::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: Add your message handler code here and/or call default

	CButton::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


BOOL CMMMenuButton::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class

	return CButton::PreCreateWindow(cs);
}


int CMMMenuButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}


void CMMMenuButton::OnSize(UINT nType, int cx, int cy)
{
	CButton::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}


void CMMMenuButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CButton::OnMouseMove(nFlags, point);
}


void CMMMenuButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CButton::OnMouseHover(nFlags, point);
}


void CMMMenuButton::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default

	CButton::OnMouseLeave();
}


void CMMMenuButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect  rect = lpDrawItemStruct->rcItem;
	BOOL   bSelect = lpDrawItemStruct->itemState & ODS_SELECTED;
	BOOL   bFocus = lpDrawItemStruct->itemState & ODS_FOCUS;
    //ボタンの描画
    CBrush* pOrigBrush = NULL;
    CBrush   brush;

    brush.CreateSolidBrush(bSelect ? RGB(217, 219, 221) : RGB(236, 233, 233));
    pOrigBrush = pDC->SelectObject(&brush);
    pDC->Rectangle(rect);
    pDC->SelectObject(pOrigBrush);
    brush.DeleteObject();

    //境界の描画
    CPen* pOrigPen = NULL;
    CPen    lpen(PS_SOLID, 2, ::GetSysColor(COLOR_BTNFACE));
    CPen    dpen(PS_SOLID, 2, RGB(0, 0, 100));
    pOrigBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
    pOrigPen = pDC->SelectObject(bSelect ? &lpen : &dpen);

    pDC->Rectangle(rect);

    pDC->SelectObject(pOrigPen);
    pDC->SelectObject(pOrigBrush);

    lpen.DeleteObject();
    dpen.DeleteObject();

    //ボタン表題描画
    CFont* pOrigFont = NULL;
    //CFont   font;
    //font.CreatePointFont(80, _T("MS Gothic"));
    pOrigFont = pDC->SelectObject(m_font.Get());

    CString   str;
    GetWindowText(str);

    CSize     size(pDC->GetTextExtent(str));
    CPoint    point = rect.CenterPoint();
    size.cy += 20;
    point.y = size.cy / 2;
    size.cx = rect.Width() * 0.8;
    point.Offset(-1 * size.cx / 2, bSelect ? 0 : 1);
    CRect txtrect(point, size);
    pDC->SetBkMode(TRANSPARENT);

    brush.CreateSolidBrush(m_bChecked ? RGB(173, 255, 47) : RGB(169,169,169));
    pOrigBrush = pDC->SelectObject(&brush);
    pDC->RoundRect(txtrect, POINT{10,10});
    pDC->SelectObject(pOrigBrush);
    brush.DeleteObject();

    pDC->DrawText(str, &txtrect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    pDC->SelectObject(pOrigFont);
    //font.DeleteObject();
}


BOOL CMMMenuButton::Create(
    LPCTSTR lpszCaption, DWORD dwStyle, 
    const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    while (TRUE)
    {
        if (!CButton::Create(lpszCaption,
            WS_VISIBLE | WS_TABSTOP | WS_CHILD
            | BS_PUSHBUTTON | BS_OWNERDRAW,
            rect,
            pParentWnd,
            nID))
            break;
        return TRUE;
    }
    if (GetSafeHwnd() != NULL) DestroyWindow();
    return FALSE;
}


void CMMMenuButton::OnDestroy()
{
    CButton::OnDestroy();
    m_font.Delete();
}


void CMMMenuButton::PreSubclassWindow()
{
    // TODO: Add your specialized code here and/or call the base class
    m_font.Create(32, true);
    CButton::PreSubclassWindow();
}
