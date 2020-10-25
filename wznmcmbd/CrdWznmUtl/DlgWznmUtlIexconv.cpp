/**
	* \file DlgWznmUtlIexconv.cpp
	* job handler for job DlgWznmUtlIexconv (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmUtlIexconv.h"

#include "DlgWznmUtlIexconv_blks.cpp"
#include "DlgWznmUtlIexconv_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmUtlIexconv
 ******************************************************************************/

DlgWznmUtlIexconv::DlgWznmUtlIexconv(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMUTLIEXCONV, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::SRC;

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmUtlIexconv::~DlgWznmUtlIexconv() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWznm* DlgWznmUtlIexconv::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfcnv, &continfres, &feedFDse, &feedFSge, &statshr, &statshrcnv, &statshrres, &statshrsrc, items);
	};

	return dpcheng;
};

void DlgWznmUtlIexconv::refreshSrc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrSrc oldStatshrsrc(statshrsrc);

	// IP refreshSrc --- BEGIN
	// statshrsrc
	statshrsrc.UldActive = evalSrcUldActive(dbswznm);

	// IP refreshSrc --- END
	if (statshrsrc.diff(&oldStatshrsrc).size() != 0) insert(moditems, DpchEngData::STATSHRSRC);
};

void DlgWznmUtlIexconv::refreshCnv(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrCnv oldStatshrcnv(statshrcnv);
	ContInfCnv oldContinfcnv(continfcnv);

	// IP refreshCnv --- RBEGIN
	// continfcnv
	continfcnv.TxtPrg = getSquawk(dbswznm);

	// statshrcnv
	statshrcnv.ButRunActive = evalCnvButRunActive(dbswznm);
	statshrcnv.ButStoActive = evalCnvButStoActive(dbswznm);

	// IP refreshCnv --- REND
	if (statshrcnv.diff(&oldStatshrcnv).size() != 0) insert(moditems, DpchEngData::STATSHRCNV);
	if (continfcnv.diff(&oldContinfcnv).size() != 0) insert(moditems, DpchEngData::CONTINFCNV);
};

void DlgWznmUtlIexconv::refreshRes(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfRes oldContinfres(continfres);
	StatShrRes oldStatshrres(statshrres);

	// IP refreshRes --- BEGIN
	// continfres

	// statshrres
	statshrres.DldActive = evalResDldActive(dbswznm);

	// IP refreshRes --- END
	if (continfres.diff(&oldContinfres).size() != 0) insert(moditems, DpchEngData::CONTINFRES);
	if (statshrres.diff(&oldStatshrres).size() != 0) insert(moditems, DpchEngData::STATSHRRES);
};

void DlgWznmUtlIexconv::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
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

	refreshSrc(dbswznm, moditems);
	refreshCnv(dbswznm, moditems);
	refreshRes(dbswznm, moditems);
};

void DlgWznmUtlIexconv::handleRequest(
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

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLIEXCONVDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLIEXCONVDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoCnv != 0) {
				if (dpchappdo->ixVDoCnv == VecVDoCnv::BUTRUNCLICK) {
					handleDpchAppDoCnvButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoCnv == VecVDoCnv::BUTSTOCLICK) {
					handleDpchAppDoCnvButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
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
		else if ((req->sref == "mon") && (ixVSge == VecVSge::CONV)) handleTimerWithSrefMonInSgeConv(dbswznm);
	};
};

void DlgWznmUtlIexconv::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmUtlIexconv::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::SRC) && (_contiac->numFDse <= VecVDit::RES)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmUtlIexconv::handleDpchAppDoButDneClick(
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

void DlgWznmUtlIexconv::handleDpchAppDoCnvButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoCnvButRunClick --- BEGIN
	if (statshrcnv.ButRunActive) {
		changeStage(dbswznm, VecVSge::CONV, dpcheng);
	};
	// IP handleDpchAppDoCnvButRunClick --- END
};

void DlgWznmUtlIexconv::handleDpchAppDoCnvButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoCnvButStoClick --- INSERT
};

