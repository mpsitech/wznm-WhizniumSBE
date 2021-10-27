/**
	* \file PnlWznmFilDetail.cpp
	* job handler for job PnlWznmFilDetail (implementation)
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

#include "PnlWznmFilDetail.h"

#include "PnlWznmFilDetail_blks.cpp"
#include "PnlWznmFilDetail_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWznmFilDetail
 ******************************************************************************/

PnlWznmFilDetail::PnlWznmFilDetail(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::PNLWZNMFILDETAIL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFLstClu.tag = "FeedFLstClu";
	feedFPupCnt.tag = "FeedFPupCnt";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMFILECONTENT, ixWznmVLocale, feedFPupCnt);
	feedFPupMim.tag = "FeedFPupMim";
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMFILEMIMETYPE, ixWznmVLocale, feedFPupMim);
	feedFPupRet.tag = "FeedFPupRet";
	VecWznmVMFileRefTbl::fillFeed(ixWznmVLocale, feedFPupRet);

	// IP constructor.cust1 --- INSERT

	dirty = false;

	// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMFIL_REUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMFIL_RETEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMFIL_CLUEQ, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMFILECONTENT);
	xchg->addIxClstn(VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, VecWznmVKeylist::KLSTWZNMKMFILEMIMETYPE);

	updatePreset(dbswznm, VecWznmVPreset::PREWZNMREFFIL, jref);
};

PnlWznmFilDetail::~PnlWznmFilDetail() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* PnlWznmFilDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFLstClu, &feedFPupCnt, &feedFPupMim, &feedFPupRet, &statshr, items);
	};

	return dpcheng;
};

void PnlWznmFilDetail::refreshLstClu(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

	statshr.LstCluActive = evalLstCluActive(dbswznm);
	statshr.ButCluViewActive = evalButCluViewActive(dbswznm);
	statshr.ButCluClusterAvail = evalButCluClusterAvail(dbswznm);
	statshr.ButCluUnclusterAvail = evalButCluUnclusterAvail(dbswznm);

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmFilDetail::refreshClu(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	vector<ubigint> refs;

	bool first;

	// contiac
	contiac.numFLstClu = 0;

	// feedFLstClu, continf
	feedFLstClu.clear();
	continf.TxtClu = "";

	if (recFil.refWznmCFile != 0) dbswznm->tblwznmmfile->loadRefsByClu(recFil.refWznmCFile, false, refs);

	first = true;
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] != recFil.ref) {
			feedFLstClu.appendRefTitles(refs[i], StubWznm::getStubFilStd(dbswznm, refs[i], ixWznmVLocale));

			if (first) first = false;
			else continf.TxtClu += ";";

			continf.TxtClu += StubWznm::getStubFilStd(dbswznm, refs[i], ixWznmVLocale);
		};
	};
	if (first) continf.TxtClu = "-";

	insert(moditems, DpchEngData::FEEDFLSTCLU);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshLstClu(dbswznm, moditems);
};

