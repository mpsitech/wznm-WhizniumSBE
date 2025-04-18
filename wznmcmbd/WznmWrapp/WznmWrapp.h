/**
	* \file WznmWrapp.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMWRAPP_H
#define WZNMWRAPP_H

#include "WznmWrapp_blks.h"

// IP include.cust --- INSERT

namespace WznmWrapp {

	// IP cust --- IBEGIN
	void loadRtjtree(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMApp, ListWznmMRtjob& rtjs);

	void writeRtjtree(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixWznmVApptarget, ListWznmMRtjob& rtjs);
	void writeRtobjs(DbsWznm* dbswznm, std::fstream& outfile, const Sbecore::uint ixWznmVApptarget, ListWznmMRtjob& rtjs);

	void analyzeStes(DbsWznm* dbswznm, const Sbecore::ubigint refWznmMApp, ListWznmMSequence& seqs, ListWznmMState& stes, std::vector<unsigned int>& icsSeqs, std::vector<Sbecore::uint>& cntsEnt, std::vector<Sbecore::uint>& cntsReent, std::vector<Sbecore::uint>& cntsLve);

	void getSteTrigs(DbsWznm* dbswznm, const std::string& Prjshort, const std::string& Appshort, const Sbecore::uint ixWznmVApptarget, const Sbecore::ubigint refWznmMState, const std::string& dom, const std::string& subdlm, std::map<std::string,std::string>& trigs);
	std::string getSteTrigs_string(DbsWznm* dbswznm, const std::string& Prjshort, const std::string& Appshort, const Sbecore::uint ixWznmVApptarget, WznmAMStateTrig* steAtrg, const std::string& dom, const std::string& subdlm);

	void getTargetStrs(const Sbecore::uint ixWznmVApptarget, std::string& dom, std::string& indent, std::string& subdlm, std::string& dpchjref);

	std::string getScrJrefVar(DbsWznm* dbswznm, WznmMRtjob* rtj, WznmMJob* job);
	// IP cust --- IEND
};

#endif
