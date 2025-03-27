/**
	* \file WznmCtpWrsrvPrefs.cpp
	* Wznm operation processor - implement preferences panels (implementation)
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

#include "WznmCtpWrsrvPrefs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpWrsrvPrefs
 ******************************************************************************/

DpchRetWznm* WznmCtpWrsrvPrefs::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpWrsrv* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	const string Crdshort = "Prf";
	
	set<ubigint> unqrefs;

	WznmMCapability* cpb = NULL;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	ListWznmMOppack opks;
	WznmMOppack* opk = NULL;

	ListWznmMBlock blks, blks2, allblks;
	WznmMBlock* blk = NULL;

	vector<string> stdsrefs;

	vector<string> blkreusrefs;
	vector<string> pnljobshorts, pnljobblksrefsds, pnljobblksrefscmbds;

	string blkvarsd, blkvarscmbd;

	string s;

	if (dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb)) {
		// - PnlXxxxPrfDaemon.h/.cpp for daemon settings (standard blocks cf. WznmComplDeploy)
		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
					+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", false, blks);

		stdsrefs = {"Behavior", "Appsrv", "d", "cmbd", "Database", "Path", "Tenant", "Monitor", "Ddspub", "Uasrv"};

		for (unsigned int i = 0; i < stdsrefs.size(); i++) {
			s = "Stg" + Prjshort + stdsrefs[i];

			for (unsigned int j = 0; j < blks.nodes.size(); j++) {
				blk = blks.nodes[j];

				if (blk->sref == s) {
					blks2.nodes.push_back(blk);
					unqrefs.insert(blk->ref);

					break;
				};
			};
		};

		getBlkvars(blks2, blkvarsd, blkvarscmbd);

		s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + "Daemon.h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + "Daemon.cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writePnlH(hfile, Prjshort, "", blks2, blkvarsd, blkvarscmbd);
		writePnlCpp(dbswznm, cppfile, Prjshort, "Pnl" + Prjshort + Crdshort + "Daemon", true, blks2, blkvarsd, blkvarscmbd);

		hfile.close();
		cppfile.close();

		for (unsigned int i = 0; i < blks2.nodes.size(); i++) {
			allblks.nodes.push_back(new WznmMBlock(*(blks2.nodes[i])));
			blkreusrefs.push_back("");
		};
		addPnljobstrs("pnldaemon", blks2, pnljobshorts, pnljobblksrefsds, pnljobblksrefscmbds);

		blks2.nodes.clear();

		if (unqrefs.size() != blks.nodes.size()) {
			// - PnlXxxxPrfGlobal.h/.cpp for global settings
			blks2.clear();

			for (unsigned int j = 0; j < blks.nodes.size(); j++) {
				blk = blks.nodes[j];

				if (unqrefs.find(blk->ref) == unqrefs.end()) {
					blks2.nodes.push_back(blk);
					break;
				};
			};

			getBlkvars(blks2, blkvarsd, blkvarscmbd);

			s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + "Global.h.ip";
			hfile.open(s.c_str(), ios::out);
			s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + "Global.cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writePnlH(hfile, Prjshort, "", blks2, blkvarsd, blkvarscmbd);
			writePnlCpp(dbswznm, cppfile, Prjshort, "Pnl" + Prjshort + Crdshort + "Global", true, blks2, blkvarsd, blkvarscmbd);

			hfile.close();
			cppfile.close();

			for (unsigned int i = 0; i < blks2.nodes.size(); i++) {
				allblks.nodes.push_back(new WznmMBlock(*(blks2.nodes[i])));
				blkreusrefs.push_back("");
			};
			addPnljobstrs("pnlglobal", blks2, pnljobshorts, pnljobblksrefsds, pnljobblksrefscmbds);

			blks2.nodes.clear();
		};

		// - PnlXxxxPrfYyyyy.h/.cpp for job-specific settings
		dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ref IN (SELECT DISTINCT refUref FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion)
					+ " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG)
					+ ") <> 0 AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") = 0) ORDER BY sref ASC", false, jobs);

		for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
			job = jobs.nodes[i];

			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
						+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 AND (reaIxWznmWScope & "
						+ to_string(VecWznmWScope::APP) + ") = 0 ORDER BY sref ASC", false, blks);

			getBlkvars(blks, blkvarsd, blkvarscmbd);

			s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + job->sref.substr(3+4) + ".h.ip";
			hfile.open(s.c_str(), ios::out);
			s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + job->sref.substr(3+4) + ".cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writePnlH(hfile, Prjshort, job->sref, blks, blkvarsd, blkvarscmbd);
			writePnlCpp(dbswznm, cppfile, Prjshort, "Pnl" + Prjshort + Crdshort + job->sref.substr(3+4), (blks.nodes.size() > 1), blks, blkvarsd, blkvarscmbd);

			for (unsigned int j = 0; j < blks.nodes.size(); j++) {
				allblks.nodes.push_back(new WznmMBlock(*(blks.nodes[j])));
				blkreusrefs.push_back(job->sref);
			};
			addPnljobstrs("pnl" + StrMod::lc(job->sref.substr(3+4)), blks, pnljobshorts, pnljobblksrefsds, pnljobblksrefscmbds);

			hfile.close();
			cppfile.close();
		};

		// - PnlXxxxPrfYyyyy.h/.cpp for operation (pack)-specific settings
		dbswznm->tblwznmmoppack->loadRstByVer(cpb->refWznmMVersion, false, opks);

		for (unsigned int i = 0; i < opks.nodes.size(); i++) {
			opk = opks.nodes[i];

			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
						+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(opk->ref) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 ORDER BY sref ASC", false, blks);

			dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMOp, TblWznmMBlock WHERE TblWznmMOp.refWznmMOppack = " + to_string(opk->ref) + " AND TblWznmMBlock.refIxVTbl = "
						+ to_string(VecWznmVMBlockRefTbl::OPX) + " AND TblWznmMBlock.refUref = TblWznmMOp.ref AND TblWznmMBlock.ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
						+ " AND (TblWznmMBlock.wriIxWznmWScope & " + to_string(VecWznmWScope::ENG + VecWznmWScope::CMBENG) + ") <> 0 ORDER BY TblWznmMBlock.sref ASC", true, blks);

			if (blks.nodes.size() > 0) {
				getBlkvars(blks, blkvarsd, blkvarscmbd);

				s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + opk->sref.substr(4) + ".h.ip";
				hfile.open(s.c_str(), ios::out);
				s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Pnl" + Prjshort + Crdshort + opk->sref.substr(4) + ".cpp.ip";
				cppfile.open(s.c_str(), ios::out);

				writePnlH(hfile, Prjshort, opk->sref, blks, blkvarsd, blkvarscmbd);
				writePnlCpp(dbswznm, cppfile, Prjshort, "Pnl" + Prjshort + Crdshort + opk->sref.substr(4), (blks.nodes.size() > 1), blks, blkvarsd, blkvarscmbd);

				for (unsigned int j = 0; j < blks.nodes.size(); j++) {
					allblks.nodes.push_back(new WznmMBlock(*(blks.nodes[j])));
					if (blk->refIxVTbl == VecWznmVMBlockRefTbl::OPK) blkreusrefs.push_back(opk->sref);
					else {
						if (dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMOp WHERE ref = " + to_string(blk->refUref), s)) blkreusrefs.push_back(s);
						else blkreusrefs.push_back("");
					};
				};
				addPnljobstrs("pnl" + StrMod::lc(opk->sref.substr(3)), blks, pnljobshorts, pnljobblksrefsds, pnljobblksrefscmbds);

				hfile.close();
				cppfile.close();
			};
		};

		// - CrdXxxxPrf.h, CrdXxxxPrf.cpp
		s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Crd" + Prjshort + Crdshort + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/Crd" + Prjshort + Crdshort + "/Crd" + Prjshort + Crdshort + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeCrdH(hfile, Prjshort);
		writeCrdCpp(cppfile, Prjshort, Crdshort, allblks, blkreusrefs, pnljobshorts, pnljobblksrefsds, pnljobblksrefscmbds);

		hfile.close();
		cppfile.close();

		delete cpb;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmCtpWrsrvPrefs::writeCrdH(
			fstream& outfile
			, const string& Prjshort
		) {
	string prjshort = StrMod::uncap(Prjshort);

	// --- cust
	outfile << "// IP cust --- IBEGIN" << endl;
	outfile << "\t// IP cust --- BEGIN" << endl;

	outfile << "\tvoid setPref(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << "\tvoid storePref();" << endl;

	outfile << "\t// IP cust --- END" << endl;
	outfile << "// IP cust --- IEND" << endl;
};

