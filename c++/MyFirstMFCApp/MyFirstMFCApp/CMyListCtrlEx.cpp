// CMyListCtrlEx.cpp: 实现文件
//

#include "stdafx.h"
#include "MyFirstMFCApp.h"
#include "CMyListCtrlEx.h"


// CMyListCtrlEx

IMPLEMENT_DYNAMIC(CMyListCtrlEx, CListCtrl)

CMyListCtrlEx::CMyListCtrlEx()
{

}

CMyListCtrlEx::~CMyListCtrlEx()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrlEx, CListCtrl)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CMyListCtrlEx 消息处理程序




void CMyListCtrlEx::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CListCtrl::OnPaint()
	CRect clientRect;
	GetClientRect(&clientRect);
	CRect headerRect;
	GetDlgItem(0)->GetWindowRect(&headerRect);
	CDC memDC;
	CBitmap memBitMap;
	memDC.CreateCompatibleDC(&dc);
	memBitMap.CreateCompatibleBitmap(&dc, clientRect.Width(), clientRect.Height());
	memDC.SelectObject(&memBitMap);

	memDC.FillSolidRect(&clientRect, RGB(228, 236, 243));

	DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, (LPARAM)0);

	dc.BitBlt(0, headerRect.Height(), clientRect.Width(), clientRect.Height(), &memDC, 0, headerRect.Height(), SRCCOPY);
	
	memDC.DeleteDC();
	memBitMap.DeleteObject();
}


BOOL CMyListCtrlEx::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return FALSE;
	// return CListCtrl::OnEraseBkgnd(pDC);
}
