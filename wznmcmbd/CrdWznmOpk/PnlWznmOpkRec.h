/**
	* \file PnlWznmOpkRec.h
	* job handler for job PnlWznmOpkRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMOPKREC_H
#define PNLWZNMOPKREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmOpkSqkMNStub.h"
#include "PnlWznmOpkMNLibrary.h"
#include "PnlWznmOpkMNJob.h"
#include "PnlWznmOpkMNComponent.h"
#include "PnlWznmOpkRef1NBlock.h"
#include "PnlWznmOpk1NOp.h"
#include "PnlWznmOpkARetval.h"
#include "PnlWznmOpkAInvarg.h"
#include "PnlWznmOpkDetail.h"

#define VecVWznmOpkRecDo PnlWznmOpkRec::VecVDo

#define ContInfWznmOpkRec PnlWznmOpkRec::ContInf
#define StatAppWznmOpkRec PnlWznmOpkRec::StatApp
#define StatShrWznmOpkRec PnlWznmOpkRec::StatShr
#define TagWznmOpkRec PnlWznmOpkRec::Tag

#define DpchAppWznmOpkRecDo PnlWznmOpkRec::DpchAppDo
#define DpchEngWznmOpkRecData PnlWznmOpkRec::DpchEngData

/**
	* PnlWznmOpkRec
	*/
class PnlWznmOpkRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmOpkRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmOpkRec)
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
		* StatApp (full: StatAppWznmOpkRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneAInvarg = false, const bool initdoneARetval = false, const bool initdone1NOp = false, const bool initdoneRef1NBlock = false, const bool initdoneMNJob = false, const bool initdoneMNComponent = false, const bool initdoneMNLibrary = false, const bool initdoneSqkMNStub = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAInvarg = false, const bool initdoneARetval = false, const bool initdone1NOp = false, const bool initdoneRef1NBlock = false, const bool initdoneMNJob = false, const bool initdoneMNComponent = false, const bool initdoneMNLibrary = false, const bool initdoneSqkMNStub = false);
	};

	/**
		* StatShr (full: StatShrWznmOpkRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFAINVARG = 3;
		static const Sbecore::uint JREFARETVAL = 4;
		static const Sbecore::uint JREF1NOP = 5;
		static const Sbecore::uint JREFREF1NBLOCK = 6;
		static const Sbecore::uint JREFMNJOB = 7;
		static const Sbecore::uint JREFMNCOMPONENT = 8;
		static const Sbecore::uint JREFMNLIBRARY = 9;
		static const Sbecore::uint JREFSQKMNSTUB = 10;
		static const Sbecore::uint PNLSQKMNSTUBAVAIL = 11;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 12;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefAInvarg = 0, const Sbecore::ubigint jrefARetval = 0, const Sbecore::ubigint jref1NOp = 0, const Sbecore::ubigint jrefRef1NBlock = 0, const Sbecore::ubigint jrefMNJob = 0, const Sbecore::ubigint jrefMNComponent = 0, const Sbecore::ubigint jrefMNLibrary = 0, const Sbecore::ubigint jrefSqkMNStub = 0, const bool pnlsqkmnstubAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefAInvarg;
		Sbecore::ubigint jrefARetval;
		Sbecore::ubigint jref1NOp;
		Sbecore::ubigint jrefRef1NBlock;
		Sbecore::ubigint jrefMNJob;
		Sbecore::ubigint jrefMNComponent;
		Sbecore::ubigint jrefMNLibrary;
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
		* Tag (full: TagWznmOpkRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmOpkRecDo)
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
		* DpchEngData (full: DpchEngWznmOpkRecData)
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

	bool evalPnlsqkmnstubAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmOpkRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmOpkRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmOpkSqkMNStub* pnlsqkmnstub;
	PnlWznmOpkMNLibrary* pnlmnlibrary;
	PnlWznmOpkMNJob* pnlmnjob;
	PnlWznmOpkMNComponent* pnlmncomponent;
	PnlWznmOpkRef1NBlock* pnlref1nblock;
	PnlWznmOpk1NOp* pnl1nop;
	PnlWznmOpkARetval* pnlaretval;
	PnlWznmOpkAInvarg* pnlainvarg;
	PnlWznmOpkDetail* pnldetail;

	WznmMOppack recOpk;

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
	bool handleCallWznmOpkUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmOpk_sqkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmOpk_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
