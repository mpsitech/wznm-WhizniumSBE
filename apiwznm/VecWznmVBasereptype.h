/**
	* \file VecWznmVBasereptype.h
	* vector VecWznmVBasereptype (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef VECWZNMVBASEREPTYPE_H
#define VECWZNMVBASEREPTYPE_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVBasereptype
	*/
namespace VecWznmVBasereptype {
	const Sbecore::uint VOID = 1;
	const Sbecore::uint PRJGIT = 2;
	const Sbecore::uint CUSTGIT = 3;
	const Sbecore::uint ULD = 4;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
