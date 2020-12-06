/**
	* \file JobWznmIexJtr.cpp
	* job handler for job JobWznmIexJtr (implementation)
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

#include "JobWznmIexJtr.h"

#include "JobWznmIexJtr_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmJtr;

/******************************************************************************
 class JobWznmIexJtr
 ******************************************************************************/

JobWznmIexJtr::JobWznmIexJtr(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXJTR, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexJtr::~JobWznmIexJtr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexJtr::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexJtr::parseFromFile(
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

void JobWznmIexJtr::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexJtr::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexJtr::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexJtr::exportToFile(
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

void JobWznmIexJtr::handleRequest(
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

void JobWznmIexJtr::changeStage(
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

string JobWznmIexJtr::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing custom job tree features";
			else if (ixVSge == VecVSge::PRSDONE) retval = "custom job tree features parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing custom job tree features (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing custom job tree features import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting custom job tree features for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "custom job tree features collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting custom job tree features";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexJtr::enterSgeIdle(
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

	imeimblock2.clear();
	imeimcall.clear();
	imeimjob.clear();
	imeirmcallmstub.clear();

	return retval;
};

void JobWznmIexJtr::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexJtr::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmJtr::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimblock2, imeimcall, imeimjob, imeirmcallmstub);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexJtr::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexJtr::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexJtr::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexJtr::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexJtr::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexJtr::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMBlock2* blk2 = NULL;
	ImeitemIMCall* cal = NULL;
	ImeitemIMJob* job = NULL;
	ImeitemIRMCallMStub* calRstb = NULL;
	ImeitemIAMBlockItem2* blkAitm2 = NULL;
	ImeitemIAMJobCmd* jobAcmd = NULL;
	ImeitemIAMJobVar* jobAvar = NULL;
	ImeitemICAMBlockItem2* blkAitmC2 = NULL;
	ImeitemICAMJobVar* jobAvarC = NULL;
	ImeitemIMBlock1* blk1 = NULL;
	ImeitemIMMethod* mtd = NULL;
	ImeitemIMSensitivity1* sns1 = NULL;
	ImeitemIMStage* sge = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIRMJobMJob* jobRjob = NULL;
	ImeitemIRMJobMOp* jobRopx = NULL;
	ImeitemIRMJobMOppack* jobRopk = NULL;
	ImeitemIAMBlockItem1* blkAitm1 = NULL;
	ImeitemIAMMethodInvpar* mtdAipa = NULL;
	ImeitemIAMMethodRetpar* mtdArpa = NULL;
	ImeitemICAMBlockItem1* blkAitmC1 = NULL;
	ImeitemIJAMBlockItem2* bitJ2 = NULL;
	ImeitemIMSensitivity2* sns2 = NULL;
	ImeitemIMSquawk* sqk = NULL;
	ImeitemIMVectoritem* vit = NULL;
	ImeitemIJAMBlockItem1* bitJ1 = NULL;
	ImeitemIJMSquawkTitle* sqkJtit = NULL;
	ImeitemIJMVectoritem* vitJ = NULL;
	ImeitemIRMSquawkMStub* sqkRstb = NULL;

	set<ubigint> irefs1, irefs2;

	uint num1, num2;

	// IP enterSgeImport.prep --- IBEGIN
	vector<ubigint> refs;

	WznmMJob* job2 = NULL;

	WznmMBlock* blk3 = NULL;

	WznmAMBlockItem* blkAitm3 = NULL;
	WznmJAMBlockItem* bitJ3 = NULL;

	WznmMVector* vec2 = NULL;

	WznmMStage* sge2 = NULL;
	ImeitemIMStage* sge3 = NULL;

	uint bitcnt;

	uint sgecnt;

	ubigint refWznmMVersion;
	string preflcl;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	Wznm::getVerlclsref(dbswznm, refWznmMVersion, preflcl);

	ListWznmMStub stbs;
	dbswznm->loadRefsBySQL("SELECT TblWznmMStub.ref FROM TblWznmMTable, TblWznmMStub WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	dbswznm->tblwznmmstub->loadRstByRefs(refs, false, stbs);

	ListWznmMLocale lcls;
	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMJob
		for (unsigned int ix0 = 0; ix0 < imeimjob.nodes.size(); ix0++) {
			job = imeimjob.nodes[ix0];

			// retrieve
			if (dbswznm->tblwznmmjob->loadRecBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + job->sref + "'", &job2)) {
				job->ref = job2->ref;
				job->ixVBasetype = job2->ixVBasetype;
				job->refIxVTbl = job2->refIxVTbl;
				job->refUref = job2->refUref;
				job->Clisrv = job2->Clisrv;
				job->Shrdat = job2->Shrdat;
				job->Comment = job2->Comment;

				delete job2;
			} else  throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMJob"}, {"lineno",to_string(job->lineno)}});

			for (unsigned int ix1 = 0; ix1 < job->imeimvector.nodes.size(); ix1++) {
				vec = job->imeimvector.nodes[ix1];

				vec->ixWznmVIop = VecWznmVIop::getIx(vec->srefIxWznmVIop);
				if ((vec->ixWznmVIop != VecWznmVIop::INS) && (vec->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",vec->srefIxWznmVIop}, {"ime","ImeIMVector"}, {"lineno",to_string(vec->lineno)}});

				if (vec->ixWznmVIop == VecWznmVIop::INS) {
					vec->ixVBasetype = VecWznmVMVectorBasetype::getIx(vec->srefIxVBasetype);
					if (vec->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec->lineno)}});
					//vec->refWznmMVersion: PRESET
					vec->refWznmMVersion = refWznmMVersion;
					vec->hkIxVTbl = VecWznmVMVectorHkTbl::JOB;
					vec->hkUref = job->ref;
					//vec->sref: TBL
					//vec->osrefWznmKTaggrp: TBL
					//vec->srefsKOption: TBL

					dbswznm->tblwznmmvector->insertRec(vec);
					impcnt++;

				} else if (vec->ixWznmVIop == VecWznmVIop::RETRUPD) {
					// retrieve
					if (dbswznm->tblwznmmvector->loadRecBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND sref = '" + vec->sref + "'", &vec2)) {
						vec->ref = vec2->ref;
						vec->ixVBasetype = vec2->ixVBasetype;
						vec->refWznmMVersion = vec2->refWznmMVersion;
						vec->hkIxVTbl = vec2->hkIxVTbl;
						vec->hkUref = job->ref; // update
						vec->osrefWznmKTaggrp = vec2->osrefWznmKTaggrp;
						vec->srefsKOption = vec2->srefsKOption;

						delete vec2;

						dbswznm->tblwznmmvector->updateRec(vec);
					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMVector"}, {"lineno",to_string(vec->lineno)}});
				};

				for (unsigned int ix2 = 0; ix2 < vec->imeimvectoritem.nodes.size(); ix2++) {
					vit = vec->imeimvectoritem.nodes[ix2];

					vit->vecRefWznmMVector = vec->ref;
					vit->vecNum = (ix2+1); // TBD
					//vit->sref: TBL
					//vit->refJ: SUB
					//vit->Title: TBL
					//vit->Comment: TBL

					dbswznm->tblwznmmvectoritem->insertRec(vit);
					impcnt++;

					if (((vit->Title != "") || (vit->Comment != "")) && vit->imeijmvectoritem.nodes.empty()) {
						vitJ = new ImeitemIJMVectoritem();
						vit->imeijmvectoritem.nodes.push_back(vitJ);

						vitJ->refWznmMVectoritem = vit->ref;
						vitJ->Title = vit->Title;
						vitJ->Comment = vit->Comment;
					};

					for (unsigned int ix3 = 0; ix3 < vit->imeijmvectoritem.nodes.size(); ix3++) {
						vitJ = vit->imeijmvectoritem.nodes[ix3];

						vitJ->refWznmMVectoritem = vit->ref;
						//if (vitJ->srefX1RefWznmMLocale == "") vitJ->srefX1RefWznmMLocale: CUSTOM DEFVAL
						if (vitJ->srefX1RefWznmMLocale == "") vitJ->srefX1RefWznmMLocale = preflcl;
						//vitJ->x1RefWznmMLocale: RST
						for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
							if (lcls.nodes[i]->sref.compare(vitJ->srefX1RefWznmMLocale) == 0) {
								vitJ->x1RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						};
						if (vitJ->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",vitJ->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(vitJ->lineno)}});
						//vitJ->Title: TBL
						//vitJ->Comment: TBL

						dbswznm->tblwznmjmvectoritem->insertRec(vitJ);
						impcnt++;

						if (ix3 == 0) {
							vit->refJ = vitJ->ref;
							vit->Title = vitJ->Title;
							vit->Comment = vitJ->Comment;
							dbswznm->tblwznmmvectoritem->updateRec(vit);
						};
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < job->imeimblock1.nodes.size(); ix1++) {
				blk1 = job->imeimblock1.nodes[ix1];

				blk1->ixWznmVIop = VecWznmVIop::getIx(blk1->srefIxWznmVIop);
				if ((blk1->ixWznmVIop != VecWznmVIop::INS) && (blk1->ixWznmVIop != VecWznmVIop::RETR) && (blk1->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",blk1->srefIxWznmVIop}, {"ime","ImeIMBlock1"}, {"lineno",to_string(blk1->lineno)}});

				if ((blk1->ixWznmVIop == VecWznmVIop::INS) || (blk1->ixWznmVIop == VecWznmVIop::RETRUPD)) {
					blk1->ixVBasetype = VecWznmVMBlockBasetype::getIx(blk1->srefIxVBasetype);
					if (blk1->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blk1->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(blk1->lineno)}});
					//blk1->refWznmMVersion: PRESET
					blk1->refWznmMVersion = refWznmMVersion;
					blk1->refIxVTbl = VecWznmVMBlockRefTbl::JOB;
					blk1->refUref = job->ref;
					blk1->reaIxWznmWScope = VecWznmWScope::getIx(blk1->srefsReaIxWznmWScope);
					blk1->wriIxWznmWScope = VecWznmWScope::getIx(blk1->srefsWriIxWznmWScope);
					//blk1->sref: TBL
					//blk1->Comment: TBL
				};

				if ((blk1->ixWznmVIop == VecWznmVIop::RETR) || (blk1->ixWznmVIop == VecWznmVIop::RETRUPD)) {
					// retrieve
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
								+ " AND sref = '" + blk1->sref + "'", blk1->ref);

					if (blk1->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMBlock1"}, {"lineno",to_string(blk1->lineno)}});
				};

				if (blk1->ixWznmVIop == VecWznmVIop::INS) {
					dbswznm->tblwznmmblock->insertRec(blk1);
					impcnt++;

				} else if ((blk1->ixWznmVIop == VecWznmVIop::RETR) && (blk1->ref != 0)) {
					// initialize blkNum for block items so that block items are appended
					dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blk1->ref), bitcnt);

				} else if ((blk1->ixWznmVIop == VecWznmVIop::RETRUPD) && (blk1->ref != 0)) {
					// clear block items
					dbswznm->executeQuery("DELETE FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blk1->ref));
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < blk1->imeicamblockitem1.nodes.size(); ix2++) {
					blkAitmC1 = blk1->imeicamblockitem1.nodes[ix2];

					if (irefs2.find(blkAitmC1->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(blkAitmC1->iref)}, {"ime","ImeICAMBlockItem1"}, {"lineno",to_string(blkAitmC1->lineno)}});
					blkAitmC1->ref = dbswznm->tblwznmcamblockitem->getNewRef();
					irefs2.insert(blkAitmC1->iref);

					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < blk1->imeiamblockitem1.nodes.size(); ix2++) {
					blkAitm1 = blk1->imeiamblockitem1.nodes[ix2];

					blkAitm1->ixWznmVIop = VecWznmVIop::getIx(blkAitm1->srefIxWznmVIop);
					if ((blkAitm1->ixWznmVIop != VecWznmVIop::INS) && (blkAitm1->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",blkAitm1->srefIxWznmVIop}, {"ime","ImeIAMBlockItem1"}, {"lineno",to_string(blkAitm1->lineno)}});

					//blkAitm1->refWznmCAMBlockItem: PREVIMP
					if (blkAitm1->irefRefWznmCAMBlockItem != 0) {
						for (unsigned int i = 0; i < blk1->imeicamblockitem1.nodes.size(); i++)
							if (blk1->imeicamblockitem1.nodes[i]->iref == blkAitm1->irefRefWznmCAMBlockItem) {
								blkAitm1->refWznmCAMBlockItem = blk1->imeicamblockitem1.nodes[i]->ref;
								break;
							};
						if (blkAitm1->refWznmCAMBlockItem == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(blkAitm1->irefRefWznmCAMBlockItem)}, {"iel","irefRefWznmCAMBlockItem"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					blkAitm1->blkRefWznmMBlock = blk1->ref;
					//blkAitm1->blkNum: CUST
					if (blkAitm1->ixWznmVIop == VecWznmVIop::INS) {
						if (blk1->ixWznmVIop == VecWznmVIop::RETR) {
							blkAitm1->blkNum = (bitcnt++)+1;
						} else {
							blkAitm1->blkNum = (ix2+1);
						};
					};

					if ((blkAitm1->ixWznmVIop == VecWznmVIop::INS) || (blkAitm1->srefIxVBasetype != "")) {
						blkAitm1->ixVBasetype = VecWznmVAMBlockItemBasetype::getIx(blkAitm1->srefIxVBasetype);
						if (blkAitm1->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm1->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->sref: TBL
					if ((blkAitm1->ixWznmVIop == VecWznmVIop::INS) || (blkAitm1->srefIxWznmVVartype != "")) {
						blkAitm1->ixWznmVVartype = VecWznmVVartype::getIx(blkAitm1->srefIxWznmVVartype);
						if (blkAitm1->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm1->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->refWznmMControl: CUSTSQL
					if ((blkAitm1->ixVBasetype == VecWznmVAMBlockItemBasetype::CONPAR) || (blkAitm1->ixVBasetype == VecWznmVAMBlockItemBasetype::CONTIT)) {
						if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + blkAitm1->srefRefWznmMControl + "'", blkAitm1->refWznmMControl);
						} else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + blkAitm1->srefRefWznmMControl + "'", blkAitm1->refWznmMControl);
						} else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + blkAitm1->srefRefWznmMControl + "'", blkAitm1->refWznmMControl);
						};
						if (blkAitm1->refWznmMControl == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMControl}, {"iel","srefRefWznmMControl"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->refWznmMVector: CUSTSQL
					if (blkAitm1->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, blkAitm1->srefRefWznmMVector, blkAitm1->refWznmMVector);
						if (blkAitm1->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->refWznmMFeed: CUSTSQL
					if (blkAitm1->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
						// require a feed that corresponds to a card/dialog/panel control
						if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) {
							dbswznm->loadRefBySQL("SELECT TblWznmMFeed.ref FROM TblWznmMFeed, TblWznmMControl WHERE TblWznmMFeed.refWznmMControl = TblWznmMControl.ref AND TblWznmMControl.hkIxVTbl = "
										+ to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(job->refUref) + " AND TblWznmMFeed.sref = '" + blkAitm1->srefRefWznmMFeed + "'", blkAitm1->refWznmMFeed);
						} else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) {
							dbswznm->loadRefBySQL("SELECT TblWznmMFeed.ref FROM TblWznmMFeed, TblWznmMControl WHERE TblWznmMFeed.refWznmMControl = TblWznmMControl.ref AND TblWznmMControl.hkIxVTbl = "
										+ to_string(VecWznmVMControlHkTbl::DLG) + " AND TblWznmMControl.hkUref = " + to_string(job->refUref) + " AND TblWznmMFeed.sref = '" + blkAitm1->srefRefWznmMFeed + "'", blkAitm1->refWznmMFeed);
						} else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) {
							dbswznm->loadRefBySQL("SELECT TblWznmMFeed.ref FROM TblWznmMFeed, TblWznmMControl WHERE TblWznmMFeed.refWznmMControl = TblWznmMControl.ref AND TblWznmMControl.hkIxVTbl = "
										+ to_string(VecWznmVMControlHkTbl::PNL) + " AND TblWznmMControl.hkUref = " + to_string(job->refUref) + " AND TblWznmMFeed.sref = '" + blkAitm1->srefRefWznmMFeed + "'", blkAitm1->refWznmMFeed);
						};
						if (blkAitm1->refWznmMFeed == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMFeed}, {"iel","srefRefWznmMFeed"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->refWznmMTable: CUSTSQL
					if (blkAitm1->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + blkAitm1->srefRefWznmMTable + "'", blkAitm1->refWznmMTable);
						if (blkAitm1->refWznmMTable == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMTable}, {"iel","srefRefWznmMTable"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->refWznmMBlock: CUSTSQLPP
					//blkAitm1->refJ: SUB
					//blkAitm1->Defval: TBL
					//blkAitm1->refWznmMVectoritem: CUSTSQL
					if ((blkAitm1->refWznmMVector != 0) && (blkAitm1->srefRefWznmMVectoritem != "")) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm1->refWznmMVector) + " AND sref = '" + blkAitm1->srefRefWznmMVectoritem + "'", blkAitm1->refWznmMVectoritem);
						if (blkAitm1->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->Comment: TBL

					if (blkAitm1->ixWznmVIop == VecWznmVIop::INS) {
						dbswznm->tblwznmamblockitem->insertRec(blkAitm1);
						impcnt++;

						if (((blkAitm1->Defval != "") || (blkAitm1->srefRefWznmMVectoritem != "")) && blkAitm1->imeijamblockitem1.nodes.empty()) {
							bitJ1 = new ImeitemIJAMBlockItem1();
							blkAitm1->imeijamblockitem1.nodes.push_back(bitJ1);

							bitJ1->refWznmAMBlockItem = blkAitm1->ref;
							bitJ1->Defval = blkAitm1->Defval;
							bitJ1->srefRefWznmMVectoritem = blkAitm1->srefRefWznmMVectoritem;
						};

					} else if (blkAitm1->ixWznmVIop == VecWznmVIop::RETRUPD) {
						if (dbswznm->tblwznmamblockitem->loadRecBySQL("SELECT * FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blk1->ref) + " AND sref = '" + blkAitm1->sref + "'", &blkAitm3)) {
							blkAitm1->ref = blkAitm3->ref;
							//blkAitm1->blkRefWznmMBlock = ;
							blkAitm1->blkNum = blkAitm3->blkNum;
							blkAitm1->ixVBasetype = blkAitm3->ixVBasetype;
							//blkAitm1->sref = ;
							blkAitm1->ixWznmVVartype = blkAitm3->ixWznmVVartype;
							blkAitm1->refWznmMControl = blkAitm3->refWznmMControl;
							blkAitm1->refWznmMVector = blkAitm3->refWznmMVector;
							blkAitm1->refWznmMFeed = blkAitm3->refWznmMFeed;
							blkAitm1->refWznmMTable = blkAitm3->refWznmMTable;
							blkAitm1->refWznmMBlock = blkAitm3->refWznmMBlock;
							blkAitm1->refJ = blkAitm3->refJ;
							//blkAitm1->Defval = ; // update
							//blkAitm1->refWznmMVectoritem = ; // update
							blkAitm1->Comment = blkAitm3->Comment;

							dbswznm->tblwznmamblockitem->updateRec(blkAitm1);

							if (dbswznm->tblwznmjamblockitem->loadRecByRef(blkAitm1->refJ, &bitJ3)) {
								bitJ3->Defval = blkAitm1->Defval;
								bitJ3->refWznmMVectoritem = blkAitm1->refWznmMVectoritem;

								dbswznm->tblwznmjamblockitem->updateRec(bitJ3);

								delete bitJ3;
							};

							delete blkAitm3;
						} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIAMBlockItem1"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < job->imeimsensitivity1.nodes.size(); ix1++) {
				sns1 = job->imeimsensitivity1.nodes[ix1];

				sns1->ixVBasetype = VecWznmVMSensitivityBasetype::getIx(sns1->srefIxVBasetype);
				if (sns1->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns1->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(sns1->lineno)}});
				sns1->refWznmMJob = job->ref;
				//sns1->refWznmMCall: IMPPP
				sns1->ixVJactype = VecWznmVMSensitivityJactype::getIx(sns1->srefIxVJactype);
				if (sns1->ixVJactype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns1->srefIxVJactype}, {"iel","srefIxVJactype"}, {"lineno",to_string(sns1->lineno)}});
				sns1->ixVJobmask = VecWznmVMSensitivityJobmask::getIx(sns1->srefIxVJobmask);
				if (sns1->ixVJobmask == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns1->srefIxVJobmask}, {"iel","srefIxVJobmask"}, {"lineno",to_string(sns1->lineno)}});
				//sns1->Jobshort: TBL
				//sns1->Argpatt: TBL
				//sns1->refWznmMControl: CUSTSQL
				if (sns1->srefRefWznmMControl != "") {
					if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + sns1->srefRefWznmMControl + "'", sns1->refWznmMControl);
					} else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + sns1->srefRefWznmMControl + "'", sns1->refWznmMControl);
					} else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + sns1->srefRefWznmMControl + "'", sns1->refWznmMControl);
					};
					if (sns1->refWznmMControl == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns1->srefRefWznmMControl}, {"iel","srefRefWznmMControl"}, {"lineno",to_string(sns1->lineno)}});
				};
				//sns1->srefTimer: TBL
				sns1->ixVAction = VecWznmVMSensitivityAction::getIx(sns1->srefIxVAction);
				if (sns1->ixVAction == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns1->srefIxVAction}, {"iel","srefIxVAction"}, {"lineno",to_string(sns1->lineno)}});
				//sns1->csgRefWznmMStage: IMPPP
				//sns1->Custcode: TBL

				dbswznm->tblwznmmsensitivity->insertRec(sns1);
				impcnt++;
			};

			// initialize jobNum for stages so that stages are appended
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref), sgecnt);

			for (unsigned int ix1 = 0; ix1 < job->imeimstage.nodes.size(); ix1++) {
				sge = job->imeimstage.nodes[ix1];

				if (dbswznm->tblwznmmstage->loadRecBySQL("SELECT * FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref) + " AND sref = '" + sge->sref + "'", &sge2)) {
					// retrieve and update
					sge->ref = sge2->ref;
					sge->ixVBasetype = sge2->ixVBasetype;
					sge->jobRefWznmMJob = sge2->jobRefWznmMJob;
					sge->jobNum = sge2->jobNum;
					sge->refWznmMSquawk = sge2->refWznmMSquawk;
					//sge->sref
					if (sge->Monitvl == 0) sge->Monitvl = sge2->Monitvl;
					//sge->snxRefWznmMStage: CUSTSQLPP
					//sge->fnxRefWznmMStage: CUSTSQLPP
					//sge->enxRefWznmMStage: CUSTSQLPP
					if (sge->Comment == "") sge->Comment = sge2->Comment;

					delete sge2;

					dbswznm->tblwznmmstage->updateRec(sge);

				} else {
					// insert
					sge->ixVBasetype = VecWznmVMStageBasetype::getIx(sge->srefIxVBasetype);
					if (sge->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sge->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(sge->lineno)}});
					sge->jobRefWznmMJob = job->ref;
					sge->jobNum = (sgecnt++)+1;
					//sge->refWznmMSquawk: SUB
					//sge->sref: TBL
					//sge->Monitvl: TBL
					//sge->snxSrefWznmMStage: TBL
					//sge->fnxSrefWznmMStage: TBL
					//sge->enxSrefWznmMStage: TBL
					//sge->Comment: TBL

					dbswznm->tblwznmmstage->insertRec(sge);
					impcnt++;
				};


				for (unsigned int ix2 = 0; ix2 < sge->imeimsquawk.nodes.size(); ix2++) {
					sqk = sge->imeimsquawk.nodes[ix2];

					sqk->refIxVTbl = VecWznmVMSquawkRefTbl::SGE;
					sqk->refUref = sge->ref;
					//sqk->refJTitle: SUB
					//sqk->Title: TBL
					//sqk->Example: TBL

					dbswznm->tblwznmmsquawk->insertRec(sqk);
					impcnt++;

					if (((sqk->Title != "")) && sqk->imeijmsquawktitle.nodes.empty()) {
						sqkJtit = new ImeitemIJMSquawkTitle();
						sqk->imeijmsquawktitle.nodes.push_back(sqkJtit);

						sqkJtit->refWznmMSquawk = sqk->ref;
						sqkJtit->Title = sqk->Title;
					};

					if (ix2 == 0) {
						sge->refWznmMSquawk = sqk->ref;
						dbswznm->tblwznmmstage->updateRec(sge);
					};

					for (unsigned int ix3 = 0; ix3 < sqk->imeijmsquawktitle.nodes.size(); ix3++) {
						sqkJtit = sqk->imeijmsquawktitle.nodes[ix3];

						sqkJtit->refWznmMSquawk = sqk->ref;
						//if (sqkJtit->srefX1RefWznmMLocale == "") sqkJtit->srefX1RefWznmMLocale: CUSTOM DEFVAL
						if (sqkJtit->srefX1RefWznmMLocale == "") sqkJtit->srefX1RefWznmMLocale = preflcl;
						//sqkJtit->x1RefWznmMLocale: RST
						for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
							if (lcls.nodes[i]->sref.compare(sqkJtit->srefX1RefWznmMLocale) == 0) {
								sqkJtit->x1RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						};
						if (sqkJtit->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sqkJtit->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(sqkJtit->lineno)}});
						//sqkJtit->Title: TBL

						dbswznm->tblwznmjmsquawktitle->insertRec(sqkJtit);
						impcnt++;

						if (ix3 == 0) {
							sqk->refJTitle = sqkJtit->ref;
							sqk->Title = sqkJtit->Title;
							dbswznm->tblwznmmsquawk->updateRec(sqk);
						};
					};

					for (unsigned int ix3 = 0; ix3 < sqk->imeirmsquawkmstub.nodes.size(); ix3++) {
						sqkRstb = sqk->imeirmsquawkmstub.nodes[ix3];

						sqkRstb->refWznmMSquawk = sqk->ref;
						//sqkRstb->refWznmMStub: RST
						for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
							if (stbs.nodes[i]->sref.compare(sqkRstb->srefRefWznmMStub) == 0) {
								sqkRstb->refWznmMStub = stbs.nodes[i]->ref;
								break;
							};
						};
						if (sqkRstb->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sqkRstb->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(sqkRstb->lineno)}});

						dbswznm->tblwznmrmsquawkmstub->insertRec(sqkRstb);
						impcnt++;
					};
				};

				for (unsigned int ix2 = 0; ix2 < sge->imeimsensitivity2.nodes.size(); ix2++) {
					sns2 = sge->imeimsensitivity2.nodes[ix2];

					sns2->ixVBasetype = VecWznmVMSensitivityBasetype::getIx(sns2->srefIxVBasetype);
					if (sns2->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns2->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(sns2->lineno)}});
					sns2->refWznmMJob = job->ref;
					sns2->refWznmMStage = sge->ref;
					//sns2->refWznmMCall: IMPPP
					sns2->ixVJactype = VecWznmVMSensitivityJactype::getIx(sns2->srefIxVJactype);
					if (sns2->ixVJactype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns2->srefIxVJactype}, {"iel","srefIxVJactype"}, {"lineno",to_string(sns2->lineno)}});
					sns2->ixVJobmask = VecWznmVMSensitivityJobmask::getIx(sns2->srefIxVJobmask);
					if (sns2->ixVJobmask == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns2->srefIxVJobmask}, {"iel","srefIxVJobmask"}, {"lineno",to_string(sns2->lineno)}});
					//sns2->Jobshort: TBL
					//sns2->Argpatt: TBL
					//sns2->refWznmMControl: CUSTSQL
					if (sns2->srefRefWznmMControl != "") {
						if (job->refIxVTbl == VecWznmVMJobRefTbl::CAR) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + sns2->srefRefWznmMControl + "'", sns2->refWznmMControl);
						} else if (job->refIxVTbl == VecWznmVMJobRefTbl::DLG) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + sns2->srefRefWznmMControl + "'", sns2->refWznmMControl);
						} else if (job->refIxVTbl == VecWznmVMJobRefTbl::PNL) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(job->refUref) + " AND sref = '" + sns2->srefRefWznmMControl + "'", sns2->refWznmMControl);
						};
						if (sns2->refWznmMControl == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns2->srefRefWznmMControl}, {"iel","srefRefWznmMControl"}, {"lineno",to_string(sns2->lineno)}});
					};
					//sns2->srefTimer: TBL
					sns2->ixVAction = VecWznmVMSensitivityAction::getIx(sns2->srefIxVAction);
					if (sns2->ixVAction == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sns2->srefIxVAction}, {"iel","srefIxVAction"}, {"lineno",to_string(sns2->lineno)}});
					//sns2->csgRefWznmMStage: IMPPP
					//sns2->Custcode: TBL

					dbswznm->tblwznmmsensitivity->insertRec(sns2);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < job->imeiamjobcmd.nodes.size(); ix1++) {
				jobAcmd = job->imeiamjobcmd.nodes[ix1];

				jobAcmd->refWznmMJob = job->ref;
				//jobAcmd->sref: TBL
				//jobAcmd->Comment: TBL

				dbswznm->tblwznmamjobcmd->insertRec(jobAcmd);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < job->imeimmethod.nodes.size(); ix1++) {
				mtd = job->imeimmethod.nodes[ix1];

				mtd->refWznmMJob = job->ref;
				//mtd->sref: TBL
				//mtd->Execmast: TBL
				//mtd->Comment: TBL

				dbswznm->tblwznmmmethod->insertRec(mtd);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < mtd->imeiammethodinvpar.nodes.size(); ix2++) {
					mtdAipa = mtd->imeiammethodinvpar.nodes[ix2];

					mtdAipa->mtdRefWznmMMethod = mtd->ref;
					mtdAipa->mtdNum = (ix2+1); // TBD
					//mtdAipa->sref: TBL
					mtdAipa->ixWznmVVartype = VecWznmVVartype::getIx(mtdAipa->srefIxWznmVVartype);
					if (mtdAipa->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",mtdAipa->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(mtdAipa->lineno)}});
					//mtdAipa->refWznmMVector: CUSTSQL
					if (mtdAipa->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, mtdAipa->srefRefWznmMVector, mtdAipa->refWznmMVector);
						if (mtdAipa->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",mtdAipa->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(mtdAipa->lineno)}});
					};
					//mtdAipa->Length: TBL
					//mtdAipa->Comment: TBL

					dbswznm->tblwznmammethodinvpar->insertRec(mtdAipa);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < mtd->imeiammethodretpar.nodes.size(); ix2++) {
					mtdArpa = mtd->imeiammethodretpar.nodes[ix2];

					mtdArpa->mtdRefWznmMMethod = mtd->ref;
					mtdArpa->mtdNum = (ix2+1); // TBD
					//mtdArpa->sref: TBL
					mtdArpa->ixWznmVVartype = VecWznmVVartype::getIx(mtdArpa->srefIxWznmVVartype);
					if (mtdArpa->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",mtdArpa->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(mtdArpa->lineno)}});
					//mtdArpa->refWznmMVector: CUSTSQL
					if (mtdArpa->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, mtdArpa->srefRefWznmMVector, mtdArpa->refWznmMVector);
						if (mtdArpa->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",mtdArpa->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(mtdArpa->lineno)}});
					};
					//mtdArpa->Length: TBL
					//mtdArpa->Comment: TBL

					dbswznm->tblwznmammethodretpar->insertRec(mtdArpa);
					impcnt++;
				};
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < job->imeicamjobvar.nodes.size(); ix1++) {
				jobAvarC = job->imeicamjobvar.nodes[ix1];

				if (irefs1.find(jobAvarC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(jobAvarC->iref)}, {"ime","ImeICAMJobVar"}, {"lineno",to_string(jobAvarC->lineno)}});
				jobAvarC->ref = dbswznm->tblwznmcamjobvar->getNewRef();
				irefs1.insert(jobAvarC->iref);

				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < job->imeiamjobvar.nodes.size(); ix1++) {
				jobAvar = job->imeiamjobvar.nodes[ix1];

				//jobAvar->refWznmCAMJobVar: PREVIMP
				if (jobAvar->irefRefWznmCAMJobVar != 0) {
					for (unsigned int i = 0; i < job->imeicamjobvar.nodes.size(); i++)
						if (job->imeicamjobvar.nodes[i]->iref == jobAvar->irefRefWznmCAMJobVar) {
							jobAvar->refWznmCAMJobVar = job->imeicamjobvar.nodes[i]->ref;
							break;
						};
					if (jobAvar->refWznmCAMJobVar == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(jobAvar->irefRefWznmCAMJobVar)}, {"iel","irefRefWznmCAMJobVar"}, {"lineno",to_string(jobAvar->lineno)}});
				};
				jobAvar->jobRefWznmMJob = job->ref;
				jobAvar->jobNum = (ix1+1); // TBD
				//jobAvar->sref: TBL
				jobAvar->ixWznmVVartype = VecWznmVVartype::getIx(jobAvar->srefIxWznmVVartype);
				if (jobAvar->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",jobAvar->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(jobAvar->lineno)}});
				if (jobAvar->ixWznmVVartype == VecWznmVVartype::VECSREF) {
					//jobAvar->refWznmMVector: CUSTSQL
					dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, jobAvar->srefRefWznmMVector, jobAvar->refWznmMVector);
					if (jobAvar->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",jobAvar->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(jobAvar->lineno)}});
				};
				//jobAvar->Length: TBL
				//jobAvar->Shr: TBL
				//jobAvar->Comment: TBL

				dbswznm->tblwznmamjobvar->insertRec(jobAvar);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < job->imeirmjobmjob.nodes.size(); ix1++) {
				jobRjob = job->imeirmjobmjob.nodes[ix1];

				jobRjob->supRefWznmMJob = job->ref;
				//jobRjob->subRefWznmMJob: CUSTSQL
				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + jobRjob->srefSubRefWznmMJob + "'", jobRjob->subRefWznmMJob);
				if (jobRjob->subRefWznmMJob == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",jobRjob->srefSubRefWznmMJob}, {"iel","srefSubRefWznmMJob"}, {"lineno",to_string(jobRjob->lineno)}});
				//jobRjob->Short: TBL
				//jobRjob->Multi: TBL
				jobRjob->ixVConstract = VecWznmVRMJobMJobConstract::getIx(jobRjob->srefIxVConstract);
				if (jobRjob->ixVConstract == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",jobRjob->srefIxVConstract}, {"iel","srefIxVConstract"}, {"lineno",to_string(jobRjob->lineno)}});

				dbswznm->tblwznmrmjobmjob->insertRec(jobRjob);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < job->imeirmjobmop.nodes.size(); ix1++) {
				jobRopx = job->imeirmjobmop.nodes[ix1];

				jobRopx->refWznmMJob = job->ref;
				//jobRopx->refWznmMOp: CUSTSQL
				dbswznm->loadRefBySQL("SELECT TblWznmMOp.ref FROM TblWznmMOppack, TblWznmMOp WHERE TblWznmMOppack.refWznmMVersion = " + to_string(refWznmMVersion) + " AND TblWznmMOp.refWznmMOppack = TblWznmMOppack.ref AND TblWznmMOp.sref = '" + jobRopx->srefRefWznmMOp + "'", jobRopx->refWznmMOp);
				if (jobRopx->refWznmMOp == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",jobRopx->srefRefWznmMOp}, {"iel","srefRefWznmMOp"}, {"lineno",to_string(jobRopx->lineno)}});

				dbswznm->tblwznmrmjobmop->insertRec(jobRopx);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < job->imeirmjobmoppack.nodes.size(); ix1++) {
				jobRopk = job->imeirmjobmoppack.nodes[ix1];

				jobRopk->refWznmMJob = job->ref;
				//jobRopk->refWznmMOppack: CUSTSQL
				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + jobRopk->srefRefWznmMOppack + "'", jobRopk->refWznmMOppack);
				if (jobRopk->refWznmMOppack == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",jobRopk->srefRefWznmMOppack}, {"iel","srefRefWznmMOppack"}, {"lineno",to_string(jobRopk->lineno)}});

				dbswznm->tblwznmrmjobmoppack->insertRec(jobRopk);
				impcnt++;
			};
		};

		// -- ImeIMCall
		for (unsigned int ix0 = 0; ix0 < imeimcall.nodes.size(); ix0++) {
			cal = imeimcall.nodes[ix0];

			cal->ixVBasetype = VecWznmVMCallBasetype::getIx(cal->srefIxVBasetype);
			if (cal->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cal->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(cal->lineno)}});
			//cal->refWznmMVersion: PRESET
			cal->refWznmMVersion = refWznmMVersion;
			cal->refIxVTbl = VecWznmVMCallRefTbl::VOID;
			cal->invIxWznmWArgtype = VecWznmWArgtype::getIx(cal->srefsInvIxWznmWArgtype);
			cal->retIxWznmWArgtype = VecWznmWArgtype::getIx(cal->srefsRetIxWznmWArgtype);
			//cal->sref: TBL
			//cal->Comment: TBL

			dbswznm->tblwznmmcall->insertRec(cal);
			impcnt++;
		};

		// -- ImeIRMCallMStub
		for (unsigned int ix0 = 0; ix0 < imeirmcallmstub.nodes.size(); ix0++) {
			calRstb = imeirmcallmstub.nodes[ix0];

			//calRstb->refWznmMCall: CUSTSQL
			dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCall WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + calRstb->srefRefWznmMCall + "'", calRstb->refWznmMCall);
			if (calRstb->refWznmMCall == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",calRstb->srefRefWznmMCall}, {"iel","srefRefWznmMCall"}, {"lineno",to_string(calRstb->lineno)}});
			//calRstb->refWznmMStub: CUSTSQL
			dbswznm->loadRefBySQL("SELECT TblWznmMStub.ref FROM TblWznmMStub, TblWznmMTable WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion)
						+ " AND TblWznmMStub.sref = '" + calRstb->srefRefWznmMStub + "'", calRstb->refWznmMStub);
			if (calRstb->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",calRstb->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(calRstb->lineno)}});

			dbswznm->tblwznmrmcallmstub->insertRec(calRstb);
			impcnt++;
		};

		// -- ImeIMBlock2
		for (unsigned int ix0 = 0; ix0 < imeimblock2.nodes.size(); ix0++) {
			blk2 = imeimblock2.nodes[ix0];

			// retrieve
			if (dbswznm->tblwznmmblock->loadRecBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + blk2->sref + "'", &blk3)) {
				blk2->ref = blk3->ref;
				blk2->ixVBasetype = blk3->ixVBasetype;
				blk2->refIxVTbl = blk3->refIxVTbl;
				blk2->refUref = blk3->refUref;
				blk2->reaIxWznmWScope = blk3->reaIxWznmWScope;
				blk2->wriIxWznmWScope = blk3->wriIxWznmWScope;
				blk2->Comment = blk3->Comment;

				delete blk3;
			} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMBlock2"}, {"lineno",to_string(blk2->lineno)}});

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < blk2->imeicamblockitem2.nodes.size(); ix1++) {
				blkAitmC2 = blk2->imeicamblockitem2.nodes[ix1];

				if (irefs1.find(blkAitmC2->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(blkAitmC2->iref)}, {"ime","ImeICAMBlockItem2"}, {"lineno",to_string(blkAitmC2->lineno)}});
				blkAitmC2->ref = dbswznm->tblwznmcamblockitem->getNewRef();
				irefs1.insert(blkAitmC2->iref);

				impcnt++;
			};

			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blk2->ref), bitcnt);

			for (unsigned int ix1 = 0; ix1 < blk2->imeiamblockitem2.nodes.size(); ix1++) {
				blkAitm2 = blk2->imeiamblockitem2.nodes[ix1];

				blkAitm2->ixWznmVIop = VecWznmVIop::getIx(blkAitm2->srefIxWznmVIop);
				if ((blkAitm2->ixWznmVIop != VecWznmVIop::INS) && (blkAitm2->ixWznmVIop != VecWznmVIop::RETR) && (blkAitm2->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",blkAitm2->srefIxWznmVIop}, {"ime","ImeIAMBlockItem2"}, {"lineno",to_string(blkAitm2->lineno)}});

				//blkAitm2->refWznmCAMBlockItem: PREVIMP
				if (blkAitm2->irefRefWznmCAMBlockItem != 0) {
					for (unsigned int i = 0; i < blk2->imeicamblockitem2.nodes.size(); i++)
						if (blk2->imeicamblockitem2.nodes[i]->iref == blkAitm2->irefRefWznmCAMBlockItem) {
							blkAitm2->refWznmCAMBlockItem = blk2->imeicamblockitem2.nodes[i]->ref;
							break;
						};
					if (blkAitm2->refWznmCAMBlockItem == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(blkAitm2->irefRefWznmCAMBlockItem)}, {"iel","irefRefWznmCAMBlockItem"}, {"lineno",to_string(blkAitm2->lineno)}});
				};
				blkAitm2->blkRefWznmMBlock = blk2->ref;
				//blkAitm2->blkNum: CUST
				if (blkAitm2->ixWznmVIop == VecWznmVIop::INS) blkAitm2->blkNum = (bitcnt++)+1;

				if ((blkAitm2->ixWznmVIop == VecWznmVIop::INS) || (blkAitm2->srefIxVBasetype != "")) {
					blkAitm2->ixVBasetype = VecWznmVAMBlockItemBasetype::getIx(blkAitm2->srefIxVBasetype);
					if (blkAitm2->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm2->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(blkAitm2->lineno)}});
				};
				//blkAitm2->sref: TBL
				if ((blkAitm2->ixWznmVIop == VecWznmVIop::INS) || (blkAitm2->srefIxWznmVVartype != "")) {
					blkAitm2->ixWznmVVartype = VecWznmVVartype::getIx(blkAitm2->srefIxWznmVVartype);
					if (blkAitm2->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm2->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(blkAitm2->lineno)}});
				};
				//blkAitm2->refWznmMVector: CUSTSQL
				if (blkAitm2->ixWznmVVartype == VecWznmVVartype::VECSREF) {
					dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, blkAitm2->srefRefWznmMVector, blkAitm2->refWznmMVector);
					if (blkAitm2->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm2->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(blkAitm2->lineno)}});
				};
				//blkAitm2->refJ: SUB
				//blkAitm2->Defval: TBL
				//blkAitm2->refWznmMVectoritem: CUSTSQL
				if ((blkAitm2->refWznmMVector != 0) && (blkAitm2->srefRefWznmMVectoritem != "")) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm2->refWznmMVector) + " AND sref = '" + blkAitm2->srefRefWznmMVectoritem + "'", blkAitm2->refWznmMVectoritem);
					if (blkAitm2->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm2->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(blkAitm2->lineno)}});
				};
				//blkAitm2->Comment: TBL

				if (blkAitm2->ixWznmVIop == VecWznmVIop::INS) {
					dbswznm->tblwznmamblockitem->insertRec(blkAitm2);
					impcnt++;

					if (((blkAitm2->Defval != "") || (blkAitm2->srefRefWznmMVectoritem != "")) && blkAitm2->imeijamblockitem2.nodes.empty()) {
						bitJ2 = new ImeitemIJAMBlockItem2();
						bitJ2->lineno = blkAitm2->lineno;
						blkAitm2->imeijamblockitem2.nodes.push_back(bitJ2);

						bitJ2->refWznmAMBlockItem = blkAitm2->ref;
						bitJ2->Defval = blkAitm2->Defval;
						bitJ2->srefRefWznmMVectoritem = blkAitm2->srefRefWznmMVectoritem;
					};

				} else if (blkAitm2->ixWznmVIop == VecWznmVIop::RETRUPD) {
					if (dbswznm->tblwznmamblockitem->loadRecBySQL("SELECT * FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blk2->ref) + " AND sref = '" + blkAitm2->sref + "'", &blkAitm3)) {
						blkAitm2->ref = blkAitm3->ref;
						//blkAitm2->blkRefWznmMBlock = ;
						blkAitm2->blkNum = blkAitm3->blkNum;
						blkAitm2->ixVBasetype = blkAitm3->ixVBasetype;
						//blkAitm2->sref = ;
						blkAitm2->ixWznmVVartype = blkAitm3->ixWznmVVartype;
						blkAitm2->refWznmMControl = blkAitm3->refWznmMControl;
						blkAitm2->refWznmMVector = blkAitm3->refWznmMVector;
						blkAitm2->refWznmMFeed = blkAitm3->refWznmMFeed;
						blkAitm2->refWznmMTable = blkAitm3->refWznmMTable;
						blkAitm2->refWznmMBlock = blkAitm3->refWznmMBlock;
						blkAitm2->refJ = blkAitm3->refJ;
						//blkAitm2->Defval = ; // update
						//blkAitm2->refWznmMVectoritem = ; // update
						blkAitm2->Comment = blkAitm3->Comment;

						dbswznm->tblwznmamblockitem->updateRec(blkAitm2);

						if (dbswznm->tblwznmjamblockitem->loadRecByRef(blkAitm2->refJ, &bitJ3)) {
							bitJ3->Defval = blkAitm2->Defval;
							bitJ3->refWznmMVectoritem = blkAitm2->refWznmMVectoritem;

							dbswznm->tblwznmjamblockitem->updateRec(bitJ3);

							delete bitJ3;
						};

						delete blkAitm3;
					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIAMBlockItem2"}, {"lineno",to_string(blkAitm2->lineno)}});
				};

				for (unsigned int ix2 = 0; ix2 < blkAitm2->imeijamblockitem2.nodes.size(); ix2++) {
					bitJ2 = blkAitm2->imeijamblockitem2.nodes[ix2];

					bitJ2->refWznmAMBlockItem = blkAitm2->ref;
					//bitJ2->Defval: TBL
					//bitJ2->refWznmMVectoritem: CUSTSQL
					if ((blkAitm2->refWznmMVector != 0) && (bitJ2->srefRefWznmMVectoritem != "")) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm2->refWznmMVector) + " AND sref = '" + bitJ2->srefRefWznmMVectoritem + "'", bitJ2->refWznmMVectoritem);
						if (bitJ2->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",bitJ2->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(bitJ2->lineno)}});
					};

					dbswznm->tblwznmjamblockitem->insertRec(bitJ2);
					impcnt++;

					if (ix2 == 0) {
						blkAitm2->refJ = bitJ2->ref;
						blkAitm2->Defval = bitJ2->Defval;
						blkAitm2->refWznmMVectoritem = bitJ2->refWznmMVectoritem;
						dbswznm->tblwznmamblockitem->updateRec(blkAitm2);
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		// -- ImeIMJob
		for (unsigned int ix0 = 0; ix0 < imeimjob.nodes.size(); ix0++) {
			job = imeimjob.nodes[ix0];

			if (job->ref != 0) {
				for (unsigned int ix1 = 0; ix1 < job->imeimblock1.nodes.size(); ix1++) {
					blk1 = job->imeimblock1.nodes[ix1];

					if (blk1->ref != 0) {
						for (unsigned int ix2 = 0; ix2 < blk1->imeiamblockitem1.nodes.size(); ix2++) {
							blkAitm1 = blk1->imeiamblockitem1.nodes[ix2];

							if (blkAitm1->ref != 0) {
								if (blkAitm1->srefRefWznmMBlock != "") {
									if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + blkAitm1->srefRefWznmMBlock + "'", blkAitm1->refWznmMBlock)) dbswznm->tblwznmamblockitem->updateRec(blkAitm1);
									else throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMBlock}, {"iel","srefRefWznmMBlock"}, {"lineno",to_string(blkAitm1->lineno)}});
								};
							};
						};
					};
				};

				for (unsigned int ix1 = 0; ix1 < job->imeimsensitivity1.nodes.size(); ix1++) {
					sns1 = job->imeimsensitivity1.nodes[ix1];

					if (sns1->srefRefWznmMCall != "") {
						if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCall WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sns1->srefRefWznmMCall + "'", sns1->refWznmMCall)) dbswznm->tblwznmmsensitivity->updateRec(sns1);
						else throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns1->srefRefWznmMCall}, {"iel","srefRefWznmMCall"}, {"lineno",to_string(sns1->lineno)}});
					};
					if (sns1->srefCsgRefWznmMStage != "") {
						if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref) + " AND sref = '" + sns1->srefCsgRefWznmMStage + "'", sns1->csgRefWznmMStage)) dbswznm->tblwznmmsensitivity->updateRec(sns1);
						else throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns1->srefCsgRefWznmMStage}, {"iel","srefCsgRefWznmMStage"}, {"lineno",to_string(sns1->lineno)}});
					};
				};

				for (unsigned int ix1 = 0; ix1 < job->imeimstage.nodes.size(); ix1++) {
					sge = job->imeimstage.nodes[ix1];

					if (sge->srefSnxRefWznmMStage != "")
						if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref) + " AND sref = '" + sge->srefSnxRefWznmMStage + "'", sge->snxRefWznmMStage))
							throw SbeException(SbeException::IEX_TSREF, {{"tsref",sge->srefSnxRefWznmMStage}, {"iel","srefSnxRefWznmMStage"}, {"lineno",to_string(sge->lineno)}});
					if (sge->srefFnxRefWznmMStage != "")
						if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref) + " AND sref = '" + sge->srefFnxRefWznmMStage + "'", sge->fnxRefWznmMStage))
							throw SbeException(SbeException::IEX_TSREF, {{"tsref",sge->srefFnxRefWznmMStage}, {"iel","srefFnxRefWznmMStage"}, {"lineno",to_string(sge->lineno)}});
					if (sge->srefEnxRefWznmMStage != "")
						if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref) + " AND sref = '" + sge->srefEnxRefWznmMStage + "'", sge->enxRefWznmMStage))
							throw SbeException(SbeException::IEX_TSREF, {{"tsref",sge->srefEnxRefWznmMStage}, {"iel","srefSnxRefWznmMStage"}, {"lineno",to_string(sge->lineno)}});
					if ((sge->snxRefWznmMStage != 0) || (sge->fnxRefWznmMStage != 0) || (sge->enxRefWznmMStage != 0)) dbswznm->tblwznmmstage->updateRec(sge);

					for (unsigned int ix2 = 0; ix2 < sge->imeimsensitivity2.nodes.size(); ix2++) {
						sns2 = sge->imeimsensitivity2.nodes[ix2];

						if (sns2->srefRefWznmMCall != "") {
							if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCall WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sns2->srefRefWznmMCall + "'", sns2->refWznmMCall)) dbswznm->tblwznmmsensitivity->updateRec(sns2);
							else throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns2->srefRefWznmMCall}, {"iel","srefRefWznmMCall"}, {"lineno",to_string(sns2->lineno)}});
						};
						if (sns2->srefCsgRefWznmMStage != "") {
							if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMStage WHERE jobRefWznmMJob = " + to_string(job->ref) + " AND sref = '" + sns2->srefCsgRefWznmMStage + "'", sns2->csgRefWznmMStage)) dbswznm->tblwznmmsensitivity->updateRec(sns2);
							else throw SbeException(SbeException::IEX_TSREF, {{"tsref",sns2->srefCsgRefWznmMStage}, {"iel","srefCsgRefWznmMStage"}, {"lineno",to_string(sns2->lineno)}});
						};
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