void WznmCtpWrsrvPrefs::writeCrdCpp(
			fstream& outfile
			, const string& Prjshort
			, const string& Crdshort
			, ListWznmMBlock& blks // blks.nodes.size()
			, const vector<string>& blkreusrefs // blks.nodes.size()
			, const vector<string>& pnljobshorts // pnljobshorts.size()
			, const vector<string>& pnljobblksrefsds // pnljobshorts.size()
			, const vector<string>& pnljobblksrefscmbds // pnljobshorts.size()
		) {
	WznmMBlock* blk = NULL;

	string prjshort = StrMod::uncap(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	// --- cust
	outfile << "// IP cust --- IBEGIN" << endl;
	outfile << "// IP cust --- BEGIN" << endl;

	outfile << "void Crd" << Prjshort << Crdshort << "::setPref(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	for (unsigned int i = 0; i < pnljobshorts.size(); i++) outfile << "\t" << pnljobshorts[i] << "->setPref(dbs" << prjshort << ", true);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	outfile << "void Crd" << Prjshort << Crdshort << "::storePref() {" << endl;
	outfile << "\txmlTextWriter* wr = NULL;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		if (blkreusrefs[i] == "") outfile << "\t" << blk->sref << "* " << StrMod::lc(blk->sref) << " = &(xchg->" << StrMod::lc(blk->sref) << ");" << endl;
		else outfile << "\t" << blkreusrefs[i] << "::Stg* " << StrMod::lc(blk->sref) << " = &(" << blkreusrefs[i] << "::stg);" << endl; // for now, only one stg block per job/opk/opx

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) != (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) outfile << "#endif" << endl;
	};

	outfile << endl;

	outfile << "\ttime_t now;" << endl;
	outfile << endl;

	outfile << "\tint res;" << endl;
	outfile << endl;

	outfile << "\tstring s;" << endl;
	outfile << endl;

	outfile << "#if defined(" << PRJSHORT << "D)" << endl;
	outfile << "\tconst string fileroot = \"Pref" << Prjshort << "d\";" << endl;
	outfile << "#elif defined(" << PRJSHORT << "CMBD)" << endl;
	outfile << "\tconst string fileroot = \"Pref" << Prjshort << "cmbd\";" << endl;
	outfile << "#endif" << endl;
	outfile << endl;

	outfile << "\t// create backup of current preferences file" << endl;
	outfile << "\ttime(&now);" << endl;
	outfile << "\ts = \"cp -p \" + xchg->exedir + \"/\" + fileroot + \".xml \" + xchg->exedir + \"/\" + fileroot + \"_\" + to_string(now) + \".xml\";" << endl;
	outfile << "\tres = system(s.c_str());" << endl;
	outfile << "\tif (res != 0) throw SbeException(SbeException::PATHNF, {{\"path\",xchg->exedir + \"/\" + fileroot + \".xml\"}});" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < pnljobshorts.size(); i++) {
		for (unsigned int j = 0; j < 2; j++) {
			if ((j == 1) && (pnljobblksrefsds[i] == pnljobblksrefscmbds[i])) break;

			if ((j == 0) && (pnljobblksrefsds[i] != pnljobblksrefscmbds[i])) outfile << "#ifdef " << PRJSHORT << "D" << endl;
			else if (j == 1) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

			outfile << "\t" << pnljobshorts[i] << "->getPref(";
			if (j == 0) outfile << pnljobblksrefsds[i];
			else outfile << pnljobblksrefscmbds[i];
			outfile << ");" << endl;

			if (pnljobblksrefsds[i] != pnljobblksrefscmbds[i]) outfile << "#endif" << endl;
		};
	};
	outfile << endl;

	outfile << "\tstartwriteFile(xchg->exedir + \"/\" + fileroot + \".xml\", &wr);" << endl;
	outfile << "\txmlTextWriterSetIndent(wr, 1);" << endl;
	outfile << "\txmlTextWriterSetIndentString(wr, BAD_CAST \"\t\");" << endl;
	outfile << "\txmlTextWriterStartElement(wr, BAD_CAST fileroot.c_str());" << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		outfile << "\t\t" << StrMod::lc(blk->sref) << "->writeXML(wr);" << endl;

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) != (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) outfile << "#endif" << endl;
	};

	outfile << "\txmlTextWriterEndElement(wr);" << endl;
	outfile << "\tclosewriteFile(wr);" << endl;
	outfile << "};" << endl;

	outfile << "// IP cust --- END" << endl;
	outfile << "// IP cust --- IEND" << endl;

	// --- handleDpchAppDoMitCrdRvrClick
	outfile << "// IP handleDpchAppDoMitCrdRvrClick --- IBEGIN" << endl;
	outfile << "\tsetPref(dbs" << prjshort << "); // IP handleDpchAppDoMitCrdRvrClick --- LINE" << endl;
	outfile << "// IP handleDpchAppDoMitCrdRvrClick --- IEND" << endl;

	// --- handleDpchAppDoMitCrdStoClick
	outfile << "// IP handleDpchAppDoMitCrdStoClick --- IBEGIN" << endl;
	outfile << "\tstorePref(); // IP handleDpchAppDoMitCrdStoClick --- LINE" << endl;
	outfile << "// IP handleDpchAppDoMitCrdStoClick --- IEND" << endl;
};

