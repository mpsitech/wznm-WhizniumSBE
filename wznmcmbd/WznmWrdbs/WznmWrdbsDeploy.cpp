/**
	* \file WznmWrdbsDeploy.cpp
	* Wznm operation processor - write database access library deployment scripts (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrdbsDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrdbs;

/******************************************************************************
 namespace WznmWrdbsDeploy
 ******************************************************************************/

DpchRetWznm* WznmWrdbsDeploy::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrdbsDeploy* dpchinv
		) {
	ubigint refWznmMRelease = dpchinv->refWznmMRelease;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream mkfile;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	ubigint refMty;

	set<string> incpaths;

	string sbeconfig;

	string s;

	dbswznm->tblwznmmrelease->loadRecByRef(refWznmMRelease, &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->loadRefBySQL("SELECT refWznmMMachtype FROM TblWznmMMachine WHERE ref = " + to_string(rls->refWznmMMachine), refMty);

	// libraries
	addLibBySref(dbswznm, "sbecore", refMty, rls->refWznmMMachine, incpaths);

	dbswznm->tblwznmammachinepar->loadValByMchKey(rls->refWznmMMachine, "sbeconfig", sbeconfig);

	if (StrMod::srefInSrefs(sbeconfig, "mar") && (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO))) addLibBySref(dbswznm, "sbecore_mar", refMty, rls->refWznmMMachine, incpaths);
	else if (StrMod::srefInSrefs(sbeconfig, "my") && (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM))) addLibBySref(dbswznm, "sbecore_my", refMty, rls->refWznmMMachine, incpaths);

	if (StrMod::srefInSrefs(sbeconfig, "pg") && (ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG)) addLibBySref(dbswznm, "sbecore_pg", refMty, rls->refWznmMMachine, incpaths);
	if (StrMod::srefInSrefs(sbeconfig, "lite" )&& (ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE)) addLibBySref(dbswznm, "sbecore_lite", refMty, rls->refWznmMMachine, incpaths);

	// write Makefile
	s = xchg->tmppath + "/" + folder + "/Makefile.ip";
	mkfile.open(s.c_str(), ios::out);
	writeMake(dbswznm, mkfile, ver->ref, refMty, rls, incpaths);
	mkfile.close();

	delete rls;
	delete cmp;
	delete ver;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrdbsDeploy::writeMake(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const ubigint refMty
			, WznmMRelease* rls
			, set<string>& incpaths
		) {
	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	string rootfs, inclibeq;

	bool dynlib = StrMod::srefInSrefs(rls->srefsKOption, "dynlib");

	string s;

	dbswznm->tblwznmammachinepar->loadValByMchKey(rls->refWznmMMachine, "rootfs", rootfs);
	if (rootfs != "") inclibeq = "=";

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	if (dynlib) outfile << " -fpic";
	outfile << endl;
	outfile << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlib", s);
	outfile << "STATLIB = " << s << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlibflags", s);
	outfile << "STATLIBFLAGS = " << s << endl;

	if (dynlib) {
		outfile << endl;

		s = "";
		dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "dynlib", s);
		outfile << "DYNLIB = " << s << endl;

		outfile << "DYNLIBFLAGS =";
		if (rootfs != "") outfile << " --sysroot=" << rootfs;
		if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "dynlibflags", s)) outfile << " " << s;
		outfile << endl;

		s = "";
		dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "dynlibext", s);
		outfile << "DYNLIBEXT = " << s << endl;
	};
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH =";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- objs
	outfile << "# IP objs --- IBEGIN" << endl;
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND ixVBasetype <> " + to_string(VecWznmVMTableBasetype::QRY) + " ORDER BY sref ASC", false, tbls);

	outfile << "OBJS +=";
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];
		outfile << " " << tbl->sref.substr(3) << ".o";
	};
	outfile << endl;

	dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::QRY, refWznmMVersion, false, tbls);

	outfile << "OBJS +=";
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];
		outfile << " " << tbl->sref.substr(3) << ".o";
	};
	outfile << endl;
	outfile << "# IP objs --- IEND" << endl;

	// --- mkdynlib*
	if (dynlib) outfile << "# IP mkdynlib --- AFFIRM" << endl;
	else outfile << "# IP mkdynlib --- REMOVE" << endl;

	// --- instdynlib*
	if (dynlib) outfile << "# IP instdynlib --- AFFIRM" << endl;
	else outfile << "# IP instdynlib --- REMOVE" << endl;
};

// stripped down version from WznmWrsrvDeploy.cpp
void WznmWrdbsDeploy::addLibBySref(
			DbsWznm* dbswznm
			, const string& srefLib
			, const ubigint refMty
			, const ubigint refMch
			, set<string>& incpaths
		) {
	ubigint refLib;
	WznmMLibrary* lib = NULL;

	vector<string> ss;
	string s;

	if (dbswznm->tblwznmmlibrary->loadRefBySrf(srefLib, refLib)) {
		if (dbswznm->tblwznmmlibrary->loadRecByRef(refLib, &lib)) {
			s = getLibAMkfTagVal(dbswznm, refLib, refMty, refMch, "incpath");
			if (s != "") incpaths.insert(s);

			StrMod::stringToVector(lib->depSrefsWznmMLibrary, ss);
			for (unsigned int i = 0; i < ss.size(); i++) addLibBySref(dbswznm, ss[i], refMty, refMch, incpaths);

			delete lib;
		};
	};
};

// exact copy from WznmWrsrvDeploy.cpp
string WznmWrdbsDeploy::getLibAMkfTagVal(
			DbsWznm* dbswznm
			, const ubigint refWznmMLibrary
			, const ubigint refMty
			, const ubigint refMch
			, const string& tag
		) {
	string s;
	
	dbswznm->tblwznmamlibrarymakefile->loadValByLibRetReuTag(refWznmMLibrary, VecWznmVAMLibraryMakefileRefTbl::VOID, 0, tag, s);
	dbswznm->tblwznmamlibrarymakefile->loadValByLibRetReuTag(refWznmMLibrary, VecWznmVAMLibraryMakefileRefTbl::MTY, refMty, tag, s);
	dbswznm->tblwznmamlibrarymakefile->loadValByLibRetReuTag(refWznmMLibrary, VecWznmVAMLibraryMakefileRefTbl::MCH, refMch, tag, s);

	return s;
};

// stripped down version from WznmWrsrvDeploy.cpp
string WznmWrdbsDeploy::pathToPathstr(
			const string& path
			, const string& inclibeq
		) {
	string pathstr;

	vector<string> ss;

	StrMod::stringToVector(path, ss, ' ');

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (i != 0) pathstr += " ";
		pathstr += "-I" + inclibeq + ss[i];
	};

	return pathstr;
};
// IP cust --- IEND


