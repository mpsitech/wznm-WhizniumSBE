/**
	* \file DlgWznmRlsWrite.cpp
	* job handler for job DlgWznmRlsWrite (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "DlgWznmRlsWrite.h"

#include "DlgWznmRlsWrite_blks.cpp"
#include "DlgWznmRlsWrite_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWznmRlsWrite
 ******************************************************************************/

DlgWznmRlsWrite::DlgWznmRlsWrite(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const uint ixWznmVLocale
		) :
			JobWznm(xchg, VecWznmVJob::DLGWZNMRLSWRITE, jrefSup, ixWznmVLocale)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWznmVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	license = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::DET;

	license = new JobWznmLicense(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMProject* prj = NULL;

	refWznmMRelease = xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref);

	// author
	dbswznm->loadRefBySQL("SELECT refWznmMPerson FROM TblWznmMUser WHERE ref = " + to_string(xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jref)), ref);
	author = StubWznm::getStubPrsStd(dbswznm, ref);

	if (dbswznm->tblwznmmrelease->loadRecByRef(refWznmMRelease, &rls)) {
		// release identifier
		rlssref = rls->sref;
	
		// project, component type, component
		if (dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp)) {
			ixCmptype = cmp->ixVBasetype;

			CMPSREF = StrMod::uc(cmp->sref);
			Cmpsref = StrMod::cap(cmp->sref);
			cmpsref = StrMod::lc(cmp->sref);

			// find project short and title
			if (dbswznm->tblwznmmproject->loadRecBySQL("SELECT TblWznmMProject.* FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(cmp->refWznmMVersion), &prj)) {
				PRJSHORT = StrMod::uc(prj->Short);
				Prjshort = StrMod::cap(prj->Short);
				prjshort = StrMod::lc(prj->Short);

				Prjtit = prj->Title;
			};

			delete cmp;
		};

		// (cross-)compilation parameters
		if ((ixCmptype == VecWznmVMComponentBasetype::ENG) || (ixCmptype == VecWznmVMComponentBasetype::OPENG) || (ixCmptype == VecWznmVMComponentBasetype::CMBENG) || (ixCmptype == VecWznmVMComponentBasetype::DBS)
					|| (ixCmptype == VecWznmVMComponentBasetype::API)) {

			dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, refs);

			dbswznm->loadRefBySQL("SELECT cchRefWznmMMachine FROM TblWznmMMachine WHERE ref = " + to_string(rls->refWznmMMachine), ref);

			if (ref == 0) {
				for (unsigned int i = 0; i < refs.size(); i++) {
					dbswznm->loadRefBySQL("SELECT cchRefWznmMMachine FROM TblWznmMMachine WHERE ref = " + to_string(refs[i]), ref);
					if (ref != 0) break;
				};
			};

			if (ref == 0) {
				Wznm::getMchpar(dbswznm, rls->refWznmMMachine, refs, "ncore", ncore);

			} else {
				// cross-compilation
				Wznm::getMchpar(dbswznm, rls->refWznmMMachine, refs, "sysroot", sysroot);

				cchost = " (" + StubWznm::getStubMchSref(dbswznm, ref) + " cross-compilation)";
				inclibeq = "=";

				dbswznm->tblwznmmmachine->loadHrefsup(ref, refs);
				Wznm::getMchpar(dbswznm, ref, refs, "ncore", ncore);
			};
		};

		delete rls;
	};
	// IP constructor.cust2 --- IEND

	set<uint> moditems;
	refresh(dbswznm, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWznmRlsWrite::~DlgWznmRlsWrite() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void DlgWznmRlsWrite::createIpoutSubfolder(
			const bool spec
			, const string& sub1
			, const string& sub2
		) {
	string s;

	s = xchg->tmppath + "/" + ipfolder + "/" + sub1;
	if (sub2 != "") s = s + "/" + sub2;
	mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	if (spec) {
		s = xchg->tmppath + "/" + specfolder + "/" + sub1;
		if (sub2 != "") s = s + "/" + sub2;
		mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	};

	s = xchg->tmppath + "/" + outfolder + "/" + sub1;
	if (sub2 != "") s = s + "/" + sub2;
	mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
};

void DlgWznmRlsWrite::copyAcvtmp(
			DbsWznm* dbswznm
			, const ubigint refWznmMFile
			, const string& tmpfile
		) {
	Wznm::run("cp -p " + xchg->acvpath + "/" +  Acv::getfile(dbswznm, refWznmMFile) + " " + xchg->tmppath + "/" + tmpfile);
};

void DlgWznmRlsWrite::createEng(
			DbsWznm* dbswznm
			, const bool dplonly
		) {
	vector<ubigint> refs;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created, version;
	string PREFLCL;
	string objddspub, objuasrv;
	string buildroot, libroot, binroot, reproot, nddshome, uasdkroot;

	vector<string> keys;
	vector<string> vals;

	ListWznmMCard crds;
	WznmMCard* crd = NULL;

	bool hasdds, hasua;

	// --- load basics
	dbswznm->tblwznmmrelease->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	dbswznm->tblwznmmmodule->loadRefsByVer(ver->ref, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, crds);

	hasdds = (ver->ixWOption & VecWznmWMVersionOption::DDSPUB);
	hasua = (ver->ixWOption & VecWznmWMVersionOption::UASRV);

	// --- find template files in archive
	ubigint refDexehfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxd_exe.h'", refDexehfile);
	ubigint refDexecppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxd_exe.cpp'", refDexecppfile);

	ubigint refAppsrvhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdAppsrv.h'", refAppsrvhfile);
	ubigint refAppsrvcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdAppsrv.cpp'", refAppsrvcppfile);
	ubigint refJprchfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdJobprc.h'", refJprchfile);
	ubigint refJprccppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdJobprc.cpp'", refJprccppfile);
	ubigint refOprchfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdOpprc.h'", refOprchfile);
	ubigint refOprccppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdOpprc.cpp'", refOprccppfile);
	ubigint refOeclihfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdOpengcli.h'", refOeclihfile);
	ubigint refOeclicppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdOpengcli.cpp'", refOeclicppfile);
	ubigint refOesrvhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdOpengsrv.h'", refOesrvhfile);
	ubigint refOesrvcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdOpengsrv.cpp'", refOesrvcppfile);
	ubigint refDhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxd.h'", refDhfile);
	ubigint refDcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxd.cpp'", refDcppfile);

	ubigint refDdspubhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdDdspub.h'", refDdspubhfile);
	ubigint refDdspubcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdDdspub.cpp'", refDdspubcppfile);

	ubigint refUasrvhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdUasrv.h'", refUasrvhfile);
	ubigint refUasrvcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxdUasrv.cpp'", refUasrvcppfile);

	ubigint refChkoutfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Eng.sh'", refChkoutfile);
	ubigint refMakefile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Eng'", refMakefile);
	ubigint refMkincfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Eng.inc'", refMkincfile);
	ubigint refMkshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'make_Eng.sh'", refMkshfile);
	ubigint refRmkshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'remake_Eng.sh'", refRmkshfile);
	ubigint refMkcrdfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_CrdXxxxYyy'", refMkcrdfile);
	ubigint refMkiexfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_IexXxxx'", refMkiexfile);
	ubigint refMkvecfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_VecXxxx'", refMkvecfile);

	ubigint refStashfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'start_Eng.sh'", refStashfile);
	ubigint refStoshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'stop_Eng.sh'", refStoshfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, "_ini");
	createIpoutSubfolder(false, "_ini", rlssref);

	createIpoutSubfolder(true, cmpsref);

	// --- prepare standard key/value pairs

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	version = StubWznm::getStubVerStd(dbswznm, ver->ref);

	// -- preferred locale
	dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMLocale WHERE ref = " + to_string(ver->refWznmMLocale), PREFLCL);

	PREFLCL = StrMod::uc(PREFLCL);

	// -- directories
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "buildroot", buildroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "libroot", libroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "binroot", binroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "reproot", reproot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "nddshome", nddshome);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "uasdkroot", uasdkroot);

	// --- deployment scripts (WznmWrsrvDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("CMPSREF"); vals.push_back(CMPSREF);
	keys.push_back("cmpsref"); vals.push_back(cmpsref);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("inclibeq"); vals.push_back(inclibeq);

	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);
	keys.push_back("binroot"); vals.push_back(binroot);
	keys.push_back("nddshome"); vals.push_back(nddshome);
	keys.push_back("uasdkroot"); vals.push_back(uasdkroot);
	keys.push_back("reproot"); vals.push_back(reproot);
	keys.push_back("ncore"); vals.push_back(ncore);

	keys.push_back("Crdsref"); vals.push_back("Crdsref");
	keys.push_back("crdsref"); vals.push_back("crdsref");

	addInv(new DpchInvWznmWrsrvDeploy(0, 0, rls->ref, Prjshort, ipfolder + "/_rls/" + rlssref));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkincfile, "", outfolder + "/_rls/" + rlssref + "/Makefile.inc", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkshfile, "", outfolder + "/_rls/" + rlssref + "/make.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refRmkshfile, "", outfolder + "/_rls/" + rlssref + "/remake.sh", keys, vals));

	for (unsigned int i = 0; i < crds.nodes.size(); i++) {
		crd = crds.nodes[i];

		vals[vals.size()-2] = crd->sref;
		vals[vals.size()-1] = StrMod::lc(crd->sref);

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkcrdfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_" + crd->sref, keys, vals));
	};

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkiexfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_Iex" + Prjshort, keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkvecfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_Vec" + Prjshort, keys, vals));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refStashfile, "", outfolder + "/_ini/" + rlssref + "/start.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refStoshfile, "", outfolder + "/_ini/" + rlssref + "/stop.sh", keys, vals));

	// --- preferences file (WznmWrsrvPref)
	addInv(new DpchInvWznmWrsrvPref(0, 0, rls->ref, "", outfolder + "/_ini/" + rlssref + "/Pref" + Cmpsref + ".xml"));

	if (!dplonly) {
		// --- engine globals (WznmWrsrvEngbase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("Prjtit"); vals.push_back(Prjtit);
		keys.push_back("version"); vals.push_back(version);
		keys.push_back("PREFLCL"); vals.push_back(PREFLCL);

		addInv(new DpchInvWznmWrsrvEngbase(0, 0, ver->ref, xchg->stgwznmtenant.orgname, Prjshort, ipfolder + "/" + cmpsref));

		// -- Xxxxd_exe
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDexehfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "d_exe.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDexecppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "d_exe.cpp", keys, vals));

		// -- Appsrv
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refAppsrvhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dAppsrv.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refAppsrvcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dAppsrv.cpp", keys, vals));

		// -- Jobprc
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJprchfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dJobprc.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJprccppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dJobprc.cpp", keys, vals));

		// -- Opprc
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOprchfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dOpprc.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOprccppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dOpprc.cpp", keys, vals));

		// -- Opengcli
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOeclihfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dOpengcli.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOeclicppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dOpengcli.cpp", keys, vals));

		// -- Opengsrv
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOesrvhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dOpengsrv.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOesrvcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dOpengsrv.cpp", keys, vals));

		// -- Xxxxd
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "d.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "d.cpp", keys, vals));

		if (hasdds) {
			// -- Ddspub
			addInv(new DpchInvWznmWrsrvDds(0, 0, cmp->ref, Prjshort, ipfolder + "/" + cmpsref, ipfolder + "/_ini/" + prjshort));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDdspubhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dDdspub.h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDdspubcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dDdspub.cpp", keys, vals));
		};

		if (hasua) {
			// -- Uasrv
			addInv(new DpchInvWznmWrsrvUa(0, 0, ver->ref, Prjshort, Cmpsref, ipfolder + "/" + cmpsref));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refUasrvhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dUasrv.h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refUasrvcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "dUasrv.cpp", keys, vals));
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWznmRlsWrite::createOpeng(
			DbsWznm* dbswznm
			, const bool dplonly
		) {
	vector<ubigint> refs;

	string sref;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string PREFLCL;
	string buildroot, libroot, binroot, reproot;

	vector<string> keys;
	vector<string> vals;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	// --- load basics
	dbswznm->tblwznmmrelease->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	dbswznm->tblwznmrmcomponentmoppack->loadOpksByCmp(cmp->ref, false, refs);
	dbswznm->tblwznmmoppack->loadRstByRefs(refs, false, opks);

	// --- find template files in archive
	ubigint refOpdexehfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxopd_exe.h'", refOpdexehfile);
	ubigint refOpdexecppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxopd_exe.cpp'", refOpdexecppfile);
	ubigint refEnsrvhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxopdEngsrv.h'", refEnsrvhfile);
	ubigint refEnsrvcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxopdEngsrv.cpp'", refEnsrvcppfile);
	ubigint refOprchfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxopdOpprc.h'", refOprchfile);
	ubigint refOprccppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxopdOpprc.cpp'", refOprccppfile);
	ubigint refOphfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxopd.h'", refOphfile);
	ubigint refOpcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxopd.cpp'", refOpcppfile);

	ubigint refChkoutfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Openg.sh'", refChkoutfile);
	ubigint refMakefile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Openg'", refMakefile);
	ubigint refMkincfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Openg.inc'", refMkincfile);
	ubigint refMkshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'make_Openg.sh'", refMkshfile);
	ubigint refRmkshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'remake_Openg.sh'", refRmkshfile);
	ubigint refMkopkfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_XxxxYyyyy'", refMkopkfile);
	ubigint refMkiexfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_IexXxxx'", refMkiexfile);
	ubigint refMkvecfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_VecXxxx'", refMkvecfile);

	ubigint refStashfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'start_Openg.sh'", refStashfile);
	ubigint refStoshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'stop_Openg.sh'", refStoshfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, "_ini");
	createIpoutSubfolder(false, "_ini", rlssref);

	createIpoutSubfolder(false, cmpsref);

	// --- prepare standard key/value pairs

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- preferred locale
	dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMLocale WHERE ref = " + to_string(ver->refWznmMLocale), PREFLCL);

	PREFLCL = StrMod::uc(PREFLCL);

	// -- directories
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "buildroot", buildroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "libroot", libroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "binroot", binroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "reproot", reproot);

	// --- deployment scripts (WznmWrsrvDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("CMPSREF"); vals.push_back(CMPSREF);
	keys.push_back("Cmpsref"); vals.push_back(Cmpsref);
	keys.push_back("cmpsref"); vals.push_back(cmpsref);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("inclibeq"); vals.push_back(inclibeq);

	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);
	keys.push_back("binroot"); vals.push_back(binroot);
	keys.push_back("reproot"); vals.push_back(reproot);
	keys.push_back("ncore"); vals.push_back(ncore);

	keys.push_back("Opksref"); vals.push_back("Opksref");
	keys.push_back("opksref"); vals.push_back("opksref");

	addInv(new DpchInvWznmWrsrvDeploy(0, 0, rls->ref, Prjshort, ipfolder + "/_rls/" + rlssref));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkincfile, "", outfolder + "/_rls/" + rlssref + "/Makefile.inc", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkshfile, "", outfolder + "/_rls/" + rlssref + "/make.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refRmkshfile, "", outfolder + "/_rls/" + rlssref + "/remake.sh", keys, vals));

	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		vals[vals.size()-2] = opk->sref;
		vals[vals.size()-1] = StrMod::lc(opk->sref);

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkopkfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_" + opk->sref, keys, vals));
	};

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkiexfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_Iex" + Prjshort, keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkvecfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_Vec" + Prjshort, keys, vals));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refStashfile, "", outfolder + "/_ini/" + rlssref + "/start.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refStoshfile, "", outfolder + "/_ini/" + rlssref + "/stop.sh", keys, vals));

	// --- preferences file (WznmWrsrvPref)
	addInv(new DpchInvWznmWrsrvPref(0, 0, rls->ref, "", outfolder + "/_ini/" + rlssref + "/Pref" + Prjshort + "opd.xml"));

	if (!dplonly) {
		// --- operation engine globals (WznmWrsrvOpengbase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("CMPSREF"); vals.push_back(CMPSREF);
		keys.push_back("cmpsref"); vals.push_back(cmpsref);
		keys.push_back("PREFLCL"); vals.push_back(PREFLCL);

		addInv(new DpchInvWznmWrsrvOpengbase(0, 0, cmp->ref, Prjshort, ipfolder + "/" + cmpsref));

		// -- Xxxxopd_exe
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpdexehfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opd_exe.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpdexecppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opd_exe.cpp", keys, vals));

		// -- Engsrv
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refEnsrvhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opdEngsrv.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refEnsrvcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opdEngsrv.cpp", keys, vals));

		// -- Opprc
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOprchfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opdOpprc.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOprccppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opdOpprc.cpp", keys, vals));

		// -- Xxxxopd
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOphfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opd.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "opd.cpp", keys, vals));
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWznmRlsWrite::createCmbeng(
			DbsWznm* dbswznm
			, const bool dplonly
		) {
	vector<ubigint> refs;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string version, vermajor, verminor, versub;
	string PREFLCL;
	string buildroot, libroot, reproot, binroot, nddshome, uasdkroot;

	vector<string> keys;
	vector<string> vals;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMCard crds;
	WznmMCard* crd = NULL;

	bool hasdds, hasua;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	bool hasblks, hasevals;

	vector<string> bitsEval;
	vector<string> rulesEval;
	vector<string> exprsEval;

	string ipfld, specfld, outfld;

	WznmMImpexpcplx* iex = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	uint cnt;

	// --- load basics
	dbswznm->tblwznmmrelease->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	dbswznm->tblwznmmmodule->loadRefsByVer(ver->ref, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, crds);

	hasdds = (ver->ixWOption & VecWznmWMVersionOption::DDSPUB);
	hasua = (ver->ixWOption & VecWznmWMVersionOption::UASRV);

	// --- find template files in archive
	ubigint refCmbdexehfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxcmbd_exe.h'", refCmbdexehfile);
	ubigint refCmbdexecppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxcmbd_exe.cpp'", refCmbdexecppfile);

	ubigint refAppsrvhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdAppsrv.h'", refAppsrvhfile);
	ubigint refAppsrvcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdAppsrv.cpp'", refAppsrvcppfile);
	ubigint refJprchfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdJobprc.h'", refJprchfile);
	ubigint refJprccppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdJobprc.cpp'", refJprccppfile);
	ubigint refOprchfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdOpprc.h'", refOprchfile);
	ubigint refOprccppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdOpprc.cpp'", refOprccppfile);
	ubigint refCmbdhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxcmbd.h'", refCmbdhfile);
	ubigint refCmbdcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxxcmbd.cpp'", refCmbdcppfile);

	ubigint refDdspubhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdDdspub.h'", refDdspubhfile);
	ubigint refDdspubcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdDdspub.cpp'", refDdspubcppfile);
	ubigint refDdsidlfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DdsXxxx.idl'", refDdsidlfile);

	ubigint refUasrvhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdUasrv.h'", refUasrvhfile);
	ubigint refUasrvcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxcmbdUasrv.cpp'", refUasrvcppfile);

	ubigint refChkoutfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Cmbeng.sh'", refChkoutfile);
	ubigint refMakefile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Cmbeng'", refMakefile);
	ubigint refMkincfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Cmbeng.inc'", refMkincfile);
	ubigint refMkshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'make_Cmbeng.sh'", refMkshfile);
	ubigint refRmkshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'remake_Cmbeng.sh'", refRmkshfile);
	ubigint refMkcrdfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_CrdXxxxYyy'", refMkcrdfile);
	ubigint refMkiexfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_IexXxxx'", refMkiexfile);
	ubigint refMkopkfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_XxxxYyyyy'", refMkopkfile);
	ubigint refMkvecfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_VecXxxx'", refMkvecfile);

	ubigint refStashfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'start_Cmbeng.sh'", refStashfile);
	ubigint refStoshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'stop_Cmbeng.sh'", refStoshfile);

	ubigint refGblhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.h'", refGblhfile);
	ubigint refGblcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.cpp'", refGblcppfile);

	ubigint refIexhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'IexXxxxYyy.h'", refIexhfile);
	ubigint refIexcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'IexXxxxYyy.cpp'", refIexcppfile);

	ubigint refVechfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxYZzzzz.h'", refVechfile);
	ubigint refVeccppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxYZzzzz.cpp'", refVeccppfile);

	ubigint refJobhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'JobXxxxYyyZzzzz.h'", refJobhfile);
	ubigint refJobblkfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'JobXxxxYyyZzzzz_blks.cpp'", refJobblkfile);
	ubigint refJobevalfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'JobXxxxYyyZzzzz_evals.cpp'", refJobevalfile);
	ubigint refJobcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'JobXxxxYyyZzzzz.cpp'", refJobcppfile);

	ubigint refOpkblkhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxYyyyy_blks.h'", refOpkblkhfile);
	ubigint refOpkblkcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxYyyyy_blks.cpp'", refOpkblkcppfile);
	ubigint refOpkhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxYyyyy.h'", refOpkhfile);
	ubigint refOpkcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxYyyyy.cpp'", refOpkcppfile);
	ubigint refOpksqkhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'SqkXxxxYyyyy.h'", refOpksqkhfile);
	ubigint refOpksqkcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'SqkXxxxYyyyy.cpp'", refOpksqkcppfile);

	ubigint refOphfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxYyyyyZzzzz.h'", refOphfile);
	ubigint refOpcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxYyyyyZzzzz.cpp'", refOpcppfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);
	specfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, "_ini");
	createIpoutSubfolder(false, "_ini", prjshort);
	createIpoutSubfolder(false, "_ini", cmpsref);
	createIpoutSubfolder(false, "_ini", rlssref);

	createIpoutSubfolder(true, cmpsref);

	createIpoutSubfolder(true, cmpsref, "gbl");

	// -- all cards
	for (unsigned int i = 0; i < crds.nodes.size(); i++) {
		crd = crds.nodes[i];
		createIpoutSubfolder(true, cmpsref, crd->sref);
	};

	// -- all operation packs
	dbswznm->tblwznmmoppack->loadRstBySQL("SELECT * FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(ver->ref), false, opks);

	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		createIpoutSubfolder(false, cmpsref, opk->sref);
	};

	// -- IexXxxx, VecXxxx
	createIpoutSubfolder(true, cmpsref, "Iex" + Prjshort);
	createIpoutSubfolder(false, cmpsref, "Vec" + Prjshort);

	// --- prepare standard key/value pairs

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	version = StubWznm::getStubVerStd(dbswznm, ver->ref);

	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- preferred locale
	dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMLocale WHERE ref = " + to_string(ver->refWznmMLocale), PREFLCL);

	PREFLCL = StrMod::uc(PREFLCL);

	// -- directories
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "buildroot", buildroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "libroot", libroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "binroot", binroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "reproot", reproot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "nddshome", nddshome);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "uasdkroot", uasdkroot);

	// --- deployment scripts (WznmWrsrvDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("CMPSREF"); vals.push_back(CMPSREF);
	keys.push_back("cmpsref"); vals.push_back(cmpsref);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("inclibeq"); vals.push_back(inclibeq);

	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);
	keys.push_back("binroot"); vals.push_back(binroot);
	keys.push_back("reproot"); vals.push_back(reproot);
	keys.push_back("nddshome"); vals.push_back(nddshome);
	keys.push_back("uasdkroot"); vals.push_back(uasdkroot);
	keys.push_back("ncore"); vals.push_back(ncore);

	keys.push_back("Crdsref"); vals.push_back("Crdsref");
	keys.push_back("crdsref"); vals.push_back("crdsref");

	keys.push_back("Opksref"); vals.push_back("Opksref");
	keys.push_back("opksref"); vals.push_back("opksref");

	addInv(new DpchInvWznmWrsrvDeploy(0, 0, rls->ref, Prjshort, ipfolder + "/_rls/" + rlssref));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkincfile, "", outfolder + "/_rls/" + rlssref + "/Makefile.inc", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkshfile, "", outfolder + "/_rls/" + rlssref + "/make.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refRmkshfile, "", outfolder + "/_rls/" + rlssref + "/remake.sh", keys, vals));

	for (unsigned int i = 0; i < crds.nodes.size(); i++) {
		crd = crds.nodes[i];

		vals[vals.size()-4] = crd->sref;
		vals[vals.size()-3] = StrMod::lc(crd->sref);

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkcrdfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_" + crd->sref, keys, vals));
	};

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkiexfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_Iex" + Prjshort, keys, vals));

	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		vals[vals.size()-2] = opk->sref;
		vals[vals.size()-1] = StrMod::lc(opk->sref);

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkopkfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_" + opk->sref, keys, vals));
	};

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkvecfile, "", outfolder + "/_rls/" + rlssref + "/Makefile_Vec" + Prjshort, keys, vals));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refStashfile, "", outfolder + "/_ini/" + rlssref + "/start.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refStoshfile, "", outfolder + "/_ini/" + rlssref + "/stop.sh", keys, vals));

	// --- preferences file (WznmWrsrvPref)
	addInv(new DpchInvWznmWrsrvPref(0, 0, rls->ref, "", outfolder + "/_ini/" + rlssref + "/Pref" + Cmpsref + ".xml"));

	if (!dplonly) {
		// --- initialization files (WznmWrsrvInixml)
		addInv(new DpchInvWznmWrsrvInixml(0, 0, ver->ref, Prjshort, outfolder + "/_ini/" + cmpsref));

		// --- combined engine globals (WznmWrsrvCmbengbase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("Prjtit"); vals.push_back(Prjtit);
		keys.push_back("version"); vals.push_back(version);
		keys.push_back("PREFLCL"); vals.push_back(PREFLCL);

		addInv(new DpchInvWznmWrsrvCmbengbase(0, 0, ver->ref, xchg->stgwznmtenant.orgname, Prjshort, ipfolder + "/" + cmpsref));

		// -- Xxxxcmbd_exe
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCmbdexehfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbd_exe.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCmbdexecppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbd_exe.cpp", keys, vals));

		// -- Appsrv
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refAppsrvhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdAppsrv.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refAppsrvcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdAppsrv.cpp", keys, vals));

		// -- Jobprc
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJprchfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdJobprc.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJprccppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdJobprc.cpp", keys, vals));

		// -- Opprc
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOprchfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdOpprc.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOprccppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdOpprc.cpp", keys, vals));

		// -- Xxxxcmbd
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCmbdhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbd.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCmbdcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbd.cpp", keys, vals));

		if (hasdds) {
			// -- Ddspub
			addInv(new DpchInvWznmWrsrvDds(0, 0, cmp->ref, Prjshort, ipfolder + "/" + cmpsref, ipfolder + "/_ini/" + prjshort));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDdspubhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdDdspub.h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDdspubcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdDdspub.cpp", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDdsidlfile, "", outfolder + "/_ini/" + prjshort + "/Dds" + Prjshort + ".idl", keys, vals));
		};

		if (hasua) {
			// -- Uasrv
			addInv(new DpchInvWznmWrsrvUa(0, 0, ver->ref, Prjshort, Cmpsref, ipfolder + "/" + cmpsref));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refUasrvhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdUasrv.h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refUasrvcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + "cmbdUasrv.cpp", keys, vals));
		};

		// --- server globals (WznmWrsrvBase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		addInv(new DpchInvWznmWrsrvBase(0, 0, ver->ref, Prjshort, ipfolder + "/" + cmpsref));

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refGblhfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + ".h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refGblcppfile, "", outfolder + "/" + cmpsref + "/" + Prjshort + ".cpp", keys, vals));

		// --- app-wide vectors (DpchInvWznmWrsrvVec)
		keys.push_back("Vecsref"); vals.push_back("Vecsref");
		keys.push_back("VECSREF"); vals.push_back("VECSREF");

		dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND ((ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN) + ") OR (ixVBasetype = "
					+ to_string(VecWznmVMVectorBasetype::OR) + ")) AND ((hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::VOID) + ") OR (hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + ")) AND hkUref = 0 ORDER BY sref ASC", false, vecs);

		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			addInv(new DpchInvWznmWrsrvVec(0, 0, vec->ref, Prjshort, ipfolder + "/" + cmpsref + "/Vec" + Prjshort));

			vals[vals.size()-2] = vec->sref;
			vals[vals.size()-1] = StrMod::uc(vec->sref);

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVechfile, "", outfolder + "/" + cmpsref + "/Vec" + Prjshort + "/" + vec->sref + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVeccppfile, "", outfolder + "/" + cmpsref + "/Vec" + Prjshort + "/" + vec->sref + ".cpp", keys, vals));
		};

		// --- engine base jobs (WznmWrsrvRootsess)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("PREFLCL"); vals.push_back(PREFLCL);

		keys.push_back("Supcls"); vals.push_back("Supcls");
		keys.push_back("Jobsref"); vals.push_back("Jobsref");
		keys.push_back("JOBSREF"); vals.push_back("JOBSREF");

		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::ROOT), false, jobs);
		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS), true, jobs);

		addInv(new DpchInvWznmWrsrvRootsess(0, 0, ver->ref, Prjshort, specfolder + "/" + cmpsref));

		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];

			vals[vals.size()-3] = "Job" + Prjshort;
			vals[vals.size()-2] = job->sref;
			vals[vals.size()-1] = StrMod::uc(job->sref);

			addInv(new DpchInvWznmWrsrvJob(0, 0, job->ref, xchg->stgwznmtenant.orgweb, Prjshort, ipfolder + "/" + cmpsref));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobhfile, "", outfolder + "/" + cmpsref + "/" + job->sref + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobblkfile, "", outfolder + "/" + cmpsref + "/" + job->sref + "_blks.cpp", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobcppfile, "", outfolder + "/" + cmpsref + "/" + job->sref + ".cpp", keys, vals));
		};

		// --- global jobs
		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " AND Global = 1 ORDER BY TblWznmMJob.sref ASC", false, jobs);

		// write to global job directory
		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];

			if (job->Clisrv) vals[vals.size()-3] = "Csjob" + Prjshort;
			else vals[vals.size()-3] = "Job" + Prjshort;
			vals[vals.size()-2] = job->sref;
			vals[vals.size()-1] = StrMod::uc(job->sref);

			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = " + to_string(job->ref), cnt);
			hasblks = (cnt > 0);
			if (!hasblks) {
				dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref), cnt);
				hasblks = (cnt > 0);
			};

			Wznm::getJobevals(dbswznm, job, bitsEval, rulesEval, exprsEval);
			hasevals = (bitsEval.size() > 0);

			addInv(new DpchInvWznmWrsrvJob(0, 0, job->ref, xchg->stgwznmtenant.orgweb, Prjshort, ipfolder + "/" + cmpsref + "/gbl"));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobhfile, "", outfolder + "/" + cmpsref + "/gbl/" + job->sref + ".h", keys, vals));
			if (hasblks) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobblkfile, "", outfolder + "/" + cmpsref + "/gbl/" + job->sref + "_blks.cpp", keys, vals));
			if (hasevals) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobevalfile, "", outfolder + "/" + cmpsref + "/gbl/" + job->sref + "_evals.cpp", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobcppfile, "", outfolder + "/" + cmpsref + "/gbl/" + job->sref + ".cpp", keys, vals));

			if (job->ixVBasetype == VecWznmVMJobBasetype::PNL) {
				addInv(new DpchInvWznmWrsrvPnl(0, 0, job->ref, Prjshort, specfolder + "/" + cmpsref + "/gbl"));
			} else if (job->ixVBasetype == VecWznmVMJobBasetype::QRY) {
				addInv(new DpchInvWznmWrsrvQry(0, 0, job->ref, Prjshort, specfolder + "/" + cmpsref + "/gbl"));
			};
		};

		// --- cards and their subordinate jobs
		for (unsigned int i = 0; i < crds.nodes.size(); i++) {
			crd = crds.nodes[i];

			ipfld = ipfolder + "/" + cmpsref + "/" + crd->sref;
			specfld = specfolder + "/" + cmpsref + "/" + crd->sref;
			outfld = outfolder + "/" + cmpsref + "/" + crd->sref;

			jobs.clear();
			Wznm::getCrdsubjobs(dbswznm, jobs, crd->refWznmMJob);

			for (unsigned int j = 0; j < jobs.nodes.size(); j++) {
				job = jobs.nodes[j];

				if (job->Clisrv) vals[vals.size()-3] = "Csjob" + Prjshort;
				else vals[vals.size()-3] = "Job" + Prjshort;
				vals[vals.size()-2] = job->sref;
				vals[vals.size()-1] = StrMod::uc(job->sref);

				dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = " + to_string(job->ref), cnt);
				hasblks = (cnt > 0);
				if (!hasblks) {
					dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref), cnt);
					hasblks = (cnt > 0);
				};

				Wznm::getJobevals(dbswznm, job, bitsEval, rulesEval, exprsEval);
				hasevals = (bitsEval.size() > 0);

				addInv(new DpchInvWznmWrsrvJob(0, 0, job->ref, xchg->stgwznmtenant.orgweb, Prjshort, ipfld));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobhfile, "", outfld + "/" + job->sref + ".h", keys, vals));
				if (hasblks) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobblkfile, "", outfld + "/" + job->sref + "_blks.cpp", keys, vals));
				if (hasevals) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobevalfile, "", outfld + "/" + job->sref + "_evals.cpp", keys, vals));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobcppfile, "", outfld + "/" + job->sref + ".cpp", keys, vals));

				if (job->ixVBasetype == VecWznmVMJobBasetype::CRD) {
					addInv(new DpchInvWznmWrsrvCrd(0, 0, job->ref, Prjshort, specfld));
				} else if (job->ixVBasetype == VecWznmVMJobBasetype::DLG) {
					addInv(new DpchInvWznmWrsrvDlg(0, 0, job->ref, Prjshort, specfld));
				} else if (job->ixVBasetype == VecWznmVMJobBasetype::PNL) {
					addInv(new DpchInvWznmWrsrvPnl(0, 0, job->ref, Prjshort, specfld));
				} else if (job->ixVBasetype == VecWznmVMJobBasetype::QRY) {
					addInv(new DpchInvWznmWrsrvQry(0, 0, job->ref, Prjshort, specfld));
				};
			};
		};

		// --- import/export complexes and corresponding jobs
		keys.push_back("Iexsref"); vals.push_back("Iexsref");
		keys.push_back("IEXSREF"); vals.push_back("IEXSREF");

		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::IEX) + " ORDER BY sref ASC", false, jobs);

		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];

			if (dbswznm->tblwznmmimpexpcplx->loadRecByRef(job->refUref, &iex)) {
				vals[vals.size()-5] = "Job" + Prjshort;
				vals[vals.size()-4] = job->sref;
				vals[vals.size()-3] = StrMod::uc(job->sref);

				vals[vals.size()-2] = iex->sref;
				vals[vals.size()-1] = StrMod::uc(iex->sref);

				addInv(new DpchInvWznmWrsrvJob(0, 0, job->ref, xchg->stgwznmtenant.orgweb, Prjshort, ipfolder + "/" + cmpsref + "/Iex" + Prjshort));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobhfile, "", outfolder + "/" + cmpsref + "/Iex" + Prjshort + "/" + job->sref + ".h", keys, vals));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobblkfile, "", outfolder + "/" + cmpsref + "/Iex" + Prjshort + "/" + job->sref + "_blks.cpp", keys, vals));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobcppfile, "", outfolder + "/" + cmpsref + "/Iex" + Prjshort + "/" + job->sref + ".cpp", keys, vals));

				addInv(new DpchInvWznmWrsrvIex(0, 0, job->ref, Prjshort, specfolder + "/" + cmpsref + "/Iex" + Prjshort));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refIexhfile, "", outfolder + "/" + cmpsref + "/Iex" + Prjshort + "/" + iex->sref + ".h", keys, vals));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refIexcppfile, "", outfolder + "/" + cmpsref + "/Iex" + Prjshort + "/" + iex->sref + ".cpp", keys, vals));

				delete iex;
			};
		};

		keys.pop_back(); vals.pop_back();
		keys.pop_back(); vals.pop_back();
		// -

		// --- operation packs
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);

		keys.push_back("Opksref"); vals.push_back("Opksref");
		keys.push_back("OPKSREF"); vals.push_back("OPKSREF");

		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];

			vals[vals.size()-2] = opk->sref;
			vals[vals.size()-1] = StrMod::uc(opk->sref);

			addInv(new DpchInvWznmWrsrvOpk(0, 0, opk->ref, xchg->stgwznmtenant.orgweb, Prjshort, ipfolder + "/" + cmpsref + "/" + opk->sref));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpkblkhfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/" + opk->sref + "_blks.h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpkblkcppfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/" + opk->sref + "_blks.cpp", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpkhfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/" + opk->sref + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpkcppfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/" + opk->sref + ".cpp", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpksqkhfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/Sqk" + opk->sref + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpksqkcppfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/Sqk" + opk->sref + ".cpp", keys, vals));
		};

		// --- operations
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("Opksref"); vals.push_back("Opksref");
		keys.push_back("Opsref"); vals.push_back("Opsref");
		keys.push_back("OPSREF"); vals.push_back("OPSREF");
		keys.push_back("opcmt"); vals.push_back("opcmt");

		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];

			vals[vals.size()-4] = opk->sref;

			dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);

			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];

				vals[vals.size()-3] = op->sref;
				vals[vals.size()-2] = StrMod::uc(op->sref);
				vals[vals.size()-1] = op->Comment;

				addInv(new DpchInvWznmWrsrvOp(0, 0, op->ref, Prjshort, ipfolder + "/" + cmpsref + "/" + opk->sref));

				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOphfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/" + op->sref + ".h", keys, vals));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refOpcppfile, "", outfolder + "/" + cmpsref + "/" + opk->sref + "/" + op->sref + ".cpp", keys, vals));
			};
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWznmRlsWrite::createDbs(
			DbsWznm* dbswznm
			, const bool dplonly
		) {
	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string sbeconfig;

	bool mar, my, pg, lite;

	string version, created;
	string vermajor, verminor, versub;
	string buildroot, libroot;
	string dbsusername, dbspassword;

	vector<string> keys;
	vector<string> vals;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;
	string tblshort;

	bool hasvecs;

	string sref;

	uint cnt;

	// --- load basics and database types
	dbswznm->tblwznmmrelease->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "sbeconfig", sbeconfig);

	lite = ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) != 0);
	mar = ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO)) != 0);
	my = ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) != 0);
	pg = ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG) != 0);

	// --- find template files in archive
	ubigint refDbshfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DbsXxxx.h'", refDbshfile);
	ubigint refDbsvecfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DbsXxxx_vecs.cpp'", refDbsvecfile);
	ubigint refDbscppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DbsXxxx.cpp'", refDbscppfile);

	ubigint refLitesqlfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CreateDbsXxxxLite.sql'", refLitesqlfile);
	ubigint refMysqlfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CreateDbsXxxxMy.sql'", refMysqlfile);
	ubigint refPgsqlfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CreateDbsXxxxPg.sql'", refPgsqlfile);

	ubigint refCluhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxCYyyyy.h'", refCluhfile);
	ubigint refClucppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxCYyyyy.cpp'", refClucppfile);
	ubigint refQemhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxQEmpty.h'", refQemhfile);
	ubigint refQemcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxQEmpty.cpp'", refQemcppfile);
	ubigint refQtbhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxQYyyyy.h'", refQtbhfile);
	ubigint refQtbcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxQYyyyy.cpp'", refQtbcppfile);
	ubigint refTblhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxYZzzzz.h'", refTblhfile);
	ubigint refTblvecfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxYZzzzz_vecs.cpp'", refTblvecfile);
	ubigint refTblcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxYZzzzz.cpp'", refTblcppfile);

	ubigint refChkoutfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Dbs.sh'", refChkoutfile);
	ubigint refMakefile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Dbs'", refMakefile);
	ubigint refMkallfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'makeall_Dbs.sh'", refMkallfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, "_ini");
	createIpoutSubfolder(false, "_ini", cmpsref);
	if (StrMod::srefInSrefs(sbeconfig, "my") || StrMod::srefInSrefs(sbeconfig, "mar") || StrMod::srefInSrefs(sbeconfig, "pg")) createIpoutSubfolder(false, "_ini", rlssref);

	createIpoutSubfolder(false, cmpsref);

	// --- prepare standard key/value pairs

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- directories, number of cores and database credentials
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "buildroot", buildroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "libroot", libroot);

	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "dbsusername", dbsusername);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "dbspassword", dbspassword);

	// --- deployment scripts
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("inclibeq"); vals.push_back(inclibeq);
	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);
	keys.push_back("ncore"); vals.push_back(ncore);

	addInv(new DpchInvWznmWrdbsDeploy(0, 0, rls->ref, ipfolder + "/_rls/" + rlssref));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkallfile, "", outfolder + "/_rls/" + rlssref + "/makeall.sh", keys, vals));

	// --- release-specific SQL scripts
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("orgname"); vals.push_back(xchg->stgwznmtenant.orgname);
	keys.push_back("dbsusername"); vals.push_back(dbsusername);
	keys.push_back("dbspassword"); vals.push_back(dbspassword);

	// -- CreateDbsXxxx.sql
	addInv(new DpchInvWznmWrdbsSql(0, 0, rls->ref, Prjshort, ipfolder + "/_ini"));

	if (mar && StrMod::srefInSrefs(sbeconfig, "mar")) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMysqlfile, "", outfolder + "/_ini/" + rlssref + "/CreateDbs" + Prjshort + "Mar.sql", keys, vals));
	if (my && StrMod::srefInSrefs(sbeconfig, "my")) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMysqlfile, "", outfolder + "/_ini/" + rlssref + "/CreateDbs" + Prjshort + "My.sql", keys, vals));
	if (pg && StrMod::srefInSrefs(sbeconfig, "pg")) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPgsqlfile, "", outfolder + "/_ini/" + rlssref + "/CreateDbs" + Prjshort + "Pg.sql", keys, vals));
	if (lite && StrMod::srefInSrefs(sbeconfig, "lite")) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refLitesqlfile, "", outfolder + "/_ini/" + cmpsref + "/CreateDbs" + Prjshort + "Lite.sql", keys, vals));

	if (!dplonly) {
		// --- database globals (DbsXxxx)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		// -- DbsXxxx
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND ((ixVBasetype = " + to_string(VecWznmVMVectorBasetype::LIN) + ") OR (ixVBasetype = "
					+ to_string(VecWznmVMVectorBasetype::OR) + ")) AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::TBL) + " AND hkUref = 0", cnt);

		hasvecs = (cnt > 0);

		addInv(new DpchInvWznmWrdbsDbs(0, 0, ver->ref, Prjshort, ipfolder + "/" + cmpsref));

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDbshfile, "", outfolder + "/" + cmpsref + "/Dbs" + Prjshort + ".h", keys, vals));
		if (hasvecs) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDbsvecfile, "", outfolder + "/" + cmpsref + "/Dbs" + Prjshort + "_vecs.cpp", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDbscppfile, "", outfolder + "/" + cmpsref + "/Dbs" + Prjshort + ".cpp", keys, vals));

		// --- cluster tables
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("TBLSHORT"); vals.push_back("TBLSHORT");
		keys.push_back("Tblshort"); vals.push_back("Tblshort");
		keys.push_back("supref"); vals.push_back("supref");

		dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::CLUST, ver->ref, false, tbls);

		for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
			tbl = tbls.nodes[i];

			addInv(new DpchInvWznmWrdbsTbl(0, 0, tbl->ref, Prjshort, (mar || my), pg, lite, ipfolder + "/" + cmpsref));

			tblshort = tbl->sref.substr(3+4+1);

			vals[vals.size()-3] = StrMod::uc(tblshort);
			vals[vals.size()-2] = tblshort;

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCluhfile, "", outfolder + "/" + cmpsref + "/" + tbl->sref.substr(3) + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refClucppfile, "", outfolder + "/" + cmpsref + "/" + tbl->sref.substr(3) + ".cpp", keys, vals));
		};

		// --- query tables
		dbswznm->tblwznmmtable->loadRstByTypVer(VecWznmVMTableBasetype::QRY, ver->ref, false, tbls);

		for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
			tbl = tbls.nodes[i];

			addInv(new DpchInvWznmWrdbsTbl(0, 0, tbl->ref, Prjshort, (mar || my), pg, lite, ipfolder + "/" + cmpsref));

			tblshort = tbl->sref.substr(3+4+1);

			vals[vals.size()-3] = StrMod::uc(tblshort);
			vals[vals.size()-2] = tblshort;

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refQtbhfile, "", outfolder + "/" + cmpsref + "/" + tbl->sref.substr(3) + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refQtbcppfile, "", outfolder + "/" + cmpsref + "/" + tbl->sref.substr(3) + ".cpp", keys, vals));
		};

		// --- tables which are neither cluster nor query
		dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype <> " + to_string(VecWznmVMTableBasetype::CLUST) + " AND ixVBasetype <> " + to_string(VecWznmVMTableBasetype::QRY), false, tbls);

		for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
			tbl = tbls.nodes[i];

			addInv(new DpchInvWznmWrdbsTbl(0, 0, tbl->ref, Prjshort, (mar || my), pg, lite, ipfolder + "/" + cmpsref));

			tblshort = tbl->sref.substr(3+4);

			vals[vals.size()-3] = StrMod::uc(tblshort);
			vals[vals.size()-2] = tblshort;

			// additional specific placeholder for tables with HRSTUP load function: supref
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(tbl->ref) + " AND ixVLoadtype = " + to_string(VecWznmVAMTableLoadfctLoadtype::HRSTUP), cnt);
			if (cnt > 0) {
				dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND Short = 'sup'", sref);
				vals[vals.size()-1] = sref;
			};

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refTblhfile, "", outfolder + "/" + cmpsref + "/" + tbl->sref.substr(3) + ".h", keys, vals));

			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::TBL) + " AND TblWznmMVector.hkUref = " + to_string(tbl->ref) + " AND ((ixVBasetype = "
					+ to_string(VecWznmVMVectorBasetype::LIN) + ") OR (ixVBasetype = " + to_string(VecWznmVMVectorBasetype::OR) + "))", cnt);
			if (cnt > 0) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refTblvecfile, "", outfolder + "/" + cmpsref + "/" + tbl->sref.substr(3) + "_vecs.cpp", keys, vals));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refTblcppfile, "", outfolder + "/" + cmpsref + "/" + tbl->sref.substr(3) + ".cpp", keys, vals));
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWznmRlsWrite::createWebapp(
			DbsWznm* dbswznm
			, const bool dplonly
		) {
	vector<ubigint> refs;

	uint cnt;

	string s;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string version, vermajor, verminor, versub;
	string webroot, reproot;

	vector<string> keys;
	vector<string> vals;

	ListWznmMCard crds;
	WznmMCard* crd = NULL;

	ListWznmMDialog dlgs;
	WznmMDialog* dlg = NULL;

	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;
	WznmMPanel* pnl2 = NULL;

	bool hashdr, hasftr, hasdse;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	vector<unsigned int> icsBasecons;

	unsigned int ncol;

	unsigned int h, h1, h2;

	// --- load basics
	dbswznm->tblwznmmrelease->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	dbswznm->tblwznmmmodule->loadRefsByVer(ver->ref, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, crds);

	// --- find template files in archive
	ubigint refIfrGzfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'iframe.tgz'", refIfrGzfile);
	ubigint refIconGzfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'icon.tgz'", refIconGzfile);
	ubigint refScrGzfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'script.tgz'", refScrGzfile);
	ubigint refStyGzfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'style.tgz'", refStyGzfile);

	ubigint refSrcXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'srcxxxx.xml'", refSrcXmfile);
	ubigint refGblJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Xxxx.js'", refGblJsfile);
	ubigint refAlrJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'alr.js'", refAlrJsfile);
	ubigint refLstJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'lst.js'", refLstJsfile);
	ubigint refPupJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'pup.js'", refPupJsfile);
	ubigint refRbuJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'rbu.js'", refRbuJsfile);
	ubigint refSldJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'sld.js'", refSldJsfile);
	ubigint refUpdJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'upd.js'", refUpdJsfile);

	ubigint refCsHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CrdXxxxStart.html'", refCsHtfile);
	ubigint refCssrcXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CrdXxxxStart_src.xml'", refCssrcXmfile);
	ubigint refCsJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CrdXxxxStart.js'", refCsJsfile);
	ubigint refPsfaXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxStartFailure.xml'", refPsfaXmfile);
	ubigint refPsliXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxStartLogin.xml'", refPsliXmfile);
	ubigint refPsloXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxStartLogout.xml'", refPsloXmfile);
	ubigint refPssuXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxStartSuccess.xml'", refPssuXmfile);
	ubigint refPssulstXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxStartSuccess_LstSuspsess.xml'", refPssulstXmfile);

	ubigint refMenHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'MenXxx.html'", refMenHtfile);

	ubigint refCusXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CusXxx.xml'", refCusXmfile);
	ubigint refLstXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'LstXxx.xml'", refLstXmfile);

	ubigint refCrdHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CrdXxxxYyy.html'", refCrdHtfile);
	ubigint refCrdJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CrdXxxxYyy.js'", refCrdJsfile);
	ubigint refCrvHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'CrdXxxxYyy_Refvoid.html'", refCrvHtfile);

	ubigint refPhcXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyHeadbar_cont.xml'", refPhcXmfile);
	ubigint refPhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyHeadbar.html'", refPhHtfile);
	ubigint refPhJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyHeadbar.js'", refPhJsfile);

	ubigint refPhlcXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_cont_Headline.xml'", refPhlcXmfile);
	ubigint refPhlHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_Headline.html'", refPhlHtfile);
	ubigint refPhlJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_Headline.js'", refPhlJsfile);

	ubigint refPfaHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_a_Form.html'", refPfaHtfile);
	ubigint refPfbHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_b_Form.html'", refPfbHtfile);
	ubigint refPfbcXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bcont_Form.xml'", refPfbcXmfile);
	ubigint refPfbfHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bftr_Form.html'", refPfbfHtfile);
	ubigint refPfbhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bhdr_Form.html'", refPfbhHtfile);
	ubigint refPfHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_Form.html'", refPfHtfile);
	ubigint refPfJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_Form.js'", refPfJsfile);

	ubigint refPlaHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList_a.html'", refPlaHtfile);
	ubigint refPlasHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList_aside.html'", refPlasHtfile);
	ubigint refPlbHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList_b.html'", refPlbHtfile);
	ubigint refPlbfXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList_bftr.xml'", refPlbfXmfile);
	ubigint refPlbhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList_bhdr.html'", refPlbhHtfile);
	ubigint refPlbsHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList_bside.html'", refPlbsHtfile);
	ubigint refPlbtXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList_btbl.xml'", refPlbtXmfile);
	ubigint refPlHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList.html'", refPlHtfile);
	ubigint refPlJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyList.js'", refPlJsfile);

	ubigint refPraHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec_a.html'", refPraHtfile);
	ubigint refPrasHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec_aside.html'", refPrasHtfile);
	ubigint refPrbHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec_b.html'", refPrbHtfile);
	ubigint refPrbhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec_bhdr.html'", refPrbhHtfile);
	ubigint refPrbsHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec_bside.html'", refPrbsHtfile);
	ubigint refPrlhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec_lhs.html'", refPrlhHtfile);
	ubigint refPrrhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec_rhs.html'", refPrrhHtfile);
	ubigint refPrHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec.html'", refPrHtfile);
	ubigint refPrJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyRec.js'", refPrJsfile);

	ubigint refPrfbHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_b_Recform.html'", refPrfbHtfile);
	ubigint refPrfbcXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bcont_Recform.xml'", refPrfbcXmfile);
	ubigint refPrfbfHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bftr_Recform.html'", refPrfbfHtfile);
	ubigint refPrfbhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bhdr_Recform.html'", refPrfbhHtfile);
	ubigint refPrfHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_Recform.html'", refPrfHtfile);
	ubigint refPrfJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_Recform.js'", refPrfJsfile);

	ubigint refPnlaHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_a.html'", refPnlaHtfile);
	ubigint refPnlasHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_aside.html'", refPnlasHtfile);
	ubigint refPnlbHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_b.html'", refPnlbHtfile);
	ubigint refPnlbfXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bftr.xml'", refPnlbfXmfile);
	ubigint refPnlbhHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bhdr.html'", refPnlbhHtfile);
	ubigint refPnlbsHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_bside.html'", refPnlbsHtfile);
	ubigint refPnlbtXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz_btbl.xml'", refPnlbtXmfile);
	ubigint refPnlHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz.html'", refPnlHtfile);
	ubigint refPnlJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'PnlXxxxYyyZzzzz.js'", refPnlJsfile);

	ubigint refDlgHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DlgXxxxYyyZzzzz.html'", refDlgHtfile);
	ubigint refDlghXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DlgXxxxYyyZzzzz_hdr.xml'", refDlghXmfile);
	ubigint refDlgfHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DlgXxxxYyyZzzzz_ftr.html'", refDlgfHtfile);
	ubigint refDlghHtfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DlgXxxxYyyZzzzz_hdr.html'", refDlghHtfile);
	ubigint refDlgaXmfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DlgXxxxYyyZzzzzAaa.xml'", refDlgaXmfile);
	ubigint refDlgJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DlgXxxxYyyZzzzz.js'", refDlgJsfile);
	ubigint refDlgndJsfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DlgXxxxYyyZzzzz_Nodse.js'", refDlgndJsfile);

	ubigint refChkoutfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Web.sh'", refChkoutfile);
	ubigint refChkinfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkin_Web.sh'", refChkinfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, cmpsref);
	
	// -- all cards
	for (unsigned int i = 0; i < crds.nodes.size(); i++) {
		crd = crds.nodes[i];
		createIpoutSubfolder(false, cmpsref, crd->sref);
	};

	// -- CrdXxxxStart
	createIpoutSubfolder(false, cmpsref, "Crd" + Prjshort + "Start");

	// -- iframe, icon, script and style
	createIpoutSubfolder(false, cmpsref, "iframe");
	createIpoutSubfolder(false, cmpsref, "icon");
	createIpoutSubfolder(false, cmpsref, "script");
	createIpoutSubfolder(false, cmpsref, "style");

	// --- prepare standard key/value pairs

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	version = StubWznm::getStubVerStd(dbswznm, ver->ref);

	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- directories
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "sysroot", sysroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "webroot", webroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "reproot", reproot);

	// --- deployment scripts (WznmWrwebDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("webroot"); vals.push_back(webroot);
	keys.push_back("reproot"); vals.push_back(reproot);

	addInv(new DpchInvWznmWrwebDeploy(0, 0, ver->ref, Prjshort, ipfolder + "/_rls/" + rlssref));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkinfile, "", outfolder + "/_rls/" + rlssref + "/checkin.sh", keys, vals));

	if (!dplonly) {
		// --- web UI globals (WznmWrwebBase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("version"); vals.push_back(version);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		addInv(new DpchInvWznmWrwebBase(0, 0, ver->ref, Prjshort, ipfolder + "/" + cmpsref));

		// -- .tgz files
		Wznm::untgz(xchg->acvpath + "/" + Acv::getfile(dbswznm, refIfrGzfile), xchg->tmppath + "/" + outfolder + "/" + cmpsref + "/iframe");
		Wznm::untgz(xchg->acvpath + "/" + Acv::getfile(dbswznm, refIconGzfile), xchg->tmppath + "/" + outfolder + "/" + cmpsref + "/icon");
		Wznm::untgz(xchg->acvpath + "/" + Acv::getfile(dbswznm, refScrGzfile), xchg->tmppath + "/" + outfolder + "/" + cmpsref + "/script");
		Wznm::untgz(xchg->acvpath + "/" + Acv::getfile(dbswznm, refStyGzfile), xchg->tmppath + "/" + outfolder + "/" + cmpsref + "/style");

		// -- srcxxxx.xml
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refSrcXmfile, "", outfolder + "/" + cmpsref + "/iframe/src" + prjshort + ".xml", keys, vals));

		// -- Xxxx.js, alr.js, lst.js, pup.js, rbu.js, sld.js, upd.js
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refGblJsfile, "", outfolder + "/" + cmpsref + "/script/" + Prjshort + ".js", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refAlrJsfile, "", outfolder + "/" + cmpsref + "/script/alr.js", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refLstJsfile, "", outfolder + "/" + cmpsref + "/script/lst.js", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPupJsfile, "", outfolder + "/" + cmpsref + "/script/pup.js", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refRbuJsfile, "", outfolder + "/" + cmpsref + "/script/rbu.js", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refSldJsfile, "", outfolder + "/" + cmpsref + "/script/sld.js", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refUpdJsfile, "", outfolder + "/" + cmpsref + "/script/upd.js", keys, vals));

		// -- CrdStart
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCsHtfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Crd" + Prjshort + "Start.html", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCssrcXmfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Crd" + Prjshort + "Start_src.xml", keys, vals));

		// - key "lcl" for CrdXxxxStart.js
		s = "";
		dbswznm->loadStringBySQL("SELECT TblWznmMLocale.sref FROM TblWznmMLocale WHERE ref = " + to_string(ver->refWznmMLocale), s);
		// -
		keys.push_back("lcl"); vals.push_back(s);

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCsJsfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Crd" + Prjshort + "Start.js", keys, vals));

		keys.pop_back(); vals.pop_back();
		// -

		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPsfaXmfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Pnl" + Prjshort + "StartFailure.xml", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPsliXmfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Pnl" + Prjshort + "StartLogin.xml", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPsloXmfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Pnl" + Prjshort + "StartLogout.xml", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPssuXmfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Pnl" + Prjshort + "StartSuccess.xml", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPssulstXmfile, "", outfolder + "/" + cmpsref + "/Crd" + Prjshort + "Start/Pnl" + Prjshort + "StartSuccess_LstSuspsess.xml", keys, vals));

		// --- cards
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("version"); vals.push_back(version);

		keys.push_back("Crdshort"); vals.push_back("Crdshort");
		keys.push_back("crdshort"); vals.push_back("crdshort");

		for (unsigned int i = 0; i < crds.nodes.size(); i++) {
			crd = crds.nodes[i];

			vals[vals.size()-2] = crd->sref.substr(3+4);
			vals[vals.size()-1] = StrMod::lc(crd->sref.substr(3+4));

			addInv(new DpchInvWznmWrwebCrd(0, 0, crd->ref, Prjshort, ipfolder + "/" + cmpsref + "/" + crd->sref));

			if (crd->refIxVTbl == VecWznmVMCardRefTbl::VOID) {
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCrvHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + crd->sref + ".html", keys, vals));
			} else {
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCrdHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + crd->sref + ".html", keys, vals));
			};

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCrdJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + crd->sref + ".js", keys, vals));

			keys.push_back("Menshort"); vals.push_back("Menshort");

			dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::CAR) + " AND hkUref = " + to_string(crd->ref)
						+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::MEN) + " ORDER BY hkNum ASC", false, cons);
			for (unsigned int i = 0; i < cons.nodes.size(); i++) {
				con = cons.nodes[i];

				vals[vals.size()-1] = con->sref.substr(3);

				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMenHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + con->sref + ".html", keys, vals));
			};

			keys.pop_back(); vals.pop_back();
			// -

			// -- dialogs
			dbswznm->tblwznmmdialog->loadRstBySQL("SELECT * FROM TblWznmMDialog WHERE refWznmMCard = " + to_string(crd->ref), false, dlgs);

			keys.push_back("Dlgsref"); vals.push_back("Dlgsref");
			keys.push_back("Dlgshort"); vals.push_back("Dlgshort");
			keys.push_back("ditcnt"); vals.push_back("ditcnt");

			for (unsigned int j = 0; j < dlgs.nodes.size(); j++) {
				dlg = dlgs.nodes[j];

				addInv(new DpchInvWznmWrwebDlg(0, 0, dlg->ref, Prjshort, ipfolder + "/" + cmpsref + "/" + crd->sref));

				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref)
							+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::DIT) + " ORDER BY hkNum ASC", false, cons);

				hasdse = (cons.nodes.size() > 0);

				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref)
							+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::CUS) + " ORDER BY supNum ASC", false, cons);

				if (cons.nodes.size() > 0) {
					keys.push_back("parent"); vals.push_back("parent.parent.");
					keys.push_back("Ctlsref"); vals.push_back("Ctlsref");

					for (unsigned int k = 0; k < cons.nodes.size(); k++) {
						con = cons.nodes[k];

						vals[vals.size()-1] = con->sref;

						if (StrMod::srefInSrefs(con->srefsKOption, "iframe")) {
							s = dlg->sref;
							if (hasdse) s += con->sref.substr(0, 3) + "_" + con->sref.substr(3);
							else s += "_" + con->sref;

							addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCusXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + s + ".xml", keys, vals));
						};
					};

					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					// -
				};

				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref)
							+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::LST) + " ORDER BY supNum ASC", false, cons);

				if (cons.nodes.size() > 0) {
					keys.push_back("parent"); vals.push_back("parent.parent.");
					keys.push_back("ditshort"); vals.push_back("ditshort");
					keys.push_back("Lstsref"); vals.push_back("Lstsref");
					keys.push_back("ncol"); vals.push_back("ncol");
					keys.push_back("colspan"); vals.push_back("colspan");
					keys.push_back("multsel"); vals.push_back("multsel");

					for (unsigned int k = 0; k < cons.nodes.size(); k++) {
						con = cons.nodes[k];

						if (hasdse) {
							vals[vals.size()-5] = con->sref.substr(0, 3);
							vals[vals.size()-4] = con->sref.substr(3);
						} else {
							vals[vals.size()-4] = con->sref;
						};

						ncol = 1;
						if (StrMod::srefInSrefs(con->srefsKOption, "bicol")) ncol = 2;
						else if (StrMod::srefInSrefs(con->srefsKOption, "tricol")) ncol = 3;

						vals[vals.size()-3] = to_string(ncol);
						vals[vals.size()-2] = to_string(ncol+2);

						if (StrMod::srefInSrefs(con->srefsKOption, "multsel")) vals[vals.size()-1] = "true";
						else vals[vals.size()-1] = "false";

						s = dlg->sref;
						if (hasdse) s += con->sref.substr(0, 3) + "_" + con->sref.substr(3);
						else s += "_" + con->sref;

						addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refLstXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + s + ".xml", keys, vals));
					};

					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					// -
				};

				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref)
							+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::DIT) + " ORDER BY hkNum ASC", false, cons);

				vals[vals.size()-3] = dlg->sref;
				vals[vals.size()-2] = dlg->sref.substr(3+4+3);
				vals[vals.size()-1] = to_string(cons.nodes.size());

				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlgHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + ".html", keys, vals));

				if (hasdse) {
					keys.push_back("colspan");
					if (cons.nodes.size() < 5) vals.push_back(to_string(cons.nodes.size()+1));
					else vals.push_back("6");

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlghXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + "_hdr.xml", keys, vals));

					keys.pop_back(); vals.pop_back();
					// -

				} else addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlghHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + "_hdr.html", keys, vals));

				if (hasdse) {
					keys.push_back("Ditshort"); vals.push_back("Ditshort");

					for (unsigned int k = 0; k < cons.nodes.size(); k++) {
						con = cons.nodes[k];

						vals[vals.size()-1] = con->sref.substr(3);
						addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlgaXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + con->sref.substr(3) + ".xml", keys, vals));
					};

					keys.pop_back(); vals.pop_back();
					// -

				} else {
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlgaXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + "_cont.xml", keys, vals));
				};

				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlgfHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + "_ftr.html", keys, vals));

				if (hasdse) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlgJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + ".js", keys, vals));
				else addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDlgndJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + dlg->sref + ".js", keys, vals));
			};

			keys.pop_back(); vals.pop_back();
			keys.pop_back(); vals.pop_back();
			keys.pop_back(); vals.pop_back();
			// -
		};

		// --- panels
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);

		keys.push_back("Crdsref"); vals.push_back("Crdsref");
		keys.push_back("Crdshort"); vals.push_back("Crdshort");
		keys.push_back("crdshort"); vals.push_back("crdshort");
		keys.push_back("Pnlsref"); vals.push_back("Pnlsref");
		keys.push_back("Pnlshort"); vals.push_back("Pnlshort");

		for (unsigned int i = 0; i < crds.nodes.size(); i++) {
			crd = crds.nodes[i];

			vals[vals.size()-5] = crd->sref;
			vals[vals.size()-4] = crd->sref.substr(3+4);
			vals[vals.size()-3] = StrMod::lc(crd->sref.substr(3+4));

			dbswznm->tblwznmmpanel->loadRstByCar(crd->ref, false, pnls);
			for (unsigned int j = 0; j < pnls.nodes.size(); j++) {
				pnl = pnls.nodes[j];

				addInv(new DpchInvWznmWrwebPnl(0, 0, pnl->ref, Prjshort, ipfolder + "/" + cmpsref + "/" + crd->sref));

				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref)
							+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::CUS) + " ORDER BY supNum ASC", false, cons);

				if (cons.nodes.size() > 0) {
					keys.push_back("parent"); vals.push_back("parent.parent.parent.");
					keys.push_back("Ctlsref"); vals.push_back("Ctlsref");

					for (unsigned int k = 0; k < cons.nodes.size(); k++) {
						con = cons.nodes[k];

						vals[vals.size()-1] = con->sref;

						if (StrMod::srefInSrefs(con->srefsKOption, "iframe"))
									addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refCusXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_" + con->sref + ".xml", keys, vals));
					};

					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					// -
				};

				dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref)
							+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::LST) + " ORDER BY supNum ASC", false, cons);

				if (cons.nodes.size() > 0) {
					keys.push_back("parent"); vals.push_back("parent.parent.parent.");
					keys.push_back("Lstsref"); vals.push_back("Lstsref");
					keys.push_back("ncol"); vals.push_back("ncol");
					keys.push_back("colspan"); vals.push_back("colspan");
					keys.push_back("multsel"); vals.push_back("multsel");

					for (unsigned int k = 0; k < cons.nodes.size(); k++) {
						con = cons.nodes[k];

						vals[vals.size()-4] = con->sref;

						ncol = 1;
						if (StrMod::srefInSrefs(con->srefsKOption, "bicol")) ncol = 2;
						else if (StrMod::srefInSrefs(con->srefsKOption, "tricol")) ncol = 3;

						vals[vals.size()-3] = to_string(ncol);
						vals[vals.size()-2] = to_string(ncol+2);

						if (StrMod::srefInSrefs(con->srefsKOption, "multsel")) vals[vals.size()-1] = "true";
						else vals[vals.size()-1] = "false";

						addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refLstXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_" + con->sref + ".xml", keys, vals));
					};

					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					// -
				};

				vals[vals.size()-2] = pnl->sref;
				vals[vals.size()-1] = pnl->sref.substr(3+4+3);

				if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) {
					copyAcvtmp(dbswznm, refPhcXmfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_cont.xml");
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPhHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPhJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".js", keys, vals));

				} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) {
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPhlcXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_cont.xml", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPhlHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPhlJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".js", keys, vals));

				} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
					hashdr = true;

					hasftr = false;
					if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND hkIxVSection = "
								+ to_string(VecWznmVMControlHkSection::FTR) + " AND supRefWznmMControl = 0", cnt)) hasftr = (cnt > 0);

					// calculate content height
					h = 10;
					dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);
					Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTREGD}, 0, icsBasecons);
					for (unsigned int k = 0; k < icsBasecons.size(); k++) h += Wznm::getConheight(dbswznm, cons.nodes[icsBasecons[k]]);

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPfaHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_a.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlasHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_aside.html", keys, vals));

					// key "conth" for PnlXxxxYyyZzzzz_b_Form.html
					keys.push_back("conth"); vals.push_back(to_string(h));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPfbHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_b.html", keys, vals));
					keys.pop_back(); vals.pop_back();
					// -

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPfbcXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bcont.xml", keys, vals));

					if (hasftr) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPfbfHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bftr.html", keys, vals));
					if (hashdr) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPfbhHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bhdr.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlbsHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bside.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPfHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".html", keys, vals));

					// keys "regh", "hdrftrh" for PnlXxxxYyyZzzzz_Form.js
					keys.push_back("regh"); vals.push_back(to_string(h));

					h = 2;
					if (hashdr) h += 29;
					if (hasftr) h += 24;
					keys.push_back("hdrftrh"); vals.push_back(to_string(h));
		
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPfJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".js", keys, vals));

					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					// -

				} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
					copyAcvtmp(dbswznm, refPlaHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_a.html");
					copyAcvtmp(dbswznm, refPlasHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_aside.html");

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPlbHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_b.html", keys, vals));

					copyAcvtmp(dbswznm, refPlbfXmfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bftr.xml");
					copyAcvtmp(dbswznm, refPlbhHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bhdr.html");
					copyAcvtmp(dbswznm, refPlbsHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bside.html");
					copyAcvtmp(dbswznm, refPlbtXmfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_btbl.xml");

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPlHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPlJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".js", keys, vals));

				} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
					copyAcvtmp(dbswznm, refPraHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_a.html");
					copyAcvtmp(dbswznm, refPrasHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_aside.html");

					// - key "lrhsh" for PnlXxxxYyyRec_b.html (re-use of h for flexh, regh)
					h1 = 5; h2 = 5;

					for (unsigned int k = 0; k < pnls.nodes.size(); k++) {
						pnl2 = pnls.nodes[k];

						if (Wznm::getPnlrhs(dbswznm, pnl2)) h2 += (30+13);
						else if (Wznm::getPnllhs(dbswznm, pnl2)) h1 += (30+13);
					};

					if (h1 > h2) h = h1; else h = h2;

					keys.push_back("lrhsh"); vals.push_back(to_string(h));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrbHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_b.html", keys, vals));
					keys.pop_back(); vals.pop_back();
					// -

					copyAcvtmp(dbswznm, refPrbhHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bhdr.html");

					// - key "flexh" for PnlXxxxYyyRec_bside.html
					keys.push_back("flexh"); vals.push_back(to_string(h+1));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrbsHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bside.html", keys, vals));
					keys.pop_back(); vals.pop_back();
					// -

					copyAcvtmp(dbswznm, refPrlhHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_lhs.html");
					copyAcvtmp(dbswznm, refPrrhHtfile, outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_rhs.html");

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".html", keys, vals));

					// - key "regh" for PnlXxxxYyyRec.js
					keys.push_back("regh"); vals.push_back(to_string(h+1+45));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".js", keys, vals));
					keys.pop_back(); vals.pop_back();
					// -

				} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) {
					hashdr = (pnl->sref.find("Detail") == string::npos);

					hasftr = false;
					if (dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND hkIxVSection = "
								+ to_string(VecWznmVMControlHkSection::FTR) + " AND supRefWznmMControl = 0", cnt)) hasftr = (cnt > 0);

					// calculate content height
					h = 10;
					dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);
					Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTREGD}, 0, icsBasecons);
					for (unsigned int k = 0; k < icsBasecons.size(); k++) h += Wznm::getConheight(dbswznm, cons.nodes[icsBasecons[k]]);

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlaHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_a.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlasHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_aside.html", keys, vals));

					// key "conth" for PnlXxxxYyyZzzzz_b_Recform.html
					keys.push_back("conth"); vals.push_back(to_string(h));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrfbHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_b.html", keys, vals));
					keys.pop_back(); vals.pop_back();
					// -

					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrfbcXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bcont.xml", keys, vals));

					if (hasftr) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrfbfHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bftr.html", keys, vals));
					if (hashdr) addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrfbhHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bhdr.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlbsHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bside.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrfHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".html", keys, vals));


					// keys "regh", "hdrftrh" for PnlXxxxYyyZzzzz_Form.js
					keys.push_back("regh"); vals.push_back(to_string(h));

					h = 2;
					if (hashdr) h += 29;
					if (hasftr) h += 24;
					keys.push_back("hdrftrh"); vals.push_back(to_string(h));
		
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPrfJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".js", keys, vals));

					keys.pop_back(); vals.pop_back();
					keys.pop_back(); vals.pop_back();
					// -

				} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlaHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_a.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlasHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_aside.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlbHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_b.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlbfXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bftr.xml", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlbhHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bhdr.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlbsHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_bside.html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlbtXmfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + "_btbl.xml", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlHtfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".html", keys, vals));
					addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refPnlJsfile, "", outfolder + "/" + cmpsref + "/" + crd->sref + "/" + pnl->sref + ".js", keys, vals));
				};
			};
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWznmRlsWrite::createApi(
			DbsWznm* dbswznm
			, const bool dplonly
		) {
	vector<ubigint> refs;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string vermajor, verminor, versub;
	string buildroot, libroot;

	vector<string> keys;
	vector<string> vals;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	ListWznmMTable qtbs;
	WznmMTable* qtb = NULL;

	string tblshort;

	uint cnt;

	// --- load basics
	dbswznm->tblwznmmrelease->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	// --- find template files in archive
	ubigint refGblhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'ApiXxxx_blks.h'", refGblhfile);
	ubigint refGblcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'ApiXxxx_blks.cpp'", refGblcppfile);

	ubigint refApihfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'ApiXxxx.h'", refApihfile);
	ubigint refApicppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'ApiXxxx.cpp'", refApicppfile);

	ubigint refVecdphfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxVDpch.h'", refVecdphfile);
	ubigint refVecdpcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxVDpch.cpp'", refVecdpcppfile);

	ubigint refVechfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxYZzzzz.h'", refVechfile);
	ubigint refVeccppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxYZzzzz.cpp'", refVeccppfile);

	ubigint refJobhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'JobXxxxYyyZzzzz_Api.h'", refJobhfile);
	ubigint refJobcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'JobXxxxYyyZzzzz_Api.cpp'", refJobcppfile);

	ubigint refQtbhfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxQYyyyy_Api.h'", refQtbhfile);
	ubigint refQtbcppfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'TblXxxxQYyyyy_Api.cpp'", refQtbcppfile);

	ubigint refChkoutfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Api.sh'", refChkoutfile);
	ubigint refMakefile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'Makefile_Api'", refMakefile);
	ubigint refMkallfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'makeall_Api.sh'", refMkallfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(false, "_ini");
	createIpoutSubfolder(false, "_ini", cmpsref);

	createIpoutSubfolder(true, cmpsref);

	// --- prepare standard key/value pairs

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- directories
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "buildroot", buildroot);
	Wznm::getMchpar(dbswznm, rls->refWznmMMachine, hrefsMch, "libroot", libroot);

	// --- deployment scripts (WznmWrapiDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);
	keys.push_back("cchost"); vals.push_back(cchost);

	keys.push_back("sysroot"); vals.push_back(sysroot);
	keys.push_back("inclibeq"); vals.push_back(inclibeq);
	keys.push_back("buildroot"); vals.push_back(buildroot);
	keys.push_back("libroot"); vals.push_back(libroot);

	keys.push_back("ncore"); vals.push_back(ncore);

	addInv(new DpchInvWznmWrapiDeploy(0, 0, rls->ref, Prjshort, ipfolder + "/_rls/" + rlssref));

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMakefile, "", outfolder + "/_rls/" + rlssref + "/Makefile", keys, vals));
	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refMkallfile, "", outfolder + "/_rls/" + rlssref + "/makeall.sh", keys, vals));

	if (!dplonly) {
		// --- API globals (WznmWrapiBase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		addInv(new DpchInvWznmWrapiBase(0, 0, ver->ref, Prjshort, ipfolder + "/" + cmpsref));

		// -- ApiXxxx_blks
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refGblhfile, "", outfolder + "/" + cmpsref + "/Api" + Prjshort + "_blks.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refGblcppfile, "", outfolder + "/" + cmpsref + "/Api" + Prjshort + "_blks.cpp", keys, vals));

		// -- ApiXxxx
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refApihfile, "", outfolder + "/" + cmpsref + "/Api" + Prjshort + ".h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refApicppfile, "", outfolder + "/" + cmpsref + "/Api" + Prjshort + ".cpp", keys, vals));

		// -- global vectors
		dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(ver->ref) + " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = 0", false, vecs);

		keys.push_back("VECSREF"); vals.push_back("VECSREF");
		keys.push_back("Vecsref"); vals.push_back("Vecsref");

		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			vals[vals.size()-2] = StrMod::uc(vec->sref);
			vals[vals.size()-1] = vec->sref;

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVechfile, "", outfolder + "/" + cmpsref + "/" + vec->sref + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVeccppfile, "", outfolder + "/" + cmpsref + "/" + vec->sref + ".cpp", keys, vals));
		};

		// -- VecXxxxVDpch
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVecdphfile, "", outfolder + "/" + cmpsref + "/Vec" + Prjshort + "VDpch.h", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVecdpcppfile, "", outfolder + "/" + cmpsref + "/Vec" + Prjshort + "VDpch.cpp", keys, vals));

		// --- jobs (WznmWrapiJob)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("JOBSREF"); vals.push_back("JOBSREF");
		keys.push_back("Jobsref"); vals.push_back("Jobsref");

		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " ORDER BY sref ASC", false, jobs);

		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];

			// count shared blocks
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
						+ " AND (((reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0) OR ((wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0))", cnt);
		
			if (cnt > 0) {
				vals[vals.size()-2] = StrMod::uc(job->sref);
				vals[vals.size()-1] = job->sref;

				addInv(new DpchInvWznmWrapiJob(0, 0, cmp->ref, job->ref, xchg->stgwznmtenant.orgweb, Prjshort, ipfolder + "/" + cmpsref));

				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobhfile, "", outfolder + "/" + cmpsref + "/" + job->sref + ".h", keys, vals));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobcppfile, "", outfolder + "/" + cmpsref + "/" + job->sref + ".cpp", keys, vals));
			};
		};

		// --- query tables (WznmWrapiQtb)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);

		keys.push_back("TBLSHORT"); vals.push_back("TBLSHORT");
		keys.push_back("Tblshort"); vals.push_back("Tblshort");

		dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMQuery, TblWznmMTable WHERE TblWznmMTable.ref = TblWznmMQuery.qtbRefWznmMTable AND TblWznmMQuery.refWznmMVersion = "
					+ to_string(ver->ref) + " ORDER BY TblWznmMTable.sref ASC", false, qtbs);

		for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
			qtb = qtbs.nodes[i];

			tblshort = qtb->sref.substr(3+4+1);

			vals[vals.size()-2] = StrMod::uc(tblshort);
			vals[vals.size()-1] = tblshort;

			addInv(new DpchInvWznmWrapiQtb(0, 0, qtb->ref, ipfolder + "/" + cmpsref));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refQtbhfile, "", outfolder + "/" + cmpsref + "/" + qtb->sref.substr(3) + ".h", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refQtbcppfile, "", outfolder + "/" + cmpsref + "/" + qtb->sref.substr(3) + ".cpp", keys, vals));
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

