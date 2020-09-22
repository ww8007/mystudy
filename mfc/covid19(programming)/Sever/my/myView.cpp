
// myView.cpp: CmyView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "my.h"
#endif

#include "myDoc.h"
#include "myView.h"
#include "ConnectNum.h"
#include "CHuman.h"
#include "DlgHumanMake.h"
#define CircleSize 15
#define XCirclenum 21
#define YCirclenum 10
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include  <time.h>
#include "CChildSocket.h"
#include "ResultDlg.h"
// CmyView

IMPLEMENT_DYNCREATE(CmyView, CView)

BEGIN_MESSAGE_MAP(CmyView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_COMMAND(ID_32771, &CmyView::OnMakeNum)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32772, &CmyView::OnMakeHumanFromDlg)
	ON_COMMAND(ID_32773, &CmyView::OnGameStart)
END_MESSAGE_MAP()

// CmyView 생성/소멸

CmyView::CmyView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	srand((unsigned)time(NULL));
	m_pListenSocket = new CListenSocket;
	if (m_pListenSocket->Create(7000, SOCK_STREAM))
	{
		if (m_pListenSocket->Listen()) {
		}
		else {
			AfxMessageBox(_T("Failed to LISTEN."));
		}
	}
	else
	{
		AfxMessageBox(_T("Failed to create socket for listen."));
	}
}

CmyView::~CmyView()
{
}

BOOL CmyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CmyView 그리기

void CmyView::OnDraw(CDC* pDC)
{
	CmyDoc* pDoc = GetDocument();
	
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	CBrush Brush;
	CBrush* pOldBrush;
	CPen redpen;
	CPen* pOldPen;
	GetClientRect(&rect);
	rect1.SetRect(40, 80 , rect.Width()-40, rect.Height() - 80);
	redpen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&redpen);
	pDC->Rectangle(rect1);
	pDC->SelectObject(pOldPen);
	redpen.DeleteObject();
	if (CCnt == 0)
	{
		FHnum = _ttoi(Fhnum);
		FGnum = _ttoi(Fgnum);
	}
	
	if (Cnt == 1)
	{
		number = new CHuman[FHnum];
		
		for (int i = 0; i < FHnum; i++)
		{
			
			number[i].age = rand() % 69 + 1;
			number[i].incubation = rand() % 14 + 2; //잠복기 설정 13단계
			number[i].status = 0; // 비감염 상태변수
			number[i].status2 = 3; //비감염  상태변수 2
			
			
			

			number[i].color1 = 0;
			number[i].color2 = 255;
			number[i].color3 = 0;
			
			number[i].countnum = 0;
			number[i].xpos = rand() % 11 - 5;
			number[i].ypos = rand() % 11 - 5;
			if (number[i].xpos == 0)
			{
				number[i].xpos = -1;
			}
			else if (number[i].ypos == 0)
			{
				number[i].ypos = -1;
			}
		}
		int countnum11 = 0;
		int num;
		int CCircleSize = 2 * CircleSize;
		for (int i = 0; i < FHnum; i++)
		{
			number[i].x = rand() % (rect1.Width() - CircleSize * 2) + 40 + CircleSize;
			number[i].y = rand() % (rect1.Height() - CircleSize * 2) + 81 + CircleSize;

			for (int j = 0; j < i; j++)
			{
				if (i != j)
				{
					num  = ((number[i].x - number[j].x) * (number[i].x - number[j].x)) + ((number[i].y - number[j].y) * (number[i].y - number[j].y));
					if (sqrt(num) < (CCircleSize))
					{
						i = i - 1;
						break;

					}
				}
				
			}
			
		}
		
		for (int i = 0; i < FHnum; i++)
		{
			int mynum = 20 - number[i].incubation;
			number[i].recovery = mynum; //회복기 설정
		}
		for (int i = 0; i < FGnum; i++)
		{
			number[i].color1 = 255;
			number[i].color2 = 0;
			number[i].color3 = 0;
			number[i].status = 1; //감염자 상태변수
			number[i].status2 = 2; //회복기 상태변수
		}
		for (int i = 0; i < FGnum; i++)
		{
			Brush.CreateSolidBrush((RGB(255, 0, 0)));
			pDC->SelectObject(&Brush);
			pDC->Ellipse(number[i].x - CircleSize, number[i].y - CircleSize, number[i].x + CircleSize, number[i].y + CircleSize);
			Brush.DeleteObject();
		}
		for (int i = FGnum; i < FHnum; i++)
		{
			Brush.CreateSolidBrush((RGB(0, 255, 0)));
			pDC->SelectObject(&Brush);
			pDC->Ellipse(number[i].x - CircleSize, number[i].y - CircleSize, number[i].x + CircleSize, number[i].y + CircleSize);
			Brush.DeleteObject();
		}
	}

	
	else if(Cnt==2)
	{
		for (int i = 0; i < FHnum; i++)
		{
			Brush.CreateSolidBrush((RGB(number[i].color1, number[i].color2, number[i].color3)));
			pDC->SelectObject(&Brush);
			pDC->Ellipse(number[i].x - CircleSize, number[i].y - CircleSize, number[i].x + CircleSize, number[i].y + CircleSize);
			Brush.DeleteObject();
		}
	}



}


