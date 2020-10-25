/**
	* \file SqkWznmPrctree.cpp
	* squawk generation for operation pack WznmPrctree (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "SqkWznmPrctree.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmPrctree
 ******************************************************************************/

string SqkWznmPrctree::getSquawkExtract(
			DbsWznm* dbswznm
			, DpchInvWznmPrctreeExtract* dpchinv
		) {
	// example: "extract from file tree 'test/abcd' into extract file tree 'test/efgh'"
	// IP getSquawkExtract --- RBEGIN
	if (dpchinv->infile != "")return("extract insertion points from file '" + dpchinv->infile + "' into file '" + dpchinv->extfile + "'");
	else return("extract insertion points from file tree '" + dpchinv->infolder + "' into folder '" + dpchinv->extfolder + "'");
	// IP getSquawkExtract --- REND
};

string SqkWznmPrctree::getSquawkMerge(
			DbsWznm* dbswznm
			, DpchInvWznmPrctreeMerge* dpchinv
		) {
	// example: "merge extract file tree 'test/abcd' into template file tree 'test/efgh'"
	// IP getSquawkMerge --- RBEGIN
	if (dpchinv->tplfile != "") return("merge extract file '" + dpchinv->extfile + "' into template file '" + dpchinv->tplfile + "'");
	else return("merge extract file tree '" + dpchinv->extfolder + "' into template file tree '" + dpchinv->tplfolder + "'");
	// IP getSquawkMerge --- REND
};

string SqkWznmPrctree::getSquawkValidate(
			DbsWznm* dbswznm
			, DpchInvWznmPrctreeValidate* dpchinv
		) {
	// example: "validate file tree"
	return("validate file tree"); // IP getSquawkValidate --- RLINE
};


