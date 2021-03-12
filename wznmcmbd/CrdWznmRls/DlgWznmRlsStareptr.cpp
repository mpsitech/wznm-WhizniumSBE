/**
	* \file DlgWznmRlsStareptr.cpp
	* job handler for job DlgWznmRlsStareptr (implementation)
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

#include "DlgWznmRlsStareptr.h"

#include "DlgWznmRlsStareptr_blks.cpp"
#include "DlgWznmRlsStareptr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmRlsStareptr
 ******************************************************************************/

DlgWznmRlsStareptr::DlgWznmRlsStareptr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMRLSSTAREPTR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDetRbuBrt.tag = "FeedFDetRbuBrt";
	VecWznmVBasereptype::fillFeed(ixWznmVLocale, feedFDetRbuBrt);
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- IBEGIN
	dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref)), usrsref);

	mGitprg = Mutex("mGitprg", "DlgWznmRlsStareptr(" + to_string(jref) + ")", "DlgWznmRlsStareptr");
	// IP constructor.cust1 --- IEND

	ixVDit = VecVDit::DET;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmRlsStareptr::~DlgWznmRlsStareptr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
int DlgWznmRlsStareptr::gitCredCallback(
			git_cred** cred
			, const char* url
			, const char* username_from_url
			, unsigned int allowed_types
			, void* payload
		) {
	DlgWznmRlsStareptr* inst = (DlgWznmRlsStareptr*) payload;

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

int DlgWznmRlsStareptr::gitFetchCallback(
			const git_transfer_progress* _stats
			, void* payload
		) {
	DlgWznmRlsStareptr* inst = (DlgWznmRlsStareptr*) payload;

	inst->mGitprg.lock("DlgWznmRlsStareptr", "gitFetchCallback");
	inst->gitprg = " (fetch: " + to_string(_stats->received_bytes/1024) + "kB received)";
	inst->mGitprg.unlock("DlgWznmRlsStareptr", "gitFetchCallback");

	return 0;
};

void DlgWznmRlsStareptr::gitCheckoutCallback(
			const char* path
			, size_t _cur
			, size_t _tot
			, void* payload
		) {
	DlgWznmRlsStareptr* inst = (DlgWznmRlsStareptr*) payload;

	inst->mGitprg.lock("DlgWznmRlsStareptr", "gitCheckoutCallback");
	inst->gitprg = " (checkout: " + to_string(_cur) + "/" + to_string(_tot) + " steps completed)";
	inst->mGitprg.unlock("DlgWznmRlsStareptr", "gitCheckoutCallback");
};

// IP cust --- IEND

DpchEngWznm* DlgWznmRlsStareptr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continfext, &continfini, &continflfi, &feedFDetRbuBrt, &feedFDse, &feedFSge, &statshr, &statshrdet, &statshrext, &statshrini, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWznmRlsStareptr::refreshDet(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrDet oldStatshrdet(statshrdet);
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- RBEGIN
	// contiacdet

	// statshrdet
	statshrdet.TxfGrlAvail = (feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt) == VecWznmVBasereptype::CUSTGIT);
	statshrdet.ButStaActive = evalDetButStaActive(dbswznm);

	// IP refreshDet --- REND
	if (statshrdet.diff(&oldStatshrdet).size() != 0) insert(moditems, DpchEngData::STATSHRDET);
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgWznmRlsStareptr::refreshIni(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfIni oldContinfini(continfini);
	StatShrIni oldStatshrini(statshrini);

	// IP refreshIni --- RBEGIN
	// statshrini
	statshrini.UldAvail = evalIniUldAvail(dbswznm);
	statshrini.UldActive = evalIniUldActive(dbswznm);
	statshrini.TxtPrgAvail = evalIniTxtPrgAvail(dbswznm);
	statshrini.Sep1Avail = evalIniSep1Avail(dbswznm);
	statshrini.ButClgAvail = evalIniButClgAvail(dbswznm);
	statshrini.ButClgActive = evalIniButClgActive(dbswznm);

	// continfini
	continfini.TxtPrg = getSquawk(dbswznm);

	// IP refreshIni --- REND
	if (continfini.diff(&oldContinfini).size() != 0) insert(moditems, DpchEngData::CONTINFINI);
	if (statshrini.diff(&oldStatshrini).size() != 0) insert(moditems, DpchEngData::STATSHRINI);
};

void DlgWznmRlsStareptr::refreshExt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrExt oldStatshrext(statshrext);
	ContInfExt oldContinfext(continfext);

	// IP refreshExt --- RBEGIN
	// continfext
	continfext.TxtPrg = getSquawk(dbswznm);

	// statshrext
	statshrext.ButRunActive = evalExtButRunActive(dbswznm);
	statshrext.ButStoActive = evalExtButStoActive(dbswznm);

	// IP refreshExt --- REND
	if (statshrext.diff(&oldStatshrext).size() != 0) insert(moditems, DpchEngData::STATSHREXT);
	if (continfext.diff(&oldContinfext).size() != 0) insert(moditems, DpchEngData::CONTINFEXT);
};

