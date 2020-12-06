/**
	* \file DlgWznmPrjNew.h
	* API code for job DlgWznmPrjNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMPRJNEW_H
#define DLGWZNMPRJNEW_H

#include "ApiWznm_blks.h"

#define VecVDlgWznmPrjNewDo DlgWznmPrjNew::VecVDo
#define VecVDlgWznmPrjNewSge DlgWznmPrjNew::VecVSge

#define ContIacDlgWznmPrjNew DlgWznmPrjNew::ContIac
#define ContInfDlgWznmPrjNew DlgWznmPrjNew::ContInf
#define StatAppDlgWznmPrjNew DlgWznmPrjNew::StatApp
#define StatShrDlgWznmPrjNew DlgWznmPrjNew::StatShr
#define TagDlgWznmPrjNew DlgWznmPrjNew::Tag

#define DpchAppDlgWznmPrjNewData DlgWznmPrjNew::DpchAppData
#define DpchAppDlgWznmPrjNewDo DlgWznmPrjNew::DpchAppDo
#define DpchEngDlgWznmPrjNewData DlgWznmPrjNew::DpchEngData

/**
	* DlgWznmPrjNew
	*/
namespace DlgWznmPrjNew {
	/**
		* VecVDo (full: VecVDlgWznmPrjNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTAUTCLICK = 1;
		static const Sbecore::uint BUTCNCCLICK = 2;
		static const Sbecore::uint BUTCRECLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmPrjNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRAER = 2;
		static const Sbecore::uint AUTH = 3;
		static const Sbecore::uint AUTDONE = 4;
		static const Sbecore::uint CREATE = 5;
		static const Sbecore::uint SYNC = 6;
		static const Sbecore::uint DONE = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWznmPrjNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETTXFSHO = 1;
		static const Sbecore::uint DETTXFTIT = 2;
		static const Sbecore::uint DETTXFABT = 3;
		static const Sbecore::uint NUMSFDETLSTDTY = 4;
		static const Sbecore::uint NUMSFDETLSTLOC = 5;
		static const Sbecore::uint NUMFDETPUPPLC = 6;
		static const Sbecore::uint NUMFDETPUPPMC = 7;

	public:
		ContIac(const std::string& DetTxfSho = "", const std::string& DetTxfTit = "", const std::string& DetTxfAbt = "", const std::vector<Sbecore::uint>& numsFDetLstDty = {}, const std::vector<Sbecore::uint>& numsFDetLstLoc = {}, const Sbecore::uint numFDetPupPlc = 1, const Sbecore::uint numFDetPupPmc = 1);

	public:
		std::string DetTxfSho;
		std::string DetTxfTit;
		std::string DetTxfAbt;
		std::vector<Sbecore::uint> numsFDetLstDty;
		std::vector<Sbecore::uint> numsFDetLstLoc;
		Sbecore::uint numFDetPupPlc;
		Sbecore::uint numFDetPupPmc;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmPrjNew)
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
	  * StatApp (full: StatAppDlgWznmPrjNew)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SHORTMENU = 1;
		static const Sbecore::uint DETLSTDTYNUMFIRSTDISP = 2;
		static const Sbecore::uint DETLSTLOCNUMFIRSTDISP = 3;

	public:
		StatApp(const std::string& shortMenu = "", const Sbecore::uint DetLstDtyNumFirstdisp = 1, const Sbecore::uint DetLstLocNumFirstdisp = 1);

	public:
		std::string shortMenu;
		Sbecore::uint DetLstDtyNumFirstdisp;
		Sbecore::uint DetLstLocNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWznmPrjNew)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DETBUTAUTACTIVE = 1;
		static const Sbecore::uint BUTCNCACTIVE = 2;
		static const Sbecore::uint BUTCREACTIVE = 3;

	public:
		StatShr(const bool DetButAutActive = true, const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool DetButAutActive;
		bool ButCncActive;
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWznmPrjNew)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DETCPTSHO = 2;
		static const Sbecore::uint DETCPTTIT = 3;
		static const Sbecore::uint DETCPTABT = 4;
		static const Sbecore::uint DETCPTDTY = 5;
		static const Sbecore::uint DETCPTLOC = 6;
		static const Sbecore::uint DETCPTPLC = 7;
		static const Sbecore::uint DETCPTTMC = 8;
		static const Sbecore::uint DETBUTAUT = 9;
		static const Sbecore::uint BUTCNC = 10;
		static const Sbecore::uint BUTCRE = 11;

	public:
		Tag(const std::string& Cpt = "", const std::string& DetCptSho = "", const std::string& DetCptTit = "", const std::string& DetCptAbt = "", const std::string& DetCptDty = "", const std::string& DetCptLoc = "", const std::string& DetCptPlc = "", const std::string& DetCptTmc = "", const std::string& DetButAut = "", const std::string& ButCnc = "", const std::string& ButCre = "");

	public:
		std::string Cpt;
		std::string DetCptSho;
		std::string DetCptTit;
		std::string DetCptAbt;
		std::string DetCptDty;
		std::string DetCptLoc;
		std::string DetCptPlc;
		std::string DetCptTmc;
		std::string DetButAut;
		std::string ButCnc;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmPrjNewData)
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
		* DpchAppDo (full: DpchAppDlgWznmPrjNewDo)
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
		* DpchEngData (full: DpchEngDlgWznmPrjNewData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETLSTDTY = 4;
		static const Sbecore::uint FEEDFDETLSTLOC = 5;
		static const Sbecore::uint FEEDFDETPUPPLC = 6;
		static const Sbecore::uint FEEDFDETPUPPMC = 7;
		static const Sbecore::uint FEEDFSGE = 8;
		static const Sbecore::uint STATAPP = 9;
		static const Sbecore::uint STATSHR = 10;
		static const Sbecore::uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFDetLstDty;
		Sbecore::Xmlio::Feed feedFDetLstLoc;
		Sbecore::Xmlio::Feed feedFDetPupPlc;
		Sbecore::Xmlio::Feed feedFDetPupPmc;
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
