/**
	* \file WznmWrsrvRootsess.cpp
	* Wznm operation processor - write specific job C++ code for root and session (implementation)
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

#include "WznmWrsrvRootsess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsrvRootsess
 ******************************************************************************/

DpchRetWznm* WznmWrsrvRootsess::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvRootsess* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMJob* job = NULL;

	fstream hfile;
	fstream cppfile;

	string s;

	dbswznm->tblwznmmjob->loadRecBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS) + " AND sref = 'M2msess" + Prjshort + "'", &job);

	// RootXxxx.h, RootXxxx.cpp
	s = xchg->tmppath + "/" + folder + "/Root" + Prjshort + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/Root" + Prjshort + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeRtH(dbswznm, hfile, Prjshort);
	writeRtCpp(dbswznm, cppfile, refWznmMVersion, Prjshort, (job != NULL));

	hfile.close();
	cppfile.close();

	// SessXxxx.h, SessXxxx.cpp
	s = xchg->tmppath + "/" + folder + "/Sess" + Prjshort + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/Sess" + Prjshort + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeSessH(dbswznm, hfile, refWznmMVersion, Prjshort);
	writeSessCpp(dbswznm, cppfile, refWznmMVersion, Prjshort);

	hfile.close();
	cppfile.close();

	if (job) {
		// M2msessXxxx.h, M2msessXxxx.cpp
		s = xchg->tmppath + "/" + folder + "/M2msess" + Prjshort + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/M2msess" + Prjshort + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeM2msessH(dbswznm, hfile, Prjshort);
		writeM2msessCpp(dbswznm, cppfile, job, Prjshort);

		hfile.close();
		cppfile.close();

		delete job;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvRootsess::writeRtH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
		) {
	string prjshort = StrMod::lc(Prjshort);

	// --- include.spec
	outfile << "// IP include.spec --- IBEGIN" << endl;
	outfile << "#include <signal.h>" << endl;
	outfile << "// IP include.spec --- IEND" << endl;

	// --- constructor
	outfile << "// IP constructor --- RBEGIN" << endl;
	outfile << "\tRoot" << Prjshort << "(Xchg" << Prjshort << "* xchg, Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::ubigint jrefSup, const bool _clearAll);" << endl;
	outfile << "// IP constructor --- REND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tvoid clearAll(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << "\tvoid clearQtb(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << endl;
	
	outfile << "\tbool authenticate(Dbs" << Prjshort << "* dbs" << prjshort << ", const std::string& username, const std::string& password, Sbecore::ubigint& ref" << Prjshort << "MUser);" << endl;
	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvRootsess::writeRtCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const bool hasm2m
		) {
	ubigint ref;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	bool hasadr, hasorg;

	string srefLcl;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	hasadr = dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "MAddress'", ref);
	hasorg = dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Tbl" + Prjshort + "MOrg'", ref);

	dbswznm->loadStringBySQL("SELECT TblWznmMLocale.sref FROM TblWznmMVersion, TblWznmMLocale WHERE TblWznmMLocale.ref = TblWznmMVersion.refWznmMLocale AND TblWznmMVersion.ref = "
				+ to_string(refWznmMVersion), srefLcl);

	// --- constructor.hdr
	outfile << "// IP constructor.hdr --- RBEGIN" << endl;
	outfile << "Root" << Prjshort << "::Root" << Prjshort << "(" << endl;
	outfile << "\t\t\tXchg" << Prjshort << "* xchg" << endl;
	outfile << "\t\t\t, Dbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const ubigint jrefSup" << endl;
	outfile << "\t\t\t, const bool _clearAll" << endl;
	outfile << "\t\t) :" << endl;
	outfile << "\t\t\tJob" << Prjshort << "(xchg, Vec" << Prjshort << "VJob::ROOT" << PRJSHORT << ", jrefSup, Vec" << Prjshort << "VLocale::" << StrMod::uc(srefLcl) << ")" << endl;
	outfile << "\t\t{" << endl;
	outfile << "// IP constructor.hdr --- REND" << endl;

	// --- constructor.spec1
	outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
	outfile << "\t// log" << endl;
	outfile << "\txchg->appendToLogfile(\"root job created\");" << endl;
	outfile << endl;

	outfile << "\tif (_clearAll) clearAll(dbs" << prjshort << ");" << endl;
	outfile << "\telse clearQtb(dbs" << prjshort << ");" << endl;
	outfile << "// IP constructor.spec1 --- IEND" << endl;

	// --- constructor.spec3
	outfile << "// IP constructor.spec3 --- IBEGIN" << endl;
	outfile << "\tif (xchg->stg" << prjshort << "appearance.roottterm != 0) wrefLast = xchg->addWakeup(jref, \"warnterm\", 1e6 * xchg->stg" << prjshort << "appearance.roottterm);" << endl;
	outfile << "// IP constructor.spec3 --- IEND" << endl;

	// --- destructor.spec
	outfile << "// IP destructor.spec --- IBEGIN" << endl;
	outfile << "\t// log" << endl;
	outfile << "\txchg->appendToLogfile(\"root job deleted\");" << endl;
	outfile << "// IP destructor.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	// -- clearAll
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, tbls);

	outfile << "void Root" << Prjshort << "::clearAll(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\t" << Prjshort << "MUsergroup* usg = NULL;" << endl;
	outfile << "\t" << Prjshort << "RMUserMUsergroup* uru = NULL;" << endl;
	outfile << "\t" << Prjshort << "MUser* usr = NULL;" << endl;
	outfile << "\t" << Prjshort << "MPerson* prs = NULL;" << endl;
	outfile << endl;

	outfile << "\ttime_t now;" << endl;
	outfile << endl;

	outfile << "\tstring s;" << endl;
	outfile << endl;

	outfile << "\t// empty out tables" << endl;
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		if (tbl->ixVBasetype != VecWznmVMTableBasetype::QRY) {
			if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST) {
				outfile << "\tif (dbs" << prjshort << "->ixDbsVDbstype == VecDbsVDbstype::MY) dbs" << prjshort << "->executeQuery(\"DELETE FROM " << tbl->sref << "\");" << endl;
				outfile << "\telse if (dbs" << prjshort << "->ixDbsVDbstype == VecDbsVDbstype::PG) dbs" << prjshort << "->executeQuery(\"ALTER SEQUENCE " << tbl->sref << " RESTART WITH 1\");" << endl;
			} else {
				outfile << "\tdbs" << prjshort << "->executeQuery(\"DELETE FROM " << tbl->sref << "\");" << endl;
			};
		};
	};
	outfile << endl;

	outfile << "\tclearQtb(dbs" << prjshort << ");" << endl;
	outfile << endl;

	outfile << "\t// generate a temporary user such that a session can be generated" << endl;
	outfile << "\ttime(&now);" << endl;
	outfile << endl;

	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "musergroup->insertNewRec(&usg, 0, 0, \"temp\", \"temporary user group for system initialization\");" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "amusergroupaccess->insertNewRec(NULL, usg->ref, Vec" << Prjshort << "VFeatgroup::VEC" << PRJSHORT << "VCARD, \"Crd" << Prjshort << "Nav\", Vec" << Prjshort << "WAccess::EDIT + Vec" << Prjshort << "WAccess::EXEC + Vec" << Prjshort << "WAccess::VIEW);" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "rmusermusergroup->insertNewRec(&uru, 0, usg->ref, Vec" << Prjshort << "VUserlevel::GADM);" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "muser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, \"temp\", 0, Vec" << Prjshort << "VMUserState::DUE, Vec" << Prjshort << "VLocale::" << StrMod::uc(srefLcl) << ", Vec" << Prjshort << "VUserlevel::GADM, \"asdf1234\", \"\", \"temporary user for system initialization\");" << endl;
	outfile << "\tusr->refJState = dbs" << prjshort << "->tbl" << prjshort << "jmuserstate->insertNewRec(NULL, usr->ref, 0, Vec" << Prjshort << "VMUserState::DUE);" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "jmuserstate->insertNewRec(NULL, usr->ref, now + 24*3600, Vec" << Prjshort << "VMUserState::EXP);" << endl;
	outfile << "\tusr->ref" << Prjshort << "MPerson = dbs" << prjshort << "->tbl" << prjshort << "mperson->insertNewRec(&prs, usg->ref, usr->ref, Vec" << Prjshort << "WMPersonDerivate::USR";
	if (hasadr) outfile << ", 0";
	if (hasorg) outfile << ", 0, 0";
	outfile << ", Vec" << Prjshort << "VMPersonSex::M, \"Mr.\", \"Jack\", 0, \"Smith\", 0, \"\", 0, \"\", \"Dear Jack\");" << endl;
	outfile << endl;

	if (hasadr) outfile << "\tprs->ref" << Prjshort << "MAddress = dbs" << prjshort << "->tbl" << prjshort << "maddress->insertNewRec(NULL, usg->ref, usr->ref, 0, Vec" << Prjshort << "VMAddressHkTbl::PRS, prs->ref, \"ofc\", \"1234 West 119th Street\", \"\", \"10027\", \"New York\", \"NY\", \"us\");" << endl;
	outfile << "\tprs->refJLastname = dbs" << prjshort << "->tbl" << prjshort << "jmpersonlastname->insertNewRec(NULL, prs->ref, 0, \"Smith\");" << endl;
	outfile << endl;

	outfile << "\tusg->grp = usg->ref;" << endl;
	outfile << "\tusg->own = usr->ref;" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "musergroup->updateRec(usg);" << endl;
	outfile << endl;

	outfile << "\turu->ref" << Prjshort << "MUser = usr->ref;" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "rmusermusergroup->updateRec(uru);" << endl;
	outfile << endl;

	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "muser->updateRec(usr);" << endl;
	outfile << endl;

	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "mperson->updateRec(prs);" << endl;
	outfile << endl;

	outfile << "\tcout << \"\\ttemporary account created for user 'temp', expires \" << Ftm::stamp(now + 24*3600) << \"; use password 'asdf1234' to log in\" << endl;" << endl;
	outfile << endl;

	outfile << "\txchg->appendToLogfile(\"database cleared\");" << endl;
	outfile << endl;

	outfile << "\tdelete usg;" << endl;
	outfile << "\tdelete uru;" << endl;
	outfile << "\tdelete usr;" << endl;
	outfile << "\tdelete prs;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- clearQtb
	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::QRY, refWznmMVersion, false, tbls);

	outfile << "void Root" << Prjshort << "::clearQtb(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;

	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];
		outfile << "\tdbs" << prjshort << "->executeQuery(\"DELETE FROM " << tbl->sref << "\");" << endl;
	};
	outfile << "};" << endl;
	outfile << endl;

	// -- authenticate
	outfile << "bool Root" << Prjshort << "::authenticate(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const string& username" << endl;
	outfile << "\t\t\t, const string& password" << endl;
	outfile << "\t\t\t, ubigint& ref" << Prjshort << "MUser" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tbool valid = false;" << endl;
	outfile << endl;

	outfile << "\tubigint ref;" << endl;
	outfile << endl;

	outfile << "\t" << Prjshort << "MUser* usr = NULL;" << endl;
	outfile << endl;

	outfile << "\ttime_t now;" << endl;
	outfile << endl;

	outfile << "\tref" << Prjshort << "MUser = 0;" << endl;
	outfile << endl;

	outfile << "\tif (dbs" << prjshort << "->tbl" << prjshort << "muser->loadRecBySrfPwd(username, password, &usr)) {" << endl;
	outfile << "\t\tif ((usr->ixVState == Vec" << Prjshort << "VMUserState::DSG) || (usr->ixVState == Vec" << Prjshort << "VMUserState::DUE)) {" << endl;
	outfile << "\t\t\t// check if expired" << endl;
	outfile << "\t\t\ttime(&now);" << endl;
	outfile << endl;

	outfile << "\t\t\tif (dbs" << prjshort << "->loadRefBySQL(\"SELECT ref FROM Tbl" << Prjshort << "JMUserState WHERE ref" << Prjshort << "MUser = \" + to_string(usr->ref) + \" AND x1Start < \" + to_string(now) + \" AND ixVState = \" + to_string(Vec" << Prjshort << "VMUserState::EXP) + \" ORDER BY x1Start DESC LIMIT 1\", ref)) {" << endl;
	outfile << "\t\t\t\tusr->refJState = ref;" << endl;
	outfile << "\t\t\t\tusr->ixVState = Vec" << Prjshort << "VMUserState::EXP;" << endl;
	outfile << "\t\t\t\tdbs" << prjshort << "->tbl" << prjshort << "muser->updateRec(usr);" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t\tvalid = ((usr->ixVState == Vec" << Prjshort << "VMUserState::ACT) || (usr->ixVState == Vec" << Prjshort << "VMUserState::DUE));" << endl;
	outfile << endl;

	outfile << "\t\tif (valid) ref" << Prjshort << "MUser = usr->ref;" << endl;
	outfile << endl;

	outfile << "\t\tdelete usr;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\treturn valid;" << endl;
	outfile << "};" << endl;

	outfile << "// IP spec --- IEND" << endl;

	// --- handleCreateSess
	outfile << "// IP handleCreateSess --- IBEGIN" << endl;
	outfile << "\tstring input;" << endl;
	outfile << "\tstring input2;" << endl;
	outfile << endl;

	outfile << "\tubigint refUsr;" << endl;
	outfile << endl;

	outfile << "\tSess" << Prjshort << "* sess = NULL;" << endl;
	outfile << endl;

	outfile << "\tcout << \"\\tuser name: \";" << endl;
	outfile << "\tcin >> input;" << endl;
	outfile << "\tcout << \"\\tpassword: \";" << endl;
	outfile << "\tcin >> input2;" << endl;
	outfile << endl;

	outfile << "\t// verify password and create a session" << endl;
	outfile << "\tif (authenticate(dbs" << prjshort << ", input, input2, refUsr)) {" << endl;
	outfile << "\t\tsess = new Sess" << Prjshort << "(xchg, dbs" << prjshort << ", jref, refUsr, \"127.0.0.1\");" << endl;
	outfile << "\t\tsesss.push_back(sess);" << endl;
	outfile << endl;

	outfile << "\t\tcout << \"\\tjob reference: \" << sess->jref << endl;" << endl;
	outfile << "\t\txchg->jrefCmd = sess->jref;" << endl;
	outfile << endl;

	outfile << "\t\tif ((xchg->stg" << prjshort << "appearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, \"warnterm\", 1e6 * (xchg->stg" << prjshort << "appearance.sesstterm - xchg->stg" << prjshort << "appearance.sesstwarn));" << endl;
	outfile << endl;

	outfile << "\t\txchg->appendToLogfile(\"command line session created for user '\" + input + \"'\");" << endl;
	outfile << endl;

	outfile << "\t} else {" << endl;
	outfile << "\t\tcout << \"\\tlogin failed.\" << endl;" << endl;
	outfile << endl;

	outfile << "\t\txchg->appendToLogfile(\"command line login refused for user '\" + input + \"'\");" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "// IP handleCreateSess --- IEND" << endl;

	// --- handleEraseSess
	outfile << "// IP handleEraseSess --- IBEGIN" << endl;
	outfile << "\tstring input;" << endl;
	outfile << "\tuint iinput;" << endl;
	outfile << endl;

	outfile << "\tSess" << Prjshort << "* sess = NULL;" << endl;
	outfile << endl;

	outfile << "\tcout << \"\\tjob reference: \";" << endl;
	outfile << "\tcin >> input;" << endl;
	outfile << "\tiinput = atoi(input.c_str());" << endl;
	outfile << endl;

	outfile << "\tfor (auto it = sesss.begin(); it != sesss.end();) {" << endl;
	outfile << "\t\tsess = *it;" << endl;
	outfile << "\t\tif (sess->jref == iinput) {" << endl;
	outfile << "\t\t\tit = sesss.erase(it);" << endl;
	outfile << "\t\t\tdelete sess;" << endl;
	outfile << "\t\t\tbreak;" << endl;
	outfile << "\t\t} else it++;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\treturn false;" << endl;
	outfile << "// IP handleEraseSess --- IEND" << endl;

	// --- handleClearAll
	outfile << "// IP handleClearAll --- IBEGIN" << endl;
	outfile << "\tclearAll(dbs" << prjshort << ");" << endl;
	outfile << "// IP handleClearAll --- IEND" << endl;

	// --- handleDpchAppLogin
	outfile << "// IP handleDpchAppLogin --- IBEGIN" << endl;
	outfile << "\tubigint refUsr;" << endl;
	outfile << endl;

	outfile << "\tSess" << Prjshort << "* sess = NULL;" << endl;
	if (hasm2m) outfile << "\tM2msess" << Prjshort << "* m2msess = NULL;" << endl;
	outfile << endl;

	outfile << "\tFeed feedFEnsSps(\"FeedFEnsSps\");" << endl;
	outfile << endl;

	outfile << "\t// verify password" << endl;
	outfile << "\tif (authenticate(dbs" << prjshort << ", StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {" << endl;

	outfile << "\t\tif (!(dpchapplogin->m2mNotReg)) {" << endl;
	outfile << "\t\t\tif (xchg->stg" << prjshort << "appearance.suspsess && dpchapplogin->chksuspsess) {" << endl;
	outfile << "\t\t\t\t// look for suspended sessions" << endl;
	outfile << "\t\t\t\tfor (auto it = sesss.begin(); it != sesss.end(); it++) {" << endl;
	outfile << "\t\t\t\t\tsess = *it;" << endl;
	outfile << endl;

	outfile << "\t\t\t\t\tif (xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "OWNER, sess->jref) == refUsr) {" << endl;
	outfile << "\t\t\t\t\t\tif (xchg->getBoolvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SUSPSESS, sess->jref)) {" << endl;
	outfile << "\t\t\t\t\t\t\txchg->addTxtvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IP, sess->jref, ip);" << endl;
	outfile << "\t\t\t\t\t\t\tfeedFEnsSps.appendIxSrefTitles(0, Scr::scramble(sess->jref), Stub" << Prjshort << "::getStubSesStd(dbs" << prjshort << ", xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SESS, sess->jref)));" << endl;
	outfile << "\t\t\t\t\t\t};" << endl;
	outfile << "\t\t\t\t\t};" << endl;
	outfile << "\t\t\t\t};" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\tif (feedFEnsSps.size() == 0) {" << endl;
	outfile << "\t\t\t\t// start new session" << endl;
	outfile << "\t\t\t\tsess = new Sess" << Prjshort << "(xchg, dbs" << prjshort << ", jref, refUsr, ip);" << endl;
	outfile << "\t\t\t\tsesss.push_back(sess);" << endl;
	outfile << endl;

	outfile << "\t\t\t\tif ((xchg->stg" << prjshort << "appearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, \"warnterm\", 1e6 * (xchg->stg" << prjshort << "appearance.sesstterm - xchg->stg" << prjshort << "appearance.sesstwarn));" << endl;
	outfile << endl;

	outfile << "\t\t\t\txchg->appendToLogfile(\"session created for user '\" + dpchapplogin->username + \"' from IP \" + ip);" << endl;
	outfile << endl;

	outfile << "\t\t\t\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, sess->jref, \"\");" << endl;
	outfile << endl;

	outfile << "\t\t\t} else {" << endl;
	outfile << "\t\t\t\t// return suspended sessions" << endl;
	outfile << "\t\t\t\t*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	if (hasm2m) {
		outfile << endl;
		outfile << "\t\t} else {" << endl;
		outfile << "\t\t\tm2msess = new M2msess" << Prjshort << "(xchg, dbs" << prjshort << ", jref, refUsr, ip);" << endl;
		outfile << endl;

		outfile << "\t\t\tm2msesss.push_back(m2msess);" << endl;
		outfile << endl;

		outfile << "\t\t\txchg->appendToLogfile(\"M2M session created for user '\" + dpchapplogin->username + \"' from IP \" + ip);" << endl;
		outfile << endl;

		outfile << "\t\t\t*dpcheng = new DpchEng" << Prjshort << "Confirm(true, m2msess->jref, \"\");" << endl;
	};

	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t} else {" << endl;
	outfile << "\t\txchg->appendToLogfile(\"login refused for user '\" + dpchapplogin->username + \"' from IP \" + ip);" << endl;
	outfile << endl;

	outfile << "\t\t*dpcheng = new DpchEng" << Prjshort << "Confirm(false, 0, \"\");" << endl;

	outfile << "\t};" << endl;
	outfile << "// IP handleDpchAppLogin --- IEND" << endl;

	// --- handleTimerWithSrefWarnterm
	outfile << "// IP handleTimerWithSrefWarnterm --- IBEGIN" << endl;
	outfile << "\tSess" << Prjshort << "* sess = NULL;" << endl;
	outfile << endl;

	outfile << "\ttime_t tlast;" << endl;
	outfile << "\ttime_t tnext = 0;" << endl;
	outfile << endl;

	outfile << "\ttime_t rawtime;" << endl;
	outfile << "\ttime(&rawtime);" << endl;
	outfile << endl;

	outfile << "\tbool term;" << endl;
	outfile << endl;

	outfile << "\tif (xchg->stg" << prjshort << "appearance.sesstterm != 0) {" << endl;
	outfile << "\t\tfor (auto it = sesss.begin(); it != sesss.end();) {" << endl;
	outfile << "\t\t\tsess = *it;" << endl;
	outfile << endl;

	outfile << "\t\t\tterm = false;" << endl;
	outfile << endl;

	outfile << "\t\t\ttlast = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "TLAST, sess->jref);" << endl;
	outfile << endl;

	outfile << "\t\t\tif ((tlast + ((int) xchg->stg" << prjshort << "appearance.sesstterm)) <= rawtime) term = true;" << endl;
	outfile << "\t\t\telse if ((tlast + ((int) xchg->stg" << prjshort << "appearance.sesstterm) - ((int) xchg->stg" << prjshort << "appearance.sesstwarn)) <= rawtime) {" << endl;
	outfile << "\t\t\t\tsess->warnTerm(dbs" << prjshort << ");" << endl;
	outfile << "\t\t\t\tif ((tnext == 0) || ((tlast + ((int) xchg->stg" << prjshort << "appearance.sesstterm)) < tnext)) tnext = tlast + ((int) xchg->stg" << prjshort << "appearance.sesstterm);" << endl;
	outfile << "\t\t\t} else if ((tnext == 0) || ((tlast + ((int) xchg->stg" << prjshort << "appearance.sesstterm) - ((int) xchg->stg" << prjshort << "appearance.sesstwarn)) < tnext)) tnext = tlast + xchg->stg" << prjshort << "appearance.sesstterm - xchg->stg" << prjshort << "appearance.sesstwarn;" << endl;
	outfile << endl;
	
	outfile << "\t\t\tif (term) {" << endl;
	outfile << "\t\t\t\tsess->term(dbs" << prjshort << ");" << endl;
	outfile << "\t\t\t\tit = sesss.erase(it);" << endl;
	outfile << endl;

	outfile << "\t\t\t\tdelete sess;" << endl;
	outfile << endl;

	outfile << "\t\t\t} else it++;" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tterm = false;" << endl;
	outfile << endl;

	outfile << "\tif (xchg->stg" << prjshort << "appearance.roottterm != 0) {" << endl;
	outfile << "\t\ttlast = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "TLAST, jref);" << endl;
	outfile << endl;

	outfile << "\t\tif ((tlast + ((int) xchg->stg" << prjshort << "appearance.roottterm)) <= rawtime) term = true;" << endl;
	outfile << "\t\telse if ((tnext == 0) || ((tlast + ((int) xchg->stg" << prjshort << "appearance.roottterm)) < tnext)) tnext = tlast + xchg->stg" << prjshort << "appearance.roottterm;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (term) {" << endl;
	outfile << "\t\tcout << endl << \"\\tterminating due to inactivity\" << endl;" << endl;
	outfile << "\t\tkill(getpid(), SIGTERM);" << endl;
	outfile << "\t} else if (tnext != 0) wrefLast = xchg->addWakeup(jref, \"warnterm\", 1e6 * (tnext - rawtime));" << endl;
	outfile << "// IP handleTimerWithSrefWarnterm --- IEND" << endl;

	// --- handleCallXxxxLogout
	outfile << "// IP handleCall" << Prjshort << "Logout --- IBEGIN" << endl;
	outfile << endl;

	outfile << "\tSess" << Prjshort << "* sess = NULL;" << endl;
	if (hasm2m) outfile << "\tM2msess" << Prjshort << "* m2msess = NULL;" << endl;
	outfile << endl;

	outfile << "\ttime_t rawtime;" << endl;
	outfile << endl;

	outfile << "\tif (!boolvalInv) {" << endl;
	outfile << "\t\tfor (auto it = sesss.begin(); it != sesss.end();) {" << endl;
	outfile << "\t\t\tsess = *it;" << endl;
	outfile << "\t\t\tif (sess->jref == jrefTrig) {" << endl;
	outfile << "\t\t\t\tsess->term(dbs" << prjshort << ");" << endl;
	outfile << "\t\t\t\tit = sesss.erase(it);" << endl;
	outfile << endl;

	outfile << "\t\t\t\tdelete sess;" << endl;
	outfile << "\t\t\t\tbreak;" << endl;
	outfile << "\t\t\t} else it++;" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t\tif (xchg->stg" << prjshort << "appearance.roottterm) {" << endl;
	outfile << "\t\t\ttime(&rawtime);" << endl;
	outfile << "\t\t\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "TLAST, jref, rawtime);" << endl;
	outfile << "\t\t};" << endl;

	if (hasm2m) {
		outfile << endl;
		outfile << "\t} else {" << endl;
		outfile << "\t\tfor (auto it = m2msesss.begin(); it != m2msesss.end();) {" << endl;
		outfile << "\t\t\tm2msess = *it;" << endl;
		outfile << "\t\t\tif (m2msess->jref == jrefTrig) {" << endl;
		outfile << "\t\t\t\tm2msess->term(dbs" << prjshort << ");" << endl;
		outfile << "\t\t\t\tit = m2msesss.erase(it);" << endl;
		outfile << endl;

		outfile << "\t\t\t\tdelete m2msess;" << endl;
		outfile << "\t\t\t\tbreak;" << endl;
		outfile << "\t\t\t} else it++;" << endl;
		outfile << "\t\t};" << endl;
	};

	outfile << "\t};" << endl;

	outfile << endl;
	outfile << "// IP handleCall" << Prjshort << "Logout --- IEND" << endl;

	// --- handleCallXxxxRefPreSet
	outfile << "// IP handleCall" << Prjshort << "RefPreSet --- IBEGIN" << endl;
	outfile << endl;

	outfile << "\tif (ixInv == Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "TLAST) {" << endl;
	outfile << "\t\txchg->addRefPreset(ixInv, jref, refInv);" << endl;
	outfile << "\t};" << endl;

	outfile << endl;
	outfile << "// IP handleCall" << Prjshort << "RefPreSet --- IEND" << endl;

	// --- handleCallXxxxSuspsess
	outfile << "// IP handleCall" << Prjshort << "Suspsess --- IBEGIN" << endl;
	outfile << endl;

	outfile << "\txchg->addBoolvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SUSPSESS, jrefTrig, true);" << endl;
	outfile << "\txchg->removeDcolsByJref(jrefTrig);" << endl;

	outfile << endl;
	outfile << "// IP handleCall" << Prjshort << "Suspsess --- IEND" << endl;
};

