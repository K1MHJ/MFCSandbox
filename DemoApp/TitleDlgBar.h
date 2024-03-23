#pragma once
#include "CMMLabel.h"
class CTitleDlgBar : public CDialogBar
{
	DECLARE_DYNAMIC(CTitleDlgBar)
	CMMLabel m_label;
	CMMLabel m_label_ip;

public:
	CTitleDlgBar();
	virtual ~CTitleDlgBar();
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnInitDialog(WPARAM wParam, LPARAM lParam);
	virtual void DoDataExchange(CDataExchange* pDX);
};