void DlgWznmRlsStareptr::refreshLfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);
	ContInfLfi oldContinflfi(continflfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswznm);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
};

void DlgWznmRlsStareptr::refresh(
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

	refreshDet(dbswznm, moditems);
	refreshIni(dbswznm, moditems);
	refreshExt(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmRlsStareptr::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbswznm, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoDet != 0) {
				if (dpchappdo->ixVDoDet == VecVDoDet::BUTSTACLICK) {
					handleDpchAppDoDetButStaClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoExt != 0) {
				if (dpchappdo->ixVDoExt == VecVDoExt::BUTRUNCLICK) {
					handleDpchAppDoExtButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoExt == VecVDoExt::BUTSTOCLICK) {
					handleDpchAppDoExtButStoClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoIni != 0) {
				if (dpchappdo->ixVDoIni == VecVDoIni::BUTCLGCLICK) {
					handleDpchAppDoIniButClgClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::STADONE) handleUploadInSgeStadone(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);
		else if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMPRCTREEEXTRACT) {
				handleDpchRetWznmPrctreeExtract(dbswznm, (DpchRetWznmPrctreeExtract*) (req->dpchret));
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

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswznm, req->sref);
		else if (ixVSge == VecVSge::CLGIDLE) handleTimerInSgeClgidle(dbswznm, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::CLONEGIT)) handleTimerWithSrefMonInSgeClonegit(dbswznm);
	};
};

void DlgWznmRlsStareptr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmRlsStareptr::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmRlsStareptr::handleDpchAppDataContiacdet(
			DbsWznm* dbswznm
			, ContIacDet* _contiacdet
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	if (has(diffitems, ContIacDet::NUMFRBUBRT)) {
		if ((_contiacdet->numFRbuBrt >= VecWznmVBasereptype::VOID) && (_contiacdet->numFRbuBrt <= VecWznmVBasereptype::ULD)) contiacdet.numFRbuBrt = _contiacdet->numFRbuBrt;
		else contiacdet.numFRbuBrt = VecWznmVBasereptype::VOID;
	};

	if (has(diffitems, ContIacDet::TXFGRL)) contiacdet.TxfGrl = _contiacdet->TxfGrl;

	refresh(dbswznm, moditems);

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmRlsStareptr::handleDpchAppDoButDneClick(
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

void DlgWznmRlsStareptr::handleDpchAppDoDetButStaClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoDetButStaClick --- IBEGIN

	WznmMProject* prj = NULL;

	string giturl;

	if (feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt) == VecWznmVBasereptype::PRJGIT) {
		if (dbswznm->tblwznmmproject->loadRecBySQL("SELECT TblWznmMProject.* FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = "
					+ to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)), &prj)) {

			giturl = prj->Giturl;
			delete prj;
		};

	} else if (feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt) == VecWznmVBasereptype::CUSTGIT) giturl = contiacdet.TxfGrl;

	xchg->triggerIxTxtvalCall(dbswznm, VecWznmVCall::CALLWZNMREPTRSTART, jref, feedFDetRbuBrt.getIxByNum(contiacdet.numFRbuBrt), giturl);

	changeStage(dbswznm, VecVSge::STADONE, dpcheng);

	// IP handleDpchAppDoDetButStaClick --- IEND
};

void DlgWznmRlsStareptr::handleDpchAppDoExtButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoExtButRunClick --- BEGIN
	if (statshrext.ButRunActive) {
		changeStage(dbswznm, VecVSge::EXTRACT, dpcheng);
	};
	// IP handleDpchAppDoExtButRunClick --- END
};

void DlgWznmRlsStareptr::handleDpchAppDoExtButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoExtButStoClick --- INSERT
};

void DlgWznmRlsStareptr::handleDpchAppDoIniButClgClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoIniButClgClick --- BEGIN
	if (statshrini.ButClgAvail && statshrini.ButClgActive) {
		changeStage(dbswznm, VecVSge::CLGIDLE, dpcheng);
	};
	// IP handleDpchAppDoIniButClgClick --- END
};

void DlgWznmRlsStareptr::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if ((ixVSge == VecVSge::ALRGNF) || (ixVSge == VecVSge::ALRGAD) || (ixVSge == VecVSge::ALRGVE) || (ixVSge == VecVSge::ALRXER)) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

void DlgWznmRlsStareptr::handleDpchRetWznmPrctreeExtract(
			DbsWznm* dbswznm
			, DpchRetWznmPrctreeExtract* dpchret
		) {
	logfile = dpchret->logfile; // IP handleDpchRetWznmPrctreeExtract --- ILINE
};

void DlgWznmRlsStareptr::handleUploadInSgeStadone(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeStadone --- ILINE
	changeStage(dbswznm, VecVSge::UPKIDLE);
};

string DlgWznmRlsStareptr::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(""); // IP handleDownloadInSgeDone --- LINE
};

string DlgWznmRlsStareptr::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWznmRlsStareptr::handleTimerInSgeUpkidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmRlsStareptr::handleTimerInSgeClgidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmRlsStareptr::handleTimerWithSrefMonInSgeClonegit(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeClonegit --- ILINE
};

