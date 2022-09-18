/**
	* \file DlgWznmUsrMngkeypair.cpp
	* job handler for job DlgWznmUsrMngkeypair (implementation)
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

#include "DlgWznmUsrMngkeypair.h"

#include "DlgWznmUsrMngkeypair_blks.cpp"
#include "DlgWznmUsrMngkeypair_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmUsrMngkeypair
 ******************************************************************************/

DlgWznmUsrMngkeypair::DlgWznmUsrMngkeypair(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMUSRMNGKEYPAIR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFUSR, jref)), usrsref);

	string s = xchg->stgwznmpath.keypath + "/id_wznm_" + usrsref;

	if (access(s.c_str(), R_OK) == 0) ixVSge = VecVSge::FOUND;
	else ixVSge = VecVSge::NF;
	// IP constructor.cust1 --- IEND

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmUsrMngkeypair::~DlgWznmUsrMngkeypair() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmUsrMngkeypair::getNewDpchEng(
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

void DlgWznmUsrMngkeypair::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContInf oldContinf(continf);

	// IP refresh --- RBEGIN
	// continf
	continf.numFSge = ixVSge;
	continf.DetTxtSte = getSquawk(dbswznm);
	continf.DetDld = "id_wznm_" + usrsref + ".pub";

	// statshr
	statshr.DetButDelAvail = evalDetButDelAvail(dbswznm);
	statshr.DetButGenAvail = evalDetButGenAvail(dbswznm);
	statshr.DetDldActive = evalDetDldActive(dbswznm);

	// IP refresh --- REND
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	muteRefresh = false;
};

void DlgWznmUsrMngkeypair::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUSRMNGKEYPAIRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::DETBUTDELCLICK) {
					handleDpchAppDoDetButDelClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::DETBUTGENCLICK) {
					handleDpchAppDoDetButGenClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FOUND) req->filename = handleDownloadInSgeFound(dbswznm);
	};
};

void DlgWznmUsrMngkeypair::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmUsrMngkeypair::handleDpchAppDoDetButDelClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoDetButDelClick --- IBEGIN
	string s;

	s = xchg->stgwznmpath.keypath + "/id_wznm_" + usrsref;
	if (access(s.c_str(), R_OK) == 0) Wznm::run("rm " + s);

	s = xchg->stgwznmpath.keypath + "/id_wznm_" + usrsref + ".pub";
	if (access(s.c_str(), R_OK) == 0) Wznm::run("rm " + s);

	changeStage(dbswznm, VecVSge::NF, dpcheng);
	// IP handleDpchAppDoDetButDelClick --- IEND
};

void DlgWznmUsrMngkeypair::handleDpchAppDoDetButGenClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoDetButGenClick --- IBEGIN
	string s = xchg->stgwznmpath.keypath + "/id_wznm_" + usrsref;

	char hostname[256];
	gethostname(hostname, 256);

	Wznm::run("ssh-keygen -t rsa -b 4096 -f " + s + " -C WhizniumSBE:" + usrsref + "@" + string(hostname) + " -N ''");

	if (access(s.c_str(), R_OK) == 0) changeStage(dbswznm, VecVSge::FOUND, dpcheng);
	// IP handleDpchAppDoDetButGenClick --- IEND
};

void DlgWznmUsrMngkeypair::handleDpchAppDoButDneClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	*dpcheng = new DpchEngWznmConfirm(true, jref, "");
	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
	// IP handleDpchAppDoButDneClick --- IEND
};

string DlgWznmUsrMngkeypair::handleDownloadInSgeFound(
			DbsWznm* dbswznm
		) {
	return(xchg->stgwznmpath.keypath + "/id_wznm_" + usrsref + ".pub"); // IP handleDownloadInSgeFound --- RLINE
};

void DlgWznmUsrMngkeypair::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::NF: leaveSgeNf(dbswznm); break;
				case VecVSge::FOUND: leaveSgeFound(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::NF: _ixVSge = enterSgeNf(dbswznm, reenter); break;
			case VecVSge::FOUND: _ixVSge = enterSgeFound(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmUsrMngkeypair::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::NF) || (ixVSge == VecVSge::FOUND) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::NF) retval = "SSH key pair not found";
			else if (ixVSge == VecVSge::FOUND) retval = "SSH key pair found";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmUsrMngkeypair::enterSgeNf(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::NF;

	// IP enterSgeNf --- INSERT

	return retval;
};

void DlgWznmUsrMngkeypair::leaveSgeNf(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeNf --- INSERT
};

uint DlgWznmUsrMngkeypair::enterSgeFound(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FOUND;

	// IP enterSgeFound --- INSERT

	return retval;
};

void DlgWznmUsrMngkeypair::leaveSgeFound(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFound --- INSERT
};
