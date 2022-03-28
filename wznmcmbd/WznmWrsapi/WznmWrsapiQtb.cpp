/**
	* \file WznmWrsapiQtb.cpp
	* Wznm operation processor - write Swift API code for query table (implementation)
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

#include "WznmWrsapiQtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsapiQtb
 ******************************************************************************/

DpchRetWznm* WznmWrsapiQtb::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsapiQtb* dpchinv
		) {
	ubigint refWznmMTable = dpchinv->refWznmMTable;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	ListWznmMQuerycol qcos;

	string s;
	fstream swfile;

	if (dbswznm->tblwznmmtable->loadRecByRef(refWznmMTable, &tbl)) {
		// load table and query columns
		dbswznm->tblwznmmtablecol->loadRstByTbl(refWznmMTable, false, tcos);
		dbswznm->tblwznmmquerycol->loadRstByQry(tbl->refUref, false, qcos);

		// create files
		s = xchg->tmppath + "/" + folder + "/" + tbl->sref.substr(3) + ".swift.ip";
		swfile.open(s.c_str(), ios::out);

		writeQtbSw(dbswznm, swfile, tbl, tcos, qcos);

		swfile.close();

		delete tbl;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsapiQtb::writeQtbSw(
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

	outfile << "\tpublic init(" << endl;
	outfile << "\t\t\t\t_ jnum: Int = 0" << endl;

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\t\t\t\t, _ " << qco->sref << ": " << getQcoTcoSwType(qco, tcos) << " = " << getQcoSwDefault(getQcoTcoSwType(qco, tcos)) << endl;
	};

	outfile << "\t\t\t) {" << endl;
	outfile << "\t\tself.jnum = jnum" << endl;

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\t\tself." << qco->sref << " = " << qco->sref << endl;
	};
	outfile << "\t}" << endl;
	outfile << "// IP constructor --- IEND" << endl;

	// --- tcos
	outfile << "// IP tcos --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\tpublic var " << qco->sref << ": " << getQcoTcoSwType(qco, tcos) << endl;
	};
	outfile << "// IP tcos --- IEND" << endl;

	// --- readXML.extract
	outfile << "// IP readXML.extract --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) {
			qcotype = getQcoSwType(qco->ixVBasetype);
			if (qcotype.length() == 0) for (unsigned int k = 0; k < tcos.nodes.size(); k++) if (tcos.nodes[k]->sref == qco->sref) qcotype = getTcoSwType(tcos.nodes[k]->ixVBasetype, tcos.nodes[k]->ixVSubtype);

			outfile << "\t\t\t" << qco->sref << " = Xmlio.extract" << StrMod::cap(qcotype) << "Uclc(doc, basexpath!, \"" << qco->sref << "\", \"" << qco->Short << "\", &dummy, 0)" << endl;
		};
	};
	outfile << "// IP readXML.extract --- IEND" << endl;
};

string WznmWrsapiQtb::getTcoSwType(
			const uint ixVBasetype
			, const uint ixVSubtype
		) {
	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) return("Long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) return("Long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) return("Int");
	if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) return("Long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) return("Long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) return("Int");
	if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) return("Int");

	if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TINYINT) return("Int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::UTINYINT) return("Int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::SMALLINT) return("Int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::USMALLINT) return("Int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::INT) return("Int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::UINT) return("Int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) return("Long");
		if (ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT) return("Long");
		return("");
	};

	if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) return("Double");
	if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) return("Bool");
	if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) return("String");

	if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) return("Double");
		return("int");
	};

	if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) return("String");

	return("");
};

string WznmWrsapiQtb::getQcoSwType(
			const uint ixVBasetype
		) {
	if (ixVBasetype == VecWznmVMQuerycolBasetype::STUB) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::HSTUB) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::USTUB) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::STUBS) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VSREF) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VSREFS) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VTIT) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::VTITS) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::YESNO) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMDATE) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMTIME) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMSTAMP) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::FTMUSTAMP) return("String");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QIDREF) return("Long");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QJREF) return("Long");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QJENUM) return("Int");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::INTVAL) return("Int");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::DBLVAL) return("Double");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::BOOLVAL) return("Bool");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::TXTVAL) return("String");

	return("");
};

string WznmWrsapiQtb::getQcoTcoSwType(
			WznmMQuerycol* qco
			, const ListWznmMTablecol& tcos
		) {
	string swtype;

	swtype = getQcoSwType(qco->ixVBasetype);
	if (swtype == "") for (unsigned int i = 0; i < tcos.nodes.size(); i++) if (tcos.nodes[i]->sref == qco->sref) swtype = getTcoSwType(tcos.nodes[i]->ixVBasetype, tcos.nodes[i]->ixVSubtype);

	return swtype;
};

string WznmWrsapiQtb::getQcoSwDefault(
			const string& qcotype
		) {
	if (qcotype == "String") return("\"\"");
	if (qcotype == "Bool") return("false");
	if (qcotype == "Double") return("0.0");

	return("0");
};
// IP cust --- IEND
