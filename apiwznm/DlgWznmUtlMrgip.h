/**
	* \file DlgWznmUtlMrgip.h
	* API code for job DlgWznmUtlMrgip (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef DLGWZNMUTLMRGIP_H
#define DLGWZNMUTLMRGIP_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmUtlMrgipDit DlgWznmUtlMrgip::VecVDit
#define VecVDlgWznmUtlMrgipDo DlgWznmUtlMrgip::VecVDo
#define VecVDlgWznmUtlMrgipDoMrg DlgWznmUtlMrgip::VecVDoMrg
#define VecVDlgWznmUtlMrgipSge DlgWznmUtlMrgip::VecVSge

#define ContIacDlgWznmUtlMrgip DlgWznmUtlMrgip::ContIac
#define ContInfDlgWznmUtlMrgip DlgWznmUtlMrgip::ContInf
#define ContInfDlgWznmUtlMrgipLfi DlgWznmUtlMrgip::ContInfLfi
#define ContInfDlgWznmUtlMrgipMrg DlgWznmUtlMrgip::ContInfMrg
#define ContInfDlgWznmUtlMrgipRes DlgWznmUtlMrgip::ContInfRes
#define StatAppDlgWznmUtlMrgip DlgWznmUtlMrgip::StatApp
#define StatShrDlgWznmUtlMrgip DlgWznmUtlMrgip::StatShr
#define StatShrDlgWznmUtlMrgipLfi DlgWznmUtlMrgip::StatShrLfi
#define StatShrDlgWznmUtlMrgipMrg DlgWznmUtlMrgip::StatShrMrg
#define StatShrDlgWznmUtlMrgipRes DlgWznmUtlMrgip::StatShrRes
#define StatShrDlgWznmUtlMrgipSrc DlgWznmUtlMrgip::StatShrSrc
#define StatShrDlgWznmUtlMrgipTrg DlgWznmUtlMrgip::StatShrTrg
#define TagDlgWznmUtlMrgip DlgWznmUtlMrgip::Tag
#define TagDlgWznmUtlMrgipLfi DlgWznmUtlMrgip::TagLfi
#define TagDlgWznmUtlMrgipMrg DlgWznmUtlMrgip::TagMrg
#define TagDlgWznmUtlMrgipRes DlgWznmUtlMrgip::TagRes
#define TagDlgWznmUtlMrgipSrc DlgWznmUtlMrgip::TagSrc
#define TagDlgWznmUtlMrgipTrg DlgWznmUtlMrgip::TagTrg

#define DpchAppDlgWznmUtlMrgipData DlgWznmUtlMrgip::DpchAppData
#define DpchAppDlgWznmUtlMrgipDo DlgWznmUtlMrgip::DpchAppDo
#define DpchEngDlgWznmUtlMrgipData DlgWznmUtlMrgip::DpchEngData

/**
	* DlgWznmUtlMrgip
	*/