void WznmCtpWrsrvPrefs::writePnlH(
			fstream& outfile
			, const string& Prjshort
			, const string& Reusref
			, ListWznmMBlock& blks
			, const string& blkvarsd
			, const string& blkvarscmbd
		) {
	WznmMBlock* blk = NULL;

	string prjshort = StrMod::uncap(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	// --- include.cust
	if (Reusref != "") {
		outfile << "// IP include.cust --- IBEGIN" << endl;
		outfile << "#include \"" << Reusref << ".h\" // IP include.cust --- LINE" << endl;
		outfile << "// IP include.cust --- IEND" << endl;
	};

	// --- vars.cust
	outfile << "// IP vars.cust --- IBEGIN" << endl;
	outfile << "\t// IP vars.cust --- BEGIN" << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		outfile << "\t";
		if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << blk->sref;
		else outfile << blk->sref.substr(3) << "::Stg";
		outfile << " " << StrMod::lc(blk->sref) << ";" << endl;

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) != (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) outfile << "#endif" << endl;
	};

	outfile << "\t// IP vars.cust --- END" << endl;
	outfile << "// IP vars.cust --- IEND" << endl;

	// --- cust
	outfile << "// IP cust --- IBEGIN" << endl;
	outfile << "\t// IP cust --- BEGIN" << endl;

	for (unsigned int j = 0; j < 2; j++) {
		if ((j == 1) && (blkvarsd == blkvarscmbd)) break;

		if ((j == 0) && (blkvarsd != blkvarscmbd)) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if (j == 1) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		outfile << "\tvoid getPref(";
		if (j == 0) outfile << blkvarsd;
		else outfile << blkvarscmbd;
		outfile << ");" << endl;

		if (blkvarsd != blkvarscmbd) outfile << "#endif" << endl;
	};

	outfile << "\tvoid setPref(Dbs" << Prjshort << "* dbs" << prjshort << ", const bool _refresh = false);" << endl;

	outfile << "\t// IP cust --- END" << endl;
	outfile << "// IP cust --- IEND" << endl;
};

void WznmCtpWrsrvPrefs::writePnlCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, const string& Pnlsref
			, const bool hashdg
			, ListWznmMBlock& blks
			, const string& blkvarsd
			, const string& blkvarscmbd
		) {
	WznmMBlock* blk = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	unsigned int pnlsectNum;

	vector<string> ss;

	bool first;

	string prjshort = StrMod::uncap(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	// --- constructor.cust2
	outfile << "// IP constructor.cust2 --- IBEGIN" << endl;
	outfile << "\tsetPref(dbs" << prjshort << "); // IP constructor.cust2 --- LINE" << endl;
	outfile << "// IP constructor.cust2 --- IEND" << endl;

	// --- cust
	outfile << "// IP cust --- IBEGIN" << endl;
	outfile << "// IP cust --- BEGIN" << endl;

	// -- getPref()
	outfile << "void " << Pnlsref << "::getPref(" << endl;

	for (unsigned int j = 0; j < 2; j++) {
		if ((j == 1) && (blkvarsd == blkvarscmbd)) break;

		if ((j == 0) && (blkvarsd != blkvarscmbd)) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if (j == 1) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		if (j == 0) StrMod::stringToVector(blkvarsd, ss, ',', false);
		else StrMod::stringToVector(blkvarscmbd, ss, ',', false);

		for (unsigned int k = 0; k < ss.size(); k++) {
			outfile << "\t\t\t";
			if (k != 0) outfile << ", ";
			outfile << ss[k] << endl;
		};

		if (blkvarsd != blkvarscmbd) outfile << "#endif" << endl;
	};

	outfile << "\t\t) {" << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		//
		outfile << "\tif (!(";

		pnlsectNum = 100*i + 1;
		if (i != 0) pnlsectNum = pnlsectNum; // no increment for SEP
		if (hashdg) pnlsectNum++; // increment for HDG
		first = true;

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				switch (bit->ixWznmVVartype) {
					case VecWznmVVartype::BOOLEAN:
						if (first) first = false;
						else outfile << " && ";
						outfile << "statshr.Chk" << pnlsectNum++ << "Clean";
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
					case VecWznmVVartype::STRING:
						if (first) first = false;
						else outfile << " && ";
						outfile << "statshr.Txf" << pnlsectNum++ << "Clean";
						break;

					case VecWznmVVartype::VECSREF:
						if (first) first = false;
						else outfile << " && ";
						outfile << "statshr.Pup" << pnlsectNum++ << "Clean";
						break;
				};
			};
		};

		outfile << ")) {" << endl;
		// ^

		outfile << "\t\t_" << StrMod::lc(blk->sref) << " = &" << StrMod::lc(blk->sref) << ";" << endl;

		//
		pnlsectNum = 100*i + 1;
		if (i != 0) pnlsectNum = pnlsectNum; // no increment for SEP
		if (hashdg) pnlsectNum++; // increment for HDG

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				switch (bit->ixWznmVVartype) {
					case VecWznmVVartype::BOOLEAN:
						outfile << "\t\t" << StrMod::lc(blk->sref) << "." << bit->sref << " = contiac.Chk" << pnlsectNum++ << ";" << endl;
						break;

					case VecWznmVVartype::TINYINT:
					case VecWznmVVartype::UTINYINT:
					case VecWznmVVartype::SMALLINT:
					case VecWznmVVartype::USMALLINT:
						outfile << "\t\t" << StrMod::lc(blk->sref) << "." << bit->sref << " = atoi(contiac.Txf" << pnlsectNum++ << ".c_str());" << endl;
						break;

					case VecWznmVVartype::INT:
					case VecWznmVVartype::UINT:
					case VecWznmVVartype::BIGINT:
					case VecWznmVVartype::UBIGINT:
						outfile << "\t\t" << StrMod::lc(blk->sref) << "." << bit->sref << " = atol(contiac.Txf" << pnlsectNum++ << ".c_str());" << endl;
						break;

					case VecWznmVVartype::FLOAT:
					case VecWznmVVartype::DOUBLE:
						outfile << "\t\t" << StrMod::lc(blk->sref) << "." << bit->sref << " = atof(contiac.Txf" << pnlsectNum++ << ".c_str());" << endl;
						break;

					case VecWznmVVartype::STRING:
						outfile << "\t\t" << StrMod::lc(blk->sref) << "." << bit->sref << " = contiac.Txf" << pnlsectNum++ << ";" << endl;
						break;

					case VecWznmVVartype::VECSREF:
						outfile << "\t\t" << StrMod::lc(blk->sref) << "." << bit->sref << " = feedFPup" << pnlsectNum << ".getIxByNum(contiac.numFPup" << pnlsectNum << ");" << endl; pnlsectNum++;
						break;
				};
			};
		};
		// ^

		outfile << "\t};" << endl;

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) != (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) outfile << "#endif" << endl;

		outfile << endl;
	};

	outfile << "};" << endl;
	outfile << endl;

	// setPref()
	outfile << "void " << Pnlsref << "::setPref(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const bool _refresh" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tset<uint> moditems;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		//
		pnlsectNum = 100*i + 1;
		if (i != 0) pnlsectNum = pnlsectNum; // no increment for SEP
		if (hashdg) pnlsectNum++; // increment for HDG

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				switch (bit->ixWznmVVartype) {
					case VecWznmVVartype::BOOLEAN:
						outfile << "\tcontiac.Chk" << pnlsectNum++ << " = ";
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << ";" << endl;
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
						outfile << "\tcontiac.Txf" << pnlsectNum++ << " = to_string(";
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << ");" << endl;
						break;

					case VecWznmVVartype::STRING:
						outfile << "\tcontiac.Txf" << pnlsectNum++ << " = ";
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << ";" << endl;
						break;

					case VecWznmVVartype::VECSREF:
						outfile << "\tcontiac.numFPup" << pnlsectNum << " = feedFPup" << pnlsectNum << ".getNumByIx("; pnlsectNum++;
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << ");" << endl;
						break;
				};
			};
		};
		// ^

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) != (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) outfile << "#endif" << endl;

		outfile << endl;
	};

	outfile << "\tif (_refresh) {" << endl;
	outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
	outfile << "\t\tinsert(moditems, DpchEngData::CONTIAC);" << endl;
	outfile << "\t\txchg->submitDpch(getNewDpchEng(moditems));" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << "// IP cust --- END" << endl;
	outfile << "// IP cust --- IEND" << endl;

	// --- refresh
	outfile << "// IP refresh --- RBEGIN" << endl;
	outfile << "\t// IP refresh --- BEGIN" << endl;

	outfile << "\t// statshr" << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) != (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) {
			//
			pnlsectNum = 100*i + 1;
			if (i != 0) pnlsectNum = pnlsectNum; // no increment for SEP

			outfile << "\tstatshr.Sep" << i << "Avail = evalSep" << i << "Avail(dbs" << prjshort << ");" << endl;

			if (blks.nodes.size() > 1) {
				outfile << "\tstatshr.Hdg" << pnlsectNum << "Avail = evalHdg" << pnlsectNum << "Avail(dbs" << prjshort << ");" << endl;
				pnlsectNum++;
			};

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					switch (bit->ixWznmVVartype) {
						case VecWznmVVartype::BOOLEAN:
							outfile << "\tstatshr.Chk" << pnlsectNum << "Avail = evalChk" << pnlsectNum << "Avail(dbs" << prjshort << ");" << endl; pnlsectNum++;
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
						case VecWznmVVartype::STRING:
							outfile << "\tstatshr.Txf" << pnlsectNum << "Avail = evalTxf" << pnlsectNum << "Avail(dbs" << prjshort << ");" << endl; pnlsectNum++;
							break;

						case VecWznmVVartype::VECSREF:
							outfile << "\tstatshr.Pup" << pnlsectNum << "Avail = evalPup" << pnlsectNum << "Avail(dbs" << prjshort << ");" << endl; pnlsectNum++;
							break;
					};
				};
			};
			// ^

			outfile << endl;
		};

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::ENG) outfile << "#ifdef " << PRJSHORT << "D" << endl;
		else if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) == VecWznmWScope::CMBENG) outfile << "#ifdef " << PRJSHORT << "CMBD" << endl;

		//
		pnlsectNum = 100*i + 1;
		if (i != 0) pnlsectNum = pnlsectNum; // no increment for SEP
		if (hashdg) pnlsectNum++; // increment for HDG

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				switch (bit->ixWznmVVartype) {
					case VecWznmVVartype::BOOLEAN:
						outfile << "\tstatshr.Chk" << pnlsectNum << "Clean = (contiac.Chk" << pnlsectNum << " == "; pnlsectNum++;
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << ");" << endl;
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
						outfile << "\tstatshr.Txf" << pnlsectNum << "Clean = (contiac.Txf" << pnlsectNum << " == to_string("; pnlsectNum++;
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << "));" << endl;
						break;

					case VecWznmVVartype::STRING:
						outfile << "\tstatshr.Txf" << pnlsectNum << "Clean = (contiac.Txf" << pnlsectNum << " == "; pnlsectNum++;
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << ");" << endl;
						break;

					case VecWznmVVartype::VECSREF:
						outfile << "\tstatshr.Pup" << pnlsectNum << "Clean = (contiac.numFPup" << pnlsectNum << " == feedFPup" << pnlsectNum << ".getNumByIx("; pnlsectNum++;
						if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "xchg->" << StrMod::lc(blk->sref) << "." << bit->sref;
						else outfile << blk->sref.substr(3) << "::stg." << bit->sref;
						outfile << "));" << endl;
						break;
				};
			};
		};
		// ^

		if ((blk->wriIxWznmWScope & (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) != (VecWznmWScope::ENG + VecWznmWScope::CMBENG)) outfile << "#endif" << endl;

		outfile << endl;
	};

	outfile << "\t// IP refresh --- END" << endl;
	outfile << "// IP refresh --- REND" << endl;

	// --- handleDpchAppDataContiac
	outfile << "// IP handleDpchAppDataContiac --- IBEGIN" << endl;
	outfile << "\t// IP handleDpchAppDataContiac --- BEGIN" << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		//
		pnlsectNum = 100*i + 1;
		if (i != 0) pnlsectNum = pnlsectNum; // no increment for SEP
		if (hashdg) pnlsectNum++; // increment for HDG

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				switch (bit->ixWznmVVartype) {
					case VecWznmVVartype::BOOLEAN:
						outfile << "\tif (has(diffitems, ContIac::CHK" << pnlsectNum << ")) contiac.Chk" << pnlsectNum << " = _contiac->Chk" << pnlsectNum << ";" << endl;  pnlsectNum++;
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
					case VecWznmVVartype::STRING:
						outfile << "\tif (has(diffitems, ContIac::TXF" << pnlsectNum << ")) contiac.Txf" << pnlsectNum << " = _contiac->Txf" << pnlsectNum << ";" << endl;  pnlsectNum++;
						break;

					case VecWznmVVartype::VECSREF:
						outfile << "\tif (has(diffitems, ContIac::NUMFPUP" << pnlsectNum << ")) {" << endl;
						outfile << "\t\tif (feedFPup" << pnlsectNum << ".getIxByNum(_contiac->numFPup" << pnlsectNum << ") != 0) contiac.numFPup" << pnlsectNum << " = _contiac->numFPup" << pnlsectNum << ";" << endl;
						outfile << "\t\telse contiac.numFPup" << pnlsectNum++ << " = 1;" << endl;
						outfile << "\t};" << endl;
						break;
				};
			};
		};
		// ^

		outfile << endl;
	};

	outfile << "\tif (!diffitems.empty()) refresh(dbs" << prjshort << ", moditems);" << endl;

	outfile << "\t// IP handleDpchAppDataContiac --- END" << endl;
	outfile << "// IP handleDpchAppDataContiac --- IEND" << endl;
};

