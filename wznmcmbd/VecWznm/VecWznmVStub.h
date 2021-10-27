/**
	* \file VecWznmVStub.h
	* vector VecWznmVStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWZNMVSTUB_H
#define VECWZNMVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVStub
	*/
namespace VecWznmVStub {
	const Sbecore::uint STUBWZNMCMPSTD = 1;
	const Sbecore::uint STUBWZNMCONSREF = 2;
	const Sbecore::uint STUBWZNMCONSTD = 3;
	const Sbecore::uint STUBWZNMDLGSTD = 4;
	const Sbecore::uint STUBWZNMEVTSTD = 5;
	const Sbecore::uint STUBWZNMFEDSREF = 6;
	const Sbecore::uint STUBWZNMFEDSTD = 7;
	const Sbecore::uint STUBWZNMFILSTD = 8;
	const Sbecore::uint STUBWZNMIMESTD = 9;
	const Sbecore::uint STUBWZNMIELSTD = 10;
	const Sbecore::uint STUBWZNMIEXSTD = 11;
	const Sbecore::uint STUBWZNMJOBSTD = 12;
	const Sbecore::uint STUBWZNMLIBSREF = 13;
	const Sbecore::uint STUBWZNMLIBSTD = 14;
	const Sbecore::uint STUBWZNMLOCSREF = 15;
	const Sbecore::uint STUBWZNMLOCSTD = 16;
	const Sbecore::uint STUBWZNMMCHSREF = 17;
	const Sbecore::uint STUBWZNMMCHSTD = 18;
	const Sbecore::uint STUBWZNMMTDSTD = 19;
	const Sbecore::uint STUBWZNMMDLSTD = 20;
	const Sbecore::uint STUBWZNMOPXSTD = 21;
	const Sbecore::uint STUBWZNMBLKSTD = 22;
	const Sbecore::uint STUBWZNMAPPSTD = 23;
	const Sbecore::uint STUBWZNMSBSSTD = 24;
	const Sbecore::uint STUBWZNMVERNO = 25;
	const Sbecore::uint STUBWZNMVERSHORT = 26;
	const Sbecore::uint STUBWZNMVERSTD = 27;
	const Sbecore::uint STUBWZNMVECSTD = 28;
	const Sbecore::uint STUBWZNMVITSREF = 29;
	const Sbecore::uint STUBWZNMVITSTD = 30;
	const Sbecore::uint STUBWZNMGROUP = 31;
	const Sbecore::uint STUBWZNMUSGSTD = 32;
	const Sbecore::uint STUBWZNMOWNER = 33;
	const Sbecore::uint STUBWZNMUSRSTD = 34;
	const Sbecore::uint STUBWZNMTAGSTD = 35;
	const Sbecore::uint STUBWZNMTCOSREF = 36;
	const Sbecore::uint STUBWZNMTCOSTD = 37;
	const Sbecore::uint STUBWZNMTBLSTD = 38;
	const Sbecore::uint STUBWZNMSTESTD = 39;
	const Sbecore::uint STUBWZNMSTBSTD = 40;
	const Sbecore::uint STUBWZNMSQKSTD = 41;
	const Sbecore::uint STUBWZNMSGESTD = 42;
	const Sbecore::uint STUBWZNMSEQSTD = 43;
	const Sbecore::uint STUBWZNMSESMENU = 44;
	const Sbecore::uint STUBWZNMSESSTD = 45;
	const Sbecore::uint STUBWZNMRTJSTD = 46;
	const Sbecore::uint STUBWZNMRTDSTD = 47;
	const Sbecore::uint STUBWZNMRTBSTD = 48;
	const Sbecore::uint STUBWZNMRLSSTD = 49;
	const Sbecore::uint STUBWZNMRELSTD = 50;
	const Sbecore::uint STUBWZNMQMDSTD = 51;
	const Sbecore::uint STUBWZNMQCOSTD = 52;
	const Sbecore::uint STUBWZNMQRYSTD = 53;
	const Sbecore::uint STUBWZNMPRSSTD = 54;
	const Sbecore::uint STUBWZNMPSTSTD = 55;
	const Sbecore::uint STUBWZNMPRJSHORT = 56;
	const Sbecore::uint STUBWZNMPRJSTD = 57;
	const Sbecore::uint STUBWZNMPNLSTD = 58;
	const Sbecore::uint STUBWZNMOPKSTD = 59;
	const Sbecore::uint STUBWZNMCHKSTD = 60;
	const Sbecore::uint STUBWZNMCARSTD = 61;
	const Sbecore::uint STUBWZNMCAPSTD = 62;
	const Sbecore::uint STUBWZNMCPBSREF = 63;
	const Sbecore::uint STUBWZNMCPBSTD = 64;
	const Sbecore::uint STUBWZNMCTPSREF = 65;
	const Sbecore::uint STUBWZNMCTPSTD = 66;
	const Sbecore::uint STUBWZNMCALSTD = 67;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
