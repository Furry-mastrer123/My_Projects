
// Dialog.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CDialogApp:
// Сведения о реализации этого класса: Dialog.cpp
//

class CDialogApp : public CWinApp
{
public:
	CDialogApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CDialogApp theApp;
