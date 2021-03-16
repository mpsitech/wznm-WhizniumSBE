/**
	* \file RootWznm.h
	* job handler for job RootWznm (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef ROOTWZNM_H
#define ROOTWZNM_H

#include <signal.h>

// IP include.cust --- INSERT

#include "JobWznmLicense.h"
#include "SessWznm.h"

#define VecVRootWznmSge RootWznm::VecVSge

#define DpchAppRootWznmLogin RootWznm::DpchAppLogin
#define DpchEngRootWznmData RootWznm::DpchEngData

/**
	* RootWznm
	*/
class RootWznm : public JobWznm {

public:
	/**
		* VecVSge (full: VecVRootWznmSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint SYNC = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* DpchAppLogin (full: DpchAppRootWznmLogin)
		*/
	class DpchAppLogin : public DpchAppWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;

	public:
		DpchAppLogin();

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngRootWznmData)
		*/
	class DpchEngData : public DpchEngWznm {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Feed* feedFEnsSps = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWznm* dpcheng);

		void writeJSON(const Sbecore::uint ixWznmVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWznmVLocale, xmlTextWriter* wr);
	};

public:
	RootWznm(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const bool _clearAll);
	~RootWznm();

public:

	JobWznmLicense* license;
	std::list<SessWznm*> sesss;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsWznm* dbswznm);
	void clearQtb(DbsWznm* dbswznm);

	bool authenticate(DbsWznm* dbswznm, const std::string& username, const std::string& password, Sbecore::ubigint& refWznmMUser);

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:
	bool handleClearAll(DbsWznm* dbswznm);
	bool handleCreateSess(DbsWznm* dbswznm);
	bool handleEraseSess(DbsWznm* dbswznm);
	bool handleExportIni(DbsWznm* dbswznm);
	bool handleTest(DbsWznm* dbswznm);

	void handleDpchAppLogin(DbsWznm* dbswznm, DpchAppLogin* dpchapplogin, const std::string ip, DpchEngWznm** dpcheng);

	void handleTimerWithSrefMonInSgeIdle(DbsWznm* dbswznm);
	void handleTimerWithSrefWarnterm(DbsWznm* dbswznm);

public:
	void handleCall(DbsWznm* dbswznm, Sbecore::Call* call);

private:
	bool handleCallWznmSuspsess(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig);
	bool handleCallWznmRefPreSet(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallWznmLogout(DbsWznm* dbswznm, const Sbecore::ubigint jrefTrig, const bool boolvalInv);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge, DpchEngWznm** dpcheng = NULL);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSync(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSync(DbsWznm* dbswznm);

};

#endif
