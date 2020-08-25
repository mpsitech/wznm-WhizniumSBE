/**
	* \file WznmWrsrvCmbengbase.cpp
	* Wznm operation processor - write combined engine C++ code basics (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrvCmbengbase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvCmbengbase
 ******************************************************************************/

DpchRetWznm* WznmWrsrvCmbengbase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvCmbengbase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string orgname = dpchinv->orgname;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;

	WznmMVersion* ver = NULL;

	ListWznmMBlock stgblks;

	bool dbsmarmy, dbslite;

	bool hasdds, hasua;

	fstream hfile;
	fstream cppfile;

	string s;

	if (dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver)) {
		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
					+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", false, stgblks);

		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
					+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP)
					+ ") = 0 ORDER BY sref ASC", true, stgblks);

		dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) {
			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
						+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(refs[i]) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", true, stgblks);

			dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMOp, TblWznmMBlock WHERE TblWznmMOp.refWznmMOppack = " + to_string(refs[i]) + " AND TblWznmMBlock.refIxVTbl = "
						+ to_string(VecWznmVMBlockRefTbl::OPX) + " AND TblWznmMBlock.refUref = TblWznmMOp.ref AND TblWznmMBlock.ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
						+ " AND (TblWznmMBlock.wriIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 ORDER BY TblWznmMBlock.sref ASC", true, stgblks);
		};

 		dbsmarmy = ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO + VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) != 0);
		dbslite = ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) != 0);

		hasdds = (ver->ixWOption & VecWznmWMVersionOption::DDSPUB);
		hasua = (ver->ixWOption & VecWznmWMVersionOption::UASRV);

		// Xxxxcmbd_exe.h, Xxxxcmbd_exe.cpp
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "cmbd_exe.h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "cmbd_exe.cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeExeH(dbswznm, hfile, Prjshort, hasdds, hasua);
		writeExeCpp(dbswznm, cppfile, refWznmMVersion, Prjshort, stgblks, dbsmarmy, dbslite, hasdds, hasua);

		hfile.close();
		cppfile.close();

		// XxxxcmbdAppsrv.cpp
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "cmbdAppsrv.cpp.ip";
		cppfile.open(s.c_str(), ios::out);
		writeAppCpp(dbswznm, cppfile, refWznmMVersion, Prjshort);
		cppfile.close();

		// XxxxcmbdOpprc.h, XxxxcmbdOpprc.cpp
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "cmbdOpprc.h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "cmbdOpprc.cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeOprcH(dbswznm, hfile, refWznmMVersion);
		writeOprcCpp(dbswznm, cppfile, refWznmMVersion, Prjshort);

		hfile.close();
		cppfile.close();

		// Xxxxcmbd.h, Xxxxcmbd.cpp
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "cmbd.h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + Prjshort + "cmbd.cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeCmbdH(dbswznm, hfile, ver, Prjshort, stgblks, hasdds, hasua);
		writeCmbdCpp(dbswznm, cppfile, ver, orgname, Prjshort, stgblks, hasdds, hasua);

		hfile.close();
		cppfile.close();

		delete ver;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvCmbengbase::writeExeH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, const bool hasdds
			, const bool hasua
		) {
	// --- include.ddspub*
	if (hasdds) outfile << "// IP include.ddspub --- AFFIRM" << endl;
	else outfile << "// IP include.ddspub --- REMOVE" << endl;

	// --- include.uasrv*
	if (hasua) outfile << "// IP include.uasrv --- AFFIRM" << endl;
	else outfile << "// IP include.uasrv --- REMOVE" << endl;

	// --- ddspub*
	if (hasdds) outfile << "// IP ddspub --- AFFIRM" << endl;
	else outfile << "// IP ddspub --- REMOVE" << endl;

	// --- uasrv*
	if (hasua) outfile << "// IP uasrv --- AFFIRM" << endl;
	else outfile << "// IP uasrv --- REMOVE" << endl;
};

