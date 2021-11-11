/**
	* \file WznmCtpGenuiDbeterm.cpp
	* Wznm operation processor - add terminal panel (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpGenuiDbeterm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenui;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenuiDbeterm
 ******************************************************************************/

DpchRetWznmCtpGenui* WznmCtpGenuiDbeterm::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenui* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	WznmMCapability* cpb = NULL;

	ubigint refWznmMCard;
	uint carNum;

	ubigint refWznmMPanel;
	uint hkNum;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	ubigint refLcl;
	vector<ubigint> refsLcl;

	ubigint refSup;

	string s;

	if (dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb)) {
		if (dbswznm->loadRefBySQL("SELECT unvUref FROM TblWznmRMCapabilityUniversal WHERE refWznmMCapability = " + to_string(refWznmMCapability) + " AND srefKKey = 'car'", refWznmMCard)) {
			Wznm::getVerlclrefs(dbswznm, cpb->refWznmMVersion, refLcl, refsLcl);

			carNum = 1;
			if (dbswznm->tblwznmamcapabilitypar->loadValByCpbKey(refWznmMCapability, "carNum", s)) carNum = atoi(s.c_str());

			refWznmMPanel = dbswznm->tblwznmmpanel->insertNewRec(NULL, VecWznmVMPanelBasetype::FORM, refWznmMCard, carNum, VecWznmVMPanelRefTbl::VOID, 0, 0, cpb->sref, false, "", "");

			hkNum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::HDR, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "cpt", refLcl, refsLcl);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::HDR, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "ButClaim", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "custom()", "icon;onoff");

			refSup = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "TxtCst", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 1,
						VecWznmVMControlScope::APP, 0, "CptCst", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "cst", refLcl, refsLcl);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::APP, 0, "Sep1", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			refSup = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::HDG, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::APP, 0, "HdgDio", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "dio", refLcl, refsLcl);

			refSup = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CUS, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "CusDat", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, refSup, "height", 0, "200");
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 1,
						VecWznmVMControlScope::SHR, 0, "TxtDatLog", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::APP, 0, "Sep2", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			refSup = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::HDG, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::APP, 0, "HdgCex", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "cex", refLcl, refsLcl);

			refSup = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::PUP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "PupCmd", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			con->refWznmMFeed = dbswznm->tblwznmmfeed->insertNewRec(NULL, con->ref, VecWznmVMFeedSrcTbl::VOID, 0, "FeedFPupCmd", "", "", "");
			dbswznm->tblwznmmcontrol->updateRec(con);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 1,
						VecWznmVMControlScope::APP, 0, "CptCmd", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "cmd", refLcl, refsLcl);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 2,
						VecWznmVMControlScope::SHR, 0, "ButApd", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "apd", refLcl, refsLcl);

			refSup = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "TxfCsq", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "t");
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 1,
						VecWznmVMControlScope::APP, 0, "CptCsq", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "csq", refLcl, refsLcl);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "ButSmt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "custom()", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "smt", refLcl, refsLcl);
		};

		delete cpb;
	};
	// IP run --- IEND

	return(new DpchRetWznmCtpGenui("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
