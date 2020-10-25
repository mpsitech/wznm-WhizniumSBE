/**
	* \file WznmComplBscui.cpp
	* Wznm operation processor - complement basic user interface (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmComplBscui.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCompl;

/******************************************************************************
 namespace WznmComplBscui
 ******************************************************************************/

DpchRetWznm* WznmComplBscui::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplBscui* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	genCarJtits(dbswznm, refWznmMVersion, Prjshort);
	genCaraccPres(dbswznm, refWznmMVersion, Prjshort);
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmComplBscui::genCarJtits(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	vector<ubigint> refs;
	ubigint ref;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	ListWznmAMTableTitle tats;
	WznmAMTableTitle* tat = NULL;

	ListWznmAMSubsetTitle sats;
	WznmAMSubsetTitle* sat = NULL;

	ubigint refLcl;

	Wznm::getVerlclref(dbswznm, refWznmMVersion, refLcl);

	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if ( (car->refIxVTbl == VecWznmVMCardRefTbl::TBL) && (car->refJTitle == 0) ) {
			dbswznm->tblwznmamtabletitle->loadRstBySQL("SELECT * FROM TblWznmAMTableTitle WHERE refWznmMTable = " + to_string(car->refUref) + " AND x1IxVType = " + to_string(VecWznmVAMTableTitleType::PLFULL), false, tats);

			for (unsigned int j = 0; j < tats.nodes.size(); j++) {
				tat = tats.nodes[j];

				ref = dbswznm->tblwznmjmcardtitle->insertNewRec(NULL, car->ref, tat->x2RefWznmMLocale, tat->Title);

				if (tat->x2RefWznmMLocale == refLcl) {
					car->refJTitle = ref;
					car->Title = tat->Title;
					
					dbswznm->tblwznmmcard->updateRec(car);
				};
			};

		} else if ( (car->refIxVTbl == VecWznmVMCardRefTbl::SBS) && (car->refJTitle == 0) ) {
			dbswznm->tblwznmamsubsettitle->loadRstBySQL("SELECT * FROM TblWznmAMSubsetTitle WHERE refWznmMSubset = " + to_string(car->refUref) + " AND x1IxVType = " + to_string(VecWznmVAMSubsetTitleType::PLFULL), false, sats);

			for (unsigned int j = 0; j < sats.nodes.size(); j++) {
				sat = sats.nodes[j];

				ref = dbswznm->tblwznmjmcardtitle->insertNewRec(NULL, car->ref, sat->x2RefWznmMLocale, sat->Title);

				if (sat->x2RefWznmMLocale == refLcl) {
					car->refJTitle = ref;
					car->Title = sat->Title;
					
					dbswznm->tblwznmmcard->updateRec(car);
				};
			};
		};
	};
};

void WznmComplBscui::genCaraccPres(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
		) {
	vector<ubigint> refs;

	ubigint refVec;

	ListWznmMPreset pres;

	ListWznmMCard cars;
	WznmMCard* car = NULL;

	dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = 'Vec" + Prjshort + "WAccess'", refVec);

	dbswznm->tblwznmmmodule->loadRefsByVer(refWznmMVersion, false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswznm->tblwznmmcard->loadRstByMdl(refs[i], true, cars);

	// one preset for each card
	for (unsigned int i = 0; i < cars.nodes.size(); i++) {
		car = cars.nodes[i];

		if (car->sref.substr(3+4).compare("Nav") != 0) {
			dbswznm->tblwznmmpreset->appendNewRecToRst(pres, NULL, refWznmMVersion, VecWznmVMPresetRefTbl::VEC, refVec, VecWznmVMPresetScope::SESS, "Pre" + Prjshort + "IxCrdacc" + car->sref.substr(3+4),
						VecWznmWArgtype::IX, 0, "");
		};
	};
};
// IP cust --- IEND


