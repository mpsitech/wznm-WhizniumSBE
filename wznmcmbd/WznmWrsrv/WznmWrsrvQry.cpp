/**
	* \file WznmWrsrvQry.cpp
	* Wznm operation processor - write specific job C++ code for query (implementation)
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

#include "WznmWrsrvQry.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvQry
 ******************************************************************************/

DpchRetWznm* WznmWrsrvQry::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvQry* dpchinv
		) {
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	vector<ubigint> refs;
	set<ubigint> unqrefs;
	ubigint ref;

	WznmMJob* job = NULL;
	WznmMQuery* qry = NULL;
	WznmMTable* qtb = NULL;

	WznmMQuery* lrefqry = NULL;
	WznmMTable* lreftbl = NULL;

	WznmMQuery* oprqry = NULL;
	WznmMTable* oprtbl = NULL;

	ListWznmMQuerymod bras;

	ListWznmMQuerymod exbras;

	ListWznmMQuerymod filts;

	ListWznmMQuerymod jovrs;
	ListWznmMQuerymod stovrs;

	ListWznmAMQueryClause qacs;

	ListWznmAMQueryOrder qaos;
	WznmAMQueryOrder* lrefqao = NULL;
	WznmAMQueryOrder* oprqao = NULL;

	ListWznmMPreset psts;

	string s;

	dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job);
	dbswznm->tblwznmmquery->loadRecByRef(job->refUref, &qry);
	dbswznm->tblwznmmtable->loadRecByRef(qry->qtbRefWznmMTable, &qtb);

	// DEBUG
	//showQry(dbswznm, qry->ref);

	// sub-queries
	if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST)) {
		dbswznm->tblwznmmquery->loadRecBySQL("SELECT * FROM TblWznmMQuery WHERE supRefWznmMQuery = " + to_string(qry->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMQuerySupSubrole::LREF), &lrefqry);
		dbswznm->tblwznmmtable->loadRecByRef(lrefqry->refWznmMTable, &lreftbl);
		dbswznm->tblwznmmquery->loadRecBySQL("SELECT * FROM TblWznmMQuery WHERE supRefWznmMQuery = " + to_string(qry->ref) + " AND supIxVSubrole = " + to_string(VecWznmVMQuerySupSubrole::OPR), &oprqry);
		dbswznm->tblwznmmtable->loadRecByRef(oprqry->refWznmMTable, &oprtbl);
	};

	// branch query modifications
	if (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) {
		dbswznm->tblwznmmquerymod->loadRstBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND ixVBasetype = " + to_string(VecWznmVMQuerymodBasetype::BRA)
					+ " ORDER BY qryNum ASC", false, bras);
	};

	if (qry->ixVBasetype == VecWznmVMQueryBasetype::STD) {
		dbswznm->tblwznmmquerymod->loadRstBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND ixVBasetype = " + to_string(VecWznmVMQuerymodBasetype::EXBRA)
					+ " ORDER BY qryNum ASC", false, exbras);
	} else if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST)) {
		dbswznm->tblwznmmquerymod->loadRstBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(lrefqry->ref) + " AND ixVBasetype = " + to_string(VecWznmVMQuerymodBasetype::EXBRA)
					+ " ORDER BY qryNum ASC", false, exbras);
	};

	// filters
	if ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) {
		dbswznm->tblwznmmquerymod->loadRstBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND ixVBasetype = " + to_string(VecWznmVMQuerymodBasetype::FILT)
					+ " ORDER BY qryNum ASC", false, filts);
	} else if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST)) {
		dbswznm->tblwznmmquerymod->loadRstBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(oprqry->ref) + " AND ixVBasetype = " + to_string(VecWznmVMQuerymodBasetype::FILT)
					+ " ORDER BY qryNum ASC", false, filts);
	};

	// jump table overrides
	dbswznm->tblwznmmquerymod->loadRstBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND ixVBasetype = " + to_string(VecWznmVMQuerymodBasetype::JOVR)
				+ " ORDER BY qryNum ASC", false, jovrs);

	// "S" (sub1n) / "T" (submn) table overrides
	dbswznm->tblwznmmquerymod->loadRstBySQL("SELECT * FROM TblWznmMQuerymod WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND ixVBasetype = " + to_string(VecWznmVMQuerymodBasetype::STOVR)
				+ " ORDER BY qryNum ASC", false, stovrs);

	// order directives
	dbswznm->tblwznmamqueryorder->loadRstByQry(qry->ref, false, qaos);

	if (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST) dbswznm->tblwznmamqueryorder->loadRecBySQL("SELECT * FROM TblWznmAMQueryOrder WHERE refWznmMQuery = " + to_string(lrefqry->ref), &lrefqao);
	if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST))
				dbswznm->tblwznmamqueryorder->loadRecBySQL("SELECT * FROM TblWznmAMQueryOrder WHERE refWznmMQuery = " + to_string(oprqry->ref), &oprqao);

	// unique preset's needed in rerun()
	unqrefs.clear();

	if ( ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) && (qaos.nodes.size() > 1) ) {
		dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND sref = 'Pre" + Prjshort + "IxOrd'", ref);
		unqrefs.insert(ref);
	};

	if (bras.nodes.size() > 0) {
		dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND sref = 'Pre" + Prjshort + "IxPre'", ref);
		unqrefs.insert(ref);
	};

	for (unsigned int i = 0; i < bras.nodes.size(); i++) if (bras.nodes[i]->refWznmMPreset != 0) unqrefs.insert(bras.nodes[i]->refWznmMPreset);
	for (unsigned int i = 0; i < exbras.nodes.size(); i++) if (exbras.nodes[i]->refWznmMPreset != 0) unqrefs.insert(exbras.nodes[i]->refWznmMPreset);
	for (unsigned int i = 0; i < filts.nodes.size(); i++) if (filts.nodes[i]->refWznmMPreset != 0) unqrefs.insert(filts.nodes[i]->refWznmMPreset);

	if ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) {
		dbswznm->tblwznmamqueryclause->loadRstByQry(qry->ref, false, qacs);
	} else if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST)) {
		dbswznm->tblwznmamqueryclause->loadRstByQry(lrefqry->ref, false, qacs);
	};
	for (unsigned int i = 0; i < qacs.nodes.size(); i++) if (qacs.nodes[i]->refWznmMPreset != 0) unqrefs.insert(qacs.nodes[i]->refWznmMPreset);

	refs.clear();
	for (auto it = unqrefs.begin(); it != unqrefs.end(); it++) refs.push_back(*it);

	dbswznm->tblwznmmpreset->loadRstByRefs(refs, false, psts);

	// QryXxxxYyyZzzzz.h, QryXxxxYyyZzzzz.cpp
	s = xchg->tmppath + "/" + folder + "/" + qry->sref + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/" + qry->sref + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeQryH(dbswznm, hfile, qry, qtb, bras, exbras, filts, qaos, Prjshort);
	writeQryCpp(dbswznm, cppfile, job, qry, qtb, lrefqry, lreftbl, oprqry, oprtbl, bras, exbras, filts, jovrs, stovrs, qaos, lrefqao, oprqao, psts, Prjshort);

	hfile.close();
	cppfile.close();

	delete job;
	delete qry;
	delete qtb;

	if (lrefqry) delete lrefqry;
	if (lreftbl) delete lreftbl;

	if (oprqry) delete oprqry;
	if (oprtbl) delete oprtbl;
	
	if (lrefqao) delete lrefqao;
	if (oprqao) delete oprqao;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvQry::writeQryH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMQuery* qry
			, WznmMTable* qtb
			, ListWznmMQuerymod& bras
			, ListWznmMQuerymod& exbras
			, ListWznmMQuerymod& filts
			, ListWznmAMQueryOrder& qaos
			, const string& Prjshort
		) {
	vector<unsigned int> unqicsFilts;
	WznmMQuerymod* filt = NULL;

	WznmMPreset* pst = NULL;

	WznmMQuerymod* exbra = NULL;

	string prjshort = StrMod::lc(Prjshort);

	unsigned int cnt;

	// --- specVar
	outfile << "// IP vars.spec --- IBEGIN" << endl;
	outfile << "\tList" << qtb->sref.substr(3) << " rst;" << endl;
	outfile << endl;
	outfile << "\tSbecore::uint ix" << Prjshort << "VQrystate;" << endl;
	outfile << "// IP vars.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tvoid refreshJnum();" << endl;
	outfile << endl;

	outfile << "\tvoid rerun(Dbs" << Prjshort << "* dbs" << prjshort << ", const bool call = false);" << endl;

	if (((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) && (exbras.nodes.size() > 0))
				|| ((qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) && (bras.nodes.size() > 0))) {
		outfile << "\tvoid rerun_baseSQL(std::string& sqlstr);" << endl;
	};

	if ( ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) && (filts.nodes.size() > 0) ) {
		getUnqicsQmdpsts(filts, unqicsFilts);

		outfile << "\tvoid rerun_filtSQL(std::string& sqlstr";

		for (unsigned int i = 0; i < unqicsFilts.size(); i++) {
			filt = filts.nodes[unqicsFilts[i]];

			if (dbswznm->tblwznmmpreset->loadRecByRef(filt->refWznmMPreset, &pst)) {
				outfile << ", const " << getPstCppType(pst->ixWznmWArgtype, true, true) << " " << getPstVar(pst->sref);
				delete pst;
			};
		};

		outfile << ", const bool addwhere);" << endl;

		outfile << "\tvoid rerun_filtSQL_append(std::string& sqlstr, bool& first);" << endl;
	};

	if ( ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) && (qaos.nodes.size() > 1) )
				outfile << "\tvoid rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);" << endl;

	if (qry->ixVBasetype != VecWznmVMQueryBasetype::MULTBRA) {
		cnt = 0;
		for (unsigned int i = 0; i < exbras.nodes.size(); i++) {
			exbra = exbras.nodes[i];

			if (exbra->Avail.length() > 0) {
				outfile << "\tbool evalQmd" << exbra->qryNum << "Avail();" << endl;
				cnt++;
			};
		};
		if (cnt > 0) outfile << endl;
	};
	outfile << endl;

	outfile << "\tvoid fetch(Dbs" << Prjshort << "* dbs" << prjshort << ");" << endl;
	outfile << endl;

	outfile << "\tSbecore::uint getJnumByRef(const Sbecore::ubigint ref);" << endl;
	outfile << "\tSbecore::ubigint getRefByJnum(const Sbecore::uint jnum);" << endl;
	outfile << "\t" << qtb->sref.substr(3) << "* getRecByJnum(const Sbecore::uint jnum);" << endl;
	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvQry::writeQryCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMQuery* qry
			, WznmMTable* qtb
			, WznmMQuery* lrefqry
			, WznmMTable* lreftbl
			, WznmMQuery* oprqry
			, WznmMTable* oprtbl
			, ListWznmMQuerymod& bras
			, ListWznmMQuerymod& exbras
			, ListWznmMQuerymod& filts
			, ListWznmMQuerymod& jovrs
			, ListWznmMQuerymod& stovrs
			, ListWznmAMQueryOrder& qaos
			, WznmAMQueryOrder* lrefqao
			, WznmAMQueryOrder* oprqao
			, ListWznmMPreset& psts
			, const string& Prjshort
		) {
	vector<ubigint> refs;

	WznmMQuery* _qry = NULL;

	WznmMQuerymod* bra = NULL;
	WznmMQuerymod* exbra = NULL;

	vector<unsigned int> unqicsFilts;
	WznmMQuerymod* filt = NULL;

	vector<unsigned int> unqicsRecovrs;
	WznmMQuerymod* jovr = NULL;

	WznmMQuerymod* stovr = NULL;

	WznmAMQueryOrder* qao = NULL;

	ListWznmAMQueryClause qacs;
	WznmAMQueryClause* qac = NULL;

	WznmMPreset* pst = NULL;
	ubigint refPst;

	ListWznmRMQueryMTable qrts;
	WznmRMQueryMTable* qrt = NULL;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;
	vector<string> tblpfxs;

	vector<string> comtbls;
	vector<string> bratbls;

	ListWznmMQuerycol allqcos;
	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	ListWznmJMQuerycolStub qjss;
	WznmJMQuerycolStub* qjs = NULL;

	ListWznmMTablecol alltcos;
	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;

	ListWznmMTablecol tco2s;
	WznmMTablecol* tco2 = NULL;
	WznmMTablecol* psttco2 = NULL;
	WznmMTablecol* spttco2 = NULL;
	WznmMTablecol* epttco2 = NULL;

	WznmMVector* vec = NULL;
	WznmMVectoritem* vit = NULL;

	WznmMStub* stb = NULL;

	ListWznmMTable mtbs;
	WznmMTable* mtb = NULL;

	ListWznmMTable rectbls;

	WznmMCall* recupdcal;

	ListWznmMCall cals;
	WznmMCall* cal = NULL;

	bool first, first2;
	bool found;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	bool hasqwr = false;

	Expr expr;

	uint cnt;

	string id;

	vector<string> ss;
	string s, s2;

	size_t ptr;

	// load source tables along with their prefixes
	dbswznm->tblwznmrmquerymtable->loadRstBySQL("SELECT * FROM TblWznmRMQueryMTable WHERE refWznmMQuery = " + to_string(qry->ref) + " AND Source = 1", false, qrts);
	for (unsigned int i = 0; i < qrts.nodes.size(); i++) {
		qrt = qrts.nodes[i];

		dbswznm->tblwznmmtable->loadRecByRef(qrt->refWznmMTable, &tbl);
		tbls.nodes.push_back(tbl);
		tblpfxs.push_back(qrt->Prefix);
	};

	// load common non-source tables (sref's only)
	dbswznm->tblwznmrmquerymtable->loadRstBySQL("SELECT * FROM TblWznmRMQueryMTable WHERE refWznmMQuery = " + to_string(qry->ref) + " AND Source = 0", false, qrts);
	for (unsigned int i = 0; i < qrts.nodes.size(); i++) {
		qrt = qrts.nodes[i];

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmTMQuerymodMQuery WHERE refR = " + to_string(qrt->ref), cnt);

		if (cnt == 0) {
			dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMTable WHERE ref = " + to_string(qrt->refWznmMTable), s);
			comtbls.push_back(s);
		};
	};

	// load all query columns
	dbswznm->tblwznmmquerycol->loadRstByQry(qry->ref, false, allqcos);

	for (unsigned int i = 0; i < allqcos.nodes.size(); i++) {
		qco = allqcos.nodes[i];

		if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QWR) hasqwr = true;

		if (dbswznm->tblwznmmtablecol->loadRecByRef(qco->refWznmMTablecol, &tco)) alltcos.nodes.push_back(tco);
		else alltcos.nodes.push_back(NULL); // pushing back a NULL pointer does not create problems during the destruction of alltcos
	};

	// load query columns that appear in both base and query tables
	dbswznm->tblwznmmquerycol->loadRstBySQL("SELECT * FROM TblWznmMQuerycol WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND (ixWOccurrence & "
				+ to_string(VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB) + ") = " + to_string(VecWznmWMQuerycolOccurrence::QTB + VecWznmWMQuerycolOccurrence::BTB)
				+ " ORDER BY qryNum ASC", false, qcos);

	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];

		dbswznm->tblwznmmtablecol->loadRecByRef(qco->refWznmMTablecol, &tco);
		tcos.nodes.push_back(tco);

		// rename tco to include table sref
		for (unsigned int j = 0; j < tbls.nodes.size(); j++) {
			tbl = tbls.nodes[j];
			qrt = qrts.nodes[j];

			if (tbl->ref == tco->tblRefWznmMTable) {
				tco->sref = tbl->sref + "." + tco->sref;
				break;
			};
		};
	};

	// let tbl point to primary source table
	for (unsigned int i = 0; i < tblpfxs.size(); i++) {
		if (tblpfxs[i].length() == 0) {
			tbl = tbls.nodes[i];
			break;
		};
	};

	// load record update and table modification calls
	dbswznm->tblwznmmcall->loadRecBySQL("SELECT TblWznmMCall.* FROM TblWznmMCall, TblWznmMSensitivity WHERE TblWznmMCall.ref = TblWznmMSensitivity.refWznmMCall AND TblWznmMSensitivity.refWznmMJob = "
				+ to_string(job->ref) + " AND TblWznmMCall.ixVBasetype = " + to_string(VecWznmVMCallBasetype::RECUPD), &recupdcal);

	dbswznm->tblwznmmcall->loadRstBySQL("SELECT TblWznmMCall.* FROM TblWznmMCall, TblWznmMSensitivity WHERE TblWznmMCall.ref = TblWznmMSensitivity.refWznmMCall AND TblWznmMSensitivity.refWznmMJob = "
				+ to_string(job->ref) + " AND TblWznmMCall.ixVBasetype = " + to_string(VecWznmVMCallBasetype::TBLMOD), false, cals);

	// --- ns.spec
	outfile << "// IP ns.spec --- IBEGIN" << endl;
	outfile << "// IP ns.spec --- IEND" << endl;

	// --- constructor.spec1
	outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
	outfile << "\txchg->addStmgr(jref, Stub::VecVNonetype::SHORT);" << endl;
	outfile << "\tix" << Prjshort << "VQrystate = Vec" << Prjshort << "VQrystate::OOD;" << endl;
	outfile << "// IP constructor.spec1 --- IEND" << endl;

	// --- constructor.spec2
	outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
	outfile << "\trerun(dbs" << prjshort << ");" << endl;
	outfile << endl;
	outfile << "// IP constructor.spec2 --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	// -- refreshJnum
	outfile << "void " << qry->sref << "::refreshJnum() {" << endl;
	outfile << "\tubigint preRefSel = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REFSEL, jref);" << endl;
	outfile << endl;

	outfile << "\tstgiac.jnum = getJnumByRef(preRefSel);" << endl;

	if (recupdcal) {
		outfile << endl;
		outfile << "\tif (preRefSel == 0) xchg->removeClstns(Vec" << Prjshort << "VCall::" << StrMod::uc(StrMod::dotToUsc(recupdcal->sref)) << ", jref);" << endl;
		outfile << "\telse xchg->addRefClstn(Vec" << Prjshort << "VCall::" << StrMod::uc(StrMod::dotToUsc(recupdcal->sref)) << ", jref, Clstn::VecVJobmask::ALL, 0, true, preRefSel);" << endl;
	};

	outfile << "};" << endl;
	outfile << endl;

	// -- rerun
	outfile << "void " << qry->sref << "::rerun(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, const bool call" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tstring sqlstr;" << endl;
	outfile << endl;

	if (qry->Limofs) {
		if (qry->ixVBasetype == VecWznmVMQueryBasetype::STD) {
			outfile << "\tuint cnt;" << endl;
			outfile << endl;

		} else if (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) {
			outfile << "\tvector<ubigint> cnts;" << endl;
			outfile << "\tuint cnt, cntsum;" << endl;
			outfile << endl;

			outfile << "\tvector<ubigint> lims;" << endl;
			outfile << "\tvector<ubigint> ofss;" << endl;
			outfile << endl;
		};
	};

	if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST)) {
		outfile << "\tvector<ubigint> refsList;" << endl;
		outfile << "\tvector<ubigint> refsPool;" << endl;
		outfile << endl;

		outfile << "\tList" << oprtbl->sref.substr(3) << " " << oprtbl->Short << "s;" << endl;
		outfile << "\t" << oprtbl->sref.substr(3) << "* " << oprtbl->Short << ";" << endl;
		outfile << endl;
	};

	// determine availability of exclusive branches
	if (qry->ixVBasetype != VecWznmVMQueryBasetype::MULTBRA) {
		cnt = 0;
		for (unsigned int i = 0; i < exbras.nodes.size(); i++) {
			exbra = exbras.nodes[i];

			if (exbra->Avail.length() > 0) {
				outfile << "\tbool qmd" << exbra->qryNum << "Avail = evalQmd" << exbra->qryNum << "Avail();" << endl;
				cnt++;
			};
		};
		if (cnt > 0) outfile << endl;
	};

	// fetch presets including preIxPre, preIxOrd if required
	for (unsigned int i = 0; i < psts.nodes.size(); i++) {
		pst = psts.nodes[i];

		outfile << "\t" << getPstCppType(pst->ixWznmWArgtype) << " " << getPstVar(pst->sref)
					<< " = xchg->get" << StrMod::cap(VecWznmWArgtype::getSrefs(pst->ixWznmWArgtype)) << "Preset(Vec" << Prjshort << "VPreset::" << StrMod::uc(StrMod::dotToUsc(pst->sref)) << ", jref);" << endl;
	};
	if (psts.nodes.size() > 0) outfile << endl;

	// reset
	for (unsigned int i = 0; i < cals.nodes.size(); i++) {
		cal = cals.nodes[i];
		if (cal->invIxWznmWArgtype != 0) outfile << "\txchg->removeClstns(Vec" << Prjshort << "VCall::" << StrMod::uc(StrMod::dotToUsc(cal->sref)) << ", jref);" << endl;
	};
	outfile << endl;

	outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "qselect->removeRstByJref(jref);" << endl;
	outfile << "\tdbs" << prjshort << "->" << StrMod::lc(qtb->sref) << "->removeRstByJref(jref);" << endl;
	outfile << endl;

	if ( ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) && qry->Limofs) {
		// - count
		if (qry->ixVBasetype == VecWznmVMQueryBasetype::STD) {
			first = true;
			for (unsigned int i = 0; i < exbras.nodes.size(); i++) {
				exbra = exbras.nodes[i];

				if (exbra->Avail.length() > 0) {
					getBratbls(dbswznm, exbra->ref, tbls, comtbls, bratbls);

					dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = " + to_string(exbra->ref)
								+ " ORDER BY qryNum ASC", false, qacs);

					outfile << "\t";
					if (first) first = false;
					else outfile << "} else ";
					outfile << "if (qmd" << exbra->qryNum << "Avail) {" << endl;

					writeCnt(dbswznm, outfile, qry, tbl, bratbls, qacs, filts, Prjshort, "\t\t");

					outfile << endl;
				};
			};

			if (first) {
				id = "\t";
			} else {
				id = "\t\t";
				outfile << "\t} else {" << endl;
			};

			// "null" branch
			getBratbls(dbswznm, 0, tbls, comtbls, bratbls);

			dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);

			writeCnt(dbswznm, outfile, qry, tbl, bratbls, qacs, filts, Prjshort, id);

			if (!first) outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\tstatshr.ntot = cnt;" << endl;
			outfile << "\tstatshr.nload = 0;" << endl;
			outfile << endl;

			outfile << "\tif (stgiac.jnumFirstload > cnt) {" << endl;
			outfile << "\t\tif (cnt >= stgiac.nload) stgiac.jnumFirstload = cnt-stgiac.nload+1;" << endl;
			outfile << "\t\telse stgiac.jnumFirstload = 1;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

		} else if (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) {
			refPst = 0;

			outfile << "\tcntsum = 0;" << endl;
			outfile << endl;

			for (unsigned int i = 0; i < bras.nodes.size(); i++) {
				bra = bras.nodes[i];

				getBratbls(dbswznm, bra->ref, tbls, comtbls, bratbls);

				dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);
				dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = " + to_string(bra->ref) + " ORDER BY qryNum ASC", true, qacs);

				if (dbswznm->tblwznmmpreset->loadRecByRef(bra->refWznmMPreset, &pst)) {
					if (bra->refWznmMPreset != refPst) {
						outfile << "\t";
						if (refPst != 0) outfile << "} else ";
						outfile << "if (preIxPre == Vec" << Prjshort << "VPreset::" << StrMod::uc(StrMod::dotToUsc(pst->sref)) << ") {" << endl;

						refPst = bra->refWznmMPreset;
					};

					writeCnt(dbswznm, outfile, qry, tbl, bratbls, qacs, filts, Prjshort, "\t\t");
					outfile << endl;

					delete pst;
				};
			};

			if (bras.nodes.size() == 0) {
				id = "\t";
			} else {
				id = "\t\t";
				outfile << "\t} else {" << endl;
			};

			// "null" branch
			getBratbls(dbswznm, 0, tbls, comtbls, bratbls);

			dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);

			writeCnt(dbswznm, outfile, qry, tbl, bratbls, qacs, filts, Prjshort, id);

			if (bras.nodes.size() > 0) outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\tstatshr.ntot = 0;" << endl;
			outfile << "\tstatshr.nload = 0;" << endl;
			outfile << endl;

			outfile << "\tif (stgiac.jnumFirstload > cntsum) {" << endl;
			outfile << "\t\tif (cntsum >= stgiac.nload) stgiac.jnumFirstload = cntsum-stgiac.nload+1;" << endl;
			outfile << "\t\telse stgiac.jnumFirstload = 1;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\tfor (unsigned int i = 0; i < cnts.size(); i++) {" << endl;
			outfile << "\t\tif (statshr.nload < stgiac.nload) {" << endl;
			outfile << "\t\t\tif ((statshr.ntot+cnts[i]) >= stgiac.jnumFirstload) {" << endl;
			outfile << "\t\t\t\tif (statshr.ntot >= stgiac.jnumFirstload) {" << endl;
			outfile << "\t\t\t\t\tofss[i] = 0;" << endl;
			outfile << "\t\t\t\t} else {" << endl;
			outfile << "\t\t\t\t\tofss[i] = stgiac.jnumFirstload-statshr.ntot-1;" << endl;
			outfile << "\t\t\t\t};" << endl;
			outfile << endl;

			outfile << "\t\t\t\tif ((statshr.nload+cnts[i]-ofss[i]) > stgiac.nload) lims[i] = stgiac.nload-statshr.nload;" << endl;
			outfile << "\t\t\t\telse lims[i] = cnts[i]-ofss[i];" << endl;
			outfile << "\t\t\t};" << endl;
			outfile << "\t\t};" << endl;
			outfile << endl;

			outfile << "\t\tstatshr.ntot += cnts[i];" << endl;
			outfile << "\t\tstatshr.nload += lims[i];" << endl;
			outfile << "\t};" << endl;
			outfile << endl;
		};
	};

	if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST)) {
		// - select available list references (.lref)
		first = true;
		for (unsigned int i = 0; i < exbras.nodes.size(); i++) {
			exbra = exbras.nodes[i];

			if (exbra->Avail.length() > 0) {
				dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(lrefqry->ref) + " AND x1RefWznmMQuerymod = " + to_string(exbra->ref) + " ORDER BY qryNum ASC", false, qacs);

				outfile << "\t";
				if (first) first = false;
				else outfile << "} else ";
				outfile << "if (qmd" << exbra->qryNum << "Avail) {" << endl;

				writeLrefqry(dbswznm, outfile, qry, lreftbl, qacs, lrefqao, Prjshort, "\t\t");
				outfile << endl;
			};
		};

		if (first) {
			id = "\t";
		} else {
			id = "\t\t";
			outfile << "\t} else {" << endl;
		};

		// "null" branch
		dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(lrefqry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);

		writeLrefqry(dbswznm, outfile, qry, lreftbl, qacs, lrefqao, Prjshort, id);

		if (!first) outfile << "\t};" << endl;
		outfile << endl;

		// - select applicable operators (.opr)
		if (filts.nodes.size() == 1) {
			filt = filts.nodes[0];

			if (dbswznm->tblwznmmpreset->loadRecByRef(filt->refWznmMPreset, &pst)) {
				if (pst->ixWznmWArgtype == VecWznmWArgtype::REFS) id = "\t\t"; else id = "\t";

				if (pst->ixWznmWArgtype == VecWznmWArgtype::REFS) outfile << "\tfor (unsigned int i = 0; i < " << getPstVar(pst->sref) << ".size(); i++) {" << endl;

				outfile << id << "sqlstr = \"SELECT * FROM " << oprtbl->sref << "\";" << endl;

				dbswznm->tblwznmamqueryclause->loadRstByQry(oprqry->ref, false, qacs);

				for (unsigned int i = 0; i < qacs.nodes.size(); i++) {
					qac = qacs.nodes[i];

					outfile << id << "sqlstr += \"";
					if (i == 0) outfile << " WHERE "; else outfile << " AND ";

					writeQac(dbswznm, outfile, qac, Prjshort);
				};

				if (oprqao) outfile << "\tsqlstr += \" ORDER BY " << oprqao->srefsWznmMTablecol << " ASC\";" << endl; // opr query has only one table ; plus, single tco sref

				outfile << id << "dbs" << prjshort << "->" << StrMod::lc(oprtbl->sref) << "->loadRstBySQL(sqlstr, ";
				if (pst->ixWznmWArgtype == VecWznmWArgtype::REFS) outfile << "true"; else outfile << "false";
				outfile << ", " << oprtbl->Short << "s);" << endl;

				if (pst->ixWznmWArgtype == VecWznmWArgtype::REFS) outfile << "\t};" << endl;
				outfile << endl;

				delete pst;
			};
		};

		// - apply operators to list
		outfile << "\tfor (unsigned int i = 0; i < " << oprtbl->Short << "s.nodes.size(); i++) {" << endl;
		outfile << "\t\t" << oprtbl->Short << " = " << oprtbl->Short << "s.nodes[i];" << endl;

		if (qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) {
			outfile << "\t\tLop::apply(" << oprtbl->Short << "->ix" << Prjshort << "VLop, refsList, refsPool, " << oprtbl->Short << "->";
			if (lreftbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) outfile << "pr1RefM"; else outfile << "pr1RefLR";
			outfile << ");" << endl;

		} else if (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST) {
			outfile << "\t\tOolop::apply(" << oprtbl->Short << "->ix" << Prjshort << "VOolop, refsList, refsPool, " << oprtbl->Short << "->";
			if (lreftbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) outfile << "pr1RefM"; else outfile << "pr1RefLR";
			outfile << ", " << oprtbl->Short << "->";
			if (lreftbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) outfile << "pr2RefM"; else outfile << "pr2RefLR";
			outfile << ");" << endl;
		};

		outfile << "\t};" << endl;
		outfile << endl;

		if (qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) {
			if (qry->Limofs) {
				outfile << "\tstatshr.ntot = 0;" << endl;
				outfile << "\tstatshr.nload = 0;" << endl;
				outfile << endl;
			};

			outfile << "\tfor (unsigned int i = 0; i < refsList.size(); i++) {" << endl;
			outfile << "\t\tif (refsList[i] != 0) {" << endl;
			outfile << "\t\t\tdbs" << prjshort << "->tbl" << prjshort << "qselect->insertNewRec(NULL, jref, i+1, 0, refsList[i]);" << endl;
			if (qry->Limofs) outfile << "\t\t\tstatshr.ntot++;" << endl;
			outfile << "\t\t};" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

		} else if (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST) {
			if (qry->Limofs) {
				outfile << "\tstatshr.ntot = refsList.size();" << endl;
				outfile << "\tstatshr.nload = 0;" << endl;
				outfile << endl;
			};
			outfile << "\tfor (unsigned int i = 0; i < refsList.size(); i++) dbs" << prjshort << "->tbl" << prjshort << "qselect->insertNewRec(NULL, jref, i+1, 0, refsList[i]);" << endl;
		};
	};

	// - actual query
	if (qry->ixVBasetype == VecWznmVMQueryBasetype::STD) {
		first = true;
		for (unsigned int i = 0; i < exbras.nodes.size(); i++) {
			exbra = exbras.nodes[i];

			if (exbra->Avail.length() > 0) {
				getBratbls(dbswznm, exbra->ref, tbls, comtbls, bratbls);

				dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = " + to_string(exbra->ref) + " ORDER BY qryNum ASC", false, qacs);

				outfile << "\t";
				if (first) first = false;
				else outfile << "} else ";
				outfile << "if (qmd" << exbra->qryNum << "Avail) {" << endl;

				writeQry(dbswznm, outfile, qry, qtb, filts, qaos, qacs, bratbls, qcos, tcos, Prjshort, "\t\t", hasqwr, true, (filts.nodes.size() > 0), 0);

				outfile << endl;
			};
		};

		if (first) {
			id = "\t";
		} else {
			id = "\t\t";
			outfile << "\t} else {" << endl;
		};

		// "null" branch
		getBratbls(dbswznm, 0, tbls, comtbls, bratbls);

		dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);

		writeQry(dbswznm, outfile, qry, qtb, filts, qaos, qacs, bratbls, qcos, tcos, Prjshort, id, hasqwr, !first, (filts.nodes.size() > 0), 0);

		if (!first) outfile << "\t};" << endl;
		outfile << endl;

	} else if (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) {
		refPst = 0;
		cnt = 0;

		for (unsigned int i = 0; i < bras.nodes.size(); i++) {
			bra = bras.nodes[i];

			getBratbls(dbswznm, bra->ref, tbls, comtbls, bratbls);

			dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);
			dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = " + to_string(bra->ref) + " ORDER BY qryNum ASC", true, qacs);

			if (dbswznm->tblwznmmpreset->loadRecByRef(bra->refWznmMPreset, &pst)) {
				if (bra->refWznmMPreset != refPst) {
					outfile << "\t";
					if (refPst != 0) outfile << "} else ";
					outfile << "if (preIxPre == Vec" << Prjshort << "VPreset::" << StrMod::uc(StrMod::dotToUsc(pst->sref)) << ") {" << endl;

					refPst = bra->refWznmMPreset;
					cnt = 0;
				} else cnt++;

				writeQry(dbswznm, outfile, qry, qtb, filts, qaos, qacs, bratbls, qcos, tcos, Prjshort, "\t\t", hasqwr, true, (filts.nodes.size() > 0), cnt);
				outfile << endl;

				delete pst;
			};
		};

		if (bras.nodes.size() == 0) {
			id = "\t";
		} else {
			id = "\t\t";
			outfile << "\t} else {" << endl;
		};

		// "null" branch
		getBratbls(dbswznm, 0, tbls, comtbls, bratbls);

		dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);

		writeQry(dbswznm, outfile, qry, qtb, filts, qaos, qacs, bratbls, qcos, tcos, Prjshort, id, hasqwr, (bras.nodes.size() > 0), (filts.nodes.size() > 0), 0);

		if (bras.nodes.size() > 0) outfile << "\t};" << endl;
		outfile << endl;

	} else if ((qry->ixVBasetype == VecWznmVMQueryBasetype::LIST) || (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST)) {
		getBratbls(dbswznm, 0, tbls, comtbls, bratbls);

		dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);

		writeQry(dbswznm, outfile, qry, qtb, filts, qaos, qacs, bratbls, qcos, tcos, Prjshort, "\t", hasqwr, false, false, 0);
		outfile << endl;
	};

	// FUTURE: jovrs go here
	// ex.:
