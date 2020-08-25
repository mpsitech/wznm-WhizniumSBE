/**
	* \file JobWznmIexIni.cpp
	* job handler for job JobWznmIexIni (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "JobWznmIexIni.h"

#include "JobWznmIexIni_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace IexWznmIni;

/******************************************************************************
 class JobWznmIexIni
 ******************************************************************************/

JobWznmIexIni::JobWznmIexIni(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::JOBWZNMIEXINI, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.cust2 --- INSERT

	changeStage(dbswznm, VecVSge::IDLE);

	// IP constructor.cust3 --- INSERT

};

JobWznmIexIni::~JobWznmIexIni() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void JobWznmIexIni::reset(
			DbsWznm* dbswznm
		) {
	if (ixVSge != VecVSge::IDLE) changeStage(dbswznm, VecVSge::IDLE);
};

void JobWznmIexIni::parseFromFile(
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

void JobWznmIexIni::import(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::PRSDONE) changeStage(dbswznm, VecVSge::IMPORT);
};

void JobWznmIexIni::reverse(
			DbsWznm* dbswznm
		) {
	if (ixVSge == VecVSge::IMPERR) changeStage(dbswznm, VecVSge::REVERSE);
};

void JobWznmIexIni::collect(
			DbsWznm* dbswznm
			, const map<uint,uint>& _icsWznmVIop
		) {
	if (ixVSge == VecVSge::IDLE) {
		icsWznmVIop = _icsWznmVIop;
		changeStage(dbswznm, VecVSge::COLLECT);
	};
};

void JobWznmIexIni::exportToFile(
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

void JobWznmIexIni::handleRequest(
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

void JobWznmIexIni::changeStage(
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

string JobWznmIexIni::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::REVERSE) || (ixVSge == VecVSge::COLLECT) || (ixVSge == VecVSge::CLTDONE) || (ixVSge == VecVSge::EXPORT) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(impcnt) + " records added)";
			else if (ixVSge == VecVSge::REVERSE) retval = "reversing initialization data import";
			else if (ixVSge == VecVSge::COLLECT) retval = "collecting initialization data for export";
			else if (ixVSge == VecVSge::CLTDONE) retval = "initialization data collected for export";
			else if (ixVSge == VecVSge::EXPORT) retval = "exporting initialization data";
		};

	} else if ( (ixVSge == VecVSge::PRSERR) || (ixVSge == VecVSge::IMPERR) ) {
		retval = lasterror;

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWznmIexIni::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	fullpath = "";
	xmlNotTxt = false;

	lineno = 0;
	impcnt = 0;

	icsWznmVIop.clear();

	imeiavcontrolpar.clear();
	imeiavkeylistkey1.clear();
	imeiavvaluelistval.clear();
	imeimcapability.clear();
	imeimfile.clear();
	imeimlibrary.clear();
	imeimlocale.clear();
	imeimmachtype.clear();
	imeimtag1.clear();
	imeimusergroup.clear();

	return retval;
};

void JobWznmIexIni::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWznmIexIni::enterSgeParse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::PRSERR;

	try {
		IexWznmIni::parseFromFile(fullpath, xmlNotTxt, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcapability, imeimfile, imeimlibrary, imeimlocale, imeimmachtype, imeimtag1, imeimusergroup);

	} catch (SbeException& e) {
		if (e.ix == SbeException::PATHNF) e.vals["path"] = "<hidden>";
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);

		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexIni::leaveSgeParse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeParse --- INSERT
};

uint JobWznmIexIni::enterSgePrserr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSERR;

	// IP enterSgePrserr --- INSERT

	return retval;
};

void JobWznmIexIni::leaveSgePrserr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrserr --- INSERT
};

uint JobWznmIexIni::enterSgePrsdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void JobWznmIexIni::leaveSgePrsdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint JobWznmIexIni::enterSgeImport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::IMPERR;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCapability* cpb = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLibrary* lib = NULL;
	ImeitemIMLocale* loc = NULL;
	ImeitemIMMachtype* mty = NULL;
	ImeitemIMTag1* tag1 = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMCapabilityPar* cpbApar = NULL;
	ImeitemIAMLibraryMakefile* libAmkf = NULL;
	ImeitemIAMLibraryPkglist* libApkl = NULL;
	ImeitemIAMMachtypeMakefile* mtyAmkf = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey1* klkJkey1 = NULL;
	ImeitemIJMLocaleTitle* locJtit = NULL;
	ImeitemIJMTagTitle1* tagJtit1 = NULL;
	ImeitemIMMachine* mch = NULL;
	ImeitemIMTag2* tag2 = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIRMCapabilityUniversal* cpbRunv = NULL;
	ImeitemIAMMachinePar* mchApar = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJAVKeylistKey2* klkJkey2 = NULL;
	ImeitemIJMTagTitle2* tagJtit2 = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint num0, num1;

	// IP enterSgeImport.prep --- IBEGIN
	WznmRMUserMUsergroup uru;

	vector<string> ss;
	// IP enterSgeImport.prep --- IEND

	try {
		// IP enterSgeImport.traverse --- RBEGIN

		// -- ImeIAVControlPar
		for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
			ctlApar = imeiavcontrolpar.nodes[ix0];

			ctlApar->ixWznmVControl = VecWznmVControl::getIx(ctlApar->srefIxWznmVControl);
			if (ctlApar->ixWznmVControl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",ctlApar->srefIxWznmVControl}, {"iel","srefIxWznmVControl"}, {"lineno",to_string(ctlApar->lineno)}});
			//ctlApar->Par: TBL
			//ctlApar->Val: TBL

			dbswznm->tblwznmavcontrolpar->insertRec(ctlApar);
			impcnt++;
		};

		// -- ImeIAVKeylistKey1
		for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey1.nodes.size(); ix0++) {
			klsAkey1 = imeiavkeylistkey1.nodes[ix0];

			klsAkey1->klsIxWznmVKeylist = VecWznmVKeylist::getIx(klsAkey1->srefKlsIxWznmVKeylist);
			if (klsAkey1->klsIxWznmVKeylist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klsAkey1->srefKlsIxWznmVKeylist}, {"iel","srefKlsIxWznmVKeylist"}, {"lineno",to_string(klsAkey1->lineno)}});
			klsAkey1->klsNum = (ix0+1); // TBD
			klsAkey1->x1IxWznmVMaintable = VecWznmVMaintable::VOID;
			klsAkey1->Fixed = true;
			//klsAkey1->sref: TBL
			//klsAkey1->Avail: TBL
			//klsAkey1->Implied: TBL
			//klsAkey1->refJ: SUB
			//klsAkey1->Title: TBL
			//klsAkey1->Comment: TBL

			dbswznm->tblwznmavkeylistkey->insertRec(klsAkey1);
			impcnt++;

			if (((klsAkey1->Title != "") || (klsAkey1->Comment != "")) && klsAkey1->imeijavkeylistkey1.nodes.empty()) {
				klkJkey1 = new ImeitemIJAVKeylistKey1();
				klkJkey1->lineno = klsAkey1->lineno;
				klsAkey1->imeijavkeylistkey1.nodes.push_back(klkJkey1);

				klkJkey1->refWznmAVKeylistKey = klsAkey1->ref;
				klkJkey1->Title = klsAkey1->Title;
				klkJkey1->Comment = klsAkey1->Comment;
			};

			for (unsigned int ix1 = 0; ix1 < klsAkey1->imeijavkeylistkey1.nodes.size(); ix1++) {
				klkJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

				klkJkey1->refWznmAVKeylistKey = klsAkey1->ref;
				if (klkJkey1->srefX1IxWznmVLocale == "") klkJkey1->srefX1IxWznmVLocale = "enus";
				klkJkey1->x1IxWznmVLocale = VecWznmVLocale::getIx(klkJkey1->srefX1IxWznmVLocale);
				if (klkJkey1->x1IxWznmVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klkJkey1->srefX1IxWznmVLocale}, {"iel","srefX1IxWznmVLocale"}, {"lineno",to_string(klkJkey1->lineno)}});
				//klkJkey1->Title: TBL
				//klkJkey1->Comment: TBL

				dbswznm->tblwznmjavkeylistkey->insertRec(klkJkey1);
				impcnt++;

				if (ix1 == 0) {
					klsAkey1->refJ = klkJkey1->ref;
					klsAkey1->Title = klkJkey1->Title;
					klsAkey1->Comment = klkJkey1->Comment;
					dbswznm->tblwznmavkeylistkey->updateRec(klsAkey1);
				};
			};
		};

		// -- ImeIAVValuelistVal
		for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
			vlsAval = imeiavvaluelistval.nodes[ix0];

			vlsAval->vlsIxWznmVValuelist = VecWznmVValuelist::getIx(vlsAval->srefVlsIxWznmVValuelist);
			if (vlsAval->vlsIxWznmVValuelist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefVlsIxWznmVValuelist}, {"iel","srefVlsIxWznmVValuelist"}, {"lineno",to_string(vlsAval->lineno)}});
			vlsAval->vlsNum = (ix0+1); // TBD
			vlsAval->x1IxWznmVLocale = VecWznmVLocale::getIx(vlsAval->srefX1IxWznmVLocale);
			if (vlsAval->x1IxWznmVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",vlsAval->srefX1IxWznmVLocale}, {"iel","srefX1IxWznmVLocale"}, {"lineno",to_string(vlsAval->lineno)}});
			//vlsAval->Val: TBL

			dbswznm->tblwznmavvaluelistval->insertRec(vlsAval);
			impcnt++;
		};

		// -- ImeIMFile
		for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
			fil = imeimfile.nodes[ix0];

			fil->refIxVTbl = VecWznmVMFileRefTbl::VOID;
			//fil->osrefKContent: TBL
			//fil->Filename: TBL
			//fil->srefKMimetype: TBL
			//fil->Comment: TBL

			dbswznm->tblwznmmfile->insertRec(fil);
			impcnt++;
		};

		// -- ImeIMMachtype
		for (unsigned int ix0 = 0; ix0 < imeimmachtype.nodes.size(); ix0++) {
			mty = imeimmachtype.nodes[ix0];

			//mty->sref: TBL
			mty->ixVArch = VecWznmVMMachtypeArch::getIx(mty->srefIxVArch);
			if (mty->ixVArch == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",mty->srefIxVArch}, {"iel","srefIxVArch"}, {"lineno",to_string(mty->lineno)}});
			//mty->srefKOs: TBL
			//mty->cchRefWznmMMachine: IMPPP
			//mty->srefKPkgmgr: TBL
			//mty->Comment: TBL

			dbswznm->tblwznmmmachtype->insertRec(mty);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < mty->imeiammachtypemakefile.nodes.size(); ix1++) {
				mtyAmkf = mty->imeiammachtypemakefile.nodes[ix1];

				mtyAmkf->refWznmMMachtype = mty->ref;
				//mtyAmkf->x1SrefKTag: TBL
				//mtyAmkf->Val: TBL

				dbswznm->tblwznmammachtypemakefile->insertRec(mtyAmkf);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < mty->imeimmachine.nodes.size(); ix1++) {
				mch = mty->imeimmachine.nodes[ix1];

				mch->refWznmMMachtype = mty->ref;
				//mch->sref: TBL
				mch->ixWznmWCloudtype = VecWznmWCloudtype::getIx(mch->srefIxWznmWCloudtype);
				//mch->Comment: TBL

				dbswznm->tblwznmmmachine->insertRec(mch);
				impcnt++;

				for (unsigned int ix2 = 0; ix2 < mch->imeiammachinepar.nodes.size(); ix2++) {
					mchApar = mch->imeiammachinepar.nodes[ix2];

					mchApar->refWznmMMachine = mch->ref;
					//mchApar->x1SrefKKey: TBL
					//mchApar->Val: TBL

					dbswznm->tblwznmammachinepar->insertRec(mchApar);
					impcnt++;
				};
			};
		};

		// -- ImeIMLibrary
		for (unsigned int ix0 = 0; ix0 < imeimlibrary.nodes.size(); ix0++) {
			lib = imeimlibrary.nodes[ix0];

			//lib->sref: TBL
			//lib->Title: TBL
			//lib->Version: TBL
			//lib->srefKLictype: TBL
			//lib->depSrefsWznmMLibrary: TBL
			//lib->Comment: TBL

			dbswznm->tblwznmmlibrary->insertRec(lib);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarymakefile.nodes.size(); ix1++) {
				libAmkf = lib->imeiamlibrarymakefile.nodes[ix1];

				libAmkf->refWznmMLibrary = lib->ref;
				libAmkf->x1RefIxVTbl = VecWznmVAMLibraryMakefileRefTbl::getIx(libAmkf->srefX1RefIxVTbl);
				if (libAmkf->x1RefIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",libAmkf->srefX1RefIxVTbl}, {"iel","srefX1RefIxVTbl"}, {"lineno",to_string(libAmkf->lineno)}});
				if (libAmkf->srefX1RefUref != "") {
					//libAmkf->x1RefUref: PREVIMP
					if (libAmkf->x1RefIxVTbl == VecWznmVAMLibraryMakefileRefTbl::MCH) {
						for (unsigned int i = 0; i < imeimmachtype.nodes.size(); i++) {
							mty = imeimmachtype.nodes[i];

							for (unsigned int j = 0; j < mty->imeimmachine.nodes.size(); j++) {
								mch = mty->imeimmachine.nodes[j];

								if (mch->sref == libAmkf->srefX1RefUref) {
									libAmkf->x1RefUref = mch->ref;
									break;
								};
							};
							
							if (libAmkf->x1RefUref != 0) break;
						};
					} else if (libAmkf->x1RefIxVTbl == VecWznmVAMLibraryMakefileRefTbl::MTY) {
						for (unsigned int i = 0; i < imeimmachtype.nodes.size(); i++) {
							mty = imeimmachtype.nodes[i];
							
							if (mty->sref == libAmkf->srefX1RefUref) {
								libAmkf->x1RefUref = mty->ref;
								break;
							};
						};
					};
					if (libAmkf->x1RefUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",libAmkf->srefX1RefUref}, {"iel","srefX1RefUref"}, {"lineno",to_string(libAmkf->lineno)}});
				};
				//libAmkf->x2SrefKTag: TBL
				//libAmkf->Val: TBL

				dbswznm->tblwznmamlibrarymakefile->insertRec(libAmkf);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarypkglist.nodes.size(); ix1++) {
				libApkl = lib->imeiamlibrarypkglist.nodes[ix1];

				libApkl->refWznmMLibrary = lib->ref;
				libApkl->x1RefIxVTbl = VecWznmVAMLibraryPkglistRefTbl::getIx(libApkl->srefX1RefIxVTbl);
				if (libApkl->x1RefIxVTbl == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",libApkl->srefX1RefIxVTbl}, {"iel","srefX1RefIxVTbl"}, {"lineno",to_string(libApkl->lineno)}});
				if (libApkl->srefX1RefUref != "") {
					//libApkl->x1RefUref: PREVIMP
					if (libApkl->x1RefIxVTbl == VecWznmVAMLibraryPkglistRefTbl::MCH) {
						for (unsigned int i = 0; i < imeimmachtype.nodes.size(); i++) {
							mty = imeimmachtype.nodes[i];

							for (unsigned int j = 0; j < mty->imeimmachine.nodes.size(); j++) {
								mch = mty->imeimmachine.nodes[j];

								if (mch->sref == libApkl->srefX1RefUref) {
									libApkl->x1RefUref = mch->ref;
									break;
								};
							};
							
							if (libApkl->x1RefUref != 0) break;
						};
					} else if (libApkl->x1RefIxVTbl == VecWznmVAMLibraryPkglistRefTbl::MTY) {
						for (unsigned int i = 0; i < imeimmachtype.nodes.size(); i++) {
							mty = imeimmachtype.nodes[i];
							
							if (mty->sref == libApkl->srefX1RefUref) {
								libApkl->x1RefUref = mty->ref;
								break;
							};
						};
					};
					if (libApkl->x1RefUref == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",libApkl->srefX1RefUref}, {"iel","srefX1RefUref"}, {"lineno",to_string(libApkl->lineno)}});
				};
				//libApkl->Pkglist: TBL

				dbswznm->tblwznmamlibrarypkglist->insertRec(libApkl);
				impcnt++;
			};
		};

		// -- ImeIMLocale
		for (unsigned int ix0 = 0; ix0 < imeimlocale.nodes.size(); ix0++) {
			loc = imeimlocale.nodes[ix0];

			//loc->sref: TBL
			//loc->refJTitle: SUB
			//loc->Title: TBL

			dbswznm->tblwznmmlocale->insertRec(loc);
			impcnt++;

			if (((loc->Title != "")) && loc->imeijmlocaletitle.nodes.empty()) {
				locJtit = new ImeitemIJMLocaleTitle();
				loc->imeijmlocaletitle.nodes.push_back(locJtit);

				locJtit->refWznmMLocale = loc->ref;
				locJtit->Title = loc->Title;
			};

			for (unsigned int ix1 = 0; ix1 < loc->imeijmlocaletitle.nodes.size(); ix1++) {
				locJtit = loc->imeijmlocaletitle.nodes[ix1];

				locJtit->refWznmMLocale = loc->ref;
				if (locJtit->srefX1RefWznmMLocale == "") locJtit->srefX1RefWznmMLocale = "enus";
				//locJtit->x1RefWznmMLocale: IMPPP
				//locJtit->Title: TBL

				dbswznm->tblwznmjmlocaletitle->insertRec(locJtit);
				impcnt++;

				if (ix1 == 0) {
					loc->refJTitle = locJtit->ref;
					loc->Title = locJtit->Title;
					dbswznm->tblwznmmlocale->updateRec(loc);
				};
			};
		};

		// -- ImeIMTag
		for (unsigned int ix0 = 0; ix0 < imeimtag1.nodes.size(); ix0++) {
			tag1 = imeimtag1.nodes[ix0];

			//tag1->sref: TBL
			//tag1->osrefWznmKTaggrp: TBL
			//tag1->refJTitle: SUB
			//tag1->Title: TBL

			dbswznm->tblwznmmtag->insertRec(tag1);
			impcnt++;

			if (((tag1->Title != "")) && tag1->imeijmtagtitle1.nodes.empty()) {
				tagJtit1 = new ImeitemIJMTagTitle1();
				tag1->imeijmtagtitle1.nodes.push_back(tagJtit1);

				tagJtit1->refWznmMTag = tag1->ref;
				tagJtit1->Title = tag1->Title;
			};

			for (unsigned int ix1 = 0; ix1 < tag1->imeijmtagtitle1.nodes.size(); ix1++) {
				tagJtit1 = tag1->imeijmtagtitle1.nodes[ix1];

				tagJtit1->refWznmMTag = tag1->ref;
				if (tagJtit1->srefX1RefWznmMLocale == "") tagJtit1->srefX1RefWznmMLocale = "enus";
				//tagJtit1->x1RefWznmMLocale: PREVIMP
				for (unsigned int i = 0; i < imeimlocale.nodes.size(); i++)
					if (imeimlocale.nodes[i]->sref == tagJtit1->srefX1RefWznmMLocale) {
						tagJtit1->x1RefWznmMLocale = imeimlocale.nodes[i]->ref;
						break;
					};
				if (tagJtit1->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",tagJtit1->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(tagJtit1->lineno)}});
				//tagJtit1->Title: TBL

				dbswznm->tblwznmjmtagtitle->insertRec(tagJtit1);
				impcnt++;

				if (ix1 == 0) {
					tag1->refJTitle = tagJtit1->ref;
					tag1->Title = tagJtit1->Title;
					dbswznm->tblwznmmtag->updateRec(tag1);
				};
			};
		};

		// -- ImeIMUsergroup
		for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
			usg = imeimusergroup.nodes[ix0];

			//usg->sref: TBL
			//usg->Comment: TBL

			dbswznm->tblwznmmusergroup->insertRec(usg);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
				usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

				usgAacc->refWznmMUsergroup = usg->ref;
				usgAacc->x1IxWznmVFeatgroup = VecWznmVFeatgroup::getIx(usgAacc->srefX1IxWznmVFeatgroup);
				if (usgAacc->x1IxWznmVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usgAacc->srefX1IxWznmVFeatgroup}, {"iel","srefX1IxWznmVFeatgroup"}, {"lineno",to_string(usgAacc->lineno)}});
				//usgAacc->x2FeaSrefUix: TBL
				usgAacc->ixWznmWAccess = VecWznmWAccess::getIx(usgAacc->srefsIxWznmWAccess);

				dbswznm->tblwznmamusergroupaccess->insertRec(usgAacc);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
				usr = usg->imeimuser.nodes[ix1];

				//usr->refRUsergroup: IMPPP
				//usr->refWznmMPerson: IMPPP
				//usr->sref: TBL
				//usr->refJState: SUB
				if (usr->srefIxVState != "") {
					usr->ixVState = VecWznmVMUserState::getIx(usr->srefIxVState);
					if (usr->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usr->lineno)}});
				};
				usr->ixWznmVLocale = VecWznmVLocale::getIx(usr->srefIxWznmVLocale);
				if (usr->ixWznmVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWznmVLocale}, {"iel","srefIxWznmVLocale"}, {"lineno",to_string(usr->lineno)}});
				usr->ixWznmVUserlevel = VecWznmVUserlevel::getIx(usr->srefIxWznmVUserlevel);
				if (usr->ixWznmVUserlevel == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usr->srefIxWznmVUserlevel}, {"iel","srefIxWznmVUserlevel"}, {"lineno",to_string(usr->lineno)}});
				//usr->Password: TBL
				//usr->Fullkey: TBL
				//usr->Comment: TBL

				dbswznm->tblwznmmuser->insertRec(usr);
				impcnt++;

				if (((usr->srefIxVState != "")) && usr->imeijmuserstate.nodes.empty()) {
					usrJste = new ImeitemIJMUserState();
					usr->imeijmuserstate.nodes.push_back(usrJste);

					usrJste->refWznmMUser = usr->ref;
					usrJste->srefIxVState = usr->srefIxVState;
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
					usrJste = usr->imeijmuserstate.nodes[ix2];

					usrJste->refWznmMUser = usr->ref;
					usrJste->x1Start = Ftm::invstamp("&now;");
					usrJste->ixVState = VecWznmVMUserState::getIx(usrJste->srefIxVState);
					if (usrJste->ixVState == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrJste->srefIxVState}, {"iel","srefIxVState"}, {"lineno",to_string(usrJste->lineno)}});

					dbswznm->tblwznmjmuserstate->insertRec(usrJste);
					impcnt++;

					if (ix2 == 0) {
						usr->refJState = usrJste->ref;
						usr->ixVState = usrJste->ixVState;
						dbswznm->tblwznmmuser->updateRec(usr);
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
					prs = usr->imeimperson.nodes[ix2];

					prs->ixWDerivate = VecWznmWMPersonDerivate::USR;
					prs->ixVSex = VecWznmVMPersonSex::getIx(prs->srefIxVSex);
					if (prs->ixVSex == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",prs->srefIxVSex}, {"iel","srefIxVSex"}, {"lineno",to_string(prs->lineno)}});
					//prs->Title: TBL
					//prs->Firstname: TBL
					//prs->refJLastname: SUB
					//prs->Lastname: TBL

					dbswznm->tblwznmmperson->insertRec(prs);
					impcnt++;

					if (((prs->Lastname != "")) && prs->imeijmpersonlastname.nodes.empty()) {
						prsJlnm = new ImeitemIJMPersonLastname();
						prs->imeijmpersonlastname.nodes.push_back(prsJlnm);

						prsJlnm->refWznmMPerson = prs->ref;
						prsJlnm->Lastname = prs->Lastname;
					};

					if (ix2 == 0) {
						usr->refWznmMPerson = prs->ref;
						dbswznm->tblwznmmuser->updateRec(usr);
					};

					for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
						prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

						prsJlnm->refWznmMPerson = prs->ref;
						prsJlnm->x1Startd = Ftm::invdate("&today;");
						//prsJlnm->Lastname: TBL

						dbswznm->tblwznmjmpersonlastname->insertRec(prsJlnm);
						impcnt++;

						if (ix3 == 0) {
							prs->refJLastname = prsJlnm->ref;
							prs->Lastname = prsJlnm->Lastname;
							dbswznm->tblwznmmperson->updateRec(prs);
						};
					};
				};

				for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
					usrAacc = usr->imeiamuseraccess.nodes[ix2];

					usrAacc->refWznmMUser = usr->ref;
					usrAacc->x1IxWznmVFeatgroup = VecWznmVFeatgroup::getIx(usrAacc->srefX1IxWznmVFeatgroup);
					if (usrAacc->x1IxWznmVFeatgroup == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",usrAacc->srefX1IxWznmVFeatgroup}, {"iel","srefX1IxWznmVFeatgroup"}, {"lineno",to_string(usrAacc->lineno)}});
					//usrAacc->x2FeaSrefUix: TBL
					usrAacc->ixWznmWAccess = VecWznmWAccess::getIx(usrAacc->srefsIxWznmWAccess);

					dbswznm->tblwznmamuseraccess->insertRec(usrAacc);
					impcnt++;
				};

				uru.refWznmMUser = usr->ref;
				uru.refWznmMUsergroup = usg->ref;
				uru.ixWznmVUserlevel = usr->ixWznmVUserlevel;
				dbswznm->tblwznmrmusermusergroup->insertRec(&uru);

				usr->refRUsergroup = uru.ref;
				usr->refWznmMUsergroup = usg->ref;
				dbswznm->tblwznmmuser->updateRec(usr);
			};
		};

		// -- ImeIMCapability
		for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
			cpb = imeimcapability.nodes[ix0];

			//cpb->sref: TBL
			cpb->ixWArtefact = VecWznmWMCapabilityArtefact::getIx(cpb->srefsIxWArtefact);
			//cpb->Comment: TBL

			dbswznm->tblwznmmcapability->insertRec(cpb);
			impcnt++;

			for (unsigned int ix1 = 0; ix1 < cpb->imeiavkeylistkey2.nodes.size(); ix1++) {
				klsAkey2 = cpb->imeiavkeylistkey2.nodes[ix1];

				klsAkey2->klsIxWznmVKeylist = VecWznmVKeylist::getIx(klsAkey2->srefKlsIxWznmVKeylist);
				if (klsAkey2->klsIxWznmVKeylist == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klsAkey2->srefKlsIxWznmVKeylist}, {"iel","srefKlsIxWznmVKeylist"}, {"lineno",to_string(klsAkey2->lineno)}});
				klsAkey2->klsNum = (ix1+1); // TBD
				klsAkey2->x1IxWznmVMaintable = VecWznmVMaintable::TBLWZNMMCAPABILITY;
				klsAkey2->x1Uref = cpb->ref;
				klsAkey2->Fixed = true;
				//klsAkey2->sref: TBL
				//klsAkey2->refJ: SUB
				//klsAkey2->Title: TBL
				//klsAkey2->Comment: TBL

				dbswznm->tblwznmavkeylistkey->insertRec(klsAkey2);
				impcnt++;

				if (((klsAkey2->Title != "") || (klsAkey2->Comment != "")) && klsAkey2->imeijavkeylistkey2.nodes.empty()) {
					klkJkey2 = new ImeitemIJAVKeylistKey2();
					klkJkey2->lineno = klsAkey2->lineno;
					klsAkey2->imeijavkeylistkey2.nodes.push_back(klkJkey2);

					klkJkey2->refWznmAVKeylistKey = klsAkey2->ref;
					klkJkey2->Title = klsAkey2->Title;
					klkJkey2->Comment = klsAkey2->Comment;
				};

				for (unsigned int ix2 = 0; ix2 < klsAkey2->imeijavkeylistkey2.nodes.size(); ix2++) {
					klkJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix2];

					klkJkey2->refWznmAVKeylistKey = klsAkey2->ref;
					if (klkJkey2->srefX1IxWznmVLocale == "") klkJkey2->srefX1IxWznmVLocale = "enus";
					klkJkey2->x1IxWznmVLocale = VecWznmVLocale::getIx(klkJkey2->srefX1IxWznmVLocale);
					if (klkJkey2->x1IxWznmVLocale == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",klkJkey2->srefX1IxWznmVLocale}, {"iel","srefX1IxWznmVLocale"}, {"lineno",to_string(klkJkey2->lineno)}});
					//klkJkey2->Title: TBL
					//klkJkey2->Comment: TBL

					dbswznm->tblwznmjavkeylistkey->insertRec(klkJkey2);
					impcnt++;

					if (ix2 == 0) {
						klsAkey2->refJ = klkJkey2->ref;
						klsAkey2->Title = klkJkey2->Title;
						klsAkey2->Comment = klkJkey2->Comment;
						dbswznm->tblwznmavkeylistkey->updateRec(klsAkey2);
					};
				};
			};

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

			for (unsigned int ix1 = 0; ix1 < cpb->imeirmcapabilityuniversal.nodes.size(); ix1++) {
				cpbRunv = cpb->imeirmcapabilityuniversal.nodes[ix1];

				cpbRunv->refWznmMCapability = cpb->ref;
				cpbRunv->unvIxWznmVMaintable = VecWznmVMaintable::getIx(cpbRunv->srefUnvIxWznmVMaintable);
				if (cpbRunv->unvIxWznmVMaintable == 0) throw SbeException(SbeException::IEX_VSREF, {{"vsref",cpbRunv->srefUnvIxWznmVMaintable}, {"iel","srefUnvIxWznmVMaintable"}, {"lineno",to_string(cpbRunv->lineno)}});
				//cpbRunv->srefKKey: TBL

				dbswznm->tblwznmrmcapabilityuniversal->insertRec(cpbRunv);
				impcnt++;
			};

			for (unsigned int ix1 = 0; ix1 < cpb->imeimtag2.nodes.size(); ix1++) {
				tag2 = cpb->imeimtag2.nodes[ix1];

				tag2->refWznmMCapability = cpb->ref;
				//tag2->sref: TBL
				//tag2->refJTitle: SUB
				//tag2->Title: TBL

				dbswznm->tblwznmmtag->insertRec(tag2);
				impcnt++;

				if (((tag2->Title != "")) && tag2->imeijmtagtitle2.nodes.empty()) {
					tagJtit2 = new ImeitemIJMTagTitle2();
					tagJtit2->lineno = tag2->lineno;
					tag2->imeijmtagtitle2.nodes.push_back(tagJtit2);

					tagJtit2->refWznmMTag = tag2->ref;
					tagJtit2->Title = tag2->Title;
				};

				for (unsigned int ix2 = 0; ix2 < tag2->imeijmtagtitle2.nodes.size(); ix2++) {
					tagJtit2 = tag2->imeijmtagtitle2.nodes[ix2];

					tagJtit2->refWznmMTag = tag2->ref;
					if (tagJtit2->srefX1RefWznmMLocale == "") tagJtit2->srefX1RefWznmMLocale = "enus";
					for (unsigned int i = 0; i < imeimlocale.nodes.size(); i++)
						if (imeimlocale.nodes[i]->sref == tagJtit2->srefX1RefWznmMLocale) {
							tagJtit2->x1RefWznmMLocale = imeimlocale.nodes[i]->ref;
							break;
						};
					if (tagJtit2->x1RefWznmMLocale == 0) throw SbeException(SbeException::IEX_TSREF, {{"tsref",tagJtit2->srefX1RefWznmMLocale}, {"iel","srefX1RefWznmMLocale"}, {"lineno",to_string(tagJtit2->lineno)}});
					//tagJtit2->Title: TBL

					dbswznm->tblwznmjmtagtitle->insertRec(tagJtit2);
					impcnt++;

					if (ix2 == 0) {
						tag2->refJTitle = tagJtit2->ref;
						tag2->Title = tagJtit2->Title;
						dbswznm->tblwznmmtag->updateRec(tag2);
					};
				};
			};
		};
		// IP enterSgeImport.traverse --- REND

		// IP enterSgeImport.ppr --- IBEGIN
		// -- ImeIMLocale
		for (unsigned int ix0 = 0; ix0 < imeimlocale.nodes.size(); ix0++) {
			loc = imeimlocale.nodes[ix0];

			for (unsigned int ix1 = 0; ix1 < loc->imeijmlocaletitle.nodes.size(); ix1++) {
				locJtit = loc->imeijmlocaletitle.nodes[ix1];

				for (unsigned int ix=0;ix<imeimlocale.nodes.size();ix++) {
					if (imeimlocale.nodes[ix]->sref.compare(locJtit->srefX1RefWznmMLocale) == 0) {
						locJtit->x1RefWznmMLocale = imeimlocale.nodes[ix]->ref;
						dbswznm->tblwznmjmlocaletitle->updateRec(locJtit);
						break;
					};
				};
			};
		};

		// -- ImeIMMachtype
		for (unsigned int ix0 = 0; ix0 < imeimmachtype.nodes.size(); ix0++) {
			mty = imeimmachtype.nodes[ix0];
			if (mty->srefCchRefWznmMMachine != "") if (dbswznm->tblwznmmmachine->loadRefBySrf(mty->srefCchRefWznmMMachine, mty->cchRefWznmMMachine)) dbswznm->tblwznmmmachtype->updateRec(mty);
		};
		// IP enterSgeImport.ppr --- IEND
	} catch (SbeException& e) {
		lasterror = e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, ixWznmVLocale);
		retval = nextIxVSgeFailure;
	};

	return retval;
};

void JobWznmIexIni::leaveSgeImport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImport --- INSERT
};

uint JobWznmIexIni::enterSgeImperr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IMPERR;

	// IP enterSgeImperr --- INSERT

	return retval;
};

void JobWznmIexIni::leaveSgeImperr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeImperr --- INSERT
};

uint JobWznmIexIni::enterSgeReverse(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCapability* cpb = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLibrary* lib = NULL;
	ImeitemIMLocale* loc = NULL;
	ImeitemIMMachtype* mty = NULL;
	ImeitemIMTag1* tag1 = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMCapabilityPar* cpbApar = NULL;
	ImeitemIAMLibraryMakefile* libAmkf = NULL;
	ImeitemIAMLibraryPkglist* libApkl = NULL;
	ImeitemIAMMachtypeMakefile* mtyAmkf = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey1* klkJkey1 = NULL;
	ImeitemIJMLocaleTitle* locJtit = NULL;
	ImeitemIJMTagTitle1* tagJtit1 = NULL;
	ImeitemIMMachine* mch = NULL;
	ImeitemIMTag2* tag2 = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIRMCapabilityUniversal* cpbRunv = NULL;
	ImeitemIAMMachinePar* mchApar = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJAVKeylistKey2* klkJkey2 = NULL;
	ImeitemIJMTagTitle2* tagJtit2 = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];
		if (ctlApar->ref != 0) dbswznm->tblwznmavcontrolpar->removeRecByRef(ctlApar->ref);
	};

	// -- ImeIAVKeylistKey1
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey1.nodes.size(); ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];
		if (klsAkey1->ref != 0) dbswznm->tblwznmavkeylistkey->removeRecByRef(klsAkey1->ref);

		for (unsigned int ix1 = 0; ix1 < klsAkey1->imeijavkeylistkey1.nodes.size(); ix1++) {
			klkJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];
			if (klkJkey1->ref != 0) dbswznm->tblwznmjavkeylistkey->removeRecByRef(klkJkey1->ref);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];
		if (vlsAval->ref != 0) dbswznm->tblwznmavvaluelistval->removeRecByRef(vlsAval->ref);
	};

	// -- ImeIMCapability
	for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
		cpb = imeimcapability.nodes[ix0];
		if (cpb->ref != 0) dbswznm->tblwznmmcapability->removeRecByRef(cpb->ref);

		for (unsigned int ix1 = 0; ix1 < cpb->imeiamcapabilitypar.nodes.size(); ix1++) {
			cpbApar = cpb->imeiamcapabilitypar.nodes[ix1];
			if (cpbApar->ref != 0) dbswznm->tblwznmamcapabilitypar->removeRecByRef(cpbApar->ref);
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeiavkeylistkey2.nodes.size(); ix1++) {
			klsAkey2 = cpb->imeiavkeylistkey2.nodes[ix1];
			if (klsAkey2->ref != 0) dbswznm->tblwznmavkeylistkey->removeRecByRef(klsAkey2->ref);

			for (unsigned int ix2 = 0; ix2 < klsAkey2->imeijavkeylistkey2.nodes.size(); ix2++) {
				klkJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix2];
				if (klkJkey2->ref != 0) dbswznm->tblwznmjavkeylistkey->removeRecByRef(klkJkey2->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeimtag2.nodes.size(); ix1++) {
			tag2 = cpb->imeimtag2.nodes[ix1];
			if (tag2->ref != 0) dbswznm->tblwznmmtag->removeRecByRef(tag2->ref);

			for (unsigned int ix2 = 0; ix2 < tag2->imeijmtagtitle2.nodes.size(); ix2++) {
				tagJtit2 = tag2->imeijmtagtitle2.nodes[ix2];
				if (tagJtit2->ref != 0) dbswznm->tblwznmjmtagtitle->removeRecByRef(tagJtit2->ref);
			};
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeirmcapabilityuniversal.nodes.size(); ix1++) {
			cpbRunv = cpb->imeirmcapabilityuniversal.nodes[ix1];
			if (cpbRunv->ref != 0) dbswznm->tblwznmrmcapabilityuniversal->removeRecByRef(cpbRunv->ref);
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
		fil = imeimfile.nodes[ix0];
		if (fil->ref != 0) dbswznm->tblwznmmfile->removeRecByRef(fil->ref);
	};

	// -- ImeIMLibrary
	for (unsigned int ix0 = 0; ix0 < imeimlibrary.nodes.size(); ix0++) {
		lib = imeimlibrary.nodes[ix0];
		if (lib->ref != 0) dbswznm->tblwznmmlibrary->removeRecByRef(lib->ref);

		for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarymakefile.nodes.size(); ix1++) {
			libAmkf = lib->imeiamlibrarymakefile.nodes[ix1];
			if (libAmkf->ref != 0) dbswznm->tblwznmamlibrarymakefile->removeRecByRef(libAmkf->ref);
		};

		for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarypkglist.nodes.size(); ix1++) {
			libApkl = lib->imeiamlibrarypkglist.nodes[ix1];
			if (libApkl->ref != 0) dbswznm->tblwznmamlibrarypkglist->removeRecByRef(libApkl->ref);
		};
	};

	// -- ImeIMLocale
	for (unsigned int ix0 = 0; ix0 < imeimlocale.nodes.size(); ix0++) {
		loc = imeimlocale.nodes[ix0];
		if (loc->ref != 0) dbswznm->tblwznmmlocale->removeRecByRef(loc->ref);

		for (unsigned int ix1 = 0; ix1 < loc->imeijmlocaletitle.nodes.size(); ix1++) {
			locJtit = loc->imeijmlocaletitle.nodes[ix1];
			if (locJtit->ref != 0) dbswznm->tblwznmjmlocaletitle->removeRecByRef(locJtit->ref);
		};
	};

	// -- ImeIMMachtype
	for (unsigned int ix0 = 0; ix0 < imeimmachtype.nodes.size(); ix0++) {
		mty = imeimmachtype.nodes[ix0];
		if (mty->ref != 0) dbswznm->tblwznmmmachtype->removeRecByRef(mty->ref);

		for (unsigned int ix1 = 0; ix1 < mty->imeiammachtypemakefile.nodes.size(); ix1++) {
			mtyAmkf = mty->imeiammachtypemakefile.nodes[ix1];
			if (mtyAmkf->ref != 0) dbswznm->tblwznmammachtypemakefile->removeRecByRef(mtyAmkf->ref);
		};

		for (unsigned int ix1 = 0; ix1 < mty->imeimmachine.nodes.size(); ix1++) {
			mch = mty->imeimmachine.nodes[ix1];
			if (mch->ref != 0) dbswznm->tblwznmmmachine->removeRecByRef(mch->ref);

			for (unsigned int ix2 = 0; ix2 < mch->imeiammachinepar.nodes.size(); ix2++) {
				mchApar = mch->imeiammachinepar.nodes[ix2];
				if (mchApar->ref != 0) dbswznm->tblwznmammachinepar->removeRecByRef(mchApar->ref);
			};
		};
	};

	// -- ImeIMTag1
	for (unsigned int ix0 = 0; ix0 < imeimtag1.nodes.size(); ix0++) {
		tag1 = imeimtag1.nodes[ix0];
		if (tag1->ref != 0) dbswznm->tblwznmmtag->removeRecByRef(tag1->ref);

		for (unsigned int ix1 = 0; ix1 < tag1->imeijmtagtitle1.nodes.size(); ix1++) {
			tagJtit1 = tag1->imeijmtagtitle1.nodes[ix1];
			if (tagJtit1->ref != 0) dbswznm->tblwznmjmtagtitle->removeRecByRef(tagJtit1->ref);
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];
		if (usg->ref != 0) dbswznm->tblwznmmusergroup->removeRecByRef(usg->ref);

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];
			if (usgAacc->ref != 0) dbswznm->tblwznmamusergroupaccess->removeRecByRef(usgAacc->ref);
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];
			if (usr->ref != 0) dbswznm->tblwznmmuser->removeRecByRef(usr->ref);

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];
				if (usrAacc->ref != 0) dbswznm->tblwznmamuseraccess->removeRecByRef(usrAacc->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];
				if (usrJste->ref != 0) dbswznm->tblwznmjmuserstate->removeRecByRef(usrJste->ref);
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];
				if (prs->ref != 0) dbswznm->tblwznmmperson->removeRecByRef(prs->ref);

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];
					if (prsJlnm->ref != 0) dbswznm->tblwznmjmpersonlastname->removeRecByRef(prsJlnm->ref);
				};
			};
		};
	};

	return retval;
};

