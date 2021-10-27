/**
	* \file WznmComplCtpcpy.cpp
	* Wznm operation processor - copy dependencies and parameters from template (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmComplCtpcpy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCompl;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmComplCtpcpy
 ******************************************************************************/

DpchRetWznm* WznmComplCtpcpy::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmComplCtpcpy* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMCapability* cpb = NULL;
	WznmMCapability* ctp = NULL;

	ListWznmRMCapabilityUniversal cpbRunvs;
	WznmRMCapabilityUniversal* cpbRunv = NULL;

	ListWznmAMCapabilityPar cpas;
	WznmAMCapabilityPar* cpa = NULL;

	set<string> cpakeys;
	uint cpbNum;

	if (dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb)) {
		if (dbswznm->tblwznmmcapability->loadRecByRef(cpb->tplRefWznmMCapability, &ctp)) {

			// - dependencies
			dbswznm->tblwznmrmcapabilityuniversal->loadRstBySQL("SELECT * FROM TblWznmRMCapabilityUniversal WHERE refWznmMCapability = " + to_string(ctp->ref), false, cpbRunvs);
			for (unsigned int i = 0; i < cpbRunvs.nodes.size(); i++) {
				cpbRunv = cpbRunvs.nodes[i];

				cpbRunv->refWznmMCapability = cpb->ref;
				
				cpbRunv->ref = 0;
				dbswznm->tblwznmrmcapabilityuniversal->insertRec(cpbRunv);
			};

			// - parameters unless they are present already
			cpakeys.clear();

			dbswznm->tblwznmamcapabilitypar->loadRstByCpb(cpb->ref, false, cpas);
			for (unsigned int i = 0; i < cpas.nodes.size(); i++) cpakeys.insert(cpas.nodes[i]->x1SrefKKey);

			cpbNum = cpas.nodes.size() + 1;

			dbswznm->tblwznmamcapabilitypar->loadRstByCpb(ctp->ref, false, cpas);

			for (unsigned int i = 0; i < cpas.nodes.size(); i++) {
				cpa = cpas.nodes[i];

				if (cpakeys.find(cpa->x1SrefKKey) == cpakeys.end()) {
					cpa->cpbRefWznmMCapability = cpb->ref;
					cpa->cpbNum = cpbNum++;

					cpa->ref = 0;
					dbswznm->tblwznmamcapabilitypar->insertRec(cpa);
				};
			};

			delete ctp;
		};

		delete cpb;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
