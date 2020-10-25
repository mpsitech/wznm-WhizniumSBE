/**
	* \file DlgWznmVerNew.cpp
	* job handler for job DlgWznmVerNew (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmVerNew.h"

#include "DlgWznmVerNew_blks.cpp"
#include "DlgWznmVerNew_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVerNew
 ******************************************************************************/

DlgWznmVerNew::DlgWznmVerNew(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVERNEW, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDetLstLoc.tag = "FeedFDetLstLoc";
	feedFDetPupBvr.tag = "FeedFDetPupBvr";
	feedFDetPupPlc.tag = "FeedFDetPupPlc";
	feedFDetPupPrj.tag = "FeedFDetPupPrj";
	feedFDetRbuVni.tag = "FeedFDetRbuVni";
	VecVVni::fillFeed(ixWznmVLocale, feedFDetRbuVni);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iexprj = NULL;

	// IP constructor.cust1 --- IBEGIN
	ListWznmMProject prjs;
	WznmMProject* prj = NULL;

	ListWznmMLocale locs;
	WznmMLocale* loc = NULL;

	contiac.numFDetPupPrj = 0;

	dbswznm->tblwznmmproject->loadRstBySQL("SELECT * FROM TblWznmMProject ORDER BY Short ASC", false, prjs);
	for (unsigned int i = 0; i < prjs.nodes.size(); i++) {
		prj = prjs.nodes[i];
		feedFDetPupPrj.appendIxRefSrefTitles(0, prj->ref, prj->Short, StubWznm::getStubPrjStd(dbswznm, prj->ref));
	};

	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale ORDER BY sref ASC", false, locs);
	for (unsigned int i = 0; i < locs.nodes.size(); i++) {
		loc = locs.nodes[i];
		feedFDetLstLoc.appendIxRefSrefTitles(0, loc->ref, loc->sref, StubWznm::getStubLocStd(dbswznm, loc->ref));
	};
	// IP constructor.cust1 --- IEND

	valid = false;

	iexprj = new JobWznmIexPrj(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVerNew::~DlgWznmVerNew() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgWznmVerNew::refreshDetBvr(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// fill feedFDetPupBvr based on selection in PupPrj
	ContIac oldContiac(contiac);

	vector<ubigint> refs;

	WznmMProject* prj = NULL;

	feedFDetPupBvr.clear();
	contiac.numFDetPupBvr = 0;
	contiac.numsFDetLstLoc.clear();
	contiac.numFDetPupPlc = 0;

	if (dbswznm->tblwznmmproject->loadRecByRef(feedFDetPupPrj.getRefByNum(contiac.numFDetPupPrj), &prj)) {
		dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMVersion WHERE prjRefWznmMProject = " + to_string(prj->ref) + " ORDER BY prjNum ASC", false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) {
			feedFDetPupBvr.appendRefTitles(refs[i], StubWznm::getStubVerStd(dbswznm, refs[i]));

			if (refs[i] == prj->refWznmMVersion) {
				contiac.numFDetPupBvr = (i+1);

				refreshDetLstLoc(dbswznm, moditems);
				refreshDetPupPlc(dbswznm, moditems);
			};
		};

		delete prj;
	};

	insert(moditems, DpchEngData::FEEDFDETPUPBVR);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};

void DlgWznmVerNew::refreshDetLstLoc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// make selection numsFDetLstLoc based on selection in PupBvr
	ContIac oldContiac(contiac);

	vector<ubigint> refs;
	uint num;

	contiac.numsFDetLstLoc.clear();

	dbswznm->loadRefsBySQL("SELECT refWznmMLocale FROM TblWznmRMLocaleMVersion WHERE refWznmMVersion = " + to_string(feedFDetPupBvr.getRefByNum(contiac.numFDetPupBvr)), false, refs);

	for (unsigned int i = 0; i < refs.size(); i++) {
		num = feedFDetLstLoc.getNumByRef(refs[i]);
		if (num != 0) contiac.numsFDetLstLoc.push_back(num);
	};

	insert(moditems, DpchEngData::FEEDFDETLSTLOC);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshDetPlc(dbswznm, moditems);
};

void DlgWznmVerNew::refreshDetPupPlc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// make selection numFDetPupPlc based on selection in PupBvr
	ContIac oldContiac(contiac);

	ubigint ref;

	contiac.numFDetPupPlc = 0;

	dbswznm->loadRefBySQL("SELECT refWznmMLocale FROM TblWznmMVersion WHERE ref = " + to_string(feedFDetPupBvr.getRefByNum(contiac.numFDetPupBvr)), ref);
	contiac.numFDetPupPlc = feedFDetPupPlc.getNumByRef(ref);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
};

