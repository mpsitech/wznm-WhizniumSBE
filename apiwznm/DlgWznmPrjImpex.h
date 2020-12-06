/**
	* \file DlgWznmPrjImpex.h
	* API code for job DlgWznmPrjImpex (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMPRJIMPEX_H
#define DLGWZNMPRJIMPEX_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmPrjImpexDit DlgWznmPrjImpex::VecVDit
#define VecVDlgWznmPrjImpexDo DlgWznmPrjImpex::VecVDo
#define VecVDlgWznmPrjImpexDoImp DlgWznmPrjImpex::VecVDoImp
#define VecVDlgWznmPrjImpexSge DlgWznmPrjImpex::VecVSge

#define ContIacDlgWznmPrjImpex DlgWznmPrjImpex::ContIac
#define ContInfDlgWznmPrjImpex DlgWznmPrjImpex::ContInf
#define ContInfDlgWznmPrjImpexImp DlgWznmPrjImpex::ContInfImp
#define ContInfDlgWznmPrjImpexLfi DlgWznmPrjImpex::ContInfLfi
#define StatAppDlgWznmPrjImpex DlgWznmPrjImpex::StatApp
#define StatShrDlgWznmPrjImpex DlgWznmPrjImpex::StatShr
#define StatShrDlgWznmPrjImpexIfi DlgWznmPrjImpex::StatShrIfi
#define StatShrDlgWznmPrjImpexImp DlgWznmPrjImpex::StatShrImp
#define StatShrDlgWznmPrjImpexLfi DlgWznmPrjImpex::StatShrLfi
#define TagDlgWznmPrjImpex DlgWznmPrjImpex::Tag
#define TagDlgWznmPrjImpexIfi DlgWznmPrjImpex::TagIfi
#define TagDlgWznmPrjImpexImp DlgWznmPrjImpex::TagImp
#define TagDlgWznmPrjImpexLfi DlgWznmPrjImpex::TagLfi

#define DpchAppDlgWznmPrjImpexData DlgWznmPrjImpex::DpchAppData
#define DpchAppDlgWznmPrjImpexDo DlgWznmPrjImpex::DpchAppDo
#define DpchEngDlgWznmPrjImpexData DlgWznmPrjImpex::DpchEngData

/**
	* DlgWznmPrjImpex
	*/
namespace DlgWznmPrjImpex {
	/**
		* VecVDit (full: VecVDlgWznmPrjImpexDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint IFI = 1;
		static const Sbecore::uint IMP = 2;
		static const Sbecore::uint LFI = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmPrjImpexDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgWznmPrjImpexDoImp)
		*/
	class VecVDoImp {

	public:
		static const Sbecore::uint BUTAUTCLICK = 1;
		static const Sbecore::uint BUTRUNCLICK = 2;
		static const Sbecore::uint BUTSTOCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmPrjImpexSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint PRSIDLE = 3;
		static const Sbecore::uint PARSE = 4;
		static const Sbecore::uint ALRWZNMPER = 5;
		static const Sbecore::uint PRSDONE = 6;
		static const Sbecore::uint AUTH = 7;
		static const Sbecore::uint AUTDONE = 8;
		static const Sbecore::uint IMPIDLE = 9;
		static const Sbecore::uint IMPORT = 10;
		static const Sbecore::uint ALRWZNMIER = 11;
		static const Sbecore::uint SYNC = 12;
		static const Sbecore::uint DONE = 13;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmPrjImpex)
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
	  * ContInf (full: ContInfDlgWznmPrjImpex)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * ContInfImp (full: ContInfDlgWznmPrjImpexImp)
	  */
	class ContInfImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfImp(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfImp* comp);
		std::set<Sbecore::uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmPrjImpexLfi)
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
	  * StatApp (full: StatAppDlgWznmPrjImpex)
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
	  * StatShr (full: StatShrDlgWznmPrjImpex)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

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
	  * StatShrIfi (full: StatShrDlgWznmPrjImpexIfi)
	  */
	class StatShrIfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrIfi* comp);
		std::set<Sbecore::uint> diff(const StatShrIfi* comp);
	};

	/**
	  * StatShrImp (full: StatShrDlgWznmPrjImpexImp)
	  */
	class StatShrImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTAUTACTIVE = 1;
		static const Sbecore::uint BUTRUNACTIVE = 2;
		static const Sbecore::uint BUTSTOACTIVE = 3;

	public:
		StatShrImp(const bool ButAutActive = true, const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButAutActive;
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrImp* comp);
		std::set<Sbecore::uint> diff(const StatShrImp* comp);
	};

	/**
	  * StatShrLfi (full: StatShrDlgWznmPrjImpexLfi)
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
	  * Tag (full: TagDlgWznmPrjImpex)
	  */
	class Tag : public Sbecore::Xmlio::Block {

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
	  * TagIfi (full: TagDlgWznmPrjImpexIfi)
	  */
	class TagIfi : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagIfi(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagImp (full: TagDlgWznmPrjImpexImp)
	  */
	class TagImp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTAUT = 2;
		static const Sbecore::uint BUTRUN = 3;
		static const Sbecore::uint BUTSTO = 4;

	public:
		TagImp(const std::string& CptPrg = "", const std::string& ButAut = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButAut;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagLfi (full: TagDlgWznmPrjImpexLfi)
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
		* DpchAppData (full: DpchAppDlgWznmPrjImpexData)
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
		* DpchAppDo (full: DpchAppDlgWznmPrjImpexDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOIMP = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoImp = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoImp;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmPrjImpexData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFIMP = 4;
		static const Sbecore::uint CONTINFLFI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRIFI = 10;
		static const Sbecore::uint STATSHRIMP = 11;
		static const Sbecore::uint STATSHRLFI = 12;
		static const Sbecore::uint TAG = 13;
		static const Sbecore::uint TAGIFI = 14;
		static const Sbecore::uint TAGIMP = 15;
		static const Sbecore::uint TAGLFI = 16;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfLfi continflfi;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		Tag tag;
		TagIfi tagifi;
		TagImp tagimp;
		TagLfi taglfi;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
