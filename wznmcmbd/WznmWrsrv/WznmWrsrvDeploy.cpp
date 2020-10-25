/**
	* \file WznmWrsrvDeploy.cpp
	* Wznm operation processor - write server deployment scripts (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrvDeploy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvDeploy
 ******************************************************************************/

DpchRetWznm* WznmWrsrvDeploy::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvDeploy* dpchinv
		) {
	ubigint refWznmMRelease = dpchinv->refWznmMRelease;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream shfile;
	fstream mkfile;
	fstream mkifile;

	vector<ubigint> refs;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	bool hasdds, hasua;

	ubigint refMty;

	string rootfs, inclibeq;

	set<string> cppflags;
	set<string> linkflags;
	set<string> incpaths;
	set<string> libpaths;
	vector<string> libss;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMJob gbljobs;

	string sbeconfig;

	string s;

	dbswznm->tblwznmmrelease->loadRecByRef(refWznmMRelease, &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	hasdds = (ver->ixWOption & VecWznmWMVersionOption::DDSPUB);
	hasua = (ver->ixWOption & VecWznmWMVersionOption::UASRV);

	dbswznm->loadRefBySQL("SELECT refWznmMMachtype FROM TblWznmMMachine WHERE ref = " + to_string(rls->refWznmMMachine), refMty);

	dbswznm->tblwznmammachinepar->loadValByMchKey(rls->refWznmMMachine, "rootfs", rootfs);
	if (rootfs != "") inclibeq = "=";

	// libraries
	addLibBySref(dbswznm, "microhttpd", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);
	if (cmp->ixVBasetype != VecWznmVMComponentBasetype::CMBENG) addLibBySref(dbswznm, "curl", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);

	addLibBySref(dbswznm, "sbecore_plus", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);

	dbswznm->tblwznmammachinepar->loadValByMchKey(rls->refWznmMMachine, "sbeconfig", sbeconfig);

	if (StrMod::srefInSrefs(sbeconfig, "mar") && (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO))) addLibBySref(dbswznm, "sbecore_mar", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);
	else if (StrMod::srefInSrefs(sbeconfig, "my") && (ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM))) addLibBySref(dbswznm, "sbecore_my", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);

	if (StrMod::srefInSrefs(sbeconfig, "pg") && (ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG)) addLibBySref(dbswznm, "sbecore_pg", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);
	if (StrMod::srefInSrefs(sbeconfig, "lite" )&& (ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE)) addLibBySref(dbswznm, "sbecore_lite", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);

	if ((cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) || (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG)) {
		addLibBySref(dbswznm, "sbecore_mon", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);

		if (ver->ixWOption & VecWznmWMVersionOption::APIMON) addLibBySref(dbswznm, "sbecore_apimon", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);
		if (ver->ixWOption & VecWznmWMVersionOption::DBSMON) addLibBySref(dbswznm, "sbecore_dbsmon", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);
	};

	if (hasdds && (cmp->ixVBasetype != VecWznmVMComponentBasetype::OPENG)) addLibBySref(dbswznm, "ddspub", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);
	if (hasua && (cmp->ixVBasetype != VecWznmVMComponentBasetype::OPENG)) addLibBySref(dbswznm, "uasrv", refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);

	dbswznm->tblwznmrmcomponentmlibrary->loadLibsByCmp(cmp->ref, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) addLibByRef(dbswznm, refs[i], refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);

	if ((cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) || (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG)) {
		// cards
		dbswznm->tblwznmmmodule->loadRefsByVer(ver->ref, false, refs);
		for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);
	};

	// operation packs
	if (cmp->ixVBasetype == VecWznmVMComponentBasetype::OPENG) {
		dbswznm->tblwznmrmcomponentmoppack->loadOpksByCmp(cmp->ref, false, refs);
		dbswznm->tblwznmmoppack->loadRstByRefs(refs, false, opks);
	} else dbswznm->tblwznmmoppack->loadRstBySQL("SELECT * FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(ver->ref), false, opks);

	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		dbswznm->tblwznmrmlibrarymoppack->loadLibsByOpk(opk->ref, false, refs);
		for (unsigned int j = 0; j < refs.size(); j++) addLibByRef(dbswznm, refs[j], refMty, rls->refWznmMMachine, cppflags, linkflags, incpaths, libpaths, libss, 0);
	};

	trimLibss(libss);

	// global jobs
	if ((cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) || (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG)) {
		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::ROOT) + " ORDER BY sref ASC", false, gbljobs);
		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS) + " ORDER BY sref ASC", true, gbljobs);
		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " AND Global = 1 ORDER BY sref ASC", true, gbljobs);
	};

	if (cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) {
		s = xchg->tmppath + "/" + folder + "/checkout.sh.ip";
		shfile.open(s.c_str(), ios::out);
		writeChkoutSh(dbswznm, shfile, cmp->refWznmMVersion, Prjshort, cars, opks, hasdds, hasua);
		shfile.close();

		s = xchg->tmppath + "/" + folder + "/Makefile.inc.ip";
		mkifile.open(s.c_str(), ios::out);
		writeMakeInc(mkifile, hasdds, hasua);
		mkifile.close();

		s = xchg->tmppath + "/" + folder + "/Makefile.ip";
		mkfile.open(s.c_str(), ios::out);
		writeMake(dbswznm, mkfile, ver, refMty, rootfs, inclibeq, rls, Prjshort, cppflags, linkflags, incpaths, libpaths, libss, cars, opks, gbljobs, hasdds, hasua);
		mkfile.close();

		s = xchg->tmppath + "/" + folder + "/make.sh.ip";
		shfile.open(s.c_str(), ios::out);
		writeMkSh(dbswznm, shfile, cmp->refWznmMVersion, Prjshort, cars);
		shfile.close();

	} else if (cmp->ixVBasetype == VecWznmVMComponentBasetype::OPENG) {
		s = xchg->tmppath + "/" + folder + "/checkout.sh.ip";
		shfile.open(s.c_str(), ios::out);
		writeCoopSh(dbswznm, shfile, Prjshort, StrMod::lc(cmp->sref), opks);
		shfile.close();

		s = xchg->tmppath + "/" + folder + "/Makefile.ip";
		mkfile.open(s.c_str(), ios::out);
		writeMkop(dbswznm, mkfile, ver, cmp, refMty, rootfs, inclibeq, rls, Prjshort, cppflags, linkflags, incpaths, libpaths, libss, opks);
		mkfile.close();

		s = xchg->tmppath + "/" + folder +"/make.sh.ip";
		shfile.open(s.c_str(), ios::out);
		writeMkopSh(dbswznm, shfile, cmp->refWznmMVersion, Prjshort, opks);
		shfile.close();

	} else if (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG) {
		// create files
		s = xchg->tmppath + "/" + folder + "/checkout.sh.ip";
		shfile.open(s.c_str(), ios::out);
		writeCocmbSh(dbswznm, shfile, cmp->refWznmMVersion, Prjshort, cars, opks, hasdds, hasua);
		shfile.close();

		s = xchg->tmppath + "/" + folder + "/Makefile.inc.ip";
		mkifile.open(s.c_str(), ios::out);
		writeMakeInc(mkifile, hasdds, hasua);
		mkifile.close();

		s = xchg->tmppath + "/" + folder + "/Makefile.ip";
		mkfile.open(s.c_str(), ios::out);
		writeMkcmb(dbswznm, mkfile, ver, refMty, rootfs, inclibeq, rls, Prjshort, cppflags, linkflags, incpaths, libpaths, libss, cars, opks, gbljobs, hasdds, hasua);
		mkfile.close();

		s = xchg->tmppath + "/" + folder + "/make.sh.ip";
		shfile.open(s.c_str(), ios::out);
		writeMkcmbSh(dbswznm, shfile, cmp->refWznmMVersion, Prjshort, cars, opks);
		shfile.close();
	};

	if ((cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) || (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG)) {
		for (unsigned int i = 0; i < cars.nodes.size(); i++) {
			car = cars.nodes[i];

			s = xchg->tmppath + "/" + folder + "/Makefile_" + car->sref + ".ip";
			mkfile.open(s.c_str(), ios::out);
			writeMkcar(dbswznm, mkfile, cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG, refMty, rootfs, inclibeq, Prjshort, cppflags, incpaths, car);
			mkfile.close();
		};
	};

	s = xchg->tmppath + "/" + folder + "/Makefile_Iex" + Prjshort + ".ip";
	mkfile.open(s.c_str(), ios::out);
	writeMkiex(dbswznm, mkfile, cmp->refWznmMVersion, cmp->ixVBasetype != VecWznmVMComponentBasetype::OPENG , cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG, refMty, rootfs, inclibeq, Prjshort, cppflags, incpaths);
	mkfile.close();

	if ((cmp->ixVBasetype == VecWznmVMComponentBasetype::OPENG) || (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG)) {
		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];

			s = xchg->tmppath + "/" + folder + "/Makefile_" + opk->sref + ".ip";
			mkfile.open(s.c_str(), ios::out);
			writeMkopk(dbswznm, mkfile, cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG, refMty, rootfs, inclibeq, Prjshort, cppflags, incpaths, opk);
			mkfile.close();
		};
	};

	if ((cmp->ixVBasetype == VecWznmVMComponentBasetype::ENG) || (cmp->ixVBasetype == VecWznmVMComponentBasetype::OPENG)
				|| (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG)) {
		s = xchg->tmppath + "/" + folder + "/Makefile_Vec" + Prjshort + ".ip";
		mkfile.open(s.c_str(), ios::out);
		writeMkvec(dbswznm, mkfile, cmp->refWznmMVersion, refMty, rootfs, inclibeq, Prjshort, cppflags, incpaths);
		mkfile.close();
	};

	delete rls;
	delete cmp;
	delete ver;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvDeploy::writeChkoutSh(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMCard& cars
			, ListWznmMOppack& opks
			, const bool hasdds
			, const bool hasua
		) {
	WznmMCard* car = NULL;

	WznmMOppack* opk = NULL;

	string prjshort = StrMod::lc(Prjshort);

	// --- mkdir.cars
	outfile << "# IP mkdir.cars --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		outfile << "mkdir $SRCROOT/" << prjshort << "d/" << car->sref << endl;
	};
	outfile << "# IP mkdir.cars --- IEND" << endl;

	// --- cp.ddspub*
	if (hasdds) outfile << "# IP cp.ddspub --- AFFIRM" << endl;
	else outfile << "# IP cp.ddspub --- REMOVE" << endl;

	// --- cp.uasrv*
	if (hasua) outfile << "# IP cp.uasrv --- AFFIRM" << endl;
	else outfile << "# IP cp.uasrv --- REMOVE" << endl;

	// --- cp.m2msess*
	if (hasdds || hasua) outfile << "# IP cp.m2msess --- AFFIRM" << endl;
	else outfile << "# IP cp.m2msess --- REMOVE" << endl;

	// --- cp.cars
	outfile << "# IP cp.cars --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		outfile << "cp Makefile_" << car->sref << " $SRCROOT/" << prjshort << "d/" << car->sref << "/Makefile" << endl;
		outfile << endl;

		outfile << "cp $CMBDSRCROOT/" << car->sref << "/*.h $SRCROOT/" << prjshort << "d/" << car->sref << "/" << endl;
		outfile << "cp $CMBDSRCROOT/" << car->sref << "/*.cpp $SRCROOT/" << prjshort << "d/" << car->sref << "/" << endl;
		outfile << endl;
	};
	outfile << "# IP cp.cars --- IEND" << endl;

	// --- cp.opkgbls
	outfile << "# IP cp.opkgbls --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		outfile << "cp $CMBDSRCROOT/" << opk->sref << "/" << opk->sref << "_blks.h $SRCROOT/" << prjshort << "d/" << endl;
		outfile << "cp $CMBDSRCROOT/" << opk->sref << "/" << opk->sref << "_blks.cpp $SRCROOT/" << prjshort << "d/" << endl;
		outfile << "cp $CMBDSRCROOT/" << opk->sref << "/Sqk" << opk->sref << ".h $SRCROOT/" << prjshort << "d/" << endl;
		outfile << "cp $CMBDSRCROOT/" << opk->sref << "/Sqk" << opk->sref << ".cpp $SRCROOT/" << prjshort << "d/" << endl;
		outfile << endl;
	};
	outfile << "# IP cp.opkgbls --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMakeInc(
			fstream& outfile
			, const bool hasdds
			, const bool hasua
		) {
	// --- ddspub*
	if (hasdds) outfile << "# IP ddspub --- AFFIRM" << endl;
	else outfile << "# IP ddspub --- REMOVE" << endl;

	// --- uasrv*
	if (hasua) outfile << "# IP uasrv --- AFFIRM" << endl;
	else outfile << "# IP uasrv --- REMOVE" << endl;
};

void WznmWrsrvDeploy::writeMake(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMVersion* ver
			, const ubigint refMty
			, const string& rootfs
			, const string& inclibeq
			, WznmMRelease* rls
			, const string& Prjshort
			, set<string>& cppflags
			, set<string>& linkflags
			, set<string>& incpaths
			, set<string>& libpaths
			, vector<string>& libss
			, ListWznmMCard& cars
			, ListWznmMOppack& opks
			, ListWznmMJob& gbljobs
			, const bool hasdds
			, const bool hasua
		) {
	WznmMCard* car = NULL;

	WznmMOppack* opk = NULL;

	WznmMJob* gbljob = NULL;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	bool statNotDyn = StrMod::srefInSrefs(rls->srefsKOption, "linkstat");
	bool stripdbg = StrMod::srefInSrefs(rls->srefsKOption, "stripdbg");

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	outfile << " -D" << PRJSHORT << "D";
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "link", s);
	outfile << "LINK = " << s << endl;

	outfile << "LINKFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "linkflags", s)) outfile << " " << s;
	if (stripdbg) outfile << " -s";
	for (auto it = linkflags.begin(); it != linkflags.end(); it++) outfile << " " << (*it);
	outfile << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.cmpspec
	outfile << "# IP incpath.cmpspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		outfile << " -I" << inclibeq << "$(SRCROOT)/" << prjshort << "d/" << car->sref;
	};
	outfile << endl;
	outfile << "# IP incpath.cmpspec --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- objs.ddspub*
	if (hasdds) outfile << "# IP objs.ddspub --- AFFIRM" << endl;
	else outfile << "# IP objs.ddspub --- REMOVE" << endl;

	// --- objs.uasrv*
	if (hasua) outfile << "# IP objs.uasrv --- AFFIRM" << endl;
	else outfile << "# IP objs.uasrv --- REMOVE" << endl;

	// --- objs
	outfile << "# IP objs --- IBEGIN" << endl;
	if (gbljobs.nodes.size() > 0) {
		outfile << "OBJS +=";
		for (unsigned int i = 0; i < gbljobs.nodes.size(); i++) {
			gbljob = gbljobs.nodes[i];
			outfile << " " << gbljob->sref << ".o";
		};
		outfile << endl;
	};

	if (opks.nodes.size() > 0) {
		outfile << "OBJS +=";
		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];
			outfile << " " << opk->sref << "_blks.o Sqk" << opk->sref << ".o";
		};
		outfile << endl;
	};
	outfile << "# IP objs --- IEND" << endl;

	// --- libpath.libspec
	outfile << "# IP libpath.libspec --- IBEGIN" << endl;
	outfile << "LIBPATH +=";
	for (auto it = libpaths.begin(); it != libpaths.end(); it++) outfile << " -L" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP libpath.libspec --- IEND" << endl;

	// --- libpath.mtyspec
	outfile << "# IP libpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "libpath", s)) outfile << "LIBPATH += " << pathToPathstr(s, true, inclibeq) << endl;
	outfile << "# IP libpath.mtyspec --- IEND" << endl;

	// --- libs.cmpspec
	outfile << "# IP libs.cmpspec --- IBEGIN" << endl;
	outfile << "LIBS =";
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		
		if (statNotDyn) outfile << " -l:lib" << StrMod::lc(car->sref) << ".a";
		else outfile << " -l" << StrMod::lc(car->sref);
	};
	outfile << endl;
	outfile << "# IP libs.cmpspec --- IEND" << endl;

	// --- libs.prjspec*, libs.statprjspec*
	if (statNotDyn) {
		outfile << "# IP libs.prjspec --- REMOVE" << endl;
		outfile << "# IP libs.statprjspec --- AFFIRM" << endl;
	} else {
		outfile << "# IP libs.prjspec --- AFFIRM" << endl;
		outfile << "# IP libs.statprjspec --- REMOVE" << endl;
	};

	// --- libs.libspec
	outfile << "# IP libs.libspec --- IBEGIN" << endl;
	for (unsigned int i = 0; i < libss.size(); i++) outfile << "LIBS += " << libsToLibstr(libss[i], statNotDyn) << endl;
	outfile << "# IP libs.libspec --- IEND" << endl;

	// --- libs.mtyspec
	outfile << "# IP libs.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "libs", s)) outfile << "LIBS += " << libsToLibstr(s, statNotDyn) << endl;
	outfile << "# IP libs.mtyspec --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkSh(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMCard& cars
		) {
	WznmMCard* car = NULL;

	// --- all
	outfile << "# IP all --- IBEGIN" << endl;
	outfile << "\tsubs=(\"Iex" << Prjshort << "\" \"Vec" << Prjshort << "\"";
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		outfile << " \"" << car->sref << "\"";
	};
	outfile << ")" << endl;
	outfile << "# IP all --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkcar(
			DbsWznm* dbswznm
			, fstream& outfile
			, const bool cmbdNotD
			, const ubigint refMty
			, const string& rootfs
			, const string& inclibeq
			, const string& Prjshort
			, set<string>& cppflags
			, set<string>& incpaths
			, WznmMCard* car
		) {
	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	string PRJSHORT = StrMod::uc(Prjshort);

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	outfile << " -D" << PRJSHORT;
	if (cmbdNotD) outfile << "CMBD";
	else outfile << "D";
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlib", s);
	outfile << "STATLIB = " << s << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlibflags", s);
	outfile << "STATLIBFLAGS = " << s << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- objs
	outfile << "# IP objs --- IBEGIN" << endl;
	outfile << "OBJS =";

	Wznm::getCrdsubjobs(dbswznm, jobs, car->refWznmMJob);

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];
		outfile << " " << job->sref << ".o";
	};

	outfile << endl;
	outfile << "# IP objs --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkiex(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const bool dCmbdNotOpd
			, const bool cmbdNotD
			, const ubigint refMty
			, const string& rootfs
			, const string& inclibeq
			, const string& Prjshort
			, set<string>& cppflags
			, set<string>& incpaths
		) {
	ListWznmMImpexpcplx iexs;
	WznmMImpexpcplx* iex = NULL;

	WznmMJob* job = NULL;

	string PRJSHORT = StrMod::uc(Prjshort);

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	if (dCmbdNotOpd) {
		outfile << " -D" << PRJSHORT;
		if (cmbdNotD) outfile << "CMBD";
		else outfile << "D";
	};
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlib", s);
	outfile << "STATLIB = " << s << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlibflags", s);
	outfile << "STATLIBFLAGS = " << s << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- objs
	dbswznm->tblwznmmimpexpcplx->loadRstBySQL("SELECT * FROM TblWznmMImpexpcplx WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, iexs);

	outfile << "# IP objs --- IBEGIN" << endl;
	outfile << "OBJS =";
	for (unsigned int i = 0; i < iexs.nodes.size(); i++) {
		iex = iexs.nodes[i];
		outfile << " " << iex->sref << ".o";

		if (dCmbdNotOpd) if (dbswznm->tblwznmmjob->loadRecByRef(iex->refWznmMJob, &job)) {
			outfile << " " << job->sref << ".o";
			delete job;
		};
	};
	outfile << endl;
	outfile << "# IP objs --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkvec(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const ubigint refMty
			, const string& rootfs
			, const string& inclibeq
			, const string& Prjshort
			, set<string>& cppflags
			, set<string>& incpaths
		) {
	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	string PRJSHORT = StrMod::uc(Prjshort);

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlib", s);
	outfile << "STATLIB = " << s << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlibflags", s);
	outfile << "STATLIBFLAGS = " << s << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH =";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- objs
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ((ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN) + ") OR (ixVBasetype = "
				+ to_string(VecWznmVMVectorBasetype::OR) + ")) AND ((hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::VOID) + ") OR (hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + ")) AND hkUref = 0 ORDER BY sref ASC", false, vecs);

	outfile << "# IP objs --- IBEGIN" << endl;
	outfile << "OBJS =";
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		outfile << " " << vec->sref << ".o";
	};
	outfile << endl;
	outfile << "# IP objs --- IEND" << endl;
};

