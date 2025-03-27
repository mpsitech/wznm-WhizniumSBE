/**
	* \file WznmCtpGenuiPrefs.cpp
	* Wznm operation processor - add preferences panels (implementation)
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

#include "WznmCtpGenuiPrefs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenui;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenuiPrefs
 ******************************************************************************/

DpchRetWznmCtpGenui* WznmCtpGenuiPrefs::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenui* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	ubigint ref;
	set<ubigint> unqrefs, unqrefs2;

	WznmMCapability* cpb = NULL;

	const string Crdshort = "Prf";
	ubigint refWznmMCard;
	uint carNum;

	ubigint refWznmMPanel;
	uint hkNum;

	unsigned int pnlsectNum;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	ListWznmAMBlockItem bits;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ubigint refLcl;
	vector<ubigint> refsLcl;

	map<ubigint,string> plhs; // by locale (used to append " settings" to panel / heading caption)

	ubigint refSup;
	string Avail;

	vector<string> stdsrefs;

	map<ubigint,string> tagTits;

	vector<unsigned int> mitlens;
	unsigned int mitlen;

	string s;

	bool found;

	if (dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb)) {
		if (dbswznm->loadRefBySQL("SELECT TblWznmMCard.ref FROM TblWznmMModule, TblWznmMCard WHERE TblWznmMModule.verRefWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref AND TblWznmMCard.sref = 'Crd" + Prjshort + Crdshort + "'", refWznmMCard)) {
			Wznm::getVerlclrefs(dbswznm, cpb->refWznmMVersion, refLcl, refsLcl);

			if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTag WHERE refWznmMCapability = " + to_string(cpb->tplRefWznmMCapability) + " AND sref = 'stg'", ref))
				for (unsigned int i = 0; i < refsLcl.size(); i++) if (dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(ref, refLcl, s)) plhs[refsLcl[i]] = s;

			// - menu
			hkNum = 1;
			if (dbswznm->loadUintBySQL("SELECT hkNum FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(refWznmMCard) + " ORDER BY hkNum DESC LIMIT 1", hkNum)) hkNum++;

			refSup = dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MEN, 0, VecWznmVMControlHkTbl::CAR, refWznmMCard, hkNum++, VecWznmVMControlHkSection::MBAR, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::APP, 0, "MenCrd", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "pref", refLcl, refsLcl);

			Wznm::getTagtits(dbswznm, cpb->tplRefWznmMCapability, "pref", "", "", {}, refLcl, refsLcl, tagTits, false);
			for (unsigned int i = 0; i < refsLcl.size(); i++) dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, refSup, "cptwidth", refsLcl[i], to_string(StrMod::getCharcnt(tagTits[refsLcl[i]])*9 + 10));

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, refWznmMCard, hkNum++, VecWznmVMControlHkSection::MBAR,
						VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 1, VecWznmVMControlScope::APP, 0, "MspCrd1", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			mitlens.resize(refsLcl.size(), 0);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MIT, 0, VecWznmVMControlHkTbl::CAR, refWznmMCard, hkNum++, VecWznmVMControlHkSection::MBAR, VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 2,
						VecWznmVMControlScope::SHR, 0, "MitCrdRvr", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "revert", refLcl, refsLcl);

			Wznm::getTagtits(dbswznm, cpb->tplRefWznmMCapability, "revert", "", "", {}, refLcl, refsLcl, tagTits, false);
			for (unsigned int i = 0; i < refsLcl.size(); i++) {
				mitlen = StrMod::getCharcnt(tagTits[refsLcl[i]])*7 + 8;
				if (mitlen > mitlens[i]) mitlens[i] = mitlen;
			};

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MIT, 0, VecWznmVMControlHkTbl::CAR, refWznmMCard, hkNum++, VecWznmVMControlHkSection::MBAR, VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 3,
						VecWznmVMControlScope::SHR, 0, "MitCrdSto", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "store", refLcl, refsLcl);

			for (unsigned int i = 0; i < refsLcl.size(); i++) dbswznm->tblwznmamcontrolpar->insertNewRec(NULL, refSup, "width", refsLcl[i], to_string(mitlens[i]));

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::MSP, 0, VecWznmVMControlHkTbl::CAR, refWznmMCard, hkNum++, VecWznmVMControlHkSection::MBAR,
						VecWznmVMControlRefTbl::VOID, 0, refSup, 1, 4, VecWznmVMControlScope::APP, 0, "MspCrd2", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");

			// - daemon settings (standard blocks cf. WznmComplDeploy)
			carNum = 1;

			refWznmMPanel = dbswznm->tblwznmmpanel->insertNewRec(NULL, VecWznmVMPanelBasetype::FORM, refWznmMCard, carNum++, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + Prjshort + Crdshort + "Daemon", false, "", "");

			hkNum = 1;

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::HDR, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
			addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "d", refLcl, refsLcl, "&tag; &plh;", plhs);

			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");
			dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
						VecWznmVMControlScope::SHR, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
						+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", false, blks);

			stdsrefs = {"Behavior", "Appsrv", "d", "cmbd", "Database", "Path", "Tenant", "Monitor", "Ddspub", "Uasrv"};

			unqrefs.clear();

			for (unsigned int i = 0; i < stdsrefs.size(); i++) {
				s = "Stg" + Prjshort + stdsrefs[i];

				found = false;

				for (unsigned int j = 0; j < blks.nodes.size(); j++) {
					blk = blks.nodes[j];

					if (blk->sref == s) {
						found = true;
						break;
					};
				};

				if (found) {
					pnlsectNum = 100*unqrefs.size() + 1;

					if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) Avail = "!cmbdNotD()";
					else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) Avail = "cmbdNotD()";
					else Avail = "";

					if (!unqrefs.empty()) {
						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
									VecWznmVMControlScope::APP, 0, "Sep" + to_string(unqrefs.size()), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "");
					};

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::HDG, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::APP, 0, "Hdg" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "");
					addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, StrMod::uncap(stdsrefs[i]), refLcl, refsLcl);

					dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);
					addBitcons(dbswznm, bits, cons, refWznmMPanel, hkNum, Avail, pnlsectNum, refLcl);
					unqrefs.insert(blk->ref);
				};
			};

			if (unqrefs.size() != blks.nodes.size()) {
				// - global settings
				refWznmMPanel = dbswznm->tblwznmmpanel->insertNewRec(NULL, VecWznmVMPanelBasetype::FORM, refWznmMCard, carNum++, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + Prjshort + Crdshort + "Global", false, "", "");

				hkNum = 1;

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::HDR, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
							VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
				addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "global", refLcl, refsLcl, "&tag; &plh;", plhs);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
							VecWznmVMControlScope::SHR, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");
				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
							VecWznmVMControlScope::SHR, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

				unqrefs2.clear();

				for (unsigned int i = 0; i < blks.nodes.size(); i++) {
					blk = blks.nodes[i];

					if (unqrefs.find(blk->ref) == unqrefs.end()) {
						pnlsectNum = 100*unqrefs2.size() + 1;

						if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) Avail = "!cmbdNotD()";
						else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) Avail = "cmbdNotD()";
						else Avail = "";

						if (!unqrefs2.empty()) {
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
										VecWznmVMControlScope::APP, 0, "Sep" + to_string(unqrefs2.size()), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "");
						};

						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::HDG, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
									VecWznmVMControlScope::APP, 0, "Hdg" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, blk->sref, 0, 0, 0, Avail, "", "");
						con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, blk->sref);
						dbswznm->tblwznmmcontrol->updateRec(con);

						dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);
						addBitcons(dbswznm, bits, cons, refWznmMPanel, hkNum, Avail, pnlsectNum, refLcl);

						unqrefs2.insert(blk->ref);
					};
				};
			};

			// - job-specific settings
			plhs.clear();

			dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ref IN (SELECT DISTINCT refUref FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion)
						+ " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG)
						+ ") <> 0 AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = 0) ORDER BY sref ASC", false, jobs);

			for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
				job = jobs.nodes[i];

				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
							+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 AND (reaIxWznmWScope & "
							+ to_string(VecWznmWScope::APP) + ") = 0 ORDER BY sref ASC", false, blks);

				refWznmMPanel = dbswznm->tblwznmmpanel->insertNewRec(NULL, VecWznmVMPanelBasetype::FORM, refWznmMCard, carNum++, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + Prjshort + Crdshort + job->sref.substr(3+4), false, "", "");

				hkNum = 1;

				plhs[refLcl] = job->sref;

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::HDR, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
							VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
				addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "stg", refLcl, refsLcl, "&plh; &tag;", plhs);

				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
							VecWznmVMControlScope::SHR, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");
				dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
							VecWznmVMControlScope::SHR, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

				for (unsigned int j = 0; j < blks.nodes.size(); j++) {
					blk = blks.nodes[j];

					pnlsectNum = 100*j + 1;

					if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) Avail = "!cmbdNotD()";
					else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) Avail = "cmbdNotD()";
					else Avail = "";

					if (j != 0)
						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
									VecWznmVMControlScope::APP, 0, "Sep" + to_string(j), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "");

					if (blks.nodes.size() > 1) {
						dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::HDG, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
									VecWznmVMControlScope::APP, 0, "Hdg" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, blk->sref, 0, 0, 0, Avail, "", "");
						con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, blk->sref);
						dbswznm->tblwznmmcontrol->updateRec(con);
					};

					dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);
					addBitcons(dbswznm, bits, cons, refWznmMPanel, hkNum, Avail, pnlsectNum, refLcl);
				};
			};

			// - operation (pack)-specific settings
			dbswznm->tblwznmmoppack->loadRstByVer(cpb->refWznmMVersion, false, opks);

			for (unsigned int i = 0; i < opks.nodes.size(); i++) {
				opk = opks.nodes[i];

				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
							+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(opk->ref) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", false, blks);

				dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMOp, TblWznmMBlock WHERE TblWznmMOp.refWznmMOppack = " + to_string(opk->ref) + " AND TblWznmMBlock.refIxVTbl = "
							+ to_string(VecWznmVMBlockRefTbl::OPX) + " AND TblWznmMBlock.refUref = TblWznmMOp.ref AND TblWznmMBlock.ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
							+ " AND (TblWznmMBlock.wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 ORDER BY TblWznmMBlock.sref ASC", true, blks);

				if (blks.nodes.size() > 0) {
					refWznmMPanel = dbswznm->tblwznmmpanel->insertNewRec(NULL, VecWznmVMPanelBasetype::FORM, refWznmMCard, carNum++, VecWznmVMPanelRefTbl::VOID, 0, 0, "Pnl" + Prjshort + Crdshort + opk->sref.substr(4), false, "", "");

					hkNum = 1;

					plhs[refLcl] = opk->sref;

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::HDR, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::APP, 0, "Cpt", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
					addCjttag(dbswznm, con, cpb->tplRefWznmMCapability, "stg", refLcl, refsLcl, "&plh; &tag;", plhs);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::SHR, 0, "ButRegularize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::BUT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::SIDE, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::SHR, 0, "ButMinimize", VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "icon");

					for (unsigned int j = 0; j < blks.nodes.size(); j++) {
						blk = blks.nodes[j];

						pnlsectNum = 100*j + 1;

						if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) Avail = "!cmbdNotD()";
						else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) Avail = "cmbdNotD()";
						else Avail = "";

						if (j != 0)
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::SEP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
										VecWznmVMControlScope::APP, 0, "Sep" + to_string(j), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "");

						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::OPX) {
							dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::HDG, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
										VecWznmVMControlScope::APP, 0, "Hdg" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, blk->sref, 0, 0, 0, Avail, "", "");
							con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, blk->sref);
							dbswznm->tblwznmmcontrol->updateRec(con);
						};

						dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);
						addBitcons(dbswznm, bits, cons, refWznmMPanel, hkNum, Avail, pnlsectNum, refLcl);
					};
				};
			};
		};

		delete cpb;
	};
	// IP run --- IEND

	return(new DpchRetWznmCtpGenui("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- IBEGIN
void WznmCtpGenuiPrefs::addBitcons(
			DbsWznm* dbswznm
			, ListWznmAMBlockItem& bits
			, ListWznmMControl& cons
			, const ubigint refWznmMPanel
			, uint& hkNum
			, const string& Avail
			, uint& pnlsectNum
			, const ubigint refLcl
		) {
	WznmAMBlockItem* bit;

	WznmMControl* supcon = NULL;
	WznmMControl* con = NULL;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
			switch (bit->ixWznmVVartype) {
				case VecWznmVVartype::BOOLEAN:
					// CHK: Chk {Cpt}
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::CHK, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::SHR, 0, "Chk" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "clean");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, 1,
								VecWznmVMControlScope::APP, 0, "Cpt" + to_string(pnlsectNum - 1), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
					con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, bit->sref);
					dbswznm->tblwznmmcontrol->updateRec(con);

					break;

				case VecWznmVVartype::TINYINT:
				case VecWznmVVartype::UTINYINT:
				case VecWznmVVartype::SMALLINT:
				case VecWznmVVartype::USMALLINT:
				case VecWznmVVartype::INT:
				case VecWznmVVartype::UINT:
				case VecWznmVVartype::BIGINT:
				case VecWznmVVartype::UBIGINT:
				case VecWznmVVartype::FLOAT:
				case VecWznmVVartype::DOUBLE:
					// TXF: Txf {Cpt}
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::SHR, 0, "Txf" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "s;clean");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, 1,
								VecWznmVMControlScope::APP, 0, "Cpt" + to_string(pnlsectNum - 1), VecWznmVMControlSubtype::VOID, "", 0, bit->sref, 0, 0, 0, "", "", "");
					con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, bit->sref);
					dbswznm->tblwznmmcontrol->updateRec(con);

					break;

				case VecWznmVVartype::STRING:
					// TXF: Txf {Cpt}
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::TXF, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::SHR, 0, "Txf" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "clean");

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, 1,
								VecWznmVMControlScope::APP, 0, "Cpt" + to_string(pnlsectNum - 1), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
					con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, bit->sref);
					dbswznm->tblwznmmcontrol->updateRec(con);

					break;

				case VecWznmVVartype::VECSREF:
					// PUP: Pup {Cpt}
					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &supcon, VecWznmVMControlBasetype::PUP, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, 0, 0, 0,
								VecWznmVMControlScope::SHR, 0, "Pup" + to_string(pnlsectNum++), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, Avail, "", "clean");
					supcon->refWznmMFeed = dbswznm->tblwznmmfeed->insertNewRec(NULL, supcon->ref, VecWznmVMFeedSrcTbl::VEC, bit->refWznmMVector, "FeedF" + supcon->sref, "", "", "");
					dbswznm->tblwznmmcontrol->updateRec(supcon);

					dbswznm->tblwznmmcontrol->appendNewRecToRst(cons, &con, VecWznmVMControlBasetype::CPT, 0, VecWznmVMControlHkTbl::PNL, refWznmMPanel, hkNum++, VecWznmVMControlHkSection::CONT, VecWznmVMControlRefTbl::VOID, 0, supcon->ref, 1, 1,
								VecWznmVMControlScope::APP, 0, "Cpt" + to_string(pnlsectNum - 1), VecWznmVMControlSubtype::VOID, "", 0, "", 0, 0, 0, "", "", "");
					con->refJTitle = dbswznm->tblwznmjmcontroltitle->insertNewRec(NULL, con->ref, refLcl, bit->sref);
					dbswznm->tblwznmmcontrol->updateRec(con);

					break;
			};
		};
	};
};
// IP cust --- IEND
