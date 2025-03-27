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
	const Sbecore::uint STUBWZNMBOXSTD = 3;
	const Sbecore::uint STUBWZNMCALSTD = 4;
	const Sbecore::uint STUBWZNMCAPSTD = 5;
	const Sbecore::uint STUBWZNMCPBSREF = 6;
	const Sbecore::uint STUBWZNMCPBSTD = 7;
	const Sbecore::uint STUBWZNMCTPSREF = 8;
	const Sbecore::uint STUBWZNMCTPSTD = 9;
	const Sbecore::uint STUBWZNMCARSTD = 10;
	const Sbecore::uint STUBWZNMCHKSTD = 11;
	const Sbecore::uint STUBWZNMCMPSTD = 12;
	const Sbecore::uint STUBWZNMCONSREF = 13;
	const Sbecore::uint STUBWZNMCONSTD = 14;
	const Sbecore::uint STUBWZNMDLGSTD = 15;
	const Sbecore::uint STUBWZNMEVTSTD = 16;
	const Sbecore::uint STUBWZNMFEDSREF = 17;
	const Sbecore::uint STUBWZNMFEDSTD = 18;
	const Sbecore::uint STUBWZNMFILSTD = 19;
	const Sbecore::uint STUBWZNMIMESTD = 20;
	const Sbecore::uint STUBWZNMIELSTD = 21;
	const Sbecore::uint STUBWZNMIEXSTD = 22;
	const Sbecore::uint STUBWZNMJOBSTD = 23;
	const Sbecore::uint STUBWZNMLIBSREF = 24;
	const Sbecore::uint STUBWZNMLIBSTD = 25;
	const Sbecore::uint STUBWZNMLOCSREF = 26;
	const Sbecore::uint STUBWZNMLOCSTD = 27;
	const Sbecore::uint STUBWZNMMCHSREF = 28;
	const Sbecore::uint STUBWZNMMCHSTD = 29;
	const Sbecore::uint STUBWZNMMTDSTD = 30;
	const Sbecore::uint STUBWZNMMDLSTD = 31;
	const Sbecore::uint STUBWZNMOPXSTD = 32;
	const Sbecore::uint STUBWZNMOPKSTD = 33;
	const Sbecore::uint STUBWZNMPNLSTD = 34;
	const Sbecore::uint STUBWZNMPRSSTD = 35;
	const Sbecore::uint STUBWZNMPSTSTD = 36;
	const Sbecore::uint STUBWZNMPRJSHORT = 37;
	const Sbecore::uint STUBWZNMPRJSTD = 38;
	const Sbecore::uint STUBWZNMQRYSTD = 39;
	const Sbecore::uint STUBWZNMQCOSTD = 40;
	const Sbecore::uint STUBWZNMQMDSTD = 41;
	const Sbecore::uint STUBWZNMRELSTD = 42;
	const Sbecore::uint STUBWZNMRLSSTD = 43;
	const Sbecore::uint STUBWZNMRTBSTD = 44;
	const Sbecore::uint STUBWZNMRTDSTD = 45;
	const Sbecore::uint STUBWZNMRTJSTD = 46;
	const Sbecore::uint STUBWZNMSEQSTD = 47;
	const Sbecore::uint STUBWZNMSESMENU = 48;
	const Sbecore::uint STUBWZNMSESSTD = 49;
	const Sbecore::uint STUBWZNMSHTSTD = 50;
	const Sbecore::uint STUBWZNMSQKSTD = 51;
	const Sbecore::uint STUBWZNMSGESTD = 52;
	const Sbecore::uint STUBWZNMSTESTD = 53;
	const Sbecore::uint STUBWZNMSTBSTD = 54;
	const Sbecore::uint STUBWZNMSBSSTD = 55;
	const Sbecore::uint STUBWZNMTBLSTD = 56;
	const Sbecore::uint STUBWZNMTCOSREF = 57;
	const Sbecore::uint STUBWZNMTCOSTD = 58;
	const Sbecore::uint STUBWZNMTAGSTD = 59;
	const Sbecore::uint STUBWZNMOWNER = 60;
	const Sbecore::uint STUBWZNMUSRSTD = 61;
	const Sbecore::uint STUBWZNMGROUP = 62;
	const Sbecore::uint STUBWZNMUSGSTD = 63;
	const Sbecore::uint STUBWZNMVECSTD = 64;
	const Sbecore::uint STUBWZNMVITSREF = 65;
	const Sbecore::uint STUBWZNMVITSTD = 66;
	const Sbecore::uint STUBWZNMVERNO = 67;
	const Sbecore::uint STUBWZNMVERSHORT = 68;
	const Sbecore::uint STUBWZNMVERSTD = 69;
	const Sbecore::uint STUBWZNMVISSTD = 70;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
