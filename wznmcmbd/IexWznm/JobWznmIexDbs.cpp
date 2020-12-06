/**
	* \file JobWznmIexDbs.cpp
	* job handler for job JobWznmIexDbs (implementation)
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

#include "JobWznmIexDbs.h"

#include "JobWznmIexDbs_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmDbs;

/******************************************************************************
 class JobWznmIexDbs
 ******************************************************************************/

JobWznmIexDbs::JobWznmIexDbs(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXDBS, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexDbs::~JobWznmIexDbs() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexDbs::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexDbs::parseFromFile(
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

void JobWznmIexDbs::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexDbs::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexDbs::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexDbs::exportToFile(
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

void JobWznmIexDbs::handleRequest(
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

void JobWznmIexDbs::changeStage(
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

string JobWznmIexDbs::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing database structure";
			else if (ixVSge == VecVSge::PRSDONE) retval = "database structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing database structure (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing database structure import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting database structure for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "database structure collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting database structure";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexDbs::enterSgeIdle(
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

	imeicrelation.clear();
	imeimrelation.clear();
	imeimstub.clear();
	imeimtable.clear();
	imeimvector1.clear();
	imeirmstubmstub.clear();

	return retval;
};

void JobWznmIexDbs::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexDbs::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmDbs::parseFromFile(fullpath, xmlNotTxt, rectpath, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexDbs::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexDbs::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexDbs::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexDbs::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexDbs::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexDbs::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemICRelation* relC = NULL;
	ImeitemIMRelation* rel = NULL;
	ImeitemIMStub* stb = NULL;
	ImeitemIMTable* tbl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIRMStubMStub* stbRstb = NULL;
	ImeitemIAMRelationTitle* relAtit = NULL;
	ImeitemIAMTableLoadfct* tblAlfc = NULL;
	ImeitemIAMTableTitle* tblAtit = NULL;
	ImeitemIAMVectorTitle1* vecAtit1 = NULL;
	ImeitemIMCheck* chk = NULL;
	ImeitemIMSubset* sbs = NULL;
	ImeitemIMTablecol* tco = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIRMTableMVector1* tblRvec1 = NULL;
	ImeitemIAMSubsetTitle* sbsAtit = NULL;
	ImeitemIAMTablecolTitle* tcoAtit = NULL;
	ImeitemIAMVectorTitle2* vecAtit2 = NULL;
	ImeitemIJMVectoritem1* vitJ1 = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;
	ImeitemIRMSubsetMSubset* sbsRsbs = NULL;
	ImeitemIRMTableMVector2* tblRvec2 = NULL;
	ImeitemIJMVectoritem2* vitJ2 = NULL;

	set<ubigint> irefs0;

	uint num1, num2;

	// IP enterSgeImport.prep --- IBEGIN
	ImeitemIMTable* tbl2 = NULL;
	ImeitemIMSubset* sbs2 = NULL;
	ImeitemIMRelation* rel2 = NULL;

	ubigint ref;

	ubigint refWznmMVersion;
	string preflcl;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	Wznm::getVerlclsref(dbswznm, refWznmMVersion, preflcl);

	ListWznmMLocale lcls;

	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN
		// -- ImeIMVector1
		for (unsigned int ix0 = 0; ix0 < imeimvector1.nodes.size(); ix0++) {
			vec1 = imeimvector1.nodes[ix0];

			vec1->ixVBasetype = VecWznmVMVectorBasetype::getIx(vec1->srefIxVBasetype);
			if (vec1->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec1->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec1->lineno)}});
			vec1->refWznmMVersion = refWznmMVersion;
			vec1->hkIxVTbl = VecWznmVMVectorHkTbl::TBL;
			//vec1->sref: TBL
			//vec1->osrefWznmKTaggrp: TBL
			//vec1->srefsKOption: TBL

			dbswznm->tblwznmmvector->insertRec(vec1);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < vec1->imeiamvectortitle1.nodes.size(); ix1++) {
				vecAtit1 = vec1->imeiamvectortitle1.nodes[ix1];

				vecAtit1->refWznmMVector = vec1->ref;
				vecAtit1->x1IxVType = VecWznmVAMVectorTitleType::getIx(vecAtit1->srefX1IxVType);
				if (vecAtit1->x1IxVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vecAtit1->srefX1IxVType}, {"iel","srefX1IxVType"}, {"lineno",to_string(vecAtit1->lineno)}});
				//vecAtit1->x2RefWznmMLocale: RST
				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					if (lcls.nodes[i]->sref == vecAtit1->srefX2RefWznmMLocale) {
						vecAtit1->x2RefWznmMLocale = lcls.nodes[i]->ref;
						break;
					};
				};
				if (vecAtit1->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",vecAtit1->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(vecAtit1->lineno)}});
				//vecAtit1->Title: TBL

				dbswznm->tblwznmamvectortitle->insertRec(vecAtit1);
				impcnt++;
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < vec1->imeimvectoritem1.nodes.size(); ix1++) {
				vit1 = vec1->imeimvectoritem1.nodes[ix1];

				vit1->vecRefWznmMVector = vec1->ref;
				vit1->vecNum = num1++;
				//vit1->sref: TBL
				//vit1->Avail: TBL
				//vit1->Implied: TBL
				//vit1->refJ: SUB
				//vit1->Title: TBL
				//vit1->Comment: TBL

				dbswznm->tblwznmmvectoritem->insertRec(vit1);
				impcnt++;

				if (((vit1->Title != "") || (vit1->Comment != "")) && vit1->imeijmvectoritem1.nodes.empty()) {
					vitJ1 = new ImeitemIJMVectoritem1();
					vit1->imeijmvectoritem1.nodes.push_back(vitJ1);

					vitJ1->refWznmMVectoritem = vit1->ref;
					vitJ1->Title = vit1->Title;
					vitJ1->Comment = vit1->Comment;
				};

				for (unsigned int ix2 = 0; ix2 < vit1->imeijmvectoritem1.nodes.size(); ix2++) {
					vitJ1 = vit1->imeijmvectoritem1.nodes[ix2];

					vitJ1->refWznmMVectoritem = vit1->ref;
					//if (vitJ1->srefX1RefWznmMLocale == "") vitJ1->srefX1RefWznmMLocale: CUSTOM DEFVAL
					if (vitJ1->srefX1RefWznmMLocale == "") vitJ1->srefX1RefWznmMLocale = preflcl;
					//vitJ1->x1RefWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
						if (lcls.nodes[i]->sref == vitJ1->srefX1RefWznmMLocale) {
							vitJ1->x1RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					};
					if (vitJ1->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",vitJ1->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(vitJ1->lineno)}});
					//vitJ1->Title: TBL
					//vitJ1->Comment: TBL

					dbswznm->tblwznmjmvectoritem->insertRec(vitJ1);
					impcnt++;

					if (ix2 == 0) {
						vit1->refJ = vitJ1->ref;
						vit1->Title = vitJ1->Title;
						vit1->Comment = vitJ1->Comment;
						dbswznm->tblwznmmvectoritem->updateRec(vit1);
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < vec1->imeirmtablemvector1.nodes.size(); ix1++) {
				tblRvec1 = vec1->imeirmtablemvector1.nodes[ix1];

				//tblRvec1->refWznmMTable: IMPPP
				//tblRvec1->refWznmMSubset: IMPPP
				tblRvec1->refWznmMVector = vec1->ref;

				dbswznm->tblwznmrmtablemvector->insertRec(tblRvec1);
				impcnt++;
			};
		};

		// -- ImeIMTable
		for (unsigned int ix0 = 0; ix0 < imeimtable.nodes.size(); ix0++) {
			tbl = imeimtable.nodes[ix0];

			tbl->ixVBasetype = VecWznmVMTableBasetype::getIx(tbl->srefIxVBasetype);
			if (tbl->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tbl->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(tbl->lineno)}});
			tbl->refWznmMVersion = refWznmMVersion;
			tbl->refIxVTbl = VecWznmVMTableRefTbl::getIx(tbl->srefRefIxVTbl);
			if (tbl->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tbl->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(tbl->lineno)}});
			//tbl->refUref: IMPPP
			//tbl->sref: TBL
			//tbl->Short: TBL
			//tbl->unqSrefsWznmMTablecol: TBL
			//tbl->Comment: TBL

			dbswznm->tblwznmmtable->insertRec(tbl);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < tbl->imeiamtabletitle.nodes.size(); ix1++) {
				tblAtit = tbl->imeiamtabletitle.nodes[ix1];

				tblAtit->refWznmMTable = tbl->ref;
				tblAtit->x1IxVType = VecWznmVAMTableTitleType::getIx(tblAtit->srefX1IxVType);
				if (tblAtit->x1IxVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tblAtit->srefX1IxVType}, {"iel","srefX1IxVType"}, {"lineno",to_string(tblAtit->lineno)}});
				//tblAtit->x2RefWznmMLocale: RST
				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					if (lcls.nodes[i]->sref == tblAtit->srefX2RefWznmMLocale) {
						tblAtit->x2RefWznmMLocale = lcls.nodes[i]->ref;
						break;
					};
				};
				if (tblAtit->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",tblAtit->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(tblAtit->lineno)}});
				tblAtit->ixWznmVGender = VecWznmVGender::getIx(tblAtit->srefIxWznmVGender);
				if (tblAtit->ixWznmVGender == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tblAtit->srefIxWznmVGender}, {"iel","srefIxWznmVGender"}, {"lineno",to_string(tblAtit->lineno)}});
				//tblAtit->Title: TBL

				dbswznm->tblwznmamtabletitle->insertRec(tblAtit);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < tbl->imeimsubset.nodes.size(); ix1++) {
				sbs = tbl->imeimsubset.nodes[ix1];

				sbs->refWznmMTable = tbl->ref;
				//sbs->sref: TBL
				//sbs->Short: TBL
				//sbs->Cond: TBL
				//sbs->Comment: TBL

				dbswznm->tblwznmmsubset->insertRec(sbs);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < sbs->imeiamsubsettitle.nodes.size(); ix2++) {
					sbsAtit = sbs->imeiamsubsettitle.nodes[ix2];

					sbsAtit->refWznmMSubset = sbs->ref;
					sbsAtit->x1IxVType = VecWznmVAMSubsetTitleType::getIx(sbsAtit->srefX1IxVType);
					if (sbsAtit->x1IxVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sbsAtit->srefX1IxVType}, {"iel","srefX1IxVType"}, {"lineno",to_string(sbsAtit->lineno)}});
					//sbsAtit->x2RefWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
						if (lcls.nodes[i]->sref == sbsAtit->srefX2RefWznmMLocale) {
							sbsAtit->x2RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					};
					if (sbsAtit->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sbsAtit->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(sbsAtit->lineno)}});
					sbsAtit->ixWznmVGender = VecWznmVGender::getIx(sbsAtit->srefIxWznmVGender);
					if (sbsAtit->ixWznmVGender == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sbsAtit->srefIxWznmVGender}, {"iel","srefIxWznmVGender"}, {"lineno",to_string(sbsAtit->lineno)}});
					//sbsAtit->Title: TBL

					dbswznm->tblwznmamsubsettitle->insertRec(sbsAtit);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < sbs->imeirmsubsetmsubset.nodes.size(); ix2++) {
					sbsRsbs = sbs->imeirmsubsetmsubset.nodes[ix2];

					sbsRsbs->asbRefWznmMSubset = sbs->ref;
					//sbsRsbs->bsbRefWznmMSubset: IMPPP
					sbsRsbs->ixVReltype = VecWznmVRMSubsetMSubsetReltype::getIx(sbsRsbs->srefIxVReltype);
					if (sbsRsbs->ixVReltype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",sbsRsbs->srefIxVReltype}, {"iel","srefIxVReltype"}, {"lineno",to_string(sbsRsbs->lineno)}});

					dbswznm->tblwznmrmsubsetmsubset->insertRec(sbsRsbs);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < tbl->imeimvector2.nodes.size(); ix1++) {
				vec2 = tbl->imeimvector2.nodes[ix1];

				vec2->ixVBasetype = VecWznmVMVectorBasetype::getIx(vec2->srefIxVBasetype);
				if (vec2->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec2->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec2->lineno)}});
				vec2->refWznmMVersion = refWznmMVersion;
				vec2->hkIxVTbl = VecWznmVMVectorHkTbl::TBL;
				vec2->hkUref = tbl->ref;
				//vec2->sref: TBL
				//vec2->osrefWznmKTaggrp: TBL
				//vec2->srefsKOption: TBL

				dbswznm->tblwznmmvector->insertRec(vec2);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < vec2->imeiamvectortitle2.nodes.size(); ix2++) {
					vecAtit2 = vec2->imeiamvectortitle2.nodes[ix2];

					vecAtit2->refWznmMVector = vec2->ref;
					vecAtit2->x1IxVType = VecWznmVAMVectorTitleType::getIx(vecAtit2->srefX1IxVType);
					if (vecAtit2->x1IxVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vecAtit2->srefX1IxVType}, {"iel","srefX1IxVType"}, {"lineno",to_string(vecAtit2->lineno)}});
					//vecAtit2->x2RefWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
						if (lcls.nodes[i]->sref == vecAtit2->srefX2RefWznmMLocale) {
							vecAtit2->x2RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					};
					if (vecAtit2->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",vecAtit2->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(vecAtit2->lineno)}});
					//vecAtit2->Title: TBL

					dbswznm->tblwznmamvectortitle->insertRec(vecAtit2);
					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < vec2->imeimvectoritem2.nodes.size(); ix2++) {
					vit2 = vec2->imeimvectoritem2.nodes[ix2];

					vit2->vecRefWznmMVector = vec2->ref;
					vit2->vecNum = num2++;
					//vit2->sref: TBL
					//vit2->Avail: TBL
					//vit2->Implied: TBL
					//vit2->refJ: SUB
					//vit2->Title: TBL
					//vit2->Comment: TBL

					dbswznm->tblwznmmvectoritem->insertRec(vit2);
					impcnt++;

					if (((vit2->Title != "") || (vit2->Comment != "")) && vit2->imeijmvectoritem2.nodes.empty()) {
						vitJ2 = new ImeitemIJMVectoritem2();
						vit2->imeijmvectoritem2.nodes.push_back(vitJ2);

						vitJ2->refWznmMVectoritem = vit2->ref;
						vitJ2->Title = vit2->Title;
						vitJ2->Comment = vit2->Comment;
					};

					for (unsigned int ix3 = 0; ix3 < vit2->imeijmvectoritem2.nodes.size(); ix3++) {
						vitJ2 = vit2->imeijmvectoritem2.nodes[ix3];

						vitJ2->refWznmMVectoritem = vit2->ref;
						//vitJ2->x1RefWznmMLocale: RST
						//if (vitJ2->srefX1RefWznmMLocale == "") vitJ2->srefX1RefWznmMLocale: CUSTOM DEFVAL
						if (vitJ2->srefX1RefWznmMLocale == "") vitJ2->srefX1RefWznmMLocale = preflcl;
						for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
							if (lcls.nodes[i]->sref == vitJ2->srefX1RefWznmMLocale) {
								vitJ2->x1RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						};
						if (vitJ2->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",vitJ2->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(vitJ2->lineno)}});
						//vitJ2->Title: TBL
						//vitJ2->Comment: TBL

						dbswznm->tblwznmjmvectoritem->insertRec(vitJ2);
						impcnt++;

						if (ix3 == 0) {
							vit2->refJ = vitJ2->ref;
							vit2->Title = vitJ2->Title;
							vit2->Comment = vitJ2->Comment;
							dbswznm->tblwznmmvectoritem->updateRec(vit2);
						};
					};
				};

				for (unsigned int ix2 = 0; ix2 < vec2->imeirmtablemvector2.nodes.size(); ix2++) {
					tblRvec2 = vec2->imeirmtablemvector2.nodes[ix2];

					//tblRvec2->refWznmMTable: IMPPP
					//tblRvec2->refWznmMSubset: IMPPP
					tblRvec2->refWznmMVector = vec2->ref;

					dbswznm->tblwznmrmtablemvector->insertRec(tblRvec2);
					impcnt++;
				};
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < tbl->imeimtablecol.nodes.size(); ix1++) {
				tco = tbl->imeimtablecol.nodes[ix1];

				tco->ixVBasetype = VecWznmVMTablecolBasetype::getIx(tco->srefIxVBasetype);
				if (tco->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tco->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(tco->lineno)}});
				tco->tblRefWznmMTable = tbl->ref;
				tco->tblNum = num1++;
				//tco->refWznmMSubset: IMPPP
				//tco->refWznmMRelation: IMPPP
				tco->fctIxVTbl = VecWznmVMTablecolFctTbl::getIx(tco->srefFctIxVTbl);
				if (tco->fctIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tco->srefFctIxVTbl}, {"iel","srefFctIxVTbl"}, {"lineno",to_string(tco->lineno)}});
				//tco->fctUref: IMPPP
				//tco->sref: TBL
				//tco->Short: TBL
				tco->ixVSubtype = VecWznmVMTablecolSubtype::getIx(tco->srefIxVSubtype);
				if (tco->ixVSubtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tco->srefIxVSubtype}, {"iel","srefIxVSubtype"}, {"lineno",to_string(tco->lineno)}});
				tco->ixVAxisfct = VecWznmVMTablecolAxisfct::getIx(tco->srefIxVAxisfct);
				if (tco->ixVAxisfct == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tco->srefIxVAxisfct}, {"iel","srefIxVAxisfct"}, {"lineno",to_string(tco->lineno)}});
				//tco->srefsKOption: TBL
				//tco->Principal: TBL
				//tco->Eponymous: TBL

				dbswznm->tblwznmmtablecol->insertRec(tco);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < tco->imeiamtablecoltitle.nodes.size(); ix2++) {
					tcoAtit = tco->imeiamtablecoltitle.nodes[ix2];

					tcoAtit->refWznmMTablecol = tco->ref;
					tcoAtit->x1IxVType = VecWznmVAMTablecolTitleType::getIx(tcoAtit->srefX1IxVType);
					if (tcoAtit->x1IxVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tcoAtit->srefX1IxVType}, {"iel","srefX1IxVType"}, {"lineno",to_string(tcoAtit->lineno)}});
					//tcoAtit->x2RefWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
						if (lcls.nodes[i]->sref == tcoAtit->srefX2RefWznmMLocale) {
							tcoAtit->x2RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					};
					if (tcoAtit->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",tcoAtit->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(tcoAtit->lineno)}});
					//tcoAtit->Title: TBL

					dbswznm->tblwznmamtablecoltitle->insertRec(tcoAtit);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < tbl->imeiamtableloadfct.nodes.size(); ix1++) {
				tblAlfc = tbl->imeiamtableloadfct.nodes[ix1];

				tblAlfc->refWznmMTable = tbl->ref;
				tblAlfc->ixVLoadtype = VecWznmVAMTableLoadfctLoadtype::getIx(tblAlfc->srefIxVLoadtype);
				if (tblAlfc->ixVLoadtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tblAlfc->srefIxVLoadtype}, {"iel","srefIxVLoadtype"}, {"lineno",to_string(tblAlfc->lineno)}});
				//tblAlfc->Fctname: TBL
				//tblAlfc->ldSrefWznmMTablecol: TBL
				//tblAlfc->lbySrefsWznmMTablecol: TBL
				//tblAlfc->ordSrefsWznmMTablecol: TBL
				tblAlfc->ixVLimtype = VecWznmVAMTableLoadfctLimtype::getIx(tblAlfc->srefIxVLimtype);
				if (tblAlfc->ixVLimtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",tblAlfc->srefIxVLimtype}, {"iel","srefIxVLimtype"}, {"lineno",to_string(tblAlfc->lineno)}});

				dbswznm->tblwznmamtableloadfct->insertRec(tblAlfc);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < tbl->imeimcheck.nodes.size(); ix1++) {
				chk = tbl->imeimcheck.nodes[ix1];

				chk->ixVBasetype = VecWznmVMCheckBasetype::getIx(chk->srefIxVBasetype);
				if (chk->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",chk->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(chk->lineno)}});
				chk->refWznmMTable = tbl->ref;
				//chk->refWznmMTablecol: PREVIMP
				if (chk->srefRefWznmMTablecol != "") {
					for (unsigned int i = 0; i < tbl->imeimtablecol.nodes.size(); i++) {
						tco = tbl->imeimtablecol.nodes[i];
						if (tco->sref == chk->srefRefWznmMTablecol) {
							chk->refWznmMTablecol = tco->ref;
							break;
						};
					};
					if (chk->refWznmMTablecol == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",chk->srefRefWznmMTablecol}, {"iel","srefRefWznmMTablecol"}, {"lineno",to_string(chk->lineno)}});
				};
				//chk->sref: TBL
				//chk->Comment: TBL

				dbswznm->tblwznmmcheck->insertRec(chk);
				impcnt++;
			};
		};

		// -- ImeICRelation
		irefs0.clear();

		for (unsigned int ix0 = 0; ix0 < imeicrelation.nodes.size(); ix0++) {
			relC = imeicrelation.nodes[ix0];

			if (irefs0.find(relC->iref) != irefs0.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(relC->iref)}, {"ime","ImeICRelation"}, {"lineno",to_string(relC->lineno)}});
			relC->ref = dbswznm->tblwznmcrelation->getNewRef();
			irefs0.insert(relC->iref);

			impcnt++;
		};

		// -- ImeIMRelation
		irefs0.clear();

		for (unsigned int ix0 = 0; ix0 < imeimrelation.nodes.size(); ix0++) {
			rel = imeimrelation.nodes[ix0];

			if (irefs0.find(rel->iref) != irefs0.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(rel->iref)}, {"ime","ImeIMRelation"}, {"lineno",to_string(rel->lineno)}});
			rel->ixVBasetype = VecWznmVMRelationBasetype::getIx(rel->srefIxVBasetype);
			if (rel->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",rel->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(rel->lineno)}});
			//rel->refWznmCRelation: PREVIMP
			if (rel->irefRefWznmCRelation != 0) {
				for (unsigned int ix1 = 0; ix1 < imeicrelation.nodes.size(); ix1++) {
					relC = imeicrelation.nodes[ix1];

					if (relC->iref == rel->irefRefWznmCRelation) {
						rel->refWznmCRelation = relC->ref;
						break;
					};
				};
				if (rel->refWznmCRelation == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(rel->irefRefWznmCRelation)}, {"iel","irefRefWznmCRelation"}, {"lineno",to_string(rel->lineno)}});
			};
			rel->refWznmMVersion = refWznmMVersion;
			//rel->supRefWznmMRelation: IMPPP
			rel->supIxVSubrole = VecWznmVMRelationSupSubrole::getIx(rel->srefSupIxVSubrole);
			if (rel->supIxVSubrole == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",rel->srefSupIxVSubrole}, {"iel","srefSupIxVSubrole"}, {"lineno",to_string(rel->lineno)}});
			if (rel->srefFrRefWznmMTable != "") {
				//rel->frRefWznmMTable: PREVIMP
				for (unsigned int i = 0; i < imeimtable.nodes.size(); i++) {
					tbl = imeimtable.nodes[i];

					if (tbl->sref == rel->srefFrRefWznmMTable) {
						rel->frRefWznmMTable = tbl->ref;

						if (rel->srefFrsRefWznmMSubset != "") {
							//rel->frsRefWznmMSubset: PREVIMP

							for (unsigned int j = 0; j < tbl->imeimsubset.nodes.size(); j++) {
								sbs = tbl->imeimsubset.nodes[j];

								if (sbs->sref == rel->srefFrsRefWznmMSubset) {
									rel->frsRefWznmMSubset = sbs->ref;
									break;
								};
							};
							if (rel->frsRefWznmMSubset == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rel->srefFrsRefWznmMSubset}, {"iel","srefFrsRefWznmMSubset"}, {"lineno",to_string(rel->lineno)}});
						};
						break;
					};
				};
				if (rel->frRefWznmMTable == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rel->srefFrRefWznmMTable}, {"iel","srefFrRefWznmMTable"}, {"lineno",to_string(rel->lineno)}});
			};
			if (rel->srefToRefWznmMTable != "") {
				//rel->toRefWznmMTable: PREVIMP
				for (unsigned int ix1 = 0; ix1 < imeimtable.nodes.size(); ix1++) {
					tbl = imeimtable.nodes[ix1];

					if (tbl->sref == rel->srefToRefWznmMTable) {
						rel->toRefWznmMTable = tbl->ref;

						if (rel->srefTosRefWznmMSubset != "") {
							//rel->tosRefWznmMSubset: PREVIMP
							for (unsigned int ix2 = 0; ix2 < tbl->imeimsubset.nodes.size(); ix2++) {
								sbs = tbl->imeimsubset.nodes[ix2];

								if (sbs->sref == rel->srefTosRefWznmMSubset) {
									rel->tosRefWznmMSubset = sbs->ref;
									break;
								};
							};
							if (rel->tosRefWznmMSubset == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rel->srefTosRefWznmMSubset}, {"iel","srefTosRefWznmMSubset"}, {"lineno",to_string(rel->lineno)}});
						};
						break;
					};
				};
				if (rel->toRefWznmMTable == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rel->srefToRefWznmMTable}, {"iel","srefToRefWznmMTable"}, {"lineno",to_string(rel->lineno)}});
			};
			//rel->refWznmMTable: PREVIMP
			if (rel->srefRefWznmMTable != "") {
				for (unsigned int ix1 = 0; ix1 < imeimtable.nodes.size(); ix1++) {
					tbl = imeimtable.nodes[ix1];

					if (tbl->sref == rel->srefRefWznmMTable) {
						rel->refWznmMTable = tbl->ref;
						break;
					};
				};
				if (rel->refWznmMTable == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",rel->srefRefWznmMTable}, {"iel","srefRefWznmMTable"}, {"lineno",to_string(rel->lineno)}});
			};
			//rel->Prefix: TBL
			//rel->srefsKOption: TBL

			dbswznm->tblwznmmrelation->insertRec(rel);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < rel->imeiamrelationtitle.nodes.size(); ix1++) {
				relAtit = rel->imeiamrelationtitle.nodes[ix1];

				relAtit->refWznmMRelation = rel->ref;
				relAtit->x1IxVType = VecWznmVAMRelationTitleType::getIx(relAtit->srefX1IxVType);
				if (relAtit->x1IxVType == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",relAtit->srefX1IxVType}, {"iel","srefX1IxVType"}, {"lineno",to_string(relAtit->lineno)}});
				//relAtit->x2RefWznmMLocale: RST
				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					if (lcls.nodes[i]->sref == relAtit->srefX2RefWznmMLocale) {
						relAtit->x2RefWznmMLocale = lcls.nodes[i]->ref;
						break;
					};
				};
				if (relAtit->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",relAtit->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(relAtit->lineno)}});
				//relAtit->Title: TBL

				dbswznm->tblwznmamrelationtitle->insertRec(relAtit);
				impcnt++;
			};
		};

		// -- ImeIMStub
		for (unsigned int ix0 = 0; ix0 < imeimstub.nodes.size(); ix0++) {
			stb = imeimstub.nodes[ix0];

			stb->ixVBasetype = VecWznmVMStubBasetype::getIx(stb->srefIxVBasetype);
			if (stb->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",stb->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(stb->lineno)}});
			//stb->refWznmMTable: PREVIMP
			for (unsigned int ix1 = 0; ix1 < imeimtable.nodes.size(); ix1++) {
				tbl = imeimtable.nodes[ix1];

				if (tbl->sref == stb->srefRefWznmMTable) {
					stb->refWznmMTable = tbl->ref;

					if (stb->srefRefWznmMSubset != "") { 
						//stb->refWznmMSubset: PREVIMP
						for (unsigned int ix2 = 0; ix2 < tbl->imeimsubset.nodes.size(); ix2++) {
							sbs = tbl->imeimsubset.nodes[ix2];

							if (sbs->sref == stb->srefRefWznmMSubset) {
								stb->refWznmMSubset = sbs->ref;
								break;
							};
						};
						if (stb->refWznmMSubset == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",stb->srefRefWznmMSubset}, {"iel","srefRefWznmMSubset"}, {"lineno",to_string(stb->lineno)}});
					};
					break;
				};
			};
			if (stb->refWznmMTable == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",stb->srefRefWznmMTable}, {"iel","srefRefWznmMTable"}, {"lineno",to_string(stb->lineno)}});
			//stb->sref: TBL
			//stb->Hierarch: TBL
			if (stb->srefRefWznmMTablecol != "") {
				//stb->refWznmMTablecol: PREVIMP
				for (unsigned int ix1 = 0; ix1 < imeimtable.nodes.size(); ix1++) {
					tbl = imeimtable.nodes[ix1];

					if (tbl->ref == stb->refWznmMTable) {
						for (unsigned int ix2 = 0; ix2 < tbl->imeimtablecol.nodes.size(); ix2++) {
							tco = tbl->imeimtablecol.nodes[ix2];

							if (tco->sref == stb->srefRefWznmMTablecol) {
								stb->refWznmMTablecol = tco->ref;
								break;
							};
						};
						break;
					};
				};
				if (stb->refWznmMTablecol == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",stb->srefRefWznmMTablecol}, {"iel","srefRefWznmMTablecol"}, {"lineno",to_string(stb->lineno)}});
			};
			//stb->Localized: TBL
			//stb->Example: TBL

			dbswznm->tblwznmmstub->insertRec(stb);
			impcnt++;
		};

		// -- ImeIRMStubMStub
		for (unsigned int ix0 = 0; ix0 < imeirmstubmstub.nodes.size(); ix0++) {
			stbRstb = imeirmstubmstub.nodes[ix0];

			//stbRstb->supRefWznmMStub: PREVIMP
			for (unsigned int ix1 = 0; ix1 < imeimstub.nodes.size(); ix1++) {
				stb = imeimstub.nodes[ix1];

				if (stb->sref == stbRstb->srefSupRefWznmMStub) {
					stbRstb->supRefWznmMStub = stb->ref;
					break;
				};
			};
			if (stbRstb->supRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",stbRstb->srefSupRefWznmMStub}, {"iel","srefSupRefWznmMStub"}, {"lineno",to_string(stbRstb->lineno)}});
			//stbRstb->subRefWznmMStub: PREVIMP
			for (unsigned int ix1 = 0; ix1 < imeimstub.nodes.size(); ix1++) {
				stb = imeimstub.nodes[ix1];

				if (stb->sref == stbRstb->srefSubRefWznmMStub) {
					stbRstb->subRefWznmMStub = stb->ref;
					break;
				};
			};
			if (stbRstb->subRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",stbRstb->srefSubRefWznmMStub}, {"iel","srefSubRefWznmMStub"}, {"lineno",to_string(stbRstb->lineno)}});

			dbswznm->tblwznmrmstubmstub->insertRec(stbRstb);
			impcnt++;
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		// -- MVector
		for (unsigned int ix0 = 0; ix0 < imeimvector1.nodes.size(); ix0++) {
			vec1 = imeimvector1.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < vec1->imeirmtablemvector1.nodes.size(); ix1++) {
				tblRvec1 = vec1->imeirmtablemvector1.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < imeimtable.nodes.size(); ix2++) {
					tbl = imeimtable.nodes[ix2];

					if (tbl->sref == tblRvec1->srefRefWznmMTable) {
						tblRvec1->refWznmMTable = tbl->ref;

						for (unsigned int ix3 = 0; ix3 < tbl->imeimsubset.nodes.size(); ix3++) {
							sbs = tbl->imeimsubset.nodes[ix3];

							if (sbs->sref == tblRvec1->srefRefWznmMSubset) {
								tblRvec1->refWznmMSubset = sbs->ref;
								break;
							};
						};

						break;
					};
				};

				dbswznm->tblwznmrmtablemvector->updateRec(tblRvec1);
			};
		};

		// -- MTable
		for (unsigned int ix0 = 0; ix0 < imeimtable.nodes.size(); ix0++) {
			tbl = imeimtable.nodes[ix0];

			if (tbl->refIxVTbl == VecWznmVMTableRefTbl::REL) {
				for (unsigned int ix1 = 0; ix1 < imeimrelation.nodes.size(); ix1++) {
					rel = imeimrelation.nodes[ix1];

					if (rel->iref == tbl->irefRefUref) {
						tbl->refUref = rel->ref;
						break;
					};
				};

				dbswznm->tblwznmmtable->updateRec(tbl);
			};

			for (unsigned int ix1 = 0; ix1 < tbl->imeimsubset.nodes.size(); ix1++) {
				sbs = tbl->imeimsubset.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < sbs->imeirmsubsetmsubset.nodes.size(); ix2++) {
					sbsRsbs = sbs->imeirmsubsetmsubset.nodes[ix2];

					for (unsigned int i = 0; i < tbl->imeimsubset.nodes.size(); i++) {
						sbs2 = tbl->imeimsubset.nodes[i];
				
						if (sbs2->sref == sbsRsbs->srefBsbRefWznmMSubset) {
							sbsRsbs->bsbRefWznmMSubset = sbs2->ref;
							break;
						};
					};

					dbswznm->tblwznmrmsubsetmsubset->updateRec(sbsRsbs);
				};
			};

			for (unsigned int ix1 = 0; ix1 < tbl->imeimvector2.nodes.size(); ix1++) {
				vec2 = tbl->imeimvector2.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < vec2->imeirmtablemvector2.nodes.size(); ix2++) {
					tblRvec2 = vec2->imeirmtablemvector2.nodes[ix2];

					for (unsigned int i = 0; i < imeimtable.nodes.size(); i++) {
						tbl2 = imeimtable.nodes[i];

						if (tbl2->sref == tblRvec2->srefRefWznmMTable) {
							tblRvec2->refWznmMTable = tbl2->ref;

							for (unsigned int j = 0; j < tbl2->imeimsubset.nodes.size(); j++) {
								sbs2 = tbl2->imeimsubset.nodes[j];

								if (sbs2->sref == tblRvec2->srefRefWznmMSubset) {
									tblRvec2->refWznmMSubset = sbs2->ref;
									break;
								};
							};

							break;
						};
					};

					dbswznm->tblwznmrmtablemvector->updateRec(tblRvec2);
				};
			};

			for (unsigned int ix1 = 0; ix1 < tbl->imeimtablecol.nodes.size(); ix1++) {
				tco = tbl->imeimtablecol.nodes[ix1];

				for (unsigned int i = 0; i < tbl->imeimsubset.nodes.size(); i++) {
					sbs = tbl->imeimsubset.nodes[i];

					if (sbs->sref == tco->srefRefWznmMSubset) {
						tco->refWznmMSubset = sbs->ref;
						break;
					};
				};

				if (tco->irefRefWznmMRelation != 0) {
					for (unsigned int i = 0; i < imeimrelation.nodes.size(); i++) {
						rel = imeimrelation.nodes[i];

						if (rel->iref == tco->irefRefWznmMRelation) {
							tco->refWznmMRelation = rel->ref;
							break;
						};
					};
				};

				if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL) {
					for (unsigned int i = 0; i < imeimtable.nodes.size(); i++) {
						tbl2 = imeimtable.nodes[i];

						if (tbl2->sref == tco->srefFctUref) {
							tco->fctUref = tbl2->ref;
							break;
						};
					};

				} else if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
					if (dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, tco->srefFctUref, ref)) tco->fctUref = ref;
				};

				dbswznm->tblwznmmtablecol->updateRec(tco);
			};
		};

		// -- MRelation
		for (unsigned int ix0 = 0; ix0 < imeimrelation.nodes.size(); ix0++) {
			rel = imeimrelation.nodes[ix0];

			if (rel->irefSupRefWznmMRelation != 0) {
				for (unsigned int i = 0; i < imeimrelation.nodes.size(); i++) {
					rel2 = imeimrelation.nodes[i];

					if (rel2->iref == rel->irefSupRefWznmMRelation) {
						rel->supRefWznmMRelation = rel2->ref;
						break;
					};
				};

				dbswznm->tblwznmmrelation->updateRec(rel);
			};
		};
		// IP enterSgeImport.ppr --- IEND
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexDbs::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexDbs::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexDbs::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexDbs::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMRelation* rel = NULL;
	ImeitemIMStub* stb = NULL;
	ImeitemIMTable* tbl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIRMStubMStub* stbRstb = NULL;
	ImeitemIAMRelationTitle* relAtit = NULL;
	ImeitemIAMTableLoadfct* tblAlfc = NULL;
	ImeitemIAMTableTitle* tblAtit = NULL;
	ImeitemIAMVectorTitle1* vecAtit1 = NULL;
	ImeitemIMCheck* chk = NULL;
	ImeitemIMSubset* sbs = NULL;
	ImeitemIMTablecol* tco = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIRMTableMVector1* tblRvec1 = NULL;
	ImeitemIAMSubsetTitle* sbsAtit = NULL;
	ImeitemIAMTablecolTitle* tcoAtit = NULL;
	ImeitemIAMVectorTitle2* vecAtit2 = NULL;
	ImeitemIJMVectoritem1* vitJ1 = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;
	ImeitemIRMSubsetMSubset* sbsRsbs = NULL;
	ImeitemIRMTableMVector2* tblRvec2 = NULL;
	ImeitemIJMVectoritem2* vitJ2 = NULL;

	// -- ImeICRelation

	// -- ImeIMRelation
	for (unsigned int ix0 = 0; ix0 < imeimrelation.nodes.size(); ix0++) {
		rel = imeimrelation.nodes[ix0];
		if (rel->ref != 0) dbswznm->tblwznmmrelation->removeRecByRef(rel->ref);

		for (unsigned int ix1 = 0; ix1 < rel->imeiamrelationtitle.nodes.size(); ix1++) {
			relAtit = rel->imeiamrelationtitle.nodes[ix1];
			if (relAtit->ref != 0) dbswznm->tblwznmamrelationtitle->removeRecByRef(relAtit->ref);
		};
	};

	// -- ImeIMStub
	for (unsigned int ix0 = 0; ix0 < imeimstub.nodes.size(); ix0++) {
		stb = imeimstub.nodes[ix0];
		if (stb->ref != 0) dbswznm->tblwznmmstub->removeRecByRef(stb->ref);
	};

	// -- ImeIMTable
	for (unsigned int ix0 = 0; ix0 < imeimtable.nodes.size(); ix0++) {
		tbl = imeimtable.nodes[ix0];
		if (tbl->ref != 0) dbswznm->tblwznmmtable->removeRecByRef(tbl->ref);

		for (unsigned int ix1 = 0; ix1 < tbl->imeiamtableloadfct.nodes.size(); ix1++) {
			tblAlfc = tbl->imeiamtableloadfct.nodes[ix1];
			if (tblAlfc->ref != 0) dbswznm->tblwznmamtableloadfct->removeRecByRef(tblAlfc->ref);
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeiamtabletitle.nodes.size(); ix1++) {
			tblAtit = tbl->imeiamtabletitle.nodes[ix1];
			if (tblAtit->ref != 0) dbswznm->tblwznmamtabletitle->removeRecByRef(tblAtit->ref);
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimcheck.nodes.size(); ix1++) {
			chk = tbl->imeimcheck.nodes[ix1];
			if (chk->ref != 0) dbswznm->tblwznmmcheck->removeRecByRef(chk->ref);
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimsubset.nodes.size(); ix1++) {
			sbs = tbl->imeimsubset.nodes[ix1];
			if (sbs->ref != 0) dbswznm->tblwznmmsubset->removeRecByRef(sbs->ref);

			for (unsigned int ix2 = 0; ix2 < sbs->imeiamsubsettitle.nodes.size(); ix2++) {
				sbsAtit = sbs->imeiamsubsettitle.nodes[ix2];
				if (sbsAtit->ref != 0) dbswznm->tblwznmamsubsettitle->removeRecByRef(sbsAtit->ref);
			};

			for (unsigned int ix2 = 0; ix2 < sbs->imeirmsubsetmsubset.nodes.size(); ix2++) {
				sbsRsbs = sbs->imeirmsubsetmsubset.nodes[ix2];
				if (sbsRsbs->ref != 0) dbswznm->tblwznmrmsubsetmsubset->removeRecByRef(sbsRsbs->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimtablecol.nodes.size(); ix1++) {
			tco = tbl->imeimtablecol.nodes[ix1];
			if (tco->ref != 0) dbswznm->tblwznmmtablecol->removeRecByRef(tco->ref);

			for (unsigned int ix2 = 0; ix2 < tco->imeiamtablecoltitle.nodes.size(); ix2++) {
				tcoAtit = tco->imeiamtablecoltitle.nodes[ix2];
				if (tcoAtit->ref != 0) dbswznm->tblwznmamtablecoltitle->removeRecByRef(tcoAtit->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimvector2.nodes.size(); ix1++) {
			vec2 = tbl->imeimvector2.nodes[ix1];
			if (vec2->ref != 0) dbswznm->tblwznmmvector->removeRecByRef(vec2->ref);

			for (unsigned int ix2 = 0; ix2 < vec2->imeiamvectortitle2.nodes.size(); ix2++) {
				vecAtit2 = vec2->imeiamvectortitle2.nodes[ix2];
				if (vecAtit2->ref != 0) dbswznm->tblwznmamvectortitle->removeRecByRef(vecAtit2->ref);
			};

			for (unsigned int ix2 = 0; ix2 < vec2->imeimvectoritem2.nodes.size(); ix2++) {
				vit2 = vec2->imeimvectoritem2.nodes[ix2];
				if (vit2->ref != 0) dbswznm->tblwznmmvectoritem->removeRecByRef(vit2->ref);

				for (unsigned int ix3 = 0; ix3 < vit2->imeijmvectoritem2.nodes.size(); ix3++) {
					vitJ2 = vit2->imeijmvectoritem2.nodes[ix3];
					if (vitJ2->ref != 0) dbswznm->tblwznmjmvectoritem->removeRecByRef(vitJ2->ref);
				};
			};

			for (unsigned int ix2 = 0; ix2 < vec2->imeirmtablemvector2.nodes.size(); ix2++) {
				tblRvec2 = vec2->imeirmtablemvector2.nodes[ix2];
				if (tblRvec2->ref != 0) dbswznm->tblwznmrmtablemvector->removeRecByRef(tblRvec2->ref);
			};
		};
	};

	// -- ImeIMVector1
	for (unsigned int ix0 = 0; ix0 < imeimvector1.nodes.size(); ix0++) {
		vec1 = imeimvector1.nodes[ix0];
		if (vec1->ref != 0) dbswznm->tblwznmmvector->removeRecByRef(vec1->ref);

		for (unsigned int ix1 = 0; ix1 < vec1->imeiamvectortitle1.nodes.size(); ix1++) {
			vecAtit1 = vec1->imeiamvectortitle1.nodes[ix1];
			if (vecAtit1->ref != 0) dbswznm->tblwznmamvectortitle->removeRecByRef(vecAtit1->ref);
		};

		for (unsigned int ix1 = 0; ix1 < vec1->imeimvectoritem1.nodes.size(); ix1++) {
			vit1 = vec1->imeimvectoritem1.nodes[ix1];
			if (vit1->ref != 0) dbswznm->tblwznmmvectoritem->removeRecByRef(vit1->ref);

			for (unsigned int ix2 = 0; ix2 < vit1->imeijmvectoritem1.nodes.size(); ix2++) {
				vitJ1 = vit1->imeijmvectoritem1.nodes[ix2];
				if (vitJ1->ref != 0) dbswznm->tblwznmjmvectoritem->removeRecByRef(vitJ1->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < vec1->imeirmtablemvector1.nodes.size(); ix1++) {
			tblRvec1 = vec1->imeirmtablemvector1.nodes[ix1];
			if (tblRvec1->ref != 0) dbswznm->tblwznmrmtablemvector->removeRecByRef(tblRvec1->ref);
		};
	};

	// -- ImeIRMStubMStub
	for (unsigned int ix0 = 0; ix0 < imeirmstubmstub.nodes.size(); ix0++) {
		stbRstb = imeirmstubmstub.nodes[ix0];
		if (stbRstb->ref != 0) dbswznm->tblwznmrmstubmstub->removeRecByRef(stbRstb->ref);
	};

	return retval;
};

void JobWznmIexDbs::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexDbs::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemICRelation* relC = NULL;
	ImeitemIMRelation* rel = NULL;
	ImeitemIMStub* stb = NULL;
	ImeitemIMTable* tbl = NULL;
	ImeitemIMVector1* vec1 = NULL;
	ImeitemIRMStubMStub* stbRstb = NULL;
	ImeitemIAMRelationTitle* relAtit = NULL;
	ImeitemIAMTableLoadfct* tblAlfc = NULL;
	ImeitemIAMTableTitle* tblAtit = NULL;
	ImeitemIAMVectorTitle1* vecAtit1 = NULL;
	ImeitemIMCheck* chk = NULL;
	ImeitemIMSubset* sbs = NULL;
	ImeitemIMTablecol* tco = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIMVectoritem1* vit1 = NULL;
	ImeitemIRMTableMVector1* tblRvec1 = NULL;
	ImeitemIAMSubsetTitle* sbsAtit = NULL;
	ImeitemIAMTablecolTitle* tcoAtit = NULL;
	ImeitemIAMVectorTitle2* vecAtit2 = NULL;
	ImeitemIJMVectoritem1* vitJ1 = NULL;
	ImeitemIMVectoritem2* vit2 = NULL;
	ImeitemIRMSubsetMSubset* sbsRsbs = NULL;
	ImeitemIRMTableMVector2* tblRvec2 = NULL;
	ImeitemIJMVectoritem2* vitJ2 = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeICRelation
	for (unsigned int ix0 = 0; ix0 < imeicrelation.nodes.size(); ix0++) {
		relC = imeicrelation.nodes[ix0];

		if (relC->ref != 0) {
			relC->iref = ix0+1;
		};
	};

	// -- ImeIMRelation
	for (unsigned int ix0 = 0; ix0 < imeimrelation.nodes.size(); ix0++) {
		rel = imeimrelation.nodes[ix0];

		if (rel->ref != 0) {
			rel->iref = ix0+1;
			//rel->irefRefWznmCRelation: IREF
			//rel->irefSupRefWznmMRelation: IREF
			rel->srefFrRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rel->frRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			rel->srefFrsRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, rel->frsRefWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			rel->srefToRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rel->toRefWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			rel->srefTosRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, rel->tosRefWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			rel->srefRefWznmMTable = StubWznm::getStubTblStd(dbswznm, rel->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMRELATIONTITLE, ixWznmVIop)) {
			dbswznm->tblwznmamrelationtitle->loadRefsByRel(rel->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) rel->imeiamrelationtitle.nodes.push_back(new ImeitemIAMRelationTitle(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < rel->imeiamrelationtitle.nodes.size(); ix1++) {
			relAtit = rel->imeiamrelationtitle.nodes[ix1];

			if (relAtit->ref != 0) {
				relAtit->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, relAtit->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMStub
	for (unsigned int ix0 = 0; ix0 < imeimstub.nodes.size(); ix0++) {
		stb = imeimstub.nodes[ix0];

		if (stb->ref != 0) {
			stb->srefRefWznmMTable = StubWznm::getStubTblStd(dbswznm, stb->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			stb->srefRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, stb->refWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			stb->srefRefWznmMTablecol = StubWznm::getStubTcoSref(dbswznm, stb->refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};

	// -- ImeIMTable
	for (unsigned int ix0 = 0; ix0 < imeimtable.nodes.size(); ix0++) {
		tbl = imeimtable.nodes[ix0];

		if (tbl->ref != 0) {
			//tbl->irefRefUref: IREF
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMTABLELOADFCT, ixWznmVIop)) {
			dbswznm->tblwznmamtableloadfct->loadRefsByTbl(tbl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) tbl->imeiamtableloadfct.nodes.push_back(new ImeitemIAMTableLoadfct(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeiamtableloadfct.nodes.size(); ix1++) {
			tblAlfc = tbl->imeiamtableloadfct.nodes[ix1];

			if (tblAlfc->ref != 0) {
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMTABLETITLE, ixWznmVIop)) {
			dbswznm->tblwznmamtabletitle->loadRefsByTbl(tbl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) tbl->imeiamtabletitle.nodes.push_back(new ImeitemIAMTableTitle(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeiamtabletitle.nodes.size(); ix1++) {
			tblAtit = tbl->imeiamtabletitle.nodes[ix1];

			if (tblAtit->ref != 0) {
				tblAtit->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, tblAtit->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMCHECK, ixWznmVIop)) {
			dbswznm->tblwznmmcheck->loadRefsByTbl(tbl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) tbl->imeimcheck.nodes.push_back(new ImeitemIMCheck(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimcheck.nodes.size(); ix1++) {
			chk = tbl->imeimcheck.nodes[ix1];

			if (chk->ref != 0) {
				chk->srefRefWznmMTablecol = StubWznm::getStubTcoSref(dbswznm, chk->refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSUBSET, ixWznmVIop)) {
			dbswznm->tblwznmmsubset->loadRefsByTbl(tbl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) tbl->imeimsubset.nodes.push_back(new ImeitemIMSubset(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimsubset.nodes.size(); ix1++) {
			sbs = tbl->imeimsubset.nodes[ix1];

			if (sbs->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMSUBSETTITLE, ixWznmVIop)) {
				dbswznm->tblwznmamsubsettitle->loadRefsBySbs(sbs->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) sbs->imeiamsubsettitle.nodes.push_back(new ImeitemIAMSubsetTitle(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < sbs->imeiamsubsettitle.nodes.size(); ix2++) {
				sbsAtit = sbs->imeiamsubsettitle.nodes[ix2];

				if (sbsAtit->ref != 0) {
					sbsAtit->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, sbsAtit->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMSUBSETMSUBSET, ixWznmVIop)) {
				dbswznm->tblwznmrmsubsetmsubset->loadRefsByAsb(sbs->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) sbs->imeirmsubsetmsubset.nodes.push_back(new ImeitemIRMSubsetMSubset(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < sbs->imeirmsubsetmsubset.nodes.size(); ix2++) {
				sbsRsbs = sbs->imeirmsubsetmsubset.nodes[ix2];

				if (sbsRsbs->ref != 0) {
					sbsRsbs->srefBsbRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, sbsRsbs->bsbRefWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMTABLECOL, ixWznmVIop)) {
			dbswznm->tblwznmmtablecol->loadRefsByTbl(tbl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) tbl->imeimtablecol.nodes.push_back(new ImeitemIMTablecol(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimtablecol.nodes.size(); ix1++) {
			tco = tbl->imeimtablecol.nodes[ix1];

			if (tco->ref != 0) {
				tco->srefRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, tco->refWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				//tco->irefRefWznmMRelation: IREF
				tco->srefFctUref = StubWznm::getStubTblStd(dbswznm, tco->fctUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMTABLECOLTITLE, ixWznmVIop)) {
				dbswznm->tblwznmamtablecoltitle->loadRefsByTco(tco->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) tco->imeiamtablecoltitle.nodes.push_back(new ImeitemIAMTablecolTitle(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < tco->imeiamtablecoltitle.nodes.size(); ix2++) {
				tcoAtit = tco->imeiamtablecoltitle.nodes[ix2];

				if (tcoAtit->ref != 0) {
					tcoAtit->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, tcoAtit->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMVECTOR2, ixWznmVIop)) {
			dbswznm->tblwznmmvector->loadRefsByHktHku(VecWznmVMVectorHkTbl::TBL, tbl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) tbl->imeimvector2.nodes.push_back(new ImeitemIMVector2(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < tbl->imeimvector2.nodes.size(); ix1++) {
			vec2 = tbl->imeimvector2.nodes[ix1];

			if (vec2->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMVECTORTITLE2, ixWznmVIop)) {
				dbswznm->tblwznmamvectortitle->loadRefsByVec(vec2->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) vec2->imeiamvectortitle2.nodes.push_back(new ImeitemIAMVectorTitle2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < vec2->imeiamvectortitle2.nodes.size(); ix2++) {
				vecAtit2 = vec2->imeiamvectortitle2.nodes[ix2];

				if (vecAtit2->ref != 0) {
					vecAtit2->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, vecAtit2->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMVECTORITEM2, ixWznmVIop)) {
				dbswznm->tblwznmmvectoritem->loadRefsByVec(vec2->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) vec2->imeimvectoritem2.nodes.push_back(new ImeitemIMVectoritem2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < vec2->imeimvectoritem2.nodes.size(); ix2++) {
				vit2 = vec2->imeimvectoritem2.nodes[ix2];

				if (vit2->ref != 0) {
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMVECTORITEM2, ixWznmVIop)) {
					dbswznm->tblwznmjmvectoritem->loadRefsByVit(vit2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == vit2->refJ) {refs[i] = refs[0]; refs[0] = vit2->refJ; break;};
					for (unsigned int i = 0; i < refs.size(); i++) vit2->imeijmvectoritem2.nodes.push_back(new ImeitemIJMVectoritem2(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < vit2->imeijmvectoritem2.nodes.size(); ix3++) {
					vitJ2 = vit2->imeijmvectoritem2.nodes[ix3];

					if (vitJ2->ref != 0) {
						vitJ2->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, vitJ2->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMTABLEMVECTOR2, ixWznmVIop)) {
				dbswznm->tblwznmrmtablemvector->loadRefsByVec(vec2->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) vec2->imeirmtablemvector2.nodes.push_back(new ImeitemIRMTableMVector2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < vec2->imeirmtablemvector2.nodes.size(); ix2++) {
				tblRvec2 = vec2->imeirmtablemvector2.nodes[ix2];

				if (tblRvec2->ref != 0) {
					tblRvec2->srefRefWznmMTable = StubWznm::getStubTblStd(dbswznm, tblRvec2->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					tblRvec2->srefRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, tblRvec2->refWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};
	};

	// -- ImeIMVector1
	for (unsigned int ix0 = 0; ix0 < imeimvector1.nodes.size(); ix0++) {
		vec1 = imeimvector1.nodes[ix0];

		if (vec1->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMVECTORTITLE1, ixWznmVIop)) {
			dbswznm->tblwznmamvectortitle->loadRefsByVec(vec1->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) vec1->imeiamvectortitle1.nodes.push_back(new ImeitemIAMVectorTitle1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < vec1->imeiamvectortitle1.nodes.size(); ix1++) {
			vecAtit1 = vec1->imeiamvectortitle1.nodes[ix1];

			if (vecAtit1->ref != 0) {
				vecAtit1->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, vecAtit1->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMVECTORITEM1, ixWznmVIop)) {
			dbswznm->tblwznmmvectoritem->loadRefsByVec(vec1->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) vec1->imeimvectoritem1.nodes.push_back(new ImeitemIMVectoritem1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < vec1->imeimvectoritem1.nodes.size(); ix1++) {
			vit1 = vec1->imeimvectoritem1.nodes[ix1];

			if (vit1->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMVECTORITEM1, ixWznmVIop)) {
				dbswznm->tblwznmjmvectoritem->loadRefsByVit(vit1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == vit1->refJ) {refs[i] = refs[0]; refs[0] = vit1->refJ; break;};
				for (unsigned int i = 0; i < refs.size(); i++) vit1->imeijmvectoritem1.nodes.push_back(new ImeitemIJMVectoritem1(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < vit1->imeijmvectoritem1.nodes.size(); ix2++) {
				vitJ1 = vit1->imeijmvectoritem1.nodes[ix2];

				if (vitJ1->ref != 0) {
					vitJ1->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, vitJ1->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMTABLEMVECTOR1, ixWznmVIop)) {
			dbswznm->tblwznmrmtablemvector->loadRefsByVec(vec1->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) vec1->imeirmtablemvector1.nodes.push_back(new ImeitemIRMTableMVector1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < vec1->imeirmtablemvector1.nodes.size(); ix1++) {
			tblRvec1 = vec1->imeirmtablemvector1.nodes[ix1];

			if (tblRvec1->ref != 0) {
				tblRvec1->srefRefWznmMTable = StubWznm::getStubTblStd(dbswznm, tblRvec1->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				tblRvec1->srefRefWznmMSubset = StubWznm::getStubSbsStd(dbswznm, tblRvec1->refWznmMSubset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIRMStubMStub
	for (unsigned int ix0 = 0; ix0 < imeirmstubmstub.nodes.size(); ix0++) {
		stbRstb = imeirmstubmstub.nodes[ix0];

		if (stbRstb->ref != 0) {
			stbRstb->srefSupRefWznmMStub = StubWznm::getStubStbStd(dbswznm, stbRstb->supRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			stbRstb->srefSubRefWznmMStub = StubWznm::getStubStbStd(dbswznm, stbRstb->subRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexDbs::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexDbs::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexDbs::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexDbs::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmDbs::exportToFile(fullpath, xmlNotTxt, shorttags, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);

	return retval;
};

void JobWznmIexDbs::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexDbs::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexDbs::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
