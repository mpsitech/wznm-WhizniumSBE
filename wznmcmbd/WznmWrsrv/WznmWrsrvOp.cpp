/**
	* \file WznmWrsrvOp.cpp
	* Wznm operation processor - write C++ code for operation (implementation)
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

#include "WznmWrsrvOp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvOp
 ******************************************************************************/

DpchRetWznm* WznmWrsrvOp::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvOp* dpchinv
		) {
	ubigint refWznmMOp = dpchinv->refWznmMOp;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	uint cnt;

	fstream hfile;
	fstream cppfile;

	WznmMOp* op = NULL;

	WznmMBlock* stgblk = NULL;

	string srefDpchinv;
	string srefDpchret;

	string s;

	if (dbswznm->tblwznmmop->loadRecByRef(refWznmMOp, &op)) {
		dbswznm->tblwznmmblock->loadRecBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX)
					+ " AND refUref = " + to_string(refWznmMOp), &stgblk);

		// find invocation and return dispatches
		srefDpchinv = "DpchInv" + Prjshort;
		srefDpchret = "DpchRet" + Prjshort;

		// check for custom invocation parameters
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMOppackInvarg WHERE opkRefWznmMOppack = " + to_string(op->refWznmMOppack), cnt);
		if (cnt > 0) {
			dbswznm->tblwznmmoppack->loadSrfByRef(op->refWznmMOppack, s);
			srefDpchinv = "DpchInv" + s;
		} else {
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMOpInvarg WHERE opxRefWznmMOp = " + to_string(op->ref), cnt);
			if (cnt > 0) srefDpchinv = "DpchInv" + op->sref;
		};

		// check for custom return parameters
		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMOppackRetval WHERE opkRefWznmMOppack = " + to_string(op->refWznmMOppack), cnt);
		if (cnt > 0) {
			dbswznm->tblwznmmoppack->loadSrfByRef(op->refWznmMOppack, s);
			srefDpchret = "DpchRet" + s;
		} else {
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMOpRetval WHERE opxRefWznmMOp = " + to_string(op->ref), cnt);
			if (cnt > 0) srefDpchret = "DpchRet" + op->sref;
		};

		// XxxxYyyyyZzzzz.h, XxxxYyyyyZzzzz.cpp
		s = xchg->tmppath + "/" + folder + "/" + op->sref + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + op->sref + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeOpH(dbswznm, hfile, op, stgblk, Prjshort, srefDpchinv, srefDpchret);
		writeOpCpp(dbswznm, cppfile, op, stgblk, Prjshort, srefDpchinv, srefDpchret);

		hfile.close();
		cppfile.close();

		if (stgblk) delete stgblk;
		delete op;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvOp::writeOpH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOp* op
			, WznmMBlock* stgblk
			, const string& Prjshort
			, const string& srefDpchinv
			, const string& srefDpchret
		) {
	// --- fsrs.stg*
	if (stgblk) outfile << "// IP fsrs.stg --- AFFIRM" << endl;
	else outfile << "// IP fsrs.stg --- REMOVE" << endl;

	// --- fsrs.shrdat*
	if (op->Shrdat) outfile << "// IP fsrs.shrdat --- AFFIRM" << endl;
	else outfile << "// IP fsrs.shrdat --- REMOVE" << endl;

	// --- Stg
	outfile << "// IP Stg --- IBEGIN" << endl;
	if (stgblk) writeBlkstgH(dbswznm, Prjshort, outfile, NULL, stgblk, true, "Stg");
	outfile << "// IP Stg --- IEND" << endl;

	// --- Shrdat*
	if (op->Shrdat) outfile << "// IP Shrdat --- AFFIRM" << endl;
	else outfile << "// IP Shrdat --- REMOVE" << endl;

	// --- vars.stg*
	if (stgblk) outfile << "// IP vars.stg --- AFFIRM" << endl;
	else outfile << "// IP vars.stg --- REMOVE" << endl;

	// --- vars.shrdat*
	if (op->Shrdat) outfile << "// IP vars.shrdat --- AFFIRM" << endl;
	else outfile << "// IP vars.shrdat --- REMOVE" << endl;

	// --- run
	outfile << "// IP run --- IBEGIN" << endl;
	outfile << "\t" << srefDpchret << "* run(Xchg" << Prjshort << "* xchg, Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << ", " << srefDpchinv << "* dpchinv);" << endl;
	outfile << "// IP run --- IEND" << endl;
};

