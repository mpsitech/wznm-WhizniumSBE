/**
	* \file WznmWrsrvIex.cpp
	* Wznm operation processor - write C++ code for import/export complex (implementation)
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

#include "WznmWrsrvIex.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsrvIex
 ******************************************************************************/

DpchRetWznm* WznmWrsrvIex::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvIex* dpchinv
		) {
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refsLcl;
	ubigint refLcl;

	fstream hfile;
	fstream cppfile;

	WznmMJob* job = NULL;
	WznmMImpexpcplx* iex = NULL;

	string s;

	if (dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job)) {
		if (dbswznm->tblwznmmimpexpcplx->loadRecByRef(job->refUref, &iex)) {
			Wznm::getVerlclrefs(dbswznm, job->refWznmMVersion, refLcl, refsLcl);

			// IexXxxxYyy.h, IexXxxxYyy.cpp
			s = xchg->tmppath + "/" + folder + "/" + iex->sref + ".h.ip";
			hfile.open(s.c_str(), ios::out);
			s = xchg->tmppath + "/" + folder + "/" + iex->sref + ".cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writeIexH(dbswznm, hfile, job, iex, Prjshort);
			writeIexCpp(dbswznm, cppfile, job, iex, Prjshort, refLcl, refsLcl);

			hfile.close();
			cppfile.close();

			// JobXxxxIexYyy.h, JobXxxxIexYyy.cpp
			s = xchg->tmppath + "/" + folder + "/" + job->sref + ".h.ip";
			hfile.open(s.c_str(), ios::out);
			s = xchg->tmppath + "/" + folder + "/" + job->sref + ".cpp.ip";
			cppfile.open(s.c_str(), ios::out);

			writeIexjobH(dbswznm, hfile, job, iex, Prjshort);
			writeIexjobCpp(dbswznm, cppfile, job, iex, Prjshort);

			hfile.close();
			cppfile.close();

			delete iex;
		};

		delete job;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvIex::writeIexH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMImpexpcplx* iex
			, const string& Prjshort
		) {
	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	WznmMVector* vec = NULL;

	string prjshort = StrMod::lc(Prjshort);

	string s;

	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " AND supRefWznmMImpexp = 0 ORDER BY sref ASC", false, imes);

	// --- fsrs
	outfile << "// IP fsrs --- IBEGIN" << endl;
	outfile << "#define VecV" << iex->sref << "Ime " << iex->sref << "::VecVIme" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		writeIexH_imefsrsDef(dbswznm, outfile, job, iex, ime);
	};
	outfile << "// IP fsrs --- IEND" << endl;

	// --- blks
	outfile << "// IP blks --- IBEGIN" << endl;

	// single vector VecVIexWznmBuiIme
	if (dbswznm->tblwznmmvector->loadRecBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::IEX) + " AND hkUref = " + to_string(iex->ref)
				+ " AND sref = 'VecV" + iex->sref + "Ime'", &vec)) {

		writeVecH(dbswznm, Prjshort, outfile, vec, true, "VecVIme", 1);
		outfile << endl;

		delete vec;
	};

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		writeIexH_imeDecl(dbswznm, outfile, job, iex, ime, Prjshort);
	};
	outfile << "// IP blks --- IEND" << endl;

	// --- parseReadWrite
	outfile << "// IP parseReadWrite --- IBEGIN" << endl;

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		s += ", " + ime->sref + "& " + StrMod::lc(ime->sref);
	};

	outfile << "\tvoid parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath" << s << ");" << endl;
	outfile << "\tvoid exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags" << s << ");" << endl;
	outfile << endl;

	outfile << "\tvoid readTxt(Sbecore::Txtrd& txtrd" << s << ");" << endl;
	outfile << "\tvoid readXML(xmlXPathContext* docctx, std::string basexpath" << s << ");" << endl;
	outfile << endl;

	outfile << "\tvoid writeTxt(std::fstream& outfile" << s << ");" << endl;
	outfile << "\tvoid writeXML(xmlTextWriter* wr, const bool shorttags" << s << ");" << endl;

	outfile << "// IP parseReadWrite --- IEND" << endl;
};

void WznmWrsrvIex::writeIexH_imefsrsDef(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMImpexpcplx* iex
			, WznmMImpexp* ime
		) {
	ListWznmMImpexp subimes;
	WznmMImpexp* subime = NULL;

	WznmMVector* vec = NULL;

	// --- recursion over sub-ime's to make sure that order is maintained
	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY sref ASC", false, subimes);

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];
		writeIexH_imefsrsDef(dbswznm, outfile, job, iex, subime);
	};

	// --- this ime
	outfile << "#define ImeitemI" << iex->sref.substr(3) << ime->sref.substr(4) << " " << iex->sref << "::Imeitem" << ime->sref.substr(3) << endl;
	outfile << "#define ImeI" << iex->sref.substr(3) << ime->sref.substr(4) << " " << iex->sref << "::" << ime->sref << endl;

	// single vector VecWImeIWznmBuiJMModuleIel
	if (dbswznm->tblwznmmvector->loadRecBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::IME) + " AND hkUref = " + to_string(ime->ref)
				+ " AND sref = 'VecWImeI" + iex->sref.substr(3) + ime->sref.substr(4) + "Iel'", &vec)) {

		outfile << "#define " << vec->sref << " " << iex->sref << "::" << ime->sref << "::VecWIel" << endl;

		delete vec;
	};

	outfile << endl;
};

void WznmWrsrvIex::writeIexH_imeDecl(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMImpexpcplx* iex
			, WznmMImpexp* ime
			, const string& Prjshort
		) {
	ListWznmMImpexp subimes;
	WznmMImpexp* subime = NULL;

	set<uint> icsWIop;

	WznmMVector* vec = NULL;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;

	WznmMTable* tbl = NULL;
	WznmMTablecol* tco = NULL;

	bool first;

	string prjshort = StrMod::lc(Prjshort);

	// --- recursion over sub-ime's to make sure that order is maintained
	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY sref ASC", false, subimes);

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];
		writeIexH_imeDecl(dbswznm, outfile, job, iex, subime, Prjshort);
	};

	// --- this ime
	VecWznmWMImpexpIop::getIcs(ime->ixWIop, icsWIop);

	dbswznm->tblwznmmimpexpcol->loadRstBySQL("SELECT * FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY imeNum ASC", false, iels);

	dbswznm->tblwznmmtable->loadRecByRef(ime->refWznmMTable, &tbl);

	outfile << "\t/**" << endl;
	outfile << "\t\t* Imeitem" << ime->sref.substr(3) << " (full: ImeitemI" << iex->sref.substr(3) << ime->sref.substr(4) << ")" << endl;
	outfile << "\t\t*/" << endl;

	// constructor 1
	outfile << "\tclass Imeitem" << ime->sref.substr(3);
	if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) outfile << " : public " << tbl->sref.substr(3);
	outfile << " {" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tImeitem" << ime->sref.substr(3) << "(";
	first = true;
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
			if (first) first = false;
			else outfile << ", ";

			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
				outfile << "const Sbecore::uint ix" << Prjshort << "VIop = 0";
			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF)) {
				outfile << "const Sbecore::ubigint " << iel->sref << " = 0";
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
						outfile << "const Sbecore::uint " << iel->sref << " = 0";
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
						if (tco->ixVSubtype == VecWznmVMTablecolSubtype::INT) outfile << "const int " << iel->sref << " = 0";
						else outfile << "const Sbecore::" << VecWznmVMTablecolSubtype::getSref(tco->ixVSubtype) << " " << iel->sref << " = 0";
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
						outfile << "const double " << iel->sref << " = 0.0";
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
						outfile << "const bool " << iel->sref << " = false";
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
						if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) outfile << "const double " << iel->sref << " = 0.0";
						else outfile << "const Sbecore::uint " << iel->sref << " = 0";
					} else  { // IDSREF, KLREF, TBLSREF, TXTVAL, EXPR
						outfile << "const std::string& " << iel->sref << " = \"\"";
					};
					delete tco;
				};

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::FTM)) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					outfile << "const Sbecore::uint " << tco->sref << " = 0";
					delete tco;
				};
			} else { // TSREF, THSREF, THINT, IARG
				outfile << "const std::string& " << iel->sref << " = \"\"";
			};
		};
	};
	outfile << ");" << endl;

	// constructor 2
	outfile << "\t\tImeitem" << ime->sref.substr(3) << "(Dbs" << Prjshort << "* dbs" << prjshort;
	if (icsWIop.size() > 1) outfile << ", const Sbecore::uint ix" << Prjshort << "VIop";
	outfile << ", const Sbecore::ubigint ref);" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tSbecore::uint lineno;" << endl;
	outfile << "\t\tSbecore::uint ixWIelValid;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
			outfile << "\t\tSbecore::uint ix" << Prjshort << "VIop;" << endl;
			outfile << "\t\tstd::string srefIx" << Prjshort << "VIop;" << endl;
		} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) {
			outfile << "\t\tSbecore::ubigint " << iel->sref << ";" << endl;
			if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					outfile << "\t\tSbecore::ubigint " << tco->sref << ";" << endl;
					delete tco;
				};
			};
		} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF) {
			outfile << "\t\tSbecore::ubigint " << iel->sref << ";" << endl;
		} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
		} else { // TSREF, THSREF, THINT, VSREF, FTM, IARG
			outfile << "\t\tstd::string " << iel->sref << ";" << endl;
		};
	};
	outfile << endl;

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];
		outfile << "\t\t" << subime->sref << " " << StrMod::lc(subime->sref) << ";" << endl;
	};
	if (subimes.nodes.size() > 0) outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tvoid readTxt(Sbecore::Txtrd& txtrd);" << endl;
	outfile << "\t\tvoid readXML(xmlXPathContext* docctx, const std::string& basexpath);" << endl;
	outfile << endl;

	outfile << "\t\tvoid writeTxt(std::fstream& outfile);" << endl;
	outfile << "\t\tvoid writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\t/**" << endl;
	outfile << "\t\t* " << ime->sref << " (full: ImeI" << iex->sref.substr(3) << ime->sref.substr(4) << ")" << endl;
	outfile << "\t\t*/" << endl;
	outfile << "\tclass " << ime->sref << " {" << endl;
	outfile << endl;

	// single vector VecWImeIWznmBuiJMModuleIel
	if (dbswznm->tblwznmmvector->loadRecBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::IME) + " AND hkUref = " + to_string(ime->ref)
				+ " AND sref = 'VecWImeI" + iex->sref.substr(3) + ime->sref.substr(4) + "Iel'", &vec)) {

		outfile << "\tpublic:" << endl;
		writeVecH(dbswznm, Prjshort, outfile, vec, true, "VecWIel", 2);
		outfile << endl;

		delete vec;
	};

	outfile << "\tpublic:" << endl;
	outfile << "\t\t" << ime->sref << "();" << endl;
	outfile << "\t\t~" << ime->sref << "();" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tstd::vector<Imeitem" << ime->sref.substr(3) << "*> nodes;" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tvoid clear();" << endl;
	outfile << endl;

	outfile << "\t\tvoid readTxt(Sbecore::Txtrd& txtrd);" << endl;
	outfile << "\t\tvoid readXML(xmlXPathContext* docctx, std::string basexpath);" << endl;
	outfile << endl;

	outfile << "\t\tvoid writeTxt(std::fstream& outfile);" << endl;
	outfile << "\t\tvoid writeXML(xmlTextWriter* wr, const bool shorttags = true);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	delete tbl;
};

