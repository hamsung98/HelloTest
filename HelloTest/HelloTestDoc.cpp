
// HelloTestDoc.cpp : CHelloTestDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// CHelloTestDoc ����/�Ҹ�

CHelloTestDoc::CHelloTestDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CHelloTestDoc::~CHelloTestDoc()
{
}

BOOL CHelloTestDoc::OnNewDocument()
{
	if (!CHtmlEditDoc::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.
	POSITION p = GetFirstViewPosition();
	CHtmlView *pView = (CHtmlView *)GetNextView(p);
	pView->Navigate2(_T("www.naver.com"));

	return TRUE;
}



#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CHelloTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CHelloTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CHelloTestDoc ����

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


// CHelloTestDoc ���
