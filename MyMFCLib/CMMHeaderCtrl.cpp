#include "pch.h"
#include "CMMHeaderCtrl.h"

void CMMHeaderCtrl::DrawHeader(CDC* pDC, CRect Rt, COLORREF rgb1, COLORREF rgb2)
{
	if (pDC)
	{
		TRIVERTEX m_Vert[2];
		m_Vert[0].x = Rt.left;
		m_Vert[0].y = Rt.top;
		m_Vert[0].Red	= GetRValue(rgb1) << 8;
		m_Vert[0].Green	= GetGValue(rgb1) << 8;
		m_Vert[0].Blue	= GetBValue(rgb1) << 8;
		m_Vert[0].Alpha	= 0;

		//End Gradient Info
		m_Vert[1].x = Rt.right;
		m_Vert[1].y = Rt.bottom;
		m_Vert[1].Red	= GetRValue(rgb2) << 8;
		m_Vert[1].Green	= GetGValue(rgb2) << 8;
		m_Vert[1].Blue	= GetBValue(rgb2) << 8;
		m_Vert[1].Alpha	= 0;

		GRADIENT_RECT gRt;

		gRt.UpperLeft	= 0;
		gRt.LowerRight	= 1;

		GradientFill(pDC->m_hDC, m_Vert, 2, &gRt, 1, GRADIENT_FILL_RECT_V);
		CPen pen(PS_SOLID, 1, RGB(24, 52, 76));

		CPen* pOld = pDC->SelectObject(&pen);
	}
}
BEGIN_MESSAGE_MAP(CMMHeaderCtrl, CHeaderCtrl)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


void CMMHeaderCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CHeaderCtrl::OnPaint() for painting messages
	int nItemCount = GetItemCount();
	int nStart = 0;
	for (int iter = 0; iter < nItemCount; iter++)
	{
		CRect rt;
		HDITEM item;
		memset(&item, 0, sizeof(item));
		TCHAR buf1[256];
		item.mask = HDI_TEXT | HDI_FORMAT | HDI_ORDER | HDI_WIDTH;
		item.pszText = buf1;
		item.cchTextMax = 255;
		GetItemRect(iter, rt);
		GetItem(iter, &item);
		rt.left = nStart;
		rt.right = rt.left + item.cxy;
		nStart = rt.right;
		DrawHeader(&dc, rt, RGB(4, 92, 207), RGB(20, 46, 80));
		dc.SetBkMode(TRANSPARENT);
		dc.SelectObject(GetFont());
		dc.SetTextColor(RGB(230, 220, 230));
		dc.MoveTo(rt.right - 1, rt.top);
		dc.LineTo(rt.right - 1, rt.bottom);
		if (item.pszText)
		{
			dc.DrawText(CString(item.pszText), rt, DT_SINGLELINE | DT_WORD_ELLIPSIS);
		}
	}
}


BOOL CMMHeaderCtrl::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	CRect rt;
	pDC->GetClipBox(rt);
	DrawHeader(pDC, rt, RGB(4, 92, 207), RGB(20, 46, 80));
	return TRUE;//CHeaderCtrl::OnEraseBkgnd(pDC);
}
