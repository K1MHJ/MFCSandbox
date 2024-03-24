#pragma once
#include "CMMMenuButton.h"
// CMenuBar
class CMenuBar : public CDialogBar
{
	DECLARE_DYNAMIC(CMenuBar)
	CMMMenuButton m_btn[2];
public:
	CMenuBar();
	virtual ~CMenuBar();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnInitDialog(WPARAM wParam, LPARAM lParam);
	afx_msg void OnUpdateCmdUI(CCmdUI* pCmdUI);
	afx_msg void OnBnClickedMenu1_Btn();
	afx_msg void OnBnClickedMenu2_Btn();
	virtual void DoDataExchange(CDataExchange* pDX);
};


