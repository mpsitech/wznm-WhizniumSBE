/**
	* \file SqkWznmCtpGenjtr.h
	* squawk generation for operation pack WznmCtpGenjtr (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef SQKWZNMCTPGENJTR_H
#define SQKWZNMCTPGENJTR_H

#include "WznmCtpGenjtr_blks.h"

/**
	* SqkWznmCtpGenjtr
	*/
namespace SqkWznmCtpGenjtr {
	std::string getSquawk(DbsWznm* dbswznm, DpchInvWznmCtpGenjtr* dpchinv);
};

#endif

