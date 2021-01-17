/**
	* \file JobWznmIexApp.cpp
	* job handler for job JobWznmIexApp (implementation)
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
			, const string& _rectpath
		) {
	if (ixVSge == VecVSge::IDLE) {
		fullpath = _fullpath;
		xmlNotTxt = _xmlNotTxt;
		rectpath = _rectpath;

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
	rectpath = "";

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeimevent.clear();
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
		IexWznmApp::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimevent, imeimrtjob, imeimsequence);

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

	ImeitemIMEvent* evt = NULL;
	ImeitemIMRtjob* rtj = NULL;
	ImeitemIMSequence* seq = NULL;
	ImeitemIMRtblock* rtb = NULL;
	ImeitemIMRtdpch* rtd = NULL;
	ImeitemIMState* ste = NULL;
	ImeitemIAMStateAction* steAact = NULL;
	ImeitemIAMStateTrig* steAtrg = NULL;
	ImeitemIJAMStateTrigCond* strJcnd = NULL;

	set<ubigint> irefs0;

	uint num1, num2;

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

	ImeitemIMSequence* seq2 = NULL;

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

		// -- ImeIMEvent
		for (unsigned int ix0 = 0; ix0 < imeimevent.nodes.size(); ix0++) {
			evt = imeimevent.nodes[ix0];

			evt->refWznmMApp = refWznmMApp;
			//evt->sref: TBL
			//evt->Comment: TBL

			dbswznm->tblwznmmevent->insertRec(evt);
			impcnt++;
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
				//ste->Comment: TBL

				dbswznm->tblwznmmstate->insertRec(ste);
				impcnt++;

				refsSte[ste->sref] = ste->ref;

				for (unsigned int ix2 = 0; ix2 < ste->imeiamstatetrig.nodes.size(); ix2++) {
					steAtrg = ste->imeiamstatetrig.nodes[ix2];

					steAtrg->refWznmMState = ste->ref;
					//steAtrg->sref: TBL
					steAtrg->ixVType = VecWznmVAMStateTrigType::getIx(steAtrg->srefIxVType);
					if (steAtrg->ixVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",steAtrg->srefIxVType}, {"iel","srefIxVType"}, {"lineno",to_string(steAtrg->lineno)}});
					if (steAtrg->srefRefWznmMEvent != "") {
						for (unsigned int i = 0; i < imeimevent.nodes.size(); i++) {
							evt = imeimevent.nodes[i];
							if (evt->sref == steAtrg->srefRefWznmMEvent) {
								steAtrg->refWznmMEvent = evt->ref;
								break;
							};
						};
						if (steAtrg->refWznmMEvent == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAtrg->srefRefWznmMEvent}, {"iel","srefRefWznmMEvent"}, {"lineno",to_string(steAtrg->lineno)}});
					};
					if (steAtrg->irefRefWznmMRtjob != 0) {
						for (unsigned int i = 0; i < imeimrtjob.nodes.size(); i++) {
							rtj = imeimrtjob.nodes[i];
							if (rtj->iref == steAtrg->irefRefWznmMRtjob) {
								steAtrg->refWznmMRtjob = rtj->ref;

								if (steAtrg->srefRefWznmMVectoritem != "") {
									dbswznm->loadRefBySQL("SELECT TblWznmMVectoritem.ref FROM TblWznmMVector, TblWznmMVectoritem WHERE TblWznmMVector.hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB)
												+ " AND TblWznmMVector.hkUref = " + to_string(rtj->refWznmMJob) + " AND TblWznmMVector.sref LIKE 'Vec%Sge' AND TblWznmMVectoritem.vecRefWznmMVector = TblWznmMVector.ref AND TblWznmMVectoritem.sref = '"
												+ steAtrg->srefRefWznmMVectoritem + "'", steAtrg->refWznmMVectoritem);
									if (steAtrg->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAtrg->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(steAtrg->lineno)}});
								};
								if (steAtrg->srefRefWznmMRtdpch != "") {
									for (unsigned int j = 0; j < rtj->imeimrtdpch.nodes.size(); j++) {
										rtd = rtj->imeimrtdpch.nodes[j];
										if (rtd->sref == steAtrg->srefRefWznmMRtdpch) {
											steAtrg->refWznmMRtdpch = rtd->ref;
											break;
										};
									};
									if (steAtrg->refWznmMRtdpch == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAtrg->srefRefWznmMRtdpch}, {"iel","srefRefWznmMRtdpch"}, {"lineno",to_string(steAtrg->lineno)}});
								};

								break;
							};
						};

						if (steAtrg->refWznmMRtjob == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(steAtrg->irefRefWznmMRtjob)}, {"iel","irefRefWznmMRtjob"}, {"lineno",to_string(steAtrg->lineno)}});
					};
					//steAtrg->xsref: TBL
					//steAtrg->srefsMask: TBL
					//steAtrg->Cond: TBL

					dbswznm->tblwznmamstatetrig->insertRec(steAtrg);
					impcnt++;

					for (unsigned int ix3 = 0; ix3 < steAtrg->imeijamstatetrigcond.nodes.size(); ix3++) {
						strJcnd = steAtrg->imeijamstatetrigcond.nodes[ix3];

						strJcnd->refWznmAMStateTrig = steAtrg->ref;
						strJcnd->x1IxWznmVApptarget = VecWznmVApptarget::getIx(strJcnd->srefX1IxWznmVApptarget);
						if (strJcnd->x1IxWznmVApptarget == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",strJcnd->srefX1IxWznmVApptarget}, {"iel","srefX1IxWznmVApptarget"}, {"lineno",to_string(strJcnd->lineno)}});
						//strJcnd->Cond: TBL

						dbswznm->tblwznmjamstatetrigcond->insertRec(strJcnd);
						impcnt++;
					};
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < ste->imeiamstateaction.nodes.size(); ix2++) {
					steAact = ste->imeiamstateaction.nodes[ix2];

					steAact->steRefWznmMState = ste->ref;
					steAact->steNum = num2++;
					steAact->ixVSection = VecWznmVAMStateActionSection::getIx(steAact->srefIxVSection);
					if (steAact->ixVSection == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",steAact->srefIxVSection}, {"iel","srefIxVSection"}, {"lineno",to_string(steAact->lineno)}});
					steAact->ixVType = VecWznmVAMStateActionType::getIx(steAact->srefIxVType);
					if (steAact->ixVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",steAact->srefIxVType}, {"iel","srefIxVType"}, {"lineno",to_string(steAact->lineno)}});
					if (steAact->irefRefWznmMRtjob != 0) {
						for (unsigned int i = 0; i < imeimrtjob.nodes.size(); i++) {
							rtj = imeimrtjob.nodes[i];
							if (rtj->iref == steAact->irefRefWznmMRtjob) {
								steAact->refWznmMRtjob = rtj->ref;
								break;
							};
						};
						if (steAact->refWznmMRtjob == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(steAact->irefRefWznmMRtjob)}, {"iel","irefRefWznmMRtjob"}, {"lineno",to_string(steAact->lineno)}});
					};
					if (steAact->srefRefWznmMVector != "") {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + steAact->srefRefWznmMVector + "'", steAact->refWznmMVector);
						if (steAact->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAact->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(steAact->lineno)}});
						if (steAact->srefRefWznmMVectoritem != "") {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(steAact->refWznmMVector) + " AND sref = '" + steAact->srefRefWznmMVectoritem + "'", steAact->refWznmMVectoritem);
							if (steAact->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAact->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(steAact->lineno)}});
						};
					};
					//steAact->snxRefWznmMState: IMPPP
					//steAact->refWznmMSequence: IMPPP
					//steAact->tr1SrefATrig: TBL
					//steAact->Ip1: TBL
					//steAact->tr2SrefATrig: TBL
					//steAact->Ip2: TBL
					//steAact->tr3SrefATrig: TBL
					//steAact->Ip3: TBL
					//steAact->tr4SrefATrig: TBL
					//steAact->Ip4: TBL

					dbswznm->tblwznmamstateaction->insertRec(steAact);
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

				if (rtj->supRefWznmMRtjob == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(rtj->irefSupRefWznmMRtjob)}, {"iel","irefSupRefWznmMRtjob"}, {"lineno",to_string(rtj->lineno)}});
				else dbswznm->tblwznmmrtjob->updateRec(rtj);
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

				for (unsigned int ix2 = 0; ix2 < ste->imeiamstateaction.nodes.size(); ix2++) {
					steAact = ste->imeiamstateaction.nodes[ix2];

					if (steAact->srefSnxRefWznmMState != "") {
						//steAact->snxRefWznmMState: IMPPP
						itRefsSte = refsSte.find(steAact->srefSnxRefWznmMState);
						if (itRefsSte == refsSte.end()) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAact->srefSnxRefWznmMState}, {"iel","srefSnxRefWznmMState"}, {"lineno",to_string(steAact->lineno)}});
						else {
							steAact->snxRefWznmMState = itRefsSte->second;
							dbswznm->tblwznmamstateaction->updateRec(steAact);
						};
					};

					if (steAact->srefRefWznmMSequence != "") {
						//steAact->refWznmMSequence: IMPPP
						for (unsigned int i = 0; i < imeimsequence.nodes.size(); i++) {
							seq2 = imeimsequence.nodes[i];

							if (seq2->sref == steAact->srefRefWznmMSequence) {
								steAact->refWznmMSequence = seq2->ref;
								dbswznm->tblwznmamstateaction->updateRec(steAact);

								break;
							};
						};

						if (steAact->refWznmMSequence == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",steAact->srefRefWznmMSequence}, {"iel","srefRefWznmMSequence"}, {"lineno",to_string(steAact->lineno)}});
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

	ImeitemIMEvent* evt = NULL;
	ImeitemIMRtjob* rtj = NULL;
	ImeitemIMSequence* seq = NULL;
	ImeitemIMRtblock* rtb = NULL;
	ImeitemIMRtdpch* rtd = NULL;
	ImeitemIMState* ste = NULL;
	ImeitemIAMStateAction* steAact = NULL;
	ImeitemIAMStateTrig* steAtrg = NULL;
	ImeitemIJAMStateTrigCond* strJcnd = NULL;

	// -- ImeIMEvent
	for (unsigned int ix0 = 0; ix0 < imeimevent.nodes.size(); ix0++) {
		evt = imeimevent.nodes[ix0];
		if (evt->ref != 0) dbswznm->tblwznmmevent->removeRecByRef(evt->ref);
	};

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

			for (unsigned int ix2 = 0; ix2 < ste->imeiamstateaction.nodes.size(); ix2++) {
				steAact = ste->imeiamstateaction.nodes[ix2];
				if (steAact->ref != 0) dbswznm->tblwznmamstateaction->removeRecByRef(steAact->ref);
			};

			for (unsigned int ix2 = 0; ix2 < ste->imeiamstatetrig.nodes.size(); ix2++) {
				steAtrg = ste->imeiamstatetrig.nodes[ix2];
				if (steAtrg->ref != 0) dbswznm->tblwznmamstatetrig->removeRecByRef(steAtrg->ref);

				for (unsigned int ix3 = 0; ix3 < steAtrg->imeijamstatetrigcond.nodes.size(); ix3++) {
					strJcnd = steAtrg->imeijamstatetrigcond.nodes[ix3];
					if (strJcnd->ref != 0) dbswznm->tblwznmjamstatetrigcond->removeRecByRef(strJcnd->ref);
				};
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

	ImeitemIMEvent* evt = NULL;
	ImeitemIMRtjob* rtj = NULL;
	ImeitemIMSequence* seq = NULL;
	ImeitemIMRtblock* rtb = NULL;
	ImeitemIMRtdpch* rtd = NULL;
	ImeitemIMState* ste = NULL;
	ImeitemIAMStateAction* steAact = NULL;
	ImeitemIAMStateTrig* steAtrg = NULL;
	ImeitemIJAMStateTrigCond* strJcnd = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMEvent
	for (unsigned int ix0 = 0; ix0 < imeimevent.nodes.size(); ix0++) {
		evt = imeimevent.nodes[ix0];

		if (evt->ref != 0) {
		};
	};

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
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMSTATEACTION, ixWznmVIop)) {
				dbswznm->tblwznmamstateaction->loadRefsBySte(ste->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ste->imeiamstateaction.nodes.push_back(new ImeitemIAMStateAction(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ste->imeiamstateaction.nodes.size(); ix2++) {
				steAact = ste->imeiamstateaction.nodes[ix2];

				if (steAact->ref != 0) {
					//steAact->irefRefWznmMRtjob: IREF
					steAact->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, steAact->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					steAact->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, steAact->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					steAact->srefSnxRefWznmMState = StubWznm::getStubSteStd(dbswznm, steAact->snxRefWznmMState, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					steAact->srefRefWznmMSequence = StubWznm::getStubSeqStd(dbswznm, steAact->refWznmMSequence, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMSTATETRIG, ixWznmVIop)) {
				dbswznm->tblwznmamstatetrig->loadRefsBySte(ste->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ste->imeiamstatetrig.nodes.push_back(new ImeitemIAMStateTrig(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ste->imeiamstatetrig.nodes.size(); ix2++) {
				steAtrg = ste->imeiamstatetrig.nodes[ix2];

				if (steAtrg->ref != 0) {
					//steAtrg->srefRefWznmMEvent: STUB
					//steAtrg->irefRefWznmMRtjob: IREF
					steAtrg->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, steAtrg->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					steAtrg->srefRefWznmMRtdpch = StubWznm::getStubRtdStd(dbswznm, steAtrg->refWznmMRtdpch, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAMSTATETRIGCOND, ixWznmVIop)) {
					dbswznm->tblwznmjamstatetrigcond->loadRefsByStr(steAtrg->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) steAtrg->imeijamstatetrigcond.nodes.push_back(new ImeitemIJAMStateTrigCond(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < steAtrg->imeijamstatetrigcond.nodes.size(); ix3++) {
					strJcnd = steAtrg->imeijamstatetrigcond.nodes[ix3];

					if (strJcnd->ref != 0) {
					};
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

	IexWznmApp::exportToFile(fullpath, xmlNotTxt, shorttags, imeimevent, imeimrtjob, imeimsequence);

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