namespace DlgWznmUtlMrgip {
	/**
		* VecVDit (full: VecVDlgWznmUtlMrgipDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint SRC = 1;
		static const Sbecore::uint TRG = 2;
		static const Sbecore::uint MRG = 3;
		static const Sbecore::uint LFI = 4;
		static const Sbecore::uint RES = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmUtlMrgipDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoMrg (full: VecVDlgWznmUtlMrgipDoMrg)
		*/
	class VecVDoMrg {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmUtlMrgipSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRMER = 2;
		static const Sbecore::uint SUPIDLE = 3;
		static const Sbecore::uint SRCUNPACK = 4;
		static const Sbecore::uint SUPDONE = 5;
		static const Sbecore::uint SULDONE = 6;
		static const Sbecore::uint TUPIDLE = 7;
		static const Sbecore::uint TRGUNPACK = 8;
		static const Sbecore::uint TUPDONE = 9;
		static const Sbecore::uint TULDONE = 10;
		static const Sbecore::uint MERGE = 11;
		static const Sbecore::uint PACK = 12;
		static const Sbecore::uint FAIL = 13;
		static const Sbecore::uint DONE = 14;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmUtlMrgip)
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
	  * ContInf (full: ContInfDlgWznmUtlMrgip)
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
	  * ContInfLfi (full: ContInfDlgWznmUtlMrgipLfi)
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
	  * ContInfMrg (full: ContInfDlgWznmUtlMrgipMrg)
	  */
	class ContInfMrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfMrg(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfMrg* comp);
		std::set<Sbecore::uint> diff(const ContInfMrg* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWznmUtlMrgipRes)
	  */
	class ContInfRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInfRes(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmUtlMrgip)
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
	  * StatShr (full: StatShrDlgWznmUtlMrgip)
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
	  * StatShrLfi (full: StatShrDlgWznmUtlMrgipLfi)
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
	  * StatShrMrg (full: StatShrDlgWznmUtlMrgipMrg)
	  */
	class StatShrMrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrMrg(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrMrg* comp);
		std::set<Sbecore::uint> diff(const StatShrMrg* comp);
	};

	/**
	  * StatShrRes (full: StatShrDlgWznmUtlMrgipRes)
	  */
	class StatShrRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDACTIVE = 1;

	public:
		StatShrRes(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
	  * StatShrSrc (full: StatShrDlgWznmUtlMrgipSrc)
	  */
	class StatShrSrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrSrc(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrSrc* comp);
		std::set<Sbecore::uint> diff(const StatShrSrc* comp);
	};

	/**
	  * StatShrTrg (full: StatShrDlgWznmUtlMrgipTrg)
	  */
	class StatShrTrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULDACTIVE = 1;

	public:
		StatShrTrg(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrTrg* comp);
		std::set<Sbecore::uint> diff(const StatShrTrg* comp);
	};

	/**
	  * Tag (full: TagDlgWznmUtlMrgip)
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
	  * TagLfi (full: TagDlgWznmUtlMrgipLfi)
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
	  * TagMrg (full: TagDlgWznmUtlMrgipMrg)
	  */
	class TagMrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagMrg(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagRes (full: TagDlgWznmUtlMrgipRes)
	  */
	class TagRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		TagRes(const std::string& Dld = "");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagSrc (full: TagDlgWznmUtlMrgipSrc)
	  */
	class TagSrc : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagSrc(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagTrg (full: TagDlgWznmUtlMrgipTrg)
	  */
	class TagTrg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ULD = 1;
		static const Sbecore::uint CPT = 2;

	public:
		TagTrg(const std::string& Uld = "", const std::string& Cpt = "");

	public:
		std::string Uld;
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmUtlMrgipData)
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
		* DpchAppDo (full: DpchAppDlgWznmUtlMrgipDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOMRG = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoMrg = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoMrg;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmUtlMrgipData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFLFI = 4;
		static const Sbecore::uint CONTINFMRG = 5;
		static const Sbecore::uint CONTINFRES = 6;
		static const Sbecore::uint FEEDFDSE = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint STATSHRLFI = 11;
		static const Sbecore::uint STATSHRMRG = 12;
		static const Sbecore::uint STATSHRRES = 13;
		static const Sbecore::uint STATSHRSRC = 14;
		static const Sbecore::uint STATSHRTRG = 15;
		static const Sbecore::uint TAG = 16;
		static const Sbecore::uint TAGLFI = 17;
		static const Sbecore::uint TAGMRG = 18;
		static const Sbecore::uint TAGRES = 19;
		static const Sbecore::uint TAGSRC = 20;
		static const Sbecore::uint TAGTRG = 21;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfLfi continflfi;
		ContInfMrg continfmrg;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrLfi statshrlfi;
		StatShrMrg statshrmrg;
		StatShrRes statshrres;
		StatShrSrc statshrsrc;
		StatShrTrg statshrtrg;
		Tag tag;
		TagLfi taglfi;
		TagMrg tagmrg;
		TagRes tagres;
		TagSrc tagsrc;
		TagTrg tagtrg;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

