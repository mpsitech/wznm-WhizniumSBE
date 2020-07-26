/**
	* \file SqkWznmWrweb.h
	* squawk generation for operation pack WznmWrweb (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