void DlgWznmRlsWrite::createJapi(
			DbsWznm* dbswznm
			, const bool dplonly
		) {
	vector<ubigint> refs;

	WznmMRelease* rls = NULL;
	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	vector<ubigint> hrefsMch;

	string created;
	string vermajor, verminor, versub;

	vector<string> keys;
	vector<string> vals;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	ListWznmMTable qtbs;
	WznmMTable* qtb = NULL;

	string tblshort;

	uint cnt;

	// --- load basics
	dbswznm->tblwznmmrelease->loadRecByRef(xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref), &rls);
	dbswznm->tblwznmmcomponent->loadRecByRef(rls->refWznmMComponent, &cmp);
	dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver);

	dbswznm->tblwznmmmachine->loadHrefsup(rls->refWznmMMachine, hrefsMch);

	// --- find template files in archive
	ubigint refApijfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'ApiXxxx.java'", refApijfile);

	ubigint refContinfalrjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'ContInfXxxxAlert.java'", refContinfalrjfile);
	ubigint refDpchjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchXxxx.java'", refDpchjfile);
	ubigint refDpchappjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchAppXxxx.java'", refDpchappjfile);
	ubigint refDpchappalrjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchAppXxxxAlert.java'", refDpchappalrjfile);
	ubigint refDpchappinijfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchAppXxxxInit.java'", refDpchappinijfile);
	ubigint refDpchapprsmjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchAppXxxxResume.java'", refDpchapprsmjfile);
	ubigint refDpchengjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchEngXxxx.java'", refDpchengjfile);
	ubigint refDpchengackjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchEngXxxxAck.java'", refDpchengackjfile);
	ubigint refDpchengalrjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchEngXxxxAlert.java'", refDpchengalrjfile);
	ubigint refDpchengcnfjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchEngXxxxConfirm.java'", refDpchengcnfjfile);
	ubigint refDpchengspsjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'DpchEngXxxxSuspend.java'", refDpchengspsjfile);
	ubigint refStgjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'StgXxxxapi.java'", refStgjfile);

	ubigint refVecdpchjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxVDpch.java'", refVecdpchjfile);

	ubigint refJobjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'JobXxxxYyyZzzzz.java'", refJobjfile);

	ubigint refQtbjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'XxxxQYyyyy.java'", refQtbjfile);
	ubigint refLqtbjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'ListXxxxQYyyyy.java'", refLqtbjfile);

	ubigint refVecjfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'VecXxxxYZzzzz.java'", refVecjfile);

	ubigint refChkoutfile; dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMFile WHERE osrefKContent = 'cftpl' AND Filename = 'checkout_Japi.sh'", refChkoutfile);

	// --- generate folder structure
	ipfolder = Tmp::newfolder(xchg->tmppath);

	outfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMREPFOLDER, jref);
	if (outfolder == "") outfolder = Tmp::newfolder(xchg->tmppath);

	createIpoutSubfolder(false, "_rls");
	createIpoutSubfolder(false, "_rls", rlssref);

	createIpoutSubfolder(true, cmpsref);

	// --- prepare standard key/value pairs

	// -- created/modified date
	time_t rawtime;
	time(&rawtime);

	created = StrMod::timetToString(rawtime);

	// -- version
	vermajor = to_string(ver->Major);
	verminor = to_string(ver->Minor);
	versub = to_string(ver->Sub);

	// -- directories

	// --- deployment scripts (WznmWrjapiDeploy)
	keys.resize(0); vals.resize(0);
	keys.push_back("author"); vals.push_back(author);
	keys.push_back("created"); vals.push_back(created);
	keys.push_back("Prjshort"); vals.push_back(Prjshort);
	keys.push_back("prjshort"); vals.push_back(prjshort);
	keys.push_back("rlssref"); vals.push_back(rlssref);

	addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refChkoutfile, "", outfolder + "/_rls/" + rlssref + "/checkout.sh", keys, vals));

	if (!dplonly) {
		// --- Java API globals (WznmWrjapiBase)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("orgweb"); vals.push_back(xchg->stgwznmtenant.orgweb);
		keys.push_back("PRJSHORT"); vals.push_back(PRJSHORT);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);
		keys.push_back("vermajor"); vals.push_back(vermajor);
		keys.push_back("verminor"); vals.push_back(verminor);
		keys.push_back("versub"); vals.push_back(versub);

		addInv(new DpchInvWznmWrjapiBase(0, 0, ver->ref, Prjshort, ipfolder + "/" + cmpsref));

		// -- ApiXxxx
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refApijfile, "", outfolder + "/" + cmpsref + "/Api" + Prjshort + ".java", keys, vals));

		// -- ContInfXxxxAlert, DpchXxxx, DpchAppXxxx, DpchAppXxxxAlert, DpchAppXxxxInit, DpchAppXxxxResume
		// -- DpchEngXxxx, DpchEngXxxxAck, DpchEngXxxxAlert, DpchEngXxxxConfirm, DpchEngXxxxSuspend, StgXxxxapi
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refContinfalrjfile, "", outfolder + "/" + cmpsref + "/ContInf" + Prjshort + "Alert.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchjfile, "", outfolder + "/" + cmpsref + "/Dpch" + Prjshort + ".java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchappjfile, "", outfolder + "/" + cmpsref + "/DpchApp" + Prjshort + ".java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchappalrjfile, "", outfolder + "/" + cmpsref + "/DpchApp" + Prjshort + "Alert.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchappinijfile, "", outfolder + "/" + cmpsref + "/DpchApp" + Prjshort + "Init.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchapprsmjfile, "", outfolder + "/" + cmpsref + "/DpchApp" + Prjshort + "Resume.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchengjfile, "", outfolder + "/" + cmpsref + "/DpchEng" + Prjshort + ".java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchengackjfile, "", outfolder + "/" + cmpsref + "/DpchEng" + Prjshort + "Ack.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchengalrjfile, "", outfolder + "/" + cmpsref + "/DpchEng" + Prjshort + "Alert.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchengcnfjfile, "", outfolder + "/" + cmpsref + "/DpchEng" + Prjshort + "Confirm.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refDpchengspsjfile, "", outfolder + "/" + cmpsref + "/DpchEng" + Prjshort + "Suspend.java", keys, vals));
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refStgjfile, "", outfolder + "/" + cmpsref + "/Stg" + Prjshort + "api.java", keys, vals));

		// -- global vectors (WznmWrjapiVec) and VecXxxxVDpch
		dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(ver->ref) + " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = 0", false, vecs);

		keys.push_back("Vecsref"); vals.push_back("Vecsref");

		for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
			vec = vecs.nodes[i];

			vals[vals.size()-1] = vec->sref;

			addInv(new DpchInvWznmWrjapiVec(0, 0, vec->ref, Prjshort, ipfolder + "/" + cmpsref));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVecjfile, "", outfolder + "/" + cmpsref + "/" + vec->sref + ".java", keys, vals));
		};

		// -- VecXxxxVDpch
		addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refVecdpchjfile, "", outfolder + "/" + cmpsref + "/Vec" + Prjshort + "VDpch.java", keys, vals));

		// --- jobs (WznmWrjapiJob)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("prjshort"); vals.push_back(prjshort);

		keys.push_back("Jobsref"); vals.push_back("Jobsref");

		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(ver->ref) + " ORDER BY sref ASC", false, jobs);

		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];

			// count shared blocks
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
						+ " AND (((reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0) OR ((wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0))", cnt);
		
			if (cnt > 0) {
				vals[vals.size()-1] = job->sref;

				addInv(new DpchInvWznmWrjapiJob(0, 0, cmp->ref, job->ref, xchg->stgwznmtenant.orgweb, Prjshort, ipfolder + "/" + cmpsref));
				addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refJobjfile, "", outfolder + "/" + cmpsref + "/" + job->sref + ".java", keys, vals));
			};
		};

		// --- query tables (WznmWrjapiQtb)
		keys.resize(0); vals.resize(0);
		keys.push_back("author"); vals.push_back(author);
		keys.push_back("created"); vals.push_back(created);
		keys.push_back("Prjshort"); vals.push_back(Prjshort);
		keys.push_back("prjshort"); vals.push_back(prjshort);

		keys.push_back("Tblshort"); vals.push_back("Tblshort");

		dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMQuery, TblWznmMTable WHERE TblWznmMTable.ref = TblWznmMQuery.qtbRefWznmMTable AND TblWznmMQuery.refWznmMVersion = "
					+ to_string(ver->ref) + " ORDER BY TblWznmMTable.sref ASC", false, qtbs);

		for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
			qtb = qtbs.nodes[i];

			tblshort = qtb->sref.substr(3+4+1);

			vals[vals.size()-1] = tblshort;

			addInv(new DpchInvWznmWrjapiQtb(0, 0, qtb->ref, ipfolder + "/" + cmpsref));

			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refQtbjfile, "", outfolder + "/" + cmpsref + "/" + qtb->sref.substr(3) + ".java", keys, vals));
			addInv(new DpchInvWznmPrcfilePlhrpl(0, 0, refLqtbjfile, "", outfolder + "/" + cmpsref + "/List" + qtb->sref.substr(3) + ".java", keys, vals));
		};
	};

	// --- clean up
	delete rls;
	delete cmp;
	delete ver;
};

// IP cust --- IEND

DpchEngWznm* DlgWznmRlsWrite::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWznm* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWznmConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &contiacdet, &continf, &continffia, &continflfi, &continfwrc, &feedFDse, &feedFSge, &statshr, &statshrcuc, &statshrfia, &statshrlfi, &statshrwrc, items);
	};

	return dpcheng;
};

void DlgWznmRlsWrite::refreshDet(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContIacDet oldContiacdet(contiacdet);

	// IP refreshDet --- BEGIN
	// contiacdet

	// IP refreshDet --- END
	if (contiacdet.diff(&oldContiacdet).size() != 0) insert(moditems, DpchEngData::CONTIACDET);
};

void DlgWznmRlsWrite::refreshCuc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrCuc oldStatshrcuc(statshrcuc);

	// IP refreshCuc --- BEGIN
	// statshrcuc
	statshrcuc.UldAvail = evalCucUldAvail(dbswznm);
	statshrcuc.UldActive = evalCucUldActive(dbswznm);

	// IP refreshCuc --- END
	if (statshrcuc.diff(&oldStatshrcuc).size() != 0) insert(moditems, DpchEngData::STATSHRCUC);
};

void DlgWznmRlsWrite::refreshWrc(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	ContInfWrc oldContinfwrc(continfwrc);
	StatShrWrc oldStatshrwrc(statshrwrc);

	// IP refreshWrc --- RBEGIN
	// continfwrc
	continfwrc.TxtPrg = getSquawk(dbswznm);

	// statshrwrc
	statshrwrc.ButAutActive = evalWrcButAutActive(dbswznm);
	statshrwrc.ButRunActive = evalWrcButRunActive(dbswznm);
	statshrwrc.ButStoActive = evalWrcButStoActive(dbswznm);

	// IP refreshWrc --- REND
	if (continfwrc.diff(&oldContinfwrc).size() != 0) insert(moditems, DpchEngData::CONTINFWRC);
	if (statshrwrc.diff(&oldStatshrwrc).size() != 0) insert(moditems, DpchEngData::STATSHRWRC);
};

