/**
	* \file DlgWznmRlsFinreptr.h
	* API code for job DlgWznmRlsFinreptr (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMRLSFINREPTR_H
#define DLGWZNMRLSFINREPTR_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmRlsFinreptrDit DlgWznmRlsFinreptr::VecVDit
#define VecVDlgWznmRlsFinreptrDo DlgWznmRlsFinreptr::VecVDo
#define VecVDlgWznmRlsFinreptrDoFin DlgWznmRlsFinreptr::VecVDoFin
#define VecVDlgWznmRlsFinreptrDoRes DlgWznmRlsFinreptr::VecVDoRes
#define VecVDlgWznmRlsFinreptrSge DlgWznmRlsFinreptr::VecVSge

#define ContIacDlgWznmRlsFinreptr DlgWznmRlsFinreptr::ContIac
#define ContInfDlgWznmRlsFinreptr DlgWznmRlsFinreptr::ContInf
#define ContInfDlgWznmRlsFinreptrFin DlgWznmRlsFinreptr::ContInfFin
#define ContInfDlgWznmRlsFinreptrRes DlgWznmRlsFinreptr::ContInfRes
#define StatAppDlgWznmRlsFinreptr DlgWznmRlsFinreptr::StatApp
#define StatShrDlgWznmRlsFinreptr DlgWznmRlsFinreptr::StatShr
#define StatShrDlgWznmRlsFinreptrFin DlgWznmRlsFinreptr::StatShrFin
#define StatShrDlgWznmRlsFinreptrRes DlgWznmRlsFinreptr::StatShrRes
#define TagDlgWznmRlsFinreptr DlgWznmRlsFinreptr::Tag
#define TagDlgWznmRlsFinreptrFin DlgWznmRlsFinreptr::TagFin
#define TagDlgWznmRlsFinreptrRes DlgWznmRlsFinreptr::TagRes

#define DpchAppDlgWznmRlsFinreptrData DlgWznmRlsFinreptr::DpchAppData
#define DpchAppDlgWznmRlsFinreptrDo DlgWznmRlsFinreptr::DpchAppDo
#define DpchEngDlgWznmRlsFinreptrData DlgWznmRlsFinreptr::DpchEngData

/**
	* DlgWznmRlsFinreptr
	*/
namespace DlgWznmRlsFinreptr {
	/**
		* VecVDit (full: VecVDlgWznmRlsFinreptrDit)
		*/
	class VecVDit {

	public:
		static const Sbecore::uint FIN = 1;
		static const Sbecore::uint RES = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDo (full: VecVDlgWznmRlsFinreptrDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoFin (full: VecVDlgWznmRlsFinreptrDoFin)
		*/
	class VecVDoFin {

	public:
		static const Sbecore::uint BUTRUNCLICK = 1;
		static const Sbecore::uint BUTSTOCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVDoRes (full: VecVDlgWznmRlsFinreptrDoRes)
		*/
	class VecVDoRes {

	public:
		static const Sbecore::uint BUTPSGCLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmRlsFinreptrSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRGNF = 2;
		static const Sbecore::uint ALRGAD = 3;
		static const Sbecore::uint FINIDLE = 4;
		static const Sbecore::uint PACK = 5;
		static const Sbecore::uint COMMIT = 6;
		static const Sbecore::uint FINDONE = 7;
		static const Sbecore::uint PSGIDLE = 8;
		static const Sbecore::uint PUSHGIT = 9;
		static const Sbecore::uint DONE = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmRlsFinreptr)
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
	  * ContInf (full: ContInfDlgWznmRlsFinreptr)
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
	  * ContInfFin (full: ContInfDlgWznmRlsFinreptrFin)
	  */
	class ContInfFin : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRG = 1;

	public:
		ContInfFin(const std::string& TxtPrg = "");

	public:
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfFin* comp);
		std::set<Sbecore::uint> diff(const ContInfFin* comp);
	};

