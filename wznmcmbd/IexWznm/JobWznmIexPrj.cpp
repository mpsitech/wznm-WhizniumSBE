/**
	* \file JobWznmIexPrj.cpp
	* job handler for job JobWznmIexPrj (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "JobWznmIexPrj.h"

#include "JobWznmIexPrj_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmPrj;

/******************************************************************************
 class JobWznmIexPrj
 ******************************************************************************/

JobWznmIexPrj::JobWznmIexPrj(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXPRJ, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexPrj::~JobWznmIexPrj() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexPrj::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexPrj::parseFromFile(
			DbsWznm* dbswznm
			, const string& _fullpath
			, const bool _xmlNotTxt
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;

		changeStage(dbswznm, VecVSge::PARSE);
	};
};

void JobWznmIexPrj::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexPrj::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexPrj::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexPrj::exportToFile(
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

void JobWznmIexPrj::handleRequest(
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

void JobWznmIexPrj::changeStage(
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

string JobWznmIexPrj::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing projects and versions";
			else if (ixVSge == VecVSge::PRSDONE) retval = "projects and versions parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing projects and versions (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing projects and versions import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting projects and versions for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "projects and versions collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting projects and versions";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexPrj::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeimproject.clear();

	return retval;
};

void JobWznmIexPrj::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexPrj::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmPrj::parseFromFile(fullpath, xmlNotTxt, imeimproject);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexPrj::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexPrj::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexPrj::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexPrj::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexPrj::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexPrj::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMProject* prj = NULL;
	ImeitemIMVersion* ver = NULL;
	ImeitemIRMPersonMProject* prsRprj = NULL;
	ImeitemIJMVersion* verJ = NULL;
	ImeitemIJMVersionState* verJste = NULL;
	ImeitemIRMLocaleMVersion* locRver = NULL;

	uint num1;

	// IP enterSgeImport.prep --- IBEGIN
	WznmMProject* prj_r = NULL;

	ubigint grp;
	grp = xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref);

	ubigint own;
	own = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);

	ListWznmMLocale lcls;
	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);

	string preflcl;

	time_t rawtime;
	time(&rawtime);

	vector<string> ss;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMProject
		for (unsigned int ix0 = 0; ix0 < imeimproject.nodes.size(); ix0++) {
			prj = imeimproject.nodes[ix0];

			prj->grp = grp;
			prj->own = own;
			//prj->refWznmMVersion: SUB
			//prj->Short: TBL
			//prj->Title: TBL
			//prj->Giturl: TBL
			//prj->Comment: TBL

			if (dbswznm->tblwznmmproject->loadRecBySQL("SELECT * FROM TblWznmMProject WHERE Short = '" + prj->Short + "'", &prj_r)) {
				prj->ref = prj_r->ref;
				prj->grp = prj_r->grp;
				prj->own = prj_r->own;
				prj->refWznmMVersion = prj_r->refWznmMVersion;
				prj->Short = prj_r->Short;
				prj->Title = prj_r->Title;
				prj->Giturl = prj_r->Giturl;
				prj->Comment = prj_r->Comment;

				delete prj_r;
			};

			if (prj->ref == 0) {
				dbswznm->tblwznmmproject->insertRec(prj);
				impcnt++;
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < prj->imeimversion.nodes.size(); ix1++) {
				ver = prj->imeimversion.nodes[ix1];

				ver->grp = grp;
				ver->own = own;
				ver->prjRefWznmMProject = prj->ref;
				ver->prjNum = num1++;
				//ver->refRLocale: SUB
				//ver->refWznmMLocale: TBL
				//ver->Major: TBL
				//ver->Minor: TBL
				//ver->Sub: TBL
				//ver->refJState: SUB
				if (ver->srefIxVState == "") ver->srefIxVState = "newimp";
				ver->ixVState = VecWznmVMVersionState::getIx(ver->srefIxVState);
				if (ver->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ver->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(ver->lineno)}});
				ver->ixWDbmstype = VecWznmWMVersionDbmstype::getIx(ver->srefsIxWDbmstype);
				ver->ixWOption = VecWznmWMVersionOption::getIx(ver->srefsIxWOption);
				//ver->refJ: SUB
				//ver->About1: TBL
				//ver->About2: TBL
				//ver->About3: TBL
				//ver->Comment: TBL

				dbswznm->tblwznmmversion->insertRec(ver);
				impcnt++;

				if (((ver->srefIxVState != "")) && ver->imeijmversionstate.nodes.empty()) {
					verJste = new ImeitemIJMVersionState();
					ver->imeijmversionstate.nodes.push_back(verJste);

					verJste->refWznmMVersion = ver->ref;
					verJste->srefIxVState = ver->srefIxVState;
				};

				if (((ver->About1 != "") || (ver->About2 != "") || (ver->About3 != "")) && ver->imeijmversion.nodes.empty()) {
					verJ = new ImeitemIJMVersion();
					ver->imeijmversion.nodes.push_back(verJ);

					verJ->refWznmMVersion = ver->ref;
					verJ->About1 = ver->About1;
					verJ->About2 = ver->About2;
					verJ->About3 = ver->About3;
				};

				if (ix1 == 0) {
					prj->refWznmMVersion = ver->ref;
					dbswznm->tblwznmmproject->updateRec(prj);
				};

				preflcl = "";

				for (unsigned int ix2 = 0; ix2 < ver->imeirmlocalemversion.nodes.size(); ix2++) {
					locRver = ver->imeirmlocalemversion.nodes[ix2];

					//locRver->refWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++)
						if (lcls.nodes[i]->sref == locRver->srefRefWznmMLocale) {
							locRver->refWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					if (locRver->refWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",locRver->srefRefWznmMLocale}, {"iel","srefRefWznmMLocale"}, {"lineno",to_string(locRver->lineno)}});
					locRver->refWznmMVersion = ver->ref;

					dbswznm->tblwznmrmlocalemversion->insertRec(locRver);
					impcnt++;

					if (ix2 == 0) {
						ver->refRLocale = locRver->ref;
						ver->refWznmMLocale = locRver->refWznmMLocale;
						dbswznm->tblwznmmversion->updateRec(ver);

						preflcl = locRver->srefRefWznmMLocale;
					};
				};

				for (unsigned int ix2 = 0; ix2 < ver->imeijmversionstate.nodes.size(); ix2++) {
					verJste = ver->imeijmversionstate.nodes[ix2];

					verJste->refWznmMVersion = ver->ref;
					verJste->x1Start = Ftm::invstamp("&now;");
					verJste->ixVState = VecWznmVMVersionState::getIx(verJste->srefIxVState);
					if (verJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",verJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(verJste->lineno)}});

					dbswznm->tblwznmjmversionstate->insertRec(verJste);
					impcnt++;

					if (ix2 == 0) {
						ver->refJState = verJste->ref;
						ver->ixVState = verJste->ixVState;
						dbswznm->tblwznmmversion->updateRec(ver);
					};
				};

				for (unsigned int ix2 = 0; ix2 < ver->imeijmversion.nodes.size(); ix2++) {
					verJ = ver->imeijmversion.nodes[ix2];

					verJ->refWznmMVersion = ver->ref;
					//if (verJ->srefX1RefWznmMLocale == "") verJ->srefX1RefWznmMLocale: CUSTOM DEFVAL
					if (verJ->srefX1RefWznmMLocale == "") verJ->srefX1RefWznmMLocale = preflcl;
					//verJ->x1RefWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
						if (lcls.nodes[i]->sref == verJ->srefX1RefWznmMLocale) {
							verJ->x1RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					};
					if (verJ->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",verJ->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(verJ->lineno)}});
					//verJ->About1: TBL
					//verJ->About2: TBL
					//verJ->About3: TBL

					dbswznm->tblwznmjmversion->insertRec(verJ);
					impcnt++;

					if (ix2 == 0) {
						ver->refJ = verJ->ref;
						ver->About1 = verJ->About1;
						ver->About2 = verJ->About2;
						ver->About3 = verJ->About3;
						dbswznm->tblwznmmversion->updateRec(ver);
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < prj->imeirmpersonmproject.nodes.size(); ix1++) {
				prsRprj = prj->imeirmpersonmproject.nodes[ix1];

				//prsRprj->refWznmMPerson: THINT ; look for any person, format StubWznmPrsStd
				StrMod::stringToVector(prsRprj->hintRefWznmMPerson, ss, ' ');
				if (ss.size() == 2) dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPerson WHERE Lastname = '" + StrMod::esc(ss[1]) + "' AND Firstname = '" + StrMod::esc(ss[0]) + "'", prsRprj->refWznmMPerson);
				prsRprj->refWznmMProject = prj->ref;
				//prsRprj->srefKFunction: TBL

				dbswznm->tblwznmrmpersonmproject->insertRec(prsRprj);
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

void JobWznmIexPrj::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexPrj::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexPrj::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexPrj::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMProject* prj = NULL;
	ImeitemIMVersion* ver = NULL;
	ImeitemIRMPersonMProject* prsRprj = NULL;
	ImeitemIJMVersion* verJ = NULL;
	ImeitemIJMVersionState* verJste = NULL;
	ImeitemIRMLocaleMVersion* locRver = NULL;

	// -- ImeIMProject
	for (unsigned int ix0 = 0; ix0 < imeimproject.nodes.size(); ix0++) {
		prj = imeimproject.nodes[ix0];
		if (prj->ref != 0) dbswznm->tblwznmmproject->removeRecByRef(prj->ref);

		for (unsigned int ix1 = 0; ix1 < prj->imeimversion.nodes.size(); ix1++) {
			ver = prj->imeimversion.nodes[ix1];
			if (ver->ref != 0) dbswznm->tblwznmmversion->removeRecByRef(ver->ref);

			for (unsigned int ix2 = 0; ix2 < ver->imeijmversion.nodes.size(); ix2++) {
				verJ = ver->imeijmversion.nodes[ix2];
				if (verJ->ref != 0) dbswznm->tblwznmjmversion->removeRecByRef(verJ->ref);
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeijmversionstate.nodes.size(); ix2++) {
				verJste = ver->imeijmversionstate.nodes[ix2];
				if (verJste->ref != 0) dbswznm->tblwznmjmversionstate->removeRecByRef(verJste->ref);
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeirmlocalemversion.nodes.size(); ix2++) {
				locRver = ver->imeirmlocalemversion.nodes[ix2];
				if (locRver->ref != 0) dbswznm->tblwznmrmlocalemversion->removeRecByRef(locRver->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < prj->imeirmpersonmproject.nodes.size(); ix1++) {
			prsRprj = prj->imeirmpersonmproject.nodes[ix1];
			if (prsRprj->ref != 0) dbswznm->tblwznmrmpersonmproject->removeRecByRef(prsRprj->ref);
		};
	};

	return retval;
};

void JobWznmIexPrj::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexPrj::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMProject* prj = NULL;
	ImeitemIMVersion* ver = NULL;
	ImeitemIRMPersonMProject* prsRprj = NULL;
	ImeitemIJMVersion* verJ = NULL;
	ImeitemIJMVersionState* verJste = NULL;
	ImeitemIRMLocaleMVersion* locRver = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- RBEGIN

	// -- ImeIMProject
	for (unsigned int ix0 = 0; ix0 < imeimproject.nodes.size(); ix0++) {
		prj = imeimproject.nodes[ix0];

		if (prj->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMVERSION, ixWznmVIop)) {
			dbswznm->tblwznmmversion->loadRefsByPrj(prj->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) prj->imeimversion.nodes.push_back(new ImeitemIMVersion(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < prj->imeimversion.nodes.size(); ix1++) {
			ver = prj->imeimversion.nodes[ix1];

			if (ver->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMVERSION, ixWznmVIop)) {
				dbswznm->tblwznmjmversion->loadRefsByVer(ver->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == ver->refJ) {refs[i] = refs[0]; refs[0] = ver->refJ; break;};
				for (unsigned int i = 0; i < refs.size(); i++) ver->imeijmversion.nodes.push_back(new ImeitemIJMVersion(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeijmversion.nodes.size(); ix2++) {
				verJ = ver->imeijmversion.nodes[ix2];

				if (verJ->ref != 0) {
					verJ->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, verJ->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMVERSIONSTATE, ixWznmVIop)) {
				dbswznm->tblwznmjmversionstate->loadRefsByVer(ver->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == ver->refJState) {refs[i] = refs[0]; refs[0] = ver->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) ver->imeijmversionstate.nodes.push_back(new ImeitemIJMVersionState(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeijmversionstate.nodes.size(); ix2++) {
				verJste = ver->imeijmversionstate.nodes[ix2];

				if (verJste->ref != 0) {
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMLOCALEMVERSION, ixWznmVIop)) {
				dbswznm->tblwznmrmlocalemversion->loadRefsByVer(ver->ref, false, refs);

				// put primary locale first
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == ver->refRLocale) {refs[i] = refs[0]; refs[0] = ver->refRLocale; break;};

				for (unsigned int i = 0; i < refs.size(); i++) ver->imeirmlocalemversion.nodes.push_back(new ImeitemIRMLocaleMVersion(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ver->imeirmlocalemversion.nodes.size(); ix2++) {
				locRver = ver->imeirmlocalemversion.nodes[ix2];

				if (locRver->ref != 0) {
					locRver->srefRefWznmMLocale = StubWznm::getStubLocSref(dbswznm, locRver->refWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMPERSONMPROJECT, ixWznmVIop)) {
			dbswznm->tblwznmrmpersonmproject->loadRefsByPrj(prj->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) prj->imeirmpersonmproject.nodes.push_back(new ImeitemIRMPersonMProject(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < prj->imeirmpersonmproject.nodes.size(); ix1++) {
			prsRprj = prj->imeirmpersonmproject.nodes[ix1];

			if (prsRprj->ref != 0) {
				prsRprj->hintRefWznmMPerson = StubWznm::getStubPrsStd(dbswznm, prsRprj->refWznmMPerson, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};
	// IP enterSgeCollect.traverse --- REND
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexPrj::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexPrj::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexPrj::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexPrj::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmPrj::exportToFile(fullpath, xmlNotTxt, shorttags, imeimproject);

	return retval;
};

void JobWznmIexPrj::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexPrj::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexPrj::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


