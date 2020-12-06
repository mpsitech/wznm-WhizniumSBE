/**
	* \file WznmPrctreeExtract.h
	* Wznm operation processor - extract from file tree into extract file tree (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMPRCTREEEXTRACT_H
#define WZNMPRCTREEEXTRACT_H

#include "WznmPrctree.h"

// IP include.cust --- INSERT

namespace WznmPrctreeExtract {

	DpchRetWznmPrctreeExtract* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmPrctreeExtract* dpchinv);
	// IP cust --- IBEGIN

	bool scanFolder(const std::string& tmppath, const std::string& infolder, const std::string& extfolder, std::fstream& logfi);
	bool scanFile(const std::string& tmppath, const std::string& infile, const std::string& extfile, std::fstream& logfi);
	void writeExtfile(const std::string& tmppath, const std::string& extfile, const std::vector<WznmPrctree::Ip*>& ips);
	// IP cust --- IEND
};

#endif
