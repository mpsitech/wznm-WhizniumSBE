/**
	* \file SqkWznmWrweb.h
	* squawk generation for operation pack WznmWrweb (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRWEB_H
#define SQKWZNMWRWEB_H

#include "WznmWrweb_blks.h"

/**
	* SqkWznmWrweb
	*/
namespace SqkWznmWrweb {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrwebBase* dpchinv);
	std::string getSquawkCrd(DbsWznm* dbswznm, DpchInvWznmWrwebCrd* dpchinv);
	std::string getSquawkDeploy(DbsWznm* dbswznm, DpchInvWznmWrwebDeploy* dpchinv);
	std::string getSquawkDlg(DbsWznm* dbswznm, DpchInvWznmWrwebDlg* dpchinv);
	std::string getSquawkPnl(DbsWznm* dbswznm, DpchInvWznmWrwebPnl* dpchinv);
};

#endif
