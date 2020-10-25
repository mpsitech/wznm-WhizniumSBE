/**
	* \file JobWznmLicense.h
	* job handler for job JobWznmLicense (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef JOBWZNMLICENSE_H
#define JOBWZNMLICENSE_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include "AppWzla.h"
#include "IexWznmPrj.h"
// IP include.cust --- IEND

#define VecVJobWznmLicenseSge JobWznmLicense::VecVSge

#define StgJobWznmLicense JobWznmLicense::Stg

#define ShrdatJobWznmLicense JobWznmLicense::Shrdat

/**
	* JobWznmLicense
	*/
class JobWznmLicense : public CsjobWznm {

public:
	/**
		* VecVSge (full: VecVJobWznmLicenseSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CONN = 2;
		static const Sbecore::uint CONERR = 3;
		static const Sbecore::uint AUTH = 4;
		static const Sbecore::uint AUTERR = 5;
		static const Sbecore::uint SYNC = 6;
		static const Sbecore::uint SNCERR = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* Stg (full: StgJobWznmLicense)
		*/
	class Stg : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint ENGIP = 1;
		static const Sbecore::uint ENGPORT = 2;
		static const Sbecore::uint USERNAME = 3;
		static const Sbecore::uint PASSWORD = 4;
		static const Sbecore::uint LICENSEBASE = 5;
		static const Sbecore::uint LICENSEUA = 6;
		static const Sbecore::uint LICENSEDDS = 7;
		static const Sbecore::uint LASTATTEMPT = 8;
		static const Sbecore::uint LASTSUCCESS = 9;
		static const Sbecore::uint LASTSYNC = 10;

	public:
		Stg(const std::string& engip = "license.mpsitech.cloud", const Sbecore::uint engport = 13110, const std::string& username = "", const std::string& password = "", const std::string& licenseBase = "", const std::string& licenseUa = "", const std::string& licenseDds = "", const std::string& lastAttempt = "", const std::string& lastSuccess = "", const std::string& lastSync = "");

	public:
		std::string engip;
		Sbecore::uint engport;
		std::string username;
		std::string password;
		std::string licenseBase;
		std::string licenseUa;
		std::string licenseDds;
		std::string lastAttempt;
		std::string lastSuccess;
		std::string lastSync;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const Stg* comp);
		std::set<Sbecore::uint> diff(const Stg* comp);
	};

	/**
		* Shrdat (full: ShrdatJobWznmLicense)
		*/
	class Shrdat : public ShrdatWznm {

	public:
		// IP Shrdat.subs --- INSERT

	public:
		Shrdat();

	public:

		// IP Shrdat.vars.cust --- IBEGIN
		//AppWzla appwzla;
		// IP Shrdat.vars.cust --- IEND

	public:
		void init(XchgWznm* xchg, DbsWznm* dbswznm);
		void term(XchgWznm* xchg);
	};

public:
	JobWznmLicense(XchgWznm* xchg, DbsWznm* dbswznm, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWznmVLocale);
	~JobWznmLicense();

public:
	static Stg stg;
	static Shrdat shrdat;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- IBEGIN
	void connect(DbsWznm* dbswznm);
	void disconnect(DbsWznm* dbswznm);

	void heartbeat(const bool active);

	void syncAll(DbsWznm* dbswznm);
	void syncPrj(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMProject);
	void syncVer(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMProject, const Sbecore::ubigint refWznmMVersion);

	bool authPrjImpex(IexWznmPrj::ImeIMProject& imeimproject);
	bool authPrjNew();
	bool authRlsWrite(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMRelease);

	// future / container-based solution only
	bool validateLicenseBase(const bool startup);
	bool validateLicenseUa();
	bool validateLicenseDds();
	// IP cust --- IEND

public:
	// IP spec --- INSERT

public:

public:
	void handleRequest(DbsWznm* dbswznm, ReqWznm* req);

private:
	bool handleTest(DbsWznm* dbswznm);

private:
	void changeStage(DbsWznm* dbswznm, Sbecore::uint _ixVSge);

public:
	std::string getSquawk(DbsWznm* dbswznm);

private:
	Sbecore::uint enterSgeIdle(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeIdle(DbsWznm* dbswznm);
	Sbecore::uint enterSgeConn(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeConn(DbsWznm* dbswznm);
	Sbecore::uint enterSgeConerr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeConerr(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAuth(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAuth(DbsWznm* dbswznm);
	Sbecore::uint enterSgeAuterr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeAuterr(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSync(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSync(DbsWznm* dbswznm);
	Sbecore::uint enterSgeSncerr(DbsWznm* dbswznm, const bool reenter);
	void leaveSgeSncerr(DbsWznm* dbswznm);

public:
	bool handleClaim(DbsWznm* dbswznm, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest);
};

#endif


