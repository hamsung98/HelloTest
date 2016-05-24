
// HelloTestDoc.cpp : CHelloTestDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HelloTest.h"
#endif

#include "HelloTestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHelloTestDoc

IMPLEMENT_DYNCREATE(CHelloTestDoc, CHtmlEditDoc)

BEGIN_MESSAGE_MAP(CHelloTestDoc, CHtmlEditDoc)
END_MESSAGE_MAP()


// CHelloTestDoc 생성/소멸

CHelloTestDoc::CHelloTestDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHelloTestDoc::~CHelloTestDoc()
{
}

BOOL CHelloTestDoc::OnNewDocument()
{
	if (!CHtmlEditDoc::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	POSITION p = GetFirstViewPosition();
	CHtmlView *pView = (CHtmlView *)GetNextView(p);
	pView->Navigate2(_T("www.naver.com"));

	return TRUE;
}



#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CHelloTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CHelloTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHelloTestDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHelloTestDoc 진단

#ifdef _DEBUG
void CHelloTestDoc::AssertValid() const
{
	CHtmlEditDoc::AssertValid();
}

void CHelloTestDoc::Dump(CDumpContext& dc) const
{
	CHtmlEditDoc::Dump(dc);
}
#endif //_DEBUG


// CHelloTestDoc 명령
