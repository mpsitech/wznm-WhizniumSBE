/**
	* \file PnlWznmQryRec.h
	* job handler for job PnlWznmQryRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMQRYREC_H
#define PNLWZNMQRYREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmQryDetail.h"
#include "PnlWznmQryAOrder.h"
#include "PnlWznmQryAClause.h"
#include "PnlWznmQrySup1NQuery.h"
#include "PnlWznmQryQry1NQuerycol.h"
#include "PnlWznmQry1NQuerymod.h"
#include "PnlWznmQryMNTable.h"
#include "PnlWznmQryMNDialog.h"
#include "PnlWznmQryMNPanel.h"

#define VecVWznmQryRecDo PnlWznmQryRec::VecVDo

#define ContInfWznmQryRec PnlWznmQryRec::ContInf
#define StatAppWznmQryRec PnlWznmQryRec::StatApp
#define StatShrWznmQryRec PnlWznmQryRec::StatShr
#define TagWznmQryRec PnlWznmQryRec::Tag

#define DpchAppWznmQryRecDo PnlWznmQryRec::DpchAppDo
#define DpchEngWznmQryRecData PnlWznmQryRec::DpchEngData

/**
	* PnlWznmQryRec
	*/
class PnlWznmQryRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmQryRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmQryRec)
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
		* StatApp (full: StatAppWznmQryRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAOrder = false, const bool initdoneAClause = false, const bool initdoneSup1NQuery = false, const bool initdoneQry1NQuerycol = false, const bool initdone1NQuerymod = false, const bool initdoneMNTable = false, const bool initdoneMNDialog = false, const bool initdoneMNPanel = false);
	};

	/**
		* StatShr (full: StatShrWznmQryRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFAORDER = 3;
		static const Sbecore::uint JREFACLAUSE = 4;
		static const Sbecore::uint JREFSUP1NQUERY = 5;
		static const Sbecore::uint JREFQRY1NQUERYCOL = 6;
		static const Sbecore::uint JREF1NQUERYMOD = 7;
		static const Sbecore::uint JREFMNTABLE = 8;
		static const Sbecore::uint JREFMNDIALOG = 9;
		static const Sbecore::uint JREFMNPANEL = 10;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 11;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefAOrder = 0, const Sbecore::ubigint jrefAClause = 0, const Sbecore::ubigint jrefSup1NQuery = 0, const Sbecore::ubigint jrefQry1NQuerycol = 0, const Sbecore::ubigint jref1NQuerymod = 0, const Sbecore::ubigint jrefMNTable = 0, const Sbecore::ubigint jrefMNDialog = 0, const Sbecore::ubigint jrefMNPanel = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefAOrder;
		Sbecore::ubigint jrefAClause;
		Sbecore::ubigint jrefSup1NQuery;
		Sbecore::ubigint jrefQry1NQuerycol;
		Sbecore::ubigint jref1NQuerymod;
		Sbecore::ubigint jrefMNTable;
		Sbecore::ubigint jrefMNDialog;
		Sbecore::ubigint jrefMNPanel;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmQryRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmQryRecDo)
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
		* DpchEngData (full: DpchEngWznmQryRecData)
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

	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmQryRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmQryRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmQryDetail* pnldetail;
	PnlWznmQryAOrder* pnlaorder;
	PnlWznmQryAClause* pnlaclause;
	PnlWznmQrySup1NQuery* pnlsup1nquery;
	PnlWznmQryQry1NQuerycol* pnlqry1nquerycol;
	PnlWznmQry1NQuerymod* pnl1nquerymod;
	PnlWznmQryMNTable* pnlmntable;
	PnlWznmQryMNDialog* pnlmndialog;
	PnlWznmQryMNPanel* pnlmnpanel;

	WznmMQuery recQry;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems);

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
	bool handleCallWznmQryUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmQry_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmQry_supEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmQry_jobEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

