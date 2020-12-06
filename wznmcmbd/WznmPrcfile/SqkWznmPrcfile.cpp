/**
	* \file SqkWznmPrcfile.cpp
	* squawk generation for operation pack WznmPrcfile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "SqkWznmPrcfile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace SqkWznmPrcfile
 ******************************************************************************/

string SqkWznmPrcfile::getSquawkConcat(
			DbsWznm* dbswznm
			, DpchInvWznmPrcfileConcat* dpchinv
		) {
	// example: "concatenate text from mutliple input files into output file 'test/abcd/test.txt'"
	return("concatenate text from mutliple input files into output file '" + dpchinv->outfile + "'"); // IP getSquawkConcat --- RLINE
};

string SqkWznmPrcfile::getSquawkPlhrpl(
			DbsWznm* dbswznm
			, DpchInvWznmPrcfilePlhrpl* dpchinv
		) {
	// example: "replace placeholders by text into file 'test/abcd/test.txt'"
	return("replace placeholders by text into file '" + dpchinv->outfile + "'"); // IP getSquawkPlhrpl --- RLINE
};
