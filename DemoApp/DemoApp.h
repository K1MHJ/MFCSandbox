
// DemoApp.h : main header file for the DemoApp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

#define UM_CLICK_MENU_BTN  100

// CDemoAppApp:
// See DemoApp.cpp for the implementation of this class
//

class CDemoAppApp : public CWinApp
{
public:
	CDemoAppApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDemoAppApp theApp;