void WznmWrsrvCmbengbase::writeExeCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMBlock& stgblks
			, const bool dbsmy
			, const bool dbslite
			, const bool hasdds
			, const bool hasua
		) {
	WznmMBlock* stgblk = NULL;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	bool first;

	string prjshort = StrMod::lc(Prjshort);

	// --- init.my*
	if (dbsmy) outfile << "// IP init.my --- AFFIRM" << endl;
	else outfile << "// IP init.my --- REMOVE" << endl;

	// --- init.lite*
	if (dbslite) outfile << "// IP init.lite --- AFFIRM" << endl;
	else outfile << "// IP init.lite --- REMOVE" << endl;

	// --- init.shrdat.jobs
	outfile << "// IP init.shrdat.jobs --- IBEGIN" << endl;
	dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND Shrdat='1' ORDER BY sref ASC", false, jobs);
	
	if (jobs.nodes.size() > 0) outfile << endl;
	
	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];
		outfile << "\t" << job->sref << "::shrdat.init(xchg, &dbs" << prjshort << ");" << endl;
	};

	outfile << "// IP init.shrdat.jobs --- IEND" << endl;

	// --- init.shrdat.ops
	outfile << "// IP init.shrdat.ops --- IBEGIN" << endl;

	first = true;

	dbswznm->tblwznmmoppack->loadRstByVer(refWznmMVersion, false, opks);
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		if (opk->Shrdat) {
			if (first) outfile << endl;
			first = false;

			outfile << "\t" << opk->sref << "::shrdat.init(xchg, &dbs" << prjshort << ");" << endl;
		};

		dbswznm->tblwznmmop->loadRstBySQL("SELECT * FROM TblWznmMOp WHERE refWznmMOppack = " + to_string(opk->ref) + " AND Shrdat='1' ORDER BY sref ASC", false, ops);
		for (unsigned int j = 0; j < ops.nodes.size(); j++) {
			op = ops.nodes[j];

			if (first) outfile << endl;
			first = false;

			outfile << "\t" << op->sref << "::shrdat.init(xchg, &dbs" << prjshort << ");" << endl;
		};
	};

	outfile << "// IP init.shrdat.ops --- IEND" << endl;

	// --- init.ddspub*
	if (hasdds) outfile << "// IP init.ddspub --- AFFIRM" << endl;
	else outfile << "// IP init.ddspub --- REMOVE" << endl;

	// --- init.uasrv*
	if (hasua) outfile << "// IP init.uasrv --- AFFIRM" << endl;
	else outfile << "// IP init.uasrv --- REMOVE" << endl;

	// --- term.uasrv*
	if (hasua) outfile << "// IP term.uasrv --- AFFIRM" << endl;
	else outfile << "// IP term.uasrv --- REMOVE" << endl;

	// --- term.ddspub*
	if (hasdds) outfile << "// IP term.ddspub --- AFFIRM" << endl;
	else outfile << "// IP term.ddspub --- REMOVE" << endl;

	// --- term.shrdat.ops
	outfile << "// IP term.shrdat.ops --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		if (opk->Shrdat) outfile << "\t" << opk->sref << "::shrdat.term(xchg);" << endl;

		dbswznm->tblwznmmop->loadRstBySQL("SELECT * FROM TblWznmMOp WHERE refWznmMOppack = " + to_string(opk->ref) + " AND Shrdat='1' ORDER BY sref ASC", false, ops);
		for (unsigned int j = 0; j < ops.nodes.size(); j++) {
			op = ops.nodes[j];

			outfile << "\t" << op->sref << "::shrdat.term(xchg);" << endl;
		};
	};

	// re-use from above
	if (!first) outfile << endl;

	outfile << "// IP term.shrdat.ops --- IEND" << endl;

	// --- term.shrdat.jobs
	outfile << "// IP term.shrdat.jobs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];
		outfile << "\t" << job->sref << "::shrdat.term(xchg);" << endl;
	};

	if (jobs.nodes.size() > 0) outfile << endl;

	outfile << "// IP term.shrdat.jobs --- IEND" << endl;

	// --- loadPref
	outfile << "// IP loadPref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];

		if (stgblk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "\t\txchg->" << StrMod::lc(stgblk->sref) << ".readXML(docctx, basexpath, true);" << endl;
		else outfile << "\t\t" << stgblk->sref.substr(3) << "::stg.readXML(docctx, basexpath, true);" << endl;
	};
	outfile << "// IP loadPref --- IEND" << endl;

	// --- storePref
	outfile << "// IP storePref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];

		if (stgblk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "\t\txchg->" << StrMod::lc(stgblk->sref) << ".writeXML(wr);" << endl;
		else outfile << "\t\t" << stgblk->sref.substr(3) << "::stg.writeXML(wr);" << endl;
	};
	outfile << "// IP storePref --- IEND" << endl;

	// --- stgs
	outfile << "// IP stgs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];

		if (stgblk->refIxVTbl != VecWznmVMBlockRefTbl::VOID) outfile << stgblk->sref << " " << stgblk->sref.substr(3) << "::stg;" << endl;
	};
	outfile << "// IP stgs --- IEND" << endl;

	// --- shrdats
	outfile << "// IP shrdats --- IBEGIN" << endl;
	dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND Shrdat='1' ORDER BY sref ASC", false, jobs);
	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];
		outfile << "Shrdat" << job->sref << " " << job->sref << "::shrdat;" << endl;
	};

	dbswznm->tblwznmmoppack->loadRstByVer(refWznmMVersion, false, opks);
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		if (opk->Shrdat) outfile << "Shrdat" << opk->sref << " " << opk->sref << "::shrdat;" << endl;

		dbswznm->tblwznmmop->loadRstBySQL("SELECT * FROM TblWznmMOp WHERE refWznmMOppack = " + to_string(opk->ref) + " AND Shrdat='1' ORDER BY sref ASC", false, ops);
		for (unsigned int j = 0; j < ops.nodes.size(); j++) {
			op = ops.nodes[j];

			outfile << "Shrdat" << op->sref << " " << op->sref << "::shrdat;" << endl;
		};
	};
	outfile << "// IP shrdats --- IEND" << endl;
};

