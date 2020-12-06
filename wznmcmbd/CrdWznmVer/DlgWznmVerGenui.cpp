/**
	* \file DlgWznmVerGenui.cpp
	* job handler for job DlgWznmVerGenui (implementation)
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

#include "DlgWznmVerGenui.h"

#include "DlgWznmVerGenui_blks.cpp"
#include "DlgWznmVerGenui_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVerGenui
 ******************************************************************************/

DlgWznmVerGenui::DlgWznmVerGenui(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVERGENUI, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::GUI;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVerGenui::~DlgWznmVerGenui() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmVerGenui::getNewDpchEng(
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

void DlgWznmVerGenui::refreshGui(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {

	// IP refreshGui --- BEGIN
	// IP refreshGui --- END
};

void DlgWznmVerGenui::refreshLfi(
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

void DlgWznmVerGenui::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);

	// IP refresh --- RBEGIN
	// continf
	continf.numFSge = ixVSge;
	continf.GuiTxtPrg = getSquawk(dbswznm);

	// statshr
	statshr.GuiButRunActive = evalGuiButRunActive(dbswznm);
	statshr.GuiButStoActive = evalGuiButStoActive(dbswznm);
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// IP refresh --- REND
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	refreshGui(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmVerGenui::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENUIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENUIDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::GUIBUTRUNCLICK) {
					handleDpchAppDoGuiButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::GUIBUTSTOCLICK) {
					handleDpchAppDoGuiButStoClick(dbswznm, &(req->dpcheng));
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
			} else if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMCTPGENUI) {
				handleDpchRetWznmCtpGenui(dbswznm, (DpchRetWznmCtpGenui*) (req->dpchret));
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

void DlgWznmVerGenui::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVerGenui::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::GUI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmVerGenui::handleDpchAppDoGuiButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoGuiButRunClick --- BEGIN
	if (statshr.GuiButRunActive) {
		changeStage(dbswznm, VecVSge::GENUI, dpcheng);
	};
	// IP handleDpchAppDoGuiButRunClick --- END
};

void DlgWznmVerGenui::handleDpchAppDoGuiButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoGuiButStoClick --- INSERT
};

void DlgWznmVerGenui::handleDpchAppDoButDneClick(
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

void DlgWznmVerGenui::handleDpchAppWznmAlert(
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

void DlgWznmVerGenui::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

void DlgWznmVerGenui::handleDpchRetWznmCtpGenui(
			DbsWznm* dbswznm
			, DpchRetWznmCtpGenui* dpchret
		) {
	// IP handleDpchRetWznmCtpGenui --- IBEGIN
	if (dpchret->logfile != "") {
		auto it = orefsToRefs.find(dpchret->oref);

		if (it != orefsToRefs.end()) {
			logfiles.push_back(dpchret->logfile);
			logheaders.push_back("### capability " + StubWznm::getStubCapStd(dbswznm, it->second) + " ###");
		};
	};
	// IP handleDpchRetWznmCtpGenui --- IEND
};

string DlgWznmVerGenui::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(""); // IP handleDownloadInSgeFail --- LINE
};

void DlgWznmVerGenui::changeStage(
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
				case VecVSge::GENUI: leaveSgeGenui(dbswznm); break;
				case VecVSge::GENCTP: leaveSgeGenctp(dbswznm); break;
				case VecVSge::ASMLFI: leaveSgeAsmlfi(dbswznm); break;
				case VecVSge::FAIL: leaveSgeFail(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRGER: _ixVSge = enterSgeAlrger(dbswznm, reenter); break;
			case VecVSge::GENUI: _ixVSge = enterSgeGenui(dbswznm, reenter); break;
			case VecVSge::GENCTP: _ixVSge = enterSgeGenctp(dbswznm, reenter); break;
			case VecVSge::ASMLFI: _ixVSge = enterSgeAsmlfi(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVerGenui::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::GENUI) || (ixVSge == VecVSge::GENCTP) || (ixVSge == VecVSge::ASMLFI) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::GENUI) retval = "generating detailed user interface";
			else if (ixVSge == VecVSge::GENCTP) retval = "generating template-based user interface (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::ASMLFI) retval = "assembling log file";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVerGenui::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVerGenui::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVerGenui::enterSgeAlrger(
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

void DlgWznmVerGenui::leaveSgeAlrger(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrger --- INSERT
};

uint DlgWznmVerGenui::enterSgeGenui(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::GENUI;
	nextIxVSgeSuccess = VecVSge::DONE;

	clearInvs();

	// IP enterSgeGenui --- IBEGIN
	// invoke WznmGenDetui
	string Prjshort;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	Prjshort = Wznm::getPrjshort(dbswznm, refWznmMVersion);

	addInv(new DpchInvWznmGenDetui(0, 0, refWznmMVersion, Prjshort));
	// IP enterSgeGenui --- IEND

	submitInvs(dbswznm, VecVSge::IDLE, retval);
	return retval;
};

void DlgWznmVerGenui::leaveSgeGenui(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeGenui --- INSERT
};

uint DlgWznmVerGenui::enterSgeGenctp(
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

	Prjshort = Wznm::getPrjshort(dbswznm, refWznmMVersion);

	orefsToRefs.clear();

	logfiles.clear();
	logheaders.clear();

	// determine capabilities due for op invocation
	Wznm::getSrefsCtpCustops(dbswznm, srefsCtpCustops, VecWznmVKeylist::KLSTKWZNMCTPGENUICUSTOP);

	dbswznm->tblwznmmcapability->loadRstBySQL("SELECT * FROM TblWznmMCapability WHERE refWznmMVersion = " + to_string(refWznmMVersion), false, cpbs);

	for (unsigned int i = 0; i < cpbs.nodes.size(); i++) {
		cpb = cpbs.nodes[i];

		auto it = srefsCtpCustops.find(cpb->tplRefWznmMCapability);

		if (it != srefsCtpCustops.end()) {
			dpchinv = new DpchInvWznmCtpGenui(0, it->second, 0, cpb->ref, Prjshort);
			addInv(dpchinv);
			orefsToRefs[dpchinv->oref] = cpb->ref;
		};
	};

	// IP enterSgeGenctp --- IEND

	submitInvs(dbswznm, VecVSge::DONE, retval);
	return retval;
};

void DlgWznmVerGenui::leaveSgeGenctp(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeGenctp --- INSERT
};

uint DlgWznmVerGenui::enterSgeAsmlfi(
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

void DlgWznmVerGenui::leaveSgeAsmlfi(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAsmlfi --- INSERT
};

uint DlgWznmVerGenui::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmVerGenui::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmVerGenui::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN
	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	Wznm::updateVerste(dbswznm, refWznmMVersion, VecWznmVMVersionState::DSNGENUI);
	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWznmVerGenui::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
