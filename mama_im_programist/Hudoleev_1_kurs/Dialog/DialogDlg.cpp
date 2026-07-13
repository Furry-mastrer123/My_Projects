
// DialogDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Dialog.h"
#include "DialogDlg.h"
#include "afxdialogex.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
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


// Диалоговое окно CDialogDlg



CDialogDlg::CDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DIALOG, pParent)
	, hours(0)
	, minutes(0)
	, Seconds(0)
	, FullSeconds(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Hours, hours);
	DDV_MinMaxInt(pDX, hours, 0, 23);
	DDX_Control(pDX, IDC_Hours, HourControl);
	DDX_Text(pDX, IDC_Min, minutes);
	DDV_MinMaxInt(pDX, minutes, 0, 59);
	DDX_Control(pDX, IDC_Min, MinutesControl);
	DDX_Text(pDX, IDC_Sec, Seconds);
	DDV_MinMaxInt(pDX, Seconds, 0, 59);
	DDX_Control(pDX, IDC_Sec, SecondsControl);
	DDX_Control(pDX, IDC_RadioFromFullsec, ToHoursControl);
	DDX_Control(pDX, IDC_RadioToFullsec, ToSecControl);
	DDX_Control(pDX, IDC_FullSec, FullSecControl);
	DDX_Text(pDX, IDC_FullSec, FullSeconds);
	DDV_MinMaxInt(pDX, FullSeconds, 0, INT_MAX);
}

BEGIN_MESSAGE_MAP(CDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BeginOp, &CDialogDlg::OnBnClickedBeginop)
	ON_BN_CLICKED(IDC_RadioToFullsec, &CDialogDlg::OnBnClickedRadiotofullsec)
	ON_BN_CLICKED(IDC_RadioFromFullsec, &CDialogDlg::OnBnClickedRadiofromfullsec)
	ON_BN_CLICKED(IDC_Exit, &CDialogDlg::OnBnClickedExit)
END_MESSAGE_MAP()


// Обработчики сообщений CDialogDlg

BOOL CDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	ToSecControl.SetCheck(1);
	OnBnClickedRadiotofullsec();
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogDlg::OnBnClickedBeginop()
{
	UpdateData(TRUE);
	if (ToSecControl.GetCheck() == true)
	{
		FullSeconds = Seconds + hours * 3600 + minutes * 60;
	}
	else if (ToSecControl.GetCheck() == false)
	{
		hours = FullSeconds / 3600;
		minutes = (FullSeconds - hours * 3600) / 60;
		Seconds = FullSeconds - hours * 3600 - minutes * 60;
	}
	UpdateData(FALSE);
		// TODO: добавьте свой код обработчика уведомлений
}


void CDialogDlg::OnBnClickedRadiotofullsec()
{
	HourControl.SetReadOnly(FALSE);
	SecondsControl.SetReadOnly(FALSE);
	MinutesControl.SetReadOnly(FALSE);
	FullSecControl.SetReadOnly(TRUE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CDialogDlg::OnBnClickedRadiofromfullsec()
{
	HourControl.SetReadOnly(TRUE);
	SecondsControl.SetReadOnly(TRUE);
	MinutesControl.SetReadOnly(TRUE);
	FullSecControl.SetReadOnly(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CDialogDlg::OnBnClickedExit()
{
	DestroyWindow();
	// TODO: добавьте свой код обработчика уведомлений
}
