/**
	* \file WznmGenBase.cpp
	* Wznm operation processor - generate version basics (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmGenBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmGen;

/******************************************************************************
 namespace WznmGenBase
 ******************************************************************************/

DpchRetWznm* WznmGenBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmGenBase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMVersion* ver;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	if (dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver)) {
		Wznm::getVerlclrefs(dbswznm, refWznmMVersion, refLcl, refsLcl);

		// generate navigator card
		genCrdnav(dbswznm, ver, Prjshort, refsLcl);

		// generate standard alerts
		genStdAlrs(dbswznm, ver, Prjshort, refLcl);

		// generate standard vectors
		genStdVecs(dbswznm, ver, Prjshort, refsLcl);

		// generate standard pre-selections
		genStdPres(dbswznm, ver, Prjshort);

		// generate standard query tables
		genStdQtbs(dbswznm, ver, Prjshort);

		// generate standard settings blocks
		genStdBlks(dbswznm, ver, Prjshort);

		delete ver;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmGenBase::genCrdnav(
			DbsWznm* dbswznm
			, WznmMVersion* ver
			, const string& Prjshort
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	WznmMModule* mdl = NULL;

	map<ubigint,string> tagTits;

	// navigation module
	dbswznm->tblwznmmmodule->insertNewRec(&mdl, ver->ref, 1, "Mdl" + Prjshort + "Nav", 0, "", "");

	// module title: from tag 'nav'
	Wznm::getTagtits(dbswznm, "nav", "", "", {}, ver->refWznmMLocale, refsLcl, tagTits, false);

	if (!tagTits.empty()) {
		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			ref = dbswznm->tblwznmjmmodule->insertNewRec(NULL, mdl->ref, refsLcl[i], tagTits[refsLcl[i]], "");

			if (refsLcl[i] == ver->refWznmMLocale) {
				mdl->refJ = ref;
				mdl->Title = tagTits[refsLcl[i]];
				dbswznm->tblwznmmmodule->updateRec(mdl);
			};
		};
	};

	// navigation card
	dbswznm->tblwznmmcard->insertNewRec(NULL, mdl->ref, 1, VecWznmVMCardRefTbl::VOID, 0, 0, "Crd" + Prjshort + "Nav");

	delete mdl;
};

void WznmGenBase::genStdAlrs(
			DbsWznm* dbswznm
			, WznmMVersion* ver
			, const string& Prjshort
			, const ubigint refLcl
		) {
	ubigint supref;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	unsigned int connum = 1;

	// AlrXxxxAbt (about)
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::ALR, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::VOID,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Alr" + Prjshort + "Abt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 1, VecWznmVMControlScope::SHR, 0, "TxtAbtCpt", VecWznmVMControlSubtype::VOID, "about", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MCB, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 2, VecWznmVMControlScope::SHR, 0, "McbAbt", VecWznmVMControlSubtype::VOID, "close", 0, "", 0, 0, 0, "", "", "cap");

	// AlrXxxxIer (import error)
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::ALR, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::VOID,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Alr" + Prjshort + "Ier", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 1, VecWznmVMControlScope::SHR, 0, "TxtIerCpt", VecWznmVMControlSubtype::VOID, "imperr", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::CONT,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 2, VecWznmVMControlScope::SHR, 0, "TxtIerMsg1", VecWznmVMControlSubtype::VOID, "", 0, "&iexsqk;", 0, 0, 0, "", "", "");

	con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, "&iexsqk;");
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MCB, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 3, VecWznmVMControlScope::SHR, 0, "McbIer", VecWznmVMControlSubtype::VOID, "cancel;reverse", 0, "", 0, 0, 0, "", "", "cap");

	// AlrXxxxPer (parse error)
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::ALR, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::VOID,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Alr" + Prjshort + "Per", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 1, VecWznmVMControlScope::SHR, 0, "TxtPerCpt", VecWznmVMControlSubtype::VOID, "prserr", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::CONT,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 2, VecWznmVMControlScope::SHR, 0, "TxtPerMsg1", VecWznmVMControlSubtype::VOID, "", 0, "&iexsqk;", 0, 0, 0, "", "", "");

	con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, "&iexsqk;");
	dbswznm->tblwznmmcontrol->updateRec(con);

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MCB, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 3, VecWznmVMControlScope::SHR, 0, "McbPer", VecWznmVMControlSubtype::VOID, "ok", 0, "", 0, 0, 0, "", "", "cap");

	// AlrXxxxSav (save changes)
	supref = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::ALR, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::VOID,
				VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0, VecWznmVMControlScope::SHR, 0, "Alr" + Prjshort + "Sav", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::HDR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 1, VecWznmVMControlScope::SHR, 0, "TxtSavCpt", VecWznmVMControlSubtype::VOID, "quest", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::CONT,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 2, VecWznmVMControlScope::SHR, 0, "TxtSavMsg1", VecWznmVMControlSubtype::VOID, "stdalr.sav", 0, "", 0, 0, 0, "", "", "cap");

	dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MCB, 0, VecWznmVMControlHkTbl::VER, ver->ref, connum++, VecWznmVMControlHkSection::FTR,
				VecWznmVMControlRefTbl::VOID, 0, supref, 1, 3, VecWznmVMControlScope::SHR, 0, "McbSav", VecWznmVMControlSubtype::VOID, "cancel;fls;tru", 0, "", 0, 0, 0, "", "", "cap");
};

void WznmGenBase::genStdVecs(
			DbsWznm* dbswznm
			, WznmMVersion* ver
			, const string& Prjshort
			, const vector<ubigint>& refsLcl
		) {
	ubigint ref;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	WznmMVectoritem* vit = NULL;

	map<ubigint,string> voidTits;
	map<ubigint,string> cardTits;

	string s;

	Wznm::getTagtits(dbswznm, "void", "", "", {}, ver->refWznmMLocale, refsLcl, voidTits, false);
	Wznm::getTagtits(dbswznm, "card", "stdvec", "", {}, ver->refWznmMLocale, refsLcl, cardTits, false);

	// -- vectors for filling lateron

	// - VecXxxxVCall (in WznmGenSysvec)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "call", "noloc;notit", refsLcl));

	// - VecXxxxVCard (in WznmGenSysvec)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "card", "filfed", refsLcl));

	// - VecXxxxVControl (in WznmGenSysvec)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "control", "noloc;notit", refsLcl));

	// - VecXxxxVDpch (in WznmGenSysvec)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "dpch", "noloc;notit", refsLcl));

	// - VecXxxxVFeatgroup (in WznmGenSysvec)
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "featgroup", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	// add item "VecXxxxVCard"
	dbswznm->tblwznmmvectoritem->insertNewRec(&vit, vec->ref, 1, "Vec" + Prjshort + "VCard", "", "", 0, "", "");

	if (!cardTits.empty()) {
		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refsLcl[i], cardTits[refsLcl[i]], "");

			if (refsLcl[i] == ver->refWznmMLocale) {
				vit->refJ = ref;
				vit->Title = cardTits[refsLcl[i]];
				dbswznm->tblwznmmvectoritem->updateRec(vit);
			};
		};
	};

	// - VecXxxxVJob (in WznmGenSysvec)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "job", "noloc;notit", refsLcl));

	// - VecXxxxVKeylist (in WznmComplDbs)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "keylist", "", refsLcl));

	// - VecXxxxVMaintable (in WznmComplDbs)
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "maintable", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	// add item "void"
	dbswznm->tblwznmmvectoritem->insertNewRec(&vit, vec->ref, 1, "void", "", "", 0, "", "");

	if (!voidTits.empty()) {
		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refsLcl[i], voidTits[refsLcl[i]], "");

			if (refsLcl[i] == ver->refWznmMLocale) {
				vit->refJ = ref;
				vit->Title = voidTits[refsLcl[i]];
				dbswznm->tblwznmmvectoritem->updateRec(vit);
			};
		};
	};

	// - VecXxxxVMimetype (in WznmGenSysvec)
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "mimetype", "noloc", refsLcl);
	vecs.nodes.push_back(vec);

	// - VecXxxxVOpengtype (in WznmGenSysvec)
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "opengtype", "apdfed;filfed", refsLcl);
	vecs.nodes.push_back(vec);

	// - VecXxxxVOppack (in WznmGenSysvec)
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "oppack", "apdfed;filfed;noloc;cmt", refsLcl);
	vecs.nodes.push_back(vec);

	// - VecXxxxVPreset (in WznmGenSysvec)
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "preset", "", refsLcl);
	vecs.nodes.push_back(vec);

	// add item "void"
	dbswznm->tblwznmmvectoritem->insertNewRec(&vit, vec->ref, 1, "void", "", "", 0, "", "");

	if (!voidTits.empty()) {
		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			ref = dbswznm->tblwznmjmvectoritem->insertNewRec(NULL, vit->ref, refsLcl[i], voidTits[refsLcl[i]], "");

			if (refsLcl[i] == ver->refWznmMLocale) {
				vit->refJ = ref;
				vit->Title = voidTits[refsLcl[i]];
				dbswznm->tblwznmmvectoritem->updateRec(vit);
			};
		};
	};

	// - VecXxxxVStub (in WznmGenSysvec)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "stub", "noloc;notit", refsLcl));

	// - VecXxxxVTag (in WznmGenSysvec)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "tag", "apdfed", refsLcl));

	// - VecXxxxVValuelist (in WznmComplDbs)
	vecs.nodes.push_back(genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "valuelist", "", refsLcl));

	// -- vectors to be filled now

	// - VecXxxxVError (more in WznmGenSysvec)
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "error", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "error", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVExpstate
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::JOB, Prjshort, "expstate", "noloc;notit", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "expstate", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVIop
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "iop", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "iop", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVLat
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "lat", "noloc;notit", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "lat", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVLocale
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "locale", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	fillVecLocale(dbswznm, vec->ref, ver->refWznmMLocale, refsLcl);

	// - VecXxxxVLop
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "lop", "noloc;notit", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "lop", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVOolop
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "oolop", "noloc;notit", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "oolop", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVQrystate
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::VOID, Prjshort, "qrystate", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "qrystate", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVRecaccess
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "recaccess", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "recaccess", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVReqitmode
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::JOB, Prjshort, "reqitmode", "noloc;notit", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "reqitmode", ver->refWznmMLocale, refsLcl);

	// - VecXxxxVUserlevel
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::LIN, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "userlevel", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "userlevel", ver->refWznmMLocale, refsLcl);

	// - VecXxxxWAccess
	vec = genStdvecEmpty(dbswznm, VecWznmVMVectorBasetype::OR, ver, VecWznmVMVectorHkTbl::TBL, Prjshort, "access", "filfed", refsLcl);
	vecs.nodes.push_back(vec);

	Wznm::fillVecFromTaggrp(dbswznm, vec, "access", ver->refWznmMLocale, refsLcl);
};

