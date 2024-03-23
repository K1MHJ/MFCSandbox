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
	ON_UPDATE_COMMAND_UI(IDC_MENU_BTN1, CMenuBar::OnUpdateCmdUI)
	ON_UPDATE_COMMAND_UI(IDC_MENU_BTN2, CMenuBar::OnUpdateCmdUI)
	ON_BN_CLICKED(IDC_MENU_BTN1, &CMenuBar::OnBnClickedMenu1_Btn)
	ON_BN_CLICKED(IDC_MENU_BTN2, &CMenuBar::OnBnClickedMenu2_Btn)
END_MESSAGE_MAP()
// CMenuBar message handlers


void CMenuBar::OnUpdateCmdUI(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}
void CMenuBar::OnBnClickedMenu1_Btn()
{
	// TODO: Add your control notification handler code here
}


void CMenuBar::OnBnClickedMenu2_Btn()
{
	// TODO: Add your control notification handler code here
}
