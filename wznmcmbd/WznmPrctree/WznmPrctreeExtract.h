/**
	* \file WznmPrctreeExtract.h
	* Wznm operation processor - extract from file tree into extract file tree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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


