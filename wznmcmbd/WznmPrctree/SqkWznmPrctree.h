/**
	* \file SqkWznmPrctree.h
	* squawk generation for operation pack WznmPrctree (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef SQKWZNMPRCTREE_H
#define SQKWZNMPRCTREE_H

#include "WznmPrctree_blks.h"

/**
	* SqkWznmPrctree
	*/
namespace SqkWznmPrctree {
	std::string getSquawkExtract(DbsWznm* dbswznm, DpchInvWznmPrctreeExtract* dpchinv);
	std::string getSquawkMerge(DbsWznm* dbswznm, DpchInvWznmPrctreeMerge* dpchinv);
	std::string getSquawkValidate(DbsWznm* dbswznm, DpchInvWznmPrctreeValidate* dpchinv);
};

#endif

