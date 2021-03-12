/**
	* \file WznmWrsrvOpk.cpp
	* Wznm operation processor - write C++ code for operation pack (implementation)
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

#include "WznmWrsrvOpk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsrvOpk
 ******************************************************************************/

DpchRetWznm* WznmWrsrvOpk::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvOpk* dpchinv
		) {
	ubigint refWznmMOppack = dpchinv->refWznmMOppack;
	string orgweb = dpchinv->orgweb;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	WznmMOppack* opk = NULL;

	WznmMBlock* stgblk = NULL;

	string s;

	dbswznm->tblwznmmoppack->loadRecByRef(refWznmMOppack, &opk);

	dbswznm->tblwznmmblock->loadRecBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK)
				+ " AND refUref = " + to_string(refWznmMOppack), &stgblk);

	// XxxxYyyyy.h, XxxxYyyyy.cpp
	s = xchg->tmppath + "/" + folder + "/" + opk->sref + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/" + opk->sref + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeOpkH(dbswznm, hfile, opk, stgblk, Prjshort);
	writeOpkCpp(dbswznm, cppfile, opk, stgblk, Prjshort);

	hfile.close();
	cppfile.close();

	// XxxxYyyyy_blks.h, XxxxYyyyy_blks.cpp
	s = xchg->tmppath + "/" + folder + "/" + opk->sref + "_blks.h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/" + opk->sref + "_blks.cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeOpkblksH(dbswznm, hfile, opk, Prjshort);
	writeOpkblksCpp(dbswznm, cppfile, opk, orgweb, Prjshort);

	hfile.close();
	cppfile.close();

	// SqkXxxxYyyyy.h, SqkXxxxYyyyy.cpp
	s = xchg->tmppath + "/" + folder + "/Sqk" + opk->sref + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/Sqk" + opk->sref + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeSqkH(dbswznm, hfile, opk, Prjshort);
	writeSqkCpp(dbswznm, cppfile, opk, Prjshort);

	hfile.close();
	cppfile.close();

	delete opk;
	if (stgblk) delete stgblk;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvOpk::writeOpkH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOppack* opk
			, WznmMBlock* stgblk
			, const string& Prjshort
		) {
	// --- fsrs.stg*
	if (stgblk) outfile << "// IP fsrs.stg --- AFFIRM" << endl;
	else outfile << "// IP fsrs.stg --- REMOVE" << endl;

	// --- fsrs.shrdat*
	if (opk->Shrdat) outfile << "// IP fsrs.shrdat --- AFFIRM" << endl;
	else outfile << "// IP fsrs.shrdat --- REMOVE" << endl;

	// --- Stg
	outfile << "// IP Stg --- IBEGIN" << endl;
	if (stgblk) writeBlkstgH(dbswznm, Prjshort, outfile, NULL, stgblk, true, "Stg");
	outfile << "// IP Stg --- IEND" << endl;

	// --- Shrdat*
	if (opk->Shrdat) outfile << "// IP Shrdat --- AFFIRM" << endl;
	else outfile << "// IP Shrdat --- REMOVE" << endl;

	// --- varStg*
	if (stgblk) outfile << "// IP vars.stg --- AFFIRM" << endl;
	else outfile << "// IP vars.stg --- REMOVE" << endl;

	// --- varShrdat*
	if (opk->Shrdat) outfile << "// IP vars.shrdat --- AFFIRM" << endl;
	else outfile << "// IP vars.shrdat --- REMOVE" << endl;
};

void WznmWrsrvOpk::writeOpkCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOppack* opk
			, WznmMBlock* stgblk
			, const string& Prjshort
		) {
	// --- Stg
	outfile << "// IP Stg --- IBEGIN" << endl;
	if (stgblk) writeBlkstgCpp(dbswznm, Prjshort, outfile, NULL, stgblk, true, opk->sref, "Stg");
	outfile << "// IP Stg --- IEND" << endl;

	// --- Shrdat*
	if (opk->Shrdat) outfile << "// IP Shrdat --- AFFIRM" << endl;
	else outfile << "// IP Shrdat --- REMOVE" << endl;
};