void WznmWrsrvCmbengbase::writeAppCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	WznmMJob* job = NULL;

	string subsref;

	// --- readDpchApp
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refWznmMVersion = "
				+ to_string(refWznmMVersion) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::CMBENG) + ") <> 0 AND (wriIxWznmWScope & "
				+ to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", false, blks);

	outfile << "// IP readDpchApp --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		outfile << "\t\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ") {" << endl;

		if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &job)) {
			if ((job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::PNL)) {
				// special rule for subsref
				// ex. DpchAppPlnrNavData -> CrdPlnrNav::DpchAppData
				subsref = "DpchApp" + blk->sref.substr(blk->sref.find(job->sref.substr(3)) + job->sref.length() - 3);
			} else {
				// regular rule for subsref
				// ex. DpchAppDlgPlnrNavLoainiData -> DlgPlnrNavLoaini::DpchAppData
				subsref = "DpchApp" + blk->sref.substr(blk->sref.find(job->sref) + job->sref.length());
			};

			outfile << "\t\t\treq->dpchapp = new " << job->sref << "::" << subsref << "();" << endl;
			outfile << "\t\t\t((" << job->sref << "::" << subsref << "*) (req->dpchapp))->readXML(docctx, \"/\", true);" << endl;

			delete job;

		} else {
			outfile << "\t\t\treq->dpchapp = new " << blk->sref << "();" << endl;
			outfile << "\t\t\t((" << blk->sref << "*) (req->dpchapp))->readXML(docctx, \"/\", true);" << endl;
		};
	};
	if (blks.nodes.size() > 0) outfile << "\t\t};" << endl;
	outfile << "// IP readDpchApp --- IEND" << endl;
};

void WznmWrsrvCmbengbase::writeOprcH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
		) {
	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	dbswznm->tblwznmmoppack->loadRstBySQL("SELECT * FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, opks);

	// --- include.ops
	outfile << "// IP include.ops --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);
		for (unsigned int j = 0; j < ops.nodes.size(); j++) {
			op = ops.nodes[j];
			outfile << "#include \"" << op->sref << ".h\"" << endl;
		};
	};
	outfile << "// IP include.ops --- IEND" << endl;
};

