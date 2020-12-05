/**
	* \file WznmCtpWrstkitArm.cpp
	* Wznm operation processor - database, basic UI and import/export (implementation)
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

#include "WznmCtpWrstkitArm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrstkit;

/******************************************************************************
 namespace WznmCtpWrstkitArm
 ******************************************************************************/

DpchRetWznm* WznmCtpWrstkitArm::run(
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

	string Val;

	bool adr, horg, org;

	ubigint refLcl;
	vector<ubigint> refsLcl;

	ListWznmMLocale lcls;

	adr = false; if (Wznm::getCpa(dbswznm, refWznmMCapability, "adr", Val)) adr = (Val == "true");
	horg = false; if (Wznm::getCpa(dbswznm, refWznmMCapability, "horg", Val)) horg = (Val == "true");
	org = false; if (Wznm::getCpa(dbswznm, refWznmMCapability, "org", Val)) org = (Val == "true");

	dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb);

	Wznm::getVerlcls(dbswznm, cpb->refWznmMVersion, refLcl, refsLcl, lcls);

	writeIexBui(dbswznm, cpb->refWznmMVersion, Prjshort, xchg->tmppath + "/" + folder, adr, org, horg, refLcl, refsLcl, lcls);
	writeIexDbs(dbswznm, cpb->refWznmMVersion, Prjshort, xchg->tmppath + "/" + folder, adr, org, horg, refLcl, refsLcl, lcls);
	writeIexIex(dbswznm, cpb->refWznmMVersion, Prjshort, xchg->tmppath + "/" + folder, adr, org, horg, refLcl, refsLcl, lcls);

	delete cpb;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmCtpWrstkitArm::writeIexBui(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& outfolder
			, const bool adr
			, const bool org
			, const bool horg
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

	car = new IexWznmBui::ImeitemIMCard(VecWznmVMCardRefTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "Crd" + Prjshort + "Usg", "", ""); mdl->imeimcard.nodes.push_back(car);

	car = new IexWznmBui::ImeitemIMCard(VecWznmVMCardRefTbl::TBL, "Tbl" + Prjshort + "MUser", "Crd" + Prjshort + "Usr", "", ""); mdl->imeimcard.nodes.push_back(car);

	if (org || horg) {car = new IexWznmBui::ImeitemIMCard(VecWznmVMCardRefTbl::TBL, "Tbl" + Prjshort + "MOrg", "Crd" + Prjshort + "Org", "", ""); mdl->imeimcard.nodes.push_back(car);};

	car = new IexWznmBui::ImeitemIMCard(VecWznmVMCardRefTbl::TBL, "Tbl" + Prjshort + "MPerson", "Crd" + Prjshort + "Prs", "", ""); mdl->imeimcard.nodes.push_back(car);

	IexWznmBui::exportToFile(outfolder + "/IexWznmBui_" + StrMod::lc(Prjshort) + ".txt", false, false, imeimmodule, imeimpreset);
	IexWznmBui::exportToFile(outfolder + "/IexWznmBui_" + StrMod::lc(Prjshort) + ".xml", true, true, imeimmodule, imeimpreset);
};

