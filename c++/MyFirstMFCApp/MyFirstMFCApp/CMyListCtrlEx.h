#pragma once


// CMyListCtrlEx

class CMyListCtrlEx : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListCtrlEx)

public:
	CMyListCtrlEx();
	virtual ~CMyListCtrlEx();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


