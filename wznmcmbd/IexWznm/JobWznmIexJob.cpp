/**
	* \file JobWznmIexJob.cpp
	* job handler for job JobWznmIexJob (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "JobWznmIexJob.h"

#include "JobWznmIexJob_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmJob;

/******************************************************************************
 class JobWznmIexJob
 ******************************************************************************/

JobWznmIexJob::JobWznmIexJob(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXJOB, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexJob::~JobWznmIexJob() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexJob::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexJob::parseFromFile(
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

void JobWznmIexJob::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexJob::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexJob::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexJob::exportToFile(
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

void JobWznmIexJob::handleRequest(
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

void JobWznmIexJob::changeStage(
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

string JobWznmIexJob::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing custom jobs";
			else if (ixVSge == VecVSge::PRSDONE) retval = "custom jobs parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing custom jobs (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing custom jobs import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting custom jobs for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "custom jobs collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting custom jobs";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexJob::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeimcapability.clear();
	imeimjob.clear();

	return retval;
};

void JobWznmIexJob::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexJob::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmJob::parseFromFile(fullpath, xmlNotTxt, imeimcapability, imeimjob);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexJob::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexJob::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexJob::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexJob::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexJob::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexJob::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMCapability* cpb = NULL;
	ImeitemIMJob* job = NULL;
	ImeitemIMBlock* blk = NULL;
	ImeitemIRMCapabilityUniversal* cpbRunv = NULL;
	ImeitemIAMBlockItem* blkAitm = NULL;
	ImeitemICAMBlockItem* blkAitmC = NULL;
	ImeitemIJAMBlockItem* bitJ = NULL;

	set<ubigint> irefs2;

	uint num2;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWznmMVersion;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMJob
		for (unsigned int ix0 = 0; ix0 < imeimjob.nodes.size(); ix0++) {
			job = imeimjob.nodes[ix0];

			job->ixVBasetype = VecWznmVMJobBasetype::CUST;
			//job->refWznmMVersion: PRESET
			job->refWznmMVersion = refWznmMVersion;
			job->refIxVTbl = VecWznmVMJobRefTbl::VOID;
			//job->sref: TBL
			//job->Clisrv: TBL
			//job->Shrdat: TBL
			//job->Comment: TBL

			dbswznm->tblwznmmjob->insertRec(job);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < job->imeimblock.nodes.size(); ix1++) {
				blk = job->imeimblock.nodes[ix1];

				blk->ixVBasetype = VecWznmVMBlockBasetype::STG;
				//blk->refWznmMVersion: PRESET
				blk->refWznmMVersion = refWznmMVersion;
				blk->refIxVTbl = VecWznmVMBlockRefTbl::JOB;
				blk->refUref = job->ref;
				blk->reaIxWznmWScope = VecWznmWScope::getIx(blk->srefsReaIxWznmWScope);
				blk->wriIxWznmWScope = VecWznmWScope::getIx(blk->srefsWriIxWznmWScope);
				//blk->sref: TBL
				//blk->Comment: TBL

				dbswznm->tblwznmmblock->insertRec(blk);
				impcnt++;

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < blk->imeicamblockitem.nodes.size(); ix2++) {
					blkAitmC = blk->imeicamblockitem.nodes[ix2];

					if (irefs2.find(blkAitmC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(blkAitmC->iref)}, {"ime","ImeICAMBlockItem"}, {"lineno",to_string(blkAitmC->lineno)}});
					blkAitmC->ref = dbswznm->tblwznmcamblockitem->getNewRef();
					irefs2.insert(blkAitmC->iref);

					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < blk->imeiamblockitem.nodes.size(); ix2++) {
					blkAitm = blk->imeiamblockitem.nodes[ix2];

					//blkAitm->refWznmCAMBlockItem: PREVIMP
					if (blkAitm->irefRefWznmCAMBlockItem != 0) {
						for (unsigned int i = 0; i < blk->imeicamblockitem.nodes.size(); i++)
							if (blk->imeicamblockitem.nodes[i]->iref == blkAitm->irefRefWznmCAMBlockItem) {
								blkAitm->refWznmCAMBlockItem = blk->imeicamblockitem.nodes[i]->ref;
								break;
							};
						if (blkAitm->refWznmCAMBlockItem == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(blkAitm->irefRefWznmCAMBlockItem)}, {"iel","irefRefWznmCAMBlockItem"}, {"lineno",to_string(blkAitm->lineno)}});
					};
					blkAitm->blkRefWznmMBlock = blk->ref;
					blkAitm->blkNum = num2++;
					blkAitm->ixVBasetype = VecWznmVAMBlockItemBasetype::getIx(blkAitm->srefIxVBasetype);
					if (blkAitm->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(blkAitm->lineno)}});
					//blkAitm->sref: TBL
					blkAitm->ixWznmVVartype = VecWznmVVartype::getIx(blkAitm->srefIxWznmVVartype);
					if (blkAitm->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(blkAitm->lineno)}});
					//blkAitm->refWznmMVector: CUSTSQL
					if (blkAitm->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, blkAitm->srefRefWznmMVector, blkAitm->refWznmMVector);
						if (blkAitm->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(blkAitm->lineno)}});
					};
					//blkAitm->refJ: SUB
					//blkAitm->Defval: TBL
					//blkAitm->refWznmMVectoritem: CUSTSQL
					if ((blkAitm->refWznmMVector != 0) && (blkAitm->srefRefWznmMVectoritem != "")) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm->refWznmMVector) + " AND sref = '" + blkAitm->srefRefWznmMVectoritem + "'", blkAitm->refWznmMVectoritem);
						if (blkAitm->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(blkAitm->lineno)}});
					};
					//blkAitm->Comment: TBL

					dbswznm->tblwznmamblockitem->insertRec(blkAitm);
					impcnt++;

					if (((blkAitm->Defval != "") || (blkAitm->srefRefWznmMVectoritem != "")) && blkAitm->imeijamblockitem.nodes.empty()) {
						bitJ = new ImeitemIJAMBlockItem();
						bitJ->lineno = blkAitm->lineno;
						blkAitm->imeijamblockitem.nodes.push_back(bitJ);

						bitJ->refWznmAMBlockItem = blkAitm->ref;
						bitJ->Defval = blkAitm->Defval;
						bitJ->srefRefWznmMVectoritem = blkAitm->srefRefWznmMVectoritem;
					};

					for (unsigned int ix3 = 0; ix3 < blkAitm->imeijamblockitem.nodes.size(); ix3++) {
						bitJ = blkAitm->imeijamblockitem.nodes[ix3];

						bitJ->refWznmAMBlockItem = blkAitm->ref;
						//bitJ->Defval: TBL
						//bitJ->refWznmMVectoritem: CUSTSQL
						if ((blkAitm->refWznmMVector != 0) && (bitJ->srefRefWznmMVectoritem != "")) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm->refWznmMVector) + " AND sref = '" + bitJ->srefRefWznmMVectoritem + "'", bitJ->refWznmMVectoritem);
							if (bitJ->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",bitJ->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(bitJ->lineno)}});
						};

						dbswznm->tblwznmjamblockitem->insertRec(bitJ);
						impcnt++;

						if (ix3 == 0) {
							blkAitm->refJ = bitJ->ref;
							blkAitm->Defval = bitJ->Defval;
							blkAitm->refWznmMVectoritem = bitJ->refWznmMVectoritem;
							dbswznm->tblwznmamblockitem->updateRec(blkAitm);
						};
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- INSERT
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexJob::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexJob::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexJob::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexJob::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMCapability* cpb = NULL;
	ImeitemIMJob* job = NULL;
	ImeitemIMBlock* blk = NULL;
	ImeitemIRMCapabilityUniversal* cpbRunv = NULL;
	ImeitemIAMBlockItem* blkAitm = NULL;
	ImeitemIJAMBlockItem* bitJ = NULL;

	// -- ImeIMCapability
	for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
		cpb = imeimcapability.nodes[ix0];
		if (cpb->ref != 0) dbswznm->tblwznmmcapability->removeRecByRef(cpb->ref);

		for (unsigned int ix1 = 0; ix1 < cpb->imeirmcapabilityuniversal.nodes.size(); ix1++) {
			cpbRunv = cpb->imeirmcapabilityuniversal.nodes[ix1];
			if (cpbRunv->ref != 0) dbswznm->tblwznmrmcapabilityuniversal->removeRecByRef(cpbRunv->ref);
		};
	};

	// -- ImeIMJob
	for (unsigned int ix0 = 0; ix0 < imeimjob.nodes.size(); ix0++) {
		job = imeimjob.nodes[ix0];
		if (job->ref != 0) dbswznm->tblwznmmjob->removeRecByRef(job->ref);

		for (unsigned int ix1 = 0; ix1 < job->imeimblock.nodes.size(); ix1++) {
			blk = job->imeimblock.nodes[ix1];
			if (blk->ref != 0) dbswznm->tblwznmmblock->removeRecByRef(blk->ref);

			for (unsigned int ix2 = 0; ix2 < blk->imeiamblockitem.nodes.size(); ix2++) {
				blkAitm = blk->imeiamblockitem.nodes[ix2];
				if (blkAitm->ref != 0) dbswznm->tblwznmamblockitem->removeRecByRef(blkAitm->ref);

				for (unsigned int ix3 = 0; ix3 < blkAitm->imeijamblockitem.nodes.size(); ix3++) {
					bitJ = blkAitm->imeijamblockitem.nodes[ix3];
					if (bitJ->ref != 0) dbswznm->tblwznmjamblockitem->removeRecByRef(bitJ->ref);
				};
			};

		};
	};

	return retval;
};