WznmMVector* WznmGenBase::genStdvecEmpty(
			DbsWznm* dbswznm
			, const uint ixVBasetype
			, WznmMVersion* ver
			, const uint hkIxVTbl
			, const string& Prjshort
			, const string& osrefWznmKTaggrp
			, const string& srefsKOption
			, const vector<ubigint>& refsLcl
		) {
	WznmMVector* vec = NULL;

	map<ubigint,string> tagTits;

	if (ixVBasetype == VecWznmVMVectorBasetype::LIN) {
		dbswznm->tblwznmmvector->insertNewRec(&vec, ixVBasetype, ver->ref, hkIxVTbl, 0, 0, "Vec" + Prjshort + "V" + StrMod::cap(osrefWznmKTaggrp), osrefWznmKTaggrp, srefsKOption);
	} else {
		dbswznm->tblwznmmvector->insertNewRec(&vec, ixVBasetype, ver->ref, hkIxVTbl, 0, 0, "Vec" + Prjshort + "W" + StrMod::cap(osrefWznmKTaggrp), osrefWznmKTaggrp, srefsKOption);
	};

	Wznm::getTagtits(dbswznm, osrefWznmKTaggrp, "stdvec", "", {}, ver->refWznmMLocale, refsLcl, tagTits, false);

	if (!tagTits.empty()) {
		for (unsigned int i = 0; i < refsLcl.size(); i++) {
			dbswznm->tblwznmamvectortitle->insertNewRec(NULL, vec->ref, VecWznmVAMVectorTitleType::FULL, refsLcl[i], tagTits[refsLcl[i]]);
		};
	};

	return vec;
};

