
// HelloTestView.cpp : CHelloTestView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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
// CHelloTestView 생성/소멸

CHelloTestView::CHelloTestView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHelloTestView::~CHelloTestView()
{
}

BOOL CHelloTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	return CHtmlEditView::PreCreateWindow(cs);
}


// CHelloTestView 인쇄


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


// CHelloTestView 진단

#ifdef _DEBUG
void CHelloTestView::AssertValid() const
{
	CHtmlEditView::AssertValid();
}

void CHelloTestView::Dump(CDumpContext& dc) const
{
	CHtmlEditView::Dump(dc);
}

CHelloTestDoc* CHelloTestView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloTestDoc)));
	return (CHelloTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloTestView 메시지 처리기
