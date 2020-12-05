/**
	* \file DlgWznmVerGenjtr.h
	* API code for job DlgWznmVerGenjtr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVERGENJTR_H
#define DLGWZNMVERGENJTR_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmVerGenjtrDit DlgWznmVerGenjtr::VecVDit
#define VecVDlgWznmVerGenjtrDo DlgWznmVerGenjtr::VecVDo
#define VecVDlgWznmVerGenjtrSge DlgWznmVerGenjtr::VecVSge

#define ContIacDlgWznmVerGenjtr DlgWznmVerGenjtr::ContIac
#define ContInfDlgWznmVerGenjtr DlgWznmVerGenjtr::ContInf
#define ContInfDlgWznmVerGenjtrLfi DlgWznmVerGenjtr::ContInfLfi
#define StatAppDlgWznmVerGenjtr DlgWznmVerGenjtr::StatApp
#define StatShrDlgWznmVerGenjtr DlgWznmVerGenjtr::StatShr
#define StatShrDlgWznmVerGenjtrLfi DlgWznmVerGenjtr::StatShrLfi
#define TagDlgWznmVerGenjtr DlgWznmVerGenjtr::Tag
#define TagDlgWznmVerGenjtrGjt DlgWznmVerGenjtr::TagGjt
#define TagDlgWznmVerGenjtrLfi DlgWznmVerGenjtr::TagLfi

#define DpchAppDlgWznmVerGenjtrData DlgWznmVerGenjtr::DpchAppData
#define DpchAppDlgWznmVerGenjtrDo DlgWznmVerGenjtr::DpchAppDo
#define DpchEngDlgWznmVerGenjtrData DlgWznmVerGenjtr::DpchEngData

/**
	* DlgWznmVerGenjtr
	*/
namespace DlgWznmVerGenjtr {
	/**
		* VecVDit (full: VecVDlgWznmVerGenjtrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint GJT = 1;
		static const Sbecore::uint LFI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmVerGenjtrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint GJTBUTRUNCLICK = 1;
		static const Sbecore::uint GJTBUTSTOCLICK = 2;
		static const Sbecore::uint BUTDNECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerGenjtrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGER = 2;
		static const Sbecore::uint GENQTB = 3;
		static const Sbecore::uint GENJOB = 4;
		static const Sbecore::uint GENCALL = 5;
		static const Sbecore::uint GENCTP = 6;
		static const Sbecore::uint ASMLFI = 7;
		static const Sbecore::uint FAIL = 8;
		static const Sbecore::uint DONE = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVerGenjtr)
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
	  * ContInf (full: ContInfDlgWznmVerGenjtr)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint GJTTXTPRG = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& GjtTxtPrg = "");

	public:
		Sbecore::uint numFSge;
		std::string GjtTxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmVerGenjtrLfi)
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
	  * StatApp (full: StatAppDlgWznmVerGenjtr)
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
	  * StatShr (full: StatShrDlgWznmVerGenjtr)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint GJTBUTRUNACTIVE = 1;
		static const Sbecore::uint GJTBUTSTOACTIVE = 2;
		static const Sbecore::uint BUTDNEACTIVE = 3;

	public:
		StatShr(const bool GjtButRunActive = true, const bool GjtButStoActive = true, const bool ButDneActive = true);

	public:
		bool GjtButRunActive;
		bool GjtButStoActive;
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWznmVerGenjtrLfi)
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
	  * Tag (full: TagDlgWznmVerGenjtr)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint GJTBUTRUN = 2;
		static const Sbecore::uint GJTBUTSTO = 3;
		static const Sbecore::uint BUTDNE = 4;

	public:
		Tag(const std::string& Cpt = "", const std::string& GjtButRun = "", const std::string& GjtButSto = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string GjtButRun;
		std::string GjtButSto;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagGjt (full: TagDlgWznmVerGenjtrGjt)
	  */
	class TagGjt : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;

	public:
		TagGjt(const std::string& CptPrg = "");

	public:
		std::string CptPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgWznmVerGenjtrLfi)
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
		* DpchAppData (full: DpchAppDlgWznmVerGenjtrData)
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
		* DpchAppDo (full: DpchAppDlgWznmVerGenjtrDo)
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
		* DpchEngData (full: DpchEngDlgWznmVerGenjtrData)
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
		static const Sbecore::uint TAGGJT = 11;
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
		TagGjt taggjt;
		TagLfi taglfi;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

