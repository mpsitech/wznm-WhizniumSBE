/**
	* \file PnlWznmJobRec.h
	* job handler for job PnlWznmJobRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMJOBREC_H
#define PNLWZNMJOBREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmJobSubMNJob.h"
#include "PnlWznmJobMNOp.h"
#include "PnlWznmJobMNOppack.h"
#include "PnlWznmJobSupMNJob.h"
#include "PnlWznmJobRef1NBlock.h"
#include "PnlWznmJob1NSensitivity.h"
#include "PnlWznmJobHk1NVector.h"
#include "PnlWznmJobJob1NStage.h"
#include "PnlWznmJob1NRtjob.h"
#include "PnlWznmJobACmd.h"
#include "PnlWznmJob1NMethod.h"
#include "PnlWznmJobAVar.h"
#include "PnlWznmJobDetail.h"

#define VecVWznmJobRecDo PnlWznmJobRec::VecVDo

#define ContInfWznmJobRec PnlWznmJobRec::ContInf
#define StatAppWznmJobRec PnlWznmJobRec::StatApp
#define StatShrWznmJobRec PnlWznmJobRec::StatShr
#define TagWznmJobRec PnlWznmJobRec::Tag

#define DpchAppWznmJobRecDo PnlWznmJobRec::DpchAppDo
#define DpchEngWznmJobRecData PnlWznmJobRec::DpchEngData

/**
	* PnlWznmJobRec
	*/
class PnlWznmJobRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmJobRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmJobRec)
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
		* StatApp (full: StatAppWznmJobRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneAVar = false, const bool initdoneACmd = false, const bool initdone1NMethod = false, const bool initdone1NRtjob = false, const bool initdoneJob1NStage = false, const bool initdone1NSensitivity = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NBlock = false, const bool initdoneMNOppack = false, const bool initdoneSupMNJob = false, const bool initdoneMNOp = false, const bool initdoneSubMNJob = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAVar = false, const bool initdoneACmd = false, const bool initdone1NMethod = false, const bool initdone1NRtjob = false, const bool initdoneJob1NStage = false, const bool initdone1NSensitivity = false, const bool initdoneHk1NVector = false, const bool initdoneRef1NBlock = false, const bool initdoneMNOppack = false, const bool initdoneSupMNJob = false, const bool initdoneMNOp = false, const bool initdoneSubMNJob = false);
	};

	/**
		* StatShr (full: StatShrWznmJobRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFAVAR = 3;
		static const Sbecore::uint JREFACMD = 4;
		static const Sbecore::uint JREF1NMETHOD = 5;
		static const Sbecore::uint JREF1NRTJOB = 6;
		static const Sbecore::uint JREFJOB1NSTAGE = 7;
		static const Sbecore::uint JREF1NSENSITIVITY = 8;
		static const Sbecore::uint JREFHK1NVECTOR = 9;
		static const Sbecore::uint JREFREF1NBLOCK = 10;
		static const Sbecore::uint JREFMNOPPACK = 11;
		static const Sbecore::uint JREFSUPMNJOB = 12;
		static const Sbecore::uint JREFMNOP = 13;
		static const Sbecore::uint JREFSUBMNJOB = 14;
		static const Sbecore::uint PNLSUBMNJOBAVAIL = 15;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 16;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefAVar = 0, const Sbecore::ubigint jrefACmd = 0, const Sbecore::ubigint jref1NMethod = 0, const Sbecore::ubigint jref1NRtjob = 0, const Sbecore::ubigint jrefJob1NStage = 0, const Sbecore::ubigint jref1NSensitivity = 0, const Sbecore::ubigint jrefHk1NVector = 0, const Sbecore::ubigint jrefRef1NBlock = 0, const Sbecore::ubigint jrefMNOppack = 0, const Sbecore::ubigint jrefSupMNJob = 0, const Sbecore::ubigint jrefMNOp = 0, const Sbecore::ubigint jrefSubMNJob = 0, const bool pnlsubmnjobAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefAVar;
		Sbecore::ubigint jrefACmd;
		Sbecore::ubigint jref1NMethod;
		Sbecore::ubigint jref1NRtjob;
		Sbecore::ubigint jrefJob1NStage;
		Sbecore::ubigint jref1NSensitivity;
		Sbecore::ubigint jrefHk1NVector;
		Sbecore::ubigint jrefRef1NBlock;
		Sbecore::ubigint jrefMNOppack;
		Sbecore::ubigint jrefSupMNJob;
		Sbecore::ubigint jrefMNOp;
		Sbecore::ubigint jrefSubMNJob;
		bool pnlsubmnjobAvail;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmJobRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmJobRecDo)
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
		* DpchEngData (full: DpchEngWznmJobRecData)
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

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

	bool evalPnlsubmnjobAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmJobRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmJobRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmJobSubMNJob* pnlsubmnjob;
	PnlWznmJobMNOp* pnlmnop;
	PnlWznmJobMNOppack* pnlmnoppack;
	PnlWznmJobSupMNJob* pnlsupmnjob;
	PnlWznmJobRef1NBlock* pnlref1nblock;
	PnlWznmJob1NSensitivity* pnl1nsensitivity;
	PnlWznmJobHk1NVector* pnlhk1nvector;
	PnlWznmJobJob1NStage* pnljob1nstage;
	PnlWznmJob1NRtjob* pnl1nrtjob;
	PnlWznmJobACmd* pnlacmd;
	PnlWznmJob1NMethod* pnl1nmethod;
	PnlWznmJobAVar* pnlavar;
	PnlWznmJobDetail* pnldetail;

	WznmMJob recJob;

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
	bool handleCallWznmJobUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmJob_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmJob_typEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmJob_reuEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmJob_retEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