void WznmWrsrvIex::writeIexCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMImpexpcplx* iex
			, const string& Prjshort
			, const ubigint refLcl
			, vector<ubigint>& refsLcl
		) {
	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	set<uint> icsWIop;

	ListWznmMImpexp allimes;

	WznmMVector* vec = NULL;

	string s;

	bool first;

	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " AND supRefWznmMImpexp = 0 ORDER BY sref ASC", false, imes);

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		s += ", " + StrMod::lc(ime->sref);
	};

	dbswznm->tblwznmmimpexp->loadRstByIex(iex->ref, false, allimes);

	// --- blks
	outfile << "// IP blks --- IBEGIN" << endl;

	// single vector VecVIexWznmBuiIme
	if (dbswznm->tblwznmmvector->loadRecBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::IEX) + " AND hkUref = " + to_string(iex->ref)
				+ " AND sref = 'VecV" + iex->sref + "Ime'", &vec)) {

		writeVecCpp(dbswznm, Prjshort, outfile, vec, true, iex->sref, "VecVIme", refLcl, refsLcl);
		outfile << endl;

		delete vec;
	};

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		writeIexCpp_ime(dbswznm, outfile, job, iex, ime, Prjshort, refLcl, refsLcl);
	};
	outfile << "// IP blks --- IEND" << endl;

	// --- hdr.imesRoot
	outfile << "// IP hdr.imesRoot --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\t\t\t, " + ime->sref + "& " + StrMod::lc(ime->sref) << endl;
	};
	outfile << "// IP hdr.imesRoot --- IEND" << endl;

	// --- parseFromFile.readXML
	outfile << "// IP parseFromFile.readXML --- IBEGIN" << endl;
	outfile << "\t\t\treadXML(docctx, \"/\"" << s << ");" << endl;
	outfile << "// IP parseFromFile.readXML --- IEND" << endl;

	// --- parseFromFile.readTxt
	outfile << "// IP parseFromFile.readTxt --- IBEGIN" << endl;
	outfile << "\t\t\tTxtrd rd(fullpath, rectpath, \"" << iex->sref << "\", Version(\"" << iex->Minversion << "\"), VecVIme::getIx);" << endl;
	outfile << "\t\t\treadTxt(rd" << s << ");" << endl;
	outfile << "// IP parseFromFile.readTxt --- IEND" << endl;

	// --- exportToFile.writeXML
	outfile << "// IP exportToFile.writeXML --- IBEGIN" << endl;
	outfile << "\t\t\twriteXML(wr, shorttags" << s << ");" << endl;
	outfile << "// IP exportToFile.writeXML --- IEND" << endl;

	// --- exportToFile.writeTxt
	outfile << "// IP exportToFile.writeTxt --- IBEGIN" << endl;
	outfile << "\t\twriteTxt(txtfile" << s << ");" << endl;
	outfile << "// IP exportToFile.writeTxt --- IEND" << endl;

	// --- readTxt.header
	outfile << "// IP readTxt.header --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];

		outfile << "\t\t\t\t";
		if (i != 0) outfile << "else ";
		outfile << "if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::" << StrMod::uc(ime->sref) << ")) " << StrMod::lc(ime->sref) << ".readTxt(txtrd);" << endl;
	};

	outfile << "\t\t\t\t";
	if (imes.nodes.size() > 0) outfile << "else ";
	outfile << "throw SbeException(SbeException::TXTRD_TKNMISPL, {{\"tkn\",VecVIme::getSref(txtrd.ixVToken)}, {\"lineno\",to_string(txtrd.linecnt)}});" << endl;
	outfile << endl;
	outfile << "// IP readTxt.header --- IEND" << endl;

	// --- readXML.chkversion*
	if (iex->Minversion != "") outfile << "// IP readXML.chkversion --- AFFIRM" << endl;
	else outfile << "// IP readXML.chkversion --- REMOVE" << endl;

	// --- readXML.minversion
	if (iex->Minversion != "") {
		outfile << "// IP readXML.minversion --- IBEGIN" << endl;
		outfile << "\t\t\tif (Version(version) < Version(\"" << iex->Minversion << "\")) throw SbeException(SbeException::IEX_VERSION, {{\"version\",version},{\"minversion\",\"" << iex->Minversion << "\"}});" << endl;
		outfile << "// IP readXML.minversion --- IEND" << endl;
	};

	// --- readXML.subs
	outfile << "// IP readXML.subs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\t\t" << StrMod::lc(ime->sref) << ".readXML(docctx, basexpath);" << endl;
	};
	outfile << "// IP readXML.subs --- IEND" << endl;

	// --- readXML.reset
	outfile << "// IP readXML.reset --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\t\t" << StrMod::lc(ime->sref) << " = " << ime->sref << "();" << endl;
	};
	outfile << "// IP readXML.reset --- IEND" << endl;

	// --- writeTxt
	outfile << "// IP writeTxt --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\t" << StrMod::lc(ime->sref) << ".writeTxt(outfile);" << endl;
	};
	outfile << "// IP writeTxt --- IEND" << endl;

	// --- writeXML
	outfile << "// IP writeXML --- IBEGIN" << endl;
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\t\t" << StrMod::lc(ime->sref) << ".writeXML(wr, shorttags);" << endl;
	};
	outfile << "// IP writeXML --- IEND" << endl;

	// --- icsVIopInsAll
	outfile << "// IP icsVIopInsAll --- IBEGIN" << endl;
	outfile << "\treturn {";

	first = true;
	for (unsigned int i = 0; i < allimes.nodes.size(); i++) {
		ime = allimes.nodes[i];

		VecWznmWMImpexpIop::getIcs(ime->ixWIop, icsWIop);

		if (hasAny(icsWIop, {VecWznmWMImpexpIop::INS,VecWznmWMImpexpIop::RETRINS,VecWznmWMImpexpIop::RETRUPDINS})) {
			if (first) first = false;
			else outfile << ",";

			outfile << "{(uint)VecVIme::" << StrMod::uc(ime->sref) << ",Vec" << Prjshort << "VIop::";
			if (has(icsWIop, VecWznmWMImpexpIop::INS)) outfile << "INS";
			else if (has(icsWIop, VecWznmWMImpexpIop::RETRINS)) outfile << "RETRINS";
			else outfile << "RETRUPDINS";
			outfile << "}";
		};
	};

	outfile << "};" << endl;
	outfile << "// IP icsVIopInsAll --- IEND" << endl;
};

