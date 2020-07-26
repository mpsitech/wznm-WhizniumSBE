/**
	* \file VecWznmVQrystate.h
	* vector VecWznmVQrystate (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef VECWZNMVQRYSTATE_H
#define VECWZNMVQRYSTATE_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVQrystate
	*/
namespace VecWznmVQrystate {
	const Sbecore::uint MNR = 1;
	const Sbecore::uint OOD = 2;
	const Sbecore::uint SLM = 3;
	const Sbecore::uint UTD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

	void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

