/**
	* \file DlgWznmVerWrinimdl.h
	* API code for job DlgWznmVerWrinimdl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVERWRINIMDL_H
#define DLGWZNMVERWRINIMDL_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmVerWrinimdlDit DlgWznmVerWrinimdl::VecVDit
#define VecVDlgWznmVerWrinimdlDo DlgWznmVerWrinimdl::VecVDo
#define VecVDlgWznmVerWrinimdlDoWri DlgWznmVerWrinimdl::VecVDoWri
#define VecVDlgWznmVerWrinimdlSge DlgWznmVerWrinimdl::VecVSge

#define ContIacDlgWznmVerWrinimdl DlgWznmVerWrinimdl::ContIac
#define ContInfDlgWznmVerWrinimdl DlgWznmVerWrinimdl::ContInf
#define ContInfDlgWznmVerWrinimdlFia DlgWznmVerWrinimdl::ContInfFia
#define ContInfDlgWznmVerWrinimdlWri DlgWznmVerWrinimdl::ContInfWri
#define StatAppDlgWznmVerWrinimdl DlgWznmVerWrinimdl::StatApp
#define StatShrDlgWznmVerWrinimdl DlgWznmVerWrinimdl::StatShr
#define StatShrDlgWznmVerWrinimdlFia DlgWznmVerWrinimdl::StatShrFia
#define StatShrDlgWznmVerWrinimdlWri DlgWznmVerWrinimdl::StatShrWri
#define TagDlgWznmVerWrinimdl DlgWznmVerWrinimdl::Tag
#define TagDlgWznmVerWrinimdlFia DlgWznmVerWrinimdl::TagFia
#define TagDlgWznmVerWrinimdlWri DlgWznmVerWrinimdl::TagWri

#define DpchAppDlgWznmVerWrinimdlData DlgWznmVerWrinimdl::DpchAppData
#define DpchAppDlgWznmVerWrinimdlDo DlgWznmVerWrinimdl::DpchAppDo
#define DpchEngDlgWznmVerWrinimdlData DlgWznmVerWrinimdl::DpchEngData

/**
	* DlgWznmVerWrinimdl
	*/
namespace DlgWznmVerWrinimdl {
	/**
		* VecVDit (full: VecVDlgWznmVerWrinimdlDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint WRI = 1;
		static const Sbecore::uint FIA = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmVerWrinimdlDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoWri (full: VecVDlgWznmVerWrinimdlDoWri)
		*/
	class VecVDoWri {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerWrinimdlSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint EXPORT = 2;
		static const Sbecore::uint WRITE = 3;
		static const Sbecore::uint PACK = 4;
		static const Sbecore::uint DONE = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVerWrinimdl)
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
	  * ContInf (full: ContInfDlgWznmVerWrinimdl)
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
	  * ContInfFia (full: ContInfDlgWznmVerWrinimdlFia)
	  */
	class ContInfFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfFia(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfFia* comp);
		std::set<Sbecore::uint> diff(const ContInfFia* comp);
	};

	/**
	  * ContInfWri (full: ContInfDlgWznmVerWrinimdlWri)
	  */
	class ContInfWri : public Sbecore::Xmlio::Block {

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
	  * StatApp (full: StatAppDlgWznmVerWrinimdl)
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
	  * StatShr (full: StatShrDlgWznmVerWrinimdl)
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
	  * StatShrFia (full: StatShrDlgWznmVerWrinimdlFia)
	  */
	class StatShrFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrFia(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrFia* comp);
		std::set<Sbecore::uint> diff(const StatShrFia* comp);
	};

	/**
	  * StatShrWri (full: StatShrDlgWznmVerWrinimdlWri)
	  */
	class StatShrWri : public Sbecore::Xmlio::Block {

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
	  * Tag (full: TagDlgWznmVerWrinimdl)
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
	  * TagFia (full: TagDlgWznmVerWrinimdlFia)
	  */
	class TagFia : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagFia(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagWri (full: TagDlgWznmVerWrinimdlWri)
	  */
	class TagWri : public Sbecore::Xmlio::Block {

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
		* DpchAppData (full: DpchAppDlgWznmVerWrinimdlData)
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
		* DpchAppDo (full: DpchAppDlgWznmVerWrinimdlDo)
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
		* DpchEngData (full: DpchEngDlgWznmVerWrinimdlData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIA = 4;
		static const Sbecore::uint CONTINFWRI = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRFIA = 10;
		static const Sbecore::uint STATSHRWRI = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGFIA = 13;
		static const Sbecore::uint TAGWRI = 14;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFia continffia;
		ContInfWri continfwri;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrFia statshrfia;
		StatShrWri statshrwri;
		Tag tag;
		TagFia tagfia;
		TagWri tagwri;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