void DlgWznmRlsStareptr::changeStage(
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
				case VecVSge::ALRGVE: leaveSgeAlrgve(dbswznm); break;
				case VecVSge::ALRXER: leaveSgeAlrxer(dbswznm); break;
				case VecVSge::STADONE: leaveSgeStadone(dbswznm); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswznm); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswznm); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswznm); break;
				case VecVSge::CLGIDLE: leaveSgeClgidle(dbswznm); break;
				case VecVSge::CLONEGIT: leaveSgeClonegit(dbswznm); break;
				case VecVSge::CLGDONE: leaveSgeClgdone(dbswznm); break;
				case VecVSge::EXTRACT: leaveSgeExtract(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::FAIL: leaveSgeFail(dbswznm); break;
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
			case VecVSge::ALRGVE: _ixVSge = enterSgeAlrgve(dbswznm, reenter); break;
			case VecVSge::ALRXER: _ixVSge = enterSgeAlrxer(dbswznm, reenter); break;
			case VecVSge::STADONE: _ixVSge = enterSgeStadone(dbswznm, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswznm, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswznm, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswznm, reenter); break;
			case VecVSge::CLGIDLE: _ixVSge = enterSgeClgidle(dbswznm, reenter); break;
			case VecVSge::CLONEGIT: _ixVSge = enterSgeClonegit(dbswznm, reenter); break;
			case VecVSge::CLGDONE: _ixVSge = enterSgeClgdone(dbswznm, reenter); break;
			case VecVSge::EXTRACT: _ixVSge = enterSgeExtract(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmRlsStareptr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::STADONE) || (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::CLONEGIT) || (ixVSge == VecVSge::CLGDONE) || (ixVSge == VecVSge::EXTRACT) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::STADONE) retval = "repository transaction started";
			else if (ixVSge == VecVSge::UNPACK) retval = "unpacking base repository";
			else if (ixVSge == VecVSge::UPKDONE) retval = "base repository unpacked";
			else if (ixVSge == VecVSge::CLONEGIT) {
				mGitprg.lock("DlgWznmRlsStareptr", "getSquawk");
				retval = "cloning Git repository at " + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMGITURL, jref) + gitprg;
				mGitprg.unlock("DlgWznmRlsStareptr", "getSquawk");
			} else if (ixVSge == VecVSge::CLGDONE) retval = "Git repository cloned";
			else if (ixVSge == VecVSge::EXTRACT) retval = "extracting insertion points";
			else if (ixVSge == VecVSge::PACK) retval = "packing result";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWznmRlsStareptr::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeAlrgnf(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGNF;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrgnf --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Unable to locate Git repository at " + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMGITURL, jref) + ".";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrgnf --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeAlrgnf(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrgnf --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeAlrgad(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGAD;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrgad --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Access to Git repository at " + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMGITURL, jref) + " denied for user " + usrsref + ".";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrgad --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeAlrgad(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrgad --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeAlrgve(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRGVE;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrgve --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Version error for Git repository at " + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMGITURL, jref) + ".";
		continf.TxtMsg2 = "Tag of latest commit is " + acttag + " and not " + exptag + " as expected.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
	// IP enterSgeAlrgve --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeAlrgve(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrgve --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeAlrxer(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRXER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrxer --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Extraction error. View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrxer --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeAlrxer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrxer --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeStadone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::STADONE;

	// IP enterSgeStadone --- IBEGIN

	if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::VOID) retval = VecVSge::DONE;

	// IP enterSgeStadone --- IEND

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeStadone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeStadone --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeUpkidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeUpkidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeUnpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN

	// assume .tgz input file archive
	Wznm::run("mv " + infilename + " " + infilename + ".tgz");

	Wznm::untgz(infilename + ".tgz", xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref));

	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeUnpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeUpkdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeUpkdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeClgidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLGIDLE;
	nextIxVSgeSuccess = VecVSge::CLONEGIT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeClgidle --- INSERT

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeClgidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeClgidle --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeClonegit(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLGDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeClonegit --- IBEGIN

	ubigint ref;

	WznmMVersion* bvr = NULL;

	int res;
	bool valid;

	const git_error* err;

	char hashbuf[GIT_OID_HEXSZ+1];
	memset(hashbuf, 0, GIT_OID_HEXSZ+1);

	git_repository* rep = NULL;
	git_remote* remote = NULL;

	git_remote_callbacks cbs = GIT_REMOTE_CALLBACKS_INIT;

	const git_remote_head** ls = NULL;
	const git_remote_head* lsitem;

	git_clone_options cloneopts = GIT_CLONE_OPTIONS_INIT;
	git_checkout_options checkoutopts = GIT_CHECKOUT_OPTIONS_INIT;

	string giturl;

	string testfolder;
	string repfolder;

	string headtag;
	string bvritag;
	string bvrftag;

	string hash;

	string headhash;
	string bvrihash;
	string bvrfhash;

	string s, s2;

	size_t size;

	git_libgit2_init();

	giturl = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMGITURL, jref);

	gitprg = "";

	testfolder = xchg->tmppath + "/" + Tmp::newfolder(xchg->tmppath);
	repfolder = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);

	// --- assemble allowed tags for base version
	dbswznm->loadRefBySQL("SELECT bvrRefWznmMVersion FROM TblWznmMVersion WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)), ref);

	if (dbswznm->tblwznmmversion->loadRecByRef(ref, &bvr)) {
		bvritag = "v" + to_string(bvr->Major) + "." + to_string(bvr->Minor) + "." + to_string(bvr->Sub) + "i";
		bvrftag = "v" + to_string(bvr->Major) + "." + to_string(bvr->Minor) + "." + to_string(bvr->Sub) + "f";

		delete bvr;
	};

	// --- validate remote connectivity and tag of latest commit

	// -- connect to remote
	res = git_repository_init(&rep, testfolder.c_str(), false);
	valid = (res == 0);

	if (!valid) {
		err = giterr_last();
		cout << "error on git_repository_init(): " << err->message << endl;

		retval = VecVSge::IDLE;
	};

	if (valid) {
		git_remote_set_url(rep, "origin", giturl.c_str());

		res = git_remote_lookup(&remote, rep, "origin"); // actually, only the parser correctness is checked here!
		valid = (res == 0);

		if (!valid) {
			cout << "error: origin remote location not found" << endl;

			retval = VecVSge::ALRGNF;
		};
	};

	if (valid) {
		cbs.credentials = gitCredCallback;
		cbs.payload = this;

		res = git_remote_connect(remote, GIT_DIRECTION_FETCH, &cbs, NULL, NULL);
		valid = (res == 0);

		if (!valid) {
			// differentiate result - ex.:
			// Failed to connect to 192.168.0.10: Connection refused -> ALRGAD
			// fatal: 'idhx.git' does not appear to be a git repository -> ALRGNF

			err = giterr_last();
			cout << "error on git_remote_connect(): " << err->message << endl;

			retval = VecVSge::ALRGAD;
		};
	};

	// -- fetch remote listing
	if (valid) {
		res = git_remote_ls(&ls, &size, remote);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_remote_ls(): " << err->message << endl;

			retval = VecVSge::IDLE;
		};
	};

	// -- look for relevant oid's
	if (valid) {
		s = "refs/tags/" + bvritag + "^{}";
		s2 = "refs/tags/" + bvrftag + "^{}";
		for (size_t i = 0; i < size; i++) {
			lsitem = ls[i];

			git_oid_fmt(hashbuf, &(lsitem->oid));
			hash = hashbuf;

			if ((headhash != "") && (hash == headhash)) {
				headtag = lsitem->name;
				if (headtag.find("refs/tags/") == 0) headtag = headtag.substr(10);
				if ((headtag.rfind("^{}")+3) == headtag.length()) headtag = headtag.substr(0, headtag.length()-3);
			};

			if (strcmp(lsitem->name, "HEAD") == 0) {
				headhash = hash;
			} else if (strcmp(lsitem->name, s.c_str()) == 0) {
				bvrihash = hash;
			} else if (strcmp(lsitem->name, s2.c_str()) == 0) {
				bvrfhash = hash;
			};
		};

		if (headhash == "") {
			valid = false;
			cout << "error: HEAD commit not listed" << endl;
			retval = VecVSge::IDLE;

		} else if (bvrfhash != "") {
			if (headhash != bvrfhash) {
				valid = false;
				cout << "error: HEAD commit does not equal base version commit " << bvrftag << endl;

				acttag = headtag;
				exptag = bvrftag;

				retval = VecVSge::ALRGVE;
			};

		} else if (bvrihash != "") {
			if (headhash != bvrihash) {
				valid = false;
				cout << "error: HEAD commit does not equal base version commit " << bvritag << endl;

				acttag = headtag;
				exptag = bvritag;

				retval = VecVSge::ALRGVE;
			};

		} else {
			valid = false;
			cout << "error: base version commit not listed" << endl;
			retval = VecVSge::IDLE;
		};
	};

	// -- clean up
	if (remote) {
		git_remote_disconnect(remote);
		git_remote_free(remote);
		remote = NULL;
	};

	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	// --- clone from remote repository using SSH
	// ex.: git clone git@github.com/mpsitech/idhw /Users/epsi/.../xyza1234
	// not possible with libgit2 : git clone --depth 1 git@github.com/mpsitech/idhw /Users/epsi/.../xyza1234

	if (valid) {
		checkoutopts.checkout_strategy = GIT_CHECKOUT_SAFE;
		checkoutopts.progress_cb = gitCheckoutCallback;
		checkoutopts.progress_payload = this;

		cloneopts.checkout_opts = checkoutopts;
		cloneopts.fetch_opts.callbacks.transfer_progress = &gitFetchCallback;
		cloneopts.fetch_opts.callbacks.credentials = gitCredCallback;
		cloneopts.fetch_opts.callbacks.payload = this;

		res = git_clone(&rep, giturl.c_str(), repfolder.c_str(), &cloneopts);
		valid = (res == 0);

		if (!valid) {
			err = giterr_last();
			cout << "error on git_clone(): " << err->message << endl;

			retval = VecVSge::IDLE;
		};
	};

	// -- clean up
	if (rep) {
		git_repository_free(rep);
		rep = NULL;
	};

	git_libgit2_shutdown();

	// IP enterSgeClonegit --- IEND

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeClonegit(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeClonegit --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeClgdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLGDONE;

	// IP enterSgeClgdone --- INSERT

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeClgdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeClgdone --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeExtract(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::EXTRACT;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRXER;

	clearInvs();

	// IP enterSgeExtract --- IBEGIN

	// invoke WznmPrctreeExtract
	addInv(new DpchInvWznmPrctreeExtract(0, 0, "", xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref), "", xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref)));

	// IP enterSgeExtract --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmRlsStareptr::leaveSgeExtract(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExtract --- IBEGIN

	ubigint refWznmMVersion;

	string Prjshort, prjshort;

	ListWznmMComponent cmps;
	WznmMComponent* cmp = NULL;

	string inpath;
	string outpath;

	string s;

	// MISSING: root folder KEEP files and KEEP sub-folders

	// copy IP's from xxxxcmbd/Xxxxcmbd_exe.cpp, xxxxcmbd/Xxxxcmbd.h and xxxxcmbd/Xxxxcmbd.cpp for xxxxd and xxxxopd's
	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	// find project short
	Prjshort = Wznm::getPrjshort(dbswznm, refWznmMVersion);

	prjshort = StrMod::lc(Prjshort);

	inpath = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref) + "/" + prjshort + "cmbd";

	if (!access(inpath.c_str(), R_OK)) {
		dbswznm->tblwznmmcomponent->loadRstByVer(refWznmMVersion, false, cmps);

		for (unsigned int i = 0; i < cmps.nodes.size(); i++) {
			cmp = cmps.nodes[i];

			if ((cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) || (cmp->ixVBasetype == VecWznmVMComponentBasetype::OPENG)) {
				outpath = xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref) + "/" + StrMod::lc(cmp->sref);
				if (cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) s = Prjshort + "d";
				else s = Prjshort + "opd";

#ifdef _WIN32
				if (access(outpath.c_str(), W_OK) == -1) mkdir(outpath.c_str());
#else
				if (access(outpath.c_str(), W_OK) == -1) mkdir(outpath.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

				Wznm::run("cp " + inpath + "/" + Prjshort + "cmbd_exe.cpp.ip " + outpath + "/" + s + "_exe.cpp.ip");
				Wznm::run("cp " + inpath + "/" + Prjshort + "cmbd.h.ip " + outpath + "/" + s + ".h.ip");
				Wznm::run("cp " + inpath + "/" + Prjshort + "cmbd.cpp.ip " + outpath + "/" + s + ".cpp.ip");
			};
		};
	};

	// IP leaveSgeExtract --- IEND
};

