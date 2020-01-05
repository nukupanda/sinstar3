// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
#include "../include/FileHelper.h"
#include "GroupInfoDlg.h"
#include <ShellAPI.h>

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
}

CMainDlg::~CMainDlg()
{
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	SMCListView *pPlView= FindChildByID2<SMCListView>(R.id.lv_plgroup);
	m_groupAdapter.Attach(new CGroupAdapter);
	pPlView->SetAdapter(m_groupAdapter);
	m_prog = FindChildByID2<SProgress>(R.id.prog_import);
	return 0;
}
//TODO:消息映射
void CMainDlg::OnClose()
{
	SNativeWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

void CMainDlg::OnMenuSelected(EventArgs *e)
{
	EventSelectMenu *e2=sobj_cast<EventSelectMenu>(e);

	switch(e2->m_id)
	{
	case R.id.menu_exit:
		OnClose();
		break;
	case R.id.menu_help:
		{
			SStringW strHelp = GETSTRING(R.string.help);
			ShellExecute(m_hWnd,_T("open"),strHelp,NULL,NULL,SW_SHOWNORMAL);
		}
		break;
	case R.id.menu_about:
		{
			SHostDialog about(UIRES.LAYOUT.dlg_about);
			about.DoModal();
		}
		break;
	}
	if(!IsDataReady())
		return;

	switch(e2->m_id)
	{
	case R.id.menu_load_sys_lib:
		m_dataCenter.LoadSysPL();
		break;
	case R.id.menu_open_lib:
		{
			CFileDialogEx openDlg(TRUE, _T("spl"), 0, 6, _T("启程词库文件(*.spl)\0*.spl\0All files (*.*)\0*.*\0\0"));
			if(openDlg.DoModal()==IDOK)
			{
				m_dataCenter.LoadPL(openDlg.m_szFileName);
			}
		}
		break;
	case R.id.menu_save_lib:
		{
			CFileDialogEx openDlg(FALSE, _T("spl"), _T("new"), 6, _T("启程词库文件(*.spl)\0*.spl\0All files (*.*)\0*.*\0\0"));
			if(openDlg.DoModal()==IDOK)
			{
				m_dataCenter.SavePL(openDlg.m_szFileName);
			}
		}
		break;
	case R.id.menu_add_group:
		{
			GROUPINFO groupInfo={0};
			CGroupInfoDlg dlg(&groupInfo);
			if(dlg.DoModal()==IDOK)
			{
				m_dataCenter.AddGroup(groupInfo);
				OnGroupChanged();
			}
		}
		break;
	case R.id.menu_modify_group:
		{
			SMCListView *pList = FindChildByID2<SMCListView>(R.id.lv_plgroup);
			int iSel = pList->GetSel();
			if(iSel!=-1)
			{
				const std::vector<GROUPINFO> & group = m_dataCenter.GetGroup();
				GROUPINFO groupInfo = group[iSel];
				CGroupInfoDlg dlg(&groupInfo);
				if(dlg.DoModal()==IDOK)
				{
					m_dataCenter.SetGroup(iSel,groupInfo);
					OnGroupChanged();
				}
			}else
			{
				SMessageBox(m_hWnd,_T("先选择分组!"),_T("提示"),MB_OK|MB_ICONSTOP);
			}
		}
		break;
	case R.id.menu_import_to_group:
		{
			SMCListView *pList = FindChildByID2<SMCListView>(R.id.lv_plgroup);
			int iSel = pList->GetSel();
			if(iSel!=-1)
			{
				CFileDialogEx openDlg(TRUE, _T("txt"), 0, 6, _T("文本词库(*.txt)\0*.txt\0All files (*.*)\0*.*\0\0"));
				if(openDlg.DoModal()==IDOK)
				{
					SStringT strMin = FindChildByID(R.id.edit_rate_min)->GetWindowText();
					SStringT strMax = FindChildByID(R.id.edit_rate_max)->GetWindowText();
					BYTE byMin = (BYTE)_ttoi(strMin);
					BYTE byMax = (BYTE)_ttoi(strMax);
					m_dataCenter.Import2Group(openDlg.m_szFileName,byMin,byMax,iSel);
				}
			}else
			{
				SMessageBox(m_hWnd,_T("先选择分组!"),_T("提示"),MB_OK|MB_ICONSTOP);
			}
		}
		break;
	case R.id.menu_export_from_group:
		{
			SMCListView *pList = FindChildByID2<SMCListView>(R.id.lv_plgroup);
			int iSel = pList->GetSel();
			if(iSel!=-1)
			{
				GROUPINFO groupInfo = m_dataCenter.GetGroup()[iSel];
				SStringT  defName=S_CA2T(groupInfo.szName);
				CFileDialogEx openDlg(FALSE, _T("txt"), defName, 6, _T("文本词库(*.txt)\0*.txt\0All files (*.*)\0*.*\0\0"));
				if(openDlg.DoModal()==IDOK)
				{
					m_dataCenter.ExportGroup(openDlg.m_szFileName,iSel);
				}
			}else
			{
				SMessageBox(m_hWnd,_T("先选择分组!"),_T("提示"),MB_OK|MB_ICONSTOP);
			}
		}
		break;
	case R.id.menu_clear_group:
		m_dataCenter.Clear();
		OnGroupChanged();
		break;
	default:
		break;
	}
}

void CMainDlg::OnProgStart(EventArgs *e)
{
	EventProgStart *e2 = sobj_cast<EventProgStart>(e);
	m_prog->SetVisible(TRUE,TRUE);
	m_prog->SetRange(0,e2->dwMax);
	SLOG_INFO("max="<<e2->dwMax);
}

void CMainDlg::OnProgRun(EventArgs *e)
{
	EventProgRun *e2 = sobj_cast<EventProgRun>(e);
	m_prog->SetValue(e2->dwValue);
	SLOG_INFO("value="<<e2->dwValue<<" max="<<e2->dwMax);
}

void CMainDlg::OnProgEnd(EventArgs *e)
{
	EventProgEnd *e2 = sobj_cast<EventProgEnd>(e);
	m_prog->SetVisible(FALSE,TRUE);
	if(e2->bUpdateUI)
		OnGroupChanged();
	SLOG_INFO("end");
}

void CMainDlg::OnGroupChanged()
{
	m_groupAdapter->RemoveAll();
	const std::vector<GROUPINFO> & group = m_dataCenter.GetGroup();
	for(int i=0;i<group.size();i++)
	{
		m_groupAdapter->AddGroup(group[i]);
	}
	m_groupAdapter->notifyDataSetChanged();
}

bool CMainDlg::IsDataReady() const
{
	if(!m_dataCenter.IsReady())
	{
		SMessageBox(m_hWnd,_T("正在后台整理数据,请稍等"),_T("提示"),MB_OK|MB_ICONSTOP);
		return false;
	}
	return true;
}