void DlgWznmVerNew::refreshDetPlc(
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

DpchEngWznm* DlgWznmVerNew::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFDetLstLoc, &feedFDetPupBvr, &feedFDetPupPlc, &feedFDetPupPrj, &feedFDetRbuVni, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWznmVerNew::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButCreActive = evalButCreActive(dbswznm);

	// contiac

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
};

void DlgWznmVerNew::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTCNCCLICK) {
					handleDpchAppDoButCncClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCRECLICK) {
					handleDpchAppDoButCreClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void DlgWznmVerNew::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVerNew::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	if (has(diffitems, ContIac::NUMFDETRBUVNI)) {
		if ((_contiac->numFDetRbuVni >= VecVVni::MAJ) && (_contiac->numFDetRbuVni <= VecVVni::VOID)) contiac.numFDetRbuVni = _contiac->numFDetRbuVni;
		else contiac.numFDetRbuVni = VecVVni::MAJ;
	};

	if (has(diffitems, ContIac::NUMFDETPUPPLC)) {
		if (feedFDetPupPlc.getRefByNum(_contiac->numFDetPupPlc) != 0) contiac.numFDetPupPlc = _contiac->numFDetPupPlc;
		else contiac.numFDetPupPlc = 0;
	};

	if (has(diffitems, ContIac::NUMFDETPUPPRJ)) {
		if (feedFDetPupPrj.getRefByNum(_contiac->numFDetPupPrj) != 0) contiac.numFDetPupPrj = _contiac->numFDetPupPrj;
		else contiac.numFDetPupPrj = 0;

		refreshDetBvr(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMFDETPUPBVR)) {
		if (feedFDetPupBvr.getRefByNum(_contiac->numFDetPupBvr) != 0) contiac.numFDetPupBvr = _contiac->numFDetPupBvr;
		else contiac.numFDetPupBvr = 0;

		refreshDetLstLoc(dbswznm, moditems);
		refreshDetPupPlc(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::NUMSFDETLSTLOC)) {
		contiac.numsFDetLstLoc = _contiac->numsFDetLstLoc;
		refreshDetPlc(dbswznm, moditems);
	};

	valid = ((contiac.numFDetPupPrj != 0) && (contiac.numsFDetLstLoc.size() > 0) && (contiac.numFDetPupPlc != 0));

	refresh(dbswznm, moditems);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmVerNew::handleDpchAppDoButCncClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCncClick --- IBEGIN
	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
	// IP handleDpchAppDoButCncClick --- IEND
};

void DlgWznmVerNew::handleDpchAppDoButCreClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCreClick --- RBEGIN
	if (statshr.ButCreActive) {
		if (ixVSge == VecVSge::IDLE) {
			changeStage(dbswznm, VecVSge::CREATE, dpcheng);
		};

		if (ixVSge == VecVSge::DONE) {
			*dpcheng = new DpchEngWznmConfirm(true, jref, "");
			xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
		};
	};
	// IP handleDpchAppDoButCreClick --- REND
};

