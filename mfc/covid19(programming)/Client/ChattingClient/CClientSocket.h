#pragma once

// CClientSocket 명령 대상

class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	int i=0;
	int j=0;
	int k = 0;
	int count = 0;
};


