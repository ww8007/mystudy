#pragma once

// CListenSocket 명령 대상
#include "CChildSocket.h"
class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();
	CChildSocket m_Socket;
	CPtrList m_ptrChildSocketList;
	virtual void OnAccept(int nErrorCode);
	void CloseClientSocket(CSocket* pChild);
	void BroadCast(char* pszBuffer, int len);
};


