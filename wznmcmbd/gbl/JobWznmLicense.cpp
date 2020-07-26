/**
	* \file JobWznmLicense.cpp
	* job handler for job JobWznmLicense (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "JobWznmLicense.h"

#include "JobWznmLicense_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
// this is a crutch ...
#include "VecWzlaVSte.cpp"
#include "AppWzla.cpp"
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWznmLicense::Shrdat
 ******************************************************************************/

JobWznmLicense::Shrdat::Shrdat() :
			ShrdatWznm("JobWznmLicense", "Shrdat")
		{
};

void JobWznmLicense::Shrdat::init(
			XchgWznm* xchg
			, DbsWznm* dbswznm
		) {
	// IP Shrdat.init --- INSERT
};

void JobWznmLicense::Shrdat::term(
			XchgWznm* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWznmLicense
 ******************************************************************************/

JobWznmLicense::JobWznmLicense(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			CsjobWznm(xchg, VecWznmVJob::JOBWZNMLICENSE, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWznmLicense::~JobWznmLicense() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void JobWznmLicense::connect(
			DbsWznm* dbswznm
		) {

};

void JobWznmLicense::disconnect(
			DbsWznm* dbswznm
		) {

};

void JobWznmLicense::heartbeat(
			const bool active
		) {

};

void JobWznmLicense::syncAll(
			DbsWznm* dbswznm
		) {
	
};

void JobWznmLicense::syncPrj(
			DbsWznm* dbswznm
			, const ubigint refWznmMProject
		) {
	
};

void JobWznmLicense::syncVer(
			DbsWznm* dbswznm
			, const ubigint refWznmMProject
			, const ubigint refWznmMVersion
		) {
	
};

bool JobWznmLicense::authPrjImpex(
			IexWznmPrj::ImeIMProject& imeimproject
		) {
	return true;
};

bool JobWznmLicense::authPrjNew() {
	return true;
};

bool JobWznmLicense::authRlsWrite(
			DbsWznm* dbswznm
			, const ubigint refWznmMRelease
		) {
	return true;
};

bool JobWznmLicense::validateLicenseBase(
			const bool startup
		) {
	return true;

/*
	string s;
	vector<string> ss;

	time_t rawtime;

	// expect <license sref/8>;sbe_base;<expiry/time stamp>
	s = Wznm::decrypt(stg.licenseBase);
	StrMod::stringToVector(s, ss);

	try {
		if (ss.size() != 3) throw SbeException(0, {{"msg","invalid base license format"}});
		if (ss[0].length() != 8) throw SbeException(0, {{"msg","invalid base license format"}});
		if (ss[1] != "sbe_base") throw SbeException(0, {{"msg","invalid base license type"}});

		time(&rawtime);
		if (((unsigned int) atol(ss[2].c_str())) < ((unsigned int) rawtime)) throw SbeException(0, {{"msg","base license has expired"},{"stamp",Ftm::stamp(rawtime)}});

	} catch (SbeException& e) {
		if (!startup) throw;
	};
*/
};

bool JobWznmLicense::validateLicenseUa() {
	return true;
};

bool JobWznmLicense::validateLicenseDds() {
	return true;
};

// IP cust --- IEND

// IP spec --- INSERT

void JobWznmLicense::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswznm);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool JobWznmLicense::handleTest(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWznmLicense::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::CONN: leaveSgeConn(dbswznm); break;
				case VecVSge::CONERR: leaveSgeConerr(dbswznm); break;
				case VecVSge::AUTH: leaveSgeAuth(dbswznm); break;
				case VecVSge::AUTERR: leaveSgeAuterr(dbswznm); break;
				case VecVSge::SYNC: leaveSgeSync(dbswznm); break;
				case VecVSge::SNCERR: leaveSgeSncerr(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::CONN: _ixVSge = enterSgeConn(dbswznm, reenter); break;
			case VecVSge::CONERR: _ixVSge = enterSgeConerr(dbswznm, reenter); break;
			case VecVSge::AUTH: _ixVSge = enterSgeAuth(dbswznm, reenter); break;
			case VecVSge::AUTERR: _ixVSge = enterSgeAuterr(dbswznm, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswznm, reenter); break;
			case VecVSge::SNCERR: _ixVSge = enterSgeSncerr(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWznmLicense::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CONN) || (ixVSge == VecVSge::CONERR) || (ixVSge == VecVSge::AUTH) || (ixVSge == VecVSge::AUTERR) || (ixVSge == VecVSge::SYNC) || (ixVSge == VecVSge::SNCERR) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "not connected";
			else if (ixVSge == VecVSge::CONN) retval = "connected";
			else if (ixVSge == VecVSge::CONERR) retval = "connection failure";
			else if (ixVSge == VecVSge::AUTH) retval = "authenticating";
			else if (ixVSge == VecVSge::AUTERR) retval = "authentication failure";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing";
			else if (ixVSge == VecVSge::SNCERR) retval = "synchronization failure";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWznmLicense::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWznmLicense::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmLicense::enterSgeConn(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::CONERR;

	// IP enterSgeConn --- INSERT

	return retval;
};

void JobWznmLicense::leaveSgeConn(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeConn --- INSERT
};

uint JobWznmLicense::enterSgeConerr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeConerr --- INSERT

	return retval;
};

void JobWznmLicense::leaveSgeConerr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeConerr --- INSERT
};

uint JobWznmLicense::enterSgeAuth(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::AUTERR;

	// IP enterSgeAuth --- INSERT

	return retval;
};

void JobWznmLicense::leaveSgeAuth(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAuth --- INSERT
};

uint JobWznmLicense::enterSgeAuterr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;

	// IP enterSgeAuterr --- INSERT

	return retval;
};

void JobWznmLicense::leaveSgeAuterr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAuterr --- INSERT
};

uint JobWznmLicense::enterSgeSync(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::SNCERR;

	// IP enterSgeSync --- INSERT

	return retval;
};

void JobWznmLicense::leaveSgeSync(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSync --- INSERT
};

uint JobWznmLicense::enterSgeSncerr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CONN;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSncerr --- INSERT

	return retval;
};

void JobWznmLicense::leaveSgeSncerr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSncerr --- INSERT
};

bool JobWznmLicense::handleClaim(
			DbsWznm* dbswznm
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- INSERT

	return mod;
};


