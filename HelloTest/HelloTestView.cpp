
// HelloTestView.cpp : CHelloTestView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "HelloTest.h"
#endif

#include "HelloTestDoc.h"
#include "HelloTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloTestView

IMPLEMENT_DYNCREATE(CHelloTestView, CHtmlEditView)

BEGIN_MESSAGE_MAP(CHelloTestView, CHtmlEditView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CHtmlEditView::OnFilePrint)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

BEGIN_DHTMLEDITING_CMDMAP(CHelloTestView)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_COPY, IDM_COPY)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_CUT, IDM_CUT)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_PASTE, IDM_PASTE)
	DHTMLEDITING_CMD_ENTRY(ID_EDIT_UNDO, IDM_UNDO)
END_DHTMLEDITING_CMDMAP()
// CHelloTestView ����/�Ҹ�

CHelloTestView::CHelloTestView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CHelloTestView::~CHelloTestView()
{
}

BOOL CHelloTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	return CHtmlEditView::PreCreateWindow(cs);
}


// CHelloTestView �μ�


void CHelloTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}


void CHelloTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHelloTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHelloTestView ����

#ifdef _DEBUG
void CHelloTestView::AssertValid() const
{
	CHtmlEditView::AssertValid();
}

void CHelloTestView::Dump(CDumpContext& dc) const
{
	CHtmlEditView::Dump(dc);
}

CHelloTestDoc* CHelloTestView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloTestDoc)));
	return (CHelloTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloTestView �޽��� ó����
