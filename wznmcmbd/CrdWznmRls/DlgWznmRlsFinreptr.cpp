/**
	* \file DlgWznmRlsFinreptr.cpp
	* job handler for job DlgWznmRlsFinreptr (implementation)
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

#include "DlgWznmRlsFinreptr.h"

#include "DlgWznmRlsFinreptr_blks.cpp"
#include "DlgWznmRlsFinreptr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmRlsFinreptr
 ******************************************************************************/

DlgWznmRlsFinreptr::DlgWznmRlsFinreptr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMRLSFINREPTR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref)), usrsref);

	mGitprg = Mutex("mGitprg", "DlgWznmRlsFinreptr(" + to_string(jref) + ")", "DlgWznmRlsFinreptr");
	// IP constructor.cust1 --- IEND

	ixVDit = VecVDit::FIN;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmRlsFinreptr::~DlgWznmRlsFinreptr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
int DlgWznmRlsFinreptr::gitCredCallback(
			git_cred** cred
			, const char* url
			, const char* username_from_url
			, unsigned int allowed_types
			, void* payload
		) {
	DlgWznmRlsFinreptr* inst = (DlgWznmRlsFinreptr*) payload;

	int res;

	// SSH key naming convention: id_<usrsref>[.pub]
	string pubkey = inst->xchg->stgwznmpath.keypath + "/id_" + inst->usrsref + ".pub";
	string privkey = inst->xchg->stgwznmpath.keypath + "/id_" + inst->usrsref;

	res = git_cred_ssh_key_new(cred, "git", pubkey.c_str(), privkey.c_str(), "");
	if (res != 0) {
		cout << "error: SSH-based credentials can not be generated" << endl;

		return -1;
	};

	return 0;
};

int DlgWznmRlsFinreptr::gitIndexUpdateCallback(
			const char* path
			, const char* matched_pathspec
			, void* payload
		) {
	DlgWznmRlsFinreptr* inst = (DlgWznmRlsFinreptr*) payload;

	return 0;
};

int DlgWznmRlsFinreptr::gitIndexAddCallback(
			const char* path
			, const char* matched_pathspec
			, void* payload
		) {
	DlgWznmRlsFinreptr* inst = (DlgWznmRlsFinreptr*) payload;

	return 0;
};

int DlgWznmRlsFinreptr::gitPackCallback(
			int stage
			, unsigned int current
			, unsigned int total
			, void* payload
		) {
	DlgWznmRlsFinreptr* inst = (DlgWznmRlsFinreptr*) payload;

	inst->mGitprg.lock("DlgWznmRlsFinreptr", "gitPackCallback");
	inst->gitprg = " (pack: " + to_string(current) + "/" + to_string(total) + " steps completed)";
	inst->mGitprg.unlock("DlgWznmRlsFinreptr", "gitPackCallback");

	return 0;
};

int DlgWznmRlsFinreptr::gitPushCallback(
			unsigned int current
			, unsigned int total
			, size_t bytes
			, void *payload
		) {
	DlgWznmRlsFinreptr* inst = (DlgWznmRlsFinreptr*) payload;

	inst->mGitprg.lock("DlgWznmRlsFinreptr", "gitPushCallback");
	inst->gitprg = " (push: " + to_string(bytes/1024) + "kB sent)";
	inst->mGitprg.unlock("DlgWznmRlsFinreptr", "gitPushCallback");

	return 0;
};

// IP cust --- IEND

DpchEngWznm* DlgWznmRlsFinreptr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continffin, &continfres, &feedFDse, &feedFSge, &statshr, &statshrfin, &statshrres, items);
	};

	return dpcheng;
};

void DlgWznmRlsFinreptr::refreshFin(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrFin oldStatshrfin(statshrfin);
	ContInfFin oldContinffin(continffin);

	// IP refreshFin --- RBEGIN
	// continffin
	continffin.TxtPrg = getSquawk(dbswznm);

	// statshrfin
	statshrfin.ButRunActive = evalFinButRunActive(dbswznm);
	statshrfin.ButStoActive = evalFinButStoActive(dbswznm);

	// IP refreshFin --- REND
	if (statshrfin.diff(&oldStatshrfin).size() != 0) insert(moditems, DpchEngData::STATSHRFIN);
	if (continffin.diff(&oldContinffin).size() != 0) insert(moditems, DpchEngData::CONTINFFIN);
};

