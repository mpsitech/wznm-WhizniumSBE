/**
	* \file WznmWrsrvOpengbase.cpp
	* Wznm operation processor - write operation engine C++ code basics (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrvOpengbase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvOpengbase
 ******************************************************************************/

DpchRetWznm* WznmWrsrvOpengbase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvOpengbase* dpchinv
		) {
	ubigint refWznmMComponent = dpchinv->refWznmMComponent;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;

	WznmMComponent* cmp = NULL;
	WznmMVersion* ver = NULL;

	ListWznmMOppack opks;

	ListWznmMOp ops;

	ListWznmMBlock stgblks;

	bool dbsmarmy, dbslite;

	fstream hfile;
	fstream cppfile;

	string s;

	if (dbswznm->tblwznmmcomponent->loadRecByRef(refWznmMComponent, &cmp)) {
		if (dbswznm->tblwznmmversion->loadRecByRef(cmp->refWznmMVersion, &ver)) {
			dbswznm->tblwznmrmcomponentmoppack->loadOpksByCmp(refWznmMComponent, false, refs);
			dbswznm->tblwznmmoppack->loadRstByRefs(refs, false, opks);

			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(ver->ref) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID)
						+ " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::OPENG) + ") <> 0 ORDER BY sref ASC", false, stgblks);

			for (unsigned int i = 0; i < refs.size(); i++) {
				dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(ver->ref) + " AND ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
							+ " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(refs[i]) + " AND (wriIxWznmWScope & " + to_string(VecWznmWScope::OPENG) + ") <> 0 ORDER BY sref ASC", true, stgblks);

				dbswznm->tblwznmmblock->loadRstBySQL("SELECT TblWznmMBlock.* FROM TblWznmMOp, TblWznmMBlock WHERE TblWznmMOp.refWznmMOppack = " + to_string(refs[i]) + " AND TblWznmMBlock.refIxVTbl = "
							+ to_string(VecWznmVMBlockRefTbl::OPX) + " AND TblWznmMBlock.refUref = TblWznmMOp.ref AND TblWznmMBlock.ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG)
							+ " AND (TblWznmMBlock.wriIxWznmWScope & " + to_string(VecWznmWScope::OPENG) + ") <> 0 ORDER BY TblWznmMBlock.sref ASC", true, stgblks);
			};

 			dbsmarmy = ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO + VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) != 0);
			dbslite = ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) != 0);

			// Xxxxopd_exe.cpp
			s = xchg->tmppath + "/" + folder + "/" + Prjshort + "opd_exe.cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writeExeCpp(dbswznm, cppfile, ver->ref, Prjshort, opks, stgblks, dbsmarmy, dbslite);

			cppfile.close();

			// XxxxopdEngsrv.cpp
			s = xchg->tmppath + "/" + folder + "/" + Prjshort + "opdEngsrv.h.ip";
			hfile.open(s.c_str(), ios::out);
			s = xchg->tmppath + "/" + folder + "/" + Prjshort + "opdEngsrv.cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writeEsrvH(dbswznm, hfile, ver->ref, opks);
			writeEsrvCpp(dbswznm, cppfile, ver->ref, Prjshort, opks);

			hfile.close();
			cppfile.close();

			// XxxxopdOpprc.h, XxxxopdOpprc.cpp
			s = xchg->tmppath + "/" + folder + "/" + Prjshort + "opdOpprc.h.ip";
			hfile.open(s.c_str(), ios::out);
			s = xchg->tmppath + "/" + folder + "/" + Prjshort + "opdOpprc.cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writeOprcH(dbswznm, hfile, ver->ref, opks);
			writeOprcCpp(dbswznm, cppfile, ver->ref, Prjshort, opks);

			hfile.close();
			cppfile.close();

			// Xxxxopd.h
			s = xchg->tmppath + "/" + folder + "/" + Prjshort + "opd.h.ip";
			hfile.open(s.c_str(), ios::out);
			s = xchg->tmppath + "/" + folder + "/" + Prjshort + "opd.cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writeOpdH(dbswznm, hfile, Prjshort, stgblks);
			writeOpdCpp(dbswznm, cppfile, Prjshort, stgblks);

			hfile.close();
			cppfile.close();

			delete ver;
		};

		delete cmp;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvOpengbase::writeExeCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMOppack& opks
			, ListWznmMBlock& stgblks
			, const bool dbsmy
			, const bool dbslite
		) {
	WznmMBlock* stgblk = NULL;

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

	// --- init.shrdat.ops
	outfile << "// IP init.shrdat.ops --- IBEGIN" << endl;

	first = true;

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

void WznmWrsrvOpengbase::writeEsrvH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, ListWznmMOppack& opks
		) {
	WznmMOppack* opk = NULL;

	// --- include.blks
	outfile << "// IP include.blks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];
		outfile << "#include \"" << opk->sref << "_blks.h\"" << endl;
	};
	outfile << "// IP include.blks --- IEND" << endl;
};

