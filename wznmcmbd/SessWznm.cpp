/**
	* \file SessWznm.cpp
	* job handler for job SessWznm (implementation)
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

#include "SessWznm.h"

#include "SessWznm_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class SessWznm
 ******************************************************************************/

SessWznm::SessWznm(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const ubigint refWznmMUser
			, const string& ip
		) :
			JobWznm(xchg, VecWznmVJob::SESSWZNM, jrefSup)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	crdnav = NULL;

	// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	WznmMUser* usr = NULL;

	bool adm;

	ListWznmRMUserMUsergroup urus;
	WznmRMUserMUsergroup* uru = NULL;

	uint ixWznmWAccessBase, ixWznmWAccess;

	uint jnum;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbswznm->tblwznmmsession->insertNewRec(NULL, refWznmMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecWznmVPreset::PREWZNMSESS, jref, refSes);
	xchg->addTxtvalPreset(VecWznmVPreset::PREWZNMIP, jref, ip);

	// set locale and presetings corresponding to user
	dbswznm->tblwznmmuser->loadRecByRef(refWznmMUser, &usr);

	ixWznmVLocale = usr->ixWznmVLocale;
	adm = (usr->ixWznmVUserlevel == VecWznmVUserlevel::ADM);

	xchg->addBoolvalPreset(VecWznmVPreset::PREWZNMADMIN, jref, adm);
	xchg->addBoolvalPreset(VecWznmVPreset::PREWZNMNOADM, jref, (usr->ixWznmVUserlevel == VecWznmVUserlevel::REG));

	xchg->addRefPreset(VecWznmVPreset::PREWZNMGROUP, jref, usr->refWznmMUsergroup);
	xchg->addRefPreset(VecWznmVPreset::PREWZNMOWNER, jref, refWznmMUser);

	delete usr;

	// set jrefSess (for access to WznmQSelect from rst-type panel queries)
	xchg->addRefPreset(VecWznmVPreset::PREWZNMJREFSESS, jref, jref);

	// fill query in WznmQSelect with all applicable user groups
	jnum = 1;

	dbswznm->tblwznmqselect->insertNewRec(NULL, jref, jnum++, 0, 0);

	if (adm) {
		dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmqselect->insertNewRec(NULL, jref, jnum++, 0, refs[i]);

	} else {
		dbswznm->tblwznmrmusermusergroup->loadRstByUsr(refWznmMUser, false, urus);

		for (unsigned int i = 0; i < urus.nodes.size(); i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refWznmMUsergroup] = uru->ixWznmVUserlevel;
			dbswznm->tblwznmqselect->insertNewRec(NULL, jref, jnum++, 0, uru->refWznmMUsergroup);
		};
	};

	// determine access rights for each card
	ixWznmWAccessBase = 0;
	getIxCrdacc(dbswznm, 0, adm, urus, refWznmMUser, ixWznmWAccessBase);

	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMUSG, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMUSR, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSR, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMPRS, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRS, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMFIL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMLOC, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLOC, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMTAG, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMCTP, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCTP, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMMCH, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMLIB, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMPRJ, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMVER, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMCAP, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAP, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMERR, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCERR, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMTBL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMTCO, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMSBS, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMREL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMVEC, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMVIT, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMCHK, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCHK, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMSTB, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMIEX, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMIME, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMIEL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEL, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMPST, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMMDL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMCAR, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMDLG, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMPNL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMQRY, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMQCO, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMQMD, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQMD, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMCON, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMOPK, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMOPX, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMJOB, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMSGE, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMMTD, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTD, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMBLK, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBLK, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMCAL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAL, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMCMP, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMRLS, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMAPP, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMRTJ, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMEVT, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMSEQ, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMSTE, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMUTL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUTL, jref, ixWznmWAccess);

	crdnav = new CrdWznmNav(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMLOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessWznm::~SessWznm() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void SessWznm::warnTerm(
			DbsWznm* dbswznm
		) {
	crdnav->warnTerm(dbswznm);
};

void SessWznm::term(
			DbsWznm* dbswznm
		) {
	WznmMSession* ses = NULL;

	time_t rawtime;

	// update session with stop time
	time(&rawtime);

	if (dbswznm->tblwznmmsession->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMSESS, jref), &ses)) {
		ses->stop = rawtime;
		dbswznm->tblwznmmsession->updateRec(ses);

		delete ses;
	};
};

void SessWznm::eraseCrd(
			map<ubigint, JobWznm*>& subjobs
		) {
	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoll(input.c_str());

	if (!eraseSubjobByJref(subjobs, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tcard erased." << endl;
};

uint SessWznm::checkCrdActive(
			const uint ixWznmVCard
		) {
	if (ixWznmVCard == VecWznmVCard::CRDWZNMTAG) return evalCrdtagActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVER) return evalCrdverActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAP) return evalCrdcapActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMERR) return evalCrderrActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTBL) return evalCrdtblActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTCO) return evalCrdtcoActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSBS) return evalCrdsbsActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMREL) return evalCrdrelActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVEC) return evalCrdvecActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVIT) return evalCrdvitActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCHK) return evalCrdchkActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTB) return evalCrdstbActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEX) return evalCrdiexActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIME) return evalCrdimeActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEL) return evalCrdielActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPST) return evalCrdpstActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMDL) return evalCrdmdlActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAR) return evalCrdcarActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMDLG) return evalCrddlgActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPNL) return evalCrdpnlActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQRY) return evalCrdqryActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQCO) return evalCrdqcoActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQMD) return evalCrdqmdActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCON) return evalCrdconActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPK) return evalCrdopkActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPX) return evalCrdopxActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMJOB) return evalCrdjobActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSGE) return evalCrdsgeActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTD) return evalCrdmtdActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMBLK) return evalCrdblkActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAL) return evalCrdcalActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCMP) return evalCrdcmpActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMRLS) return evalCrdrlsActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMRTJ) return evalCrdrtjActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMEVT) return evalCrdevtActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) return evalCrdseqActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTE) return evalCrdsteActive();

	return 0;
};

