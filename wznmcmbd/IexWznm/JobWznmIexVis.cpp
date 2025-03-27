/**
	* \file JobWznmIexVis.cpp
	* job handler for job JobWznmIexVis (implementation)
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

#include "JobWznmIexVis.h"

#include "JobWznmIexVis_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmVis;

/******************************************************************************
 class JobWznmIexVis
 ******************************************************************************/

JobWznmIexVis::JobWznmIexVis(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXVIS, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexVis::~JobWznmIexVis() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexVis::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexVis::parseFromFile(
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

void JobWznmIexVis::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexVis::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexVis::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexVis::exportToFile(
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

void JobWznmIexVis::handleRequest(
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

void JobWznmIexVis::changeStage(
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

string JobWznmIexVis::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing visualization features";
			else if (ixVSge == VecVSge::PRSDONE) retval = "visualization features parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing visualization features (&impcnt; records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing visualization features import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting visualization features for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "visualization features collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting visualization features";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWznmIexVis::enterSgeIdle(
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

	imeimsheet.clear();

	return retval;
};

void JobWznmIexVis::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexVis::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmVis::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimsheet);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexVis::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexVis::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexVis::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexVis::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexVis::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexVis::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMSheet* sht = NULL;
	ImeitemIMBox* box = NULL;
	ImeitemIRMBoxMBox* boxRbox = NULL;

	set<ubigint> irefs1;

	uint num0;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint refWznmMVis;
	refWznmMVis = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref);

	ubigint refWznmMVersion;
	dbswznm->loadRefBySQL("SELECT verRefWznmMVersion FROM TblWznmMVisual WHERE ref = " + to_string(refWznmMVis), refWznmMVersion);

	string s, s2;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMSheet
		num0 = 1;

		for (unsigned int ix0 = 0; ix0 < imeimsheet.nodes.size(); ix0++) {
			sht = imeimsheet.nodes[ix0];

			sht->visRefWznmMVisual = refWznmMVis;
			sht->visNum = num0++;
			//sht->Title: TBL

			dbswznm->tblwznmmsheet->insertRec(sht);
			impcnt++;

			irefs1.clear();

			for (unsigned int ix1 = 0; ix1 < sht->imeimbox.nodes.size(); ix1++) {
				box = sht->imeimbox.nodes[ix1];

				if (irefs1.find(box->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(box->iref)}, {"ime","ImeIMBox"}, {"lineno",to_string(box->lineno)}});
				irefs1.insert(box->iref);
				box->refWznmMSheet = sht->ref;
				box->unvIxWznmVMaintable = VecWznmVMaintable::getIx(box->srefUnvIxWznmVMaintable);
				if (box->unvIxWznmVMaintable == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",box->srefUnvIxWznmVMaintable}, {"iel","srefUnvIxWznmVMaintable"}, {"lineno",to_string(box->lineno)}});
				//box->unvUref: CUSTSQL
				if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMIMPEXP) {
					// expect format <iexsref>.<imesref>
					if (box->srefUnvUref.find('.') != string::npos) {
						s = box->srefUnvUref.substr(0, box->srefUnvUref.find('.'));
						s2 = box->srefUnvUref.substr(box->srefUnvUref.find('.') + 1);

						dbswznm->loadRefBySQL("SELECT TblWznmMImpexp.ref FROM TblWznmMImpexpcplx, TblWznmMImpexp WHERE TblWznmMImpexpcplx.refWznmMVersion = " + to_string(refWznmMVersion)
									+ " AND TblWznmMImpexpcplx.ref = TblWznmMImpexp.refWznmMImpexpcplx AND TblWznmMImpexpcplx.sref = '" + s + "' AND TblWznmMImpexp.sref = '" + s2 + "'", box->unvUref);
					};
				} else if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMTABLE) dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + box->srefUnvUref + "'", box->unvUref);
				else if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMVECTOR) dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + box->srefUnvUref + "'", box->unvUref);
				if (box->unvUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",box->srefUnvUref}, {"iel","srefUnvUref"}, {"lineno",to_string(box->lineno)}});
				//box->x: TBL
				//box->y: TBL

				dbswznm->tblwznmmbox->insertRec(box);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < box->imeirmboxmbox.nodes.size(); ix2++) {
					boxRbox = box->imeirmboxmbox.nodes[ix2];

					boxRbox->orgRefWznmMBox = box->ref;
					//boxRbox->dstRefWznmMBox: IMPPP
					//boxRbox->Weight: TBL

					dbswznm->tblwznmrmboxmbox->insertRec(boxRbox);
					impcnt++;
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		for (unsigned int ix0 = 0; ix0 < imeimsheet.nodes.size(); ix0++) {
			sht = imeimsheet.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < sht->imeimbox.nodes.size(); ix1++) {
				box = sht->imeimbox.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < box->imeirmboxmbox.nodes.size(); ix2++) {
					boxRbox = box->imeirmboxmbox.nodes[ix2];

					if (boxRbox->irefDstRefWznmMBox != 0) {
						for (unsigned int i = 0; i < sht->imeimbox.nodes.size(); i++) {
							if (sht->imeimbox.nodes[i]->iref == boxRbox->irefDstRefWznmMBox) {
								boxRbox->dstRefWznmMBox = sht->imeimbox.nodes[i]->ref;
								break;
							};
						};

						if (boxRbox->dstRefWznmMBox == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(boxRbox->irefDstRefWznmMBox)}, {"iel","irefDstRefWznmMBox"}, {"lineno",to_string(boxRbox->lineno)}});
						else dbswznm->tblwznmrmboxmbox->updateRec(boxRbox);
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

void JobWznmIexVis::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexVis::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexVis::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexVis::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMSheet* sht = NULL;
	ImeitemIMBox* box = NULL;
	ImeitemIRMBoxMBox* boxRbox = NULL;

	// -- ImeIMSheet
	for (unsigned int ix0 = 0; ix0 < imeimsheet.nodes.size(); ix0++) {
		sht = imeimsheet.nodes[ix0];
		if (sht->ref != 0) dbswznm->tblwznmmsheet->removeRecByRef(sht->ref);

		for (unsigned int ix1 = 0; ix1 < sht->imeimbox.nodes.size(); ix1++) {
			box = sht->imeimbox.nodes[ix1];
			if (box->ref != 0) dbswznm->tblwznmmbox->removeRecByRef(box->ref);

			for (unsigned int ix2 = 0; ix2 < box->imeirmboxmbox.nodes.size(); ix2++) {
				boxRbox = box->imeirmboxmbox.nodes[ix2];
				if (boxRbox->ref != 0) dbswznm->tblwznmrmboxmbox->removeRecByRef(boxRbox->ref);
			};
		};
	};

	return retval;
};

