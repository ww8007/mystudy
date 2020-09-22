#pragma once


// ResultDlg 대화 상자

class ResultDlg : public CDialog
{
	DECLARE_DYNAMIC(ResultDlg)

public:
	ResultDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString Zeronum1;
	CString Onenum1;
	CString Twonum1;
	CString Threenum1;
	CString Fournum1;
	CString Fivenum1;
	CString Sixnum1;
	CString Sevennum1;
	CString Eightnum1;
	CString Ninenum1;
	CString ProgramTime1;
	CString YesGermnum1;
	CString Healnum1;
	CString ProgramStatus;
};
