/**
	* \file WznmCtpGenjtrDbeterm.cpp
	* Wznm operation processor - connect source job to terminal panel (implementation)
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

#include "WznmCtpGenjtrDbeterm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenjtr;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmCtpGenjtrDbeterm
 ******************************************************************************/

DpchRetWznmCtpGenjtr* WznmCtpGenjtrDbeterm::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenjtr* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	ubigint ref;

	WznmMCapability* cpb = NULL;

	ubigint refWznmMJob;

	WznmMJob* src = NULL;

	if (dbswznm->tblwznmmcapability->loadRecByRef(refWznmMCapability, &cpb)) {
		// consider introducing derived cpbRunv's: here TblWznmMPanel (NOT TblWznmMJob, because it's unclear where to update this)
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND sref = '" + cpb->sref + "'", refWznmMJob)) {
			if (dbswznm->tblwznmmjob->loadRecBySQL("SELECT TblWznmMJob.* FROM TblWznmMJob, TblWznmRMCapabilityUniversal WHERE TblWznmRMCapabilityUniversal.refWznmMCapability = " + to_string(refWznmMCapability)
						+ " AND TblWznmRMCapabilityUniversal.srefKKey = 'src' AND TblWznmMJob.ref = TblWznmRMCapabilityUniversal.unvUref", &src)) {

				if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMCall WHERE refWznmMVersion = " + to_string(cpb->refWznmMVersion) + " AND sref = 'Call" + Prjshort + "ClaimChg'", ref))
							dbswznm->tblwznmmsensitivity->insertNewRec(NULL, VecWznmVMSensitivityBasetype::CAL, refWznmMJob, 0, ref, VecWznmVMSensitivityJactype::WEAK, VecWznmVMSensitivityJobmask::SPEC, StrMod::lc(src->sref.substr(3+4)), "", 0, "", VecWznmVMSensitivityAction::CUST, 0, false);

				dbswznm->tblwznmrmjobmjob->insertNewRec(NULL, refWznmMJob, src->ref, StrMod::lc(src->sref.substr(3+4)), false, VecWznmVRMJobMJobConstract::CRE);

				delete src;
			};
		};

		delete cpb;
	};
	// IP run --- IEND

	return(new DpchRetWznmCtpGenjtr("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
