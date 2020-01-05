// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <helper/SAdapterBase.h>
#include "DataCenter.h"

class CGroupAdapter : public SMcAdapterBase
{
public:
	void AddGroup(const GROUPINFO & gi)
	{
		m_arrGroupInfo.Add(gi);
	}

	void RemoveAll()
	{
		m_arrGroupInfo.RemoveAll();
		notifyDataSetChanged();
	}
protected:

	virtual int getCount()
	{
		return m_arrGroupInfo.GetCount();
	}

	virtual void getView(int position, SWindow * pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}
		SCheckBox *pCheck = pItem->FindChildByID2<SCheckBox>(R.id.chk_group_name);
		pCheck->SetWindowText(S_CA2T(m_arrGroupInfo[position].szName));
		subscribeCheckEvent(pCheck);
		pCheck->GetEventSet()->setMutedState(true);
		pCheck->SetCheck(m_arrGroupInfo[position].bValid);
		pCheck->GetEventSet()->setMutedState(false);

		pItem->FindChildByID(R.id.txt_group_size)->SetWindowText(SStringT().Format(_T("%d"), m_arrGroupInfo[position].dwCount));
		pItem->FindChildByID(R.id.txt_editor)->SetWindowText(S_CA2T(m_arrGroupInfo[position].szEditor));
		pItem->FindChildByID(R.id.txt_remark)->SetWindowText(S_CA2T(m_arrGroupInfo[position].szRemark));
	}

	virtual SStringW GetColumnName(int iCol) const {
		const wchar_t * pszColNames[] = {
			L"col_group",L"col_size",L"col_editor",L"col_remark"
		};
		return pszColNames[iCol];
	}

	virtual void subscribeCheckEvent(SCheckBox *pCheck)
	{
	}
protected:
	SArray<GROUPINFO> m_arrGroupInfo;
};

class CMainDlg : public SHostWnd, public TAutoEventMapReg<CMainDlg>
{
	SAutoRefPtr<CGroupAdapter> m_groupAdapter;
	SProgress	* m_prog;
	CDataCenter	  m_dataCenter;
public:
	CMainDlg();
	~CMainDlg();

protected:
	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	bool IsDataReady() const;

protected:
	void OnMenuSelected(EventArgs *e);

	void OnProgStart(EventArgs *e);
	void OnProgRun(EventArgs *e);
	void OnProgEnd(EventArgs *e);

	void OnGroupChanged();

	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_HANDLER(EventSelectMenu::EventID,OnMenuSelected)
		EVENT_HANDLER(EventProgStart::EventID,OnProgStart)
		EVENT_HANDLER(EventProgRun::EventID,OnProgRun)
		EVENT_HANDLER(EventProgEnd::EventID,OnProgEnd)
	EVENT_MAP_END()
		
protected:
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

};