void WznmWrsrvRootsess::writeSessH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	vector<ubigint> refs;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	string prjshort = StrMod::lc(Prjshort);

	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	// --- constructor
	outfile << "// IP constructor --- RBEGIN" << endl;
	outfile << "\tSess" << Prjshort << "(Xchg" << Prjshort << "* xchg, Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << ", const Sbecore::ubigint jrefSup, const Sbecore::ubigint ref" << Prjshort << "MUser, const std::string& ip);" << endl;
	outfile << "// IP constructor --- REND" << endl;

	// --- specVar
	outfile << "// IP vars.spec --- IBEGIN" << endl;
	outfile << "\tstd::map<Sbecore::ubigint,Sbecore::uint> usgaccs;" << endl;
	outfile << endl;

	outfile << "\tstd::map<Sbecore::ubigint,std::string> scr;" << endl;
	outfile << "\tstd::map<std::string,Sbecore::ubigint> descr;" << endl;
	outfile << "// IP vars.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tvoid warnTerm(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << "\tvoid term(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << endl;

	outfile << "\tSbecore::uint checkCrdActive(const Sbecore::uint ix" << Prjshort << "VCard);" << endl;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		if (car->Active.length() > 0) outfile << "\tSbecore::uint evalCrd" << StrMod::lc(car->sref.substr(3+4)) << "Active();" << endl;
	};
	outfile << endl;

	outfile << "\tSbecore::uint checkCrdaccess(const Sbecore::uint ix" << Prjshort << "VCard);" << endl;
	outfile << "\tvoid getIxCrdacc(Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::uint ix" << Prjshort << "VCard, const bool adm, List" << Prjshort << "RMUserMUsergroup& urus, const Sbecore::ubigint ref" << Prjshort << "MUser, Sbecore::uint& ix" << Prjshort << "WAccess);" << endl;
	outfile << endl;

	outfile << "\tSbecore::uint checkRecaccess(Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << ", const Sbecore::uint ix" << Prjshort << "VCard, const Sbecore::ubigint ref);" << endl;
	outfile << "\tvoid logRecaccess(Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << ", const Sbecore::uint ix" << Prjshort << "VPreset, const Sbecore::ubigint preUref, const Sbecore::uint ix" << Prjshort << "VCard, const Sbecore::ubigint unvUref);" << endl;
	outfile << endl;

	outfile << "\tSbecore::uint crdToMtb(const Sbecore::uint ix" << Prjshort << "VCard);" << endl;
	outfile << "\tSbecore::uint preToMtb(const Sbecore::uint ix" << Prjshort << "VPreset);" << endl;
	outfile << "\tbool hasActive(const Sbecore::uint ix" << Prjshort << "VCard);" << endl;
	outfile << "\tbool hasGrpown(const Sbecore::uint ix" << Prjshort << "VMaintable);" << endl;
	outfile << endl;

	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvRootsess::writeSessCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	vector<ubigint> refs;
	ubigint ref;

	WznmMVersion* ver = NULL;

	ListWznmMTable mtbs;
	WznmMTable* mtb = NULL;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	ListWznmMPreset psts;
	WznmMPreset* pst = NULL;

	bool accgrpreg, accnogoall;

	Expr expr;

	string s;
	bool first;
	uint cnt;

	string pre;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS), ref);

	accgrpreg = false;
	accnogoall = false;

	if (dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver)) {
		accgrpreg = (ver->ixWOption & VecWznmWMVersionOption::ACCGRPREG);
		accnogoall = (ver->ixWOption & VecWznmWMVersionOption::ACCNOGOALL);

		delete ver;
	};

	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::MAIN, refWznmMVersion, false, mtbs);

	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	dbswznm->tblwznmmpreset->loadRstBySQL("SELECT * FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND refIxVTbl <> " + to_string(VecWznmVMPresetRefTbl::VOID)
				+ " ORDER BY sref ASC", false, psts);

	// --- constructor.hdr
	outfile << "// IP constructor.hdr --- RBEGIN" << endl;
	outfile << "Sess" << Prjshort << "::Sess" << Prjshort << "(" << endl;
	outfile << "\t\t\tXchg" << Prjshort << "* xchg" << endl;
	outfile << "\t\t\t, Dbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const ubigint jrefSup" << endl;
	outfile << "\t\t\t, const ubigint ref" << Prjshort << "MUser" << endl;
	outfile << "\t\t\t, const string& ip" << endl;
	outfile << "\t\t) :" << endl;
	outfile << "\t\t\tJob" << Prjshort << "(xchg, Vec" << Prjshort << "VJob::SESS" << PRJSHORT << ", jrefSup)" << endl;
	outfile << "\t\t{" << endl;
	outfile << "// IP constructor.hdr --- REND" << endl;

	// --- constructor.spec1
	outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
	outfile << "\tvector<ubigint> refs;" << endl;
	outfile << endl;

	outfile << "\tubigint refSes;" << endl;
	outfile << endl;

	outfile << "\t" << Prjshort << "MUser* usr = NULL;" << endl;
	outfile << endl;

	outfile << "\tbool adm;" << endl;
	outfile << endl;

	outfile << "\tList" << Prjshort << "RMUserMUsergroup urus;" << endl;
	outfile << "\t" << Prjshort << "RMUserMUsergroup* uru = NULL;" << endl;
	outfile << endl;

	outfile << "\tuint ix" << Prjshort << "WAccessBase, ix" << Prjshort << "WAccess;" << endl;
	outfile << endl;

	outfile << "\tuint jnum;" << endl;
	outfile << endl;

	outfile << "\t// create new session with start time" << endl;
	outfile << "\ttime_t rawtime;" << endl;
	outfile << "\ttime(&rawtime);" << endl;
	outfile << endl;

	outfile << "\trefSes = dbs" << prjshort << "->tbl" << prjshort << "msession->insertNewRec(NULL, ref" << Prjshort << "MUser, (uint) rawtime, 0, ip);" << endl;
	outfile << endl;

	outfile << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SESS, jref, refSes);" << endl;
	outfile << "\txchg->addTxtvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IP, jref, ip);" << endl;
	outfile << endl;

	outfile << "\t// set locale and presetings corresponding to user" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "muser->loadRecByRef(ref" << Prjshort << "MUser, &usr);" << endl;
	outfile << endl;

	outfile << "\tix" << Prjshort << "VLocale = usr->ix" << Prjshort << "VLocale;" << endl;
	outfile << "\tadm = (usr->ix" << Prjshort << "VUserlevel == Vec" << Prjshort << "VUserlevel::ADM);" << endl;
	outfile << endl;

	outfile << "\txchg->addBoolvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "ADMIN, jref, adm);" << endl;
	outfile << "\txchg->addBoolvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "NOADM, jref, (usr->ix" << Prjshort << "VUserlevel == Vec" << Prjshort << "VUserlevel::REG));" << endl;
	outfile << endl;

	outfile << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "GROUP, jref, usr->ref" << Prjshort << "MUsergroup);" << endl;
	outfile << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "OWNER, jref, ref" << Prjshort << "MUser);" << endl;
	outfile << endl;

	outfile << "\tdelete usr;" << endl;
	outfile << endl;

	outfile << "\t// set jrefSess (for access to " << Prjshort << "QSelect from rst-type panel queries)" << endl;
	outfile << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFSESS, jref, jref);" << endl;
	outfile << endl;

	outfile << "\t// fill query in " << Prjshort << "QSelect with all applicable user groups" << endl;
	outfile << "\tjnum = 1;" << endl;
	outfile << endl;

	outfile << "\t";
	if (accnogoall) outfile << "if (adm) ";
	outfile << "dbs" << prjshort << "->tbl" << prjshort << "qselect->insertNewRec(NULL, jref, jnum++, 0, 0);" << endl;
	outfile << endl;

	outfile << "\tif (adm) {" << endl;
	outfile << "\t\tdbs" << prjshort << "->loadRefsBySQL(\"SELECT ref FROM Tbl" << Prjshort << "MUsergroup ORDER BY ref ASC\", false, refs);" << endl;
	outfile << endl;

	outfile << "\t\tfor (unsigned int i = 0; i < refs.size(); i++) dbs" << prjshort << "->tbl" << prjshort << "qselect->insertNewRec(NULL, jref, jnum++, 0, refs[i]);" << endl;
	outfile << endl;

	outfile << "\t} else {" << endl;
	outfile << "\t\tdbs" << prjshort << "->tbl" << prjshort << "rmusermusergroup->loadRstByUsr(ref" << Prjshort << "MUser, false, urus);" << endl;
	outfile << endl;

	outfile << "\t\tfor (unsigned int i = 0; i < urus.nodes.size(); i++) {" << endl;
	outfile << "\t\t\turu = urus.nodes[i];" << endl;
	outfile << endl;

	outfile << "\t\t\tusgaccs[uru->ref" << Prjshort << "MUsergroup] = uru->ix" << Prjshort << "VUserlevel;" << endl;
	outfile << "\t\t\tdbs" << prjshort << "->tbl" << prjshort << "qselect->insertNewRec(NULL, jref, jnum++, 0, uru->ref" << Prjshort << "MUsergroup);" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\t// determine access rights for each card" << endl;
	outfile << "\tix" << Prjshort << "WAccessBase = 0;" << endl;
	outfile << "\tgetIxCrdacc(dbs" << prjshort << ", 0, adm, urus, ref" << Prjshort << "MUser, ix" << Prjshort << "WAccessBase);" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.find("Nav") != (3+4)) {
			outfile << "\tix" << Prjshort << "WAccess = ix" << Prjshort << "WAccessBase; if (!adm) getIxCrdacc(dbs" << prjshort << ", Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ", adm, urus, ref" << Prjshort << "MUser, ix" << Prjshort << "WAccess); xchg->addIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXCRDACC" << StrMod::uc(car->sref.substr(3+4)) << ", jref, ix" << Prjshort << "WAccess);" << endl;
		};
	};

	outfile << "// IP constructor.spec1 --- IEND" << endl;

	// --- constructor.spec2
	outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
	outfile << "\tstatshr.jrefCrdnav = crdnav->jref;" << endl;
	outfile << "// IP constructor.spec2 --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	// -- warnTerm
	outfile << "void Sess" << Prjshort << "::warnTerm(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tcrdnav->warnTerm(dbs" << prjshort << ");" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- term
	outfile << "void Sess" << Prjshort << "::term(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\t" << Prjshort << "MSession* ses = NULL;" << endl;
	outfile << endl;

	outfile << "\ttime_t rawtime;" << endl;
	outfile << endl;

	outfile << "\t// update session with stop time" << endl;
	outfile << "\ttime(&rawtime);" << endl;
	outfile << endl;

	outfile << "\tif (dbs" << prjshort << "->tbl" << prjshort << "msession->loadRecByRef(xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SESS, jref), &ses)) {" << endl;
	outfile << "\t\tses->stop = rawtime;" << endl;
	outfile << "\t\tdbs" << prjshort << "->tbl" << prjshort << "msession->updateRec(ses);" << endl;
	outfile << endl;

	outfile << "\t\tdelete ses;" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- checkCrdActive
	outfile << "uint Sess" << Prjshort << "::checkCrdActive(" << endl;
	outfile << "\t\t\tconst uint ix" << Prjshort << "VCard" << endl;
	outfile << "\t\t) {" << endl;

	first = true;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->Active.length() > 0) {
			outfile << "\t";

			if (first) first = false;
			else outfile << "else ";

			outfile << "if (ix" << Prjshort << "VCard == Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ") return evalCrd" << StrMod::lc(car->sref.substr(3+4)) << "Active();" << endl;
		};
	};

	outfile << endl;
	outfile << "\treturn 0;" << endl;

	outfile << "};" << endl;
	outfile << endl;

	// -- evaluation of card Active expressions
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->Active.length() > 0) {
			outfile << "uint Sess" << Prjshort << "::evalCrd" << StrMod::lc(car->sref.substr(3+4)) << "Active() {" << endl;
			outfile << "\t// " << car->Active << endl;
			outfile << endl;

			if (expr.tokenize(car->Active)) {
				if (expr.parse()) {
					outfile << "\tvector<uint> args;" << endl;
					if (expr.has(Expr::VecVNodetype::FCT, "less") || expr.has(Expr::VecVNodetype::FCT, "more")) outfile << "\tuint a, b;" << endl;
					outfile << endl;

					writePreeval(Prjshort, outfile, expr.root);
					outfile << endl;

					outfile << "\treturn(args.back());" << endl;

				} else {
					outfile << "\treturn 0;" << endl;
				};
			} else {
				outfile << "\treturn 0;" << endl;
			};

			outfile << "};" << endl;
			outfile << endl;
		};
	};

	// -- checkCrdaccess
	outfile << "uint Sess" << Prjshort << "::checkCrdaccess(" << endl;
	outfile << "\t\t\tconst uint ix" << Prjshort << "VCard" << endl;
	outfile << "\t\t) {" << endl;

	first = true;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.find("Nav") != (3+4)) {
			outfile << "\t";

			if (first) first = false;
			else outfile << "else ";

			outfile << "if (ix" << Prjshort << "VCard == Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref)
						<< ") return xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXCRDACC" << StrMod::uc(car->sref.substr(3+4)) << ", jref);" << endl;
		};
	};
	outfile << endl;

	outfile << "\treturn 0;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- getIxCrdacc
	outfile << "void Sess" << Prjshort << "::getIxCrdacc(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VCard" << endl;
	outfile << "\t\t\t, const bool adm" << endl;
	outfile << "\t\t\t, List" << Prjshort << "RMUserMUsergroup& urus" << endl;
	outfile << "\t\t\t, const ubigint ref" << Prjshort << "MUser" << endl;
	outfile << "\t\t\t, uint& ix" << Prjshort << "WAccess" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\t" << Prjshort << "RMUserMUsergroup* uru = NULL;" << endl;
	outfile << "\t" << Prjshort << "AMUsergroupAccess* usgAacc = NULL;" << endl;
	outfile << "\t" << Prjshort << "AMUserAccess* usrAacc = NULL;" << endl;
	outfile << endl;

	outfile << "\tuint ixCrdacc = 0;" << endl;
	outfile << endl;

	outfile << "\tbool first = true;" << endl;
	outfile << endl;

	outfile << "\tif (adm) {" << endl;
	outfile << "\t\tix" << Prjshort << "WAccess = Vec" << Prjshort << "WAccess::EDIT + Vec" << Prjshort << "WAccess::EXEC + Vec" << Prjshort << "WAccess::VIEW;" << endl;
	outfile << "\t\treturn;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\t// check for access rights override by any of the applicable user groups" << endl;
	outfile << "\tfor (unsigned int i = 0; i < urus.nodes.size(); i++) {" << endl;
	outfile << "\t\turu = urus.nodes[i];" << endl;
	outfile << endl;

	outfile << "\t\tif (dbs" << prjshort << "->tbl" << prjshort << "amusergroupaccess->loadRecBySQL(\"SELECT * FROM Tbl" << Prjshort << "AMUsergroupAccess WHERE ref" << Prjshort << "MUsergroup = \" + to_string(uru->ref"
				<< Prjshort << "MUsergroup) + \" AND x1Ix" << Prjshort << "VFeatgroup = \" + to_string(Vec" << Prjshort << "VFeatgroup::VEC" << PRJSHORT << "VCARD) + \" AND x2FeaSrefUix = '\" + Vec" << Prjshort << "VCard::getSref(ix"
				<< Prjshort << "VCard) + \"'\", &usgAacc)) {" << endl;
	outfile << "\t\t\tixCrdacc |= usgAacc->ix" << Prjshort << "WAccess;" << endl;
	outfile << "\t\t\tfirst = false;" << endl;
	outfile << endl;

	outfile << "\t\t\tdelete usgAacc;" << endl;
	outfile << "\t\t\tif (ixCrdacc == (Vec" << Prjshort << "WAccess::EDIT + Vec" << Prjshort << "WAccess::EXEC + Vec" << Prjshort << "WAccess::VIEW)) break;" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (!first) ix" << Prjshort << "WAccess = ixCrdacc;" << endl;
	outfile << endl;

	outfile << "\t// user access rights override user group access rights" << endl;
	outfile << "\tif (dbs" << prjshort << "->tbl" << prjshort << "amuseraccess->loadRecBySQL(\"SELECT * FROM Tbl" << Prjshort << "AMUserAccess WHERE ref" << Prjshort << "MUser = \" + to_string(ref"
				<< Prjshort << "MUser) + \" AND x1Ix" << Prjshort << "VFeatgroup = \" + to_string(Vec" << Prjshort << "VFeatgroup::VEC" << PRJSHORT << "VCARD) + \" AND x2FeaSrefUix = '\" + Vec" << Prjshort << "VCard::getSref(ix"
				<< Prjshort << "VCard) + \"'\", &usrAacc)) {" << endl;
	outfile << "\t\tix" << Prjshort << "WAccess = usrAacc->ix" << Prjshort << "WAccess;" << endl;
	outfile << "\t\tdelete usrAacc;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "};" << endl;
	outfile << endl;

	// -- checkRecaccess
	outfile << "uint Sess" << Prjshort << "::checkRecaccess(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VCard" << endl;
	outfile << "\t\t\t, const ubigint ref" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tuint retval = Vec" << Prjshort << "VRecaccess::NONE;" << endl;
	outfile << endl;

	outfile << "\tubigint grp;" << endl;
	outfile << "\tubigint own;" << endl;
	outfile << endl;

	outfile << "\tmap<ubigint,uint>::iterator it;" << endl;
	outfile << endl;

	outfile << "\tubigint ref" << Prjshort << "MUser;" << endl;
	outfile << "\tuint ix" << Prjshort << "VMaintable;" << endl;
	outfile << endl;

	outfile << "\t" << Prjshort << "AccRMUserUniversal* ausrRunv = NULL;" << endl;
	outfile << "\t" << Prjshort << "RMUsergroupUniversal* usgRunv = NULL;" << endl;
	outfile << endl;

	outfile << "\tix" << Prjshort << "VMaintable = crdToMtb(ix" << Prjshort << "VCard);" << endl;
	outfile << endl;

	outfile << "\tif (ix" << Prjshort << "VMaintable == Vec" << Prjshort << "VMaintable::VOID) {" << endl;
	outfile << "\t\tretval = Vec" << Prjshort << "VRecaccess::FULL;" << endl;
	outfile << endl;

	outfile << "\t} else if (hasGrpown(ix" << Prjshort << "VMaintable) && (ref != 0)) {" << endl;
	outfile << "\t\t// find record's group and owner" << endl;
	outfile << "\t\tdbs" << prjshort << "->loadRefBySQL(\"SELECT grp FROM \" + Vec" << Prjshort << "VMaintable::getSref(ix" << Prjshort << "VMaintable) + \" WHERE ref = \" + to_string(ref), grp);" << endl;
	outfile << "\t\tdbs" << prjshort << "->loadRefBySQL(\"SELECT own FROM \" + Vec" << Prjshort << "VMaintable::getSref(ix" << Prjshort << "VMaintable) + \" WHERE ref = \" + to_string(ref), own);" << endl;
	outfile << endl;

	outfile << "\t\t// administrators can edit any record" << endl;
	outfile << "\t\tif (xchg->getBoolvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "ADMIN, jref)) retval = Vec" << Prjshort << "VRecaccess::FULL;" << endl;
	outfile << endl;

	if (accnogoall) {
		outfile << "\t\t// all non-administrators may view non-specific records but not edit them" << endl;
		outfile << "\t\tif (retval == Vec" << Prjshort << "VRecaccess::NONE) {" << endl;
		outfile << "\t\t\tif (grp == 0) retval = Vec" << Prjshort << "VRecaccess::VIEW;" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;
	};

	outfile << "\t\tif (retval == Vec" << Prjshort << "VRecaccess::NONE) {" << endl;
	outfile << "\t\t\tref" << Prjshort << "MUser = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "OWNER, jref);" << endl;
	outfile << endl;

	outfile << "\t\t\t// a record's owner has full rights on his records" << endl;
	outfile << "\t\t\tif (ref" << Prjshort << "MUser == own) retval = Vec" << Prjshort << "VRecaccess::FULL;" << endl;
	outfile << endl;

	outfile << "\t\t\tif (retval != Vec" << Prjshort << "VRecaccess::FULL) {" << endl;
	outfile << "\t\t\t\t// individual record access right" << endl;
	outfile << "\t\t\t\tif (dbs" << prjshort << "->tbl" << prjshort << "accrmuseruniversal->loadRecByUsrMtbUnv(ref" << Prjshort << "MUser, ix" << Prjshort << "VMaintable, ref, &ausrRunv)) {" << endl;
	outfile << "\t\t\t\t\tretval = ausrRunv->ix" << Prjshort << "VRecaccess;" << endl;
	outfile << "\t\t\t\t\tdelete ausrRunv;" << endl;
	outfile << "\t\t\t\t};" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\tif (retval != Vec" << Prjshort << "VRecaccess::FULL) {" << endl;
	outfile << "\t\t\t\tit = usgaccs.find(grp);" << endl;
	outfile << "\t\t\t\tif (it != usgaccs.end()) {" << endl;
	outfile << "\t\t\t\t\tif (it->second == Vec" << Prjshort << "VUserlevel::GADM) {" << endl;
	outfile << "\t\t\t\t\t\t// group admins have full access to all of the group's records" << endl;
	outfile << "\t\t\t\t\t\tretval = Vec" << Prjshort << "VRecaccess::FULL;" << endl;
	if (accgrpreg) {
		outfile << "\t\t\t\t\t} else {" << endl;
		outfile << "\t\t\t\t\t\t// other group members have view access only" << endl;
		outfile << "\t\t\t\t\t\tretval = Vec" << Prjshort << "VRecaccess::VIEW;" << endl;
	};
	outfile << "\t\t\t\t\t};" << endl;
	outfile << "\t\t\t\t};" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\tif (retval != Vec" << Prjshort << "VRecaccess::FULL) {" << endl;
	outfile << "\t\t\t\t// individual record access right due to group membership" << endl;
	outfile << "\t\t\t\tfor (it = usgaccs.begin(); it != usgaccs.end(); it++) {" << endl;
	outfile << endl;

	if (accgrpreg) {
		outfile << "\t\t\t\t\tif (dbs" << prjshort << "->tbl" << prjshort << "rmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ix" << Prjshort << "VMaintable, ref, &usgRunv)) {" << endl;
		outfile << "\t\t\t\t\t\tif (usgRunv->ix" << Prjshort << "VRecaccess == Vec" << Prjshort << "VRecaccess::FULL) retval = Vec" << Prjshort << "VRecaccess::FULL;" << endl;
		outfile << "\t\t\t\t\t\telse retval = Vec" << Prjshort << "VRecaccess::VIEW;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\tdelete usgRunv;" << endl;
		outfile << "\t\t\t\t\t};" << endl;
	} else {
		outfile << "\t\t\t\t\tif (it->second == Vec" << Prjshort << "VUserlevel::GADM) {" << endl;
		outfile << "\t\t\t\t\t\tif (dbs" << prjshort << "->tbl" << prjshort << "rmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ix" << Prjshort << "VMaintable, ref, &usgRunv)) {" << endl;
		outfile << "\t\t\t\t\t\t\tif (usgRunv->ix" << Prjshort << "VRecaccess == Vec" << Prjshort << "VRecaccess::FULL) retval = Vec" << Prjshort << "VRecaccess::FULL;" << endl;
		outfile << "\t\t\t\t\t\t\telse retval = Vec" << Prjshort << "VRecaccess::VIEW;" << endl;
		outfile << endl;

		outfile << "\t\t\t\t\t\t\tdelete usgRunv;" << endl;
		outfile << "\t\t\t\t\t\t};" << endl;
		outfile << "\t\t\t\t\t};" << endl;
	};
	outfile << endl;

	outfile << "\t\t\t\t\tif (retval == Vec" << Prjshort << "VRecaccess::FULL) break;" << endl;
	outfile << "\t\t\t\t};" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t} else {" << endl;
	outfile << "\t\tif (xchg->getBoolvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "ADMIN, jref)) retval = Vec" << Prjshort << "VRecaccess::FULL;" << endl;
	outfile << "\t\telse retval = Vec" << Prjshort << "VRecaccess::VIEW;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\treturn retval;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- logRecaccess
	outfile << "void Sess" << Prjshort << "::logRecaccess(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VPreset" << endl;
	outfile << "\t\t\t, const ubigint preUref" << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VCard" << endl;
	outfile << "\t\t\t, const ubigint unvUref" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tvector<ubigint> refs;" << endl;
	outfile << endl;

	outfile << "\tubigint ref" << Prjshort << "MUser;" << endl;
	outfile << "\tuint unvIx" << Prjshort << "VMaintable;" << endl;
	outfile << "\tuint preIx" << Prjshort << "VMaintable;" << endl;
	outfile << endl;

	outfile << "\t" << Prjshort << "HistRMUserUniversal* husrRunv = NULL;" << endl;
	outfile << endl;

	outfile << "\tif (xchg->stg" << prjshort << "appearance.histlength > 0) {" << endl;
	outfile << "\t\tref" << Prjshort << "MUser = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "OWNER, jref);" << endl;
	outfile << "\t\tunvIx" << Prjshort << "VMaintable = crdToMtb(ix" << Prjshort << "VCard);" << endl;
	outfile << "\t\tpreIx" << Prjshort << "VMaintable = preToMtb(ix" << Prjshort << "VPreset);" << endl;
	outfile << endl;

	outfile << "\t\tif (!dbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->loadRecByUsrMtbUnvCrd(ref" << Prjshort << "MUser, unvIx" << Prjshort << "VMaintable, unvUref, ix" << Prjshort << "VCard, &husrRunv)) {" << endl;

	outfile << "\t\t\thusrRunv = new " << Prjshort << "HistRMUserUniversal(0, ref" << Prjshort << "MUser, unvIx" << Prjshort << "VMaintable, unvUref, ix" << Prjshort << "VCard, ix" << Prjshort << "VPreset, preIx" << Prjshort << "VMaintable, preUref, 0);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t\thusrRunv->start = time(NULL);" << endl;
	outfile << endl;

	outfile << "\t\tif (husrRunv->ref == 0) {" << endl;
	outfile << "\t\t\tdbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->insertRec(husrRunv);" << endl;
	outfile << endl;

	outfile << "\t\t\tdbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->loadRefsByUsrMtbCrd(ref" << Prjshort << "MUser, unvIx" << Prjshort << "VMaintable, ix" << Prjshort << "VCard, false, refs, 4294967296, xchg->stg" << prjshort << "appearance.histlength);" << endl;
	outfile << "\t\t\tfor (unsigned int i = 0; i < refs.size(); i++) dbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->removeRecByRef(refs[i]);" << endl;
	outfile << endl;

	outfile << "\t\t} else dbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->updateRec(husrRunv);" << endl;
	outfile << endl;

	outfile << "\t\txchg->triggerIxRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "HUSRRUNVMOD_CRDUSREQ, jref, ix" << Prjshort << "VCard, ref" << Prjshort << "MUser);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tdelete husrRunv;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- crdToMtb
	outfile << "uint Sess" << Prjshort << "::crdToMtb(" << endl;
	outfile << "\t\t\tconst uint ix" << Prjshort << "VCard" << endl;
	outfile << "\t\t) {" << endl;
	
	first = true;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		s = "";

		if (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) {
			dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMTable WHERE ref = " + to_string(car->refUref), s);
		} else if (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) {
			dbswznm->loadStringBySQL("SELECT TblWznmMTable.sref FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = TblWznmMSubset.refWznmMTable AND TblWznmMSubset.ref = " + to_string(car->refUref), s);
		};

		if (s.length() > 0) {
			outfile << "\t";
			if (first) first = false; else outfile << "else ";
			outfile << "if (ix" << Prjshort << "VCard == Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ") return Vec" << Prjshort << "VMaintable::" << StrMod::uc(s) << ";" << endl;
		};
	};
	outfile << endl;

	outfile << "\treturn Vec" << Prjshort << "VMaintable::VOID;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- preToMtb
	outfile << "uint Sess" << Prjshort << "::preToMtb(" << endl;
	outfile << "\t\t\tconst uint ix" << Prjshort << "VPreset" << endl;
	outfile << "\t\t) {" << endl;

	first = true;
	for (unsigned int i = 0; i < psts.nodes.size(); i++) {
		pst = psts.nodes[i];

		s = "";

		if (pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) {
			dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMTable WHERE ref = " + to_string(pst->refUref) + " AND ixVBasetype = " + to_string(VecWznmVMTableBasetype::MAIN), s);
		} else if (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS) {
			dbswznm->loadStringBySQL("SELECT TblWznmMTable.sref FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = TblWznmMSubset.refWznmMTable AND TblWznmMTable.ixVBasetype = "
						+ to_string(VecWznmVMTableBasetype::MAIN) + " AND TblWznmMSubset.ref = " + to_string(pst->refUref), s);
		};

		if (s.length() > 0) {
			outfile << "\t";
			if (first) first = false; else outfile << "else ";
			outfile << "if (ix" << Prjshort << "VPreset == Vec" << Prjshort << "VPreset::" << StrMod::uc(pst->sref) << ") return Vec" << Prjshort << "VMaintable::" << StrMod::uc(s) << ";" << endl;
		};
	};
	outfile << endl;

	outfile << "\treturn Vec" << Prjshort << "VMaintable::VOID;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- hasActive
	outfile << "bool Sess" << Prjshort << "::hasActive(" << endl;
	outfile << "\t\t\tconst uint ix" << Prjshort << "VCard" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\treturn(";
	first = true;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->Active.length() > 0) {
			if (first) first = false; else outfile << " || ";
			outfile << "(ix" << Prjshort << "VCard == Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ")";
		};
	};
	if (first) outfile << "false";
	outfile << ");" << endl;

	outfile << "};" << endl;
	outfile << endl;

	// -- hasGrpown
	outfile << "bool Sess" << Prjshort << "::hasGrpown(" << endl;
	outfile << "\t\t\tconst uint ix" << Prjshort << "VMaintable" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\treturn(";
	first = true;
	for (unsigned int i = 0; i < mtbs.nodes.size(); i++) {
		mtb = mtbs.nodes[i];

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(mtb->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::GRP), cnt);

		if (cnt > 0) {
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(mtb->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::OWN), cnt);

			if (cnt > 0) {
				if (first) first = false; else outfile << " || ";
				outfile << "(ix" << Prjshort << "VMaintable == Vec" << Prjshort << "VMaintable::" << StrMod::uc(mtb->sref) << ")";
			};
		};
	};
	if (first) outfile << "false";
	outfile << ");" << endl;

	outfile << "};" << endl;
	outfile << endl;

	outfile << "// IP spec --- IEND" << endl;

	// --- handleDpchAppXxxxInit
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IBEGIN" << endl;
	outfile << "\tFeed feedFEnsSec(\"FeedFEnsSec\");" << endl;
	outfile << endl;

	outfile << "\t// resume session" << endl;
	outfile << "\txchg->removePreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SUSPSESS, jref);" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.find("Nav") != (3+4)) {
			outfile << "\tfor (auto it = crd" << StrMod::lc(car->sref.substr(3+4)) << "s.begin(); it != crd" << StrMod::lc(car->sref.substr(3+4))
						<< "s.end(); it++) feedFEnsSec.appendIxSrefTitles(0, Scr::scramble((*it)->jref), \"" << car->sref << "\");" << endl;
		};
	};
	outfile << endl;

	outfile << "\t*dpcheng = new DpchEngData(jref, &feedFEnsSec, &statshr, {DpchEngData::ALL});" << endl;
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IEND" << endl;

	// --- handleCreateCrdxxxxx
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.find("Nav") != (3+4)) {
			outfile << "// IP handleCreateCrd" << StrMod::lc(car->sref.substr(3+4)) << " --- IBEGIN" << endl;

			outfile << "\t" << car->sref << "* crd" << StrMod::lc(car->sref.substr(3+4)) << " = NULL;" << endl;
			outfile << endl;

			if (car->Active.length() != 0) {
				outfile << "\tuint ix" << Prjshort << "VPreset = evalCrd" << StrMod::lc(car->sref.substr(3+4)) << "Active();" << endl;
				outfile << endl;

				outfile << "\tif (ix" << Prjshort << "VPreset == 0) {" << endl;
				outfile << "\t\tcout << \"\\tcard is not activated!\" << endl;" << endl;
				outfile << "\t} else {" << endl;
			};

			if (car->Active.length() == 0) pre = "\t"; else pre = "\t\t";

			outfile << pre << "crd" << StrMod::lc(car->sref.substr(3+4)) << " = new " << car->sref << "(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale";
			if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS)) outfile <<  ", 0";
			if (car->Active.length() != 0) outfile << ", ix" << Prjshort << "VPreset, xchg->getRefPreset(ix" << Prjshort << "VPreset, jref)";
			outfile << ");" << endl;
			outfile << pre << "crd" << StrMod::lc(car->sref.substr(3+4)) << "s.push_back(crd" << StrMod::lc(car->sref.substr(3+4)) << ");" << endl;

			outfile << pre << "cout << \"\\tjob reference: \" << crd" << StrMod::lc(car->sref.substr(3+4)) << "->jref << endl;" << endl;
			outfile << pre << "xchg->jrefCmd = crd" << StrMod::lc(car->sref.substr(3+4)) << "->jref;" << endl;

			if (car->Active.length() != 0) outfile << "\t};" << endl;

			outfile << endl;

			outfile << "\treturn false;" << endl;
			outfile << "// IP handleCreateCrd" << StrMod::lc(car->sref.substr(3+4)) << " --- IEND" << endl;

			outfile << "// IP handleEraseCrd" << StrMod::lc(car->sref.substr(3+4)) << " --- IBEGIN" << endl;
			outfile << "\tstring input;" << endl;
			outfile << "\tuint iinput;" << endl;
			outfile << endl;

			outfile << "\t" << car->sref << "* crd" << StrMod::lc(car->sref.substr(3+4)) << " = NULL;" << endl;
			outfile << endl;

			outfile << "\tcout << \"\\tjob reference: \";" << endl;
			outfile << "\tcin >> input;" << endl;
			outfile << "\tiinput = atoi(input.c_str());" << endl;
			outfile << endl;

			outfile << "\tfor (auto it = crd" << StrMod::lc(car->sref.substr(3+4)) << "s.begin(); it != crd" << StrMod::lc(car->sref.substr(3+4)) << "s.end();) {" << endl;
			outfile << "\t\tcrd" << StrMod::lc(car->sref.substr(3+4)) << " = *it;" << endl;
			outfile << "\t\tif (crd" << StrMod::lc(car->sref.substr(3+4)) << "->jref == iinput) {" << endl;
			outfile << "\t\t\tit = crd" << StrMod::lc(car->sref.substr(3+4)) << "s.erase(it);" << endl;
			outfile << "\t\t\tdelete crd" << StrMod::lc(car->sref.substr(3+4)) << ";" << endl;
			outfile << "\t\t\tbreak;" << endl;
			outfile << "\t\t} else it++;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "// IP handleEraseCrd" << StrMod::lc(car->sref.substr(3+4)) << " --- IEND" << endl;
		};
	};

	// --- handleCallXxxxCrdActive
	outfile << "// IP handleCall" << Prjshort << "CrdActive --- IBEGIN" << endl;
	outfile << "\tixRet = checkCrdActive(ixInv);" << endl;
	outfile << "// IP handleCall" << Prjshort << "CrdActive --- IEND" << endl;

	// --- handleCallXxxxCrdClose
	outfile << "// IP handleCall" << Prjshort << "CrdClose --- IBEGIN" << endl;

	outfile << "\t// delete only if card is not part of a suspended session" << endl;
	outfile << "\tif (xchg->getBoolvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SUSPSESS, jrefTrig)) return retval;" << endl;
	outfile << endl;

	outfile << "\tubigint jrefNotif = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFNOTIFY, jref);" << endl;
	outfile << "\tif (jrefNotif == jrefTrig) xchg->removePreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFNOTIFY, jref);" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (ixInv == Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ") {" << endl;

		if (car->sref.find("Nav") == (3+4)) {
			outfile << "\t\tif (crdnav) {" << endl;
			outfile << "\t\t\tdelete crdnav;" << endl;
			outfile << "\t\t\tcrdnav = NULL;" << endl;
			outfile << "\t\t};" << endl;
			outfile << endl;

		} else {
			// regular card
			outfile << "\t\t" << car->sref << "* crd" << StrMod::lc(car->sref.substr(3+4)) << " = NULL;" << endl;
			outfile << endl;

			outfile << "\t\tfor (auto it = crd" << StrMod::lc(car->sref.substr(3+4)) << "s.begin(); it != crd" << StrMod::lc(car->sref.substr(3+4)) << "s.end();) {" << endl;
			outfile << "\t\t\tcrd" << StrMod::lc(car->sref.substr(3+4)) << " = *it;" << endl;
			outfile << "\t\t\tif (crd" << StrMod::lc(car->sref.substr(3+4)) << "->jref == jrefTrig) {" << endl;
			outfile << "\t\t\t\tit = crd" << StrMod::lc(car->sref.substr(3+4)) << "s.erase(it);" << endl;
			outfile << "\t\t\t\tdelete crd" << StrMod::lc(car->sref.substr(3+4)) << ";" << endl;
			outfile << "\t\t\t\tbreak;" << endl;
			outfile << "\t\t\t} else it++;" << endl;
			outfile << "\t\t};" << endl;
		};
	};
	if (cars.nodes.size() > 0) outfile << "\t};" << endl;
	outfile << "// IP handleCall" << Prjshort << "CrdClose --- IEND" << endl;

	// --- handleCallXxxxCrdOpen
	outfile << "// IP handleCall" << Prjshort << "CrdOpen --- IBEGIN" << endl;

	outfile << "\tbool denied = false;" << endl;
	outfile << endl;

	outfile << "\tuint ix" << Prjshort << "VCard = Vec" << Prjshort << "VCard::getIx(srefInv);" << endl;
	outfile << endl;

	outfile << "\tubigint ref = (ubigint) intvalInv;" << endl;
	outfile << "\tif (intvalInv == -1) {" << endl;
	outfile << "\t\tref = 0;" << endl;
	outfile << "\t\tref--;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tuint ix" << Prjshort << "VPreset;" << endl;
	outfile << "\tubigint preUref = 0;" << endl;
	outfile << endl;

	outfile << "\tuint ix" << Prjshort << "WAccess;" << endl;
	outfile << "\tuint ix" << Prjshort << "VRecaccess;" << endl;
	outfile << endl;

	outfile << "\tif (hasActive(ix" << Prjshort << "VCard)) {" << endl;
	outfile << "\t\tif (ixInv == 0) {" << endl;
	outfile << "\t\t\tix" << Prjshort << "VPreset = checkCrdActive(ix" << Prjshort << "VCard);" << endl;
	outfile << "\t\t\tif (ix" << Prjshort << "VPreset == 0) {" << endl;
	outfile << "\t\t\t\tdenied = true;" << endl;
	outfile << "\t\t\t} else {" << endl;
	outfile << "\t\t\t\tpreUref = xchg->getRefPreset(ix" << Prjshort << "VPreset, jref);" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t} else {" << endl;
	outfile << "\t\t\tix" << Prjshort << "VPreset = ixInv;" << endl;
	outfile << "\t\t\tpreUref = refInv;" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (!denied) {" << endl;
	outfile << "\t\tix" << Prjshort << "WAccess = checkCrdaccess(ix" << Prjshort << "VCard);" << endl;
	outfile << "\t\tdenied = (ix" << Prjshort << "WAccess == 0);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (!denied) {" << endl;
	outfile << "\t\tif (intvalInv == -1) {" << endl;
	outfile << "\t\t\tdenied = (((ix" << Prjshort << "WAccess & Vec" << Prjshort << "WAccess::EDIT) == 0) || ((ix" << Prjshort << "WAccess & Vec" << Prjshort << "WAccess::EXEC) == 0));" << endl;
	outfile << "\t\t} else if (intvalInv > 0) {" << endl;
	outfile << "\t\t\tix" << Prjshort << "VRecaccess = checkRecaccess(dbs" << prjshort << ", ix" << Prjshort << "VCard, intvalInv);" << endl;
	outfile << "\t\t\tdenied = (ix" << Prjshort << "VRecaccess == Vec" << Prjshort << "VRecaccess::NONE);" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (denied) {" << endl;
	outfile << "\t\trefRet = 0;" << endl;
	outfile << endl;

	outfile << "\t} else {" << endl;

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		outfile << "\t\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (ix" << Prjshort << "VCard == Vec" << Prjshort << "VCard::" << StrMod::uc(car->sref) << ") {" << endl;

		if (car->sref.find("Nav") != (3+4)) {
			outfile << "\t\t\t" << car->sref << "* crd" << StrMod::lc(car->sref.substr(3+4)) << " = NULL;" << endl;
			outfile << endl;

			outfile << "\t\t\tcrd" << StrMod::lc(car->sref.substr(3+4)) << " = new " << car->sref << "(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale";
			if ((car->refIxVTbl == VecWznmVMCardRefTbl::TBL) || (car->refIxVTbl == VecWznmVMCardRefTbl::SBS)) outfile << ", ref";
			if (car->Active.length() > 0) outfile << ", ix" << Prjshort << "VPreset, preUref";
			outfile << ");" << endl;

			outfile << "\t\t\tcrd" << StrMod::lc(car->sref.substr(3+4)) << "s.push_back(crd" << StrMod::lc(car->sref.substr(3+4)) << ");" << endl;
			outfile << endl;

			outfile << "\t\t\trefRet = crd" << StrMod::lc(car->sref.substr(3+4)) << "->jref;" << endl;
			outfile << endl;
		};
	};
	if (cars.nodes.size() > 0) outfile << "\t\t};" << endl;

	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "// IP handleCall" << Prjshort << "CrdOpen --- IEND" << endl;

	// --- handleCallXxxxLog
	outfile << "// IP handleCall" << Prjshort << "Log --- IBEGIN" << endl;
	outfile << "\tlogRecaccess(dbs" << prjshort << ", ixInv, refInv, Vec" << Prjshort << "VCard::getIx(srefInv), intvalInv);" << endl;
	outfile << "// IP handleCall" << Prjshort << "Log --- IEND" << endl;

	// --- handleCallXxxxRecccess
	outfile << "// IP handleCall" << Prjshort << "Recaccess --- IBEGIN" << endl;
	outfile << "\tixRet = checkRecaccess(dbs" << prjshort << ", ixInv, refInv);" << endl;
	outfile << "// IP handleCall" << Prjshort << "Recaccess --- IEND" << endl;

	// --- handleCallXxxxRefPreSet
	outfile << "// IP handleCall" << Prjshort << "RefPreSet --- IBEGIN" << endl;

	outfile << "\tif (ixInv == Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFNOTIFY) {" << endl;
	outfile << "\t\tubigint jrefNotify_old = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "JREFNOTIFY, jref);" << endl;
	outfile << endl;

	outfile << "\t\tif (refInv != jrefNotify_old) {" << endl;
	outfile << "\t\t\tif (jrefNotify_old != 0) xchg->submitDpch(new DpchEng" << Prjshort << "Suspend(jrefNotify_old));" << endl;
	outfile << endl;
		
	outfile << "\t\t\tif (refInv == 0) xchg->removePreset(ixInv, jref);" << endl;
	outfile << "\t\t\telse xchg->addRefPreset(ixInv, jref, refInv);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t} else if (ixInv == Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "TLAST) {" << endl;
	outfile << "\t\tif (xchg->stg" << prjshort << "appearance.sesstterm != 0) xchg->addRefPreset(ixInv, jref, refInv);" << endl;
	outfile << endl;

	first = true;
	for (unsigned int i = 0; i < psts.nodes.size(); i++) {
		pst = psts.nodes[i];
		if ((pst->ixVScope == VecWznmVMPresetScope::SESS) && ((pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) || (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS))) {
			first = false;
			break;
		};
	};

	if (first) {
		outfile << "\t};" << endl;

	} else {
		outfile << "\t} else if (";

		first = true;
		for (unsigned int i = 0; i < psts.nodes.size(); i++) {
			pst = psts.nodes[i];

			if ((pst->ixVScope == VecWznmVMPresetScope::SESS) && ((pst->refIxVTbl == VecWznmVMPresetRefTbl::TBL) || (pst->refIxVTbl == VecWznmVMPresetRefTbl::SBS))) {
				if (first) first = false; else outfile << " || ";
				outfile << "(ixInv == Vec" << Prjshort << "VPreset::" << StrMod::uc(pst->sref) << ")";
			};
		};

		outfile << ") {" << endl;
		outfile << "\t\tif (refInv == 0) xchg->removePreset(ixInv, jref);" << endl;
		outfile << "\t\telse xchg->addRefPreset(ixInv, jref, refInv);" << endl;
		outfile << endl;

		outfile << "\t\tif (crdnav) crdnav->updatePreset(dbs" << prjshort << ", ixInv, jrefTrig, true);" << endl;
		outfile << "\t};" << endl;
	};

	outfile << "// IP handleCall" << Prjshort << "RefPreSet --- IEND" << endl;
};

