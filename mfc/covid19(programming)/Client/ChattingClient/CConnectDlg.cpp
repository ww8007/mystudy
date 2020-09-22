// CConnectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ChattingClient.h"
#include "CConnectDlg.h"
#include "afxdialogex.h"


// CConnectDlg 대화 상자

IMPLEMENT_DYNAMIC(CConnectDlg, CDialog)

CConnectDlg::CConnectDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CConnectDlg::~CConnectDlg()
{
}

void CConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConnectDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CConnectDlg::OnBnClickedOk)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &CConnectDlg::OnIpnFieldchangedIpaddress1)
END_MESSAGE_MAP()


// CConnectDlg 메시지 처리기


void CConnectDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_IPADDRESS1, m_strAddress);
	CDialog::OnOK();
}


BOOL CConnectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CDialog::OnInitDialog();
	SetDlgItemText(IDC_IPADDRESS1, _T("127.0.0.1"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CConnectDlg::OnIpnFieldchangedIpaddress1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
