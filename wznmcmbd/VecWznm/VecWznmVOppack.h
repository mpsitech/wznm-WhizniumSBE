/**
	* \file VecWznmVOppack.h
	* vector VecWznmVOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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

	void appendToFeed(const Sbecore::uint ix, Sbecore::Feed& feed);
	void fillFeed(Sbecore::Feed& feed);
};

#endif
