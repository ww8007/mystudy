#pragma once

// CChildSocket 명령 대상

class CChildSocket : public CSocket
{
public:
	CChildSocket();
	CAsyncSocket* m_pListenSocket;
	virtual ~CChildSocket();
	void SetListenSocket(CAsyncSocket* pSocket);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	int cnt=0;
	int j = 0;
	int k = 0;
	int m = 0;
};


