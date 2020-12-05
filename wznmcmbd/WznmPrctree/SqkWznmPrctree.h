/**
	* \file SqkWznmPrctree.h
	* squawk generation for operation pack WznmPrctree (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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



