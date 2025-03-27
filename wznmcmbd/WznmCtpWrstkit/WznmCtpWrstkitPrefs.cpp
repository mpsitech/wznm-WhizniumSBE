/**
	* \file WznmCtpWrstkitPrefs.cpp
	* Wznm operation processor - basic UI (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpWrstkitPrefs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpWrstkit;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpWrstkitPrefs
 ******************************************************************************/

DpchRetWznm* WznmCtpWrstkitPrefs::run(
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

	writeIexBui(dbswznm, cpb, Prjshort, xchg->tmppath + "/" + folder, refLcl, refsLcl, lcls);

	delete cpb;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmCtpWrstkitPrefs::writeIexBui(
			DbsWznm* dbswznm
			, WznmMCapability* cpb
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
	addIJMModules(dbswznm, mdl, 0, "admmdl", "", refLcl, refsLcl, lcls);

	car = new IexWznmBui::ImeitemIMCard(VecWznmVMCardRefTbl::VOID, "", "Crd" + Prjshort + "Prf", "", ""); mdl->imeimcard.nodes.push_back(car);
	addIJMCardTitles(dbswznm, car, cpb->tplRefWznmMCapability, "pref", "", refLcl, refsLcl, lcls);

	IexWznmBui::exportToFile(outfolder + "/IexWznmBui_" + StrMod::lc(Prjshort) + ".txt", false, false, imeimmodule, imeimpreset);
	IexWznmBui::exportToFile(outfolder + "/IexWznmBui_" + StrMod::lc(Prjshort) + ".xml", true, true, imeimmodule, imeimpreset);
};
// IP cust --- IEND
