/**
	* \file JobWznmIexIex.cpp
	* job handler for job JobWznmIexIex (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "JobWznmIexIex.h"

#include "JobWznmIexIex_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmIex;

/******************************************************************************
 class JobWznmIexIex
 ******************************************************************************/

JobWznmIexIex::JobWznmIexIex(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXIEX, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexIex::~JobWznmIexIex() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexIex::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexIex::parseFromFile(
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

void JobWznmIexIex::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexIex::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexIex::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexIex::exportToFile(
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

void JobWznmIexIex::handleRequest(
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

void JobWznmIexIex::changeStage(
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

string JobWznmIexIex::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing import/export structure";
			else if (ixVSge == VecVSge::PRSDONE) retval = "import/export structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing import/export structure (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing import/export structure import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting import/export structure for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "import/export structure collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting import/export structure";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexIex::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeimimpexpcplx.clear();

	return retval;
};

void JobWznmIexIex::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexIex::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmIex::parseFromFile(fullpath, xmlNotTxt, imeimimpexpcplx);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexIex::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexIex::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexIex::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexIex::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexIex::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexIex::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMImpexpcplx* iex = NULL;
	ImeitemIJMImpexpcplxTitle* iexJtit = NULL;
	ImeitemIMImpexp* ime = NULL;
	ImeitemIMImpexpcol* iel = NULL;
	ImeitemIJMImpexpcolStub* ielJstb = NULL;

	set<ubigint> irefs1;

	uint num2;

	// IP enterSgeImport.prep --- IBEGIN
	ListWznmMLocale lcls;

	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);

	ImeitemIMImpexp* ime2 = NULL;

	ubigint refWznmMVersion;
	string preflcl;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	Wznm::getVerlclsref(dbswznm, refWznmMVersion, preflcl);

	ubigint refWznmMVector;

	string Prjshort;
	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(refWznmMVersion), Prjshort);
	Prjshort = StrMod::cap(Prjshort);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMImpexpcplx
		for (unsigned int ix0 = 0; ix0 < imeimimpexpcplx.nodes.size(); ix0++) {
			iex = imeimimpexpcplx.nodes[ix0];

			iex->refWznmMVersion = refWznmMVersion;
			//iex->sref: TBL
			//iex->Short: TBL
			//iex->refJTitle: SUB
			//iex->Title: TBL
			//iex->Minversion: TBL
			//iex->Comment: TBL

			dbswznm->tblwznmmimpexpcplx->insertRec(iex);
			impcnt++;

			if (((iex->Title != "")) && iex->imeijmimpexpcplxtitle.nodes.empty()) {
				iexJtit = new ImeitemIJMImpexpcplxTitle();
				iex->imeijmimpexpcplxtitle.nodes.push_back(iexJtit);

				iexJtit->refWznmMImpexpcplx = iex->ref;
				iexJtit->Title = iex->Title;
			};

			for (unsigned int ix1 = 0; ix1 < iex->imeijmimpexpcplxtitle.nodes.size(); ix1++) {
				iexJtit = iex->imeijmimpexpcplxtitle.nodes[ix1];

				iexJtit->refWznmMImpexpcplx = iex->ref;
				//if (iexJtit->srefX1RefWznmMLocale == "") iexJtit->srefX1RefWznmMLocale: CUSTOM DEFVAL
				if (iexJtit->srefX1RefWznmMLocale == "") iexJtit->srefX1RefWznmMLocale = preflcl;
				//iexJtit->x1RefWznmMLocale: RST
				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					if (lcls.nodes[i]->sref == iexJtit->srefX1RefWznmMLocale) {
						iexJtit->x1RefWznmMLocale = lcls.nodes[i]->ref;
						break;
					};
				};
				if (iexJtit->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",iexJtit->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(iexJtit->lineno)}});
				//iexJtit->Title: TBL

				dbswznm->tblwznmjmimpexpcplxtitle->insertRec(iexJtit);
				impcnt++;

				if (ix1 == 0) {
					iex->refJTitle = iexJtit->ref;
					iex->Title = iexJtit->Title;
					dbswznm->tblwznmmimpexpcplx->updateRec(iex);
				};
			};

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < iex->imeimimpexp.nodes.size(); ix1++) {
				ime = iex->imeimimpexp.nodes[ix1];

				if (irefs1.find(ime->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(ime->iref)}, {"ime","ImeIMImpexp"}, {"lineno",to_string(ime->lineno)}});
				ime->refWznmMImpexpcplx = iex->ref;
				//ime->supRefWznmMImpexp: IMPPP
				//ime->refWznmMTable: CUSTSQL
				dbswznm->tblwznmmtable->loadRefByVerSrf(refWznmMVersion, ime->srefRefWznmMTable, ime->refWznmMTable);
				if (ime->refWznmMTable == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",ime->srefRefWznmMTable}, {"iel","srefRefWznmMTable"}, {"lineno",to_string(ime->lineno)}});
				//ime->sref: TBL
				//ime->rtrSrefsWznmMImpexpcol: TBL
				ime->ixWIop = VecWznmWMImpexpIop::getIx(ime->srefsIxWIop);
				//ime->Comment: TBL

				dbswznm->tblwznmmimpexp->insertRec(ime);
				impcnt++;

				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < ime->imeimimpexpcol.nodes.size(); ix2++) {
					iel = ime->imeimimpexpcol.nodes[ix2];

					iel->ixVBasetype = VecWznmVMImpexpcolBasetype::getIx(iel->srefIxVBasetype);
					if (iel->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",iel->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(iel->lineno)}});
					iel->ixWOccurrence = VecWznmWMImpexpcolOccurrence::getIx(iel->srefsIxWOccurrence);
					iel->imeRefWznmMImpexp = ime->ref;
					iel->imeNum = num2++;
					if (iel->srefRefWznmMTablecol != "") {
						//iel->refWznmMTablecol: CUSTSQL
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(ime->refWznmMTable) + " AND sref = '" + iel->srefRefWznmMTablecol + "'", iel->refWznmMTablecol);
						if (iel->refWznmMTablecol == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",iel->srefRefWznmMTablecol}, {"iel","srefRefWznmMTablecol"}, {"lineno",to_string(iel->lineno)}});
					};
					//iel->sref: TBL
					//iel->Short: TBL
					//iel->refWznmMImpexp: IMPPP
					iel->ixVConvtype = VecWznmVMImpexpcolConvtype::getIx(iel->srefIxVConvtype);
					if (iel->ixVConvtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",iel->srefIxVConvtype}, {"iel","srefIxVConvtype"}, {"lineno",to_string(iel->lineno)}});
					//iel->Defval: TBL
					if (iel->srefRefWznmMPreset != "") {
						//iel->refWznmMPreset: CUSTSQL
						dbswznm->tblwznmmpreset->loadRefByVerSrf(refWznmMVersion, iel->srefRefWznmMPreset, iel->refWznmMPreset);
						if (iel->refWznmMPreset == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",iel->srefRefWznmMPreset}, {"iel","srefRefWznmMPreset"}, {"lineno",to_string(iel->lineno)}});
					};
					//iel->refJStub: SUB
					if (iel->srefRefWznmMStub != "") {
						//iel->refWznmMStub: CUSTSQL
						dbswznm->loadRefBySQL("SELECT TblWznmMStub.ref FROM TblWznmMTable, TblWznmMStub WHERE TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion) + " AND TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMStub.sref = '" + iel->srefRefWznmMStub + "'", iel->refWznmMStub);
						if (iel->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",iel->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(iel->lineno)}});
					};
					if (iel->srefRefWznmMVectoritem != "") {
						//iel->refWznmMVectoritem: CUSTSQL
						dbswznm->loadRefBySQL("SELECT TblWznmMVectoritem.ref FROM TblWznmMTablecol, TblWznmMVectoritem WHERE TblWznmMVectoritem.vecRefWznmMVector = TblWznmMTablecol.fctUref AND TblWznmMTablecol.ref = " + to_string(iel->refWznmMTablecol) + " AND TblWznmMVectoritem.sref = '" + iel->srefRefWznmMVectoritem + "'", iel->refWznmMVectoritem);
						if (iel->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",iel->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(iel->lineno)}});
					};

					dbswznm->tblwznmmimpexpcol->insertRec(iel);
					impcnt++;

					if (((iel->srefRefWznmMStub != "")) && iel->imeijmimpexpcolstub.nodes.empty()) {
						ielJstb = new ImeitemIJMImpexpcolStub();
						iel->imeijmimpexpcolstub.nodes.push_back(ielJstb);

						ielJstb->refWznmMImpexpcol = iel->ref;
						ielJstb->srefRefWznmMStub = iel->srefRefWznmMStub;
					};

					if (iel->imeijmimpexpcolstub.nodes.size() > 0) {
						if (dbswznm->loadRefBySQL("SELECT TblWznmMTablecol2.fctUref FROM TblWznmMTablecol AS TblWznmMTablecol1, TblWznmMTablecol AS TblWznmMTablecol2 WHERE TblWznmMTablecol1.refWznmMRelation = TblWznmMTablecol2.refWznmMRelation AND TblWznmMTablecol1.tblRefWznmMTable = TblWznmMTablecol2.tblRefWznmMTable AND TblWznmMTablecol1.ref = "
									+ to_string(iel->refWznmMTablecol) + " AND TblWznmMTablecol2.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND TblWznmMTablecol2.sref LIKE '%VTbl'", refWznmMVector)) {

							for (unsigned int ix3 = 0; ix3 < iel->imeijmimpexpcolstub.nodes.size(); ix3++) {
								ielJstb = iel->imeijmimpexpcolstub.nodes[ix3];

								ielJstb->refWznmMImpexpcol = iel->ref;
								if (ielJstb->srefX1RefWznmMVectoritem != "") {
									//ielJstb->x1RefWznmMVectoritem = CUSTSQL;
									dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refWznmMVector) + " AND sref = '" + ielJstb->srefX1RefWznmMVectoritem + "'", ielJstb->x1RefWznmMVectoritem);
									if (ielJstb->x1RefWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",ielJstb->srefX1RefWznmMVectoritem}, {"iel","srefX1RefWznmMVectoritem"}, {"lineno",to_string(ielJstb->lineno)}});
								};
								//ielJstb->refWznmMStub = CUSTSQL;
								dbswznm->loadRefBySQL("SELECT TblWznmMStub.ref FROM TblWznmMTable, TblWznmMStub WHERE TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion) + " AND TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMStub.sref = '" + ielJstb->srefRefWznmMStub + "'", ielJstb->refWznmMStub);
								if (ielJstb->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",ielJstb->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(ielJstb->lineno)}});

								dbswznm->tblwznmjmimpexpcolstub->insertRec(ielJstb);
								impcnt++;

								if (ix3 == 0) {
									iel->refJStub = ielJstb->ref;
									iel->refWznmMStub = ielJstb->refWznmMStub;
									dbswznm->tblwznmmimpexpcol->updateRec(iel);
								};
							};
						};
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		for (unsigned int ix0 = 0; ix0 < imeimimpexpcplx.nodes.size(); ix0++) {
			iex = imeimimpexpcplx.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < iex->imeimimpexp.nodes.size(); ix1++) {
				ime = iex->imeimimpexp.nodes[ix1];

				if (ime->irefSupRefWznmMImpexp != 0) {
					for (unsigned int ix2 = 0; ix2 < iex->imeimimpexp.nodes.size(); ix2++) {
						ime2 = iex->imeimimpexp.nodes[ix2];

						if (ime2->iref == ime->irefSupRefWznmMImpexp) {
							ime->supRefWznmMImpexp = ime2->ref;
							ime->supLvl = ime2->supLvl+1;

							break;
						};
					};

					dbswznm->tblwznmmimpexp->updateRec(ime);
				};

				for (unsigned int ix2 = 0; ix2 < ime->imeimimpexpcol.nodes.size(); ix2++) {
					iel = ime->imeimimpexpcol.nodes[ix2];

					if (iel->irefRefWznmMImpexp != 0) {
						for (unsigned int ix3 = 0; ix3 < iex->imeimimpexp.nodes.size(); ix3++) {
							ime2 = iex->imeimimpexp.nodes[ix3];

							if (ime2->iref == iel->irefRefWznmMImpexp) {
								iel->refWznmMImpexp = ime2->ref;

								break;
							};
						};

						dbswznm->tblwznmmimpexpcol->updateRec(iel);
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

void JobWznmIexIex::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexIex::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexIex::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexIex::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMImpexpcplx* iex = NULL;
	ImeitemIJMImpexpcplxTitle* iexJtit = NULL;
	ImeitemIMImpexp* ime = NULL;
	ImeitemIMImpexpcol* iel = NULL;
	ImeitemIJMImpexpcolStub* ielJstb = NULL;

	// -- ImeIMImpexpcplx
	for (unsigned int ix0 = 0; ix0 < imeimimpexpcplx.nodes.size(); ix0++) {
		iex = imeimimpexpcplx.nodes[ix0];
		if (iex->ref != 0) dbswznm->tblwznmmimpexpcplx->removeRecByRef(iex->ref);

		for (unsigned int ix1 = 0; ix1 < iex->imeijmimpexpcplxtitle.nodes.size(); ix1++) {
			iexJtit = iex->imeijmimpexpcplxtitle.nodes[ix1];
			if (iexJtit->ref != 0) dbswznm->tblwznmjmimpexpcplxtitle->removeRecByRef(iexJtit->ref);
		};

		for (unsigned int ix1 = 0; ix1 < iex->imeimimpexp.nodes.size(); ix1++) {
			ime = iex->imeimimpexp.nodes[ix1];
			if (ime->ref != 0) dbswznm->tblwznmmimpexp->removeRecByRef(ime->ref);

			for (unsigned int ix2 = 0; ix2 < ime->imeimimpexpcol.nodes.size(); ix2++) {
				iel = ime->imeimimpexpcol.nodes[ix2];
				if (iel->ref != 0) dbswznm->tblwznmmimpexpcol->removeRecByRef(iel->ref);

				for (unsigned int ix3 = 0; ix3 < iel->imeijmimpexpcolstub.nodes.size(); ix3++) {
					ielJstb = iel->imeijmimpexpcolstub.nodes[ix3];
					if (ielJstb->ref != 0) dbswznm->tblwznmjmimpexpcolstub->removeRecByRef(ielJstb->ref);
				};
			};
		};
	};

	return retval;
};

void JobWznmIexIex::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexIex::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMImpexpcplx* iex = NULL;
	ImeitemIJMImpexpcplxTitle* iexJtit = NULL;
	ImeitemIMImpexp* ime = NULL;
	ImeitemIMImpexpcol* iel = NULL;
	ImeitemIJMImpexpcolStub* ielJstb = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMImpexpcplx
	for (unsigned int ix0 = 0; ix0 < imeimimpexpcplx.nodes.size(); ix0++) {
		iex = imeimimpexpcplx.nodes[ix0];

		if (iex->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMIMPEXPCPLXTITLE, ixWznmVIop)) {
			dbswznm->tblwznmjmimpexpcplxtitle->loadRefsByIex(iex->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == iex->refJTitle) {refs[i] = refs[0]; refs[0] = iex->refJTitle; break;};
			for (unsigned int i = 0; i < refs.size(); i++) iex->imeijmimpexpcplxtitle.nodes.push_back(new ImeitemIJMImpexpcplxTitle(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < iex->imeijmimpexpcplxtitle.nodes.size(); ix1++) {
			iexJtit = iex->imeijmimpexpcplxtitle.nodes[ix1];

			if (iexJtit->ref != 0) {
				iexJtit->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, iexJtit->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMIMPEXP, ixWznmVIop)) {
			dbswznm->tblwznmmimpexp->loadRefsByIex(iex->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) iex->imeimimpexp.nodes.push_back(new ImeitemIMImpexp(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < iex->imeimimpexp.nodes.size(); ix1++) {
			ime = iex->imeimimpexp.nodes[ix1];

			if (ime->ref != 0) {
				ime->iref = ix1+1;
				//ime->irefSupRefWznmMImpexp: IREF
				ime->srefRefWznmMTable = StubWznm::getStubTblStd(dbswznm, ime->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMIMPEXPCOL, ixWznmVIop)) {
				dbswznm->tblwznmmimpexpcol->loadRefsByIme(ime->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) ime->imeimimpexpcol.nodes.push_back(new ImeitemIMImpexpcol(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < ime->imeimimpexpcol.nodes.size(); ix2++) {
				iel = ime->imeimimpexpcol.nodes[ix2];

				if (iel->ref != 0) {
					iel->srefRefWznmMTablecol = StubWznm::getStubTcoSref(dbswznm, iel->refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					//iel->irefRefWznmMImpexp: IREF
					iel->srefRefWznmMPreset = StubWznm::getStubPstStd(dbswznm, iel->refWznmMPreset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					iel->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, iel->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					iel->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, iel->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMIMPEXPCOLSTUB, ixWznmVIop)) {
					dbswznm->tblwznmjmimpexpcolstub->loadRefsByIel(iel->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) iel->imeijmimpexpcolstub.nodes.push_back(new ImeitemIJMImpexpcolStub(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < iel->imeijmimpexpcolstub.nodes.size(); ix3++) {
					ielJstb = iel->imeijmimpexpcolstub.nodes[ix3];

					if (ielJstb->ref != 0) {
						ielJstb->srefX1RefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, ielJstb->x1RefWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
						ielJstb->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, ielJstb->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
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

void JobWznmIexIex::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexIex::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexIex::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexIex::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmIex::exportToFile(fullpath, xmlNotTxt, shorttags, imeimimpexpcplx);

	return retval;
};

void JobWznmIexIex::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexIex::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexIex::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


