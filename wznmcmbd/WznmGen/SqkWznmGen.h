/**
	* \file SqkWznmGen.h
	* squawk generation for operation pack WznmGen (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

