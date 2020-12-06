/**
	* \file SqkWznmGen.h
	* squawk generation for operation pack WznmGen (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef SQKWZNMGEN_H
#define SQKWZNMGEN_H

#include "WznmGen_blks.h"

/**
	* SqkWznmGen
	*/
namespace SqkWznmGen {
	std::string getSquawkBase(DbsWznm* dbswznm, DpchInvWznmGenBase* dpchinv);
	std::string getSquawkCal(DbsWznm* dbswznm, DpchInvWznmGenCal* dpchinv);
	std::string getSquawkChk(DbsWznm* dbswznm, DpchInvWznmGenChk* dpchinv);
	std::string getSquawkDetui(DbsWznm* dbswznm, DpchInvWznmGenDetui* dpchinv);
	std::string getSquawkJob(DbsWznm* dbswznm, DpchInvWznmGenJob* dpchinv);
	std::string getSquawkQtb(DbsWznm* dbswznm, DpchInvWznmGenQtb* dpchinv);
	std::string getSquawkSysvec(DbsWznm* dbswznm, DpchInvWznmGenSysvec* dpchinv);
};

#endif
