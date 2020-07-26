/**
	* \file SessWznm.cpp
	* job handler for job SessWznm (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMMTY, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTY, jref, ixWznmWAccess);
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
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMSEQ, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMSTE, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref, ixWznmWAccess);
	ixWznmWAccess = ixWznmWAccessBase; if (!adm) getIxCrdacc(dbswznm, VecWznmVCard::CRDWZNMUTL, adm, urus, refWznmMUser, ixWznmWAccess); xchg->addIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUTL, jref, ixWznmWAccess);

	crdnav = new CrdWznmNav(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMLOG, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMRECACCESS, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

SessWznm::~SessWznm() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

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

uint SessWznm::checkCrdActive(
			const uint ixWznmVCard
		) {
	if (ixWznmVCard == VecWznmVCard::CRDWZNMVER) return evalCrdverActive();
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
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) return evalCrdseqActive();
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTE) return evalCrdsteActive();

	return 0;
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
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTY) return xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTY, jref);
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
	else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTY) return VecWznmVMaintable::TBLWZNMMMACHTYPE;
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
	else if (ixWznmVPreset == VecWznmVPreset::PREWZNMREFMTY) return VecWznmVMaintable::TBLWZNMMMACHTYPE;
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
	return((ixWznmVCard == VecWznmVCard::CRDWZNMVER) || (ixWznmVCard == VecWznmVCard::CRDWZNMCAP) || (ixWznmVCard == VecWznmVCard::CRDWZNMERR) || (ixWznmVCard == VecWznmVCard::CRDWZNMTBL) || (ixWznmVCard == VecWznmVCard::CRDWZNMTCO) || (ixWznmVCard == VecWznmVCard::CRDWZNMSBS) || (ixWznmVCard == VecWznmVCard::CRDWZNMREL) || (ixWznmVCard == VecWznmVCard::CRDWZNMVEC) || (ixWznmVCard == VecWznmVCard::CRDWZNMVIT) || (ixWznmVCard == VecWznmVCard::CRDWZNMCHK) || (ixWznmVCard == VecWznmVCard::CRDWZNMSTB) || (ixWznmVCard == VecWznmVCard::CRDWZNMIEX) || (ixWznmVCard == VecWznmVCard::CRDWZNMIME) || (ixWznmVCard == VecWznmVCard::CRDWZNMIEL) || (ixWznmVCard == VecWznmVCard::CRDWZNMPST) || (ixWznmVCard == VecWznmVCard::CRDWZNMMDL) || (ixWznmVCard == VecWznmVCard::CRDWZNMCAR) || (ixWznmVCard == VecWznmVCard::CRDWZNMDLG) || (ixWznmVCard == VecWznmVCard::CRDWZNMPNL) || (ixWznmVCard == VecWznmVCard::CRDWZNMQRY) || (ixWznmVCard == VecWznmVCard::CRDWZNMQCO) || (ixWznmVCard == VecWznmVCard::CRDWZNMQMD) || (ixWznmVCard == VecWznmVCard::CRDWZNMCON) || (ixWznmVCard == VecWznmVCard::CRDWZNMOPK) || (ixWznmVCard == VecWznmVCard::CRDWZNMOPX) || (ixWznmVCard == VecWznmVCard::CRDWZNMJOB) || (ixWznmVCard == VecWznmVCard::CRDWZNMSGE) || (ixWznmVCard == VecWznmVCard::CRDWZNMMTD) || (ixWznmVCard == VecWznmVCard::CRDWZNMBLK) || (ixWznmVCard == VecWznmVCard::CRDWZNMCAL) || (ixWznmVCard == VecWznmVCard::CRDWZNMCMP) || (ixWznmVCard == VecWznmVCard::CRDWZNMRLS) || (ixWznmVCard == VecWznmVCard::CRDWZNMRTJ) || (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) || (ixWznmVCard == VecWznmVCard::CRDWZNMSTE));
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
			cout << "\tcreateCrdmty" << endl;
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
			cout << "\teraseCrdmty" << endl;
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

		} else if (req->cmd == "createCrdmty") {
			req->retain = handleCreateCrdmty(dbswznm);

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

		} else if (req->cmd == "eraseCrdmty") {
			req->retain = handleEraseCrdmty(dbswznm);

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
	CrdWznmApp* crdapp = NULL;

	crdapp = new CrdWznmApp(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdapps.push_back(crdapp);
	cout << "\tjob reference: " << crdapp->jref << endl;
	xchg->jrefCmd = crdapp->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdblk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmBlk* crdblk = NULL;

	uint ixWznmVPreset = evalCrdblkActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdblk = new CrdWznmBlk(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdblks.push_back(crdblk);
		cout << "\tjob reference: " << crdblk->jref << endl;
		xchg->jrefCmd = crdblk->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdcal(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmCal* crdcal = NULL;

	uint ixWznmVPreset = evalCrdcalActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcal = new CrdWznmCal(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdcals.push_back(crdcal);
		cout << "\tjob reference: " << crdcal->jref << endl;
		xchg->jrefCmd = crdcal->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdcap(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmCap* crdcap = NULL;

	uint ixWznmVPreset = evalCrdcapActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcap = new CrdWznmCap(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdcaps.push_back(crdcap);
		cout << "\tjob reference: " << crdcap->jref << endl;
		xchg->jrefCmd = crdcap->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdcar(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmCar* crdcar = NULL;

	uint ixWznmVPreset = evalCrdcarActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcar = new CrdWznmCar(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdcars.push_back(crdcar);
		cout << "\tjob reference: " << crdcar->jref << endl;
		xchg->jrefCmd = crdcar->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdchk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmChk* crdchk = NULL;

	uint ixWznmVPreset = evalCrdchkActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdchk = new CrdWznmChk(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdchks.push_back(crdchk);
		cout << "\tjob reference: " << crdchk->jref << endl;
		xchg->jrefCmd = crdchk->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdcmp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmCmp* crdcmp = NULL;

	uint ixWznmVPreset = evalCrdcmpActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcmp = new CrdWznmCmp(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdcmps.push_back(crdcmp);
		cout << "\tjob reference: " << crdcmp->jref << endl;
		xchg->jrefCmd = crdcmp->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdcon(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmCon* crdcon = NULL;

	uint ixWznmVPreset = evalCrdconActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcon = new CrdWznmCon(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdcons.push_back(crdcon);
		cout << "\tjob reference: " << crdcon->jref << endl;
		xchg->jrefCmd = crdcon->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdctp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmCtp* crdctp = NULL;

	crdctp = new CrdWznmCtp(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdctps.push_back(crdctp);
	cout << "\tjob reference: " << crdctp->jref << endl;
	xchg->jrefCmd = crdctp->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrddlg(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmDlg* crddlg = NULL;

	uint ixWznmVPreset = evalCrddlgActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crddlg = new CrdWznmDlg(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crddlgs.push_back(crddlg);
		cout << "\tjob reference: " << crddlg->jref << endl;
		xchg->jrefCmd = crddlg->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrderr(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmErr* crderr = NULL;

	uint ixWznmVPreset = evalCrderrActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crderr = new CrdWznmErr(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crderrs.push_back(crderr);
		cout << "\tjob reference: " << crderr->jref << endl;
		xchg->jrefCmd = crderr->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdfil(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmFil* crdfil = NULL;

	crdfil = new CrdWznmFil(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdfils.push_back(crdfil);
	cout << "\tjob reference: " << crdfil->jref << endl;
	xchg->jrefCmd = crdfil->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdiel(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmIel* crdiel = NULL;

	uint ixWznmVPreset = evalCrdielActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdiel = new CrdWznmIel(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdiels.push_back(crdiel);
		cout << "\tjob reference: " << crdiel->jref << endl;
		xchg->jrefCmd = crdiel->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdiex(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmIex* crdiex = NULL;

	uint ixWznmVPreset = evalCrdiexActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdiex = new CrdWznmIex(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdiexs.push_back(crdiex);
		cout << "\tjob reference: " << crdiex->jref << endl;
		xchg->jrefCmd = crdiex->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdime(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmIme* crdime = NULL;

	uint ixWznmVPreset = evalCrdimeActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdime = new CrdWznmIme(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdimes.push_back(crdime);
		cout << "\tjob reference: " << crdime->jref << endl;
		xchg->jrefCmd = crdime->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdjob(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmJob* crdjob = NULL;

	uint ixWznmVPreset = evalCrdjobActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdjob = new CrdWznmJob(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdjobs.push_back(crdjob);
		cout << "\tjob reference: " << crdjob->jref << endl;
		xchg->jrefCmd = crdjob->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdlib(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmLib* crdlib = NULL;

	crdlib = new CrdWznmLib(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdlibs.push_back(crdlib);
	cout << "\tjob reference: " << crdlib->jref << endl;
	xchg->jrefCmd = crdlib->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdloc(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmLoc* crdloc = NULL;

	crdloc = new CrdWznmLoc(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdlocs.push_back(crdloc);
	cout << "\tjob reference: " << crdloc->jref << endl;
	xchg->jrefCmd = crdloc->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdmch(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmMch* crdmch = NULL;

	crdmch = new CrdWznmMch(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdmchs.push_back(crdmch);
	cout << "\tjob reference: " << crdmch->jref << endl;
	xchg->jrefCmd = crdmch->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdmdl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmMdl* crdmdl = NULL;

	uint ixWznmVPreset = evalCrdmdlActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdmdl = new CrdWznmMdl(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdmdls.push_back(crdmdl);
		cout << "\tjob reference: " << crdmdl->jref << endl;
		xchg->jrefCmd = crdmdl->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdmtd(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmMtd* crdmtd = NULL;

	uint ixWznmVPreset = evalCrdmtdActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdmtd = new CrdWznmMtd(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdmtds.push_back(crdmtd);
		cout << "\tjob reference: " << crdmtd->jref << endl;
		xchg->jrefCmd = crdmtd->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdmty(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmMty* crdmty = NULL;

	crdmty = new CrdWznmMty(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdmtys.push_back(crdmty);
	cout << "\tjob reference: " << crdmty->jref << endl;
	xchg->jrefCmd = crdmty->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdopk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmOpk* crdopk = NULL;

	uint ixWznmVPreset = evalCrdopkActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdopk = new CrdWznmOpk(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdopks.push_back(crdopk);
		cout << "\tjob reference: " << crdopk->jref << endl;
		xchg->jrefCmd = crdopk->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdopx(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmOpx* crdopx = NULL;

	uint ixWznmVPreset = evalCrdopxActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdopx = new CrdWznmOpx(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdopxs.push_back(crdopx);
		cout << "\tjob reference: " << crdopx->jref << endl;
		xchg->jrefCmd = crdopx->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdpnl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmPnl* crdpnl = NULL;

	uint ixWznmVPreset = evalCrdpnlActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdpnl = new CrdWznmPnl(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdpnls.push_back(crdpnl);
		cout << "\tjob reference: " << crdpnl->jref << endl;
		xchg->jrefCmd = crdpnl->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdprj(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmPrj* crdprj = NULL;

	crdprj = new CrdWznmPrj(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdprjs.push_back(crdprj);
	cout << "\tjob reference: " << crdprj->jref << endl;
	xchg->jrefCmd = crdprj->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdprs(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmPrs* crdprs = NULL;

	crdprs = new CrdWznmPrs(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdprss.push_back(crdprs);
	cout << "\tjob reference: " << crdprs->jref << endl;
	xchg->jrefCmd = crdprs->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdpst(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmPst* crdpst = NULL;

	uint ixWznmVPreset = evalCrdpstActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdpst = new CrdWznmPst(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdpsts.push_back(crdpst);
		cout << "\tjob reference: " << crdpst->jref << endl;
		xchg->jrefCmd = crdpst->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdqco(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmQco* crdqco = NULL;

	uint ixWznmVPreset = evalCrdqcoActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdqco = new CrdWznmQco(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdqcos.push_back(crdqco);
		cout << "\tjob reference: " << crdqco->jref << endl;
		xchg->jrefCmd = crdqco->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdqmd(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmQmd* crdqmd = NULL;

	uint ixWznmVPreset = evalCrdqmdActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdqmd = new CrdWznmQmd(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdqmds.push_back(crdqmd);
		cout << "\tjob reference: " << crdqmd->jref << endl;
		xchg->jrefCmd = crdqmd->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdqry(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmQry* crdqry = NULL;

	uint ixWznmVPreset = evalCrdqryActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdqry = new CrdWznmQry(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdqrys.push_back(crdqry);
		cout << "\tjob reference: " << crdqry->jref << endl;
		xchg->jrefCmd = crdqry->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdrel(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmRel* crdrel = NULL;

	uint ixWznmVPreset = evalCrdrelActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdrel = new CrdWznmRel(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdrels.push_back(crdrel);
		cout << "\tjob reference: " << crdrel->jref << endl;
		xchg->jrefCmd = crdrel->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdrls(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmRls* crdrls = NULL;

	uint ixWznmVPreset = evalCrdrlsActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdrls = new CrdWznmRls(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdrlss.push_back(crdrls);
		cout << "\tjob reference: " << crdrls->jref << endl;
		xchg->jrefCmd = crdrls->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdrtj(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmRtj* crdrtj = NULL;

	uint ixWznmVPreset = evalCrdrtjActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdrtj = new CrdWznmRtj(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdrtjs.push_back(crdrtj);
		cout << "\tjob reference: " << crdrtj->jref << endl;
		xchg->jrefCmd = crdrtj->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdsbs(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmSbs* crdsbs = NULL;

	uint ixWznmVPreset = evalCrdsbsActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdsbs = new CrdWznmSbs(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdsbss.push_back(crdsbs);
		cout << "\tjob reference: " << crdsbs->jref << endl;
		xchg->jrefCmd = crdsbs->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdseq(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmSeq* crdseq = NULL;

	uint ixWznmVPreset = evalCrdseqActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdseq = new CrdWznmSeq(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdseqs.push_back(crdseq);
		cout << "\tjob reference: " << crdseq->jref << endl;
		xchg->jrefCmd = crdseq->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdsge(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmSge* crdsge = NULL;

	uint ixWznmVPreset = evalCrdsgeActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdsge = new CrdWznmSge(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdsges.push_back(crdsge);
		cout << "\tjob reference: " << crdsge->jref << endl;
		xchg->jrefCmd = crdsge->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdstb(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmStb* crdstb = NULL;

	uint ixWznmVPreset = evalCrdstbActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdstb = new CrdWznmStb(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdstbs.push_back(crdstb);
		cout << "\tjob reference: " << crdstb->jref << endl;
		xchg->jrefCmd = crdstb->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdste(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmSte* crdste = NULL;

	uint ixWznmVPreset = evalCrdsteActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdste = new CrdWznmSte(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdstes.push_back(crdste);
		cout << "\tjob reference: " << crdste->jref << endl;
		xchg->jrefCmd = crdste->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdtag(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmTag* crdtag = NULL;

	crdtag = new CrdWznmTag(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdtags.push_back(crdtag);
	cout << "\tjob reference: " << crdtag->jref << endl;
	xchg->jrefCmd = crdtag->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdtbl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmTbl* crdtbl = NULL;

	uint ixWznmVPreset = evalCrdtblActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdtbl = new CrdWznmTbl(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdtbls.push_back(crdtbl);
		cout << "\tjob reference: " << crdtbl->jref << endl;
		xchg->jrefCmd = crdtbl->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdtco(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmTco* crdtco = NULL;

	uint ixWznmVPreset = evalCrdtcoActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdtco = new CrdWznmTco(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdtcos.push_back(crdtco);
		cout << "\tjob reference: " << crdtco->jref << endl;
		xchg->jrefCmd = crdtco->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdusg(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmUsg* crdusg = NULL;

	crdusg = new CrdWznmUsg(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdusgs.push_back(crdusg);
	cout << "\tjob reference: " << crdusg->jref << endl;
	xchg->jrefCmd = crdusg->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdusr(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmUsr* crdusr = NULL;

	crdusr = new CrdWznmUsr(xchg, dbswznm, jref, ixWznmVLocale, 0);
	crdusrs.push_back(crdusr);
	cout << "\tjob reference: " << crdusr->jref << endl;
	xchg->jrefCmd = crdusr->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdutl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmUtl* crdutl = NULL;

	crdutl = new CrdWznmUtl(xchg, dbswznm, jref, ixWznmVLocale);
	crdutls.push_back(crdutl);
	cout << "\tjob reference: " << crdutl->jref << endl;
	xchg->jrefCmd = crdutl->jref;

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdvec(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmVec* crdvec = NULL;

	uint ixWznmVPreset = evalCrdvecActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdvec = new CrdWznmVec(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdvecs.push_back(crdvec);
		cout << "\tjob reference: " << crdvec->jref << endl;
		xchg->jrefCmd = crdvec->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdver(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmVer* crdver = NULL;

	uint ixWznmVPreset = evalCrdverActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdver = new CrdWznmVer(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdvers.push_back(crdver);
		cout << "\tjob reference: " << crdver->jref << endl;
		xchg->jrefCmd = crdver->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleCreateCrdvit(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	CrdWznmVit* crdvit = NULL;

	uint ixWznmVPreset = evalCrdvitActive();

	if (ixWznmVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdvit = new CrdWznmVit(xchg, dbswznm, jref, ixWznmVLocale, 0, ixWznmVPreset, xchg->getRefPreset(ixWznmVPreset, jref));
		crdvits.push_back(crdvit);
		cout << "\tjob reference: " << crdvit->jref << endl;
		xchg->jrefCmd = crdvit->jref;
	};

	return false;
	return retval;
};

bool SessWznm::handleEraseCrdapp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmApp* crdapp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdapps.begin(); it != crdapps.end();) {
		crdapp = *it;
		if (crdapp->jref == iinput) {
			it = crdapps.erase(it);
			delete crdapp;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdblk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmBlk* crdblk = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdblks.begin(); it != crdblks.end();) {
		crdblk = *it;
		if (crdblk->jref == iinput) {
			it = crdblks.erase(it);
			delete crdblk;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdcal(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmCal* crdcal = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcals.begin(); it != crdcals.end();) {
		crdcal = *it;
		if (crdcal->jref == iinput) {
			it = crdcals.erase(it);
			delete crdcal;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdcap(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmCap* crdcap = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcaps.begin(); it != crdcaps.end();) {
		crdcap = *it;
		if (crdcap->jref == iinput) {
			it = crdcaps.erase(it);
			delete crdcap;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdcar(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmCar* crdcar = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcars.begin(); it != crdcars.end();) {
		crdcar = *it;
		if (crdcar->jref == iinput) {
			it = crdcars.erase(it);
			delete crdcar;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdchk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmChk* crdchk = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdchks.begin(); it != crdchks.end();) {
		crdchk = *it;
		if (crdchk->jref == iinput) {
			it = crdchks.erase(it);
			delete crdchk;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdcmp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmCmp* crdcmp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcmps.begin(); it != crdcmps.end();) {
		crdcmp = *it;
		if (crdcmp->jref == iinput) {
			it = crdcmps.erase(it);
			delete crdcmp;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdcon(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmCon* crdcon = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdcons.begin(); it != crdcons.end();) {
		crdcon = *it;
		if (crdcon->jref == iinput) {
			it = crdcons.erase(it);
			delete crdcon;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdctp(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmCtp* crdctp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdctps.begin(); it != crdctps.end();) {
		crdctp = *it;
		if (crdctp->jref == iinput) {
			it = crdctps.erase(it);
			delete crdctp;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrddlg(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmDlg* crddlg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crddlgs.begin(); it != crddlgs.end();) {
		crddlg = *it;
		if (crddlg->jref == iinput) {
			it = crddlgs.erase(it);
			delete crddlg;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrderr(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmErr* crderr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crderrs.begin(); it != crderrs.end();) {
		crderr = *it;
		if (crderr->jref == iinput) {
			it = crderrs.erase(it);
			delete crderr;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdfil(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmFil* crdfil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdfils.begin(); it != crdfils.end();) {
		crdfil = *it;
		if (crdfil->jref == iinput) {
			it = crdfils.erase(it);
			delete crdfil;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdiel(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmIel* crdiel = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdiels.begin(); it != crdiels.end();) {
		crdiel = *it;
		if (crdiel->jref == iinput) {
			it = crdiels.erase(it);
			delete crdiel;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdiex(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmIex* crdiex = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdiexs.begin(); it != crdiexs.end();) {
		crdiex = *it;
		if (crdiex->jref == iinput) {
			it = crdiexs.erase(it);
			delete crdiex;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdime(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmIme* crdime = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdimes.begin(); it != crdimes.end();) {
		crdime = *it;
		if (crdime->jref == iinput) {
			it = crdimes.erase(it);
			delete crdime;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdjob(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmJob* crdjob = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdjobs.begin(); it != crdjobs.end();) {
		crdjob = *it;
		if (crdjob->jref == iinput) {
			it = crdjobs.erase(it);
			delete crdjob;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdlib(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmLib* crdlib = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdlibs.begin(); it != crdlibs.end();) {
		crdlib = *it;
		if (crdlib->jref == iinput) {
			it = crdlibs.erase(it);
			delete crdlib;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdloc(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmLoc* crdloc = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdlocs.begin(); it != crdlocs.end();) {
		crdloc = *it;
		if (crdloc->jref == iinput) {
			it = crdlocs.erase(it);
			delete crdloc;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdmch(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmMch* crdmch = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdmchs.begin(); it != crdmchs.end();) {
		crdmch = *it;
		if (crdmch->jref == iinput) {
			it = crdmchs.erase(it);
			delete crdmch;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdmdl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmMdl* crdmdl = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdmdls.begin(); it != crdmdls.end();) {
		crdmdl = *it;
		if (crdmdl->jref == iinput) {
			it = crdmdls.erase(it);
			delete crdmdl;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdmtd(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmMtd* crdmtd = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdmtds.begin(); it != crdmtds.end();) {
		crdmtd = *it;
		if (crdmtd->jref == iinput) {
			it = crdmtds.erase(it);
			delete crdmtd;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdmty(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmMty* crdmty = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdmtys.begin(); it != crdmtys.end();) {
		crdmty = *it;
		if (crdmty->jref == iinput) {
			it = crdmtys.erase(it);
			delete crdmty;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdopk(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmOpk* crdopk = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdopks.begin(); it != crdopks.end();) {
		crdopk = *it;
		if (crdopk->jref == iinput) {
			it = crdopks.erase(it);
			delete crdopk;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdopx(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmOpx* crdopx = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdopxs.begin(); it != crdopxs.end();) {
		crdopx = *it;
		if (crdopx->jref == iinput) {
			it = crdopxs.erase(it);
			delete crdopx;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdpnl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmPnl* crdpnl = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdpnls.begin(); it != crdpnls.end();) {
		crdpnl = *it;
		if (crdpnl->jref == iinput) {
			it = crdpnls.erase(it);
			delete crdpnl;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdprj(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmPrj* crdprj = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdprjs.begin(); it != crdprjs.end();) {
		crdprj = *it;
		if (crdprj->jref == iinput) {
			it = crdprjs.erase(it);
			delete crdprj;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdprs(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmPrs* crdprs = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdprss.begin(); it != crdprss.end();) {
		crdprs = *it;
		if (crdprs->jref == iinput) {
			it = crdprss.erase(it);
			delete crdprs;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdpst(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmPst* crdpst = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdpsts.begin(); it != crdpsts.end();) {
		crdpst = *it;
		if (crdpst->jref == iinput) {
			it = crdpsts.erase(it);
			delete crdpst;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdqco(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmQco* crdqco = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdqcos.begin(); it != crdqcos.end();) {
		crdqco = *it;
		if (crdqco->jref == iinput) {
			it = crdqcos.erase(it);
			delete crdqco;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdqmd(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmQmd* crdqmd = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdqmds.begin(); it != crdqmds.end();) {
		crdqmd = *it;
		if (crdqmd->jref == iinput) {
			it = crdqmds.erase(it);
			delete crdqmd;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdqry(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmQry* crdqry = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdqrys.begin(); it != crdqrys.end();) {
		crdqry = *it;
		if (crdqry->jref == iinput) {
			it = crdqrys.erase(it);
			delete crdqry;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdrel(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmRel* crdrel = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdrels.begin(); it != crdrels.end();) {
		crdrel = *it;
		if (crdrel->jref == iinput) {
			it = crdrels.erase(it);
			delete crdrel;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdrls(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmRls* crdrls = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdrlss.begin(); it != crdrlss.end();) {
		crdrls = *it;
		if (crdrls->jref == iinput) {
			it = crdrlss.erase(it);
			delete crdrls;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdrtj(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmRtj* crdrtj = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdrtjs.begin(); it != crdrtjs.end();) {
		crdrtj = *it;
		if (crdrtj->jref == iinput) {
			it = crdrtjs.erase(it);
			delete crdrtj;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdsbs(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmSbs* crdsbs = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdsbss.begin(); it != crdsbss.end();) {
		crdsbs = *it;
		if (crdsbs->jref == iinput) {
			it = crdsbss.erase(it);
			delete crdsbs;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdseq(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmSeq* crdseq = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdseqs.begin(); it != crdseqs.end();) {
		crdseq = *it;
		if (crdseq->jref == iinput) {
			it = crdseqs.erase(it);
			delete crdseq;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdsge(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmSge* crdsge = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdsges.begin(); it != crdsges.end();) {
		crdsge = *it;
		if (crdsge->jref == iinput) {
			it = crdsges.erase(it);
			delete crdsge;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdstb(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmStb* crdstb = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdstbs.begin(); it != crdstbs.end();) {
		crdstb = *it;
		if (crdstb->jref == iinput) {
			it = crdstbs.erase(it);
			delete crdstb;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdste(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmSte* crdste = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdstes.begin(); it != crdstes.end();) {
		crdste = *it;
		if (crdste->jref == iinput) {
			it = crdstes.erase(it);
			delete crdste;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdtag(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmTag* crdtag = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdtags.begin(); it != crdtags.end();) {
		crdtag = *it;
		if (crdtag->jref == iinput) {
			it = crdtags.erase(it);
			delete crdtag;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdtbl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmTbl* crdtbl = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdtbls.begin(); it != crdtbls.end();) {
		crdtbl = *it;
		if (crdtbl->jref == iinput) {
			it = crdtbls.erase(it);
			delete crdtbl;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdtco(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmTco* crdtco = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdtcos.begin(); it != crdtcos.end();) {
		crdtco = *it;
		if (crdtco->jref == iinput) {
			it = crdtcos.erase(it);
			delete crdtco;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdusg(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmUsg* crdusg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdusgs.begin(); it != crdusgs.end();) {
		crdusg = *it;
		if (crdusg->jref == iinput) {
			it = crdusgs.erase(it);
			delete crdusg;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdusr(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmUsr* crdusr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdusrs.begin(); it != crdusrs.end();) {
		crdusr = *it;
		if (crdusr->jref == iinput) {
			it = crdusrs.erase(it);
			delete crdusr;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdutl(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmUtl* crdutl = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdutls.begin(); it != crdutls.end();) {
		crdutl = *it;
		if (crdutl->jref == iinput) {
			it = crdutls.erase(it);
			delete crdutl;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdvec(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmVec* crdvec = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdvecs.begin(); it != crdvecs.end();) {
		crdvec = *it;
		if (crdvec->jref == iinput) {
			it = crdvecs.erase(it);
			delete crdvec;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdver(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmVer* crdver = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdvers.begin(); it != crdvers.end();) {
		crdver = *it;
		if (crdver->jref == iinput) {
			it = crdvers.erase(it);
			delete crdver;
			break;
		} else it++;
	};

	return retval;
};

bool SessWznm::handleEraseCrdvit(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdWznmVit* crdvit = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = crdvits.begin(); it != crdvits.end();) {
		crdvit = *it;
		if (crdvit->jref == iinput) {
			it = crdvits.erase(it);
			delete crdvit;
			break;
		} else it++;
	};

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

	for (auto it = crdusgs.begin(); it != crdusgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmUsg");
	for (auto it = crdusrs.begin(); it != crdusrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmUsr");
	for (auto it = crdprss.begin(); it != crdprss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmPrs");
	for (auto it = crdfils.begin(); it != crdfils.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmFil");
	for (auto it = crdlocs.begin(); it != crdlocs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmLoc");
	for (auto it = crdtags.begin(); it != crdtags.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmTag");
	for (auto it = crdctps.begin(); it != crdctps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmCtp");
	for (auto it = crdmtys.begin(); it != crdmtys.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmMty");
	for (auto it = crdmchs.begin(); it != crdmchs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmMch");
	for (auto it = crdlibs.begin(); it != crdlibs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmLib");
	for (auto it = crdprjs.begin(); it != crdprjs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmPrj");
	for (auto it = crdvers.begin(); it != crdvers.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmVer");
	for (auto it = crdcaps.begin(); it != crdcaps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmCap");
	for (auto it = crderrs.begin(); it != crderrs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmErr");
	for (auto it = crdtbls.begin(); it != crdtbls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmTbl");
	for (auto it = crdtcos.begin(); it != crdtcos.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmTco");
	for (auto it = crdsbss.begin(); it != crdsbss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmSbs");
	for (auto it = crdrels.begin(); it != crdrels.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmRel");
	for (auto it = crdvecs.begin(); it != crdvecs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmVec");
	for (auto it = crdvits.begin(); it != crdvits.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmVit");
	for (auto it = crdchks.begin(); it != crdchks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmChk");
	for (auto it = crdstbs.begin(); it != crdstbs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmStb");
	for (auto it = crdiexs.begin(); it != crdiexs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmIex");
	for (auto it = crdimes.begin(); it != crdimes.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmIme");
	for (auto it = crdiels.begin(); it != crdiels.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmIel");
	for (auto it = crdpsts.begin(); it != crdpsts.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmPst");
	for (auto it = crdmdls.begin(); it != crdmdls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmMdl");
	for (auto it = crdcars.begin(); it != crdcars.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmCar");
	for (auto it = crddlgs.begin(); it != crddlgs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmDlg");
	for (auto it = crdpnls.begin(); it != crdpnls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmPnl");
	for (auto it = crdqrys.begin(); it != crdqrys.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmQry");
	for (auto it = crdqcos.begin(); it != crdqcos.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmQco");
	for (auto it = crdqmds.begin(); it != crdqmds.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmQmd");
	for (auto it = crdcons.begin(); it != crdcons.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmCon");
	for (auto it = crdopks.begin(); it != crdopks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmOpk");
	for (auto it = crdopxs.begin(); it != crdopxs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmOpx");
	for (auto it = crdjobs.begin(); it != crdjobs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmJob");
	for (auto it = crdsges.begin(); it != crdsges.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmSge");
	for (auto it = crdmtds.begin(); it != crdmtds.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmMtd");
	for (auto it = crdblks.begin(); it != crdblks.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmBlk");
	for (auto it = crdcals.begin(); it != crdcals.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmCal");
	for (auto it = crdcmps.begin(); it != crdcmps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmCmp");
	for (auto it = crdrlss.begin(); it != crdrlss.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmRls");
	for (auto it = crdapps.begin(); it != crdapps.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmApp");
	for (auto it = crdrtjs.begin(); it != crdrtjs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmRtj");
	for (auto it = crdseqs.begin(); it != crdseqs.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmSeq");
	for (auto it = crdstes.begin(); it != crdstes.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmSte");
	for (auto it = crdutls.begin(); it != crdutls.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), "CrdWznmUtl");

	*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});
};

void SessWznm::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMREFPRESET) {
		call->abort = handleCallWznmRefPreSet(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLOG) {
		call->abort = handleCallWznmLog(dbswznm, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMRECACCESS) {
		call->abort = handleCallWznmRecaccess(dbswznm, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCRDOPEN) {
		call->abort = handleCallWznmCrdOpen(dbswznm, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCRDACTIVE) {
		call->abort = handleCallWznmCrdActive(dbswznm, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMCRDCLOSE) {
		call->abort = handleCallWznmCrdClose(dbswznm, call->jref, call->argInv.ix);
	};
};

bool SessWznm::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	if (ixInv == VecWznmVPreset::PREWZNMJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngWznmSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if ((ixInv == VecWznmVPreset::PREWZNMREFAPP) || (ixInv == VecWznmVPreset::PREWZNMREFVER)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbswznm, ixInv, jrefTrig, true);
	};
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
		if (ixWznmVCard == VecWznmVCard::CRDWZNMUSG) {
			CrdWznmUsg* crdusg = NULL;

			crdusg = new CrdWznmUsg(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdusgs.push_back(crdusg);

			refRet = crdusg->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMUSR) {
			CrdWznmUsr* crdusr = NULL;

			crdusr = new CrdWznmUsr(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdusrs.push_back(crdusr);

			refRet = crdusr->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRS) {
			CrdWznmPrs* crdprs = NULL;

			crdprs = new CrdWznmPrs(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdprss.push_back(crdprs);

			refRet = crdprs->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMFIL) {
			CrdWznmFil* crdfil = NULL;

			crdfil = new CrdWznmFil(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdfils.push_back(crdfil);

			refRet = crdfil->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMNAV) {
		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMLOC) {
			CrdWznmLoc* crdloc = NULL;

			crdloc = new CrdWznmLoc(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdlocs.push_back(crdloc);

			refRet = crdloc->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMTAG) {
			CrdWznmTag* crdtag = NULL;

			crdtag = new CrdWznmTag(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdtags.push_back(crdtag);

			refRet = crdtag->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMCTP) {
			CrdWznmCtp* crdctp = NULL;

			crdctp = new CrdWznmCtp(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdctps.push_back(crdctp);

			refRet = crdctp->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTY) {
			CrdWznmMty* crdmty = NULL;

			crdmty = new CrdWznmMty(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdmtys.push_back(crdmty);

			refRet = crdmty->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMMCH) {
			CrdWznmMch* crdmch = NULL;

			crdmch = new CrdWznmMch(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdmchs.push_back(crdmch);

			refRet = crdmch->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMLIB) {
			CrdWznmLib* crdlib = NULL;

			crdlib = new CrdWznmLib(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdlibs.push_back(crdlib);

			refRet = crdlib->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMPRJ) {
			CrdWznmPrj* crdprj = NULL;

			crdprj = new CrdWznmPrj(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdprjs.push_back(crdprj);

			refRet = crdprj->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMVER) {
			CrdWznmVer* crdver = NULL;

			crdver = new CrdWznmVer(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdvers.push_back(crdver);

			refRet = crdver->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAP) {
			CrdWznmCap* crdcap = NULL;

			crdcap = new CrdWznmCap(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdcaps.push_back(crdcap);

			refRet = crdcap->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMERR) {
			CrdWznmErr* crderr = NULL;

			crderr = new CrdWznmErr(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crderrs.push_back(crderr);

			refRet = crderr->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMTBL) {
			CrdWznmTbl* crdtbl = NULL;

			crdtbl = new CrdWznmTbl(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdtbls.push_back(crdtbl);

			refRet = crdtbl->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMTCO) {
			CrdWznmTco* crdtco = NULL;

			crdtco = new CrdWznmTco(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdtcos.push_back(crdtco);

			refRet = crdtco->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMSBS) {
			CrdWznmSbs* crdsbs = NULL;

			crdsbs = new CrdWznmSbs(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdsbss.push_back(crdsbs);

			refRet = crdsbs->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMREL) {
			CrdWznmRel* crdrel = NULL;

			crdrel = new CrdWznmRel(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdrels.push_back(crdrel);

			refRet = crdrel->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMVEC) {
			CrdWznmVec* crdvec = NULL;

			crdvec = new CrdWznmVec(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdvecs.push_back(crdvec);

			refRet = crdvec->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMVIT) {
			CrdWznmVit* crdvit = NULL;

			crdvit = new CrdWznmVit(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdvits.push_back(crdvit);

			refRet = crdvit->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMCHK) {
			CrdWznmChk* crdchk = NULL;

			crdchk = new CrdWznmChk(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdchks.push_back(crdchk);

			refRet = crdchk->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTB) {
			CrdWznmStb* crdstb = NULL;

			crdstb = new CrdWznmStb(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdstbs.push_back(crdstb);

			refRet = crdstb->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEX) {
			CrdWznmIex* crdiex = NULL;

			crdiex = new CrdWznmIex(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdiexs.push_back(crdiex);

			refRet = crdiex->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMIME) {
			CrdWznmIme* crdime = NULL;

			crdime = new CrdWznmIme(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdimes.push_back(crdime);

			refRet = crdime->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMIEL) {
			CrdWznmIel* crdiel = NULL;

			crdiel = new CrdWznmIel(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdiels.push_back(crdiel);

			refRet = crdiel->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMPST) {
			CrdWznmPst* crdpst = NULL;

			crdpst = new CrdWznmPst(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdpsts.push_back(crdpst);

			refRet = crdpst->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMMDL) {
			CrdWznmMdl* crdmdl = NULL;

			crdmdl = new CrdWznmMdl(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdmdls.push_back(crdmdl);

			refRet = crdmdl->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAR) {
			CrdWznmCar* crdcar = NULL;

			crdcar = new CrdWznmCar(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdcars.push_back(crdcar);

			refRet = crdcar->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMDLG) {
			CrdWznmDlg* crddlg = NULL;

			crddlg = new CrdWznmDlg(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crddlgs.push_back(crddlg);

			refRet = crddlg->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMPNL) {
			CrdWznmPnl* crdpnl = NULL;

			crdpnl = new CrdWznmPnl(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdpnls.push_back(crdpnl);

			refRet = crdpnl->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMQRY) {
			CrdWznmQry* crdqry = NULL;

			crdqry = new CrdWznmQry(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdqrys.push_back(crdqry);

			refRet = crdqry->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMQCO) {
			CrdWznmQco* crdqco = NULL;

			crdqco = new CrdWznmQco(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdqcos.push_back(crdqco);

			refRet = crdqco->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMQMD) {
			CrdWznmQmd* crdqmd = NULL;

			crdqmd = new CrdWznmQmd(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdqmds.push_back(crdqmd);

			refRet = crdqmd->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMCON) {
			CrdWznmCon* crdcon = NULL;

			crdcon = new CrdWznmCon(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdcons.push_back(crdcon);

			refRet = crdcon->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPK) {
			CrdWznmOpk* crdopk = NULL;

			crdopk = new CrdWznmOpk(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdopks.push_back(crdopk);

			refRet = crdopk->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMOPX) {
			CrdWznmOpx* crdopx = NULL;

			crdopx = new CrdWznmOpx(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdopxs.push_back(crdopx);

			refRet = crdopx->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMJOB) {
			CrdWznmJob* crdjob = NULL;

			crdjob = new CrdWznmJob(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdjobs.push_back(crdjob);

			refRet = crdjob->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMSGE) {
			CrdWznmSge* crdsge = NULL;

			crdsge = new CrdWznmSge(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdsges.push_back(crdsge);

			refRet = crdsge->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMMTD) {
			CrdWznmMtd* crdmtd = NULL;

			crdmtd = new CrdWznmMtd(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdmtds.push_back(crdmtd);

			refRet = crdmtd->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMBLK) {
			CrdWznmBlk* crdblk = NULL;

			crdblk = new CrdWznmBlk(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdblks.push_back(crdblk);

			refRet = crdblk->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMCAL) {
			CrdWznmCal* crdcal = NULL;

			crdcal = new CrdWznmCal(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdcals.push_back(crdcal);

			refRet = crdcal->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMCMP) {
			CrdWznmCmp* crdcmp = NULL;

			crdcmp = new CrdWznmCmp(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdcmps.push_back(crdcmp);

			refRet = crdcmp->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMRLS) {
			CrdWznmRls* crdrls = NULL;

			crdrls = new CrdWznmRls(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdrlss.push_back(crdrls);

			refRet = crdrls->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMAPP) {
			CrdWznmApp* crdapp = NULL;

			crdapp = new CrdWznmApp(xchg, dbswznm, jref, ixWznmVLocale, ref);
			crdapps.push_back(crdapp);

			refRet = crdapp->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMRTJ) {
			CrdWznmRtj* crdrtj = NULL;

			crdrtj = new CrdWznmRtj(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdrtjs.push_back(crdrtj);

			refRet = crdrtj->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMSEQ) {
			CrdWznmSeq* crdseq = NULL;

			crdseq = new CrdWznmSeq(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdseqs.push_back(crdseq);

			refRet = crdseq->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMSTE) {
			CrdWznmSte* crdste = NULL;

			crdste = new CrdWznmSte(xchg, dbswznm, jref, ixWznmVLocale, ref, ixWznmVPreset, preUref);
			crdstes.push_back(crdste);

			refRet = crdste->jref;

		} else if (ixWznmVCard == VecWznmVCard::CRDWZNMUTL) {
			CrdWznmUtl* crdutl = NULL;

			crdutl = new CrdWznmUtl(xchg, dbswznm, jref, ixWznmVLocale);
			crdutls.push_back(crdutl);

			refRet = crdutl->jref;

		};
	};

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

	if (ixInv == VecWznmVCard::CRDWZNMUSG) {
		CrdWznmUsg* crdusg = NULL;

		for (auto it = crdusgs.begin(); it != crdusgs.end();) {
			crdusg = *it;
			if (crdusg->jref == jrefTrig) {
				it = crdusgs.erase(it);
				delete crdusg;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMUSR) {
		CrdWznmUsr* crdusr = NULL;

		for (auto it = crdusrs.begin(); it != crdusrs.end();) {
			crdusr = *it;
			if (crdusr->jref == jrefTrig) {
				it = crdusrs.erase(it);
				delete crdusr;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMPRS) {
		CrdWznmPrs* crdprs = NULL;

		for (auto it = crdprss.begin(); it != crdprss.end();) {
			crdprs = *it;
			if (crdprs->jref == jrefTrig) {
				it = crdprss.erase(it);
				delete crdprs;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMFIL) {
		CrdWznmFil* crdfil = NULL;

		for (auto it = crdfils.begin(); it != crdfils.end();) {
			crdfil = *it;
			if (crdfil->jref == jrefTrig) {
				it = crdfils.erase(it);
				delete crdfil;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMNAV) {
		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

	} else if (ixInv == VecWznmVCard::CRDWZNMLOC) {
		CrdWznmLoc* crdloc = NULL;

		for (auto it = crdlocs.begin(); it != crdlocs.end();) {
			crdloc = *it;
			if (crdloc->jref == jrefTrig) {
				it = crdlocs.erase(it);
				delete crdloc;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMTAG) {
		CrdWznmTag* crdtag = NULL;

		for (auto it = crdtags.begin(); it != crdtags.end();) {
			crdtag = *it;
			if (crdtag->jref == jrefTrig) {
				it = crdtags.erase(it);
				delete crdtag;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMCTP) {
		CrdWznmCtp* crdctp = NULL;

		for (auto it = crdctps.begin(); it != crdctps.end();) {
			crdctp = *it;
			if (crdctp->jref == jrefTrig) {
				it = crdctps.erase(it);
				delete crdctp;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMMTY) {
		CrdWznmMty* crdmty = NULL;

		for (auto it = crdmtys.begin(); it != crdmtys.end();) {
			crdmty = *it;
			if (crdmty->jref == jrefTrig) {
				it = crdmtys.erase(it);
				delete crdmty;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMMCH) {
		CrdWznmMch* crdmch = NULL;

		for (auto it = crdmchs.begin(); it != crdmchs.end();) {
			crdmch = *it;
			if (crdmch->jref == jrefTrig) {
				it = crdmchs.erase(it);
				delete crdmch;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMLIB) {
		CrdWznmLib* crdlib = NULL;

		for (auto it = crdlibs.begin(); it != crdlibs.end();) {
			crdlib = *it;
			if (crdlib->jref == jrefTrig) {
				it = crdlibs.erase(it);
				delete crdlib;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMPRJ) {
		CrdWznmPrj* crdprj = NULL;

		for (auto it = crdprjs.begin(); it != crdprjs.end();) {
			crdprj = *it;
			if (crdprj->jref == jrefTrig) {
				it = crdprjs.erase(it);
				delete crdprj;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMVER) {
		CrdWznmVer* crdver = NULL;

		for (auto it = crdvers.begin(); it != crdvers.end();) {
			crdver = *it;
			if (crdver->jref == jrefTrig) {
				it = crdvers.erase(it);
				delete crdver;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMCAP) {
		CrdWznmCap* crdcap = NULL;

		for (auto it = crdcaps.begin(); it != crdcaps.end();) {
			crdcap = *it;
			if (crdcap->jref == jrefTrig) {
				it = crdcaps.erase(it);
				delete crdcap;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMERR) {
		CrdWznmErr* crderr = NULL;

		for (auto it = crderrs.begin(); it != crderrs.end();) {
			crderr = *it;
			if (crderr->jref == jrefTrig) {
				it = crderrs.erase(it);
				delete crderr;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMTBL) {
		CrdWznmTbl* crdtbl = NULL;

		for (auto it = crdtbls.begin(); it != crdtbls.end();) {
			crdtbl = *it;
			if (crdtbl->jref == jrefTrig) {
				it = crdtbls.erase(it);
				delete crdtbl;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMTCO) {
		CrdWznmTco* crdtco = NULL;

		for (auto it = crdtcos.begin(); it != crdtcos.end();) {
			crdtco = *it;
			if (crdtco->jref == jrefTrig) {
				it = crdtcos.erase(it);
				delete crdtco;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMSBS) {
		CrdWznmSbs* crdsbs = NULL;

		for (auto it = crdsbss.begin(); it != crdsbss.end();) {
			crdsbs = *it;
			if (crdsbs->jref == jrefTrig) {
				it = crdsbss.erase(it);
				delete crdsbs;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMREL) {
		CrdWznmRel* crdrel = NULL;

		for (auto it = crdrels.begin(); it != crdrels.end();) {
			crdrel = *it;
			if (crdrel->jref == jrefTrig) {
				it = crdrels.erase(it);
				delete crdrel;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMVEC) {
		CrdWznmVec* crdvec = NULL;

		for (auto it = crdvecs.begin(); it != crdvecs.end();) {
			crdvec = *it;
			if (crdvec->jref == jrefTrig) {
				it = crdvecs.erase(it);
				delete crdvec;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMVIT) {
		CrdWznmVit* crdvit = NULL;

		for (auto it = crdvits.begin(); it != crdvits.end();) {
			crdvit = *it;
			if (crdvit->jref == jrefTrig) {
				it = crdvits.erase(it);
				delete crdvit;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMCHK) {
		CrdWznmChk* crdchk = NULL;

		for (auto it = crdchks.begin(); it != crdchks.end();) {
			crdchk = *it;
			if (crdchk->jref == jrefTrig) {
				it = crdchks.erase(it);
				delete crdchk;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMSTB) {
		CrdWznmStb* crdstb = NULL;

		for (auto it = crdstbs.begin(); it != crdstbs.end();) {
			crdstb = *it;
			if (crdstb->jref == jrefTrig) {
				it = crdstbs.erase(it);
				delete crdstb;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMIEX) {
		CrdWznmIex* crdiex = NULL;

		for (auto it = crdiexs.begin(); it != crdiexs.end();) {
			crdiex = *it;
			if (crdiex->jref == jrefTrig) {
				it = crdiexs.erase(it);
				delete crdiex;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMIME) {
		CrdWznmIme* crdime = NULL;

		for (auto it = crdimes.begin(); it != crdimes.end();) {
			crdime = *it;
			if (crdime->jref == jrefTrig) {
				it = crdimes.erase(it);
				delete crdime;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMIEL) {
		CrdWznmIel* crdiel = NULL;

		for (auto it = crdiels.begin(); it != crdiels.end();) {
			crdiel = *it;
			if (crdiel->jref == jrefTrig) {
				it = crdiels.erase(it);
				delete crdiel;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMPST) {
		CrdWznmPst* crdpst = NULL;

		for (auto it = crdpsts.begin(); it != crdpsts.end();) {
			crdpst = *it;
			if (crdpst->jref == jrefTrig) {
				it = crdpsts.erase(it);
				delete crdpst;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMMDL) {
		CrdWznmMdl* crdmdl = NULL;

		for (auto it = crdmdls.begin(); it != crdmdls.end();) {
			crdmdl = *it;
			if (crdmdl->jref == jrefTrig) {
				it = crdmdls.erase(it);
				delete crdmdl;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMCAR) {
		CrdWznmCar* crdcar = NULL;

		for (auto it = crdcars.begin(); it != crdcars.end();) {
			crdcar = *it;
			if (crdcar->jref == jrefTrig) {
				it = crdcars.erase(it);
				delete crdcar;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMDLG) {
		CrdWznmDlg* crddlg = NULL;

		for (auto it = crddlgs.begin(); it != crddlgs.end();) {
			crddlg = *it;
			if (crddlg->jref == jrefTrig) {
				it = crddlgs.erase(it);
				delete crddlg;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMPNL) {
		CrdWznmPnl* crdpnl = NULL;

		for (auto it = crdpnls.begin(); it != crdpnls.end();) {
			crdpnl = *it;
			if (crdpnl->jref == jrefTrig) {
				it = crdpnls.erase(it);
				delete crdpnl;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMQRY) {
		CrdWznmQry* crdqry = NULL;

		for (auto it = crdqrys.begin(); it != crdqrys.end();) {
			crdqry = *it;
			if (crdqry->jref == jrefTrig) {
				it = crdqrys.erase(it);
				delete crdqry;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMQCO) {
		CrdWznmQco* crdqco = NULL;

		for (auto it = crdqcos.begin(); it != crdqcos.end();) {
			crdqco = *it;
			if (crdqco->jref == jrefTrig) {
				it = crdqcos.erase(it);
				delete crdqco;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMQMD) {
		CrdWznmQmd* crdqmd = NULL;

		for (auto it = crdqmds.begin(); it != crdqmds.end();) {
			crdqmd = *it;
			if (crdqmd->jref == jrefTrig) {
				it = crdqmds.erase(it);
				delete crdqmd;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMCON) {
		CrdWznmCon* crdcon = NULL;

		for (auto it = crdcons.begin(); it != crdcons.end();) {
			crdcon = *it;
			if (crdcon->jref == jrefTrig) {
				it = crdcons.erase(it);
				delete crdcon;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMOPK) {
		CrdWznmOpk* crdopk = NULL;

		for (auto it = crdopks.begin(); it != crdopks.end();) {
			crdopk = *it;
			if (crdopk->jref == jrefTrig) {
				it = crdopks.erase(it);
				delete crdopk;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMOPX) {
		CrdWznmOpx* crdopx = NULL;

		for (auto it = crdopxs.begin(); it != crdopxs.end();) {
			crdopx = *it;
			if (crdopx->jref == jrefTrig) {
				it = crdopxs.erase(it);
				delete crdopx;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMJOB) {
		CrdWznmJob* crdjob = NULL;

		for (auto it = crdjobs.begin(); it != crdjobs.end();) {
			crdjob = *it;
			if (crdjob->jref == jrefTrig) {
				it = crdjobs.erase(it);
				delete crdjob;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMSGE) {
		CrdWznmSge* crdsge = NULL;

		for (auto it = crdsges.begin(); it != crdsges.end();) {
			crdsge = *it;
			if (crdsge->jref == jrefTrig) {
				it = crdsges.erase(it);
				delete crdsge;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMMTD) {
		CrdWznmMtd* crdmtd = NULL;

		for (auto it = crdmtds.begin(); it != crdmtds.end();) {
			crdmtd = *it;
			if (crdmtd->jref == jrefTrig) {
				it = crdmtds.erase(it);
				delete crdmtd;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMBLK) {
		CrdWznmBlk* crdblk = NULL;

		for (auto it = crdblks.begin(); it != crdblks.end();) {
			crdblk = *it;
			if (crdblk->jref == jrefTrig) {
				it = crdblks.erase(it);
				delete crdblk;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMCAL) {
		CrdWznmCal* crdcal = NULL;

		for (auto it = crdcals.begin(); it != crdcals.end();) {
			crdcal = *it;
			if (crdcal->jref == jrefTrig) {
				it = crdcals.erase(it);
				delete crdcal;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMCMP) {
		CrdWznmCmp* crdcmp = NULL;

		for (auto it = crdcmps.begin(); it != crdcmps.end();) {
			crdcmp = *it;
			if (crdcmp->jref == jrefTrig) {
				it = crdcmps.erase(it);
				delete crdcmp;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMRLS) {
		CrdWznmRls* crdrls = NULL;

		for (auto it = crdrlss.begin(); it != crdrlss.end();) {
			crdrls = *it;
			if (crdrls->jref == jrefTrig) {
				it = crdrlss.erase(it);
				delete crdrls;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMAPP) {
		CrdWznmApp* crdapp = NULL;

		for (auto it = crdapps.begin(); it != crdapps.end();) {
			crdapp = *it;
			if (crdapp->jref == jrefTrig) {
				it = crdapps.erase(it);
				delete crdapp;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMRTJ) {
		CrdWznmRtj* crdrtj = NULL;

		for (auto it = crdrtjs.begin(); it != crdrtjs.end();) {
			crdrtj = *it;
			if (crdrtj->jref == jrefTrig) {
				it = crdrtjs.erase(it);
				delete crdrtj;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMSEQ) {
		CrdWznmSeq* crdseq = NULL;

		for (auto it = crdseqs.begin(); it != crdseqs.end();) {
			crdseq = *it;
			if (crdseq->jref == jrefTrig) {
				it = crdseqs.erase(it);
				delete crdseq;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMSTE) {
		CrdWznmSte* crdste = NULL;

		for (auto it = crdstes.begin(); it != crdstes.end();) {
			crdste = *it;
			if (crdste->jref == jrefTrig) {
				it = crdstes.erase(it);
				delete crdste;
				break;
			} else it++;
		};
	} else if (ixInv == VecWznmVCard::CRDWZNMUTL) {
		CrdWznmUtl* crdutl = NULL;

		for (auto it = crdutls.begin(); it != crdutls.end();) {
			crdutl = *it;
			if (crdutl->jref == jrefTrig) {
				it = crdutls.erase(it);
				delete crdutl;
				break;
			} else it++;
		};
	};
	return retval;
};

