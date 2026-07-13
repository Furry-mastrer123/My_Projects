
// DialogDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CDialogDlg
class CDialogDlg : public CDialogEx
{
// Создание
public:
	CDialogDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int hours;
	CEdit HourControl;
	int minutes;
	CEdit MinutesControl;
	int Seconds;
	CEdit SecondsControl;
	CButton ToHoursControl;
	CButton ToSecControl;
	CEdit FullSecControl;
	int FullSeconds;
	afx_msg void OnBnClickedBeginop();
	afx_msg void OnBnClickedRadiotofullsec();
	afx_msg void OnBnClickedRadiofromfullsec();
	afx_msg void OnBnClickedExit();
};