uint SessWznm::evalCrdtagActive() {
	// pre.refCtp() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCTP, jref)) ? VecWznmVPreset::PREWZNMREFCTP : 0);
	args.push_back([](){uint preVoid = VecWznmVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdverActive() {
	// pre.refPrj() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRJ, jref)) ? VecWznmVPreset::PREWZNMREFPRJ : 0);
	args.push_back([](){uint preVoid = VecWznmVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdcapActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrderrActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdtblActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdtcoActive() {
	// pre.refTbl() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref)) ? VecWznmVPreset::PREWZNMREFTBL : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdsbsActive() {
	// pre.refTbl() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref)) ? VecWznmVPreset::PREWZNMREFTBL : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdrelActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdvecActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdvitActive() {
	// pre.refVec() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVEC, jref)) ? VecWznmVPreset::PREWZNMREFVEC : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdchkActive() {
	// pre.refTbl() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref)) ? VecWznmVPreset::PREWZNMREFTBL : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdstbActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdiexActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdimeActive() {
	// pre.refIex() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEX, jref)) ? VecWznmVPreset::PREWZNMREFIEX : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdielActive() {
	// pre.refIex() > pre.refIme()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEX, jref)) ? VecWznmVPreset::PREWZNMREFIEX : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIME, jref)) ? VecWznmVPreset::PREWZNMREFIME : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdpstActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdmdlActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdcarActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrddlgActive() {
	// pre.refCar() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref)) ? VecWznmVPreset::PREWZNMREFCAR : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdpnlActive() {
	// pre.refCar() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref)) ? VecWznmVPreset::PREWZNMREFCAR : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdqryActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdqcoActive() {
	// pre.refQry() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQRY, jref)) ? VecWznmVPreset::PREWZNMREFQRY : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdqmdActive() {
	// pre.refQry() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQRY, jref)) ? VecWznmVPreset::PREWZNMREFQRY : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdconActive() {
	// pre.refPnl() > pre.refDlg() > pre.refCar() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPNL, jref)) ? VecWznmVPreset::PREWZNMREFPNL : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFDLG, jref)) ? VecWznmVPreset::PREWZNMREFDLG : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref)) ? VecWznmVPreset::PREWZNMREFCAR : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdopkActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdopxActive() {
	// pre.refOpk() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref)) ? VecWznmVPreset::PREWZNMREFOPK : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdjobActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdsgeActive() {
	// pre.refJob() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref)) ? VecWznmVPreset::PREWZNMREFJOB : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdmtdActive() {
	// pre.refJob() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref)) ? VecWznmVPreset::PREWZNMREFJOB : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdblkActive() {
	// pre.refJob() > pre.refOpx() > pre.refOpk() > pre.refVer()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref)) ? VecWznmVPreset::PREWZNMREFJOB : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPX, jref)) ? VecWznmVPreset::PREWZNMREFOPX : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref)) ? VecWznmVPreset::PREWZNMREFOPK : 0);
	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdcalActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdcmpActive() {
	// pre.refVer() > pre.void()

	vector<uint> args;
	uint a, b;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);
	args.push_back([](){uint preVoid = VecWznmVPreset::VOID; return preVoid;}());
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessWznm::evalCrdrlsActive() {
	// pre.refVer()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref)) ? VecWznmVPreset::PREWZNMREFVER : 0);

	return(args.back());
};

uint SessWznm::evalCrdrtjActive() {
	// pre.refApp()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref)) ? VecWznmVPreset::PREWZNMREFAPP : 0);

	return(args.back());
};

uint SessWznm::evalCrdevtActive() {
	// pre.refApp()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref)) ? VecWznmVPreset::PREWZNMREFAPP : 0);

	return(args.back());
};

uint SessWznm::evalCrdseqActive() {
	// pre.refApp()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref)) ? VecWznmVPreset::PREWZNMREFAPP : 0);

	return(args.back());
};

uint SessWznm::evalCrdsteActive() {
	// pre.refApp()

	vector<uint> args;

	args.push_back((xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref)) ? VecWznmVPreset::PREWZNMREFAPP : 0);

	return(args.back());
};

uint SessWznm::checkCrdaccess(
			const uint ixWznmVCard
		) {
	if (ixWznmVCard == VecWznmVCard::CRDWZNMUSG) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMUSR) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSR, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRS) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRS, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMFIL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMLOC) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLOC, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTAG) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCTP) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCTP, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMCH) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMLIB) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRJ) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVER) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAP) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAP, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMERR) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCERR, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTBL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTCO) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSBS) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMREL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVEC) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVIT) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCHK) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCHK, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTB) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEX) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIME) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEL, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPST) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMDL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAR) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMDLG) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPNL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQRY) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQCO) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQMD) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQMD, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCON) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPK) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPX) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMJOB) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSGE) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTD) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTD, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMBLK) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBLK, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAL, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCMP) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMRLS) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMAPP) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMRTJ) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMEVT) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTE) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref);
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMUTL) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUTL, jref);

	return 0;
};

void SessWznm::getIxCrdacc(
			DbsWznm* dbswznm
			, const uint ixWznmVCard
			, const bool adm
			, ListWznmRMUserMUsergroup& urus
			, const ubigint refWznmMUser
			, uint& ixWznmWAccess
		) {
	WznmRMUserMUsergroup* uru = NULL;
	WznmAMUsergroupAccess* usgAacc = NULL;
	WznmAMUserAccess* usrAacc = NULL;

	uint ixCrdacc = 0;

	bool first = true;

	if (adm) {
		ixWznmWAccess = VecWznmWAccess::EDIT + VecWznmWAccess::EXEC + VecWznmWAccess::VIEW;
		return;
	};

	// check for access rights override by any of the applicable user groups
	for (unsigned int i = 0; i < urus.nodes.size(); i++) {
		uru = urus.nodes[i];

		if (dbswznm->tblwznmamusergroupaccess->loadRecBySQL("SELECT * FROM TblWznmAMUsergroupAccess WHERE refWznmMUsergroup = " + to_string(uru->refWznmMUsergroup) + " AND x1IxWznmVFeatgroup = " + to_string(VecWznmVFeatgroup::VECWZNMVCARD) + " AND x2FeaSrefUix = '" + VecWznmVCard::getSref(ixWznmVCard) + "'", &usgAacc)) {
			ixCrdacc |= usgAacc->ixWznmWAccess;
			first = false;

			delete usgAacc;
			if (ixCrdacc == (VecWznmWAccess::EDIT + VecWznmWAccess::EXEC + VecWznmWAccess::VIEW)) break;
		};
	};

	if (!first) ixWznmWAccess = ixCrdacc;

	// user access rights override user group access rights
	if (dbswznm->tblwznmamuseraccess->loadRecBySQL("SELECT * FROM TblWznmAMUserAccess WHERE refWznmMUser = " + to_string(refWznmMUser) + " AND x1IxWznmVFeatgroup = " + to_string(VecWznmVFeatgroup::VECWZNMVCARD) + " AND x2FeaSrefUix = '" + VecWznmVCard::getSref(ixWznmVCard) + "'", &usrAacc)) {
		ixWznmWAccess = usrAacc->ixWznmWAccess;
		delete usrAacc;
	};

};

uint SessWznm::checkRecaccess(
			DbsWznm* dbswznm
			, const uint ixWznmVCard
			, const ubigint ref
		) {
	uint retval = VecWznmVRecaccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refWznmMUser;
	uint ixWznmVMaintable;

	WznmAccRMUserUniversal* ausrRunv = NULL;
	WznmRMUsergroupUniversal* usgRunv = NULL;

	ixWznmVMaintable = crdToMtb(ixWznmVCard);

	if (ixWznmVMaintable == VecWznmVMaintable::VOID) {
		retval = VecWznmVRecaccess::FULL;

	} else if (hasGrpown(ixWznmVMaintable) && (ref != 0)) {
		// find record's group and owner
		dbswznm->loadRefBySQL("SELECT grp FROM " + VecWznmVMaintable::getSref(ixWznmVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbswznm->loadRefBySQL("SELECT own FROM " + VecWznmVMaintable::getSref(ixWznmVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMADMIN, jref)) retval = VecWznmVRecaccess::FULL;

		if (retval == VecWznmVRecaccess::NONE) {
			refWznmMUser = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);

			// a record's owner has full rights on his records
			if (refWznmMUser == own) retval = VecWznmVRecaccess::FULL;

			if (retval != VecWznmVRecaccess::FULL) {
				// individual record access right
				if (dbswznm->tblwznmaccrmuseruniversal->loadRecByUsrMtbUnv(refWznmMUser, ixWznmVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixWznmVRecaccess;
					delete ausrRunv;
				};
			};

			if (retval != VecWznmVRecaccess::FULL) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecWznmVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecWznmVRecaccess::FULL;
					};
				};
			};

			if (retval != VecWznmVRecaccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin(); it != usgaccs.end(); it++) {

					if (it->second == VecWznmVUserlevel::GADM) {
						if (dbswznm->tblwznmrmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixWznmVMaintable, ref, &usgRunv)) {
							if (usgRunv->ixWznmVRecaccess == VecWznmVRecaccess::FULL) retval = VecWznmVRecaccess::FULL;
							else retval = VecWznmVRecaccess::VIEW;

							delete usgRunv;
						};
					};

					if (retval == VecWznmVRecaccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMADMIN, jref)) retval = VecWznmVRecaccess::FULL;
		else retval = VecWznmVRecaccess::VIEW;
	};

	return retval;
};

void SessWznm::logRecaccess(
			DbsWznm* dbswznm
			, const uint ixWznmVPreset
			, const ubigint preUref
			, const uint ixWznmVCard
			, const ubigint unvUref
		) {
	vector<ubigint> refs;

	ubigint refWznmMUser;
	uint unvIxWznmVMaintable;
	uint preIxWznmVMaintable;

	WznmHistRMUserUniversal* husrRunv = NULL;

	if (xchg->stgwznmappearance.histlength > 0) {
		refWznmMUser = xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref);
		unvIxWznmVMaintable = crdToMtb(ixWznmVCard);
		preIxWznmVMaintable = preToMtb(ixWznmVPreset);

		if (!dbswznm->tblwznmhistrmuseruniversal->loadRecByUsrMtbUnvCrd(refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, &husrRunv)) {
			husrRunv = new WznmHistRMUserUniversal(0, refWznmMUser, unvIxWznmVMaintable, unvUref, ixWznmVCard, ixWznmVPreset, preIxWznmVMaintable, preUref, 0);
		};

		husrRunv->start = time(NULL);

		if (husrRunv->ref == 0) {
			dbswznm->tblwznmhistrmuseruniversal->insertRec(husrRunv);

			dbswznm->tblwznmhistrmuseruniversal->loadRefsByUsrMtbCrd(refWznmMUser, unvIxWznmVMaintable, ixWznmVCard, false, refs, 4294967296, xchg->stgwznmappearance.histlength);
			for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmhistrmuseruniversal->removeRecByRef(refs[i]);

		} else dbswznm->tblwznmhistrmuseruniversal->updateRec(husrRunv);

		xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMHUSRRUNVMOD_CRDUSREQ, jref, ixWznmVCard, refWznmMUser);
	};

	delete husrRunv;
};

