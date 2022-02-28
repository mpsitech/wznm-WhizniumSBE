/**
	* \file SqkWznmWrvue.h
	* squawk generation for operation pack WznmWrvue (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Feb 2022
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRVUE_H
#define SQKWZNMWRVUE_H

#include "WznmWrvue_blks.h"

/**
	* SqkWznmWrvue
	*/
namespace SqkWznmWrvue {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrvueBase* dpchinv);
	std::string getSquawkCrd(DbsWznm* dbswznm, DpchInvWznmWrvueCrd* dpchinv);
	std::string getSquawkDlg(DbsWznm* dbswznm, DpchInvWznmWrvueDlg* dpchinv);
	std::string getSquawkPnl(DbsWznm* dbswznm, DpchInvWznmWrvuePnl* dpchinv);
};

#endif
