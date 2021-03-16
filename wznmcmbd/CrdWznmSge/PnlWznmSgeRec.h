/**
	* \file PnlWznmSgeRec.h
	* job handler for job PnlWznmSgeRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMSGEREC_H
#define PNLWZNMSGEREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmSgeSqkMNStub.h"
#include "PnlWznmSgeDetail.h"
#include "PnlWznmSge1NSensitivity.h"

#define VecVWznmSgeRecDo PnlWznmSgeRec::VecVDo

#define ContInfWznmSgeRec PnlWznmSgeRec::ContInf
#define StatAppWznmSgeRec PnlWznmSgeRec::StatApp
#define StatShrWznmSgeRec PnlWznmSgeRec::StatShr
#define TagWznmSgeRec PnlWznmSgeRec::Tag

#define DpchAppWznmSgeRecDo PnlWznmSgeRec::DpchAppDo
#define DpchEngWznmSgeRecData PnlWznmSgeRec::DpchEngData

/**
	* PnlWznmSgeRec
	*/
class PnlWznmSgeRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmSgeRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmSgeRec)
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
		* StatApp (full: StatAppWznmSgeRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdone1NSensitivity = false, const bool initdoneSqkMNStub = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NSensitivity = false, const bool initdoneSqkMNStub = false);
	};

	/**
		* StatShr (full: StatShrWznmSgeRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREF1NSENSITIVITY = 3;
		static const Sbecore::uint JREFSQKMNSTUB = 4;
		static const Sbecore::uint PNLSQKMNSTUBAVAIL = 5;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jref1NSensitivity = 0, const Sbecore::ubigint jrefSqkMNStub = 0, const bool pnlsqkmnstubAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jref1NSensitivity;
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
		* Tag (full: TagWznmSgeRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmSgeRecDo)
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
		* DpchEngData (full: DpchEngWznmSgeRecData)
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
	PnlWznmSgeRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmSgeRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmSgeSqkMNStub* pnlsqkmnstub;
	PnlWznmSgeDetail* pnldetail;
	PnlWznmSge1NSensitivity* pnl1nsensitivity;

	WznmMStage recSge;

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
	bool handleCallWznmSgeUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSqkUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmSge_sqkEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSge_snxEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSge_jobEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmSge_fnxEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
