/**
	* \file VecWznmVStub.h
	* vector VecWznmVStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef VECWZNMVSTUB_H
#define VECWZNMVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWznmVStub
	*/
namespace VecWznmVStub {
	const Sbecore::uint STUBWZNMRTJSTD = 1;
	const Sbecore::uint STUBWZNMCMPSTD = 2;
	const Sbecore::uint STUBWZNMQMDSTD = 3;
	const Sbecore::uint STUBWZNMOPXSTD = 4;
	const Sbecore::uint STUBWZNMPRSSTD = 5;
	const Sbecore::uint STUBWZNMPSTSTD = 6;
	const Sbecore::uint STUBWZNMPRJSTD = 7;
	const Sbecore::uint STUBWZNMQRYSTD = 8;
	const Sbecore::uint STUBWZNMTCOSREF = 9;
	const Sbecore::uint STUBWZNMTCOSTD = 10;
	const Sbecore::uint STUBWZNMTAGSTD = 11;
	const Sbecore::uint STUBWZNMOWNER = 12;
	const Sbecore::uint STUBWZNMUSRSTD = 13;
	const Sbecore::uint STUBWZNMGROUP = 14;
	const Sbecore::uint STUBWZNMUSGSTD = 15;
	const Sbecore::uint STUBWZNMVECSTD = 16;
	const Sbecore::uint STUBWZNMVITSREF = 17;
	const Sbecore::uint STUBWZNMVITSTD = 18;
	const Sbecore::uint STUBWZNMVERNO = 19;
	const Sbecore::uint STUBWZNMVERSTD = 20;
	const Sbecore::uint STUBWZNMTBLSTD = 21;
	const Sbecore::uint STUBWZNMSTESTD = 22;
	const Sbecore::uint STUBWZNMSTBSTD = 23;
	const Sbecore::uint STUBWZNMSBSSTD = 24;
	const Sbecore::uint STUBWZNMSGESTD = 25;
	const Sbecore::uint STUBWZNMSEQSTD = 26;
	const Sbecore::uint STUBWZNMSESMENU = 27;
	const Sbecore::uint STUBWZNMSESSTD = 28;
	const Sbecore::uint STUBWZNMSQKSTD = 29;
	const Sbecore::uint STUBWZNMRTDSTD = 30;
	const Sbecore::uint STUBWZNMRTBSTD = 31;
	const Sbecore::uint STUBWZNMRLSSTD = 32;
	const Sbecore::uint STUBWZNMRELSTD = 33;
	const Sbecore::uint STUBWZNMQCOSTD = 34;
	const Sbecore::uint STUBWZNMPNLSTD = 35;
	const Sbecore::uint STUBWZNMOPKSTD = 36;
	const Sbecore::uint STUBWZNMMDLSTD = 37;
	const Sbecore::uint STUBWZNMMTDSTD = 38;
	const Sbecore::uint STUBWZNMMTYSTD = 39;
	const Sbecore::uint STUBWZNMMCHSTD = 40;
	const Sbecore::uint STUBWZNMLOCSREF = 41;
	const Sbecore::uint STUBWZNMLOCSTD = 42;
	const Sbecore::uint STUBWZNMLIBSREF = 43;
	const Sbecore::uint STUBWZNMLIBSTD = 44;
	const Sbecore::uint STUBWZNMJOBSTD = 45;
	const Sbecore::uint STUBWZNMIEXSTD = 46;
	const Sbecore::uint STUBWZNMIELSTD = 47;
	const Sbecore::uint STUBWZNMIMESTD = 48;
	const Sbecore::uint STUBWZNMFILSTD = 49;
	const Sbecore::uint STUBWZNMFEDSREF = 50;
	const Sbecore::uint STUBWZNMFEDSTD = 51;
	const Sbecore::uint STUBWZNMDLGSTD = 52;
	const Sbecore::uint STUBWZNMCONSREF = 53;
	const Sbecore::uint STUBWZNMCONSTD = 54;
	const Sbecore::uint STUBWZNMCARSTD = 55;
	const Sbecore::uint STUBWZNMCHKSTD = 56;
	const Sbecore::uint STUBWZNMCAPSTD = 57;
	const Sbecore::uint STUBWZNMCPBSTD = 58;
	const Sbecore::uint STUBWZNMCTPSTD = 59;
	const Sbecore::uint STUBWZNMCALSTD = 60;
	const Sbecore::uint STUBWZNMBLKSTD = 61;
	const Sbecore::uint STUBWZNMAPPSTD = 62;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

