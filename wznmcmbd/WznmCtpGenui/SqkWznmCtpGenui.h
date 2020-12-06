/**
	* \file SqkWznmCtpGenui.h
	* squawk generation for operation pack WznmCtpGenui (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
