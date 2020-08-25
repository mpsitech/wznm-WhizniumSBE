/**
	* \file WznmWrapiDeploy.cpp
	* Wznm operation processor - write API code deployment scripts (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrapiDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapi;

/******************************************************************************
 namespace WznmWrapiDeploy
 ******************************************************************************/

DpchRetWznm* WznmWrapiDeploy::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrapiDeploy* dpchinv
		) {
	ubigint refWznmMRelease = dpchinv->refWznmMRelease;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream mkfile;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;

	ubigint refMty;

	set<string> incpaths;

	string s;

	dbswznm->tblwznmmrelease->loadRecByRef(refWznmMRelease, &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);

	dbswznm->loadRefBySQL("SELECT refWznmMMachtype FROM TblWznmMMachine WHERE ref = " + to_string(rls->refWznmMMachine), refMty);

	// library
	addLibBySref(dbswznm, "sbecore", refMty, rls->refWznmMMachine, incpaths);

	// write Makefile
	s = xchg->tmppath + "/" + folder + "/Makefile.ip";
	mkfile.open(s.c_str(), ios::out);
	writeMake(dbswznm, mkfile, cmp->refWznmMVersion, Prjshort, refMty, rls, incpaths);
	mkfile.close();

	delete rls;
	delete cmp;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrapiDeploy::writeMake(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const ubigint refMty
			, WznmMRelease* rls
			, set<string>& incpaths
		) {
	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMTable qtbs;
	WznmMTable* qtb = NULL;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	uint cnt;

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
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = 0 ORDER BY sref ASC", false, vecs);

	outfile << "OBJS += Vec" + Prjshort + "VDpch.o ";
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		outfile << " " << vec->sref << ".o";
	};
	outfile << endl;

	dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMQuery, TblWznmMTable WHERE TblWznmMTable.ref = TblWznmMQuery.qtbRefWznmMTable AND TblWznmMQuery.refWznmMVersion = "
				+ to_string(refWznmMVersion) + " ORDER BY TblWznmMTable.sref ASC", false, qtbs);

	outfile << "OBJS +=";
	for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
		qtb = qtbs.nodes[i];
		outfile << " " << qtb->sref.substr(3) << ".o";
	};
	outfile << endl;

	dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, jobs);

	outfile << "OBJS +=";
	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		// count shared blocks
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
					+ " AND (((reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0) OR ((wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0))", cnt);
	
		if (cnt > 0) outfile << " " << job->sref << ".o";
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
void WznmWrapiDeploy::addLibBySref(
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
string WznmWrapiDeploy::getLibAMkfTagVal(
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
string WznmWrapiDeploy::pathToPathstr(
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