void WznmWrsrvIex::writeIexCpp_ime(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMImpexpcplx* iex
			, WznmMImpexp* ime
			, const string& Prjshort
			, const ubigint refLcl
			, vector<ubigint>& refsLcl
		) {
	ListWznmMImpexp subimes;
	WznmMImpexp* subime = NULL;

	set<uint> icsWIop;

	WznmMVector* vec = NULL;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;

	WznmMTable* tbl = NULL;
	WznmMTablecol* tco = NULL;

	unsigned int ix;

	bool first;

	string prjshort = StrMod::lc(Prjshort);

	// --- recursion over sub-ime's to make sure that order is maintained
	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY sref ASC", false, subimes);

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];
		writeIexCpp_ime(dbswznm, outfile, job, iex, subime, Prjshort, refLcl, refsLcl);
	};

	// --- this ime
	VecWznmWMImpexpIop::getIcs(ime->ixWIop, icsWIop);

	dbswznm->tblwznmmimpexpcol->loadRstBySQL("SELECT * FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY imeNum ASC", false, iels);

	dbswznm->tblwznmmtable->loadRecByRef(ime->refWznmMTable, &tbl);

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << iex->sref << "::Imeitem" << ime->sref.substr(3) << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	// - ime item

	// constructor 1
	outfile << iex->sref << "::Imeitem" << ime->sref.substr(3) << "::Imeitem" << ime->sref.substr(3) << "(" << endl;
	first = true;
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
			outfile << "\t\t\t";
			if (first) first = false;
			else outfile << ", ";

			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
				outfile << "const uint ix" << Prjshort << "VIop" << endl;
			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF)) {
				outfile << "const ubigint " << iel->sref << endl;
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
						outfile << "const uint " << iel->sref << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
						outfile << "const " << VecWznmVMTablecolSubtype::getSref(tco->ixVSubtype) << " " << iel->sref << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
						outfile << "const double " << iel->sref << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
						outfile << "const bool " << iel->sref << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
						if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) outfile << "const double " << iel->sref << endl;
						else outfile << "const uint " << iel->sref << endl;
					} else  { // IDSREF, KLREF, TBLSREF, TXTVAL, EXPR
						outfile << "const string& " << iel->sref << endl;
					};
					delete tco;
				};

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::FTM)) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					outfile << "const uint " << tco->sref << endl;
					delete tco;
				};
			} else { // TSREF, THSREF, THINT, IARG
				outfile << "const string& " << iel->sref << endl;
			};
		};
	};
	outfile << "\t\t)";
	if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) outfile << " : " << tbl->sref.substr(3) << "()";
	outfile << " {" << endl;

	outfile << "\tlineno = 0;" << endl;
	outfile << "\tixWIelValid = 0;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
				outfile << "\tthis->ix" << Prjshort << "VIop = ix" << Prjshort << "VIop;" << endl;

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::FTM)) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					outfile << "\tthis->" << tco->sref << " = " << tco->sref << ";" << endl;
					delete tco;
				};
			} else {
				outfile << "\tthis->" << iel->sref << " = " << iel->sref << ";" << endl;
			};
		};
	};

	outfile << "};" << endl;
	outfile << endl;

	// constructor 2
	outfile << iex->sref << "::Imeitem" << ime->sref.substr(3) << "::Imeitem" << ime->sref.substr(3) << "(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	if (icsWIop.size() > 1) outfile << "\t\t\t, const uint ix" << Prjshort << "VIop" << endl;
	outfile << "\t\t\t, const ubigint ref" << endl;
	outfile << "\t\t) :" << endl;
	outfile << "\t\t\tImeitem" << ime->sref.substr(3) << "(";
	if (icsWIop.size() > 1) outfile << "ix" << Prjshort << "VIop";
	outfile << ")" << endl;
	outfile << "\t\t{" << endl;

	if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) {
		outfile << "\t" << tbl->sref.substr(3) << "* rec = NULL;" << endl;
		outfile << endl;

		outfile << "\tthis->ref = ref;" << endl;
		outfile << endl;

		outfile << "\tif (dbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRecByRef(ref, &rec)) {" << endl;

		for (unsigned int i = 0; i < iels.nodes.size(); i++) {
			iel = iels.nodes[i];

			if (iel->refWznmMTablecol != 0) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVBasetype != VecWznmVMTablecolBasetype::IDREF) outfile << "\t\t" << tco->sref << " = rec->" << tco->sref << ";" << endl;
					delete tco;
				};
			};
		};

		outfile << endl;
		outfile << "\t\tdelete rec;" << endl;
		outfile << "\t};" << endl;
	};

	outfile << "};" << endl;
	outfile << endl;
	// readTxt
	outfile << "void " << iex->sref << "::Imeitem" << ime->sref.substr(3) << "::readTxt(" << endl;
	outfile << "\t\t\tTxtrd& txtrd" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tlineno = txtrd.linecnt;" << endl;
	outfile << endl;

	ix = 0;
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
			outfile << "\tif (txtrd.fields.size() > " << ix << ") {";

			if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF)) {
				outfile << iel->sref << " = atoll(txtrd.fields[" << ix << "].c_str());";

			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
						outfile << iel->sref << " = atol(txtrd.fields[" << ix << "].c_str());";
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
						if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::INT) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::UINT)) {
							outfile << iel->sref << " = atol(txtrd.fields[" << ix << "].c_str());";
						} else if ((tco->ixVSubtype == VecWznmVMTablecolSubtype::BIGINT) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::UBIGINT)) {
							outfile << iel->sref << " = atoll(txtrd.fields[" << ix << "].c_str());";
						} else {
							// TINYINT, UTINYINT, SMALLINT, USMALLINT
							outfile << iel->sref << " = atoi(txtrd.fields[" << ix << "].c_str());";
						};
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
						outfile << iel->sref << " = atof(txtrd.fields[" << ix << "].c_str());";
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
						outfile << iel->sref << " = (txtrd.fields[" << ix << "] == \"true\");";
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
						if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) {
							outfile << iel->sref << " = atof(txtrd.fields[" << ix << "].c_str());";
						} else {
							outfile << iel->sref << " = atol(txtrd.fields[" << ix << "].c_str());";
						};
					} else { // IDSREF, KLREF, TBLSREF, TXTVAL, EXPR
						outfile << iel->sref << " = txtrd.fields[" << ix << "];";
					};
					delete tco;
				};

			} else { // IOP, TSREF, THSREF, THINT, VSREF, FTM, IARG
				outfile << "" << iel->sref << " = txtrd.fields[" << ix << "];";
			};

			outfile << " ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) << ";};" << endl;
			ix++;
		};
	};
	outfile << endl;

	outfile << "\twhile (txtrd.readLine()) {" << endl;
	outfile << "\t\tswitch (txtrd.ixVLinetype) {" << endl;
	outfile << "\t\t\tcase Txtrd::VecVLinetype::HEADER:" << endl;

	if (subimes.nodes.size() > 0) {
		for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
			subime = subimes.nodes[i];

			outfile << "\t\t\t\t";
			if (i != 0) outfile << "} else ";

			outfile << "if ((txtrd.il == " << subime->supLvl << ") && (txtrd.ixVToken == VecVIme::" << StrMod::uc(subime->sref) << ")) {" << endl;
			outfile << "\t\t\t\t\t" << StrMod::lc(subime->sref) << ".readTxt(txtrd);" << endl;
			outfile << "\t\t\t\t\tcontinue;" << endl;
			outfile << endl;
		};

		outfile << "\t\t\t\t} else {" << endl;
		outfile << "\t\t\t\t\ttxtrd.skip = true;" << endl;
		outfile << "\t\t\t\t\treturn;" << endl;
		outfile << "\t\t\t\t};" << endl;
		outfile << endl;
	};

	outfile << "\t\t\tcase Txtrd::VecVLinetype::DATA:" << endl;
	outfile << "\t\t\tcase Txtrd::VecVLinetype::FOOTER:" << endl;
	outfile << "\t\t\t\ttxtrd.skip = true;" << endl;
	outfile << "\t\t\t\treturn;" << endl;
	outfile << endl;

	outfile << "\t\t\tcase Txtrd::VecVLinetype::COMMENT:" << endl;
	outfile << "\t\t\t\tcontinue;" << endl;
	outfile << endl;

	outfile << "\t\t\tdefault:" << endl;
	outfile << "\t\t\t\tthrow SbeException(SbeException::TXTRD_CONTENT, {{\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(lineno)}});" << endl;

	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// readXML
	outfile << "void " << iex->sref << "::Imeitem" << ime->sref.substr(3) << "::readXML(" << endl;
	outfile << "\t\t\txmlXPathContext* docctx" << endl;
	outfile << "\t\t\t, const string& basexpath" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tif (checkXPath(docctx, basexpath, lineno)) {" << endl;

	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
				outfile << "\t\tif (extractStringUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF)) {
				outfile << "\t\tif (extractUbigintUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
						outfile << "\t\tif (extractUintUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
						outfile << "\t\tif (extract" << StrMod::cap(VecWznmVMTablecolSubtype::getSref(tco->ixVSubtype)) << "Uclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
						outfile << "\t\tif (extractDoubleUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
						outfile << "\t\tif (extractBoolUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
						if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) {
							outfile << "\t\tif (extractDoubleUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
						} else {
							outfile << "\t\tif (extractUintUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
						};
					} else { // IDSREF, KLREF, TBLSREF, TXTVAL, EXPR
						outfile << "\t\tif (extractStringUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
					};
					delete tco;
				};
			} else { // TSREF, THSREF, THINT, VSREF, FTM, IARG
				outfile << "\t\tif (extractStringUclc(docctx, basexpath, \"" << iel->sref << "\", \"" << iel->Short << "\", " << iel->sref << ")) ixWIelValid += " << ime->sref << "::VecWIel::" << StrMod::uc(iel->sref) <<  ";" << endl;
			};
		};
	};

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];
		outfile << "\t\t" << StrMod::lc(subime->sref) << ".readXML(docctx, basexpath);" << endl;
	};

	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// writeTxt
	outfile << "void " << iex->sref << "::Imeitem" << ime->sref.substr(3) << "::writeTxt(" << endl;
	outfile << "\t\t\tfstream& outfile" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\toutfile";

	if (ime->supLvl > 0) {
		outfile << " << \"";
		for (unsigned int i = 0; i < ime->supLvl; i++) outfile << "\\t";
		outfile << "\"";
	};

	first = true;
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
			if (first) first = false;
			else outfile << " << \"\\t\"";

			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
				outfile << " << Vec" << Prjshort << "VIop::getSref(ix" << Prjshort << "VIop)";
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
						outfile << " << StrMod::boolToString(" << iel->sref << ")";
					} else { // ENUM, INTVAL, DBLVAL, TIMEVAL, IDSREF, KLREF, TBLSREF, TXTVAL, EXPR
						outfile << " << " << iel->sref;
					};
					delete tco;
				};
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
						if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) outfile << " << " << vec->sref << "::getSref(" << tco->sref << ")";
						else outfile << " << " << vec->sref << "::getSrefs(" << tco->sref << ")";

						delete vec;
					};
					delete tco;
				};
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::FTM) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) {
						outfile << " << Ftm::stamp(" << tco->sref << ")" << endl;
					} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) {
						outfile << " << Ftm::date(" << tco->sref << ")" << endl;
					} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) {
						outfile << " << Ftm::time(" << tco->sref << ")" << endl;
					};
					delete tco;
				};
			} else { // IDIREF, IREF, TSREF, THSREF, IARG
				outfile << " << " << iel->sref;
			};
		};
	};

	if (first) outfile << " << \"^\"";

	outfile << " << endl;" << endl;

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];
		outfile << "\t" << StrMod::lc(subime->sref) << ".writeTxt(outfile);" << endl;
	};

	outfile << "};" << endl;
	outfile << endl;

	// writeXML
	outfile << "void " << iex->sref << "::Imeitem" << ime->sref.substr(3) << "::writeXML(" << endl;
	outfile << "\t\t\txmlTextWriter* wr" << endl;
	outfile << "\t\t\t, const uint num" << endl;
	outfile << "\t\t\t, const bool shorttags" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tvector<string> tags;" << endl;
	outfile << "\tif (shorttags) tags = {\"Ii\"";
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];
		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) outfile << ",\"" << iel->Short << "\"";
	};
	outfile << "};" << endl;
	outfile << "\telse tags = {\"Imeitem" << ime->sref.substr(3) << "\"";
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];
		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) outfile << ",\"" << iel->sref << "\"";
	};
	outfile << "};" << endl;
	outfile << endl;

	outfile << "\txmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());" << endl;
	outfile << "\t\txmlTextWriterWriteAttribute(wr, BAD_CAST \"num\", BAD_CAST to_string(num).c_str());" << endl;

	ix = 1;
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
				outfile << "\t\twriteString(wr, tags[" << ix << "], Vec" << Prjshort << "VIop::getSref(ix" << Prjshort << "VIop));" << endl;
			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF)) {
				outfile << "\t\twriteUbigint(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVBasetype == VecWznmVMTablecolBasetype::ENUM) {
						outfile << "\t\twriteUint(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
						outfile << "\t\twrite" << StrMod::cap(VecWznmVMTablecolSubtype::getSref(tco->ixVSubtype)) << "(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
						outfile << "\t\twriteDouble(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
						outfile << "\t\twriteBool(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
						if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) outfile << "\t\twriteDouble(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
						else outfile << "\t\twriteUint(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
					} else { // IDSREF, KLREF, TBLSREF, TXTVAL, EXPR
						outfile << "\t\twriteString(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
					};
					delete tco;
				};
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
						if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) outfile << "\t\twriteString(wr, tags[" << ix << "], " << vec->sref << "::getSref(" << tco->sref << "));" << endl;
						else outfile << "\t\twriteString(wr, tags[" << ix << "], " << vec->sref << "::getSrefs(" << tco->sref << "));" << endl;

						delete vec;
					};
					delete tco;
				};
			} else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::FTM) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) {
						outfile << "\t\twriteString(wr, tags[" << ix << "], Ftm::stamp(" << tco->sref << "));" << endl;
					} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) {
						outfile << "\t\twriteString(wr, tags[" << ix << "], Ftm::date(" << tco->sref << "));" << endl;
					} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) {
						outfile << "\t\twriteString(wr, tags[" << ix << "], Ftm::time(" << tco->sref << "));" << endl;
					};
					delete tco;
				};
			} else { // IDIREF, IREF, TSREF, THSREF, IARG
				outfile << "\t\twriteString(wr, tags[" << ix << "], " << iel->sref << ");" << endl;
			};

			ix++;
		};
	};

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];
		outfile << "\t\t" << StrMod::lc(subime->sref) << ".writeXML(wr, shorttags);" << endl;
	};

	outfile << "\txmlTextWriterEndElement(wr);" << endl;

	outfile << "};" << endl;
	outfile << endl;

	// - ime VecWIel
	if (dbswznm->tblwznmmvector->loadRecBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::IME) + " AND hkUref = " + to_string(ime->ref)
				+ " AND sref = 'VecWImeI" + iex->sref.substr(3) + ime->sref.substr(4) + "Iel'", &vec)) {

		writeVecCpp(dbswznm, Prjshort, outfile, vec, true, iex->sref + "::" + ime->sref, "VecWIel", refLcl, refsLcl);

		outfile << endl;

		delete vec;
	};

	// - ime

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << iex->sref << "::" << ime->sref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	// constructor
	outfile << iex->sref << "::" << ime->sref << "::" << ime->sref << "() {" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// destructor
	outfile << iex->sref << "::" << ime->sref << "::~" << ime->sref << "() {" << endl;
	outfile << "\tclear();" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// clear
	outfile << "void " << iex->sref << "::" << ime->sref << "::clear() {" << endl;
	outfile << "\tfor (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];" << endl;
	outfile << "\tnodes.resize(0);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// readTxt
	outfile << "void " << iex->sref << "::" << ime->sref << "::readTxt(" << endl;
	outfile << "\t\t\tTxtrd& txtrd" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\t" << iex->sref << "::Imeitem" << ime->sref.substr(3) << "* ii = NULL;" << endl;
	outfile << endl;

	outfile << "\tclear();" << endl;
	outfile << endl;

	outfile << "\twhile (txtrd.readLine()) {" << endl;
	outfile << "\t\tswitch (txtrd.ixVLinetype) {" << endl;

	outfile << "\t\t\tcase Txtrd::VecVLinetype::DATA:" << endl;
	outfile << "\t\t\t\tif (txtrd.il == " << ime->supLvl << ") {" << endl;
	outfile << "\t\t\t\t\tii = new " << iex->sref << "::Imeitem" << ime->sref.substr(3) << "();" << endl;
	outfile << "\t\t\t\t\tnodes.push_back(ii);" << endl;
	outfile << endl;

	outfile << "\t\t\t\t\tii->readTxt(txtrd);" << endl;
	outfile << endl;

	outfile << "\t\t\t\t\tbreak;" << endl;
	outfile << endl;

	if (ime->supLvl > 0) {
		outfile << "\t\t\t\t} else if (txtrd.il < " << ime->supLvl << ") {" << endl;
		outfile << "\t\t\t\t\tthrow SbeException(SbeException::TXTRD_ENDTKN, {{\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(txtrd.linecnt)}});" << endl;
		outfile << endl;
	};

	outfile << "\t\t\t\t} else throw SbeException(SbeException::TXTRD_CONTENT, {{\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(txtrd.linecnt)}});" << endl;
	outfile << endl;

	outfile << "\t\t\tcase Txtrd::VecVLinetype::FOOTER:" << endl;
	outfile << "\t\t\t\tif (txtrd.ixVToken == VecVIme::" << StrMod::uc(ime->sref) << ") return;" << endl;
	outfile << "\t\t\t\telse throw SbeException(SbeException::TXTRD_TKNMISPL, {{\"tkn\",VecVIme::getSref(txtrd.ixVToken)}, {\"lineno\",to_string(txtrd.linecnt)}});" << endl;
	outfile << endl;

	outfile << "\t\t\tcase Txtrd::VecVLinetype::COMMENT:" << endl;
	outfile << "\t\t\t\tcontinue;" << endl;
	outfile << endl;

	outfile << "\t\t\tdefault:" << endl;
	outfile << "\t\t\t\tthrow SbeException(SbeException::TXTRD_ENDTKN, {{\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(txtrd.linecnt)}});" << endl;

	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(txtrd.linecnt)}});" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// readXML
	outfile << "void " << iex->sref << "::" << ime->sref << "::readXML(" << endl;
	outfile << "\t\t\txmlXPathContext* docctx" << endl;
	outfile << "\t\t\t, string basexpath" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tvector<unsigned int> nums;" << endl;
	outfile << "\tvector<bool> _shorttags;" << endl;
	outfile << endl;

	outfile << "\t" << iex->sref << "::Imeitem" << ime->sref.substr(3) << "* ii = NULL;" << endl;
	outfile << endl;

	outfile << "\tbool basefound;" << endl;
	outfile << endl;

	outfile << "\tstring s;" << endl;
	outfile << endl;

	outfile << "\tbasefound = checkUclcXPaths(docctx, basexpath, basexpath, \"" << ime->sref << "\");" << endl;
	outfile << endl;

	outfile << "\tclear();" << endl;
	outfile << endl;

	outfile << "\tif (basefound) {" << endl;
	outfile << "\t\textractList(docctx, basexpath, \"Imeitem" << ime->sref.substr(3) << "\", \"Ii\", \"num\", nums, _shorttags);" << endl;
	outfile << endl;

	outfile << "\t\tfor (unsigned int i = 0; i < nums.size(); i++) {" << endl;
	outfile << "\t\t\ts = basexpath + \"/\";" << endl;
	outfile << "\t\t\tif (_shorttags[i]) s += \"Ii\"; else s += \"Imeitem" << ime->sref.substr(3) << "\";" << endl;
	outfile << "\t\t\ts += \"[@num='\" + to_string(nums[i]) + \"']\";" << endl;
	outfile << endl;

	outfile << "\t\t\tii = new " << iex->sref << "::Imeitem" << ime->sref.substr(3) << "();" << endl;
	outfile << "\t\t\tii->readXML(docctx, s);" << endl;
	outfile << "\t\t\tnodes.push_back(ii);" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// writeTxt
	outfile << "void " << iex->sref << "::" << ime->sref << "::writeTxt(" << endl;
	outfile << "\t\t\tfstream& outfile" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (nodes.size() > 0) {" << endl;

	outfile << "\t\toutfile << \"";
	for (unsigned int i = 0; i < ime->supLvl; i++) outfile << "\\t";
	outfile << ime->sref << ".";
	
	if (iels.nodes.size() > 0) {
		outfile << "\" << StrMod::replaceChar(" << ime->sref << "::VecWIel::getSrefs(";

		ix = 1;
		for (unsigned int i = 0; i < iels.nodes.size(); i++) if (iels.nodes[i]->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) ix *= 2;
		outfile << (ix-1);

		outfile << "), ';', '\\t') << endl;" << endl;

	} else {
		outfile << "item\" << endl;" << endl;
	};

	outfile << "\t\tfor (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);" << endl;

	outfile << "\t\toutfile << \"";
	for (unsigned int i = 0; i < ime->supLvl; i++) outfile << "\\t";
	outfile << ime->sref << ".end\" << endl;" << endl;

	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// writeXML
	outfile << "void " << iex->sref << "::" << ime->sref << "::writeXML(" << endl;
	outfile << "\t\t\txmlTextWriter* wr" << endl;
	outfile << "\t\t\t, const bool shorttags" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (nodes.size() > 0) {" << endl;
	outfile << "\t\txmlTextWriterStartElement(wr, BAD_CAST \"" << ime->sref << "\");" << endl;
	outfile << "\t\t\tfor (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);" << endl;
	outfile << "\t\txmlTextWriterEndElement(wr);" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	delete tbl;
};

void WznmWrsrvIex::writeIexjobH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMImpexpcplx* iex
			, const string& Prjshort
		) {
	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " AND supRefWznmMImpexp = 0 ORDER BY sref ASC", false, imes);

	string prjshort = StrMod::lc(Prjshort);

	// --- include.spec
	outfile << "// IP include.spec --- IBEGIN" << endl;
	outfile << "#include \"" << iex->sref << ".h\"" << endl;
	outfile << "// IP include.spec --- IEND" << endl;

	// --- specVar
	outfile << "// IP vars.spec --- IBEGIN" << endl;
	outfile << "\tstd::string fullpath;" << endl;
	outfile << "\tbool xmlNotTxt;" << endl;
	outfile << "\tstd::string rectpath;" << endl;
	outfile << endl;

	outfile << "\tSbecore::uint lineno;" << endl;
	outfile << "\tSbecore::uint impcnt;" << endl;
	outfile << endl;

	outfile << "\tstd::map<Sbecore::uint,Sbecore::uint> ics" << Prjshort << "VIop;" << endl;
	outfile << endl;

	outfile << "\tbool shorttags;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\t" << iex->sref << "::" << ime->sref << " " << StrMod::lc(ime->sref) << ";" << endl;
	};
	outfile << "// IP vars.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tvoid reset(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << endl;

	outfile << "\tvoid parseFromFile(Dbs" << Prjshort << "* dbs" << prjshort << ", const std::string& _fullpath, const bool _xmlNotTxt, const std::string& _rectpath = \"\");" << endl;
	outfile << "\tvoid import(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << "\tvoid reverse(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << "\tvoid collect(Dbs" << Prjshort << "* dbs" << prjshort << ", const std::map<Sbecore::uint,Sbecore::uint>& _ics" << Prjshort << "VIop = " << iex->sref << "::ics" << Prjshort << "VIopInsAll());" << endl;
	outfile << "\tvoid exportToFile(Dbs" << Prjshort << "* dbs" << prjshort << ", const std::string& _fullpath, const bool _xmlNotTxt, const bool _shorttags = true);" << endl;
	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvIex::writeIexjobCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMImpexpcplx* iex
			, const string& Prjshort
		) {
	set<uint> icsWIop;

	ListWznmMImpexp topimes;
	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	ListWznmMImpexpcol iels;

	uint ixVBasetype;

	uint supLvl;
	uint cnt;

	bool first;

	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " AND supRefWznmMImpexp = 0 ORDER BY sref ASC", false, topimes);
	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " ORDER BY supLvl ASC, sref ASC", false, imes);

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	// --- ns.spec
	outfile << "// IP ns.spec --- IBEGIN" << endl;
	outfile << "using namespace " << iex->sref << ";" << endl;
	outfile << "// IP ns.spec --- IEND" << endl;

	// --- constructor.spec1
	outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
	outfile << "// IP constructor.spec1 --- IEND" << endl;

	// --- constructor.spec2
	outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
	outfile << "\tchangeStage(dbs" << prjshort << ", VecVSge::IDLE);" << endl;
	outfile << "// IP constructor.spec2 --- IEND" << endl;

	// --- constructor.spec3
	outfile << "// IP constructor.spec3 --- IBEGIN" << endl;
	outfile << "// IP constructor.spec3 --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	// -- reset
	outfile << "void " << job->sref << "::reset(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (ixVSge != VecVSge::IDLE) changeStage(dbs" << prjshort << ", VecVSge::IDLE);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- parseFromFile
	outfile << "void " << job->sref << "::parseFromFile(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const string& _fullpath" << endl;
	outfile << "\t\t\t, const bool _xmlNotTxt" << endl;
	outfile << "\t\t\t, const string& _rectpath" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (ixVSge == VecVSge::IDLE) {" << endl;
	outfile << "\t\tfullpath = _fullpath;" << endl;
	outfile << "\t\txmlNotTxt = _xmlNotTxt;" << endl;
	outfile << "\t\trectpath = _rectpath;" << endl;
	outfile << endl;

	outfile << "\t\tchangeStage(dbs" << prjshort << ", VecVSge::PARSE);" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- import
	outfile << "void " << job->sref << "::import(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (ixVSge == VecVSge::PRSDONE) changeStage(dbs" << prjshort << ", VecVSge::IMPORT);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- reverse
	outfile << "void " << job->sref << "::reverse(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (ixVSge == VecVSge::IMPERR) changeStage(dbs" << prjshort << ", VecVSge::REVERSE);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- collect
	outfile << "void " << job->sref << "::collect(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const map<uint,uint>& _ics" << Prjshort << "VIop" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (ixVSge == VecVSge::IDLE) {" << endl;
	outfile << "\t\tics" << Prjshort << "VIop = _ics" << Prjshort << "VIop;" << endl;
	outfile << "\t\tchangeStage(dbs" << prjshort << ", VecVSge::COLLECT);" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- exportToFile
	outfile << "void " << job->sref << "::exportToFile(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const string& _fullpath" << endl;
	outfile << "\t\t\t, const bool _xmlNotTxt" << endl;
	outfile << "\t\t\t, const bool _shorttags" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::CLTDONE)) {" << endl;
	outfile << "\t\tfullpath = _fullpath;" << endl;
	outfile << "\t\txmlNotTxt = _xmlNotTxt;" << endl;
	outfile << "\t\tshorttags = _shorttags;" << endl;
	outfile << endl;

	outfile << "\t\tchangeStage(dbs" << prjshort << ", VecVSge::EXPORT);" << endl;
	outfile << "\t};" << endl;
	outfile << "};" << endl;
	outfile << endl;

	outfile << "// IP spec --- IEND" << endl;

	// --- enterSgeIdle
	outfile << "// IP enterSgeIdle --- IBEGIN" << endl;
	outfile << "\tfullpath = \"\";" << endl;
	outfile << "\txmlNotTxt = false;" << endl;
	outfile << "\trectpath = \"\";" << endl;
	outfile << endl;

	outfile << "\tlineno = 0;" << endl;
	outfile << "\timpcnt = 0;" << endl;
	outfile << endl;

	outfile << "\tics" << Prjshort << "VIop.clear();" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < topimes.nodes.size(); i++) {
		ime = topimes.nodes[i];
		outfile << "\t" << StrMod::lc(ime->sref) << ".clear();" << endl;
	};
	outfile << "// IP enterSgeIdle --- IEND" << endl;

	// --- enterSgeParse
	outfile << "// IP enterSgeParse --- IBEGIN" << endl;

	outfile << "\ttry {" << endl;
	outfile << "\t\t" << iex->sref << "::parseFromFile(fullpath, xmlNotTxt, rectpath";
	for (unsigned int i = 0; i < topimes.nodes.size(); i++) {
		ime = topimes.nodes[i];
		outfile << ", " << StrMod::lc(ime->sref);
	};
	outfile << ");" << endl;
	outfile << endl;

	outfile << "\t} catch (SbeException& e) {" << endl;
	outfile << "\t\tif (e.ix == SbeException::PATHNF) e.vals[\"path\"] = \"<hidden>\";" << endl;
	outfile << "\t\tlasterror = e.getSquawk(Vec" << Prjshort << "VError::getIx, Vec" << Prjshort << "VError::getTitle, ix" << Prjshort << "VLocale);" << endl;
	outfile << endl;

	outfile << "\t\tretval = nextIxVSgeFailure;" << endl;
	outfile << "\t};" << endl;
	outfile << "// IP enterSgeParse --- IEND" << endl;

	// --- enterSgeImport
	outfile << "// IP enterSgeImport --- IBEGIN" << endl;

	// imes
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\tImeitem" << ime->sref.substr(3) << "* " << writeIexjobCpp_getImeshort(dbswznm, ime) << " = NULL;" << endl;
	};
	outfile << endl;

	// idirefs
	supLvl = (0-1);
	first = true;

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];

		if (ime->supLvl != supLvl) {
			dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(ime->ref) + " AND ixVBasetype = " + to_string(VecWznmVMImpexpcolBasetype::IDIREF), cnt);

			if (cnt > 0) {
				if (first) {
					outfile << "\tset<ubigint> irefs";
					first = false;

				} else {
					outfile << ", irefs";
				};

				outfile << ime->supLvl;
				supLvl = ime->supLvl;
			};
		};
	};

	if (!first) {
		outfile << ";" << endl;
		outfile << endl;
	};

	// nums
	supLvl = (0-1);
	first = true;

	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];

		if (ime->supLvl != supLvl) {
			dbswznm->loadUintBySQL("SELECT COUNT(TblWznmMImpexpcol.ref) FROM TblWznmMImpexpcol, TblWznmMTablecol WHERE TblWznmMTablecol.ref = TblWznmMImpexpcol.refWznmMTablecol AND TblWznmMImpexpcol.imeRefWznmMImpexp = " + to_string(ime->ref)
						+ " AND TblWznmMTablecol.ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::ENUM) + " AND TblWznmMImpexpcol.ixVConvtype <> " + to_string(VecWznmVMImpexpcolConvtype::VOID), cnt);

			if (cnt > 0) {
				if (first) {
					outfile << "\tuint num";
					first = false;

				} else {
					outfile << ", num";
				};

				outfile << ime->supLvl;
				supLvl = ime->supLvl;
			};
		};
	};

	if (!first) {
		outfile << ";" << endl;
		outfile << endl;
	};


	outfile << "\t// IP enterSgeImport.prep --- INSERT" << endl;
	outfile << endl;

	// enterSgeImport.traverse
	outfile << "\ttry {" << endl;
	outfile << "\t\t// IP enterSgeImport.traverse --- BEGIN" << endl;

	for (unsigned int i = 0; i < topimes.nodes.size(); i++) {
		ime = topimes.nodes[i];

		outfile << endl;
		outfile << "\t\t// -- " << ime->sref << endl;

		writeIexjobCpp_imptraverse(dbswznm, outfile, iex, NULL, NULL, iels, ime, Prjshort);
	};

	outfile << "\t\t// IP enterSgeImport.traverse --- END" << endl;
	outfile << endl;

	outfile << "\t\t// IP enterSgeImport.ppr --- INSERT" << endl;
	outfile << "\t} catch (SbeException& e) {" << endl;
	outfile << "\t\tlasterror = e.getSquawk(Vec" << Prjshort << "VError::getIx, Vec" << Prjshort << "VError::getTitle, ix" << Prjshort << "VLocale);" << endl;
	outfile << "\t\tretval = nextIxVSgeFailure;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "// IP enterSgeImport --- IEND" << endl;

	// --- enterSgeReverse
	outfile << "// IP enterSgeReverse --- IBEGIN" << endl;

	// imes
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];

		dbswznm->loadUintBySQL("SELECT ixVBasetype FROM TblWznmMTable WHERE ref = " + to_string(ime->refWznmMTable), ixVBasetype);
		if (ixVBasetype != VecWznmVMTableBasetype::CLUST) outfile << "\tImeitem" << ime->sref.substr(3) << "* " << writeIexjobCpp_getImeshort(dbswznm, ime) << " = NULL;" << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < topimes.nodes.size(); i++) {
		ime = topimes.nodes[i];

		outfile << endl;
		outfile << "\t// -- " << ime->sref << endl;

		writeIexjobCpp_rvrtraverse(dbswznm, outfile, iex, ime, NULL, Prjshort);
	};

	outfile << "// IP enterSgeReverse --- IEND" << endl;

	// --- enterSgeCollect
	outfile << "// IP enterSgeCollect --- IBEGIN" << endl;

	// imes
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];
		outfile << "\tImeitem" << ime->sref.substr(3) << "* " << writeIexjobCpp_getImeshort(dbswznm, ime) << " = NULL;" << endl;
	};
	outfile << endl;

	outfile << "\tuint ix" << Prjshort << "VIop;" << endl;
	outfile << endl;

	outfile << "\tvector<ubigint> refs;" << endl;
	outfile << endl;

	outfile << "\tStcch* stcch = new Stcch(false);" << endl;
	outfile << endl;

	// enterSgeCollect.traverse
	outfile << "\t// IP enterSgeCollect.traverse --- BEGIN" << endl;

	for (unsigned int i = 0; i < topimes.nodes.size(); i++) {
		ime = topimes.nodes[i];

		outfile << endl;
		outfile << "\t// -- " << ime->sref << endl;

		writeIexjobCpp_coltraverse(dbswznm, outfile, iex, NULL, ime, Prjshort);
	};

	outfile << "\t// IP enterSgeCollect.traverse --- END" << endl;

	// enterSgeCollect.ppr
	outfile << "\t// IP enterSgeCollect.ppr --- INSERT" << endl;
	outfile << endl;

	outfile << "\tdelete stcch;" << endl;
	outfile << endl;

	outfile << "// IP enterSgeCollect --- IEND" << endl;

	// --- enterSgeExport
	outfile << "// IP enterSgeExport --- IBEGIN" << endl;

	outfile << "\t" << iex->sref << "::exportToFile(fullpath, xmlNotTxt, shorttags";
	for (unsigned int i = 0; i < topimes.nodes.size(); i++) {
		ime = topimes.nodes[i];
		outfile << ", " << StrMod::lc(ime->sref);
	};
	outfile << ");" << endl;

	outfile << "// IP enterSgeExport --- IEND" << endl;
};