void WznmCtpWrstkitArm::writeIexDbs(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& outfolder
			, const bool adr
			, const bool org
			, const bool horg
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

	if (adr) {
		// - TblXxxxMAddress
		tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::MAIN, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "MAddress", "adr", "", ""); imeimtable.nodes.push_back(tbl);
		addIAMTableTitles(dbswznm, tbl, "adr", VecWznmVAMTableTitleType::SNGFULL, "stdtbl", refLcl, refsLcl, lcls);
		addIAMTableTitles(dbswznm, tbl, "adr", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

		if (org || horg) {
			vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::LIN, "Vec" + Prjshort + "VMAddressHkTbl", "", "filfed"); tbl->imeimvector2.nodes.push_back(vec2);
			addIAMVectorTitles(dbswznm, vec2, "adr.hktbl", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

			vit2 = new IexWznmDbs::ImeitemIMVectoritem2("org", "", ""); vec2->imeimvectoritem2.nodes.push_back(vit2);
			addIJMVectoritems(dbswznm, vit2, "org.sngfull", "stdtbl", refLcl, refsLcl, lcls);

			vit2 = new IexWznmDbs::ImeitemIMVectoritem2("prs", "", ""); vec2->imeimvectoritem2.nodes.push_back(vit2);
			addIJMVectoritems(dbswznm, vit2, "prs.sngfull", "stdtbl", refLcl, refsLcl, lcls);
		};

		vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::KLST, "KlstKMAddressAdrtype", "adrtype", ""); tbl->imeimvector2.nodes.push_back(vec2);
		addIAMVectorTitles(dbswznm, vec2, "adr.adrtyp", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

		vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::KLST, "Klst" + Prjshort + "KMAddressCountry", "ctry", ""); tbl->imeimvector2.nodes.push_back(vec2);
		addIAMVectorTitles(dbswznm, vec2, "adr.country", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::GRP, "", 47, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "grp", "grp", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::OWN, "", 48, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "own", "own", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x1Startd", "sta", VecWznmVMTablecolSubtype::TMDATE, VecWznmVMTablecolAxisfct::SPT, "idx", false, false));

		if (org || horg) {
			tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 9, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMAddressHkTbl", "hkIxVTbl", "hkt", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
			tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 9, VecWznmVMTablecolFctTbl::VOID, "", "hkUref", "hku", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "", true, false));

		} else {
			tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 9, VecWznmVMTablecolFctTbl::VOID, "", "ref" + Prjshort + "MPerson", "prs", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		};

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::KLREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "KlstKMAddressAdrtype", "srefKAdrtype", "aty", VecWznmVMTablecolSubtype::KLREFSNG, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Address1", "ad1", VecWznmVMTablecolSubtype::TXT100, VecWznmVMTablecolAxisfct::VOID, "", true, true));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Address2", "ad2", VecWznmVMTablecolSubtype::TXT100, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Zipcode", "zip", VecWznmVMTablecolSubtype::TXT10, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "City", "cty", VecWznmVMTablecolSubtype::TXT50, VecWznmVMTablecolAxisfct::VOID, "idx", true, true));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "State", "ste", VecWznmVMTablecolSubtype::TXT50, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::KLREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Klst" + Prjshort + "KMAddressCountry", "srefKCountry", "cry", VecWznmVMTablecolSubtype::KLREFSNG, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	};

	if (org || horg) {
		// - TblXxxxMOrg
		tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::MAIN, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "MOrg", "org", "", ""); imeimtable.nodes.push_back(tbl);

		addIAMTableTitles(dbswznm, tbl, "org", VecWznmVAMTableTitleType::SNGFULL, "stdtbl", refLcl, refsLcl, lcls);
		addIAMTableTitles(dbswznm, tbl, "org", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

		vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::OR, "Vec" + Prjshort + "WMOrgDerivate", "", "filfed"); tbl->imeimvector2.nodes.push_back(vec2);
		addIAMVectorTitles(dbswznm, vec2, "derivs", VecWznmVAMVectorTitleType::FULL, "", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::GRP, "", 60, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "grp", "grp", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::OWN, "", 61, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "own", "own", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 57, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "WMOrgDerivate", "ixWDerivate", "drv", VecWznmVMTablecolSubtype::VREFAND, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));

		if (adr) tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 58, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MAddress", "ref" + Prjshort + "MAddress", "adr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));

		if (horg) {
			tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 51, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MOrg", "supRef" + Prjshort + "MOrg", "sup", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
			tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::LVL, "", 51, VecWznmVMTablecolFctTbl::VOID, "", "supLvl", "sul", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		};

		tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDSREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "sref", "srf", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, true); tbl->imeimtablecol.nodes.push_back(tco);
		addIAMTablecolTitles(dbswznm, tco, "sref", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 53, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "JMOrgTitle", "refJTitle", "j", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, true));

		tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Title", "tit", VecWznmVMTablecolSubtype::TXT50, VecWznmVMTablecolAxisfct::VOID, "idx", true, true); tbl->imeimtablecol.nodes.push_back(tco);
		addIAMTablecolTitles(dbswznm, tco, "title", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 55, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "AMOrgDetail", "telRefADetail", "ate", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "telVal", "tel", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 56, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "AMOrgDetail", "emlRefADetail", "aem", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "emlVal", "eml", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);

		tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::CONFIRM, "confirmByRef", "", "ref", "", VecWznmVAMTableLoadfctLimtype::VOID));
		
		if (org) tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefBySrf", "ref", "sref", "", VecWznmVAMTableLoadfctLimtype::VOID));
		else if (horg) tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefBySupSrf", "ref", "supRef" + Prjshort + "MOrg;sref", "", VecWznmVAMTableLoadfctLimtype::VOID));
	};

	// - TblXxxxMPerson
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::MAIN, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "MPerson", "prs", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "prs", VecWznmVAMTableTitleType::SNGFULL, "stdtbl", refLcl, refsLcl, lcls);
	addIAMTableTitles(dbswznm, tbl, "prs", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::OR, "Vec" + Prjshort + "WMPersonDerivate", "", "filfed"); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "deriv", VecWznmVAMVectorTitleType::FULL, "", refLcl, refsLcl, lcls);

	vit2 = new IexWznmDbs::ImeitemIMVectoritem2("usr", "", ""); vec2->imeimvectoritem2.nodes.push_back(vit2);
	addIJMVectoritems(dbswznm, vit2, "usr.sngfull", "stdtbl", refLcl, refsLcl, lcls);

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::LIN, "Vec" + Prjshort + "VMPersonSex", "sex", "filfed"); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "prs.sex", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::VLST, "Vlst" + Prjshort + "UMPersonTitle", "prstit", ""); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "prs.title", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::GRP, "", 1, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "grp", "grp", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::OWN, "", 2, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "own", "own", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 32, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "WMPersonDerivate", "ixWDerivate", "drv", VecWznmVMTablecolSubtype::VREFAND, VecWznmVMTablecolAxisfct::VOID, "idx", false, false));

	if (org || horg) {
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 7, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "RMOrgMPerson", "refROrg", "ror", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 8, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MOrg", "ref" + Prjshort + "MOrg", "org", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	};

	if (adr) tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", (org || horg) ? 59 : 11, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MAddress", "ref" + Prjshort + "MAddress", "adr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMPersonSex", "ixVSex", "sex", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vlst" + Prjshort + "UMPersonTitle", "Title", "tit", VecWznmVMTablecolSubtype::TXT30, VecWznmVMTablecolAxisfct::VOID, "", true, true));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Firstname", "fnm", VecWznmVMTablecolSubtype::TXT30, VecWznmVMTablecolAxisfct::VOID, "", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "prs.fnm", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 13, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "JMPersonLastname", "refJLastname", "j", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, true));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Lastname", "lnm", VecWznmVMTablecolSubtype::TXT50, VecWznmVMTablecolAxisfct::VOID, "idx", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "prs.lnm", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 15, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "AMPersonDetail", "telRefADetail", "ate", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "telVal", "tel", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 16, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "AMPersonDetail", "emlRefADetail", "aem", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "emlVal", "eml", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Salutation", "sal", VecWznmVMTablecolSubtype::TXT100, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "prs.sal", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	// - TblXxxxMSession
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::MAIN, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "MSession", "ses", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "ses", VecWznmVAMTableTitleType::SNGFULL, "stdtbl", refLcl, refsLcl, lcls);
	addIAMTableTitles(dbswznm, tbl, "ses", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 23, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "usr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "start", "sta", VecWznmVMTablecolSubtype::TMSTAMP, VecWznmVMTablecolAxisfct::VOID, "idx", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "ses.sta", VecWznmVAMTablecolTitleType::SHORT, "stdtco", refLcl, refsLcl, lcls);
	addIAMTablecolTitles(dbswznm, tco, "ses.sta", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "stop", "sto", VecWznmVMTablecolSubtype::TMSTAMP, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "ses.sto", VecWznmVAMTablecolTitleType::SHORT, "stdtco", refLcl, refsLcl, lcls);
	addIAMTablecolTitles(dbswznm, tco, "ses.sto", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Ip", "ip", VecWznmVMTablecolSubtype::TXT30, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "ses.ip", VecWznmVAMTablecolTitleType::SHORT, "stdtco", refLcl, refsLcl, lcls);
	addIAMTablecolTitles(dbswznm, tco, "ses.ip", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsByUsr", "ref", "ref" + Prjshort + "MUser", "start", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByUsr", "", "ref" + Prjshort + "MUser", "start", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxMUser
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::MAIN, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "MUser", "usr", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "usr", VecWznmVAMTableTitleType::SNGFULL, "stdtbl", refLcl, refsLcl, lcls);
	addIAMTableTitles(dbswznm, tbl, "usr", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::GRP, "", 24, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "grp", "grp", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::OWN, "", 25, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "own", "own", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 30, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "RMUserMUsergroup", "refRUsergroup", "rug", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 31, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "ref" + Prjshort + "MUsergroup", "usg", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 33, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MPerson", "ref" + Prjshort + "MPerson", "prs", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, true));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDSREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "sref", "srf", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "usr.srf", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 35, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "JMUserState", "refJState", "j", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::LIN, "Vec" + Prjshort + "VMUserState", "usrste", "filfed"); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "state", VecWznmVAMVectorTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMUserState", "ixVState", "ste", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VLocale", "ix" + Prjshort + "VLocale", "lcl", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VUserlevel", "ix" + Prjshort + "VUserlevel", "ulv", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Password", "pwd", VecWznmVMTablecolSubtype::TXT30, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "usr.pwd", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Fullkey", "fky", VecWznmVMTablecolSubtype::TXTLONG, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "usr.fky", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Comment", "cmt", VecWznmVMTablecolSubtype::TXTLONG, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "comment", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefByPrs", "ref", "ref" + Prjshort + "MPerson", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByPrs", "", "ref" + Prjshort + "MPerson", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefBySrf", "ref", "sref", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecBySrf", "", "sref", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecBySrfPwd", "", "sref;Password", "", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxMUsergroup
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::MAIN, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "MUsergroup", "usg", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "usg", VecWznmVAMTableTitleType::SNGFULL, "stdtbl", refLcl, refsLcl, lcls);
	addIAMTableTitles(dbswznm, tbl, "usg", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::GRP, "", 36, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "grp", "grp", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::OWN, "", 37, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "own", "own", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDSREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "sref", "srf", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "sref", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Comment", "cmt", VecWznmVMTablecolSubtype::TXTLONG, VecWznmVMTablecolAxisfct::VOID, "", false, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "comment", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefBySrf", "ref", "sref", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecBySrf", "", "sref", "", VecWznmVAMTableLoadfctLimtype::VOID));

	if (org || horg) {
		// - TblXxxxAMOrgDetail
		tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::AUX, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "AMOrgDetail", "orgAdet", "", ""); imeimtable.nodes.push_back(tbl);
		addIAMTableTitles(dbswznm, tbl, "orgAdet", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

		vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::KLST, "Klst" + Prjshort + "KAMOrgDetailType", "ctdet", ""); tbl->imeimvector2.nodes.push_back(vec2);
		addIAMVectorTitles(dbswznm, vec2, "type", VecWznmVAMVectorTitleType::FULL, "", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 54, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MOrg", "ref" + Prjshort + "MOrg", "org", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::KLREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Klst" + Prjshort + "KAMOrgDetailType", "x1SrefKType", "typ", VecWznmVMTablecolSubtype::KLREFSNG, VecWznmVMTablecolAxisfct::PT, "", true, true));

		tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Val", "val", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
		addIAMTablecolTitles(dbswznm, tco, "value", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

		tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByOrgTyp", "", "ref" + Prjshort + "MOrg;x1SrefKType", "", VecWznmVAMTableLoadfctLimtype::VOID));
	};

	// - TblXxxxAMPersonDetail
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::AUX, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "AMPersonDetail", "prsAdet", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "prsAdet", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::KLST, "Klst" + Prjshort + "KAMPersonDetailType", "ctdet", ""); tbl->imeimvector2.nodes.push_back(vec2);
	addIAMVectorTitles(dbswznm, vec2, "type", VecWznmVAMVectorTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 14, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MPerson", "ref" + Prjshort + "MPerson", "prs", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::KLREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Klst" + Prjshort + "KAMPersonDetailType", "x1SrefKType", "typ", VecWznmVMTablecolSubtype::KLREFSNG, VecWznmVMTablecolAxisfct::PT, "", true, true));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Val", "val", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "value", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByPrsTyp", "", "ref" + Prjshort + "MPerson;x1SrefKType", "", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxAMUserAccess
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::AUX, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "AMUserAccess", "usrAacc", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "usrAacc", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 17, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "usr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VFeatgroup", "x1Ix" + Prjshort + "VFeatgroup", "feg", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::PT, "idx", true, true));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::UVSREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x2FeaSrefUix", "fea", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::PT, "idx", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "usgAacc.fea", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "WAccess", "ix" + Prjshort + "WAccess", "acc", VecWznmVMTablecolSubtype::VREFAND, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	// - TblXxxxAMUsergroupAccess
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::AUX, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "AMUsergroupAccess", "usgAacc", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "usgAacc", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 18, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "ref" + Prjshort + "MUsergroup", "usg", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VFeatgroup", "x1Ix" + Prjshort + "VFeatgroup", "feg", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::PT, "idx", true, true));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::UVSREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x2FeaSrefUix", "fea", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::PT, "idx", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "usgAacc.fea", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "WAccess", "ix" + Prjshort + "WAccess", "acc", VecWznmVMTablecolSubtype::VREFAND, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	// - TblXxxxAVControlPar
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::AUX, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "AVControlPar", "ctlApar", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "ctlApar", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VControl", "ix" + Prjshort + "VControl", "ctl", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 19, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "x1Ref" + Prjshort + "MUser", "usr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::PT, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VLocale", "x2Ix" + Prjshort + "VLocale", "lcl", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::PT, "idx", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Par", "par", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "idx", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "par", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Val", "val", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "value", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::STRING, "loadValByCtlUsrPar", "Val", "ix" + Prjshort + "VControl;x1Ref" + Prjshort + "MUser;Par", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefByCtlUsrPar", "ref", "ix" + Prjshort + "VControl;x1Ref" + Prjshort + "MUser;Par", "", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxAVKeylistKey
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::AUX, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "AVKeylistKey", "klsAkey", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "klsAkey", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VKeylist", "klsIx" + Prjshort + "VKeylist", "kls", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::ENUM, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "klsNum", "kln", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 20, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMaintable", "x1Ix" + Prjshort + "VMaintable", "mtb", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::PT, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 20, VecWznmVMTablecolFctTbl::TBL, "", "x1Uref", "urf", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::PT, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::BOOLVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Fixed", "fix", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "klsAkey.fix", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDSREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "sref", "srf", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "sref", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::EXPR, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Avail", "avl", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "klsAkey.avl", VecWznmVAMTablecolTitleType::SHORT, "stdtco", refLcl, refsLcl, lcls);
	addIAMTablecolTitles(dbswznm, tco, "klsAkey.avl", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::EXPR, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Implied", "imp", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "klsAkey.imp", VecWznmVAMTablecolTitleType::SHORT, "stdtco", refLcl, refsLcl, lcls);
	addIAMTablecolTitles(dbswznm, tco, "klsAkey.imp", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 22, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "JAVKeylistKey", "refJ", "j", VecWznmVMTablecolSubtype::TREFMIN, VecWznmVMTablecolAxisfct::VOID, "", true, true));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Title", "tit", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "title", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Comment", "cmt", VecWznmVMTablecolSubtype::TXTLONG, VecWznmVMTablecolAxisfct::VOID, "", true, true); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "comment", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByKls", "", "klsIx" + Prjshort + "VKeylist", "klsNum", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByKlsMtbUrf", "", "klsIx" + Prjshort + "VKeylist;x1Ix" + Prjshort + "VMaintable;x1Uref", "klsNum", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::STRING, "loadTitByRef", "Title", "ref", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefByKlsSrf", "ref", "klsIx" + Prjshort + "VKeylist;sref", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadRefByKlsMtbUrfSrf", "ref", "klsIx" + Prjshort + "VKeylist;x1Ix" + Prjshort + "VMaintable;x1Uref;sref", "", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxAVValuelistVal
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::AUX, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "AVValuelistVal", "vlsAval", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "vlsAval", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VValuelist", "vlsIx" + Prjshort + "VValuelist", "vls", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::ENUM, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "vlsNum", "vln", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VLocale", "x1Ix" + Prjshort + "VLocale", "lcl", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::PT, "idx", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Val", "val", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "value", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByVlsLcl", "", "vlsIx" + Prjshort + "VValuelist;x1Ix" + Prjshort + "VLocale", "vlsNum", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxJAVKeylistKey
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::JUMP, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "JAVKeylistKey", "kakJkey", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "kakJkey", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 21, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "AVKeylistKey", "ref" + Prjshort + "AVKeylistKey", "klk", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VLocale", "x1Ix" + Prjshort + "VLocale", "lcl", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::PT, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Title", "tit", VecWznmVMTablecolSubtype::TXT192, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Comment", "cmt", VecWznmVMTablecolSubtype::TXTLONG, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByKlk", "", "ref" + Prjshort + "AVKeylistKey", "x1Ix" + Prjshort + "VLocale", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::STRING, "loadTitByKlkLcl", "Title", "ref" + Prjshort + "AVKeylistKey;x1Ix" + Prjshort + "VLocale", "", VecWznmVAMTableLoadfctLimtype::VOID));

	if (org || horg) {
		// - TblXxxxJMOrgTitle
		tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::JUMP, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "JMOrgTitle", "orgJtit", "", ""); imeimtable.nodes.push_back(tbl);
		addIAMTableTitles(dbswznm, tbl, "orgJtit", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 52, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MOrg", "ref" + Prjshort + "MOrg", "org", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));

		tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x1Startd", "sta", VecWznmVMTablecolSubtype::TMDATE, VecWznmVMTablecolAxisfct::SPT, "idx", true, false); tbl->imeimtablecol.nodes.push_back(tco);
		addIAMTablecolTitles(dbswznm, tco, "start", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Title", "tit", VecWznmVMTablecolSubtype::TXT50, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	};

	// - TblXxxxJMPersonLastname
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::JUMP, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "JMPersonLastname", "prsJlnm", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "prsJlnm", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 12, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MPerson", "ref" + Prjshort + "MPerson", "prs", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x1Startd", "sta", VecWznmVMTablecolSubtype::TMDATE, VecWznmVMTablecolAxisfct::SPT, "idx", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "start", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TXTVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "Lastname", "lnm", VecWznmVMTablecolSubtype::TXT50, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByPrsSta", "", "ref" + Prjshort + "MPerson;x1Startd.leq", "x1Startd.desc", VecWznmVAMTableLoadfctLimtype::FIRST));

	// - TblXxxxJMUserState
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::JUMP, VecWznmVMTableRefTbl::VOID, 0, "Tbl" + Prjshort + "JMUserState", "usrJste", "", ""); imeimtable.nodes.push_back(tbl);
	addIAMTableTitles(dbswznm, tbl, "usrJste", VecWznmVAMTableTitleType::PLFULL, "stdtbl", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 34, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "usr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x1Start", "sta", VecWznmVMTablecolSubtype::TMSTAMP, VecWznmVMTablecolAxisfct::SPT, "idx", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "start", VecWznmVAMTablecolTitleType::FULL, "", refLcl, refsLcl, lcls);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMUserState", "ixVState", "ste", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByUsrSta", "", "ref" + Prjshort + "MUser;x1Start.leq", "x1Start.desc", VecWznmVAMTableLoadfctLimtype::FIRST));

	// - TblXxxxAccRMUserUniversal
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::REL, VecWznmVMTableRefTbl::REL, 38, "Tbl" + Prjshort + "AccRMUserUniversal", "ausrRunv", "", ""); imeimtable.nodes.push_back(tbl);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 39, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "usr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 40, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMaintable", "unvIx" + Prjshort + "VMaintable", "mtb", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 40, VecWznmVMTablecolFctTbl::TBL, "", "unvUref", "unv", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VRecaccess", "ix" + Prjshort + "VRecaccess", "rac", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByUsrMtbUnv", "", "ref" + Prjshort + "MUser;unvIx" + Prjshort + "VMaintable;unvUref", "", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxHistRMUserUniversal
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::REL, VecWznmVMTableRefTbl::REL, 41, "Tbl" + Prjshort + "HistRMUserUniversal", "husrRunv", "", ""); imeimtable.nodes.push_back(tbl);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 42, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "usr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 43, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMaintable", "unvIx" + Prjshort + "VMaintable", "mtb", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 43, VecWznmVMTablecolFctTbl::TBL, "", "unvUref", "unv", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VCard", "ix" + Prjshort + "VCard", "crd", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VPreset", "ix" + Prjshort + "VPreset", "pre", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 210, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMaintable", "preIx" + Prjshort + "VMaintable", "prm", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 210, VecWznmVMTablecolFctTbl::TBL, "", "preUref", "pru", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tco = new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "start", "sta", VecWznmVMTablecolSubtype::TMSTAMP, VecWznmVMTablecolAxisfct::VOID, "", true, false); tbl->imeimtablecol.nodes.push_back(tco);
	addIAMTablecolTitles(dbswznm, tco, "husrRunv.sta", VecWznmVAMTablecolTitleType::FULL, "stdtco", refLcl, refsLcl, lcls);

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REF, "loadUnuByRef", "unvUref", "ref", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::RST, "loadRstByUsrCrd", "", "ref" + Prjshort + "MUser;ix" + Prjshort + "VCard", "start.desc", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByUsrMtbUnvCrd", "", "ref" + Prjshort + "MUser;unvIx" + Prjshort + "VMaintable;unvUref;ix" + Prjshort + "VCard", "", VecWznmVAMTableLoadfctLimtype::VOID));
	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsByUsrMtbCrd", "ref", "ref" + Prjshort + "MUser;unvIx" + Prjshort + "VMaintable;ix" + Prjshort + "VCard", "start.desc", VecWznmVAMTableLoadfctLimtype::LIMOFS));

	if (org || horg) {
		// - TblXxxxRMOrgMPerson
		tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::REL, VecWznmVMTableRefTbl::REL, 3, "Tbl" + Prjshort + "RMOrgMPerson", "orgRprs", "", ""); imeimtable.nodes.push_back(tbl);

		vec2 = new IexWznmDbs::ImeitemIMVector2(VecWznmVMVectorBasetype::KLST, "Klst" + Prjshort + "KRMOrgMPersonFunction", "", ""); tbl->imeimvector2.nodes.push_back(vec2);
		addIAMVectorTitles(dbswznm, vec2, "orgRprs.function", VecWznmVAMVectorTitleType::FULL, "stdvec", refLcl, refsLcl, lcls);

		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x1Startd", "sta", VecWznmVMTablecolSubtype::TMDATE, VecWznmVMTablecolAxisfct::SPT, "idx", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TIMEVAL, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "x1Stopd", "sto", VecWznmVMTablecolSubtype::TMDATE, VecWznmVMTablecolAxisfct::EPT, "idx", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 4, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MOrg", "ref" + Prjshort + "MOrg", "org", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 5, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MPerson", "ref" + Prjshort + "MPerson", "prs", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
		tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::KLREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Klst" + Prjshort + "KRMOrgMPersonFunction", "srefKFunction", "fct", VecWznmVMTablecolSubtype::KLREFSNG, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	};

	// - TblXxxxRMUsergroupUniversal
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::REL, VecWznmVMTableRefTbl::REL, 44, "Tbl" + Prjshort + "RMUsergroupUniversal", "usgRunv", "", ""); imeimtable.nodes.push_back(tbl);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 45, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "ref" + Prjshort + "MUsergroup", "usg", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 46, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VMaintable", "unvIx" + Prjshort + "VMaintable", "mtb", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "idx", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 46, VecWznmVMTablecolFctTbl::TBL, "", "unvUref", "unv", VecWznmVMTablecolSubtype::TREFUNIV, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VRecaccess", "ix" + Prjshort + "VRecaccess", "rac", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "", true, false));

	tbl->imeiamtableloadfct.nodes.push_back(new IexWznmDbs::ImeitemIAMTableLoadfct(VecWznmVAMTableLoadfctLoadtype::REC, "loadRecByUsgMtbUnv", "", "ref" + Prjshort + "MUsergroup;unvIx" + Prjshort + "VMaintable;unvUref", "", VecWznmVAMTableLoadfctLimtype::VOID));

	// - TblXxxxRMUserMUsergroup
	tbl = new IexWznmDbs::ImeitemIMTable(VecWznmVMTableBasetype::REL, VecWznmVMTableRefTbl::REL, 26, "Tbl" + Prjshort + "RMUserMUsergroup", "usrRusg", "", ""); imeimtable.nodes.push_back(tbl);

	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::IDREF, "", 0, VecWznmVMTablecolFctTbl::VOID, "", "ref", "ref", VecWznmVMTablecolSubtype::VOID, VecWznmVMTablecolAxisfct::VOID, "", false, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 27, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "usr", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::TBLREF, "", 28, VecWznmVMTablecolFctTbl::TBL, "Tbl" + Prjshort + "MUsergroup", "ref" + Prjshort + "MUsergroup", "usg", VecWznmVMTablecolSubtype::TREFSPEC, VecWznmVMTablecolAxisfct::VOID, "", true, false));
	tbl->imeimtablecol.nodes.push_back(new IexWznmDbs::ImeitemIMTablecol(VecWznmVMTablecolBasetype::VECREF, "", 0, VecWznmVMTablecolFctTbl::VEC, "Vec" + Prjshort + "VUserlevel", "ix" + Prjshort + "VUserlevel", "ulv", VecWznmVMTablecolSubtype::VREFLIN, VecWznmVMTablecolAxisfct::VOID, "", false, false));

	// - relations
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(1, VecWznmVMRelationBasetype::GRP, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "MPerson", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(2, VecWznmVMRelationBasetype::OWN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "MPerson", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(12, VecWznmVMRelationBasetype::J, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MPerson", "", "Tbl" + Prjshort + "JMPersonLastname", "", "", "", "pref"));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(13, VecWznmVMRelationBasetype::JPREF, 0, 12, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "JMPersonLastname", "", "Tbl" + Prjshort + "MPerson", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(14, VecWznmVMRelationBasetype::AUX, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MPerson", "", "Tbl" + Prjshort + "AMPersonDetail", "", "", "", "pref"));

	rel = new IexWznmDbs::ImeitemIMRelation(15, VecWznmVMRelationBasetype::AUXPREF, 0, 14, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "AMPersonDetail", "", "Tbl" + Prjshort + "MPerson", "", "", "tel", ""); imeimrelation.nodes.push_back(rel);
	addIAMRelationTitles(dbswznm, rel, "tel", VecWznmVAMRelationTitleType::FROMSNGFULL, "ctdet", refLcl, refsLcl, lcls);

	rel = new IexWznmDbs::ImeitemIMRelation(16, VecWznmVMRelationBasetype::AUXPREF, 0, 14, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "AMPersonDetail", "", "Tbl" + Prjshort + "MPerson", "", "", "eml", ""); imeimrelation.nodes.push_back(rel);
	addIAMRelationTitles(dbswznm, rel, "eml", VecWznmVAMRelationTitleType::FROMSNGFULL, "ctdet", refLcl, refsLcl, lcls);

	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(17, VecWznmVMRelationBasetype::AUX, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "AMUserAccess", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(18, VecWznmVMRelationBasetype::AUX, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "AMUsergroupAccess", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(19, VecWznmVMRelationBasetype::_1N, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "AVControlPar", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(20, VecWznmVMRelationBasetype::UM1N, 0, 0, VecWznmVMRelationSupSubrole::VOID, "", "", "Tbl" + Prjshort + "AVKeylistKey", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(21, VecWznmVMRelationBasetype::J, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "AVKeylistKey", "", "Tbl" + Prjshort + "JAVKeylistKey", "", "", "", "pref"));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(22, VecWznmVMRelationBasetype::JPREF, 0, 21, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "JAVKeylistKey", "", "Tbl" + Prjshort + "AVKeylistKey", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(23, VecWznmVMRelationBasetype::_1N, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "MSession", "", "", "", "affil"));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(24, VecWznmVMRelationBasetype::GRP, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "MUser", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(25, VecWznmVMRelationBasetype::OWN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "MUser", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(26, VecWznmVMRelationBasetype::MN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "RMUserMUsergroup", "", "preffrom"));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(27, VecWznmVMRelationBasetype::_1N, 0, 26, VecWznmVMRelationSupSubrole::FROM1N, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "RMUserMUsergroup", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(28, VecWznmVMRelationBasetype::_1N, 0, 26, VecWznmVMRelationSupSubrole::TO1N, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "RMUserMUsergroup", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(29, VecWznmVMRelationBasetype::MNPREF, 0, 26, VecWznmVMRelationSupSubrole::FROMPREF, "", "", "", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(30, VecWznmVMRelationBasetype::_1N, 0, 29, VecWznmVMRelationSupSubrole::R1N, "Tbl" + Prjshort + "RMUserMUsergroup", "", "Tbl" + Prjshort + "MUser", "", "", "", ""));

	rel = new IexWznmDbs::ImeitemIMRelation(31, VecWznmVMRelationBasetype::_1N, 0, 29, VecWznmVMRelationSupSubrole::MN1N, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "MUser", "", "", "", ""); imeimrelation.nodes.push_back(rel);
	addIAMRelationTitles(dbswznm, rel, "priusg", VecWznmVAMRelationTitleType::FROMSNGFULL, "stdrel", refLcl, refsLcl, lcls);

	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(32, VecWznmVMRelationBasetype::DRV, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MPerson", "", "", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(33, VecWznmVMRelationBasetype::DRVSUB, 0, 32, VecWznmVMRelationSupSubrole::SUB, "Tbl" + Prjshort + "MPerson", "", "Tbl" + Prjshort + "MUser", "", "", "usr", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(34, VecWznmVMRelationBasetype::J, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "JMUserState", "", "", "", "pref"));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(35, VecWznmVMRelationBasetype::JPREF, 0, 34, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "JMUserState", "", "Tbl" + Prjshort + "MUser", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(36, VecWznmVMRelationBasetype::GRP, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "MUsergroup", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(37, VecWznmVMRelationBasetype::OWN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "MUsergroup", "", "", "", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(38, VecWznmVMRelationBasetype::UMN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "", "", "Tbl" + Prjshort + "AccRMUserUniversal", "acc", ""));

	rel = new IexWznmDbs::ImeitemIMRelation(39, VecWznmVMRelationBasetype::_1N, 0, 38, VecWznmVMRelationSupSubrole::FROM1N, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "AccRMUserUniversal", "", "", "", ""); imeimrelation.nodes.push_back(rel);
	addIAMRelationTitles(dbswznm, rel, "recacc", VecWznmVAMRelationTitleType::TOPLFULL, "stdrel", refLcl, refsLcl, lcls);

	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(40, VecWznmVMRelationBasetype::UM1N, 0, 38, VecWznmVMRelationSupSubrole::TOUM1N, "", "", "Tbl" + Prjshort + "AccRMUserUniversal", "", "", "unv", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(41, VecWznmVMRelationBasetype::UMN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "", "", "Tbl" + Prjshort + "HistRMUserUniversal", "hist", ""));

	rel = new IexWznmDbs::ImeitemIMRelation(42, VecWznmVMRelationBasetype::_1N, 0, 41, VecWznmVMRelationSupSubrole::FROM1N, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "HistRMUserUniversal", "", "", "", ""); imeimrelation.nodes.push_back(rel);
	addIAMRelationTitles(dbswznm, rel, "hist", VecWznmVAMRelationTitleType::TOPLFULL, "stdrel", refLcl, refsLcl, lcls);

	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(43, VecWznmVMRelationBasetype::UM1N, 0, 41, VecWznmVMRelationSupSubrole::TOUM1N, "", "", "Tbl" + Prjshort + "HistRMUserUniversal", "", "", "unv", ""));
	imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(44, VecWznmVMRelationBasetype::UMN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUsergroup", "", "", "", "Tbl" + Prjshort + "RMUsergroupUniversal", "", ""));

	rel = new IexWznmDbs::ImeitemIMRelation(45, VecWznmVMRelationBasetype::_1N, 0, 44, VecWznmVMRelationSupSubrole::FROM1N, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "RMUsergroupUniversal", "", "", "", ""); imeimrelation.nodes.push_back(rel);
	addIAMRelationTitles(dbswznm, rel, "recacc", VecWznmVAMRelationTitleType::TOPLFULL, "stdrel", refLcl, refsLcl, lcls);

	rel = new IexWznmDbs::ImeitemIMRelation(46, VecWznmVMRelationBasetype::UM1N, 0, 44, VecWznmVMRelationSupSubrole::TOUM1N, "", "", "Tbl" + Prjshort + "RMUsergroupUniversal", "", "", "unv", ""); imeimrelation.nodes.push_back(rel);

	if (adr) {
		if (org || horg) {
			imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(9, VecWznmVMRelationBasetype::U1N, 0, 0, VecWznmVMRelationSupSubrole::VOID, "", "", "Tbl" + Prjshort + "MAddress", "", "", "hk", "affil"));
			imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(10, VecWznmVMRelationBasetype::U1NSUB, 0, 9, VecWznmVMRelationSupSubrole::SUB, "Tbl" + Prjshort + "MOrg", "", "Tbl" + Prjshort + "MAddress", "", "", "org", "pref"));
			imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(11, VecWznmVMRelationBasetype::U1NSUB, 0, 9, VecWznmVMRelationSupSubrole::SUB, "Tbl" + Prjshort + "MPerson", "", "Tbl" + Prjshort + "MAddress", "", "", "prs", "pref"));
			imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(58, VecWznmVMRelationBasetype::U1NSUBPREF, 0, 10, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "MAddress", "", "Tbl" + Prjshort + "MOrg", "", "", "", ""));
			imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(59, VecWznmVMRelationBasetype::U1NSUBPREF, 0, 11, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "MAddress", "", "Tbl" + Prjshort + "MPerson", "", "", "", ""));
		} else {
			imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(9, VecWznmVMRelationBasetype::_1N, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MPerson", "", "Tbl" + Prjshort + "MAddress", "", "", "", "pref"));
			imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(10, VecWznmVMRelationBasetype::_1NPREF, 0, 9, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "MAddress", "", "Tbl" + Prjshort + "MPerson", "", "", "", ""));
		};
	};

	if (horg) imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(51, VecWznmVMRelationBasetype::H1N, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MOrg", "", "Tbl" + Prjshort + "MOrg", "", "", "sup", "affil"));

	if (org || horg) {
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(60, VecWznmVMRelationBasetype::GRP, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUsergroup", "", "Tbl" + Prjshort + "MOrg", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(61, VecWznmVMRelationBasetype::OWN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MUser", "", "Tbl" + Prjshort + "MOrg", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(3, VecWznmVMRelationBasetype::MN, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MOrg", "", "Tbl" + Prjshort + "MPerson", "", "Tbl" + Prjshort + "RMOrgMPerson", "", "prefto"));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(4, VecWznmVMRelationBasetype::_1N, 0, 3, VecWznmVMRelationSupSubrole::FROM1N, "Tbl" + Prjshort + "MOrg", "", "Tbl" + Prjshort + "RMOrgMPerson", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(5, VecWznmVMRelationBasetype::_1N, 0, 3, VecWznmVMRelationSupSubrole::TO1N, "Tbl" + Prjshort + "MPerson", "", "Tbl" + Prjshort + "RMOrgMPerson", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(6, VecWznmVMRelationBasetype::MNPREF, 0, 5, VecWznmVMRelationSupSubrole::TOPREF, "", "", "", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(7, VecWznmVMRelationBasetype::_1N, 0, 6, VecWznmVMRelationSupSubrole::R1N, "Tbl" + Prjshort + "RMOrgMPerson", "", "Tbl" + Prjshort + "MPerson", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(8, VecWznmVMRelationBasetype::_1N, 0, 6, VecWznmVMRelationSupSubrole::MN1N, "Tbl" + Prjshort + "MOrg", "", "Tbl" + Prjshort + "MPerson", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(52, VecWznmVMRelationBasetype::J, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MOrg", "", "Tbl" + Prjshort + "JMOrgTitle", "", "", "", "pref"));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(53, VecWznmVMRelationBasetype::JPREF, 0, 52, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "JMOrgTitle", "", "Tbl" + Prjshort + "MOrg", "", "", "", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(54, VecWznmVMRelationBasetype::AUX, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MOrg", "", "Tbl" + Prjshort + "AMOrgDetail", "", "", "", "pref"));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(55, VecWznmVMRelationBasetype::AUXPREF, 0, 54, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "AMOrgDetail", "", "Tbl" + Prjshort + "MOrg", "", "", "tel", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(56, VecWznmVMRelationBasetype::AUXPREF, 0, 54, VecWznmVMRelationSupSubrole::PREF, "Tbl" + Prjshort + "AMOrgDetail", "", "Tbl" + Prjshort + "MOrg", "", "", "eml", ""));
		imeimrelation.nodes.push_back(new IexWznmDbs::ImeitemIMRelation(57, VecWznmVMRelationBasetype::DRV, 0, 0, VecWznmVMRelationSupSubrole::VOID, "Tbl" + Prjshort + "MOrg", "", "", "", "", "", ""));
	};

	// - stubs
	if (adr) imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::CUST, "Tbl" + Prjshort + "MAddress", "", "Stub" + Prjshort + "AdrStd", false, "", true, "1234 Broadway, 10027 New York City, United States"));

	if (org) imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::TCO, "Tbl" + Prjshort + "MOrg", "", "Stub" + Prjshort + "OrgStd", false, "sref", false, "ethz"));
	else if (horg) imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::TCO, "Tbl" + Prjshort + "MOrg", "", "Stub" + Prjshort + "OrgStd", true, "sref", false, "ethz;itet;hpe"));

	imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::CUST, "Tbl" + Prjshort + "MPerson", "", "Stub" + Prjshort + "PrsStd", false, "", false, "Franz Kuntz"));
	imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::CUST, "Tbl" + Prjshort + "MSession", "", "Stub" + Prjshort + "SesMenu", false, "", true, "user fkuntz / Franz Kuntz;logged in from 127.0.0.1;since 01-01-2010 10:34"));
	imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::CUST, "Tbl" + Prjshort + "MSession", "", "Stub" + Prjshort + "SesStd", false, "", true, "01-01-2010 10:34 from 127.0.0.1"));
	imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::CUST, "Tbl" + Prjshort + "MUser", "", "Stub" + Prjshort + "UsrStd", false, "", false, "fkuntz / Franz Kuntz"));
	imeimstub.nodes.push_back(new IexWznmDbs::ImeitemIMStub(VecWznmVMStubBasetype::TCO, "Tbl" + Prjshort + "MUsergroup", "", "Stub" + Prjshort + "UsgStd", false, "sref", false, "super"));

	if (horg) imeirmstubmstub.nodes.push_back(new IexWznmDbs::ImeitemIRMStubMStub("Stub" + Prjshort + "OrgStd", "Stub" + Prjshort + "OrgStd"));
	imeirmstubmstub.nodes.push_back(new IexWznmDbs::ImeitemIRMStubMStub("Stub" + Prjshort + "UsrStd", "Stub" + Prjshort + "SesMenu"));
	imeirmstubmstub.nodes.push_back(new IexWznmDbs::ImeitemIRMStubMStub("Stub" + Prjshort + "PrsStd", "Stub" + Prjshort + "UsrStd"));

	IexWznmDbs::exportToFile(outfolder + "/IexWznmDbs_" + StrMod::lc(Prjshort) + ".txt", false, false, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
	IexWznmDbs::exportToFile(outfolder + "/IexWznmDbs_" + StrMod::lc(Prjshort) + ".xml", true, true, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
};

void WznmCtpWrstkitArm::writeIexIex(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, const string& outfolder
			, const bool adr
			, const bool org
			, const bool horg
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

	string preflcl;
	dbswznm->tblwznmmlocale->loadSrfByRef(refLcl, preflcl);

	iex = new IexWznmIex::ImeitemIMImpexpcplx("Iex" + Prjshort + "Ini", "ini", "", "", "tool initialization");
	addIJMImpexpcplxTitles(dbswznm, iex, "ini", refLcl, refsLcl, lcls);

	imeimimpexpcplx.nodes.push_back(iex);

	ime = new IexWznmIex::ImeitemIMImpexp(1, 0, "Tbl" + Prjshort + "AVKeylistKey", "ImeIAVKeylistKey", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "klsIx" + Prjshort + "VKeylist", "srefKlsIx" + Prjshort + "VKeylist", "kls", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "klsNum", "klsNum", "", 0, VecWznmVMImpexpcolConvtype::CUST, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "x1Ix" + Prjshort + "VMaintable", "x1Ix" + Prjshort + "VMaintable", "", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", "void"));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "Fixed", "Fixed", "", 0, VecWznmVMImpexpcolConvtype::VOID, "true", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "sref", "sref", "srf", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Avail", "Avail", "avl", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Implied", "Implied", "imp", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "refJ", "refJ", "", 2, VecWznmVMImpexpcolConvtype::SUB, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Title", "Title", "tit", 2, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Comment", "Comment", "cmt", 2, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(2, 1, "Tbl" + Prjshort + "JAVKeylistKey", "ImeIJAVKeylistKey", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ref" + Prjshort + "AVKeylistKey", "ref" + Prjshort + "AVKeylistKey", "", 1, VecWznmVMImpexpcolConvtype::SUP, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "x1Ix" + Prjshort + "VLocale", "srefX1Ix" + Prjshort + "VLocale", "lcl", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", preflcl));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Title", "Title", "tit", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Comment", "Comment", "cmt", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(3, 0, "Tbl" + Prjshort + "AVValuelistVal", "ImeIAVValuelistVal", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "vlsIx" + Prjshort + "VValuelist", "srefVlsIx" + Prjshort + "VValuelist", "vls", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "vlsNum", "vlsNum", "", 0, VecWznmVMImpexpcolConvtype::CUST, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "x1Ix" + Prjshort + "VLocale", "srefX1Ix" + Prjshort + "VLocale", "lcl", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Val", "Val", "val", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(4, 0, "Tbl" + Prjshort + "AVControlPar", "ImeIAVControlPar", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ix" + Prjshort + "VControl", "srefIx" + Prjshort + "VControl", "ctl", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Par", "Par", "par", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Val", "Val", "val", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(6, 0, "Tbl" + Prjshort + "MUsergroup", "ImeIMUsergroup", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "sref", "sref", "srf", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Comment", "Comment", "cmt", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(7, 6, "Tbl" + Prjshort + "AMUsergroupAccess", "ImeIAMUsergroupAccess", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ref" + Prjshort + "MUsergroup", "ref" + Prjshort + "MUsergroup", "", 6, VecWznmVMImpexpcolConvtype::SUP, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "x1Ix" + Prjshort + "VFeatgroup", "srefX1Ix" + Prjshort + "VFeatgroup", "feg", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "x2FeaSrefUix", "x2FeaSrefUix", "fea", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ix" + Prjshort + "WAccess", "srefsIx" + Prjshort + "WAccess", "acc", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(8, 6, "Tbl" + Prjshort + "MUser", "ImeIMUser", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "refRUsergroup", "refRUsergroup", "", 0, VecWznmVMImpexpcolConvtype::IMPPP, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ref" + Prjshort + "MUsergroup", "ref" + Prjshort + "MUsergroup", "", 6, VecWznmVMImpexpcolConvtype::SUP, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ref" + Prjshort + "MPerson", "ref" + Prjshort + "MPerson", "", 10, VecWznmVMImpexpcolConvtype::SUB, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "sref", "sref", "srf", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "refJState", "refJState", "", 9, VecWznmVMImpexpcolConvtype::SUB, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ixVState", "srefIxVState", "ste", 9, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ix" + Prjshort + "VLocale", "srefIx" + Prjshort + "VLocale", "lcl", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ix" + Prjshort + "VUserlevel", "srefIx" + Prjshort + "VUserlevel", "ulv", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Password", "Password", "pwd", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Comment", "Comment", "cmt", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(9, 8, "Tbl" + Prjshort + "JMUserState", "ImeIJMUserState", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ref" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "", 8, VecWznmVMImpexpcolConvtype::SUP, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "x1Start", "x1Start", "", 0, VecWznmVMImpexpcolConvtype::VOID, "&now;", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ixVState", "srefIxVState", "ste", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(10, 8, "Tbl" + Prjshort + "MPerson", "ImeIMPerson", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ixWDerivate", "ixWDerivate", "", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", "usr"));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ixVSex", "srefIxVSex", "sex", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Title", "Title", "tit", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Firstname", "Firstname", "fnm", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "refJLastname", "refJLastname", "", 11, VecWznmVMImpexpcolConvtype::SUB, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Lastname", "Lastname", "lnm", 11, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(11, 10, "Tbl" + Prjshort + "JMPersonLastname", "ImeIJMPersonLastname", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ref" + Prjshort + "MPerson", "ref" + Prjshort + "MPerson", "", 10, VecWznmVMImpexpcolConvtype::SUP, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "x1Startd", "x1Startd", "", 0, VecWznmVMImpexpcolConvtype::VOID, "&today;", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "Lastname", "Lastname", "lnm", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));

	ime = new IexWznmIex::ImeitemIMImpexp(12, 8, "Tbl" + Prjshort + "AMUserAccess", "ImeIAMUserAccess", "", VecWznmWMImpexpIop::INS, "");
	iex->imeimimpexp.nodes.push_back(ime);

	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::TBL, "ref" + Prjshort + "MUser", "ref" + Prjshort + "MUser", "", 8, VecWznmVMImpexpcolConvtype::SUP, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "x1Ix" + Prjshort + "VFeatgroup", "srefX1Ix" + Prjshort + "VFeatgroup", "feg", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::TBL, VecWznmWMImpexpcolOccurrence::FIL + VecWznmWMImpexpcolOccurrence::TBL, "x2FeaSrefUix", "x2FeaSrefUix", "fea", 0, VecWznmVMImpexpcolConvtype::VOID, "", "", "", ""));
	ime->imeimimpexpcol.nodes.push_back(new IexWznmIex::ImeitemIMImpexpcol(VecWznmVMImpexpcolBasetype::VSREF, VecWznmWMImpexpcolOccurrence::FIL, "ix" + Prjshort + "WAccess", "srefsIx" + Prjshort + "WAccess", "acc", 0, VecWznmVMImpexpcolConvtype::IXSREF, "", "", "", ""));

	IexWznmIex::exportToFile(outfolder + "/IexWznmIex_" + StrMod::lc(Prjshort) + ".txt", false, false, imeimimpexpcplx);
	IexWznmIex::exportToFile(outfolder + "/IexWznmIex_" + StrMod::lc(Prjshort) + ".xml", true, true, imeimimpexpcplx);
};
// IP cust --- IEND



