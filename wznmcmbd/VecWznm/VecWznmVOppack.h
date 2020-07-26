/**
	* \file VecWznmVOppack.h
	* vector VecWznmVOppack (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef VECWZNMVOPPACK_H
#define VECWZNMVOPPACK_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVOppack
	*/
namespace VecWznmVOppack {
	const Sbecore::uint WZNMCOMPL = 1;
	const Sbecore::uint WZNMCTPGENJTR = 2;
	const Sbecore::uint WZNMCTPGENUI = 3;
	const Sbecore::uint WZNMCTPWRSRV = 4;
	const Sbecore::uint WZNMCTPWRSTKIT = 5;
	const Sbecore::uint WZNMCTPWRWEB = 6;
	const Sbecore::uint WZNMGEN = 7;
	const Sbecore::uint WZNMPRCFILE = 8;
	const Sbecore::uint WZNMPRCTREE = 9;
	const Sbecore::uint WZNMWRAPI = 10;
	const Sbecore::uint WZNMWRAPP = 11;
	const Sbecore::uint WZNMWRDBS = 12;
	const Sbecore::uint WZNMWRJAPI = 13;
	const Sbecore::uint WZNMWRSRV = 14;
	const Sbecore::uint WZNMWRWEB = 15;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix);
	std::string getComment(const Sbecore::uint ix);

	void appendToFeed(const Sbecore::uint ix, Sbecore::Xmlio::Feed& feed);
	void fillFeed(Sbecore::Xmlio::Feed& feed);
};

#endif

