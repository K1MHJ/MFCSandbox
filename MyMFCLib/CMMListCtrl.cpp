#include "pch.h"
#include "CMMListCtrl.h"


void CMMListCtrl::PreSubclassWindow()
{
	//// TODO: Add your specialized code here and/or call the base class
	//ModifyStyle(0, LVS_OWNERDRAWFIXED, SWP_FRAMECHANGED);

	CHeaderCtrl* pCtrl = GetHeaderCtrl();
	HWND hWnd = (HWND) ::SendMessage(m_hWnd, LVM_GETHEADER, 0, 0);


	pCtrl->ModifyStyle(0, LVS_OWNERDRAWFIXED, SWP_FRAMECHANGED);

	m_headerCtrl.SubclassWindow(hWnd);

	CListCtrl::PreSubclassWindow();
}
