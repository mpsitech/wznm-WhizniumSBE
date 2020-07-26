/**
	* \file WznmWrsrvJob.h
	* Wznm operation processor - write C++ code for job (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMWRSRVJOB_H
#define WZNMWRSRVJOB_H

#include "WznmWrsrv.h"

// IP include.cust --- INSERT

namespace WznmWrsrvJob {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmWrsrvJob* dpchinv);
	// IP cust --- IBEGIN

	void writeJobH(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, ListWznmRMJobMJob& jrjs, ListWznmMVector& vecs, ListWznmMBlock& blks, ListWznmMBlock& dpchs, ListWznmMBlock& rets, ListWznmMControl& cons, ListWznmMFeed& feds, ListWznmMStage& sges, std::map<Sbecore::ubigint,std::string>& srefsSges, ListWznmAMJobCmd& cmds, ListWznmMMethod& mtds, ListWznmAMJobVar& vars, ListWznmMSensitivity& snss, std::vector<std::string>& rulesEval, std::vector<std::string>& exprsEval, const std::string& Prjshort, const bool hasstg, const bool hasdpch, const bool hassge, const bool hassgealr, const bool hasuld, const bool hasdld, const bool hastmr, const bool hascall);
	void writeJobblksCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, ListWznmMVector& vecs, ListWznmMBlock& blks, const std::string& orgweb, const std::string& Prjshort, Sbecore::ubigint& refLcl, std::vector<Sbecore::ubigint>& refsLcl);
	void writeJobevalsCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, ListWznmMTable& rectbls, std::vector<std::string>& rulesEval, std::vector<std::string>& exprsEval, const std::string& Prjshort);

	void writeJobCpp(DbsWznm* dbswznm, std::fstream& outfile, WznmMJob* job, ListWznmRMJobMJob& jrjs, ListWznmMVector& vecs, ListWznmMBlock& blks, ListWznmMBlock& dpchs, ListWznmMBlock& rets, ListWznmMControl& cons, ListWznmMFeed& feds, ListWznmMStage& sges, std::map<Sbecore::ubigint,std::string>& srefsSges, ListWznmAMJobCmd& cmds, ListWznmMMethod& mtds, ListWznmMSensitivity& snss, ListWznmMTable& rectbls, const std::string& Prjshort, ListWznmMLocale& lcls, const bool hasblks, const bool hasevals, const bool hasdpch, const bool hassge, const bool hassgealr, const bool hasuld, const bool hasdld, const bool hasret, const bool hastmr, const bool hascall);

	void wrIparpa(std::fstream& outfile, const std::string& sref, const Sbecore::uint ixWznmVVartype, const bool newline, const bool refNotConst, const bool ns);

	void analyzeSns(DbsWznm* dbswznm, WznmMSensitivity* sns, const std::map<std::string,Sbecore::uint>& csasJrjs, const std::map<Sbecore::ubigint,std::string>& srefsSges, const std::string& Prjshort, std::string& fctname, std::string& fctif, Sbecore::uint& skipInvIxWznmWArgtype, bool& skipsref, bool& skipsge, Sbecore::Arg& arg, bool& nonspecarg);

	std::string genSgeif(std::vector<std::string>& ss, const std::string& Prjshort);

	std::string rplSqkstr(const std::string& sqkstr);
	// IP cust --- IEND
};

#endif


