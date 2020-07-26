/**
	* \file VecWznmVOpengtype.h
	* vector VecWznmVOpengtype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

	void appendToFeed(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

