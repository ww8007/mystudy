
// myView.h: CmyView 클래스의 인터페이스
//

#pragma once
#include "CHuman.h"
#include "CListenSocket.h"
#include "myDoc.h"
#include "DlgHumanMake.h"
class CmyView : public CView
{
protected: // serialization에서만 만들어집니다.
	CmyView() noexcept;
	DECLARE_DYNCREATE(CmyView)

// 특성입니다.
public:
	CmyDoc* GetDocument() const;

// 작업입니다.
public:
	CListenSocket* m_pListenSocket;
	CRect rect1;
	CString Fhnum;
	CString Fgnum;
	CString SElect;
	CRect rect;
	CSize size;
	CHuman* number;
	DlgHumanMake dlg;
	CString Send1;
	int Cnt = 0;
	int CCnt = 0;
	int FHnum=0;
	int FGnum=0;
	int Select=0;
	int NoGermnum=0;
	int YesGermnum = 0;
	int Healnum = 0;
	int NoGermRate=0;
	double YesGermRate = 0.0;
	int YesgermRate;
	int Healrate;
	double HealRate = 0.0;
	int ProgramStatus1=0;
	int ProgramTime = 1;
	int ProgramTime11;
	int Zeronum = 0;
	int Onenum = 0;
	int Twonum = 0;
	int Threenum = 0;
	int Fournum = 0;
	int Fivenum = 0;
	int SeverMakeORDlg = 0;
	
	CString Zeronum1; //0~9
	CString Onenum1; //10대
	CString Twonum1; //20대
	CString Threenum1; //30대
	CString Fournum1; //40대
	CString Fivenum1; //50대
	CString Sixnum1; //60대
 	CString Sevennum1;
	CString Eightnum1;
	CString Ninenum1;
	char szBuffer[1024];
	CString Nogermnum1; // 비감염자 비율
	CString YesGermnum1; // 감염자 비율
	CString Healnum1; // 회복자 비율
	CString ProgramStatus; // 종료원인
	CString ProgramTime1; //시간 비율
	int num1;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CmyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnMakeNum();
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	void OnMakeHuman();
	void SendDatamy();
	void SSendData(int number);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMakeHumanFromDlg();
	afx_msg void OnGameStart();
	void OnStop();
};

#ifndef _DEBUG  // myView.cpp의 디버그 버전
inline CmyDoc* CmyView::GetDocument() const
   { return reinterpret_cast<CmyDoc*>(m_pDocument); }
#endif

