/**
	* \file WznmWrjapiVec.cpp
	* Wznm operation processor - write Java code for vector (implementation)
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

#include "WznmWrjapiVec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrjapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrjapiVec
 ******************************************************************************/

DpchRetWznm* WznmWrjapiVec::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrjapiVec* dpchinv
		) {
	ubigint refWznmMVector = dpchinv->refWznmMVector;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream jfile;

	WznmMVector* vec = NULL;

	string s;

	dbswznm->tblwznmmvector->loadRecByRef(refWznmMVector, &vec);

	// create files
	s = xchg->tmppath + "/" + folder + "/" + vec->sref + ".java.ip";
	jfile.open(s.c_str(), ios::out);

	// --- vec
	jfile << "// IP vec --- IBEGIN" << endl;
	writeVecJ(dbswznm, Prjshort, jfile, vec, false, "", "");
	jfile << "// IP vec --- IEND" << endl;

	jfile.close();

	delete vec;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
