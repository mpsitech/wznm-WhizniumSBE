/**
	* \file WznmWrsapiVec.cpp
	* Wznm operation processor - write Swift code for vector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsapiVec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsapiVec
 ******************************************************************************/

DpchRetWznm* WznmWrsapiVec::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsapiVec* dpchinv
		) {
	ubigint refWznmMVector = dpchinv->refWznmMVector;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream swfile;

	WznmMVector* vec = NULL;

	string s;

	dbswznm->tblwznmmvector->loadRecByRef(refWznmMVector, &vec);

	// create files
	s = xchg->tmppath + "/" + folder + "/" + vec->sref + ".swift.ip";
	swfile.open(s.c_str(), ios::out);

	// --- vec
	swfile << "// IP vec --- IBEGIN" << endl;
	writeVecSw(dbswznm, Prjshort, swfile, vec, false, "", "");
	swfile << "// IP vec --- IEND" << endl;

	swfile.close();

	delete vec;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
