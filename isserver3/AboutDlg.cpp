// MainDlg.cpp : implementation of the CAboutDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AboutDlg.h"	
#include "../helper/helper.h"

CAboutDlg::CAboutDlg() : SHostDialog(UIRES.LAYOUT.dlg_about)
{
}

CAboutDlg::~CAboutDlg()
{
}

void CAboutDlg::OnClose()
{
	EndDialog(IDOK);
}

SStringT CAboutDlg::GetVersionInfo(DWORD &dwVer)
{
	TCHAR szFileName[MAX_PATH];
	GetModuleFileName(NULL, szFileName, MAX_PATH);
	TCHAR szDesc[200];
	Helper_PEVersion(szFileName, &dwVer, NULL, szDesc);
	return SStringT(szDesc);
}

BOOL CAboutDlg::OnInitDialog(HWND wnd, LPARAM lInitParam)
{
	DWORD dwVer = 0;
	SStringT strDesc = GetVersionInfo(dwVer);
	TCHAR szVer[100];
	Helper_VersionString(dwVer, szVer);
	FindChildByID(R.id.txt_ver)->SetWindowText(szVer);
	FindChildByID(R.id.txt_name)->SetWindowText(strDesc);
	return 0;
}
