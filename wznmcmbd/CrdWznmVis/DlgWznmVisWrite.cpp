/**
	* \file DlgWznmVisWrite.cpp
	* job handler for job DlgWznmVisWrite (implementation)
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

#include "DlgWznmVisWrite.h"

#include "DlgWznmVisWrite_blks.cpp"
#include "DlgWznmVisWrite_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmVisWrite
 ******************************************************************************/

DlgWznmVisWrite::DlgWznmVisWrite(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMVISWRITE, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	qryboxctx = NULL;
	qrylinkctx = NULL;
	qryrowctx = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::WRC;

	qryboxctx = new QryWznmVisBoxctx(xchg, dbswznm, jref, ixWznmVLocale);
	qrylinkctx = new QryWznmVisLinkctx(xchg, dbswznm, jref, ixWznmVLocale);
	qryrowctx = new QryWznmVisRowctx(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- IBEGIN
	WznmMVisual* vis = NULL;

	// find type
	if (dbswznm->tblwznmmvisual->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref), &vis)) {
		ixVistype = vis->ixVBasetype;

		// find project short
		Prjshort = Wznm::getPrjshort(dbswznm, vis->verRefWznmMVersion);

		delete vis;
	};

	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmVisWrite::~DlgWznmVisWrite() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgWznmVisWrite::create(
			DbsWznm* dbswznm
		) {
	vector<ubigint> refs;
	ubigint ref;

	WznmMVisual* vis = NULL;

	ListWznmMSheet shts;
	WznmMSheet* sht = NULL;
	string Shtshort;

	string author, created;

	vector<string> keys;
	vector<string> vals;

	set<string> cftpls;
	ubigint refCftpl;

	string s;
	size_t ptr, ptr2;

	dbswznm->tblwznmmvisual->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref), &vis);

	ipfolder = Tmp::newfolder(xchg->tmppath);
	outfolder = Tmp::newfolder(xchg->tmppath);

	// --- prepare standard key/value pairs

	// -- author
	dbswznm->loadRefBySQL("SELECT refWznmMPerson FROM TblWznmMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref)), ref);

	author = StubWznm::getStubPrsStd(dbswznm, ref);

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// --- all files
	cftpls = {"VisXxxxxYyyyZzzzz.html", "VisXxxxxYyyyZzzzz_src.xml", "VisXxxxxYyyyZzzzz.svg"};
	cftpls.insert("vis" + StrMod::cap(VecWznmVMVisualBasetype::getSref(ixVistype)) + "Xxxx.js");

	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(StrMod::lc(Prjshort));
	keys.push_back("Typ"); vals.push_back(StrMod::cap(VecWznmVMVisualBasetype::getSref(ixVistype)));

	keys.push_back("Shtshort"); vals.push_back("Shtshort");
	keys.push_back("Shttit"); vals.push_back("Shttit");

	dbswznm->tblwznmmsheet->loadRstByVis(vis->ref, false, shts);
	unsigned int j = 0;
	unsigned int k = 0;

	for (unsigned int i = 0; i < shts.nodes.size(); i++) {
		sht = shts.nodes[i];

		Shtshort = to_string(sht->visNum);

/*
		ptr = sht->Title.find(' ');
		if (ptr == string::npos) Shtshort = StrMod::cap(sht->Title);
		else Shtshort = StrMod::cap(sht->Title.substr(0, ptr));
*/

		if (ixVistype == VecWznmVMVisualBasetype::DBSTR) {

		} else if (ixVistype == VecWznmVMVisualBasetype::IMPEXP) {
			if (dbswznm->loadRefBySQL("SELECT unvUref FROM TblWznmQVisBoxctx WHERE jref = " + to_string(qryboxctx->jref) + " AND tref = " + to_string(sht->ref) + " LIMIT 1", ref))
				dbswznm->loadStringBySQL("SELECT TblWznmMImpexpcplx.sref FROM TblWznmMImpexpcplx, TblWznmMImpexp WHERE TblWznmMImpexpcplx.ref = TblWznmMImpexp.refWznmMImpexpcplx AND TblWznmMImpexp.ref = " + to_string(ref), Shtshort);
		};

		vals[vals.size()-2] = Shtshort;
		vals[vals.size()-1] = sht->Title + " - " + StubWznm::getStubVisStd(dbswznm, sht->visRefWznmMVisual);

		for (auto it = cftpls.begin(); it != cftpls.end(); it++) {
			s = (*it);
			if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = '" + s + "'", refCftpl)) {
				ptr = s.find("Xxxxx");
				if (ptr != string::npos) s = s.replace(ptr, 5, StrMod::cap(VecWznmVMVisualBasetype::getSref(ixVistype)));

				ptr = s.find("Xxxx");
				if (ptr == string::npos) ptr = s.find("Yyyy");
				if (ptr != string::npos) s = s.replace(ptr, 4, Prjshort);

				ptr = s.find("Zzzzz");
				if (ptr != string::npos) s = s.replace(ptr, 5, Shtshort);

				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCftpl, "", outfolder + "/" + s, keys, vals));
			};
		};

		if (ixVistype == VecWznmVMVisualBasetype::DBSTR) addInv(new DpchInvWznmWrvisDbstr(0, 0, sht->ref, Prjshort, ipfolder, Shtshort, qryboxctx->jref, qrylinkctx->jref));
		else if (ixVistype == VecWznmVMVisualBasetype::IMPEXP) addInv(new DpchInvWznmWrvisImpexp(0, 0, sht->ref, Prjshort, ipfolder, Shtshort, qryboxctx->jref, qrylinkctx->jref));
	};

	delete vis;
};
// IP cust --- IEND

