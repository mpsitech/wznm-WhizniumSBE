/**
	* \file PnlWznmStbRec.h
	* job handler for job PnlWznmStbRec (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef PNLWZNMSTBREC_H
#define PNLWZNMSTBREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWznmStbDetail.h"
#include "PnlWznmStbSupMNStub.h"
#include "PnlWznmStbMNCall.h"
#include "PnlWznmStbMNSquawk.h"
#include "PnlWznmStbSubMNStub.h"

#define VecVWznmStbRecDo PnlWznmStbRec::VecVDo

#define ContInfWznmStbRec PnlWznmStbRec::ContInf
#define StatAppWznmStbRec PnlWznmStbRec::StatApp
#define StatShrWznmStbRec PnlWznmStbRec::StatShr
#define TagWznmStbRec PnlWznmStbRec::Tag

#define DpchAppWznmStbRecDo PnlWznmStbRec::DpchAppDo
#define DpchEngWznmStbRecData PnlWznmStbRec::DpchEngData

/**
	* PnlWznmStbRec
	*/
class PnlWznmStbRec : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmStbRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWznmStbRec)
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
		* StatApp (full: StatAppWznmStbRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneSupMNStub = false, const bool initdoneMNCall = false, const bool initdoneMNSquawk = false, const bool initdoneSubMNStub = false);
	};

	/**
		* StatShr (full: StatShrWznmStbRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZNMVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFSUPMNSTUB = 3;
		static const Sbecore::uint JREFMNCALL = 4;
		static const Sbecore::uint JREFMNSQUAWK = 5;
		static const Sbecore::uint JREFSUBMNSTUB = 6;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const Sbecore::uint ixWznmVExpstate = VecWznmVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefSupMNStub = 0, const Sbecore::ubigint jrefMNCall = 0, const Sbecore::ubigint jrefMNSquawk = 0, const Sbecore::ubigint jrefSubMNStub = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWznmVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefSupMNStub;
		Sbecore::ubigint jrefMNCall;
		Sbecore::ubigint jrefMNSquawk;
		Sbecore::ubigint jrefSubMNStub;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmStbRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmStbRecDo)
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
		* DpchEngData (full: DpchEngWznmStbRecData)
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
	PnlWznmStbRec(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~PnlWznmStbRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWznmStbDetail* pnldetail;
	PnlWznmStbSupMNStub* pnlsupmnstub;
	PnlWznmStbMNCall* pnlmncall;
	PnlWznmStbMNSquawk* pnlmnsquawk;
	PnlWznmStbSubMNStub* pnlsubmnstub;

	WznmMStub recStb;

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
	bool handleCallWznmStbUpd_refEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmStb_tcoEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWznmStb_sbsEq(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

