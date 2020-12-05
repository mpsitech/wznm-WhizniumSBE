/**
	* \file WznmGenQtb.cpp
	* Wznm operation processor - generate query tables (implementation)
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

#include "WznmGenQtb.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmGen;

/******************************************************************************
 namespace WznmGenQtb
 ******************************************************************************/

DpchRetWznm* WznmGenQtb::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmGenQtb* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmMTablecol tcos;
	WznmMTablecol* tco = NULL;
	WznmMTablecol* srctco = NULL;

	ListWznmMQuery qrys;
	WznmMQuery* qry = NULL;

	ListWznmMQuerycol qcos;
	WznmMQuerycol* qco = NULL;

	ListWznmRMQueryMTable qrts;
	WznmRMQueryMTable* qrt = NULL;

	dbswznm->tblwznmmquery->loadRstBySQL("SELECT * FROM TblWznmMQuery WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND supRefWznmMQuery = 0", false, qrys);
	for (unsigned int i = 0; i < qrys.nodes.size(); i++) {
		qry = qrys.nodes[i];

		if (!dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMTable WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + qry->sref + "'", ref)) {
			// create entry in TblWznmMTable (if not yet existing)
			tbl = new WznmMTable();
			
			tbl->ixVBasetype = VecWznmVMTableBasetype::QRY;
			tbl->refWznmMVersion = refWznmMVersion;
			tbl->refIxVTbl = VecWznmVMTableRefTbl::QRY;
			tbl->refUref = qry->ref;

			// generate query table sref
			tbl->sref = "Tbl" + Prjshort + "Q" + qry->sref.substr(qry->sref.find(Prjshort) + Prjshort.length());
			
			dbswznm->tblwznmmtable->insertRec(tbl);
			tbls.nodes.push_back(tbl);

			// cross link new table to query
			qry->qtbRefWznmMTable = tbl->ref;
			dbswznm->tblwznmmquery->updateRec(qry);

			// source tables
			dbswznm->tblwznmrmquerymtable->loadRstByQry(qry->ref, false, qrts);

			// query columns
			dbswznm->tblwznmmquerycol->loadRstByQry(qry->ref, false, qcos);

			for (unsigned int j = 0; j < qcos.nodes.size(); j++) {
				qco = qcos.nodes[j];

				// only those base types yield a table column
				if ((qco->ixVBasetype == VecWznmVMQuerycolBasetype::TBL) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QIDREF) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QWR)
						|| (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QJREF) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QJENUM) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::INTVAL)
						|| (qco->ixVBasetype == VecWznmVMQuerycolBasetype::DBLVAL) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::BOOLVAL) || (qco->ixVBasetype == VecWznmVMQuerycolBasetype::TXTVAL)) {

					// create entry in TblWznmMTablecol
					tco = new WznmMTablecol();
					
					tco->tblRefWznmMTable = tbl->ref;
					tco->tblNum = (j+1);
					tco->fctIxVTbl = VecWznmVMTablecolFctTbl::VOID;
					tco->sref = qco->sref;

					if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::TBL) {
						// find corresponding field in one of the source tables (first try: primary source table)
						if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(qry->refWznmMTable) + " AND sref = '" + qco->sref + "'", &srctco)) {

							if (srctco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
								tco->ixVBasetype = VecWznmVMTablecolBasetype::TBLREF;
								tco->ixVSubtype = VecWznmVMTablecolSubtype::TREFSPEC;
							} else {
								tco->ixVBasetype = srctco->ixVBasetype;
								tco->ixVSubtype = srctco->ixVSubtype;
							};

							delete srctco;

						} else {
							// look in secondary tables
							for (unsigned int k = 0; k < qrts.nodes.size(); k++) {
								qrt = qrts.nodes[k];

								if (qrt->Prefix.length() > 0) {
									if (qrt->Prefix[0] == tco->sref[0]) {
										// prefix match
										if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(qrt->refWznmMTable) + " AND sref = '" + qco->sref.substr(1) + "'", &srctco)) {

											if (srctco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
												tco->ixVBasetype = VecWznmVMTablecolBasetype::TBLREF;
												tco->ixVSubtype = VecWznmVMTablecolSubtype::TREFSPEC;
											} else {
												tco->ixVBasetype = srctco->ixVBasetype;
												tco->ixVSubtype = srctco->ixVSubtype;
											};

											delete srctco;
										};
									};
								};
							};
						};

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QIDREF) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::IDREF;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::VOID;

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QWR) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::BOOLVAL;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::VOID;

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QJREF) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::INTVAL;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::UBIGINT;
						tco->srefsKOption = "idx";

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::QJENUM) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::ENUM;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::VOID;
						tco->srefsKOption = "idx";

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::INTVAL) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::INTVAL;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::INT;

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::DBLVAL) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::DBLVAL;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::VOID;

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::BOOLVAL) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::BOOLVAL;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::VOID;

					} else if (qco->ixVBasetype == VecWznmVMQuerycolBasetype::TXTVAL) {
						tco->ixVBasetype = VecWznmVMTablecolBasetype::TXTVAL;
						tco->ixVSubtype = VecWznmVMTablecolSubtype::TXT192;
					};

					dbswznm->tblwznmmtablecol->insertRec(tco);
					tcos.nodes.push_back(tco);
				};
			};
		};
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT



