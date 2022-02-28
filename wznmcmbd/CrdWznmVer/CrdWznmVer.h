/**
	* \file CrdWznmVer.h
	* job handler for job CrdWznmVer (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZNMVER_H
#define CRDWZNMVER_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "DlgWznmVerBscui.h"
#include "DlgWznmVerCustjob.h"
#include "DlgWznmVerCustjtr.h"
#include "DlgWznmVerCustui.h"
#include "DlgWznmVerDbstr.h"
#include "DlgWznmVerDeploy.h"
#include "DlgWznmVerFinmod.h"
#include "DlgWznmVerGenjtr.h"
#include "DlgWznmVerGenui.h"
#include "DlgWznmVerGlobal.h"
#include "DlgWznmVerImpexp.h"
#include "DlgWznmVerNew.h"
#include "DlgWznmVerOppack.h"
#include "DlgWznmVerWrinimdl.h"
#include "PnlWznmVerRec.h"
#include "PnlWznmVerHeadbar.h"
#include "PnlWznmVerList.h"

#define VecVWznmVerDo CrdWznmVer::VecVDo
#define VecVWznmVerSge CrdWznmVer::VecVSge

#define ContInfWznmVer CrdWznmVer::ContInf
#define StatAppWznmVer CrdWznmVer::StatApp
#define StatShrWznmVer CrdWznmVer::StatShr
#define TagWznmVer CrdWznmVer::Tag

#define DpchAppWznmVerDo CrdWznmVer::DpchAppDo
#define DpchEngWznmVerData CrdWznmVer::DpchEngData

/**
	* CrdWznmVer
	*/
class CrdWznmVer : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmVerDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDNEWCLICK = 3;
		static const Sbecore::uint MITCRDPCVCLICK = 4;
		static const Sbecore::uint MITCRDIDPCLICK = 5;
		static const Sbecore::uint MITCRDIGBCLICK = 6;
		static const Sbecore::uint MITCRDIMDCLICK = 7;
		static const Sbecore::uint MITCRDIDBCLICK = 8;
		static const Sbecore::uint MITCRDIBUCLICK = 9;
		static const Sbecore::uint MITCRDIIECLICK = 10;
		static const Sbecore::uint MITCRDIOPCLICK = 11;
		static const Sbecore::uint MITCRDICJCLICK = 12;
		static const Sbecore::uint MITCRDGUICLICK = 13;
		static const Sbecore::uint MITCRDAUICLICK = 14;
		static const Sbecore::uint MITCRDGJTCLICK = 15;
		static const Sbecore::uint MITCRDAJTCLICK = 16;
		static const Sbecore::uint MITCRDFNMCLICK = 17;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmVerSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;
		static const Sbecore::uint ALRCVW = 3;
		static const Sbecore::uint SETPRJCVR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWznmVer)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXCRDVER = 3;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxCrdVer = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxCrdVer;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmVer)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrWznmVer)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGBSCUI = 1;
		static const Sbecore::uint JREFDLGCUSTJOB = 2;
		static const Sbecore::uint JREFDLGCUSTJTR = 3;
		static const Sbecore::uint JREFDLGCUSTUI = 4;
		static const Sbecore::uint JREFDLGDBSTR = 5;
		static const Sbecore::uint JREFDLGDEPLOY = 6;
		static const Sbecore::uint JREFDLGFINMOD = 7;
		static const Sbecore::uint JREFDLGGENJTR = 8;
		static const Sbecore::uint JREFDLGGENUI = 9;
		static const Sbecore::uint JREFDLGGLOBAL = 10;
		static const Sbecore::uint JREFDLGIMPEXP = 11;
		static const Sbecore::uint JREFDLGNEW = 12;
		static const Sbecore::uint JREFDLGOPPACK = 13;
		static const Sbecore::uint JREFDLGWRINIMDL = 14;
		static const Sbecore::uint JREFHEADBAR = 15;
		static const Sbecore::uint JREFLIST = 16;
		static const Sbecore::uint JREFREC = 17;
		static const Sbecore::uint MSPCRD1AVAIL = 18;
		static const Sbecore::uint MITCRDNEWAVAIL = 19;
		static const Sbecore::uint MITCRDPCVAVAIL = 20;
		static const Sbecore::uint MITCRDPCVACTIVE = 21;
		static const Sbecore::uint MSPCRD3AVAIL = 22;
		static const Sbecore::uint MITCRDIDPAVAIL = 23;
		static const Sbecore::uint MITCRDIDPACTIVE = 24;
		static const Sbecore::uint MITCRDIGBAVAIL = 25;
		static const Sbecore::uint MITCRDIGBACTIVE = 26;
		static const Sbecore::uint MSPCRD4AVAIL = 27;
		static const Sbecore::uint MITCRDIMDAVAIL = 28;
		static const Sbecore::uint MITCRDIMDACTIVE = 29;
		static const Sbecore::uint MSPCRD5AVAIL = 30;
		static const Sbecore::uint MITCRDIDBAVAIL = 31;
		static const Sbecore::uint MITCRDIDBACTIVE = 32;
		static const Sbecore::uint MITCRDIBUAVAIL = 33;
		static const Sbecore::uint MITCRDIBUACTIVE = 34;
		static const Sbecore::uint MITCRDIIEAVAIL = 35;
		static const Sbecore::uint MITCRDIIEACTIVE = 36;
		static const Sbecore::uint MITCRDIOPAVAIL = 37;
		static const Sbecore::uint MITCRDIOPACTIVE = 38;
		static const Sbecore::uint MITCRDICJAVAIL = 39;
		static const Sbecore::uint MITCRDICJACTIVE = 40;
		static const Sbecore::uint MSPCRD6AVAIL = 41;
		static const Sbecore::uint MITCRDGUIAVAIL = 42;
		static const Sbecore::uint MITCRDGUIACTIVE = 43;
		static const Sbecore::uint MITCRDAUIAVAIL = 44;
		static const Sbecore::uint MITCRDAUIACTIVE = 45;
		static const Sbecore::uint MITCRDGJTAVAIL = 46;
		static const Sbecore::uint MITCRDGJTACTIVE = 47;
		static const Sbecore::uint MITCRDAJTAVAIL = 48;
		static const Sbecore::uint MITCRDAJTACTIVE = 49;
		static const Sbecore::uint MSPCRD7AVAIL = 50;
		static const Sbecore::uint MITCRDFNMAVAIL = 51;
		static const Sbecore::uint MITCRDFNMACTIVE = 52;

	public:
		StatShr(const Sbecore::ubigint jrefDlgbscui = 0, const Sbecore::ubigint jrefDlgcustjob = 0, const Sbecore::ubigint jrefDlgcustjtr = 0, const Sbecore::ubigint jrefDlgcustui = 0, const Sbecore::ubigint jrefDlgdbstr = 0, const Sbecore::ubigint jrefDlgdeploy = 0, const Sbecore::ubigint jrefDlgfinmod = 0, const Sbecore::ubigint jrefDlggenjtr = 0, const Sbecore::ubigint jrefDlggenui = 0, const Sbecore::ubigint jrefDlgglobal = 0, const Sbecore::ubigint jrefDlgimpexp = 0, const Sbecore::ubigint jrefDlgnew = 0, const Sbecore::ubigint jrefDlgoppack = 0, const Sbecore::ubigint jrefDlgwrinimdl = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefList = 0, const Sbecore::ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdPcvAvail = true, const bool MitCrdPcvActive = true, const bool MspCrd3Avail = true, const bool MitCrdIdpAvail = true, const bool MitCrdIdpActive = true, const bool MitCrdIgbAvail = true, const bool MitCrdIgbActive = true, const bool MspCrd4Avail = true, const bool MitCrdImdAvail = true, const bool MitCrdImdActive = true, const bool MspCrd5Avail = true, const bool MitCrdIdbAvail = true, const bool MitCrdIdbActive = true, const bool MitCrdIbuAvail = true, const bool MitCrdIbuActive = true, const bool MitCrdIieAvail = true, const bool MitCrdIieActive = true, const bool MitCrdIopAvail = true, const bool MitCrdIopActive = true, const bool MitCrdIcjAvail = true, const bool MitCrdIcjActive = true, const bool MspCrd6Avail = true, const bool MitCrdGuiAvail = true, const bool MitCrdGuiActive = true, const bool MitCrdAuiAvail = true, const bool MitCrdAuiActive = true, const bool MitCrdGjtAvail = true, const bool MitCrdGjtActive = true, const bool MitCrdAjtAvail = true, const bool MitCrdAjtActive = true, const bool MspCrd7Avail = true, const bool MitCrdFnmAvail = true, const bool MitCrdFnmActive = true);

	public:
		Sbecore::ubigint jrefDlgbscui;
		Sbecore::ubigint jrefDlgcustjob;
		Sbecore::ubigint jrefDlgcustjtr;
		Sbecore::ubigint jrefDlgcustui;
		Sbecore::ubigint jrefDlgdbstr;
		Sbecore::ubigint jrefDlgdeploy;
		Sbecore::ubigint jrefDlgfinmod;
		Sbecore::ubigint jrefDlggenjtr;
		Sbecore::ubigint jrefDlggenui;
		Sbecore::ubigint jrefDlgglobal;
		Sbecore::ubigint jrefDlgimpexp;
		Sbecore::ubigint jrefDlgnew;
		Sbecore::ubigint jrefDlgoppack;
		Sbecore::ubigint jrefDlgwrinimdl;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefList;
		Sbecore::ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdPcvAvail;
		bool MitCrdPcvActive;
		bool MspCrd3Avail;
		bool MitCrdIdpAvail;
		bool MitCrdIdpActive;
		bool MitCrdIgbAvail;
		bool MitCrdIgbActive;
		bool MspCrd4Avail;
		bool MitCrdImdAvail;
		bool MitCrdImdActive;
		bool MspCrd5Avail;
		bool MitCrdIdbAvail;
		bool MitCrdIdbActive;
		bool MitCrdIbuAvail;
		bool MitCrdIbuActive;
		bool MitCrdIieAvail;
		bool MitCrdIieActive;
		bool MitCrdIopAvail;
		bool MitCrdIopActive;
		bool MitCrdIcjAvail;
		bool MitCrdIcjActive;
		bool MspCrd6Avail;
		bool MitCrdGuiAvail;
		bool MitCrdGuiActive;
		bool MitCrdAuiAvail;
		bool MitCrdAuiActive;
		bool MitCrdGjtAvail;
		bool MitCrdGjtActive;
		bool MitCrdAjtAvail;
		bool MitCrdAjtActive;
		bool MspCrd7Avail;
		bool MitCrdFnmAvail;
		bool MitCrdFnmActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmVer)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmVerDo)
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
		* DpchEngData (full: DpchEngWznmVerData)
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
	bool evalMitCrdPcvAvail(DbsWznm* dbswznm);
	bool evalMitCrdPcvActive(DbsWznm* dbswznm);
	bool evalMspCrd3Avail(DbsWznm* dbswznm);
	bool evalMitCrdIdpAvail(DbsWznm* dbswznm);
	bool evalMitCrdIdpActive(DbsWznm* dbswznm);
	bool evalMitCrdIgbAvail(DbsWznm* dbswznm);
	bool evalMitCrdIgbActive(DbsWznm* dbswznm);
	bool evalMspCrd4Avail(DbsWznm* dbswznm);
	bool evalMitCrdImdAvail(DbsWznm* dbswznm);
	bool evalMitCrdImdActive(DbsWznm* dbswznm);
	bool evalMspCrd5Avail(DbsWznm* dbswznm);
	bool evalMitCrdIdbAvail(DbsWznm* dbswznm);
	bool evalMitCrdIdbActive(DbsWznm* dbswznm);
	bool evalMitCrdIbuAvail(DbsWznm* dbswznm);
	bool evalMitCrdIbuActive(DbsWznm* dbswznm);
	bool evalMitCrdIieAvail(DbsWznm* dbswznm);
	bool evalMitCrdIieActive(DbsWznm* dbswznm);
	bool evalMitCrdIopAvail(DbsWznm* dbswznm);
	bool evalMitCrdIopActive(DbsWznm* dbswznm);
	bool evalMitCrdIcjAvail(DbsWznm* dbswznm);
	bool evalMitCrdIcjActive(DbsWznm* dbswznm);
	bool evalMspCrd6Avail(DbsWznm* dbswznm);
	bool evalMitCrdGuiAvail(DbsWznm* dbswznm);
	bool evalMitCrdGuiActive(DbsWznm* dbswznm);
	bool evalMitCrdAuiAvail(DbsWznm* dbswznm);
	bool evalMitCrdAuiActive(DbsWznm* dbswznm);
	bool evalMitCrdGjtAvail(DbsWznm* dbswznm);
	bool evalMitCrdGjtActive(DbsWznm* dbswznm);
	bool evalMitCrdAjtAvail(DbsWznm* dbswznm);
	bool evalMitCrdAjtActive(DbsWznm* dbswznm);
	bool evalMspCrd7Avail(DbsWznm* dbswznm);
	bool evalMitCrdFnmAvail(DbsWznm* dbswznm);
	bool evalMitCrdFnmActive(DbsWznm* dbswznm);

public:
	CrdWznmVer(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale, const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVPreset = VecWznmVPreset::VOID, const Sbecore::ubigint preUref = 0);
	~CrdWznmVer();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	DlgWznmVerBscui* dlgbscui;
	DlgWznmVerCustjob* dlgcustjob;
	DlgWznmVerCustjtr* dlgcustjtr;
	DlgWznmVerCustui* dlgcustui;
	DlgWznmVerDbstr* dlgdbstr;
	DlgWznmVerDeploy* dlgdeploy;
	DlgWznmVerFinmod* dlgfinmod;
	DlgWznmVerGenjtr* dlggenjtr;
	DlgWznmVerGenui* dlggenui;
	DlgWznmVerGlobal* dlgglobal;
	DlgWznmVerImpexp* dlgimpexp;
	DlgWznmVerNew* dlgnew;
	DlgWznmVerOppack* dlgoppack;
	DlgWznmVerWrinimdl* dlgwrinimdl;
	PnlWznmVerRec* pnlrec;
	PnlWznmVerHeadbar* pnlheadbar;
	PnlWznmVerList* pnllist;

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	void handleShowJobtree_subjobs(DbsWznm* dbswznm, const Sbecore::ubigint supRefWznmMJob, const unsigned int il);

	std::string handleWriteHtml_tcotit(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMTablecol, const Sbecore::ubigint refLocEnus);

	std::string handleWriteDbsHtml_tbltit(DbsWznm* dbswznm, WznmMTable* tbl, const Sbecore::ubigint refLocEnus);
	void handleWriteDbsHtml_tcos(DbsWznm* dbswznm, std::fstream& outfile, const std::string& tblsref, ListWznmMTablecol& tcos, std::map<Sbecore::ubigint, std::string>& anchorsTbls, const Sbecore::ubigint refLocEnus);

	void handleWriteIexHtml_struct(DbsWznm* dbswznm, std::fstream& outfile, WznmMImpexp* sup, const Sbecore::ubigint refWznmMImpexp, const std::string& prefix, std::vector<unsigned int>& ics, const Sbecore::ubigint refLocEnus);
	void handleWriteIexHtml_descr(DbsWznm* dbswznm, std::fstream& outfile, const std::string& iexsref, WznmMImpexp* sup, const Sbecore::ubigint refWznmMImpexp, const std::string& prefix, std::vector<unsigned int>& ics, const Sbecore::ubigint refLocEnus);
	std::string handleWriteIexHtml_anchor(const std::string& prefix, std::vector<unsigned int>& ics);
	std::string handleWriteIexHtml_imetit(DbsWznm* dbswznm, WznmMImpexp* ime, const Sbecore::ubigint refLocEnus);
	std::string handleWriteIexHtml_supreltype(DbsWznm* dbswznm, WznmMImpexp* sup, ListWznmMImpexpcol& iels, const Sbecore::ubigint refLocEnus);
	std::string handleWriteIexHtml_ieltype(DbsWznm* dbswznm, WznmMImpexpcol* iel);

	void handleWriteIexMd_struct(DbsWznm* dbswznm, std::fstream& outfile, WznmMImpexp* sup, const Sbecore::ubigint refWznmMImpexp, std::vector<unsigned int>& ics, const Sbecore::ubigint refLocEnus);
	void handleWriteIexMd_descr(DbsWznm* dbswznm, std::fstream& outfile, WznmMImpexp* sup, const Sbecore::ubigint refWznmMImpexp, std::vector<unsigned int>& ics, const Sbecore::ubigint refLocEnus);
	std::string handleWriteIexMd_imetit(DbsWznm* dbswznm, WznmMImpexp* ime, const Sbecore::ubigint refLocEnus);
	std::string handleWriteIexMd_supreltype(DbsWznm* dbswznm, WznmMImpexp* sup, ListWznmMImpexpcol& iels, const Sbecore::ubigint refLocEnus);
	std::string handleWriteIexMd_ieltype(DbsWznm* dbswznm, WznmMImpexpcol* iel);
	std::string handleWriteIexMd_ieltit(DbsWznm* dbswznm, WznmMImpexpcol* iel, const Sbecore::ubigint refLocEnus);
	// IP cust --- IEND

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void changeRef(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint ref, const bool notif = false);
	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:
	bool handleSelectLocales(DbsWznm* dbswznm);
	bool handleShowJobtree(DbsWznm* dbswznm);
	bool handleShowMethods(DbsWznm* dbswznm);
	bool handleShowVars(DbsWznm* dbswznm);
	bool handleWriteDbsHtml(DbsWznm* dbswznm);
	bool handleWriteIexHtml(DbsWznm* dbswznm);
	bool handleWriteIexMd(DbsWznm* dbswznm);

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoClose(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdNewClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdPcvClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIdpClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIgbClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdImdClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIdbClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIbuClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIieClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIopClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdIcjClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdGuiClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdAuiClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdGjtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdAjtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdFnmClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmDlgClose(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmStatChg(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmRefPreSet(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmabt(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmabt(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrcvw(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrcvw(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSetprjcvr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSetprjcvr(DbsWznm* dbswznm);

};

#endif