void DlgWznmRlsWrite::refreshLfi(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);
	ContInfLfi oldContinflfi(continflfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswznm);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
};

void DlgWznmRlsWrite::refreshFia(
			DbsWznm* dbswznm
			, set<uint>& moditems
		) {
	StatShrFia oldStatshrfia(statshrfia);
	ContInfFia oldContinffia(continffia);

	// IP refreshFia --- RBEGIN
	// statshrfia
	statshrfia.DldAvail = evalFiaDldAvail(dbswznm);
	statshrfia.DldActive = evalFiaDldActive(dbswznm);

	// continffia
	continffia.Dld = StubWznm::getStubRlsStd(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref)) + ".tgz";

	// IP refreshFia --- REND
	if (statshrfia.diff(&oldStatshrfia).size() != 0) insert(moditems, DpchEngData::STATSHRFIA);
	if (continffia.diff(&oldContinffia).size() != 0) insert(moditems, DpchEngData::CONTINFFIA);
};

void DlgWznmRlsWrite::refresh(
			DbsWznm* dbswznm
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

	// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbswznm);

	// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshDet(dbswznm, moditems);
	refreshCuc(dbswznm, moditems);
	refreshWrc(dbswznm, moditems);
	refreshLfi(dbswznm, moditems);
	refreshFia(dbswznm, moditems);

	muteRefresh = false;
};

void DlgWznmRlsWrite::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMINIT) {
			handleDpchAppWznmInit(dbswznm, (DpchAppWznmInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSWRITEDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswznm, &(dpchappdata->contiac), &(req->dpcheng));
			} else if (dpchappdata->has(DpchAppData::CONTIACDET)) {
				handleDpchAppDataContiacdet(dbswznm, &(dpchappdata->contiacdet), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSWRITEDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswznm, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoWrc != 0) {
				if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTAUTCLICK) {
					handleDpchAppDoWrcButAutClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTRUNCLICK) {
					handleDpchAppDoWrcButRunClick(dbswznm, &(req->dpcheng));
				} else if (dpchappdo->ixVDoWrc == VecVDoWrc::BUTSTOCLICK) {
					handleDpchAppDoWrcButStoClick(dbswznm, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			handleDpchAppWznmAlert(dbswznm, (DpchAppWznmAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswznm, req->filename);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
		if (ixVSge == VecVSge::FAIL) req->filename = handleDownloadInSgeFail(dbswznm);
		else if (ixVSge == VecVSge::DONE) req->filename = handleDownloadInSgeDone(dbswznm);

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
		if (req->dpchret->ixOpVOpres == VecOpVOpres::PROGRESS) {
			// IP handleRequest.opprogress --- INSERT
		} else {
			if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNM) {
				handleDpchRetWznm(dbswznm, (DpchRetWznm*) (req->dpchret));
			} else if (req->dpchret->ixWznmVDpch == VecWznmVDpch::DPCHRETWZNMPRCTREEMERGE) {
				handleDpchRetWznmPrctreeMerge(dbswznm, (DpchRetWznmPrctreeMerge*) (req->dpchret));
			};

			if (req->dpchret->ixOpVOpres == VecOpVOpres::SUCCESS) opNSuccess++;
			else if (req->dpchret->ixOpVOpres == VecOpVOpres::FAILURE) opNFailure++;

			if ((opNSuccess + opNFailure) == opN) {
				clearOps();

				opN = 0;
				opNSuccess = 0;

				if (opNFailure > 0) {
					opNFailure = 0;
					changeStage(dbswznm, nextIxVSgeFailure);
				} else changeStage(dbswznm, nextIxVSgeSuccess);
			};
		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::UPKIDLE) handleTimerInSgeUpkidle(dbswznm, req->sref);
		else if (ixVSge == VecVSge::CREIDLE) handleTimerInSgeCreidle(dbswznm, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::CREATE)) handleTimerWithSrefMonInSgeCreate(dbswznm);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::WRITE)) handleTimerWithSrefMonInSgeWrite(dbswznm);
	};
};

void DlgWznmRlsWrite::handleDpchAppWznmInit(
			DbsWznm* dbswznm
			, DpchAppWznmInit* dpchappwznminit
			, DpchEngWznm** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWznmRlsWrite::handleDpchAppDataContiac(
			DbsWznm* dbswznm
			, ContIac* _contiac
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::DET) && (_contiac->numFDse <= VecVDit::FIA)) ixVDit = _contiac->numFDse;
		refresh(dbswznm, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmRlsWrite::handleDpchAppDataContiacdet(
			DbsWznm* dbswznm
			, ContIacDet* _contiacdet
			, DpchEngWznm** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiacdet->diff(&contiacdet);
	// IP handleDpchAppDataContiacdet --- IBEGIN

	contiacdet.ChkBso = _contiacdet->ChkBso;

	// IP handleDpchAppDataContiacdet --- IEND
	insert(moditems, DpchEngData::CONTIACDET);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWznmRlsWrite::handleDpchAppDoButDneClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngWznmConfirm(true, jref, "");
		xchg->triggerCall(dbswznm, VecWznmVCall::CALLWZNMDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgWznmRlsWrite::handleDpchAppDoWrcButAutClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWrcButAutClick --- BEGIN
	if (statshrwrc.ButAutActive) {
		changeStage(dbswznm, VecVSge::AUTH, dpcheng);
	};
	// IP handleDpchAppDoWrcButAutClick --- END
};

void DlgWznmRlsWrite::handleDpchAppDoWrcButRunClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWrcButRunClick --- BEGIN
	if (statshrwrc.ButRunActive) {
		changeStage(dbswznm, VecVSge::CREIDLE, dpcheng);
	};
	// IP handleDpchAppDoWrcButRunClick --- END
};

void DlgWznmRlsWrite::handleDpchAppDoWrcButStoClick(
			DbsWznm* dbswznm
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppDoWrcButStoClick --- INSERT
};

void DlgWznmRlsWrite::handleDpchAppWznmAlert(
			DbsWznm* dbswznm
			, DpchAppWznmAlert* dpchappwznmalert
			, DpchEngWznm** dpcheng
		) {
	// IP handleDpchAppWznmAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRMER) {
		changeStage(dbswznm, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWznmAlert --- IEND
};

void DlgWznmRlsWrite::handleDpchRetWznm(
			DbsWznm* dbswznm
			, DpchRetWznm* dpchret
		) {
	// IP handleDpchRetWznm --- INSERT
};

void DlgWznmRlsWrite::handleDpchRetWznmPrctreeMerge(
			DbsWznm* dbswznm
			, DpchRetWznmPrctreeMerge* dpchret
		) {
	// IP handleDpchRetWznmPrctreeMerge --- IBEGIN
	logaspect = VecVSge::getSref(ixVSge);
	logfile = dpchret->logfile;
	// IP handleDpchRetWznmPrctreeMerge --- IEND
};

void DlgWznmRlsWrite::handleUploadInSgeIdle(
			DbsWznm* dbswznm
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswznm, VecVSge::UPKIDLE);
};

string DlgWznmRlsWrite::handleDownloadInSgeFail(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + logfile); // IP handleDownloadInSgeFail --- RLINE
};