void PnlWznmFilDetail::refreshPupCnt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupCnt = 0;

	for (unsigned int i = 0; i < feedFPupCnt.size(); i++) {
		if (feedFPupCnt.getSrefByNum(i+1) == contiac.TxfCnt) {
			contiac.numFPupCnt = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfCntValid = (contiac.numFPupCnt != 0);
	statshr.PupCntActive = evalPupCntActive(dbswznm);
	statshr.ButCntEditAvail = evalButCntEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmFilDetail::refreshTxfCnt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfCnt = feedFPupCnt.getSrefByNum(contiac.numFPupCnt);

	// statshr
	statshr.TxfCntValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmFilDetail::refreshCnt(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupCnt
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMFILECONTENT, ixWznmVLocale, feedFPupCnt);

	insert(moditems, DpchEngData::FEEDFPUPCNT);

	refreshPupCnt(dbswznm, moditems);
};

void PnlWznmFilDetail::refreshPupMim(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.numFPupMim = 0;

	for (unsigned int i = 0; i < feedFPupMim.size(); i++) {
		if (feedFPupMim.getSrefByNum(i+1) == contiac.TxfMim) {
			contiac.numFPupMim = i+1;
			break;
		};
	};

	// statshr
	statshr.TxfMimValid = (contiac.numFPupMim != 0);
	statshr.PupMimActive = evalPupMimActive(dbswznm);
	statshr.ButMimEditAvail = evalButMimEditAvail(dbswznm);

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmFilDetail::refreshTxfMim(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// contiac
	contiac.TxfMim = feedFPupMim.getSrefByNum(contiac.numFPupMim);

	// statshr
	statshr.TxfMimValid = true;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlWznmFilDetail::refreshMim(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	// feedFPupMim
	dbswznm->fillFeedFromKlst(VecWznmVKeylist::KLSTWZNMKMFILEMIMETYPE, ixWznmVLocale, feedFPupMim);

	insert(moditems, DpchEngData::FEEDFPUPMIM);

	refreshPupMim(dbswznm, moditems);
};

void PnlWznmFilDetail::refreshRecFil(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	WznmMFile* _recFil = NULL;

	if (dbswznm->tblwznmmfile->loadRecByRef(recFil.ref, &_recFil)) {
		recFil = *_recFil;
		delete _recFil;
	} else recFil = WznmMFile();

	dirty = false;

	if (recFil.refWznmCFile == 0) xchg->removeClstns(VecWznmVCall::CALLWZNMFILMOD_CLUEQ, jref);
	else xchg->addRefClstn(VecWznmVCall::CALLWZNMFILMOD_CLUEQ, jref, Clstn::VecVJobmask::ALL, 0, true, recFil.refWznmCFile);

	contiac.TxfFnm = recFil.Filename;
	contiac.numFPupRet = feedFPupRet.getNumByIx(recFil.refIxVTbl);
	if (recFil.refIxVTbl == VecWznmVMFileRefTbl::APP) continf.TxtReu = StubWznm::getStubAppStd(dbswznm, recFil.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recFil.refIxVTbl == VecWznmVMFileRefTbl::LIB) continf.TxtReu = StubWznm::getStubLibStd(dbswznm, recFil.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else if (recFil.refIxVTbl == VecWznmVMFileRefTbl::VER) continf.TxtReu = StubWznm::getStubVerStd(dbswznm, recFil.refUref, ixWznmVLocale, Stub::VecVNonetype::FULL);
	else continf.TxtReu = "-";
	contiac.TxfCnt = recFil.osrefKContent;
	contiac.TxfAcv = Ftm::stamp(recFil.Archived);
	contiac.TxfAnm = recFil.Archivename;
	contiac.TxfMim = recFil.srefKMimetype;
	contiac.TxfSiz = to_string(recFil.Size);
	contiac.TxfCmt = recFil.Comment;

	statshr.TxfFnmActive = evalTxfFnmActive(dbswznm);
	statshr.TxtReuActive = evalTxtReuActive(dbswznm);
	statshr.ButReuViewAvail = evalButReuViewAvail(dbswznm);
	statshr.ButReuViewActive = evalButReuViewActive(dbswznm);
	statshr.TxfAcvActive = evalTxfAcvActive(dbswznm);
	statshr.TxfAnmActive = evalTxfAnmActive(dbswznm);
	statshr.TxfSizActive = evalTxfSizActive(dbswznm);
	statshr.TxfCmtActive = evalTxfCmtActive(dbswznm);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshClu(dbswznm, moditems);
	refreshPupCnt(dbswznm, moditems);
	refreshPupMim(dbswznm, moditems);

};

void PnlWznmFilDetail::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbswznm);
	statshr.ButSaveActive = evalButSaveActive(dbswznm);
	// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWznmFilDetail::updatePreset(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
	// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFFIL) {
		recFil.ref = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFFIL, jref);
		refreshRecFil(dbswznm, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
	// IP updatePreset --- END
};

void PnlWznmFilDetail::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUVIEWCLICK) {
					handleDpchAppDoButCluViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUCLUSTERCLICK) {
					handleDpchAppDoButCluClusterClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLUUNCLUSTERCLICK) {
					handleDpchAppDoButCluUnclusterClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREUVIEWCLICK) {
					handleDpchAppDoButReuViewClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCNTEDITCLICK) {
					handleDpchAppDoButCntEditClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMIMEDITCLICK) {
					handleDpchAppDoButMimEditClick(dbswznm, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWznmFilDetail::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWznmFilDetail::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::TXFFNM, ContIac::TXFACV, ContIac::TXFANM, ContIac::TXFSIZ, ContIac::TXFCMT})) {
		if (has(diffitems, ContIac::TXFFNM)) contiac.TxfFnm = _contiac->TxfFnm;
		if (has(diffitems, ContIac::TXFACV)) contiac.TxfAcv = _contiac->TxfAcv;
		if (has(diffitems, ContIac::TXFANM)) contiac.TxfAnm = _contiac->TxfAnm;
		if (has(diffitems, ContIac::TXFSIZ)) contiac.TxfSiz = _contiac->TxfSiz;
		if (has(diffitems, ContIac::TXFCMT)) contiac.TxfCmt = _contiac->TxfCmt;
	};

	if (has(diffitems, ContIac::NUMFLSTCLU)) {
		contiac.numFLstClu = _contiac->numFLstClu;
		refreshLstClu(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFCNT)) {
		contiac.TxfCnt = _contiac->TxfCnt;
		refreshPupCnt(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPCNT)) {
		contiac.numFPupCnt = _contiac->numFPupCnt;
		refreshTxfCnt(dbswznm, moditems);
	};

	if (has(diffitems, ContIac::TXFMIM)) {
		contiac.TxfMim = _contiac->TxfMim;
		refreshPupMim(dbswznm, moditems);
	} else if (has(diffitems, ContIac::NUMFPUPMIM)) {
		contiac.numFPupMim = _contiac->numFPupMim;
		refreshTxfMim(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWznmFilDetail::handleDpchAppDoButSaveClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlWznmFilDetail::handleDpchAppDoButCluViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluViewClick --- INSERT
};

void PnlWznmFilDetail::handleDpchAppDoButCluClusterClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluClusterClick --- INSERT
};