/*
	if (qmd1Avail) {
		sqlstr = "UPDATE TblPlnrQDvcHk1NVertex, TblPlnrJMVertex";
		sqlstr += " SET TblPlnrQDvcHk1NVertex.x = TblPlnrJMVertex.x, TblPlnrQDvcHk1NVertex.y = TblPlnrJMVertex.y";
		sqlstr += " WHERE TblPlnrQDvcHk1NVertex.jref = " + to_string(jref);
		sqlstr += " AND TblPlnrQDvcHk1NVertex.ref = TblPlnrJMVertex.refPlnrMVertex";
		sqlstr += " AND TblPlnrJMVertex.x1RefPlnrMDesign = " + to_string(preRefModdsn);
		dbsplnr->executeQuery(sqlstr);
	};
*/

	outfile << "\tsqlstr = \"UPDATE " << qtb->sref << " SET jnum = qref WHERE jref = \" + to_string(jref);" << endl;
	outfile << "\tdbs" << prjshort << "->executeQuery(sqlstr);" << endl;
	outfile << endl;

	outfile << "\tix" << Prjshort << "VQrystate = Vec" << Prjshort << "VQrystate::UTD;" << endl;
	if (qry->Limofs) outfile << "\tstatshr.jnumFirstload = stgiac.jnumFirstload;" << endl;
	outfile << endl;

	outfile << "\tfetch(dbs" << prjshort << ");" << endl;
	outfile << endl;

	outfile << "\tif (call) xchg->triggerCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "STATCHG, jref);" << endl;
	outfile << endl;

	// re-establish call listeners
	if (lrefqry) _qry = lrefqry;
	else _qry = qry;

	dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(_qry->ref) + " AND x1RefWznmMQuerymod = 0 ORDER BY qryNum ASC", false, qacs);

	for (unsigned int i = 0; i < cals.nodes.size(); i++) {
		cal = cals.nodes[i];

		if (cal->invIxWznmWArgtype != 0) {
			// disect call sref to find concerned tco's / preset's
			ss.clear();

			ptr = cal->sref.rfind('.');
			if (ptr != string::npos) {
				s = cal->sref.substr(ptr+1);

				ptr = s.rfind("Eq");
				if ((ptr+2) == s.length()) {
					s = StrMod::cap(s.substr(0, s.length()-2));
					
					for (unsigned int j=s.length();j>0;j--) {
						if ((s[j-1] >= 'A') && (s[j-1] <= 'Z')) {
							ss.push_back(StrMod::lc(s.substr(j-1)));
							s = s.substr(0, j-1);
						};
					};
				};
			};

			// ss from tco->Short to tco->sref
			for (unsigned int j = 0; j < ss.size(); j++) dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(cal->refUref) + " AND Short = '" + ss[j] + "'", ss[j]);

			// ss from tco->sref to argument for add...Clstn() call
			for (unsigned int j = 0; j < ss.size(); j++) {
				for (unsigned int k = 0; k < qacs.nodes.size(); k++) {
					qac = qacs.nodes[k];

					if (qac->Clause.find(ss[j]) != string::npos) {
						if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::PRE) {
							for (unsigned int l = 0; l < psts.nodes.size(); l++) {
								pst = psts.nodes[l];
								if (pst->ref == qac->refWznmMPreset) {
									ss[j] = getPstVar(pst->sref);
									break;
								};
							};

							break;

						} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::VIT) {
							dbswznm->tblwznmmvector->loadSrfByRef(qac->refWznmMVector, ss[j]);
							if (dbswznm->tblwznmmvectoritem->loadSrfByRef(qac->refWznmMVectoritem, s)) ss[j] += "::" + StrMod::uc(StrMod::dotToUsc(s));

							break;
						};
					};
				};
			};

			// compile add...Clstn() call
			if ( (((cal->invIxWznmWArgtype == VecWznmWArgtype::IX) || (cal->invIxWznmWArgtype == VecWznmWArgtype::REF)) && (ss.size() == 1))
					|| ((cal->invIxWznmWArgtype == (VecWznmWArgtype::IX+VecWznmWArgtype::REF)) && (ss.size() == 2))
					|| ((cal->invIxWznmWArgtype == (VecWznmWArgtype::IX+VecWznmWArgtype::REF+VecWznmWArgtype::SREF)) && (ss.size() == 3)) ) {

				outfile << "\txchg->add";
				if (cal->invIxWznmWArgtype & VecWznmWArgtype::IX) outfile << "Ix";
				if (cal->invIxWznmWArgtype & VecWznmWArgtype::REF) outfile << "Ref";
				if (cal->invIxWznmWArgtype & VecWznmWArgtype::SREF) outfile << "Sref";
				outfile << "Clstn(Vec" << Prjshort << "VCall::" << StrMod::uc(StrMod::dotToUsc(cal->sref)) << ", jref, Clstn::VecVJobmask::ALL, 0, false";
				if (cal->invIxWznmWArgtype & VecWznmWArgtype::IX) {
					if (cal->invIxWznmWArgtype & VecWznmWArgtype::REF) outfile << ", " << ss[1];
					else outfile << ", " << ss[0];
				};
				if (cal->invIxWznmWArgtype & VecWznmWArgtype::REF) outfile << ", " << ss[0];
				if (cal->invIxWznmWArgtype & VecWznmWArgtype::SREF) {
					outfile << ", ";

					ptr = ss[2].find("::");
					if (ptr != string::npos) outfile << ss[2].substr(0, ptr);

					outfile << "::getSref(" << ss[2] << ")";
				};
				outfile << ");" << endl;
			};
		};
	};

	outfile << "};" << endl;
	outfile << endl;

	if (((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) && (exbras.nodes.size() > 0))
				|| ((qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) && (bras.nodes.size() > 0))) {
		// -- rerun_baseSQL
		outfile << "void " << qry->sref << "::rerun_baseSQL(" << endl;
		outfile << "\t\t\tstring& sqlstr" << endl;
		outfile << "\t\t) {" << endl;

		writeBaseSQL(outfile, qtb, qcos, tcos, hasqwr);

		outfile << "};" << endl;
		outfile << endl;
	};

	if ( ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) && (filts.nodes.size() > 0) ) {
		// -- rerun_filtSQL
		getUnqicsQmdpsts(filts, unqicsFilts);

		outfile << "void " << qry->sref << "::rerun_filtSQL(" << endl;
		outfile << "\t\t\tstring& sqlstr" << endl;

		for (unsigned int i = 0; i < unqicsFilts.size(); i++) {
			filt = filts.nodes[unqicsFilts[i]];

			if (dbswznm->tblwznmmpreset->loadRecByRef(filt->refWznmMPreset, &pst)) {
				outfile << "\t\t\t, const " << getPstCppType(pst->ixWznmWArgtype, true) << " " << getPstVar(pst->sref) << endl;
				delete pst;
			};
		};

		outfile << "\t\t\t, const bool addwhere" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tbool first = addwhere;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < filts.nodes.size(); i++) {
			filt = filts.nodes[i];

			dbswznm->tblwznmamqueryclause->loadRstBySQL("SELECT * FROM TblWznmAMQueryClause WHERE qryRefWznmMQuery = " + to_string(qry->ref) + " AND x1RefWznmMQuerymod = " + to_string(filt->ref) + " ORDER BY qryNum ASC", false, qacs);
			
			for (unsigned int j = 0; j < qacs.nodes.size(); j++) {
				qac = qacs.nodes[j];

				if (dbswznm->tblwznmmpreset->loadRecByRef(filt->refWznmMPreset, &pst)) {
					outfile << endl;

					outfile << "\tif (" << getPstVar(pst->sref);
					if (pst->ixWznmWArgtype == VecWznmWArgtype::IX) outfile << " != 0";
					else if (pst->ixWznmWArgtype == VecWznmWArgtype::REF) outfile << " != 0";
					else if (pst->ixWznmWArgtype == VecWznmWArgtype::SREF) outfile << ".length() > 0";
					else if (pst->ixWznmWArgtype == VecWznmWArgtype::INTVAL) outfile << " != numeric_limits<int>::min()";
					else if (pst->ixWznmWArgtype == VecWznmWArgtype::DBLVAL) outfile << " != -numeric_limits<double>::infinity()";
					else if (pst->ixWznmWArgtype == VecWznmWArgtype::BOOLVAL) outfile << " == true";
					else if (pst->ixWznmWArgtype == VecWznmWArgtype::TXTVAL) outfile << ".length() > 0";
					outfile << ") {" << endl;

					outfile << "\t\trerun_filtSQL_append(sqlstr, first);" << endl;

					outfile << "\t\tsqlstr += \"";
					if (j != 0) outfile << " AND ";
					writeQac(dbswznm, outfile, qac, Prjshort);
					
					outfile << "\t};" << endl;

					delete pst;
				};
			};
		};

		outfile << "};" << endl;
		outfile << endl;

		// -- rerun_filtSQL_append
		outfile << "void " << qry->sref << "::rerun_filtSQL_append(" << endl;
		outfile << "\t\t\tstring& sqlstr" << endl;
		outfile << "\t\t\t, bool& first" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tif (first) {" << endl;
		outfile << "\t\tsqlstr += \" WHERE \";" << endl;
		outfile << "\t\tfirst = false;" << endl;
		outfile << "\t} else sqlstr += \" AND \";" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if ( ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) && (qaos.nodes.size() > 1) ) {
		// -- rerun_orderSQL
		outfile << "void " << qry->sref << "::rerun_orderSQL(" << endl;
		outfile << "\t\t\tstring& sqlstr" << endl;
		outfile << "\t\t\t, const uint preIxOrd" << endl;
		outfile << "\t\t) {" << endl;

		for (unsigned int i = 0; i < qaos.nodes.size(); i++) {
			qao = qaos.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "else ";
			outfile << "if (preIxOrd == VecVOrd::" << StrMod::uc(qao->Short) << ") sqlstr += \" ORDER BY";

			StrMod::srefsToVector(qao->srefsWznmMTablecol, ss);
			for (unsigned int j = 0; j < ss.size(); j++) {
				if (j != 0) outfile << ",";
				outfile << " " << ss[j] << " ASC";
			};

			outfile << "\";" << endl;
		};

		outfile << "};" << endl;
		outfile << endl;
	};

	if (qry->ixVBasetype != VecWznmVMQueryBasetype::MULTBRA) {
		// -- evalQmdXAvail
		for (unsigned int i = 0; i < exbras.nodes.size(); i++) {
			exbra = exbras.nodes[i];

			if (exbra->Avail.length() > 0) {
				outfile << "bool " << qry->sref << "::evalQmd" << exbra->qryNum << "Avail() {" << endl;

				if (expr.tokenize(exbra->Avail)) {
					if (expr.parse()) {
						outfile << "\tvector<bool> args;" << endl;
						if (expr.has(Expr::VecVNodetype::FCT, "and") || expr.has(Expr::VecVNodetype::FCT, "or")) outfile << "\tbool a, b;" << endl;
						else outfile << "\tbool a;" << endl;
						outfile << endl;

						writeBooleval(dbswznm, Prjshort, outfile, job->refWznmMVersion, rectbls, expr.root);
						outfile << endl;

						outfile << "\treturn(args.back());" << endl;

					} else {
						outfile << "\treturn false;" << endl;
					};
				} else {
					outfile << "\treturn false;" << endl;
				};

				outfile << "};" << endl;
				outfile << endl;
			};
		};
	};

	// -- fetch
	outfile << "void " << qry->sref << "::fetch(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << StrMod::lc(Prjshort) << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tstring sqlstr;" << endl;
	outfile << endl;

	outfile << "\tStmgr" << Prjshort << "* stmgr = NULL;" << endl;
	outfile << "\tStcch* stcch = NULL;" << endl;
	outfile << endl;

	outfile << "\t" << qtb->sref.substr(3) << "* rec = NULL;" << endl;
	outfile << endl;

	// dominant presetting if needed
	found = false;
	for (unsigned int i = 0; i < allqcos.nodes.size(); i++) {
		qco = allqcos.nodes[i];

		if ( (qco->ixVBasetype == VecWznmVMQuerycolBasetype::STUB) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::HSTUB) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::USTUB) ) {
			dbswznm->tblwznmjmquerycolstub->loadRstByQco(qco->ref, false, qjss);

			for (unsigned int j = 0; j < qjss.nodes.size(); j++) {
				qjs = qjss.nodes[j];

				if (qjs->x2RefWznmMPreset != 0) {
					found = true;
					break;
				};
			};
		};

		if (found) break;
	};

	if (found) {
		outfile << "\tuint preIxPre = xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXPRE, jref);" << endl;
		outfile << endl;
	};

	// jump table record declarations
	for (unsigned int i = 0; i < jovrs.nodes.size(); i++) {
		jovr = jovrs.nodes[i];

		if (jovr->refIxVTbl == VecWznmVMQuerymodRefTbl::TBL) {
			if (dbswznm->tblwznmmtable->loadRecByRef(jovr->refUref, &tbl)) {
				dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tco2s);

				spttco2 = NULL;

				for (unsigned int j = 0; j < tco2s.nodes.size(); j++) {
					tco2 = tco2s.nodes[j];

					if (tco2->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID) {
						spttco2 = tco2;
						break;
					};
				};

				if (spttco2) {
					if (spttco2->ixVAxisfct != VecWznmVMTablecolAxisfct::PT) outfile << "\tList" << tbl->sref.substr(3) << " " << tbl->Short << "s;" << endl;
					outfile << "\t" << tbl->sref.substr(3) << "* " << tbl->Short << " = NULL;" << endl;
				};

				delete tbl;
			};
		};
	};
	outfile << endl;

	// "S" (1nsub1n) and "T" (mnsubmn) table record declarations
	for (unsigned int i = 0; i < stovrs.nodes.size(); i++) {
		stovr = stovrs.nodes[i];

		if (stovr->refIxVTbl == VecWznmVMQuerymodRefTbl::TBL) {
			if (dbswznm->tblwznmmtable->loadRecByRef(stovr->refUref, &tbl)) {
				outfile << "\tList" << tbl->sref.substr(3) << " " << tbl->Short << "s;" << endl;
				outfile << "\t" << tbl->sref.substr(3) << "* " << tbl->Short << " = NULL;" << endl;

				delete tbl;
			};
		};
	};
	outfile << endl;

	// presettings for record-wise overwrite
	getUnqicsQmdpsts(jovrs, unqicsRecovrs);

	for (unsigned int i = 0; i < unqicsRecovrs.size(); i++) {
		jovr = jovrs.nodes[unqicsRecovrs[i]];

		if (dbswznm->tblwznmmpreset->loadRecByRef(jovr->refWznmMPreset, &pst)) {
			outfile << "\t" << getPstCppType(pst->ixWznmWArgtype) << " " << getPstVar(pst->sref) << " = xchg->get" << StrMod::cap(VecWznmWArgtype::getSrefs(pst->ixWznmWArgtype))
						<< "Preset(Vec" << Prjshort << "VPreset::" << StrMod::uc(StrMod::dotToUsc(pst->sref)) << ", jref);" << endl;
			delete pst;
		};
	};
	outfile << endl;

	outfile << "\tdbs" << StrMod::lc(Prjshort) << "->" << StrMod::lc(qtb->sref) << "->loadRstByJref(jref, false, rst);" << endl;
	if (qry->Limofs) outfile << "\tstatshr.nload = rst.nodes.size();" << endl;
	outfile << endl;

	outfile << "\tstmgr = xchg->getStmgrByJref(jref);" << endl;
	outfile << endl;

	outfile << "\tif (stmgr) {" << endl;
	outfile << "\t\tstmgr->begin();" << endl;
	outfile << endl;

	outfile << "\t\tstcch = stmgr->stcch;" << endl;
	outfile << "\t\tstcch->clear();" << endl;
	outfile << endl;

	outfile << "\t\tfor (unsigned int i = 0; i < rst.nodes.size(); i++) {" << endl;
	outfile << "\t\t\trec = rst.nodes[i];" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < jovrs.nodes.size(); i++) {
		jovr = jovrs.nodes[i];

		// NOTE: dual jump overrides (type TblWznmJMControlStub) aren't covered yet
		// dual overrides don't fit into the jovr scheme (two preset's would be required)

		if (dbswznm->tblwznmmpreset->loadRecByRef(jovr->refWznmMPreset, &pst)) {
			if (jovr->refIxVTbl == VecWznmVMQuerymodRefTbl::TBL) {
				if (dbswznm->tblwznmmtable->loadRecByRef(jovr->refUref, &tbl)) {
					dbswznm->tblwznmmtablecol->loadRstByTbl(tbl->ref, false, tco2s);

					spttco2 = NULL;
					epttco2 = NULL;

					for (unsigned int j = 0; j < tco2s.nodes.size(); j++) {
						tco2 = tco2s.nodes[j];

						if (j == 1) psttco2 = tco2;
						else if (tco2->ixVAxisfct != VecWznmVMTablecolAxisfct::VOID) {
							if (tco2->sref.find("x1") != 0) break;

							if (!spttco2) spttco2 = tco2;
							else {
								epttco2 = tco2;
								break;
							};
						};
					};

					if (spttco2) {
						if (spttco2->ixVAxisfct == VecWznmVMTablecolAxisfct::PT) {
							outfile << "\t\t\tif (dbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRecBy" << StrMod::cap(psttco2->Short) << StrMod::cap(spttco2->Short) << "(rec->ref, " << getPstVar(pst->sref) << ", &" << tbl->Short << ")) {" << endl;

						} else {
							outfile << "\t\t\tdbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRstBy" << StrMod::cap(psttco2->Short) << "(rec->ref, false, " << tbl->Short << "s);" << endl;
							outfile << "\t\t\tfor (unsigned int j = 0; j < " << tbl->Short << "s.nodes.size(); j++) {" << endl;
							outfile << "\t\t\t\t" << tbl->Short << " = " << tbl->Short << "s.nodes[j];" << endl;

							if (epttco2) {
								// exact interval fit
								outfile << "\t\t\t\tif ((" << getPstVar(pst->sref) << " >= " << tbl->Short << "->" << spttco2->sref << ") && (" << getPstVar(pst->sref) << " <= " << tbl->Short << "->" << epttco2->sref << ")) {" << endl;
							} else {
								// should be spt
								outfile << "\t\t\t\tif (" << getPstVar(pst->sref) << " >= " << tbl->Short << "->" << spttco2->sref << ") {" << endl;
							};
						};

						// overwrite
						for (unsigned int j = 0; j < tco2s.nodes.size(); j++) {
							tco2 = tco2s.nodes[j];

							if ((tco2->ixVBasetype != VecWznmVMTablecolBasetype::IDREF) && (tco2->ixVAxisfct == VecWznmVMTablecolAxisfct::VOID)) {
								for (unsigned int k = 0; k < alltcos.nodes.size(); k++) {
									tco = alltcos.nodes[k];
									
									if (tco) {
										if (tco->sref == tco2->sref) {
											// copy from corresponding tco in corresponding main/aux table
											if (spttco2->ixVAxisfct != VecWznmVMTablecolAxisfct::PT) outfile << "\t";
											outfile << "\t\t\t\trec->" << tco->sref << " = " << tbl->Short << "->" << tco->sref << ";" << endl;

											break;
										};
									};
								};
							};
						};

						if (spttco2->ixVAxisfct == VecWznmVMTablecolAxisfct::PT) {
							outfile << "\t\t\t\tdelete " << tbl->Short << ";" << endl;

						} else {
							if (epttco2) outfile << "\t\t\t\t\tbreak;" << endl;
							outfile << "\t\t\t\t};" << endl;
						};

						outfile << "\t\t\t};" << endl;
					};
					
					delete tbl;
				};
			};

			delete pst;
		};
	};

	for (unsigned int i = 0; i < allqcos.nodes.size(); i++) {
		qco = allqcos.nodes[i];
		tco = alltcos.nodes[i]; // possible that this is a NULL pointer

		if (tco) {
			// add prefix where required
			if (tco->tblRefWznmMTable != qry->refWznmMTable) {
				for (unsigned int j = 0; j < tbls.nodes.size(); j++) {
					tbl = tbls.nodes[j];

					if (tbl->ref == tco->tblRefWznmMTable) {
						tco->sref = tblpfxs[j] + tco->sref;
						break;
					};
				};
			};
		};

		if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::STUB) {

			if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {
				// determine vector and corresponding tco
				if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND tblRefWznmMTable = " + to_string(tco->tblRefWznmMTable)
							+ " AND refWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND sref LIKE '%VTbl'", &tco2)) {
					if (dbswznm->tblwznmmvector->loadRecByRef(tco2->fctUref, &vec)) {

						// outer loop: vector items
						dbswznm->loadRefsBySQL("SELECT DISTINCT x1RefWznmMVectoritem FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(qco->ref), false, refs);

						first = true;

						for (unsigned int j = 0; j < refs.size(); j++) {
							if (dbswznm->tblwznmmvectoritem->loadRecByRef(refs[j], &vit)) {

								outfile << "\t\t\t";

								if (first) first = false;
								else outfile << "} else ";

								outfile << "if (rec->" << tco2->sref << " == " << vec->sref << "::" << StrMod::uc(vit->sref) << ") {" << endl;

								// inner loop: presettings
								dbswznm->tblwznmjmquerycolstub->loadRstBySQL("SELECT * FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(qco->ref) + " AND x1RefWznmMVectoritem = " + to_string(refs[j]) + " ORDER BY x2RefWznmMPreset DESC", false, qjss);

								first2 = true;

								// qjss.nodes.size() > 0 guaranteed
								for (unsigned int k = 0; k < qjss.nodes.size(); k++) {
									qjs = qjss.nodes[k];

									if (dbswznm->tblwznmmstub->loadRecByRef(qjs->refWznmMStub, &stb)) {
										if (qjs->x2RefWznmMPreset == 0) {
											outfile << "\t\t\t\t";

											if (first2) first2 = false;
											else outfile << "else ";

											outfile << "rec->" << qco->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::SHORT, stcch);" << endl;

										} else {
											if (dbswznm->tblwznmmpreset->loadRecByRef(qjs->x2RefWznmMPreset, &pst)) {
												outfile << "\t\t\t\t";

												if (first2) first2 = false;
												else outfile << "else ";

												outfile << "if (preIxPre == Vec" << Prjshort << "VPreset::" << StrMod::uc(StrMod::dotToUsc(pst->sref)) << ") ";
												outfile << "rec->" << qco->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::SHORT, stcch);" << endl;

												delete pst;
											};
										};

										delete stb;
									};
								};

								if (first2) outfile << "\t\t\t\trec->" << qco->sref << " = \"-\";" << endl;

								delete vit;
							};
						};

						outfile << "\t\t\t";
						if (!first) outfile << "} else ";
						outfile << "rec->" << qco->sref << " = \"-\";" << endl;

						delete vec;
					};

					delete tco2;
				};

			} else {
				// specific table reference: multiple stub's possible, depending on preset
				first2 = true;

				if (qco->refWznmMStub != 0) {
					if (dbswznm->tblwznmmstub->loadRecByRef(qco->refWznmMStub, &stb)) {
						outfile << "\t\t\trec->" << qco->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::SHORT, stcch);" << endl;
						first2 = false;

						delete stb;
					};

				} else {
					dbswznm->tblwznmjmquerycolstub->loadRstBySQL("SELECT * FROM TblWznmJMQuerycolStub WHERE refWznmMQuerycol = " + to_string(qco->ref) + " ORDER BY x2RefWznmMPreset DESC", false, qjss);

					for (unsigned int k = 0; k < qjss.nodes.size(); k++) {
						qjs = qjss.nodes[k];

						if (dbswznm->tblwznmmstub->loadRecByRef(qjs->refWznmMStub, &stb)) {
							if (qjs->x2RefWznmMPreset == 0) {
								outfile << "\t\t\t";

								if (first2) first2 = false;
								else outfile << "else ";

								outfile << "rec->" << qco->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::SHORT, stcch);" << endl;

							} else {
								if (dbswznm->tblwznmmpreset->loadRecByRef(qjs->x2RefWznmMPreset, &pst)) {
									outfile << "\t\t\t";

									if (first2) first2 = false;
									else outfile << "else ";

									outfile << "if (preIxPre == Vec" << Prjshort << "VPreset::" << StrMod::uc(StrMod::dotToUsc(pst->sref)) << ") ";
									outfile << "rec->" << qco->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::SHORT, stcch);" << endl;

									delete pst;
								};
							};

							delete stb;
						};
					};
				};

				if (first2) outfile << "\t\t\trec->" << qco->sref << " = \"-\";" << endl;
			};

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::HSTUB) {
		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::USTUB) {
			// default stub for uref's

			// find ixXxxxVMaintable tco
			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND tblRefWznmMTable = " + to_string(tco->tblRefWznmMTable)
						+ " AND refWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND sref LIKE '%VTbl'", &tco2)) {

				dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMTableBasetype::MAIN) + " ORDER BY sref ASC", false, mtbs);

				for (unsigned int j = 0; j < mtbs.nodes.size(); j++) {
					mtb = mtbs.nodes[j];
					
					outfile << "\t\t\t";

					if (j != 0) outfile << "else ";

					outfile << "if (rec->" << tco2->sref << " == Vec" << Prjshort << "VMaintable::" << StrMod::uc(mtb->sref) << ") ";
					outfile << "rec->" << qco->sref << " = Stub" << Prjshort << "::getStub" << StrMod::cap(mtb->Short) << "Std(dbs" << prjshort << ", rec->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::SHORT, stcch);" << endl;
				};

				outfile << "\t\t\t";
				if (mtbs.nodes.size() > 0) outfile << "else ";
				outfile << "rec->" << qco->sref << " = \"-\";" << endl;

				delete tco2;
			};

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::STUBS) {
			found = false;
			for (unsigned int j = 0; j < stovrs.nodes.size(); j++) {
				stovr = stovrs.nodes[j];
				if ((stovr->refIxVTbl == VecWznmVMQuerymodRefTbl::TBL) && (stovr->refUref == tco->tblRefWznmMTable)) {
					found = dbswznm->tblwznmmtable->loadRecByRef(stovr->refUref, &tbl);
					break;
				};
			};

			if (found) {
				if (dbswznm->tblwznmmstub->loadRecByRef(qco->refWznmMStub, &stb)) {
					outfile << "\t\t\tdbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->";
					if (tbl->ixVBasetype == VecWznmVMTableBasetype::SUB1N) outfile << "loadRstByM";
					else if (tbl->ixVBasetype == VecWznmVMTableBasetype::SUBMN) outfile << "loadRstByR";
					outfile << "(rec->ref, false, " << tbl->Short << "s);" << endl;
					outfile << "\t\t\tfor (unsigned int j = 0; j < " << tbl->Short << "s.nodes.size(); j++) {" << endl;
					outfile << "\t\t\t\t" << tbl->Short << " = " << tbl->Short << "s.nodes[j];" << endl;
					outfile << "\t\t\t\tif (j != 0) rec->" << qco->sref << " += \";\";" << endl;
					outfile << "\t\t\t\trec->" << qco->sref << " += Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", " << tbl->Short << "->" << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::DASH, stcch);" << endl;
					outfile << "\t\t\t};" << endl;

					delete stb;
				};
				
				delete tbl;
			};

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::VSREF) {
			// find vector
			if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
				if (vec->ixVBasetype == VecWznmVMVectorBasetype::OR) {
					outfile << "\t\t\trec->" << qco->sref << " = " << vec->sref << "::getSrefs(rec->" << tco->sref << ");" << endl;
				} else {
					outfile << "\t\t\trec->" << qco->sref << " = " << vec->sref << "::getSref(rec->" << tco->sref << ");" << endl;
				};
				delete vec;
			};

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::VSREFS) {
			// find vector
			if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
				outfile << "\t\t\trec->" << qco->sref << " = " << vec->sref << "::getSrefs(rec->" << tco->sref << ");" << endl;
				delete vec;
			};

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::VTIT) {
			// find vector
			if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
				if (vec->ixVBasetype == VecWznmVMVectorBasetype::KLST) {
					outfile << "\t\t\trec->" << qco->sref << " = dbs" << prjshort << "->getKlstTitleBySref(Vec" << Prjshort << "VKeylist::" << StrMod::uc(vec->sref) << ", rec->" << tco->sref << ", ix" << Prjshort << "VLocale);" << endl;
				} else {
					outfile << "\t\t\trec->" << qco->sref << " = " << vec->sref << "::getTitle(rec->" << tco->sref;
					if (!StrMod::srefInSrefs(vec->srefsKOption, "noloc")) outfile << ", ix" << Prjshort << "VLocale";
					outfile << ");" << endl;
				};

				delete vec;
			};

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::VTITS) {
		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::YESNO) {
			outfile << "\t\t\tif (rec->" << tco->sref << ") rec->" << qco->sref << " = Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::YES, ix" << Prjshort << "VLocale);"
						<< " else rec->" << qco->sref << " = Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::NO, ix" << Prjshort << "VLocale);" << endl;

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::FTMDATE) {
			outfile << "\t\t\trec->" << qco->sref << " = Ftm::date(rec->" << tco->sref << ");" << endl;

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::FTMTIME) {
			outfile << "\t\t\trec->" << qco->sref << " = Ftm::time(rec->" << tco->sref << ");" << endl;

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::FTMSTAMP) {
			outfile << "\t\t\trec->" << qco->sref << " = Ftm::stamp(rec->" << tco->sref << ");" << endl;

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::FTMUSTAMP) {
			outfile << "\t\t\trec->" << qco->sref << " = Ftm::usecstamp(rec->" << tco->sref << ");" << endl;

		} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QJENUM) {
			if (qry->Limofs) {
				outfile << "\t\t\trec->" << qco->sref << " = statshr.jnumFirstload + i;" << endl;
			} else {
				outfile << "\t\t\trec->" << qco->sref << " = i+1;" << endl;
			};
		};
	};

	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t\tstmgr->commit();" << endl;
	outfile << "\t\tstmgr->unlockAccess(\"" << qry->sref << "\", \"fetch\");" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\trefreshJnum();" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- getJnumByRef
	outfile << "uint " << qry->sref << "::getJnumByRef(" << endl;
	outfile << "\t\t\tconst ubigint ref" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tuint retval = 0;" << endl;
	outfile << endl;

	outfile << "\t" << qtb->sref.substr(3) << "* rec = NULL;" << endl;
	outfile << endl;

	outfile << "\tfor (unsigned int i = 0; i < rst.nodes.size(); i++) {" << endl;
	outfile << "\t\trec = rst.nodes[i];" << endl;
	outfile << endl;

	outfile << "\t\tif (rec->ref == ref) {" << endl;
	outfile << "\t\t\tretval = rec->jnum;" << endl;
	outfile << "\t\t\tbreak;" << endl;
	outfile << "\t\t};" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\treturn retval;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- getRefByJnum
	outfile << "ubigint " << qry->sref << "::getRefByJnum(" << endl;
	outfile << "\t\t\tconst uint jnum" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tuint ref = 0;" << endl;
	outfile << endl;

	outfile << "\t" << qtb->sref.substr(3) << "* rec = getRecByJnum(jnum);" << endl;
	outfile << "\tif (rec) ref = rec->ref;" << endl;

	outfile << "\treturn ref;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- getRecByJnum
	outfile << qtb->sref.substr(3) << "* " << qry->sref << "::getRecByJnum(" << endl;
	outfile << "\t\t\tconst uint jnum" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\t" << qtb->sref.substr(3) << "* rec = NULL;" << endl;
	outfile << endl;

	outfile << "\tfor (unsigned int i = 0; i < rst.nodes.size(); i++) {" << endl;
	outfile << "\t\trec = rst.nodes[i];" << endl;
	outfile << "\t\tif (rec->jnum == jnum) break;" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\tif (rec) if (rec->jnum != jnum) rec = NULL;" << endl;
	outfile << "\treturn rec;" << endl;
	outfile << "};" << endl;
	
	outfile << "// IP spec --- IEND" << endl;

	// --- handleRerun
	outfile << "// IP handleRerun --- IBEGIN" << endl;
	if (qry->Limofs) {
		outfile << "\tstring input;" << endl;
		outfile << endl;

		outfile << "\tcout << \"\\tjnumFirstload (\" << stgiac.jnumFirstload << \"): \";" << endl;
		outfile << "\tcin >> input;" << endl;
		outfile << "\tstgiac.jnumFirstload = atol(input.c_str());" << endl;
		outfile << "\tcout << \"\\tnload (\" << stgiac.nload << \"): \";" << endl;
		outfile << "\tcin >> input;" << endl;
		outfile << "\tstgiac.nload = atol(input.c_str());" << endl;
		outfile << endl;
	};

	outfile << "\trerun(dbs" << StrMod::lc(Prjshort) << ");" << endl;
	outfile << "// IP handleRerun --- IEND" << endl;

	// --- handleShow
	outfile << "// IP handleShow --- IBEGIN" << endl;

	outfile << "\t" << qtb->sref.substr(3) << "* rec = NULL;" << endl;
	outfile << endl;

	outfile << "\t// header row" << endl;

	for (unsigned int i = 0; i < allqcos.nodes.size(); i++) {
		qco = allqcos.nodes[i];
		outfile << "\tcout << \"\\t" << qco->sref << "\";" << endl;
	};
	outfile << "\tcout << endl;" << endl;
	outfile << endl;

	outfile << "\t// record rows" << endl;
	outfile << "\tfor (unsigned int i = 0; i < rst.nodes.size(); i++) {" << endl;
	outfile << "\t\trec = rst.nodes[i];" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < allqcos.nodes.size(); i++) {
		qco = allqcos.nodes[i];
		outfile << "\t\tcout << \"\\t\" << rec->" << qco->sref << ";" << endl;
	};
	outfile << "\t\tcout << endl;" << endl;
	outfile << "\t};" << endl;
	outfile << "// IP handleShow --- IEND" << endl;

	// --- handleCallXxxxStubChg
	outfile << "// IP handleCall" << Prjshort << "StubChg --- IBEGIN" << endl;
	outfile << endl;

	outfile << "\tif (ix" << Prjshort << "VQrystate == Vec" << Prjshort << "VQrystate::UTD) {" << endl;
	outfile << "\t\tix" << Prjshort << "VQrystate = Vec" << Prjshort << "VQrystate::SLM;" << endl;
	outfile << "\t\txchg->triggerCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "STATCHG, jref);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "// IP handleCall" << Prjshort << "StubChg --- IEND" << endl;

	// --- handleCallXxxxYyyUpd_refEq
	if (recupdcal) {
		outfile << "// IP handle" << StrMod::dotToUsc(recupdcal->sref) << " --- IBEGIN" << endl;
		outfile << endl;

		outfile << "\tif (ix" << Prjshort << "VQrystate != Vec" << Prjshort << "VQrystate::OOD) {" << endl;
		outfile << "\t\tix" << Prjshort << "VQrystate = Vec" << Prjshort << "VQrystate::OOD;" << endl;
		outfile << "\t\txchg->triggerCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "STATCHG, jref);" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "// IP handle" << StrMod::dotToUsc(recupdcal->sref) << " --- IEND" << endl;
	};

	for (unsigned int i = 0; i < cals.nodes.size(); i++) {
		cal = cals.nodes[i];

		if (cal->invIxWznmWArgtype == 0) {
			// --- handleCallXxxxYyyMod
			outfile << "// IP handle" << StrMod::dotToUsc(cal->sref) << " --- IBEGIN" << endl;
			outfile << endl;

			outfile << "\tif ((ix" << Prjshort << "VQrystate == Vec" << Prjshort << "VQrystate::UTD) || (ix" << Prjshort << "VQrystate == Vec" << Prjshort << "VQrystate::SLM)) {" << endl;
			outfile << "\t\tix" << Prjshort << "VQrystate = Vec" << Prjshort << "VQrystate::MNR;" << endl;
			outfile << "\t\txchg->triggerCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "STATCHG, jref);" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "// IP handle" << StrMod::dotToUsc(cal->sref) << " --- IEND" << endl;

		} else {
			// --- handleCallXxxxYyyMod_zzzEq
			outfile << "// IP handle" << StrMod::dotToUsc(cal->sref) << " --- IBEGIN" << endl;
			outfile << endl;

			outfile << "\tif (ix" << Prjshort << "VQrystate != Vec" << Prjshort << "VQrystate::OOD) {" << endl;
			outfile << "\t\tix" << Prjshort << "VQrystate = Vec" << Prjshort << "VQrystate::OOD;" << endl;
			outfile << "\t\txchg->triggerCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "STATCHG, jref);" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "// IP handle" << StrMod::dotToUsc(cal->sref) << " --- IEND" << endl;
		};
	};

	if (recupdcal) delete recupdcal;
};

void WznmWrsrvQry::writeCnt(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMQuery* qry
			, WznmMTable* tbl
			, vector<string>& bratbls
			, ListWznmAMQueryClause& qacs
			, ListWznmMQuerymod& filts
			, const string& Prjshort
			, const string& id
		) {
	WznmAMQueryClause* qac = NULL;

	vector<unsigned int> unqicsFilts;
	WznmMQuerymod* filt = NULL;

	WznmMPreset* pst = NULL;

	string prjshort = StrMod::lc(Prjshort);

	outfile << id << "sqlstr = \"SELECT COUNT(" << tbl->sref << ".ref)\";" << endl;

	outfile << id << "sqlstr += \" FROM";
	for (unsigned int i = 0; i < bratbls.size(); i++) {
		if (i != 0) outfile << ",";
		outfile << " " << bratbls[i];
	};
	outfile << "\";" << endl;

	for (unsigned int i = 0; i < qacs.nodes.size(); i++) {
		qac = qacs.nodes[i];

		outfile << id << "sqlstr += \"";
		if (i == 0) outfile << " WHERE "; else outfile << " AND ";

		writeQac(dbswznm, outfile, qac, Prjshort);
	};

	if (filts.nodes.size() > 0) {
		getUnqicsQmdpsts(filts, unqicsFilts);

		outfile << id << "rerun_filtSQL(sqlstr";

		for (unsigned int i = 0; i < unqicsFilts.size(); i++) {
			filt = filts.nodes[unqicsFilts[i]];

			if (dbswznm->tblwznmmpreset->loadRecByRef(filt->refWznmMPreset, &pst)) {
				outfile << ", " << getPstVar(pst->sref);
				delete pst;
			};
		};

		outfile << ", ";
		if (qacs.nodes.size() == 0) outfile << "true"; else outfile << "false";
		outfile << ");" << endl;
	};

	outfile << id << "dbs" << prjshort << "->loadUintBySQL(sqlstr, cnt);" << endl;
	if (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) {
		outfile << id << "cnts.push_back(cnt); lims.push_back(0); ofss.push_back(0);" << endl;
		outfile << id << "cntsum += cnt;" << endl;
	};
};