void WznmWrsrvDeploy::writeCoopSh(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, const string& cmpsref
			, ListWznmMOppack& opks
		) {
	WznmMOppack* opk = NULL;

	string prjshort = StrMod::lc(Prjshort);

	// --- mkdir.opks
	outfile << "# IP mkdir.opks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		outfile << "mkdir $SRCROOT/" << cmpsref << "/" << opk->sref << endl;
	};
	outfile << "# IP mkdir.opks --- IEND" << endl;

	// --- cp.opks
	outfile << "# IP cp.opks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		outfile << "cp Makefile_" << opk->sref << " $SRCROOT/" << cmpsref << "/" << opk->sref << "/Makefile" << endl;
		outfile << endl;

		outfile << "cp $CMBDSRCROOT/" << opk->sref << "/" << opk->sref << "*.h $SRCROOT/" << cmpsref << "/" << opk->sref << "/" << endl;
		outfile << "cp $CMBDSRCROOT/" << opk->sref << "/" << opk->sref << "*.cpp $SRCROOT/" << cmpsref << "/" << opk->sref << "/" << endl;
		outfile << endl;
	};
	outfile << "# IP cp.opks --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkop(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMVersion* ver
			, WznmMComponent* cmp
			, const ubigint refMty
			, const string& rootfs
			, const string& inclibeq
			, WznmMRelease* rls
			, const string& Prjshort
			, set<string>& cppflags
			, set<string>& linkflags
			, set<string>& incpaths
			, set<string>& libpaths
			, vector<string>& libss
			, ListWznmMOppack& opks
		) {
	WznmMOppack* opk = NULL;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	bool statNotDyn = StrMod::srefInSrefs(rls->srefsKOption, "linkstat");
	bool stripdbg = StrMod::srefInSrefs(rls->srefsKOption, "stripdbg");

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "link", s);
	outfile << "LINK = " << s << endl;

	outfile << "LINKFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "linkflags", s)) outfile << " " << s;
	if (stripdbg) outfile << " -s";
	for (auto it = linkflags.begin(); it != linkflags.end(); it++) outfile << " " << (*it);
	outfile << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.cmpspec
	outfile << "# IP incpath.cmpspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		outfile << " -I" << inclibeq << "$(SRCROOT)/" << StrMod::lc(cmp->sref) << "/" << opk->sref;
	};
	outfile << endl;
	outfile << "# IP incpath.cmpspec --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- libpath.libspec
	outfile << "# IP libpath.libspec --- IBEGIN" << endl;
	outfile << "LIBPATH +=";
	for (auto it = libpaths.begin(); it != libpaths.end(); it++) outfile << " -L" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP libpath.libspec --- IEND" << endl;

	// --- libpath.mtyspec
	outfile << "# IP libpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "libpath", s)) outfile << "LIBPATH += " << pathToPathstr(s, true, inclibeq) << endl;
	outfile << "# IP libpath.mtyspec --- IEND" << endl;

	// --- libs.cmpspec
	outfile << "# IP libs.cmpspec --- IBEGIN" << endl;
	outfile << "LIBS =";
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		if (statNotDyn) outfile << " -l:lib" << StrMod::lc(opk->sref) << ".a";
		else outfile << " -l" << StrMod::lc(opk->sref);
	};
	outfile << endl;
	outfile << "# IP libs.cmpspec --- IEND" << endl;

	// --- libs.prjspec*, libs.statprjspec*
	if (statNotDyn) {
		outfile << "# IP libs.prjspec --- REMOVE" << endl;
		outfile << "# IP libs.statprjspec --- AFFIRM" << endl;
	} else {
		outfile << "# IP libs.prjspec --- AFFIRM" << endl;
		outfile << "# IP libs.statprjspec --- REMOVE" << endl;
	};

	// --- libs.libspec
	outfile << "# IP libs.libspec --- IBEGIN" << endl;
	for (unsigned int i = 0; i < libss.size(); i++) outfile << "LIBS += " << libsToLibstr(libss[i], statNotDyn) << endl;
	outfile << "# IP libs.libspec --- IEND" << endl;

	// --- libs.mtyspec
	outfile << "# IP libs.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "libs", s)) outfile << "LIBS += " << libsToLibstr(s, statNotDyn) << endl;
	outfile << "# IP libs.mtyspec --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkopSh(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMOppack& opks
		) {
	WznmMOppack* opk = NULL;

	// --- all
	outfile << "# IP all --- IBEGIN" << endl;
	outfile << "\tsubs=(\"Iex" << Prjshort << "\" \"Vec" << Prjshort << "\"";
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		outfile << " \"" << opk->sref << "\"";
	};
	outfile << ")" << endl;
	outfile << "# IP all --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkopk(
			DbsWznm* dbswznm
			, fstream& outfile
			, const bool cmbdNotOpd
			, const ubigint refMty
			, const string& rootfs
			, const string& inclibeq
			, const string& Prjshort
			, set<string>& cppflags
			, set<string>& incpaths
			, WznmMOppack* opk
		) {
	ListWznmMOp ops;
	WznmMOp* op = NULL;

	string PRJSHORT = StrMod::uc(Prjshort);

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	if (cmbdNotOpd) outfile << " -D" << PRJSHORT << "CMBD";
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlib", s);
	outfile << "STATLIB = " << s << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "statlibflags", s);
	outfile << "STATLIBFLAGS = " << s << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- objs
	dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);

	outfile << "# IP objs --- IBEGIN" << endl;
	outfile << "OBJS +=";
	for (unsigned int i = 0; i < ops.nodes.size(); i++) {
		op = ops.nodes[i];
		outfile << " " << op->sref << ".o";
	};
	if (cmbdNotOpd) outfile << " Sqk" << opk->sref << ".o";
	outfile << endl;
	outfile << "# IP objs --- IEND" << endl;
};