void JobWznmIexJtr::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexJtr::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexJtr::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexJtr::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMBlock2* blk2 = NULL;
	ImeitemIMCall* cal = NULL;
	ImeitemIMJob* job = NULL;
	ImeitemIRMCallMStub* calRstb = NULL;
	ImeitemIAMBlockItem2* blkAitm2 = NULL;
	ImeitemIAMJobCmd* jobAcmd = NULL;
	ImeitemIAMJobVar* jobAvar = NULL;
	ImeitemIMBlock1* blk1 = NULL;
	ImeitemIMMethod* mtd = NULL;
	ImeitemIMSensitivity1* sns1 = NULL;
	ImeitemIMStage* sge = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIRMJobMJob* jobRjob = NULL;
	ImeitemIRMJobMOp* jobRopx = NULL;
	ImeitemIRMJobMOppack* jobRopk = NULL;
	ImeitemIAMBlockItem1* blkAitm1 = NULL;
	ImeitemIAMMethodInvpar* mtdAipa = NULL;
	ImeitemIAMMethodRetpar* mtdArpa = NULL;
	ImeitemIJAMBlockItem2* bitJ2 = NULL;
	ImeitemIMSensitivity2* sns2 = NULL;
	ImeitemIMSquawk* sqk = NULL;
	ImeitemIMVectoritem* vit = NULL;
	ImeitemIJAMBlockItem1* bitJ1 = NULL;
	ImeitemIJMSquawkTitle* sqkJtit = NULL;
	ImeitemIJMVectoritem* vitJ = NULL;
	ImeitemIRMSquawkMStub* sqkRstb = NULL;

	// -- ImeIMBlock2
	for (unsigned int ix0 = 0; ix0 < imeimblock2.nodes.size(); ix0++) {
		blk2 = imeimblock2.nodes[ix0];
		if (blk2->ref != 0) dbswznm->tblwznmmblock->removeRecByRef(blk2->ref);

		for (unsigned int ix1 = 0; ix1 < blk2->imeiamblockitem2.nodes.size(); ix1++) {
			blkAitm2 = blk2->imeiamblockitem2.nodes[ix1];
			if (blkAitm2->ref != 0) dbswznm->tblwznmamblockitem->removeRecByRef(blkAitm2->ref);

			for (unsigned int ix2 = 0; ix2 < blkAitm2->imeijamblockitem2.nodes.size(); ix2++) {
				bitJ2 = blkAitm2->imeijamblockitem2.nodes[ix2];
				if (bitJ2->ref != 0) dbswznm->tblwznmjamblockitem->removeRecByRef(bitJ2->ref);
			};
		};

	};

	// -- ImeIMCall
	for (unsigned int ix0 = 0; ix0 < imeimcall.nodes.size(); ix0++) {
		cal = imeimcall.nodes[ix0];
		if (cal->ref != 0) dbswznm->tblwznmmcall->removeRecByRef(cal->ref);
	};

	// -- ImeIMJob
	for (unsigned int ix0 = 0; ix0 < imeimjob.nodes.size(); ix0++) {
		job = imeimjob.nodes[ix0];
		if (job->ref != 0) dbswznm->tblwznmmjob->removeRecByRef(job->ref);

		for (unsigned int ix1 = 0; ix1 < job->imeiamjobcmd.nodes.size(); ix1++) {
			jobAcmd = job->imeiamjobcmd.nodes[ix1];
			if (jobAcmd->ref != 0) dbswznm->tblwznmamjobcmd->removeRecByRef(jobAcmd->ref);
		};

		for (unsigned int ix1 = 0; ix1 < job->imeiamjobvar.nodes.size(); ix1++) {
			jobAvar = job->imeiamjobvar.nodes[ix1];
			if (jobAvar->ref != 0) dbswznm->tblwznmamjobvar->removeRecByRef(jobAvar->ref);
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimblock1.nodes.size(); ix1++) {
			blk1 = job->imeimblock1.nodes[ix1];
			if (blk1->ref != 0) dbswznm->tblwznmmblock->removeRecByRef(blk1->ref);

			for (unsigned int ix2 = 0; ix2 < blk1->imeiamblockitem1.nodes.size(); ix2++) {
				blkAitm1 = blk1->imeiamblockitem1.nodes[ix2];
				if (blkAitm1->ref != 0) dbswznm->tblwznmamblockitem->removeRecByRef(blkAitm1->ref);

				for (unsigned int ix3 = 0; ix3 < blkAitm1->imeijamblockitem1.nodes.size(); ix3++) {
					bitJ1 = blkAitm1->imeijamblockitem1.nodes[ix3];
					if (bitJ1->ref != 0) dbswznm->tblwznmjamblockitem->removeRecByRef(bitJ1->ref);
				};
			};

		};

		for (unsigned int ix1 = 0; ix1 < job->imeimmethod.nodes.size(); ix1++) {
			mtd = job->imeimmethod.nodes[ix1];
			if (mtd->ref != 0) dbswznm->tblwznmmmethod->removeRecByRef(mtd->ref);

			for (unsigned int ix2 = 0; ix2 < mtd->imeiammethodinvpar.nodes.size(); ix2++) {
				mtdAipa = mtd->imeiammethodinvpar.nodes[ix2];
				if (mtdAipa->ref != 0) dbswznm->tblwznmammethodinvpar->removeRecByRef(mtdAipa->ref);
			};

			for (unsigned int ix2 = 0; ix2 < mtd->imeiammethodretpar.nodes.size(); ix2++) {
				mtdArpa = mtd->imeiammethodretpar.nodes[ix2];
				if (mtdArpa->ref != 0) dbswznm->tblwznmammethodretpar->removeRecByRef(mtdArpa->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimsensitivity1.nodes.size(); ix1++) {
			sns1 = job->imeimsensitivity1.nodes[ix1];
			if (sns1->ref != 0) dbswznm->tblwznmmsensitivity->removeRecByRef(sns1->ref);
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimstage.nodes.size(); ix1++) {
			sge = job->imeimstage.nodes[ix1];
			if (sge->ref != 0) dbswznm->tblwznmmstage->removeRecByRef(sge->ref);

			for (unsigned int ix2 = 0; ix2 < sge->imeimsensitivity2.nodes.size(); ix2++) {
				sns2 = sge->imeimsensitivity2.nodes[ix2];
				if (sns2->ref != 0) dbswznm->tblwznmmsensitivity->removeRecByRef(sns2->ref);
			};

			for (unsigned int ix2 = 0; ix2 < sge->imeimsquawk.nodes.size(); ix2++) {
				sqk = sge->imeimsquawk.nodes[ix2];
				if (sqk->ref != 0) dbswznm->tblwznmmsquawk->removeRecByRef(sqk->ref);

				for (unsigned int ix3 = 0; ix3 < sqk->imeijmsquawktitle.nodes.size(); ix3++) {
					sqkJtit = sqk->imeijmsquawktitle.nodes[ix3];
					if (sqkJtit->ref != 0) dbswznm->tblwznmjmsquawktitle->removeRecByRef(sqkJtit->ref);
				};

				for (unsigned int ix3 = 0; ix3 < sqk->imeirmsquawkmstub.nodes.size(); ix3++) {
					sqkRstb = sqk->imeirmsquawkmstub.nodes[ix3];
					if (sqkRstb->ref != 0) dbswznm->tblwznmrmsquawkmstub->removeRecByRef(sqkRstb->ref);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimvector.nodes.size(); ix1++) {
			vec = job->imeimvector.nodes[ix1];
			if (vec->ref != 0) dbswznm->tblwznmmvector->removeRecByRef(vec->ref);

			for (unsigned int ix2 = 0; ix2 < vec->imeimvectoritem.nodes.size(); ix2++) {
				vit = vec->imeimvectoritem.nodes[ix2];
				if (vit->ref != 0) dbswznm->tblwznmmvectoritem->removeRecByRef(vit->ref);

				for (unsigned int ix3 = 0; ix3 < vit->imeijmvectoritem.nodes.size(); ix3++) {
					vitJ = vit->imeijmvectoritem.nodes[ix3];
					if (vitJ->ref != 0) dbswznm->tblwznmjmvectoritem->removeRecByRef(vitJ->ref);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < job->imeirmjobmjob.nodes.size(); ix1++) {
			jobRjob = job->imeirmjobmjob.nodes[ix1];
			if (jobRjob->ref != 0) dbswznm->tblwznmrmjobmjob->removeRecByRef(jobRjob->ref);
		};

		for (unsigned int ix1 = 0; ix1 < job->imeirmjobmop.nodes.size(); ix1++) {
			jobRopx = job->imeirmjobmop.nodes[ix1];
			if (jobRopx->ref != 0) dbswznm->tblwznmrmjobmop->removeRecByRef(jobRopx->ref);
		};

		for (unsigned int ix1 = 0; ix1 < job->imeirmjobmoppack.nodes.size(); ix1++) {
			jobRopk = job->imeirmjobmoppack.nodes[ix1];
			if (jobRopk->ref != 0) dbswznm->tblwznmrmjobmoppack->removeRecByRef(jobRopk->ref);
		};
	};

	// -- ImeIRMCallMStub
	for (unsigned int ix0 = 0; ix0 < imeirmcallmstub.nodes.size(); ix0++) {
		calRstb = imeirmcallmstub.nodes[ix0];
		if (calRstb->ref != 0) dbswznm->tblwznmrmcallmstub->removeRecByRef(calRstb->ref);
	};

	return retval;
};

void JobWznmIexJtr::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexJtr::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMBlock2* blk2 = NULL;
	ImeitemIMCall* cal = NULL;
	ImeitemIMJob* job = NULL;
	ImeitemIRMCallMStub* calRstb = NULL;
	ImeitemIAMBlockItem2* blkAitm2 = NULL;
	ImeitemIAMJobCmd* jobAcmd = NULL;
	ImeitemIAMJobVar* jobAvar = NULL;
	ImeitemICAMBlockItem2* blkAitmC2 = NULL;
	ImeitemICAMJobVar* jobAvarC = NULL;
	ImeitemIMBlock1* blk1 = NULL;
	ImeitemIMMethod* mtd = NULL;
	ImeitemIMSensitivity1* sns1 = NULL;
	ImeitemIMStage* sge = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIRMJobMJob* jobRjob = NULL;
	ImeitemIRMJobMOp* jobRopx = NULL;
	ImeitemIRMJobMOppack* jobRopk = NULL;
	ImeitemIAMBlockItem1* blkAitm1 = NULL;
	ImeitemIAMMethodInvpar* mtdAipa = NULL;
	ImeitemIAMMethodRetpar* mtdArpa = NULL;
	ImeitemICAMBlockItem1* blkAitmC1 = NULL;
	ImeitemIJAMBlockItem2* bitJ2 = NULL;
	ImeitemIMSensitivity2* sns2 = NULL;
	ImeitemIMSquawk* sqk = NULL;
	ImeitemIMVectoritem* vit = NULL;
	ImeitemIJAMBlockItem1* bitJ1 = NULL;
	ImeitemIJMSquawkTitle* sqkJtit = NULL;
	ImeitemIJMVectoritem* vitJ = NULL;
	ImeitemIRMSquawkMStub* sqkRstb = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMBlock2
	for (unsigned int ix0 = 0; ix0 < imeimblock2.nodes.size(); ix0++) {
		blk2 = imeimblock2.nodes[ix0];

		if (blk2->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMBLOCKITEM2, ixWznmVIop)) {
			dbswznm->tblwznmamblockitem->loadRefsByBlk(blk2->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) blk2->imeiamblockitem2.nodes.push_back(new ImeitemIAMBlockItem2(dbswznm, ixWznmVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < blk2->imeiamblockitem2.nodes.size(); ix1++) {
			blkAitm2 = blk2->imeiamblockitem2.nodes[ix1];

			if (blkAitm2->ref != 0) {
				//blkAitm2->srefIxWznmVIop: IOP
				//blkAitm2->irefRefWznmCAMBlockItem: IREF
				blkAitm2->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, blkAitm2->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				//blkAitm2->srefRefWznmMVectoritem: STUB
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAMBLOCKITEM2, ixWznmVIop)) {
				dbswznm->tblwznmjamblockitem->loadRefsByBit(blkAitm2->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) blkAitm2->imeijamblockitem2.nodes.push_back(new ImeitemIJAMBlockItem2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < blkAitm2->imeijamblockitem2.nodes.size(); ix2++) {
				bitJ2 = blkAitm2->imeijamblockitem2.nodes[ix2];

				if (bitJ2->ref != 0) {
					bitJ2->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, bitJ2->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < blk2->imeicamblockitem2.nodes.size(); ix1++) {
			blkAitmC2 = blk2->imeicamblockitem2.nodes[ix1];

			if (blkAitmC2->ref != 0) {
				blkAitmC2->iref = ix1+1;
			};
		};
	};

	// -- ImeIMCall
	for (unsigned int ix0 = 0; ix0 < imeimcall.nodes.size(); ix0++) {
		cal = imeimcall.nodes[ix0];

		if (cal->ref != 0) {
		};
	};

	// -- ImeIMJob
	for (unsigned int ix0 = 0; ix0 < imeimjob.nodes.size(); ix0++) {
		job = imeimjob.nodes[ix0];

		if (job->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMJOBCMD, ixWznmVIop)) {
			dbswznm->tblwznmamjobcmd->loadRefsByJob(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeiamjobcmd.nodes.push_back(new ImeitemIAMJobCmd(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeiamjobcmd.nodes.size(); ix1++) {
			jobAcmd = job->imeiamjobcmd.nodes[ix1];

			if (jobAcmd->ref != 0) {
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMJOBVAR, ixWznmVIop)) {
			dbswznm->tblwznmamjobvar->loadRefsByJob(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeiamjobvar.nodes.push_back(new ImeitemIAMJobVar(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeiamjobvar.nodes.size(); ix1++) {
			jobAvar = job->imeiamjobvar.nodes[ix1];

			if (jobAvar->ref != 0) {
				//jobAvar->irefRefWznmCAMJobVar: IREF
				jobAvar->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, jobAvar->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		for (unsigned int ix1 = 0; ix1 < job->imeicamjobvar.nodes.size(); ix1++) {
			jobAvarC = job->imeicamjobvar.nodes[ix1];

			if (jobAvarC->ref != 0) {
				jobAvarC->iref = ix1+1;
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMBLOCK1, ixWznmVIop)) {
			dbswznm->tblwznmmblock->loadRefsByRetReu(VecWznmVMBlockRefTbl::JOB, job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeimblock1.nodes.push_back(new ImeitemIMBlock1(dbswznm, ixWznmVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimblock1.nodes.size(); ix1++) {
			blk1 = job->imeimblock1.nodes[ix1];

			if (blk1->ref != 0) {
				//blk1->srefIxWznmVIop: IOP
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMBLOCKITEM1, ixWznmVIop)) {
				dbswznm->tblwznmamblockitem->loadRefsByBlk(blk1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) blk1->imeiamblockitem1.nodes.push_back(new ImeitemIAMBlockItem1(dbswznm, ixWznmVIop, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < blk1->imeiamblockitem1.nodes.size(); ix2++) {
				blkAitm1 = blk1->imeiamblockitem1.nodes[ix2];

				if (blkAitm1->ref != 0) {
					//blkAitm1->srefIxWznmVIop: IOP
					//blkAitm1->irefRefWznmCAMBlockItem: IREF
					blkAitm1->srefRefWznmMControl = StubWznm::getStubConSref(dbswznm, blkAitm1->refWznmMControl, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					blkAitm1->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, blkAitm1->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					blkAitm1->srefRefWznmMFeed = StubWznm::getStubFedSref(dbswznm, blkAitm1->refWznmMFeed, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					blkAitm1->srefRefWznmMTable = StubWznm::getStubTblStd(dbswznm, blkAitm1->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					blkAitm1->srefRefWznmMBlock = StubWznm::getStubBlkStd(dbswznm, blkAitm1->refWznmMBlock, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					//blkAitm1->srefRefWznmMVectoritem: STUB
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAMBLOCKITEM1, ixWznmVIop)) {
					dbswznm->tblwznmjamblockitem->loadRefsByBit(blkAitm1->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) blkAitm1->imeijamblockitem1.nodes.push_back(new ImeitemIJAMBlockItem1(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < blkAitm1->imeijamblockitem1.nodes.size(); ix3++) {
					bitJ1 = blkAitm1->imeijamblockitem1.nodes[ix3];

					if (bitJ1->ref != 0) {
						bitJ1->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, bitJ1->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};

			for (unsigned int ix2 = 0; ix2 < blk1->imeicamblockitem1.nodes.size(); ix2++) {
				blkAitmC1 = blk1->imeicamblockitem1.nodes[ix2];

				if (blkAitmC1->ref != 0) {
					blkAitmC1->iref = ix2+1;
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMMETHOD, ixWznmVIop)) {
			dbswznm->tblwznmmmethod->loadRefsByJob(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeimmethod.nodes.push_back(new ImeitemIMMethod(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimmethod.nodes.size(); ix1++) {
			mtd = job->imeimmethod.nodes[ix1];

			if (mtd->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMMETHODINVPAR, ixWznmVIop)) {
				dbswznm->tblwznmammethodinvpar->loadRefsByMtd(mtd->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mtd->imeiammethodinvpar.nodes.push_back(new ImeitemIAMMethodInvpar(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mtd->imeiammethodinvpar.nodes.size(); ix2++) {
				mtdAipa = mtd->imeiammethodinvpar.nodes[ix2];

				if (mtdAipa->ref != 0) {
					mtdAipa->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, mtdAipa->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMMETHODRETPAR, ixWznmVIop)) {
				dbswznm->tblwznmammethodretpar->loadRefsByMtd(mtd->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mtd->imeiammethodretpar.nodes.push_back(new ImeitemIAMMethodRetpar(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mtd->imeiammethodretpar.nodes.size(); ix2++) {
				mtdArpa = mtd->imeiammethodretpar.nodes[ix2];

				if (mtdArpa->ref != 0) {
					mtdArpa->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, mtdArpa->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSENSITIVITY1, ixWznmVIop)) {
			dbswznm->tblwznmmsensitivity->loadRefsByJob(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeimsensitivity1.nodes.push_back(new ImeitemIMSensitivity1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimsensitivity1.nodes.size(); ix1++) {
			sns1 = job->imeimsensitivity1.nodes[ix1];

			if (sns1->ref != 0) {
				//sns1->srefRefWznmMCall: STUB
				//sns1->srefRefWznmMControl: STUB
				//sns1->srefCsgRefWznmMStage: STUB
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSTAGE, ixWznmVIop)) {
			dbswznm->tblwznmmstage->loadRefsByJob(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeimstage.nodes.push_back(new ImeitemIMStage(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimstage.nodes.size(); ix1++) {
			sge = job->imeimstage.nodes[ix1];

			if (sge->ref != 0) {
				//sge->srefSnxRefWznmMStage: STUB
				//sge->srefFnxRefWznmMStage: STUB
				//sge->srefEnxRefWznmMStage: STUB
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSENSITIVITY2, ixWznmVIop)) {
				dbswznm->tblwznmmsensitivity->loadRefsBySge(sge->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) sge->imeimsensitivity2.nodes.push_back(new ImeitemIMSensitivity2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < sge->imeimsensitivity2.nodes.size(); ix2++) {
				sns2 = sge->imeimsensitivity2.nodes[ix2];

				if (sns2->ref != 0) {
					//sns2->srefRefWznmMCall: STUB
					//sns2->srefRefWznmMControl: STUB
					//sns2->srefCsgRefWznmMStage: STUB
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSQUAWK, ixWznmVIop)) {
				dbswznm->tblwznmmsquawk->loadRefsByRetReu(VecWznmVMSquawkRefTbl::SGE, sge->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) sge->imeimsquawk.nodes.push_back(new ImeitemIMSquawk(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < sge->imeimsquawk.nodes.size(); ix2++) {
				sqk = sge->imeimsquawk.nodes[ix2];

				if (sqk->ref != 0) {
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMSQUAWKTITLE, ixWznmVIop)) {
					dbswznm->tblwznmjmsquawktitle->loadRefsBySqk(sqk->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == sqk->refJTitle) {refs[i] = refs[0]; refs[0] = sqk->refJTitle; break;};
					for (unsigned int i = 0; i < refs.size(); i++) sqk->imeijmsquawktitle.nodes.push_back(new ImeitemIJMSquawkTitle(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < sqk->imeijmsquawktitle.nodes.size(); ix3++) {
					sqkJtit = sqk->imeijmsquawktitle.nodes[ix3];

					if (sqkJtit->ref != 0) {
						sqkJtit->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, sqkJtit->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMSQUAWKMSTUB, ixWznmVIop)) {
					dbswznm->tblwznmrmsquawkmstub->loadRefsBySqk(sqk->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) sqk->imeirmsquawkmstub.nodes.push_back(new ImeitemIRMSquawkMStub(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < sqk->imeirmsquawkmstub.nodes.size(); ix3++) {
					sqkRstb = sqk->imeirmsquawkmstub.nodes[ix3];

					if (sqkRstb->ref != 0) {
						sqkRstb->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, sqkRstb->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMVECTOR, ixWznmVIop)) {
			dbswznm->tblwznmmvector->loadRefsByHktHku(VecWznmVMVectorHkTbl::JOB, job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeimvector.nodes.push_back(new ImeitemIMVector(dbswznm, ixWznmVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeimvector.nodes.size(); ix1++) {
			vec = job->imeimvector.nodes[ix1];

			if (vec->ref != 0) {
				//vec->srefIxWznmVIop: IOP
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMVECTORITEM, ixWznmVIop)) {
				dbswznm->tblwznmmvectoritem->loadRefsByVec(vec->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) vec->imeimvectoritem.nodes.push_back(new ImeitemIMVectoritem(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < vec->imeimvectoritem.nodes.size(); ix2++) {
				vit = vec->imeimvectoritem.nodes[ix2];

				if (vit->ref != 0) {
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMVECTORITEM, ixWznmVIop)) {
					dbswznm->tblwznmjmvectoritem->loadRefsByVit(vit->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == vit->refJ) {refs[i] = refs[0]; refs[0] = vit->refJ; break;};
					for (unsigned int i = 0; i < refs.size(); i++) vit->imeijmvectoritem.nodes.push_back(new ImeitemIJMVectoritem(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < vit->imeijmvectoritem.nodes.size(); ix3++) {
					vitJ = vit->imeijmvectoritem.nodes[ix3];

					if (vitJ->ref != 0) {
						vitJ->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, vitJ->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMJOBMJOB, ixWznmVIop)) {
			dbswznm->tblwznmrmjobmjob->loadRefsBySup(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeirmjobmjob.nodes.push_back(new ImeitemIRMJobMJob(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeirmjobmjob.nodes.size(); ix1++) {
			jobRjob = job->imeirmjobmjob.nodes[ix1];

			if (jobRjob->ref != 0) {
				jobRjob->srefSubRefWznmMJob = StubWznm::getStubJobStd(dbswznm, jobRjob->subRefWznmMJob, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMJOBMOP, ixWznmVIop)) {
			dbswznm->tblwznmrmjobmop->loadRefsByJob(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeirmjobmop.nodes.push_back(new ImeitemIRMJobMOp(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeirmjobmop.nodes.size(); ix1++) {
			jobRopx = job->imeirmjobmop.nodes[ix1];

			if (jobRopx->ref != 0) {
				jobRopx->srefRefWznmMOp = StubWznm::getStubOpxStd(dbswznm, jobRopx->refWznmMOp, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMJOBMOPPACK, ixWznmVIop)) {
			dbswznm->tblwznmrmjobmoppack->loadRefsByJob(job->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) job->imeirmjobmoppack.nodes.push_back(new ImeitemIRMJobMOppack(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < job->imeirmjobmoppack.nodes.size(); ix1++) {
			jobRopk = job->imeirmjobmoppack.nodes[ix1];

			if (jobRopk->ref != 0) {
				jobRopk->srefRefWznmMOppack = StubWznm::getStubOpkStd(dbswznm, jobRopk->refWznmMOppack, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIRMCallMStub
	for (unsigned int ix0 = 0; ix0 < imeirmcallmstub.nodes.size(); ix0++) {
		calRstb = imeirmcallmstub.nodes[ix0];

		if (calRstb->ref != 0) {
			calRstb->srefRefWznmMCall = StubWznm::getStubCalStd(dbswznm, calRstb->refWznmMCall, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			calRstb->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, calRstb->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexJtr::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexJtr::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexJtr::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexJtr::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmJtr::exportToFile(fullpath, xmlNotTxt, shorttags, imeimblock2, imeimcall, imeimjob, imeirmcallmstub);

	return retval;
};

void JobWznmIexJtr::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexJtr::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexJtr::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