void WznmCtpWrsrvPrefs::addPnljobstrs(
			const string& pnljobshort
			, ListWznmMBlock& blks
			, vector<string>& pnljobshorts
			, vector<string>& pnljobblksrefsds
			, vector<string>& pnljobblksrefscmbds
		) {
	// pnljobblksrefs[cmb]d ex. "stgfstpbehavior, stgfstpappsrv, stgfstpcmbd, stgfstpdatabase, stgfstppath"
	WznmMBlock* blk = NULL;

	string pnljobblksrefsd, pnljobblksrefscmbd;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->wriIxWznmWScope & VecWznmWScope::ENG) {
			if (pnljobblksrefsd != "") pnljobblksrefsd += ", ";
			pnljobblksrefsd += StrMod::lc(blk->sref);
		};
		if (blk->wriIxWznmWScope & VecWznmWScope::CMBENG) {
			if (pnljobblksrefscmbd != "") pnljobblksrefscmbd += ", ";
			pnljobblksrefscmbd += StrMod::lc(blk->sref);
		};
	};

	pnljobshorts.push_back(pnljobshort);
	pnljobblksrefsds.push_back(pnljobblksrefsd);
	pnljobblksrefscmbds.push_back(pnljobblksrefscmbd);
};

void WznmCtpWrsrvPrefs::getBlkvars(
			ListWznmMBlock& blks
			, string& blkvarsd
			, string& blkvarscmbd
		) {
	// ex. "StgFstpBehavior*& _stgfstpbehavior, StgFstpAppsrv*& _stgfstpappsrv, StgFstpcmbd*& _stgfstpcmbd"
	WznmMBlock* blk = NULL;

	string s;

	blkvarsd = "";
	blkvarscmbd = "";

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) s = blk->sref;
		else s = blk->sref.substr(3) + "::Stg";
		s += "*& _" + StrMod::lc(blk->sref);

		if (blk->wriIxWznmWScope & VecWznmWScope::ENG) {
			if (blkvarsd != "") blkvarsd += ", ";
			blkvarsd += s;
		};
		if (blk->wriIxWznmWScope & VecWznmWScope::CMBENG) {
			if (blkvarscmbd != "") blkvarscmbd += ", ";
			blkvarscmbd += s;
		};
	};
};
// IP cust --- IEND
