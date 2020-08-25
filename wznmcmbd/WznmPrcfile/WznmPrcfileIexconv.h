/**
	* \file WznmPrcfileIexconv.h
	* Wznm operation processor - convert text import input file into output file (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMPRCFILEIEXCONV_H
#define WZNMPRCFILEIEXCONV_H

#include "WznmPrcfile.h"

// IP include.cust --- INSERT

namespace WznmPrcfileIexconv {

	DpchRetWznm* run(XchgWznm* xchg, DbsWznm* dbswznm, DpchInvWznmPrcfileIexconv* dpchinv);
	// IP cust --- IBEGIN

	void runIconv(const std::string& infile, const std::string& outfile);
	void convert(std::ifstream& txtfile, std::ofstream& iexfile);

	std::string unicodeToHexcode(unsigned int unicode);
	void strISO8859(std::string& s);

	void strRequote(std::string& s);
	// IP cust --- IEND
};

#endif


