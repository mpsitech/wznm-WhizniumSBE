/**
	* \file DlgWznmPrjNew.cpp
	* job handler for job DlgWznmPrjNew (implementation)
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

#include "DlgWznmPrjNew.h"

#include "DlgWznmPrjNew_blks.cpp"
#include "DlgWznmPrjNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmPrjNew
 ******************************************************************************/

DlgWznmPrjNew::DlgWznmPrjNew(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMPRJNEW, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDetLstDty.tag = "FeedFDetLstDty";
	VecWznmWMVersionDbmstype::fillFeed(ixWznmVLocale, feedFDetLstDty);
	feedFDetLstLoc.tag = "FeedFDetLstLoc";
	feedFDetPupPlc.tag = "FeedFDetPupPlc";
	feedFDetPupPmc.tag = "FeedFDetPupPmc";
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	license = NULL;

	// IP constructor.cust1 --- IBEGIN
	ListWznmMLocale locs;
	WznmMLocale* loc = NULL;

	ListWznmMMachine mchs;
	WznmMMachine* mch = NULL;

	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale ORDER BY sref ASC", false, locs);
	for (unsigned int i = 0; i < locs.nodes.size(); i++) {
		loc = locs.nodes[i];
		feedFDetLstLoc.appendIxRefSrefTitles(0, loc->ref, loc->sref, StubWznm::getStubLocStd(dbswznm, loc->ref));
	};

	dbswznm->tblwznmmmachine->loadRstBySQL("SELECT * FROM TblWznmMMachine ORDER BY supRefWznmMMachine ASC, sref ASC", false, mchs);
	for (unsigned int i = 0; i < mchs.nodes.size(); i++) {
		mch = mchs.nodes[i];
		feedFDetPupPmc.appendIxRefSrefTitles(0, mch->ref, mch->sref, StubWznm::getStubMchStd(dbswznm, mch->ref));
	};
	// IP constructor.cust1 --- IEND

	valid = false;

	license = new JobWznmLicense(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmPrjNew::~DlgWznmPrjNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgWznmPrjNew::refreshDetPlc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// fill feedFDetPupPlc based on selection in LstLoc
	ContIac oldContiac(contiac);

	ubigint refOld;

	refOld = feedFDetPupPlc.getRefByNum(contiac.numFDetPupPlc);

	feedFDetPupPlc.clear();
	contiac.numFDetPupPlc = 0;

	for (unsigned int i = 0; i < contiac.numsFDetLstLoc.size(); i++) {
		feedFDetPupPlc.nodes.push_back(new Feeditem(*feedFDetLstLoc.getByNum(contiac.numsFDetLstLoc[i])));
		if (feedFDetLstLoc.getRefByNum(contiac.numsFDetLstLoc[i]) == refOld) contiac.numFDetPupPlc = i+1;
	};

	insert(moditems, DpchEngData::FEEDFDETPUPPLC);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};
// IP cust --- IEND

DpchEngWznm* DlgWznmPrjNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetLstDty, &feedFDetLstLoc, &feedFDetPupPlc, &feedFDetPupPmc, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWznmPrjNew::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- BEGIN
	// statshr
	statshr.DetButAutActive = evalDetButAutActive(dbswznm);
	statshr.ButCncActive = evalButCncActive(dbswznm);
	statshr.ButCreActive = evalButCreActive(dbswznm);

	// continf
	continf.numFSge = ixVSge;

	// contiac

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	muteRefresh = false;
};

