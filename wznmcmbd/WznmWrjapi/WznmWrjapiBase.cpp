/**
	* \file WznmWrjapiBase.cpp
	* Wznm operation processor - write Java API code basics (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrjapiBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrjapi;

/******************************************************************************
 namespace WznmWrjapiBase
 ******************************************************************************/

DpchRetWznm* WznmWrjapiBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrjapiBase* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ListWznmMBlock blks;

	string s;
	fstream jfile;

	// find dispatch blocks
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = "
				+ to_string(VecWznmVMBlockBasetype::DPCH) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", false, blks);
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = "
				+ to_string(VecWznmVMBlockBasetype::DPCH) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0 ORDER BY sref ASC", true, blks);

	// --- create files
	s = xchg->tmppath + "/" + folder + "/Api" + Prjshort + ".java.ip";
	jfile.open(s.c_str(), ios::out);

	writeApiJ(dbswznm, Prjshort, jfile, refWznmMVersion);

	jfile.close();

	// VecXxxxVDpch (special treatment, not all vector items)
	s = xchg->tmppath + "/" + folder + "/Vec" + Prjshort + "VDpch.java.ip";
	jfile.open(s.c_str(), ios::out);

	writeVecdpchJ(dbswznm, jfile, blks);

	jfile.close();
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrjapiBase::writeApiJ(
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

		outfile << "\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if (ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch." << StrMod::uc(blk->sref) << ") dpcheng = ";

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

			outfile << "(new " << job->sref << "()).new " << subsref << "()";

			delete job;

		} else {
			outfile << "new " << blk->sref << "()";
		};

		outfile << ";" << endl;
	};

	outfile << "// IP readDpchEng --- IEND" << endl;
};

void WznmWrjapiBase::writeVecdpchJ(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMBlock& blks
		) {
	WznmMBlock* blk = NULL;

	// --- vec
	outfile << "// IP vec --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\tpublic static final int " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << " = " << (i+1) << ";" << endl;
	};
	outfile << "// IP vec --- IEND" << endl;

	// --- getIx
	outfile << "// IP getIx --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\t\tif (s.equals(\"" << StrMod::lc(blk->sref) << "\")) return " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << ";" << endl;
	};
	outfile << "// IP getIx --- IEND" << endl;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(blk->sref)) << ") return(\"" << blk->sref << "\");" << endl;
	};
	outfile << "// IP getSref --- IEND" << endl;
};
// IP cust --- IEND