void WznmGenBase::fillVecLocale(
			DbsWznm* dbswznm
			, const ubigint vecRefWznmMVector
			, const ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	string s;

	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	ListWznmJMVectoritem vijs;
	WznmJMVectoritem* vij = NULL;

	ListWznmMLocale lcls;
	WznmMLocale* lcl = NULL;

	// make sure default locale goes first
	dbswznm->tblwznmmlocale->loadRecByRef(refLcl, &lcl);
	lcls.nodes.push_back(lcl);

	for (unsigned int i = 0; i < refsLcl.size(); i++) {
		if (refsLcl[i] != refLcl) {
			dbswznm->tblwznmmlocale->loadRecByRef(refsLcl[i], &lcl);
			lcls.nodes.push_back(lcl);
		};
	};

	// one vector item for each locale
	for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
		lcl = lcls.nodes[i];

		vit = new WznmMVectoritem(0, vecRefWznmMVector, (i+1), lcl->sref, "", "", 0, "", "");

		dbswznm->tblwznmmvectoritem->insertRec(vit);
		vits.nodes.push_back(vit);

		// locales have localized titles (sic) ; copy only those which are relevant for the version
		for (unsigned int j = 0; j < refsLcl.size(); j++) {

			if (dbswznm->tblwznmjmlocaletitle->loadTitByLocLo2(lcl->ref, refsLcl[j], s)) {
				vij = new WznmJMVectoritem(0, vit->ref, refsLcl[j], s, "");
				dbswznm->tblwznmjmvectoritem->insertRec(vij); vijs.nodes.push_back(vij);

				if (refsLcl[j] == refLcl) {
					vit->refJ = vij->ref;
					vit->Title = vij->Title;
					dbswznm->tblwznmmvectoritem->updateRec(vit);
				};
			};
		};
	};
};

void WznmGenBase::genStdPres(
			DbsWznm* dbswznm
			, WznmMVersion* ver
			, const string& Prjshort
		) {
	ubigint refVec;

	// ... add titles here ...

	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SYS, "Pre" + Prjshort + "Sysdate", VecWznmWArgtype::INTVAL, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SYS, "Pre" + Prjshort + "Systime", VecWznmWArgtype::INTVAL, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SYS, "Pre" + Prjshort + "Sysstamp", VecWznmWArgtype::INTVAL, 0, "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(ver->ref) + " AND sref = 'Vec" + Prjshort + "VLocale'", refVec);
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VEC, refVec, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "IxLcl", VecWznmWArgtype::IX, 0, "");

	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "Admin", VecWznmWArgtype::BOOLVAL, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "Noadm", VecWznmWArgtype::BOOLVAL, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "Group", VecWznmWArgtype::REF, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "Owner", VecWznmWArgtype::REF, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "Sess", VecWznmWArgtype::REF, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "Ip", VecWznmWArgtype::TXTVAL, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "JrefNotify", VecWznmWArgtype::REF, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "JrefSess", VecWznmWArgtype::REF, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "Suspsess", VecWznmWArgtype::BOOLVAL, 0, "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(ver->ref) + " AND sref = 'Vec" + Prjshort + "VRecaccess'", refVec);
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VEC, refVec, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "IxRecacc", VecWznmWArgtype::IX, 0, "");

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(ver->ref) + " AND sref = 'Vec" + Prjshort + "VPreset'", refVec);
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VEC, refVec, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "IxPre", VecWznmWArgtype::IX, 0, "");

	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VOID, 0, VecWznmVMPresetScope::PNL, "Pre" + Prjshort + "RefSel", VecWznmWArgtype::REF, 0, "");
	dbswznm->tblwznmmpreset->insertNewRec(NULL, ver->ref, VecWznmVMPresetRefTbl::VEC, 0, VecWznmVMPresetScope::PNL, "Pre" + Prjshort + "IxOrd", VecWznmWArgtype::IX, 0, "");
};

