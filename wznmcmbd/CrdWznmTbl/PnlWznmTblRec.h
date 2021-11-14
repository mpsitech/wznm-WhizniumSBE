/**
	* \file PnlWznmTblRec.h
	* job handler for job PnlWznmTblRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTBLREC_H
#define PNLWZNMTBLREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmTblMNQuery.h"
#include "PnlWznmTblMNVector.h"
#include "PnlWznmTblPst1NQuerymod.h"
#include "PnlWznmTblRef1NQuerymod.h"
#include "PnlWznmTblRef1NRtblock.h"
#include "PnlWznmTblHk1NVector.h"
#include "PnlWznmTblFct1NTablecol.h"
#include "PnlWznmTblRef1NPanel.h"
#include "PnlWznmTblSrc1NFeed.h"
#include "PnlWznmTblRef1NCall.h"
#include "PnlWznmTblRef1NDialog.h"
#include "PnlWznmTblTbl1NTablecol.h"
#include "PnlWznmTbl1NSubset.h"
#include "PnlWznmTbl1NStub.h"
#include "PnlWznmTblTo1NRelation.h"
#include "PnlWznmTblFr1NRelation.h"
#include "PnlWznmTbl1NCheck.h"
#include "PnlWznmTbl1NImpexp.h"
#include "PnlWznmTblATitle.h"
#include "PnlWznmTblALoadfct.h"
#include "PnlWznmTblDetail.h"

#define VecVWznmTblRecDo PnlWznmTblRec::VecVDo

#define ContInfWznmTblRec PnlWznmTblRec::ContInf
#define StatAppWznmTblRec PnlWznmTblRec::StatApp
#define StatShrWznmTblRec PnlWznmTblRec::StatShr
#define TagWznmTblRec PnlWznmTblRec::Tag

#define DpchAppWznmTblRecDo PnlWznmTblRec::DpchAppDo
#define DpchEngWznmTblRecData PnlWznmTblRec::DpchEngData

/**
	* PnlWznmTblRec
	*/
class PnlWznmTblRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmTblRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmTblRec)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmTblRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneALoadfct = false, const bool initdoneATitle = false, const bool initdone1NImpexp = false, const bool initdone1NCheck = false, const bool initdoneFr1NRelation = false, const bool initdoneTo1NRelation = false, const bool initdone1NStub = false, const bool initdone1NSubset = false, const bool initdoneTbl1NTablecol = false, const bool initdoneRef1NDialog = false, const bool initdoneRef1NCall = false, const bool initdoneSrc1NFeed = false, const bool initdoneRef1NPanel = false, const bool initdoneFct1NTablecol = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NRtblock = false, const bool initdoneRef1NQuerymod = false, const bool initdonePst1NQuerymod = false, const bool initdoneMNVector = false, const bool initdoneMNQuery = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneALoadfct = false, const bool initdoneATitle = false, const bool initdone1NImpexp = false, const bool initdone1NCheck = false, const bool initdoneFr1NRelation = false, const bool initdoneTo1NRelation = false, const bool initdone1NStub = false, const bool initdone1NSubset = false, const bool initdoneTbl1NTablecol = false, const bool initdoneRef1NDialog = false, const bool initdoneRef1NCall = false, const bool initdoneSrc1NFeed = false, const bool initdoneRef1NPanel = false, const bool initdoneFct1NTablecol = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NRtblock = false, const bool initdoneRef1NQuerymod = false, const bool initdonePst1NQuerymod = false, const bool initdoneMNVector = false, const bool initdoneMNQuery = false);
	};

	/**
		* StatShr (full: StatShrWznmTblRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFALOADFCT = 3;
		static const Sbecore::uint PNLALOADFCTAVAIL = 4;
		static const Sbecore::uint JREFATITLE = 5;
		static const Sbecore::uint PNLATITLEAVAIL = 6;
		static const Sbecore::uint JREF1NIMPEXP = 7;
		static const Sbecore::uint PNL1NIMPEXPAVAIL = 8;
		static const Sbecore::uint JREF1NCHECK = 9;
		static const Sbecore::uint PNL1NCHECKAVAIL = 10;
		static const Sbecore::uint JREFFR1NRELATION = 11;
		static const Sbecore::uint PNLFR1NRELATIONAVAIL = 12;
		static const Sbecore::uint JREFTO1NRELATION = 13;
		static const Sbecore::uint PNLTO1NRELATIONAVAIL = 14;
		static const Sbecore::uint JREF1NSTUB = 15;
		static const Sbecore::uint PNL1NSTUBAVAIL = 16;
		static const Sbecore::uint JREF1NSUBSET = 17;
		static const Sbecore::uint PNL1NSUBSETAVAIL = 18;
		static const Sbecore::uint JREFTBL1NTABLECOL = 19;
		static const Sbecore::uint JREFREF1NDIALOG = 20;
		static const Sbecore::uint PNLREF1NDIALOGAVAIL = 21;
		static const Sbecore::uint JREFREF1NCALL = 22;
		static const Sbecore::uint PNLREF1NCALLAVAIL = 23;
		static const Sbecore::uint JREFSRC1NFEED = 24;
		static const Sbecore::uint JREFREF1NPANEL = 25;
		static const Sbecore::uint JREFFCT1NTABLECOL = 26;
		static const Sbecore::uint PNLFCT1NTABLECOLAVAIL = 27;
		static const Sbecore::uint JREFHK1NVECTOR = 28;
		static const Sbecore::uint JREFREF1NRTBLOCK = 29;
		static const Sbecore::uint JREFREF1NQUERYMOD = 30;
		static const Sbecore::uint JREFPST1NQUERYMOD = 31;
		static const Sbecore::uint PNLPST1NQUERYMODAVAIL = 32;
		static const Sbecore::uint JREFMNVECTOR = 33;
		static const Sbecore::uint PNLMNVECTORAVAIL = 34;
		static const Sbecore::uint JREFMNQUERY = 35;
		static const Sbecore::uint PNLMNQUERYAVAIL = 36;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 37;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefALoadfct = 0, const bool pnlaloadfctAvail = false, const Sbecore::ubigint jrefATitle = 0, const bool pnlatitleAvail = false, const Sbecore::ubigint jref1NImpexp = 0, const bool pnl1nimpexpAvail = false, const Sbecore::ubigint jref1NCheck = 0, const bool pnl1ncheckAvail = false, const Sbecore::ubigint jrefFr1NRelation = 0, const bool pnlfr1nrelationAvail = false, const Sbecore::ubigint jrefTo1NRelation = 0, const bool pnlto1nrelationAvail = false, const Sbecore::ubigint jref1NStub = 0, const bool pnl1nstubAvail = false, const Sbecore::ubigint jref1NSubset = 0, const bool pnl1nsubsetAvail = false, const Sbecore::ubigint jrefTbl1NTablecol = 0, const Sbecore::ubigint jrefRef1NDialog = 0, const bool pnlref1ndialogAvail = false, const Sbecore::ubigint jrefRef1NCall = 0, const bool pnlref1ncallAvail = false, const Sbecore::ubigint jrefSrc1NFeed = 0, const Sbecore::ubigint jrefRef1NPanel = 0, const Sbecore::ubigint jrefFct1NTablecol = 0, const bool pnlfct1ntablecolAvail = false, const Sbecore::ubigint jrefHk1NVector = 0, const Sbecore::ubigint jrefRef1NRtblock = 0, const Sbecore::ubigint jrefRef1NQuerymod = 0, const Sbecore::ubigint jrefPst1NQuerymod = 0, const bool pnlpst1nquerymodAvail = false, const Sbecore::ubigint jrefMNVector = 0, const bool pnlmnvectorAvail = false, const Sbecore::ubigint jrefMNQuery = 0, const bool pnlmnqueryAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefALoadfct;
		bool pnlaloadfctAvail;
		Sbecore::ubigint jrefATitle;
		bool pnlatitleAvail;
		Sbecore::ubigint jref1NImpexp;
		bool pnl1nimpexpAvail;
		Sbecore::ubigint jref1NCheck;
		bool pnl1ncheckAvail;
		Sbecore::ubigint jrefFr1NRelation;
		bool pnlfr1nrelationAvail;
		Sbecore::ubigint jrefTo1NRelation;
		bool pnlto1nrelationAvail;
		Sbecore::ubigint jref1NStub;
		bool pnl1nstubAvail;
		Sbecore::ubigint jref1NSubset;
		bool pnl1nsubsetAvail;
		Sbecore::ubigint jrefTbl1NTablecol;
		Sbecore::ubigint jrefRef1NDialog;
		bool pnlref1ndialogAvail;
		Sbecore::ubigint jrefRef1NCall;
		bool pnlref1ncallAvail;
		Sbecore::ubigint jrefSrc1NFeed;
		Sbecore::ubigint jrefRef1NPanel;
		Sbecore::ubigint jrefFct1NTablecol;
		bool pnlfct1ntablecolAvail;
		Sbecore::ubigint jrefHk1NVector;
		Sbecore::ubigint jrefRef1NRtblock;
		Sbecore::ubigint jrefRef1NQuerymod;
		Sbecore::ubigint jrefPst1NQuerymod;
		bool pnlpst1nquerymodAvail;
		Sbecore::ubigint jrefMNVector;
		bool pnlmnvectorAvail;
		Sbecore::ubigint jrefMNQuery;
		bool pnlmnqueryAvail;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmTblRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmTblRecDo)
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
		* DpchEngData (full: DpchEngWznmTblRecData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalPnlaloadfctAvail(DbsWznm* dbswznm);
	bool evalPnlatitleAvail(DbsWznm* dbswznm);
	bool evalPnl1nimpexpAvail(DbsWznm* dbswznm);
	bool evalPnl1ncheckAvail(DbsWznm* dbswznm);
	bool evalPnlfr1nrelationAvail(DbsWznm* dbswznm);
	bool evalPnlto1nrelationAvail(DbsWznm* dbswznm);
	bool evalPnl1nstubAvail(DbsWznm* dbswznm);
	bool evalPnl1nsubsetAvail(DbsWznm* dbswznm);
	bool evalPnlref1ndialogAvail(DbsWznm* dbswznm);
	bool evalPnlref1ncallAvail(DbsWznm* dbswznm);
	bool evalPnlfct1ntablecolAvail(DbsWznm* dbswznm);
	bool evalPnlpst1nquerymodAvail(DbsWznm* dbswznm);
	bool evalPnlmnvectorAvail(DbsWznm* dbswznm);
	bool evalPnlmnqueryAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmTblRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmTblRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmTblMNQuery* pnlmnquery;
	PnlWznmTblMNVector* pnlmnvector;
	PnlWznmTblPst1NQuerymod* pnlpst1nquerymod;
	PnlWznmTblRef1NQuerymod* pnlref1nquerymod;
	PnlWznmTblRef1NRtblock* pnlref1nrtblock;
	PnlWznmTblHk1NVector* pnlhk1nvector;
	PnlWznmTblFct1NTablecol* pnlfct1ntablecol;
	PnlWznmTblRef1NPanel* pnlref1npanel;
	PnlWznmTblSrc1NFeed* pnlsrc1nfeed;
	PnlWznmTblRef1NCall* pnlref1ncall;
	PnlWznmTblRef1NDialog* pnlref1ndialog;
	PnlWznmTblTbl1NTablecol* pnltbl1ntablecol;
	PnlWznmTbl1NSubset* pnl1nsubset;
	PnlWznmTbl1NStub* pnl1nstub;
	PnlWznmTblTo1NRelation* pnlto1nrelation;
	PnlWznmTblFr1NRelation* pnlfr1nrelation;
	PnlWznmTbl1NCheck* pnl1ncheck;
	PnlWznmTbl1NImpexp* pnl1nimpexp;
	PnlWznmTblATitle* pnlatitle;
	PnlWznmTblALoadfct* pnlaloadfct;
	PnlWznmTblDetail* pnldetail;

	WznmMTable recTbl;
	Sbecore::uint ixWSubsetTbl;

	WznmMPreset recPst;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsWznm* dbswznm, const bool notif = false, DpchEngWznm** dpcheng = NULL);
	void regularize(DbsWznm* dbswznm, const bool notif = false, DpchEngWznm** dpcheng = NULL);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmTblUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmPstUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmTbl_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTbl_typEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTbl_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTbl_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTbl_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTbl_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTbl_carEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmPst_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
