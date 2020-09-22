
// ChattingClientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ChattingClient.h"
#include "ChattingClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChattingClientDlg 대화 상자



CChattingClientDlg::CChattingClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHATTINGCLIENT_DIALOG, pParent)
	, m_strData(_T(""))
	, m_Ptr(_T(""))
	, select(0)
	, ZNum(_T(""))
	, FNum(_T(""))
	, SNum(_T(""))
	, TNum(_T(""))
	, FourthNum(_T(""))
	, NineNum(_T(""))
	, STime(_T(""))
	, PatientRate(_T(""))
	, HealRate(_T(""))
	, FinishCause(_T(""))
	, FiveNum(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChattingClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strData);
	DDX_Control(pDX, IDC_BUTTON_SEND, m_ButtonSend);
	DDX_Control(pDX, IDC_BUTTON_CONNECT, m_ButtonConnect);
	DDX_Text(pDX, IDC_EDIT2, m_Ptr);
	DDV_MaxChars(pDX, m_Ptr, 3);
	DDV_MaxChars(pDX, m_strData, 4);
	DDX_Radio(pDX, IDC_RADIO1, select);
	DDX_Control(pDX, IDC_BUTTON_Play, m_ButtonPLAY);
	DDX_Text(pDX, IDC_EDIT3, ZNum);
	DDX_Text(pDX, IDC_EDIT4, FNum);
	DDX_Text(pDX, IDC_EDIT5, SNum);
	DDX_Text(pDX, IDC_EDIT6, TNum);
	DDX_Text(pDX, IDC_EDIT7, FourthNum);
	DDX_Text(pDX, IDC_EDIT13, STime);
	DDX_Text(pDX, IDC_EDIT14, PatientRate);
	DDX_Text(pDX, IDC_EDIT15, HealRate);
	DDX_Text(pDX, IDC_EDIT16, FinishCause);
	DDX_Text(pDX, IDC_EDIT8, FiveNum);
	DDX_Control(pDX, IDC_BUTTON3, Stop);
}

BEGIN_MESSAGE_MAP(CChattingClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CChattingClientDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CChattingClientDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_RADIO2, &CChattingClientDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON_Play, &CChattingClientDlg::OnBnClickedButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON3, &CChattingClientDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CChattingClientDlg 메시지 처리기

BOOL CChattingClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChattingClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChattingClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChattingClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include "CConnectDlg.h"

void CChattingClientDlg::OnBnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CConnectDlg dlg;
	if (dlg.DoModal() == IDOK) 
	{
		
		m_Socket.Create();
		if(m_Socket.Connect(dlg.m_strAddress, 7000) == FALSE)
		{ //서버연결이실패하였으므로프로그램을종료한다. // 
		  AfxMessageBox(_T("Failed to connect server"));
		  PostQuitMessage(0);
		}
		AfxMessageBox(_T("Sever Connected"));
		m_Socket.Connect(dlg.m_strAddress, 7000);
		m_ButtonPLAY.EnableWindow(TRUE);
		// 시작 버튼 활성화
		// <보내기> 버튼활성화
		m_ButtonSend.EnableWindow(TRUE);
		// <서버연결...> 버튼비활성화
		m_ButtonConnect.EnableWindow(FALSE);
		Stop.EnableWindow(TRUE);
	}
}


void CChattingClientDlg::OnBnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	/*m_strData1 = m_strData;
	m_Ptr1 = m_Ptr;
	m_strData.AppendChar('+');
	m_Ptr.AppendChar('-');
	m_select.Format(_T("%d"), select);
	m_select.AppendChar('*');*/
	//사용자가입력한메시지를서버에전송한다. //※전송된메시지를서버가정상적으로수신하면
	// 이를다시재전송받게되며이때리스트에출력된다.(const char*)
	/*if ((m_strData.GetLength()+ m_Ptr.GetLength()) % 2 == 1)
	{
		m_Ptr.AppendChar(' ');
	}*/
	Send1.Format(_T("%04d%03d%01d"), _ttoi(m_strData), _ttoi(m_Ptr), _ttoi(m_select));
	m_Socket.Send((LPCTSTR)Send1, 1024);
	UpdateData(0);
	
}


void CChattingClientDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CChattingClientDlg::OnBnClickedButtonPlay()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ButtonPlay.AppendChar('/');
	m_Socket.Send((LPCTSTR)m_ButtonPlay, 1024);

}


void CChattingClientDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ButtonStop.AppendChar('^');
	m_Socket.Send((LPCTSTR)m_ButtonStop, 1024);
}
