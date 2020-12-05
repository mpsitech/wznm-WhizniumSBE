/**
	* \file SqkWznmWrsrv.h
	* squawk generation for operation pack WznmWrsrv (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMWRSRV_H
#define SQKWZNMWRSRV_H

#include "WznmWrsrv_blks.h"

/**
	* SqkWznmWrsrv
	*/
namespace SqkWznmWrsrv {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmWrsrvBase* dpchinv);
	std::string getSquawkCmbengbase(DbsWznm* dbswznm, DpchInvWznmWrsrvCmbengbase* dpchinv);
	std::string getSquawkCrd(DbsWznm* dbswznm, DpchInvWznmWrsrvCrd* dpchinv);
	std::string getSquawkDds(DbsWznm* dbswznm, DpchInvWznmWrsrvDds* dpchinv);
	std::string getSquawkDeploy(DbsWznm* dbswznm, DpchInvWznmWrsrvDeploy* dpchinv);
	std::string getSquawkDlg(DbsWznm* dbswznm, DpchInvWznmWrsrvDlg* dpchinv);
	std::string getSquawkEngbase(DbsWznm* dbswznm, DpchInvWznmWrsrvEngbase* dpchinv);
	std::string getSquawkIex(DbsWznm* dbswznm, DpchInvWznmWrsrvIex* dpchinv);
	std::string getSquawkInixml(DbsWznm* dbswznm, DpchInvWznmWrsrvInixml* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmWrsrvJob* dpchinv);
	std::string getSquawkOp(DbsWznm* dbswznm, DpchInvWznmWrsrvOp* dpchinv);
	std::string getSquawkOpengbase(DbsWznm* dbswznm, DpchInvWznmWrsrvOpengbase* dpchinv);
	std::string getSquawkOpk(DbsWznm* dbswznm, DpchInvWznmWrsrvOpk* dpchinv);
	std::string getSquawkPnl(DbsWznm* dbswznm, DpchInvWznmWrsrvPnl* dpchinv);
	std::string getSquawkPref(DbsWznm* dbswznm, DpchInvWznmWrsrvPref* dpchinv);
	std::string getSquawkQry(DbsWznm* dbswznm, DpchInvWznmWrsrvQry* dpchinv);
	std::string getSquawkRootsess(DbsWznm* dbswznm, DpchInvWznmWrsrvRootsess* dpchinv);
	std::string getSquawkUa(DbsWznm* dbswznm, DpchInvWznmWrsrvUa* dpchinv);
	std::string getSquawkVec(DbsWznm* dbswznm, DpchInvWznmWrsrvVec* dpchinv);
};

#endif