void WznmWrsrvQry::writeLrefqry(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMQuery* qry
			, WznmMTable* lreftbl
			, ListWznmAMQueryClause& qacs
			, WznmAMQueryOrder* lrefqao
			, const string& Prjshort
			, const string& id
		) {
	WznmAMQueryClause* qac = NULL;

	string prjshort = StrMod::lc(Prjshort);

	outfile << id << "sqlstr = \"SELECT ref FROM " << lreftbl->sref << "\";" << endl;
	for (unsigned int i = 0; i < qacs.nodes.size(); i++) {
		qac = qacs.nodes[i];

		outfile << id << "sqlstr += \"";
		if (i == 0) outfile << " WHERE "; else outfile << " AND ";

		writeQac(dbswznm, outfile, qac, Prjshort, false); // INI
	};

	if (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST) {
		outfile << id << "sqlstr += \" ORDER BY " << lrefqao->srefsWznmMTablecol << " ASC\";" << endl; // lref query has only one table ; plus, single tco sref
		outfile << id << "dbs" << prjshort << "->loadRefsBySQL(sqlstr, false, refsList);" << endl;
	} else {
		outfile << id << "dbs" << prjshort << "->loadRefsBySQL(sqlstr, false, refsList);" << endl;
		outfile << id << "refsPool.resize(refsList.size(), 0);" << endl;
	};
	outfile << endl;

	outfile << id << "sqlstr = \"SELECT ref FROM " << lreftbl->sref << "\";" << endl;
	for (unsigned int i = 0; i < qacs.nodes.size(); i++) {
		qac = qacs.nodes[i];

		outfile << id << "sqlstr += \"";
		if (i == 0) outfile << " WHERE "; else outfile << " AND ";

		writeQac(dbswznm, outfile, qac, Prjshort, true); // DLO
	};

	if (qry->ixVBasetype == VecWznmVMQueryBasetype::OOLIST) {
		outfile << id << "dbs" << prjshort << "->loadRefsBySQL(sqlstr, false, refsPool);" << endl;
	} else {
		outfile << id << "dbs" << prjshort << "->loadRefsBySQL(sqlstr, true, refsPool);" << endl;
		outfile << id << "refsList.resize(refsPool.size(), 0);" << endl;
	};
};

