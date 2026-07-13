#include <afxwin.h>
#include "resource.h"
#include <afxext.h>

class CmyWND : public CFrameWnd
{
public:
	CToolBar bar;
	CStatusBar Sbar;
	const UINT arr[4] = { IDS_height, IDS_width, IDS_x, IDS_y };
	CmyWND()
	{
		Create(NULL, L"My first MFC APP",WS_OVERLAPPEDWINDOW,CRect(5,5,500,200),
			NULL, MAKEINTRESOURCE(IDR_MENU1));
		bar.Create(this);
		bar.LoadToolBar(IDR_TOOLBAR1);
		Sbar.Create(this);
		Sbar.SetIndicators(arr, 4);
		Sbar.SetPaneInfo(0, arr[0], SBPS_STRETCH, 10);
		Sbar.SetPaneInfo(1, arr[1], SBPS_STRETCH, 10);
		Sbar.SetPaneInfo(2, arr[2], SBPS_STRETCH, 10);
		Sbar.SetPaneInfo(3, arr[3], SBPS_STRETCH, 10);
		Sbar.SetPaneText(0, (LPCTSTR)"0", 1);
		Sbar.SetPaneText(1, (LPCTSTR)"0", 1);
		Sbar.SetPaneText(2, (LPCTSTR)"0", 1);
		Sbar.SetPaneText(3, (LPCTSTR)"0", 1);
	}
	void OnSize(UINT ntype, int x, int y);
	void CloseWND();
	void MINIMIZE();
	void MAXIMIZE();
	void OnMove(int x, int y);
	DECLARE_MESSAGE_MAP();
};

class CmyApp : public CWinApp
{
public:
	virtual BOOL InitInstance() override
	{
		m_pMainWnd = new CmyWND();
		m_pMainWnd->ShowWindow(m_nCmdShow);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}
};

CmyApp app;

void CmyWND::CloseWND()
{
	DestroyWindow();
}

void CmyWND::MINIMIZE()
{
	ShowWindow(SW_SHOWMINIMIZED);
}

void CmyWND::MAXIMIZE()
{
	ShowWindow(SW_SHOWMAXIMIZED);
}

void CmyWND::OnSize(UINT nType, int x, int y)
{
	CString str;
	str.Format(L"Height: %d", x);
	Sbar.SetPaneText(0, str, 1);
	str.Format(L"Width is %i", y);
	Sbar.SetPaneText(1, str, 1);
	CFrameWnd::OnSize(nType, x, y);
}

void CmyWND::OnMove(int x, int y)
{
	CString str;
	str.Format(L"x: %d", x);
	Sbar.SetPaneText(2, str, 1);
	str.Format(L"y is %i", y);
	Sbar.SetPaneText(3, str, 1);
	CFrameWnd::OnMove(x, y);
}


BEGIN_MESSAGE_MAP(CmyWND, CFrameWnd)
	ON_COMMAND(IDR_CLOSE, CloseWND)
	ON_COMMAND(IDR_MAXIMIZE, MAXIMIZE)
	ON_COMMAND(IDR_MINIMIZE, MINIMIZE)
	ON_COMMAND(ID_CLOSE, CloseWND)
	ON_COMMAND(ID_MAXIMIZE, MAXIMIZE)
	ON_COMMAND(ID_MINIMIZE, MINIMIZE)
	ON_WM_SIZE()
	ON_WM_MOVE()
	END_MESSAGE_MAP()