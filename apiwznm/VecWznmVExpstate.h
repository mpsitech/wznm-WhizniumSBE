/**
	* \file VecWznmVExpstate.h
	* vector VecWznmVExpstate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef VECWZNMVEXPSTATE_H
#define VECWZNMVEXPSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVExpstate
	*/
namespace VecWznmVExpstate {
	const Sbecore::uint DETD = 1;
	const Sbecore::uint MAXD = 2;
	const Sbecore::uint MIND = 3;
	const Sbecore::uint REGD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