DpchEngWznm* DlgWznmVisWrite::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continffia, &continflfi, &continfwrc, &feedFDse, &feedFSge, &statshr, &statshrfia, &statshrlfi, &statshrwrc, items);
	};

	return dpcheng;
};

void DlgWznmVisWrite::refreshWrc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrWrc oldStatshrwrc(statshrwrc);
	ContInfWrc oldContinfwrc(continfwrc);

	// IP refreshWrc --- RBEGIN
	// continfwrc
	continfwrc.TxtPrg = getSquawk(dbswznm);

	// statshrwrc
	statshrwrc.ButRunActive = evalWrcButRunActive(dbswznm);
	statshrwrc.ButStoActive = evalWrcButStoActive(dbswznm);

	// continfwrc

	// IP refreshWrc --- REND
	if (statshrwrc.diff(&oldStatshrwrc).size() != 0) insert(moditems, DpchEngData::STATSHRWRC);
	if (continfwrc.diff(&oldContinfwrc).size() != 0) insert(moditems, DpchEngData::CONTINFWRC);
};

void DlgWznmVisWrite::refreshLfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);
	ContInfLfi oldContinflfi(continflfi);

	// IP refreshLfi --- BEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswznm);

	// continflfi

	// IP refreshLfi --- END
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
};

void DlgWznmVisWrite::refreshFia(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfFia oldContinffia(continffia);
	StatShrFia oldStatshrfia(statshrfia);

	// IP refreshFia --- RBEGIN
	// continffia
	continffia.Dld = "vis" + StrMod::lc(VecWznmVMVisualBasetype::getSref(ixVistype)) + StrMod::lc(Prjshort) + ".tgz";

	// statshrfia
	statshrfia.DldActive = evalFiaDldActive(dbswznm);

	// IP refreshFia --- REND
	if (continffia.diff(&oldContinffia).size() != 0) insert(moditems, DpchEngData::CONTINFFIA);
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
};

