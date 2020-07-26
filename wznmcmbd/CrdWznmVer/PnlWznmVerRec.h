/**
	* \file PnlWznmVerRec.h
	* job handler for job PnlWznmVerRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef PNLWZNMVERREC_H
#define PNLWZNMVERREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmVerMNLocale.h"
#include "PnlWznmVerRef1NFile.h"
#include "PnlWznmVer1NPreset.h"
#include "PnlWznmVerBvr1NVersion.h"
#include "PnlWznmVer1NBlock.h"
#include "PnlWznmVer1NQuery.h"
#include "PnlWznmVer1NRelation.h"
#include "PnlWznmVer1NTable.h"
#include "PnlWznmVer1NCall.h"
#include "PnlWznmVer1NComponent.h"
#include "PnlWznmVer1NOppack.h"
#include "PnlWznmVer1NJob.h"
#include "PnlWznmVer1NImpexpcplx.h"
#include "PnlWznmVer1NVector.h"
#include "PnlWznmVerVer1NModule.h"
#include "PnlWznmVerVer1NApp.h"
#include "PnlWznmVer1NCapability.h"
#include "PnlWznmVerVer1NError.h"
#include "PnlWznmVerDetail.h"

#define VecVWznmVerRecDo PnlWznmVerRec::VecVDo

#define ContInfWznmVerRec PnlWznmVerRec::ContInf
#define StatAppWznmVerRec PnlWznmVerRec::StatApp
#define StatShrWznmVerRec PnlWznmVerRec::StatShr
#define TagWznmVerRec PnlWznmVerRec::Tag

#define DpchAppWznmVerRecDo PnlWznmVerRec::DpchAppDo
#define DpchEngWznmVerRecData PnlWznmVerRec::DpchEngData

/**
	* PnlWznmVerRec
	*/
class PnlWznmVerRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmVerRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmVerRec)
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
		* StatApp (full: StatAppWznmVerRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneVer1NError = false, const bool initdoneVer1NApp = false, const bool initdone1NCapability = false, const bool initdone1NVector = false, const bool initdoneVer1NModule = false, const bool initdone1NImpexpcplx = false, const bool initdone1NJob = false, const bool initdone1NOppack = false, const bool initdone1NComponent = false, const bool initdone1NCall = false, const bool initdone1NTable = false, const bool initdone1NRelation = false, const bool initdone1NQuery = false, const bool initdoneBvr1NVersion = false, const bool initdone1NBlock = false, const bool initdone1NPreset = false, const bool initdoneRef1NFile = false, const bool initdoneMNLocale = false);
	};

	/**
		* StatShr (full: StatShrWznmVerRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFVER1NERROR = 3;
		static const Sbecore::uint JREFVER1NAPP = 4;
		static const Sbecore::uint JREF1NCAPABILITY = 5;
		static const Sbecore::uint JREF1NVECTOR = 6;
		static const Sbecore::uint JREFVER1NMODULE = 7;
		static const Sbecore::uint JREF1NIMPEXPCPLX = 8;
		static const Sbecore::uint JREF1NJOB = 9;
		static const Sbecore::uint JREF1NOPPACK = 10;
		static const Sbecore::uint JREF1NCOMPONENT = 11;
		static const Sbecore::uint JREF1NCALL = 12;
		static const Sbecore::uint JREF1NTABLE = 13;
		static const Sbecore::uint JREF1NRELATION = 14;
		static const Sbecore::uint JREF1NQUERY = 15;
		static const Sbecore::uint JREFBVR1NVERSION = 16;
		static const Sbecore::uint JREF1NBLOCK = 17;
		static const Sbecore::uint JREF1NPRESET = 18;
		static const Sbecore::uint JREFREF1NFILE = 19;
		static const Sbecore::uint JREFMNLOCALE = 20;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 21;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefVer1NError = 0, const Sbecore::ubigint jrefVer1NApp = 0, const Sbecore::ubigint jref1NCapability = 0, const Sbecore::ubigint jref1NVector = 0, const Sbecore::ubigint jrefVer1NModule = 0, const Sbecore::ubigint jref1NImpexpcplx = 0, const Sbecore::ubigint jref1NJob = 0, const Sbecore::ubigint jref1NOppack = 0, const Sbecore::ubigint jref1NComponent = 0, const Sbecore::ubigint jref1NCall = 0, const Sbecore::ubigint jref1NTable = 0, const Sbecore::ubigint jref1NRelation = 0, const Sbecore::ubigint jref1NQuery = 0, const Sbecore::ubigint jrefBvr1NVersion = 0, const Sbecore::ubigint jref1NBlock = 0, const Sbecore::ubigint jref1NPreset = 0, const Sbecore::ubigint jrefRef1NFile = 0, const Sbecore::ubigint jrefMNLocale = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefVer1NError;
		Sbecore::ubigint jrefVer1NApp;
		Sbecore::ubigint jref1NCapability;
		Sbecore::ubigint jref1NVector;
		Sbecore::ubigint jrefVer1NModule;
		Sbecore::ubigint jref1NImpexpcplx;
		Sbecore::ubigint jref1NJob;
		Sbecore::ubigint jref1NOppack;
		Sbecore::ubigint jref1NComponent;
		Sbecore::ubigint jref1NCall;
		Sbecore::ubigint jref1NTable;
		Sbecore::ubigint jref1NRelation;
		Sbecore::ubigint jref1NQuery;
		Sbecore::ubigint jrefBvr1NVersion;
		Sbecore::ubigint jref1NBlock;
		Sbecore::ubigint jref1NPreset;
		Sbecore::ubigint jrefRef1NFile;
		Sbecore::ubigint jrefMNLocale;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmVerRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmVerRecDo)
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
		* DpchEngData (full: DpchEngWznmVerRecData)
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
	PnlWznmVerRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmVerRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmVerMNLocale* pnlmnlocale;
	PnlWznmVerRef1NFile* pnlref1nfile;
	PnlWznmVer1NPreset* pnl1npreset;
	PnlWznmVerBvr1NVersion* pnlbvr1nversion;
	PnlWznmVer1NBlock* pnl1nblock;
	PnlWznmVer1NQuery* pnl1nquery;
	PnlWznmVer1NRelation* pnl1nrelation;
	PnlWznmVer1NTable* pnl1ntable;
	PnlWznmVer1NCall* pnl1ncall;
	PnlWznmVer1NComponent* pnl1ncomponent;
	PnlWznmVer1NOppack* pnl1noppack;
	PnlWznmVer1NJob* pnl1njob;
	PnlWznmVer1NImpexpcplx* pnl1nimpexpcplx;
	PnlWznmVer1NVector* pnl1nvector;
	PnlWznmVerVer1NModule* pnlver1nmodule;
	PnlWznmVerVer1NApp* pnlver1napp;
	PnlWznmVer1NCapability* pnl1ncapability;
	PnlWznmVerVer1NError* pnlver1nerror;
	PnlWznmVerDetail* pnldetail;

	WznmMVersion recVer;

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
	bool handleCallWznmVerUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmVer_prjEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVer_steEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWznmVer_bvrEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmVer_locEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

