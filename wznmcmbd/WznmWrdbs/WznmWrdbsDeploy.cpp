/**
	* \file WznmWrdbsDeploy.cpp
	* Wznm operation processor - write database access library deployment scripts (implementation)
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

	vector<ubigint> hrefsMch;

	set<string> incpaths;

	string sbeconfig;

	string s;

	dbswznm->tblwznmmrelease->loadRecByRef(refWznmMRelease, &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	// libraries
	addLibBySref(dbswznm, "sbecore", rls->refWznmMMachine, hrefsMch, incpaths);

	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "sbeconfig", sbeconfig);

	if (StrMod::srefInSrefs(sbeconfig, "mar") && (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO))) addLibBySref(dbswznm, "sbecore_mar", rls->refWznmMMachine, hrefsMch, incpaths);
	else if (StrMod::srefInSrefs(sbeconfig, "my") && (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM))) addLibBySref(dbswznm, "sbecore_my", rls->refWznmMMachine, hrefsMch, incpaths);

	if (StrMod::srefInSrefs(sbeconfig, "pg") && (ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG)) addLibBySref(dbswznm, "sbecore_pg", rls->refWznmMMachine, hrefsMch, incpaths);
	if (StrMod::srefInSrefs(sbeconfig, "lite" )&& (ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE)) addLibBySref(dbswznm, "sbecore_lite", rls->refWznmMMachine, hrefsMch, incpaths);

	// write Makefile
	s = xchg->tmppath + "/" + folder + "/Makefile.ip";
	mkfile.open(s.c_str(), ios::out);
	writeMake(dbswznm, mkfile, ver->ref, rls, hrefsMch, incpaths);
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
			, WznmMRelease* rls
			, vector<ubigint>& hrefsMch
			, set<string>& incpaths
		) {
	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	string sysroot, inclibeq;

	bool dynlib = StrMod::srefInSrefs(rls->srefsKOption, "dynlib");

	string s;

	if (Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "sysroot", sysroot)) inclibeq = "=";

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (sysroot != "") outfile << " --sysroot=" << sysroot;
	if (Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "cppflags", s)) outfile << " " << s;
	if (dynlib) outfile << " -fPIC";
	outfile << endl;
	outfile << endl;

	Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "statlib", s);
	outfile << "STATLIB = " << s << endl;

	Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "statlibflags", s);
	outfile << "STATLIBFLAGS = " << s << endl;

	if (dynlib) {
		outfile << endl;

		Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "dynlib", s);
		outfile << "DYNLIB = " << s << endl;

		outfile << "DYNLIBFLAGS =";
		if (sysroot != "") outfile << " --sysroot=" << sysroot;
		if (Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "dynlibflags", s)) outfile << " " << s;
		outfile << endl;

		Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "dynlibext", s);
		outfile << "DYNLIBEXT = " << s << endl;
	};
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH =";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mchspec
	outfile << "# IP incpath.mchspec --- IBEGIN" << endl;
	if (Wznm::getMchmkf(dbswznm, rls->refWznmMMachine, hrefsMch, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, inclibeq) << endl;
	outfile << "# IP incpath.mchspec --- IEND" << endl;

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
			, const ubigint refMch
			, vector<ubigint>& hrefsMch
			, set<string>& incpaths
		) {
	ubigint refLib;
	WznmMLibrary* lib = NULL;

	vector<string> ss;
	string s;

	if (dbswznm->tblwznmmlibrary->loadRefBySrf(srefLib, refLib)) {
		if (dbswznm->tblwznmmlibrary->loadRecByRef(refLib, &lib)) {
			if (Wznm::getLibmkf(dbswznm, refLib, refMch, hrefsMch, "incpath", s)) incpaths.insert(s);

			StrMod::srefsToVector(lib->depSrefsWznmMLibrary, ss);
			for (unsigned int i = 0; i < ss.size(); i++) addLibBySref(dbswznm, ss[i], refMch, hrefsMch, incpaths);

			delete lib;
		};
	};
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
