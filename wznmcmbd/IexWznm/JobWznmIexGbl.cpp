/**
	* \file JobWznmIexGbl.cpp
	* job handler for job JobWznmIexGbl (implementation)
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

#include "JobWznmIexGbl.h"

#include "JobWznmIexGbl_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmGbl;

/******************************************************************************
 class JobWznmIexGbl
 ******************************************************************************/

JobWznmIexGbl::JobWznmIexGbl(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXGBL, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexGbl::~JobWznmIexGbl() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexGbl::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexGbl::parseFromFile(
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

void JobWznmIexGbl::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexGbl::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexGbl::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexGbl::exportToFile(
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

void JobWznmIexGbl::handleRequest(
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

void JobWznmIexGbl::changeStage(
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

string JobWznmIexGbl::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing global features";
			else if (ixVSge == VecVSge::PRSDONE) retval = "global features parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing global features (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing global features import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting global features for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "global features collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting global features";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexGbl::enterSgeIdle(
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

	imeimblock.clear();
	imeimcapability.clear();
	imeimerror.clear();
	imeimvector.clear();

	return retval;
};

void JobWznmIexGbl::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexGbl::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmGbl::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimblock, imeimcapability, imeimerror, imeimvector);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexGbl::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexGbl::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexGbl::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexGbl::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexGbl::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexGbl::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMBlock* blk = NULL;
	ImeitemIMCapability* cpb = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMBlockItem* blkAitm = NULL;
	ImeitemIAMCapabilityPar* cpbApar = NULL;
	ImeitemIAMVectorTitle* vecAtit = NULL;
	ImeitemICAMBlockItem* blkAitmC = NULL;
	ImeitemIJMErrorTitle* errJtit = NULL;
	ImeitemIMVectoritem* vit = NULL;
	ImeitemIJAMBlockItem* bitJ = NULL;
	ImeitemIJMVectoritem* vitJ = NULL;

	set<ubigint> irefs1;

	uint num0, num1;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWznmMVersion;
	string preflcl;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	Wznm::getVerlclsref(dbswznm, refWznmMVersion, preflcl);

	ListWznmMRelease rlss;

	dbswznm->tblwznmmrelease->loadRstBySQL("SELECT TblWznmMRelease.* FROM TblWznmMComponent, TblWznmMRelease WHERE TblWznmMRelease.refWznmMComponent = TblWznmMComponent.ref AND TblWznmMComponent.refWznmMVersion = " + to_string(refWznmMVersion), false, rlss);

	ListWznmMLocale lcls;

	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN
		// -- ImeIMError
		num0 = 1;

		for (unsigned int ix0 = 0; ix0 < imeimerror.nodes.size(); ix0++) {
			err = imeimerror.nodes[ix0];

			//err->verRefWznmMVersion: PRESET
			err->verRefWznmMVersion = refWznmMVersion;
			err->verNum = num0++;
			//err->sref: TBL
			//err->refJTitle: SUB
			//err->Title: TBL

			dbswznm->tblwznmmerror->insertRec(err);
			impcnt++;

			if ((err->Title != "") && err->imeijmerrortitle.nodes.empty()) {
				errJtit = new ImeitemIJMErrorTitle();
				err->imeijmerrortitle.nodes.push_back(errJtit);

				errJtit->refWznmMError = err->ref;
				errJtit->Title = err->Title;
			};

			for (unsigned int ix1 = 0; ix1 < err->imeijmerrortitle.nodes.size(); ix1++) {
				errJtit = err->imeijmerrortitle.nodes[ix1];

				errJtit->refWznmMError = err->ref;
				//if (errJtit->srefX1RefWznmMLocale == "") errJtit->srefX1RefWznmMLocale: CUSTOM DEFVAL
				if (errJtit->srefX1RefWznmMLocale == "") errJtit->srefX1RefWznmMLocale = preflcl;
				//errJtit->x1RefWznmMLocale: RST
				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					if (lcls.nodes[i]->sref == errJtit->srefX1RefWznmMLocale) {
						errJtit->x1RefWznmMLocale = lcls.nodes[i]->ref;
						break;
					};
				};
				if (errJtit->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",errJtit->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(errJtit->lineno)}});
				//errJtit->Title: TBL

				dbswznm->tblwznmjmerrortitle->insertRec(errJtit);
				impcnt++;

				if (ix1 == 0) {
					err->refJTitle = errJtit->ref;
					err->Title = errJtit->Title;
					dbswznm->tblwznmmerror->updateRec(err);
				};
			};
		};

		// -- ImeIMVector
		for (unsigned int ix0 = 0; ix0 < imeimvector.nodes.size(); ix0++) {
			vec = imeimvector.nodes[ix0];

			vec->ixVBasetype = VecWznmVMVectorBasetype::getIx(vec->srefIxVBasetype);
			if (vec->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec->lineno)}});
			//vec->refWznmMVersion: PRESET
			vec->refWznmMVersion = refWznmMVersion;
			vec->hkIxVTbl = VecWznmVMVectorHkTbl::JOB;
			//vec->sref: TBL
			//vec->osrefWznmKTaggrp: TBL
			//vec->srefsKOption: TBL

			dbswznm->tblwznmmvector->insertRec(vec);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < vec->imeiamvectortitle.nodes.size(); ix1++) {
				vecAtit = vec->imeiamvectortitle.nodes[ix1];

				vecAtit->refWznmMVector = vec->ref;
				vecAtit->x1IxVType = VecWznmVAMVectorTitleType::getIx(vecAtit->srefX1IxVType);
				if (vecAtit->x1IxVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vecAtit->srefX1IxVType}, {"iel","srefX1IxVType"}, {"lineno",to_string(vecAtit->lineno)}});
				//vecAtit->x2RefWznmMLocale: RST
				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					if (lcls.nodes[i]->sref.compare(vecAtit->srefX2RefWznmMLocale) == 0) {
						vecAtit->x2RefWznmMLocale = lcls.nodes[i]->ref;
						break;
					};
				};
				if (vecAtit->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",vecAtit->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(vecAtit->lineno)}});
				//vecAtit->Title: TBL

				dbswznm->tblwznmamvectortitle->insertRec(vecAtit);
				impcnt++;
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < vec->imeimvectoritem.nodes.size(); ix1++) {
				vit = vec->imeimvectoritem.nodes[ix1];

				vit->vecRefWznmMVector = vec->ref;
				vit->vecNum = num1++;
				//vit->sref: TBL
				//vit->Avail: TBL
				//vit->Implied: TBL
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

				for (unsigned int ix2 = 0; ix2 < vit->imeijmvectoritem.nodes.size(); ix2++) {
					vitJ = vit->imeijmvectoritem.nodes[ix2];

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

					if (ix2 == 0) {
						vit->refJ = vitJ->ref;
						vit->Title = vitJ->Title;
						vit->Comment = vitJ->Comment;
						dbswznm->tblwznmmvectoritem->updateRec(vit);
					};
				};
			};
		};

		// -- ImeIMBlock
		for (unsigned int ix0 = 0; ix0 < imeimblock.nodes.size(); ix0++) {
			blk = imeimblock.nodes[ix0];

			blk->ixVBasetype = VecWznmVMBlockBasetype::STG;
			//blk->refWznmMVersion: PRESET
			blk->refWznmMVersion = refWznmMVersion;
			blk->refIxVTbl = VecWznmVMBlockRefTbl::VOID;
			blk->reaIxWznmWScope = VecWznmWScope::getIx(blk->srefsReaIxWznmWScope);
			blk->wriIxWznmWScope = VecWznmWScope::getIx(blk->srefsWriIxWznmWScope);
			//blk->sref: TBL
			//blk->Comment: TBL

			dbswznm->tblwznmmblock->insertRec(blk);
			impcnt++;

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < blk->imeicamblockitem.nodes.size(); ix1++) {
				blkAitmC = blk->imeicamblockitem.nodes[ix1];

				if (irefs1.find(blkAitmC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(blkAitmC->iref)}, {"ime","ImeICAMBlockItem"}, {"lineno",to_string(blkAitmC->lineno)}});
				blkAitmC->ref = dbswznm->tblwznmcamblockitem->getNewRef();
				irefs1.insert(blkAitmC->iref);

				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < blk->imeiamblockitem.nodes.size(); ix1++) {
				blkAitm = blk->imeiamblockitem.nodes[ix1];

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
				blkAitm->blkNum = (ix1+1); // TBD
				blkAitm->ixVBasetype = VecWznmVAMBlockItemBasetype::getIx(blkAitm->srefIxVBasetype);
				if (blkAitm->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(blkAitm->lineno)}});
				//blkAitm->sref: TBL
				blkAitm->ixWznmVVartype = VecWznmVVartype::getIx(blkAitm->srefIxWznmVVartype);
				if (blkAitm->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(blkAitm->lineno)}});
				//blkAitm->refJ: SUB
				//blkAitm->Defval: TBL
				//blkAitm->Comment: TBL

				dbswznm->tblwznmamblockitem->insertRec(blkAitm);
				impcnt++;

				if ((blkAitm->Defval != "") && blkAitm->imeijamblockitem.nodes.empty()) {
					bitJ = new ImeitemIJAMBlockItem();
					blkAitm->imeijamblockitem.nodes.push_back(bitJ);

					bitJ->refWznmAMBlockItem = blkAitm->ref;
					bitJ->Defval = blkAitm->Defval;
				};

				for (unsigned int ix2 = 0; ix2 < blkAitm->imeijamblockitem.nodes.size(); ix2++) {
					bitJ = blkAitm->imeijamblockitem.nodes[ix2];

					bitJ->refWznmAMBlockItem = blkAitm->ref;
					if (bitJ->srefX1RefWznmMRelease != "") {
						//bitJ->x1RefWznmMRelease: RST
						for (unsigned int i = 0; i < rlss.nodes.size(); i++) {
							if (rlss.nodes[i]->sref == bitJ->srefX1RefWznmMRelease) {
								bitJ->x1RefWznmMRelease = rlss.nodes[i]->ref;
								break;
							};
						};
						if (bitJ->x1RefWznmMRelease == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",bitJ->srefX1RefWznmMRelease}, {"iel","srefX1RefWznmMRelease"}, {"lineno",to_string(bitJ->lineno)}});
					};
					//bitJ->Defval: TBL

					dbswznm->tblwznmjamblockitem->insertRec(bitJ);
					impcnt++;

					if (ix2 == 0) {
						blkAitm->refJ = bitJ->ref;
						blkAitm->Defval = bitJ->Defval;
						dbswznm->tblwznmamblockitem->updateRec(blkAitm);
					};
				};
			};
		};

		// -- ImeIMCapability
		for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
			cpb = imeimcapability.nodes[ix0];

			//cpb->refWznmMVersion: PRESET
			cpb->refWznmMVersion = refWznmMVersion;
			//cpb->tplRefWznmMCapability: CUSTSQL
			if (cpb->srefTplRefWznmMCapability != "") {
				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCapability WHERE tplRefWznmMCapability = 0 AND sref = '" + cpb->srefTplRefWznmMCapability + "'", cpb->tplRefWznmMCapability);
			};
			if (cpb->tplRefWznmMCapability == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cpb->srefTplRefWznmMCapability}, {"iel","srefTplRefWznmMCapability"}, {"lineno",to_string(cpb->lineno)}});
			//cpb->sref: TBL
			//cpb->Comment: TBL

			dbswznm->tblwznmmcapability->insertRec(cpb);
			impcnt++;

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < cpb->imeiamcapabilitypar.nodes.size(); ix1++) {
				cpbApar = cpb->imeiamcapabilitypar.nodes[ix1];

				cpbApar->cpbRefWznmMCapability = cpb->ref;
				cpbApar->cpbNum = num1++;
				//cpbApar->x1SrefKKey: TBL
				//cpbApar->Val: TBL

				dbswznm->tblwznmamcapabilitypar->insertRec(cpbApar);
				impcnt++;
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

void JobWznmIexGbl::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexGbl::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexGbl::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexGbl::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMBlock* blk = NULL;
	ImeitemIMCapability* cpb = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMBlockItem* blkAitm = NULL;
	ImeitemIAMCapabilityPar* cpbApar = NULL;
	ImeitemIAMVectorTitle* vecAtit = NULL;
	ImeitemIJMErrorTitle* errJtit = NULL;
	ImeitemIMVectoritem* vit = NULL;
	ImeitemIJAMBlockItem* bitJ = NULL;
	ImeitemIJMVectoritem* vitJ = NULL;

	// -- ImeIMBlock
	for (unsigned int ix0 = 0; ix0 < imeimblock.nodes.size(); ix0++) {
		blk = imeimblock.nodes[ix0];
		if (blk->ref != 0) dbswznm->tblwznmmblock->removeRecByRef(blk->ref);

		for (unsigned int ix1 = 0; ix1 < blk->imeiamblockitem.nodes.size(); ix1++) {
			blkAitm = blk->imeiamblockitem.nodes[ix1];
			if (blkAitm->ref != 0) dbswznm->tblwznmamblockitem->removeRecByRef(blkAitm->ref);

			for (unsigned int ix2 = 0; ix2 < blkAitm->imeijamblockitem.nodes.size(); ix2++) {
				bitJ = blkAitm->imeijamblockitem.nodes[ix2];
				if (bitJ->ref != 0) dbswznm->tblwznmjamblockitem->removeRecByRef(bitJ->ref);
			};
		};

	};

	// -- ImeIMCapability
	for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
		cpb = imeimcapability.nodes[ix0];
		if (cpb->ref != 0) dbswznm->tblwznmmcapability->removeRecByRef(cpb->ref);

		for (unsigned int ix1 = 0; ix1 < cpb->imeiamcapabilitypar.nodes.size(); ix1++) {
			cpbApar = cpb->imeiamcapabilitypar.nodes[ix1];
			if (cpbApar->ref != 0) dbswznm->tblwznmamcapabilitypar->removeRecByRef(cpbApar->ref);
		};
	};

	// -- ImeIMError
	for (unsigned int ix0 = 0; ix0 < imeimerror.nodes.size(); ix0++) {
		err = imeimerror.nodes[ix0];
		if (err->ref != 0) dbswznm->tblwznmmerror->removeRecByRef(err->ref);

		for (unsigned int ix1 = 0; ix1 < err->imeijmerrortitle.nodes.size(); ix1++) {
			errJtit = err->imeijmerrortitle.nodes[ix1];
			if (errJtit->ref != 0) dbswznm->tblwznmjmerrortitle->removeRecByRef(errJtit->ref);
		};
	};

	// -- ImeIMVector
	for (unsigned int ix0 = 0; ix0 < imeimvector.nodes.size(); ix0++) {
		vec = imeimvector.nodes[ix0];
		if (vec->ref != 0) dbswznm->tblwznmmvector->removeRecByRef(vec->ref);

		for (unsigned int ix1 = 0; ix1 < vec->imeiamvectortitle.nodes.size(); ix1++) {
			vecAtit = vec->imeiamvectortitle.nodes[ix1];
			if (vecAtit->ref != 0) dbswznm->tblwznmamvectortitle->removeRecByRef(vecAtit->ref);
		};

		for (unsigned int ix1 = 0; ix1 < vec->imeimvectoritem.nodes.size(); ix1++) {
			vit = vec->imeimvectoritem.nodes[ix1];
			if (vit->ref != 0) dbswznm->tblwznmmvectoritem->removeRecByRef(vit->ref);

			for (unsigned int ix2 = 0; ix2 < vit->imeijmvectoritem.nodes.size(); ix2++) {
				vitJ = vit->imeijmvectoritem.nodes[ix2];
				if (vitJ->ref != 0) dbswznm->tblwznmjmvectoritem->removeRecByRef(vitJ->ref);
			};
		};
	};

	return retval;
};

void JobWznmIexGbl::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexGbl::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMBlock* blk = NULL;
	ImeitemIMCapability* cpb = NULL;
	ImeitemIMError* err = NULL;
	ImeitemIMVector* vec = NULL;
	ImeitemIAMBlockItem* blkAitm = NULL;
	ImeitemIAMCapabilityPar* cpbApar = NULL;
	ImeitemIAMVectorTitle* vecAtit = NULL;
	ImeitemICAMBlockItem* blkAitmC = NULL;
	ImeitemIJMErrorTitle* errJtit = NULL;
	ImeitemIMVectoritem* vit = NULL;
	ImeitemIJAMBlockItem* bitJ = NULL;
	ImeitemIJMVectoritem* vitJ = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMBlock
	for (unsigned int ix0 = 0; ix0 < imeimblock.nodes.size(); ix0++) {
		blk = imeimblock.nodes[ix0];

		if (blk->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMBLOCKITEM, ixWznmVIop)) {
			dbswznm->tblwznmamblockitem->loadRefsByBlk(blk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) blk->imeiamblockitem.nodes.push_back(new ImeitemIAMBlockItem(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < blk->imeiamblockitem.nodes.size(); ix1++) {
			blkAitm = blk->imeiamblockitem.nodes[ix1];

			if (blkAitm->ref != 0) {
				//blkAitm->irefRefWznmCAMBlockItem: IREF
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAMBLOCKITEM, ixWznmVIop)) {
				dbswznm->tblwznmjamblockitem->loadRefsByBit(blkAitm->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) blkAitm->imeijamblockitem.nodes.push_back(new ImeitemIJAMBlockItem(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < blkAitm->imeijamblockitem.nodes.size(); ix2++) {
				bitJ = blkAitm->imeijamblockitem.nodes[ix2];

				if (bitJ->ref != 0) {
					bitJ->srefX1RefWznmMRelease = StubWznm::getStubRlsStd(dbswznm, bitJ->x1RefWznmMRelease, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < blk->imeicamblockitem.nodes.size(); ix1++) {
			blkAitmC = blk->imeicamblockitem.nodes[ix1];

			if (blkAitmC->ref != 0) {
				blkAitmC->iref = ix1+1;
			};
		};
	};

	// -- ImeIMCapability
	for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
		cpb = imeimcapability.nodes[ix0];

		if (cpb->ref != 0) {
			//cpb->srefTplRefWznmMCapability: STUB
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMCAPABILITYPAR, ixWznmVIop)) {
			dbswznm->tblwznmamcapabilitypar->loadRefsByCpb(cpb->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cpb->imeiamcapabilitypar.nodes.push_back(new ImeitemIAMCapabilityPar(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeiamcapabilitypar.nodes.size(); ix1++) {
			cpbApar = cpb->imeiamcapabilitypar.nodes[ix1];

			if (cpbApar->ref != 0) {
			};
		};
	};

	// -- ImeIMError
	for (unsigned int ix0 = 0; ix0 < imeimerror.nodes.size(); ix0++) {
		err = imeimerror.nodes[ix0];

		if (err->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMERRORTITLE, ixWznmVIop)) {
			dbswznm->tblwznmjmerrortitle->loadRefsByErr(err->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == err->refJTitle) {refs[i] = refs[0]; refs[0] = err->refJTitle; break;};
			for (unsigned int i = 0; i < refs.size(); i++) err->imeijmerrortitle.nodes.push_back(new ImeitemIJMErrorTitle(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < err->imeijmerrortitle.nodes.size(); ix1++) {
			errJtit = err->imeijmerrortitle.nodes[ix1];

			if (errJtit->ref != 0) {
				errJtit->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, errJtit->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMVector
	for (unsigned int ix0 = 0; ix0 < imeimvector.nodes.size(); ix0++) {
		vec = imeimvector.nodes[ix0];

		if (vec->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMVECTORTITLE, ixWznmVIop)) {
			dbswznm->tblwznmamvectortitle->loadRefsByVec(vec->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) vec->imeiamvectortitle.nodes.push_back(new ImeitemIAMVectorTitle(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < vec->imeiamvectortitle.nodes.size(); ix1++) {
			vecAtit = vec->imeiamvectortitle.nodes[ix1];

			if (vecAtit->ref != 0) {
				vecAtit->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, vecAtit->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMVECTORITEM, ixWznmVIop)) {
			dbswznm->tblwznmmvectoritem->loadRefsByVec(vec->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) vec->imeimvectoritem.nodes.push_back(new ImeitemIMVectoritem(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < vec->imeimvectoritem.nodes.size(); ix1++) {
			vit = vec->imeimvectoritem.nodes[ix1];

			if (vit->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMVECTORITEM, ixWznmVIop)) {
				dbswznm->tblwznmjmvectoritem->loadRefsByVit(vit->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == vit->refJ) {refs[i] = refs[0]; refs[0] = vit->refJ; break;};
				for (unsigned int i = 0; i < refs.size(); i++) vit->imeijmvectoritem.nodes.push_back(new ImeitemIJMVectoritem(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < vit->imeijmvectoritem.nodes.size(); ix2++) {
				vitJ = vit->imeijmvectoritem.nodes[ix2];

				if (vitJ->ref != 0) {
					vitJ->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, vitJ->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexGbl::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexGbl::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexGbl::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexGbl::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmGbl::exportToFile(fullpath, xmlNotTxt, shorttags, imeimblock, imeimcapability, imeimerror, imeimvector);

	return retval;
};

void JobWznmIexGbl::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexGbl::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexGbl::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};