string DlgWznmRlsWrite::handleDownloadInSgeDone(
			DbsWznm* dbswznm
		) {
	return(xchg->tmppath + "/" + outfolder + ".tgz"); // IP handleDownloadInSgeDone --- RLINE
};

void DlgWznmRlsWrite::handleTimerInSgeUpkidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmRlsWrite::handleTimerInSgeCreidle(
			DbsWznm* dbswznm
			, const string& sref
		) {
	changeStage(dbswznm, nextIxVSgeSuccess);
};

void DlgWznmRlsWrite::handleTimerWithSrefMonInSgeCreate(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeCreate --- ILINE
};

void DlgWznmRlsWrite::handleTimerWithSrefMonInSgeWrite(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswznm); // IP handleTimerWithSrefMonInSgeWrite --- ILINE
};

void DlgWznmRlsWrite::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::ALRAER: leaveSgeAlraer(dbswznm); break;
				case VecVSge::ALRMER: leaveSgeAlrmer(dbswznm); break;
				case VecVSge::UPKIDLE: leaveSgeUpkidle(dbswznm); break;
				case VecVSge::UNPACK: leaveSgeUnpack(dbswznm); break;
				case VecVSge::UPKDONE: leaveSgeUpkdone(dbswznm); break;
				case VecVSge::AUTH: leaveSgeAuth(dbswznm); break;
				case VecVSge::AUTDONE: leaveSgeAutdone(dbswznm); break;
				case VecVSge::CREIDLE: leaveSgeCreidle(dbswznm); break;
				case VecVSge::CREATE: leaveSgeCreate(dbswznm); break;
				case VecVSge::WRITE: leaveSgeWrite(dbswznm); break;
				case VecVSge::MRGGNR: leaveSgeMrggnr(dbswznm); break;
				case VecVSge::MRGSPEC: leaveSgeMrgspec(dbswznm); break;
				case VecVSge::MRGCTP: leaveSgeMrgctp(dbswznm); break;
				case VecVSge::MRGCUST: leaveSgeMrgcust(dbswznm); break;
				case VecVSge::PACK: leaveSgePack(dbswznm); break;
				case VecVSge::FAIL: leaveSgeFail(dbswznm); break;
				case VecVSge::DONE: leaveSgeDone(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::ALRAER: _ixVSge = enterSgeAlraer(dbswznm, reenter); break;
			case VecVSge::ALRMER: _ixVSge = enterSgeAlrmer(dbswznm, reenter); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbswznm, reenter); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbswznm, reenter); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbswznm, reenter); break;
			case VecVSge::AUTH: _ixVSge = enterSgeAuth(dbswznm, reenter); break;
			case VecVSge::AUTDONE: _ixVSge = enterSgeAutdone(dbswznm, reenter); break;
			case VecVSge::CREIDLE: _ixVSge = enterSgeCreidle(dbswznm, reenter); break;
			case VecVSge::CREATE: _ixVSge = enterSgeCreate(dbswznm, reenter); break;
			case VecVSge::WRITE: _ixVSge = enterSgeWrite(dbswznm, reenter); break;
			case VecVSge::MRGGNR: _ixVSge = enterSgeMrggnr(dbswznm, reenter); break;
			case VecVSge::MRGSPEC: _ixVSge = enterSgeMrgspec(dbswznm, reenter); break;
			case VecVSge::MRGCTP: _ixVSge = enterSgeMrgctp(dbswznm, reenter); break;
			case VecVSge::MRGCUST: _ixVSge = enterSgeMrgcust(dbswznm, reenter); break;
			case VecVSge::PACK: _ixVSge = enterSgePack(dbswznm, reenter); break;
			case VecVSge::FAIL: _ixVSge = enterSgeFail(dbswznm, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWznmRlsWrite::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::AUTH) || (ixVSge == VecVSge::AUTDONE) || (ixVSge == VecVSge::CREATE) || (ixVSge == VecVSge::WRITE) || (ixVSge == VecVSge::MRGGNR) || (ixVSge == VecVSge::MRGSPEC) || (ixVSge == VecVSge::MRGCTP) || (ixVSge == VecVSge::MRGCUST) || (ixVSge == VecVSge::PACK) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::UNPACK) retval = "unpacking custom code fragments";
			else if (ixVSge == VecVSge::UPKDONE) retval = "custom code fragments unpacked";
			else if (ixVSge == VecVSge::AUTH) retval = "authenticating";
			else if (ixVSge == VecVSge::AUTDONE) retval = "authentication successful";
			else if (ixVSge == VecVSge::CREATE) retval = "creating write operations (" + to_string(opN) + " operations prepared)";
			else if (ixVSge == VecVSge::WRITE) retval = "writing code (" + to_string(opNSuccess + opNFailure) + "/" + to_string(opN) + " operations completed)";
			else if (ixVSge == VecVSge::MRGGNR) retval = "merging generated code fragments";
			else if (ixVSge == VecVSge::MRGSPEC) retval = "merging job-type specific code fragments";
			else if (ixVSge == VecVSge::MRGCTP) retval = "merging capability template specific code fragments";
			else if (ixVSge == VecVSge::MRGCUST) retval = "merging custom code fragments";
			else if (ixVSge == VecVSge::PACK) retval = "packing code tree";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint DlgWznmRlsWrite::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWznmRlsWrite::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWznmRlsWrite::enterSgeAlraer(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRAER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlraer --- BEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Authentication failure.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);
	// IP enterSgeAlraer --- END
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsWrite::leaveSgeAlraer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlraer --- INSERT
};

