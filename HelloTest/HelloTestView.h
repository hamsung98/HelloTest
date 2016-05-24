
// HelloTestView.h : CHelloTestView Ŭ������ �������̽�
//

#pragma once


class CHelloTestView : public CHtmlEditView
{
protected: // serialization������ ��������ϴ�.
	CHelloTestView();
	DECLARE_DYNCREATE(CHelloTestView)

// Ư���Դϴ�.
public:
	CHelloTestDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CHelloTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_DHTMLEDITING_CMDMAP(CHelloTestView)
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // HelloTestView.cpp�� ����� ����
inline CHelloTestDoc* CHelloTestView::GetDocument() const
   { return reinterpret_cast<CHelloTestDoc*>(m_pDocument); }
#endif

