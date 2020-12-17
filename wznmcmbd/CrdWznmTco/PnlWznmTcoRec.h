/**
	* \file PnlWznmTcoRec.h
	* job handler for job PnlWznmTcoRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMTCOREC_H
#define PNLWZNMTCOREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmTco1NCheck.h"
#include "PnlWznmTcoRef1NControl.h"
#include "PnlWznmTcoRef1NQuerymod.h"
#include "PnlWznmTcoATitle.h"
#include "PnlWznmTco1NQuerycol.h"
#include "PnlWznmTco1NImpexpcol.h"
#include "PnlWznmTcoDetail.h"

#define VecVWznmTcoRecDo PnlWznmTcoRec::VecVDo

#define ContInfWznmTcoRec PnlWznmTcoRec::ContInf
#define StatAppWznmTcoRec PnlWznmTcoRec::StatApp
#define StatShrWznmTcoRec PnlWznmTcoRec::StatShr
#define TagWznmTcoRec PnlWznmTcoRec::Tag

#define DpchAppWznmTcoRecDo PnlWznmTcoRec::DpchAppDo
#define DpchEngWznmTcoRecData PnlWznmTcoRec::DpchEngData

/**
	* PnlWznmTcoRec
	*/
class PnlWznmTcoRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmTcoRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmTcoRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmTcoRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdone1NQuerycol = false, const bool initdone1NImpexpcol = false, const bool initdoneRef1NQuerymod = false, const bool initdoneRef1NControl = false, const bool initdone1NCheck = false);
	};

	/**
		* StatShr (full: StatShrWznmTcoRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFATITLE = 3;
		static const Sbecore::uint PNLATITLEAVAIL = 4;
		static const Sbecore::uint JREF1NQUERYCOL = 5;
		static const Sbecore::uint PNL1NQUERYCOLAVAIL = 6;
		static const Sbecore::uint JREF1NIMPEXPCOL = 7;
		static const Sbecore::uint PNL1NIMPEXPCOLAVAIL = 8;
		static const Sbecore::uint JREFREF1NQUERYMOD = 9;
		static const Sbecore::uint PNLREF1NQUERYMODAVAIL = 10;
		static const Sbecore::uint JREFREF1NCONTROL = 11;
		static const Sbecore::uint PNLREF1NCONTROLAVAIL = 12;
		static const Sbecore::uint JREF1NCHECK = 13;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 14;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefATitle = 0, const bool pnlatitleAvail = false, const Sbecore::ubigint jref1NQuerycol = 0, const bool pnl1nquerycolAvail = false, const Sbecore::ubigint jref1NImpexpcol = 0, const bool pnl1nimpexpcolAvail = false, const Sbecore::ubigint jrefRef1NQuerymod = 0, const bool pnlref1nquerymodAvail = false, const Sbecore::ubigint jrefRef1NControl = 0, const bool pnlref1ncontrolAvail = false, const Sbecore::ubigint jref1NCheck = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefATitle;
		bool pnlatitleAvail;
		Sbecore::ubigint jref1NQuerycol;
		bool pnl1nquerycolAvail;
		Sbecore::ubigint jref1NImpexpcol;
		bool pnl1nimpexpcolAvail;
		Sbecore::ubigint jrefRef1NQuerymod;
		bool pnlref1nquerymodAvail;
		Sbecore::ubigint jrefRef1NControl;
		bool pnlref1ncontrolAvail;
		Sbecore::ubigint jref1NCheck;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmTcoRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmTcoRecDo)
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
		* DpchEngData (full: DpchEngWznmTcoRecData)
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

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalPnlatitleAvail(DbsWznm* dbswznm);
	bool evalPnl1nquerycolAvail(DbsWznm* dbswznm);
	bool evalPnl1nimpexpcolAvail(DbsWznm* dbswznm);
	bool evalPnlref1nquerymodAvail(DbsWznm* dbswznm);
	bool evalPnlref1ncontrolAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmTcoRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmTcoRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmTco1NCheck* pnl1ncheck;
	PnlWznmTcoRef1NControl* pnlref1ncontrol;
	PnlWznmTcoRef1NQuerymod* pnlref1nquerymod;
	PnlWznmTcoATitle* pnlatitle;
	PnlWznmTco1NQuerycol* pnl1nquerycol;
	PnlWznmTco1NImpexpcol* pnl1nimpexpcol;
	PnlWznmTcoDetail* pnldetail;

	WznmMTablecol recTco;
	Sbecore::uint ixWSubsetTco;

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
	bool handleCallWznmTcoUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmTco_tblEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_tbl_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTco_sbsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_relEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmTco_fcuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmTco_fctEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