void WznmWrsrvDeploy::writeCocmbSh(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMCard& cars
			, ListWznmMOppack& opks
			, const bool hasdds
			, const bool hasua
		) {
	WznmMCard* car = NULL;

	WznmMOppack* opk = NULL;

	string prjshort = StrMod::lc(Prjshort);

	// --- mkdir.cars
	outfile << "# IP mkdir.cars --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		outfile << "mkdir $SRCROOT/" << prjshort << "cmbd/" << car->sref << endl;
	};
	outfile << "# IP mkdir.cars --- IEND" << endl;

	// --- mkdir.opks
	outfile << "# IP mkdir.opks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		outfile << "mkdir $SRCROOT/" << prjshort << "cmbd/" << opk->sref << endl;
	};
	outfile << "# IP mkdir.opks --- IEND" << endl;

	// --- cp.ddspub*
	if (hasdds) outfile << "# IP cp.ddspub --- AFFIRM" << endl;
	else outfile << "# IP cp.ddspub --- REMOVE" << endl;

	// --- cp.uasrv*
	if (hasua) outfile << "# IP cp.uasrv --- AFFIRM" << endl;
	else outfile << "# IP cp.uasrv --- REMOVE" << endl;

	// --- cp.m2msess*
	if (hasdds || hasua) outfile << "# IP cp.m2msess --- AFFIRM" << endl;
	else outfile << "# IP cp.m2msess --- REMOVE" << endl;

	// --- cp.cars
	outfile << "# IP cp.cars --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		outfile << "cp Makefile_" << car->sref << " $SRCROOT/" << prjshort << "cmbd/" << car->sref << "/Makefile" << endl;
		outfile << endl;

		outfile << "cp ../../" << prjshort << "cmbd/" << car->sref << "/*.h $SRCROOT/" << prjshort << "cmbd/" << car->sref << "/" << endl;
		outfile << "cp ../../" << prjshort << "cmbd/" << car->sref << "/*.cpp $SRCROOT/" << prjshort << "cmbd/" << car->sref << "/" << endl;
		outfile << endl;
	};
	outfile << "# IP cp.cars --- IEND" << endl;

	// --- cp.opks
	outfile << "# IP cp.opks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		outfile << "cp Makefile_" << opk->sref << " $SRCROOT/" << prjshort << "cmbd/" << opk->sref << "/Makefile" << endl;
		outfile << endl;

		outfile << "cp ../../" << prjshort << "cmbd/" << opk->sref << "/*.h $SRCROOT/" << prjshort << "cmbd/" << opk->sref << "/" << endl;
		outfile << "cp ../../" << prjshort << "cmbd/" << opk->sref << "/*.cpp $SRCROOT/" << prjshort << "cmbd/" << opk->sref << "/" << endl;
		outfile << endl;
	};
	outfile << "# IP cp.opks --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkcmb(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMVersion* ver
			, const ubigint refMty
			, const string& rootfs
			, const string& inclibeq
			, WznmMRelease* rls
			, const string& Prjshort
			, set<string>& cppflags
			, set<string>& linkflags
			, set<string>& incpaths
			, set<string>& libpaths
			, vector<string>& libss
			, ListWznmMCard& cars
			, ListWznmMOppack& opks
			, ListWznmMJob& gbljobs
			, const bool hasdds
			, const bool hasua
		) {
	WznmMCard* car = NULL;

	WznmMOppack* opk = NULL;

	WznmMJob* gbljob = NULL;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	bool statNotDyn = StrMod::srefInSrefs(rls->srefsKOption, "linkstat");
	bool stripdbg = StrMod::srefInSrefs(rls->srefsKOption, "stripdbg");

	string s;

	// --- tools
	outfile << "# IP tools --- IBEGIN" << endl;
	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cpp", s);
	outfile << "CPP = " << s << endl;

	outfile << "CPPFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "cppflags", s)) outfile << " " << s;
	outfile << " -D" << PRJSHORT << "CMBD";
	for (auto it = cppflags.begin(); it != cppflags.end(); it++) outfile << " " << (*it);
	outfile << endl << endl;

	s = "";
	dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "link", s);
	outfile << "LINK = " << s << endl;

	outfile << "LINKFLAGS =";
	if (rootfs != "") outfile << " --sysroot=" << rootfs;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "linkflags", s)) outfile << " " << s;
	if (stripdbg) outfile << " -s";
	for (auto it = linkflags.begin(); it != linkflags.end(); it++) outfile << " " << (*it);
	outfile << endl;
	outfile << "# IP tools --- IEND" << endl;

	// --- incpath.cmpspec
	outfile << "# IP incpath.cmpspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		outfile << " -I" << inclibeq << "$(SRCROOT)/" << prjshort << "cmbd/" << car->sref;
	};
	outfile << endl;

	if (opks.nodes.size() > 0) {
		outfile << "INCPATH +=";
		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];
			outfile << " -I" << inclibeq << "$(SRCROOT)/" << prjshort << "cmbd/" << opk->sref;
		};
		outfile << endl;
	};
	outfile << "# IP incpath.cmpspec --- IEND" << endl;

	// --- incpath.libspec
	outfile << "# IP incpath.libspec --- IBEGIN" << endl;
	outfile << "INCPATH +=";
	for (auto it = incpaths.begin(); it != incpaths.end(); it++) outfile << " -I" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP incpath.libspec --- IEND" << endl;

	// --- incpath.mtyspec
	outfile << "# IP incpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "incpath", s)) outfile << "INCPATH += " << pathToPathstr(s, false, inclibeq) << endl;
	outfile << "# IP incpath.mtyspec --- IEND" << endl;

	// --- objs.ddspub*
	if (hasdds) outfile << "# IP objs.ddspub --- AFFIRM" << endl;
	else outfile << "# IP objs.ddspub --- REMOVE" << endl;

	// --- objs.uasrv*
	if (hasua) outfile << "# IP objs.uasrv --- AFFIRM" << endl;
	else outfile << "# IP objs.uasrv --- REMOVE" << endl;

	// --- objs
	outfile << "# IP objs --- IBEGIN" << endl;
	if (gbljobs.nodes.size() > 0) {
		outfile << "OBJS +=";
		for (unsigned int i = 0; i < gbljobs.nodes.size(); i++) {
			gbljob = gbljobs.nodes[i];
			outfile << " " << gbljob->sref << ".o";
		};
		outfile << endl;
	};
	outfile << "# IP objs --- IEND" << endl;

	// --- libpath.libspec
	outfile << "# IP libpath.libspec --- IBEGIN" << endl;
	outfile << "LIBPATH +=";
	for (auto it = libpaths.begin(); it != libpaths.end(); it++) outfile << " -L" << inclibeq << (*it);
	outfile << endl;
	outfile << "# IP libpath.libspec --- IEND" << endl;

	// --- libpath.mtyspec
	outfile << "# IP libpath.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "libpath", s)) outfile << "LIBPATH += " << pathToPathstr(s, true, inclibeq) << endl;
	outfile << "# IP libpath.mtyspec --- IEND" << endl;

	// --- libs.cmpspec
	outfile << "# IP libs.cmpspec --- IBEGIN" << endl;
	outfile << "LIBS =";
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (statNotDyn) outfile << " -l:lib" << StrMod::lc(car->sref) << ".a";
		else outfile << " -l" << StrMod::lc(car->sref);
	};
	outfile << endl;

	if (opks.nodes.size() > 0) {
		outfile << "LIBS +=";
		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];

		if (statNotDyn) outfile << " -l:lib" << StrMod::lc(opk->sref) << ".a";
		else outfile << " -l" << StrMod::lc(opk->sref);
		};
		outfile << endl;
	};
	outfile << "# IP libs.cmpspec --- IEND" << endl;

	// --- libs.prjspec*, libs.statprjspec*
	if (statNotDyn) {
		outfile << "# IP libs.prjspec --- REMOVE" << endl;
		outfile << "# IP libs.statprjspec --- AFFIRM" << endl;
	} else {
		outfile << "# IP libs.prjspec --- AFFIRM" << endl;
		outfile << "# IP libs.statprjspec --- REMOVE" << endl;
	};

	// --- libs.libspec
	outfile << "# IP libs.libspec --- IBEGIN" << endl;
	for (unsigned int i = 0; i < libss.size(); i++) outfile << "LIBS += " << libsToLibstr(libss[i], statNotDyn) << endl;
	outfile << "# IP libs.libspec --- IEND" << endl;

	// --- libs.mtyspec
	outfile << "# IP libs.mtyspec --- IBEGIN" << endl;
	if (dbswznm->tblwznmammachtypemakefile->loadValByMtyTag(refMty, "libs", s)) outfile << "LIBS += " << libsToLibstr(s, statNotDyn) << endl;
	outfile << "# IP libs.mtyspec --- IEND" << endl;
};

void WznmWrsrvDeploy::writeMkcmbSh(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMCard& cars
			, ListWznmMOppack& opks
		) {
	WznmMCard* car = NULL;

	WznmMOppack* opk = NULL;

	// --- all
	outfile << "# IP all --- IBEGIN" << endl;
	outfile << "\tsubs=(\"Iex" << Prjshort << "\" \"Vec" << Prjshort << "\"";

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];
		outfile << " \"" << car->sref << "\"";
	};

	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		outfile << " \"" << opk->sref << "\"";
	};

	outfile << ")" << endl;
	outfile << "# IP all --- IEND" << endl;
};

void WznmWrsrvDeploy::addLibBySref(
			DbsWznm* dbswznm
			, const string& srefLib
			, const ubigint refMty
			, const ubigint refMch
			, set<string>& cppflags
			, set<string>& linkflags
			, set<string>& incpaths
			, set<string>& libpaths
			, vector<string>& libss
			, unsigned int ix0
		) {
	ubigint refLib;

	if (dbswznm->tblwznmmlibrary->loadRefBySrf(srefLib, refLib)) addLibByRef(dbswznm, refLib, refMty, refMch, cppflags, linkflags, incpaths, libpaths, libss, ix0);
};

void WznmWrsrvDeploy::addLibByRef(
			DbsWznm* dbswznm
			, const ubigint refLib
			, const ubigint refMty
			, const ubigint refMch
			, set<string>& cppflags
			, set<string>& linkflags
			, set<string>& incpaths
			, set<string>& libpaths
			, vector<string>& libss
			, unsigned int ix0
		) {
	WznmMLibrary* lib = NULL;

	vector<string> ss;
	string s;

	if (dbswznm->tblwznmmlibrary->loadRecByRef(refLib, &lib)) {
		s = getLibAMkfTagVal(dbswznm, refLib, refMty, refMch, "cppflags");
		if (s != "") {
			StrMod::stringToVector(s, ss, ' ');
			for (unsigned int i = 0; i < ss.size(); i++) cppflags.insert(ss[i]);
		};

		s = getLibAMkfTagVal(dbswznm, refLib, refMty, refMch, "linkflags");
		if (s != "") {
			StrMod::stringToVector(s, ss, ' ');
			for (unsigned int i = 0; i < ss.size(); i++) linkflags.insert(ss[i]);
		};

		s = getLibAMkfTagVal(dbswznm, refLib, refMty, refMch, "incpath");
		if (s != "") {
			StrMod::stringToVector(s, ss, ' ');
			for (unsigned int i = 0; i < ss.size(); i++) incpaths.insert(ss[i]);
		};

		s = getLibAMkfTagVal(dbswznm, refLib, refMty, refMch, "libpath");
		if (s != "") {
			StrMod::stringToVector(s, ss, ' ');
			for (unsigned int i = 0; i < ss.size(); i++) libpaths.insert(ss[i]);
		};

		s = getLibAMkfTagVal(dbswznm, refLib, refMty, refMch, "libs");
		if (s != "") {
			StrMod::stringToVector(s, ss, ' ');

			if (libss.size() < (ix0 + ss.size())) libss.resize(ix0 + ss.size());

			for (unsigned int i = 0; i < ss.size(); i++) {
				if (libss[ix0+i] == "") libss[ix0+i] = ss[i];
				else libss[ix0+i] += " " + ss[i];
			};

			ix0 += ss.size();
		};

		StrMod::stringToVector(lib->depSrefsWznmMLibrary, ss);
		for (unsigned int i = 0; i < ss.size(); i++) addLibBySref(dbswznm, ss[i], refMty, refMch, cppflags, linkflags, incpaths, libpaths, libss, ix0);

		delete lib;
	};
};

