#pragma once


// DlgHumanMake 대화 상자

class DlgHumanMake : public CDialog
{
	DECLARE_DYNAMIC(DlgHumanMake)

public:
	DlgHumanMake(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgHumanMake();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int Fhhnum;
	int Fggnum;
	CButton SSSelect;
	int SSSSelect;
};
