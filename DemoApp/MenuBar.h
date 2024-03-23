#pragma once


// CMenuBar

class CMenuBar : public CDialogBar
{
	DECLARE_DYNAMIC(CMenuBar)

public:
	CMenuBar();
	virtual ~CMenuBar();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateCmdUI(CCmdUI* pCmdUI);
	afx_msg void OnBnClickedMenu1_Btn();
	afx_msg void OnBnClickedMenu2_Btn();
};


