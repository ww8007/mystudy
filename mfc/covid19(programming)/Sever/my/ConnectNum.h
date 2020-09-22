#pragma once


// ConnectNum 대화 상자

class ConnectNum : public CDialog
{
	DECLARE_DYNAMIC(ConnectNum)

public:
	ConnectNum(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ConnectNum();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString Fhnum;
	CString Fgnum;
};
