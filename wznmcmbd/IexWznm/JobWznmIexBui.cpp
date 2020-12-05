/**
	* \file JobWznmIexBui.cpp
	* job handler for job JobWznmIexBui (implementation)
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

#include "JobWznmIexBui.h"

#include "JobWznmIexBui_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmBui;

/******************************************************************************
 class JobWznmIexBui
 ******************************************************************************/

JobWznmIexBui::JobWznmIexBui(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXBUI, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexBui::~JobWznmIexBui() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexBui::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexBui::parseFromFile(
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

void JobWznmIexBui::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexBui::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexBui::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexBui::exportToFile(
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

void JobWznmIexBui::handleRequest(
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

void JobWznmIexBui::changeStage(
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

string JobWznmIexBui::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing basic user interface structure";
			else if (ixVSge == VecVSge::PRSDONE) retval = "basic user interface structure parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing basic user interface structure (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing basic user interface structure import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting basic user interface structure for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "basic user interface structure collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting basic user interface structure";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexBui::enterSgeIdle(
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

	imeimmodule.clear();
	imeimpreset.clear();

	return retval;
};

void JobWznmIexBui::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexBui::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmBui::parseFromFile(fullpath, xmlNotTxt, rectpath, imeimmodule, imeimpreset);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexBui::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexBui::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexBui::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexBui::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexBui::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexBui::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMModule* mdl = NULL;
	ImeitemIMPreset* pst = NULL;
	ImeitemIJMModule* mdlJ = NULL;
	ImeitemIMCard* car = NULL;
	ImeitemIJMCardTitle* carJtit = NULL;

	uint num0, num1;

	// IP enterSgeImport.prep --- IBEGIN
	ubigint ref;

	WznmMPreset* pst2 = NULL;

	ubigint refWznmMVersion;
	string preflcl;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	Wznm::getVerlclsref(dbswznm, refWznmMVersion, preflcl);

	ListWznmMLocale lcls;

	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMModule
		num0 = 1;

		for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
			mdl = imeimmodule.nodes[ix0];

			//mdl->verRefWznmMVersion: PRESET
			mdl->verRefWznmMVersion = refWznmMVersion;
			mdl->verNum = num0++;
			//mdl->sref: TBL
			//mdl->refJ: SUB
			//mdl->Title: TBL
			//mdl->Comment: TBL

			dbswznm->tblwznmmmodule->insertRec(mdl);
			impcnt++;

			if (((mdl->Title != "") || (mdl->Comment != "")) && mdl->imeijmmodule.nodes.empty()) {
				mdlJ = new ImeitemIJMModule();
				mdl->imeijmmodule.nodes.push_back(mdlJ);

				mdlJ->refWznmMModule = mdl->ref;
				mdlJ->Title = mdl->Title;
				mdlJ->Comment = mdl->Comment;
			};

			for (unsigned int ix1 = 0; ix1 < mdl->imeijmmodule.nodes.size(); ix1++) {
				mdlJ = mdl->imeijmmodule.nodes[ix1];

				mdlJ->refWznmMModule = mdl->ref;
				//if (mdlJ->srefX1RefWznmMLocale == "") mdlJ->srefX1RefWznmMLocale: CUSTOM DEFVAL
				if (mdlJ->srefX1RefWznmMLocale == "") mdlJ->srefX1RefWznmMLocale = preflcl;
				//mdlJ->x1RefWznmMLocale: RST
				if (mdlJ->srefX1RefWznmMLocale != "")
					for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
						if (lcls.nodes[i]->sref == mdlJ->srefX1RefWznmMLocale) {
							mdlJ->x1RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					};
				if (mdlJ->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",mdlJ->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(mdlJ->lineno)}});
				//mdlJ->Title: TBL
				//mdlJ->Comment: TBL

				dbswznm->tblwznmjmmodule->insertRec(mdlJ);
				impcnt++;

				if (ix1 == 0) {
					mdl->refJ = mdlJ->ref;
					mdl->Title = mdlJ->Title;
					mdl->Comment = mdlJ->Comment;
					dbswznm->tblwznmmmodule->updateRec(mdl);
				};
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < mdl->imeimcard.nodes.size(); ix1++) {
				car = mdl->imeimcard.nodes[ix1];

				car->mdlRefWznmMModule = mdl->ref;
				car->mdlNum = num1++;
				car->refIxVTbl = VecWznmVMCardRefTbl::getIx(car->srefRefIxVTbl);
				if (car->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",car->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(car->lineno)}});
				//car->refUref: IMPPP
				if (car->srefRefUref != "") {
					if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
						if (dbswznm->tblwznmmtable->loadRefByVerSrf(refWznmMVersion, car->srefRefUref, ref)) car->refUref = ref;
					} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
						if (dbswznm->loadRefBySQL("SELECT TblWznmMSubset.ref FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion)
									+ " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.sref = '" + car->srefRefUref + "'", ref)) car->refUref = ref;
					};
					if (car->refUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",car->srefRefUref}, {"iel","ImeIMCard.srefRefUref"}, {"lineno",to_string(car->lineno)}});
				};
				//car->sref: TBL
				//car->refJTitle: SUB
				//car->Title: TBL
				//car->Avail: TBL
				//car->Active: TBL

				dbswznm->tblwznmmcard->insertRec(car);
				impcnt++;

				if (((car->Title != "")) && car->imeijmcardtitle.nodes.empty()) {
					carJtit = new ImeitemIJMCardTitle();
					car->imeijmcardtitle.nodes.push_back(carJtit);

					carJtit->refWznmMCard = car->ref;
					carJtit->Title = car->Title;
				};

				for (unsigned int ix2 = 0; ix2 < car->imeijmcardtitle.nodes.size(); ix2++) {
					carJtit = car->imeijmcardtitle.nodes[ix2];

					carJtit->refWznmMCard = car->ref;
					//if (carJtit->srefX1RefWznmMLocale == "") carJtit->srefX1RefWznmMLocale: CUSTOM DEFVAL
					if (carJtit->srefX1RefWznmMLocale == "") carJtit->srefX1RefWznmMLocale = preflcl;
					//carJtit->x1RefWznmMLocale: RST
					if (carJtit->srefX1RefWznmMLocale != "") {
						for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
							if (lcls.nodes[i]->sref.compare(carJtit->srefX1RefWznmMLocale) == 0) {
								carJtit->x1RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						};
					};
					if (carJtit->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",carJtit->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(carJtit->lineno)}});
					//carJtit->Title: TBL

					dbswznm->tblwznmjmcardtitle->insertRec(carJtit);
					impcnt++;

					if (ix2 == 0) {
						car->refJTitle = carJtit->ref;
						car->Title = carJtit->Title;
						dbswznm->tblwznmmcard->updateRec(car);
					};
				};
			};
		};

		// -- ImeIMPreset
		for (unsigned int ix0 = 0; ix0 < imeimpreset.nodes.size(); ix0++) {
			pst = imeimpreset.nodes[ix0];

			pst->ixWznmVIop = VecWznmVIop::getIx(pst->srefIxWznmVIop);
			if (pst->ixWznmVIop != VecWznmVIop::RETRUPD) throw SbeException(SbeException::IEX_IOP, {{"iop",pst->srefIxWznmVIop}, {"ime","ImeIMPreset"}, {"lineno",to_string(pst->lineno)}});

			if (pst->ixWznmVIop == VecWznmVIop::RETRUPD) {
				// retrieve
				if (dbswznm->tblwznmmpreset->loadRecBySQL("SELECT * FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + pst->sref + "'", &pst2)) {
					pst->ref = pst2->ref;
					pst->refWznmMVersion = pst2->refWznmMVersion;
					pst->refIxVTbl = pst2->refIxVTbl;
					pst->refUref = pst2->refUref;
					if (pst->srefIxVScope != "") {
						pst->ixVScope = VecWznmVMPresetScope::getIx(pst->srefIxVScope);					
						if (pst->ixVScope == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",pst->srefIxVScope}, {"iel","ImeIMPreset.srefIxVScope"}, {"lineno",to_string(pst->lineno)}});
					};
					pst->sref = pst2->sref;
					pst->ixWznmWArgtype = pst2->ixWznmWArgtype;
					pst->refJTitle = pst2->refJTitle;
					pst->Title = pst2->Title;

					dbswznm->tblwznmmpreset->updateRec(pst);

					delete pst2;

				} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMPreset"}, {"lineno",to_string(pst->lineno)}});
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		// -- ImeIMModule
		for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
			mdl = imeimmodule.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < mdl->imeimcard.nodes.size(); ix1++) {
				car = mdl->imeimcard.nodes[ix1];

				if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
					dbswznm->executeQuery("UPDATE TblWznmMTable SET refWznmMCard = " + to_string(car->ref) + " WHERE ref = " + to_string(car->refUref));
				} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
					dbswznm->executeQuery("UPDATE TblWznmMSubset SET refWznmMCard = " + to_string(car->ref) + " WHERE ref = " + to_string(car->refUref));
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

void JobWznmIexBui::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexBui::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexBui::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexBui::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMModule* mdl = NULL;
	ImeitemIMPreset* pst = NULL;
	ImeitemIJMModule* mdlJ = NULL;
	ImeitemIMCard* car = NULL;
	ImeitemIJMCardTitle* carJtit = NULL;

	// -- ImeIMModule
	for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
		mdl = imeimmodule.nodes[ix0];
		if (mdl->ref != 0) dbswznm->tblwznmmmodule->removeRecByRef(mdl->ref);

		for (unsigned int ix1 = 0; ix1 < mdl->imeijmmodule.nodes.size(); ix1++) {
			mdlJ = mdl->imeijmmodule.nodes[ix1];
			if (mdlJ->ref != 0) dbswznm->tblwznmjmmodule->removeRecByRef(mdlJ->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimcard.nodes.size(); ix1++) {
			car = mdl->imeimcard.nodes[ix1];
			if (car->ref != 0) dbswznm->tblwznmmcard->removeRecByRef(car->ref);

			for (unsigned int ix2 = 0; ix2 < car->imeijmcardtitle.nodes.size(); ix2++) {
				carJtit = car->imeijmcardtitle.nodes[ix2];
				if (carJtit->ref != 0) dbswznm->tblwznmjmcardtitle->removeRecByRef(carJtit->ref);
			};
		};
	};

	// -- ImeIMPreset
	for (unsigned int ix0 = 0; ix0 < imeimpreset.nodes.size(); ix0++) {
		pst = imeimpreset.nodes[ix0];
		if (pst->ref != 0) dbswznm->tblwznmmpreset->removeRecByRef(pst->ref);
	};

	return retval;
};

void JobWznmIexBui::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexBui::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMModule* mdl = NULL;
	ImeitemIMPreset* pst = NULL;
	ImeitemIJMModule* mdlJ = NULL;
	ImeitemIMCard* car = NULL;
	ImeitemIJMCardTitle* carJtit = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMModule
	for (unsigned int ix0 = 0; ix0 < imeimmodule.nodes.size(); ix0++) {
		mdl = imeimmodule.nodes[ix0];

		if (mdl->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMMODULE, ixWznmVIop)) {
			dbswznm->tblwznmjmmodule->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == mdl->refJ) {refs[i] = refs[0]; refs[0] = mdl->refJ; break;};
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeijmmodule.nodes.push_back(new ImeitemIJMModule(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeijmmodule.nodes.size(); ix1++) {
			mdlJ = mdl->imeijmmodule.nodes[ix1];

			if (mdlJ->ref != 0) {
				mdlJ->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, mdlJ->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMCARD, ixWznmVIop)) {
			dbswznm->tblwznmmcard->loadRefsByMdl(mdl->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mdl->imeimcard.nodes.push_back(new ImeitemIMCard(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mdl->imeimcard.nodes.size(); ix1++) {
			car = mdl->imeimcard.nodes[ix1];

			if (car->ref != 0) {
				car->srefRefUref = StubWznm::getStubSbsStd(dbswznm, car->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMCARDTITLE, ixWznmVIop)) {
				dbswznm->tblwznmjmcardtitle->loadRefsByCar(car->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == car->refJTitle) {refs[i] = refs[0]; refs[0] = car->refJTitle; break;};
				for (unsigned int i = 0; i < refs.size(); i++) car->imeijmcardtitle.nodes.push_back(new ImeitemIJMCardTitle(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < car->imeijmcardtitle.nodes.size(); ix2++) {
				carJtit = car->imeijmcardtitle.nodes[ix2];

				if (carJtit->ref != 0) {
					carJtit->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, carJtit->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};
	};

	// -- ImeIMPreset
	for (unsigned int ix0 = 0; ix0 < imeimpreset.nodes.size(); ix0++) {
		pst = imeimpreset.nodes[ix0];

		if (pst->ref != 0) {
			//pst->srefIxWznmVIop: IOP
			pst->srefRefUref = StubWznm::getStubSbsStd(dbswznm, pst->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexBui::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexBui::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexBui::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexBui::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmBui::exportToFile(fullpath, xmlNotTxt, shorttags, imeimmodule, imeimpreset);

	return retval;
};

void JobWznmIexBui::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexBui::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexBui::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};



