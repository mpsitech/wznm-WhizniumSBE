/**
	* \file PnlWznmSbsRec.h
	* job handler for job PnlWznmSbsRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSBSREC_H
#define PNLWZNMSBSREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmSbsBsbMNSubset.h"
#include "PnlWznmSbsAsbMNSubset.h"
#include "PnlWznmSbs1NTablecol.h"
#include "PnlWznmSbsPst1NQuerymod.h"
#include "PnlWznmSbsTos1NRelation.h"
#include "PnlWznmSbsFrs1NRelation.h"
#include "PnlWznmSbs1NStub.h"
#include "PnlWznmSbsATitle.h"
#include "PnlWznmSbsDetail.h"

#define VecVWznmSbsRecDo PnlWznmSbsRec::VecVDo

#define ContInfWznmSbsRec PnlWznmSbsRec::ContInf
#define StatAppWznmSbsRec PnlWznmSbsRec::StatApp
#define StatShrWznmSbsRec PnlWznmSbsRec::StatShr
#define TagWznmSbsRec PnlWznmSbsRec::Tag

#define DpchAppWznmSbsRecDo PnlWznmSbsRec::DpchAppDo
#define DpchEngWznmSbsRecData PnlWznmSbsRec::DpchEngData

/**
	* PnlWznmSbsRec
	*/
class PnlWznmSbsRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmSbsRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmSbsRec)
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
		* StatApp (full: StatAppWznmSbsRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdone1NStub = false, const bool initdoneFrs1NRelation = false, const bool initdoneTos1NRelation = false, const bool initdone1NTablecol = false, const bool initdonePst1NQuerymod = false, const bool initdoneAsbMNSubset = false, const bool initdoneBsbMNSubset = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdone1NStub = false, const bool initdoneFrs1NRelation = false, const bool initdoneTos1NRelation = false, const bool initdone1NTablecol = false, const bool initdonePst1NQuerymod = false, const bool initdoneAsbMNSubset = false, const bool initdoneBsbMNSubset = false);
	};

	/**
		* StatShr (full: StatShrWznmSbsRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFATITLE = 3;
		static const Sbecore::uint JREF1NSTUB = 4;
		static const Sbecore::uint JREFFRS1NRELATION = 5;
		static const Sbecore::uint JREFTOS1NRELATION = 6;
		static const Sbecore::uint JREF1NTABLECOL = 7;
		static const Sbecore::uint JREFPST1NQUERYMOD = 8;
		static const Sbecore::uint PNLPST1NQUERYMODAVAIL = 9;
		static const Sbecore::uint JREFASBMNSUBSET = 10;
		static const Sbecore::uint JREFBSBMNSUBSET = 11;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 12;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefATitle = 0, const Sbecore::ubigint jref1NStub = 0, const Sbecore::ubigint jrefFrs1NRelation = 0, const Sbecore::ubigint jrefTos1NRelation = 0, const Sbecore::ubigint jref1NTablecol = 0, const Sbecore::ubigint jrefPst1NQuerymod = 0, const bool pnlpst1nquerymodAvail = false, const Sbecore::ubigint jrefAsbMNSubset = 0, const Sbecore::ubigint jrefBsbMNSubset = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefATitle;
		Sbecore::ubigint jref1NStub;
		Sbecore::ubigint jrefFrs1NRelation;
		Sbecore::ubigint jrefTos1NRelation;
		Sbecore::ubigint jref1NTablecol;
		Sbecore::ubigint jrefPst1NQuerymod;
		bool pnlpst1nquerymodAvail;
		Sbecore::ubigint jrefAsbMNSubset;
		Sbecore::ubigint jrefBsbMNSubset;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmSbsRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmSbsRecDo)
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
		* DpchEngData (full: DpchEngWznmSbsRecData)
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

	bool evalPnlpst1nquerymodAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmSbsRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmSbsRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmSbsBsbMNSubset* pnlbsbmnsubset;
	PnlWznmSbsAsbMNSubset* pnlasbmnsubset;
	PnlWznmSbs1NTablecol* pnl1ntablecol;
	PnlWznmSbsPst1NQuerymod* pnlpst1nquerymod;
	PnlWznmSbsTos1NRelation* pnltos1nrelation;
	PnlWznmSbsFrs1NRelation* pnlfrs1nrelation;
	PnlWznmSbs1NStub* pnl1nstub;
	PnlWznmSbsATitle* pnlatitle;
	PnlWznmSbsDetail* pnldetail;

	WznmMSubset recSbs;

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
	bool handleCallWznmSbsUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmPstUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSbs_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSbs_carEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
