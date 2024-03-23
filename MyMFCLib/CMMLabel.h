#pragma once
#include <afxwin.h>
class CMMLabel :
    public CStatic
{
    CFont m_font;
    HBRUSH m_hBrush;
    BOOL m_bMouseOn;
    int m_fontSize;
    COLORREF m_fontColor;
public:
    CMMLabel();
    ~CMMLabel();
    void SetFontSize(int size);
    void SetFontColor(COLORREF color);
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
    afx_msg void OnMouseHover(UINT nFlags, CPoint point);
    afx_msg void OnMouseLeave();
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual void PreSubclassWindow();
};

