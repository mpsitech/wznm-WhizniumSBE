/**
	* \file JobWznmIexDpl.cpp
	* job handler for job JobWznmIexDpl (implementation)
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

#include "JobWznmIexDpl.h"

#include "JobWznmIexDpl_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmDpl;

/******************************************************************************
 class JobWznmIexDpl
 ******************************************************************************/

JobWznmIexDpl::JobWznmIexDpl(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXDPL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexDpl::~JobWznmIexDpl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexDpl::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexDpl::parseFromFile(
			DbsWznm* dbswznm
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const string& _rectpath
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		rectpath = _rectpath;

		changeStage(dbswznm, VecVSge::PARSE);
	};
};

void JobWznmIexDpl::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexDpl::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexDpl::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexDpl::exportToFile(
			DbsWznm* dbswznm
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const bool _shorttags
		) {
	if ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CLTDONE)) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		shorttags = _shorttags;

		changeStage(dbswznm, VecVSge::EXPORT);
	};
};

void JobWznmIexDpl::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

void JobWznmIexDpl::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::PARSE: leaveSgeParse(dbswznm); break;
				case VecVSge::PRSERR: leaveSgePrserr(dbswznm); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswznm); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswznm); break;
				case VecVSge::IMPERR: leaveSgeImperr(dbswznm); break;
				case VecVSge::REVERSE: leaveSgeReverse(dbswznm); break;
				case VecVSge::COLLECT: leaveSgeCollect(dbswznm); break;
				case VecVSge::CLTDONE: leaveSgeCltdone(dbswznm); break;
				case VecVSge::EXPORT: leaveSgeExport(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswznm, reenter); break;
			case VecVSge::PRSERR: _ixVSge = enterSgePrserr(dbswznm, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswznm, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswznm, reenter); break;
			case VecVSge::IMPERR: _ixVSge = enterSgeImperr(dbswznm, reenter); break;
			case VecVSge::REVERSE: _ixVSge = enterSgeReverse(dbswznm, reenter); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbswznm, reenter); break;
			case VecVSge::CLTDONE: _ixVSge = enterSgeCltdone(dbswznm, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWznmIexDpl::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing deployment information";
			else if (ixVSge == VecVSge::PRSDONE) retval = "deployment information parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing deployment information (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing deployment information import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting deployment information for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "deployment information collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting deployment information";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexDpl::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;
	rectpath = "";

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeimcomponent.clear();

	return retval;
};