void WznmWrsrvOp::writeOpCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMOp* op
			, WznmMBlock* stgblk
			, const string& Prjshort
			, const string& srefDpchinv
			, const string& srefDpchret
		) {
	ubigint ref;

	ListWznmAMBlockItem bitsInv;
	ListWznmAMBlockItem bitsRet;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	bool first;

	// --- Stg
	outfile << "// IP Stg --- IBEGIN" << endl;
	if (stgblk) writeBlkstgCpp(dbswznm, Prjshort, outfile, NULL, stgblk, true, op->sref, "Stg");
	outfile << "// IP Stg --- IEND" << endl;

	// --- Shrdat*
	if (op->Shrdat) outfile << "// IP Shrdat --- AFFIRM" << endl;
	else outfile << "// IP Shrdat --- REMOVE" << endl;

	// --- run
	outfile << "// IP run --- IBEGIN" << endl;

	outfile << srefDpchret << "* " << op->sref << "::run(" << endl;
	outfile << "\t\t\tXchg" << Prjshort << "* xchg" << endl;
	outfile << "\t\t\t, Dbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << endl;
	outfile << "\t\t\t, " << srefDpchinv << "* dpchinv" << endl;
	outfile << "\t\t) {" << endl;

	if (srefDpchinv != ("DpchInv" + Prjshort)) {
		ref = 0;
		if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(op->refWznmMOppack) + " AND sref = '" + srefDpchinv + "'", ref))
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX) + " AND refUref = " + to_string(op->ref) + " AND sref = '" + srefDpchinv + "'", ref);

		if (ref != 0) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, bitsInv);
	};

	if (srefDpchret != ("DpchRet" + Prjshort)) {
		ref = 0;
		if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPK) + " AND refUref = " + to_string(op->refWznmMOppack) + " AND sref = '" + srefDpchret + "'", ref))
					dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::DPCH) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::OPX) + " AND refUref = " + to_string(op->ref) + " AND sref = '" + srefDpchret + "'", ref);

		if (ref != 0) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, bitsRet);
	};

	if (bitsInv.nodes.size() > 0) {
		refC = 0;
		first = true;
		for (unsigned int i = 0; i < bitsInv.nodes.size(); i++) {
			bit = bitsInv.nodes[i];

			if ((bit->sref != "oref") && (bit->sref != "jref") && (bit->sref != "srefKCustop")) {
				if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

				if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) outfile << "\tbool " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) outfile << "\tvector<bool> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) outfile << "\tvector<utinyint> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) outfile << "\tvector<usmallint> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) outfile << "\tvector<int> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) outfile << "\tvector<uint> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) outfile << "\tvector<ubigint> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) outfile << "\tvector<float> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) outfile << "\tFloatmat " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) outfile << "\tvector<double> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) outfile << "\tDoublemat " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) outfile << "\tvector<string> " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\tuint " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;
				else outfile << "\t" << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << " = dpchinv->" << bit->sref << ";" << endl;

				refC = bit->refWznmCAMBlockItem;
				first = false;
			};
		};

		outfile << endl;
	};

	outfile << "\tutinyint ixOpVOpres = VecOpVOpres::SUCCESS;" << endl;
	outfile << endl;

	if (bitsRet.nodes.size() > 0) {
		refC = 0;
		first = true;
		for (unsigned int i = 0; i < bitsRet.nodes.size(); i++) {
			bit = bitsRet.nodes[i];

			if ((bit->sref != "oref") && (bit->sref != "jref") && (bit->sref != "ixOpVOpres") && (bit->sref != "pdone")) {
				if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

				wrVarDeclH(outfile, bit->ixWznmVVartype, bit->sref, 0);

				refC = bit->refWznmCAMBlockItem;
				first = false;
			};
		};
	};

	outfile << endl;
	outfile << "\t// IP run --- INSERT" << endl;
	outfile << endl;

	if (bitsRet.nodes.size() > 0) {
		outfile << "\treturn(new " << srefDpchret << "(\"\", \"\", ixOpVOpres, 100";
		for (unsigned int i = 0; i < bitsRet.nodes.size(); i++) {
			bit = bitsRet.nodes[i];

			if ((bit->sref != "oref") && (bit->sref != "jref") && (bit->sref != "ixOpVOpres") && (bit->sref != "pdone")) outfile << ", " << bit->sref;
		};
		outfile << "));" << endl;

	} else {
		outfile << "\treturn(new " << srefDpchret << "(Vec" << Prjshort << "VDpch::" << StrMod::uc(srefDpchret) << ", \"\", \"\", ixOpVOpres, 100));" << endl;
	};

	outfile << "};" << endl;
	outfile << "// IP run --- IEND" << endl;
};
// IP cust --- IEND