void WznmWrsrvCmbengbase::writeOprcCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	dbswznm->tblwznmmoppack->loadRstBySQL("SELECT * FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, opks);

	// --- run.perform
	outfile << "// IP run.perform --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);

		if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
			outfile << "\t\t\tif (req->dpchinv->ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::DPCHINV" << StrMod::uc(opk->sref) << ") {" << endl;

			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];

				outfile << "\t\t\t\t";
				if (j != 0) outfile << "else ";
				outfile << "if (((DpchInv" << opk->sref << "*) req->dpchinv)->srefKCustop == \"" << op->sref << "\") req->dpchret = " << op->sref << "::run(xchg, &dbs" << StrMod::lc(Prjshort) << ", (DpchInv" << opk->sref << "*) req->dpchinv);" << endl;
			};

			outfile << "\t\t\t};" << endl;

		} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];

				outfile << "\t\t\t";
				if (j != 0) outfile << "} else ";
				outfile << "if (req->dpchinv->ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::DPCHINV" << StrMod::uc(op->sref) << ") {" << endl;
				outfile << "\t\t\t\treq->dpchret = " << op->sref << "::run(xchg, &dbs" << StrMod::lc(Prjshort) << ", (DpchInv" << op->sref << "*) req->dpchinv);" << endl;
			};
			if (ops.nodes.size() > 0) outfile << "\t\t\t};" << endl;
		};
	};
	outfile << "// IP run.perform --- IEND" << endl;
};

void WznmWrsrvCmbengbase::writeCmbdH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMVersion* ver
			, const string& Prjshort
			, ListWznmMBlock& stgblks
			, const bool hasdds
			, const bool hasua
		) {
	WznmMBlock* stgblk = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;
	set<string> plhs;

	// --- include.mon
	outfile << "// IP include.mon --- IBEGIN" << endl;
	if (ver->ixWOption & VecWznmWMVersionOption::APIMON) outfile << "#include <sbecore/ApiMon.h>" << endl;
	else if (ver->ixWOption & VecWznmWMVersionOption::DBSMON) outfile << "#include <sbecore/DbsMon.h>" << endl;
	else outfile << "#include <sbecore/TxtMon.h>" << endl;
	outfile << "// IP include.mon --- IEND" << endl;

	// --- include.sqks
	dbswznm->tblwznmmoppack->loadRstBySQL("SELECT * FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(ver->ref) + " ORDER BY sref ASC", false, opks);

	outfile << "// IP include.sqks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		outfile << "#include \"Sqk" << opk->sref << ".h\"" << endl;
	};
	outfile << "// IP include.sqks --- IEND" << endl;

	// --- stgblks
	outfile << "// IP stgblks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];
		if (stgblk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) writeBlkstgH(dbswznm, Prjshort, outfile, NULL, stgblk, false, "");
	};
	outfile << "// IP stgblks --- IEND" << endl;

	// --- alrs
	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE ixVBasetype = " + to_string(VecWznmVMControlBasetype::ALR) + " AND hkIxVTbl = "
				+ to_string(VecWznmVMControlHkTbl::VER) + " AND hkUref = " + to_string(ver->ref) + " ORDER BY sref ASC", false, cons);

	outfile << "// IP alrs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		getAlrplhs(dbswznm, con->ref, plhs);

		outfile << "\tDpchEng" << Prjshort << "Alert* prepareAlr" << con->sref.substr(3+4) << "(const Sbecore::ubigint jref, const Sbecore::uint ix" << Prjshort << "VLocale";
		for (auto it = plhs.begin(); it != plhs.end(); it++) outfile << ", const std::string& " << *it;
		outfile << ", Sbecore::Xmlio::Feed& feedFMcbAlert);" << endl;
	};
	outfile << "// IP alrs --- IEND" << endl;

	// --- vars.stgblks
	outfile << "// IP vars.stgblks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];
		if (stgblk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "\t" << stgblk->sref << " " << StrMod::lc(stgblk->sref) << ";" << endl;
	};
	outfile << "// IP vars.stgblks --- IEND" << endl;

	// --- mon
	outfile << "// IP mon --- IBEGIN" << endl;
	if (ver->ixWOption & VecWznmWMVersionOption::APIMON) outfile << "\tSbecore::ApiMon mon;" << endl;
	else if (ver->ixWOption & VecWznmWMVersionOption::DBSMON) outfile << "\tSbecore::DbsMon mon;" << endl;
	else outfile << "\tSbecore::TxtMon mon;" << endl;
	outfile << "// IP mon --- IEND" << endl;

	// --- cDdspub*
	if (hasdds) outfile << "// IP cDdspub --- AFFIRM" << endl;
	else outfile << "// IP cDdspub --- REMOVE" << endl;

	// --- cUasrv*
	if (hasua) outfile << "// IP cUasrv --- AFFIRM" << endl;
	else outfile << "// IP cUasrv --- REMOVE" << endl;

	// --- ddspubcall*
	if (hasdds) outfile << "// IP ddspubcall --- AFFIRM" << endl;
	else outfile << "// IP ddspubcall --- REMOVE" << endl;

	// --- uasrvcall*
	if (hasua) outfile << "// IP uasrvcall --- AFFIRM" << endl;
	else outfile << "// IP uasrvcall --- REMOVE" << endl;

	// --- addClstnDdspub*
	if (hasdds) outfile << "// IP addClstnDdspub --- AFFIRM" << endl;
	else outfile << "// IP addClstnDdspub --- REMOVE" << endl;

	// --- addClstnUasrv*
	if (hasua) outfile << "// IP addClstnUasrv --- AFFIRM" << endl;
	else outfile << "// IP addClstnUasrv --- REMOVE" << endl;
};

