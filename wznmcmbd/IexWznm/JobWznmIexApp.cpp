/**
	* \file JobWznmIexApp.cpp
	* job handler for job JobWznmIexApp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "JobWznmIexApp.h"

#include "JobWznmIexApp_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmApp;

/******************************************************************************
 class JobWznmIexApp
 ******************************************************************************/

JobWznmIexApp::JobWznmIexApp(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXAPP, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexApp::~JobWznmIexApp() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexApp::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexApp::parseFromFile(
			DbsWznm* dbswznm
			, const string& _fullpath
			, const bool _xmlNotTxt
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;

		changeStage(dbswznm, VecVSge::PARSE);
	};
};

void JobWznmIexApp::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexApp::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexApp::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexApp::exportToFile(
			DbsWznm* dbswznm
			, const string& _fullpath
			, const bool _xmlNotTxt
			, const bool _shorttags
		) {
	if ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CLTDONE)) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		shorttags = _shorttags;

		changeStage(dbswznm, VecVSge::EXPORT);
	};
};

void JobWznmIexApp::handleRequest(
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

	};
};

void JobWznmIexApp::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::PARSE: leaveSgeParse(dbswznm); break;
				case VecVSge::PRSERR: leaveSgePrserr(dbswznm); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswznm); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswznm); break;
				case VecVSge::IMPERR: leaveSgeImperr(dbswznm); break;
				case VecVSge::REVERSE: leaveSgeReverse(dbswznm); break;
				case VecVSge::COLLECT: leaveSgeCollect(dbswznm); break;
				case VecVSge::CLTDONE: leaveSgeCltdone(dbswznm); break;
				case VecVSge::EXPORT: leaveSgeExport(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswznm, reenter); break;
			case VecVSge::PRSERR: _ixVSge = enterSgePrserr(dbswznm, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswznm, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswznm, reenter); break;
			case VecVSge::IMPERR: _ixVSge = enterSgeImperr(dbswznm, reenter); break;
			case VecVSge::REVERSE: _ixVSge = enterSgeReverse(dbswznm, reenter); break;
			case VecVSge::COLLECT: _ixVSge = enterSgeCollect(dbswznm, reenter); break;
			case VecVSge::CLTDONE: _ixVSge = enterSgeCltdone(dbswznm, reenter); break;
			case VecVSge::EXPORT: _ixVSge = enterSgeExport(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWznmIexApp::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing app features";
			else if (ixVSge == VecVSge::PRSDONE) retval = "app features parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing app features (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing app features import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting app features for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "app features collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting app features";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexApp::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeimrtjob.clear();
	imeimsequence.clear();

	return retval;
};