void PnlWznmFilDetail::handleDpchAppDoButCluUnclusterClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCluUnclusterClick --- INSERT
};

void PnlWznmFilDetail::handleDpchAppDoButReuViewClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	ubigint jrefNew = 0;
	string sref;

	if (statshr.ButReuViewAvail && statshr.ButReuViewActive) {
		if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref)) if (recFil.refIxVTbl == VecWznmVMFileRefTbl::APP) {
			sref = "CrdWznmApp";
			xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recFil.refUref, jrefNew);
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref)) if (recFil.refIxVTbl == VecWznmVMFileRefTbl::VER) {
				sref = "CrdWznmVer";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recFil.refUref, jrefNew);
			};
		};
		if (jrefNew == 0) {
			if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref)) if (recFil.refIxVTbl == VecWznmVMFileRefTbl::LIB) {
				sref = "CrdWznmLib";
				xchg->triggerIxRefSrefIntvalToRefCall(dbswznm, VecWznmVCall::CALLWZNMCRDOPEN, jref, 0, 0, sref, recFil.refUref, jrefNew);
			};
		};

		if (jrefNew == 0) *dpcheng = new DpchEngWznmConfirm(false, 0, "");
		else *dpcheng = new DpchEngWznmConfirm(true, jrefNew, sref);
	};
};

void PnlWznmFilDetail::handleDpchAppDoButCntEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButCntEditClick --- INSERT
};

void PnlWznmFilDetail::handleDpchAppDoButMimEditClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButMimEditClick --- INSERT
};

void PnlWznmFilDetail::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMFILMOD_CLUEQ) {
		call->abort = handleCallWznmFilMod_cluEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMKLSAKEYMOD_KLSEQ) {
		call->abort = handleCallWznmKlsAkeyMod_klsEq(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFILUPD_REFEQ) {
		call->abort = handleCallWznmFilUpd_refEq(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFIL_REUEQ) {
		call->abort = handleCallWznmFil_reuEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFIL_RETEQ) {
		call->abort = handleCallWznmFil_retEq(dbswznm, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMFIL_CLUEQ) {
		call->abort = handleCallWznmFil_cluEq(dbswznm, call->jref, call->argInv.ref, call->argRet.boolval);
	};
};

bool PnlWznmFilDetail::handleCallWznmFilMod_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	set<uint> moditems;

	refreshClu(dbswznm, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmFilDetail::handleCallWznmKlsAkeyMod_klsEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	set<uint> moditems;

	if (ixInv == VecWznmVKeylist::KLSTWZNMKMFILECONTENT) {
		refreshCnt(dbswznm, moditems);
	} else if (ixInv == VecWznmVKeylist::KLSTWZNMKMFILEMIMETYPE) {
		refreshMim(dbswznm, moditems);
	};

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};

bool PnlWznmFilDetail::handleCallWznmFilUpd_refEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWznmFilUpd_refEq --- INSERT
	return retval;
};

bool PnlWznmFilDetail::handleCallWznmFil_reuEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFil.refUref == refInv); // IP handleCallWznmFil_reuEq --- LINE
	return retval;
};

bool PnlWznmFilDetail::handleCallWznmFil_retEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFil.refIxVTbl == ixInv); // IP handleCallWznmFil_retEq --- LINE
	return retval;
};

bool PnlWznmFilDetail::handleCallWznmFil_cluEq(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
	boolvalRet = (recFil.refWznmCFile == refInv); // IP handleCallWznmFil_cluEq --- LINE
	return retval;
};
