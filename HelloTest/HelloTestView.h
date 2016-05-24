
// HelloTestView.h : CHelloTestView 클래스의 인터페이스
//

#pragma once


class CHelloTestView : public CHtmlEditView
{
protected: // serialization에서만 만들어집니다.
	CHelloTestView();
	DECLARE_DYNCREATE(CHelloTestView)

// 특성입니다.
public:
	CHelloTestDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CHelloTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_DHTMLEDITING_CMDMAP(CHelloTestView)
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HelloTestView.cpp의 디버그 버전
inline CHelloTestDoc* CHelloTestView::GetDocument() const
   { return reinterpret_cast<CHelloTestDoc*>(m_pDocument); }
#endif

