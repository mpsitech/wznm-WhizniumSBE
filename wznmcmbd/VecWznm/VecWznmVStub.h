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
	const Sbecore::uint STUBWZNMAPPSTD = 1;
	const Sbecore::uint STUBWZNMBLKSTD = 2;
	const Sbecore::uint STUBWZNMCALSTD = 3;
	const Sbecore::uint STUBWZNMCAPSTD = 4;
	const Sbecore::uint STUBWZNMCPBSREF = 5;
	const Sbecore::uint STUBWZNMCPBSTD = 6;
	const Sbecore::uint STUBWZNMCTPSREF = 7;
	const Sbecore::uint STUBWZNMCTPSTD = 8;
	const Sbecore::uint STUBWZNMCARSTD = 9;
	const Sbecore::uint STUBWZNMCHKSTD = 10;
	const Sbecore::uint STUBWZNMCMPSTD = 11;
	const Sbecore::uint STUBWZNMCONSREF = 12;
	const Sbecore::uint STUBWZNMCONSTD = 13;
	const Sbecore::uint STUBWZNMDLGSTD = 14;
	const Sbecore::uint STUBWZNMEVTSTD = 15;
	const Sbecore::uint STUBWZNMFEDSREF = 16;
	const Sbecore::uint STUBWZNMFEDSTD = 17;
	const Sbecore::uint STUBWZNMFILSTD = 18;
	const Sbecore::uint STUBWZNMIMESTD = 19;
	const Sbecore::uint STUBWZNMIELSTD = 20;
	const Sbecore::uint STUBWZNMIEXSTD = 21;
	const Sbecore::uint STUBWZNMJOBSTD = 22;
	const Sbecore::uint STUBWZNMLIBSREF = 23;
	const Sbecore::uint STUBWZNMLIBSTD = 24;
	const Sbecore::uint STUBWZNMLOCSREF = 25;
	const Sbecore::uint STUBWZNMLOCSTD = 26;
	const Sbecore::uint STUBWZNMMCHSREF = 27;
	const Sbecore::uint STUBWZNMMCHSTD = 28;
	const Sbecore::uint STUBWZNMMTDSTD = 29;
	const Sbecore::uint STUBWZNMMDLSTD = 30;
	const Sbecore::uint STUBWZNMOPXSTD = 31;
	const Sbecore::uint STUBWZNMOPKSTD = 32;
	const Sbecore::uint STUBWZNMPNLSTD = 33;
	const Sbecore::uint STUBWZNMPRSSTD = 34;
	const Sbecore::uint STUBWZNMPSTSTD = 35;
	const Sbecore::uint STUBWZNMPRJSHORT = 36;
	const Sbecore::uint STUBWZNMPRJSTD = 37;
	const Sbecore::uint STUBWZNMQRYSTD = 38;
	const Sbecore::uint STUBWZNMQCOSTD = 39;
	const Sbecore::uint STUBWZNMQMDSTD = 40;
	const Sbecore::uint STUBWZNMRELSTD = 41;
	const Sbecore::uint STUBWZNMRLSSTD = 42;
	const Sbecore::uint STUBWZNMRTBSTD = 43;
	const Sbecore::uint STUBWZNMRTDSTD = 44;
	const Sbecore::uint STUBWZNMRTJSTD = 45;
	const Sbecore::uint STUBWZNMSEQSTD = 46;
	const Sbecore::uint STUBWZNMSESMENU = 47;
	const Sbecore::uint STUBWZNMSESSTD = 48;
	const Sbecore::uint STUBWZNMSQKSTD = 49;
	const Sbecore::uint STUBWZNMSGESTD = 50;
	const Sbecore::uint STUBWZNMSTESTD = 51;
	const Sbecore::uint STUBWZNMSTBSTD = 52;
	const Sbecore::uint STUBWZNMSBSSTD = 53;
	const Sbecore::uint STUBWZNMTBLSTD = 54;
	const Sbecore::uint STUBWZNMTCOSREF = 55;
	const Sbecore::uint STUBWZNMTCOSTD = 56;
	const Sbecore::uint STUBWZNMTAGSTD = 57;
	const Sbecore::uint STUBWZNMOWNER = 58;
	const Sbecore::uint STUBWZNMUSRSTD = 59;
	const Sbecore::uint STUBWZNMGROUP = 60;
	const Sbecore::uint STUBWZNMUSGSTD = 61;
	const Sbecore::uint STUBWZNMVECSTD = 62;
	const Sbecore::uint STUBWZNMVITSREF = 63;
	const Sbecore::uint STUBWZNMVITSTD = 64;
	const Sbecore::uint STUBWZNMVERNO = 65;
	const Sbecore::uint STUBWZNMVERSHORT = 66;
	const Sbecore::uint STUBWZNMVERSTD = 67;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
