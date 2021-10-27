/**
	* \file DlgWznmVerWrinimdl.cpp
	* job handler for job DlgWznmVerWrinimdl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmVerWrinimdl.h"

#include "DlgWznmVerWrinimdl_blks.cpp"
#include "DlgWznmVerWrinimdl_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVerWrinimdl
 ******************************************************************************/

DlgWznmVerWrinimdl::DlgWznmVerWrinimdl(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVERWRINIMDL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iexprj = NULL;
	iexdpl = NULL;
	iexgbl = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::WRI;

	iexprj = new JobWznmIexPrj(xchg, dbswznm, jref, ixWznmVLocale);
	iexdpl = new JobWznmIexDpl(xchg, dbswznm, jref, ixWznmVLocale);
	iexgbl = new JobWznmIexGbl(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVerWrinimdl::~DlgWznmVerWrinimdl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmVerWrinimdl::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continffia, &continfwri, &feedFDse, &feedFSge, &statshr, &statshrfia, &statshrwri, items);
	};

	return dpcheng;
};

void DlgWznmVerWrinimdl::refreshWri(
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

void DlgWznmVerWrinimdl::refreshFia(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfFia oldContinffia(continffia);
	StatShrFia oldStatshrfia(statshrfia);

	// IP refreshFia --- RBEGIN
	// statshrfia
	statshrfia.DldActive = evalFiaDldActive(dbswznm);

	// continffia
	continffia.Dld = "Inimdl_" + prjshort + ".tgz";

	// IP refreshFia --- REND
	if (continffia.diff(&oldContinffia).size() != 0) insert(moditems, DpchEngData::CONTINFFIA);
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
};

void DlgWznmVerWrinimdl::refresh(
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
	refreshFia(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmVerWrinimdl::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERWRINIMDLDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERWRINIMDLDO) {
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

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::WRITE)) handleTimerWithSrefMonInSgeWrite(dbswznm);
	};
};

void DlgWznmVerWrinimdl::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVerWrinimdl::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::WRI) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmVerWrinimdl::handleDpchAppDoButDneClick(
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

void DlgWznmVerWrinimdl::handleDpchAppDoWriButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWriButRunClick --- BEGIN
	if (statshrwri.ButRunActive) {
		changeStage(dbswznm, VecVSge::EXPORT, dpcheng);
	};
	// IP handleDpchAppDoWriButRunClick --- END
};

void DlgWznmVerWrinimdl::handleDpchAppDoWriButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWriButStoClick --- INSERT
};

void DlgWznmVerWrinimdl::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

string DlgWznmVerWrinimdl::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfolder + ".tgz"); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmVerWrinimdl::handleTimerWithSrefMonInSgeWrite(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	// IP handleTimerWithSrefMonInSgeWrite --- INSERT
};

