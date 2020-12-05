/**
	* \file WznmWrsrvVec.cpp
	* Wznm operation processor - write C++ code for vector (implementation)
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

#include "WznmWrsrvVec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvVec
 ******************************************************************************/

DpchRetWznm* WznmWrsrvVec::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvVec* dpchinv
		) {
	ubigint refWznmMVector = dpchinv->refWznmMVector;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMVector* vec = NULL;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	fstream hfile;
	fstream cppfile;

	string s;

	// find vector
	if (dbswznm->tblwznmmvector->loadRecByRef(refWznmMVector, &vec)) {
		Wznm::getVerlclrefs(dbswznm, vec->refWznmMVersion, refLcl, refsLcl);

		// create files
		s = xchg->tmppath + "/" + folder + "/" + vec->sref + ".h.ip";
		hfile.open(s.c_str(), ios::out);
		s = xchg->tmppath + "/" + folder + "/" + vec->sref + ".cpp.ip";
		cppfile.open(s.c_str(), ios::out);

		hfile << "// IP vec --- IBEGIN" << endl;
		writeVecH(dbswznm, Prjshort, hfile, vec, false, "");
		hfile << "// IP vec --- IEND" << endl;

		cppfile << "// IP vec --- IBEGIN" << endl;
		writeVecCpp(dbswznm, Prjshort, cppfile, vec, false, "", "", refLcl, refsLcl);
		cppfile << "// IP vec --- IEND" << endl;

		cppfile.close();
		hfile.close();

		delete vec;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT



