/**
	* \file DlgWznmVerGenjtr.cpp
	* job handler for job DlgWznmVerGenjtr (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmVerGenjtr.h"

#include "DlgWznmVerGenjtr_blks.cpp"
#include "DlgWznmVerGenjtr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVerGenjtr
 ******************************************************************************/

DlgWznmVerGenjtr::DlgWznmVerGenjtr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVERGENJTR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::GJT;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVerGenjtr::~DlgWznmVerGenjtr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmVerGenjtr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continflfi, &feedFDse, &feedFSge, &statshr, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWznmVerGenjtr::refreshGjt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {

	// IP refreshGjt --- BEGIN
	// IP refreshGjt --- END
};

void DlgWznmVerGenjtr::refreshLfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfLfi oldContinflfi(continflfi);
	StatShrLfi oldStatshrlfi(statshrlfi);

	// IP refreshLfi --- BEGIN
	// continflfi

	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswznm);

	// IP refreshLfi --- END
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgWznmVerGenjtr::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- RBEGIN
	// statshr
	statshr.GjtButRunActive = evalGjtButRunActive(dbswznm);
	statshr.GjtButStoActive = evalGjtButStoActive(dbswznm);
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// continf
	continf.numFSge = ixVSge;
	continf.GjtTxtPrg = getSquawk(dbswznm);

	// IP refresh --- REND
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshGjt(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);
};

void DlgWznmVerGenjtr::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENJTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENJTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::GJTBUTRUNCLICK) {
					handleDpchAppDoGjtButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::GJTBUTSTOCLICK) {
					handleDpchAppDoGjtButStoClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNM) {
				handleDpchRetWznm(dbswznm, (DpchRetWznm*) (req->dpchret));
			} else if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMCTPGENJTR) {
				handleDpchRetWznmCtpGenjtr(dbswznm, (DpchRetWznmCtpGenjtr*) (req->dpchret));
			};

			if (req->dpchret->ixOpVOpres == VecOpVOpres::SUCCESS) opNSuccess++;
			else if (req->dpchret->ixOpVOpres == VecOpVOpres::FAILURE) opNFailure++;

			if ((opNSuccess + opNFailure) == opN) {
				clearOps();

				opN = 0;
				opNSuccess = 0;

				if (opNFailure > 0) {
					opNFailure = 0;
					changeStage(dbswznm, nextIxVSgeFailure);
				} else changeStage(dbswznm, nextIxVSgeSuccess);
			};
		};
	};
};

void DlgWznmVerGenjtr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVerGenjtr::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::GJT) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmVerGenjtr::handleDpchAppDoGjtButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoGjtButRunClick --- BEGIN
	if (statshr.GjtButRunActive) {
		changeStage(dbswznm, VecVSge::GENQTB, dpcheng);
	};
	// IP handleDpchAppDoGjtButRunClick --- END
};

void DlgWznmVerGenjtr::handleDpchAppDoGjtButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoGjtButStoClick --- INSERT
};

void DlgWznmVerGenjtr::handleDpchAppDoButDneClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngWznmConfirm(true, jref, "");
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgWznmVerGenjtr::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRGER) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

void DlgWznmVerGenjtr::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

void DlgWznmVerGenjtr::handleDpchRetWznmCtpGenjtr(
			DbsWznm* dbswznm
			, DpchRetWznmCtpGenjtr* dpchret
		) {
	// IP handleDpchRetWznmCtpGenjtr --- IBEGIN
	if (dpchret->logfile != "") {
		auto it = orefsToRefs.find(dpchret->oref);

		if (it != orefsToRefs.end()) {
			logfiles.push_back(dpchret->logfile);
			logheaders.push_back("### capability " + StubWznm::getStubCapStd(dbswznm, it->second) + " ###");
		};
	};
	// IP handleDpchRetWznmCtpGenjtr --- IEND
};