uint DlgWznmRlsStareptr::enterSgePack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	ListWznmMComponent cmps;
	WznmMComponent* cmp = NULL;

	ListWznmMFile fils;
	WznmMFile* fil = NULL;

	ubigint refWznmMVersion;
	ubigint bvrRefWznmMVersion;

	string tgzfile;

	vector<string> folders;

	string s, s2;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	// .tgz result folder
	tgzfile = Tmp::newfile(xchg->tmppath, "tgz");
	Wznm::tgz(xchg->tmppath + "/" + xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref), xchg->tmppath + "/" + tgzfile);

	// store in archive with reference to base version
	if (dbswznm->loadRefBySQL("SELECT bvrRefWznmMVersion FROM TblWznmMVersion WHERE ref = " + to_string(refWznmMVersion), bvrRefWznmMVersion))
				Acv::addfile(dbswznm, xchg->acvpath, xchg->tmppath + "/" + tgzfile, xchg->getRefPreset(VecWznmVPreset::PREWZNMGROUP, jref), xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref), VecWznmVMFileRefTbl::VER, bvrRefWznmMVersion, "custip", "custip.tgz", "tgz", "");

	s = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if ((xchg->tmppath != "") && (s != "")) {
		s = xchg->tmppath + "/" + s;

		if (access(s.c_str(), R_OK) == 0) {
			// empty out repository folder only affecting _ini, _mdl, _rls and all component subfolders
			folders.push_back("_ini");
			folders.push_back("_mdl");
			folders.push_back("_rls");

			dbswznm->tblwznmmcomponent->loadRstByVer(bvrRefWznmMVersion, false, cmps);
			if (cmps.nodes.size() == 0) dbswznm->tblwznmmcomponent->loadRstByVer(refWznmMVersion, false, cmps);

			for (unsigned int i = 0; i < cmps.nodes.size(); i++) {
				cmp = cmps.nodes[i];
				folders.push_back(cmp->sref);
			};

			for (unsigned int i = 0; i < folders.size(); i++) {
				if (folders[i] != "") {
					s2 = s + "/" + folders[i];
					if (access(s2.c_str(), R_OK) == 0) Wznm::run("rm -rf " + s2);
				};
			};

			// copy model files into _mdl subfolder
			s2 = s + "/_mdl";
#ifdef _WIN32
			if (access(s2.c_str(), W_OK) == -1) mkdir(s2.c_str());
#else
			if (access(s2.c_str(), W_OK) == -1) mkdir(s2.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

			dbswznm->tblwznmmfile->loadRstBySQL("SELECT * FROM TblWznmMFile WHERE refIxVTbl = " + to_string(VecWznmVMFileRefTbl::VER) + " AND refUref = " + to_string(refWznmMVersion) + " AND osrefKContent = 'mod'", false, fils);
			for (unsigned int i = 0; i < fils.nodes.size(); i++) {
				fil = fils.nodes[i];
				Wznm::run("cp " + xchg->acvpath + "/" + Acv::getfile(dbswznm, fil->ref) + " " + s2 + "/" + fil->Filename);
			};
		};
	};

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWznmRlsStareptr::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmRlsStareptr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmRlsStareptr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
