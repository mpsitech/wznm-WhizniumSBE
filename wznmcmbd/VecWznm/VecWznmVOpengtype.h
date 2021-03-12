/**
	* \file VecWznmVOpengtype.h
	* vector VecWznmVOpengtype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWZNMVOPENGTYPE_H
#define VECWZNMVOPENGTYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVOpengtype
	*/
namespace VecWznmVOpengtype {
	const Sbecore::uint WZNMOPD1 = 1;
	const Sbecore::uint WZNMOPD2 = 2;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
};

#endif
