/**
	* \file PnlWznmVecRec.h
	* job handler for job PnlWznmVecRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMVECREC_H
#define PNLWZNMVECREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmVecDetail.h"
#include "PnlWznmVecATitle.h"
#include "PnlWznmVecVec1NVectoritem.h"
#include "PnlWznmVecSrc1NFeed.h"
#include "PnlWznmVecRef1NPanel.h"
#include "PnlWznmVecFct1NTablecol.h"
#include "PnlWznmVecPst1NQuerymod.h"
#include "PnlWznmVecMNTable.h"

#define VecVWznmVecRecDo PnlWznmVecRec::VecVDo

#define ContInfWznmVecRec PnlWznmVecRec::ContInf
#define StatAppWznmVecRec PnlWznmVecRec::StatApp
#define StatShrWznmVecRec PnlWznmVecRec::StatShr
#define TagWznmVecRec PnlWznmVecRec::Tag

#define DpchAppWznmVecRecDo PnlWznmVecRec::DpchAppDo
#define DpchEngWznmVecRecData PnlWznmVecRec::DpchEngData

/**
	* PnlWznmVecRec
	*/
class PnlWznmVecRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmVecRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmVecRec)
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
		* StatApp (full: StatAppWznmVecRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneATitle = false, const bool initdoneVec1NVectoritem = false, const bool initdoneSrc1NFeed = false, const bool initdoneRef1NPanel = false, const bool initdoneFct1NTablecol = false, const bool initdonePst1NQuerymod = false, const bool initdoneMNTable = false);
	};

	/**
		* StatShr (full: StatShrWznmVecRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFATITLE = 3;
		static const Sbecore::uint JREFVEC1NVECTORITEM = 4;
		static const Sbecore::uint JREFSRC1NFEED = 5;
		static const Sbecore::uint JREFREF1NPANEL = 6;
		static const Sbecore::uint JREFFCT1NTABLECOL = 7;
		static const Sbecore::uint PNLFCT1NTABLECOLAVAIL = 8;
		static const Sbecore::uint JREFPST1NQUERYMOD = 9;
		static const Sbecore::uint PNLPST1NQUERYMODAVAIL = 10;
		static const Sbecore::uint JREFMNTABLE = 11;
		static const Sbecore::uint PNLMNTABLEAVAIL = 12;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 13;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefATitle = 0, const Sbecore::ubigint jrefVec1NVectoritem = 0, const Sbecore::ubigint jrefSrc1NFeed = 0, const Sbecore::ubigint jrefRef1NPanel = 0, const Sbecore::ubigint jrefFct1NTablecol = 0, const bool pnlfct1ntablecolAvail = false, const Sbecore::ubigint jrefPst1NQuerymod = 0, const bool pnlpst1nquerymodAvail = false, const Sbecore::ubigint jrefMNTable = 0, const bool pnlmntableAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefATitle;
		Sbecore::ubigint jrefVec1NVectoritem;
		Sbecore::ubigint jrefSrc1NFeed;
		Sbecore::ubigint jrefRef1NPanel;
		Sbecore::ubigint jrefFct1NTablecol;
		bool pnlfct1ntablecolAvail;
		Sbecore::ubigint jrefPst1NQuerymod;
		bool pnlpst1nquerymodAvail;
		Sbecore::ubigint jrefMNTable;
		bool pnlmntableAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmVecRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmVecRecDo)
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
		* DpchEngData (full: DpchEngWznmVecRecData)
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

	bool evalPnlfct1ntablecolAvail(DbsWznm* dbswznm);
	bool evalPnlpst1nquerymodAvail(DbsWznm* dbswznm);
	bool evalPnlmntableAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmVecRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmVecRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmVecDetail* pnldetail;
	PnlWznmVecATitle* pnlatitle;
	PnlWznmVecVec1NVectoritem* pnlvec1nvectoritem;
	PnlWznmVecSrc1NFeed* pnlsrc1nfeed;
	PnlWznmVecRef1NPanel* pnlref1npanel;
	PnlWznmVecFct1NTablecol* pnlfct1ntablecol;
	PnlWznmVecPst1NQuerymod* pnlpst1nquerymod;
	PnlWznmVecMNTable* pnlmntable;

	WznmMVector recVec;
	Sbecore::uint ixWSubsetVec;

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
	bool handleCallWznmPst_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmPst_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPst_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVec_hktEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmVec_hkuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVec_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmVec_pstEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVec_typEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmVec_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmPstUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVecUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
