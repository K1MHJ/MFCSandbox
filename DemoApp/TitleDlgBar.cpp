#include "pch.h"
#include "DemoApp.h"
#include "TitleDlgBar.h"
IMPLEMENT_DYNAMIC(CTitleDlgBar, CDialogBar)

CTitleDlgBar::CTitleDlgBar()
{

}

CTitleDlgBar::~CTitleDlgBar()
{
}


BEGIN_MESSAGE_MAP(CTitleDlgBar, CDialogBar)
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)
END_MESSAGE_MAP()



// CTitleDlgBar message handlers
LRESULT CTitleDlgBar::OnInitDialog(WPARAM wParam, LPARAM lParam)
{
	// <-- with these lines. -->
	//BOOL bRet = HandleInitDialog(wParam, lParam);
	UpdateData(FALSE);

	m_label.SetFontSize(48);
	m_label.SetFontColor(RGB(65, 105, 225));
	m_label_ip.SetFontSize(24);
	m_label_ip.SetFontColor(RGB(65,105,225));
	if (!UpdateData(FALSE))
	{
		TRACE0("Warning: UpdateData failed during dialog init.\n");
	}
	return 0;
}
void CTitleDlgBar::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LABEL_ICON, m_label);
	DDX_Control(pDX, IDC_LABEL_IP, m_label_ip);
}