void JobWznmIexApp::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexApp::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmApp::parseFromFile(fullpath, xmlNotTxt, imeimrtjob, imeimsequence);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexApp::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexApp::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexApp::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexApp::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexApp::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexApp::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMRtjob* rtj = NULL;
	ImeitemIMSequence* seq = NULL;
	ImeitemIMRtblock* rtb = NULL;
	ImeitemIMRtdpch* rtd = NULL;
	ImeitemIMState* ste = NULL;
	ImeitemIAMStateStep* steAstp = NULL;

	set<ubigint> irefs0;

	uint num1;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWznmMApp;
	refWznmMApp = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref);

	ubigint refWznmMVersion;
	dbswznm->loadRefBySQL("SELECT verRefWznmMVersion FROM TblWznmMApp WHERE ref = " + to_string(refWznmMApp), refWznmMVersion);

	map<string,ubigint> refsSte;
	map<string,ubigint>::iterator itRefsSte;

	WznmMJob* job = NULL;
	uint hkIxVTbl;

	ImeitemIMRtjob* rtj2 = NULL;

	bool found;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMRtjob
		irefs0.clear();

		for (unsigned int ix0 = 0; ix0 < imeimrtjob.nodes.size(); ix0++) {
			rtj = imeimrtjob.nodes[ix0];

			if (irefs0.find(rtj->iref) != irefs0.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(rtj->iref)}, {"ime","ImeIMRtjob"}, {"lineno",to_string(rtj->lineno)}});
			irefs0.insert(rtj->iref);
			rtj->refWznmMApp = refWznmMApp;
			//rtj->supRefWznmMRtjob: IMPPP
			//rtj->refWznmMJob: CUSTSQL
			dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + rtj->srefRefWznmMJob + "'", rtj->refWznmMJob);
			if (rtj->refWznmMJob == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rtj->srefRefWznmMJob}, {"iel","srefRefWznmMJob"}, {"lineno",to_string(rtj->lineno)}});
			//rtj->sref: TBL
			//rtj->Comment: TBL

			dbswznm->tblwznmmrtjob->insertRec(rtj);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < rtj->imeimrtblock.nodes.size(); ix1++) {
				rtb = rtj->imeimrtblock.nodes[ix1];

				rtb->refWznmMRtjob = rtj->ref;
				rtb->refIxVTbl = VecWznmVMRtblockRefTbl::getIx(rtb->srefRefIxVTbl);
				if (rtb->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",rtb->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(rtb->lineno)}});
				//rtb->refUref: CUSTSQL
				if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::BLK) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + rtb->srefRefUref + "'", rtb->refUref);
				} else if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::FED) {
					if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
						hkIxVTbl = 0;

						if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) hkIxVTbl = VecWznmVMControlHkTbl::CAR;
						else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) hkIxVTbl = VecWznmVMControlHkTbl::DLG;
						else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) hkIxVTbl = VecWznmVMControlHkTbl::PNL;

						if (hkIxVTbl != 0) dbswznm->loadRefBySQL("SELECT TblWznmMFeed.ref FROM TblWznmMFeed, TblWznmMControl WHERE TblWznmMControl.hkIxVTbl = " + to_string(hkIxVTbl) + " AND TblWznmMControl.hkUref = "
									+ to_string(job->refUref) + " AND TblWznmMFeed.refWznmMControl = TblWznmMControl.ref AND TblWznmMFeed.sref = '" + rtb->srefRefUref + "'", rtb->refUref);

						delete job;
					};
				} else if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::TBL) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + rtb->srefRefUref + "'", rtb->refUref);
				};
				if (rtb->refUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rtb->srefRefUref}, {"iel","srefRefUref"}, {"lineno",to_string(rtb->lineno)}});
				//rtb->sref: TBL
				//rtb->srcSrefsWznmAMBlockItem: TBL

				dbswznm->tblwznmmrtblock->insertRec(rtb);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < rtj->imeimrtdpch.nodes.size(); ix1++) {
				rtd = rtj->imeimrtdpch.nodes[ix1];

				rtd->refWznmMRtjob = rtj->ref;
				//rtd->refWznmMBlock: CUSTSQL
				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(rtj->refWznmMJob) + " AND sref = '" + rtd->srefRefWznmMBlock + "'", rtd->refWznmMBlock))
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID) + " AND sref = '" + rtd->srefRefWznmMBlock + "'", rtd->refWznmMBlock);
				if (rtd->refWznmMBlock == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rtd->srefRefWznmMBlock}, {"iel","srefRefWznmMBlock"}, {"lineno",to_string(rtd->lineno)}});
				//rtd->sref: TBL
				//rtd->Merge: TBL

				dbswznm->tblwznmmrtdpch->insertRec(rtd);
				impcnt++;
			};
		};

		// -- ImeIMSequence
		for (unsigned int ix0 = 0; ix0 < imeimsequence.nodes.size(); ix0++) {
			seq = imeimsequence.nodes[ix0];

			seq->appRefWznmMApp = refWznmMApp;
			seq->appNum = (ix0+1); // TBD
			//seq->sref: TBL
			//seq->Title: TBL
			//seq->Comment: TBL

			dbswznm->tblwznmmsequence->insertRec(seq);
			impcnt++;

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < seq->imeimstate.nodes.size(); ix1++) {
				ste = seq->imeimstate.nodes[ix1];

				ste->seqRefWznmMSequence = seq->ref;
				ste->seqNum = num1++;
				//ste->sref: TBL
				ste->eacIxVAction = VecWznmVMStateAction::getIx(ste->srefEacIxVAction);
				if (ste->eacIxVAction == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ste->srefEacIxVAction}, {"iel","srefEacIxVAction"}, {"lineno",to_string(ste->lineno)}});
				//ste->erjRefWznmMRtjob: PREVIMP
				if (ste->irefErjRefWznmMRtjob != 0) {
					for (unsigned int i = 0; i < imeimrtjob.nodes.size(); i++) {
						rtj = imeimrtjob.nodes[i];
						if (rtj->iref == ste->irefErjRefWznmMRtjob) {
							ste->erjRefWznmMRtjob = rtj->ref;
							break;
						};
					};
					if (ste->erjRefWznmMRtjob == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(ste->irefErjRefWznmMRtjob)}, {"iel","irefErjRefWznmMRtjob"}, {"lineno",to_string(ste->lineno)}});
				};
				//ste->eveRefWznmMVector: CUSTSQL
				if (ste->srefEveRefWznmMVector != "") {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + ste->srefEveRefWznmMVector + "'", ste->eveRefWznmMVector);
					if (ste->eveRefWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",ste->srefEveRefWznmMVector}, {"iel","srefEveRefWznmMVector"}, {"lineno",to_string(ste->lineno)}});
				};
				//ste->eviRefWznmMVectoritem: CUSTSQL
				if ((ste->eveRefWznmMVector != 0) && (ste->srefEviRefWznmMVectoritem != "")) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(ste->eveRefWznmMVector) + " AND sref = '" + ste->srefEviRefWznmMVectoritem + "'", ste->eviRefWznmMVectoritem);
					if (ste->eviRefWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",ste->srefEviRefWznmMVectoritem}, {"iel","srefEviRefWznmMVectoritem"}, {"lineno",to_string(ste->lineno)}});
				};
				//ste->esnRefWznmMState: IMPPP
				ste->lacIxVAction = VecWznmVMStateAction::getIx(ste->srefLacIxVAction);
				if (ste->lacIxVAction == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ste->srefLacIxVAction}, {"iel","srefLacIxVAction"}, {"lineno",to_string(ste->lineno)}});
				//ste->Custstep: TBL
				//ste->Comment: TBL

				dbswznm->tblwznmmstate->insertRec(ste);
				impcnt++;

				refsSte[ste->sref] = ste->ref;

				for (unsigned int ix2 = 0; ix2 < ste->imeiamstatestep.nodes.size(); ix2++) {
					steAstp = ste->imeiamstatestep.nodes[ix2];

					steAstp->refWznmMState = ste->ref;
					//steAstp->snxRefWznmMState: IMPPP
					steAstp->ixVTrigger = VecWznmVAMStateStepTrigger::getIx(steAstp->srefIxVTrigger);
					if (steAstp->ixVTrigger == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",steAstp->srefIxVTrigger}, {"iel","srefIxVTrigger"}, {"lineno",to_string(steAstp->lineno)}});
					//steAstp->refWznmMRtjob: PREVIMP
					if (steAstp->irefRefWznmMRtjob != 0) {
						for (unsigned int i = 0; i < imeimrtjob.nodes.size(); i++) {
							rtj = imeimrtjob.nodes[i];
							if (rtj->iref == steAstp->irefRefWznmMRtjob) {
								steAstp->refWznmMRtjob = rtj->ref;

								//steAstp->refWznmMVectoritem: CUSTSQL
								if (steAstp->srefRefWznmMVectoritem != "") {
									dbswznm->loadRefBySQL("SELECT TblWznmMVectoritem.ref FROM TblWznmMVector, TblWznmMVectoritem WHERE TblWznmMVector.hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB)
												+ " AND TblWznmMVector.hkUref = " + to_string(rtj->refWznmMJob) + " AND TblWznmMVector.sref LIKE 'Vec%Sge' AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMVector.ref AND TblWznmMVectoritem.sref = '"
												+ steAstp->srefRefWznmMVectoritem + "'", steAstp->refWznmMVectoritem);
									if (steAstp->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAstp->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(steAstp->lineno)}});
								};
								//steAstp->refWznmMRtdpch: PREVIMP
								if (steAstp->srefRefWznmMRtdpch != "") {
									for (unsigned int j = 0; j < rtj->imeimrtdpch.nodes.size(); j++) {
										rtd = rtj->imeimrtdpch.nodes[j];
										if (rtd->sref == steAstp->srefRefWznmMRtdpch) {
											steAstp->refWznmMRtdpch = rtd->ref;
											break;
										};
									};
									if (steAstp->refWznmMRtdpch == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAstp->srefRefWznmMRtdpch}, {"iel","srefRefWznmMRtdpch"}, {"lineno",to_string(steAstp->lineno)}});
								};

								break;
							};
						};

						if (steAstp->refWznmMRtjob == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(steAstp->irefRefWznmMRtjob)}, {"iel","irefRefWznmMRtjob"}, {"lineno",to_string(steAstp->lineno)}});
					};
					//steAstp->xsref: TBL
					//steAstp->srefsMask: TBL
					//steAstp->Cond: TBL
					//steAstp->Custcode: TBL

					dbswznm->tblwznmamstatestep->insertRec(steAstp);
					impcnt++;
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		for (unsigned int ix0 = 0; ix0 < imeimrtjob.nodes.size(); ix0++) {
			rtj = imeimrtjob.nodes[ix0];

			if (rtj->irefSupRefWznmMRtjob != 0) {
				for (unsigned int i = 0; i < imeimrtjob.nodes.size(); i++) {
					if (imeimrtjob.nodes[i]->iref == rtj->irefSupRefWznmMRtjob) {
						rtj->supRefWznmMRtjob = imeimrtjob.nodes[i]->ref;
						break;
					};
				};

				dbswznm->tblwznmmrtjob->updateRec(rtj);
			};
		};

		for (unsigned int ix0 = 0; ix0 < imeimrtjob.nodes.size(); ix0++) {
			rtj = imeimrtjob.nodes[ix0];

			if (rtj->supRefWznmMRtjob != 0) {
				rtj2 = rtj;

				while (rtj2->supRefWznmMRtjob != 0) {
					rtj->supLvl++;

					found = false;
					for (unsigned int i = 0; i < imeimrtjob.nodes.size(); i++) {
						if (imeimrtjob.nodes[i]->ref == rtj2->supRefWznmMRtjob) {
							rtj2 = imeimrtjob.nodes[i];
							found = true;
							break;
						};
					};

					if (!found) break;
				};

				dbswznm->tblwznmmrtjob->updateRec(rtj);
			};
		};

		for (unsigned int ix0 = 0; ix0 < imeimsequence.nodes.size(); ix0++) {
			seq = imeimsequence.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < seq->imeimstate.nodes.size(); ix1++) {
				ste = seq->imeimstate.nodes[ix1];

				//ste->esnRefWznmMState: IMPPP
				itRefsSte = refsSte.find(ste->srefEsnRefWznmMState);
				if (itRefsSte != refsSte.end()) {
					ste->esnRefWznmMState = itRefsSte->second;
					dbswznm->tblwznmmstate->updateRec(ste);
				};

				for (unsigned int ix2 = 0; ix2 < ste->imeiamstatestep.nodes.size(); ix2++) {
					steAstp = ste->imeiamstatestep.nodes[ix2];

					//steAstp->snxRefWznmMState: IMPPP
					itRefsSte = refsSte.find(steAstp->srefSnxRefWznmMState);
					if (itRefsSte != refsSte.end()) {
						steAstp->snxRefWznmMState = itRefsSte->second;
						dbswznm->tblwznmamstatestep->updateRec(steAstp);
					};
				};
			};
		};
		// IP enterSgeImport.ppr --- IEND
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexApp::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexApp::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexApp::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexApp::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMRtjob* rtj = NULL;
	ImeitemIMSequence* seq = NULL;
	ImeitemIMRtblock* rtb = NULL;
	ImeitemIMRtdpch* rtd = NULL;
	ImeitemIMState* ste = NULL;
	ImeitemIAMStateStep* steAstp = NULL;

	// -- ImeIMRtjob
	for (unsigned int ix0 = 0; ix0 < imeimrtjob.nodes.size(); ix0++) {
		rtj = imeimrtjob.nodes[ix0];
		if (rtj->ref != 0) dbswznm->tblwznmmrtjob->removeRecByRef(rtj->ref);

		for (unsigned int ix1 = 0; ix1 < rtj->imeimrtblock.nodes.size(); ix1++) {
			rtb = rtj->imeimrtblock.nodes[ix1];
			if (rtb->ref != 0) dbswznm->tblwznmmrtblock->removeRecByRef(rtb->ref);
		};

		for (unsigned int ix1 = 0; ix1 < rtj->imeimrtdpch.nodes.size(); ix1++) {
			rtd = rtj->imeimrtdpch.nodes[ix1];
			if (rtd->ref != 0) dbswznm->tblwznmmrtdpch->removeRecByRef(rtd->ref);
		};
	};

	// -- ImeIMSequence
	for (unsigned int ix0 = 0; ix0 < imeimsequence.nodes.size(); ix0++) {
		seq = imeimsequence.nodes[ix0];
		if (seq->ref != 0) dbswznm->tblwznmmsequence->removeRecByRef(seq->ref);

		for (unsigned int ix1 = 0; ix1 < seq->imeimstate.nodes.size(); ix1++) {
			ste = seq->imeimstate.nodes[ix1];
			if (ste->ref != 0) dbswznm->tblwznmmstate->removeRecByRef(ste->ref);

			for (unsigned int ix2 = 0; ix2 < ste->imeiamstatestep.nodes.size(); ix2++) {
				steAstp = ste->imeiamstatestep.nodes[ix2];
				if (steAstp->ref != 0) dbswznm->tblwznmamstatestep->removeRecByRef(steAstp->ref);
			};
		};
	};

	return retval;
};

