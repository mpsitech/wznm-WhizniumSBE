/**
	* \file JobWznmLicense.cpp
	* job handler for job JobWznmLicense (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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
	StrMod::stringToVector(s, ss, ';', true);

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
	// IP handleTest --- IBEGIN

	// derive hash from list of projects
	string hash;

	ListWznmMProject prjs;
	WznmMProject* prj = NULL;

	dbswznm->tblwznmmproject->loadRstBySQL("SELECT * FROM TblWznmMProject ORDER BY Short ASC", false, prjs);

	for (unsigned int i = 0; i < prjs.nodes.size(); i++) {
		prj = prjs.nodes[i];
		hash += prj->Short + prj->Title;
	};

	cout << "project list hash: '" << hash << "'" << endl;

	// derive hash for (build-ready) versions
	//string hash;
	ubigint refWznmMProject;

	ListWznmMVersion vers;
	WznmMVersion* ver = NULL;

//	ListWznmJMVersionState verJstes;
//	WznmJMVersionState* verJste = NULL;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	ListWznmMPreset psts;
	WznmMPreset* pst = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	ListWznmMRelease rlss;
	WznmMRelease* rls = NULL;

	for (unsigned int k = 0; k < prjs.nodes.size(); k++) {
		prj = prjs.nodes[k];

		refWznmMProject = prj->ref;

		dbswznm->tblwznmmversion->loadRstBySQL("SELECT * FROM TblWznmMVersion WHERE prjRefWznmMProject = " + to_string(refWznmMProject) + " AND ixVState = " + to_string(VecWznmVMVersionState::READY)
					+ " ORDER BY prjNum ASC, Major ASC, Minor ASC, Sub ASC", false, vers);
		for (unsigned int i = 0; i < vers.nodes.size(); i++) {
			ver = vers.nodes[i];

			hash = to_string(ver->Major) + to_string(ver->Minor) + to_string(ver->Sub);

/*
			dbswznm->tblwznmjmversionstate->loadRstByVer(ver->ref, false, verJstes);
			for (unsigned int j = 0; j < verJstes.nodes.size(); j++) {
				verJste = verJstes.nodes[j];
				hash += to_string(verJste->x1Start) + VecWznmVMVersionState::getSref(verJste->ixVState);
			};
*/

			dbswznm->tblwznmmtable->loadRstByVer(ver->ref, false, tbls);
			for (unsigned int j = 0; j < tbls.nodes.size(); j++) {
				tbl = tbls.nodes[j];
				hash += tbl->sref;
			};

			dbswznm->tblwznmmvector->loadRstByVer(ver->ref, false, vecs);
			for (unsigned int j = 0; j < vecs.nodes.size(); j++) {
				vec = vecs.nodes[j];
				hash += vec->sref;
			};

			dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT TblWznmMImpexp.* FROM TblWznmMImpexpcplx, TblWznmMImpexp WHERE TblWznmMImpexp.refWznmMImpexpcplx = TblWznmMImpexpcplx.ref AND TblWznmMImpexpcplx.refWznmMVersion = "
						+ to_string(ver->ref) + " ORDER BY TblWznmMImpexp.sref ASC", false, imes);
			for (unsigned int j = 0; j < imes.nodes.size(); j++) {
				ime = imes.nodes[j];
				hash += ime->sref;
			};

			dbswznm->tblwznmmpreset->loadRstByVer(ver->ref, false, psts);
			for (unsigned int j = 0; j < psts.nodes.size(); j++) {
				pst = psts.nodes[j];
				hash += pst->sref;
			};

			dbswznm->tblwznmmop->loadRstBySQL("SELECT TblWznmMOp.* FROM TblWznmMOppack, TblWznmMOp WHERE TblWznmMOp.refWznmMOppack = TblWznmMOppack.ref AND TblWznmMOppack.refWznmMVersion = " + to_string(ver->ref)
						+ " ORDER BY TblWznmMOp.sref ASC", false, ops);
			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];
				hash += op->sref;
			};

			dbswznm->tblwznmmblock->loadRstByVer(ver->ref, false, blks);
			for (unsigned int j = 0; j < blks.nodes.size(); j++) {
				blk = blks.nodes[j];
				hash += blk->sref;
			};

			dbswznm->tblwznmmrelease->loadRstBySQL("SELECT TblWznmMRelease.* FROM TblWznmMComponent, TblWznmMRelease WHERE TblWznmMRelease.refWznmMComponent = TblWznmMComponent.ref AND TblWznmMComponent.refWznmMVersion = "
						+ to_string(ver->ref) + " ORDER BY TblWznmMRelease.sref ASC", false, rlss);
			for (unsigned int j = 0; j < rlss.nodes.size(); j++) {
				rls = rlss.nodes[j];
				hash += rls->sref;
			};

			cout << "hash for build-ready version " << prj->Short << " " << to_string(ver->Major) << "." << to_string(ver->Minor) << "." << to_string(ver->Sub) << " is '" << hash << "'" << endl;
		};
	};

	unsigned char md[SHA256_DIGEST_LENGTH];
	SHA256_CTX context;

	bool success;

	success = SHA256_Init(&context);

	if (success) success = SHA256_Update(&context, (const unsigned char*) hash.c_str(), hash.length());

	if (success) success = SHA256_Final(md, &context);

	if (success) cout << "hellyeah!" << endl;

	// IP handleTest --- IEND
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