// CmyView 인쇄

BOOL CmyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CmyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CmyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CmyView 진단

#ifdef _DEBUG
void CmyView::AssertValid() const
{
	CView::AssertValid();
}

void CmyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmyDoc* CmyView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmyDoc)));
	return (CmyDoc*)m_pDocument;
}
#endif //_DEBUG


// CmyView 메시지 처리기


void CmyView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	POSITION pos;
	pos = m_pListenSocket->m_ptrChildSocketList.GetHeadPosition();
	CChildSocket* pChild = NULL;
	while (pos != NULL) 
	{
		pChild = (CChildSocket*)m_pListenSocket->m_ptrChildSocketList.GetNext(pos);
			if (pChild != NULL) 
			{
				pChild->ShutDown();
				pChild->Close();
				delete pChild;
			}
	}
	m_pListenSocket->ShutDown();
	m_pListenSocket->Close();

}


void CmyView::OnMakeNum()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ConnectNum dlg;
	dlg.Fgnum = Fgnum;
	dlg.Fhnum = Fhnum;
	FHnum = _ttoi(Fhnum);
	FGnum = _ttoi(Fgnum);
	dlg.DoModal();
}


void CmyView::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnClose();
}


void CmyView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	size = CSize(cx / 2, cy / 2);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CmyView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int RealCircleSize = CircleSize * 2;
	if (nIDEvent == 0) // 방향변수 더해주기 + 감염 판별
	{
		GetClientRect(rect1);
		rect.SetRect(40, 80, rect1.Width() - 40, rect1.Width() - 80);
		
		int i;
		int j=0;
		if (FHnum == FGnum)
		{
			KillTimer(0);
			KillTimer(1);
			KillTimer(2);
			KillTimer(3);
			::ZeroMemory(szBuffer, 1024);
		}
		for (int i = 0; i < FHnum; i++) // 방향변수 더해주기
		{
			
			if (number[i].x - (CircleSize+6) < 40)
			{
				number[i].xpos *= -1;
			}
			if (number[i].x + (CircleSize + 6) > rect1.Width()-40)
			{
				number[i].xpos *= -1;
			}
			if (number[i].y - (CircleSize + 6) < 80)
			{
				number[i].ypos *= -1;
			}
			if (number[i].y + (CircleSize + 6) > rect1.Height()-80)
			{
				number[i].ypos *= -1;
			}
			number[i].x = number[i].x + (number[i].xpos);
			number[i].y = number[i].y + (number[i].ypos);
		}
		
		
	}
	else if (nIDEvent == 1)
	{
		int i;

		for (i = 0; i < FHnum; i++)
		{
			
			for (int j = 0; j < FHnum; j++)
			{
				if (i != j)
				{
					if (number[i].status == 0 && number[i].status2 != 0) //비감염자
					{
						if (number[j].status == 1 && number[j].status2 == 2) // 감염자 이고 잠복기가 아닐시
						{
							int num = ((number[i].x - number[j].x) * (number[i].x - number[j].x)) + ((number[i].y - number[j].y) * (number[i].y - number[j].y));

							if (sqrt(num) < RealCircleSize)
							{
								number[i].countnum++; //확률 검사 다시 안하도록 1로 변경

								if (number[i].countnum == 1) // 1일 때만 확률검사
								{
									int germ = rand() % 11;
									switch (Select)
									{
									case 0:
										if (germ <= 1)
										{
											number[i].status2 = 1; // 잠복기로 판별
											number[i].status = 1; // 감염자로 판별
											number[i].color1 = 255;
											number[i].color2 = 0;
											number[i].color3 = 0;
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}
										else
										{
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}
									case 1:
										if (germ <= 3)
										{
											number[i].status2 = 1;
											number[i].status = 1;
											number[i].color1 = 255;
											number[i].color2 = 0;
											number[i].color3 = 0;
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}
										else
										{
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}

									case 2:
										if (germ <= 5)
										{
											number[i].status2 = 1;
											number[i].status = 1;
											number[i].color1 = 255;
											number[i].color2 = 0;
											number[i].color3 = 0;
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}
										else
										{
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}

									case 3:
										if (germ <= 9)
										{
											number[i].status2 = 1;
											number[i].status = 1;
											number[i].color1 = 255;
											number[i].color2 = 0;
											number[i].color3 = 0;
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}
										else
										{
											number[i].countnum++; //확률 검사 다시 안하도록 1로 변경
										}
									}
								}

							}
							else
							{
								if(number[i].countnum > 2)
									number[i].countnum = 0; //확률 검사 다시 안하도록 1로 변경
								
							}
						}
					}
				}
			}
		}
	} //프로그램 종료 
	else if (nIDEvent == 2) // 프로그램 종료 종료원인 : 시간 초과
	{
		KillTimer(0);
		KillTimer(1);
		KillTimer(3);
		KillTimer(2);
		
		KillTimer(4);
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status == 0) // 비감염자
			{
				if (number[i].status2 == 3) //완전한 비감염자
				{
					NoGermnum++; //비감염자 넘버 ++
				}
			}
			
		}
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status2 == 0) // 회복자 
			{
				Healnum++; //회복자 넘버 ++
			}
		}
		
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status == 1) // 감염자
			{
				YesGermnum++; // 감염자 넘버 ++
			}
		}
		
		num1 = 3;
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status == 1) // 감염자이라고 판단시 나이별로 ++
			{
				if (number[i].age / 10 < 1)
				{
					Zeronum++;
				}
				else if (number[i].age / 10 >= 1 && number[i].age / 10 < 2)
				{
					Onenum++;
				}
				else if (number[i].age / 10 >= 2 && number[i].age / 10 < 3)
				{
					Twonum++;
				}
				else if (number[i].age / 10 >= 3 && number[i].age / 10 < 4)
				{
					Threenum++;

				}
				else if (number[i].age / 10 >= 4 && number[i].age / 10 < 5)
				{
					Fournum++;

				}
				else if (number[i].age / 10 >= 5 && number[i].age / 10 < 6)
				{
					Fivenum++;

				}
			}
			
		}
		YesGermRate = ((double)YesGermnum / (double)FHnum) * (double)100;
		HealRate = ((double)Healnum / (double)FHnum) * (double)100;
	
		ProgramStatus1 = 7;
		
		Zeronum1.Format(_T("%d"), (int)(((double)Zeronum / (double)YesGermnum) * (double)100));
		Onenum1.Format(_T("%d"), (int)(((double)Onenum / (double)YesGermnum) * (double)100));
		Twonum1.Format(_T("%d"), (int)(((double)Twonum / (double)YesGermnum) * (double)100));
		Threenum1.Format(_T("%d"), (int)(((double)Threenum / (double)YesGermnum) * (double)100));
		Fournum1.Format(_T("%d"), (int)(((double)Fournum / (double)YesGermnum) * (double)100));
		Fivenum1.Format(_T("%d"), (int)(((double)Fivenum / (double)YesGermnum) * (double)100));
		ProgramTime1.Format(_T("%d"), ProgramTime);
		
		YesGermnum1.Format(_T("%d"), (int)YesGermRate);
		Healnum1.Format(_T("%d"), (int)HealRate);
		ProgramStatus.Format(_T("%d"), ProgramStatus1);
		Send1.Format(_T("%03d%03d%03d%03d%03d%03d%02d%03d%03d%01d"), _ttoi(Zeronum1), _ttoi(Onenum1), _ttoi(Twonum1), _ttoi(Threenum1), _ttoi(Fournum1), _ttoi(Fivenum1), _ttoi(ProgramTime1), _ttoi(YesGermnum1), _ttoi(Healnum1), _ttoi(ProgramStatus));
		ResultDlg dlg;
		dlg.Zeronum1 = Zeronum1;
		dlg.Onenum1 = Onenum1;
		dlg.Twonum1 = Twonum1;
		dlg.Threenum1 = Threenum1;
		dlg.Fournum1 = Fournum1;
		dlg.Fivenum1 = Fivenum1;
		dlg.ProgramTime1 = ProgramTime1;
		dlg.Healnum1 = Healnum1;
		dlg.YesGermnum1 = YesGermnum1;
		dlg.ProgramStatus = "Time out";
		dlg.DoModal();
		
		
		
		m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Send1, 1024);
		
		

		
		
		
		
	

	} // 재감염
	else if (nIDEvent == 3) // 감염 시간 판별
	{
		ProgramTime++;
		
		for (int i = 0; i < FHnum; i++)
		{
			
			if (number[i].status == 1) // 감염자라면
			{
				YesGermnum++; //감염자 사람 추가
				if (number[i].status2 == 1) // 잠복기 의 사람일시
				{
					number[i].incubation--; // 잠복기 시간 - 
					if (number[i].incubation <= 0) //잠복기 시간 0 이면
					{
						number[i].status2 = 2; // 회복기
					}
				}
			}
			
		}
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status2 == 2) // 회복기의 사람일 시
			{
				number[i].recovery--; // 회복 시간 -
				if (number[i].recovery <= 0) // 회복 시간 끝났을 시
				{
					YesGermnum--; // 감염자-
					Healnum++; // 회복자+
					number[i].status = 3; //회복자로 판별
					number[i].status2 = 0; // 회복자로 판별
					number[i].color1 = 0;
					number[i].color2 = 0;
					number[i].color3 = 255; // 파란색
				}
			}
		}

		for (int i = 0; i < FHnum; i++)
		{

			if (number[i].status == 0) // 감염자라면
			{
				NoGermnum++; //감염자 사람 추가
				
			}
			else if (number[i].status == 1)
			{
				YesGermnum++;
			}
		}
		if (NoGermnum == 0) // 비감염자 한명도 없을 시 -> 모두 감염자
		{
			KillTimer(0);
			KillTimer(1);
			KillTimer(3);
			KillTimer(2);

			KillTimer(4);
			NoGermnum = 0;
			Healnum = 0;
			YesGermnum = 0;
			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status == 0) // 비감염자
				{
					if (number[i].status2 == 3) //완전한 비감염자
					{
						NoGermnum++; //비감염자 넘버 ++
					}
				}

			}
			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status2 == 0) // 회복자 
				{
					Healnum++; //회복자 넘버 ++
				}
			}

			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status == 1) // 감염자
				{
					YesGermnum++; // 감염자 넘버 ++
				}
			}

			num1 = 3;
			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status == 1) // 감염자이라고 판단시 나이별로 ++
				{
					if (number[i].age / 10 < 1)
					{
						Zeronum++;
					}
					else if (number[i].age / 10 >= 1 && number[i].age / 10 < 2)
					{
						Onenum++;
					}
					else if (number[i].age / 10 >= 2 && number[i].age / 10 < 3)
					{
						Twonum++;
					}
					else if (number[i].age / 10 >= 3 && number[i].age / 10 < 4)
					{
						Threenum++;

					}
					else if (number[i].age / 10 >= 4 && number[i].age / 10 < 5)
					{
						Fournum++;

					}
					else if (number[i].age / 10 >= 5 && number[i].age / 10 < 6)
					{
						Fivenum++;

					}
					
				}

			}


			
			YesGermRate = ((double)YesGermnum / (double)FHnum) * (double)100;
			HealRate = (double)100 - YesGermRate;
			
			ProgramStatus1 = 6;

			Zeronum1.Format(_T("%d"), (int)(((double)Zeronum / (double)YesGermnum) * (double)100));
			Onenum1.Format(_T("%d"), (int)(((double)Onenum / (double)YesGermnum) * (double)100));
			Twonum1.Format(_T("%d"), (int)(((double)Twonum / (double)YesGermnum) * (double)100));
			Threenum1.Format(_T("%d"), (int)(((double)Threenum / (double)YesGermnum) * (double)100));
			Fournum1.Format(_T("%d"), (int)(((double)Fournum / (double)YesGermnum) * (double)100));
			Fivenum1.Format(_T("%d"), (int)(((double)Fivenum / (double)YesGermnum) * (double)100));
			ProgramTime1.Format(_T("%d"), ProgramTime);

			YesGermnum1.Format(_T("%d"), (int)YesGermRate);
			Healnum1.Format(_T("%d"), (int)HealRate);
			ProgramStatus.Format(_T("%d"), ProgramStatus1);
			Send1.Format(_T("%03d%03d%03d%03d%03d%03d%02d%03d%03d%01d"), _ttoi(Zeronum1), _ttoi(Onenum1), _ttoi(Twonum1), _ttoi(Threenum1), _ttoi(Fournum1), _ttoi(Fivenum1), _ttoi(ProgramTime1), _ttoi(YesGermnum1), _ttoi(Healnum1), _ttoi(ProgramStatus));
			ResultDlg dlg;
			dlg.Zeronum1 = Zeronum1;
			dlg.Onenum1 = Onenum1;
			dlg.Twonum1 = Twonum1;
			dlg.Threenum1 = Threenum1;
			dlg.Fournum1 = Fournum1;
			dlg.Fivenum1 = Fivenum1;
			dlg.Ninenum1 = Ninenum1;
			dlg.ProgramTime1 = ProgramTime1;
			dlg.Healnum1 = Healnum1;
			dlg.YesGermnum1 = YesGermnum1;
			dlg.ProgramStatus = "All infetee be Regainer";
			dlg.DoModal();


			m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Send1, 1024);
	





		}
		else if (YesGermnum == 0)
		{
		KillTimer(0);
		KillTimer(1);
		KillTimer(3);
		KillTimer(2);

		KillTimer(4);
		NoGermnum = 0;
		Healnum = 0;
		YesGermnum = 0;
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status == 0) // 비감염자
			{
				if (number[i].status2 == 3) //완전한 비감염자
				{
					NoGermnum++; //비감염자 넘버 ++
				}
			}

		}
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status2 == 0) // 회복자 
			{
				Healnum++; //회복자 넘버 ++
			}
		}

		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status == 1) // 감염자
			{
				YesGermnum++; // 감염자 넘버 ++
			}
		}

		num1 = 3;
		for (int i = 0; i < FHnum; i++)
		{
			if (number[i].status == 1) // 감염자이라고 판단시 나이별로 ++
			{
				if (number[i].age / 10 < 1)
				{
					Zeronum = 0;
				}
				else if (number[i].age / 10 >= 1 && number[i].age / 10 < 2)
				{
					Onenum = 0;
				}
				else if (number[i].age / 10 >= 2 && number[i].age / 10 < 3)
				{
					Twonum = 0;
				}
				else if (number[i].age / 10 >= 3 && number[i].age / 10 < 4)
				{
					Threenum = 0;

				}
				else if (number[i].age / 10 >= 4 && number[i].age / 10 < 5)
				{
					Fournum = 0;

				}
				else if (number[i].age / 10 >= 5 && number[i].age / 10 < 6)
				{
					Fivenum = 0;

				}
			}

		}
		HealRate = ((double)Healnum / (double)FHnum) * (double)100;
		YesgermRate = 0;
		
		
		ProgramStatus1 = 8;

		Zeronum1.Format(_T("%d"), Zeronum);
		Onenum1.Format(_T("%d"), Onenum);
		Twonum1.Format(_T("%d"), Twonum);
		Threenum1.Format(_T("%d"), Threenum);
		Fournum1.Format(_T("%d"), Fournum);
		Fivenum1.Format(_T("%d"), Fivenum);
		ProgramTime1.Format(_T("%d"), ProgramTime);

		YesGermnum1.Format(_T("%d"), (int)YesGermRate);
		Healnum1.Format(_T("%d"), (int)HealRate);
		ProgramStatus.Format(_T("%d"), ProgramStatus1);
		Send1.Format(_T("%03d%03d%03d%03d%03d%03d%02d%03d%03d%01d"), _ttoi(Zeronum1), _ttoi(Onenum1), _ttoi(Twonum1), _ttoi(Threenum1), _ttoi(Fournum1), _ttoi(Fivenum1), _ttoi(ProgramTime1), _ttoi(YesGermnum1), _ttoi(Healnum1), _ttoi(ProgramStatus));
		ResultDlg dlg;
		dlg.Zeronum1 = Zeronum1;
		dlg.Onenum1 = Onenum1;
		dlg.Twonum1 = Twonum1;
		dlg.Threenum1 = Threenum1;
		dlg.Fournum1 = Fournum1;
		dlg.Fivenum1 = Fivenum1;
		dlg.ProgramTime1 = ProgramTime1;
		dlg.Healnum1 = Healnum1;
		dlg.YesGermnum1 = YesGermnum1;
		dlg.ProgramStatus = "All Num is Infectee";
		dlg.DoModal();
		


		m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Send1, 1024);
		




	 }
		NoGermnum = 0;
		YesGermnum = 0;
	} // 
	else if (nIDEvent == 4) // 방향 변수 랜덤 조정
	{
		for (int i = 0; i < FHnum; i++)
		{
			number[i].xpos = rand() % 9 - 4;
			number[i].ypos = rand() % 9 - 4;
			if (number[i].xpos == 0)
			{
				number[i].xpos = -1;
			}
			else if (number[i].ypos == 0)
			{
				number[i].ypos = -1;
			}
			
		}

	}
	

	Invalidate(1);
	CView::OnTimer(nIDEvent);
}


