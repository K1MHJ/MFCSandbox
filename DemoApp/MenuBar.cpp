// MenuBar.cpp : implementation file
//

#include "pch.h"
#include "DemoApp.h"
#include "MenuBar.h"


// CMenuBar

IMPLEMENT_DYNAMIC(CMenuBar, CDialogBar)

CMenuBar::CMenuBar()
{

}

CMenuBar::~CMenuBar()
{
}


BEGIN_MESSAGE_MAP(CMenuBar, CDialogBar)
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)
	ON_UPDATE_COMMAND_UI(IDC_MENU_BTN1, CMenuBar::OnUpdateCmdUI)
	ON_UPDATE_COMMAND_UI(IDC_MENU_BTN2, CMenuBar::OnUpdateCmdUI)
	ON_BN_CLICKED(IDC_MENU_BTN1, &CMenuBar::OnBnClickedMenu1_Btn)
	ON_BN_CLICKED(IDC_MENU_BTN2, &CMenuBar::OnBnClickedMenu2_Btn)
END_MESSAGE_MAP()
// CMenuBar message handlers


LRESULT CMenuBar::OnInitDialog(WPARAM wParam, LPARAM lParam)
{
	if (!UpdateData(FALSE))
	{
		TRACE0("Warning: UpdateData failed during dialog init.\n");
	}
	m_btn[0].UpdateWindow();
	m_btn[0].RedrawWindow();
	return 0;
}
void CMenuBar::OnUpdateCmdUI(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}
void CMenuBar::OnBnClickedMenu1_Btn()
{
	m_btn[0].SetCheck(TRUE);
	m_btn[1].SetCheck(FALSE);
	RedrawWindow();
	this->GetParent()->SendMessage(UM_CLICK_MENU_BTN, IDC_MENU_BTN1);
}


void CMenuBar::OnBnClickedMenu2_Btn()
{
	m_btn[0].SetCheck(FALSE);
	m_btn[1].SetCheck(TRUE);
	RedrawWindow();
	this->GetParent()->SendMessage(UM_CLICK_MENU_BTN, IDC_MENU_BTN2);
}


void CMenuBar::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class
	CDialogBar::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MENU_BTN1, m_btn[0]);
	DDX_Control(pDX, IDC_MENU_BTN2, m_btn[1]);
}