string WznmWrsrvDeploy::getLibAMkfTagVal(
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

void WznmWrsrvDeploy::trimLibss(
			vector<string>& libss
		) {
	set<string> unqlibs;

	vector<string> ss;
	set<string> unqss;

	string s;

	for (unsigned int i=libss.size();i>0;i--) {
		unqss.clear();

		StrMod::stringToVector(libss[i-1], ss, ' ');
		for (unsigned int j = 0; j < ss.size(); j++) {
			if (unqlibs.find(ss[j]) == unqlibs.end()) {
				unqlibs.insert(ss[j]);
				unqss.insert(ss[j]);
			};
		};

		s = "";
		for (auto it = unqss.begin(); it != unqss.end(); it++) {
			if (it != unqss.begin()) s += " ";
			s += *it;
		};

		libss[i-1] = s;
	};
};

string WznmWrsrvDeploy::pathToPathstr(
			const string& path
			, const bool libNotInc
			, const string& inclibeq
		) {
	string pathstr;

	vector<string> ss;

	StrMod::stringToVector(path, ss, ' ');

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (i != 0) pathstr += " ";

		if (libNotInc) pathstr += "-L" + inclibeq + ss[i];
		else pathstr += "-I" + inclibeq + ss[i];
	};

	return pathstr;
};

string WznmWrsrvDeploy::libsToLibstr(
			const string& libs
			, const bool statNotDyn
		) {
	string libstr;

	vector<string> ss;

	StrMod::stringToVector(libs, ss, ' ');

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (i != 0) libstr += " ";
		
		if (statNotDyn) libstr += "-l:" + ss[i] + ".a";
		else libstr += "-l" + ss[i].substr(3);
	};

	return libstr;
};
// IP cust --- IEND


