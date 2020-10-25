/**
	* \file WznmWrjapiVec.cpp
	* Wznm operation processor - write Java code for vector (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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


