/**
	* \file JobWznmIexUix.cpp
	* job handler for job JobWznmIexUix (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "JobWznmIexUix.h"

#include "JobWznmIexUix_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmUix;

/******************************************************************************
 class JobWznmIexUix
 ******************************************************************************/

JobWznmIexUix::JobWznmIexUix(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXUIX, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexUix::~JobWznmIexUix() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void JobWznmIexUix::removeControl(
			DbsWznm* dbswznm
			, const ubigint refWznmMControl
		) {
	dbswznm->executeQuery("DELETE FROM TblWznmMFeed WHERE refWznmMControl = " + to_string(refWznmMControl));
	dbswznm->executeQuery("DELETE FROM TblWznmAMControlPar WHERE refWznmMControl = " + to_string(refWznmMControl));
	dbswznm->executeQuery("DELETE FROM TblWznmJMControl WHERE refWznmMControl = " + to_string(refWznmMControl));
	dbswznm->executeQuery("DELETE FROM TblWznmJMControlTitle WHERE refWznmMControl = " + to_string(refWznmMControl));

	dbswznm->tblwznmmcontrol->removeRecByRef(refWznmMControl);
};
// IP cust --- IEND

void JobWznmIexUix::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexUix::parseFromFile(
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

void JobWznmIexUix::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexUix::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexUix::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexUix::exportToFile(
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

void JobWznmIexUix::handleRequest(
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

void JobWznmIexUix::changeStage(
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

string JobWznmIexUix::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing custom user interface features";
			else if (ixVSge == VecVSge::PRSDONE) retval = "custom user interface features parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing custom user interface features (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing custom user interface features import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting custom user interface features for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "custom user interface features collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting custom user interface features";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexUix::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeimcard.clear();
	imeimpreset.clear();
	imeimquery.clear();
	imeirmpanelmquery.clear();

	return retval;
};

void JobWznmIexUix::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexUix::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmUix::parseFromFile(fullpath, xmlNotTxt, imeimcard, imeimpreset, imeimquery, imeirmpanelmquery);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexUix::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexUix::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexUix::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexUix::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexUix::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexUix::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIMCard* car = NULL;
	ImeitemIMPreset* pst = NULL;
	ImeitemIMQuery* qry = NULL;
	ImeitemIRMPanelMQuery* pnlRqry = NULL;
	ImeitemIAMQueryClause* qryAcse = NULL;
	ImeitemIAMQueryOrder* qryAord = NULL;
	ImeitemIJMPresetTitle* pstJtit = NULL;
	ImeitemIMControl1* con1 = NULL;
	ImeitemIMDialog* dlg = NULL;
	ImeitemIMPanel* pnl = NULL;
	ImeitemIMQuerycol* qco = NULL;
	ImeitemIMQuerymod* qmd = NULL;
	ImeitemIRMQueryMTable* qryRtbl = NULL;
	ImeitemIAMControlPar1* conApar1 = NULL;
	ImeitemICControl2* conC2 = NULL;
	ImeitemICControl3* conC3 = NULL;
	ImeitemIJMControlTitle1* conJtit1 = NULL;
	ImeitemIJMQuerycolStub* qcoJstb = NULL;
	ImeitemIMControl2* con2 = NULL;
	ImeitemIMControl3* con3 = NULL;
	ImeitemITMQuerymodMQuery* qryTqmd = NULL;
	ImeitemIAMControlPar2* conApar2 = NULL;
	ImeitemIAMControlPar3* conApar3 = NULL;
	ImeitemIJMControl2* conJ2 = NULL;
	ImeitemIJMControl3* conJ3 = NULL;
	ImeitemIJMControlTitle2* conJtit2 = NULL;
	ImeitemIJMControlTitle3* conJtit3 = NULL;
	ImeitemIMFeed2* fed2 = NULL;
	ImeitemIMFeed3* fed3 = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIMVector3* vec3 = NULL;

	set<ubigint> irefs0, irefs1, irefs2;

	uint num1, num2;

	// IP enterSgeImport.prep --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	uint cnt;

	WznmMPanel* pnl_r = NULL;

	WznmMControl* con2_r = NULL;

	ImeitemIMControl2* con22 = NULL;
	ImeitemIMControl3* con32 = NULL;

	WznmMQuerycol* qco_r = NULL;

	ListWznmMQuerycol qcos2;
	WznmMQuerycol* qco2 = NULL;

	ImeitemIMQuery* qry2 = NULL;

	WznmMQuerymod* qmd2 = NULL;

	ubigint refWznmMVersion;
	string preflcl;

	refWznmMVersion = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref);
	Wznm::getVerlclsref(dbswznm, refWznmMVersion, preflcl);

	ubigint refWznmMVector;

	string Prjshort;
	dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(refWznmMVersion), Prjshort);
	Prjshort = StrMod::cap(Prjshort);

	ListWznmMLocale lcls;
	dbswznm->tblwznmmlocale->loadRstBySQL("SELECT * FROM TblWznmMLocale", false, lcls);

	ListWznmMStub stbs;
	dbswznm->tblwznmmstub->loadRstBySQL("SELECT TblWznmMStub.* FROM TblWznmMStub, TblWznmMTable WHERE TblWznmMStub.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion), false, stbs);

	bool first, found;
	string s, s2;
	size_t ptr;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIMCard
		for (unsigned int ix0 = 0; ix0 < imeimcard.nodes.size(); ix0++) {
			car = imeimcard.nodes[ix0];

			// retrieve
			dbswznm->loadRefBySQL("SELECT TblWznmMCard.ref FROM TblWznmMModule, TblWznmMCard WHERE TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref AND TblWznmMModule.verRefWznmMVersion = "
						+ to_string(refWznmMVersion) + " AND TblWznmMCard.sref = '" + car->sref + "'", car->ref);
			if (car->ref == 0) throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMCard"}, {"lineno",to_string(car->lineno)}});

			for (unsigned int ix1 = 0; ix1 < car->imeimcontrol1.nodes.size(); ix1++) {
				con1 = car->imeimcontrol1.nodes[ix1];

				con1->ixVBasetype = VecWznmVMControlBasetype::getIx(con1->srefIxVBasetype);
				if (con1->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con1->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(con1->lineno)}});
				con1->hkIxVTbl = VecWznmVMControlHkTbl::CAR;
				con1->hkUref = car->ref;
				//con1->hkNum: CUST
				dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(car->ref), cnt);
				con1->hkNum = cnt+1;
				con1->hkIxVSection = VecWznmVMControlHkSection::getIx(con1->srefHkIxVSection);
				if (con1->hkIxVSection == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con1->srefHkIxVSection}, {"iel","srefHkIxVSection"}, {"lineno",to_string(con1->lineno)}});
				con1->refIxVTbl = VecWznmVMControlRefTbl::getIx(con1->srefRefIxVTbl);
				if (con1->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con1->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(con1->lineno)}});
				//con1->refUref: CUSTSQLPP
				//con1->supRefWznmMControl: CUSTSQL
				if (con1->srefSupRefWznmMControl != "") {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(car->ref)
								+ " AND sref = '" + con1->srefSupRefWznmMControl + "'", con1->supRefWznmMControl);
					if (con1->supRefWznmMControl == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",con1->srefSupRefWznmMControl}, {"iel","srefSupRefWznmMControl"}, {"lineno",to_string(con1->lineno)}});
				};
				//con1->supNum: TBL
				if (con1->supRefWznmMControl != 0) {
					dbswznm->executeQuery("UPDATE TblWznmMControl SET supNum = supNum + 1 WHERE supRefWznmMControl = " + to_string(con1->supRefWznmMControl) + " AND supNum >= " + to_string(con1->supNum));
				};
				con1->ixVScope = VecWznmVMControlScope::getIx(con1->srefIxVScope);
				if (con1->ixVScope == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con1->srefIxVScope}, {"iel","srefIxVScope"}, {"lineno",to_string(con1->lineno)}});
				//con1->sref: TBL
				con1->ixVSubtype = VecWznmVMControlSubtype::getIx(con1->srefIxVSubtype);
				if (con1->ixVSubtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con1->srefIxVSubtype}, {"iel","srefIxVSubtype"}, {"lineno",to_string(con1->lineno)}});
				//con1->srefsWznmMTag: TBL
				//con1->refJTitle: SUB
				//con1->Title: TBL
				//con1->Avail: TBL
				//con1->Active: TBL
				//con1->srefsKOption: TBL

				dbswznm->tblwznmmcontrol->insertRec(con1);
				impcnt++;

				if (((con1->Title != "")) && con1->imeijmcontroltitle1.nodes.empty()) {
					conJtit1 = new ImeitemIJMControlTitle1();
					con1->imeijmcontroltitle1.nodes.push_back(conJtit1);

					conJtit1->refWznmMControl = con1->ref;
					conJtit1->Title = con1->Title;
				};

				for (unsigned int ix2 = 0; ix2 < con1->imeijmcontroltitle1.nodes.size(); ix2++) {
					conJtit1 = con1->imeijmcontroltitle1.nodes[ix2];

					conJtit1->refWznmMControl = con1->ref;
					//if (conJtit1->srefX1RefWznmMLocale == "") conJtit1->srefX1RefWznmMLocale: CUSTOM DEFVAL
					if (conJtit1->srefX1RefWznmMLocale == "") conJtit1->srefX1RefWznmMLocale = preflcl;
					//conJtit1->x1RefWznmMLocale: RST
					for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
						if (lcls.nodes[i]->sref.compare(conJtit1->srefX1RefWznmMLocale) == 0) {
							conJtit1->x1RefWznmMLocale = lcls.nodes[i]->ref;
							break;
						};
					};
					if (conJtit1->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJtit1->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(conJtit1->lineno)}});
					//conJtit1->Title: TBL

					dbswznm->tblwznmjmcontroltitle->insertRec(conJtit1);
					impcnt++;

					if (ix2 == 0) {
						con1->refJTitle = conJtit1->ref;
						con1->Title = conJtit1->Title;
						dbswznm->tblwznmmcontrol->updateRec(con1);
					};
				};

				for (unsigned int ix2 = 0; ix2 < con1->imeiamcontrolpar1.nodes.size(); ix2++) {
					conApar1 = con1->imeiamcontrolpar1.nodes[ix2];

					conApar1->refWznmMControl = con1->ref;
					//conApar1->x1SrefKKey: TBL
					//conApar1->x2RefWznmMLocale: RST
					if (conApar1->srefX2RefWznmMLocale != "") {
						for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
							if (lcls.nodes[i]->sref == conApar1->srefX2RefWznmMLocale) {
								conApar1->x2RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						};
						if (conApar1->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conApar1->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(conApar1->lineno)}});
					};
					//conApar1->osrefKVal: TBL

					dbswznm->tblwznmamcontrolpar->insertRec(conApar1);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < car->imeimpanel.nodes.size(); ix1++) {
				pnl = car->imeimpanel.nodes[ix1];

				pnl->ixWznmVIop = VecWznmVIop::getIx(pnl->srefIxWznmVIop);
				if ((pnl->ixWznmVIop != VecWznmVIop::INS) && (pnl->ixWznmVIop != VecWznmVIop::RETR) && (pnl->ixWznmVIop != VecWznmVIop::RETRUPD) && (pnl->ixWznmVIop != VecWznmVIop::RMV)) throw SbeException(SbeException::IEX_IOP, {{"iop",pnl->srefIxWznmVIop}, {"ime","ImeIMPanel"}, {"lineno",to_string(pnl->lineno)}});

				if (pnl->ixWznmVIop == VecWznmVIop::INS) {
					pnl->ixVBasetype = VecWznmVMPanelBasetype::getIx(pnl->srefIxVBasetype);
					if (pnl->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",pnl->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(pnl->lineno)}});
					pnl->carRefWznmMCard = car->ref;
					//pnl->carNum: TBL
					if (pnl->carNum != 0) {
						dbswznm->executeQuery("UPDATE TblWznmMPanel SET carNum = carNum + 1 WHERE carRefWznmMCard = " + to_string(car->ref) + " AND carNum >= " + to_string(pnl->carNum));
					};
					pnl->refIxVTbl = VecWznmVMPanelRefTbl::VOID;
					//pnl->sref: TBL
					//pnl->Detach: TBL
					//pnl->Avail: TBL
					//pnl->Comment: TBL

					dbswznm->tblwznmmpanel->insertRec(pnl);
					impcnt++;

				} else if ((pnl->ixWznmVIop == VecWznmVIop::RETR) || (pnl->ixWznmVIop == VecWznmVIop::RETRUPD) || (pnl->ixWznmVIop == VecWznmVIop::RMV)) {
					// retrieve
					if (dbswznm->tblwznmmpanel->loadRecBySQL("SELECT * FROM TblWznmMPanel WHERE carRefWznmMCard = " + to_string(car->ref) + " AND sref = '" + pnl->sref + "'", &pnl_r)) {
						pnl->ref = pnl_r->ref;

						if (pnl->ixWznmVIop == VecWznmVIop::RMV) {
							dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref), false, refs);
							for (unsigned int i = 0; i < refs.size(); i++) removeControl(dbswznm, refs[i]);

							dbswznm->executeQuery("DELETE FROM TblWznmRMPanelMQuery WHERE refWznmMPanel = " + to_string(pnl->ref));

							dbswznm->tblwznmmpanel->removeRecByRef(pnl->ref);
							
							pnl->ref = 0;

						} else {
							pnl->ixVBasetype = pnl_r->ixVBasetype;
							pnl->carRefWznmMCard = pnl_r->carRefWznmMCard;
							pnl->carNum = pnl_r->carNum;
							pnl->refIxVTbl = pnl_r->refIxVTbl;
							pnl->refUref = pnl_r->refUref;
							pnl->refWznmMJob = pnl_r->refWznmMJob;
							pnl->sref = pnl_r->sref;
							pnl->Detach = pnl_r->Detach;
							if ((pnl->ixWznmVIop == VecWznmVIop::RETR) || (pnl->Avail.length() == 0)) pnl->Avail = pnl_r->Avail;
							pnl->Comment = pnl_r->Comment;

							if (pnl->ixWznmVIop == VecWznmVIop::RETRUPD) dbswznm->tblwznmmpanel->updateRec(pnl);
						};

						delete pnl_r;

					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMPanel"}, {"lineno",to_string(pnl->lineno)}});
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < pnl->imeiccontrol2.nodes.size(); ix2++) {
					conC2 = pnl->imeiccontrol2.nodes[ix2];

					if (irefs2.find(conC2->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(conC2->iref)}, {"ime","ImeICControl2"}, {"lineno",to_string(conC2->lineno)}});
					conC2->ref = dbswznm->tblwznmccontrol->getNewRef();
					irefs2.insert(conC2->iref);

					impcnt++;
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < pnl->imeimcontrol2.nodes.size(); ix2++) {
					con2 = pnl->imeimcontrol2.nodes[ix2];

					con2->ixWznmVIop = VecWznmVIop::getIx(con2->srefIxWznmVIop);
					if ((con2->ixWznmVIop != VecWznmVIop::INS) && (con2->ixWznmVIop != VecWznmVIop::RETR) && (con2->ixWznmVIop != VecWznmVIop::RETRUPD) && (con2->ixWznmVIop != VecWznmVIop::RMV)) throw SbeException(SbeException::IEX_IOP, {{"iop",con2->srefIxWznmVIop}, {"ime","ImeIMControl2"}, {"lineno",to_string(con2->lineno)}});

					if (con2->iref != 0) {
						if (irefs2.find(con2->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(con2->iref)}, {"ime","ImeIMControl2"}, {"lineno",to_string(con2->lineno)}});
						irefs2.insert(con2->iref);
					};
					if ((con2->ixWznmVIop == VecWznmVIop::INS) || (con2->srefIxVBasetype != "")) {
						con2->ixVBasetype = VecWznmVMControlBasetype::getIx(con2->srefIxVBasetype);
						if (con2->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con2->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(con2->lineno)}});
					};
					//con2->refWznmCControl: PREVIMP
					if (con2->irefRefWznmCControl != 0) {
						for (unsigned int i = 0; i < pnl->imeimcontrol2.nodes.size(); i++) {
							if (pnl->imeimcontrol2.nodes[i]->iref == con2->irefRefWznmCControl) {
								con2->refWznmCControl = pnl->imeimcontrol2.nodes[i]->ref;
								break;
							};
						};
						if (con2->refWznmCControl == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(con2->irefRefWznmCControl)}, {"iel","irefRefWznmCControl"}, {"lineno",to_string(con2->lineno)}});
					};
					con2->hkIxVTbl = VecWznmVMControlHkTbl::PNL;
					con2->hkUref = pnl->ref;
					//con2->hkNum: CUST
					dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref), cnt);
					con2->hkNum = cnt+1;
					if ((con2->ixWznmVIop == VecWznmVIop::INS) || (con2->srefHkIxVSection != "")) {
						con2->hkIxVSection = VecWznmVMControlHkSection::getIx(con2->srefHkIxVSection);
						if (con2->hkIxVSection == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con2->srefHkIxVSection}, {"iel","srefHkIxVSection"}, {"lineno",to_string(con2->lineno)}});
					};
					if ((con2->ixWznmVIop == VecWznmVIop::INS) || (con2->srefRefIxVTbl != "")) {
						con2->refIxVTbl = VecWznmVMControlRefTbl::getIx(con2->srefRefIxVTbl);
						if (con2->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con2->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(con2->lineno)}});
					};
					//con2->refUref: CUSTSQLPP
					//con2->supRefWznmMControl: IMPPP
					if ((con2->ixWznmVIop == VecWznmVIop::INS) || (con2->srefIxVScope != "")) {
						con2->ixVScope = VecWznmVMControlScope::getIx(con2->srefIxVScope);
						if (con2->ixVScope == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con2->srefIxVScope}, {"iel","srefIxVScope"}, {"lineno",to_string(con2->lineno)}});
					};
					//con2->refWznmMFeed: SUB
					//con2->sref: TBL
					if ((con2->ixWznmVIop == VecWznmVIop::INS) || (con2->srefIxVSubtype != "")) {
						con2->ixVSubtype = VecWznmVMControlSubtype::getIx(con2->srefIxVSubtype);
						if (con2->ixVSubtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con2->srefIxVSubtype}, {"iel","srefIxVSubtype"}, {"lineno",to_string(con2->lineno)}});
					};
					//con2->srefsWznmMTag: TBL
					//con2->refJTitle: SUB
					//con2->Title: TBL
					//con2->refJ: SUB
					//con2->stdRefWznmMStub: RST
					if (con2->srefStdRefWznmMStub != "") {
						for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
							if (stbs.nodes[i]->sref == con2->srefStdRefWznmMStub) {
								con2->stdRefWznmMStub = stbs.nodes[i]->ref;
								break;
							};
						};
						if (con2->stdRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",con2->srefStdRefWznmMStub}, {"iel","srefStdRefWznmMStub"}, {"lineno",to_string(con2->lineno)}});
					};
					//con2->shoRefWznmMStub: RST
					if (con2->srefShoRefWznmMStub != "") {
						for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
							if (stbs.nodes[i]->sref == con2->srefShoRefWznmMStub) {
								con2->shoRefWznmMStub = stbs.nodes[i]->ref;
								break;
							};
						};
						if (con2->shoRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",con2->srefShoRefWznmMStub}, {"iel","srefShoRefWznmMStub"}, {"lineno",to_string(con2->lineno)}});
					};
					//con2->Avail: TBL
					//con2->Active: TBL
					//con2->srefsKOption: TBL

					if (con2->ixWznmVIop == VecWznmVIop::INS) {
						dbswznm->tblwznmmcontrol->insertRec(con2);
						impcnt++;

						if (((con2->Title != "")) && con2->imeijmcontroltitle2.nodes.empty()) {
							conJtit2 = new ImeitemIJMControlTitle2();
							con2->imeijmcontroltitle2.nodes.push_back(conJtit2);

							conJtit2->srefIxWznmVIop = "ins";
							conJtit2->refWznmMControl = con2->ref;
							conJtit2->Title = con2->Title;
						};

						if (((con2->srefStdRefWznmMStub != "") || (con2->srefShoRefWznmMStub != "")) && con2->imeijmcontrol2.nodes.empty()) {
							conJ2 = new ImeitemIJMControl2();
							con2->imeijmcontrol2.nodes.push_back(conJ2);

							conJ2->srefIxWznmVIop = "ins";
							conJ2->refWznmMControl = con2->ref;
							conJ2->stdRefWznmMStub = con2->stdRefWznmMStub;
							conJ2->shoRefWznmMStub = con2->shoRefWznmMStub;
						};

					} else if ((con2->ixWznmVIop == VecWznmVIop::RETR) || (con2->ixWznmVIop == VecWznmVIop::RETRUPD) || (con2->ixWznmVIop == VecWznmVIop::RMV)) {
						// retrieve
						if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref)
									+ " AND sref = '" + con2->sref + "'", &con2_r)) {
							con2->ref = con2_r->ref;

							if (con2->ixWznmVIop == VecWznmVIop::RMV) {
								dbswznm->tblwznmmcontrol->loadHrefsdown(con2->ref, false, refs);
								for (unsigned int i = 0; i < refs.size(); i++) removeControl(dbswznm, refs[i]);
								
								con2->ref = 0;

							} else {
								con2->ixVBasetype = con2_r->ixVBasetype;
								con2->refWznmCControl = con2_r->refWznmCControl;
								con2->hkIxVTbl = con2_r->hkIxVTbl;
								con2->hkUref = con2_r->hkUref;
								con2->hkNum = con2_r->hkNum;
								con2->hkIxVSection = con2_r->hkIxVSection;
								con2->refIxVTbl = con2_r->refIxVTbl;
								con2->refUref = con2_r->refUref;
								con2->supRefWznmMControl = con2_r->supRefWznmMControl;
								con2->supLvl = con2_r->supLvl;
								con2->supNum = con2_r->supNum;
								con2->ixVScope = con2_r->ixVScope;
								con2->refWznmMFeed = con2_r->refWznmMFeed;
								con2->sref = con2_r->sref;
								con2->ixVSubtype = con2_r->ixVSubtype;
								con2->srefsWznmMTag = con2_r->srefsWznmMTag;
								con2->refJTitle = con2_r->refJTitle;
								con2->Title = con2_r->Title;
								con2->stdRefWznmMStub = con2_r->stdRefWznmMStub;
								con2->shoRefWznmMStub = con2_r->shoRefWznmMStub;
								if ((con2->ixWznmVIop == VecWznmVIop::RETR) || (con2->Avail == "")) con2->Avail = con2_r->Avail;
								if ((con2->ixWznmVIop == VecWznmVIop::RETR) || (con2->Active == "")) con2->Active = con2_r->Active;
								if ((con2->ixWznmVIop == VecWznmVIop::RETR) || (con2->srefsKOption == "")) con2->srefsKOption = con2_r->srefsKOption;

								if (con2->ixWznmVIop == VecWznmVIop::RETRUPD) dbswznm->tblwznmmcontrol->updateRec(con2);
							};

							delete con2_r;

						} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMControl2"}, {"lineno",to_string(con2->lineno)}});
					};

					for (unsigned int ix3 = 0; ix3 < con2->imeiamcontrolpar2.nodes.size(); ix3++) {
						conApar2 = con2->imeiamcontrolpar2.nodes[ix3];

						conApar2->ixWznmVIop = VecWznmVIop::getIx(conApar2->srefIxWznmVIop);
						if ((conApar2->ixWznmVIop != VecWznmVIop::INS) && (conApar2->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",conApar2->srefIxWznmVIop}, {"ime","ImeIAMControlPar2"}, {"lineno",to_string(conApar2->lineno)}});

						conApar2->refWznmMControl = con2->ref;
						//conApar2->x1SrefKKey: TBL
						//conApar2->x2RefWznmMLocale: RST
						if (conApar2->srefX2RefWznmMLocale != "") {
							for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
								if (lcls.nodes[i]->sref == conApar2->srefX2RefWznmMLocale) {
									conApar2->x2RefWznmMLocale = lcls.nodes[i]->ref;
									break;
								};
							};
							if (conApar2->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conApar2->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(conApar2->lineno)}});
						};
						//conApar2->osrefKVal: TBL

						if (conApar2->ixWznmVIop == VecWznmVIop::INS) {
							dbswznm->tblwznmamcontrolpar->insertRec(conApar2);
							impcnt++;

						} else if (conApar2->ixWznmVIop == VecWznmVIop::RETRUPD) {
							// retrieve
							if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMControlPar WHERE refWznmMControl = " + to_string(con2->ref) + " AND x1SrefKKey = '"
										+ conApar2->x1SrefKKey + "' AND x2RefWznmMLocale = " + to_string(conApar2->x2RefWznmMLocale), conApar2->ref)) {

								dbswznm->tblwznmamcontrolpar->updateRec(conApar2);

							} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIAMControlPar2"}, {"lineno",to_string(conApar2->lineno)}});
						};
					};

					for (unsigned int ix3 = 0; ix3 < con2->imeijmcontroltitle2.nodes.size(); ix3++) {
						conJtit2 = con2->imeijmcontroltitle2.nodes[ix3];

						conJtit2->ixWznmVIop = VecWznmVIop::getIx(conJtit2->srefIxWznmVIop);
						if ((conJtit2->ixWznmVIop != VecWznmVIop::INS) && (conJtit2->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",conJtit2->srefIxWznmVIop}, {"ime","ImeIJMControlTitle2"}, {"lineno",to_string(conJtit2->lineno)}});

						conJtit2->refWznmMControl = con2->ref;
						//if (conJtit2->srefX1RefWznmMLocale == "") conJtit2->srefX1RefWznmMLocale: CUSTOM DEFVAL
						if (conJtit2->srefX1RefWznmMLocale == "") conJtit2->srefX1RefWznmMLocale = preflcl;
						//conJtit2->x1RefWznmMLocale: RST
						for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
							if (lcls.nodes[i]->sref.compare(conJtit2->srefX1RefWznmMLocale) == 0) {
								conJtit2->x1RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						};
						if (conJtit2->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJtit2->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(conJtit2->lineno)}});
						//conJtit2->Title: TBL

						if (conJtit2->ixWznmVIop == VecWznmVIop::INS) {
							dbswznm->tblwznmjmcontroltitle->insertRec(conJtit2);
							impcnt++;

							if ((con2->ixWznmVIop == VecWznmVIop::INS) && (ix3 == 0)) {
								con2->refJTitle = conJtit2->ref;
								con2->Title = conJtit2->Title;
								dbswznm->tblwznmmcontrol->updateRec(con2);
							};

						} else if (conJtit2->ixWznmVIop == VecWznmVIop::RETRUPD) {
							// retrieve
							if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmJMControlTitle WHERE refWznmMControl = " + to_string(con2->ref) + " AND x1RefWznmMLocale = " + to_string(conJtit2->x1RefWznmMLocale), conJtit2->ref)) {
								dbswznm->tblwznmjmcontroltitle->updateRec(conJtit2);

								// con2 necessarily is RETR

							} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIJMControlTitle2"}, {"lineno",to_string(conJtit2->lineno)}});
						};
					};

					if ((con2->refIxVTbl == VecWznmVMControlRefTbl::TCO) && (con2->imeijmcontrol2.nodes.size() > 0)) {
						if (dbswznm->loadRefBySQL("SELECT TblWznmMTablecol2.fctUref FROM TblWznmMTablecol AS TblWznmMTablecol1, TblWznmMTablecol AS TblWznmMTablecol2 WHERE TblWznmMTablecol1.refWznmMRelation = TblWznmMTablecol2.refWznmMRelation AND TblWznmMTablecol1.tblRefWznmMTable = TblWznmMTablecol2.tblRefWznmMTable AND TblWznmMTablecol1.ref = "
									+ to_string(con2->refUref) + " AND TblWznmMTablecol2.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND TblWznmMTablecol2.sref LIKE '%VTbl'", refWznmMVector)) {

							for (unsigned int ix3 = 0; ix3 < con2->imeijmcontrol2.nodes.size(); ix3++) {
								conJ2 = con2->imeijmcontrol2.nodes[ix3];

								conJ2->ixWznmVIop = VecWznmVIop::getIx(conJ2->srefIxWznmVIop);
								if ((conJ2->ixWznmVIop != VecWznmVIop::INS) && (conJ2->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",conJ2->srefIxWznmVIop}, {"ime","ImeIJMControl2"}, {"lineno",to_string(conJ2->lineno)}});

								conJ2->refWznmMControl = con2->ref;
								if (conJ2->srefX1RefWznmMVectoritem != "") {
									//conJ2->x1RefWznmMVectoritem: CUSTSQL
									dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refWznmMVector) + " AND sref = '" + conJ2->srefX1RefWznmMVectoritem + "'", conJ2->x1RefWznmMVectoritem);
									if (conJ2->x1RefWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJ2->srefX1RefWznmMVectoritem}, {"iel","srefX1RefWznmMVectoritem"}, {"lineno",to_string(conJ2->lineno)}});
								};
								//conJ2->stdRefWznmMStub: RST
								if (conJ2->srefStdRefWznmMStub != "") {
									for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
										if (stbs.nodes[i]->sref == conJ2->srefStdRefWznmMStub) {
											conJ2->stdRefWznmMStub = stbs.nodes[i]->ref;
											break;
										};
									};
									if (conJ2->stdRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJ2->srefStdRefWznmMStub}, {"iel","srefStdRefWznmMStub"}, {"lineno",to_string(conJ2->lineno)}});
								};
								//conJ2->shoRefWznmMStub: RST
								if (conJ2->srefShoRefWznmMStub != "") {
									for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
										if (stbs.nodes[i]->sref.compare(conJ2->srefShoRefWznmMStub) == 0) {
											conJ2->shoRefWznmMStub = stbs.nodes[i]->ref;
											break;
										};
									};
									if (conJ2->shoRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJ2->srefShoRefWznmMStub}, {"iel","srefShoRefWznmMStub"}, {"lineno",to_string(conJ2->lineno)}});
								};

								if (conJ2->ixWznmVIop == VecWznmVIop::INS) {
									dbswznm->tblwznmjmcontrol->insertRec(conJ2);
									impcnt++;

									if ((con2->ixWznmVIop == VecWznmVIop::INS) && (ix3 == 0)) {
										con2->refJ = conJ2->ref;
										con2->stdRefWznmMStub = conJ2->stdRefWznmMStub;
										con2->shoRefWznmMStub = conJ2->shoRefWznmMStub;
										dbswznm->tblwznmmcontrol->updateRec(con2);
									};

								} else if (conJ2->ixWznmVIop == VecWznmVIop::RETRUPD) {
									// retrieve
									if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmJMControl WHERE refWznmMControl = " + to_string(con2->ref) + " AND x1RefWznmMVectoritem = " + to_string(conJ2->x1RefWznmMVectoritem), conJ2->ref)) {
										dbswznm->tblwznmjmcontrol->updateRec(conJ2);

										// con2 necessarily is RETR
										if (con2->refJ == conJ2->ref) {
											con2->stdRefWznmMStub = conJ2->stdRefWznmMStub;
											con2->shoRefWznmMStub = conJ2->shoRefWznmMStub;
											dbswznm->tblwznmmcontrol->updateRec(con2);
										};

									} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIJMControl2"}, {"lineno",to_string(conJ2->lineno)}});
								};
							};
						};
					};

					for (unsigned int ix3 = 0; ix3 < con2->imeimfeed2.nodes.size(); ix3++) {
						fed2 = con2->imeimfeed2.nodes[ix3];

						fed2->refWznmMControl = con2->ref;
						fed2->srcIxVTbl = VecWznmVMFeedSrcTbl::getIx(fed2->srefSrcIxVTbl);
						if (fed2->srcIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",fed2->srefSrcIxVTbl}, {"iel","srefSrcIxVTbl"}, {"lineno",to_string(fed2->lineno)}});
						//fed2->srcUref: CUSTSQL
						if (fed2->srefSrcUref != "") {
							if (fed2->srcIxVTbl == VecWznmVMFeedSrcTbl::VEC) {
								dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + fed2->srefSrcUref + "'", fed2->srcUref);
							} else if (fed2->srcIxVTbl == VecWznmVMFeedSrcTbl::TBL) {
								dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + fed2->srefSrcUref + "'", fed2->srcUref);
							};
							if (fed2->srcUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",fed2->srefSrcUref}, {"iel","srefSrcUref"}, {"lineno",to_string(fed2->lineno)}});
						};
						//fed2->sref: TBL
						//fed2->srefsWznmMVectoritem: TBL
						//fed2->srefsWznmMTag: TBL
						//fed2->Comment: TBL

						dbswznm->tblwznmmfeed->insertRec(fed2);
						impcnt++;

						if (ix3 == 0) {
							con2->refWznmMFeed = fed2->ref;
							dbswznm->tblwznmmcontrol->updateRec(con2);
						};

						for (unsigned int ix4 = 0; ix4 < fed2->imeimvector2.nodes.size(); ix4++) {
							vec2 = fed2->imeimvector2.nodes[ix4];

							vec2->ixVBasetype = VecWznmVMVectorBasetype::getIx(vec2->srefIxVBasetype);
							if (vec2->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec2->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec2->lineno)}});
							//vec2->refWznmMVersion: PRESET
							vec2->refWznmMVersion = refWznmMVersion;
							vec2->hkIxVTbl = VecWznmVMVectorHkTbl::JOB;
							//vec2->sref: TBL
							//vec2->osrefWznmKTaggrp: TBL
							//vec2->srefsKOption: TBL

							dbswznm->tblwznmmvector->insertRec(vec2);
							impcnt++;

							if (ix4 == 0) {
								fed2->srcUref = vec2->ref;
								dbswznm->tblwznmmfeed->updateRec(fed2);
							};
						};
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < car->imeimdialog.nodes.size(); ix1++) {
				dlg = car->imeimdialog.nodes[ix1];

				dlg->ixVBasetype = VecWznmVMDialogBasetype::getIx(dlg->srefIxVBasetype);
				if (dlg->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",dlg->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(dlg->lineno)}});
				dlg->refWznmMCard = car->ref;
				dlg->refIxVTbl = VecWznmVMDialogRefTbl::getIx(dlg->srefRefIxVTbl);
				if (dlg->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",dlg->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(dlg->lineno)}});
				//dlg->refUref: CUSTSQL
				if (dlg->srefRefUref != "") {
					if (dlg->refIxVTbl == VecWznmVMDialogRefTbl::TBL) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + dlg->srefRefUref + "'", dlg->refUref);
					} else if (dlg->refIxVTbl == VecWznmVMDialogRefTbl::REL) {
						// difficult ...
					} else if (dlg->refIxVTbl == VecWznmVMDialogRefTbl::IEX) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMImpexpcplx WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + dlg->srefRefUref + "'", dlg->refUref);
					};
					if (dlg->refUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",dlg->srefRefUref}, {"iel","srefRefUref"}, {"lineno",to_string(dlg->lineno)}});
				};
				//dlg->sref: TBL
				//dlg->Comment: TBL

				dbswznm->tblwznmmdialog->insertRec(dlg);
				impcnt++;

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < dlg->imeiccontrol3.nodes.size(); ix2++) {
					conC3 = dlg->imeiccontrol3.nodes[ix2];

					if (irefs2.find(conC3->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(conC3->iref)}, {"ime","ImeICControl3"}, {"lineno",to_string(conC3->lineno)}});
					conC3->ref = dbswznm->tblwznmccontrol->getNewRef();
					irefs2.insert(conC3->iref);

					impcnt++;
				};

				irefs2.clear();
				num2 = 1;

				for (unsigned int ix2 = 0; ix2 < dlg->imeimcontrol3.nodes.size(); ix2++) {
					con3 = dlg->imeimcontrol3.nodes[ix2];

					if (con3->iref != 0) {
						if (irefs2.find(con3->iref) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(con3->iref)}, {"ime","ImeIMControl3"}, {"lineno",to_string(con3->lineno)}});
						irefs2.insert(con3->iref);
					};
					con3->ixVBasetype = VecWznmVMControlBasetype::getIx(con3->srefIxVBasetype);
					if (con3->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con3->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(con3->lineno)}});
					//con3->refWznmCControl: PREVIMP
					if (con3->irefRefWznmCControl != 0) {
						for (unsigned int i = 0; i < dlg->imeiccontrol3.nodes.size(); i++) {
							if (dlg->imeiccontrol3.nodes[i]->iref == con3->irefRefWznmCControl) {
								con3->refWznmCControl = dlg->imeiccontrol3.nodes[i]->ref;
								break;
							};
						};
						if (con3->refWznmCControl == 0) throw SbeException(SbeException::IEX_IREF, {{"iref",to_string(con3->irefRefWznmCControl)}, {"iel","irefRefWznmCControl"}, {"lineno",to_string(con3->lineno)}});
					};
					con3->hkIxVTbl = VecWznmVMControlHkTbl::DLG;
					con3->hkUref = dlg->ref;
					con3->hkNum = num2++;
					con3->hkIxVSection = VecWznmVMControlHkSection::getIx(con3->srefHkIxVSection);
					if (con3->hkIxVSection == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con3->srefHkIxVSection}, {"iel","srefHkIxVSection"}, {"lineno",to_string(con3->lineno)}});
					con3->refIxVTbl = VecWznmVMControlRefTbl::getIx(con3->srefRefIxVTbl);
					if (con3->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con3->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(con3->lineno)}});
					//con3->refUref: CUSTSQLPP
					//con3->supRefWznmMControl: IMPPP
					con3->ixVScope = VecWznmVMControlScope::getIx(con3->srefIxVScope);
					if (con3->ixVScope == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con3->srefIxVScope}, {"iel","srefIxVScope"}, {"lineno",to_string(con3->lineno)}});
					//con3->refWznmMFeed: SUB
					//con3->sref: TBL
					con3->ixVSubtype = VecWznmVMControlSubtype::getIx(con3->srefIxVSubtype);
					if (con3->ixVSubtype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",con3->srefIxVSubtype}, {"iel","srefIxVSubtype"}, {"lineno",to_string(con3->lineno)}});
					//con3->srefsWznmMTag: TBL
					//con3->refJTitle: SUB
					//con3->Title: TBL
					//con3->refJ: SUB
					//con3->stdRefWznmMStub: RST
					if (con3->srefStdRefWznmMStub != "") {
						for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
							if (stbs.nodes[i]->sref.compare(con3->srefStdRefWznmMStub) == 0) {
								con3->stdRefWznmMStub = stbs.nodes[i]->ref;
								break;
							};
						};
						if (con3->stdRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",con3->srefStdRefWznmMStub}, {"iel","srefStdRefWznmMStub"}, {"lineno",to_string(con3->lineno)}});
					};
					//con3->shoRefWznmMStub: RST
					if (con3->srefShoRefWznmMStub != "") {
						for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
							if (stbs.nodes[i]->sref.compare(con3->srefShoRefWznmMStub) == 0) {
								con3->shoRefWznmMStub = stbs.nodes[i]->ref;
								break;
							};
						};
						if (con3->shoRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",con3->srefShoRefWznmMStub}, {"iel","srefShoRefWznmMStub"}, {"lineno",to_string(con3->lineno)}});
					};
					//con3->Avail: TBL
					//con3->Active: TBL
					//con3->srefsKOption: TBL

					dbswznm->tblwznmmcontrol->insertRec(con3);
					impcnt++;

					if (((con3->Title != "")) && con3->imeijmcontroltitle3.nodes.empty()) {
						conJtit3 = new ImeitemIJMControlTitle3();
						con3->imeijmcontroltitle3.nodes.push_back(conJtit3);

						conJtit3->refWznmMControl = con3->ref;
						conJtit3->Title = con3->Title;
					};

					if (((con3->srefStdRefWznmMStub != "") || (con3->srefShoRefWznmMStub != "")) && con3->imeijmcontrol3.nodes.empty()) {
						conJ3 = new ImeitemIJMControl3();
						con3->imeijmcontrol3.nodes.push_back(conJ3);

						conJ3->refWznmMControl = con3->ref;
						conJ3->stdRefWznmMStub = con3->stdRefWznmMStub;
						conJ3->shoRefWznmMStub = con3->shoRefWznmMStub;
					};

					for (unsigned int ix3 = 0; ix3 < con3->imeiamcontrolpar3.nodes.size(); ix3++) {
						conApar3 = con3->imeiamcontrolpar3.nodes[ix3];

						conApar3->refWznmMControl = con3->ref;
						//conApar3->x1SrefKKey: TBL
						//conApar3->x2RefWznmMLocale: RST
						if (conApar3->srefX2RefWznmMLocale != "") {
							for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
								if (lcls.nodes[i]->sref.compare(conApar3->srefX2RefWznmMLocale) == 0) {
									conApar3->x2RefWznmMLocale = lcls.nodes[i]->ref;
									break;
								};
							};
							if (conApar3->x2RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conApar3->srefX2RefWznmMLocale}, {"iel","srefX2RefWznmMLocale"}, {"lineno",to_string(conApar3->lineno)}});
						};
						//conApar3->osrefKVal: TBL

						dbswznm->tblwznmamcontrolpar->insertRec(conApar3);
						impcnt++;
					};

					for (unsigned int ix3 = 0; ix3 < con3->imeijmcontroltitle3.nodes.size(); ix3++) {
						conJtit3 = con3->imeijmcontroltitle3.nodes[ix3];

						conJtit3->refWznmMControl = con3->ref;
						//if (conJtit3->srefX1RefWznmMLocale == "") conJtit3->srefX1RefWznmMLocale: CUSTOM DEFVAL
						if (conJtit3->srefX1RefWznmMLocale == "") conJtit3->srefX1RefWznmMLocale = preflcl;
						//conJtit3->x1RefWznmMLocale: RST
						for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
							if (lcls.nodes[i]->sref.compare(conJtit3->srefX1RefWznmMLocale) == 0) {
								conJtit3->x1RefWznmMLocale = lcls.nodes[i]->ref;
								break;
							};
						};
						if (conJtit3->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJtit3->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(conJtit3->lineno)}});
						//conJtit3->Title: TBL

						dbswznm->tblwznmjmcontroltitle->insertRec(conJtit3);
						impcnt++;

						if (ix3 == 0) {
							con3->refJTitle = conJtit3->ref;
							con3->Title = conJtit3->Title;
							dbswznm->tblwznmmcontrol->updateRec(con3);
						};
					};

					if ((con3->refIxVTbl == VecWznmVMControlRefTbl::TCO) && (con3->imeijmcontrol3.nodes.size() > 0)) {
						if (dbswznm->loadRefBySQL("SELECT TblWznmMTablecol2.fctUref FROM TblWznmMTablecol AS TblWznmMTablecol1, TblWznmMTablecol AS TblWznmMTablecol2 WHERE TblWznmMTablecol1.refWznmMRelation = TblWznmMTablecol2.refWznmMRelation AND TblWznmMTablecol1.tblRefWznmMTable = TblWznmMTablecol2.tblRefWznmMTable AND TblWznmMTablecol1.ref = "
									+ to_string(con3->refUref) + " AND TblWznmMTablecol2.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND TblWznmMTablecol2.sref LIKE '%VTbl'", refWznmMVector)) {

							for (unsigned int ix3 = 0; ix3 < con3->imeijmcontrol3.nodes.size(); ix3++) {
								conJ3 = con3->imeijmcontrol3.nodes[ix3];

								conJ3->refWznmMControl = con3->ref;
								if (conJ3->srefX1RefWznmMVectoritem != "") {
									//conJ3->x1RefWznmMVectoritem: CUSTSQL
									dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refWznmMVector) + " AND sref = '" + conJ3->srefX1RefWznmMVectoritem + "'", conJ3->x1RefWznmMVectoritem);
									if (conJ3->x1RefWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJ3->srefX1RefWznmMVectoritem}, {"iel","srefX1RefWznmMVectoritem"}, {"lineno",to_string(conJ3->lineno)}});
								};
								//conJ3->stdRefWznmMStub: RST
								if (conJ3->srefStdRefWznmMStub != "") {
									for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
										if (stbs.nodes[i]->sref.compare(conJ3->srefStdRefWznmMStub) == 0) {
											conJ3->stdRefWznmMStub = stbs.nodes[i]->ref;
											break;
										};
									};
									if (conJ3->stdRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJ3->srefStdRefWznmMStub}, {"iel","srefStdRefWznmMStub"}, {"lineno",to_string(conJ3->lineno)}});
								};
								//conJ3->shoRefWznmMStub: RST
								if (conJ3->srefShoRefWznmMStub != "") {
									for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
										if (stbs.nodes[i]->sref.compare(conJ3->srefShoRefWznmMStub) == 0) {
											conJ3->shoRefWznmMStub = stbs.nodes[i]->ref;
											break;
										};
									};
									if (conJ3->shoRefWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",conJ3->srefShoRefWznmMStub}, {"iel","srefShoRefWznmMStub"}, {"lineno",to_string(conJ3->lineno)}});
								};

								dbswznm->tblwznmjmcontrol->insertRec(conJ3);
								impcnt++;

								if (ix3 == 0) {
									con3->refJ = conJ3->ref;
									con3->stdRefWznmMStub = conJ3->stdRefWznmMStub;
									con3->shoRefWznmMStub = conJ3->shoRefWznmMStub;
									dbswznm->tblwznmmcontrol->updateRec(con3);
								};
							};
						};
					};

					for (unsigned int ix3 = 0; ix3 < con3->imeimfeed3.nodes.size(); ix3++) {
						fed3 = con3->imeimfeed3.nodes[ix3];

						fed3->refWznmMControl = con3->ref;
						fed3->srcIxVTbl = VecWznmVMFeedSrcTbl::getIx(fed3->srefSrcIxVTbl);
						if (fed3->srcIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",fed3->srefSrcIxVTbl}, {"iel","srefSrcIxVTbl"}, {"lineno",to_string(fed3->lineno)}});
						//fed3->srcUref: CUSTSQL
						if (fed3->srefSrcUref != "") {
							if (fed3->srcIxVTbl == VecWznmVMFeedSrcTbl::VEC) {
								dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + fed3->srefSrcUref + "'", fed3->srcUref);
							} else if (fed3->srcIxVTbl == VecWznmVMFeedSrcTbl::TBL) {
								dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + fed3->srefSrcUref + "'", fed3->srcUref);
							};
							if (fed3->srcUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",fed3->srefSrcUref}, {"iel","srefSrcUref"}, {"lineno",to_string(fed3->lineno)}});
						};
						//fed3->sref: TBL
						//fed3->srefsWznmMVectoritem: TBL
						//fed3->srefsWznmMTag: TBL
						//fed3->Comment: TBL

						dbswznm->tblwznmmfeed->insertRec(fed3);
						impcnt++;

						if (ix3 == 0) {
							con3->refWznmMFeed = fed3->ref;
							dbswznm->tblwznmmcontrol->updateRec(con3);
						};

						for (unsigned int ix4 = 0; ix4 < fed3->imeimvector3.nodes.size(); ix4++) {
							vec3 = fed3->imeimvector3.nodes[ix4];

							vec3->ixVBasetype = VecWznmVMVectorBasetype::getIx(vec3->srefIxVBasetype);
							if (vec3->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vec3->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(vec3->lineno)}});
							//vec3->refWznmMVersion: PRESET
							vec3->refWznmMVersion = refWznmMVersion;
							vec3->hkIxVTbl = VecWznmVMVectorHkTbl::JOB;
							//vec3->sref: TBL
							//vec3->osrefWznmKTaggrp: TBL
							//vec3->srefsKOption: TBL

							dbswznm->tblwznmmvector->insertRec(vec3);
							impcnt++;

							if (ix4 == 0) {
								fed3->srcUref = vec3->ref;
								dbswznm->tblwznmmfeed->updateRec(fed3);
							};
						};
					};
				};
			};
		};

		// -- ImeIMPreset
		for (unsigned int ix0 = 0; ix0 < imeimpreset.nodes.size(); ix0++) {
			pst = imeimpreset.nodes[ix0];

			pst->ixWznmVIop = VecWznmVIop::getIx(pst->srefIxWznmVIop);
			if ((pst->ixWznmVIop != VecWznmVIop::INS) && (pst->ixWznmVIop != VecWznmVIop::RMV)) throw SbeException(SbeException::IEX_IOP, {{"iop",pst->srefIxWznmVIop}, {"ime","ImeIMPreset"}, {"lineno",to_string(pst->lineno)}});

			if (pst->ixWznmVIop == VecWznmVIop::INS) {
				//pst->refWznmMVersion: PRESET
				pst->refWznmMVersion = refWznmMVersion;
				pst->refIxVTbl = VecWznmVMPresetRefTbl::getIx(pst->srefRefIxVTbl);
				if (pst->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",pst->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(pst->lineno)}});
				//pst->refUref: CUSTSQL
				if (pst->srefRefUref != "") {
					if (pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + pst->srefRefUref + "'", pst->refUref);
					} else if (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS) {
						dbswznm->loadRefBySQL("SELECT TblWznmMSubset.ref FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMTable.refWznmMVersion = "
									+ to_string(refWznmMVersion) + " AND TblWznmMSubset.sref = '" + pst->srefRefUref + "'", pst->refUref);
					} else if (pst->refIxVTbl == VecWznmVMPresetRefTbl::VEC) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + pst->srefRefUref + "'", pst->refUref);
					};
					if (pst->refUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",pst->srefRefUref}, {"iel","srefRefUref"}, {"lineno",to_string(pst->lineno)}});
				};
				pst->ixVScope = VecWznmVMPresetScope::getIx(pst->srefIxVScope);
				if (pst->ixVScope == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",pst->srefIxVScope}, {"iel","srefIxVScope"}, {"lineno",to_string(pst->lineno)}});
				//pst->sref: TBL
				pst->ixWznmWArgtype = VecWznmWArgtype::getIx(pst->srefIxWznmWArgtype);
				//pst->refJTitle: SUB
				//pst->Title: TBL

				dbswznm->tblwznmmpreset->insertRec(pst);
				impcnt++;

				if (((pst->Title != "")) && pst->imeijmpresettitle.nodes.empty()) {
					pstJtit = new ImeitemIJMPresetTitle();
					pst->imeijmpresettitle.nodes.push_back(pstJtit);

					pstJtit->refWznmMPreset = pst->ref;
					pstJtit->Title = pst->Title;
				};

			} else if (pst->ixWznmVIop == VecWznmVIop::RMV) {
				// retrieve
				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + pst->sref + "'", pst->ref)) {
					dbswznm->executeQuery("DELETE FROM TblWznmJMPresetTitle WHERE refWznmMPreset = " + to_string(pst->ref));
					dbswznm->tblwznmmpreset->removeRecByRef(pst->ref);
				} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMPreset"}, {"lineno",to_string(pst->lineno)}});
			};

			for (unsigned int ix1 = 0; ix1 < pst->imeijmpresettitle.nodes.size(); ix1++) {
				pstJtit = pst->imeijmpresettitle.nodes[ix1];

				pstJtit->refWznmMPreset = pst->ref;
				//if (pstJtit->srefX1RefWznmMLocale == "") pstJtit->srefX1RefWznmMLocale: CUSTOM DEFVAL
				if (pstJtit->srefX1RefWznmMLocale == "") pstJtit->srefX1RefWznmMLocale = preflcl;
				//pstJtit->x1RefWznmMLocale: RST
				for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
					if (lcls.nodes[i]->sref.compare(pstJtit->srefX1RefWznmMLocale) == 0) {
						pstJtit->x1RefWznmMLocale = lcls.nodes[i]->ref;
						break;
					};
				};
				if (pstJtit->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",pstJtit->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(pstJtit->lineno)}});
				//pstJtit->Title: TBL

				dbswznm->tblwznmjmpresettitle->insertRec(pstJtit);
				impcnt++;

				if (ix1 == 0) {
					pst->refJTitle = pstJtit->ref;
					pst->Title = pstJtit->Title;
					dbswznm->tblwznmmpreset->updateRec(pst);
				};
			};
		};

		// -- ImeIMQuery
		irefs0.clear();

		for (unsigned int ix0 = 0; ix0 < imeimquery.nodes.size(); ix0++) {
			qry = imeimquery.nodes[ix0];

			qry->ixWznmVIop = VecWznmVIop::getIx(qry->srefIxWznmVIop);
			if ((qry->ixWznmVIop != VecWznmVIop::INS) && (qry->ixWznmVIop != VecWznmVIop::RETR) && (qry->ixWznmVIop != VecWznmVIop::RMV)) throw SbeException(SbeException::IEX_IOP, {{"iop",qry->srefIxWznmVIop}, {"ime","ImeIMQuery"}, {"lineno",to_string(qry->lineno)}});

			if (qry->ixWznmVIop == VecWznmVIop::INS) {
				if (irefs0.find(qry->iref) != irefs0.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(qry->iref)}, {"ime","ImeIMQuery"}, {"lineno",to_string(qry->lineno)}});
				irefs0.insert(qry->iref);
				qry->ixVBasetype = VecWznmVMQueryBasetype::getIx(qry->srefIxVBasetype);
				if (qry->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",qry->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(qry->lineno)}});
				//qry->refWznmMVersion: PRESET
				qry->refWznmMVersion = refWznmMVersion;
				//qry->supRefWznmMQuery: IMPPP
				qry->supIxVSubrole = VecWznmVMQuerySupSubrole::getIx(qry->srefSupIxVSubrole);
				if (qry->supIxVSubrole == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",qry->srefSupIxVSubrole}, {"iel","srefSupIxVSubrole"}, {"lineno",to_string(qry->lineno)}});
				//qry->refRTable: SUB
				//qry->sref: TBL
				//qry->inoRefAOrder: SUB
				//qry->Limofs: TBL
				//qry->Comment: TBL

				dbswznm->tblwznmmquery->insertRec(qry);
				impcnt++;

			} else if ((qry->ixWznmVIop == VecWznmVIop::RETR) || (qry->ixWznmVIop == VecWznmVIop::RMV)) {
				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMQuery WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qry->sref + "'", qry->ref)) {
					if (qry->ixWznmVIop == VecWznmVIop::RMV) {
						dbswznm->tblwznmmquerycol->loadRstByQry(qry->ref, false, qcos2);
						for (unsigned int i = 0; i < qcos2.nodes.size(); i++) {
							qco2 = qcos2.nodes[i];

							dbswznm->executeQuery("DELETE FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(qco2->ref));

							dbswznm->tblwznmmquerycol->removeRecByRef(qco2->ref);
						};

						dbswznm->executeQuery("DELETE FROM TblWznmRMQueryMTable WHERE refWznmMQuery = " + to_string(qry->ref));
						dbswznm->executeQuery("DELETE FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref));
						dbswznm->executeQuery("DELETE FROM TblWznmRMPanelMQuery WHERE refWznmMQuery = " + to_string(qry->ref));

						dbswznm->tblwznmmquery->removeRecByRef(qry->ref);
					};
				} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMQuery"}, {"lineno",to_string(qry->lineno)}});
			};

			for (unsigned int ix1 = 0; ix1 < qry->imeirmquerymtable.nodes.size(); ix1++) {
				qryRtbl = qry->imeirmquerymtable.nodes[ix1];

				qryRtbl->refWznmMQuery = qry->ref;
				//qryRtbl->refWznmMTable: CUSTSQL
				dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qryRtbl->srefRefWznmMTable + "'", qryRtbl->refWznmMTable);
				if (qryRtbl->refWznmMTable == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qryRtbl->srefRefWznmMTable}, {"iel","srefRefWznmMTable"}, {"lineno",to_string(qryRtbl->lineno)}});
				//qryRtbl->Source: TBL
				//qryRtbl->Prefix: TBL

				dbswznm->tblwznmrmquerymtable->insertRec(qryRtbl);
				impcnt++;

				if (ix1 == 0) {
					qry->refRTable = qryRtbl->ref;
					qry->refWznmMTable = qryRtbl->refWznmMTable;
					dbswznm->tblwznmmquery->updateRec(qry);
				};

				irefs2.clear();

				for (unsigned int ix2 = 0; ix2 < qryRtbl->imeitmquerymodmquery.nodes.size(); ix2++) {
					qryTqmd = qryRtbl->imeitmquerymodmquery.nodes[ix2];

					if (qryTqmd->irefRefWznmMQuerymod != 0) {
						if (irefs2.find(qryTqmd->irefRefWznmMQuerymod) != irefs2.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(qryTqmd->irefRefWznmMQuerymod)}, {"ime","ImeITMQuerymodMQuery"}, {"lineno",to_string(qryTqmd->lineno)}});
						irefs2.insert(qryTqmd->irefRefWznmMQuerymod);
					};
					qryTqmd->refR = qryRtbl->ref;

					dbswznm->tblwznmtmquerymodmquery->insertRec(qryTqmd);
					impcnt++;
				};
			};

			for (unsigned int ix1 = 0; ix1 < qry->imeiamqueryclause.nodes.size(); ix1++) {
				qryAcse = qry->imeiamqueryclause.nodes[ix1];

				qryAcse->qryRefWznmMQuery = qry->ref;
				//qryAcse->x1RefWznmMQuerymod: IMPPP
				qryAcse->ixVBasetype = VecWznmVAMQueryClauseBasetype::getIx(qryAcse->srefIxVBasetype);
				if (qryAcse->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",qryAcse->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(qryAcse->lineno)}});
				//qryAcse->Clause: TBL
				//qryAcse->refWznmMPreset: CUSTSQL
				if (qryAcse->ixVBasetype == VecWznmVAMQueryClauseBasetype::PRE) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qryAcse->srefRefWznmMPreset + "'", qryAcse->refWznmMPreset);
					if (qryAcse->refWznmMPreset == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qryAcse->srefRefWznmMPreset}, {"iel","srefRefWznmMPreset"}, {"lineno",to_string(qryAcse->lineno)}});
				};
				//qryAcse->refWznmMVector: CUSTSQL
				if (qryAcse->ixVBasetype == VecWznmVAMQueryClauseBasetype::VIT) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qryAcse->srefRefWznmMVector + "'", qryAcse->refWznmMVector);
					if (qryAcse->refWznmMVector == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qryAcse->srefRefWznmMVector}, {"iel","srefRefWznmMVector"}, {"lineno",to_string(qryAcse->lineno)}});
				};
				//qryAcse->refWznmMVectoritem: CUSTSQL
				if ((qryAcse->refWznmMVector != 0) && (qryAcse->srefRefWznmMVectoritem != "")) {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(qryAcse->refWznmMVector) + " AND sref = '" + qryAcse->srefRefWznmMVectoritem + "'", qryAcse->refWznmMVectoritem);
					if (qryAcse->refWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qryAcse->srefRefWznmMVectoritem}, {"iel","srefRefWznmMVectoritem"}, {"lineno",to_string(qryAcse->lineno)}});
				};

				dbswznm->tblwznmamqueryclause->insertRec(qryAcse);
				impcnt++;
			};

			irefs1.clear();
			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < qry->imeimquerymod.nodes.size(); ix1++) {
				qmd = qry->imeimquerymod.nodes[ix1];

				qmd->ixWznmVIop = VecWznmVIop::getIx(qmd->srefIxWznmVIop);
				if ((qmd->ixWznmVIop != VecWznmVIop::INS) && (qmd->ixWznmVIop != VecWznmVIop::RETRUPD) && (qmd->ixWznmVIop != VecWznmVIop::RMV)) throw SbeException(SbeException::IEX_IOP, {{"iop",qmd->srefIxWznmVIop}, {"ime","ImeIMQuerymod"}, {"lineno",to_string(qmd->lineno)}});

				if (qmd->iref != 0) {
					if (irefs1.find(qmd->iref) != irefs1.end()) throw SbeException(SbeException::IEX_IDIREF, {{"idiref",to_string(qmd->iref)}, {"ime","ImeIMQuerymod"}, {"lineno",to_string(qmd->lineno)}});
					irefs1.insert(qmd->iref);
				};
				if ((qmd->ixWznmVIop == VecWznmVIop::INS) || (qmd->srefIxVBasetype != "")) {
					qmd->ixVBasetype = VecWznmVMQuerymodBasetype::getIx(qmd->srefIxVBasetype);
					if (qmd->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",qmd->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(qmd->lineno)}});
				};
				qmd->qryRefWznmMQuery = qry->ref;
				qmd->qryNum = num1++;
				//qmd->refWznmMPreset: CUSTSQL
				if (qmd->srefRefWznmMPreset != "") {
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qmd->srefRefWznmMPreset + "'", qmd->refWznmMPreset);
					if (qmd->refWznmMPreset == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qmd->srefRefWznmMPreset}, {"iel","srefRefWznmMPreset"}, {"lineno",to_string(qmd->lineno)}});
				};
				qmd->refIxVTbl = VecWznmVMQuerymodRefTbl::getIx(qmd->srefRefIxVTbl);
				if (qmd->refIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",qmd->srefRefIxVTbl}, {"iel","srefRefIxVTbl"}, {"lineno",to_string(qmd->lineno)}});
				//qmd->refUref: CUSTSQL
				if (qmd->srefRefUref != "") {
					if (qmd->refIxVTbl == VecWznmVMQuerymodRefTbl::TCO) {
						// expect format <tblsref>.<tcosref>
						if (qmd->srefRefUref.find('.') != string::npos) {
							s = qmd->srefRefUref.substr(0, qmd->srefRefUref.find('.'));
							s2 = qmd->srefRefUref.substr(qmd->srefRefUref.find('.') + 1);

							dbswznm->loadRefBySQL("SELECT TblWznmMTablecol.ref FROM TblWznmMTable, TblWznmMTablecol WHERE TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion)
										+ " AND TblWznmMTablecol.tblRefWznmMTable = TblWznmMTable.ref AND TblWznmMTable.sref = '" + s + "' AND TblWznmMTablecol.sref = '" + s2 + "'", qmd->refUref);
						};
					} else if (qmd->refIxVTbl == VecWznmVMQuerymodRefTbl::TBL) {
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qmd->srefRefUref + "'", qmd->refUref);
					};
					if (qmd->refUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qmd->srefRefUref}, {"iel","srefRefUref"}, {"lineno",to_string(qmd->lineno)}});
				};
				//qmd->Avail: TBL

				if (qmd->ixWznmVIop == VecWznmVIop::INS) {
					dbswznm->tblwznmmquerymod->insertRec(qmd);
					impcnt++;

				} else if ((qmd->ixWznmVIop == VecWznmVIop::RETRUPD) || (qmd->ixWznmVIop == VecWznmVIop::RMV)) {
					// retrieve
					if (dbswznm->tblwznmmquerymod->loadRecBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND refIxVTbl = " + to_string(qmd->refIxVTbl)
								+ " AND refUref = " + to_string(qmd->refUref), &qmd2)) {
						qmd->ref = qmd2->ref;

						if (qmd->ixWznmVIop == VecWznmVIop::RMV) {
							dbswznm->executeQuery("DELETE FROM TblWznmAMQueryClause WHERE x1RefWznmMQuerymod = " + to_string(qmd2->ref));

							dbswznm->tblwznmmquerymod->removeRecByRef(qmd2->ref);

						} else {
							qmd->ixVBasetype = qmd2->ixVBasetype;
							qmd->qryNum = qmd2->qryNum;
							//qmd->refWznmMPreset = qmd2->refWznmMPreset;
							//qmd->Avail = qmd2->Avail;

							dbswznm->tblwznmmquerymod->updateRec(qmd);

							// transfer change in presetting to related query clause
							dbswznm->executeQuery("UPDATE TblWznmAMQueryClause SET refWznmMPreset = " + to_string(qmd->refWznmMPreset) + " WHERE qryRefWznmMQuery = " + to_string(qry->ref)
										+ " AND x1RefWznmMQuerymod = " + to_string(qmd->ref) + " AND refWznmMPreset = " + to_string(qmd2->refWznmMPreset));
						};

						delete qmd2;

					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMQuerymod"}, {"lineno",to_string(qmd->lineno)}});
				};
			};

			first = true;

			for (unsigned int ix1 = 0; ix1 < qry->imeiamqueryorder.nodes.size(); ix1++) {
				qryAord = qry->imeiamqueryorder.nodes[ix1];

				qryAord->ixWznmVIop = VecWznmVIop::getIx(qryAord->srefIxWznmVIop);
				if ((qryAord->ixWznmVIop != VecWznmVIop::INS) && (qryAord->ixWznmVIop != VecWznmVIop::RMV)) throw SbeException(SbeException::IEX_IOP, {{"iop",qryAord->srefIxWznmVIop}, {"ime","ImeIAMQueryOrder"}, {"lineno",to_string(qryAord->lineno)}});

				if (qryAord->ixWznmVIop == VecWznmVIop::INS) {
					qryAord->refWznmMQuery = qry->ref;
					//qryAord->Short = ;
					//qryAord->srefsWznmMTablecol = ;

					dbswznm->tblwznmamqueryorder->insertRec(qryAord);
					impcnt++;

					if (first) {
						qry->inoRefAOrder = qryAord->ref;
						qry->inoSrefsWznmMTablecol = qryAord->srefsWznmMTablecol;
						
						dbswznm->tblwznmmquery->updateRec(qry);

						first = false;
					};

				} else if (qryAord->ixWznmVIop == VecWznmVIop::RMV) {
					// retrieve
					if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMQueryOrder WHERE refWznmMQuery = " + to_string(qry->ref) + " AND Short = '" + qryAord->Short + "'", qryAord->ref)) {
						dbswznm->tblwznmamqueryorder->removeRecByRef(qryAord->ref);
					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIAMQueryOrder"}, {"lineno",to_string(qryAord->lineno)}});
				};
			};

			num1 = 1;

			for (unsigned int ix1 = 0; ix1 < qry->imeimquerycol.nodes.size(); ix1++) {
				qco = qry->imeimquerycol.nodes[ix1];

				qco->ixWznmVIop = VecWznmVIop::getIx(qco->srefIxWznmVIop);
				if ((qco->ixWznmVIop != VecWznmVIop::INS) && (qco->ixWznmVIop != VecWznmVIop::RETR) && (qco->ixWznmVIop != VecWznmVIop::RETRUPD) && (qco->ixWznmVIop != VecWznmVIop::RMV)) throw SbeException(SbeException::IEX_IOP, {{"iop",qco->srefIxWznmVIop}, {"ime","ImeIMQuerycol"}, {"lineno",to_string(qco->lineno)}});

				if ((qco->ixWznmVIop == VecWznmVIop::INS) || (qco->srefIxVBasetype != "")) {
					qco->ixVBasetype = VecWznmVMQuerycolBasetype::getIx(qco->srefIxVBasetype);
					if (qco->ixVBasetype == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",qco->srefIxVBasetype}, {"iel","srefIxVBasetype"}, {"lineno",to_string(qco->lineno)}});
				};
				qco->ixWOccurrence = VecWznmWMQuerycolOccurrence::getIx(qco->srefsIxWOccurrence);
				qco->qryRefWznmMQuery = qry->ref;
				qco->qryNum = num1++;
				//qco->refWznmMTablecol: CUSTSQL
				if (qco->srefRefWznmMTablecol != "") {
					s = qco->srefRefWznmMTablecol;
					s2 = qco->srefRefWznmMTablecol;
					ptr = qco->srefRefWznmMTablecol.find('.');
					if (ptr != string::npos) {
						s = qco->srefRefWznmMTablecol.substr(0, ptr);
						s2 = qco->srefRefWznmMTablecol.substr(ptr + 1);
					};
					if (qry->imeirmquerymtable.nodes.size() == 1) {
						// single table
						dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(qry->refWznmMTable) + " AND sref = '" + s2 + "'", qco->refWznmMTablecol);
					} else {
						// expect format <tblsref>.<tcosref>
						dbswznm->loadRefBySQL("SELECT TblWznmMTablecol.ref FROM TblWznmMTable, TblWznmMTablecol WHERE TblWznmMTable.refWznmMVersion = " + to_string(refWznmMVersion)
									+ " AND TblWznmMTablecol.tblRefWznmMTable = TblWznmMTable.ref AND TblWznmMTable.sref = '" + s + "' AND TblWznmMTablecol.sref = '" + s2 + "'", qco->refWznmMTablecol);
					};
					if (qco->refWznmMTablecol == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qco->srefRefWznmMTablecol}, {"iel","srefRefWznmMTablecol"}, {"lineno",to_string(qco->lineno)}});
				};
				//qco->sref: TBL
				//qco->Short: TBL
				//qco->refWznmMStub: RST
				if (qco->srefRefWznmMStub != "") {
					for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
						if (stbs.nodes[i]->sref.compare(qco->srefRefWznmMStub) == 0) {
							qco->refWznmMStub = stbs.nodes[i]->ref;
							break;
						};
					};
					if (qco->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qco->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(qco->lineno)}});
				};

				if (qco->ixWznmVIop == VecWznmVIop::INS) {
					dbswznm->tblwznmmquerycol->insertRec(qco);
					impcnt++;

				} else if ((qco->ixWznmVIop == VecWznmVIop::RETR) || (qco->ixWznmVIop == VecWznmVIop::RETRUPD) || (qco->ixWznmVIop == VecWznmVIop::RMV)) {
					// retrieve
					if (dbswznm->tblwznmmquerycol->loadRecBySQL("SELECT * FROM TblWznmMQuerycol WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND sref = '" + qco->sref + "'", &qco_r)) {
						qco->ref = qco_r->ref;

						if (qco->ixWznmVIop == VecWznmVIop::RMV) {
							dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMControl WHERE refIxVTbl = " + to_string(VecWznmVMControlRefTbl::QCO) + " AND refUref = " + to_string(qco->ref), false, refs);
							for (unsigned int i = 0; i < refs.size(); i++) removeControl(dbswznm, refs[i]);

							dbswznm->executeQuery("DELETE FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(qco->ref));

							dbswznm->tblwznmmquerycol->removeRecByRef(qco->ref);

							qco->ref = 0;

						} else {
							qco->ixVBasetype = qco_r->ixVBasetype;
							qco->ixWOccurrence = qco_r->ixWOccurrence;
							qco->qryRefWznmMQuery = qco_r->qryRefWznmMQuery;
							qco->qryNum = qco_r->qryNum;
							qco->refWznmMTablecol = qco_r->refWznmMTablecol;
							qco->sref = qco_r->sref;
							qco->Short = qco_r->Short;
							if ((qco->ixWznmVIop == VecWznmVIop::RETR) || (qco->refWznmMStub == 0)) qco->refWznmMStub = qco_r->refWznmMStub;

							if (qco->ixWznmVIop == VecWznmVIop::RETRUPD) dbswznm->tblwznmmquerycol->updateRec(qco);
						};

						delete qco_r;

					} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIMQuerycol"}, {"lineno",to_string(qco->lineno)}});
				};

				if (qco->imeijmquerycolstub.nodes.size() > 0) {
					if (dbswznm->loadRefBySQL("SELECT TblWznmMTablecol2.fctUref FROM TblWznmMTablecol AS TblWznmMTablecol1, TblWznmMTablecol AS TblWznmMTablecol2 WHERE TblWznmMTablecol1.refWznmMRelation = TblWznmMTablecol2.refWznmMRelation AND TblWznmMTablecol1.tblRefWznmMTable = TblWznmMTablecol2.tblRefWznmMTable AND TblWznmMTablecol1.ref = "
								+ to_string(qco->refWznmMTablecol) + " AND TblWznmMTablecol2.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND TblWznmMTablecol2.sref LIKE '%VTbl'", refWznmMVector)) {

						for (unsigned int ix2 = 0; ix2 < qco->imeijmquerycolstub.nodes.size(); ix2++) {
							qcoJstb = qco->imeijmquerycolstub.nodes[ix2];

							qcoJstb->ixWznmVIop = VecWznmVIop::getIx(qcoJstb->srefIxWznmVIop);
							if ((qcoJstb->ixWznmVIop != VecWznmVIop::INS) && (qcoJstb->ixWznmVIop != VecWznmVIop::RETRUPD)) throw SbeException(SbeException::IEX_IOP, {{"iop",qcoJstb->srefIxWznmVIop}, {"ime","ImeIJMQuerycolStub"}, {"lineno",to_string(qcoJstb->lineno)}});

							qcoJstb->refWznmMQuerycol = qco->ref;
							//qcoJstb->x1RefWznmMVectoritem: CUSTSQL
							if (qcoJstb->srefX1RefWznmMVectoritem != "") { 
								dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(refWznmMVector) + " AND sref = '" + qcoJstb->srefX1RefWznmMVectoritem + "'", qcoJstb->x1RefWznmMVectoritem);
								if (qcoJstb->x1RefWznmMVectoritem == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qcoJstb->srefX1RefWznmMVectoritem}, {"iel","srefX1RefWznmMVectoritem"}, {"lineno",to_string(qcoJstb->lineno)}});
							};
							//qcoJstb->x2RefWznmMPreset: CUSTSQL
							if (qcoJstb->srefX2RefWznmMPreset != "") {
								dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qcoJstb->srefX2RefWznmMPreset + "'", qcoJstb->x2RefWznmMPreset);
								if (qcoJstb->x2RefWznmMPreset == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qcoJstb->srefX2RefWznmMPreset}, {"iel","srefX2RefWznmMPreset"}, {"lineno",to_string(qcoJstb->lineno)}});
							};
							//qcoJstb->refWznmMStub: RST
							for (unsigned int i = 0; i < stbs.nodes.size(); i++) {
								if (stbs.nodes[i]->sref.compare(qcoJstb->srefRefWznmMStub) == 0) {
									qcoJstb->refWznmMStub = stbs.nodes[i]->ref;
									break;
								};
							};
							if (qcoJstb->refWznmMStub == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",qcoJstb->srefRefWznmMStub}, {"iel","srefRefWznmMStub"}, {"lineno",to_string(qcoJstb->lineno)}});

							if (qcoJstb->ixWznmVIop == VecWznmVIop::INS) {
								dbswznm->tblwznmjmquerycolstub->insertRec(qcoJstb);
								impcnt++;

							} else if (qcoJstb->ixWznmVIop == VecWznmVIop::RETRUPD) {
								// retrieve
								if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(qco->ref) + " AND x1RefWznmMVectoritem = " + to_string(qcoJstb->x1RefWznmMVectoritem)
											+ " AND x2RefWznmMPreset = " + to_string(qcoJstb->x2RefWznmMPreset), qcoJstb->ref)) {
									dbswznm->tblwznmjmquerycolstub->updateRec(qcoJstb);
								} else throw SbeException(SbeException::IEX_RETR, {{"ime","ImeIJMQuerycolStub"}, {"lineno",to_string(qcoJstb->lineno)}});
							};
						};
					};
				};
			};
		};

		// -- ImeIRMPanelMQuery
		for (unsigned int ix0 = 0; ix0 < imeirmpanelmquery.nodes.size(); ix0++) {
			pnlRqry = imeirmpanelmquery.nodes[ix0];

			//pnlRqry->refWznmMPanel: PREVIMP
			found = false;
			for (unsigned int i = 0; i < imeimcard.nodes.size(); i++) {
				car = imeimcard.nodes[i];
				for (unsigned int j = 0; j < car->imeimpanel.nodes.size(); j++) {
					pnl = car->imeimpanel.nodes[j];
					if (pnl->sref.compare(pnlRqry->srefRefWznmMPanel) == 0) {
						pnlRqry->refWznmMPanel = pnl->ref;
						found = true;
						break;
					};
				};
				if (found) break;
			};
			if (pnlRqry->refWznmMPanel == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",pnlRqry->srefRefWznmMPanel}, {"iel","srefRefWznmMPanel"}, {"lineno",to_string(pnlRqry->lineno)}});
			//pnlRqry->refWznmMQuery: PREVIMP
			for (unsigned int i = 0; i < imeimquery.nodes.size(); i++) {
				qry = imeimquery.nodes[i];
				if (qry->sref.compare(pnlRqry->srefRefWznmMQuery) == 0) {
					pnlRqry->refWznmMQuery = qry->ref;
					break;
				};
			};
			if (pnlRqry->refWznmMQuery == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",pnlRqry->srefRefWznmMQuery}, {"iel","srefRefWznmMQuery"}, {"lineno",to_string(pnlRqry->lineno)}});

			dbswznm->tblwznmrmpanelmquery->insertRec(pnlRqry);
			impcnt++;
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		for (unsigned int ix0 = 0; ix0 < imeimcard.nodes.size(); ix0++) {
			car = imeimcard.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < car->imeimcontrol1.nodes.size(); ix1++) {
				con1 = car->imeimcontrol1.nodes[ix1];

				//con1->refUref = CUSTSQLPP;
				if (con1->srefRefUref != "") {
					if (con1->refIxVTbl == VecWznmVMControlRefTbl::DLG) {
						dbswznm->loadRefBySQL("SELECT TblWznmMDialog.ref FROM TblWznmMModule, TblWznmMCard, TblWznmMDialog WHERE TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref AND TblWznmMModule.verRefWznmMVersion = "
									+ to_string(refWznmMVersion) + " AND TblWznmMCard.ref = TblWznmMDialog.refWznmMCard AND TblWznmMDialog.sref = '"
									+ con1->srefRefUref + "'", con1->refUref);

						dbswznm->executeQuery("UPDATE TblWznmMControl SET refUref = " + to_string(con1->refUref) + " WHERE ref = " + to_string(con1->ref));
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < car->imeimpanel.nodes.size(); ix1++) {
				pnl = car->imeimpanel.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < pnl->imeimcontrol2.nodes.size(); ix2++) {
					con2 = pnl->imeimcontrol2.nodes[ix2];

					if ((con2->ixWznmVIop == VecWznmVIop::INS) && (con2->irefSupRefWznmMControl != 0)) {
						//con2->refUref = CUSTSQLPP;
						//con2->supRefWznmMControl = IMPPP;
						for (unsigned int i = 0; i < pnl->imeimcontrol2.nodes.size(); i++) {
							con22 = pnl->imeimcontrol2.nodes[i];
							if (con22->iref == con2->irefSupRefWznmMControl) {
								con2->supRefWznmMControl = con22->ref;
								con2->supLvl = con22->supLvl + 1;
								break;
							};
						};

						dbswznm->executeQuery("UPDATE TblWznmMControl SET supRefWznmMControl = " + to_string(con2->supRefWznmMControl) + ", supLvl = " + to_string(con2->supLvl) + " WHERE ref = " + to_string(con2->ref));
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < car->imeimdialog.nodes.size(); ix1++) {
				dlg = car->imeimdialog.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < dlg->imeimcontrol3.nodes.size(); ix2++) {
					con3 = dlg->imeimcontrol3.nodes[ix2];

					if (con3->irefSupRefWznmMControl != 0) {
						//con3->refUref = CUSTSQLPP;
						//con3->supRefWznmMControl = IMPPP;
						for (unsigned int i = 0; i < dlg->imeimcontrol3.nodes.size(); i++) {
							con32 = dlg->imeimcontrol3.nodes[i];
							if (con32->iref == con3->irefSupRefWznmMControl) {
								con3->supRefWznmMControl = con32->ref;
								con3->supLvl = con32->supLvl + 1;
								break;
							};
						};

						dbswznm->executeQuery("UPDATE TblWznmMControl SET supRefWznmMControl = " + to_string(con3->supRefWznmMControl) + ", supLvl = " + to_string(con3->supLvl) + " WHERE ref = " + to_string(con3->ref));
					};
				};
			};
		};

		for (unsigned int ix0 = 0; ix0 < imeimquery.nodes.size(); ix0++) {
			qry = imeimquery.nodes[ix0];

			if ((qry->ixWznmVIop == VecWznmVIop::INS) && (qry->irefSupRefWznmMQuery != 0)) {
				for (unsigned int i = 0; i < imeimquery.nodes.size(); i++) {
					qry2 = imeimquery.nodes[i];
					
					if (qry2->iref == qry->irefSupRefWznmMQuery) {
						qry->supRefWznmMQuery = qry2->ref;
						
						break;
					};
				};

				dbswznm->tblwznmmquery->updateRec(qry);
			};

			for (unsigned int ix1 = 0; ix1 < qry->imeirmquerymtable.nodes.size(); ix1++) {
				qryRtbl = qry->imeirmquerymtable.nodes[ix1];

				for (unsigned int ix2 = 0; ix2 < qryRtbl->imeitmquerymodmquery.nodes.size(); ix2++) {
					qryTqmd = qryRtbl->imeitmquerymodmquery.nodes[ix2];

					if (qryTqmd->irefRefWznmMQuerymod != 0) {
						for (unsigned int i = 0; i < qry->imeimquerymod.nodes.size(); i++) {
							qmd = qry->imeimquerymod.nodes[i];

							if (qmd->iref == qryTqmd->irefRefWznmMQuerymod) {
								qryTqmd->refWznmMQuerymod = qmd->ref;

								break;
							};
						};

						dbswznm->tblwznmtmquerymodmquery->updateRec(qryTqmd);
					};
				};
			};

			for (unsigned int ix1 = 0; ix1 < qry->imeiamqueryclause.nodes.size(); ix1++) {
				qryAcse = qry->imeiamqueryclause.nodes[ix1];

				if (qryAcse->irefX1RefWznmMQuerymod != 0) {
					for (unsigned int i = 0; i < qry->imeimquerymod.nodes.size(); i++) {
						qmd = qry->imeimquerymod.nodes[i];

						if (qmd->iref == qryAcse->irefX1RefWznmMQuerymod) {
							qryAcse->x1RefWznmMQuerymod = qmd->ref;

							break;
						};
					};

					dbswznm->tblwznmamqueryclause->updateRec(qryAcse);
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

void JobWznmIexUix::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexUix::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexUix::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexUix::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIMCard* car = NULL;
	ImeitemIMPreset* pst = NULL;
	ImeitemIMQuery* qry = NULL;
	ImeitemIRMPanelMQuery* pnlRqry = NULL;
	ImeitemIAMQueryClause* qryAcse = NULL;
	ImeitemIAMQueryOrder* qryAord = NULL;
	ImeitemIJMPresetTitle* pstJtit = NULL;
	ImeitemIMControl1* con1 = NULL;
	ImeitemIMDialog* dlg = NULL;
	ImeitemIMPanel* pnl = NULL;
	ImeitemIMQuerycol* qco = NULL;
	ImeitemIMQuerymod* qmd = NULL;
	ImeitemIRMQueryMTable* qryRtbl = NULL;
	ImeitemIAMControlPar1* conApar1 = NULL;
	ImeitemIJMControlTitle1* conJtit1 = NULL;
	ImeitemIJMQuerycolStub* qcoJstb = NULL;
	ImeitemIMControl2* con2 = NULL;
	ImeitemIMControl3* con3 = NULL;
	ImeitemITMQuerymodMQuery* qryTqmd = NULL;
	ImeitemIAMControlPar2* conApar2 = NULL;
	ImeitemIAMControlPar3* conApar3 = NULL;
	ImeitemIJMControl2* conJ2 = NULL;
	ImeitemIJMControl3* conJ3 = NULL;
	ImeitemIJMControlTitle2* conJtit2 = NULL;
	ImeitemIJMControlTitle3* conJtit3 = NULL;
	ImeitemIMFeed2* fed2 = NULL;
	ImeitemIMFeed3* fed3 = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIMVector3* vec3 = NULL;

	// -- ImeIMCard
	for (unsigned int ix0 = 0; ix0 < imeimcard.nodes.size(); ix0++) {
		car = imeimcard.nodes[ix0];
		if (car->ref != 0) dbswznm->tblwznmmcard->removeRecByRef(car->ref);

		for (unsigned int ix1 = 0; ix1 < car->imeimcontrol1.nodes.size(); ix1++) {
			con1 = car->imeimcontrol1.nodes[ix1];
			if (con1->ref != 0) dbswznm->tblwznmmcontrol->removeRecByRef(con1->ref);

			for (unsigned int ix2 = 0; ix2 < con1->imeiamcontrolpar1.nodes.size(); ix2++) {
				conApar1 = con1->imeiamcontrolpar1.nodes[ix2];
				if (conApar1->ref != 0) dbswznm->tblwznmamcontrolpar->removeRecByRef(conApar1->ref);
			};

			for (unsigned int ix2 = 0; ix2 < con1->imeijmcontroltitle1.nodes.size(); ix2++) {
				conJtit1 = con1->imeijmcontroltitle1.nodes[ix2];
				if (conJtit1->ref != 0) dbswznm->tblwznmjmcontroltitle->removeRecByRef(conJtit1->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < car->imeimdialog.nodes.size(); ix1++) {
			dlg = car->imeimdialog.nodes[ix1];
			if (dlg->ref != 0) dbswznm->tblwznmmdialog->removeRecByRef(dlg->ref);

			for (unsigned int ix2 = 0; ix2 < dlg->imeimcontrol3.nodes.size(); ix2++) {
				con3 = dlg->imeimcontrol3.nodes[ix2];
				if (con3->ref != 0) dbswznm->tblwznmmcontrol->removeRecByRef(con3->ref);

				for (unsigned int ix3 = 0; ix3 < con3->imeiamcontrolpar3.nodes.size(); ix3++) {
					conApar3 = con3->imeiamcontrolpar3.nodes[ix3];
					if (conApar3->ref != 0) dbswznm->tblwznmamcontrolpar->removeRecByRef(conApar3->ref);
				};

				for (unsigned int ix3 = 0; ix3 < con3->imeijmcontrol3.nodes.size(); ix3++) {
					conJ3 = con3->imeijmcontrol3.nodes[ix3];
					if (conJ3->ref != 0) dbswznm->tblwznmjmcontrol->removeRecByRef(conJ3->ref);
				};

				for (unsigned int ix3 = 0; ix3 < con3->imeijmcontroltitle3.nodes.size(); ix3++) {
					conJtit3 = con3->imeijmcontroltitle3.nodes[ix3];
					if (conJtit3->ref != 0) dbswznm->tblwznmjmcontroltitle->removeRecByRef(conJtit3->ref);
				};

				for (unsigned int ix3 = 0; ix3 < con3->imeimfeed3.nodes.size(); ix3++) {
					fed3 = con3->imeimfeed3.nodes[ix3];
					if (fed3->ref != 0) dbswznm->tblwznmmfeed->removeRecByRef(fed3->ref);

					for (unsigned int ix4 = 0; ix4 < fed3->imeimvector3.nodes.size(); ix4++) {
						vec3 = fed3->imeimvector3.nodes[ix4];
						if (vec3->ref != 0) dbswznm->tblwznmmvector->removeRecByRef(vec3->ref);
					};
				};
			};
		};

		for (unsigned int ix1 = 0; ix1 < car->imeimpanel.nodes.size(); ix1++) {
			pnl = car->imeimpanel.nodes[ix1];
			if (pnl->ref != 0) dbswznm->tblwznmmpanel->removeRecByRef(pnl->ref);

			for (unsigned int ix2 = 0; ix2 < pnl->imeimcontrol2.nodes.size(); ix2++) {
				con2 = pnl->imeimcontrol2.nodes[ix2];
				if (con2->ref != 0) dbswznm->tblwznmmcontrol->removeRecByRef(con2->ref);

				for (unsigned int ix3 = 0; ix3 < con2->imeiamcontrolpar2.nodes.size(); ix3++) {
					conApar2 = con2->imeiamcontrolpar2.nodes[ix3];
					if (conApar2->ref != 0) dbswznm->tblwznmamcontrolpar->removeRecByRef(conApar2->ref);
				};

				for (unsigned int ix3 = 0; ix3 < con2->imeijmcontrol2.nodes.size(); ix3++) {
					conJ2 = con2->imeijmcontrol2.nodes[ix3];
					if (conJ2->ref != 0) dbswznm->tblwznmjmcontrol->removeRecByRef(conJ2->ref);
				};

				for (unsigned int ix3 = 0; ix3 < con2->imeijmcontroltitle2.nodes.size(); ix3++) {
					conJtit2 = con2->imeijmcontroltitle2.nodes[ix3];
					if (conJtit2->ref != 0) dbswznm->tblwznmjmcontroltitle->removeRecByRef(conJtit2->ref);
				};

				for (unsigned int ix3 = 0; ix3 < con2->imeimfeed2.nodes.size(); ix3++) {
					fed2 = con2->imeimfeed2.nodes[ix3];
					if (fed2->ref != 0) dbswznm->tblwznmmfeed->removeRecByRef(fed2->ref);

					for (unsigned int ix4 = 0; ix4 < fed2->imeimvector2.nodes.size(); ix4++) {
						vec2 = fed2->imeimvector2.nodes[ix4];
						if (vec2->ref != 0) dbswznm->tblwznmmvector->removeRecByRef(vec2->ref);
					};
				};
			};
		};
	};

	// -- ImeIMPreset
	for (unsigned int ix0 = 0; ix0 < imeimpreset.nodes.size(); ix0++) {
		pst = imeimpreset.nodes[ix0];
		if (pst->ref != 0) dbswznm->tblwznmmpreset->removeRecByRef(pst->ref);

		for (unsigned int ix1 = 0; ix1 < pst->imeijmpresettitle.nodes.size(); ix1++) {
			pstJtit = pst->imeijmpresettitle.nodes[ix1];
			if (pstJtit->ref != 0) dbswznm->tblwznmjmpresettitle->removeRecByRef(pstJtit->ref);
		};
	};

	// -- ImeIMQuery
	for (unsigned int ix0 = 0; ix0 < imeimquery.nodes.size(); ix0++) {
		qry = imeimquery.nodes[ix0];
		if (qry->ref != 0) dbswznm->tblwznmmquery->removeRecByRef(qry->ref);

		for (unsigned int ix1 = 0; ix1 < qry->imeiamqueryclause.nodes.size(); ix1++) {
			qryAcse = qry->imeiamqueryclause.nodes[ix1];
			if (qryAcse->ref != 0) dbswznm->tblwznmamqueryclause->removeRecByRef(qryAcse->ref);
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeiamqueryorder.nodes.size(); ix1++) {
			qryAord = qry->imeiamqueryorder.nodes[ix1];
			if (qryAord->ref != 0) dbswznm->tblwznmamqueryorder->removeRecByRef(qryAord->ref);
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeimquerycol.nodes.size(); ix1++) {
			qco = qry->imeimquerycol.nodes[ix1];
			if (qco->ref != 0) dbswznm->tblwznmmquerycol->removeRecByRef(qco->ref);

			for (unsigned int ix2 = 0; ix2 < qco->imeijmquerycolstub.nodes.size(); ix2++) {
				qcoJstb = qco->imeijmquerycolstub.nodes[ix2];
				if (qcoJstb->ref != 0) dbswznm->tblwznmjmquerycolstub->removeRecByRef(qcoJstb->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeimquerymod.nodes.size(); ix1++) {
			qmd = qry->imeimquerymod.nodes[ix1];
			if (qmd->ref != 0) dbswznm->tblwznmmquerymod->removeRecByRef(qmd->ref);
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeirmquerymtable.nodes.size(); ix1++) {
			qryRtbl = qry->imeirmquerymtable.nodes[ix1];
			if (qryRtbl->ref != 0) dbswznm->tblwznmrmquerymtable->removeRecByRef(qryRtbl->ref);

			for (unsigned int ix2 = 0; ix2 < qryRtbl->imeitmquerymodmquery.nodes.size(); ix2++) {
				qryTqmd = qryRtbl->imeitmquerymodmquery.nodes[ix2];
				if (qryTqmd->ref != 0) dbswznm->tblwznmtmquerymodmquery->removeRecByRef(qryTqmd->ref);
			};
		};
	};

	// -- ImeIRMPanelMQuery
	for (unsigned int ix0 = 0; ix0 < imeirmpanelmquery.nodes.size(); ix0++) {
		pnlRqry = imeirmpanelmquery.nodes[ix0];
		if (pnlRqry->ref != 0) dbswznm->tblwznmrmpanelmquery->removeRecByRef(pnlRqry->ref);
	};

	return retval;
};

void JobWznmIexUix::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexUix::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIMCard* car = NULL;
	ImeitemIMPreset* pst = NULL;
	ImeitemIMQuery* qry = NULL;
	ImeitemIRMPanelMQuery* pnlRqry = NULL;
	ImeitemIAMQueryClause* qryAcse = NULL;
	ImeitemIAMQueryOrder* qryAord = NULL;
	ImeitemIJMPresetTitle* pstJtit = NULL;
	ImeitemIMControl1* con1 = NULL;
	ImeitemIMDialog* dlg = NULL;
	ImeitemIMPanel* pnl = NULL;
	ImeitemIMQuerycol* qco = NULL;
	ImeitemIMQuerymod* qmd = NULL;
	ImeitemIRMQueryMTable* qryRtbl = NULL;
	ImeitemIAMControlPar1* conApar1 = NULL;
	ImeitemICControl2* conC2 = NULL;
	ImeitemICControl3* conC3 = NULL;
	ImeitemIJMControlTitle1* conJtit1 = NULL;
	ImeitemIJMQuerycolStub* qcoJstb = NULL;
	ImeitemIMControl2* con2 = NULL;
	ImeitemIMControl3* con3 = NULL;
	ImeitemITMQuerymodMQuery* qryTqmd = NULL;
	ImeitemIAMControlPar2* conApar2 = NULL;
	ImeitemIAMControlPar3* conApar3 = NULL;
	ImeitemIJMControl2* conJ2 = NULL;
	ImeitemIJMControl3* conJ3 = NULL;
	ImeitemIJMControlTitle2* conJtit2 = NULL;
	ImeitemIJMControlTitle3* conJtit3 = NULL;
	ImeitemIMFeed2* fed2 = NULL;
	ImeitemIMFeed3* fed3 = NULL;
	ImeitemIMVector2* vec2 = NULL;
	ImeitemIMVector3* vec3 = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIMCard
	for (unsigned int ix0 = 0; ix0 < imeimcard.nodes.size(); ix0++) {
		car = imeimcard.nodes[ix0];

		if (car->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMCONTROL1, ixWznmVIop)) {
			dbswznm->tblwznmmcontrol->loadRefsByHktHku(VecWznmVMControlHkTbl::CAR, car->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) car->imeimcontrol1.nodes.push_back(new ImeitemIMControl1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < car->imeimcontrol1.nodes.size(); ix1++) {
			con1 = car->imeimcontrol1.nodes[ix1];

			if (con1->ref != 0) {
				con1->srefRefUref = StubWznm::getStubDlgStd(dbswznm, con1->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				con1->srefSupRefWznmMControl = StubWznm::getStubConSref(dbswznm, con1->supRefWznmMControl, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMCONTROLPAR1, ixWznmVIop)) {
				dbswznm->tblwznmamcontrolpar->loadRefsByCon(con1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) con1->imeiamcontrolpar1.nodes.push_back(new ImeitemIAMControlPar1(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < con1->imeiamcontrolpar1.nodes.size(); ix2++) {
				conApar1 = con1->imeiamcontrolpar1.nodes[ix2];

				if (conApar1->ref != 0) {
					conApar1->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, conApar1->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMCONTROLTITLE1, ixWznmVIop)) {
				dbswznm->tblwznmjmcontroltitle->loadRefsByCon(con1->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == con1->refJTitle) {refs[i] = refs[0]; refs[0] = con1->refJTitle; break;};
				for (unsigned int i = 0; i < refs.size(); i++) con1->imeijmcontroltitle1.nodes.push_back(new ImeitemIJMControlTitle1(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < con1->imeijmcontroltitle1.nodes.size(); ix2++) {
				conJtit1 = con1->imeijmcontroltitle1.nodes[ix2];

				if (conJtit1->ref != 0) {
					conJtit1->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, conJtit1->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMDIALOG, ixWznmVIop)) {
			dbswznm->tblwznmmdialog->loadRefsByCar(car->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) car->imeimdialog.nodes.push_back(new ImeitemIMDialog(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < car->imeimdialog.nodes.size(); ix1++) {
			dlg = car->imeimdialog.nodes[ix1];

			if (dlg->ref != 0) {
				dlg->srefRefUref = StubWznm::getStubTblStd(dbswznm, dlg->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			for (unsigned int ix2 = 0; ix2 < dlg->imeiccontrol3.nodes.size(); ix2++) {
				conC3 = dlg->imeiccontrol3.nodes[ix2];

				if (conC3->ref != 0) {
					conC3->iref = ix2+1;
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMCONTROL3, ixWznmVIop)) {
				dbswznm->tblwznmmcontrol->loadRefsByHktHku(VecWznmVMControlHkTbl::DLG, dlg->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) dlg->imeimcontrol3.nodes.push_back(new ImeitemIMControl3(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < dlg->imeimcontrol3.nodes.size(); ix2++) {
				con3 = dlg->imeimcontrol3.nodes[ix2];

				if (con3->ref != 0) {
					con3->iref = ix2+1;
					//con3->irefRefWznmCControl: IREF
					//con3->srefRefUref: STUB
					//con3->irefSupRefWznmMControl: IREF
					con3->srefStdRefWznmMStub = StubWznm::getStubStbStd(dbswznm, con3->stdRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					con3->srefShoRefWznmMStub = StubWznm::getStubStbStd(dbswznm, con3->shoRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMCONTROLPAR3, ixWznmVIop)) {
					dbswznm->tblwznmamcontrolpar->loadRefsByCon(con3->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) con3->imeiamcontrolpar3.nodes.push_back(new ImeitemIAMControlPar3(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con3->imeiamcontrolpar3.nodes.size(); ix3++) {
					conApar3 = con3->imeiamcontrolpar3.nodes[ix3];

					if (conApar3->ref != 0) {
						conApar3->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, conApar3->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMCONTROL3, ixWznmVIop)) {
					dbswznm->tblwznmjmcontrol->loadRefsByCon(con3->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) con3->imeijmcontrol3.nodes.push_back(new ImeitemIJMControl3(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con3->imeijmcontrol3.nodes.size(); ix3++) {
					conJ3 = con3->imeijmcontrol3.nodes[ix3];

					if (conJ3->ref != 0) {
						conJ3->srefX1RefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, conJ3->x1RefWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
						conJ3->srefStdRefWznmMStub = StubWznm::getStubStbStd(dbswznm, conJ3->stdRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
						conJ3->srefShoRefWznmMStub = StubWznm::getStubStbStd(dbswznm, conJ3->shoRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMCONTROLTITLE3, ixWznmVIop)) {
					dbswznm->tblwznmjmcontroltitle->loadRefsByCon(con3->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == con3->refJTitle) {refs[i] = refs[0]; refs[0] = con3->refJTitle; break;};
					for (unsigned int i = 0; i < refs.size(); i++) con3->imeijmcontroltitle3.nodes.push_back(new ImeitemIJMControlTitle3(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con3->imeijmcontroltitle3.nodes.size(); ix3++) {
					conJtit3 = con3->imeijmcontroltitle3.nodes[ix3];

					if (conJtit3->ref != 0) {
						conJtit3->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, conJtit3->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMFEED3, ixWznmVIop)) {
					dbswznm->tblwznmmfeed->loadRefsByCon(con3->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) con3->imeimfeed3.nodes.push_back(new ImeitemIMFeed3(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con3->imeimfeed3.nodes.size(); ix3++) {
					fed3 = con3->imeimfeed3.nodes[ix3];

					if (fed3->ref != 0) {
						fed3->srefSrcUref = StubWznm::getStubTblStd(dbswznm, fed3->srcUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};

					for (unsigned int ix4 = 0; ix4 < fed3->imeimvector3.nodes.size(); ix4++) {
						vec3 = fed3->imeimvector3.nodes[ix4];

						if (vec3->ref != 0) {
						};
					};
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMPANEL, ixWznmVIop)) {
			dbswznm->tblwznmmpanel->loadRefsByCar(car->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) car->imeimpanel.nodes.push_back(new ImeitemIMPanel(dbswznm, ixWznmVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < car->imeimpanel.nodes.size(); ix1++) {
			pnl = car->imeimpanel.nodes[ix1];

			if (pnl->ref != 0) {
				//pnl->srefIxWznmVIop: IOP
			};

			for (unsigned int ix2 = 0; ix2 < pnl->imeiccontrol2.nodes.size(); ix2++) {
				conC2 = pnl->imeiccontrol2.nodes[ix2];

				if (conC2->ref != 0) {
					conC2->iref = ix2+1;
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMCONTROL2, ixWznmVIop)) {
				dbswznm->tblwznmmcontrol->loadRefsByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) pnl->imeimcontrol2.nodes.push_back(new ImeitemIMControl2(dbswznm, ixWznmVIop, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < pnl->imeimcontrol2.nodes.size(); ix2++) {
				con2 = pnl->imeimcontrol2.nodes[ix2];

				if (con2->ref != 0) {
					//con2->srefIxWznmVIop: IOP
					con2->iref = ix2+1;
					//con2->irefRefWznmCControl: IREF
					con2->srefRefUref = StubWznm::getStubDlgStd(dbswznm, con2->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					//con2->irefSupRefWznmMControl: IREF
					con2->srefStdRefWznmMStub = StubWznm::getStubStbStd(dbswznm, con2->stdRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					con2->srefShoRefWznmMStub = StubWznm::getStubStbStd(dbswznm, con2->shoRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMCONTROLPAR2, ixWznmVIop)) {
					dbswznm->tblwznmamcontrolpar->loadRefsByCon(con2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) con2->imeiamcontrolpar2.nodes.push_back(new ImeitemIAMControlPar2(dbswznm, ixWznmVIop, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con2->imeiamcontrolpar2.nodes.size(); ix3++) {
					conApar2 = con2->imeiamcontrolpar2.nodes[ix3];

					if (conApar2->ref != 0) {
						//conApar2->srefIxWznmVIop: IOP
						conApar2->srefX2RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, conApar2->x2RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMCONTROL2, ixWznmVIop)) {
					dbswznm->tblwznmjmcontrol->loadRefsByCon(con2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) con2->imeijmcontrol2.nodes.push_back(new ImeitemIJMControl2(dbswznm, ixWznmVIop, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con2->imeijmcontrol2.nodes.size(); ix3++) {
					conJ2 = con2->imeijmcontrol2.nodes[ix3];

					if (conJ2->ref != 0) {
						//conJ2->srefIxWznmVIop: IOP
						conJ2->srefX1RefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, conJ2->x1RefWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
						conJ2->srefStdRefWznmMStub = StubWznm::getStubStbStd(dbswznm, conJ2->stdRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
						conJ2->srefShoRefWznmMStub = StubWznm::getStubStbStd(dbswznm, conJ2->shoRefWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMCONTROLTITLE2, ixWznmVIop)) {
					dbswznm->tblwznmjmcontroltitle->loadRefsByCon(con2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == con2->refJTitle) {refs[i] = refs[0]; refs[0] = con2->refJTitle; break;};
					for (unsigned int i = 0; i < refs.size(); i++) con2->imeijmcontroltitle2.nodes.push_back(new ImeitemIJMControlTitle2(dbswznm, ixWznmVIop, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con2->imeijmcontroltitle2.nodes.size(); ix3++) {
					conJtit2 = con2->imeijmcontroltitle2.nodes[ix3];

					if (conJtit2->ref != 0) {
						//conJtit2->srefIxWznmVIop: IOP
						conJtit2->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, conJtit2->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMFEED2, ixWznmVIop)) {
					dbswznm->tblwznmmfeed->loadRefsByCon(con2->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) con2->imeimfeed2.nodes.push_back(new ImeitemIMFeed2(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < con2->imeimfeed2.nodes.size(); ix3++) {
					fed2 = con2->imeimfeed2.nodes[ix3];

					if (fed2->ref != 0) {
						fed2->srefSrcUref = StubWznm::getStubTblStd(dbswznm, fed2->srcUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					};

					for (unsigned int ix4 = 0; ix4 < fed2->imeimvector2.nodes.size(); ix4++) {
						vec2 = fed2->imeimvector2.nodes[ix4];

						if (vec2->ref != 0) {
						};
					};
				};
			};
		};
	};

	// -- ImeIMPreset
	for (unsigned int ix0 = 0; ix0 < imeimpreset.nodes.size(); ix0++) {
		pst = imeimpreset.nodes[ix0];

		if (pst->ref != 0) {
			//pst->srefIxWznmVIop: IOP
			pst->srefRefUref = StubWznm::getStubTblStd(dbswznm, pst->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMPRESETTITLE, ixWznmVIop)) {
			dbswznm->tblwznmjmpresettitle->loadRefsByPst(pst->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == pst->refJTitle) {refs[i] = refs[0]; refs[0] = pst->refJTitle; break;};
			for (unsigned int i = 0; i < refs.size(); i++) pst->imeijmpresettitle.nodes.push_back(new ImeitemIJMPresetTitle(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < pst->imeijmpresettitle.nodes.size(); ix1++) {
			pstJtit = pst->imeijmpresettitle.nodes[ix1];

			if (pstJtit->ref != 0) {
				pstJtit->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, pstJtit->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMQuery
	for (unsigned int ix0 = 0; ix0 < imeimquery.nodes.size(); ix0++) {
		qry = imeimquery.nodes[ix0];

		if (qry->ref != 0) {
			//qry->srefIxWznmVIop: IOP
			qry->iref = ix0+1;
			//qry->irefSupRefWznmMQuery: IREF
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMQUERYCLAUSE, ixWznmVIop)) {
			dbswznm->tblwznmamqueryclause->loadRefsByQry(qry->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) qry->imeiamqueryclause.nodes.push_back(new ImeitemIAMQueryClause(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeiamqueryclause.nodes.size(); ix1++) {
			qryAcse = qry->imeiamqueryclause.nodes[ix1];

			if (qryAcse->ref != 0) {
				//qryAcse->irefX1RefWznmMQuerymod: IREF
				qryAcse->srefRefWznmMPreset = StubWznm::getStubPstStd(dbswznm, qryAcse->refWznmMPreset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				qryAcse->srefRefWznmMVector = StubWznm::getStubVecStd(dbswznm, qryAcse->refWznmMVector, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				qryAcse->srefRefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, qryAcse->refWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMQUERYORDER, ixWznmVIop)) {
			dbswznm->tblwznmamqueryorder->loadRefsByQry(qry->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) qry->imeiamqueryorder.nodes.push_back(new ImeitemIAMQueryOrder(dbswznm, ixWznmVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeiamqueryorder.nodes.size(); ix1++) {
			qryAord = qry->imeiamqueryorder.nodes[ix1];

			if (qryAord->ref != 0) {
				//qryAord->srefIxWznmVIop: IOP
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMQUERYCOL, ixWznmVIop)) {
			dbswznm->tblwznmmquerycol->loadRefsByQry(qry->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) qry->imeimquerycol.nodes.push_back(new ImeitemIMQuerycol(dbswznm, ixWznmVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeimquerycol.nodes.size(); ix1++) {
			qco = qry->imeimquerycol.nodes[ix1];

			if (qco->ref != 0) {
				//qco->srefIxWznmVIop: IOP
				qco->srefRefWznmMTablecol = StubWznm::getStubTcoStd(dbswznm, qco->refWznmMTablecol, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				qco->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, qco->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMQUERYCOLSTUB, ixWznmVIop)) {
				dbswznm->tblwznmjmquerycolstub->loadRefsByQco(qco->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) qco->imeijmquerycolstub.nodes.push_back(new ImeitemIJMQuerycolStub(dbswznm, ixWznmVIop, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < qco->imeijmquerycolstub.nodes.size(); ix2++) {
				qcoJstb = qco->imeijmquerycolstub.nodes[ix2];

				if (qcoJstb->ref != 0) {
					//qcoJstb->srefIxWznmVIop: IOP
					qcoJstb->srefX1RefWznmMVectoritem = StubWznm::getStubVitSref(dbswznm, qcoJstb->x1RefWznmMVectoritem, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					qcoJstb->srefX2RefWznmMPreset = StubWznm::getStubPstStd(dbswznm, qcoJstb->x2RefWznmMPreset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
					qcoJstb->srefRefWznmMStub = StubWznm::getStubStbStd(dbswznm, qcoJstb->refWznmMStub, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMQUERYMOD, ixWznmVIop)) {
			dbswznm->tblwznmmquerymod->loadRefsByQry(qry->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) qry->imeimquerymod.nodes.push_back(new ImeitemIMQuerymod(dbswznm, ixWznmVIop, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeimquerymod.nodes.size(); ix1++) {
			qmd = qry->imeimquerymod.nodes[ix1];

			if (qmd->ref != 0) {
				//qmd->srefIxWznmVIop: IOP
				qmd->iref = ix1+1;
				qmd->srefRefWznmMPreset = StubWznm::getStubPstStd(dbswznm, qmd->refWznmMPreset, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				qmd->srefRefUref = StubWznm::getStubTcoStd(dbswznm, qmd->refUref, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMQUERYMTABLE, ixWznmVIop)) {
			dbswznm->tblwznmrmquerymtable->loadRefsByQry(qry->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) qry->imeirmquerymtable.nodes.push_back(new ImeitemIRMQueryMTable(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < qry->imeirmquerymtable.nodes.size(); ix1++) {
			qryRtbl = qry->imeirmquerymtable.nodes[ix1];

			if (qryRtbl->ref != 0) {
				qryRtbl->srefRefWznmMTable = StubWznm::getStubTblStd(dbswznm, qryRtbl->refWznmMTable, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEITMQUERYMODMQUERY, ixWznmVIop)) {
				dbswznm->tblwznmtmquerymodmquery->loadRefsByR(qryRtbl->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) qryRtbl->imeitmquerymodmquery.nodes.push_back(new ImeitemITMQuerymodMQuery(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < qryRtbl->imeitmquerymodmquery.nodes.size(); ix2++) {
				qryTqmd = qryRtbl->imeitmquerymodmquery.nodes[ix2];

				if (qryTqmd->ref != 0) {
					qryTqmd->irefRefWznmMQuerymod = ix2+1;
				};
			};
		};
	};

	// -- ImeIRMPanelMQuery
	for (unsigned int ix0 = 0; ix0 < imeirmpanelmquery.nodes.size(); ix0++) {
		pnlRqry = imeirmpanelmquery.nodes[ix0];

		if (pnlRqry->ref != 0) {
			pnlRqry->srefRefWznmMPanel = StubWznm::getStubPnlStd(dbswznm, pnlRqry->refWznmMPanel, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			pnlRqry->srefRefWznmMQuery = StubWznm::getStubQryStd(dbswznm, pnlRqry->refWznmMQuery, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};
	// IP enterSgeCollect.traverse --- END
	// IP enterSgeCollect.ppr --- INSERT

	delete stcch;

	return retval;
};

void JobWznmIexUix::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexUix::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexUix::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexUix::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmUix::exportToFile(fullpath, xmlNotTxt, shorttags, imeimcard, imeimpreset, imeimquery, imeirmpanelmquery);

	return retval;
};

void JobWznmIexUix::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexUix::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexUix::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