void JobWznmIexVis::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexVis::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMSheet* sht = NULL;
	ImeitemIMBox* box = NULL;
	ImeitemIRMBoxMBox* boxRbox = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- RBEGIN
	ubigint ref;

	map<ubigint,ubigint> irefsBoxs; // by ref

	// -- ImeIMSheet
	for (unsigned int ix0 = 0; ix0 < imeimsheet.nodes.size(); ix0++) {
		sht = imeimsheet.nodes[ix0];

		if (sht->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMBOX, ixWznmVIop)) {
			dbswznm->tblwznmmbox->loadRefsBySht(sht->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) sht->imeimbox.nodes.push_back(new ImeitemIMBox(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < sht->imeimbox.nodes.size(); ix1++) {
			box = sht->imeimbox.nodes[ix1];

			if (box->ref != 0) {
				box->iref = ix1+1;
				irefsBoxs[box->ref] = box->iref;

				//box->srefUnvUref: STUB
				if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMIMPEXP) {
					// format <iexsref>.<imesref>
					if (dbswznm->loadRefBySQL("SELECT refWznmMImpexpcplx FROM TblWznmMImpexp WHERE ref = " + to_string(box->unvUref), ref)) box->srefUnvUref = StubWznm::getStubIexStd(dbswznm, ref) + "." + StubWznm::getStubImeStd(dbswznm, box->unvUref);
				} else if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMTABLE) box->srefUnvUref = StubWznm::getStubTblStd(dbswznm, box->unvUref);
				else if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMVECTOR) box->srefUnvUref = StubWznm::getStubVecStd(dbswznm, box->unvUref);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMBOXMBOX, ixWznmVIop)) {
				dbswznm->tblwznmrmboxmbox->loadRefsByOrg(box->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) box->imeirmboxmbox.nodes.push_back(new ImeitemIRMBoxMBox(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < box->imeirmboxmbox.nodes.size(); ix2++) {
				boxRbox = box->imeirmboxmbox.nodes[ix2];

				if (boxRbox->ref != 0) {
					//boxRbox->irefDstRefWznmMBox: IREF
				};
			};
		};
	};
	// IP enterSgeCollect.traverse --- REND
	// IP enterSgeCollect.ppr --- IBEGIN
	for (unsigned int ix0 = 0; ix0 < imeimsheet.nodes.size(); ix0++) {
		sht = imeimsheet.nodes[ix0];

		for (unsigned int ix1 = 0; ix1 < sht->imeimbox.nodes.size(); ix1++) {
			box = sht->imeimbox.nodes[ix1];

			for (unsigned int ix2 = 0; ix2 < box->imeirmboxmbox.nodes.size(); ix2++) {
				boxRbox = box->imeirmboxmbox.nodes[ix2];

				if (boxRbox->ref != 0) {
					auto it = irefsBoxs.find(boxRbox->dstRefWznmMBox);
					if (it != irefsBoxs.end()) boxRbox->irefDstRefWznmMBox = it->second;
				};
			};
		};
	};
	// IP enterSgeCollect.ppr --- IEND

	delete stcch;

	return retval;
};

void JobWznmIexVis::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexVis::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexVis::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexVis::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmVis::exportToFile(fullpath, xmlNotTxt, shorttags, imeimsheet);

	return retval;
};

void JobWznmIexVis::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexVis::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexVis::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
