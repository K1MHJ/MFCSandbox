#pragma once
#include <afxwin.h>
class CMMFont : private CFont
{
    bool created;
public:
    CMMFont();
    ~CMMFont();
    CFont* Get() { return this; }
public:
    void SetNewFont(int size, bool bold);
    void Create(int size, bool bold);
    void Delete();
};

