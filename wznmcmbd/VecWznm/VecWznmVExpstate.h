/**
	* \file VecWznmVExpstate.h
	* vector VecWznmVExpstate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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