void WznmWrsrvOpk::writeOpkblksH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOppack* opk
			, const string& Prjshort
		) {
	ListWznmMOp ops;
	WznmMOp* op = NULL;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	// --- invrets
	outfile << "// IP invrets --- IBEGIN" << endl;

	if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(opk->ref) + " ORDER BY sref ASC", false, blks);

	} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
		dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);
		for (unsigned int i = 0; i < ops.nodes.size(); i++) {
			op = ops.nodes[i];
			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX) + " AND refUref = " + to_string(op->ref) + " ORDER BY sref ASC", true, blks);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		writeBlkdpchH(dbswznm, Prjshort, outfile, NULL, blk, "");
	};

	outfile << "// IP invrets --- IEND" << endl;
};

void WznmWrsrvOpk::writeOpkblksCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOppack* opk
			, const string& orgweb
			, const string& Prjshort
		) {
	ListWznmMOp ops;
	WznmMOp* op = NULL;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	// --- invrets
	outfile << "// IP invrets --- IBEGIN" << endl;

	if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
		dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(opk->ref) + " ORDER BY sref ASC", false, blks);

	} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
		dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);
		for (unsigned int i = 0; i < ops.nodes.size(); i++) {
			op = ops.nodes[i];
			dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX) + " AND refUref = " + to_string(op->ref) + " ORDER BY sref ASC", true, blks);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];
		writeBlkdpchCpp(dbswznm, orgweb, Prjshort, outfile, NULL, blk, "");
	};

	outfile << "// IP invrets --- IEND" << endl;
};

void WznmWrsrvOpk::writeSqkH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOppack* opk
			, const string& Prjshort
		) {
	ListWznmMOp ops;
	WznmMOp* op = NULL;

	// --- getSquawks
	outfile << "// IP getSquawks --- IBEGIN" << endl;

	if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
		outfile << "\tstd::string getSquawk(Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << ", DpchInv" << opk->sref << "* dpchinv);" << endl;

	} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
		dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);
		for (unsigned int i = 0; i < ops.nodes.size(); i++) {
			op = ops.nodes[i];
			outfile << "\tstd::string getSquawk" << op->sref.substr(opk->sref.length()) << "(Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << ", DpchInv" << op->sref << "* dpchinv);" << endl;
		};
	};

	outfile << "// IP getSquawks --- IEND" << endl;
};

void WznmWrsrvOpk::writeSqkCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOppack* opk
			, const string& Prjshort
		) {
	ListWznmMOp ops;
	WznmMOp* op = NULL;

	WznmMSquawk* sqk = NULL;

	// --- getSquawks
	outfile << "// IP getSquawks --- IBEGIN" << endl;

	if (opk->ixVBasetype == VecWznmVMOppackBasetype::CUST) {
		outfile << "string Sqk" << opk->sref << "::getSquawk(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << endl;
		outfile << "\t\t\t, DpchInv" << opk->sref << "* dpchinv" << endl;
		outfile << "\t\t) {" << endl;

		if (dbswznm->tblwznmmsquawk->loadRecByRef(opk->refWznmMSquawk, &sqk)) {
			outfile << "\t// example: \"" << sqk->Example << "\"" << endl;
			delete sqk;
		};

		outfile << "\treturn(\"\"); // IP getSquawk --- LINE" << endl;
		outfile << "};" << endl;

	} else if (opk->ixVBasetype == VecWznmVMOppackBasetype::STAT) {
		dbswznm->tblwznmmop->loadRstByOpk(opk->ref, false, ops);
		for (unsigned int i = 0; i < ops.nodes.size(); i++) {
			op = ops.nodes[i];

			outfile << "string Sqk" << opk->sref << "::getSquawk" << op->sref.substr(opk->sref.length()) << "(" << endl;
			outfile << "\t\t\tDbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << endl;
			outfile << "\t\t\t, DpchInv" << op->sref << "* dpchinv" << endl;
			outfile << "\t\t) {" << endl;

			if (dbswznm->tblwznmmsquawk->loadRecByRef(op->refWznmMSquawk, &sqk)) {
				outfile << "\t// example: \"" << sqk->Example << "\"" << endl;
				delete sqk;
			};

			outfile << "\treturn(\"\"); // IP getSquawk" << op->sref.substr(opk->sref.length()) << " --- LINE" << endl;
			outfile << "};" << endl;

			outfile << endl;
		};
	};

	outfile << "// IP getSquawks --- IEND" << endl;
};
// IP cust --- IEND
