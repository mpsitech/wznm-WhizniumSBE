/**
	* \file JobWznmIexOpk.cpp
	* job handler for job JobWznmIexOpk (implementation)
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

#include "JobWznmIexOpk.h"

#include "JobWznmIexOpk_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmOpk;

/******************************************************************************
 class JobWznmIexOpk
 ******************************************************************************/

JobWznmIexOpk::JobWznmIexOpk(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXOPK, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexOpk::~JobWznmIexOpk() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexOpk::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexOpk::parseFromFile(
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

void JobWznmIexOpk::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexOpk::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexOpk::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexOpk::exportToFile(
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

void JobWznmIexOpk::handleRequest(
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

void JobWznmIexOpk::changeStage(
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

string JobWznmIexOpk::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing operation pack structure";
			else if (ixVSge == VecVSge::PRSDONE) retval = "operation pack structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing operation pack structure (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing operation pack structure import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting operation pack structure for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "operation pack structure collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting operation pack structure";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexOpk::enterSgeIdle(
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

	imeimoppack.clear();

	return retval;
};

void JobWznmIexOpk::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexOpk::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmOpk::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimoppack);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexOpk::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexOpk::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexOpk::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexOpk::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexOpk::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexOpk::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMOppack* opk = NULL;
	ImeitemIAMOppackInvarg* opkAinv = NULL;
	ImeitemIAMOppackRetval* opkAret = NULL;
	ImeitemICAMOppackInvarg* opkAinvC = NULL;
	ImeitemICAMOppackRetval* opkAretC = NULL;
	ImeitemIMBlock1* blk1 = NULL;
	ImeitemIMOp* opx = NULL;
	ImeitemIMSquawk1* sqk1 = NULL;
	ImeitemIRMComponentMOppack* cmpRopk = NULL;
	ImeitemIRMLibraryMOppack* libRopk = NULL;
	ImeitemIAMBlockItem1* blkAitm1 = NULL;
	ImeitemIAMOpInvarg* opxAinv = NULL;
	ImeitemIAMOpRetval* opxAret = NULL;
	ImeitemICAMBlockItem1* blkAitmC1 = NULL;
	ImeitemICAMOpInvarg* opxAinvC = NULL;
	ImeitemICAMOpRetval* opxAretC = NULL;
	ImeitemIJMSquawkTitle1* sqkJtit1 = NULL;
	ImeitemIMBlock2* blk2 = NULL;
	ImeitemIMSquawk2* sqk2 = NULL;
	ImeitemIRMSquawkMStub1* sqkRstb1 = NULL;
	ImeitemIAMBlockItem2* blkAitm2 = NULL;
	ImeitemICAMBlockItem2* blkAitmC2 = NULL;
	ImeitemIJAMBlockItem1* bitJ1 = NULL;
	ImeitemIJMSquawkTitle2* sqkJtit2 = NULL;
	ImeitemIRMSquawkMStub2* sqkRstb2 = NULL;
	ImeitemIJAMBlockItem2* bitJ2 = NULL;

	set<ubigint> irefs1, irefs2, irefs3;

	uint num1, num2, num3;

	// IP enterSgeImport.prep --- IBEGIN
	vector<ubigint> refs;

	ubigint refWznmMVersion;
	string preflcl;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	Wznm::getVerlclsref(dbswznm, refWznmMVersion, preflcl);

	ListWznmMRelease rlss;
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMComponent WHERE refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	dbswznm->tblwznmmrelease->loadRstByRefs(refs, false, rlss);

	ListWznmMStub stbs;
	dbswznm->loadRefsBySQL("SELECT TblWznmMStub.ref FROM TblWznmMTable, TblWznmMStub WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion), false, refs);
	dbswznm->tblwznmmstub->loadRstByRefs(refs, false, stbs);

	ListWznmMLocale lcls;
	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMOppack
		for (unsigned int ix0 = 0; ix0 < imeimoppack.nodes.size(); ix0++) {
			opk = imeimoppack.nodes[ix0];

			opk->ixVBasetype = VecWznmVMOppackBasetype::getIx(opk->srefIxVBasetype);
			if (opk->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",opk->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(opk->lineno)}});
			//opk->refWznmMVersion: PRESET
			opk->refWznmMVersion = refWznmMVersion;
			//opk->refWznmMSquawk: SUB
			//opk->sref: TBL
			//opk->Title: TBL
			if (opk->Shrdat == false) opk->Shrdat = false;
			//opk->Shrdat: TBL
			//opk->Comment: TBL

			dbswznm->tblwznmmoppack->insertRec(opk);
			impcnt++;

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < opk->imeicamoppackinvarg.nodes.size(); ix1++) {
				opkAinvC = opk->imeicamoppackinvarg.nodes[ix1];

				if (irefs1.find(opkAinvC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(opkAinvC->iref)}, {"ime","ImeICAMOppackInvarg"}, {"lineno",to_string(opkAinvC->lineno)}});
				opkAinvC->ref = dbswznm->tblwznmcamoppackinvarg->getNewRef();
				irefs1.insert(opkAinvC->iref);

				impcnt++;
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < opk->imeiamoppackinvarg.nodes.size(); ix1++) {
				opkAinv = opk->imeiamoppackinvarg.nodes[ix1];

				//opkAinv->refWznmCAMOppackInvarg: PREVIMP
				if (opkAinv->irefRefWznmCAMOppackInvarg != 0) {
					for (unsigned int i = 0; i < opk->imeicamoppackinvarg.nodes.size(); i++)
						if (opk->imeicamoppackinvarg.nodes[i]->iref == opkAinv->irefRefWznmCAMOppackInvarg) {
							opkAinv->refWznmCAMOppackInvarg = opk->imeicamoppackinvarg.nodes[i]->ref;
							break;
						};
					if (opkAinv->refWznmCAMOppackInvarg == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(opkAinv->irefRefWznmCAMOppackInvarg)}, {"iel","irefRefWznmCAMOppackInvarg"}, {"lineno",to_string(opkAinv->lineno)}});
				};
				opkAinv->opkRefWznmMOppack = opk->ref;
				opkAinv->opkNum = num1++;
				//opkAinv->sref: TBL
				opkAinv->ixWznmVVartype = VecWznmVVartype::getIx(opkAinv->srefIxWznmVVartype);
				if (opkAinv->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",opkAinv->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(opkAinv->lineno)}});
				//opkAinv->refWznmMVector: CUSTSQL
				if (opkAinv->ixWznmVVartype == VecWznmVVartype::VECSREF) {
					dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, opkAinv->srefRefWznmMVector, opkAinv->refWznmMVector);
					if (opkAinv->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",opkAinv->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(opkAinv->lineno)}});
				};
				//opkAinv->Defval: TBL
				//opkAinv->refWznmMVectoritem: CUSTSQL
				if ((opkAinv->refWznmMVector != 0) && (opkAinv->srefRefWznmMVectoritem != "")) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(opkAinv->refWznmMVector) + " AND sref = '" + opkAinv->srefRefWznmMVectoritem + "'", opkAinv->refWznmMVectoritem);
					if (opkAinv->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",opkAinv->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(opkAinv->lineno)}});
				};
				//opkAinv->Comment: TBL

				dbswznm->tblwznmamoppackinvarg->insertRec(opkAinv);
				impcnt++;
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < opk->imeicamoppackretval.nodes.size(); ix1++) {
				opkAretC = opk->imeicamoppackretval.nodes[ix1];

				if (irefs1.find(opkAretC->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(opkAretC->iref)}, {"ime","ImeICAMOppackRetval"}, {"lineno",to_string(opkAretC->lineno)}});
				opkAretC->ref = dbswznm->tblwznmcamoppackretval->getNewRef();
				irefs1.insert(opkAretC->iref);

				impcnt++;
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < opk->imeiamoppackretval.nodes.size(); ix1++) {
				opkAret = opk->imeiamoppackretval.nodes[ix1];

				//opkAret->refWznmCAMOppackRetval: PREVIMP
				if (opkAret->irefRefWznmCAMOppackRetval != 0) {
					for (unsigned int i = 0; i < opk->imeicamoppackretval.nodes.size(); i++)
						if (opk->imeicamoppackretval.nodes[i]->iref == opkAret->irefRefWznmCAMOppackRetval) {
							opkAret->refWznmCAMOppackRetval = opk->imeicamoppackretval.nodes[i]->ref;
							break;
						};
					if (opkAret->refWznmCAMOppackRetval == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(opkAret->irefRefWznmCAMOppackRetval)}, {"iel","irefRefWznmCAMOppackRetval"}, {"lineno",to_string(opkAret->lineno)}});
				};
				opkAret->opkRefWznmMOppack = opk->ref;
				opkAret->opkNum = num1++;
				//opkAret->sref: TBL
				opkAret->ixWznmVVartype = VecWznmVVartype::getIx(opkAret->srefIxWznmVVartype);
				if (opkAret->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",opkAret->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(opkAret->lineno)}});
				//opkAret->refWznmMVector: CUSTSQL
				if (opkAret->ixWznmVVartype == VecWznmVVartype::VECSREF) {
					dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, opkAret->srefRefWznmMVector, opkAret->refWznmMVector);
					if (opkAret->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",opkAret->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(opkAret->lineno)}});
				};
				//opkAret->Comment: TBL

				dbswznm->tblwznmamoppackretval->insertRec(opkAret);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < opk->imeimsquawk1.nodes.size(); ix1++) {
				sqk1 = opk->imeimsquawk1.nodes[ix1];

				sqk1->refIxVTbl = VecWznmVMSquawkRefTbl::OPK;
				sqk1->refUref = opk->ref;
				//sqk1->refJTitle: SUB
				//sqk1->Title: TBL
				//sqk1->Example: TBL

				dbswznm->tblwznmmsquawk->insertRec(sqk1);
				impcnt++;

				if (((sqk1->Title != "")) && sqk1->imeijmsquawktitle1.nodes.empty()) {
					sqkJtit1 = new ImeitemIJMSquawkTitle1();
					sqk1->imeijmsquawktitle1.nodes.push_back(sqkJtit1);

					sqkJtit1->refWznmMSquawk = sqk1->ref;
					sqkJtit1->Title = sqk1->Title;
				};

				if (ix1 == 0) {
					opk->refWznmMSquawk = sqk1->ref;
					dbswznm->tblwznmmoppack->updateRec(opk);
				};

				for (unsigned int ix2 = 0; ix2 < sqk1->imeijmsquawktitle1.nodes.size(); ix2++) {
					sqkJtit1 = sqk1->imeijmsquawktitle1.nodes[ix2];

					sqkJtit1->refWznmMSquawk = sqk1->ref;
					//if (sqkJtit1->srefX1RefWznmMLocale == "") sqkJtit1->srefX1RefWznmMLocale: CUSTOM DEFVAL
					if (sqkJtit1->srefX1RefWznmMLocale == "") sqkJtit1->srefX1RefWznmMLocale = preflcl;
					//sqkJtit1->x1RefWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++)
						if (lcls.nodes[i]->sref.compare(sqkJtit1->srefX1RefWznmMLocale) == 0) {
							sqkJtit1->x1RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					if (sqkJtit1->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sqkJtit1->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(sqkJtit1->lineno)}});
					//sqkJtit1->Title: TBL

					dbswznm->tblwznmjmsquawktitle->insertRec(sqkJtit1);
					impcnt++;

					if (ix2 == 0) {
						sqk1->refJTitle = sqkJtit1->ref;
						sqk1->Title = sqkJtit1->Title;
						dbswznm->tblwznmmsquawk->updateRec(sqk1);
					};
				};

				for (unsigned int ix2 = 0; ix2 < sqk1->imeirmsquawkmstub1.nodes.size(); ix2++) {
					sqkRstb1 = sqk1->imeirmsquawkmstub1.nodes[ix2];

					sqkRstb1->refWznmMSquawk = sqk1->ref;
					//sqkRstb1->refWznmMStub: RST
					for (unsigned int i = 0; i < stbs.nodes.size(); i++)
						if (stbs.nodes[i]->sref.compare(sqkRstb1->srefRefWznmMStub) == 0) {
							sqkRstb1->refWznmMStub = stbs.nodes[i]->ref;
							break;
						};
					//if (sqkRstb1->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sqkRstb1->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(sqkRstb1->lineno)}});

					dbswznm->tblwznmrmsquawkmstub->insertRec(sqkRstb1);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < opk->imeimblock1.nodes.size(); ix1++) {
				blk1 = opk->imeimblock1.nodes[ix1];

				blk1->ixVBasetype = VecWznmVMBlockBasetype::STG;
				//blk1->refWznmMVersion: PRESET
				blk1->refWznmMVersion = refWznmMVersion;
				blk1->refIxVTbl = VecWznmVMBlockRefTbl::OPK;
				blk1->refUref = opk->ref;
				blk1->reaIxWznmWScope = VecWznmWScope::CMBENG + VecWznmWScope::OPENG;
				blk1->wriIxWznmWScope = VecWznmWScope::CMBENG + VecWznmWScope::OPENG;
				//blk1->sref: TBL
				//blk1->Comment: TBL

				dbswznm->tblwznmmblock->insertRec(blk1);
				impcnt++;

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < blk1->imeicamblockitem1.nodes.size(); ix2++) {
					blkAitmC1 = blk1->imeicamblockitem1.nodes[ix2];

					if (irefs2.find(blkAitmC1->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(blkAitmC1->iref)}, {"ime","ImeICAMBlockItem1"}, {"lineno",to_string(blkAitmC1->lineno)}});
					blkAitmC1->ref = dbswznm->tblwznmcamblockitem->getNewRef();
					irefs2.insert(blkAitmC1->iref);

					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < blk1->imeiamblockitem1.nodes.size(); ix2++) {
					blkAitm1 = blk1->imeiamblockitem1.nodes[ix2];

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
					blkAitm1->blkNum = num2++;
					blkAitm1->ixVBasetype = VecWznmVAMBlockItemBasetype::VAR;
					//blkAitm1->sref: TBL
					blkAitm1->ixWznmVVartype = VecWznmVVartype::getIx(blkAitm1->srefIxWznmVVartype);
					if (blkAitm1->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm1->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(blkAitm1->lineno)}});
					//blkAitm1->refWznmMVector: CUSTSQL
					if (blkAitm1->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, blkAitm1->srefRefWznmMVector, blkAitm1->refWznmMVector);
						if (blkAitm1->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->refJ: SUB
					//blkAitm1->Defval: TBL
					//blkAitm1->refWznmMVectoritem: CUSTSQL
					if ((blkAitm1->refWznmMVector != 0) && (blkAitm1->srefRefWznmMVectoritem != "")) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm1->refWznmMVector) + " AND sref = '" + blkAitm1->srefRefWznmMVectoritem + "'", blkAitm1->refWznmMVectoritem);
						if (blkAitm1->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",blkAitm1->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(blkAitm1->lineno)}});
					};
					//blkAitm1->Comment: TBL

					dbswznm->tblwznmamblockitem->insertRec(blkAitm1);
					impcnt++;

					if (((blkAitm1->Defval != "") || (blkAitm1->srefRefWznmMVectoritem != "")) && blkAitm1->imeijamblockitem1.nodes.empty()) {
						bitJ1 = new ImeitemIJAMBlockItem1();
						blkAitm1->imeijamblockitem1.nodes.push_back(bitJ1);

						bitJ1->refWznmAMBlockItem = blkAitm1->ref;
						bitJ1->Defval = blkAitm1->Defval;
						bitJ1->srefRefWznmMVectoritem = blkAitm1->srefRefWznmMVectoritem;
					};

					for (unsigned int ix3 = 0; ix3 < blkAitm1->imeijamblockitem1.nodes.size(); ix3++) {
						bitJ1 = blkAitm1->imeijamblockitem1.nodes[ix3];

						bitJ1->refWznmAMBlockItem = blkAitm1->ref;
						//bitJ1->Defval: TBL
						//bitJ1->refWznmMVectoritem: CUSTSQL
						if ((blkAitm1->refWznmMVector != 0) && (bitJ1->srefRefWznmMVectoritem != "")) {
							dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm1->refWznmMVector) + " AND sref = '" + bitJ1->srefRefWznmMVectoritem + "'", bitJ1->refWznmMVectoritem);
							if (bitJ1->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",bitJ1->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(bitJ1->lineno)}});
						};

						dbswznm->tblwznmjamblockitem->insertRec(bitJ1);
						impcnt++;

						if (ix3 == 0) {
							blkAitm1->refJ = bitJ1->ref;
							blkAitm1->Defval = bitJ1->Defval;
							blkAitm1->refWznmMVectoritem = bitJ1->refWznmMVectoritem;
							dbswznm->tblwznmamblockitem->updateRec(blkAitm1);
						};
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < opk->imeimop.nodes.size(); ix1++) {
				opx = opk->imeimop.nodes[ix1];

				opx->refWznmMOppack = opk->ref;
				//opx->refWznmMSquawk: SUB
				//opx->sref: TBL
				if (opx->Shrdat == false) opx->Shrdat = false;
				//opx->Shrdat: TBL
				//opx->Comment: TBL

				dbswznm->tblwznmmop->insertRec(opx);
				impcnt++;

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < opx->imeicamopinvarg.nodes.size(); ix2++) {
					opxAinvC = opx->imeicamopinvarg.nodes[ix2];

					if (irefs2.find(opxAinvC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(opxAinvC->iref)}, {"ime","ImeICAMOpInvarg"}, {"lineno",to_string(opxAinvC->lineno)}});
					opxAinvC->ref = dbswznm->tblwznmcamopinvarg->getNewRef();
					irefs2.insert(opxAinvC->iref);

					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < opx->imeiamopinvarg.nodes.size(); ix2++) {
					opxAinv = opx->imeiamopinvarg.nodes[ix2];

					//opxAinv->refWznmCAMOpInvarg: PREVIMP
					if (opxAinv->irefRefWznmCAMOpInvarg != 0) {
						for (unsigned int i = 0; i < opx->imeicamopinvarg.nodes.size(); i++)
							if (opx->imeicamopinvarg.nodes[i]->iref == opxAinv->irefRefWznmCAMOpInvarg) {
								opxAinv->refWznmCAMOpInvarg = opx->imeicamopinvarg.nodes[i]->ref;
								break;
							};
						if (opxAinv->refWznmCAMOpInvarg == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(opxAinv->irefRefWznmCAMOpInvarg)}, {"iel","irefRefWznmCAMOpInvarg"}, {"lineno",to_string(opxAinv->lineno)}});
					};
					opxAinv->opxRefWznmMOp = opx->ref;
					opxAinv->opxNum = num2++;
					//opxAinv->sref: TBL
					opxAinv->ixWznmVVartype = VecWznmVVartype::getIx(opxAinv->srefIxWznmVVartype);
					if (opxAinv->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",opxAinv->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(opxAinv->lineno)}});
					//opxAinv->refWznmMVector: CUSTSQL
					if (opxAinv->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, opxAinv->srefRefWznmMVector, opxAinv->refWznmMVector);
						if (opxAinv->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",opxAinv->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(opxAinv->lineno)}});
					};
					//opxAinv->Defval: TBL
					//opxAinv->refWznmMVectoritem: CUSTSQL
					if ((opxAinv->refWznmMVector != 0) && (opxAinv->srefRefWznmMVectoritem != "")) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(opxAinv->refWznmMVector) + " AND sref = '" + opxAinv->srefRefWznmMVectoritem + "'", opxAinv->refWznmMVectoritem);
						if (opxAinv->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",opxAinv->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(opxAinv->lineno)}});
					};
					//opxAinv->Comment: TBL

					dbswznm->tblwznmamopinvarg->insertRec(opxAinv);
					impcnt++;
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < opx->imeicamopretval.nodes.size(); ix2++) {
					opxAretC = opx->imeicamopretval.nodes[ix2];

					if (irefs2.find(opxAretC->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(opxAretC->iref)}, {"ime","ImeICAMOpRetval"}, {"lineno",to_string(opxAretC->lineno)}});
					opxAretC->ref = dbswznm->tblwznmcamopretval->getNewRef();
					irefs2.insert(opxAretC->iref);

					impcnt++;
				};

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < opx->imeiamopretval.nodes.size(); ix2++) {
					opxAret = opx->imeiamopretval.nodes[ix2];

					//opxAret->refWznmCAMOpRetval: PREVIMP
					if (opxAret->irefRefWznmCAMOpRetval != 0) {
						for (unsigned int i = 0; i < opx->imeicamopretval.nodes.size(); i++)
							if (opx->imeicamopretval.nodes[i]->iref == opxAret->irefRefWznmCAMOpRetval) {
								opxAret->refWznmCAMOpRetval = opx->imeicamopretval.nodes[i]->ref;
								break;
							};
						if (opxAret->refWznmCAMOpRetval == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(opxAret->irefRefWznmCAMOpRetval)}, {"iel","irefRefWznmCAMOpRetval"}, {"lineno",to_string(opxAret->lineno)}});
					};
					opxAret->opxRefWznmMOp = opx->ref;
					opxAret->opxNum = num2++;
					//opxAret->sref: TBL
					opxAret->ixWznmVVartype = VecWznmVVartype::getIx(opxAret->srefIxWznmVVartype);
					if (opxAret->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",opxAret->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(opxAret->lineno)}});
					//opxAret->refWznmMVector: CUSTSQL
					if (opxAret->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						dbswznm->tblwznmmvector->loadRefByVerSrf(refWznmMVersion, opxAret->srefRefWznmMVector, opxAret->refWznmMVector);
						if (opxAret->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",opxAret->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(opxAret->lineno)}});
					};
					//opxAret->Comment: TBL

					dbswznm->tblwznmamopretval->insertRec(opxAret);
					impcnt++;
				};

				for (unsigned int ix2 = 0; ix2 < opx->imeimsquawk2.nodes.size(); ix2++) {
					sqk2 = opx->imeimsquawk2.nodes[ix2];

					sqk2->refIxVTbl = VecWznmVMSquawkRefTbl::OPX;
					sqk2->refUref = opx->ref;
					//sqk2->refJTitle: SUB
					//sqk2->Title: TBL
					//sqk2->Example: TBL

					dbswznm->tblwznmmsquawk->insertRec(sqk2);
					impcnt++;

					if (((sqk2->Title != "")) && sqk2->imeijmsquawktitle2.nodes.empty()) {
						sqkJtit2 = new ImeitemIJMSquawkTitle2();
						sqk2->imeijmsquawktitle2.nodes.push_back(sqkJtit2);

						sqkJtit2->refWznmMSquawk = sqk2->ref;
						sqkJtit2->Title = sqk2->Title;
					};

					if (ix2 == 0) {
						opx->refWznmMSquawk = sqk2->ref;
						dbswznm->tblwznmmop->updateRec(opx);
					};

					for (unsigned int ix3 = 0; ix3 < sqk2->imeijmsquawktitle2.nodes.size(); ix3++) {
						sqkJtit2 = sqk2->imeijmsquawktitle2.nodes[ix3];

						sqkJtit2->refWznmMSquawk = sqk2->ref;
						//if (sqkJtit2->srefX1RefWznmMLocale == "") sqkJtit2->srefX1RefWznmMLocale: CUSTOM DEFVAL
						if (sqkJtit2->srefX1RefWznmMLocale == "") sqkJtit2->srefX1RefWznmMLocale = preflcl;
						//sqkJtit2->x1RefWznmMLocale: RST
						for (unsigned int i = 0; i < lcls.nodes.size(); i++)
							if (lcls.nodes[i]->sref.compare(sqkJtit2->srefX1RefWznmMLocale) == 0) {
								sqkJtit2->x1RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						if (sqkJtit2->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sqkJtit2->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(sqkJtit2->lineno)}});
						//sqkJtit2->Title: TBL

						dbswznm->tblwznmjmsquawktitle->insertRec(sqkJtit2);
						impcnt++;

						if (ix3 == 0) {
							sqk2->refJTitle = sqkJtit2->ref;
							sqk2->Title = sqkJtit2->Title;
							dbswznm->tblwznmmsquawk->updateRec(sqk2);
						};
					};

					for (unsigned int ix3 = 0; ix3 < sqk2->imeirmsquawkmstub2.nodes.size(); ix3++) {
						sqkRstb2 = sqk2->imeirmsquawkmstub2.nodes[ix3];

						sqkRstb2->refWznmMSquawk = sqk2->ref;
						//sqkRstb2->refWznmMStub: RST
						for (unsigned int i = 0; i < stbs.nodes.size(); i++)
							if (stbs.nodes[i]->sref.compare(sqkRstb2->srefRefWznmMStub) == 0) {
								sqkRstb2->refWznmMStub = stbs.nodes[i]->ref;
								break;
							};
						if (sqkRstb2->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",sqkRstb2->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(sqkRstb2->lineno)}});

						dbswznm->tblwznmrmsquawkmstub->insertRec(sqkRstb2);
						impcnt++;
					};
				};

				for (unsigned int ix2 = 0; ix2 < opx->imeimblock2.nodes.size(); ix2++) {
					blk2 = opx->imeimblock2.nodes[ix2];

					blk2->ixVBasetype = VecWznmVMBlockBasetype::STG;
					//blk2->refWznmMVersion: PRESET
					blk2->refWznmMVersion = refWznmMVersion;
					blk2->refIxVTbl = VecWznmVMBlockRefTbl::OPX;
					blk2->refUref = opx->ref;
					blk2->reaIxWznmWScope = VecWznmWScope::CMBENG + VecWznmWScope::OPENG;
					blk2->wriIxWznmWScope = VecWznmWScope::CMBENG + VecWznmWScope::OPENG;
					//blk2->sref: TBL
					//blk2->Comment: TBL

					dbswznm->tblwznmmblock->insertRec(blk2);
					impcnt++;

					irefs3.clear();

					for (unsigned int ix3 = 0; ix3 < blk2->imeicamblockitem2.nodes.size(); ix3++) {
						blkAitmC2 = blk2->imeicamblockitem2.nodes[ix3];

						if (irefs3.find(blkAitmC2->iref) != irefs3.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(blkAitmC2->iref)}, {"ime","ImeICAMBlockItem2"}, {"lineno",to_string(blkAitmC2->lineno)}});
						blkAitmC2->ref = dbswznm->tblwznmcamblockitem->getNewRef();
						irefs3.insert(blkAitmC2->iref);

						impcnt++;
					};

					num3 = 1;

					for (unsigned int ix3 = 0; ix3 < blk2->imeiamblockitem2.nodes.size(); ix3++) {
						blkAitm2 = blk2->imeiamblockitem2.nodes[ix3];

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
						blkAitm2->blkNum = num3++;
						blkAitm2->ixVBasetype = VecWznmVAMBlockItemBasetype::VAR;
						//blkAitm2->sref: TBL
						blkAitm2->ixWznmVVartype = VecWznmVVartype::getIx(blkAitm2->srefIxWznmVVartype);
						if (blkAitm2->ixWznmVVartype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",blkAitm2->srefIxWznmVVartype}, {"iel","srefIxWznmVVartype"}, {"lineno",to_string(blkAitm2->lineno)}});
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

						dbswznm->tblwznmamblockitem->insertRec(blkAitm2);
						impcnt++;

						if (((blkAitm2->Defval != "") || (blkAitm2->srefRefWznmMVectoritem != "")) && blkAitm2->imeijamblockitem2.nodes.empty()) {
							bitJ2 = new ImeitemIJAMBlockItem2();
							blkAitm2->imeijamblockitem2.nodes.push_back(bitJ2);

							bitJ2->refWznmAMBlockItem = blkAitm2->ref;
							bitJ2->Defval = blkAitm2->Defval;
							bitJ2->srefRefWznmMVectoritem = blkAitm2->srefRefWznmMVectoritem;
						};

						for (unsigned int ix4 = 0; ix4 < blkAitm2->imeijamblockitem2.nodes.size(); ix4++) {
							bitJ2 = blkAitm2->imeijamblockitem2.nodes[ix4];

							bitJ2->refWznmAMBlockItem = blkAitm2->ref;
							//bitJ2->Defval: TBL
							//bitJ2->refWznmMVectoritem: CUSTSQL
							if ((blkAitm2->refWznmMVector != 0) && (bitJ2->srefRefWznmMVectoritem != "")) {
								dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(blkAitm2->refWznmMVector) + " AND sref = '" + bitJ2->srefRefWznmMVectoritem + "'", bitJ2->refWznmMVectoritem);
								if (bitJ2->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",bitJ2->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(bitJ2->lineno)}});
							};

							dbswznm->tblwznmjamblockitem->insertRec(bitJ2);
							impcnt++;

							if (ix4 == 0) {
								blkAitm2->refJ = bitJ2->ref;
								blkAitm2->Defval = bitJ2->Defval;
								blkAitm2->refWznmMVectoritem = bitJ2->refWznmMVectoritem;
								dbswznm->tblwznmamblockitem->updateRec(blkAitm2);
							};
						};
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < opk->imeirmcomponentmoppack.nodes.size(); ix1++) {
				cmpRopk = opk->imeirmcomponentmoppack.nodes[ix1];

				//cmpRopk->refWznmMComponent: CUSTSQL
				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMComponent WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + cmpRopk->srefRefWznmMComponent + "'", cmpRopk->refWznmMComponent);
				if (cmpRopk->refWznmMComponent == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",cmpRopk->srefRefWznmMComponent}, {"iel","srefRefWznmMComponent"}, {"lineno",to_string(cmpRopk->lineno)}});
				cmpRopk->refWznmMOppack = opk->ref;

				dbswznm->tblwznmrmcomponentmoppack->insertRec(cmpRopk);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < opk->imeirmlibrarymoppack.nodes.size(); ix1++) {
				libRopk = opk->imeirmlibrarymoppack.nodes[ix1];

				//libRopk->refWznmMLibrary: CUSTSQL
				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMLibrary WHERE sref = '" + libRopk->srefRefWznmMLibrary + "'", libRopk->refWznmMLibrary);
				if (libRopk->refWznmMLibrary == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",libRopk->srefRefWznmMLibrary}, {"iel","srefRefWznmMLibrary"}, {"lineno",to_string(libRopk->lineno)}});
				libRopk->refWznmMOppack = opk->ref;

				dbswznm->tblwznmrmlibrarymoppack->insertRec(libRopk);
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

void JobWznmIexOpk::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexOpk::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexOpk::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexOpk::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMOppack* opk = NULL;
	ImeitemIAMOppackInvarg* opkAinv = NULL;
	ImeitemIAMOppackRetval* opkAret = NULL;
	ImeitemIMBlock1* blk1 = NULL;
	ImeitemIMOp* opx = NULL;
	ImeitemIMSquawk1* sqk1 = NULL;
	ImeitemIRMComponentMOppack* cmpRopk = NULL;
	ImeitemIRMLibraryMOppack* libRopk = NULL;
	ImeitemIAMBlockItem1* blkAitm1 = NULL;
	ImeitemIAMOpInvarg* opxAinv = NULL;
	ImeitemIAMOpRetval* opxAret = NULL;
	ImeitemIJMSquawkTitle1* sqkJtit1 = NULL;
	ImeitemIMBlock2* blk2 = NULL;
	ImeitemIMSquawk2* sqk2 = NULL;
	ImeitemIRMSquawkMStub1* sqkRstb1 = NULL;
	ImeitemIAMBlockItem2* blkAitm2 = NULL;
	ImeitemIJAMBlockItem1* bitJ1 = NULL;
	ImeitemIJMSquawkTitle2* sqkJtit2 = NULL;
	ImeitemIRMSquawkMStub2* sqkRstb2 = NULL;
	ImeitemIJAMBlockItem2* bitJ2 = NULL;

	// -- ImeIMOppack
	for (unsigned int ix0 = 0; ix0 < imeimoppack.nodes.size(); ix0++) {
		opk = imeimoppack.nodes[ix0];
		if (opk->ref != 0) dbswznm->tblwznmmoppack->removeRecByRef(opk->ref);

		for (unsigned int ix1 = 0; ix1 < opk->imeiamoppackinvarg.nodes.size(); ix1++) {
			opkAinv = opk->imeiamoppackinvarg.nodes[ix1];
			if (opkAinv->ref != 0) dbswznm->tblwznmamoppackinvarg->removeRecByRef(opkAinv->ref);
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeiamoppackretval.nodes.size(); ix1++) {
			opkAret = opk->imeiamoppackretval.nodes[ix1];
			if (opkAret->ref != 0) dbswznm->tblwznmamoppackretval->removeRecByRef(opkAret->ref);
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeimblock1.nodes.size(); ix1++) {
			blk1 = opk->imeimblock1.nodes[ix1];
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

		for (unsigned int ix1 = 0; ix1 < opk->imeimop.nodes.size(); ix1++) {
			opx = opk->imeimop.nodes[ix1];
			if (opx->ref != 0) dbswznm->tblwznmmop->removeRecByRef(opx->ref);

			for (unsigned int ix2 = 0; ix2 < opx->imeiamopinvarg.nodes.size(); ix2++) {
				opxAinv = opx->imeiamopinvarg.nodes[ix2];
				if (opxAinv->ref != 0) dbswznm->tblwznmamopinvarg->removeRecByRef(opxAinv->ref);
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeiamopretval.nodes.size(); ix2++) {
				opxAret = opx->imeiamopretval.nodes[ix2];
				if (opxAret->ref != 0) dbswznm->tblwznmamopretval->removeRecByRef(opxAret->ref);
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeimblock2.nodes.size(); ix2++) {
				blk2 = opx->imeimblock2.nodes[ix2];
				if (blk2->ref != 0) dbswznm->tblwznmmblock->removeRecByRef(blk2->ref);

				for (unsigned int ix3 = 0; ix3 < blk2->imeiamblockitem2.nodes.size(); ix3++) {
					blkAitm2 = blk2->imeiamblockitem2.nodes[ix3];
					if (blkAitm2->ref != 0) dbswznm->tblwznmamblockitem->removeRecByRef(blkAitm2->ref);

					for (unsigned int ix4 = 0; ix4 < blkAitm2->imeijamblockitem2.nodes.size(); ix4++) {
						bitJ2 = blkAitm2->imeijamblockitem2.nodes[ix4];
						if (bitJ2->ref != 0) dbswznm->tblwznmjamblockitem->removeRecByRef(bitJ2->ref);
					};
				};

			};

			for (unsigned int ix2 = 0; ix2 < opx->imeimsquawk2.nodes.size(); ix2++) {
				sqk2 = opx->imeimsquawk2.nodes[ix2];
				if (sqk2->ref != 0) dbswznm->tblwznmmsquawk->removeRecByRef(sqk2->ref);

				for (unsigned int ix3 = 0; ix3 < sqk2->imeijmsquawktitle2.nodes.size(); ix3++) {
					sqkJtit2 = sqk2->imeijmsquawktitle2.nodes[ix3];
					if (sqkJtit2->ref != 0) dbswznm->tblwznmjmsquawktitle->removeRecByRef(sqkJtit2->ref);
				};

				for (unsigned int ix3 = 0; ix3 < sqk2->imeirmsquawkmstub2.nodes.size(); ix3++) {
					sqkRstb2 = sqk2->imeirmsquawkmstub2.nodes[ix3];
					if (sqkRstb2->ref != 0) dbswznm->tblwznmrmsquawkmstub->removeRecByRef(sqkRstb2->ref);
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeimsquawk1.nodes.size(); ix1++) {
			sqk1 = opk->imeimsquawk1.nodes[ix1];
			if (sqk1->ref != 0) dbswznm->tblwznmmsquawk->removeRecByRef(sqk1->ref);

			for (unsigned int ix2 = 0; ix2 < sqk1->imeijmsquawktitle1.nodes.size(); ix2++) {
				sqkJtit1 = sqk1->imeijmsquawktitle1.nodes[ix2];
				if (sqkJtit1->ref != 0) dbswznm->tblwznmjmsquawktitle->removeRecByRef(sqkJtit1->ref);
			};

			for (unsigned int ix2 = 0; ix2 < sqk1->imeirmsquawkmstub1.nodes.size(); ix2++) {
				sqkRstb1 = sqk1->imeirmsquawkmstub1.nodes[ix2];
				if (sqkRstb1->ref != 0) dbswznm->tblwznmrmsquawkmstub->removeRecByRef(sqkRstb1->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeirmcomponentmoppack.nodes.size(); ix1++) {
			cmpRopk = opk->imeirmcomponentmoppack.nodes[ix1];
			if (cmpRopk->ref != 0) dbswznm->tblwznmrmcomponentmoppack->removeRecByRef(cmpRopk->ref);
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeirmlibrarymoppack.nodes.size(); ix1++) {
			libRopk = opk->imeirmlibrarymoppack.nodes[ix1];
			if (libRopk->ref != 0) dbswznm->tblwznmrmlibrarymoppack->removeRecByRef(libRopk->ref);
		};
	};

	return retval;
};

void JobWznmIexOpk::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexOpk::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMOppack* opk = NULL;
	ImeitemIAMOppackInvarg* opkAinv = NULL;
	ImeitemIAMOppackRetval* opkAret = NULL;
	ImeitemICAMOppackInvarg* opkAinvC = NULL;
	ImeitemICAMOppackRetval* opkAretC = NULL;
	ImeitemIMBlock1* blk1 = NULL;
	ImeitemIMOp* opx = NULL;
	ImeitemIMSquawk1* sqk1 = NULL;
	ImeitemIRMComponentMOppack* cmpRopk = NULL;
	ImeitemIRMLibraryMOppack* libRopk = NULL;
	ImeitemIAMBlockItem1* blkAitm1 = NULL;
	ImeitemIAMOpInvarg* opxAinv = NULL;
	ImeitemIAMOpRetval* opxAret = NULL;
	ImeitemICAMBlockItem1* blkAitmC1 = NULL;
	ImeitemICAMOpInvarg* opxAinvC = NULL;
	ImeitemICAMOpRetval* opxAretC = NULL;
	ImeitemIJMSquawkTitle1* sqkJtit1 = NULL;
	ImeitemIMBlock2* blk2 = NULL;
	ImeitemIMSquawk2* sqk2 = NULL;
	ImeitemIRMSquawkMStub1* sqkRstb1 = NULL;
	ImeitemIAMBlockItem2* blkAitm2 = NULL;
	ImeitemICAMBlockItem2* blkAitmC2 = NULL;
	ImeitemIJAMBlockItem1* bitJ1 = NULL;
	ImeitemIJMSquawkTitle2* sqkJtit2 = NULL;
	ImeitemIRMSquawkMStub2* sqkRstb2 = NULL;
	ImeitemIJAMBlockItem2* bitJ2 = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMOppack
	for (unsigned int ix0 = 0; ix0 < imeimoppack.nodes.size(); ix0++) {
		opk = imeimoppack.nodes[ix0];

		if (opk->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMOPPACKINVARG, ixWznmVIop)) {
			dbswznm->tblwznmamoppackinvarg->loadRefsByOpk(opk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) opk->imeiamoppackinvarg.nodes.push_back(new ImeitemIAMOppackInvarg(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeiamoppackinvarg.nodes.size(); ix1++) {
			opkAinv = opk->imeiamoppackinvarg.nodes[ix1];

			if (opkAinv->ref != 0) {
				//opkAinv->irefRefWznmCAMOppackInvarg: IREF
				opkAinv->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, opkAinv->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				opkAinv->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, opkAinv->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMOPPACKRETVAL, ixWznmVIop)) {
			dbswznm->tblwznmamoppackretval->loadRefsByOpk(opk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) opk->imeiamoppackretval.nodes.push_back(new ImeitemIAMOppackRetval(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeiamoppackretval.nodes.size(); ix1++) {
			opkAret = opk->imeiamoppackretval.nodes[ix1];

			if (opkAret->ref != 0) {
				//opkAret->irefRefWznmCAMOppackRetval: IREF
				opkAret->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, opkAret->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeicamoppackinvarg.nodes.size(); ix1++) {
			opkAinvC = opk->imeicamoppackinvarg.nodes[ix1];

			if (opkAinvC->ref != 0) {
				opkAinvC->iref = ix1+1;
			};
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeicamoppackretval.nodes.size(); ix1++) {
			opkAretC = opk->imeicamoppackretval.nodes[ix1];

			if (opkAretC->ref != 0) {
				opkAretC->iref = ix1+1;
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMBLOCK1, ixWznmVIop)) {
			dbswznm->tblwznmmblock->loadRefsByRetReu(VecWznmVMBlockRefTbl::OPK, opk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) opk->imeimblock1.nodes.push_back(new ImeitemIMBlock1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeimblock1.nodes.size(); ix1++) {
			blk1 = opk->imeimblock1.nodes[ix1];

			if (blk1->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMBLOCKITEM1, ixWznmVIop)) {
				dbswznm->tblwznmamblockitem->loadRefsByBlk(blk1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) blk1->imeiamblockitem1.nodes.push_back(new ImeitemIAMBlockItem1(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < blk1->imeiamblockitem1.nodes.size(); ix2++) {
				blkAitm1 = blk1->imeiamblockitem1.nodes[ix2];

				if (blkAitm1->ref != 0) {
					//blkAitm1->irefRefWznmCAMBlockItem: IREF
					blkAitm1->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, blkAitm1->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					blkAitm1->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, blkAitm1->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
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

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMOP, ixWznmVIop)) {
			dbswznm->tblwznmmop->loadRefsByOpk(opk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) opk->imeimop.nodes.push_back(new ImeitemIMOp(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeimop.nodes.size(); ix1++) {
			opx = opk->imeimop.nodes[ix1];

			if (opx->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMOPINVARG, ixWznmVIop)) {
				dbswznm->tblwznmamopinvarg->loadRefsByOpx(opx->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) opx->imeiamopinvarg.nodes.push_back(new ImeitemIAMOpInvarg(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeiamopinvarg.nodes.size(); ix2++) {
				opxAinv = opx->imeiamopinvarg.nodes[ix2];

				if (opxAinv->ref != 0) {
					//opxAinv->irefRefWznmCAMOpInvarg: IREF
					opxAinv->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, opxAinv->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					opxAinv->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, opxAinv->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMOPRETVAL, ixWznmVIop)) {
				dbswznm->tblwznmamopretval->loadRefsByOpx(opx->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) opx->imeiamopretval.nodes.push_back(new ImeitemIAMOpRetval(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeiamopretval.nodes.size(); ix2++) {
				opxAret = opx->imeiamopretval.nodes[ix2];

				if (opxAret->ref != 0) {
					//opxAret->irefRefWznmCAMOpRetval: IREF
					opxAret->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, opxAret->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeicamopinvarg.nodes.size(); ix2++) {
				opxAinvC = opx->imeicamopinvarg.nodes[ix2];

				if (opxAinvC->ref != 0) {
					opxAinvC->iref = ix2+1;
				};
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeicamopretval.nodes.size(); ix2++) {
				opxAretC = opx->imeicamopretval.nodes[ix2];

				if (opxAretC->ref != 0) {
					opxAretC->iref = ix2+1;
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMBLOCK2, ixWznmVIop)) {
				dbswznm->tblwznmmblock->loadRefsByRetReu(VecWznmVMBlockRefTbl::OPX, opx->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) opx->imeimblock2.nodes.push_back(new ImeitemIMBlock2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeimblock2.nodes.size(); ix2++) {
				blk2 = opx->imeimblock2.nodes[ix2];

				if (blk2->ref != 0) {
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMBLOCKITEM2, ixWznmVIop)) {
					dbswznm->tblwznmamblockitem->loadRefsByBlk(blk2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) blk2->imeiamblockitem2.nodes.push_back(new ImeitemIAMBlockItem2(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < blk2->imeiamblockitem2.nodes.size(); ix3++) {
					blkAitm2 = blk2->imeiamblockitem2.nodes[ix3];

					if (blkAitm2->ref != 0) {
						//blkAitm2->irefRefWznmCAMBlockItem: IREF
						blkAitm2->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, blkAitm2->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
						blkAitm2->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, blkAitm2->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};

					if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAMBLOCKITEM2, ixWznmVIop)) {
						dbswznm->tblwznmjamblockitem->loadRefsByBit(blkAitm2->ref, false, refs);
						for (unsigned int i = 0; i < refs.size(); i++) blkAitm2->imeijamblockitem2.nodes.push_back(new ImeitemIJAMBlockItem2(dbswznm, refs[i]));
					};

					for (unsigned int ix4 = 0; ix4 < blkAitm2->imeijamblockitem2.nodes.size(); ix4++) {
						bitJ2 = blkAitm2->imeijamblockitem2.nodes[ix4];

						if (bitJ2->ref != 0) {
							bitJ2->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, bitJ2->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
						};
					};
				};

				for (unsigned int ix3 = 0; ix3 < blk2->imeicamblockitem2.nodes.size(); ix3++) {
					blkAitmC2 = blk2->imeicamblockitem2.nodes[ix3];

					if (blkAitmC2->ref != 0) {
						blkAitmC2->iref = ix3+1;
					};
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSQUAWK2, ixWznmVIop)) {
				dbswznm->tblwznmmsquawk->loadRefsByRetReu(VecWznmVMSquawkRefTbl::OPX, opx->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) opx->imeimsquawk2.nodes.push_back(new ImeitemIMSquawk2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < opx->imeimsquawk2.nodes.size(); ix2++) {
				sqk2 = opx->imeimsquawk2.nodes[ix2];

				if (sqk2->ref != 0) {
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMSQUAWKTITLE2, ixWznmVIop)) {
					dbswznm->tblwznmjmsquawktitle->loadRefsBySqk(sqk2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == sqk2->refJTitle) {refs[i] = refs[0]; refs[0] = sqk2->refJTitle; break;};
					for (unsigned int i = 0; i < refs.size(); i++) sqk2->imeijmsquawktitle2.nodes.push_back(new ImeitemIJMSquawkTitle2(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < sqk2->imeijmsquawktitle2.nodes.size(); ix3++) {
					sqkJtit2 = sqk2->imeijmsquawktitle2.nodes[ix3];

					if (sqkJtit2->ref != 0) {
						sqkJtit2->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, sqkJtit2->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMSQUAWKMSTUB2, ixWznmVIop)) {
					dbswznm->tblwznmrmsquawkmstub->loadRefsBySqk(sqk2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) sqk2->imeirmsquawkmstub2.nodes.push_back(new ImeitemIRMSquawkMStub2(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < sqk2->imeirmsquawkmstub2.nodes.size(); ix3++) {
					sqkRstb2 = sqk2->imeirmsquawkmstub2.nodes[ix3];

					if (sqkRstb2->ref != 0) {
						sqkRstb2->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, sqkRstb2->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMSQUAWK1, ixWznmVIop)) {
			dbswznm->tblwznmmsquawk->loadRefsByRetReu(VecWznmVMSquawkRefTbl::OPK, opk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) opk->imeimsquawk1.nodes.push_back(new ImeitemIMSquawk1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeimsquawk1.nodes.size(); ix1++) {
			sqk1 = opk->imeimsquawk1.nodes[ix1];

			if (sqk1->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMSQUAWKTITLE1, ixWznmVIop)) {
				dbswznm->tblwznmjmsquawktitle->loadRefsBySqk(sqk1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == sqk1->refJTitle) {refs[i] = refs[0]; refs[0] = sqk1->refJTitle; break;};
				for (unsigned int i = 0; i < refs.size(); i++) sqk1->imeijmsquawktitle1.nodes.push_back(new ImeitemIJMSquawkTitle1(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < sqk1->imeijmsquawktitle1.nodes.size(); ix2++) {
				sqkJtit1 = sqk1->imeijmsquawktitle1.nodes[ix2];

				if (sqkJtit1->ref != 0) {
					sqkJtit1->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, sqkJtit1->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMSQUAWKMSTUB1, ixWznmVIop)) {
				dbswznm->tblwznmrmsquawkmstub->loadRefsBySqk(sqk1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) sqk1->imeirmsquawkmstub1.nodes.push_back(new ImeitemIRMSquawkMStub1(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < sqk1->imeirmsquawkmstub1.nodes.size(); ix2++) {
				sqkRstb1 = sqk1->imeirmsquawkmstub1.nodes[ix2];

				if (sqkRstb1->ref != 0) {
					sqkRstb1->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, sqkRstb1->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMCOMPONENTMOPPACK, ixWznmVIop)) {
			dbswznm->tblwznmrmcomponentmoppack->loadRefsByOpk(opk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) opk->imeirmcomponentmoppack.nodes.push_back(new ImeitemIRMComponentMOppack(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeirmcomponentmoppack.nodes.size(); ix1++) {
			cmpRopk = opk->imeirmcomponentmoppack.nodes[ix1];

			if (cmpRopk->ref != 0) {
				cmpRopk->srefRefWznmMComponent = StubWznm::getStubCmpStd(dbswznm, cmpRopk->refWznmMComponent, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMLIBRARYMOPPACK, ixWznmVIop)) {
			dbswznm->tblwznmrmlibrarymoppack->loadRefsByOpk(opk->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) opk->imeirmlibrarymoppack.nodes.push_back(new ImeitemIRMLibraryMOppack(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < opk->imeirmlibrarymoppack.nodes.size(); ix1++) {
			libRopk = opk->imeirmlibrarymoppack.nodes[ix1];

			if (libRopk->ref != 0) {
				libRopk->srefRefWznmMLibrary = StubWznm::getStubLibSref(dbswznm, libRopk->refWznmMLibrary, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexOpk::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexOpk::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexOpk::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexOpk::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmOpk::exportToFile(fullpath, xmlNotTxt, shorttags, imeimoppack);

	return retval;
};

void JobWznmIexOpk::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexOpk::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexOpk::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
