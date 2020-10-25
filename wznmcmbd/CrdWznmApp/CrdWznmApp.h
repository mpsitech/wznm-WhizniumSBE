/**
	* \file CrdWznmApp.h
	* job handler for job CrdWznmApp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef CRDWZNMAPP_H
#define CRDWZNMAPP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "DlgWznmAppNew.h"
#include "DlgWznmAppWrite.h"
#include "DlgWznmAppImpstr.h"
#include "PnlWznmAppRec.h"
#include "PnlWznmAppHeadbar.h"
#include "PnlWznmAppList.h"

#define VecVWznmAppDo CrdWznmApp::VecVDo
#define VecVWznmAppSge CrdWznmApp::VecVSge

#define ContInfWznmApp CrdWznmApp::ContInf
#define StatAppWznmApp CrdWznmApp::StatApp
#define StatShrWznmApp CrdWznmApp::StatShr
#define TagWznmApp CrdWznmApp::Tag

#define DpchAppWznmAppDo CrdWznmApp::DpchAppDo
#define DpchEngWznmAppData CrdWznmApp::DpchEngData

/**
	* CrdWznmApp
	*/
class CrdWznmApp : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmAppDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDISTCLICK = 4;
		static const Sbecore::uint MITCRDWRCCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmAppSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWznmApp)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDAPP = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdApp = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdApp;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmApp)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWznmApp)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGIMPSTR = 1;
		static const Sbecore::uint JREFDLGNEW = 2;
		static const Sbecore::uint JREFDLGWRITE = 3;
		static const Sbecore::uint JREFHEADBAR = 4;
		static const Sbecore::uint JREFLIST = 5;
		static const Sbecore::uint JREFREC = 6;
		static const Sbecore::uint MSPCRD1AVAIL = 7;
		static const Sbecore::uint MITCRDNEWAVAIL = 8;
		static const Sbecore::uint MITCRDISTAVAIL = 9;
		static const Sbecore::uint MITCRDISTACTIVE = 10;
		static const Sbecore::uint MITCRDWRCAVAIL = 11;
		static const Sbecore::uint MITCRDWRCACTIVE = 12;

	public:
		StatShr(const Sbecore::ubigint jrefDlgimpstr = 0, const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefDlgwrite = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdIstAvail = true, const bool MitCrdIstActive = true, const bool MitCrdWrcAvail = true, const bool MitCrdWrcActive = true);

	public:
		Sbecore::ubigint jrefDlgimpstr;
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefDlgwrite;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdIstAvail;
		bool MitCrdIstActive;
		bool MitCrdWrcAvail;
		bool MitCrdWrcActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmApp)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmAppDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWznmAppData)
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
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalMspCrd1Avail(DbsWznm* dbswznm);
	bool evalMitCrdNewAvail(DbsWznm* dbswznm);
	bool evalMitCrdIstAvail(DbsWznm* dbswznm);
	bool evalMitCrdIstActive(DbsWznm* dbswznm);
	bool evalMitCrdWrcAvail(DbsWznm* dbswznm);
	bool evalMitCrdWrcActive(DbsWznm* dbswznm);

public:
	CrdWznmApp(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale, const Sbecore::ubigint ref = 0);
	~CrdWznmApp();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	DlgWznmAppNew* dlgnew;
	DlgWznmAppWrite* dlgwrite;
	DlgWznmAppImpstr* dlgimpstr;
	PnlWznmAppRec* pnlrec;
	PnlWznmAppHeadbar* pnlheadbar;
	PnlWznmAppList* pnllist;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);
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
	void handleDpchAppDoMitCrdWrcClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
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

