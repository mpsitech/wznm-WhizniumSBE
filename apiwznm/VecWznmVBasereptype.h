/**
	* \file VecWznmVBasereptype.h
	* vector VecWznmVBasereptype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

