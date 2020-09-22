// CClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "ChattingClient.h"
#include "CClientSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 멤버 함수


void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ShutDown();
	Close();
	CSocket::OnClose(nErrorCode);
	AfxMessageBox(_T("ERROR : Disconnected from server!"));
}


#include "ChattingClientDlg.h"
void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	char szBuffer[1024];
	::ZeroMemory(szBuffer, 1024);
	int len;
	
	//실제로데이터를수신한다.
	CChattingClientDlg* pMain = (CChattingClientDlg*)AfxGetMainWnd();
	if (len = Receive(szBuffer, 1024) > 0)
	{
		int count = 0;
		int number = 5;
		pMain->ZNum.AppendChar(szBuffer[0]);
		pMain->ZNum.AppendChar(szBuffer[2]);
		pMain->ZNum.AppendChar(szBuffer[4]);

		pMain->FNum.AppendChar(szBuffer[6]);
		pMain->FNum.AppendChar(szBuffer[8]);
		pMain->FNum.AppendChar(szBuffer[10]);

		pMain->SNum.AppendChar(szBuffer[12]);
		pMain->SNum.AppendChar(szBuffer[14]);
		pMain->SNum.AppendChar(szBuffer[16]);

		pMain->TNum.AppendChar(szBuffer[18]);
		pMain->TNum.AppendChar(szBuffer[20]);
		pMain->TNum.AppendChar(szBuffer[22]);

		pMain->FourthNum.AppendChar(szBuffer[24]);
		pMain->FourthNum.AppendChar(szBuffer[26]);
		pMain->FourthNum.AppendChar(szBuffer[28]);

		pMain->FiveNum.AppendChar(szBuffer[30]);
		pMain->FiveNum.AppendChar(szBuffer[32]);
		pMain->FiveNum.AppendChar(szBuffer[34]);

		pMain->STime.AppendChar(szBuffer[36]);
		pMain->STime.AppendChar(szBuffer[38]);

		pMain->PatientRate.AppendChar(szBuffer[40]);
		pMain->PatientRate.AppendChar(szBuffer[42]);
		pMain->PatientRate.AppendChar(szBuffer[44]);

		pMain->HealRate.AppendChar(szBuffer[46]);
		pMain->HealRate.AppendChar(szBuffer[48]);
		pMain->HealRate.AppendChar(szBuffer[50]);

		if (szBuffer[52] == '7')
			pMain->FinishCause = "Time out";
		else if (szBuffer[52] == '5')
			pMain->FinishCause = "Press Stop";
		else if (szBuffer[52] == '9')
			pMain->FinishCause = "Key Down CTRL+X";
		else if (szBuffer[52] == '6')
			pMain->FinishCause = "All infecetee or Regainer";
		else if (szBuffer[52] == '8')
			pMain->FinishCause = "All infetee be Regainer";
		/*for (i = 0; i < 4; i++)
		{
			pMain->ZNum.AppendChar(szBuffer[count]);
			count += 2;
		}
		count = 8;
		for (i = 0; i < 4; i++)
		{
			pMain->FNum.AppendChar(szBuffer[count]);
			count += 2;
		}
		count = 16;
		for (i = 0; i < 4; i++)
		{
			pMain->SNum.AppendChar(szBuffer[count]);
			count += 2;
		}
		count = 24;
		for (i = 0; i < 4; i++)
		{
			pMain->TNum.AppendChar(szBuffer[count]);
			count += 2;
		}
		count = 32;
		for (i = 0; i < 4; i++)
		{
			pMain->FourthNum.AppendChar(szBuffer[count]);
			count += 2;
		}
		count = 40;
		for (i = 0; i < 4; i++)
		{
			pMain->FiveNum.AppendChar(szBuffer[count]);
			count += 2;
		}
		count = 48;
		for (i = 0; i < 4; i++)
		{
			pMain->STime.AppendChar(szBuffer[count]);
			count += 2;
		}
		count = 56;
		for (i = 0; i < 4; i++)
		{
			pMain->PatientRate.AppendChar(szBuffer[count]);
			count += 2;
		}
		if (szBuffer[64] == '9')
		{
			pMain->FinishCause = "Time out";
		}
		else if (szBuffer[64] == '7')
		{
			pMain->FinishCause = "Button stop";
		}*/
		
	}
	pMain->UpdateData(0);
	CSocket::OnReceive(nErrorCode);
}