uint SessWznm::crdToMtb(
			const uint ixWznmVCard
		) {
	if (ixWznmVCard == VecWznmVCard::CRDWZNMUSG) return VecWznmVMaintable::TBLWZNMMUSERGROUP;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMUSR) return VecWznmVMaintable::TBLWZNMMUSER;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRS) return VecWznmVMaintable::TBLWZNMMPERSON;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMFIL) return VecWznmVMaintable::TBLWZNMMFILE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMLOC) return VecWznmVMaintable::TBLWZNMMLOCALE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTAG) return VecWznmVMaintable::TBLWZNMMTAG;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCTP) return VecWznmVMaintable::TBLWZNMMCAPABILITY;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMCH) return VecWznmVMaintable::TBLWZNMMMACHINE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMLIB) return VecWznmVMaintable::TBLWZNMMLIBRARY;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRJ) return VecWznmVMaintable::TBLWZNMMPROJECT;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVER) return VecWznmVMaintable::TBLWZNMMVERSION;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAP) return VecWznmVMaintable::TBLWZNMMCAPABILITY;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMERR) return VecWznmVMaintable::TBLWZNMMERROR;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTBL) return VecWznmVMaintable::TBLWZNMMTABLE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMTCO) return VecWznmVMaintable::TBLWZNMMTABLECOL;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSBS) return VecWznmVMaintable::TBLWZNMMSUBSET;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMREL) return VecWznmVMaintable::TBLWZNMMRELATION;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVEC) return VecWznmVMaintable::TBLWZNMMVECTOR;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMVIT) return VecWznmVMaintable::TBLWZNMMVECTORITEM;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCHK) return VecWznmVMaintable::TBLWZNMMCHECK;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTB) return VecWznmVMaintable::TBLWZNMMSTUB;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEX) return VecWznmVMaintable::TBLWZNMMIMPEXPCPLX;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIME) return VecWznmVMaintable::TBLWZNMMIMPEXP;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEL) return VecWznmVMaintable::TBLWZNMMIMPEXPCOL;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPST) return VecWznmVMaintable::TBLWZNMMPRESET;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMDL) return VecWznmVMaintable::TBLWZNMMMODULE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAR) return VecWznmVMaintable::TBLWZNMMCARD;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMDLG) return VecWznmVMaintable::TBLWZNMMDIALOG;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMPNL) return VecWznmVMaintable::TBLWZNMMPANEL;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQRY) return VecWznmVMaintable::TBLWZNMMQUERY;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQCO) return VecWznmVMaintable::TBLWZNMMQUERYCOL;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMQMD) return VecWznmVMaintable::TBLWZNMMQUERYMOD;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCON) return VecWznmVMaintable::TBLWZNMMCONTROL;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPK) return VecWznmVMaintable::TBLWZNMMOPPACK;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPX) return VecWznmVMaintable::TBLWZNMMOP;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMJOB) return VecWznmVMaintable::TBLWZNMMJOB;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSGE) return VecWznmVMaintable::TBLWZNMMSTAGE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTD) return VecWznmVMaintable::TBLWZNMMMETHOD;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMBLK) return VecWznmVMaintable::TBLWZNMMBLOCK;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAL) return VecWznmVMaintable::TBLWZNMMCALL;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMCMP) return VecWznmVMaintable::TBLWZNMMCOMPONENT;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMRLS) return VecWznmVMaintable::TBLWZNMMRELEASE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMAPP) return VecWznmVMaintable::TBLWZNMMAPP;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMRTJ) return VecWznmVMaintable::TBLWZNMMRTJOB;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMEVT) return VecWznmVMaintable::TBLWZNMMEVENT;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) return VecWznmVMaintable::TBLWZNMMSEQUENCE;
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTE) return VecWznmVMaintable::TBLWZNMMSTATE;

	return VecWznmVMaintable::VOID;
};

uint SessWznm::preToMtb(
			const uint ixWznmVPreset
		) {
	if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFAPP) return VecWznmVMaintable::TBLWZNMMAPP;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFBLK) return VecWznmVMaintable::TBLWZNMMBLOCK;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCAI) return VecWznmVMaintable::TBLWZNMMCONTROL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCAL) return VecWznmVMaintable::TBLWZNMMCALL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCAP) return VecWznmVMaintable::TBLWZNMMCAPABILITY;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCAR) return VecWznmVMaintable::TBLWZNMMCARD;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCCP) return VecWznmVMaintable::TBLWZNMMCOMPONENT;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCDC) return VecWznmVMaintable::TBLWZNMMCALL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCFB) return VecWznmVMaintable::TBLWZNMMCONTROL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCHK) return VecWznmVMaintable::TBLWZNMMCHECK;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCMP) return VecWznmVMaintable::TBLWZNMMCOMPONENT;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCON) return VecWznmVMaintable::TBLWZNMMCONTROL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCPB) return VecWznmVMaintable::TBLWZNMMCAPABILITY;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFCTP) return VecWznmVMaintable::TBLWZNMMCAPABILITY;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFDLG) return VecWznmVMaintable::TBLWZNMMDIALOG;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFERR) return VecWznmVMaintable::TBLWZNMMERROR;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFEVT) return VecWznmVMaintable::TBLWZNMMEVENT;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFFED) return VecWznmVMaintable::TBLWZNMMFEED;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFFIL) return VecWznmVMaintable::TBLWZNMMFILE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFIEL) return VecWznmVMaintable::TBLWZNMMIMPEXPCOL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFIEX) return VecWznmVMaintable::TBLWZNMMIMPEXPCPLX;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFIME) return VecWznmVMaintable::TBLWZNMMIMPEXP;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFJOB) return VecWznmVMaintable::TBLWZNMMJOB;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFKLS) return VecWznmVMaintable::TBLWZNMMVECTOR;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFLIB) return VecWznmVMaintable::TBLWZNMMLIBRARY;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFLOC) return VecWznmVMaintable::TBLWZNMMLOCALE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMCH) return VecWznmVMaintable::TBLWZNMMMACHINE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMDL) return VecWznmVMaintable::TBLWZNMMMODULE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMTB) return VecWznmVMaintable::TBLWZNMMTABLE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMTD) return VecWznmVMaintable::TBLWZNMMMETHOD;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOEN) return VecWznmVMaintable::TBLWZNMMCOMPONENT;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOPK) return VecWznmVMaintable::TBLWZNMMOPPACK;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFOPX) return VecWznmVMaintable::TBLWZNMMOP;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPNL) return VecWznmVMaintable::TBLWZNMMPANEL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPRJ) return VecWznmVMaintable::TBLWZNMMPROJECT;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPRS) return VecWznmVMaintable::TBLWZNMMPERSON;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFPST) return VecWznmVMaintable::TBLWZNMMPRESET;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFQCO) return VecWznmVMaintable::TBLWZNMMQUERYCOL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFQMD) return VecWznmVMaintable::TBLWZNMMQUERYMOD;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFQRY) return VecWznmVMaintable::TBLWZNMMQUERY;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFQTB) return VecWznmVMaintable::TBLWZNMMTABLE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFREL) return VecWznmVMaintable::TBLWZNMMRELATION;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFRLS) return VecWznmVMaintable::TBLWZNMMRELEASE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFRLT) return VecWznmVMaintable::TBLWZNMMTABLE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFRTB) return VecWznmVMaintable::TBLWZNMMRTBLOCK;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFRTD) return VecWznmVMaintable::TBLWZNMMRTDPCH;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFRTJ) return VecWznmVMaintable::TBLWZNMMRTJOB;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSBS) return VecWznmVMaintable::TBLWZNMMSUBSET;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSEQ) return VecWznmVMaintable::TBLWZNMMSEQUENCE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSES) return VecWznmVMaintable::TBLWZNMMSESSION;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSGE) return VecWznmVMaintable::TBLWZNMMSTAGE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSNS) return VecWznmVMaintable::TBLWZNMMSENSITIVITY;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSQK) return VecWznmVMaintable::TBLWZNMMSQUAWK;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSTB) return VecWznmVMaintable::TBLWZNMMSTUB;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSTC) return VecWznmVMaintable::TBLWZNMMTABLECOL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSTE) return VecWznmVMaintable::TBLWZNMMSTATE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFSTT) return VecWznmVMaintable::TBLWZNMMTABLE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTAG) return VecWznmVMaintable::TBLWZNMMTAG;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTBL) return VecWznmVMaintable::TBLWZNMMTABLE;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFTCO) return VecWznmVMaintable::TBLWZNMMTABLECOL;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFUSG) return VecWznmVMaintable::TBLWZNMMUSERGROUP;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFUSR) return VecWznmVMaintable::TBLWZNMMUSER;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVEC) return VecWznmVMaintable::TBLWZNMMVECTOR;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVER) return VecWznmVMaintable::TBLWZNMMVERSION;
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFVIT) return VecWznmVMaintable::TBLWZNMMVECTORITEM;

	return VecWznmVMaintable::VOID;
};

