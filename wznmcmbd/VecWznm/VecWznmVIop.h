/**
	* \file VecWznmVIop.h
	* vector VecWznmVIop (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWZNMVIOP_H
#define VECWZNMVIOP_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVIop
	*/
namespace VecWznmVIop {
	const Sbecore::uint INS = 1;
	const Sbecore::uint RETR = 2;
	const Sbecore::uint RETRINS = 3;
	const Sbecore::uint RETRUPD = 4;
	const Sbecore::uint RETRUPDINS = 5;
	const Sbecore::uint RMV = 6;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

	void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif
