
// ChattingClientDlg.h: 헤더 파일
//

#pragma once
#include "CClientSocket.h"

// CChattingClientDlg 대화 상자
class CChattingClientDlg : public CDialog
{
// 생성입니다.
public:
	CChattingClientDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CClientSocket m_Socket;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATTINGCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Send1;
	CString m_Ptr;
	CString m_strData;
	CString m_Ptr1;
	CString m_strData1;
	CButton m_ButtonSend;
	CButton m_ButtonConnect;
	CString m_select;
	CString m_ButtonPlay;
	CString m_ButtonStop;
	CString Trash;
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonSend();
	
	int select;
	afx_msg void OnBnClickedRadio2();
	CButton m_ButtonPLAY;
	afx_msg void OnBnClickedButtonPlay();
	CString ZNum;
	CString FNum;
	CString SNum;
	CString TNum;
	CString FourthNum;
	CString SixNum;
	CString SevenNum;
	CString EightNum;
	CString NineNum;
	CString STime;
	CString PatientRate; //환자비율
	CString HealRate; //회복자 비율
	CString FinishCause;
	CString FiveNum;
	CButton Stop;
	afx_msg void OnBnClickedButton3();
};
