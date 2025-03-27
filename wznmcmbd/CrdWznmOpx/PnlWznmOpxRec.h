/**
	* \file PnlWznmOpxRec.h
	* job handler for job PnlWznmOpxRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMOPXREC_H
#define PNLWZNMOPXREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmOpxMNJob.h"
#include "PnlWznmOpxSqkMNStub.h"
#include "PnlWznmOpxAInvarg.h"
#include "PnlWznmOpxRef1NBlock.h"
#include "PnlWznmOpxARetval.h"
#include "PnlWznmOpxDetail.h"

#define VecVWznmOpxRecDo PnlWznmOpxRec::VecVDo

#define ContInfWznmOpxRec PnlWznmOpxRec::ContInf
#define StatAppWznmOpxRec PnlWznmOpxRec::StatApp
#define StatShrWznmOpxRec PnlWznmOpxRec::StatShr
#define TagWznmOpxRec PnlWznmOpxRec::Tag

#define DpchAppWznmOpxRecDo PnlWznmOpxRec::DpchAppDo
#define DpchEngWznmOpxRecData PnlWznmOpxRec::DpchEngData

/**
	* PnlWznmOpxRec
	*/
class PnlWznmOpxRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmOpxRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmOpxRec)
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
		* StatApp (full: StatAppWznmOpxRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneARetval = false, const bool initdoneAInvarg = false, const bool initdoneRef1NBlock = false, const bool initdoneMNJob = false, const bool initdoneSqkMNStub = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneARetval = false, const bool initdoneAInvarg = false, const bool initdoneRef1NBlock = false, const bool initdoneMNJob = false, const bool initdoneSqkMNStub = false);
	};

	/**
		* StatShr (full: StatShrWznmOpxRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFARETVAL = 3;
		static const Sbecore::uint JREFAINVARG = 4;
		static const Sbecore::uint JREFREF1NBLOCK = 5;
		static const Sbecore::uint JREFMNJOB = 6;
		static const Sbecore::uint JREFSQKMNSTUB = 7;
		static const Sbecore::uint PNLSQKMNSTUBAVAIL = 8;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefARetval = 0, const Sbecore::ubigint jrefAInvarg = 0, const Sbecore::ubigint jrefRef1NBlock = 0, const Sbecore::ubigint jrefMNJob = 0, const Sbecore::ubigint jrefSqkMNStub = 0, const bool pnlsqkmnstubAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefARetval;
		Sbecore::ubigint jrefAInvarg;
		Sbecore::ubigint jrefRef1NBlock;
		Sbecore::ubigint jrefMNJob;
		Sbecore::ubigint jrefSqkMNStub;
		bool pnlsqkmnstubAvail;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmOpxRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmOpxRecDo)
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
		* DpchEngData (full: DpchEngWznmOpxRecData)
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

	bool evalPnlsqkmnstubAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmOpxRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmOpxRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmOpxMNJob* pnlmnjob;
	PnlWznmOpxSqkMNStub* pnlsqkmnstub;
	PnlWznmOpxAInvarg* pnlainvarg;
	PnlWznmOpxRef1NBlock* pnlref1nblock;
	PnlWznmOpxARetval* pnlaretval;
	PnlWznmOpxDetail* pnldetail;

	WznmMOp recOpx;

	WznmMSquawk recSqk;

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
	bool handleCallWznmSqkUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmOpxUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmOpx_sqkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmOpx_opkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
