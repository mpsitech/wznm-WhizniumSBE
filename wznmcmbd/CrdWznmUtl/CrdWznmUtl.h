/**
	* \file CrdWznmUtl.h
	* job handler for job CrdWznmUtl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZNMUTL_H
#define CRDWZNMUTL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "DlgWznmUtlExtrip.h"
#include "DlgWznmUtlMrgip.h"
#include "PnlWznmUtlHeadbar.h"

#define VecVWznmUtlDo CrdWznmUtl::VecVDo
#define VecVWznmUtlSge CrdWznmUtl::VecVSge

#define ContInfWznmUtl CrdWznmUtl::ContInf
#define StatAppWznmUtl CrdWznmUtl::StatApp
#define StatShrWznmUtl CrdWznmUtl::StatShr
#define TagWznmUtl CrdWznmUtl::Tag

#define DpchAppWznmUtlDo CrdWznmUtl::DpchAppDo
#define DpchEngWznmUtlData CrdWznmUtl::DpchEngData

/**
	* CrdWznmUtl
	*/
class CrdWznmUtl : public JobWznm {

public:
	/**
		* VecVDo (full: VecVWznmUtlDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDXIPCLICK = 3;
		static const Sbecore::uint MITCRDMIPCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWznmUtlSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZNMABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWznmUtl)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWznmUtl)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWznmVReqitmode = VecWznmVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false);
	};

	/**
		* StatShr (full: StatShrWznmUtl)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGEXTRIP = 1;
		static const Sbecore::uint JREFDLGMRGIP = 2;
		static const Sbecore::uint JREFHEADBAR = 3;

	public:
		StatShr(const Sbecore::ubigint jrefDlgextrip = 0, const Sbecore::ubigint jrefDlgmrgip = 0, const Sbecore::ubigint jrefHeadbar = 0);

	public:
		Sbecore::ubigint jrefDlgextrip;
		Sbecore::ubigint jrefDlgmrgip;
		Sbecore::ubigint jrefHeadbar;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWznmUtl)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWznmUtlDo)
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
		* DpchEngData (full: DpchEngWznmUtlData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

public:
	CrdWznmUtl(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~CrdWznmUtl();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	DlgWznmUtlExtrip* dlgextrip;
	DlgWznmUtlMrgip* dlgmrgip;
	PnlWznmUtlHeadbar* pnlheadbar;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWznm* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWznm* dbswznm, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsWznm* dbswznm, const Sbecore::uint ixWznmVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:

	void handleDpchAppWznmInit(DbsWznm* dbswznm, DpchAppWznmInit* dpchappwznminit, DpchEngWznm** dpcheng);

	void handleDpchAppDoClose(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdXipClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppDoMitCrdMipClick(DbsWznm* dbswznm, DpchEngWznm** dpcheng);
	void handleDpchAppWznmAlert(DbsWznm* dbswznm, DpchAppWznmAlert* dpchappwznmalert, DpchEngWznm** dpcheng);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmDlgClose(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAlrwznmabt(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAlrwznmabt(DbsWznm* dbswznm);

};

#endif