void DlgWznmPrjNew::handleRequest(
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

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMINIT) {
			handleDpchAppWznmInit(dbswznm, (DpchAppWznmInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMPRJNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMPRJNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::DETBUTAUTCLICK) {
					handleDpchAppDoDetButAutClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

void DlgWznmPrjNew::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmPrjNew::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	ubigint ref;

	// validate DetTxfSho
	valid = (_contiac->DetTxfSho.length() == 4);
	if (valid) valid = (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMProject WHERE Short = '" + StrMod::lc(_contiac->DetTxfSho) + "'", ref) == false);

	if (valid) contiac.DetTxfSho = _contiac->DetTxfSho;
	else contiac.DetTxfSho = "";

	if (valid) {
		// validate DetTxfTit
		valid = (_contiac->DetTxfTit.length() != 0);

		if (valid) contiac.DetTxfTit = _contiac->DetTxfTit;
		else contiac.DetTxfTit = "";
	};

	if (has(diffitems, ContIac::DETTXFABT)) contiac.DetTxfAbt = _contiac->DetTxfAbt;
	if (has(diffitems, ContIac::NUMSFDETLSTDTY)) contiac.numsFDetLstDty = _contiac->numsFDetLstDty;

	if (has(diffitems, ContIac::NUMFDETPUPPLC)) {
		if (feedFDetPupPlc.getRefByNum(_contiac->numFDetPupPlc) != 0) contiac.numFDetPupPlc = _contiac->numFDetPupPlc;
		else contiac.numFDetPupPlc = 0;
	};

	if (has(diffitems, ContIac::NUMSFDETLSTLOC)) {
		contiac.numsFDetLstLoc = _contiac->numsFDetLstLoc;
		refreshDetPlc(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFDETPUPPMC)) {
		if (feedFDetPupPmc.getRefByNum(_contiac->numFDetPupPmc) != 0) contiac.numFDetPupPmc = _contiac->numFDetPupPmc;
		else contiac.numFDetPupPmc = 0;
	};

	valid = (valid && (contiac.numsFDetLstDty.size() > 0) && (contiac.numFDetPupPlc != 0) && (contiac.numFDetPupPmc != 0));

	refresh(dbswznm, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmPrjNew::handleDpchAppDoDetButAutClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoDetButAutClick --- BEGIN
	if (statshr.DetButAutActive) {
		changeStage(dbswznm, VecVSge::AUTH, dpcheng);
	};
	// IP handleDpchAppDoDetButAutClick --- END
};

void DlgWznmPrjNew::handleDpchAppDoButCncClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCncClick --- IBEGIN
	if (statshr.ButCncActive) {
		*dpcheng = new DpchEngWznmConfirm(true, jref, "");
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButCncClick --- IEND
};

void DlgWznmPrjNew::handleDpchAppDoButCreClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::AUTDONE) {
			changeStage(dbswznm, VecVSge::CREATE);
		};

		if (ixVSge == VecVSge::DONE) {
			if (!*dpcheng) *dpcheng = new DpchEngWznmConfirm(true, jref, "");
			xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgWznmPrjNew::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- INSERT
};

void DlgWznmPrjNew::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRAER: leaveSgeAlraer(dbswznm); break;
				case VecVSge::AUTH: leaveSgeAuth(dbswznm); break;
				case VecVSge::AUTDONE: leaveSgeAutdone(dbswznm); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswznm); break;
				case VecVSge::SYNC: leaveSgeSync(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRAER: _ixVSge = enterSgeAlraer(dbswznm, reenter); break;
			case VecVSge::AUTH: _ixVSge = enterSgeAuth(dbswznm, reenter); break;
			case VecVSge::AUTDONE: _ixVSge = enterSgeAutdone(dbswznm, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswznm, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmPrjNew::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::AUTH) || (ixVSge == VecVSge::AUTDONE) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::AUTH) retval = "authenticating";
			else if (ixVSge == VecVSge::AUTDONE) retval = "authentication successful";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing new project with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmPrjNew::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmPrjNew::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmPrjNew::enterSgeAlraer(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRAER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlraer --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Authentication failure.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	// IP enterSgeAlraer --- END
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmPrjNew::leaveSgeAlraer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlraer --- INSERT
};

uint DlgWznmPrjNew::enterSgeAuth(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::AUTDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRAER;

	// IP enterSgeAuth --- IBEGIN

	if (!license->authPrjNew()) retval = nextIxVSgeFailure;

	// IP enterSgeAuth --- IEND

	return retval;
};

void DlgWznmPrjNew::leaveSgeAuth(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAuth --- INSERT
};

uint DlgWznmPrjNew::enterSgeAutdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::AUTDONE;

	// IP enterSgeAutdone --- INSERT

	return retval;
};

void DlgWznmPrjNew::leaveSgeAutdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAutdone --- INSERT
};

