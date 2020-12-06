/**
	* \file WznmGenChk.cpp
	* Wznm operation processor - generate feature checks (implementation)
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

#include "WznmGenChk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmGen;

/******************************************************************************
 namespace WznmGenChk
 ******************************************************************************/

DpchRetWznm* WznmGenChk::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmGenChk* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	ListWznmMPanel pnls;
	WznmMPanel* pnl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	set<string> tblshorts;
	map<string,ubigint> tblrefs; // by Short
	set<string> skiptblshorts;

	set<string> chks;
	set<string> skipchks;

	ListWznmMCheck tblchks;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;
	map<string,ubigint> tcorefs;

	ubigint tblref;
	string tblshort;
	string tcoshort;

	uint ixVBasetype;

	Expr expr;

	string s;
	size_t ptr;

	dbswznm->tblwznmmtable->loadRstBySQL("SELECT * FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype <> " + to_string(VecWznmVMTableBasetype::QRY), false, tbls);
	
	for (unsigned int i = 0; i < tbls.nodes.size(); i++) {
		tbl = tbls.nodes[i];

		if (tbl->Short != "") {
			tblshorts.insert(tbl->Short);
			tblrefs[tbl->Short] = tbl->ref;
		};
	};

	// - card controls, panels and panel controls ; route via job.reu is not available at this stage
	dbswznm->tblwznmmcard->loadRstBySQL("SELECT TblWznmMCard.* FROM TblWznmMModule, TblWznmMCard WHERE TblWznmMModule.verRefWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref", false, cars);

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::CAR, car->ref, false, cons);
		for (unsigned int j = 0; j < cons.nodes.size(); j++) {
			con = cons.nodes[j];

			if (con->ixVScope == VecWznmVMControlScope::SHR) {
				if (con->Avail != "") if (expr.tokenize(con->Avail)) if (expr.parse()) Wznm::collectChks(tblshorts, skiptblshorts, expr.root, chks);
				if (con->Active != "") if (expr.tokenize(con->Active)) if (expr.parse()) Wznm::collectChks(tblshorts, skiptblshorts, expr.root, chks);
			};
		};

		dbswznm->tblwznmmpanel->loadRstByCar(car->ref, false, pnls);

		for (unsigned int j = 0; j < pnls.nodes.size(); j++) {
			pnl = pnls.nodes[j];

			Wznm::getPnlrecs(dbswznm, refWznmMVersion, Prjshort, car, pnl, tbls);

			// for now, include all checks, regardless of presence of record variable
			skiptblshorts.clear();
			//for (unsigned int j = 0; j < tbls.nodes.size(); j++) if (tbls.nodes[j]->Short != "") skiptblshorts.insert(tbls.nodes[j]->Short);

			if (pnl->Avail != "") if (expr.tokenize(pnl->Avail)) if (expr.parse()) Wznm::collectChks(tblshorts, skiptblshorts, expr.root, chks);

			dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);
			for (unsigned int j = 0; j < cons.nodes.size(); j++) {
				con = cons.nodes[j];

				if (con->ixVScope == VecWznmVMControlScope::SHR) {
					if (con->Avail != "") if (expr.tokenize(con->Avail)) if (expr.parse()) Wznm::collectChks(tblshorts, skiptblshorts, expr.root, chks);
					if (con->Active != "") if (expr.tokenize(con->Active)) if (expr.parse()) Wznm::collectChks(tblshorts, skiptblshorts, expr.root, chks);
				};
			};
		};
	};

	// - dialog controls ; route via job.reu is not available at this stage
	skiptblshorts.clear();

	dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT TblWznmMControl.* FROM TblWznmMModule, TblWznmMCard, TblWznmMDialog, TblWznmMControl WHERE TblWznmMModule.verRefWznmMVersion = " + to_string(refWznmMVersion)
				+ " AND TblWznmMCard.mdlRefWznmMModule = TblWznmMModule.ref AND TblWznmMDialog.refWznmMCard = TblWznmMCard.ref AND TblWznmMControl.hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::DLG)
				+ " AND TblWznmMControl.hkUref = TblWznmMCard.ref", false, cons);

	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if (con->ixVScope == VecWznmVMControlScope::SHR) {
			if (con->Avail != "") if (expr.tokenize(con->Avail)) if (expr.parse()) Wznm::collectChks(tblshorts, skiptblshorts, expr.root, chks);
			if (con->Active != "") if (expr.tokenize(con->Active)) if (expr.parse()) Wznm::collectChks(tblshorts, skiptblshorts, expr.root, chks);
		};
	};

	// - match to existing, else insert
	tblshort = "";

	for (auto it = chks.begin(); it != chks.end(); it++) {
		s = *it;

		ptr = s.find('.');
		if (ptr != string::npos) {
			if (s.substr(0, ptr) != tblshort) {
				auto it2 = tblrefs.find(s.substr(0, ptr));
				if (it2 == tblrefs.end()) continue;

				tblref = it2->second;
				tblshort = s.substr(0, ptr);
				tcorefs.clear();

				dbswznm->tblwznmmcheck->loadRstBySQL("SELECT * FROM TblWznmMCheck WHERE refWznmMTable = " + to_string(it2->second), false, tblchks);
				for (unsigned int i = 0; i < tblchks.nodes.size(); i++) skipchks.insert(tblshort + "." + tblchks.nodes[i]->sref);

				dbswznm->tblwznmmtablecol->loadRstByTbl(it2->second, false, tcos);
				for (unsigned int i = 0; i < tcos.nodes.size(); i++) {
					tco = tcos.nodes[i];
					if (tco->Short != "") tcorefs[tco->Short] = tco->ref;
				};
			};

			if (skipchks.find(s) == skipchks.end()) {
				s = s.substr(ptr+1);

				// similar to WznmComplDbs
				if ((s.rfind("Eq")+2) == s.length()) {
					ixVBasetype = VecWznmVMCheckBasetype::EQ;
					tcoshort = s.substr(0, s.length()-2);

				} else if ((s.rfind("Incl")+4) == s.length()) {
					ixVBasetype = VecWznmVMCheckBasetype::INCL;
					tcoshort = s.substr(0, s.length()-4);

				} else if (s == "isLeaf") {
					ixVBasetype = VecWznmVMCheckBasetype::LEAF;
					tcoshort = "sup";

				} else if (s == "inSbs") {
					ixVBasetype = VecWznmVMCheckBasetype::SBS;
					tcoshort = "ref";

				} else if ((s.rfind("inSbs")+5) == s.length()) { // both cases, abc.def.inSbs and abc.inSbs -> abc
					ptr = s.find('.');

					if (ptr != string::npos) {
						ixVBasetype = VecWznmVMCheckBasetype::SBS;
						tcoshort = s.substr(0, ptr);
					} else continue;

				} else continue;

				auto it2 = tcorefs.find(tcoshort);
				if (it2 != tcorefs.end()) {
					dbswznm->tblwznmmcheck->insertNewRec(NULL, ixVBasetype, tblref, it2->second, 0, s, "");
					skipchks.insert(tblshort + "." + s);
				};
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
