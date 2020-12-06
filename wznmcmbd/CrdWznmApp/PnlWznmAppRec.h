/**
	* \file PnlWznmAppRec.h
	* job handler for job PnlWznmAppRec (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZNMAPPREC_H
#define PNLWZNMAPPREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmAppDetail.h"
#include "PnlWznmApp1NEvent.h"
#include "PnlWznmAppApp1NSequence.h"
#include "PnlWznmApp1NRtjob.h"
#include "PnlWznmAppRef1NFile.h"

#define VecVWznmAppRecDo PnlWznmAppRec::VecVDo

#define ContInfWznmAppRec PnlWznmAppRec::ContInf
#define StatAppWznmAppRec PnlWznmAppRec::StatApp
#define StatShrWznmAppRec PnlWznmAppRec::StatShr
#define TagWznmAppRec PnlWznmAppRec::Tag

#define DpchAppWznmAppRecDo PnlWznmAppRec::DpchAppDo
#define DpchEngWznmAppRecData PnlWznmAppRec::DpchEngData

/**
	* PnlWznmAppRec
	*/
class PnlWznmAppRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmAppRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmAppRec)
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
		* StatApp (full: StatAppWznmAppRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NEvent = false, const bool initdoneApp1NSequence = false, const bool initdone1NRtjob = false, const bool initdoneRef1NFile = false);
	};

	/**
		* StatShr (full: StatShrWznmAppRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREF1NEVENT = 3;
		static const Sbecore::uint JREFAPP1NSEQUENCE = 4;
		static const Sbecore::uint JREF1NRTJOB = 5;
		static const Sbecore::uint JREFREF1NFILE = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jref1NEvent = 0, const Sbecore::ubigint jrefApp1NSequence = 0, const Sbecore::ubigint jref1NRtjob = 0, const Sbecore::ubigint jrefRef1NFile = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jref1NEvent;
		Sbecore::ubigint jrefApp1NSequence;
		Sbecore::ubigint jref1NRtjob;
		Sbecore::ubigint jrefRef1NFile;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmAppRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmAppRecDo)
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
		* DpchEngData (full: DpchEngWznmAppRecData)
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
	PnlWznmAppRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmAppRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmAppDetail* pnldetail;
	PnlWznmApp1NEvent* pnl1nevent;
	PnlWznmAppApp1NSequence* pnlapp1nsequence;
	PnlWznmApp1NRtjob* pnl1nrtjob;
	PnlWznmAppRef1NFile* pnlref1nfile;

	WznmMApp recApp;

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
	bool handleCallWznmAppUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmApp_verEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
