/**
	* \file DlgWznmVerFinmod.cpp
	* job handler for job DlgWznmVerFinmod (implementation)
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

#include "DlgWznmVerFinmod.h"

#include "DlgWznmVerFinmod_blks.cpp"
#include "DlgWznmVerFinmod_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVerFinmod
 ******************************************************************************/

DlgWznmVerFinmod::DlgWznmVerFinmod(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVERFINMOD, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	license = NULL;

	// IP constructor.cust1 --- INSERT

	license = new JobWznmLicense(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVerFinmod::~DlgWznmVerFinmod() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmVerFinmod::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &feedFSge, &statshr, items);
	};

	return dpcheng;
};

void DlgWznmVerFinmod::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	// statshr
	statshr.FnmButRunActive = evalFnmButRunActive(dbswznm);
	statshr.FnmButStoActive = evalFnmButStoActive(dbswznm);
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// continf
	continf.numFSge = ixVSge;
	continf.FnmTxtPrg = getSquawk(dbswznm);

	// IP refresh --- REND
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void DlgWznmVerFinmod::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERFINMODDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::FNMBUTRUNCLICK) {
					handleDpchAppDoFnmButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::FNMBUTSTOCLICK) {
					handleDpchAppDoFnmButStoClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNM) {
				handleDpchRetWznm(dbswznm, (DpchRetWznm*) (req->dpchret));
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

void DlgWznmVerFinmod::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVerFinmod::handleDpchAppDoFnmButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoFnmButRunClick --- BEGIN
	if (statshr.FnmButRunActive) {
		changeStage(dbswznm, VecVSge::FINMOD, dpcheng);
	};
	// IP handleDpchAppDoFnmButRunClick --- END
};

void DlgWznmVerFinmod::handleDpchAppDoFnmButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoFnmButStoClick --- INSERT
};

void DlgWznmVerFinmod::handleDpchAppDoButDneClick(
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

void DlgWznmVerFinmod::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

void DlgWznmVerFinmod::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::FINMOD: leaveSgeFinmod(dbswznm); break;
				case VecVSge::SYNC: leaveSgeSync(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::FINMOD: _ixVSge = enterSgeFinmod(dbswznm, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVerFinmod::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::FINMOD) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::FINMOD) retval = "finalizing model";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing build-ready version with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVerFinmod::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVerFinmod::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVerFinmod::enterSgeFinmod(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FINMOD;
	nextIxVSgeSuccess = VecVSge::SYNC;

	clearInvs();

	// IP enterSgeFinmod --- IBEGIN

	// invoke WznmComplJtr and WznmGenSysvec
	string Prjshort;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	Prjshort = Wznm::getPrjshort(dbswznm, refWznmMVersion);

	addInv(new DpchInvWznmComplJtr(0, 0, refWznmMVersion, Prjshort));
	addInv(new DpchInvWznmGenSysvec(0, 0, refWznmMVersion, Prjshort));

	// IP enterSgeFinmod --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmVerFinmod::leaveSgeFinmod(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFinmod --- IBEGIN
	WznmMVersion* ver = NULL;

	if (dbswznm->tblwznmmversion->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref), &ver)) {
		Wznm::updateVerste(dbswznm, ver->ref, VecWznmVMVersionState::READY);

		// make project's current version
		dbswznm->executeQuery("UPDATE TblWznmMProject SET refWznmMVersion = " + to_string(ver->ref) + " WHERE ref = " + to_string(ver->prjRefWznmMProject));

		delete ver;
	};
	// IP leaveSgeFinmod --- IEND
};

uint DlgWznmVerFinmod::enterSgeSync(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSync --- IBEGIN
	WznmMVersion* ver = NULL;

	if (dbswznm->tblwznmmversion->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref), &ver)) {
		license->syncVer(dbswznm, ver->prjRefWznmMProject, ver->ref);
		delete ver;
	};
	// IP enterSgeSync --- IEND

	return retval;
};

void DlgWznmVerFinmod::leaveSgeSync(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSync --- INSERT
};

uint DlgWznmVerFinmod::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmVerFinmod::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
