#pragma once
#include <afxext.h>


class CMMTopView : public CFormView
{
public:
	CMMTopView() noexcept;
protected: // create from serialization only
	
	DECLARE_DYNCREATE(CMMTopView)

public:


	// Attributes
public:
	
	// Operations
public:

	// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

	// Implementation
public:
	virtual ~CMMTopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

