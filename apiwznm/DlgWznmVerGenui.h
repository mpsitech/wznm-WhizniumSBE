/**
	* \file DlgWznmVerGenui.h
	* API code for job DlgWznmVerGenui (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef DLGWZNMVERGENUI_H
#define DLGWZNMVERGENUI_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmVerGenuiDit DlgWznmVerGenui::VecVDit
#define VecVDlgWznmVerGenuiDo DlgWznmVerGenui::VecVDo
#define VecVDlgWznmVerGenuiSge DlgWznmVerGenui::VecVSge

#define ContIacDlgWznmVerGenui DlgWznmVerGenui::ContIac
#define ContInfDlgWznmVerGenui DlgWznmVerGenui::ContInf
#define ContInfDlgWznmVerGenuiLfi DlgWznmVerGenui::ContInfLfi
#define StatAppDlgWznmVerGenui DlgWznmVerGenui::StatApp
#define StatShrDlgWznmVerGenui DlgWznmVerGenui::StatShr
#define StatShrDlgWznmVerGenuiLfi DlgWznmVerGenui::StatShrLfi
#define TagDlgWznmVerGenui DlgWznmVerGenui::Tag
#define TagDlgWznmVerGenuiGui DlgWznmVerGenui::TagGui
#define TagDlgWznmVerGenuiLfi DlgWznmVerGenui::TagLfi

#define DpchAppDlgWznmVerGenuiData DlgWznmVerGenui::DpchAppData
#define DpchAppDlgWznmVerGenuiDo DlgWznmVerGenui::DpchAppDo
#define DpchEngDlgWznmVerGenuiData DlgWznmVerGenui::DpchEngData

/**
	* DlgWznmVerGenui
	*/
namespace DlgWznmVerGenui {
	/**
		* VecVDit (full: VecVDlgWznmVerGenuiDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint GUI = 1;
		static const Sbecore::uint LFI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmVerGenuiDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint GUIBUTRUNCLICK = 1;
		static const Sbecore::uint GUIBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerGenuiSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGER = 2;
		static const Sbecore::uint GENUI = 3;
		static const Sbecore::uint GENCTP = 4;
		static const Sbecore::uint ASMLFI = 5;
		static const Sbecore::uint FAIL = 6;
		static const Sbecore::uint DONE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVerGenui)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDSE = 1;

	public:
		ContIac(const Sbecore::uint numFDse = 1);

	public:
		Sbecore::uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmVerGenui)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint GUITXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& GuiTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string GuiTxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmVerGenuiLfi)
	  */
	class ContInfLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfLfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfLfi* comp);
		std::set<Sbecore::uint> diff(const ContInfLfi* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmVerGenui)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint INITDONE = 1;
		static const Sbecore::uint SHORTMENU = 2;

	public:
		StatApp(const bool initdone = false, const std::string& shortMenu = "");

	public:
		bool initdone;
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWznmVerGenui)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint GUIBUTRUNACTIVE = 1;
		static const Sbecore::uint GUIBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool GuiButRunActive = true, const bool GuiButStoActive = true, const bool ButDneActive = true);

	public:
		bool GuiButRunActive;
		bool GuiButStoActive;
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWznmVerGenuiLfi)
	  */
	class StatShrLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrLfi* comp);
		std::set<Sbecore::uint> diff(const StatShrLfi* comp);
	};

	/**
	  * Tag (full: TagDlgWznmVerGenui)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint GUIBUTRUN = 2;
		static const Sbecore::uint GUIBUTSTO = 3;
		static const Sbecore::uint BUTDNE = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& GuiButRun = "", const std::string& GuiButSto = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string GuiButRun;
		std::string GuiButSto;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagGui (full: TagDlgWznmVerGenuiGui)
	  */
	class TagGui : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;

	public:
		TagGui(const std::string& CptPrg = "");

	public:
		std::string CptPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgWznmVerGenuiLfi)
	  */
	class TagLfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagLfi(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVerGenuiData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVerGenuiDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVerGenuiData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFLFI = 4;
		static const Sbecore::uint FEEDFDSE = 5;
		static const Sbecore::uint FEEDFSGE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint STATSHRLFI = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint TAGGUI = 11;
		static const Sbecore::uint TAGLFI = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfLfi continflfi;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrLfi statshrlfi;
		Tag tag;
		TagGui taggui;
		TagLfi taglfi;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

