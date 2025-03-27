/**
	* \file WznmComplvisDbstr.cpp
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

#include "WznmComplvisDbstr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmComplvis;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmComplvisDbstr
 ******************************************************************************/

DpchRetWznm* WznmComplvisDbstr::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplvisDbstr* dpchinv
		) {
	ubigint refWznmMVisual = dpchinv->refWznmMVisual;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	vector<ubigint> refs;

	WznmMVisual* vis = NULL;

	ListWznmMSheet shts;
	WznmMSheet* sht = NULL;

	ListWznmMBox boxs;
	WznmMBox* box = NULL;

	map<ubigint,ubigint> refsBoxTbl; // by tbl
	map<ubigint,ubigint> refsBoxVec; // by vec

	if (dbswznm->tblwznmmvisual->loadRecByRef(refWznmMVisual, &vis)) {
		dbswznm->tblwznmmsheet->loadRstByVis(vis->ref, false, shts);

		for (unsigned int i = 0; i < shts.nodes.size(); i++) {
			sht = shts.nodes[i];

			dbswznm->tblwznmmbox->loadRstBySht(sht->ref, false, boxs);

			refsBoxTbl.clear();
			refsBoxVec.clear();

			for (unsigned int j = 0; j < boxs.nodes.size(); j++) {
				box = boxs.nodes[j];

				if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMTABLE) refsBoxTbl[box->unvUref] = box->ref;
				else if (box->unvIxWznmVMaintable == VecWznmVMaintable::TBLWZNMMVECTOR) refsBoxVec[box->unvUref] = box->ref;
			};

			for (auto it = refsBoxTbl.begin(); it != refsBoxTbl.end(); it++) {
				// complement table-related vectors
				dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::TBL) + " AND hkUref = " + to_string(it->first), false, refs);

				for (unsigned int k = 0; k < refs.size(); k++) {
					if (refsBoxVec.find(refs[k]) == refsBoxVec.end()) refsBoxVec[refs[k]] = dbswznm->tblwznmmbox->insertNewRec(NULL, sht->ref, VecWznmVMaintable::TBLWZNMMVECTOR, refs[k], 0, 0);
					dbswznm->tblwznmrmboxmbox->insertNewRec(NULL, it->second, refsBoxVec[refs[k]], 0, 0, 1);
				};

				// add inter-table wiring (boxRbox)
				dbswznm->loadRefsBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(it->first) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_11), false, refs);
				dbswznm->loadRefsBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(it->first) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::_1N)
							+ " AND (supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::FROM1N) + " OR supIxVSubrole = " + to_string(VecWznmVMRelationSupSubrole::TO1N) + " OR srefsKOption LIKE '%affil%')", true, refs);
				dbswznm->loadRefsBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(it->first) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::INC), true, refs);
				dbswznm->loadRefsBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(it->first) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::J), true, refs);
				dbswznm->loadRefsBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(it->first) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::CLUST), true, refs);
				dbswznm->loadRefsBySQL("SELECT frRefWznmMTable FROM TblWznmMRelation WHERE toRefWznmMTable = " + to_string(it->first) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::AUX), true, refs);

				for (unsigned int k = 0; k < refs.size(); k++)
					if (refsBoxTbl.find(refs[k]) != refsBoxTbl.end())
						dbswznm->tblwznmrmboxmbox->insertNewRec(NULL, refsBoxTbl[refs[k]], it->second, 0, 0, 1);
			};
		};

		delete vis;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