uint DlgWznmPrjNew::enterSgeCreate(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::SYNC;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN
	ubigint ref;

	WznmMProject prj;
	WznmMVersion ver;

	ubigint refLoc;

	ubigint refMch;
	string srefMch;

	// project and version
	prj.grp = xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref);
	prj.own = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
	prj.Short = StrMod::lc(contiac.DetTxfSho);
	prj.Title = contiac.DetTxfTit;

	dbswznm->tblwznmmproject->insertRec(&prj);

	dbswznm->loadRefBySQL("SELECT refWznmMPerson FROM TblWznmMUser WHERE ref = " + to_string(prj.own), ref);
	dbswznm->tblwznmrmpersonmproject->insertNewRec(NULL, 0, 0, ref, prj.ref, "mgr");

	ver.grp = prj.grp;
	ver.own = prj.own;
	ver.prjRefWznmMProject = prj.ref;
	ver.prjNum = 1;
	ver.Major = 0;
	ver.Minor = 1;
	ver.Sub = 0;
	ver.ixVState = VecWznmVMVersionState::NEWCRE;

	ver.ixWDbmstype = 0;
	for (unsigned int i = 0; i < contiac.numsFDetLstDty.size(); i++) ver.ixWDbmstype |= feedFDetLstDty.getIxByNum(contiac.numsFDetLstDty[i]);

	ver.About1 = contiac.DetTxfAbt;

	dbswznm->tblwznmmversion->insertRec(&ver);

	prj.refWznmMVersion = ver.ref;
	dbswznm->tblwznmmproject->updateRec(&prj);

	time_t rawtime;
	time(&rawtime);

	ver.refJState = dbswznm->tblwznmjmversionstate->insertNewRec(NULL, ver.ref, rawtime, ver.ixVState);

	for (unsigned int i = 0; i < contiac.numsFDetLstLoc.size(); i++) {
		refLoc = feedFDetLstLoc.getRefByNum(contiac.numsFDetLstLoc[i]);
		ref = dbswznm->tblwznmrmlocalemversion->insertNewRec(NULL, refLoc, ver.ref);

		if (refLoc == feedFDetPupPlc.getRefByNum(contiac.numFDetPupPlc)) {
			ver.refRLocale = ref;
			ver.refWznmMLocale = refLoc;
		};
	};

	if (ver.About1 != "") ver.refJ = dbswznm->tblwznmjmversion->insertNewRec(NULL, ver.ref, ver.refWznmMLocale, ver.About1, "", "");

	dbswznm->tblwznmmversion->updateRec(&ver);

	// capabilities
	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCapability WHERE tplRefWznmMCapability = 0 AND sref = 'arm'", ref);
	dbswznm->tblwznmmcapability->insertNewRec(NULL, ver.ref, ref, "arm", 0, "Access rights management");

	// components and releases
	refMch = feedFDetPupPmc.getRefByNum(contiac.numFDetPupPmc);
	srefMch = feedFDetPupPmc.getSrefByNum(contiac.numFDetPupPmc);

	ref = dbswznm->tblwznmmcomponent->insertNewRec(NULL, VecWznmVMComponentBasetype::DBS, ver.ref, "dbs" + prj.Short, prj.Title + " database access library", "");
	dbswznm->tblwznmmrelease->insertNewRec(NULL, ref, refMch, "dbs" + prj.Short + "_" + srefMch, "", "");

	ref = dbswznm->tblwznmmcomponent->insertNewRec(NULL, VecWznmVMComponentBasetype::CMBENG, ver.ref, prj.Short + "cmbd", prj.Title + " combined engine", "");
	dbswznm->tblwznmmrelease->insertNewRec(NULL, ref, refMch, "" + prj.Short + "cmbd_" + srefMch, "", "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMMachine WHERE supRefWznmMMachine = 0 AND sref = 'any'", refMch);

	ref = dbswznm->tblwznmmcomponent->insertNewRec(NULL, VecWznmVMComponentBasetype::WEBAPP, ver.ref, "webapp" + prj.Short, prj.Title + " web app user interface files", "");
	dbswznm->tblwznmmrelease->insertNewRec(NULL, ref, refMch, "webapp" + prj.Short + "_any", "", "");

	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMPRJMOD, jref);
	xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFPRJ, prj.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWznmPrjNew::leaveSgeCreate(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWznmPrjNew::enterSgeSync(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSync --- IBEGIN

	license->syncPrj(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRJ, jref));

	// IP enterSgeSync --- IEND

	return retval;
};

void DlgWznmPrjNew::leaveSgeSync(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSync --- INSERT
};

uint DlgWznmPrjNew::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmPrjNew::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};



