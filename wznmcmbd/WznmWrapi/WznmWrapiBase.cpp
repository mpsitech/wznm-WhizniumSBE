/**
	* \file WznmWrapiBase.cpp
	* Wznm operation processor - write API code basics (implementation)
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

#include "WznmWrapiBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapi;

/******************************************************************************
 namespace WznmWrapiBase
 ******************************************************************************/

DpchRetWznm* WznmWrapiBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrapiBase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ListWznmMBlock blks;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	string s;
	fstream hfile;
	fstream cppfile;

	// find dispatch blocks
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = "
				+ to_string(VecWznmVMBlockBasetype::DPCH) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", false, blks);
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = "
				+ to_string(VecWznmVMBlockBasetype::DPCH) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", true, blks);

	// find global vectors
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = 0 ORDER BY sref ASC", false, vecs);

	// --- create files
	s = xchg->tmppath + "/" + folder + "/Api" + Prjshort + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/Api" + Prjshort + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeApiH(dbswznm, hfile, refWznmMVersion);
	writeApiCpp(dbswznm, Prjshort, cppfile, refWznmMVersion);

	cppfile.close();
	hfile.close();

	s = xchg->tmppath + "/" + folder + "/Api" + Prjshort + "_blks.h.ip";
	hfile.open(s.c_str(), ios::out);

	writeApiblksH(hfile, vecs);

	hfile.close();

	// global vectors
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		s = xchg->tmppath + "/" + folder + "/" + vec->sref + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + vec->sref + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		hfile << "// IP vec --- IBEGIN" << endl;
		writeVecH(dbswznm, Prjshort, hfile, vec, false, "");
		hfile << "// IP vec --- IEND" << endl;

		cppfile << "// IP vec --- IBEGIN" << endl;
		writeVecCpp(dbswznm, Prjshort, cppfile, vec, false, "", "");
		cppfile << "// IP vec --- IEND" << endl;

		cppfile.close();
		hfile.close();
	};

	// VecXxxxVDpch - special treatment, not all vector items
	s = xchg->tmppath + "/" + folder + "/Vec" + Prjshort + "VDpch.h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/Vec" + Prjshort + "VDpch.cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeVecdpchH(dbswznm, hfile, blks);
	writeVecdpchCpp(dbswznm, cppfile, blks);

	cppfile.close();
	hfile.close();

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrapiBase::writeApiH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
		) {
	ListWznmMTable qtbs;
	WznmMTable* qtb = NULL;

	ListWznmMJob jobs;
	WznmMJob* job = NULL;

	uint cnt;

	// --- include.qtbs
	dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMQuery, TblWznmMTable WHERE TblWznmMTable.ref = TblWznmMQuery.qtbRefWznmMTable AND TblWznmMQuery.refWznmMVersion = "
				+ to_string(refWznmMVersion) + " ORDER BY TblWznmMTable.sref ASC", false, qtbs);

	outfile << "// IP include.qtbs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qtbs.nodes.size(); i++) {
		qtb = qtbs.nodes[i];
		outfile << "#include \"" << qtb->sref.substr(3) << ".h\"" << endl;
	};
	outfile << "// IP include.qtbs --- IEND" << endl;

	// --- include.jobs
	dbswznm->tblwznmmjob->loadRstBySQL("SELECT * FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", false, jobs);

	outfile << "// IP include.jobs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		// count shared blocks
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
					+ " AND (((reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0) OR ((wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0))", cnt);
	
		if (cnt > 0) outfile << "#include \"" << job->sref << ".h\"" << endl;
	};
	outfile << "// IP include.jobs --- IEND" << endl;
};

void WznmWrapiBase::writeApiCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, const ubigint refWznmMVersion
		) {
	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	WznmMJob* job = NULL;

	string subsref;

	// --- readDpchEng
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refWznmMVersion = "
				+ to_string(refWznmMVersion) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", false, blks);

	outfile << "// IP readDpchEng --- IBEGIN" << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		outfile << "\t\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ") {" << endl;

		if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &job)) {
			if ((job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::PNL)) {
				// special rule for subsref
				// ex. DpchEngPlnrNavData -> CrdPlnrNav::DpchEngData
				subsref = "DpchEng" + blk->sref.substr(blk->sref.find(job->sref.substr(3)) + job->sref.length() - 3);
			} else {
				// regular rule for subsref
				// ex. DpchEngDlgPlnrNavLoainiData -> DlgPlnrNavLoaini::DpchEngData
				subsref = "DpchEng" + blk->sref.substr(blk->sref.find(job->sref) + job->sref.length());
			};

			outfile << "\t\t\t*dpcheng = new " << job->sref << "::" << subsref << "();" << endl;
			outfile << "\t\t\t((" << job->sref << "::" << subsref << "*) *dpcheng)->readXML(docctx, \"/\", true);" << endl;

			delete job;

		} else {
			outfile << "\t\t\t*dpcheng = new " << blk->sref << "();" << endl;
			outfile << "\t\t\t((" << blk->sref << "*) *dpcheng)->readXML(docctx, \"/\", true);" << endl;
		};
	};
	if (blks.nodes.size() > 0) outfile << "\t\t};" << endl;

	outfile << "// IP readDpchEng --- IEND" << endl;
};

void WznmWrapiBase::writeApiblksH(
			fstream& outfile
			, ListWznmMVector& vecs
		) {
	WznmMVector* vec = NULL;

	outfile << "// IP include.vecs --- IBEGIN" << endl;

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		outfile << "#include \"" << vec->sref << ".h\"" << endl;
	};

	outfile << "// IP include.vecs --- IEND" << endl;
};

void WznmWrapiBase::writeVecdpchH(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMBlock& blks
		) {
	WznmMBlock* blk = NULL;

	// --- vec
	outfile << "// IP vec --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\tconst Sbecore::uint " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << " = " << (i+1) << ";" << endl;
	};
	outfile << "// IP vec --- IEND" << endl;
};

void WznmWrapiBase::writeVecdpchCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMBlock& blks
		) {
	WznmMBlock* blk = NULL;

	// --- getIx
	outfile << "// IP getIx --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\tif (s == \"" << StrMod::lc(blk->sref) << "\") return " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << ";" << endl;
	};
	outfile << "// IP getIx --- IEND" << endl;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << ") return(\"" << blk->sref << "\");" << endl;
	};
	outfile << "// IP getSref --- IEND" << endl;
};
// IP cust --- IEND