void DlgWznmVerNew::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVerNew::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	retval = VecVSge::getSref(ixVSge);
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVerNew::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVerNew::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVerNew::enterSgeCreate(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCreate --- IBEGIN

	WznmMVersion ver;

	WznmMVersion* bvr = NULL;

	WznmRMLocaleMVersion* lrv = NULL;

	ListWznmJMVersion verJs;
	WznmJMVersion* verJ = NULL;

	map<uint,uint> icsWznmVIop;
	uint ixWznmVIop;

	string xmlfile;

	time_t rawtime;
	time(&rawtime);

	ver.grp = xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref);
	ver.own = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);

	ver.prjRefWznmMProject = feedFDetPupPrj.getRefByNum(contiac.numFDetPupPrj);

	ver.prjNum = 1;
	if (dbswznm->loadUintBySQL("SELECT prjNum FROM TblWznmMVersion WHERE prjRefWznmMProject = " + to_string(ver.prjRefWznmMProject) + " ORDER BY prjNum DESC LIMIT 1", ver.prjNum)) ver.prjNum++;

	ver.bvrRefWznmMVersion = feedFDetPupBvr.getRefByNum(contiac.numFDetPupBvr);

	if (dbswznm->tblwznmmversion->loadRecByRef(ver.bvrRefWznmMVersion, &bvr)) {
		ver.Major = bvr->Major;
		ver.Minor = bvr->Minor;
		ver.Sub = bvr->Sub;

		ver.ixWDbmstype = bvr->ixWDbmstype;
		ver.ixWOption = bvr->ixWOption;

		delete bvr;
	};

	// ver.refRLocale = ;

	ver.refWznmMLocale = feedFDetPupPlc.getRefByNum(contiac.numFDetPupPlc);

	if (contiac.numFDetRbuVni == 1) {
		ver.Major++;
		ver.Minor = 0;
		ver.Sub = 0;
	} else if (contiac.numFDetRbuVni == 2) {
		ver.Minor++;
		ver.Sub = 0;
	} else if (contiac.numFDetRbuVni == 3) {
		ver.Sub++;
	};

	// ver.refJState =
	ver.ixVState = VecWznmVMVersionState::NEWCRE;

	// ver.refJ =
	// ver.About1 =
	// ver.About2 =
	// ver.About3 =

	dbswznm->tblwznmmversion->insertRec(&ver);

	// locales
	for (unsigned int i = 0; i < contiac.numsFDetLstLoc.size(); i++) {
		dbswznm->tblwznmrmlocalemversion->insertNewRec(&lrv, feedFDetLstLoc.getRefByNum(contiac.numsFDetLstLoc[i]), ver.ref);

		if (lrv->refWznmMLocale == ver.refWznmMLocale) ver.refRLocale = lrv->ref;

		delete lrv;
	};

	// state
	ver.refJState = dbswznm->tblwznmjmversionstate->insertNewRec(NULL, ver.ref, rawtime, ver.ixVState);

	// about text (localized)
	if (ver.bvrRefWznmMVersion != 0) {
		// copy from base version
		dbswznm->tblwznmjmversion->loadRstByVer(ver.bvrRefWznmMVersion, false, verJs);

		for (unsigned int i = 0; i < verJs.nodes.size(); i++) {
			verJ = verJs.nodes[i];

			verJ->ref = 0;
			verJ->refWznmMVersion = ver.ref;

			dbswznm->tblwznmjmversion->insertRec(verJ);
			if (verJ->x1RefWznmMLocale == ver.refWznmMLocale) {
				ver.refJ = verJ->ref;
				ver.About1 = verJ->About1;
				ver.About2 = verJ->About2;
				ver.About3 = verJ->About3;
			};
		};
	};

	dbswznm->tblwznmmversion->updateRec(&ver);

	// generate and archive project model file as source for WhizniumSBEBootstrap
	iexprj->reset(dbswznm);

	iexprj->imeimproject.nodes.push_back(new ImeitemIWznmPrjMProject(dbswznm, ver.prjRefWznmMProject));

	iexprj->imeimproject.nodes[0]->imeimversion.nodes.push_back(new ImeitemIWznmPrjMVersion(dbswznm, ver.ref));
	iexprj->imeimproject.nodes[0]->imeimversion.nodes[0]->ixVState = VecWznmVMVersionState::NEWIMP;

	icsWznmVIop = IexWznmPrj::icsWznmVIopInsAll();

	ixWznmVIop = VecVIexWznmPrjIme::IMEIMVERSION; icsWznmVIop.erase(ixWznmVIop);
	ixWznmVIop = VecVIexWznmPrjIme::IMEIJMVERSIONSTATE; icsWznmVIop.erase(ixWznmVIop);

	iexprj->collect(dbswznm, icsWznmVIop);

	xmlfile = Tmp::newfile(xchg->tmppath, "xml");
	iexprj->exportToFile(dbswznm, xchg->tmppath + "/" + xmlfile, true);

	Acv::addfile(dbswznm, xchg->acvpath, xchg->tmppath + "/" + xmlfile, xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref), xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVMFileRefTbl::VER, ver.ref, "mod", "IexWznmPrj_" + StrMod::lc(feedFDetPupPrj.getSrefByNum(contiac.numFDetPupPrj)) + ".xml", "xml", "");

	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMVERMOD, jref);
	xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, jref, VecWznmVPreset::PREWZNMREFVER, ver.ref);

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWznmVerNew::leaveSgeCreate(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCreate --- INSERT
};

uint DlgWznmVerNew::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmVerNew::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


