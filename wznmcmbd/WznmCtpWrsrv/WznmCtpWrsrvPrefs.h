/**
	* \file WznmCtpWrsrvPrefs.h
	* Wznm operation processor - implement preferences panels (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Mar 2021
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSRVPREFS_H
#define WZNMCTPWRSRVPREFS_H

#include "WznmCtpWrsrv.h"

// IP include.cust --- INSERT

namespace WznmCtpWrsrvPrefs {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmCtpWrsrv* dpchinv);
	// IP cust --- IBEGIN

	void writeCrdH(std::fstream& outfile, const std::string& Prjshort);
	void writeCrdCpp(std::fstream& outfile, const std::string& Prjshort, const std::string& Crdshort, ListWznmMBlock& blks, const std::vector<std::string>& blkreusrefs, const std::vector<std::string>& pnljobshorts, const std::vector<std::string>& pnljobblksrefsd, const std::vector<std::string>& pnljobblksrefscmbd);

	void writePnlH(std::fstream& outfile, const std::string& Prjshort, const std::string& Reusref, ListWznmMBlock& blks, const std::string& blkvarsd, const std::string& blkvarscmbd);
	void writePnlCpp(DbsWznm* dbswznm, std::fstream& outfile, const std::string& Prjshort, const std::string& Pnlsref, const bool hashdg, ListWznmMBlock& blks, const std::string& blkvarsd, const std::string& blkvarscmbd);

	void addPnljobstrs(const std::string& pnljobshort, ListWznmMBlock& blks, std::vector<std::string>& pnljobshorts, std::vector<std::string>& pnljobblksrefsds, std::vector<std::string>& pnljobblksrefscmbds);
	void getBlkvars(ListWznmMBlock& blks, std::string& blkvarsd, std::string& blkvarscmbd);
	// IP cust --- IEND
};

#endif