void JobWznmIexJob::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexJob::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMCapability* cpb = NULL;
	ImeitemIMJob* job = NULL;
	ImeitemIMBlock* blk = NULL;
	ImeitemIRMCapabilityUniversal* cpbRunv = NULL;
	ImeitemIAMBlockItem* blkAitm = NULL;
	ImeitemICAMBlockItem* blkAitmC = NULL;
	ImeitemIJAMBlockItem* bitJ = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMCapability
	for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
		cpb = imeimcapability.nodes[ix0];

		if (cpb->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMCAPABILITYUNIVERSAL, ixWznmVIop)) {
			dbswznm->tblwznmrmcapabilityuniversal->loadRefsByCpb(cpb->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cpb->imeirmcapabilityuniversal.nodes.push_back(new ImeitemIRMCapabilityUniversal(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeirmcapabilityuniversal.nodes.size(); ix1++) {
			cpbRunv = cpb->imeirmcapabilityuniversal.nodes[ix1];

			if (cpbRunv->ref != 0) {
				//cpbRunv->srefUnvUref: STUB
			};
		};
	};

	// -- ImeIMJob
	for (unsigned int ix0 = 0; ix0 < imeimjob.nodes.size(); ix0++) {
		job = imeimjob.nodes[ix0];

		if (job->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMBLOCK, ixWznmVIop)) {
			dbswznm->tblwznmmblock->loadRefsByRetReu(VecWznmVMBlockRefTbl::JOB, job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeimblock.nodes.push_back(new ImeitemIMBlock(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimblock.nodes.size(); ix1++) {
			blk = job->imeimblock.nodes[ix1];

			if (blk->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMBLOCKITEM, ixWznmVIop)) {
				dbswznm->tblwznmamblockitem->loadRefsByBlk(blk->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) blk->imeiamblockitem.nodes.push_back(new ImeitemIAMBlockItem(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < blk->imeiamblockitem.nodes.size(); ix2++) {
				blkAitm = blk->imeiamblockitem.nodes[ix2];

				if (blkAitm->ref != 0) {
					//blkAitm->irefRefWznmCAMBlockItem: IREF
					blkAitm->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, blkAitm->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					//blkAitm->srefRefWznmMVectoritem: STUB
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAMBLOCKITEM, ixWznmVIop)) {
					dbswznm->tblwznmjamblockitem->loadRefsByBit(blkAitm->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) blkAitm->imeijamblockitem.nodes.push_back(new ImeitemIJAMBlockItem(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < blkAitm->imeijamblockitem.nodes.size(); ix3++) {
					bitJ = blkAitm->imeijamblockitem.nodes[ix3];

					if (bitJ->ref != 0) {
						bitJ->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, bitJ->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};

			for (unsigned int ix2 = 0; ix2 < blk->imeicamblockitem.nodes.size(); ix2++) {
				blkAitmC = blk->imeicamblockitem.nodes[ix2];

				if (blkAitmC->ref != 0) {
					blkAitmC->iref = ix2+1;
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexJob::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexJob::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexJob::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexJob::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmJob::exportToFile(fullpath, xmlNotTxt, shorttags, imeimcapability, imeimjob);

	return retval;
};

void JobWznmIexJob::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexJob::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexJob::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


