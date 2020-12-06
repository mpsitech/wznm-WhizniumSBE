/**
	* \file WznmComplDeploy.cpp
	* Wznm operation processor - complement deployment information (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmComplDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCompl;

/******************************************************************************
 namespace WznmComplDeploy
 ******************************************************************************/

DpchRetWznm* WznmComplDeploy::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplDeploy* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string orgweb = dpchinv->orgweb;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	WznmMVersion* ver = NULL;

	ListWznmMComponent cmps;
	WznmMComponent* cmp = NULL;

	ubigint refCmpEng = 0;
	set<ubigint> unqrefsCmpOpeng;
	ubigint refCmpCmbeng = 0;

	ListWznmMRelease rlss;
	WznmMRelease* rls = NULL;

	string srefDbmstypeVer, srefDbmstypeMch;
	string sbeconfig;

	ubigint refMch = 0;
	vector<ubigint> hrefsMch;
	ubigint refMchAny;

	WznmMBlock* blk = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;
	unsigned int bitnum;

	ubigint refBlkDatabase = 0;
	map<string,unsigned int> icsBitsDatabase;

	ubigint refBlkMonitor = 0;
	map<string,unsigned int> icsBitsMonitor;

	ubigint refBlkPath = 0;
	map<string,unsigned int> icsBitsPath;

	ubigint refBlkAppsrv = 0;
	map<string,unsigned int> icsBitsAppsrv;

	ubigint refBlkAppearance = 0;
	map<string,unsigned int> icsBitsAppearance;

	ubigint refBlkDdspub = 0;
	ubigint refBlkUasrv = 0;

	ubigint refBlkEng = 0;
	map<string,unsigned int> icsBitsEng;

	ubigint refBlkCmbeng = 0;
	map<string,unsigned int> icsBitsCmbeng;

	ubigint refBlkOpeng = 0;
	map<string,unsigned int> icsBitsOpeng;

	bool apimon, dbsmon;
	bool ddspub, uasrv;

	string prjshort = StrMod::lc(Prjshort);

	dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver);

	apimon = (ver->ixWOption & VecWznmWMVersionOption::APIMON);
	dbsmon = (ver->ixWOption & VecWznmWMVersionOption::DBSMON);

	ddspub = (ver->ixWOption & VecWznmWMVersionOption::DDSPUB);
	uasrv = (ver->ixWOption & VecWznmWMVersionOption::UASRV);

	dbswznm->tblwznmmcomponent->loadRstByVer(refWznmMVersion, false, cmps);

	for (unsigned int i = 0; i < cmps.nodes.size(); i++) {
		cmp = cmps.nodes[i];

		switch (cmp->ixVBasetype) {
			case VecWznmVMComponentBasetype::ENG:
				refCmpEng = cmp->ref;
				break;
			case VecWznmVMComponentBasetype::OPENG:
				unqrefsCmpOpeng.insert(cmp->ref);
				break;
			case VecWznmVMComponentBasetype::CMBENG:
				refCmpCmbeng = cmp->ref;
				break;
		};
	};

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMMachine WHERE supRefWznmMMachine = 0 AND sref = 'any'", refMchAny);

	dbswznm->tblwznmmrelease->loadRstBySQL("SELECT TblWznmMRelease.* FROM TblWznmMComponent, TblWznmMRelease WHERE TblWznmMComponent.refWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND TblWznmMRelease.refWznmMComponent = TblWznmMComponent.ref ORDER BY TblWznmMRelease.refWznmMMachine", false, rlss);

	if (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO)) srefDbmstypeVer = "mar";
	else if (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) srefDbmstypeVer = "my";
	else if (ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG) srefDbmstypeVer = "pg";
	else if (ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) srefDbmstypeVer = "lite";

	for (unsigned int i = 0; i < rlss.nodes.size(); i++) {
		rls = rlss.nodes[i];

		// only releases for components of eng/openg/cmbeng/dbs are relevant
		if ((rls->refWznmMComponent == refCmpEng) || (unqrefsCmpOpeng.find(rls->refWznmMComponent) != unqrefsCmpOpeng.end()) || (rls->refWznmMComponent == refCmpCmbeng)) {

			if (rls->refWznmMMachine != refMch) {
				dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);
				refMch = rls->refWznmMMachine;

				Wznm::getMchpar(dbswznm, refMch, hrefsMch, "sbeconfig", sbeconfig);
				srefDbmstypeMch = "";
				
				if ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO)) && StrMod::srefInSrefs(sbeconfig, "mar")) srefDbmstypeMch = "mar";
				else if ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) && StrMod::srefInSrefs(sbeconfig, "my")) srefDbmstypeMch = "my";
				else if ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG) && StrMod::srefInSrefs(sbeconfig, "pg")) srefDbmstypeMch = "pg";
				else if ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) && StrMod::srefInSrefs(sbeconfig, "lite")) srefDbmstypeMch = "lite";
			};

			// StgXxxxDatabase
			if (refBlkDatabase == 0) {
				bitnum = 1;
				refBlkDatabase = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG + VecWznmWScope::OPENG,
							VecWznmWScope::ENG + VecWznmWScope::CMBENG + VecWznmWScope::OPENG, "Stg" + Prjshort + "Database", "");

				icsBitsDatabase["ixDbsVDbstype"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ixDbsVDbstype", VecWznmVVartype::VECSREF, 0, 0, 0, 0, 0, 0, srefDbmstypeVer, 0, "");
				dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "dbspath", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "./Dbs" + Prjshort + ".sql", 0, "");
				dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "dbsname", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "Dbs" + Prjshort, 0, "");
				icsBitsDatabase["username"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "username", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "dbsusername"), 0, "");
				icsBitsDatabase["password"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "password", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "dbspassword"), 0, "");
				icsBitsDatabase["ip"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ip", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "dbsip"), 0, "");
				icsBitsDatabase["port"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "port", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, srefDbmstypeVer + "port"), 0, "");

				delete blk;
			};

			if ((srefDbmstypeVer != srefDbmstypeMch) && (srefDbmstypeMch != "")) {
				bit = bits.nodes[icsBitsDatabase["ixDbsVDbstype"]];
				if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = " + to_string(bit->ref) + " AND x1RefWznmMRelease = " + to_string(rls->ref), ref))
					dbswznm->tblwznmjamblockitem->insertNewRec(NULL, bit->ref, rls->ref, srefDbmstypeMch, 0);

				addBitJ(dbswznm, rls, bits.nodes[icsBitsDatabase["port"]], hrefsMch, getMchparAny(dbswznm, refMchAny, srefDbmstypeMch + "port"));
			};

			addBitJ(dbswznm, rls, bits.nodes[icsBitsDatabase["username"]], hrefsMch, "dbsusername");
			addBitJ(dbswznm, rls, bits.nodes[icsBitsDatabase["password"]], hrefsMch, "dbspassword");
			addBitJ(dbswznm, rls, bits.nodes[icsBitsDatabase["ip"]], hrefsMch, "dbsip");

			// StgXxxxMonitor
			if (apimon || dbsmon) {
				if (refBlkMonitor == 0) {
					bitnum = 1;
					refBlkMonitor = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG + VecWznmWScope::OPENG,
								VecWznmWScope::ENG + VecWznmWScope::CMBENG + VecWznmWScope::OPENG, "Stg" + Prjshort + "Monitor", "");

					if (apimon || dbsmon) {
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "username", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "wzemuser", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "password", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "asdf1234", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ip", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "127.0.0.1", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "port", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, "14100", 0, "");
					};

					if (dbsmon) {
						dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ixDbsVDbstype", VecWznmVVartype::VECSREF, 0, 0, 0, 0, 0, 0, "", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "dbspath", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "./DbsWzem.sql", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "dbsname", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "DbsWzem", 0, "");
						dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "dbsusername", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");
						dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "dbspassword", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");
					};

					delete blk;
				};
			};

			// StgXxxxPath
			if (refBlkPath == 0) {
				bitnum = 1;
				refBlkPath = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG + VecWznmWScope::OPENG,
							VecWznmWScope::ENG + VecWznmWScope::CMBENG + VecWznmWScope::OPENG, "Stg" + Prjshort + "Path", "");

				icsBitsPath["acvpath"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "acvpath", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "acvroot") + "/" + prjshort, 0, "");
				dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "keypath", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");
				icsBitsPath["monpath"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "monpath", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "monroot") + "/" + prjshort, 0, "");
				icsBitsPath["tmppath"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "tmppath", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "tmproot") + "/" + prjshort, 0, "");
				icsBitsPath["webpath"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "webpath", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "webroot") + "/app" + prjshort, 0, "");
				dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "helpurl", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, orgweb + "/" + prjshort, 0, "");

				delete blk;
			};

			addBitJ(dbswznm, rls, bits.nodes[icsBitsPath["acvpath"]], hrefsMch, "acvroot", "/" + prjshort);
			addBitJ(dbswznm, rls, bits.nodes[icsBitsPath["monpath"]], hrefsMch, "monroot", "/" + prjshort);
			addBitJ(dbswznm, rls, bits.nodes[icsBitsPath["tmppath"]], hrefsMch, "tmproot", "/" + prjshort);
			addBitJ(dbswznm, rls, bits.nodes[icsBitsPath["webpath"]], hrefsMch, "webroot", "/app" + prjshort);

			if ((rls->refWznmMComponent == refCmpEng) || (rls->refWznmMComponent == refCmpCmbeng)) {
				// - settings blocks, d/cmbd only

				// StgXxxxAppsrv
				if (refBlkAppsrv == 0) {
					bitnum = 1;
					refBlkAppsrv = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG, VecWznmWScope::ENG + VecWznmWScope::CMBENG, "Stg" + Prjshort + "Appsrv", "");

					icsBitsAppsrv["port"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "port", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "appsrvport"), 0, "");
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "https", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "false", 0, "");

					delete blk;
				};

				addBitJ(dbswznm, rls, bits.nodes[icsBitsAppsrv["port"]], hrefsMch, "appsrvport");

				// StgXxxxAppearance
				if (refBlkAppearance == 0) {
					bitnum = 1;
					refBlkAppearance = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG, VecWznmWScope::ENG + VecWznmWScope::CMBENG, "Stg" + Prjshort + "Appearance", "");

					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "histlength", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, "20", 0, "");
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "suspsess", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "true", 0, "");

					delete blk;
				};

				if (ddspub) {
					// StgXxxxDdspub
					if (refBlkDdspub == 0) {
						bitnum = 1;
						refBlkDdspub = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG,
									VecWznmWScope::ENG + VecWznmWScope::CMBENG, "Stg" + Prjshort + "Ddspub", "");

						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "username", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "password", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "", 0, "");

						delete blk;
					};
				};

				if (uasrv) {
					// StgXxxxUasrv
					if (refBlkUasrv == 0) {
						bitnum = 1;
						refBlkUasrv = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG + VecWznmWScope::CMBENG,
									VecWznmWScope::ENG + VecWznmWScope::CMBENG, "Stg" + Prjshort + "Uasrv", "");

						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "profile", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "./EmbeddedProfile_StandardNodes.xml", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "port", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, "4840", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "cycle", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, "100", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "maxbrowse", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "1000", 0, "");
						dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "maxmon", VecWznmVVartype::UINT, 0, 0, 0, 0, 0, 0, "10000", 0, "");

						delete blk;
					};
				};
			};

			// - component-specific settings blocks
			if (rls->refWznmMComponent == refCmpEng) {
				if (refBlkEng == 0) {
					// StgXxxxd
					bitnum = 1;
					refBlkEng = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::ENG, VecWznmWScope::ENG, "Stg" + Prjshort + "d", "");

					icsBitsEng["jobprcn"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jobprcn", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "ncore"), 0, "");
					icsBitsEng["opengsrvport"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "opengsrvport", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "opengsrvport"), 0, "");
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "appsrv", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "true", 0, "");
					if (ddspub) dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ddspub", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "true", 0, "");
					if (uasrv) dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "uasrv", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "true", 0, "");

					delete blk;
				};

				addBitJ(dbswznm, rls, bits.nodes[icsBitsEng["jobprcn"]], hrefsMch, "ncore");
				addBitJ(dbswznm, rls, bits.nodes[icsBitsEng["opengsrvport"]], hrefsMch, "opengsrvport");
			};

			if (rls->refWznmMComponent == refCmpCmbeng) {
				if (refBlkCmbeng == 0) {
					// StgXxxxcmbd
					bitnum = 1;
					refBlkCmbeng = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::CMBENG, VecWznmWScope::CMBENG, "Stg" + Prjshort + "cmbd", "");

					icsBitsCmbeng["jobprcn"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "jobprcn", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "ncore"), 0, "");
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "opprcn", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, "1", 0, "");
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "appsrv", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "true", 0, "");
					if (ddspub) dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "ddspub", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "true", 0, "");
					if (uasrv) dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "uasrv", VecWznmVVartype::BOOLEAN, 0, 0, 0, 0, 0, 0, "true", 0, "");

					delete blk;
				};

				addBitJ(dbswznm, rls, bits.nodes[icsBitsCmbeng["jobprcn"]], hrefsMch, "ncore");
			};

			if (unqrefsCmpOpeng.find(rls->refWznmMComponent) != unqrefsCmpOpeng.end()) {
				if (refBlkOpeng == 0) {
					// StgXxxxopd
					bitnum = 1;
					refBlkOpeng = dbswznm->tblwznmmblock->insertNewRec(&blk, VecWznmVMBlockBasetype::STG, ver->ref, VecWznmVMBlockRefTbl::VOID, 0, VecWznmWScope::OPENG, VecWznmWScope::OPENG, "Stg" + Prjshort + "opd", "");

					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "engip", VecWznmVVartype::STRING, 0, 0, 0, 0, 0, 0, "127.0.0.1", 0, "");
					icsBitsOpeng["engport"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "engport", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "engport"), 0, "");
					icsBitsOpeng["engsrvportbase"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "engsrvportbase", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "engsrvportbase"), 0, "");
					dbswznm->tblwznmamblockitem->insertNewRec(NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "engsrvportofs", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, "0", 0, "");
					icsBitsOpeng["opprcn"] = bits.nodes.size(); dbswznm->tblwznmamblockitem->appendNewRecToRst(bits, NULL, 0, blk->ref, bitnum++, VecWznmVAMBlockItemBasetype::VAR, "opprcn", VecWznmVVartype::USMALLINT, 0, 0, 0, 0, 0, 0, getMchparAny(dbswznm, refMchAny, "ncore"), 0, "");

					delete blk;
				};

				addBitJ(dbswznm, rls, bits.nodes[icsBitsOpeng["engport"]], hrefsMch, "engport");
				addBitJ(dbswznm, rls, bits.nodes[icsBitsOpeng["engsrvportbase"]], hrefsMch, "engsrvportbase");
				addBitJ(dbswznm, rls, bits.nodes[icsBitsOpeng["opprcn"]], hrefsMch, "ncore");
			};
		};
	};

	delete ver;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
string WznmComplDeploy::getMchparAny(
			DbsWznm* dbswznm
			, const ubigint refMchAny
			, const string& x1SrefKKey
		) {
	vector<ubigint> hrefsMch;
	string Val;

	Wznm::getMchpar(dbswznm, refMchAny, hrefsMch, x1SrefKKey, Val);

	return Val;
};

void WznmComplDeploy::addBitJ(
			DbsWznm* dbswznm
			, WznmMRelease* rls
			, WznmAMBlockItem* bit
			, vector<ubigint>& hrefsMch
			, const string& x1SrefKKey
			, const string& post
		) {
	ubigint ref;
	string Val;

	if (Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, x1SrefKKey, Val))
		if ((Val + post) != bit->Defval)
			if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmJAMBlockItem WHERE refWznmAMBlockItem = " + to_string(bit->ref) + " AND x1RefWznmMRelease = " + to_string(rls->ref), ref))
				dbswznm->tblwznmjamblockitem->insertNewRec(NULL, bit->ref, rls->ref, Val + post, 0);
};
// IP cust --- IEND
