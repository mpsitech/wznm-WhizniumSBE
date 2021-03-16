/**
	* \file DlgWznmNavMnglic.h
	* job handler for job DlgWznmNavMnglic (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZNMNAVMNGLIC_H
#define DLGWZNMNAVMNGLIC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWznmLicense.h"

#define VecVDlgWznmNavMnglicDo DlgWznmNavMnglic::VecVDo
#define VecVDlgWznmNavMnglicSge DlgWznmNavMnglic::VecVSge

#define ContIacDlgWznmNavMnglic DlgWznmNavMnglic::ContIac
#define ContInfDlgWznmNavMnglic DlgWznmNavMnglic::ContInf
#define StatAppDlgWznmNavMnglic DlgWznmNavMnglic::StatApp
#define StatShrDlgWznmNavMnglic DlgWznmNavMnglic::StatShr
#define TagDlgWznmNavMnglic DlgWznmNavMnglic::Tag

#define DpchAppDlgWznmNavMnglicData DlgWznmNavMnglic::DpchAppData
#define DpchAppDlgWznmNavMnglicDo DlgWznmNavMnglic::DpchAppDo
#define DpchEngDlgWznmNavMnglicData DlgWznmNavMnglic::DpchEngData

/**
	* DlgWznmNavMnglic
	*/
class DlgWznmNavMnglic : public JobWznm {

public:
	/**
		* VecVDo (full: VecVDlgWznmNavMnglicDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint DETBUTSCNCLICK = 1;
		static const Sbecore::uint DETBUTSDCCLICK = 2;
		static const Sbecore::uint DETBUTACTCLICK = 3;
		static const Sbecore::uint BUTDNECLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWznmNavMnglicSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint READY = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWznmNavMnglic)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFDETPUPFIS = 1;
		static const Sbecore::uint DETCHKFIS = 2;
		static const Sbecore::uint NUMFDETLSTLCS = 3;

	public:
		ContIac(const Sbecore::uint numFDetPupFis = 1, const bool DetChkFis = false, const Sbecore::uint numFDetLstLcs = 1);

	public:
		Sbecore::uint numFDetPupFis;
		bool DetChkFis;
		Sbecore::uint numFDetLstLcs;

	public:
		bool readJSON(Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWznmNavMnglic)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint DETTXTSIP = 2;
		static const Sbecore::uint DETTXTSCP = 3;
		static const Sbecore::uint DETTXTLSR = 4;
		static const Sbecore::uint DETTXTLAR = 5;
		static const Sbecore::uint DETTXTLST = 6;
		static const Sbecore::uint DETTXTLEX = 7;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& DetTxtSip = "", const std::string& DetTxtScp = "", const std::string& DetTxtLsr = "", const std::string& DetTxtLar = "", const std::string& DetTxtLst = "", const std::string& DetTxtLex = "");

	public:
		Sbecore::uint numFSge;
		std::string DetTxtSip;
		std::string DetTxtScp;
		std::string DetTxtLsr;
		std::string DetTxtLar;
		std::string DetTxtLst;
		std::string DetTxtLex;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWznmNavMnglic)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const std::string& shortMenu = "", const Sbecore::uint DetLstLcsNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "", const Sbecore::uint DetLstLcsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrDlgWznmNavMnglic)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint DETBUTACTACTIVE = 1;

	public:
		StatShr(const bool DetButActActive = true);

	public:
		bool DetButActActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWznmNavMnglic)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWznmNavMnglicData)
		*/
	class DpchAppData : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmNavMnglicDo)
		*/
	class DpchAppDo : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWznmNavMnglicData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFDETLSTLCS = 4;
		static const Sbecore::uint FEEDFDETPUPFIS = 5;
		static const Sbecore::uint FEEDFSGE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFDetLstLcs = NULL, Sbecore::Feed* feedFDetPupFis = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFDetLstLcs;
		Sbecore::Feed feedFDetPupFis;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalDetButActActive(DbsWznm* dbswznm);

public:
	DlgWznmNavMnglic(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~DlgWznmNavMnglic();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFDetLstLcs;
	Sbecore::Feed feedFDetPupFis;
	Sbecore::Feed feedFSge;

	JobWznmLicense* license;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);
	void handleDpchAppDataContiac(DbsWznm* dbswznm, ContIac* _contiac, DpchEngWznm** dpcheng);

	void handleDpchAppDoDetButScnClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoDetButSdcClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoDetButActClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButDneClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeReady(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeReady(DbsWznm* dbswznm);

};

#endif
