/**
	* \file VecWznmVStub.h
	* vector VecWznmVStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef VECWZNMVSTUB_H
#define VECWZNMVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVStub
	*/
namespace VecWznmVStub {
	const Sbecore::uint STUBWZNMVERNO = 1;
	const Sbecore::uint STUBWZNMVERSHORT = 2;
	const Sbecore::uint STUBWZNMVERSTD = 3;
	const Sbecore::uint STUBWZNMVECSTD = 4;
	const Sbecore::uint STUBWZNMVITSREF = 5;
	const Sbecore::uint STUBWZNMVITSTD = 6;
	const Sbecore::uint STUBWZNMOWNER = 7;
	const Sbecore::uint STUBWZNMUSRSTD = 8;
	const Sbecore::uint STUBWZNMGROUP = 9;
	const Sbecore::uint STUBWZNMUSGSTD = 10;
	const Sbecore::uint STUBWZNMTCOSREF = 11;
	const Sbecore::uint STUBWZNMTCOSTD = 12;
	const Sbecore::uint STUBWZNMTAGSTD = 13;
	const Sbecore::uint STUBWZNMSBSSTD = 14;
	const Sbecore::uint STUBWZNMTBLSTD = 15;
	const Sbecore::uint STUBWZNMSTBSTD = 16;
	const Sbecore::uint STUBWZNMSGESTD = 17;
	const Sbecore::uint STUBWZNMSTESTD = 18;
	const Sbecore::uint STUBWZNMSESMENU = 19;
	const Sbecore::uint STUBWZNMSESSTD = 20;
	const Sbecore::uint STUBWZNMSQKSTD = 21;
	const Sbecore::uint STUBWZNMSEQSTD = 22;
	const Sbecore::uint STUBWZNMRTDSTD = 23;
	const Sbecore::uint STUBWZNMRTJSTD = 24;
	const Sbecore::uint STUBWZNMRLSSTD = 25;
	const Sbecore::uint STUBWZNMRTBSTD = 26;
	const Sbecore::uint STUBWZNMQMDSTD = 27;
	const Sbecore::uint STUBWZNMRELSTD = 28;
	const Sbecore::uint STUBWZNMQRYSTD = 29;
	const Sbecore::uint STUBWZNMQCOSTD = 30;
	const Sbecore::uint STUBWZNMPSTSTD = 31;
	const Sbecore::uint STUBWZNMPRJSHORT = 32;
	const Sbecore::uint STUBWZNMPRJSTD = 33;
	const Sbecore::uint STUBWZNMPNLSTD = 34;
	const Sbecore::uint STUBWZNMPRSSTD = 35;
	const Sbecore::uint STUBWZNMOPXSTD = 36;
	const Sbecore::uint STUBWZNMOPKSTD = 37;
	const Sbecore::uint STUBWZNMMTDSTD = 38;
	const Sbecore::uint STUBWZNMMDLSTD = 39;
	const Sbecore::uint STUBWZNMMCHSTD = 40;
	const Sbecore::uint STUBWZNMMTYSTD = 41;
	const Sbecore::uint STUBWZNMLIBSREF = 42;
	const Sbecore::uint STUBWZNMLIBSTD = 43;
	const Sbecore::uint STUBWZNMLOCSREF = 44;
	const Sbecore::uint STUBWZNMLOCSTD = 45;
	const Sbecore::uint STUBWZNMIEXSTD = 46;
	const Sbecore::uint STUBWZNMJOBSTD = 47;
	const Sbecore::uint STUBWZNMIMESTD = 48;
	const Sbecore::uint STUBWZNMIELSTD = 49;
	const Sbecore::uint STUBWZNMFEDSREF = 50;
	const Sbecore::uint STUBWZNMFEDSTD = 51;
	const Sbecore::uint STUBWZNMFILSTD = 52;
	const Sbecore::uint STUBWZNMEVTSTD = 53;
	const Sbecore::uint STUBWZNMCONSREF = 54;
	const Sbecore::uint STUBWZNMCONSTD = 55;
	const Sbecore::uint STUBWZNMDLGSTD = 56;
	const Sbecore::uint STUBWZNMCHKSTD = 57;
	const Sbecore::uint STUBWZNMCMPSTD = 58;
	const Sbecore::uint STUBWZNMCAPSTD = 59;
	const Sbecore::uint STUBWZNMCPBSTD = 60;
	const Sbecore::uint STUBWZNMCTPSTD = 61;
	const Sbecore::uint STUBWZNMCARSTD = 62;
	const Sbecore::uint STUBWZNMCALSTD = 63;
	const Sbecore::uint STUBWZNMAPPSTD = 64;
	const Sbecore::uint STUBWZNMBLKSTD = 65;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