bool SessWznm::hasActive(
			const uint ixWznmVCard
		) {
	return((ixWznmVCard == VecWznmVCard::CRDWZNMTAG) || (ixWznmVCard == VecWznmVCard::CRDWZNMVER) || (ixWznmVCard == VecWznmVCard::CRDWZNMCAP) || (ixWznmVCard == VecWznmVCard::CRDWZNMERR) || (ixWznmVCard == VecWznmVCard::CRDWZNMTBL) || (ixWznmVCard == VecWznmVCard::CRDWZNMTCO) || (ixWznmVCard == VecWznmVCard::CRDWZNMSBS) || (ixWznmVCard == VecWznmVCard::CRDWZNMREL) || (ixWznmVCard == VecWznmVCard::CRDWZNMVEC) || (ixWznmVCard == VecWznmVCard::CRDWZNMVIT) || (ixWznmVCard == VecWznmVCard::CRDWZNMCHK) || (ixWznmVCard == VecWznmVCard::CRDWZNMSTB) || (ixWznmVCard == VecWznmVCard::CRDWZNMIEX) || (ixWznmVCard == VecWznmVCard::CRDWZNMIME) || (ixWznmVCard == VecWznmVCard::CRDWZNMIEL) || (ixWznmVCard == VecWznmVCard::CRDWZNMPST) || (ixWznmVCard == VecWznmVCard::CRDWZNMMDL) || (ixWznmVCard == VecWznmVCard::CRDWZNMCAR) || (ixWznmVCard == VecWznmVCard::CRDWZNMDLG) || (ixWznmVCard == VecWznmVCard::CRDWZNMPNL) || (ixWznmVCard == VecWznmVCard::CRDWZNMQRY) || (ixWznmVCard == VecWznmVCard::CRDWZNMQCO) || (ixWznmVCard == VecWznmVCard::CRDWZNMQMD) || (ixWznmVCard == VecWznmVCard::CRDWZNMCON) || (ixWznmVCard == VecWznmVCard::CRDWZNMOPK) || (ixWznmVCard == VecWznmVCard::CRDWZNMOPX) || (ixWznmVCard == VecWznmVCard::CRDWZNMJOB) || (ixWznmVCard == VecWznmVCard::CRDWZNMSGE) || (ixWznmVCard == VecWznmVCard::CRDWZNMMTD) || (ixWznmVCard == VecWznmVCard::CRDWZNMBLK) || (ixWznmVCard == VecWznmVCard::CRDWZNMCAL) || (ixWznmVCard == VecWznmVCard::CRDWZNMCMP) || (ixWznmVCard == VecWznmVCard::CRDWZNMRLS) || (ixWznmVCard == VecWznmVCard::CRDWZNMRTJ) || (ixWznmVCard == VecWznmVCard::CRDWZNMEVT) || (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) || (ixWznmVCard == VecWznmVCard::CRDWZNMSTE));
};

bool SessWznm::hasGrpown(
			const uint ixWznmVMaintable
		) {
	return((ixWznmVMaintable == VecWznmVMaintable::TBLWZNMMAPP) || (ixWznmVMaintable == VecWznmVMaintable::TBLWZNMMFILE) || (ixWznmVMaintable == VecWznmVMaintable::TBLWZNMMPERSON) || (ixWznmVMaintable == VecWznmVMaintable::TBLWZNMMPROJECT) || (ixWznmVMaintable == VecWznmVMaintable::TBLWZNMMUSER) || (ixWznmVMaintable == VecWznmVMaintable::TBLWZNMMUSERGROUP) || (ixWznmVMaintable == VecWznmVMaintable::TBLWZNMMVERSION));
};

