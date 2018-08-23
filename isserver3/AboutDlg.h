// MainDlg.h : interface of the CAboutDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

class CAboutDlg : public SHostDialog
{
public:
	CAboutDlg();
	~CAboutDlg();

	void OnClose();

	static SStringT GetVersionInfo(DWORD &dwVer);
protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
	EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BOOL OnInitDialog(HWND wnd, LPARAM lInitParam);
	BEGIN_MSG_MAP_EX(CAboutDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
};