void WznmWrsrvCmbengbase::writeCmbdCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMVersion* ver
			, const string& orgname
			, const string& Prjshort
			, ListWznmMBlock& stgblks
			, const bool hasdds
			, const bool hasua
		) {
	ubigint ref;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	WznmMBlock* stgblk = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;
	set<string> plhs;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	ListWznmRMCallMStub calRstbs;
	WznmRMCallMStub* calRstb = NULL;

	WznmMCall* cal = NULL;
	WznmMStub* stb = NULL;

	string prjshort = StrMod::lc(Prjshort);

	// --- stgblks
	outfile << "// IP stgblks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];
		if (stgblk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) writeBlkstgCpp(dbswznm, Prjshort, outfile, NULL, stgblk, false, "", "");
	};
	outfile << "// IP stgblks --- IEND" << endl;

	// --- alrs
	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE ixVBasetype = " + to_string(VecWznmVMControlBasetype::ALR) + " AND hkIxVTbl = "
				+ to_string(VecWznmVMControlHkTbl::VER) + " AND hkUref = " + to_string(ver->ref) + " ORDER BY sref ASC", false, cons);

	outfile << "// IP alrs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		getAlrplhs(dbswznm, con->ref, plhs);

		outfile << "DpchEng" << Prjshort << "Alert* Alr" << Prjshort << "::prepareAlr" << con->sref.substr(3+4) << "(" << endl;
		outfile << "\t\t\tconst ubigint jref" << endl;
		outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		for (auto it = plhs.begin(); it != plhs.end(); it++) outfile << "\t\t\t, const string& " << *it << endl;
		outfile << "\t\t\t, Feed& feedFMcbAlert" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tContInf" << Prjshort << "Alert continf;" << endl;
		outfile << "\t// IP prepareAlr" << con->sref.substr(3+4) << " --- BEGIN" << endl;
		wrAlrCpp(dbswznm, orgname, Prjshort, outfile, ver->ref, con, plhs);
		outfile << "\t// IP prepareAlr" << con->sref.substr(3+4) << " --- END" << endl;
		outfile << "\treturn(new DpchEng" << Prjshort << "Alert(jref, &continf, &feedFMcbAlert, {DpchEng" << Prjshort << "Alert::ALL}));" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP alrs --- IEND" << endl;

	// --- job.opsqks
	dbswznm->tblwznmmoppack->loadRstBySQL("SELECT * FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(ver->ref) + " ORDER BY sref ASC", false, opks);

	outfile << "// IP job.opsqks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
			outfile << "\tif (inv->ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::DPCHINV" << StrMod::uc(opk->sref) << ") {" << endl;
			outfile << "\t\tsquawk = Sqk" << opk->sref << "::getSquawk(dbs" << StrMod::lc(Prjshort) << ", (DpchInv" << opk->sref << "*) inv);" << endl;
			outfile << "\t};" << endl;

		} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
			dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);
			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];

				outfile << "\t";
				if (j != 0) outfile << "} else ";
				outfile << "if (inv->ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::DPCHINV" << StrMod::uc(op->sref) << ") {" << endl;
				outfile << "\t\tsquawk = Sqk" << opk->sref << "::getSquawk" << op->sref.substr(opk->sref.length()) << "(dbs" << StrMod::lc(Prjshort) << ", (DpchInv" << op->sref << "*) inv);" << endl;
			};
			if (ops.nodes.size() > 0) outfile << "\t};" << endl;
		};
	};
	outfile << "// IP job.opsqks --- IEND" << endl;

	// --- stmgr.stubs
	outfile << "// IP stmgr.stubs --- IBEGIN" << endl;

	dbswznm->tblwznmrmcallmstub->loadRstBySQL("SELECT TblWznmRMCallMStub.* FROM TblWznmRMCallMStub, TblWznmMCall WHERE TblWznmRMCallMStub.refWznmMCall = TblWznmMCall.ref AND TblWznmMCall.refWznmMVersion = "
				+ to_string(ver->ref) + " ORDER BY TblWznmMCall.sref ASC", false, calRstbs);

	ref = 0;
	for (unsigned int i = 0; i < calRstbs.nodes.size(); i++) {
		calRstb = calRstbs.nodes[i];

		if (calRstb->refWznmMCall != ref) {
			if (dbswznm->tblwznmmcall->loadRecByRef(calRstb->refWznmMCall, &cal)) {
				outfile << "\t";
				if (ref != 0) outfile << "} else ";

				outfile << "if (call->ixVCall == Vec" << Prjshort << "VCall::" << StrMod::uc(StrMod::dotToUsc(cal->sref)) << ") {" << endl;

				ref = calRstb->refWznmMCall;
				delete cal;
			};
		};

		if (dbswznm->tblwznmmstub->loadRecByRef(calRstb->refWznmMStub, &stb)) {
			outfile << "\t\tinsert(ics" << Prjshort << "VStub, Vec" << Prjshort << "VStub::" << StrMod::uc(stb->sref) << ");" << endl;
			delete stb;
		};
	};

	if (ref != 0) outfile << "\t};" << endl;
	outfile << "// IP stmgr.stubs --- IEND" << endl;

	// --- stmgr.clstns
	outfile << "// IP stmgr.clstns --- IBEGIN" << endl;

	dbswznm->tblwznmrmcallmstub->loadRstBySQL("SELECT TblWznmRMCallMStub.* FROM TblWznmRMCallMStub, TblWznmMCall, TblWznmMStub WHERE TblWznmRMCallMStub.refWznmMCall = TblWznmMCall.ref AND TblWznmMCall.refWznmMVersion = "
				+ to_string(ver->ref) + " AND TblWznmRMCallMStub.refWznmMStub = TblWznmMStub.ref ORDER BY TblWznmMStub.sref ASC", false, calRstbs);

	ref = 0;
	for (unsigned int i = 0; i < calRstbs.nodes.size(); i++) {
		calRstb = calRstbs.nodes[i];

		if (calRstb->refWznmMStub != ref) {
			if (dbswznm->tblwznmmstub->loadRecByRef(calRstb->refWznmMStub, &stb)) {
				outfile << "\t\t";
				if (ref != 0) outfile << "} else ";

				outfile << "if (*it == Vec" << Prjshort << "VStub::" << StrMod::uc(stb->sref) << ") {" << endl;

				ref = calRstb->refWznmMStub;
				delete stb;
			};
		};

		if (dbswznm->tblwznmmcall->loadRecByRef(calRstb->refWznmMCall, &cal)) {
			outfile << "\t\t\txchg->addClstnStmgr(Vec" << Prjshort << "VCall::" << StrMod::uc(StrMod::dotToUsc(cal->sref)) << ", jref);" << endl;
			delete cal;
		};
	};

	if (ref != 0) outfile << "\t\t};" << endl;
	outfile << "// IP stmgr.clstns --- IEND" << endl;

	// --- constructor.cDdspub*
	if (hasdds) outfile << "// IP constructor.cDdspub --- AFFIRM" << endl;
	else outfile << "// IP constructor.cDdspub --- REMOVE" << endl;

	// --- constructor.cUasrv*
	if (hasua) outfile << "// IP constructor.cUasrv --- AFFIRM" << endl;
	else outfile << "// IP constructor.cUasrv --- REMOVE" << endl;

	// --- constructor.mDdspubcall*
	if (hasdds) outfile << "// IP constructor.mDdspubcall --- AFFIRM" << endl;
	else outfile << "// IP constructor.mDdspubcall --- REMOVE" << endl;

	// --- constructor.mUasrvcall*
	if (hasua) outfile << "// IP constructor.mUasrvcall --- AFFIRM" << endl;
	else outfile << "// IP constructor.mUasrvcall --- REMOVE" << endl;

	// --- constructor.csjis
	outfile << "// IP constructor.csjis --- IBEGIN" << endl;
	dbswznm->tblwznmmjob->loadRstByVer(ver->ref, false, jobs);

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];
		if (job->Clisrv) outfile << "\tcsjobinfos[Vec" << Prjshort << "VJob::" << StrMod::uc(job->sref) << "] = new Csjobinfo(Vec" << Prjshort << "VJob::" << StrMod::uc(job->sref) << ");" << endl;
	};
	outfile << "// IP constructor.csjis --- IEND" << endl;

	// --- constructor.ddspubcall*
	if (hasdds) outfile << "// IP constructor.ddspubcall --- AFFIRM" << endl;
	else outfile << "// IP constructor.ddspubcall --- REMOVE" << endl;

	// --- constructor.uasrvcall*
	if (hasua) outfile << "// IP constructor.uasrvcall --- AFFIRM" << endl;
	else outfile << "// IP constructor.uasrvcall --- REMOVE" << endl;

	// --- startMon
	outfile << "// IP startMon --- IBEGIN" << endl;

	if (ver->ixWOption & VecWznmWMVersionOption::APIMON) {
		outfile << "\tmon.start(\"" << StubWznm::getStubVerStd(dbswznm, ver->ref) << "\", stg" << prjshort << "monitor.ip, stg" << prjshort << "monitor.port, stg" << prjshort << "monitor.username, stg" << prjshort << "monitor.password);" << endl;
	} else if (ver->ixWOption & VecWznmWMVersionOption::DBSMON) {
		outfile << "\tmon.start(\"" << StubWznm::getStubVerStd(dbswznm, ver->ref) << "\", stg" << prjshort << "monitor.ixDbsVDbstype, stg" << prjshort << "monitor.dbspath, stg" << prjshort << "monitor.dbsname, stg" << prjshort << "monitor.ip, stg" << prjshort << "monitor.port, stg" << prjshort << "monitor.dbsusername, stg" << prjshort << "monitor.dbspassword, stg" << prjshort << "monitor.username, stg" << prjshort << "monitor.password);" << endl;
	} else {
		outfile << "\tmon.start(\"" << StubWznm::getStubVerStd(dbswznm, ver->ref) << "\", stg" << prjshort << "path.monpath);" << endl;
	};

	outfile << "// IP startMon --- IEND" << endl;

	// --- addClstnDdspub*
	if (hasdds) outfile << "// IP addClstnDdspub --- AFFIRM" << endl;
	else outfile << "// IP addClstnDdspub --- REMOVE" << endl;

	// --- addClstnUasrv*
	if (hasua) outfile << "// IP addClstnUasrv --- AFFIRM" << endl;
	else outfile << "// IP addClstnUasrv --- REMOVE" << endl;

	// --- triggerCall.ddspub*
	if (hasdds) outfile << "// IP triggerCall.ddspub --- AFFIRM" << endl;
	else outfile << "// IP triggerCall.ddspub --- REMOVE" << endl;

	// --- triggerCall.uasrv*
	if (hasua) outfile << "// IP triggerCall.uasrv --- AFFIRM" << endl;
	else outfile << "// IP triggerCall.uasrv --- REMOVE" << endl;
};
// IP cust --- IEND