	/**
	  * ContInfRes (full: ContInfDlgWznmRlsFinreptrRes)
	  */
	class ContInfRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;
		static const Sbecore::uint TXTPRG = 2;

	public:
		ContInfRes(const std::string& Dld = "file", const std::string& TxtPrg = "");

	public:
		std::string Dld;
		std::string TxtPrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInfRes* comp);
		std::set<Sbecore::uint> diff(const ContInfRes* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWznmRlsFinreptr)
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
	  * StatShr (full: StatShrDlgWznmRlsFinreptr)
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
	  * StatShrFin (full: StatShrDlgWznmRlsFinreptrFin)
	  */
	class StatShrFin : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTRUNACTIVE = 1;
		static const Sbecore::uint BUTSTOACTIVE = 2;

	public:
		StatShrFin(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrFin* comp);
		std::set<Sbecore::uint> diff(const StatShrFin* comp);
	};

	/**
	  * StatShrRes (full: StatShrDlgWznmRlsFinreptrRes)
	  */
	class StatShrRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLDAVAIL = 1;
		static const Sbecore::uint DLDACTIVE = 2;
		static const Sbecore::uint TXTPRGAVAIL = 3;
		static const Sbecore::uint SEP1AVAIL = 4;
		static const Sbecore::uint BUTPSGAVAIL = 5;
		static const Sbecore::uint BUTPSGACTIVE = 6;

	public:
		StatShrRes(const bool DldAvail = true, const bool DldActive = true, const bool TxtPrgAvail = true, const bool Sep1Avail = true, const bool ButPsgAvail = true, const bool ButPsgActive = true);

	public:
		bool DldAvail;
		bool DldActive;
		bool TxtPrgAvail;
		bool Sep1Avail;
		bool ButPsgAvail;
		bool ButPsgActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShrRes* comp);
		std::set<Sbecore::uint> diff(const StatShrRes* comp);
	};

	/**
	  * Tag (full: TagDlgWznmRlsFinreptr)
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
	  * TagFin (full: TagDlgWznmRlsFinreptrFin)
	  */
	class TagFin : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTPRG = 1;
		static const Sbecore::uint BUTRUN = 2;
		static const Sbecore::uint BUTSTO = 3;

	public:
		TagFin(const std::string& CptPrg = "", const std::string& ButRun = "", const std::string& ButSto = "");

	public:
		std::string CptPrg;
		std::string ButRun;
		std::string ButSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
	  * TagRes (full: TagDlgWznmRlsFinreptrRes)
	  */
	class TagRes : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;
		static const Sbecore::uint CPTPRG = 2;
		static const Sbecore::uint BUTPSG = 3;

	public:
		TagRes(const std::string& Dld = "", const std::string& CptPrg = "", const std::string& ButPsg = "");

	public:
		std::string Dld;
		std::string CptPrg;
		std::string ButPsg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmRlsFinreptrData)
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
		* DpchAppDo (full: DpchAppDlgWznmRlsFinreptrDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint IXVDOFIN = 3;
		static const Sbecore::uint IXVDORES = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const Sbecore::uint ixVDoFin = 0, const Sbecore::uint ixVDoRes = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;
		Sbecore::uint ixVDoFin;
		Sbecore::uint ixVDoRes;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmRlsFinreptrData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint CONTINFFIN = 4;
		static const Sbecore::uint CONTINFRES = 5;
		static const Sbecore::uint FEEDFDSE = 6;
		static const Sbecore::uint FEEDFSGE = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint STATSHRFIN = 10;
		static const Sbecore::uint STATSHRRES = 11;
		static const Sbecore::uint TAG = 12;
		static const Sbecore::uint TAGFIN = 13;
		static const Sbecore::uint TAGRES = 14;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		ContInfFin continffin;
		ContInfRes continfres;
		Sbecore::Xmlio::Feed feedFDse;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		StatShrFin statshrfin;
		StatShrRes statshrres;
		Tag tag;
		TagFin tagfin;
		TagRes tagres;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