void SessWznm::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tcreateCrdapp" << endl;
			cout << "\tcreateCrdblk" << endl;
			cout << "\tcreateCrdcal" << endl;
			cout << "\tcreateCrdcap" << endl;
			cout << "\tcreateCrdcar" << endl;
			cout << "\tcreateCrdchk" << endl;
			cout << "\tcreateCrdcmp" << endl;
			cout << "\tcreateCrdcon" << endl;
			cout << "\tcreateCrdctp" << endl;
			cout << "\tcreateCrddlg" << endl;
			cout << "\tcreateCrderr" << endl;
			cout << "\tcreateCrdevt" << endl;
			cout << "\tcreateCrdfil" << endl;
			cout << "\tcreateCrdiel" << endl;
			cout << "\tcreateCrdiex" << endl;
			cout << "\tcreateCrdime" << endl;
			cout << "\tcreateCrdjob" << endl;
			cout << "\tcreateCrdlib" << endl;
			cout << "\tcreateCrdloc" << endl;
			cout << "\tcreateCrdmch" << endl;
			cout << "\tcreateCrdmdl" << endl;
			cout << "\tcreateCrdmtd" << endl;
			cout << "\tcreateCrdopk" << endl;
			cout << "\tcreateCrdopx" << endl;
			cout << "\tcreateCrdpnl" << endl;
			cout << "\tcreateCrdprj" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdpst" << endl;
			cout << "\tcreateCrdqco" << endl;
			cout << "\tcreateCrdqmd" << endl;
			cout << "\tcreateCrdqry" << endl;
			cout << "\tcreateCrdrel" << endl;
			cout << "\tcreateCrdrls" << endl;
			cout << "\tcreateCrdrtj" << endl;
			cout << "\tcreateCrdsbs" << endl;
			cout << "\tcreateCrdseq" << endl;
			cout << "\tcreateCrdsge" << endl;
			cout << "\tcreateCrdstb" << endl;
			cout << "\tcreateCrdste" << endl;
			cout << "\tcreateCrdtag" << endl;
			cout << "\tcreateCrdtbl" << endl;
			cout << "\tcreateCrdtco" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\tcreateCrdutl" << endl;
			cout << "\tcreateCrdvec" << endl;
			cout << "\tcreateCrdver" << endl;
			cout << "\tcreateCrdvit" << endl;
			cout << "\teraseCrdapp" << endl;
			cout << "\teraseCrdblk" << endl;
			cout << "\teraseCrdcal" << endl;
			cout << "\teraseCrdcap" << endl;
			cout << "\teraseCrdcar" << endl;
			cout << "\teraseCrdchk" << endl;
			cout << "\teraseCrdcmp" << endl;
			cout << "\teraseCrdcon" << endl;
			cout << "\teraseCrdctp" << endl;
			cout << "\teraseCrddlg" << endl;
			cout << "\teraseCrderr" << endl;
			cout << "\teraseCrdevt" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdiel" << endl;
			cout << "\teraseCrdiex" << endl;
			cout << "\teraseCrdime" << endl;
			cout << "\teraseCrdjob" << endl;
			cout << "\teraseCrdlib" << endl;
			cout << "\teraseCrdloc" << endl;
			cout << "\teraseCrdmch" << endl;
			cout << "\teraseCrdmdl" << endl;
			cout << "\teraseCrdmtd" << endl;
			cout << "\teraseCrdopk" << endl;
			cout << "\teraseCrdopx" << endl;
			cout << "\teraseCrdpnl" << endl;
			cout << "\teraseCrdprj" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdpst" << endl;
			cout << "\teraseCrdqco" << endl;
			cout << "\teraseCrdqmd" << endl;
			cout << "\teraseCrdqry" << endl;
			cout << "\teraseCrdrel" << endl;
			cout << "\teraseCrdrls" << endl;
			cout << "\teraseCrdrtj" << endl;
			cout << "\teraseCrdsbs" << endl;
			cout << "\teraseCrdseq" << endl;
			cout << "\teraseCrdsge" << endl;
			cout << "\teraseCrdstb" << endl;
			cout << "\teraseCrdste" << endl;
			cout << "\teraseCrdtag" << endl;
			cout << "\teraseCrdtbl" << endl;
			cout << "\teraseCrdtco" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
			cout << "\teraseCrdutl" << endl;
			cout << "\teraseCrdvec" << endl;
			cout << "\teraseCrdver" << endl;
			cout << "\teraseCrdvit" << endl;
		} else if (req->cmd == "createCrdapp") {
			req->retain = handleCreateCrdapp(dbswznm);

		} else if (req->cmd == "createCrdblk") {
			req->retain = handleCreateCrdblk(dbswznm);

		} else if (req->cmd == "createCrdcal") {
			req->retain = handleCreateCrdcal(dbswznm);

		} else if (req->cmd == "createCrdcap") {
			req->retain = handleCreateCrdcap(dbswznm);

		} else if (req->cmd == "createCrdcar") {
			req->retain = handleCreateCrdcar(dbswznm);

		} else if (req->cmd == "createCrdchk") {
			req->retain = handleCreateCrdchk(dbswznm);

		} else if (req->cmd == "createCrdcmp") {
			req->retain = handleCreateCrdcmp(dbswznm);

		} else if (req->cmd == "createCrdcon") {
			req->retain = handleCreateCrdcon(dbswznm);

		} else if (req->cmd == "createCrdctp") {
			req->retain = handleCreateCrdctp(dbswznm);

		} else if (req->cmd == "createCrddlg") {
			req->retain = handleCreateCrddlg(dbswznm);

		} else if (req->cmd == "createCrderr") {
			req->retain = handleCreateCrderr(dbswznm);

		} else if (req->cmd == "createCrdevt") {
			req->retain = handleCreateCrdevt(dbswznm);

		} else if (req->cmd == "createCrdfil") {
			req->retain = handleCreateCrdfil(dbswznm);

		} else if (req->cmd == "createCrdiel") {
			req->retain = handleCreateCrdiel(dbswznm);

		} else if (req->cmd == "createCrdiex") {
			req->retain = handleCreateCrdiex(dbswznm);

		} else if (req->cmd == "createCrdime") {
			req->retain = handleCreateCrdime(dbswznm);

		} else if (req->cmd == "createCrdjob") {
			req->retain = handleCreateCrdjob(dbswznm);

		} else if (req->cmd == "createCrdlib") {
			req->retain = handleCreateCrdlib(dbswznm);

		} else if (req->cmd == "createCrdloc") {
			req->retain = handleCreateCrdloc(dbswznm);

		} else if (req->cmd == "createCrdmch") {
			req->retain = handleCreateCrdmch(dbswznm);

		} else if (req->cmd == "createCrdmdl") {
			req->retain = handleCreateCrdmdl(dbswznm);

		} else if (req->cmd == "createCrdmtd") {
			req->retain = handleCreateCrdmtd(dbswznm);

		} else if (req->cmd == "createCrdopk") {
			req->retain = handleCreateCrdopk(dbswznm);

		} else if (req->cmd == "createCrdopx") {
			req->retain = handleCreateCrdopx(dbswznm);

		} else if (req->cmd == "createCrdpnl") {
			req->retain = handleCreateCrdpnl(dbswznm);

		} else if (req->cmd == "createCrdprj") {
			req->retain = handleCreateCrdprj(dbswznm);

		} else if (req->cmd == "createCrdprs") {
			req->retain = handleCreateCrdprs(dbswznm);

		} else if (req->cmd == "createCrdpst") {
			req->retain = handleCreateCrdpst(dbswznm);

		} else if (req->cmd == "createCrdqco") {
			req->retain = handleCreateCrdqco(dbswznm);

		} else if (req->cmd == "createCrdqmd") {
			req->retain = handleCreateCrdqmd(dbswznm);

		} else if (req->cmd == "createCrdqry") {
			req->retain = handleCreateCrdqry(dbswznm);

		} else if (req->cmd == "createCrdrel") {
			req->retain = handleCreateCrdrel(dbswznm);

		} else if (req->cmd == "createCrdrls") {
			req->retain = handleCreateCrdrls(dbswznm);

		} else if (req->cmd == "createCrdrtj") {
			req->retain = handleCreateCrdrtj(dbswznm);

		} else if (req->cmd == "createCrdsbs") {
			req->retain = handleCreateCrdsbs(dbswznm);

		} else if (req->cmd == "createCrdseq") {
			req->retain = handleCreateCrdseq(dbswznm);

		} else if (req->cmd == "createCrdsge") {
			req->retain = handleCreateCrdsge(dbswznm);

		} else if (req->cmd == "createCrdstb") {
			req->retain = handleCreateCrdstb(dbswznm);

		} else if (req->cmd == "createCrdste") {
			req->retain = handleCreateCrdste(dbswznm);

		} else if (req->cmd == "createCrdtag") {
			req->retain = handleCreateCrdtag(dbswznm);

		} else if (req->cmd == "createCrdtbl") {
			req->retain = handleCreateCrdtbl(dbswznm);

		} else if (req->cmd == "createCrdtco") {
			req->retain = handleCreateCrdtco(dbswznm);

		} else if (req->cmd == "createCrdusg") {
			req->retain = handleCreateCrdusg(dbswznm);

		} else if (req->cmd == "createCrdusr") {
			req->retain = handleCreateCrdusr(dbswznm);

		} else if (req->cmd == "createCrdutl") {
			req->retain = handleCreateCrdutl(dbswznm);

		} else if (req->cmd == "createCrdvec") {
			req->retain = handleCreateCrdvec(dbswznm);

		} else if (req->cmd == "createCrdver") {
			req->retain = handleCreateCrdver(dbswznm);

		} else if (req->cmd == "createCrdvit") {
			req->retain = handleCreateCrdvit(dbswznm);

		} else if (req->cmd == "eraseCrdapp") {
			req->retain = handleEraseCrdapp(dbswznm);

		} else if (req->cmd == "eraseCrdblk") {
			req->retain = handleEraseCrdblk(dbswznm);

		} else if (req->cmd == "eraseCrdcal") {
			req->retain = handleEraseCrdcal(dbswznm);

		} else if (req->cmd == "eraseCrdcap") {
			req->retain = handleEraseCrdcap(dbswznm);

		} else if (req->cmd == "eraseCrdcar") {
			req->retain = handleEraseCrdcar(dbswznm);

		} else if (req->cmd == "eraseCrdchk") {
			req->retain = handleEraseCrdchk(dbswznm);

		} else if (req->cmd == "eraseCrdcmp") {
			req->retain = handleEraseCrdcmp(dbswznm);

		} else if (req->cmd == "eraseCrdcon") {
			req->retain = handleEraseCrdcon(dbswznm);

		} else if (req->cmd == "eraseCrdctp") {
			req->retain = handleEraseCrdctp(dbswznm);

		} else if (req->cmd == "eraseCrddlg") {
			req->retain = handleEraseCrddlg(dbswznm);

		} else if (req->cmd == "eraseCrderr") {
			req->retain = handleEraseCrderr(dbswznm);

		} else if (req->cmd == "eraseCrdevt") {
			req->retain = handleEraseCrdevt(dbswznm);

		} else if (req->cmd == "eraseCrdfil") {
			req->retain = handleEraseCrdfil(dbswznm);

		} else if (req->cmd == "eraseCrdiel") {
			req->retain = handleEraseCrdiel(dbswznm);

		} else if (req->cmd == "eraseCrdiex") {
			req->retain = handleEraseCrdiex(dbswznm);

		} else if (req->cmd == "eraseCrdime") {
			req->retain = handleEraseCrdime(dbswznm);

		} else if (req->cmd == "eraseCrdjob") {
			req->retain = handleEraseCrdjob(dbswznm);

		} else if (req->cmd == "eraseCrdlib") {
			req->retain = handleEraseCrdlib(dbswznm);

		} else if (req->cmd == "eraseCrdloc") {
			req->retain = handleEraseCrdloc(dbswznm);

		} else if (req->cmd == "eraseCrdmch") {
			req->retain = handleEraseCrdmch(dbswznm);

		} else if (req->cmd == "eraseCrdmdl") {
			req->retain = handleEraseCrdmdl(dbswznm);

		} else if (req->cmd == "eraseCrdmtd") {
			req->retain = handleEraseCrdmtd(dbswznm);

		} else if (req->cmd == "eraseCrdopk") {
			req->retain = handleEraseCrdopk(dbswznm);

		} else if (req->cmd == "eraseCrdopx") {
			req->retain = handleEraseCrdopx(dbswznm);

		} else if (req->cmd == "eraseCrdpnl") {
			req->retain = handleEraseCrdpnl(dbswznm);

		} else if (req->cmd == "eraseCrdprj") {
			req->retain = handleEraseCrdprj(dbswznm);

		} else if (req->cmd == "eraseCrdprs") {
			req->retain = handleEraseCrdprs(dbswznm);

		} else if (req->cmd == "eraseCrdpst") {
			req->retain = handleEraseCrdpst(dbswznm);

		} else if (req->cmd == "eraseCrdqco") {
			req->retain = handleEraseCrdqco(dbswznm);

		} else if (req->cmd == "eraseCrdqmd") {
			req->retain = handleEraseCrdqmd(dbswznm);

		} else if (req->cmd == "eraseCrdqry") {
			req->retain = handleEraseCrdqry(dbswznm);

		} else if (req->cmd == "eraseCrdrel") {
			req->retain = handleEraseCrdrel(dbswznm);

		} else if (req->cmd == "eraseCrdrls") {
			req->retain = handleEraseCrdrls(dbswznm);

		} else if (req->cmd == "eraseCrdrtj") {
			req->retain = handleEraseCrdrtj(dbswznm);

		} else if (req->cmd == "eraseCrdsbs") {
			req->retain = handleEraseCrdsbs(dbswznm);

		} else if (req->cmd == "eraseCrdseq") {
			req->retain = handleEraseCrdseq(dbswznm);

		} else if (req->cmd == "eraseCrdsge") {
			req->retain = handleEraseCrdsge(dbswznm);

		} else if (req->cmd == "eraseCrdstb") {
			req->retain = handleEraseCrdstb(dbswznm);

		} else if (req->cmd == "eraseCrdste") {
			req->retain = handleEraseCrdste(dbswznm);

		} else if (req->cmd == "eraseCrdtag") {
			req->retain = handleEraseCrdtag(dbswznm);

		} else if (req->cmd == "eraseCrdtbl") {
			req->retain = handleEraseCrdtbl(dbswznm);

		} else if (req->cmd == "eraseCrdtco") {
			req->retain = handleEraseCrdtco(dbswznm);

		} else if (req->cmd == "eraseCrdusg") {
			req->retain = handleEraseCrdusg(dbswznm);

		} else if (req->cmd == "eraseCrdusr") {
			req->retain = handleEraseCrdusr(dbswznm);

		} else if (req->cmd == "eraseCrdutl") {
			req->retain = handleEraseCrdutl(dbswznm);

		} else if (req->cmd == "eraseCrdvec") {
			req->retain = handleEraseCrdvec(dbswznm);

		} else if (req->cmd == "eraseCrdver") {
			req->retain = handleEraseCrdver(dbswznm);

		} else if (req->cmd == "eraseCrdvit") {
			req->retain = handleEraseCrdvit(dbswznm);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMINIT) {
			handleDpchAppWznmInit(dbswznm, (DpchAppWznmInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool SessWznm::handleCreateCrdapp(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdapps, new CrdWznmApp(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdblk(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdblkActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdblks, new CrdWznmBlk(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdcal(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdcalActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcals, new CrdWznmCal(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdcap(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdcapActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcaps, new CrdWznmCap(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdcar(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdcarActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcars, new CrdWznmCar(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdchk(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdchkActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdchks, new CrdWznmChk(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdcmp(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdcmpActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcmps, new CrdWznmCmp(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdcon(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdconActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdcons, new CrdWznmCon(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdctp(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdctps, new CrdWznmCtp(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrddlg(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrddlgActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crddlgs, new CrdWznmDlg(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrderr(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrderrActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crderrs, new CrdWznmErr(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdevt(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdevtActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdevts, new CrdWznmEvt(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdfil(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdfils, new CrdWznmFil(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdiel(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdielActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdiels, new CrdWznmIel(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdiex(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdiexActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdiexs, new CrdWznmIex(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdime(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdimeActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdimes, new CrdWznmIme(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdjob(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdjobActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdjobs, new CrdWznmJob(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdlib(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdlibs, new CrdWznmLib(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdloc(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdlocs, new CrdWznmLoc(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdmch(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdmchs, new CrdWznmMch(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdmdl(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdmdlActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdmdls, new CrdWznmMdl(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdmtd(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdmtdActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdmtds, new CrdWznmMtd(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdopk(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdopkActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdopks, new CrdWznmOpk(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdopx(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdopxActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdopxs, new CrdWznmOpx(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdpnl(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdpnlActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdpnls, new CrdWznmPnl(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdprj(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprjs, new CrdWznmPrj(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdprs(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdprss, new CrdWznmPrs(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdpst(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdpstActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdpsts, new CrdWznmPst(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdqco(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdqcoActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdqcos, new CrdWznmQco(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdqmd(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdqmdActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdqmds, new CrdWznmQmd(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdqry(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdqryActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdqrys, new CrdWznmQry(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdrel(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdrelActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdrels, new CrdWznmRel(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdrls(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdrlsActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdrlss, new CrdWznmRls(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdrtj(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdrtjActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdrtjs, new CrdWznmRtj(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdsbs(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdsbsActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdsbss, new CrdWznmSbs(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdseq(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdseqActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdseqs, new CrdWznmSeq(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdsge(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdsgeActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdsges, new CrdWznmSge(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdstb(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdstbActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdstbs, new CrdWznmStb(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdste(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdsteActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdstes, new CrdWznmSte(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdtag(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdtagActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdtags, new CrdWznmTag(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdtbl(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdtblActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdtbls, new CrdWznmTbl(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdtco(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdtcoActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdtcos, new CrdWznmTco(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdusg(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusgs, new CrdWznmUsg(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdusr(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdusrs, new CrdWznmUsr(xchg, dbswznm, jref, ixWznmVLocale, 0));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdutl(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	xchg->jrefCmd = insertSubjob(crdutls, new CrdWznmUtl(xchg, dbswznm, jref, ixWznmVLocale));
	cout << "\tjob reference: " << xchg->jrefCmd << endl;

	return retval;
};

bool SessWznm::handleCreateCrdvec(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdvecActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdvecs, new CrdWznmVec(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdver(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdverActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdvers, new CrdWznmVer(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleCreateCrdvit(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	uint ixWznmVPreset = evalCrdvitActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		xchg->jrefCmd = insertSubjob(crdvits, new CrdWznmVit(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref)));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;
	};

	return retval;
};

bool SessWznm::handleEraseCrdapp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdapps);
	return retval;
};

bool SessWznm::handleEraseCrdblk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdblks);
	return retval;
};

bool SessWznm::handleEraseCrdcal(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdcals);
	return retval;
};

bool SessWznm::handleEraseCrdcap(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdcaps);
	return retval;
};

bool SessWznm::handleEraseCrdcar(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdcars);
	return retval;
};

bool SessWznm::handleEraseCrdchk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdchks);
	return retval;
};

bool SessWznm::handleEraseCrdcmp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdcmps);
	return retval;
};

bool SessWznm::handleEraseCrdcon(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdcons);
	return retval;
};

bool SessWznm::handleEraseCrdctp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdctps);
	return retval;
};

bool SessWznm::handleEraseCrddlg(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crddlgs);
	return retval;
};

bool SessWznm::handleEraseCrderr(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crderrs);
	return retval;
};

bool SessWznm::handleEraseCrdevt(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdevts);
	return retval;
};

bool SessWznm::handleEraseCrdfil(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdfils);
	return retval;
};

bool SessWznm::handleEraseCrdiel(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdiels);
	return retval;
};

bool SessWznm::handleEraseCrdiex(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdiexs);
	return retval;
};

bool SessWznm::handleEraseCrdime(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdimes);
	return retval;
};

bool SessWznm::handleEraseCrdjob(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdjobs);
	return retval;
};

bool SessWznm::handleEraseCrdlib(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdlibs);
	return retval;
};

bool SessWznm::handleEraseCrdloc(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdlocs);
	return retval;
};

bool SessWznm::handleEraseCrdmch(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdmchs);
	return retval;
};

bool SessWznm::handleEraseCrdmdl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdmdls);
	return retval;
};

bool SessWznm::handleEraseCrdmtd(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdmtds);
	return retval;
};

bool SessWznm::handleEraseCrdopk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdopks);
	return retval;
};

bool SessWznm::handleEraseCrdopx(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdopxs);
	return retval;
};

bool SessWznm::handleEraseCrdpnl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdpnls);
	return retval;
};

bool SessWznm::handleEraseCrdprj(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdprjs);
	return retval;
};

bool SessWznm::handleEraseCrdprs(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdprss);
	return retval;
};

bool SessWznm::handleEraseCrdpst(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdpsts);
	return retval;
};

bool SessWznm::handleEraseCrdqco(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdqcos);
	return retval;
};

bool SessWznm::handleEraseCrdqmd(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdqmds);
	return retval;
};

bool SessWznm::handleEraseCrdqry(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdqrys);
	return retval;
};

bool SessWznm::handleEraseCrdrel(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdrels);
	return retval;
};

bool SessWznm::handleEraseCrdrls(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdrlss);
	return retval;
};

bool SessWznm::handleEraseCrdrtj(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdrtjs);
	return retval;
};

bool SessWznm::handleEraseCrdsbs(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdsbss);
	return retval;
};

bool SessWznm::handleEraseCrdseq(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdseqs);
	return retval;
};

bool SessWznm::handleEraseCrdsge(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdsges);
	return retval;
};

bool SessWznm::handleEraseCrdstb(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdstbs);
	return retval;
};

bool SessWznm::handleEraseCrdste(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdstes);
	return retval;
};

bool SessWznm::handleEraseCrdtag(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdtags);
	return retval;
};

bool SessWznm::handleEraseCrdtbl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdtbls);
	return retval;
};

bool SessWznm::handleEraseCrdtco(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdtcos);
	return retval;
};

bool SessWznm::handleEraseCrdusg(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdusgs);
	return retval;
};

bool SessWznm::handleEraseCrdusr(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdusrs);
	return retval;
};

bool SessWznm::handleEraseCrdutl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdutls);
	return retval;
};

bool SessWznm::handleEraseCrdvec(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdvecs);
	return retval;
};

bool SessWznm::handleEraseCrdver(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdvers);
	return retval;
};

bool SessWznm::handleEraseCrdvit(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	eraseCrd(crdvits);
	return retval;
};

void SessWznm::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	Feed feedFEnsSec("FeedFEnsSec");

	// resume session
	xchg->removePreset(VecWznmVPreset::PREWZNMSUSPSESS, jref);

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmPrs");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmFil");
	for (auto it = crdlocs.begin(); it != crdlocs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmLoc");
	for (auto it = crdtags.begin(); it != crdtags.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmTag");
	for (auto it = crdctps.begin(); it != crdctps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmCtp");
	for (auto it = crdmchs.begin(); it != crdmchs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmMch");
	for (auto it = crdlibs.begin(); it != crdlibs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmLib");
	for (auto it = crdprjs.begin(); it != crdprjs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmPrj");
	for (auto it = crdvers.begin(); it != crdvers.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmVer");
	for (auto it = crdcaps.begin(); it != crdcaps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmCap");
	for (auto it = crderrs.begin(); it != crderrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmErr");
	for (auto it = crdtbls.begin(); it != crdtbls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmTbl");
	for (auto it = crdtcos.begin(); it != crdtcos.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmTco");
	for (auto it = crdsbss.begin(); it != crdsbss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmSbs");
	for (auto it = crdrels.begin(); it != crdrels.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmRel");
	for (auto it = crdvecs.begin(); it != crdvecs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmVec");
	for (auto it = crdvits.begin(); it != crdvits.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmVit");
	for (auto it = crdchks.begin(); it != crdchks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmChk");
	for (auto it = crdstbs.begin(); it != crdstbs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmStb");
	for (auto it = crdiexs.begin(); it != crdiexs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmIex");
	for (auto it = crdimes.begin(); it != crdimes.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmIme");
	for (auto it = crdiels.begin(); it != crdiels.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmIel");
	for (auto it = crdpsts.begin(); it != crdpsts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmPst");
	for (auto it = crdmdls.begin(); it != crdmdls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmMdl");
	for (auto it = crdcars.begin(); it != crdcars.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmCar");
	for (auto it = crddlgs.begin(); it != crddlgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmDlg");
	for (auto it = crdpnls.begin(); it != crdpnls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmPnl");
	for (auto it = crdqrys.begin(); it != crdqrys.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmQry");
	for (auto it = crdqcos.begin(); it != crdqcos.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmQco");
	for (auto it = crdqmds.begin(); it != crdqmds.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmQmd");
	for (auto it = crdcons.begin(); it != crdcons.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmCon");
	for (auto it = crdopks.begin(); it != crdopks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmOpk");
	for (auto it = crdopxs.begin(); it != crdopxs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmOpx");
	for (auto it = crdjobs.begin(); it != crdjobs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmJob");
	for (auto it = crdsges.begin(); it != crdsges.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmSge");
	for (auto it = crdmtds.begin(); it != crdmtds.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmMtd");
	for (auto it = crdblks.begin(); it != crdblks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmBlk");
	for (auto it = crdcals.begin(); it != crdcals.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmCal");
	for (auto it = crdcmps.begin(); it != crdcmps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmCmp");
	for (auto it = crdrlss.begin(); it != crdrlss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmRls");
	for (auto it = crdapps.begin(); it != crdapps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmApp");
	for (auto it = crdrtjs.begin(); it != crdrtjs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmRtj");
	for (auto it = crdevts.begin(); it != crdevts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmEvt");
	for (auto it = crdseqs.begin(); it != crdseqs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmSeq");
	for (auto it = crdstes.begin(); it != crdstes.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmSte");
	for (auto it = crdutls.begin(); it != crdutls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble(it->second->jref), "CrdWznmUtl");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessWznm::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMREFPRESET) {
		call->abort = handleCallWznmRefPreSet(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRECACCESS) {
		call->abort = handleCallWznmRecaccess(dbswznm, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLOG) {
		call->abort = handleCallWznmLog(dbswznm, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCRDOPEN) {
		call->abort = handleCallWznmCrdOpen(dbswznm, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCRDCLOSE) {
		call->abort = handleCallWznmCrdClose(dbswznm, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCRDACTIVE) {
		call->abort = handleCallWznmCrdActive(dbswznm, call->jref, call->argInv.ix, call->argRet.ix);
	};
};

bool SessWznm::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallWznmRefPreSet --- BEGIN
	if (ixInv == VecWznmVPreset::PREWZNMJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngWznmSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if (ixInv == VecWznmVPreset::PREWZNMTLAST) {
		if (xchg->stgwznmappearance.sesstterm != 0) xchg->addRefPreset(ixInv, jref, refInv);

	} else if ((ixInv == VecWznmVPreset::PREWZNMREFAPP) || (ixInv == VecWznmVPreset::PREWZNMREFVER)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbswznm, ixInv, jrefTrig, true);
	};
// IP handleCallWznmRefPreSet --- END
	return retval;
};

bool SessWznm::handleCallWznmRecaccess(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkRecaccess(dbswznm, ixInv, refInv);
	return retval;
};

bool SessWznm::handleCallWznmLog(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logRecaccess(dbswznm, ixInv, refInv, VecWznmVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessWznm::handleCallWznmCrdOpen(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixWznmVCard = VecWznmVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixWznmVPreset;
	ubigint preUref = 0;

	uint ixWznmWAccess;
	uint ixWznmVRecaccess;

	if (hasActive(ixWznmVCard)) {
		if (ixInv == 0) {
			ixWznmVPreset = checkCrdActive(ixWznmVCard);
			if (ixWznmVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixWznmVPreset, jref);
			};

		} else {
			ixWznmVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixWznmWAccess = checkCrdaccess(ixWznmVCard);
		denied = (ixWznmWAccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixWznmWAccess & VecWznmWAccess::EDIT) == 0) || ((ixWznmWAccess & VecWznmWAccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixWznmVRecaccess = checkRecaccess(dbswznm, ixWznmVCard, intvalInv);
			denied = (ixWznmVRecaccess == VecWznmVRecaccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixWznmVCard == VecWznmVCard::CRDWZNMUSG) refRet = insertSubjob(crdusgs, new CrdWznmUsg(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMUSR) refRet = insertSubjob(crdusrs, new CrdWznmUsr(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRS) refRet = insertSubjob(crdprss, new CrdWznmPrs(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMFIL) refRet = insertSubjob(crdfils, new CrdWznmFil(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMLOC) refRet = insertSubjob(crdlocs, new CrdWznmLoc(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMTAG) refRet = insertSubjob(crdtags, new CrdWznmTag(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMCTP) refRet = insertSubjob(crdctps, new CrdWznmCtp(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMMCH) refRet = insertSubjob(crdmchs, new CrdWznmMch(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMLIB) refRet = insertSubjob(crdlibs, new CrdWznmLib(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRJ) refRet = insertSubjob(crdprjs, new CrdWznmPrj(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMVER) refRet = insertSubjob(crdvers, new CrdWznmVer(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAP) refRet = insertSubjob(crdcaps, new CrdWznmCap(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMERR) refRet = insertSubjob(crderrs, new CrdWznmErr(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMTBL) refRet = insertSubjob(crdtbls, new CrdWznmTbl(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMTCO) refRet = insertSubjob(crdtcos, new CrdWznmTco(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMSBS) refRet = insertSubjob(crdsbss, new CrdWznmSbs(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMREL) refRet = insertSubjob(crdrels, new CrdWznmRel(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMVEC) refRet = insertSubjob(crdvecs, new CrdWznmVec(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMVIT) refRet = insertSubjob(crdvits, new CrdWznmVit(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMCHK) refRet = insertSubjob(crdchks, new CrdWznmChk(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTB) refRet = insertSubjob(crdstbs, new CrdWznmStb(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEX) refRet = insertSubjob(crdiexs, new CrdWznmIex(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMIME) refRet = insertSubjob(crdimes, new CrdWznmIme(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEL) refRet = insertSubjob(crdiels, new CrdWznmIel(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMPST) refRet = insertSubjob(crdpsts, new CrdWznmPst(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMMDL) refRet = insertSubjob(crdmdls, new CrdWznmMdl(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAR) refRet = insertSubjob(crdcars, new CrdWznmCar(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMDLG) refRet = insertSubjob(crddlgs, new CrdWznmDlg(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMPNL) refRet = insertSubjob(crdpnls, new CrdWznmPnl(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMQRY) refRet = insertSubjob(crdqrys, new CrdWznmQry(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMQCO) refRet = insertSubjob(crdqcos, new CrdWznmQco(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMQMD) refRet = insertSubjob(crdqmds, new CrdWznmQmd(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMCON) refRet = insertSubjob(crdcons, new CrdWznmCon(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPK) refRet = insertSubjob(crdopks, new CrdWznmOpk(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPX) refRet = insertSubjob(crdopxs, new CrdWznmOpx(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMJOB) refRet = insertSubjob(crdjobs, new CrdWznmJob(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMSGE) refRet = insertSubjob(crdsges, new CrdWznmSge(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTD) refRet = insertSubjob(crdmtds, new CrdWznmMtd(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMBLK) refRet = insertSubjob(crdblks, new CrdWznmBlk(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAL) refRet = insertSubjob(crdcals, new CrdWznmCal(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMCMP) refRet = insertSubjob(crdcmps, new CrdWznmCmp(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMRLS) refRet = insertSubjob(crdrlss, new CrdWznmRls(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMAPP) refRet = insertSubjob(crdapps, new CrdWznmApp(xchg, dbswznm, jref, ixWznmVLocale, ref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMRTJ) refRet = insertSubjob(crdrtjs, new CrdWznmRtj(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMEVT) refRet = insertSubjob(crdevts, new CrdWznmEvt(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) refRet = insertSubjob(crdseqs, new CrdWznmSeq(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTE) refRet = insertSubjob(crdstes, new CrdWznmSte(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref));
		else if (ixWznmVCard == VecWznmVCard::CRDWZNMUTL) refRet = insertSubjob(crdutls, new CrdWznmUtl(xchg, dbswznm, jref, ixWznmVLocale));
	};

	return retval;
};

bool SessWznm::handleCallWznmCrdClose(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	// delete only if card is not part of a suspended session
	if (xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMSUSPSESS, jrefTrig)) return retval;

	ubigint jrefNotif = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecWznmVPreset::PREWZNMJREFNOTIFY, jref);

	if (ixInv == VecWznmVCard::CRDWZNMNAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} 
else if (ixInv == VecWznmVCard::CRDWZNMUSG) eraseSubjobByJref(crdusgs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMUSR) eraseSubjobByJref(crdusrs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMPRS) eraseSubjobByJref(crdprss, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMFIL) eraseSubjobByJref(crdfils, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMLOC) eraseSubjobByJref(crdlocs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMTAG) eraseSubjobByJref(crdtags, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMCTP) eraseSubjobByJref(crdctps, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMMCH) eraseSubjobByJref(crdmchs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMLIB) eraseSubjobByJref(crdlibs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMPRJ) eraseSubjobByJref(crdprjs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMVER) eraseSubjobByJref(crdvers, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMCAP) eraseSubjobByJref(crdcaps, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMERR) eraseSubjobByJref(crderrs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMTBL) eraseSubjobByJref(crdtbls, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMTCO) eraseSubjobByJref(crdtcos, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMSBS) eraseSubjobByJref(crdsbss, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMREL) eraseSubjobByJref(crdrels, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMVEC) eraseSubjobByJref(crdvecs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMVIT) eraseSubjobByJref(crdvits, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMCHK) eraseSubjobByJref(crdchks, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMSTB) eraseSubjobByJref(crdstbs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMIEX) eraseSubjobByJref(crdiexs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMIME) eraseSubjobByJref(crdimes, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMIEL) eraseSubjobByJref(crdiels, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMPST) eraseSubjobByJref(crdpsts, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMMDL) eraseSubjobByJref(crdmdls, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMCAR) eraseSubjobByJref(crdcars, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMDLG) eraseSubjobByJref(crddlgs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMPNL) eraseSubjobByJref(crdpnls, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMQRY) eraseSubjobByJref(crdqrys, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMQCO) eraseSubjobByJref(crdqcos, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMQMD) eraseSubjobByJref(crdqmds, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMCON) eraseSubjobByJref(crdcons, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMOPK) eraseSubjobByJref(crdopks, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMOPX) eraseSubjobByJref(crdopxs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMJOB) eraseSubjobByJref(crdjobs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMSGE) eraseSubjobByJref(crdsges, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMMTD) eraseSubjobByJref(crdmtds, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMBLK) eraseSubjobByJref(crdblks, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMCAL) eraseSubjobByJref(crdcals, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMCMP) eraseSubjobByJref(crdcmps, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMRLS) eraseSubjobByJref(crdrlss, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMAPP) eraseSubjobByJref(crdapps, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMRTJ) eraseSubjobByJref(crdrtjs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMEVT) eraseSubjobByJref(crdevts, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMSEQ) eraseSubjobByJref(crdseqs, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMSTE) eraseSubjobByJref(crdstes, jrefTrig);
	else if (ixInv == VecWznmVCard::CRDWZNMUTL) eraseSubjobByJref(crdutls, jrefTrig);
	return retval;
};

bool SessWznm::handleCallWznmCrdActive(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};
