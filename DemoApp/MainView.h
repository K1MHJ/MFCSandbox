#pragma once
#include "CMMLabel.h"
// MainView form view
class MainView : public CFormView
{
	DECLARE_DYNCREATE(MainView)
public:	
	MainView();           // protected constructor used by dynamic creation
protected:
	virtual ~MainView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
};


