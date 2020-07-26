/**
	* \file WznmCtpWrstkitAcv.cpp
	* Wznm operation processor - database and basic UI (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpWrstkitAcv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrstkit;

/******************************************************************************
 namespace WznmCtpWrstkitAcv
 ******************************************************************************/

DpchRetWznm* WznmCtpWrstkitAcv::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpWrstkit* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMCapability* cpb = NULL;

	ubigint refLcl;
	vector<ubigint> refsLcl;

	ListWznmMLocale lcls;

	dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb);

	Wznm::getVerlcls(dbswznm, cpb->refWznmMVersion, refLcl, refsLcl, lcls);

	writeIexBui(dbswznm, cpb->refWznmMVersion, Prjshort, xchg->tmppath + "/" + folder, refLcl, refsLcl, lcls);
	writeIexDbs(dbswznm, cpb->refWznmMVersion, Prjshort, xchg->tmppath + "/" + folder, refLcl, refsLcl, lcls);
	writeIexIex(dbswznm, cpb->refWznmMVersion, Prjshort, xchg->tmppath + "/" + folder, refLcl, refsLcl, lcls);

	delete cpb;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmCtpWrstkitAcv::writeIexBui(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& outfolder
			, const ubigint refLcl
			, vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	// -- IexWznmBui
	// ImeIMModule
	//  ImeIJMModule
	//  ImeIMCard

	IexWznmBui::ImeIMModule imeimmodule;
	IexWznmBui::ImeIMPreset imeimpreset;

	IexWznmBui::ImeitemIMModule* mdl = NULL;
	IexWznmBui::ImeitemIMCard* car = NULL;

	mdl = new IexWznmBui::ImeitemIMModule("Mdl" + Prjshort + "Admin"); imeimmodule.nodes.push_back(mdl);
	addIJMModules(dbswznm, mdl, "admmdl", "", refLcl, refsLcl, lcls);

	car = new IexWznmBui::ImeitemIMCard(VecWznmVMCardRefTbl::TBL, "Tbl" + Prjshort + "MFile", "Crd" + Prjshort + "Fil", "", ""); mdl->imeimcard.nodes.push_back(car);

	IexWznmBui::exportToFile(outfolder + "/IexWznmBui_" + StrMod::lc(Prjshort) + ".txt", false, false, imeimmodule, imeimpreset);
	IexWznmBui::exportToFile(outfolder + "/IexWznmBui_" + StrMod::lc(Prjshort) + ".xml", true, true, imeimmodule, imeimpreset);
};

void WznmCtpWrstkitAcv::writeIexDbs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& outfolder
			, const ubigint refLcl
			, vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	// -- IexWznmDbs
	// ImeIMRelation
	//  ImeIAMRelationTitle
	// ImeIMTable
	//  ImeIAMTableTitle
	//  ImeIMTablecol
	//   ImeIAMTablecolTitle
	// 	ImeIMVector2
	// 	 ImeIAMVectorTitle2
	// 	 ImeIMVectoritem2
	// 	  ImeIJMVectoritem2
	//  ImeIAMTableLoadfct
	//  ImeIMCheck
	// ImeIMStub
	// ImeIRMStubMStub

	IexWznmDbs::ImeICRelation imeicrelation;
	IexWznmDbs::ImeIMRelation imeimrelation;
	IexWznmDbs::ImeIMStub imeimstub;
	IexWznmDbs::ImeIMTable imeimtable;
	IexWznmDbs::ImeIMVector1 imeimvector1;
	IexWznmDbs::ImeIRMStubMStub imeirmstubmstub;

	IexWznmDbs::ImeitemIMRelation* rel = NULL;
	IexWznmDbs::ImeitemIMTable* tbl = NULL;
	IexWznmDbs::ImeitemIMTablecol* tco = NULL;
	IexWznmDbs::ImeitemIMVector2* vec2 = NULL;
	IexWznmDbs::ImeitemIMVectoritem2* vit2 = NULL;

	// - TblXxxxMFile
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::MAIN, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "MFile", "fil", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "fil", VecWznmVAMTableTitleType::SNGFULL, "stdtbl", refLcl, refsLcl, lcls);
	addIAMTableTitles(dbswznm, tbl, "fil", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::LIN, "Vec" + Prjshort + "VMFileRefTbl", "", "filfed"); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "fil.reftbl", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

	vit2 = new IexWznmDbs::ImeitemIMVectoritem2("void", "", ""); vec2->imeimvectoritem2.nodes.push_back(vit2);
	addIJMVectoritems(dbswznm, vit2, "void", "", refLcl, refsLcl, lcls);

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::KLST, "Klst" + Prjshort + "KMFileContent", "", ""); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "fil.content", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::KLST, "Klst" + Prjshort + "KMFileMimetype", "mimetype", "noloc"); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "fil.mimetype", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::GRP, "", 47, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "grp", "grp", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::OWN, "", 48, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "own", "own", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 49, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "CFile", "ref" + Prjshort + "CFile", "clu", VecWznmVMTablecolSubtype::TREFCLU, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 50, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMFileRefTbl", "refIxVTbl", "ret", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 50, VecWznmVMTablecolFctTbl::TBL, "", "refUref", "reu", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::KLREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Klst" + Prjshort + "KMFileContent", "osrefKContent", "cnt", VecWznmVMTablecolSubtype::KLREFOPT, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Archived", "acv", VecWznmVMTablecolSubtype::TMSTAMP, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "fil.acv", VecWznmVAMTablecolTitleType::SHORT, "stdtco", refLcl, refsLcl, lcls);
	addIAMTablecolTitles(dbswznm, tco, "fil.acv", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Filename", "fnm", VecWznmVMTablecolSubtype::TXT50, VecWznmVMTablecolAxisfct::VOID, "idx", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "fil.fnm", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Archivename", "anm", VecWznmVMTablecolSubtype::TXT30, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "fil.anm", VecWznmVAMTablecolTitleType::SHORT, "stdtco", refLcl, refsLcl, lcls);
	addIAMTablecolTitles(dbswznm, tco, "fil.anm", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::KLREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Klst" + Prjshort + "KMFileMimetype", "srefKMimetype", "mim", VecWznmVMTablecolSubtype::KLREFSNG, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::INTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Size", "siz", VecWznmVMTablecolSubtype::USMALLINT, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "fil.siz", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Comment", "cmt", VecWznmVMTablecolSubtype::TXTLONG, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "comment", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	// - TblXxxxCFile
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::CLUST, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "CFile", "filC", "", ""); imeimtable.nodes.push_back(tbl);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));

	// - relations
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(47, VecWznmVMRelationBasetype::GRP, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "MFile", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(48, VecWznmVMRelationBasetype::OWN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "MFile", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(49, VecWznmVMRelationBasetype::CLUST, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "CFile", "", "Tbl" + Prjshort + "MFile", "", "", "", ""));

	rel = new IexWznmDbs::ImeitemIMRelation(50, VecWznmVMRelationBasetype::U1N, 0, 0, VecWznmVMRelationSupSubrole::VOID, "", "", "Tbl" + Prjshort + "MFile", "", "", "ref", "affil"); imeimrelation.nodes.push_back(rel);
	addIAMRelationTitles(dbswznm, rel, "ref", VecWznmVAMRelationTitleType::FROMSNGFULL, "stdrel", refLcl, refsLcl, lcls);

	// - stubs
	imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::TCO, "Tbl" + Prjshort + "MFile", "", "Stub" + Prjshort + "FilStd", false, "Filename", false, "customers.xlsx"));

	IexWznmDbs::exportToFile(outfolder + "/IexWznmDbs_" + StrMod::lc(Prjshort) + ".txt", false, false, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
	IexWznmDbs::exportToFile(outfolder + "/IexWznmDbs_" + StrMod::lc(Prjshort) + ".xml", true, true, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
};

void WznmCtpWrstkitAcv::writeIexIex(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& outfolder
			, const ubigint refLcl
			, vector<ubigint>& refsLcl
			, ListWznmMLocale& lcls
		) {
	// -- IexWznmIex
	// ImeIMImpexpcplx
	//  ImeIJMImpexpcplxTitle
	//  ImeIMImpexp
	//   ImeIMImpexpcol

	IexWznmIex::ImeIMImpexpcplx imeimimpexpcplx;

	IexWznmIex::ImeitemIMImpexpcplx* iex = NULL;
	IexWznmIex::ImeitemIMImpexp* ime = NULL;

	ime = new IexWznmIex::ImeitemIMImpexp(5, 0, "Tbl" + Prjshort + "MFile", "ImeIMFile", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "refIxVTbl", "refIxVTbl", "", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", "void"));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "osrefKContent", "osrefKContent", "cnt", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Filename", "Filename", "fnm", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "srefKMimetype", "srefKMimetype", "mim", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Comment", "Comment", "cmt", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	IexWznmIex::exportToFile(outfolder + "/IexWznmIex_" + StrMod::lc(Prjshort) + ".txt", false, false, imeimimpexpcplx);
	IexWznmIex::exportToFile(outfolder + "/IexWznmIex_" + StrMod::lc(Prjshort) + ".xml", true, true, imeimimpexpcplx);
};
// IP cust --- IEND