void CmyView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CmyView::OnMakeHuman()
{
	// TODO: 여기에 구현 코드 추가.
	if (Cnt == 2)
	{
		SetTimer(0, 1, NULL);
		SetTimer(1, 500, NULL);
		SetTimer(2, 30000, NULL);
		SetTimer(3, 1000, NULL);
		SetTimer(4, 1000, NULL);
	}
	
}


void CmyView::SendDatamy()
{
	// TODO: 여기에 구현 코드 추가.
	
}


void CmyView::SSendData(int number)
{
	// TODO: 여기에 구현 코드 추가.
	
	
	
}


void CmyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int count=0;
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == 0x58 && count == 0)
	{
		count = 1;
		CView::OnKeyDown(nChar, nRepCnt, nFlags);
		if ((::GetKeyState(VK_CONTROL) < 0) && count == 1)
		{
			
			KillTimer(0);
			KillTimer(1);
			KillTimer(3);
			KillTimer(2);

			KillTimer(4);
			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status == 0) // 비감염자
				{
					if (number[i].status2 == 3) //완전한 비감염자
					{
						NoGermnum++; //비감염자 넘버 ++
					}
				}

			}
			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status2 == 0) // 회복자 
				{
					Healnum++; //회복자 넘버 ++
				}
			}

			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status == 1) // 감염자
				{
					YesGermnum++; // 감염자 넘버 ++
				}
			}

			num1 = 3;
			for (int i = 0; i < FHnum; i++)
			{
				if (number[i].status == 1) // 감염자이라고 판단시 나이별로 ++
				{
					if (number[i].age / 10 < 1)
					{
						Zeronum++;
					}
					else if (number[i].age / 10 >= 1 && number[i].age / 10 < 2)
					{
						Onenum++;
					}
					else if (number[i].age / 10 >= 2 && number[i].age / 10 < 3)
					{
						Twonum++;
					}
					else if (number[i].age / 10 >= 3 && number[i].age / 10 < 4)
					{
						Threenum++;

					}
					else if (number[i].age / 10 >= 4 && number[i].age / 10 < 5)
					{
						Fournum++;

					}
					else if (number[i].age / 10 >= 5 && number[i].age / 10 < 6)
					{
						Fivenum++;

					}
				}

			}
			YesGermRate = ((double)YesGermnum / (double)FHnum) * (double)100;
			HealRate = ((double)Healnum / (double)FHnum) * (double)100;
			
			ProgramStatus1 = 9;

			Zeronum1.Format(_T("%d"), (int)(((double)Zeronum / (double)YesGermnum) * (double)100));
			Onenum1.Format(_T("%d"), (int)(((double)Onenum / (double)YesGermnum) * (double)100));
			Twonum1.Format(_T("%d"), (int)(((double)Twonum / (double)YesGermnum) * (double)100));
			Threenum1.Format(_T("%d"), (int)(((double)Threenum / (double)YesGermnum) * (double)100));
			Fournum1.Format(_T("%d"), (int)(((double)Fournum / (double)YesGermnum) * (double)100));
			Fivenum1.Format(_T("%d"), (int)(((double)Fivenum / (double)YesGermnum) * (double)100));
			ProgramTime1.Format(_T("%d"), ProgramTime);

			YesGermnum1.Format(_T("%d"), (int)YesGermRate);
			Healnum1.Format(_T("%d"), (int)HealRate);
			ProgramStatus.Format(_T("%d"), ProgramStatus1);
			Send1.Format(_T("%03d%03d%03d%03d%03d%03d%02d%03d%03d%01d"), _ttoi(Zeronum1), _ttoi(Onenum1), _ttoi(Twonum1), _ttoi(Threenum1), _ttoi(Fournum1), _ttoi(Fivenum1), _ttoi(ProgramTime1), _ttoi(YesGermnum1), _ttoi(Healnum1), _ttoi(ProgramStatus));
			ResultDlg dlg;
			dlg.Zeronum1 = Zeronum1;
			dlg.Onenum1 = Onenum1;
			dlg.Twonum1 = Twonum1;
			dlg.Threenum1 = Threenum1;
			dlg.Fournum1 = Fournum1;
			dlg.Fivenum1 = Fivenum1;
			dlg.ProgramTime1 = ProgramTime1;
			dlg.Healnum1 = Healnum1;
			dlg.YesGermnum1 = YesGermnum1;
			dlg.ProgramStatus = "Key Down CTRL+X";
			dlg.DoModal();


			m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Send1, 1024);
			


			

		}
	}
	
	
	count = 0;
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CmyView::OnMakeHumanFromDlg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
	int res = dlg.DoModal();
	if (res == IDOK)
	{
		FHnum = dlg.Fhhnum;
		FGnum = dlg.Fggnum;
		Select = dlg.SSSSelect;
		Cnt = 1;
		CCnt = 1;
		Invalidate();
	}

}