void DlgWznmRlsFinreptr::refreshRes(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfRes oldContinfres(continfres);
	StatShrRes oldStatshrres(statshrres);

	// IP refreshRes --- RBEGIN
	string Prjshort;
	Prjshort = Wznm::getPrjshort(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref));

	// statshrres
	statshrres.DldAvail = evalResDldAvail(dbswznm);
	statshrres.DldActive = evalResDldActive(dbswznm);
	statshrres.TxtPrgAvail = evalResTxtPrgAvail(dbswznm);
	statshrres.Sep1Avail = evalResSep1Avail(dbswznm);
	statshrres.ButPsgAvail = evalResButPsgAvail(dbswznm);
	statshrres.ButPsgActive = evalResButPsgActive(dbswznm);

	// continfres
	continfres.Dld = StrMod::lc(Prjshort) + ".tgz";
	continfres.TxtPrg = getSquawk(dbswznm);

	// IP refreshRes --- REND
	if (continfres.diff(&oldContinfres).size() != 0) insert(moditems, DpchEngData::CONTINFRES);
	if (statshrres.diff(&oldStatshrres).size() != 0) insert(moditems, DpchEngData::STATSHRRES);
};

void DlgWznmRlsFinreptr::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// contiac
	contiac.numFDse = ixVDit;

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshFin(dbswznm, moditems);
	refreshRes(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmRlsFinreptr::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoFin != 0) {
				if (dpchappdo->ixVDoFin == VecVDoFin::BUTRUNCLICK) {
					handleDpchAppDoFinButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoFin == VecVDoFin::BUTSTOCLICK) {
					handleDpchAppDoFinButStoClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoRes != 0) {
				if (dpchappdo->ixVDoRes == VecVDoRes::BUTPSGCLICK) {
					handleDpchAppDoResButPsgClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PSGIDLE) handleTimerInSgePsgidle(dbswznm, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::PUSHGIT)) handleTimerWithSrefMonInSgePushgit(dbswznm);
		else if (ixVSge == VecVSge::FINIDLE) handleTimerInSgeFinidle(dbswznm, req->sref);
	};
};

void DlgWznmRlsFinreptr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmRlsFinreptr::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::FIN) && (_contiac->numFDse <= VecVDit::RES)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmRlsFinreptr::handleDpchAppDoButDneClick(
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

void DlgWznmRlsFinreptr::handleDpchAppDoFinButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoFinButRunClick --- BEGIN
	if (statshrfin.ButRunActive) {
		changeStage(dbswznm, VecVSge::PACK, dpcheng);
	};
	// IP handleDpchAppDoFinButRunClick --- END
};

void DlgWznmRlsFinreptr::handleDpchAppDoFinButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoFinButStoClick --- INSERT
};

void DlgWznmRlsFinreptr::handleDpchAppDoResButPsgClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoResButPsgClick --- BEGIN
	if (statshrres.ButPsgAvail && statshrres.ButPsgActive) {
		changeStage(dbswznm, VecVSge::PSGIDLE, dpcheng);
	};
	// IP handleDpchAppDoResButPsgClick --- END
};

void DlgWznmRlsFinreptr::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if ((ixVSge == VecVSge::ALRGNF) || (ixVSge == VecVSge::ALRGAD)) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

string DlgWznmRlsFinreptr::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + tgzfile); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmRlsFinreptr::handleTimerInSgePsgidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmRlsFinreptr::handleTimerWithSrefMonInSgePushgit(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgePushgit --- ILINE
};

