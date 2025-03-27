/**
	* \file CrdWznmVis.h
	* job handler for job CrdWznmVis (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifndef CRDWZNMVIS_H
#define CRDWZNMVIS_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmVisHeadbar.h"
#include "PnlWznmVisList.h"
#include "PnlWznmVisRec.h"
#include "DlgWznmVisWrite.h"
#include "DlgWznmVisExpstr.h"
#include "DlgWznmVisMissfeat.h"
#include "DlgWznmVisNew.h"
#include "DlgWznmVisImpstr.h"

#define VecVWznmVisDo CrdWznmVis::VecVDo
#define VecVWznmVisSge CrdWznmVis::VecVSge

#define ContInfWznmVis CrdWznmVis::ContInf
#define StatAppWznmVis CrdWznmVis::StatApp
#define StatShrWznmVis CrdWznmVis::StatShr
#define TagWznmVis CrdWznmVis::Tag

#define DpchAppWznmVisDo CrdWznmVis::DpchAppDo
#define DpchEngWznmVisData CrdWznmVis::DpchEngData

/**
	* CrdWznmVis
	*/
class CrdWznmVis : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmVisDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDISTCLICK = 4;
		static const Sbecore::uint MITCRDCMFCLICK = 5;
		static const Sbecore::uint MITCRDWRCCLICK = 6;
		static const Sbecore::uint MITCRDESTCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmVisSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWznmVis)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDVIS = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdVis = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdVis;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmVis)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWznmVis)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGEXPSTR = 1;
		static const Sbecore::uint JREFDLGIMPSTR = 2;
		static const Sbecore::uint JREFDLGMISSFEAT = 3;
		static const Sbecore::uint JREFDLGNEW = 4;
		static const Sbecore::uint JREFDLGWRITE = 5;
		static const Sbecore::uint JREFHEADBAR = 6;
		static const Sbecore::uint JREFLIST = 7;
		static const Sbecore::uint JREFREC = 8;
		static const Sbecore::uint MSPCRD1AVAIL = 9;
		static const Sbecore::uint MITCRDNEWAVAIL = 10;
		static const Sbecore::uint MITCRDISTAVAIL = 11;
		static const Sbecore::uint MITCRDISTACTIVE = 12;
		static const Sbecore::uint MITCRDCMFAVAIL = 13;
		static const Sbecore::uint MITCRDCMFACTIVE = 14;
		static const Sbecore::uint MITCRDWRCAVAIL = 15;
		static const Sbecore::uint MITCRDWRCACTIVE = 16;
		static const Sbecore::uint MITCRDESTACTIVE = 17;

	public:
		StatShr(const Sbecore::ubigint jrefDlgexpstr = 0, const Sbecore::ubigint jrefDlgimpstr = 0, const Sbecore::ubigint jrefDlgmissfeat = 0, const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefDlgwrite = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdIstAvail = true, const bool MitCrdIstActive = true, const bool MitCrdCmfAvail = true, const bool MitCrdCmfActive = true, const bool MitCrdWrcAvail = true, const bool MitCrdWrcActive = true, const bool MitCrdEstActive = true);

	public:
		Sbecore::ubigint jrefDlgexpstr;
		Sbecore::ubigint jrefDlgimpstr;
		Sbecore::ubigint jrefDlgmissfeat;
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefDlgwrite;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdIstAvail;
		bool MitCrdIstActive;
		bool MitCrdCmfAvail;
		bool MitCrdCmfActive;
		bool MitCrdWrcAvail;
		bool MitCrdWrcActive;
		bool MitCrdEstActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmVis)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmVisDo)
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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmVisData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalMspCrd1Avail(DbsWznm* dbswznm);
	bool evalMitCrdNewAvail(DbsWznm* dbswznm);
	bool evalMitCrdIstAvail(DbsWznm* dbswznm);
	bool evalMitCrdIstActive(DbsWznm* dbswznm);
	bool evalMitCrdCmfAvail(DbsWznm* dbswznm);
	bool evalMitCrdCmfActive(DbsWznm* dbswznm);
	bool evalMitCrdWrcAvail(DbsWznm* dbswznm);
	bool evalMitCrdWrcActive(DbsWznm* dbswznm);
	bool evalMitCrdEstActive(DbsWznm* dbswznm);

public:
	CrdWznmVis(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale, const Sbecore::ubigint ref = 0);
	~CrdWznmVis();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWznmVisHeadbar* pnlheadbar;
	PnlWznmVisList* pnllist;
	PnlWznmVisRec* pnlrec;
	DlgWznmVisWrite* dlgwrite;
	DlgWznmVisExpstr* dlgexpstr;
	DlgWznmVisMissfeat* dlgmissfeat;
	DlgWznmVisNew* dlgnew;
	DlgWznmVisImpstr* dlgimpstr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void changeRef(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint ref, const bool notif = false);
	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoClose(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIstClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdCmfClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdWrcClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdEstClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmRefPreSet(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmDlgClose(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmabt(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmabt(DbsWznm* dbswznm);

};

#endif