void JobWznmIexDpl::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexDpl::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmDpl::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimcomponent);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexDpl::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexDpl::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexDpl::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexDpl::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexDpl::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexDpl::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMComponent* cmp = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMComponentMLibrary* cmpRlib = NULL;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWznmMVersion;
	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	vector<ubigint> refs;
	map<string,ubigint> refsMchs; // by hsref

	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMMachine", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) refsMchs[StubWznm::getStubMchStd(dbswznm, refs[i])] = refs[i];
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMComponent
		for (unsigned int ix0 = 0; ix0 < imeimcomponent.nodes.size(); ix0++) {
			cmp = imeimcomponent.nodes[ix0];

			cmp->ixVBasetype = VecWznmVMComponentBasetype::getIx(cmp->srefIxVBasetype);
			if (cmp->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cmp->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(cmp->lineno)}});
			//cmp->refWznmMVersion: PRESET
			cmp->refWznmMVersion = refWznmMVersion;
			//cmp->sref: TBL
			//cmp->Title: TBL
			//cmp->Comment: TBL

			dbswznm->tblwznmmcomponent->insertRec(cmp);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < cmp->imeimrelease.nodes.size(); ix1++) {
				rls = cmp->imeimrelease.nodes[ix1];

				rls->refWznmMComponent = cmp->ref;
				//rls->refWznmMMachine: CUST
				if (rls->hsrefRefWznmMMachine != "") {
					auto it = refsMchs.find(rls->hsrefRefWznmMMachine);
					if (it != refsMchs.end()) rls->refWznmMMachine = it->second;
					else throw SbeException(SbeException::IEX_TSREF, {{"tsref",rls->hsrefRefWznmMMachine}, {"iel","hsrefRefWznmMMachine"}, {"lineno",to_string(rls->lineno)}});
				};
				//rls->sref: TBL
				//rls->srefsKOption: TBL
				//rls->Comment: TBL

				dbswznm->tblwznmmrelease->insertRec(rls);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < cmp->imeirmcomponentmlibrary.nodes.size(); ix1++) {
				cmpRlib = cmp->imeirmcomponentmlibrary.nodes[ix1];

				cmpRlib->refWznmMComponent = cmp->ref;
				//cmpRlib->refWznmMLibrary: CUSTSQL
				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMLibrary WHERE sref = '" + cmpRlib->srefRefWznmMLibrary + "'", cmpRlib->refWznmMLibrary);
				if (cmpRlib->refWznmMLibrary == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmpRlib->srefRefWznmMLibrary}, {"iel","srefRefWznmMLibrary"}, {"lineno",to_string(cmpRlib->lineno)}});

				dbswznm->tblwznmrmcomponentmlibrary->insertRec(cmpRlib);
				impcnt++;
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexDpl::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexDpl::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexDpl::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexDpl::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMComponent* cmp = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMComponentMLibrary* cmpRlib = NULL;

	// -- ImeIMComponent
	for (unsigned int ix0 = 0; ix0 < imeimcomponent.nodes.size(); ix0++) {
		cmp = imeimcomponent.nodes[ix0];
		if (cmp->ref != 0) dbswznm->tblwznmmcomponent->removeRecByRef(cmp->ref);

		for (unsigned int ix1 = 0; ix1 < cmp->imeimrelease.nodes.size(); ix1++) {
			rls = cmp->imeimrelease.nodes[ix1];
			if (rls->ref != 0) dbswznm->tblwznmmrelease->removeRecByRef(rls->ref);
		};

		for (unsigned int ix1 = 0; ix1 < cmp->imeirmcomponentmlibrary.nodes.size(); ix1++) {
			cmpRlib = cmp->imeirmcomponentmlibrary.nodes[ix1];
			if (cmpRlib->ref != 0) dbswznm->tblwznmrmcomponentmlibrary->removeRecByRef(cmpRlib->ref);
		};
	};

	return retval;
};

void JobWznmIexDpl::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexDpl::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMComponent* cmp = NULL;
	ImeitemIMRelease* rls = NULL;
	ImeitemIRMComponentMLibrary* cmpRlib = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMComponent
	for (unsigned int ix0 = 0; ix0 < imeimcomponent.nodes.size(); ix0++) {
		cmp = imeimcomponent.nodes[ix0];

		if (cmp->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMRELEASE, ixWznmVIop)) {
			dbswznm->tblwznmmrelease->loadRefsByCmp(cmp->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cmp->imeimrelease.nodes.push_back(new ImeitemIMRelease(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cmp->imeimrelease.nodes.size(); ix1++) {
			rls = cmp->imeimrelease.nodes[ix1];

			if (rls->ref != 0) {
				rls->hsrefRefWznmMMachine = StubWznm::getStubMchStd(dbswznm, rls->refWznmMMachine, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMCOMPONENTMLIBRARY, ixWznmVIop)) {
			dbswznm->tblwznmrmcomponentmlibrary->loadRefsByCmp(cmp->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cmp->imeirmcomponentmlibrary.nodes.push_back(new ImeitemIRMComponentMLibrary(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cmp->imeirmcomponentmlibrary.nodes.size(); ix1++) {
			cmpRlib = cmp->imeirmcomponentmlibrary.nodes[ix1];

			if (cmpRlib->ref != 0) {
				cmpRlib->srefRefWznmMLibrary = StubWznm::getStubLibSref(dbswznm, cmpRlib->refWznmMLibrary, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexDpl::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexDpl::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexDpl::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexDpl::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmDpl::exportToFile(fullpath, xmlNotTxt, shorttags, imeimcomponent);

	return retval;
};

void JobWznmIexDpl::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexDpl::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexDpl::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};



