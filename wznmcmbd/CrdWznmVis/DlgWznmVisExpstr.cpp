/**
	* \file DlgWznmVisExpstr.cpp
	* job handler for job DlgWznmVisExpstr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmVisExpstr.h"

#include "DlgWznmVisExpstr_blks.cpp"
#include "DlgWznmVisExpstr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVisExpstr
 ******************************************************************************/

DlgWznmVisExpstr::DlgWznmVisExpstr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVISEXPSTR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iexvis = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::WRI;

	iexvis = new JobWznmIexVis(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- IBEGIN
	WznmMVisual* vis = NULL;

	if (dbswznm->tblwznmmvisual->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref), &vis)) {
		visshort = VecWznmVMVisualBasetype::getSref(vis->ixVBasetype) + StrMod::lc(Wznm::getPrjshort(dbswznm, vis->verRefWznmMVersion));

		delete vis;
	};
	// IP constructor.cust3 --- IEND

	// IP constructor.spec3 --- INSERT
};

DlgWznmVisExpstr::~DlgWznmVisExpstr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmVisExpstr::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfmfi, &continfwri, &feedFDse, &feedFSge, &statshr, &statshrmfi, &statshrwri, items);
	};

	return dpcheng;
};

void DlgWznmVisExpstr::refreshWri(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrWri oldStatshrwri(statshrwri);
	ContInfWri oldContinfwri(continfwri);

	// IP refreshWri --- RBEGIN
	// statshrwri
	statshrwri.ButRunActive = evalWriButRunActive(dbswznm);
	statshrwri.ButStoActive = evalWriButStoActive(dbswznm);

	// continfwri
	continfwri.TxtPrg = getSquawk(dbswznm);

	// IP refreshWri --- REND
	if (statshrwri.diff(&oldStatshrwri).size() != 0) insert(moditems, DpchEngData::STATSHRWRI);
	if (continfwri.diff(&oldContinfwri).size() != 0) insert(moditems, DpchEngData::CONTINFWRI);
};

void DlgWznmVisExpstr::refreshMfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfMfi oldContinfmfi(continfmfi);
	StatShrMfi oldStatshrmfi(statshrmfi);

	// IP refreshMfi --- RBEGIN
	// continfmfi
	continfmfi.Dld = "IexWznmVis_" + visshort + ".txt";

	// statshrmfi
	statshrmfi.DldActive = evalMfiDldActive(dbswznm);

	// IP refreshMfi --- REND
	if (continfmfi.diff(&oldContinfmfi).size() != 0) insert(moditems, DpchEngData::CONTINFMFI);
	if (statshrmfi.diff(&oldStatshrmfi).size() != 0) insert(moditems, DpchEngData::STATSHRMFI);
};

void DlgWznmVisExpstr::refresh(
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

	refreshWri(dbswznm, moditems);
	refreshMfi(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmVisExpstr::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVISEXPSTRDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVISEXPSTRDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoWri != 0) {
				if (dpchappdo->ixVDoWri == VecVDoWri::BUTRUNCLICK) {
					handleDpchAppDoWriButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWri == VecVDoWri::BUTSTOCLICK) {
					handleDpchAppDoWriButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);
	};
};

void DlgWznmVisExpstr::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVisExpstr::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::WRI) && (_contiac->numFDse <= VecVDit::MFI)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmVisExpstr::handleDpchAppDoButDneClick(
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

void DlgWznmVisExpstr::handleDpchAppDoWriButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWriButRunClick --- BEGIN
	if (statshrwri.ButRunActive) {
		changeStage(dbswznm, VecVSge::EXPORT, dpcheng);
	};
	// IP handleDpchAppDoWriButRunClick --- END
};

void DlgWznmVisExpstr::handleDpchAppDoWriButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWriButStoClick --- INSERT
};

string DlgWznmVisExpstr::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfile + ".txt"); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmVisExpstr::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::EXPORT: leaveSgeExport(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVisExpstr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if (ixVSge == VecVSge::EXPORT) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::EXPORT) retval = "exporting visualization";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVisExpstr::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVisExpstr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVisExpstr::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IDLE;

	// IP enterSgeExport --- IBEGIN
	vector<ubigint> refs;

	map<uint,uint> icsWznmVIop;

	ubigint refWznmMVisual = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref);

	outfile = Tmp::newfile(xchg->tmppath, "txt");

	icsWznmVIop = IexWznmVis::icsWznmVIopInsAll();

	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMSheet WHERE visRefWznmMVisual = " + to_string(refWznmMVisual) + " ORDER BY visNum ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexvis->imeimsheet.nodes.push_back(new ImeitemIWznmVisMSheet(dbswznm, refs[i]));

	iexvis->collect(dbswznm, icsWznmVIop);
	iexvis->exportToFile(dbswznm, xchg->tmppath + "/" + outfile + ".txt", false);
	// IP enterSgeExport --- IEND

	return retval;
};

void DlgWznmVisExpstr::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint DlgWznmVisExpstr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmVisExpstr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
