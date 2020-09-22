// CChildSocket.cpp: 구현 파일
//

#include "pch.h"
#include "my.h"
#include "CChildSocket.h"
#include "myView.h"

// CChildSocket

CChildSocket::CChildSocket()
{
	m_pListenSocket = NULL;
}

CChildSocket::~CChildSocket()
{
}


// CChildSocket 멤버 함수


void CChildSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	// TODO: 여기에 구현 코드 추가.
	m_pListenSocket = pSocket;

}
#include "CListenSocket.h"

void CChildSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
	CSocket::OnClose(nErrorCode);
}
#include "myView.h"
#include "CChildSocket.h"
#include "CListenSocket.h"
void CChildSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString tmp = _T(""), strIPAddress = _T("");
	UINT uPortNumber = 0;
	char szBuffer[1024];
	::ZeroMemory(szBuffer, 1024);
	//연결된클라이언트의IP주소와포트번호를알아낸다. 
	GetPeerName(strIPAddress, uPortNumber);
	int len;
	CFrameWnd* pMainWnd = (CFrameWnd*)AfxGetMainWnd();
	CmyView* myView = (CmyView*)pMainWnd->GetActiveView();
	if (cnt == 0)
	{
		if ((len = Receive(szBuffer, 1024)) > 0)
		{
			//데이터를수신하였다면받은메시지를리스트에출력한다. 
			
			myView->Fhnum.AppendChar(szBuffer[0]);
			myView->Fhnum.AppendChar(szBuffer[2]);
			myView->Fhnum.AppendChar(szBuffer[4]);
			myView->Fhnum.AppendChar(szBuffer[6]);

			myView->Fgnum.AppendChar(szBuffer[8]);
			myView->Fgnum.AppendChar(szBuffer[10]);
			myView->Fgnum.AppendChar(szBuffer[12]);

			myView->SElect.AppendChar(szBuffer[14]);
			myView->Select = _ttoi(myView->SElect);
			cnt++;
			myView->Cnt = 1;
			myView->Invalidate(1);
			for (int i = 0; i <= len; i++) // 총 사람 수 반별
			{
		//		if (szBuffer[i] == '+')
		//		{
		//			j = i;
		//			szBuffer[i] = NULL;
		//		}
		//	}

		//	for (int i = 0; i <= j - 2; i++) // 총 사람 수 판별
		//	{
		//		if (i % 2 == 0)
		//		{
		//			myView->Fhnum.AppendChar(szBuffer[i]);
		//		}

		//	}
		//	for (int i = j + 2; i <= len; i++) // 감염자 판별
		//	{
		//		if (szBuffer[i] == '-')
		//		{
		//			k = i;
		//			szBuffer[i] = NULL;
		//		}
		//	}
		//	for (int i = j + 2; i <= k - 2; i++) // 감염자 판별
		//	{
		//		if (i % 2 == 0)
		//		{
		//			myView->Fgnum.AppendChar(szBuffer[i]);
		//		}
		//	}
		//	for (int i = k + 2; i <= len; i++) // 방역체계 radio 판별
		//	{
		//		if (szBuffer[i] == '*')
		//		{
		//			m = i;
		//			szBuffer[i] = NULL;
		//		}
		//	}
		//	for (int i = k + 2; i <= m - 2; i++) // 방역 체계 radio 판별
		//	{
		//		if (i % 2 == 0)
		//		{
		//			myView->SElect.AppendChar(szBuffer[i]);
		//			myView->Select = _ttoi(myView->SElect);
		//		}
			}
		//	
		}
	}
	else if(cnt==1)
	{
		if ((len = Receive(szBuffer, 1024)) > 0)
		{
			
			for (int i = 0; i <= len; i++) // 총 사람 수 반별
			{
				if (szBuffer[i] == '/')
				{
					myView->Cnt = 2; // 동작 변수
					myView->OnMakeHuman(); // onTimer 구동
					myView->Invalidate(0); // Ondraw 호출
					
				}
			}
		}
		cnt++;
	}
	else if (cnt == 2)
	{
		if ((len = Receive(szBuffer, 1024)) > 0)
		{

			for (int i = 0; i <= len; i++) // 총 사람 수 반별
			{
				if (szBuffer[i] == '^')
				{
					myView->Cnt = 3; // 동작 변수
					myView->OnStop();

				}
			}
		}

	}
	CSocket::OnReceive(nErrorCode);
}