void JobWznmIexApp::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexApp::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMRtjob* rtj = NULL;
	ImeitemIMSequence* seq = NULL;
	ImeitemIMRtblock* rtb = NULL;
	ImeitemIMRtdpch* rtd = NULL;
	ImeitemIMState* ste = NULL;
	ImeitemIAMStateStep* steAstp = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMRtjob
	for (unsigned int ix0 = 0; ix0 < imeimrtjob.nodes.size(); ix0++) {
		rtj = imeimrtjob.nodes[ix0];

		if (rtj->ref != 0) {
			rtj->iref = ix0+1;
			//rtj->irefSupRefWznmMRtjob: IREF
			rtj->srefRefWznmMJob = StubWznm::getStubJobStd(dbswznm, rtj->refWznmMJob, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMRTBLOCK, ixWznmVIop)) {
			dbswznm->tblwznmmrtblock->loadRefsByRtj(rtj->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) rtj->imeimrtblock.nodes.push_back(new ImeitemIMRtblock(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < rtj->imeimrtblock.nodes.size(); ix1++) {
			rtb = rtj->imeimrtblock.nodes[ix1];

			if (rtb->ref != 0) {
				rtb->srefRefUref = StubWznm::getStubBlkStd(dbswznm, rtb->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMRTDPCH, ixWznmVIop)) {
			dbswznm->tblwznmmrtdpch->loadRefsByRtj(rtj->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) rtj->imeimrtdpch.nodes.push_back(new ImeitemIMRtdpch(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < rtj->imeimrtdpch.nodes.size(); ix1++) {
			rtd = rtj->imeimrtdpch.nodes[ix1];

			if (rtd->ref != 0) {
				rtd->srefRefWznmMBlock = StubWznm::getStubBlkStd(dbswznm, rtd->refWznmMBlock, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMSequence
	for (unsigned int ix0 = 0; ix0 < imeimsequence.nodes.size(); ix0++) {
		seq = imeimsequence.nodes[ix0];

		if (seq->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSTATE, ixWznmVIop)) {
			dbswznm->tblwznmmstate->loadRefsBySeq(seq->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) seq->imeimstate.nodes.push_back(new ImeitemIMState(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < seq->imeimstate.nodes.size(); ix1++) {
			ste = seq->imeimstate.nodes[ix1];

			if (ste->ref != 0) {
				//ste->irefErjRefWznmMRtjob: IREF
				ste->srefEveRefWznmMVector = StubWznm::getStubVecStd(dbswznm, ste->eveRefWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				ste->srefEviRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, ste->eviRefWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				ste->srefEsnRefWznmMState = StubWznm::getStubSteStd(dbswznm, ste->esnRefWznmMState, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMSTATESTEP, ixWznmVIop)) {
				dbswznm->tblwznmamstatestep->loadRefsBySte(ste->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ste->imeiamstatestep.nodes.push_back(new ImeitemIAMStateStep(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ste->imeiamstatestep.nodes.size(); ix2++) {
				steAstp = ste->imeiamstatestep.nodes[ix2];

				if (steAstp->ref != 0) {
					steAstp->srefSnxRefWznmMState = StubWznm::getStubSteStd(dbswznm, steAstp->snxRefWznmMState, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					//steAstp->irefRefWznmMRtjob: IREF
					steAstp->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, steAstp->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					steAstp->srefRefWznmMRtdpch = StubWznm::getStubRtdStd(dbswznm, steAstp->refWznmMRtdpch, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexApp::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexApp::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexApp::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexApp::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmApp::exportToFile(fullpath, xmlNotTxt, shorttags, imeimrtjob, imeimsequence);

	return retval;
};

void JobWznmIexApp::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexApp::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexApp::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


