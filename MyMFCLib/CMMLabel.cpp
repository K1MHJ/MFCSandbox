#include "pch.h"
#include "CMMLabel.h"
BEGIN_MESSAGE_MAP(CMMLabel, CStatic)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()
CMMLabel::CMMLabel() 
{
	m_hBrush = ::CreateSolidBrush(GetSysColor(COLOR_3DFACE));
	m_bMouseOn = FALSE;
	m_fontSize = 48;
	m_fontColor = RGB(0, 0, 0);
}
CMMLabel::~CMMLabel()
{
	::DeleteObject(m_hBrush);
}

int CMMLabel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	return 0;
}


void CMMLabel::OnDestroy()
{
	CStatic::OnDestroy();

	// TODO: Add your message handler code here
	m_font.DeleteObject();
}


HBRUSH CMMLabel::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  Change any attributes of the DC here
	if (CTLCOLOR_STATIC == nCtlColor)
	{
		pDC->SetBkMode(TRANSPARENT);
		//if (m_bMouseOn) pDC->SetTextColor(RGB(255, 0, 0));
		//else 
		pDC->SetTextColor(m_fontColor);
	}
	// TODO:  Return a non-NULL brush if the parent's handler should not be called
	return m_hBrush;
}


void CMMLabel::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_bMouseOn = TRUE;
	RedrawWindow();
	CStatic::OnMouseHover(nFlags, point);
}


void CMMLabel::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default
	m_bMouseOn = FALSE;
	RedrawWindow();
	CStatic::OnMouseLeave();
}


void CMMLabel::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	TRACKMOUSEEVENT tme;
	tme.cbSize = sizeof(tme);
	tme.hwndTrack = m_hWnd;
	tme.dwFlags = TME_LEAVE | TME_HOVER;
	tme.dwHoverTime = 1;
	TrackMouseEvent(&tme);
	CStatic::OnMouseMove(nFlags, point);
}


BOOL CMMLabel::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
	return CStatic::PreCreateWindow(cs);
}

static void SetNewFont(CFont* font, int size) 
{
	font->CreateFont(
		size, //size
		0, 0, 0, 
		FW_BOLD,//bold
		FALSE,//Italic
		0,//Underline
		0, 
		DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, 
		L"Garamond");
}
void CMMLabel::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	SetNewFont(&m_font, m_fontSize);
	this->SetFont(&m_font);
	CStatic::PreSubclassWindow();
}
void CMMLabel::SetFontSize(int size)
{
	m_fontSize = size;
	m_font.DeleteObject();
	SetNewFont(&m_font, m_fontSize);
	this->SetFont(&m_font);
	RedrawWindow();
}
void CMMLabel::SetFontColor(COLORREF color)
{
	m_fontColor = color;
	RedrawWindow();
}
