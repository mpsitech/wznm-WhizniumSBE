/**
	* \file WznmWrapiQtb.cpp
	* Wznm operation processor - write API code for query table (implementation)
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

#include "WznmWrapiQtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapi;

/******************************************************************************
 namespace WznmWrapiQtb
 ******************************************************************************/

DpchRetWznm* WznmWrapiQtb::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrapiQtb* dpchinv
		) {
	ubigint refWznmMTable = dpchinv->refWznmMTable;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	ListWznmMQuerycol qcos;

	string s;
	fstream hfile;
	fstream cppfile;

	if (dbswznm->tblwznmmtable->loadRecByRef(refWznmMTable, &tbl)) {
		// load table and query columns
		dbswznm->tblwznmmtablecol->loadRstByTbl(refWznmMTable, false, tcos);
		dbswznm->tblwznmmquerycol->loadRstByQry(tbl->refUref, false, qcos);

		// create files
		s = xchg->tmppath + "/" + folder + "/" + tbl->sref.substr(3) + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + tbl->sref.substr(3) + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		writeQtbH(dbswznm, hfile, tbl, tcos, qcos);
		writeQtbCpp(dbswznm, cppfile, tbl, tcos, qcos);

		cppfile.close();
		hfile.close();

		delete tbl;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrapiQtb::writeQtbH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmMQuerycol& qcos
		) {
	WznmMQuerycol* qco = NULL;

	string qcotype;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;
	outfile << "\t" << tbl->sref.substr(3) << "(const Sbecore::uint jnum = 0";

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
			qcotype = getQcoCppType(qco->ixVBasetype, true);
			if (qcotype.length() == 0) for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, true);

			outfile << ", const " << qcotype << " " << qco->sref << " = " << getQcoCppDefault(qcotype);
		};
	};

	outfile << ");" << endl;
	outfile << "// IP constructor --- IEND" << endl;

	// --- tcos
	outfile << "// IP tcos --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
			qcotype = getQcoCppType(qco->ixVBasetype, true);
			if (qcotype.length() == 0) for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, true);

			outfile << "\t" << qcotype << " " << qco->sref << ";" << endl;
		};
	};
	outfile << "// IP tcos --- IEND" << endl;
};

void WznmWrapiQtb::writeQtbCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmMQuerycol& qcos
		) {
	WznmMQuerycol* qco = NULL;

	string qcotype;

	// --- constructor.hdr
	outfile << "// IP constructor.hdr --- IBEGIN" << endl;

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
			qcotype = getQcoCppType(qco->ixVBasetype, false);
			if (qcotype.length() == 0) for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, false);

			outfile << "\t\t\t, const " << qcotype << " " << qco->sref << endl;
		};
	};

	outfile << "// IP constructor.hdr --- IEND" << endl;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\tthis->" << qco->sref << " = " << qco->sref << ";" << endl;
	};
	outfile << "// IP constructor --- IEND" << endl;

	// --- readXML
	outfile << "// IP readXML --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
			qcotype = getQcoCppType(qco->ixVBasetype, false);
			if (qcotype.length() == 0) for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoCppType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype, false);

			outfile << "\t\textract" << StrMod::cap(qcotype) << "Uclc(docctx, basexpath, \"" << qco->sref << "\", \"" << qco->Short << "\", " << qco->sref << ");" << endl;
		};
	};
	outfile << "// IP readXML --- IEND" << endl;
};

// exact copy from WznmWrdbsTbl.cpp
string WznmWrapiQtb::getTcoCppType(
			const uint ixVBasetype
			, const uint ixVSubtype
			, const bool ns
		) {
	string retval;

	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) {
		retval = "uint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) {
		retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
		retval = "uint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) {
		retval = "usmallint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TINYINT) retval = "tinyint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UTINYINT) retval = "utinyint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::SMALLINT) retval = "smallint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::USMALLINT) retval = "usmallint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::INT) retval = "int";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UINT) retval = "uint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) retval = "bigint";
		else if (ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT) retval = "ubigint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
		retval = "double";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
		retval = "bool";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) {
		retval = "string";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) retval = "double";
		else retval = "uint";

	} else if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) {
		retval = "string";
	};

	if (ns) {
		if (retval == "string") retval = "std::string";
		else if ((retval != "int") && (retval != "double") && (retval != "bool")) retval = "Sbecore::" + retval;
	};

	return retval;
};

// exact copy from WznmWrdbsTbl.cpp
string WznmWrapiQtb::getQcoCppType(
			const uint ixVBasetype
			, const bool ns
		) {
	string retval;

	if (ixVBasetype == VecWznmVMQuerycolBasetype::STUB) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::HSTUB) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::USTUB) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::STUBS) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VSREF) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VSREFS) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VTIT) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VTITS) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::YESNO) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMDATE) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMTIME) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMSTAMP) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMUSTAMP) retval = "string";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QIDREF) retval = "ubigint";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QWR) retval = "bool";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QJREF) retval = "ubigint";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QJENUM) retval = "uint";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::INTVAL) retval = "int";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::DBLVAL) retval = "double";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::BOOLVAL) retval = "bool";
	if (ixVBasetype == VecWznmVMQuerycolBasetype::TXTVAL) retval = "string";

	if (ns && (retval != "")) {
		if (retval == "string") retval = "std::string";
		else if ((retval != "int") && (retval != "double") && (retval != "bool")) retval = "Sbecore::" + retval;
	};

	return retval;
};

// exact copy from WznmWrdbsTbl.cpp
string WznmWrapiQtb::getQcoCppDefault(
			const string& qcotype
		) {
	// used in .h file only

	if (qcotype == "std::string") return("\"\"");
	if (qcotype == "bool") return("false");
	if (qcotype == "double") return("0.0");

	return("0");
};
// IP cust --- IEND



