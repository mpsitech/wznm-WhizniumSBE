/**
	* \file WznmWrsrvDlg.cpp
	* Wznm operation processor - write specific job C++ code for dialog (implementation)
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

#include "WznmWrsrvDlg.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvDlg
 ******************************************************************************/

DpchRetWznm* WznmWrsrvDlg::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvDlg* dpchinv
		) {
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	WznmMJob* job = NULL;
	WznmMDialog* dlg = NULL;

	ListWznmMControl dits;

	string s;

	dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job);

	if (dbswznm->tblwznmmdialog->loadRecByRef(job->refUref, &dlg)) {
		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG) + " AND hkUref = " + to_string(dlg->ref)
					+ " AND ixVBasetype = " + to_string(VecWznmVMControlBasetype::DIT) + " ORDER BY hkNum ASC", false, dits);

		// DlgXxxxYyyZzzzz.h, DlgXxxxYyyZzzzz.cpp
		s = xchg->tmppath + "/" + folder + "/" + dlg->sref + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + dlg->sref + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeDlgH(dbswznm, hfile, job, dlg, dits, Prjshort);
		writeDlgCpp(dbswznm, cppfile, job, dlg, dits, Prjshort);

		hfile.close();
		cppfile.close();

		delete dlg;
	};

	delete job;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvDlg::writeDlgH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMDialog* dlg
			, ListWznmMControl& dits
			, const string& Prjshort
		) {
	WznmMControl* dit = NULL;

	string prjshort = StrMod::lc(Prjshort);

	// --- specVar
	outfile << "// IP vars.spec --- IBEGIN" << endl;
	if (dits.nodes.size() > 0) {
		outfile << "\tSbecore::uint ixVDit;" << endl;
		outfile << endl;
	};

	if (dlg->ixVBasetype == VecWznmVMDialogBasetype::NEW) {
		outfile << "\tbool valid;" << endl;
		outfile << endl;
	};
	outfile << "// IP vars.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tDpchEng" << Prjshort << "* getNewDpchEng(std::set<Sbecore::uint> items);" << endl;
	outfile << endl;

	// -- refresh
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];
		outfile << "\tvoid refresh" << dit->sref.substr(3) << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
	};
	outfile << endl;

	outfile << "\tvoid refresh(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems, const bool unmute = false);" << endl;
	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvDlg::writeDlgCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMDialog* dlg
			, ListWznmMControl& dits
			, const string& Prjshort
		) {
	ubigint ref;

	ListWznmAMBlockItem dpchengdatabits;
	ListWznmMBlock jobblks;
	ListWznmRMJobMJob jrjs;

	vector<string> bitsEval;
	vector<string> rulesEval;
	vector<string> exprsEval;

	WznmMControl* dit = NULL;

	string prjshort = StrMod::lc(Prjshort);

	bool hasdse = (dits.nodes.size() > 0);

	bool hassge = dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMControl WHERE ixVBasetype = " + to_string(VecWznmVMControlBasetype::SGE) + " AND hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG)
				+ " AND hkUref = " + to_string(dlg->ref), ref);

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
				+ " AND sref = 'DpchEng" + dlg->sref + "Data'", ref)) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, dpchengdatabits);

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref), false, jobblks);

	dbswznm->tblwznmrmjobmjob->loadRstBySup(job->ref, false, jrjs);

	Wznm::getJobevals(dbswznm, job, bitsEval, rulesEval, exprsEval);

	// --- ns.spec
	outfile << "// IP ns.spec --- IBEGIN" << endl;
	outfile << "// IP ns.spec --- IEND" << endl;

	// --- constructor.spec1
	outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
	if (dits.nodes.size() > 0) {
		outfile << "\tixVDit = VecVDit::" << StrMod::uc(dits.nodes[0]->sref.substr(3)) << ";" << endl;
		outfile << endl;
	};

	if (dlg->ixVBasetype == VecWznmVMDialogBasetype::NEW) {
		outfile << "\tvalid = false;" << endl;
		outfile << endl;
	};
	outfile << "// IP constructor.spec1 --- IEND" << endl;

	// --- constructor.spec2
	outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
	outfile << "\tset<uint> moditems;" << endl;
	outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
	outfile << "// IP constructor.spec2 --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	// -- getNewDpchEng
	outfile << "DpchEng" << Prjshort << "* " << dlg->sref << "::getNewDpchEng(" << endl;
	outfile << "\t\t\tset<uint> items" << endl;
	outfile << "\t\t) {" << endl;
	wrGetnewdpchengCpp(dbswznm, Prjshort, outfile, dpchengdatabits, job, jobblks, jrjs);
	outfile << "};" << endl;
	outfile << endl;

	// -- refresh
	for (unsigned int i = 0; i < dits.nodes.size(); i++) {
		dit = dits.nodes[i];

		outfile << "void " << dlg->sref << "::refresh" << dit->sref.substr(3) << "(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, set<uint>& moditems" << endl;
		outfile << "\t\t) {" << endl;

		writeDlgCpp_refresh(dbswznm, outfile, job, jobblks, dit->sref.substr(3), bitsEval, rulesEval, exprsEval, Prjshort, hasdse, hassge);

		outfile << "};" << endl;
		outfile << endl;
	};

	outfile << "void " << dlg->sref << "::refresh(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, set<uint>& moditems" << endl;
	outfile << "\t\t\t, const bool unmute" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (muteRefresh && !unmute) return;" << endl;
	outfile << "\tmuteRefresh = true;" << endl;
	outfile << endl;

	writeDlgCpp_refresh(dbswznm, outfile, job, jobblks, "", bitsEval, rulesEval, exprsEval, Prjshort, hasdse, hassge);
	
	if (dits.nodes.size() > 0) {
		outfile << endl;

		// - dit refreshes
		for (unsigned int i = 0; i < dits.nodes.size(); i++) {
			dit = dits.nodes[i];
			outfile << "\trefresh" << dit->sref.substr(3) << "(dbs" << prjshort << ", moditems);" << endl;
		};
	};

	outfile << endl;
	outfile << "\tmuteRefresh = false;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	outfile << "// IP spec --- IEND" << endl;

	// --- handleDpchAppXxxxInit
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IBEGIN" << endl;
	outfile << "\t*dpcheng = getNewDpchEng({DpchEngData::ALL});" << endl;
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IEND" << endl;

	if (dits.nodes.size() > 0) {
		// --- handleDpchAppDataContiac
		outfile << "// IP handleDpchAppDataContiac --- IBEGIN" << endl;
		outfile << endl;

		outfile << "\tif (has(diffitems, ContIac::NUMFDSE)) {" << endl;
		outfile << "\t\tif ((_contiac->numFDse >= VecVDit::" << StrMod::uc(dits.nodes[0]->sref.substr(3)) << ") && (_contiac->numFDse <= VecVDit::" << StrMod::uc(dits.nodes[dits.nodes.size()-1]->sref.substr(3)) << ")) ixVDit = _contiac->numFDse;" << endl;
		outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "// IP handleDpchAppDataContiac --- IEND" << endl;
	};
};

void WznmWrsrvDlg::writeDlgCpp_refresh(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, ListWznmMBlock& jobblks
			, const string& ditshort
			, vector<string>& bitsEval
			, vector<string>& rulesEval
			, vector<string>& exprsEval
			, const string& Prjshort
			, const bool hasdse
			, const bool hassge
		) {
	WznmMBlock* blk = NULL;

	vector<unsigned int> icsDitblks;

	string subsref;

	string prjshort = StrMod::lc(Prjshort);

	getDitblks(job, jobblks, ditshort, icsDitblks);

	for (unsigned int i = 0; i < icsDitblks.size(); i++) {
		blk = jobblks.nodes[icsDitblks[i]];

		subsref = Wznm::getSubsref(job, blk->sref);
		outfile << "\t" << subsref << " old" << StrMod::cap(StrMod::lc(subsref)) << "(" << StrMod::lc(subsref) << ");" << endl;
	};
	outfile << endl;

	outfile << "\t// IP refresh" << ditshort << " --- BEGIN" << endl;

	for (unsigned int i = 0; i < icsDitblks.size(); i++) {
		blk = jobblks.nodes[icsDitblks[i]];

		subsref = StrMod::lc(Wznm::getSubsref(job, blk->sref));

		outfile << "\t// " << subsref << endl;

		if ((subsref == "contiac") && hasdse) {
			outfile << "\tcontiac.numFDse = ixVDit;" << endl;

		} else if ((subsref == "continf") && hassge) {
			outfile << "\tcontinf.numFSge = ixVSge;" << endl;

		} else if (subsref.find("statshr") == 0) {
			for (unsigned int j = 0; j < bitsEval.size(); j++) {
				if (bitsEval[j].find(subsref + ".") == 0) writeEvalstatshr(outfile, bitsEval[j], rulesEval[j], exprsEval[j], prjshort);
			};
		};

		outfile << endl;
	};

	outfile << "\t// IP refresh" << ditshort << " --- END" << endl;

	for (unsigned int i = 0; i < icsDitblks.size(); i++) {
		blk = jobblks.nodes[icsDitblks[i]];

		subsref = Wznm::getSubsref(job, blk->sref);
		outfile << "\tif (" << StrMod::lc(subsref) << ".diff(&old" << StrMod::cap(StrMod::lc(subsref)) << ").size() != 0) insert(moditems, DpchEngData::" << StrMod::uc(subsref) << ");" << endl;
	};
};

void WznmWrsrvDlg::getDitblks(
			WznmMJob* job
			, ListWznmMBlock& blks
			, const string& ditshort
			, vector<unsigned int>& icsDitblks
		) {
	WznmMBlock* blk = NULL;

	string subsref;

	icsDitblks.clear();

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (!isStatic(blk)) {
			if (ditshort == "") {
				subsref = Wznm::getSubsref(job, blk->sref);
				if (subsref.length() == 7) icsDitblks.push_back(i);

			} else {
				if ((blk->sref.rfind(ditshort)+3) == blk->sref.length()) icsDitblks.push_back(i);
			};
		};
	};
};
// IP cust --- IEND
