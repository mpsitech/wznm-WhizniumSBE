/**
	* \file WznmWrjapiQtb.cpp
	* Wznm operation processor - write Java API code for query table (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrjapiQtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrjapi;

/******************************************************************************
 namespace WznmWrjapiQtb
 ******************************************************************************/

DpchRetWznm* WznmWrjapiQtb::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrjapiQtb* dpchinv
		) {
	ubigint refWznmMTable = dpchinv->refWznmMTable;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	ListWznmMQuerycol qcos;

	string s;
	fstream jfile;

	if (dbswznm->tblwznmmtable->loadRecByRef(refWznmMTable, &tbl)) {
		// load table and query columns
		dbswznm->tblwznmmtablecol->loadRstByTbl(refWznmMTable, false, tcos);
		dbswznm->tblwznmmquerycol->loadRstByQry(tbl->refUref, false, qcos);

		// create files
		s = xchg->tmppath + "/" + folder + "/" + tbl->sref.substr(3) + ".java.ip";
		jfile.open(s.c_str(), ios::out);

		writeQtbJ(dbswznm, jfile, tbl, tcos, qcos);

		jfile.close();

		s = xchg->tmppath + "/" + folder + "/List" + tbl->sref.substr(3) + ".java.ip";
		jfile.open(s.c_str(), ios::out);

		writeLqtbJ(dbswznm, jfile, tbl, tcos, qcos);

		jfile.close();

		delete tbl;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrjapiQtb::writeQtbJ(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmMQuerycol& qcos
		) {
	WznmMQuerycol* qco = NULL;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;

	outfile << "\tpublic " << tbl->sref.substr(3) << "(" << endl;
	outfile << "\t\t\t\tint jnum" << endl;

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\t\t\t\t, " << getQcoTcoJType(qco, tcos) << " " << qco->sref << endl;
	};

	outfile << "\t\t\t) {" << endl;
	outfile << "\t\tthis.jnum = jnum;" << endl;

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\t\tthis." << qco->sref << " = " << qco->sref << ";" << endl;
	};
	outfile << "\t};" << endl;

	outfile << "// IP constructor --- IEND" << endl;

	// --- tcos
	outfile << "// IP tcos --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\tpublic " << getQcoTcoJType(qco, tcos) << " " << qco->sref << ";" << endl;
	};
	outfile << "// IP tcos --- IEND" << endl;

	// --- readXML.extract
	outfile << "// IP readXML.extract --- IBEGIN" << endl;
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << "\t\t\t" << qco->sref << " = Xmlio.extract" << getQcoTcoXMLType(qco, tcos) << "Uclc(doc, basexpath, \"" << qco->sref << "\", \"" << qco->Short << "\", null, 0);" << endl;
	};
	outfile << "// IP readXML.extract --- IEND" << endl;
};

void WznmWrjapiQtb::writeLqtbJ(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMTable* tbl
			, const ListWznmMTablecol& tcos
			, const ListWznmMQuerycol& qcos
		) {
	WznmMQuerycol* qco = NULL;

	// --- readXML.new
	outfile << "// IP readXML.new --- IBEGIN" << endl;
	outfile << "\t\t\t\trec = new " << tbl->sref.substr(3) << "(i+1";

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		if (qco->ixWOccurrence & VecWznmWMQuerycolOccurrence::XML) outfile << ", " << getJDefault(getQcoTcoJType(qco, tcos));
	};

	outfile << ");" << endl;
	outfile << "// IP readXML.new --- IEND" << endl;
};

string WznmWrjapiQtb::getTcoJType(
			const uint ixVBasetype
			, const uint ixVSubtype
		) {
	if (ixVBasetype == VecWznmVMTablecolBasetype::IDREF) return("long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::KLREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) return("long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::VECREF) return("int");
	if (ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) return("String");
	if (ixVBasetype == VecWznmVMTablecolBasetype::GRP) return("long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::OWN) return("long");
	if (ixVBasetype == VecWznmVMTablecolBasetype::ENUM) return("int");
	if (ixVBasetype == VecWznmVMTablecolBasetype::LVL) return("int");

	if (ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TINYINT) return("int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::UTINYINT) return("int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::SMALLINT) return("int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::USMALLINT) return("int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::INT) return("int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::UINT) return("int");
		if (ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) return("long");
		if (ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT) return("long");
		return("");
	};

	if (ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) return("double");
	if (ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) return("boolean");
	if (ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) return("String");

	if (ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
		if (ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) return("double");
		return("int");
	};

	if (ixVBasetype == VecWznmVMTablecolBasetype::EXPR) return("String");

	return("");
};

string WznmWrjapiQtb::getQcoJType(
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
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QIDREF) return("long");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QJREF) return("long");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::QJENUM) return("int");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::INTVAL) return("int");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::DBLVAL) return("double");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::BOOLVAL) return("boolean");
	if (ixVBasetype == VecWznmVMQuerycolBasetype::TXTVAL) return("String");

	return("");
};

string WznmWrjapiQtb::getQcoTcoJType(
			WznmMQuerycol* qco
			, const ListWznmMTablecol& tcos
		) {
	string jtype;

	jtype = getQcoJType(qco->ixVBasetype);
	if (jtype == "") for (unsigned int i = 0; i < tcos.nodes.size(); i++) if (tcos.nodes[i]->sref == qco->sref) jtype = getTcoJType(tcos.nodes[i]->ixVBasetype, tcos.nodes[i]->ixVSubtype);

	return jtype;
};

string WznmWrjapiQtb::getQcoTcoXMLType(
			WznmMQuerycol* qco
			, const ListWznmMTablecol& tcos
		) {
	string jtype = getQcoTcoJType(qco, tcos);

	if (jtype == "int") return("Integer");
	return(StrMod::cap(jtype));
};
// IP cust --- IEND


