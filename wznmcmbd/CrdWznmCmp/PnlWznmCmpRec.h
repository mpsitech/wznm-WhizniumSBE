/**
	* \file PnlWznmCmpRec.h
	* job handler for job PnlWznmCmpRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMCMPREC_H
#define PNLWZNMCMPREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmCmpDetail.h"
#include "PnlWznmCmp1NRelease.h"
#include "PnlWznmCmpMNOppack.h"
#include "PnlWznmCmpMNLibrary.h"

#define VecVWznmCmpRecDo PnlWznmCmpRec::VecVDo

#define ContInfWznmCmpRec PnlWznmCmpRec::ContInf
#define StatAppWznmCmpRec PnlWznmCmpRec::StatApp
#define StatShrWznmCmpRec PnlWznmCmpRec::StatShr
#define TagWznmCmpRec PnlWznmCmpRec::Tag

#define DpchAppWznmCmpRecDo PnlWznmCmpRec::DpchAppDo
#define DpchEngWznmCmpRecData PnlWznmCmpRec::DpchEngData

/**
	* PnlWznmCmpRec
	*/
class PnlWznmCmpRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmCmpRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmCmpRec)
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
		* StatApp (full: StatAppWznmCmpRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NRelease = false, const bool initdoneMNOppack = false, const bool initdoneMNLibrary = false);
	};

	/**
		* StatShr (full: StatShrWznmCmpRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREF1NRELEASE = 3;
		static const Sbecore::uint JREFMNOPPACK = 4;
		static const Sbecore::uint PNLMNOPPACKAVAIL = 5;
		static const Sbecore::uint JREFMNLIBRARY = 6;
		static const Sbecore::uint PNLMNLIBRARYAVAIL = 7;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 8;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jref1NRelease = 0, const Sbecore::ubigint jrefMNOppack = 0, const bool pnlmnoppackAvail = false, const Sbecore::ubigint jrefMNLibrary = 0, const bool pnlmnlibraryAvail = false, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jref1NRelease;
		Sbecore::ubigint jrefMNOppack;
		bool pnlmnoppackAvail;
		Sbecore::ubigint jrefMNLibrary;
		bool pnlmnlibraryAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmCmpRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmCmpRecDo)
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
		* DpchEngData (full: DpchEngWznmCmpRecData)
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

	bool evalPnlmnoppackAvail(DbsWznm* dbswznm);
	bool evalPnlmnlibraryAvail(DbsWznm* dbswznm);
	bool evalButRegularizeActive(DbsWznm* dbswznm);

public:
	PnlWznmCmpRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmCmpRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmCmpDetail* pnldetail;
	PnlWznmCmp1NRelease* pnl1nrelease;
	PnlWznmCmpMNOppack* pnlmnoppack;
	PnlWznmCmpMNLibrary* pnlmnlibrary;

	WznmMComponent recCmp;
	Sbecore::uint ixWSubsetCmp;

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
	bool handleCallWznmCmp_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmCmp_typEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmCmp_inSbs(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmCmpUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

};

#endif