void CmyView::OnGameStart()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cnt = 2;
	SeverMakeORDlg = 1; // dlg make
	Invalidate(1);
	SetTimer(0, 1, NULL);
	SetTimer(1, 500, NULL);
	SetTimer(2, 30000, NULL);
	SetTimer(3, 1000, NULL);
	SetTimer(4, 1000, NULL);
}


void CmyView::OnStop()
{
	// TODO: 여기에 구현 코드 추가.
	KillTimer(0);
	KillTimer(1);
	KillTimer(3);
	KillTimer(2);
	KillTimer(4);
	for (int i = 0; i < FHnum; i++)
	{
		if (number[i].status == 0) // 비감염자
		{
			if (number[i].status2 == 3) //완전한 비감염자
			{
				NoGermnum++; //비감염자 넘버 ++
			}
		}

	}
	for (int i = 0; i < FHnum; i++)
	{
		if (number[i].status2 == 0) // 회복자 
		{
			Healnum++; //회복자 넘버 ++
		}
	}

	for (int i = 0; i < FHnum; i++)
	{
		if (number[i].status == 1) // 감염자
		{
			YesGermnum++; // 감염자 넘버 ++
		}
	}

	num1 = 3;
	for (int i = 0; i < FHnum; i++)
	{
		if (number[i].status == 1) // 감염자이라고 판단시 나이별로 ++
		{
			if (number[i].age / 10 < 1)
			{
				Zeronum++;
			}
			else if (number[i].age / 10 >= 1 && number[i].age / 10 < 2)
			{
				Onenum++;
			}
			else if (number[i].age / 10 >= 2 && number[i].age / 10 < 3)
			{
				Twonum++;
			}
			else if (number[i].age / 10 >= 3 && number[i].age / 10 < 4)
			{
				Threenum++;

			}
			else if (number[i].age / 10 >= 4 && number[i].age / 10 < 5)
			{
				Fournum++;

			}
			else if (number[i].age / 10 >= 5 && number[i].age / 10 < 6)
			{
				Fivenum++;

			}
		}

	}
	YesGermRate = ((double)YesGermnum / (double)FHnum) * (double)100;
	HealRate = ((double)Healnum / (double)FHnum) * (double)100;
	
	ProgramStatus1 = 5;

	
	Zeronum1.Format(_T("%d"), (int)(((double)Zeronum / (double)YesGermnum) * (double)100));
	Onenum1.Format(_T("%d"), (int)(((double)Onenum / (double)YesGermnum) * (double)100));
	Twonum1.Format(_T("%d"), (int)(((double)Twonum / (double)YesGermnum) * (double)100));
	Threenum1.Format(_T("%d"), (int)(((double)Threenum / (double)YesGermnum) * (double)100));
	Fournum1.Format(_T("%d"), (int)(((double)Fournum / (double)YesGermnum) * (double)100));
	Fivenum1.Format(_T("%d"), (int)(((double)Fivenum / (double)YesGermnum) * (double)100));
	ProgramTime1.Format(_T("%d"), ProgramTime);
	
	YesGermnum1.Format(_T("%d"), (int)YesGermRate);
	Healnum1.Format(_T("%d"), (int)HealRate);
	ProgramStatus.Format(_T("%d"), ProgramStatus1);

	Send1.Format(_T("%03d%03d%03d%03d%03d%03d%02d%03d%03d%1d"), _ttoi(Zeronum1), _ttoi(Onenum1), _ttoi(Twonum1), _ttoi(Threenum1), _ttoi(Fournum1), _ttoi(Fivenum1), _ttoi(ProgramTime1), _ttoi(YesGermnum1), _ttoi(Healnum1), _ttoi(ProgramStatus));
	ResultDlg dlg;
	dlg.Zeronum1 = Zeronum1;
	dlg.Onenum1 = Onenum1;
	dlg.Twonum1 = Twonum1;
	dlg.Threenum1 = Threenum1;
	dlg.Fournum1 = Fournum1;
	dlg.Fivenum1 = Fivenum1;
	dlg.Sixnum1 = Sixnum1;
	dlg.Sevennum1 = Sevennum1;
	dlg.Eightnum1 = Eightnum1;
	dlg.Ninenum1 = Ninenum1;
	dlg.ProgramTime1 = ProgramTime1;
	dlg.Healnum1 = Healnum1;
	dlg.YesGermnum1 = YesGermnum1;
	dlg.ProgramStatus = "Press Stop";
	dlg.DoModal();

	
	m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Send1, 512);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Onenum1, 4);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Twonum1, 4);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Threenum1, 4);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Fournum1, 4);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Fivenum1, 4);

	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)ProgramTime1, 4);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)YesGermnum1, 4);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)Healnum1, 4);
	//m_pListenSocket->BroadCast((LPSTR)(LPCTSTR)ProgramStatus, 2);







}
