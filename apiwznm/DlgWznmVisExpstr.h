/**
	* \file DlgWznmVisExpstr.h
	* API code for job DlgWznmVisExpstr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVISEXPSTR_H
#define DLGWZNMVISEXPSTR_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmVisExpstrDit DlgWznmVisExpstr::VecVDit
#define VecVDlgWznmVisExpstrDo DlgWznmVisExpstr::VecVDo
#define VecVDlgWznmVisExpstrDoWri DlgWznmVisExpstr::VecVDoWri
#define VecVDlgWznmVisExpstrSge DlgWznmVisExpstr::VecVSge

#define ContIacDlgWznmVisExpstr DlgWznmVisExpstr::ContIac
#define ContInfDlgWznmVisExpstr DlgWznmVisExpstr::ContInf
#define ContInfDlgWznmVisExpstrMfi DlgWznmVisExpstr::ContInfMfi
#define ContInfDlgWznmVisExpstrWri DlgWznmVisExpstr::ContInfWri
#define StatAppDlgWznmVisExpstr DlgWznmVisExpstr::StatApp
#define StatShrDlgWznmVisExpstr DlgWznmVisExpstr::StatShr
#define StatShrDlgWznmVisExpstrMfi DlgWznmVisExpstr::StatShrMfi
#define StatShrDlgWznmVisExpstrWri DlgWznmVisExpstr::StatShrWri
#define TagDlgWznmVisExpstr DlgWznmVisExpstr::Tag
#define TagDlgWznmVisExpstrMfi DlgWznmVisExpstr::TagMfi
#define TagDlgWznmVisExpstrWri DlgWznmVisExpstr::TagWri

#define DpchAppDlgWznmVisExpstrData DlgWznmVisExpstr::DpchAppData
#define DpchAppDlgWznmVisExpstrDo DlgWznmVisExpstr::DpchAppDo
#define DpchEngDlgWznmVisExpstrData DlgWznmVisExpstr::DpchEngData

/**
	* DlgWznmVisExpstr
	*/
namespace DlgWznmVisExpstr {
	/**
		* VecVDit (full: VecVDlgWznmVisExpstrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint WRI = 1;
		static const Sbecore::uint MFI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmVisExpstrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWri (full: VecVDlgWznmVisExpstrDoWri)
		*/
	class VecVDoWri {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVisExpstrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint EXPORT = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVisExpstr)
	  */
	class ContIac : public Sbecore::Block {

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
	  * ContInf (full: ContInfDlgWznmVisExpstr)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfMfi (full: ContInfDlgWznmVisExpstrMfi)
	  */
	class ContInfMfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfMfi(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfMfi* comp);
		std::set<Sbecore::uint> diff(const ContInfMfi* comp);
	};

	/**
	  * ContInfWri (full: ContInfDlgWznmVisExpstrWri)
	  */
	class ContInfWri : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfWri(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfWri* comp);
		std::set<Sbecore::uint> diff(const ContInfWri* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmVisExpstr)
	  */
	class StatApp : public Sbecore::Block {

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
	  * StatShr (full: StatShrDlgWznmVisExpstr)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StatShrMfi (full: StatShrDlgWznmVisExpstrMfi)
	  */
	class StatShrMfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrMfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrMfi* comp);
		std::set<Sbecore::uint> diff(const StatShrMfi* comp);
	};

	/**
	  * StatShrWri (full: StatShrDlgWznmVisExpstrWri)
	  */
	class StatShrWri : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrWri(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrWri* comp);
		std::set<Sbecore::uint> diff(const StatShrWri* comp);
	};

	/**
	  * Tag (full: TagDlgWznmVisExpstr)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint BUTDNE = 2;

	public:
		Tag(const std::string& Cpt = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagMfi (full: TagDlgWznmVisExpstrMfi)
	  */
	class TagMfi : public Sbecore::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagMfi(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagWri (full: TagDlgWznmVisExpstrWri)
	  */
	class TagWri : public Sbecore::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagWri(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVisExpstrData)
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
		* DpchAppDo (full: DpchAppDlgWznmVisExpstrDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOWRI = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoWri = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoWri;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVisExpstrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFMFI = 4;
		static const Sbecore::uint CONTINFWRI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRMFI = 10;
		static const Sbecore::uint STATSHRWRI = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGMFI = 13;
		static const Sbecore::uint TAGWRI = 14;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfMfi continfmfi;
		ContInfWri continfwri;
		Sbecore::Feed feedFDse;
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrMfi statshrmfi;
		StatShrWri statshrwri;
		Tag tag;
		TagMfi tagmfi;
		TagWri tagwri;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
