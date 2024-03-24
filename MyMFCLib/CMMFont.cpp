#include "pch.h"
#include "CMMFont.h"

CMMFont::CMMFont()
{
	created = false;
}
CMMFont::~CMMFont()
{

}
void CMMFont::Delete()
{
	if (created) { this->DeleteObject(); created = false; }
}
void CMMFont::Create(int size, bool bold)
{
	if (created) { this->DeleteObject(); created = false; }
	CFont::CreateFont(
		size, //size
		0, 0, 0, 
		bold? FW_BOLD:FW_NORMAL,//bold
		FALSE,//Italic
		0,//Underline
		0, 
		DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, 
		L"Garamond");
}
void CMMFont::SetNewFont(int size, bool bold) 
{
	if (created) { this->DeleteObject(); created = false; }
	CFont::CreateFont(
		size, //size
		0, 0, 0, 
		bold? FW_BOLD:FW_NORMAL,//bold
		FALSE,//Italic
		0,//Underline
		0, 
		DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, 
		L"Garamond");
}
