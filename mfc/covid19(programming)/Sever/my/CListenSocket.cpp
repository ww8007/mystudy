// CListenSocket.cpp: 구현 파일
//

#include "pch.h"
#include "my.h"
#include "CListenSocket.h"
#include "myView.h"
// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket 멤버 함수

#include "myView.h"
void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CChildSocket* pChild = new CChildSocket;
	BOOL check = Accept(*pChild);
	if (check == FALSE) 
	{
		delete pChild;
		return;
	}
	// CListenSocket 객체의주소를CChildSocket 객체에알려주기위한함수를호출
	pChild->SetListenSocket(this); // CChildSocket 클래스에사용자가정의한함수
	AfxMessageBox(_T("Sever Connected"));
	m_ptrChildSocketList.AddTail(pChild);
	//클라이언트가접속해옴을리스트에출력한다. 
	CmyView* pMain = (CmyView*)AfxGetMainWnd();
\
	CAsyncSocket::OnAccept(nErrorCode);
}



void CListenSocket::CloseClientSocket(CSocket* pChild)
{
	// TODO: 여기에 구현 코드 추가.
	POSITION pos;
	pos = m_ptrChildSocketList.Find(pChild);
	if (pos != NULL) 
	{
		if (pChild != NULL) 
		{
			pChild->ShutDown(); //클라이언트에 연결된
			pChild->Close(); //자소켓을 닫는다.
		}
			m_ptrChildSocketList.RemoveAt(pos); //리스트에서 제거한 후
			delete pChild; //메모리를 해제한다.
	}
}


void CListenSocket::BroadCast(char* pszBuffer, int len)
{
	// TODO: 여기에 구현 코드 추가.
	POSITION pos;
	pos = m_ptrChildSocketList.GetHeadPosition();
	CChildSocket* pChild = NULL;
	while (pos != NULL)
	{
		pChild = (CChildSocket*)m_ptrChildSocketList.GetNext(pos);
		if (pChild != NULL)
		{
			pChild->Send(pszBuffer, len);
			
		}
	}
}