void WznmWrsrvQry::writeQry(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMQuery* qry
			, WznmMTable* qtb
			, ListWznmMQuerymod& filts
			, ListWznmAMQueryOrder& qaos
			, ListWznmAMQueryClause& qacs
			, vector<string>& bratbls
			, ListWznmMQuerycol& qcos
			, ListWznmMTablecol& tcos
			, const string& Prjshort
			, const string& id
			, const bool hasqwr
			, const bool hasbras
			, const bool hasfilts
			, const unsigned int ixLimofs
		) {
	vector<unsigned int> unqicsFilts;
	WznmMQuerymod* filt = NULL;

	WznmMPreset* pst = NULL;

	WznmAMQueryClause* qac = NULL;

	string prjshort = StrMod::lc(Prjshort);

	if (hasbras) {
		outfile << id << "rerun_baseSQL(sqlstr);" << endl;
	} else {
		writeBaseSQL(outfile, qtb, qcos, tcos, hasqwr);
	};

	outfile << id << "sqlstr += \" FROM";
	for (unsigned int i = 0; i < bratbls.size(); i++) {
		if (i != 0) outfile << ",";
		outfile << " " << bratbls[i];
	};
	outfile << "\";" << endl;

	for (unsigned int i = 0; i < qacs.nodes.size(); i++) {
		qac = qacs.nodes[i];

		outfile << id << "sqlstr += \"";
		if (i == 0) outfile << " WHERE "; else outfile << " AND ";

		writeQac(dbswznm, outfile, qac, Prjshort);
	};

	if (hasfilts) {
		getUnqicsQmdpsts(filts, unqicsFilts);

		outfile << id << "rerun_filtSQL(sqlstr";

		for (unsigned int i = 0; i < unqicsFilts.size(); i++) {
			filt = filts.nodes[unqicsFilts[i]];

			if (dbswznm->tblwznmmpreset->loadRecByRef(filt->refWznmMPreset, &pst)) {
				outfile << ", " << getPstVar(pst->sref);
				delete pst;
			};
		};

		outfile << ", ";
		if (qacs.nodes.size() == 0) outfile << "true"; else outfile << "false";
		outfile << ");" << endl;
	};

	if ( ((qry->ixVBasetype == VecWznmVMQueryBasetype::STD) || (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA)) && (qaos.nodes.size() > 1) ) {
		outfile << id << "rerun_orderSQL(sqlstr, preIxOrd);" << endl;
	} else {
		if (qaos.nodes.size() == 1) outfile << id << "sqlstr += \" ORDER BY " << qaos.nodes[0]->srefsWznmMTablecol << " ASC\";" << endl;
	};

	if (qry->Limofs) {
		if (qry->ixVBasetype == VecWznmVMQueryBasetype::MULTBRA) {
			outfile << id << "sqlstr += \" LIMIT \" + to_string(lims[" << ixLimofs << "]) + \" OFFSET \" + to_string(ofss[" << ixLimofs << "]);" << endl;
		} else {
			outfile << id << "sqlstr += \" LIMIT \" + to_string(stgiac.nload) + \" OFFSET \" + to_string(stgiac.jnumFirstload-1);" << endl;
		};
	};

	outfile << id << "dbs" << prjshort << "->executeQuery(sqlstr);" << endl;
};

void WznmWrsrvQry::writeBaseSQL(
			fstream& outfile
			, WznmMTable* qtb
			, ListWznmMQuerycol& qcos
			, ListWznmMTablecol& tcos
			, const bool hasqwr
		) {
	WznmMQuerycol* qco = NULL;
	WznmMTablecol* tco = NULL;

	outfile << "\tsqlstr = \"INSERT INTO " << qtb->sref << "(";
	if (hasqwr) outfile << "qwr, ";
	outfile << "jref, jnum";
	for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
		qco = qcos.nodes[i];
		outfile << ", " << qco->sref;
	};
	outfile << ")\";" << endl;

	outfile << "\tsqlstr += \" SELECT ";
	if (hasqwr) outfile << "1, ";
	outfile << "\" + to_string(jref) + \", 0";
	for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
		tco = tcos.nodes[i];
		outfile << ", " << tco->sref;
	};
	outfile << "\";" << endl;
};

void WznmWrsrvQry::writeQac(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmAMQueryClause* qac
			, const string& Prjshort
			, const bool latdlo
		) {
	WznmMPreset* pst = NULL;

	WznmMVector* vec = NULL;
	WznmMVectoritem* vit = NULL;

	string s;

	if ((qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::IX) || (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::REF)) {
		s = StrMod::findFirstPlh(qac->Clause, 0);
		outfile << StrMod::replacePlh(qac->Clause, s, "\" + to_string(stgiac." + s + ")") << ";" << endl;

	} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::EQN) {
		outfile << qac->Clause << "\";" << endl;

	} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::PRE) {
		if (dbswznm->tblwznmmpreset->loadRecByRef(qac->refWznmMPreset, &pst)) {
			s = getPstVar(pst->sref);

			if (pst->ixWznmWArgtype == VecWznmWArgtype::REFS) s = s + "[i]";

			if ((pst->ixWznmWArgtype != VecWznmWArgtype::SREF) && (pst->ixWznmWArgtype != VecWznmWArgtype::TXTVAL)) s = "to_string(" + s + ")";

			outfile << StrMod::replacePlh(qac->Clause, "pre", "\" + " + s + " + \"") << "\";" << endl;
			delete pst;
		};

	} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::VIT) {
		if (dbswznm->tblwznmmvector->loadRecByRef(qac->refWznmMVector, &vec)) {
			if (dbswznm->tblwznmmvectoritem->loadRecByRef(qac->refWznmMVectoritem, &vit)) {
				outfile << StrMod::replacePlh(qac->Clause, "vit", "\" + to_string(" + vec->sref + "::" + StrMod::uc(vit->sref)) << ");" << endl;
				delete vit;
			};
			delete vec;
		};

	} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::JREF) {
		outfile << StrMod::replacePlh(qac->Clause, "jref", "\" + to_string(jref)") << ";" << endl;

	} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::LCL) {
		outfile << StrMod::replacePlh(qac->Clause, "lcl", "\" + to_string(ix" + Prjshort + "Locale)") << ";" << endl;

	} else if (qac->ixVBasetype == VecWznmVAMQueryClauseBasetype::LAT) {
		if (latdlo) outfile << StrMod::replacePlh(qac->Clause, "lat", "\" + to_string(Vec" + Prjshort + "VLat::DLO)") << ";" << endl;
		else outfile << StrMod::replacePlh(qac->Clause, "lat", "\" + to_string(Vec" + Prjshort + "VLat::INI)") << ";" << endl;
	};
};

