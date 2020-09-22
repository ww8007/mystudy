// DlgHumanMake.cpp: 구현 파일
//

#include "pch.h"
#include "my.h"
#include "DlgHumanMake.h"
#include "afxdialogex.h"


// DlgHumanMake 대화 상자

IMPLEMENT_DYNAMIC(DlgHumanMake, CDialog)

DlgHumanMake::DlgHumanMake(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, Fhhnum(0)
	, Fggnum(0)
	, SSSSelect(0)
{

}

DlgHumanMake::~DlgHumanMake()
{
}

void DlgHumanMake::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Fhhnum);
	DDX_Text(pDX, IDC_EDIT2, Fggnum);
	DDX_Control(pDX, IDC_RADIO1, SSSelect);
	DDX_Radio(pDX, IDC_RADIO1, SSSSelect);
}


BEGIN_MESSAGE_MAP(DlgHumanMake, CDialog)
END_MESSAGE_MAP()


// DlgHumanMake 메시지 처리기