string WznmWrsrvIex::writeIexjobCpp_getImeshort(
			DbsWznm* dbswznm
			, WznmMImpexp* ime
		) {
	string retval;

	dbswznm->loadStringBySQL("SELECT Short FROM TblWznmMTable WHERE ref = " + to_string(ime->refWznmMTable), retval);

	if ((ime->sref[ime->sref.length()-1] >= '0') && (ime->sref[ime->sref.length()-1] <= '9')) retval = retval + ime->sref.substr(ime->sref.length()-1);

	return retval;
};

void WznmWrsrvIex::writeIexjobCpp_imptraverse(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMImpexpcplx* iex
			, WznmMImpexp* supime
			, WznmMTable* suptbl
			, ListWznmMImpexpcol& supiels
			, WznmMImpexp* ime
			, const string& Prjshort
		) {
	set<uint> icsWIop;

	ListWznmMImpexp subimes;
	WznmMImpexp* subime = NULL;

	WznmMImpexpcol* supiel = NULL;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;
	WznmMImpexpcol* iel2 = NULL;

	ListWznmMImpexpcol subiels;
	WznmMImpexpcol* subiel = NULL;

	WznmMTable* tbl = NULL;
	WznmMTablecol* tco = NULL;
	WznmMVector* vec = NULL;

	uint lvl;
	string ind;
	string imeshort;
	string supimeshort;
	string subimeshort;

	uint ixVBasetype;

	string s;

	bool first, found;

	// base/convtype -> SbeException:
	// iop -> IEX_IOP
	// idiref -> IEX_IDIREF
	// iref/previmp -> IEX_IREF
	// tsref/{previmp/cust/custsql/rst} -> IEX_TSREF
	// thsref/{previmp/cust/custsql/rst} -> IEX_THSREF
	// thint/{previmp/cust/custsql/rst} -> IEX_THINT
	// vsref/ixsref -> IEX_VSREF
	// ftm/invftm -> IEX_FTM
	// TBD -> IEX_IARG

	// --- this ime
	VecWznmWMImpexpIop::getIcs(ime->ixWIop, icsWIop);

	lvl = ime->supLvl;

	ind = "\t\t";
	for (unsigned int i = 0; i < ime->supLvl; i++) ind = ind + "\t";

	imeshort = writeIexjobCpp_getImeshort(dbswznm, ime);
	if (supime) supimeshort = writeIexjobCpp_getImeshort(dbswznm, supime);

	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY sref ASC", false, subimes);

	dbswznm->tblwznmmimpexpcol->loadRstBySQL("SELECT * FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY imeNum ASC", false, iels);

	dbswznm->tblwznmmtable->loadRecByRef(ime->refWznmMTable, &tbl);

	first = true;

	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) {
			outfile << ind << "irefs" << lvl << ".clear();" << endl;
			if (!first) break;
			first = false;

		} else if (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::INCR) {
			outfile << ind << "num" << lvl << " = 1;" << endl;
			if (!first) break;
			first = false;
		};
	};

	if (!first) outfile << endl;

	if (lvl == 0) {
		outfile << ind << "for (unsigned int ix" << lvl << " = 0; ix" << lvl << " < " << StrMod::lc(ime->sref) << ".nodes.size(); ix" << lvl << "++) {" << endl;
		outfile << ind << "\t" << imeshort << " = " << StrMod::lc(ime->sref) << ".nodes[ix" << lvl << "];" << endl;
	} else {
		outfile << ind << "for (unsigned int ix" << lvl << " = 0; ix" << lvl << " < " << supimeshort << "->" << StrMod::lc(ime->sref) << ".nodes.size(); ix" << lvl << "++) {" << endl;
		outfile << ind << "\t" << imeshort << " = " << supimeshort << "->" << StrMod::lc(ime->sref) << ".nodes[ix" << lvl << "];" << endl;
	};
	outfile << endl;

	if (hasAny(icsWIop, {VecWznmWMImpexpIop::RETR,VecWznmWMImpexpIop::RETRINS,VecWznmWMImpexpIop::RETRUPD,VecWznmWMImpexpIop::RETRUPDINS,VecWznmWMImpexpIop::RMV})) {
		outfile << ind << "\t// retrieve" << endl;
		outfile << ind << "\t//if (" << imeshort << "->ref == 0) throw SbeException(SbeException::IEX_RETR, {{\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(" << imeshort << "->lineno)}});" << endl;
		outfile << endl;
	};

	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) {
			outfile << ind << "\t" << imeshort << "->ix" << Prjshort << "VIop = Vec" << Prjshort << "VIop::getIx(" << imeshort << "->srefIx" << Prjshort << "VIop);" << endl;

			if (icsWIop.size() > 0) {
				outfile << ind << "\tif ";

				if (icsWIop.size() > 1) outfile << "(";
				for (auto it = icsWIop.begin(); it != icsWIop.end(); it++) {
					if (it != icsWIop.begin()) outfile << " && ";
					outfile << "(" << imeshort << "->ix" << Prjshort << "VIop != Vec" << Prjshort << "VIop::" << StrMod::uc(VecWznmWMImpexpIop::getSrefs(*it)) << ")";
				}; 
				if (icsWIop.size() > 1) outfile << ")";

				outfile << " throw SbeException(SbeException::IEX_IOP, {{\"iop\"," << imeshort << "->srefIx" << Prjshort << "VIop" << "}, {\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(" << imeshort << "->lineno)}});" << endl;
			};

		} else if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
			// --- default value
			if ((iel->Defval != "") || (iel->refWznmMVectoritem != 0)) {
				outfile << ind << "\t";
				if (iel->Defval == "&custom;") outfile << "//";

				if ((iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) != 0) {
					outfile << "if (" << imeshort << "->" << iel->sref << " == ";
					wrIelEmpty(dbswznm, outfile, iel, tco);
					outfile << ") " << imeshort << "->" << iel->sref;

				} else outfile << imeshort << "->" << tco->sref;

				if (iel->Defval == "&custom;") {
					outfile << ": CUSTOM DEFVAL" << endl;

				} else if (iel->Defval != "") {
					if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THINT)
								|| (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IARG) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF)
								|| (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR)) {
						outfile << " = \"" << StrMod::esc(iel->Defval) << "\";" << endl;

					} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
						if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) {
							outfile << " = Ftm::invstamp(\"" << StrMod::esc(iel->Defval)<< "\");" << endl;
						} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) {
							outfile << " = Ftm::invdate(\"" << StrMod::esc(iel->Defval) << "\");" << endl;
						} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) {
							outfile << " = Ftm::invtime(\"" << StrMod::esc(iel->Defval) << "\");" << endl;
						};

					} else {
						outfile << " = " << iel->Defval << ";" << endl;
					};

				} else if (iel->refWznmMVectoritem != 0) {
					if ((iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) != 0) {
						dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMVectoritem WHERE ref = " + to_string(iel->refWznmMVectoritem), s);
						outfile << " = \"" << s << "\";" << endl;
					} else {
						dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMVector WHERE ref = " + to_string(tco->fctUref), s);
						outfile << " = " << s;
						dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMVectoritem WHERE ref = " + to_string(iel->refWznmMVectoritem), s);
						outfile << "::" << StrMod::uc(s) << ";" << endl;
					};
				};
			};

			// --- actual import/export column
			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) {
				outfile << ind << "\tif (irefs" << lvl << ".find(" << imeshort << "->" << iel->sref << ") != irefs" << lvl << ".end()) throw SbeException(SbeException::IEX_IDIREF, {{\"idiref\",to_string(" << imeshort << "->" << iel->sref << ")}, {\"ime\",\"" << ime->sref << "\"}, {\"lineno\",to_string(" << imeshort << "->lineno)}});" << endl;
				if (tbl->ixVBasetype == VecWznmVMTableBasetype::CLUST) {
					outfile << ind << "\t" << imeshort << "->" << tco->sref << " = dbs" << StrMod::lc(Prjshort) << "->" << StrMod::lc(tbl->sref) << "->getNewRef();" << endl;
				};
				outfile << ind << "\tirefs" << lvl << ".insert(" << imeshort << "->" << iel->sref << ");" << endl;

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IREF) && (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::PREVIMP)) {
				outfile << ind << "\t//" << imeshort << "->" << tco->sref << ": " << StrMod::uc(VecWznmVMImpexpcolConvtype::getSref(iel->ixVConvtype)) << endl;
				outfile << ind << "\t//if (" << imeshort << "->" << tco->sref << " == 0) throw SbeException(SbeException::IEX_IREF, {{\"iref\",to_string(" << imeshort << "->" << iel->sref << ")}, {\"iel\",\"" << iel->sref << "\"}, {\"lineno\",to_string(" << imeshort << "->lineno)}});" << endl;

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) && (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::INCR)) {
				outfile << ind << "\t" << imeshort << "->" << tco->sref << " = num" << lvl << "++;" << endl;

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) && (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::SUP)) {
				if (supime) outfile << ind << "\t" << imeshort << "->" << tco->sref << " = " << supimeshort << "->ref;" << endl;

			} else if ( ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THINT)) && ((iel->ixVConvtype == VecWznmVMImpexpcolConvtype::PREVIMP) || (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::CUST) || (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::CUSTSQL) || (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::RST)) ) {
				outfile << ind << "\t//" << imeshort << "->" << tco->sref << ": " << StrMod::uc(VecWznmVMImpexpcolConvtype::getSref(iel->ixVConvtype)) << endl;
				outfile << ind << "\t//if (" << imeshort << "->" << tco->sref << " == 0) throw SbeException(SbeException::";
				if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TSREF) outfile << "IEX_TSREF, {{\"tsref\",";
				else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THSREF) outfile << "IEX_THSREF, {{\"thsref\",";
				else if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THINT) outfile << "IEX_THINT, {{\"thint\",";
				outfile << imeshort << "->" << iel->sref << "}, {\"iel\",\"" << iel->sref << "\"}, {\"lineno\",to_string(" << imeshort << "->lineno)}});" << endl;

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) && (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::IXSREF)) {
				if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
					outfile << ind << "\t" << imeshort << "->" << tco->sref << " = " << vec->sref << "::getIx(" << imeshort << "->" << iel->sref << ");" << endl;
					if (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN) outfile << ind << "\tif (" << imeshort << "->" << tco->sref << " == 0) throw SbeException(SbeException::IEX_VSREF, {{\"vsref\"," << imeshort << "->" << iel->sref << "}, {\"iel\",\"" << iel->sref << "\"}, {\"lineno\",to_string(" << imeshort << "->lineno)}});" << endl;
					delete vec;
				};

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::FTM) && (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::INVFTM)) {
				if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) {
					outfile << ind << "\t" << imeshort << "->" << tco->sref << " = Ftm::invstamp(" << imeshort << "->" << iel->sref << ");" << endl;
				} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) {
					outfile << ind << "\t" << imeshort << "->" << tco->sref << " = Ftm::invdate(" << imeshort << "->" << iel->sref << ");" << endl;
				} else if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) {
					outfile << ind << "\t" << imeshort << "->" << tco->sref << " = Ftm::invtime(" << imeshort << "->" << iel->sref << ");" << endl;
				};
				outfile << ind << "\tif (" << imeshort << "->" << tco->sref << " == 0) throw SbeException(SbeException::IEX_FTM, {{\"ftm\"," << imeshort << "->" << iel->sref << "}, {\"iel\",\"" << iel->sref << "\"}, {\"lineno\",to_string(" << imeshort << "->lineno)}});" << endl;

			} else {
				if (!(((iel->Defval != "") || (iel->refWznmMVectoritem != 0)) && ((iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) == 0))) {
					outfile << ind << "\t//" << imeshort << "->" << tco->sref << ": ";
					if (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::VOID) outfile << StrMod::uc(VecWznmVMImpexpcolBasetype::getSref(iel->ixVBasetype)) << endl;
					else outfile << StrMod::uc(VecWznmVMImpexpcolConvtype::getSref(iel->ixVConvtype)) << endl;
				};
			};

			delete tco;
		};
	};
	outfile << endl;

	if (hasAny(icsWIop, {VecWznmWMImpexpIop::INS,VecWznmWMImpexpIop::RETRINS,VecWznmWMImpexpIop::RETRUPDINS})) {
		if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) outfile << ind << "\tdbs" << StrMod::lc(Prjshort) << "->" << StrMod::lc(tbl->sref) << "->insertRec(" << imeshort << ");" << endl;
		outfile << ind << "\timpcnt++;" << endl;
	};

	// --- 2nd traverse for auto-sub's (only jump tables)
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
			if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) && (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::SUB)) {
				found = false;
				for (unsigned int j = 0; j < subimes.nodes.size(); j++) {
					subime = subimes.nodes[j];

					if (subime->ref == iel->refWznmMImpexp) {
						subimeshort = writeIexjobCpp_getImeshort(dbswznm, subime);
						dbswznm->tblwznmmimpexpcol->loadRstBySQL("SELECT * FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(subime->ref) + " ORDER BY imeNum ASC", false, subiels);

						found = true;
						break;
					};
				};

				if (found) {
					dbswznm->loadUintBySQL("SELECT ixVBasetype FROM TblWznmMTable WHERE ref = " + to_string(subime->refWznmMTable), ixVBasetype);
					if (ixVBasetype != VecWznmVMTableBasetype::JUMP) found = false;
				};

				if (found) {
					outfile << endl;
					outfile << ind << "\tif ((";

					first = true;
					for (unsigned int j = i+1; j < iels.nodes.size(); j++) {
						iel2 = iels.nodes[j];

						if (iel2->refWznmMImpexp == subime->ref) {
							if (iel2->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
								if (first) first = false;
								else outfile << " || ";

								outfile << "(" << imeshort << "->" << iel2->sref << " != ";
								wrIelEmpty(dbswznm, outfile, iel2);
								outfile << ")";
							};
						} else break;
					};

					outfile << ") && " << imeshort << "->" << StrMod::lc(subime->sref) <<  ".nodes.empty()) {" << endl;

					outfile << ind << "\t\t" << subimeshort << " = new Imeitem" << subime->sref.substr(3) << "();" << endl;
					outfile << ind << "\t\t" << subimeshort << "->lineno = " << imeshort << "->lineno;" << endl;
					outfile << ind << "\t\t" << imeshort << "->" << StrMod::lc(subime->sref) << ".nodes.push_back(" << subimeshort << ");" << endl;
					outfile << endl;

					for (unsigned int j = 0; j < subiels.nodes.size(); j++) {
						subiel = subiels.nodes[j];

						if (subiel->ixVBasetype == VecWznmVMImpexpcolBasetype::IOP) outfile << ind << "\t\t" << subimeshort << "->" << subiel->sref << " = \"ins\";" << endl;
						else if (subiel->ixVConvtype == VecWznmVMImpexpcolConvtype::SUP) outfile << ind << "\t\t" << subimeshort << "->" << subiel->sref << " = " << imeshort << "->ref;" << endl;
						else {
							for (unsigned int k = i+1; k < iels.nodes.size(); k++) {
								iel2 = iels.nodes[k];

								if (iel2->refWznmMImpexp == subime->ref) {
									if (subiel->sref == iel2->sref) {
										outfile << ind << "\t\t" << subimeshort << "->" << subiel->sref << " = " << imeshort << "->" << subiel->sref << ";" << endl;
										break;
									};
								} else break;
							};
						};
					};

					outfile << ind << "\t};" << endl;
				};
			};

			delete tco;
		};
	};

	// --- preferred record back into sup ime
	found = false;
	for (unsigned int i = 0; i < supiels.nodes.size(); i++) {
		supiel = supiels.nodes[i];

		if (!found) if (supiel->refWznmMImpexp == ime->ref) {
			found = true;
			first = true;

			outfile << endl;
			outfile << ind << "\tif (ix" << lvl << " == 0) {" << endl;
		};

		if (found) {
			if (supiel->refWznmMImpexp == ime->ref) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(supiel->refWznmMTablecol, &tco)) {
					if (first) {
						outfile << ind << "\t\t" << supimeshort << "->" << tco->sref << " = " << imeshort << "->ref;" << endl;
						first = false;

					} else outfile << ind << "\t\t" << supimeshort << "->" << tco->sref << " = " << imeshort << "->" << tco->sref << ";" << endl;

					delete tco;
				};
			};

			if ( ((i+1) == supiels.nodes.size()) || (supiel->refWznmMImpexp != ime->ref)) {
				outfile << ind << "\t\tdbs" << StrMod::lc(Prjshort) << "->" << StrMod::lc(suptbl->sref) << "->updateRec(" << supimeshort << ");" << endl;
				outfile << ind << "\t};" << endl;

				break;
			};
		};
	};

	// --- recursion over sub-ime's
	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];

		outfile << endl;
		writeIexjobCpp_imptraverse(dbswznm, outfile, iex, ime, tbl, iels, subime, Prjshort);
	};

	delete tbl;

	// --- closing brace
	outfile << ind << "};" << endl;
};

void WznmWrsrvIex::writeIexjobCpp_rvrtraverse(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMImpexpcplx* iex
			, WznmMImpexp* ime
			, WznmMImpexp* supime
			, const string& Prjshort
		) {
	WznmMTable* tbl = NULL;

	ListWznmMImpexp subimes;
	WznmMImpexp* subime = NULL;

	uint lvl;
	string ind;
	string imeshort;
	string supimeshort;

	string prjshort = StrMod::lc(Prjshort);

	// --- this ime
	lvl = ime->supLvl;

	ind = "\t";
	for (unsigned int i = 0; i < lvl; i++) ind = ind + "\t";

	imeshort = writeIexjobCpp_getImeshort(dbswznm, ime);
	if (supime) supimeshort = writeIexjobCpp_getImeshort(dbswznm, supime);

	dbswznm->tblwznmmtable->loadRecByRef(ime->refWznmMTable, &tbl);

	if (tbl->ixVBasetype != VecWznmVMTableBasetype::CLUST) {
		if (lvl == 0) {
			outfile << ind << "for (unsigned int ix" << lvl << " = 0; ix" << lvl << " < " << StrMod::lc(ime->sref) << ".nodes.size(); ix" << lvl << "++) {" << endl;
			outfile << ind << "\t" << imeshort << " = " << StrMod::lc(ime->sref) << ".nodes[ix" << lvl << "];" << endl;
		} else {
			outfile << ind << "for (unsigned int ix" << lvl << " = 0; ix" << lvl << " < " << supimeshort << "->" << StrMod::lc(ime->sref) << ".nodes.size(); ix" << lvl << "++) {" << endl;
			outfile << ind << "\t" << imeshort << " = " << supimeshort << "->" << StrMod::lc(ime->sref) << ".nodes[ix" << lvl << "];" << endl;
		};
		outfile << ind << "\tif (" << imeshort << "->ref != 0) dbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->removeRecByRef(" << imeshort << "->ref);" << endl;

		// --- recursion over sub-ime's
		dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY sref ASC", false, subimes);

		for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
			subime = subimes.nodes[i];

			outfile << endl;
			writeIexjobCpp_rvrtraverse(dbswznm, outfile, iex, subime, ime, Prjshort);
		};

		// --- closing brace
		outfile << ind << "};" << endl;
	};

	delete tbl;
};

void WznmWrsrvIex::writeIexjobCpp_coltraverse(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMImpexpcplx* iex
			, WznmMImpexp* supime
			, WznmMImpexp* ime
			, const string& Prjshort
		) {
	set<uint> icsWIop;

	ListWznmMImpexp subimes;
	WznmMImpexp* subime = NULL;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;

	ListWznmJMImpexpcolStub ielJstbs;
	WznmJMImpexpcolStub* ielJstb = NULL;

	WznmMTable* tbl = NULL;
	WznmMTable* tbl2 = NULL;
	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;
	WznmMTablecol* tco3 = NULL;
	WznmMStub* stb = NULL;
	WznmMVector* vec = NULL;
	WznmMVectoritem* vit = NULL;

	string s;

	uint lvl;
	string ind;
	string imeshort;
	string supimeshort;

	bool first;

	string prjshort = StrMod::lc(Prjshort);

	// --- this ime
	VecWznmWMImpexpIop::getIcs(ime->ixWIop, icsWIop);

	lvl = ime->supLvl;

	ind = "\t";
	for (unsigned int i = 0; i < lvl; i++) ind = ind + "\t";

	imeshort = writeIexjobCpp_getImeshort(dbswznm, ime);
	if (supime) supimeshort = writeIexjobCpp_getImeshort(dbswznm, supime);

	dbswznm->tblwznmmimpexpcol->loadRstBySQL("SELECT * FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY imeNum ASC", false, iels);

	dbswznm->tblwznmmtable->loadRecByRef(ime->refWznmMTable, &tbl);

	if (lvl == 0) {
		outfile << ind << "for (unsigned int ix" << lvl << " = 0; ix" << lvl << " < " << StrMod::lc(ime->sref) << ".nodes.size(); ix" << lvl << "++) {" << endl;
		outfile << ind << "\t" << imeshort << " = " << StrMod::lc(ime->sref) << ".nodes[ix" << lvl << "];" << endl;

	} else {
		tco = NULL;
		tco2 = NULL;

		for (unsigned int i = 0; i < iels.nodes.size(); i++) {
			iel = iels.nodes[i];

			if (iel->ixVConvtype == VecWznmVMImpexpcolConvtype::SUP) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT TblWznmMTablecol.* FROM TblWznmMTablecol, TblWznmMRelation WHERE TblWznmMTablecol.refWznmMRelation = TblWznmMRelation.ref AND TblWznmMRelation.ixVBasetype = "
								+ to_string(VecWznmVMRelationBasetype::JPREF) + " AND TblWznmMRelation.supRefWznmMRelation = " + to_string(tco->refWznmMRelation), &tco2);
				};

				break;
			};
		};

		if (tco) {
			outfile << ind << "if (getIx" << Prjshort << "VIop(ics" << Prjshort << "VIop, VecVIme::" << StrMod::uc(ime->sref) << ", ix" << Prjshort << "VIop)) {" << endl;
			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {

				if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND refWznmMRelation = " + to_string(tco->refWznmMRelation)
							+ " AND sref LIKE '%VTbl'", &tco3)) {

					if (dbswznm->tblwznmmvector->loadRecByRef(tco3->fctUref, &vec)) {
						dbswznm->loadStringBySQL("SELECT Prefix FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND frRefWznmMTable = " + to_string(supime->refWznmMTable), s);

						outfile << ind << "\tdbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRefsBy" << StrMod::cap(tco3->Short) << StrMod::cap(tco->Short) << "(" << vec->sref
									<< "::" << StrMod::uc(s) << ", " << supimeshort << "->ref, false, refs);" << endl;

						delete vec;
					};

					delete tco3;

				} else if	(dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND refWznmMRelation = " + to_string(tco->refWznmMRelation)
							+ " AND sref LIKE '%VMaintable'", &tco3)) {

					if (dbswznm->tblwznmmtable->loadRecByRef(supime->refWznmMTable, &tbl2)) {
						outfile << ind << "\tdbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRefsByMtb" << StrMod::cap(tco->Short) << "(Vec" << Prjshort << "VMaintable::"
									<< StrMod::uc(tbl2->sref) << ", " << supimeshort << "->ref, false, refs);" << endl;

						delete tbl2;
					};

					delete tco3;
				};

			} else {
				outfile << ind << "\tdbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRefsBy" << StrMod::cap(tco->Short) << "(" << supimeshort << "->ref, false, refs);" << endl;
			};
			if (tco2) outfile << ind << "\tfor (unsigned int i = 0; i < refs.size(); i++) if (refs[i] == " << supimeshort << "->" << tco2->sref << ") {refs[i] = refs[0]; refs[0] = " << supimeshort << "->" << tco2->sref << "; break;};" << endl;
			outfile << ind << "\tfor (unsigned int i = 0; i < refs.size(); i++) " << supimeshort << "->" << StrMod::lc(ime->sref) << ".nodes.push_back(new Imeitem" << ime->sref.substr(3) << "(dbs" << prjshort;
			if (icsWIop.size() > 1) outfile << ", ix" << Prjshort << "VIop";
			outfile << ", refs[i]));" << endl;
			outfile << ind << "};" << endl;
			outfile << endl;

			delete tco;
			if (tco2) delete tco2;
		};

		outfile << ind << "for (unsigned int ix" << lvl << " = 0; ix" << lvl << " < " << supimeshort << "->" << StrMod::lc(ime->sref) << ".nodes.size(); ix" << lvl << "++) {" << endl;
		outfile << ind << "\t" << imeshort << " = " << supimeshort << "->" << StrMod::lc(ime->sref) << ".nodes[ix" << lvl << "];" << endl;
	};
	outfile << endl;

	outfile << ind << "\tif (" << imeshort << "->ref != 0) {" << endl;
	for (unsigned int i = 0; i < iels.nodes.size(); i++) {
		iel = iels.nodes[i];

		if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {

			if (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IDIREF) {
				outfile << ind << "\t\t" << imeshort << "->" << iel->sref << " = ix" << lvl << "+1;" << endl;

			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THINT)) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {
					if (iel->refWznmMStub != 0) {
						if (dbswznm->tblwznmmstub->loadRecByRef(iel->refWznmMStub, &stb)) {
							outfile << ind << "\t\t" << imeshort << "->" << iel->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", " << imeshort << "->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::VOID, stcch);" << endl;
							delete stb;
						};

					} else {
						dbswznm->tblwznmjmimpexpcolstub->loadRstByIel(iel->ref, false, ielJstbs);

						if (ielJstbs.nodes.size() > 0) {
							if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND tblRefWznmMTable = " + to_string(tco->tblRefWznmMTable)
										+ " AND refWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND sref LIKE '%VTbl'", &tco2)) {
								if (dbswznm->tblwznmmvector->loadRecByRef(tco2->fctUref, &vec)) {

									first = true;
									for (unsigned int j = 0; j < ielJstbs.nodes.size(); j++) {
										ielJstb = ielJstbs.nodes[j];

										if (dbswznm->tblwznmmvectoritem->loadRecByRef(ielJstb->x1RefWznmMVectoritem, &vit)) {
											if (dbswznm->tblwznmmstub->loadRecByRef(ielJstb->refWznmMStub, &stb)) {
												outfile << ind << "\t\t";

												if (first) first = false;
												else outfile << "else ";

												outfile << "if (" << imeshort << "->" << tco2->sref << " == " << vec->sref << "::" << StrMod::uc(vit->sref) << ") " << imeshort << "->" << iel->sref << " = Stub" << Prjshort
															<< "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", " << imeshort << "->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::VOID, stcch);" << endl;

												delete stb;
											};
											delete vit;
										};
									};
									delete vec;
								};
								delete tco2;
							};
						} else {
							outfile << ind << "\t\t//" << imeshort << "->" << iel->sref << ": STUB" << endl;
						};
					};
					delete tco;
				};
			} else if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TBL) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::FTM)) {
			} else { // IREF, IARG
				outfile << ind << "\t\t//" << imeshort << "->" << iel->sref << ": " << StrMod::uc(VecWznmVMImpexpcolBasetype::getSref(iel->ixVBasetype)) << endl;
			};
		};
	};
	outfile << ind << "\t};" << endl;

	delete tbl;

	// --- recursion over sub-ime's
	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE supRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY sref ASC", false, subimes);

	for (unsigned int i = 0; i < subimes.nodes.size(); i++) {
		subime = subimes.nodes[i];

		outfile << endl;
		writeIexjobCpp_coltraverse(dbswznm, outfile, iex, ime, subime, Prjshort);
	};

	// --- closing brace
	outfile << ind << "};" << endl;
};

void WznmWrsrvIex::wrIelEmpty(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMImpexpcol* iel
			, WznmMTablecol* tco
		) {
	bool tcolocal = (tco == NULL);

	if (!tco && (iel->refWznmMTablecol != 0)) dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco);

	if ((iel->ixVBasetype == VecWznmVMImpexpcolBasetype::TSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::THINT)
				|| (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::VSREF) || (iel->ixVBasetype == VecWznmVMImpexpcolBasetype::IARG)) outfile << "\"\"";

	else if (tco) {
		if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF)
					|| (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR)) outfile << "\"\"";
		else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP)) outfile << "0.0";
		else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) outfile << "false";
		else outfile << "0";

	} else outfile << "0";

	if (tcolocal && tco) delete tco;
};
// IP cust --- IEND