void DlgWznmRlsFinreptr::handleTimerInSgeFinidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmRlsFinreptr::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRGNF: leaveSgeAlrgnf(dbswznm); break;
				case VecVSge::ALRGAD: leaveSgeAlrgad(dbswznm); break;
				case VecVSge::FINIDLE: leaveSgeFinidle(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::COMMIT: leaveSgeCommit(dbswznm); break;
				case VecVSge::FINDONE: leaveSgeFindone(dbswznm); break;
				case VecVSge::PSGIDLE: leaveSgePsgidle(dbswznm); break;
				case VecVSge::PUSHGIT: leaveSgePushgit(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRGNF: _ixVSge = enterSgeAlrgnf(dbswznm, reenter); break;
			case VecVSge::ALRGAD: _ixVSge = enterSgeAlrgad(dbswznm, reenter); break;
			case VecVSge::FINIDLE: _ixVSge = enterSgeFinidle(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::COMMIT: _ixVSge = enterSgeCommit(dbswznm, reenter); break;
			case VecVSge::FINDONE: _ixVSge = enterSgeFindone(dbswznm, reenter); break;
			case VecVSge::PSGIDLE: _ixVSge = enterSgePsgidle(dbswznm, reenter); break;
			case VecVSge::PUSHGIT: _ixVSge = enterSgePushgit(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmRlsFinreptr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PACK) || (ixVSge == VecVSge::COMMIT) || (ixVSge == VecVSge::FINDONE) || (ixVSge == VecVSge::PUSHGIT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PACK) retval = "packing repository";
			else if (ixVSge == VecVSge::COMMIT) retval = "commiting to local Git repository";
			else if (ixVSge == VecVSge::FINDONE) retval = "repository transaction finalized";
			else if (ixVSge == VecVSge::PUSHGIT) {
				mGitprg.lock("DlgWznmRlsFinreptr", "getSquawk");
				retval = "pushing to Git repository at " + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMGITURL, jref) + gitprg;
				mGitprg.unlock("DlgWznmRlsFinreptr", "getSquawk");
			};
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWznmRlsFinreptr::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgeAlrgnf(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGNF;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrgnf --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Unable to locate Git repository at &giturl;.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrgnf --- END
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgeAlrgnf(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrgnf --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgeAlrgad(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGAD;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrgad --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Access to Git repository at &giturl; denied for user &usr;.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrgad --- END
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgeAlrgad(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrgad --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgeFinidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FINIDLE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeFinidle --- IBEGIN

	uint ixBasereptype = xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref);

	if ((ixBasereptype == VecWznmVBasereptype::VOID) || (ixBasereptype == VecWznmVBasereptype::ULD)) retval = VecVSge::PACK;
	else if ((ixBasereptype == VecWznmVBasereptype::PRJGIT) || (ixBasereptype == VecWznmVBasereptype::CUSTGIT)) retval = VecVSge::COMMIT;
	else retval = VecVSge::IDLE;

	// IP enterSgeFinidle --- IEND

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgeFinidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFinidle --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgePack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	tgzfile = Tmp::newfile(xchg->tmppath, "tgz");

	// .tgz result folder
	Wznm::tgz(xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref), xchg->tmppath + "/" + tgzfile);

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgeCommit(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::FINDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeCommit --- IBEGIN

	WznmMVersion* ver = NULL;

	WznmMUser* usr = NULL;

	int res;
	bool valid;

	const git_error* err;

	char hashbuf[GIT_OID_HEXSZ+1];
	memset(hashbuf, 0, GIT_OID_HEXSZ+1);

	git_repository* rep = NULL;

	git_index* index = NULL;
	git_tree* tree = NULL;
	git_signature* signature = NULL;
	git_commit* parent = NULL;
	git_object* obj = NULL;

	git_oid oid;

	string giturl;
	
	string repfolder;
	
	string vermsg;

	string author;

	char hostname[256];

	string email;

	time_t rawtime;
	time(&rawtime);

	git_libgit2_init();

	repfolder = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);

	// --- assemble commit information
	if (dbswznm->tblwznmmversion->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref), &ver)) {
		vermsg = StubWznm::getStubPrjStd(dbswznm, ver->prjRefWznmMProject) + " " + to_string(ver->Major) + "." + to_string(ver->Minor) + "." + to_string(ver->Sub) + " initial";
		vertag = "v" + to_string(ver->Major) + "." + to_string(ver->Minor) + "." + to_string(ver->Sub) + "i";

		delete ver;
	};

	if (dbswznm->tblwznmmuser->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), &usr)) {
		author = StubWznm::getStubPrsStd(dbswznm, usr->refWznmMPerson);

		gethostname(hostname, 256);
		email = "WhizniumDBE:" + usr->sref + "@" + string(hostname);

		delete usr;
	};

	// --- open repository
	res = git_repository_open(&rep, repfolder.c_str());
	valid = (res == 0);

	if (!valid) {
		cout << "error: repository not found" << endl;

		retval = nextIxVSgeFailure;
	};

	// --- update index
	if (valid) {
		git_repository_index(&index, rep);

		git_index_update_all(index, NULL, gitIndexUpdateCallback, this);
		git_index_add_all(index, NULL, GIT_INDEX_ADD_DISABLE_PATHSPEC_MATCH, gitIndexAddCallback, this);

		git_index_write(index);

		git_index_write_tree(&oid, index);
		git_tree_lookup(&tree, rep, &oid);

		if (index) {
			git_index_free(index);
			index = NULL;
		};
	};

	// --- commit changes
	if (valid) {
		// ex.: git commit -a -m "ICARUSDetectorHardware 0.1.2 initial"
		res = git_revparse_single(&obj, rep, "HEAD");
		valid = (res == 0);

		if (!valid) {
			cout << "error: HEAD commit not found" << endl;

			retval = nextIxVSgeFailure;
		};
	};

	if (valid) {
		git_commit_lookup(&parent, rep, git_object_id(obj));
		git_signature_new(&signature, author.c_str(), email.c_str(), rawtime, 0);

		res = git_commit_create_v(&oid, rep, "HEAD", signature, signature, NULL, vermsg.c_str(), tree, 1, parent);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_commit_create_v(): " << err->message << endl;
			
			retval = nextIxVSgeFailure;
		};
	};

	if (valid) git_oid_fmt(hashbuf, &oid);

	if (tree) {
		git_tree_free(tree);
		tree = NULL;
	};

	if (obj) {
		git_object_free(obj);
		obj = NULL;
	};

	if (parent) {
		git_commit_free(parent);
		parent = NULL;
	};

	// --- add tag
	// ex.: git tag -a v0.1.2i -m "ICARUSDetectorHardware 0.1.2 initial"

	if (valid) {
		git_object_lookup(&obj, rep, &oid, GIT_OBJ_COMMIT);

		res = git_tag_create(&oid, rep, vertag.c_str(), obj, signature, vermsg.c_str(), false);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_tag_create(): " << err->message << endl;

			retval = nextIxVSgeFailure;
		};
	};

	// --- clean up
	if (signature) {
		git_signature_free(signature);
		signature = NULL;
	};

	if (obj) {
		git_object_free(obj);
		obj = NULL;
	};

	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	git_libgit2_shutdown();

	// IP enterSgeCommit --- IEND

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgeCommit(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCommit --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgeFindone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FINDONE;

	// IP enterSgeFindone --- INSERT

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgeFindone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFindone --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgePsgidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PSGIDLE;
	nextIxVSgeSuccess = VecVSge::PUSHGIT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePsgidle --- INSERT

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgePsgidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePsgidle --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgePushgit(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgePushgit --- IBEGIN

	int res;
	bool valid;

	const git_error* err;

	git_repository* rep = NULL;
	git_remote* remote = NULL;

	string refVertag = "refs/tags/" + vertag;
	const char* ss[] = {"refs/heads/master", refVertag.c_str()};
	const git_strarray refs = {(char**) ss, 2};

	git_push_options pushopts = GIT_PUSH_OPTIONS_INIT;
	pushopts.callbacks.pack_progress = gitPackCallback;
	pushopts.callbacks.push_transfer_progress = gitPushCallback;
	pushopts.callbacks.credentials = gitCredCallback;
	pushopts.callbacks.payload = this;

	string repfolder;

	git_libgit2_init();

	gitprg = "";

	repfolder = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);

	// --- open repository
	res = git_repository_open(&rep, repfolder.c_str());
	valid = (res == 0);

	if (!valid) {
		cout << "error: repository not found" << endl;

		retval = nextIxVSgeFailure;
	};

	// --- look for remote location
	if (valid) {
		res = git_remote_lookup(&remote, rep, "origin");
		valid = (res == 0);

		if (!valid) {
			cout << "error: origin remote location not found" << endl;

			retval = VecVSge::ALRGNF;
		};
	};

	if (valid) {
		git_remote_connect(remote, GIT_DIRECTION_PUSH, NULL, NULL, NULL);

		res = git_remote_push(remote, &refs, &pushopts);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_remote_push(): " << err->message << endl;

			retval = VecVSge::ALRGAD;
		};
	};

	// --- clean up
	if (remote) {
		git_remote_disconnect(remote);
		git_remote_free(remote);
		remote = NULL;
	};

	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	git_libgit2_shutdown();

	// IP enterSgePushgit --- IEND

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgePushgit(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgePushgit --- INSERT
};

uint DlgWznmRlsFinreptr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN

	xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMREPTRSTOP, jref);

	// IP enterSgeDone --- IEND

	return retval;
};

void DlgWznmRlsFinreptr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};



