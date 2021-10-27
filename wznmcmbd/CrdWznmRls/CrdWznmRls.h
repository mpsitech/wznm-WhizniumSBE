/**
	* \file CrdWznmRls.h
	* job handler for job CrdWznmRls (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZNMRLS_H
#define CRDWZNMRLS_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmRlsList.h"
#include "PnlWznmRlsHeadbar.h"
#include "PnlWznmRlsRec.h"
#include "DlgWznmRlsWrite.h"
#include "DlgWznmRlsStareptr.h"
#include "DlgWznmRlsFinreptr.h"

#define VecVWznmRlsDo CrdWznmRls::VecVDo
#define VecVWznmRlsSge CrdWznmRls::VecVSge

#define ContInfWznmRls CrdWznmRls::ContInf
#define StatAppWznmRls CrdWznmRls::StatApp
#define StatShrWznmRls CrdWznmRls::StatShr
#define TagWznmRls CrdWznmRls::Tag

#define DpchAppWznmRlsDo CrdWznmRls::DpchAppDo
#define DpchEngWznmRlsData CrdWznmRls::DpchEngData

/**
	* CrdWznmRls
	*/
class CrdWznmRls : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmRlsDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDSRTCLICK = 3;
		static const Sbecore::uint MITCRDCRTCLICK = 4;
		static const Sbecore::uint MITCRDFRTCLICK = 5;
		static const Sbecore::uint MITCRDWCOCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmRlsSge)
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
	  * ContInf (full: ContInfWznmRls)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDRLS = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdRls = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdRls;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmRls)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWznmRls)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGFINREPTR = 1;
		static const Sbecore::uint JREFDLGSTAREPTR = 2;
		static const Sbecore::uint JREFDLGWRITE = 3;
		static const Sbecore::uint JREFHEADBAR = 4;
		static const Sbecore::uint JREFLIST = 5;
		static const Sbecore::uint JREFREC = 6;
		static const Sbecore::uint MSPCRD1AVAIL = 7;
		static const Sbecore::uint MITCRDSRTAVAIL = 8;
		static const Sbecore::uint MITCRDSRTACTIVE = 9;
		static const Sbecore::uint MITCRDCRTAVAIL = 10;
		static const Sbecore::uint MITCRDCRTACTIVE = 11;
		static const Sbecore::uint MITCRDFRTAVAIL = 12;
		static const Sbecore::uint MITCRDFRTACTIVE = 13;
		static const Sbecore::uint MITCRDWCOAVAIL = 14;
		static const Sbecore::uint MITCRDWCOACTIVE = 15;

	public:
		StatShr(const Sbecore::ubigint jrefDlgfinreptr = 0, const Sbecore::ubigint jrefDlgstareptr = 0, const Sbecore::ubigint jrefDlgwrite = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdSrtAvail = true, const bool MitCrdSrtActive = true, const bool MitCrdCrtAvail = true, const bool MitCrdCrtActive = true, const bool MitCrdFrtAvail = true, const bool MitCrdFrtActive = true, const bool MitCrdWcoAvail = true, const bool MitCrdWcoActive = true);

	public:
		Sbecore::ubigint jrefDlgfinreptr;
		Sbecore::ubigint jrefDlgstareptr;
		Sbecore::ubigint jrefDlgwrite;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdSrtAvail;
		bool MitCrdSrtActive;
		bool MitCrdCrtAvail;
		bool MitCrdCrtActive;
		bool MitCrdFrtAvail;
		bool MitCrdFrtActive;
		bool MitCrdWcoAvail;
		bool MitCrdWcoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmRls)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmRlsDo)
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
		* DpchEngData (full: DpchEngWznmRlsData)
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
	bool evalMitCrdSrtAvail(DbsWznm* dbswznm);
	bool evalMitCrdSrtActive(DbsWznm* dbswznm);
	bool evalMitCrdCrtAvail(DbsWznm* dbswznm);
	bool evalMitCrdCrtActive(DbsWznm* dbswznm);
	bool evalMitCrdFrtAvail(DbsWznm* dbswznm);
	bool evalMitCrdFrtActive(DbsWznm* dbswznm);
	bool evalMitCrdWcoAvail(DbsWznm* dbswznm);
	bool evalMitCrdWcoActive(DbsWznm* dbswznm);

public:
	CrdWznmRls(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale, const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVPreset = VecWznmVPreset::VOID, const Sbecore::ubigint preUref = 0);
	~CrdWznmRls();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWznmRlsList* pnllist;
	PnlWznmRlsHeadbar* pnlheadbar;
	PnlWznmRlsRec* pnlrec;
	DlgWznmRlsWrite* dlgwrite;
	DlgWznmRlsStareptr* dlgstareptr;
	DlgWznmRlsFinreptr* dlgfinreptr;

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
	void handleDpchAppDoMitCrdSrtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdCrtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdFrtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdWcoClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmReptrStop(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmReptrStart(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const std::string& txtvalInv);
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
