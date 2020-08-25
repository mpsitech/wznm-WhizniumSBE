/**
	* \file VecWznmVReqitmode.h
	* vector VecWznmVReqitmode (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef VECWZNMVREQITMODE_H
#define VECWZNMVREQITMODE_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVReqitmode
	*/
namespace VecWznmVReqitmode {
	const Sbecore::uint IDLE = 1;
	const Sbecore::uint NOTIFY = 2;
	const Sbecore::uint POLL = 3;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