void WznmWrsrvQry::getBratbls(
			DbsWznm* dbswznm
			, const ubigint refQmd
			, ListWznmMTable& tbls
			, vector<string>& comtbls
			, vector<string>& bratbls
		) {
	ListWznmMTable tbl2s;
	WznmMTable* tbl2;

	bratbls.resize(0);

	for (unsigned int i = 0; i < tbls.nodes.size(); i++) bratbls.push_back(tbls.nodes[i]->sref);
	for (unsigned int i = 0; i < comtbls.size(); i++) bratbls.push_back(comtbls[i]);

	dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmRMQueryMTable, TblWznmTMQuerymodMQuery WHERE TblWznmMTable.ref = TblWznmRMQueryMTable.refWznmMTable AND TblWznmTMQuerymodMQuery.refR = TblWznmRMQueryMTable.ref AND TblWznmTMQuerymodMQuery.refWznmMQuerymod = "
				+ to_string(refQmd), false, tbl2s);

	for (unsigned int i = 0; i < tbl2s.nodes.size(); i++) {
		tbl2 = tbl2s.nodes[i];
		bratbls.push_back(tbl2->sref);
	};
};

void WznmWrsrvQry::getUnqicsQmdpsts(
			ListWznmMQuerymod& qmds
			, vector<unsigned int>& ics
		) {
	WznmMQuerymod* qmd = NULL;
	WznmMQuerymod* qmd2 = NULL;

	bool found;

	ics.clear();

	for (unsigned int i = 0; i < qmds.nodes.size(); i++) {
		qmd = qmds.nodes[i];

		found = false;

		for (unsigned int j = 0; j < ics.size(); j++) {
			qmd2 = qmds.nodes[ics[j]];

			if (qmd->refWznmMPreset == qmd2->refWznmMPreset) {
				found = true;
				break;
			};
		};

		if (!found) ics.push_back(i);
	};
};

string WznmWrsrvQry::getPstCppType(
			const uint ixWznmWArgtype
			, const bool fct
			, const bool ns
		) {
	string retval;

	string stdns, sbens;
	if (ns) {
		stdns = "std::";
		sbens = "Sbecore::";
	};

	if (ixWznmWArgtype == VecWznmWArgtype::IX) retval = sbens + "uint";
	else if (ixWznmWArgtype == VecWznmWArgtype::REF) retval = sbens + "ubigint";
	else if (ixWznmWArgtype == VecWznmWArgtype::INTVAL) retval = "int";
	else if (ixWznmWArgtype == VecWznmWArgtype::DBLVAL) retval = "double";
	else if (ixWznmWArgtype == VecWznmWArgtype::BOOLVAL) retval = "bool";
	else {
		if (ixWznmWArgtype == VecWznmWArgtype::REFS) retval = stdns + "vector<" + sbens + "ubigint>";
		else if (ixWznmWArgtype == VecWznmWArgtype::SREF) retval = stdns + "string";
		else if (ixWznmWArgtype == VecWznmWArgtype::TXTVAL) retval = stdns + "string";

		if (fct && (retval.length() > 0)) retval += "&";
	};

	return retval;
};

string WznmWrsrvQry::getPstVar(
			const string sref
		) {
	string retval;

	size_t ptr;

	ptr = sref.find('.');

	if (ptr == string::npos) retval = "pre" + StrMod::cap(sref.substr(3+4));
	else {
		retval = "pre" + StrMod::cap(sref.substr(ptr+1));

		ptr = retval.find('.');
		while (ptr != string::npos) {
			retval = retval.substr(0, ptr) + StrMod::cap(retval.substr(ptr+1));
			ptr = retval.find('.');
		};
	};

	return retval;
};

void WznmWrsrvQry::showQry(
			DbsWznm* dbswznm
			, const ubigint refWznmMQuery
			, const unsigned int il
		) {
	vector<ubigint> refs;

	WznmMQuery* qry = NULL;

	vector<ubigint> refsSubqrys;

	ListWznmMQuerymod qmds;
	WznmMQuerymod* qmd = NULL;

	ListWznmRMQueryMTable qrts;
	WznmRMQueryMTable* qrt = NULL;

	ListWznmAMQueryClause qacs;
	WznmAMQueryClause* qac = NULL;

	ListWznmAMQueryOrder qaos;
	WznmAMQueryOrder* qao = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	string indent;

	indent = "\t";
	for (unsigned int i = 0; i < il; i++) indent += "\t";

	dbswznm->tblwznmmquery->loadRecByRef(refWznmMQuery, &qry);

	// query
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMQuery WHERE supRefWznmMQuery = " + to_string(refWznmMQuery), false, refsSubqrys);

	if (refsSubqrys.size() == 0) cout << indent << "- ";
	else cout << indent << "+ ";
	cout << qry->sref << endl;

	delete qry;

	// query modifiers
	dbswznm->tblwznmmquerymod->loadRstByQry(refWznmMQuery, false, qmds);

	if (qmds.nodes.size() > 0) {
		cout << indent << "\tmodifiers:" << endl;

		for (unsigned int i = 0; i < qmds.nodes.size(); i++) {
			qmd = qmds.nodes[i];

			cout << indent << "\t" << qmd->qryNum << " (" << VecWznmVMQuerymodBasetype::getSref(qmd->ixVBasetype) << ") " << StubWznm::getStubPstStd(dbswznm, qmd->refWznmMPreset);

			if (qmd->refIxVTbl == VecWznmVMQuerymodRefTbl::TCO) cout << ", (tco) " << StubWznm::getStubTcoStd(dbswznm, qmd->refUref) << endl;
			else if (qmd->refIxVTbl == VecWznmVMQuerymodRefTbl::TBL) cout << ", (tbl) " << StubWznm::getStubTblStd(dbswznm, qmd->refUref) << endl;
			else cout << endl;
		};
	};

	// source tables
	dbswznm->tblwznmrmquerymtable->loadRstByQry(refWznmMQuery, false, qrts);
	
	if (qrts.nodes.size() > 0) {
		cout << indent << "\tsource tables:" << endl;

		for (unsigned int i = 0; i < qrts.nodes.size(); i++) {
			qrt = qrts.nodes[i];

			cout << indent << "\t" << StubWznm::getStubTblStd(dbswznm, qrt->refWznmMTable);

			dbswznm->loadRefsBySQL("SELECT refWznmMQuerymod FROM TblWznmTMQuerymodMQuery WHERE refR = " + to_string(qrt->ref), false, refs);

			if (refs.size() > 0) {
				cout << "(query mod. ";

				for (unsigned int j = 0; j < refs.size(); j++) {
					if (j != 0) cout << ",";

					for (unsigned int k = 0; k < qmds.nodes.size(); k++) {
						qmd = qmds.nodes[k];

						if (qmd->ref == refs[j]) {
							cout << qmd->qryNum;
							break;
						};
					};
				};

				cout << ")";
			};

			cout << endl;
		};
	};
	
	// query clauses
	dbswznm->tblwznmamqueryclause->loadRstByQry(refWznmMQuery, false, qacs);

	if (qacs.nodes.size() > 0) {
		cout << indent << "\tclauses:" << endl;

		for (unsigned int i = 0; i < qacs.nodes.size(); i++) {
			qac = qacs.nodes[i];
			cout << indent << "\t(" << VecWznmVAMQueryClauseBasetype::getSref(qac->ixVBasetype) << ") " << qac->Clause << endl;
		};
	};

	// order rules
	dbswznm->tblwznmamqueryorder->loadRstByQry(refWznmMQuery, false, qaos);

	if (qaos.nodes.size() > 0) {
		cout << indent << "\torder rules:" << endl;

		for (unsigned int i = 0; i < qaos.nodes.size(); i++) {
			qao = qaos.nodes[i];
			cout << indent << "\t" << qao->Short << ": " << qao->srefsWznmMTablecol << endl;
		};
	};

	// query columns
	dbswznm->tblwznmmquerycol->loadRstByQry(refWznmMQuery, false, qcos);

	if (qcos.nodes.size() > 0) {
		cout << indent << "\tcolumns: ";

		for (unsigned int i = 0; i < qcos.nodes.size(); i++) {
			qco = qcos.nodes[i];

			if (i != 0) cout << ",";
			cout << qco->Short;
		};

		cout << endl;
	};

	// sub-queries
	if (refsSubqrys.size() > 0) {
		cout << indent << "\tsub-queries:" << endl;
		for (unsigned int i = 0; i < refsSubqrys.size(); i++) showQry(dbswznm, refsSubqrys[i], il+1);
	};
};
// IP cust --- IEND
