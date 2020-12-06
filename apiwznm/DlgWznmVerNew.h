/**
	* \file DlgWznmVerNew.h
	* API code for job DlgWznmVerNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMVERNEW_H
#define DLGWZNMVERNEW_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmVerNewDo DlgWznmVerNew::VecVDo
#define VecVDlgWznmVerNewSge DlgWznmVerNew::VecVSge
#define VecVDlgWznmVerNewVni DlgWznmVerNew::VecVVni

#define ContIacDlgWznmVerNew DlgWznmVerNew::ContIac
#define ContInfDlgWznmVerNew DlgWznmVerNew::ContInf
#define StatAppDlgWznmVerNew DlgWznmVerNew::StatApp
#define StatShrDlgWznmVerNew DlgWznmVerNew::StatShr
#define TagDlgWznmVerNew DlgWznmVerNew::Tag

#define DpchAppDlgWznmVerNewData DlgWznmVerNew::DpchAppData
#define DpchAppDlgWznmVerNewDo DlgWznmVerNew::DpchAppDo
#define DpchEngDlgWznmVerNewData DlgWznmVerNew::DpchEngData

/**
	* DlgWznmVerNew
	*/
namespace DlgWznmVerNew {
	/**
		* VecVDo (full: VecVDlgWznmVerNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmVerNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVVni (full: VecVDlgWznmVerNewVni)
		*/
	class VecVVni {

	public:
		static const Sbecore::uint MAJ = 1;
		static const Sbecore::uint MIN = 2;
		static const Sbecore::uint SUB = 3;
		static const Sbecore::uint VOID = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmVerNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFDETPUPPRJ = 1;
		static const Sbecore::uint NUMFDETPUPBVR = 2;
		static const Sbecore::uint NUMFDETRBUVNI = 3;
		static const Sbecore::uint DETTXFCMT = 4;
		static const Sbecore::uint NUMSFDETLSTLOC = 5;
		static const Sbecore::uint NUMFDETPUPPLC = 6;

	public:
		ContIac(const Sbecore::uint numFDetPupPrj = 1, const Sbecore::uint numFDetPupBvr = 1, const Sbecore::uint numFDetRbuVni = 1, const std::string& DetTxfCmt = "", const std::vector<Sbecore::uint>& numsFDetLstLoc = {}, const Sbecore::uint numFDetPupPlc = 1);

	public:
		Sbecore::uint numFDetPupPrj;
		Sbecore::uint numFDetPupBvr;
		Sbecore::uint numFDetRbuVni;
		std::string DetTxfCmt;
		std::vector<Sbecore::uint> numsFDetLstLoc;
		Sbecore::uint numFDetPupPlc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmVerNew)
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
	  * StatApp (full: StatAppDlgWznmVerNew)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SHORTMENU = 1;
		static const Sbecore::uint DETLSTLOCNUMFIRSTDISP = 2;

	public:
		StatApp(const std::string& shortMenu = "", const Sbecore::uint DetLstLocNumFirstdisp = 1);

	public:
		std::string shortMenu;
		Sbecore::uint DetLstLocNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWznmVerNew)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCREACTIVE = 1;

	public:
		StatShr(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWznmVerNew)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETCPTPRJ = 2;
		static const Sbecore::uint DETCPTBVR = 3;
		static const Sbecore::uint DETCPTVNI = 4;
		static const Sbecore::uint DETCPTCMT = 5;
		static const Sbecore::uint DETCPTLOC = 6;
		static const Sbecore::uint DETCPTPLC = 7;
		static const Sbecore::uint BUTCNC = 8;
		static const Sbecore::uint BUTCRE = 9;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetCptPrj = "", const std::string& DetCptBvr = "", const std::string& DetCptVni = "", const std::string& DetCptCmt = "", const std::string& DetCptLoc = "", const std::string& DetCptPlc = "", const std::string& ButCnc = "", const std::string& ButCre = "");

	public:
		std::string Cpt;
		std::string DetCptPrj;
		std::string DetCptBvr;
		std::string DetCptVni;
		std::string DetCptCmt;
		std::string DetCptLoc;
		std::string DetCptPlc;
		std::string ButCnc;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVerNewData)
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
		* DpchAppDo (full: DpchAppDlgWznmVerNewDo)
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
		* DpchEngData (full: DpchEngDlgWznmVerNewData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETLSTLOC = 4;
		static const Sbecore::uint FEEDFDETPUPBVR = 5;
		static const Sbecore::uint FEEDFDETPUPPLC = 6;
		static const Sbecore::uint FEEDFDETPUPPRJ = 7;
		static const Sbecore::uint FEEDFDETRBUVNI = 8;
		static const Sbecore::uint FEEDFSGE = 9;
		static const Sbecore::uint STATAPP = 10;
		static const Sbecore::uint STATSHR = 11;
		static const Sbecore::uint TAG = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetLstLoc;
		Sbecore::Xmlio::Feed feedFDetPupBvr;
		Sbecore::Xmlio::Feed feedFDetPupPlc;
		Sbecore::Xmlio::Feed feedFDetPupPrj;
		Sbecore::Xmlio::Feed feedFDetRbuVni;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
