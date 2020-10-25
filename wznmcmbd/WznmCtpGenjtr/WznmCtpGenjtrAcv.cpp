/**
	* \file WznmCtpGenjtrAcv.cpp
	* Wznm operation processor - add stages to upload dialog (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmCtpGenjtrAcv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmCtpGenjtr;

/******************************************************************************
 namespace WznmCtpGenjtrAcv
 ******************************************************************************/

DpchRetWznmCtpGenjtr* WznmCtpGenjtrAcv::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmCtpGenjtr* dpchinv
		) {
	ubigint refWznmMCapability = dpchinv->refWznmMCapability;
	string Prjshort = dpchinv->Prjshort;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- INSERT

	return(new DpchRetWznmCtpGenjtr("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT

