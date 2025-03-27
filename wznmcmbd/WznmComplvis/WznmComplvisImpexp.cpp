/**
	* \file WznmComplvisImpexp.cpp
	* Wznm operation processor - complement visualization features (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmComplvisImpexp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmComplvis;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmComplvisImpexp
 ******************************************************************************/

DpchRetWznm* WznmComplvisImpexp::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplvisImpexp* dpchinv
		) {
	ubigint refWznmMVisual = dpchinv->refWznmMVisual;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMVisual* vis = NULL;

	ListWznmMSheet shts;
	map<string,ubigint> refsSht; // by Title
	ubigint refSht;

	ListWznmMImpexpcplx iexs;
	WznmMImpexpcplx* iex = NULL;

	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	ListWznmMBox boxs;
	map<ubigint,ubigint> refsBoxIme; // by ime

	const unsigned int xmargin = 15;
	const unsigned int wcol = 250;

	if (dbswznm->tblwznmmvisual->loadRecByRef(refWznmMVisual, &vis)) {
		dbswznm->tblwznmmsheet->loadRstByVis(vis->ref, false, shts);
		for (unsigned int i = 0; i < shts.nodes.size(); i++) refsSht[shts.nodes[i]->Title] = shts.nodes[i]->ref;

		dbswznm->tblwznmmimpexpcplx->loadRstByVer(vis->verRefWznmMVersion, false, iexs);
		for (unsigned int i = 0; i < iexs.nodes.size(); i++) {
			iex = iexs.nodes[i];

			auto it = refsSht.find(iex->Title);
			if (it == refsSht.end()) refsSht[iex->Title] = dbswznm->tblwznmmsheet->insertNewRec(NULL, vis->ref, refsSht.size() + 1, iex->Title);
			refSht = refsSht[iex->Title];
			
			dbswznm->tblwznmmbox->loadRstBySht(refSht, false, boxs);

			refsBoxIme.clear();

			for (unsigned int j = 0; j < boxs.nodes.size(); j++) refsBoxIme[boxs.nodes[j]->unvUref] = boxs.nodes[j]->ref;

			dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT * FROM TblWznmMImpexp WHERE refWznmMImpexpcplx = " + to_string(iex->ref) + " ORDER BY supLvl ASC, sref ASC", false, imes);

			for (unsigned int j = 0; j < imes.nodes.size(); j++) {
				ime = imes.nodes[j];

				auto it = refsBoxIme.find(ime->ref);

				if (it == refsBoxIme.end()) refsBoxIme[ime->ref] = dbswznm->tblwznmmbox->insertNewRec(NULL, refSht, VecWznmVMaintable::TBLWZNMMIMPEXP, ime->ref, xmargin + wcol*ime->supLvl, 0);
				else dbswznm->executeQuery("UPDATE TblWznmMBox SET x = " + to_string(xmargin + wcol*ime->supLvl) + " WHERE ref = " + to_string(it->second));

				if (refsBoxIme.find(ime->supRefWznmMImpexp) != refsBoxIme.end()) dbswznm->tblwznmrmboxmbox->insertNewRec(NULL, refsBoxIme[ime->supRefWznmMImpexp], refsBoxIme[ime->ref], 3, 9, 1);
			};
		};

		delete vis;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