string DlgWznmVerGenjtr::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWznmVerGenjtr::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRGER: leaveSgeAlrger(dbswznm); break;
				case VecVSge::GENQTB: leaveSgeGenqtb(dbswznm); break;
				case VecVSge::GENJOB: leaveSgeGenjob(dbswznm); break;
				case VecVSge::GENCALL: leaveSgeGencall(dbswznm); break;
				case VecVSge::GENCTP: leaveSgeGenctp(dbswznm); break;
				case VecVSge::ASMLFI: leaveSgeAsmlfi(dbswznm); break;
				case VecVSge::FAIL: leaveSgeFail(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRGER: _ixVSge = enterSgeAlrger(dbswznm, reenter); break;
			case VecVSge::GENQTB: _ixVSge = enterSgeGenqtb(dbswznm, reenter); break;
			case VecVSge::GENJOB: _ixVSge = enterSgeGenjob(dbswznm, reenter); break;
			case VecVSge::GENCALL: _ixVSge = enterSgeGencall(dbswznm, reenter); break;
			case VecVSge::GENCTP: _ixVSge = enterSgeGenctp(dbswznm, reenter); break;
			case VecVSge::ASMLFI: _ixVSge = enterSgeAsmlfi(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVerGenjtr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::GENQTB) || (ixVSge == VecVSge::GENJOB) || (ixVSge == VecVSge::GENCALL) || (ixVSge == VecVSge::GENCTP) || (ixVSge == VecVSge::ASMLFI) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::GENQTB) retval = "generating query tables";
			else if (ixVSge == VecVSge::GENJOB) retval = "generating job tree";
			else if (ixVSge == VecVSge::GENCALL) retval = "generating calls";
			else if (ixVSge == VecVSge::GENCTP) retval = "generating template-based job tree features (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::ASMLFI) retval = "assembling log file";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVerGenjtr::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVerGenjtr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeAlrger(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrger --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Generation error. View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	// IP enterSgeAlrger --- END
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmVerGenjtr::leaveSgeAlrger(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrger --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeGenqtb(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::GENQTB;
	nextIxVSgeSuccess = VecVSge::GENJOB;

	clearInvs();

	// IP enterSgeGenqtb --- IBEGIN

	// invoke WznmGenQtb and WznmGenChk
	string Prjshort;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = "
				+ to_string(refWznmMVersion), Prjshort);
	Prjshort = StrMod::cap(Prjshort);

	addInv(new DpchInvWznmGenQtb(0, 0, refWznmMVersion, Prjshort));
	addInv(new DpchInvWznmGenChk(0, 0, refWznmMVersion, Prjshort));

	// IP enterSgeGenqtb --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmVerGenjtr::leaveSgeGenqtb(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeGenqtb --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeGenjob(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::GENJOB;
	nextIxVSgeSuccess = VecVSge::GENCALL;

	clearInvs();

	// IP enterSgeGenjob --- IBEGIN
	// invoke WznmGenJob
	string Prjshort;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = "
				+ to_string(refWznmMVersion), Prjshort);
	Prjshort = StrMod::cap(Prjshort);

	addInv(new DpchInvWznmGenJob(0, 0, refWznmMVersion, Prjshort));
	// IP enterSgeGenjob --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmVerGenjtr::leaveSgeGenjob(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeGenjob --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeGencall(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::GENCALL;
	nextIxVSgeSuccess = VecVSge::GENCTP;

	clearInvs();

	// IP enterSgeGencall --- IBEGIN
	// invoke WznmGenCal
	string Prjshort;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = "
				+ to_string(refWznmMVersion), Prjshort);
	Prjshort = StrMod::cap(Prjshort);

	addInv(new DpchInvWznmGenCal(0, 0, refWznmMVersion, Prjshort));
	// IP enterSgeGencall --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmVerGenjtr::leaveSgeGencall(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeGencall --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeGenctp(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::GENCTP;
	nextIxVSgeSuccess = VecVSge::DONE;
	nextIxVSgeFailure = VecVSge::ASMLFI;

	clearInvs();

	// IP enterSgeGenctp --- IBEGIN

	ListWznmMCapability cpbs;
	WznmMCapability* cpb = NULL;

	DpchInvWznm* dpchinv = NULL;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	string Prjshort;

	map<ubigint,string> srefsCtpCustops;

	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(refWznmMVersion), Prjshort);
	Prjshort = StrMod::cap(Prjshort);

	orefsToRefs.clear();

	logfiles.clear();
	logheaders.clear();

	// determine capabilities due for op invocation
	Wznm::getSrefsCtpCustops(dbswznm, srefsCtpCustops, VecWznmVKeylist::KLSTKWZNMCTPGENJTRCUSTOP);

	dbswznm->tblwznmmcapability->loadRstBySQL("SELECT * FROM TblWznmMCapability WHERE refWznmMVersion = " + to_string(refWznmMVersion), false, cpbs);

	for (unsigned int i = 0; i < cpbs.nodes.size(); i++) {
		cpb = cpbs.nodes[i];

		auto it = srefsCtpCustops.find(cpb->tplRefWznmMCapability);

		if (it != srefsCtpCustops.end()) {
			dpchinv = new DpchInvWznmCtpGenjtr(0, it->second, 0, cpb->ref, Prjshort);
			addInv(dpchinv);
			orefsToRefs[dpchinv->oref] = cpb->ref;
		};
	};

	// IP enterSgeGenctp --- IEND

	submitInvs(dbswznm, VecVSge::DONE, retval);
	return retval;
};

void DlgWznmVerGenjtr::leaveSgeGenctp(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeGenctp --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeAsmlfi(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ASMLFI;
	nextIxVSgeSuccess = VecVSge::ALRGER;

	clearInvs();

	// IP enterSgeAsmlfi --- IBEGIN
	logfile = Tmp::newfile(xchg->tmppath, "txt");

	addInv(new DpchInvWznmPrcfileConcat(0, 0, logfiles, logheaders, logfile));
	// IP enterSgeAsmlfi --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmVerGenjtr::leaveSgeAsmlfi(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAsmlfi --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmVerGenjtr::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmVerGenjtr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN
	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	Wznm::updateVerste(dbswznm, refWznmMVersion, VecWznmVMVersionState::DSNGENJTR);
	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWznmVerGenjtr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