void DlgWznmVisWrite::refresh(
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

	refreshWrc(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);
	refreshFia(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmVisWrite::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVISWRITEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVISWRITEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoWrc != 0) {
				if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTRUNCLICK) {
					handleDpchAppDoWrcButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTSTOCLICK) {
					handleDpchAppDoWrcButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);
		else if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNM) {
				handleDpchRetWznm(dbswznm, (DpchRetWznm*) (req->dpchret));
			} else if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMPRCTREEMERGE) {
				handleDpchRetWznmPrctreeMerge(dbswznm, (DpchRetWznmPrctreeMerge*) (req->dpchret));
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

void DlgWznmVisWrite::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmVisWrite::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::WRC) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmVisWrite::handleDpchAppDoButDneClick(
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

void DlgWznmVisWrite::handleDpchAppDoWrcButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWrcButRunClick --- BEGIN
	if (statshrwrc.ButRunActive) {
		changeStage(dbswznm, VecVSge::WRITE, dpcheng);
	};
	// IP handleDpchAppDoWrcButRunClick --- END
};

void DlgWznmVisWrite::handleDpchAppDoWrcButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWrcButStoClick --- INSERT
};

void DlgWznmVisWrite::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRMER) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

void DlgWznmVisWrite::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

void DlgWznmVisWrite::handleDpchRetWznmPrctreeMerge(
			DbsWznm* dbswznm
			, DpchRetWznmPrctreeMerge* dpchret
		) {
	// IP handleDpchRetWznmPrctreeMerge --- IBEGIN
	logaspect = VecVSge::getSref(ixVSge);
	logfile = dpchret->logfile;
	// IP handleDpchRetWznmPrctreeMerge --- IEND
};

string DlgWznmVisWrite::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfolder + ".tgz"); // IP handleDownloadInSgeDone --- RLINE
};

string DlgWznmVisWrite::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

void DlgWznmVisWrite::handleTimerWithSrefMonInSgeWrite(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeWrite --- ILINE
};

void DlgWznmVisWrite::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRMER: leaveSgeAlrmer(dbswznm); break;
				case VecVSge::WRITE: leaveSgeWrite(dbswznm); break;
				case VecVSge::MRGGNR: leaveSgeMrggnr(dbswznm); break;
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
			case VecVSge::ALRMER: _ixVSge = enterSgeAlrmer(dbswznm, reenter); break;
			case VecVSge::WRITE: _ixVSge = enterSgeWrite(dbswznm, reenter); break;
			case VecVSge::MRGGNR: _ixVSge = enterSgeMrggnr(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmVisWrite::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::WRITE) || (ixVSge == VecVSge::MRGGNR) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::WRITE) retval = "writing code (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::MRGGNR) retval = "merging generated code fragments";
			else if (ixVSge == VecVSge::PACK) retval = "packing code tree";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmVisWrite::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmVisWrite::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmVisWrite::enterSgeAlrmer(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrmer --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Merge error (" + logaspect + "). View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	// IP enterSgeAlrmer --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmVisWrite::leaveSgeAlrmer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrmer --- INSERT
};

uint DlgWznmVisWrite::enterSgeWrite(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::WRITE;
	nextIxVSgeSuccess = VecVSge::MRGGNR;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeWrite --- IBEGIN

	// create -> outfolder
	// IP's -> ipfolder -> outfolder
	create(dbswznm);

	// IP enterSgeWrite --- IEND

	submitInvs(dbswznm, VecVSge::IDLE, retval);
	return retval;
};

void DlgWznmVisWrite::leaveSgeWrite(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeWrite --- INSERT
};

uint DlgWznmVisWrite::enterSgeMrggnr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MRGGNR;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrggnr --- IBEGIN

	if ((ixVistype == VecWznmVMVisualBasetype::DBSTR) || (ixVistype == VecWznmVMVisualBasetype::IMPEXP)) {
		// IP's -> ipfolder -> outfolder
		addInv(new DpchInvWznmPrctreeMerge(0, 0, "", ipfolder, "", outfolder, true, true));

	};

	// IP enterSgeMrggnr --- IEND

	submitInvs(dbswznm, VecVSge::PACK, retval);
	return retval;
};

void DlgWznmVisWrite::leaveSgeMrggnr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMrggnr --- INSERT
};

uint DlgWznmVisWrite::enterSgePack(
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

void DlgWznmVisWrite::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmVisWrite::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmVisWrite::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmVisWrite::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmVisWrite::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