void WznmWrsrvOpengbase::writeEsrvCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMOppack& opks
		) {
	WznmMOppack* opk = NULL;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	// --- readDpchInv
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'DpchInv"
				+ Prjshort + "'", false, blks);

	for (unsigned int i = 0; i < opks.nodes.size(); i++) {
		opk = opks.nodes[i];

		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refWznmMVersion = "
					+ to_string(refWznmMVersion) + " AND (reaIxWznmWScope & " + to_string(VecWznmWScope::OPENG) + ") <> 0 AND (wriIxWznmWScope & "
					+ to_string(VecWznmWScope::ENG) + ") <> 0 AND sref LIKE 'DpchInv" + opk->sref + "%' ORDER BY sref ASC", true, blks);
	};

	outfile << "// IP readDpchInv --- IBEGIN" << endl;
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "} else ";

		outfile << "if (ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ") {" << endl;
		outfile << "\t\treq->dpchinv = new " << blk->sref << "();" << endl;
		outfile << "\t\t((" << blk->sref << "*) (req->dpchinv))->readXML(docctx, \"/\", true);" << endl;
	};
	if (blks.nodes.size() > 0) outfile << "\t};" << endl;
	outfile << "// IP readDpchInv --- IEND" << endl;
};

void WznmWrsrvOpengbase::writeOprcH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, ListWznmMOppack& opks
		) {
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

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

void WznmWrsrvOpengbase::writeOprcCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMOppack& opks
		) {
	WznmMOppack* opk = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

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

void WznmWrsrvOpengbase::writeOpdH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, ListWznmMBlock& stgblks
		) {
	WznmMBlock* stgblk = NULL;

	// --- stgblks
	outfile << "// IP stgblks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];
		writeBlkstgH(dbswznm, Prjshort, outfile, NULL, stgblk, false, "");
	};
	outfile << "// IP stgblks --- IEND" << endl;

	// --- vars.stgblks
	outfile << "// IP vars.stgblks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];
		if (stgblk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) outfile << "\t" << stgblk->sref << " " << StrMod::lc(stgblk->sref) << ";" << endl;
	};
	outfile << "// IP vars.stgblks --- IEND" << endl;
};

void WznmWrsrvOpengbase::writeOpdCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, ListWznmMBlock& stgblks
		) {
	WznmMBlock* stgblk = NULL;

	// --- stgblks
	outfile << "// IP stgblks --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stgblks.nodes.size(); i++) {
		stgblk = stgblks.nodes[i];
		if (stgblk->refIxVTbl == VecWznmVMBlockRefTbl::VOID) writeBlkstgCpp(dbswznm, Prjshort, outfile, NULL, stgblk, false, "", "");
	};
	outfile << "// IP stgblks --- IEND" << endl;
};
// IP cust --- IEND


