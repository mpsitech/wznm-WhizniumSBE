/**
	* \file WznmWrsapiBase.swift
	* Wznm operation processor - write Swift API code basics (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsapiBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsapiBase
 ******************************************************************************/

DpchRetWznm* WznmWrsapiBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsapiBase* dpchinv
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
	fstream swfile;

	// find dispatch blocks
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = "
				+ to_string(VecWznmVMBlockBasetype::DPCH) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", false, blks);
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = "
				+ to_string(VecWznmVMBlockBasetype::DPCH) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", true, blks);

	// find global vectors
	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = 0 ORDER BY sref ASC", false, vecs);

	// --- create files
	s = xchg->tmppath + "/" + folder + "/Api" + Prjshort + ".swift.ip";
	swfile.open(s.c_str(), ios::out);

	writeApiSw(dbswznm, Prjshort, swfile, refWznmMVersion);

	swfile.close();

	// global vectors
	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		s = xchg->tmppath + "/" + folder + "/" + vec->sref + ".swift.ip";
		swfile.open(s.c_str(), ios::out);

		swfile << "// IP vec --- IBEGIN" << endl;
		writeVecSw(dbswznm, Prjshort, swfile, vec, false, "", "");
		swfile << "// IP vec --- IEND" << endl;

		swfile.close();
	};

	// VecXxxxVDpch - special treatment, not all vector items
	s = xchg->tmppath + "/" + folder + "/Vec" + Prjshort + "VDpch.swift.ip";
	swfile.open(s.c_str(), ios::out);

	writeVecdpchSw(dbswznm, swfile, blks);

	swfile.close();

	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsapiBase::writeApiSw(
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
		if (i != 0) outfile << "else ";
		outfile << "if ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch." << StrMod::uc(blk->sref) << " {";

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

			outfile << "dpcheng = " << job->sref << "." << subsref << "()";

			delete job;

		} else {
			outfile << "dpcheng = " << blk->sref << "()";
		};

		outfile << "}" << endl;
	};

	outfile << "// IP readDpchEng --- IEND" << endl;
};

void WznmWrsapiBase::writeVecdpchSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMBlock& blks
		) {
	WznmMBlock* blk = NULL;

	// --- vec
	outfile << "// IP vec --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\tpublic static let " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << ": Int = " << (i+1) << endl;
	};
	outfile << "// IP vec --- IEND" << endl;

	// --- getIx
	outfile << "// IP getIx --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\t\tif s == \"" << StrMod::lc(blk->sref) << "\" {return " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << "}" << endl;
	};
	outfile << "// IP getIx --- IEND" << endl;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << ") {return \"" << blk->sref << "\"}" << endl;
	};
	outfile << "// IP getSref --- IEND" << endl;
};
// IP cust --- IEND