void JobWznmIexIni::leaveSgeReverse(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeReverse --- INSERT
};

uint JobWznmIexIni::enterSgeCollect(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::CLTDONE;
	retval = nextIxVSgeSuccess;

	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCapability* cpb = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLibrary* lib = NULL;
	ImeitemIMLocale* loc = NULL;
	ImeitemIMMachtype* mty = NULL;
	ImeitemIMTag1* tag1 = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMCapabilityPar* cpbApar = NULL;
	ImeitemIAMLibraryMakefile* libAmkf = NULL;
	ImeitemIAMLibraryPkglist* libApkl = NULL;
	ImeitemIAMMachtypeMakefile* mtyAmkf = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIJAVKeylistKey1* klkJkey1 = NULL;
	ImeitemIJMLocaleTitle* locJtit = NULL;
	ImeitemIJMTagTitle1* tagJtit1 = NULL;
	ImeitemIMMachine* mch = NULL;
	ImeitemIMTag2* tag2 = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIRMCapabilityUniversal* cpbRunv = NULL;
	ImeitemIAMMachinePar* mchApar = NULL;
	ImeitemIAMUserAccess* usrAacc = NULL;
	ImeitemIJAVKeylistKey2* klkJkey2 = NULL;
	ImeitemIJMTagTitle2* tagJtit2 = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint ixWznmVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP enterSgeCollect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0 = 0; ix0 < imeiavcontrolpar.nodes.size(); ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey1
	for (unsigned int ix0 = 0; ix0 < imeiavkeylistkey1.nodes.size(); ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];

		if (klsAkey1->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAVKEYLISTKEY1, ixWznmVIop)) {
			dbswznm->tblwznmjavkeylistkey->loadRefsByKlk(klsAkey1->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey1->refJ) {refs[i] = refs[0]; refs[0] = klsAkey1->refJ; break;};
			for (unsigned int i = 0; i < refs.size(); i++) klsAkey1->imeijavkeylistkey1.nodes.push_back(new ImeitemIJAVKeylistKey1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < klsAkey1->imeijavkeylistkey1.nodes.size(); ix1++) {
			klkJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

			if (klkJkey1->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0 = 0; ix0 < imeiavvaluelistval.nodes.size(); ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMCapability
	for (unsigned int ix0 = 0; ix0 < imeimcapability.nodes.size(); ix0++) {
		cpb = imeimcapability.nodes[ix0];

		if (cpb->ref != 0) {
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

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAVKEYLISTKEY2, ixWznmVIop)) {
			dbswznm->tblwznmavkeylistkey->loadRefsByMtbUrf(VecWznmVMaintable::TBLWZNMMCAPABILITY, cpb->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cpb->imeiavkeylistkey2.nodes.push_back(new ImeitemIAVKeylistKey2(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeiavkeylistkey2.nodes.size(); ix1++) {
			klsAkey2 = cpb->imeiavkeylistkey2.nodes[ix1];

			if (klsAkey2->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJAVKEYLISTKEY2, ixWznmVIop)) {
				dbswznm->tblwznmjavkeylistkey->loadRefsByKlk(klsAkey2->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == klsAkey2->refJ) {refs[i] = refs[0]; refs[0] = klsAkey2->refJ; break;};
				for (unsigned int i = 0; i < refs.size(); i++) klsAkey2->imeijavkeylistkey2.nodes.push_back(new ImeitemIJAVKeylistKey2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < klsAkey2->imeijavkeylistkey2.nodes.size(); ix2++) {
				klkJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix2];

				if (klkJkey2->ref != 0) {
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMTAG2, ixWznmVIop)) {
			dbswznm->tblwznmmtag->loadRefsByCpb(cpb->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cpb->imeimtag2.nodes.push_back(new ImeitemIMTag2(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeimtag2.nodes.size(); ix1++) {
			tag2 = cpb->imeimtag2.nodes[ix1];

			if (tag2->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMTAGTITLE2, ixWznmVIop)) {
				dbswznm->tblwznmjmtagtitle->loadRefsByTag(tag2->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == tag2->refJTitle) {refs[i] = refs[0]; refs[0] = tag2->refJTitle; break;};
				for (unsigned int i = 0; i < refs.size(); i++) tag2->imeijmtagtitle2.nodes.push_back(new ImeitemIJMTagTitle2(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < tag2->imeijmtagtitle2.nodes.size(); ix2++) {
				tagJtit2 = tag2->imeijmtagtitle2.nodes[ix2];

				if (tagJtit2->ref != 0) {
					tagJtit2->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, tagJtit2->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
				};
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIRMCAPABILITYUNIVERSAL, ixWznmVIop)) {
			dbswznm->tblwznmrmcapabilityuniversal->loadRefsByCpb(cpb->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) cpb->imeirmcapabilityuniversal.nodes.push_back(new ImeitemIRMCapabilityUniversal(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < cpb->imeirmcapabilityuniversal.nodes.size(); ix1++) {
			cpbRunv = cpb->imeirmcapabilityuniversal.nodes[ix1];

			if (cpbRunv->ref != 0) {
			};
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0 = 0; ix0 < imeimfile.nodes.size(); ix0++) {
		fil = imeimfile.nodes[ix0];

		if (fil->ref != 0) {
		};
	};

	// -- ImeIMLibrary
	for (unsigned int ix0 = 0; ix0 < imeimlibrary.nodes.size(); ix0++) {
		lib = imeimlibrary.nodes[ix0];

		if (lib->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMLIBRARYMAKEFILE, ixWznmVIop)) {
			dbswznm->tblwznmamlibrarymakefile->loadRefsByLib(lib->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) lib->imeiamlibrarymakefile.nodes.push_back(new ImeitemIAMLibraryMakefile(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarymakefile.nodes.size(); ix1++) {
			libAmkf = lib->imeiamlibrarymakefile.nodes[ix1];

			if (libAmkf->ref != 0) {
				//libAmkf->srefX1RefUref: STUB
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMLIBRARYPKGLIST, ixWznmVIop)) {
			dbswznm->tblwznmamlibrarypkglist->loadRefsByLib(lib->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) lib->imeiamlibrarypkglist.nodes.push_back(new ImeitemIAMLibraryPkglist(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < lib->imeiamlibrarypkglist.nodes.size(); ix1++) {
			libApkl = lib->imeiamlibrarypkglist.nodes[ix1];

			if (libApkl->ref != 0) {
				//libApkl->srefX1RefUref: STUB
			};
		};
	};

	// -- ImeIMLocale
	for (unsigned int ix0 = 0; ix0 < imeimlocale.nodes.size(); ix0++) {
		loc = imeimlocale.nodes[ix0];

		if (loc->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMLOCALETITLE, ixWznmVIop)) {
			dbswznm->tblwznmjmlocaletitle->loadRefsByLoc(loc->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == loc->refJTitle) {refs[i] = refs[0]; refs[0] = loc->refJTitle; break;};
			for (unsigned int i = 0; i < refs.size(); i++) loc->imeijmlocaletitle.nodes.push_back(new ImeitemIJMLocaleTitle(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < loc->imeijmlocaletitle.nodes.size(); ix1++) {
			locJtit = loc->imeijmlocaletitle.nodes[ix1];

			if (locJtit->ref != 0) {
				locJtit->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, locJtit->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMMachtype
	for (unsigned int ix0 = 0; ix0 < imeimmachtype.nodes.size(); ix0++) {
		mty = imeimmachtype.nodes[ix0];

		if (mty->ref != 0) {
			//mty->srefCchRefWznmMMachine: STUB
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMMACHTYPEMAKEFILE, ixWznmVIop)) {
			dbswznm->tblwznmammachtypemakefile->loadRefsByMty(mty->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mty->imeiammachtypemakefile.nodes.push_back(new ImeitemIAMMachtypeMakefile(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mty->imeiammachtypemakefile.nodes.size(); ix1++) {
			mtyAmkf = mty->imeiammachtypemakefile.nodes[ix1];

			if (mtyAmkf->ref != 0) {
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMMACHINE, ixWznmVIop)) {
			dbswznm->tblwznmmmachine->loadRefsByTbl(mty->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) mty->imeimmachine.nodes.push_back(new ImeitemIMMachine(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < mty->imeimmachine.nodes.size(); ix1++) {
			mch = mty->imeimmachine.nodes[ix1];

			if (mch->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMMACHINEPAR, ixWznmVIop)) {
				dbswznm->tblwznmammachinepar->loadRefsByMch(mch->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) mch->imeiammachinepar.nodes.push_back(new ImeitemIAMMachinePar(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < mch->imeiammachinepar.nodes.size(); ix2++) {
				mchApar = mch->imeiammachinepar.nodes[ix2];

				if (mchApar->ref != 0) {
				};
			};
		};
	};

	// -- ImeIMTag1
	for (unsigned int ix0 = 0; ix0 < imeimtag1.nodes.size(); ix0++) {
		tag1 = imeimtag1.nodes[ix0];

		if (tag1->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMTAGTITLE1, ixWznmVIop)) {
			dbswznm->tblwznmjmtagtitle->loadRefsByTag(tag1->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == tag1->refJTitle) {refs[i] = refs[0]; refs[0] = tag1->refJTitle; break;};
			for (unsigned int i = 0; i < refs.size(); i++) tag1->imeijmtagtitle1.nodes.push_back(new ImeitemIJMTagTitle1(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < tag1->imeijmtagtitle1.nodes.size(); ix1++) {
			tagJtit1 = tag1->imeijmtagtitle1.nodes[ix1];

			if (tagJtit1->ref != 0) {
				tagJtit1->srefX1RefWznmMLocale = StubWznm::getStubLocSref(dbswznm, tagJtit1->x1RefWznmMLocale, ixWznmVLocale, Stub::VecVNonetype::VOID, stcch);
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0 = 0; ix0 < imeimusergroup.nodes.size(); ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixWznmVIop)) {
			dbswznm->tblwznmamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeiamusergroupaccess.nodes.size(); ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIMUSER, ixWznmVIop)) {
			dbswznm->tblwznmmuser->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) usg->imeimuser.nodes.push_back(new ImeitemIMUser(dbswznm, refs[i]));
		};

		for (unsigned int ix1 = 0; ix1 < usg->imeimuser.nodes.size(); ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIAMUSERACCESS, ixWznmVIop)) {
				dbswznm->tblwznmamuseraccess->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeiamuseraccess.nodes.push_back(new ImeitemIAMUserAccess(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeiamuseraccess.nodes.size(); ix2++) {
				usrAacc = usr->imeiamuseraccess.nodes[ix2];

				if (usrAacc->ref != 0) {
				};
			};

			if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMUSERSTATE, ixWznmVIop)) {
				dbswznm->tblwznmjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i = 0; i < refs.size(); i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbswznm, refs[i]));
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeijmuserstate.nodes.size(); ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2 = 0; ix2 < usr->imeimperson.nodes.size(); ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxWznmVIop(icsWznmVIop, VecVIme::IMEIJMPERSONLASTNAME, ixWznmVIop)) {
					dbswznm->tblwznmjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i = 0; i < refs.size(); i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbswznm, refs[i]));
				};

				for (unsigned int ix3 = 0; ix3 < prs->imeijmpersonlastname.nodes.size(); ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
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

void JobWznmIexIni::leaveSgeCollect(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCollect --- INSERT
};

uint JobWznmIexIni::enterSgeCltdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CLTDONE;

	// IP enterSgeCltdone --- INSERT

	return retval;
};

void JobWznmIexIni::leaveSgeCltdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCltdone --- INSERT
};

uint JobWznmIexIni::enterSgeExport(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	IexWznmIni::exportToFile(fullpath, xmlNotTxt, shorttags, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcapability, imeimfile, imeimlibrary, imeimlocale, imeimmachtype, imeimtag1, imeimusergroup);

	return retval;
};

void JobWznmIexIni::leaveSgeExport(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeExport --- INSERT
};

uint JobWznmIexIni::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void JobWznmIexIni::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};


