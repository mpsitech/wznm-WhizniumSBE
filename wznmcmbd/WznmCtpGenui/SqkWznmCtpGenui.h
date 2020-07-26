/**
	* \file SqkWznmCtpGenui.h
	* squawk generation for operation pack WznmCtpGenui (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef SQKWZNMCTPGENUI_H
#define SQKWZNMCTPGENUI_H

#include "WznmCtpGenui_blks.h"

/**
	* SqkWznmCtpGenui
	*/
namespace SqkWznmCtpGenui {
	std::string getSquawk(DbsWznm* dbswznm, DpchInvWznmCtpGenui* dpchinv);
};

#endif

