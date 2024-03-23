#pragma once
#include <afxcmn.h>
class CMMHeaderCtrl :
    public CHeaderCtrl
{
    void DrawHeader(CDC* pDC, CRect Rt, COLORREF rgb1, COLORREF rgb2);
public:
    DECLARE_MESSAGE_MAP()
    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


