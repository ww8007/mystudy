// ResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "my.h"
#include "ResultDlg.h"
#include "afxdialogex.h"


// ResultDlg 대화 상자

IMPLEMENT_DYNAMIC(ResultDlg, CDialog)

ResultDlg::ResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, Zeronum1(_T(""))
	, Onenum1(_T(""))
	, Twonum1(_T(""))
	, Threenum1(_T(""))
	, Fournum1(_T(""))
	, Fivenum1(_T(""))
	, ProgramTime1(_T(""))
	, YesGermnum1(_T(""))
	, Healnum1(_T(""))
	, ProgramStatus(_T(""))
{

}

ResultDlg::~ResultDlg()
{
}

void ResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Zeronum1);
	DDX_Text(pDX, IDC_EDIT3, Onenum1);
	DDX_Text(pDX, IDC_EDIT2, Twonum1);
	DDX_Text(pDX, IDC_EDIT4, Threenum1);
	DDX_Text(pDX, IDC_EDIT5, Fournum1);
	DDX_Text(pDX, IDC_EDIT6, Fivenum1);
	DDX_Text(pDX, IDC_EDIT11, ProgramTime1);
	DDX_Text(pDX, IDC_EDIT12, YesGermnum1);
	DDX_Text(pDX, IDC_EDIT14, Healnum1);
	DDX_Text(pDX, IDC_EDIT13, ProgramStatus);
}


BEGIN_MESSAGE_MAP(ResultDlg, CDialog)
END_MESSAGE_MAP()


// ResultDlg 메시지 처리기
