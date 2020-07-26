/**
	* \file SqkWznmPrcfile.cpp
	* squawk generation for operation pack WznmPrcfile (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

string SqkWznmPrcfile::getSquawkIexconv(
			DbsWznm* dbswznm
			, DpchInvWznmPrcfileIexconv* dpchinv
		) {
	// example: "convert text import input file 'test/abcd/testin.txt' into output file 'test/abcd/testout.txt'"
	return("convert text import file '" + dpchinv->infile + "' into output file '" + dpchinv->outfile + "'"); // IP getSquawkIexconv --- RLINE
};

string SqkWznmPrcfile::getSquawkPlhrpl(
			DbsWznm* dbswznm
			, DpchInvWznmPrcfilePlhrpl* dpchinv
		) {
	// example: "replace placeholders by text into file 'test/abcd/test.txt'"
	return("replace placeholders by text into file '" + dpchinv->outfile + "'"); // IP getSquawkPlhrpl --- RLINE
};


