//stamp:0af2a799fb21cedc
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				wnd_composition = _T("LAYOUT:wnd_composition");
				wnd_status_bar = _T("LAYOUT:wnd_status_bar");
			}
			const TCHAR * wnd_composition;
			const TCHAR * wnd_status_bar;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
				logo_32 = _T("IMG:logo_32");
				png_charmode = _T("IMG:png_charmode");
				png_charmode_full = _T("IMG:png_charmode_full");
				png_charmode_half = _T("IMG:png_charmode_half");
				png_status1 = _T("IMG:png_status1");
				png_status2 = _T("IMG:png_status2");
				png_composition = _T("IMG:png_composition");
				btn_extend = _T("IMG:btn_extend");
				btn_shrink = _T("IMG:btn_shrink");
				btn_makeword = _T("IMG:btn_makeword");
				btn_prevpage = _T("IMG:btn_prevpage");
				btn_nextpage = _T("IMG:btn_nextpage");
				btn_query = _T("IMG:btn_query");
				btn_record_enable = _T("IMG:btn_record_enable");
				btn_record_disable = _T("IMG:btn_record_disable");
				btn_sound_enable = _T("IMG:btn_sound_enable");
				btn_sound_disable = _T("IMG:btn_sound_disable");
			}
			const TCHAR * logo_32;
			const TCHAR * png_charmode;
			const TCHAR * png_charmode_full;
			const TCHAR * png_charmode_half;
			const TCHAR * png_status1;
			const TCHAR * png_status2;
			const TCHAR * png_composition;
			const TCHAR * btn_extend;
			const TCHAR * btn_shrink;
			const TCHAR * btn_makeword;
			const TCHAR * btn_prevpage;
			const TCHAR * btn_nextpage;
			const TCHAR * btn_query;
			const TCHAR * btn_record_enable;
			const TCHAR * btn_record_disable;
			const TCHAR * btn_sound_enable;
			const TCHAR * btn_sound_disable;
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
		class _smenu{
			public:
			_smenu(){
				context = _T("smenu:context");
			}
			const TCHAR * context;
		}smenu;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_charmode",65545},
		{L"btn_makeword",65546},
		{L"btn_nextpage",65539},
		{L"btn_prevpage",65537},
		{L"btn_record",65547},
		{L"btn_sound",65548},
		{L"btn_status_mode",65543},
		{L"cand_container",65538},
		{L"img_logo",65541},
		{L"statu_line2",65544},
		{L"status_line1",65540},
		{L"txt_comp",65542},
		{L"txt_comps",65536}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_charmode = namedXmlID[1].strName;
			btn_makeword = namedXmlID[2].strName;
			btn_nextpage = namedXmlID[3].strName;
			btn_prevpage = namedXmlID[4].strName;
			btn_record = namedXmlID[5].strName;
			btn_sound = namedXmlID[6].strName;
			btn_status_mode = namedXmlID[7].strName;
			cand_container = namedXmlID[8].strName;
			img_logo = namedXmlID[9].strName;
			statu_line2 = namedXmlID[10].strName;
			status_line1 = namedXmlID[11].strName;
			txt_comp = namedXmlID[12].strName;
			txt_comps = namedXmlID[13].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_charmode;
		 const wchar_t * btn_makeword;
		 const wchar_t * btn_nextpage;
		 const wchar_t * btn_prevpage;
		 const wchar_t * btn_record;
		 const wchar_t * btn_sound;
		 const wchar_t * btn_status_mode;
		 const wchar_t * cand_container;
		 const wchar_t * img_logo;
		 const wchar_t * statu_line2;
		 const wchar_t * status_line1;
		 const wchar_t * txt_comp;
		 const wchar_t * txt_comps;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_charmode	=	65545;
		const static int btn_makeword	=	65546;
		const static int btn_nextpage	=	65539;
		const static int btn_prevpage	=	65537;
		const static int btn_record	=	65547;
		const static int btn_sound	=	65548;
		const static int btn_status_mode	=	65543;
		const static int cand_container	=	65538;
		const static int img_logo	=	65541;
		const static int statu_line2	=	65544;
		const static int status_line1	=	65540;
		const static int txt_comp	=	65542;
		const static int txt_comps	=	65536;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int cand_comp	=	1;
		const static int cand_index	=	2;
		const static int cand_text	=	3;
		const static int cand_wild	=	4;
		const static int gray	=	5;
		const static int green	=	6;
		const static int red	=	7;
		const static int white	=	8;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
