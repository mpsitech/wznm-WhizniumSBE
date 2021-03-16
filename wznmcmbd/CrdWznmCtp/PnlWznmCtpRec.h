/**
	* \file PnlWznmCtpRec.h
	* job handler for job PnlWznmCtpRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCTPREC_H
#define PNLWZNMCTPREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmCtp1NTag.h"
#include "PnlWznmCtpTpl1NCapability.h"
#include "PnlWznmCtpAPar.h"
#include "PnlWznmCtpKParKey.h"
#include "PnlWznmCtpKKey.h"
#include "PnlWznmCtpDetail.h"

#define VecVWznmCtpRecDo PnlWznmCtpRec::VecVDo

#define ContInfWznmCtpRec PnlWznmCtpRec::ContInf
#define StatAppWznmCtpRec PnlWznmCtpRec::StatApp
#define StatShrWznmCtpRec PnlWznmCtpRec::StatShr
#define TagWznmCtpRec PnlWznmCtpRec::Tag

#define DpchAppWznmCtpRecDo PnlWznmCtpRec::DpchAppDo
#define DpchEngWznmCtpRecData PnlWznmCtpRec::DpchEngData

/**
	* PnlWznmCtpRec
	*/
class PnlWznmCtpRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmCtpRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmCtpRec)
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
		* StatApp (full: StatAppWznmCtpRec)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const bool initdoneDetail = false, const bool initdoneKParKey = false, const bool initdoneKKey = false, const bool initdoneAPar = false, const bool initdone1NTag = false, const bool initdoneTpl1NCapability = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKParKey = false, const bool initdoneKKey = false, const bool initdoneAPar = false, const bool initdone1NTag = false, const bool initdoneTpl1NCapability = false);
	};

	/**
		* StatShr (full: StatShrWznmCtpRec)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFKPARKEY = 3;
		static const Sbecore::uint JREFKKEY = 4;
		static const Sbecore::uint JREFAPAR = 5;
		static const Sbecore::uint JREF1NTAG = 6;
		static const Sbecore::uint JREFTPL1NCAPABILITY = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefKParKey = 0, const Sbecore::ubigint jrefKKey = 0, const Sbecore::ubigint jrefAPar = 0, const Sbecore::ubigint jref1NTag = 0, const Sbecore::ubigint jrefTpl1NCapability = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefKParKey;
		Sbecore::ubigint jrefKKey;
		Sbecore::ubigint jrefAPar;
		Sbecore::ubigint jref1NTag;
		Sbecore::ubigint jrefTpl1NCapability;
		bool ButRegularizeActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmCtpRec)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmCtpRecDo)
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
		* DpchEngData (full: DpchEngWznmCtpRecData)
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

	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmCtpRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmCtpRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmCtp1NTag* pnl1ntag;
	PnlWznmCtpTpl1NCapability* pnltpl1ncapability;
	PnlWznmCtpAPar* pnlapar;
	PnlWznmCtpKParKey* pnlkparkey;
	PnlWznmCtpKKey* pnlkkey;
	PnlWznmCtpDetail* pnldetail;

	WznmMCapability recCpb;
	Sbecore::uint ixWSubsetCpb;

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
	bool handleCallWznmCpbUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmCpb_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmCpb_tplEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmCpb_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);

};

#endif
