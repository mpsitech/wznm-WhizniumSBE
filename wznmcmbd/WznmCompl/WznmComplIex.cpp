/**
	* \file WznmComplIex.cpp
	* Wznm operation processor - complement import/export structure (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmComplIex.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCompl;

/******************************************************************************
 namespace WznmComplIex
 ******************************************************************************/

DpchRetWznm* WznmComplIex::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplIex* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN

	ubigint ref;
	ubigint refVec;

	ListWznmMImpexpcplx iexs;
	WznmMImpexpcplx* iex = NULL;

	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	ListWznmMImpexpcol iels;
	WznmMImpexpcol* iel = NULL;

	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;

	uint num;

	dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT TblWznmMImpexp.* FROM TblWznmMImpexp, TblWznmMImpexpcplx WHERE TblWznmMImpexp.refWznmMImpexpcplx = TblWznmMImpexpcplx.ref AND TblWznmMImpexpcplx.refWznmMVersion = "
				+ to_string(refWznmMVersion) + " AND TblWznmMImpexp.supRefWznmMImpexp <> 0", false, imes);

	// - additional load functions enabling collect/export
	for (unsigned int i = 0; i < imes.nodes.size(); i++) {
		ime = imes.nodes[i];

		if (dbswznm->tblwznmmimpexpcol->loadRecBySQL("SELECT * FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(ime->ref) + " AND ixVConvtype = " + to_string(VecWznmVMImpexpcolConvtype::SUP), &iel)) {
			if (dbswznm->tblwznmmtablecol->loadRecByRef(iel->refWznmMTablecol, &tco)) {

				if (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) {
					tco2 = NULL;
					
					dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND refWznmMRelation = " + to_string(tco->refWznmMRelation)
								+ " AND sref LIKE '%VTbl'", &tco2);
					if (!tco2) dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::VECREF) + " AND refWznmMRelation = " + to_string(tco->refWznmMRelation)
								+ " AND sref LIKE '%VMaintable'", &tco2);

					if (tco2) {
						if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(tco->tblRefWznmMTable) + " AND Fctname = 'loadRefsBy" + StrMod::cap(tco2->Short) + StrMod::cap(tco->Short) + "'", ref)) {
							dbswznm->tblwznmamtableloadfct->insertNewRec(NULL, tco->tblRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsBy" + StrMod::cap(tco2->Short) + StrMod::cap(tco->Short), "ref", tco2->sref + ";" + tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
						};

						delete tco2;
					};

				} else {
					if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmAMTableLoadfct WHERE refWznmMTable = " + to_string(tco->tblRefWznmMTable) + " AND Fctname = 'loadRefsBy" + StrMod::cap(tco->Short) + "'", ref)) {
						dbswznm->tblwznmamtableloadfct->insertNewRec(NULL, tco->tblRefWznmMTable, VecWznmVAMTableLoadfctLoadtype::REFS, "loadRefsBy" + StrMod::cap(tco->Short), "ref", tco->sref, "", VecWznmVAMTableLoadfctLimtype::VOID);
					};
				};

				delete tco;
			};

			delete iel;
		};
	};

	// - vectors
	dbswznm->tblwznmmimpexpcplx->loadRstByVer(refWznmMVersion, false, iexs);

	for (unsigned int i = 0; i < iexs.nodes.size(); i++) {
		iex = iexs.nodes[i];

		dbswznm->tblwznmmimpexp->loadRstByIex(iex->ref, false, imes);

		// VecVIme {<all ime's>}
		refVec = dbswznm->tblwznmmvector->insertNewRec(NULL, VecWznmVMVectorBasetype::LIN, iex->refWznmMVersion, VecWznmVMVectorHkTbl::IEX,
					iex->ref, 0, "VecV" + iex->sref + "Ime", "", "noloc;notit");

		for (unsigned int j = 0; j < imes.nodes.size(); j++) {
			ime = imes.nodes[j];
			dbswznm->tblwznmmvectoritem->insertNewRec(NULL, refVec, (j+1), ime->sref, "", "", 0, "", "");
		};

		// VecWIel for each ime {<all iel's not in table>}
		for (unsigned int j = 0; j < imes.nodes.size(); j++) {
			ime = imes.nodes[j];

			refVec = dbswznm->tblwznmmvector->insertNewRec(NULL, VecWznmVMVectorBasetype::OR, iex->refWznmMVersion, VecWznmVMVectorHkTbl::IME,
						ime->ref, 0, "VecWImeI" + iex->sref.substr(3) + ime->sref.substr(4) + "Iel", "", "noloc;notit");

			dbswznm->tblwznmmimpexpcol->loadRstBySQL("SELECT * FROM TblWznmMImpexpcol WHERE imeRefWznmMImpexp = " + to_string(ime->ref) + " ORDER BY imeNum ASC", false, iels);

			num = 1;
			for (unsigned int k = 0; k < iels.nodes.size(); k++) {
				iel = iels.nodes[k];

				if (iel->ixWOccurrence & VecWznmWMImpexpcolOccurrence::FIL) {
					dbswznm->tblwznmmvectoritem->insertNewRec(NULL, refVec, num, iel->sref, "", "", 0, "", "");
					num++;
				};
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT


