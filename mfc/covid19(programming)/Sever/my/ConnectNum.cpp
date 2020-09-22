// ConnectNum.cpp: 구현 파일
//

#include "pch.h"
#include "my.h"
#include "ConnectNum.h"
#include "afxdialogex.h"


// ConnectNum 대화 상자

IMPLEMENT_DYNAMIC(ConnectNum, CDialog)

ConnectNum::ConnectNum(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, Fhnum(_T(""))
	, Fgnum(_T(""))
{

}

ConnectNum::~ConnectNum()
{
}

void ConnectNum::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Fhnum);
	DDX_Text(pDX, IDC_EDIT2, Fgnum);
}


BEGIN_MESSAGE_MAP(ConnectNum, CDialog)
END_MESSAGE_MAP()


// ConnectNum 메시지 처리기