void DlgWznmVerWrinimdl::changeStage(
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
				case VecVSge::WRITE: leaveSgeWrite(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbswznm, reenter); break;
			case VecVSge::WRITE: _ixVSge = enterSgeWrite(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVerWrinimdl::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::EXPORT) || (ixVSge == VecVSge::WRITE) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::EXPORT) retval = "exporting project/deployment information and global features";
			else if (ixVSge == VecVSge::WRITE) retval = "writing initial model file set (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::PACK) retval = "packing model file set";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVerWrinimdl::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVerWrinimdl::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVerWrinimdl::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::WRITE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeExport --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	map<uint,uint> icsWznmVIop;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	string prjshort = StrMod::lc(Wznm::getPrjshort(dbswznm, refWznmMVersion));

	outfolder = Tmp::newfolder(xchg->tmppath);

	// - project information
	icsWznmVIop = IexWznmPrj::icsWznmVIopInsAll();

	if (dbswznm->loadRefBySQL("SELECT prjRefWznmMProject FROM TblWznmMVersion WHERE ref = " + to_string(refWznmMVersion), ref)) iexprj->imeimproject.nodes.push_back(new ImeitemIWznmPrjMProject(dbswznm, ref));

	iexprj->collect(dbswznm, icsWznmVIop);
	iexprj->exportToFile(dbswznm, xchg->tmppath + "/" + outfolder + "/IexWznmPrj_" + prjshort + ".txt", false);

	iexprj->ixVSge = JobWznmIexPrj::VecVSge::CLTDONE;
	iexprj->exportToFile(dbswznm, xchg->tmppath + "/" + outfolder + "/IexWznmPrj_" + prjshort + ".xml", true, true);

	// - deployment information
	icsWznmVIop = IexWznmDpl::icsWznmVIopInsAll();

	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMComponent WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexdpl->imeimcomponent.nodes.push_back(new ImeitemIWznmDplMComponent(dbswznm, refs[i]));

	iexdpl->collect(dbswznm, icsWznmVIop);
	iexdpl->exportToFile(dbswznm, xchg->tmppath + "/" + outfolder + "/IexWznmDpl_" + prjshort + ".txt", false);

	iexdpl->ixVSge = JobWznmIexDpl::VecVSge::CLTDONE;
	iexdpl->exportToFile(dbswznm, xchg->tmppath + "/" + outfolder + "/IexWznmDpl_" + prjshort + ".xml", true, true);

	// - global features
	icsWznmVIop = {{(uint)VecVIexWznmGblIme::IMEIMCAPABILITY,VecWznmVIop::INS},{(uint)VecVIexWznmGblIme::IMEIAMCAPABILITYPAR,VecWznmVIop::INS}};

	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMCapability WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexgbl->imeimcapability.nodes.push_back(new ImeitemIWznmGblMCapability(dbswznm, refs[i]));

	iexgbl->collect(dbswznm, icsWznmVIop);
	iexgbl->exportToFile(dbswznm, xchg->tmppath + "/" + outfolder + "/IexWznmGbl_" + prjshort + ".txt", false);

	iexgbl->ixVSge = JobWznmIexGbl::VecVSge::CLTDONE;
	iexgbl->exportToFile(dbswznm, xchg->tmppath + "/" + outfolder + "/IexWznmGbl_" + prjshort + ".xml", true, true);
	// IP enterSgeExport --- IEND

	return retval;
};

void DlgWznmVerWrinimdl::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint DlgWznmVerWrinimdl::enterSgeWrite(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::WRITE;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::IDLE;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeWrite --- IBEGIN
	ListWznmMCapability cpbs;
	WznmMCapability* cpb = NULL;

	ubigint refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);

	map<ubigint,string> srefsCtpCustops;

	string s;

	Prjshort = Wznm::getPrjshort(dbswznm, refWznmMVersion);
	prjshort = StrMod::lc(Prjshort);

	// determine capabilities due for op invocation
	Wznm::getSrefsCtpCustops(dbswznm, srefsCtpCustops, VecWznmVKeylist::KLSTKWZNMCTPWRSTKITCUSTOP);

	dbswznm->tblwznmmcapability->loadRstBySQL("SELECT * FROM TblWznmMCapability WHERE refWznmMVersion = " + to_string(refWznmMVersion), false, cpbs);

	for (unsigned int i = 0; i < cpbs.nodes.size(); i++) {
		cpb = cpbs.nodes[i];

		auto it = srefsCtpCustops.find(cpb->tplRefWznmMCapability);

		if (it != srefsCtpCustops.end()) {
			s = xchg->tmppath + "/" + outfolder + "/" + cpb->sref;
			mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

			addInv(new DpchInvWznmCtpWrstkit(0, it->second, 0, cpb->ref, Prjshort, outfolder + "/" + cpb->sref));
		};
	};
	// IP enterSgeWrite --- IEND

	submitInvs(dbswznm, VecVSge::PACK, retval);
	return retval;
};

void DlgWznmVerWrinimdl::leaveSgeWrite(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeWrite --- INSERT
};

uint DlgWznmVerWrinimdl::enterSgePack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	// .tgz result folder
	Wznm::tgz(xchg->tmppath + "/" + outfolder, xchg->tmppath + "/" + outfolder + ".tgz");

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWznmVerWrinimdl::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmVerWrinimdl::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmVerWrinimdl::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
