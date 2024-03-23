#pragma once
#include <afxcmn.h>
#include "CMMHeaderCtrl.h"

class CMMListCtrl :
    public CListCtrl
{
    virtual void PreSubclassWindow();
    CMMHeaderCtrl m_headerCtrl;
};