void DlgWznmUtlIexconv::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::UPKIDLE);
};

string DlgWznmUtlIexconv::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfile); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmUtlIexconv::handleTimerInSgeUpkidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmUtlIexconv::handleTimerWithSrefMonInSgeConv(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeConv --- ILINE
};

void DlgWznmUtlIexconv::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswznm); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswznm); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswznm); break;
				case VecVSge::ULDDONE: leaveSgeUlddone(dbswznm); break;
				case VecVSge::CONV: leaveSgeConv(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswznm, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswznm, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswznm, reenter); break;
			case VecVSge::ULDDONE: _ixVSge = enterSgeUlddone(dbswznm, reenter); break;
			case VecVSge::CONV: _ixVSge = enterSgeConv(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmUtlIexconv::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::ULDDONE) || (ixVSge == VecVSge::CONV) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::UNPACK) retval = "unpacking source";
			else if (ixVSge == VecVSge::UPKDONE) retval = "source unpacked";
			else if (ixVSge == VecVSge::ULDDONE) retval = "source uploaded";
			else if (ixVSge == VecVSge::CONV) retval = "converting files (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::PACK) retval = "packing result";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmUtlIexconv::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmUtlIexconv::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmUtlIexconv::enterSgeUpkidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWznmUtlIexconv::leaveSgeUpkidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWznmUtlIexconv::enterSgeUnpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN

	// 1st try: assume .tgz input file archive
	infolder = infilename.substr(infilename.rfind("/")+1);
	infile = infolder + ".tgz";

	Wznm::run("mv " + infilename + " " + infilename + ".tgz");

	outfolder = Tmp::newfolder(xchg->tmppath);
	outfile = Tmp::newfile(xchg->tmppath, "tgz");

	if (!Wznm::untgz(xchg->tmppath + "/" + infile, xchg->tmppath + "/" + infolder)) {
		// 2nd try: single text input file
		infolder = "";

		Wznm::run("mv " + infilename + ".tgz " + infilename + ".txt");
		infile = infilename.substr(infilename.rfind("/")+1) + ".txt";

		outfolder = "";
		outfile = Tmp::newfile(xchg->tmppath, "txt");

		retval = VecVSge::ULDDONE;
	};

	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWznmUtlIexconv::leaveSgeUnpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWznmUtlIexconv::enterSgeUpkdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWznmUtlIexconv::leaveSgeUpkdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWznmUtlIexconv::enterSgeUlddone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ULDDONE;

	// IP enterSgeUlddone --- INSERT

	return retval;
};

void DlgWznmUtlIexconv::leaveSgeUlddone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUlddone --- INSERT
};

uint DlgWznmUtlIexconv::enterSgeConv(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CONV;
	nextIxVSgeSuccess = VecVSge::PACK;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeConv --- IBEGIN

	DIR* dir = NULL;

	dirent* diritem = NULL;

	string s;

	if (infolder == "") {
		// single file
		addInv(new DpchInvWznmPrcfileIexconv(0, 0, infile, outfile));

	} else {
		// multiple files
		s = xchg->tmppath + "/" + infolder;
		dir = opendir(s.c_str());

		if (dir) {
			diritem = readdir(dir);

			while (diritem) {
				if (diritem->d_type == DT_REG) {
					s = diritem->d_name;
					if (s.rfind(".txt") == (s.length()-4)) addInv(new DpchInvWznmPrcfileIexconv(0, 0, infolder + "/" + s, outfolder + "/" + s));
				};

				diritem = readdir(dir);
			};

			closedir(dir);
		};
	};

	// IP enterSgeConv --- IEND

	submitInvs(dbswznm, VecVSge::IDLE, retval);
	return retval;
};

void DlgWznmUtlIexconv::leaveSgeConv(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeConv --- INSERT
};

uint DlgWznmUtlIexconv::enterSgePack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	// .tgz result folder
	if (outfolder != "") Wznm::tgz(xchg->tmppath + "/" + outfolder, xchg->tmppath + "/" + outfile);

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWznmUtlIexconv::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmUtlIexconv::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmUtlIexconv::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