void WznmGenBase::genStdQtbs(
			DbsWznm* dbswznm
			, WznmMVersion* ver
			, const string& Prjshort
		) {
	WznmMTable* tbl = NULL;

	// - TblXxxxQSelect
	dbswznm->tblwznmmtable->insertNewRec(&tbl, VecWznmVMTableBasetype::QRY, ver->ref, VecWznmVMTableRefTbl::VOID, 0, 0, 0, "Tbl" + Prjshort + "QSelect", "", "");

	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::IDREF, tbl->ref, 1, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "qref", "", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "");
	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::INTVAL, tbl->ref, 2, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "jref", "", VecWznmVMTablecolSubtype::UBIGINT, VecWznmVMTablecolAxisfct::VOID, "idx");
	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::ENUM, tbl->ref, 3, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "jnum", "", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "");
	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::VECREF, tbl->ref, 4, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "ix", "", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx");
	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::TBLREF, tbl->ref, 5, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "ref", "", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "");

	delete tbl;

	// - TblXxxxQPreselect
	dbswznm->tblwznmmtable->insertNewRec(&tbl, VecWznmVMTableBasetype::QRY, ver->ref, VecWznmVMTableRefTbl::VOID, 0, 0, 0, "Tbl" + Prjshort + "QPreselect", "", "");

	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::IDREF, tbl->ref, 1, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "qref", "", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "");
	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::INTVAL, tbl->ref, 2, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "jref", "", VecWznmVMTablecolSubtype::UBIGINT, VecWznmVMTablecolAxisfct::VOID, "idx");
	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::ENUM, tbl->ref, 3, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "jnum", "", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "");
	dbswznm->tblwznmmtablecol->insertNewRec(NULL, VecWznmVMTablecolBasetype::TBLREF, tbl->ref, 4, 0, 0, VecWznmVMTablecolFctTbl::VOID, 0, "ref", "", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "");

	delete tbl;
};

void WznmGenBase::genStdBlks(
			DbsWznm* dbswznm
			, WznmMVersion* ver
			, const string& Prjshort
		) {
	WznmMBlock* blk = NULL;

	unsigned int bitnum;

	// - blocks defined in Xxxx.h/.cpp
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::CONT, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::APP + VecWznmWScope::CMBENG + VecWznmWScope::ENG,
				VecWznmWScope::APP + VecWznmWScope::CMBENG + VecWznmWScope::ENG, "ContIac" + Prjshort + "Alert", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::CONT, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::APP, VecWznmWScope::CMBENG + VecWznmWScope::ENG,
				"ContInf" + Prjshort + "Alert", "");

	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::OPENG, VecWznmWScope::ENG, "DpchInv" + Prjshort, "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG, VecWznmWScope::OPENG, "DpchRet" + Prjshort, "");

	// - blocks defined in Xxxxd.h/.cpp, Xxxxcmbd.h/.cpp, Xxxxopd.h/.cpp
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG, VecWznmWScope::APP, "DpchApp" + Prjshort + "Alert", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG, VecWznmWScope::APP, "DpchApp" + Prjshort + "Init", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG, VecWznmWScope::APP, "DpchApp" + Prjshort + "Resume", "");

	// - blocks defined in Xxxxd.h/.cpp, Xxxxcmbd.h/.cpp
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::APP, VecWznmWScope::ENG + VecWznmWScope::CMBENG, "DpchEng" + Prjshort + "Ack", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::APP, VecWznmWScope::ENG + VecWznmWScope::CMBENG, "DpchEng" + Prjshort + "Alert", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::APP, VecWznmWScope::ENG + VecWznmWScope::CMBENG, "DpchEng" + Prjshort + "Confirm", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::APP, VecWznmWScope::ENG + VecWznmWScope::CMBENG, "DpchEng" + Prjshort + "Suspend", "");

	// - blocks defined in Xxxxd.h/.cpp, Xxxxopd.h/.cpp
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::OPENG, VecWznmWScope::ENG, "Dpch" + Prjshort + "dAck", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::OPENG, VecWznmWScope::ENG, "Dpch" + Prjshort + "dQuit", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::OPENG, VecWznmWScope::ENG, "Dpch" + Prjshort + "dReg", "");

	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG, VecWznmWScope::OPENG, "Dpch" + Prjshort + "opdReg", "");
	dbswznm->tblwznmmblock->insertNewRec(NULL, VecWznmVMBlockBasetype::DPCH, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG, VecWznmWScope::OPENG, "Dpch" + Prjshort + "opdUnreg", "");
};
// IP cust --- IEND