uint DlgWznmRlsWrite::enterSgeAlrmer(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::ALRMER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	ContInfWznmAlert continf;
	// IP enterSgeAlrmer --- RBEGIN
	continf.TxtCpt = VecWznmVTag::getTitle(VecWznmVTag::ERROR, ixWznmVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		continf.TxtMsg1 = "Merge error (" + logaspect + "). View log file for details.";
	};

	feedFMcbAlert.clear();

	VecWznmVTag::appendToFeed(VecWznmVTag::OK, ixWznmVLocale, feedFMcbAlert);

	nextIxVSgeSuccess = VecVSge::FAIL;
	// IP enterSgeAlrmer --- REND
	xchg->submitDpch(new DpchEngWznmAlert(jref, &continf, &feedFMcbAlert, {DpchEngWznmAlert::ALL}));

	return retval;
};

void DlgWznmRlsWrite::leaveSgeAlrmer(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAlrmer --- INSERT
};

uint DlgWznmRlsWrite::enterSgeUpkidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSgeSuccess = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeUpkidle --- INSERT

	return retval;
};

void DlgWznmRlsWrite::leaveSgeUpkidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkidle --- INSERT
};

uint DlgWznmRlsWrite::enterSgeUnpack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::UPKDONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeUnpack --- IBEGIN

	// unpack archive
	Wznm::run("mv " + infilename + " " + infilename + ".tgz");
	Wznm::untgz(infilename + ".tgz", infilename);

	if (infilename.rfind("/") == string::npos) custfolder = infilename;
	else custfolder = infilename.substr(infilename.rfind("/")+1);

	// IP enterSgeUnpack --- IEND

	return retval;
};

void DlgWznmRlsWrite::leaveSgeUnpack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUnpack --- INSERT
};

uint DlgWznmRlsWrite::enterSgeUpkdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::UPKDONE;

	// IP enterSgeUpkdone --- INSERT

	return retval;
};

void DlgWznmRlsWrite::leaveSgeUpkdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeUpkdone --- INSERT
};

uint DlgWznmRlsWrite::enterSgeAuth(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::AUTDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRAER;

	// IP enterSgeAuth --- IBEGIN

	if (!license->authRlsWrite(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref))) retval = nextIxVSgeFailure;

	// IP enterSgeAuth --- IEND

	return retval;
};

void DlgWznmRlsWrite::leaveSgeAuth(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAuth --- INSERT
};

uint DlgWznmRlsWrite::enterSgeAutdone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::AUTDONE;

	// IP enterSgeAutdone --- INSERT

	return retval;
};

void DlgWznmRlsWrite::leaveSgeAutdone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeAutdone --- INSERT
};

uint DlgWznmRlsWrite::enterSgeCreidle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::CREIDLE;
	nextIxVSgeSuccess = VecVSge::CREATE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeCreidle --- INSERT

	return retval;
};

void DlgWznmRlsWrite::leaveSgeCreidle(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeCreidle --- INSERT
};

uint DlgWznmRlsWrite::enterSgeCreate(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::WRITE;
	retval = nextIxVSgeSuccess;

	clearInvs();

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeCreate --- IBEGIN

	if (ixCmptype == VecWznmVMComponentBasetype::ENG) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder (concerns IP's of cmbeng: Xxxxcmbd_exe.cpp -> Xxxxd_exe.cpp, Xxxxcmbd.h -> Xxxxd.h, Xxxxcmbd.cpp -> Xxxxd.cpp)
		createEng(dbswznm, contiacdet.ChkBso);

	} else if (ixCmptype == VecWznmVMComponentBasetype::OPENG) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder (concerns IP's of cmbeng: Xxxxcmbd_exe.cpp -> Xxxxopd_exe.cpp, Xxxxcmbd.h -> Xxxxopd.h, Xxxxcmbd.cpp -> Xxxxopd.cpp)
		createOpeng(dbswznm, contiacdet.ChkBso);

	} else if (ixCmptype == VecWznmVMComponentBasetype::CMBENG) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// job-type specific IP's -> specfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder
		createCmbeng(dbswznm, contiacdet.ChkBso);

	} else if (ixCmptype == VecWznmVMComponentBasetype::DBS) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder (concerns header ABOVE IP's only)
		createDbs(dbswznm, contiacdet.ChkBso);

	} else if (ixCmptype == VecWznmVMComponentBasetype::WEBAPP) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder
		createWebapp(dbswznm, contiacdet.ChkBso);

	} else if (ixCmptype == VecWznmVMComponentBasetype::API) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder (concerns header ABOVE IP's only)
		createApi(dbswznm, contiacdet.ChkBso);

	} else if (ixCmptype == VecWznmVMComponentBasetype::JAPI) {
		// create -> outfolder
		// IP's -> ipfolder -> outfolder
		// (optional) custom IP's -> custfolder -> outfolder (concerns header ABOVE IP's only)
		createJapi(dbswznm, contiacdet.ChkBso);
	};

	// IP enterSgeCreate --- IEND

	return retval;
};

void DlgWznmRlsWrite::leaveSgeCreate(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeCreate --- INSERT
};

uint DlgWznmRlsWrite::enterSgeWrite(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::WRITE;
	nextIxVSgeSuccess = VecVSge::MRGGNR;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeWrite --- INSERT

	submitInvs(dbswznm, VecVSge::IDLE, retval);
	return retval;
};

void DlgWznmRlsWrite::leaveSgeWrite(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeWrite --- INSERT
};

uint DlgWznmRlsWrite::enterSgeMrggnr(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MRGGNR;
	nextIxVSgeSuccess = VecVSge::MRGSPEC;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrggnr --- IBEGIN

	addInv(new DpchInvWznmPrctreeMerge(0, 0, "", ipfolder, "", outfolder, true, true));

	// IP enterSgeMrggnr --- IEND

	submitInvs(dbswznm, retval, retval);
	return retval;
};

void DlgWznmRlsWrite::leaveSgeMrggnr(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMrggnr --- INSERT
};

uint DlgWznmRlsWrite::enterSgeMrgspec(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MRGSPEC;
	nextIxVSgeSuccess = VecVSge::MRGCTP;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgspec --- IBEGIN

	if (ixCmptype == VecWznmVMComponentBasetype::ENG) {
	} else if (ixCmptype == VecWznmVMComponentBasetype::OPENG) {
	} else if (ixCmptype == VecWznmVMComponentBasetype::CMBENG) {
		// job-type specific IP's -> specfolder -> outfolder
		if (!contiacdet.ChkBso) addInv(new DpchInvWznmPrctreeMerge(0, 0, "", specfolder + "/" + cmpsref, "", outfolder + "/" + cmpsref, true, true));

	} else if (ixCmptype == VecWznmVMComponentBasetype::DBS) {
	} else if (ixCmptype == VecWznmVMComponentBasetype::WEBAPP) {
	} else if (ixCmptype == VecWznmVMComponentBasetype::API) {
	} else if (ixCmptype == VecWznmVMComponentBasetype::JAPI) {
	};

	// IP enterSgeMrgspec --- IEND

	submitInvs(dbswznm, VecVSge::MRGCTP, retval);
	return retval;
};

void DlgWznmRlsWrite::leaveSgeMrgspec(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMrgspec --- INSERT
};

uint DlgWznmRlsWrite::enterSgeMrgctp(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MRGCTP;
	nextIxVSgeSuccess = VecVSge::MRGCUST;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgctp --- INSERT

	submitInvs(dbswznm, VecVSge::MRGCUST, retval);
	return retval;
};

void DlgWznmRlsWrite::leaveSgeMrgctp(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMrgctp --- INSERT
};

uint DlgWznmRlsWrite::enterSgeMrgcust(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::MRGCUST;
	nextIxVSgeSuccess = VecVSge::PACK;
	nextIxVSgeFailure = VecVSge::ALRMER;

	clearInvs();

	// IP enterSgeMrgcust --- IBEGIN

	if (!contiacdet.ChkBso) {
		if (custfolder == "") {
			custfolder = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMEXTFOLDER, jref);
			if (custfolder != "") custfolder += "/" + cmpsref;
		};

		addInv(new DpchInvWznmPrctreeMerge(0, 0, "", custfolder, "", outfolder + "/" + cmpsref, false, false));
	};

	// IP enterSgeMrgcust --- IEND

	submitInvs(dbswznm, VecVSge::PACK, retval);
	return retval;
};

void DlgWznmRlsWrite::leaveSgeMrgcust(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeMrgcust --- INSERT
};

uint DlgWznmRlsWrite::enterSgePack(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;

	// IP enterSgePack --- IBEGIN

	if (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == 0) {
		// .tgz result folder
		Wznm::tgz(xchg->tmppath + "/" + outfolder, xchg->tmppath + "/" + outfolder + ".tgz");
	};

	// IP enterSgePack --- IEND

	return retval;
};

void DlgWznmRlsWrite::leaveSgePack(
			DbsWznm* dbswznm
		) {
	// IP leaveSgePack --- INSERT
};

uint DlgWznmRlsWrite::enterSgeFail(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::FAIL;

	// IP enterSgeFail --- INSERT

	return retval;
};

void DlgWznmRlsWrite::leaveSgeFail(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeFail --- INSERT
};

uint DlgWznmRlsWrite::enterSgeDone(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWznmRlsWrite::leaveSgeDone(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeDone --- INSERT
};