void WznmWrsrvRootsess::writeM2msessH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
		) {
	string prjshort = StrMod::lc(Prjshort);

	// --- constructor
	outfile << "// IP constructor --- RBEGIN" << endl;
	outfile << "\tM2msess" << Prjshort << "(Xchg" << Prjshort << "* xchg, Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::ubigint jrefSup, const Sbecore::ubigint ref" << Prjshort << "MUser, const std::string& ip);" << endl;
	outfile << "// IP constructor --- REND" << endl;

	// --- specVar
	outfile << "// IP vars.spec --- IBEGIN" << endl;
	outfile << "\tstd::multimap<Sbecore::featix_t,Sbecore::uint> accs;" << endl;
	outfile << "// IP vars.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tvoid term(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << endl;

	outfile << "\tSbecore::uint addAccBase(Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::uint ix" << Prjshort << "VFeatgroup, const bool adm, List" << Prjshort << "RMUserMUsergroup& urus, const Sbecore::ubigint ref" << Prjshort << "MUser);" << endl;
	outfile << "\tvoid addAcc(Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::uint ix" << Prjshort << "VFeatgroup, const std::string& srefIxVFeature, List" << Prjshort << "RMUserMUsergroup& urus, const Sbecore::ubigint ref" << Prjshort << "MUser, const Sbecore::uint ix" << Prjshort << "WAccessBase);" << endl;
	outfile << endl;

	outfile << "\tvoid getIxAcc(Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::uint ix" << Prjshort << "VFeatgroup, const std::string& srefIxVFeature, const bool adm, List" << Prjshort << "RMUserMUsergroup& urus, const Sbecore::ubigint ref" << Prjshort << "MUser, Sbecore::uint& ix" << Prjshort << "WAccess);" << endl;
	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvRootsess::writeM2msessCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, const string& Prjshort
		) {
	ListWznmRMJobMJob jrjs;
	WznmRMJobMJob* jrj = NULL;

	ListWznmMJob subjobs;
	WznmMJob* subjob = NULL;

	ListWznmMMethod mtds;
	WznmMMethod* mtd = NULL;

	ListWznmAMJobVar vars;
	vector<string> varsrefs;
	vector<bool> Shrs;
	vector<unsigned int> Ns;

	uint cnt;

	bool hasmtd, hasvar;

	dbswznm->tblwznmrmjobmjob->loadRstBySup(job->ref, false, jrjs);

	subjobs.nodes.resize(jrjs.nodes.size(), NULL);
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) dbswznm->tblwznmmjob->loadRecByRef(jrjs.nodes[i]->subRefWznmMJob, &(subjobs.nodes[i]));

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	// --- constructor.hdr
	outfile << "// IP constructor.hdr --- RBEGIN" << endl;
	outfile << "M2msess" << Prjshort << "::M2msess" << Prjshort << "(" << endl;
	outfile << "\t\t\tXchg" << Prjshort << "* xchg" << endl;
	outfile << "\t\t\t, Dbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const ubigint jrefSup" << endl;
	outfile << "\t\t\t, const ubigint ref" << Prjshort << "MUser" << endl;
	outfile << "\t\t\t, const string& ip" << endl;
	outfile << "\t\t) :" << endl;
	outfile << "\t\t\tJob" << Prjshort << "(xchg, Vec" << Prjshort << "VJob::M2MSESS" << PRJSHORT << ", jrefSup)" << endl;
	outfile << "\t\t{" << endl;
	outfile << "// IP constructor.hdr --- REND" << endl;

	// --- constructor.spec1
	outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
	outfile << "\tvector<ubigint> refs;" << endl;
	outfile << endl;

	outfile << "\tubigint refSes;" << endl;
	outfile << endl;

	outfile << "\t" << Prjshort << "MUser* usr = NULL;" << endl;
	outfile << endl;

	outfile << "\tbool adm;" << endl;
	outfile << endl;

	outfile << "\tList" << Prjshort << "RMUserMUsergroup urus;" << endl;
	outfile << endl;

	outfile << "\tuint ix" << Prjshort << "WAccessBase;" << endl;
	outfile << endl;

	outfile << "\t// create new session with start time" << endl;
	outfile << "\ttime_t rawtime;" << endl;
	outfile << "\ttime(&rawtime);" << endl;
	outfile << endl;

	outfile << "\trefSes = dbs" << prjshort << "->tbl" << prjshort << "msession->insertNewRec(NULL, ref" << Prjshort << "MUser, (uint) rawtime, 0, ip);" << endl;
	outfile << endl;

	outfile << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SESS, jref, refSes);" << endl;
	outfile << "\txchg->addTxtvalPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IP, jref, ip);" << endl;
	outfile << endl;

	outfile << "\t// set locale and presetings corresponding to user" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "muser->loadRecByRef(ref" << Prjshort << "MUser, &usr);" << endl;
	outfile << endl;

	outfile << "\tix" << Prjshort << "VLocale = usr->ix" << Prjshort << "VLocale;" << endl;
	outfile << "\tadm = (usr->ix" << Prjshort << "VUserlevel == Vec" << Prjshort << "VUserlevel::ADM);" << endl;
	outfile << endl;

	outfile << "\tdelete usr;" << endl;
	outfile << endl;

	outfile << "\tif (!adm) dbs" << prjshort << "->tbl" << prjshort << "rmusermusergroup->loadRstByUsr(ref" << Prjshort << "MUser, false, urus);" << endl;
	outfile << endl;

	outfile << "\t// determine access rights for each feature group and feature" << endl;

	for (unsigned int i = 0; i < subjobs.nodes.size(); i++) {
		subjob = subjobs.nodes[i];

		if (subjob) {
			dbswznm->tblwznmmmethod->loadRstByJob(subjob->ref, false, mtds);
			if (mtds.nodes.size() > 0) {
				outfile << "\tix" << Prjshort << "WAccessBase = addAccBase(dbs" << prjshort << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(subjob->sref) << "METHOD, adm, urus, ref" << Prjshort << "MUser);" << endl;
				outfile << "\tif (!adm) {" << endl;
				for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
					mtd = mtds.nodes[j];
					outfile << "\t\taddAcc(dbs" << prjshort << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(subjob->sref) << "METHOD, \"" << mtd->sref << "\", urus, ref" << Prjshort << "MUser, ix" << Prjshort << "WAccessBase);" << endl;
				};
				outfile << "\t};" << endl;
			};

			Wznm::getJobvars(dbswznm, subjob->ref, vars, varsrefs, Shrs, Ns);
			if (varsrefs.size() > 0) {
				outfile << "\tix" << Prjshort << "WAccessBase = addAccBase(dbs" << prjshort << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(subjob->sref) << "VAR, adm, urus, ref" << Prjshort << "MUser);" << endl;
				outfile << "\tif (!adm) {" << endl;
				for (unsigned int j = 0; j < varsrefs.size(); j++) {
					outfile << "\t\taddAcc(dbs" << prjshort << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(subjob->sref) << "VAR, \"" << varsrefs[j] << "\", urus, ref" << Prjshort << "MUser, ix" << Prjshort << "WAccessBase);" << endl;
				};
				outfile << "\t};" << endl;
			};
		};
	};
	outfile << endl;

	outfile << "\t// create jobs according to access rights" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		subjob = subjobs.nodes[i];

		if (subjob) {
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMMethod WHERE refWznmMJob = " + to_string(subjob->ref), cnt);
			hasmtd = (cnt > 0);

			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMJobVar WHERE jobRefWznmMJob = " + to_string(subjob->ref), cnt);
			hasvar = (cnt > 0);

			if (hasmtd || hasvar) {
				outfile << "\tif ";

				if (hasmtd && hasvar) outfile << "( ";
				if (hasmtd) outfile << "(accs.find(featix_t(Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(subjob->sref) << "METHOD, \"\")) != accs.end())";
				if (hasmtd && hasvar) outfile << " || ";
				if (hasvar) outfile << "(accs.find(featix_t(Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(subjob->sref) << "VAR, \"\")) != accs.end())";
				if (hasmtd && hasvar) outfile << " )";
				outfile << " {" << endl;

				outfile << "\t\t" << jrj->Short  << " = new " << subjob->sref << "(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale);" << endl;
				outfile << "\t\tstatshr.jref" << StrMod::cap(jrj->Short) << " = " << jrj->Short << "->jref;" << endl;

				outfile << "\t};" << endl;
			};
		};
	};
	outfile << "// IP constructor.spec1 --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	// -- term
	outfile << "void M2msess" << Prjshort << "::term(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\t" << Prjshort << "MSession* ses = NULL;" << endl;
	outfile << endl;

	outfile << "\ttime_t rawtime;" << endl;
	outfile << endl;

	outfile << "\t// update session with stop time" << endl;
	outfile << "\ttime(&rawtime);" << endl;
	outfile << endl;

	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "msession->loadRecByRef(xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "SESS, jref), &ses);" << endl;
	outfile << "\tses->stop = rawtime;" << endl;
	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "msession->updateRec(ses);" << endl;
	outfile << endl;

	outfile << "\tdelete ses;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- addAccBase
	outfile << "uint M2msess" << Prjshort << "::addAccBase(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VFeatgroup" << endl;
	outfile << "\t\t\t, const bool adm" << endl;
	outfile << "\t\t\t, List" << Prjshort << "RMUserMUsergroup& urus" << endl;
	outfile << "\t\t\t, const ubigint ref" << Prjshort << "MUser" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tuint ix" << Prjshort << "WAccess = 0;" << endl;
	outfile << endl;

	outfile << "\tgetIxAcc(dbs" << prjshort << ", ix" << Prjshort << "VFeatgroup, \"\", adm, urus, ref" << Prjshort << "MUser, ix" << Prjshort << "WAccess);" << endl;
	outfile << "\tif (ix" << Prjshort << "WAccess != 0) accs.insert(pair<featix_t,uint>(featix_t(ix" << Prjshort << "VFeatgroup, \"\"), ix" << Prjshort << "WAccess));" << endl;
	outfile << endl;

	outfile << "\treturn ix" << Prjshort << "WAccess;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- addAcc
	outfile << "void M2msess" << Prjshort << "::addAcc(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VFeatgroup" << endl;
	outfile << "\t\t\t, const string& srefIxVFeature" << endl;
	outfile << "\t\t\t, List" << Prjshort << "RMUserMUsergroup& urus" << endl;
	outfile << "\t\t\t, const ubigint ref" << Prjshort << "MUser" << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "WAccessBase" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tuint ix" << Prjshort << "WAccess = ix" << Prjshort << "WAccessBase;" << endl;
	outfile << endl;

	outfile << "\tgetIxAcc(dbs" << prjshort << ", ix" << Prjshort << "VFeatgroup, srefIxVFeature, false, urus, ref" << Prjshort << "MUser, ix" << Prjshort << "WAccess);" << endl;
	outfile << "\tif (ix" << Prjshort << "WAccess != ix" << Prjshort << "WAccessBase) accs.insert(pair<featix_t,uint>(featix_t(ix" << Prjshort << "VFeatgroup, srefIxVFeature), ix" << Prjshort << "WAccess));" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- getIxAcc
	outfile << "void M2msess" << Prjshort << "::getIxAcc(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const uint ix" << Prjshort << "VFeatgroup" << endl;
	outfile << "\t\t\t, const string& srefIxVFeature" << endl;
	outfile << "\t\t\t, const bool adm" << endl;
	outfile << "\t\t\t, List" << Prjshort << "RMUserMUsergroup& urus" << endl;
	outfile << "\t\t\t, const ubigint ref" << Prjshort << "MUser" << endl;
	outfile << "\t\t\t, uint& ix" << Prjshort << "WAccess" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\t" << Prjshort << "RMUserMUsergroup* uru = NULL;" << endl;
	outfile << "\t" << Prjshort << "AMUsergroupAccess* usgAacc = NULL;" << endl;
	outfile << "\t" << Prjshort << "AMUserAccess* usrAacc = NULL;" << endl;
	outfile << endl;

	outfile << "\tuint ixAcc = 0;" << endl;
	outfile << endl;

	outfile << "\tbool first = true;" << endl;
	outfile << endl;

	outfile << "\tif (adm) {" << endl;
	outfile << "\t\tix" << Prjshort << "WAccess = Vec" << Prjshort << "WAccess::EDIT + Vec" << Prjshort << "WAccess::EXEC + Vec" << Prjshort << "WAccess::VIEW;" << endl;
	outfile << "\t\treturn;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\t// check for access rights override by any of the applicable user groups" << endl;
	outfile << "\tfor (unsigned int i = 0; i < urus.nodes.size(); i++) {" << endl;
	outfile << "\t\turu = urus.nodes[i];" << endl;
	outfile << endl;

	outfile << "\t\tif (dbs" << prjshort << "->tbl" << prjshort << "amusergroupaccess->loadRecBySQL(\"SELECT * FROM Tbl" << Prjshort << "AMUsergroupAccess WHERE ref" << Prjshort << "MUsergroup = \" + to_string(uru->ref" << Prjshort << "MUsergroup) + \" AND x1Ix" << Prjshort << "VFeatgroup = \" + to_string(ix" << Prjshort << "VFeatgroup) + \" AND x2FeaSrefUix = '\" + srefIxVFeature + \"'\", &usgAacc)) {" << endl;
	outfile << "\t\t\tixAcc |= usgAacc->ix" << Prjshort << "WAccess;" << endl;
	outfile << "\t\t\tfirst = false;" << endl;
	outfile << endl;

	outfile << "\t\t\tdelete usgAacc;" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t\tif (ixAcc == (Vec" << Prjshort << "WAccess::EDIT + Vec" << Prjshort << "WAccess::EXEC + Vec" << Prjshort << "WAccess::VIEW)) break;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (!first) ix" << Prjshort << "WAccess = ixAcc;" << endl;
	outfile << endl;

	outfile << "\t// user access rights override user group access rights" << endl;
	outfile << "\tif (dbs" << prjshort << "->tbl" << prjshort << "amuseraccess->loadRecBySQL(\"SELECT * FROM Tbl" << Prjshort << "AMUserAccess WHERE ref" << Prjshort << "MUser = \" + to_string(ref" << Prjshort << "MUser) + \" AND x1Ix" << Prjshort << "VFeatgroup = \" + to_string(ix" << Prjshort << "VFeatgroup) + \" AND x2FeaSrefUix = '\" + srefIxVFeature + \"'\", &usrAacc)) {" << endl;
	outfile << "\t\tix" << Prjshort << "WAccess = usrAacc->ix" << Prjshort << "WAccess;" << endl;
	outfile << "\t\tdelete usrAacc;" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << "// IP spec --- IEND" << endl;

	// --- handleDpchAppXxxxInit
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IBEGIN" << endl;
	outfile << "\t*dpcheng = new DpchEngData(jref, &statshr, {DpchEngData::ALL});" << endl;
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IEND" << endl;

	// --- handleCallXxxxAccess
	outfile << "// IP handleCall" << Prjshort << "Access --- IBEGIN" << endl;
	outfile << "\tixRet = 0;" << endl;
	outfile << endl;

	outfile << "\tauto it = accs.find(featix_t(ixInv, srefInv));" << endl;
	outfile << "\tif (it != accs.end()) ixRet = it->second;" << endl;
	outfile << "\telse {" << endl;
	outfile << "\t\tit = accs.find(featix_t(ixInv, \"\"));" << endl;
	outfile << "\t\tif (it != accs.end()) ixRet = it->second;" << endl;
	outfile << "\t};" << endl;
	outfile << "// IP handleCall" << Prjshort << "Access --- IEND" << endl;
};
// IP cust --- IEND
