/**
	* \file WznmGenSysvec.h
	* Wznm operation processor - fill system vectors (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMGENSYSVEC_H
#define WZNMGENSYSVEC_H

#include "WznmGen.h"

// IP include.cust --- INSERT

namespace WznmGenSysvec {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmGenSysvec* dpchinv);
	// IP cust --- IBEGIN

	void findGlobal(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion);
	void findGlobal_traverse(DbsWznm* dbswznm, ListWznmMJob& jobs, std::map<Sbecore::ubigint,unsigned int>& icsJobs, const Sbecore::ubigint refWznmMJob, std::vector<unsigned int>& lastcrdics, std::vector<unsigned int>& cntsViacrd, std::vector<unsigned int>& cntsNocrd, unsigned int crdix);

	void fillVecSge(DbsWznm* dbswznm, WznmMVector* vec);
	void fillVecOrd(DbsWznm* dbswznm, WznmMVector* vec);
	void fillVecDit(DbsWznm* dbswznm, WznmMVector* vec, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void fillVecMethod(DbsWznm* dbswznm, WznmMVector* vec);
	void fillVecVar(DbsWznm* dbswznm, WznmMVector* vec);

	void fillVecControl(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);

	void fillVecCall(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void fillVecCard(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl);
	void fillVecDpch(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void fillVecError(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl);
	void fillVecFeatgroup(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void fillVecJob(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void fillVecOpengtype(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);
	void fillVecOppack(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void fillVecPreset(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl);
	void fillVecStub(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort);
	void fillVecTag(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMVersion, const std::string& Prjshort, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl);

	// IP cust --- IEND
};

#endif


