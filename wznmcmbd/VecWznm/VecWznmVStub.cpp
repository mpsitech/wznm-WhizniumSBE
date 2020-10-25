/**
	* \file VecWznmVStub.cpp
	* vector VecWznmVStub (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "VecWznmVStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWznmVStub
 ******************************************************************************/

uint VecWznmVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubwznmverno") return STUBWZNMVERNO;
	if (s == "stubwznmvershort") return STUBWZNMVERSHORT;
	if (s == "stubwznmverstd") return STUBWZNMVERSTD;
	if (s == "stubwznmvecstd") return STUBWZNMVECSTD;
	if (s == "stubwznmvitsref") return STUBWZNMVITSREF;
	if (s == "stubwznmvitstd") return STUBWZNMVITSTD;
	if (s == "stubwznmowner") return STUBWZNMOWNER;
	if (s == "stubwznmusrstd") return STUBWZNMUSRSTD;
	if (s == "stubwznmgroup") return STUBWZNMGROUP;
	if (s == "stubwznmusgstd") return STUBWZNMUSGSTD;
	if (s == "stubwznmtcosref") return STUBWZNMTCOSREF;
	if (s == "stubwznmtcostd") return STUBWZNMTCOSTD;
	if (s == "stubwznmtagstd") return STUBWZNMTAGSTD;
	if (s == "stubwznmsbsstd") return STUBWZNMSBSSTD;
	if (s == "stubwznmtblstd") return STUBWZNMTBLSTD;
	if (s == "stubwznmstbstd") return STUBWZNMSTBSTD;
	if (s == "stubwznmsgestd") return STUBWZNMSGESTD;
	if (s == "stubwznmstestd") return STUBWZNMSTESTD;
	if (s == "stubwznmsesmenu") return STUBWZNMSESMENU;
	if (s == "stubwznmsesstd") return STUBWZNMSESSTD;
	if (s == "stubwznmsqkstd") return STUBWZNMSQKSTD;
	if (s == "stubwznmseqstd") return STUBWZNMSEQSTD;
	if (s == "stubwznmrtdstd") return STUBWZNMRTDSTD;
	if (s == "stubwznmrtjstd") return STUBWZNMRTJSTD;
	if (s == "stubwznmrlsstd") return STUBWZNMRLSSTD;
	if (s == "stubwznmrtbstd") return STUBWZNMRTBSTD;
	if (s == "stubwznmqmdstd") return STUBWZNMQMDSTD;
	if (s == "stubwznmrelstd") return STUBWZNMRELSTD;
	if (s == "stubwznmqrystd") return STUBWZNMQRYSTD;
	if (s == "stubwznmqcostd") return STUBWZNMQCOSTD;
	if (s == "stubwznmpststd") return STUBWZNMPSTSTD;
	if (s == "stubwznmprjshort") return STUBWZNMPRJSHORT;
	if (s == "stubwznmprjstd") return STUBWZNMPRJSTD;
	if (s == "stubwznmpnlstd") return STUBWZNMPNLSTD;
	if (s == "stubwznmprsstd") return STUBWZNMPRSSTD;
	if (s == "stubwznmopxstd") return STUBWZNMOPXSTD;
	if (s == "stubwznmopkstd") return STUBWZNMOPKSTD;
	if (s == "stubwznmmtdstd") return STUBWZNMMTDSTD;
	if (s == "stubwznmmdlstd") return STUBWZNMMDLSTD;
	if (s == "stubwznmmchstd") return STUBWZNMMCHSTD;
	if (s == "stubwznmmtystd") return STUBWZNMMTYSTD;
	if (s == "stubwznmlibsref") return STUBWZNMLIBSREF;
	if (s == "stubwznmlibstd") return STUBWZNMLIBSTD;
	if (s == "stubwznmlocsref") return STUBWZNMLOCSREF;
	if (s == "stubwznmlocstd") return STUBWZNMLOCSTD;
	if (s == "stubwznmiexstd") return STUBWZNMIEXSTD;
	if (s == "stubwznmjobstd") return STUBWZNMJOBSTD;
	if (s == "stubwznmimestd") return STUBWZNMIMESTD;
	if (s == "stubwznmielstd") return STUBWZNMIELSTD;
	if (s == "stubwznmfedsref") return STUBWZNMFEDSREF;
	if (s == "stubwznmfedstd") return STUBWZNMFEDSTD;
	if (s == "stubwznmfilstd") return STUBWZNMFILSTD;
	if (s == "stubwznmevtstd") return STUBWZNMEVTSTD;
	if (s == "stubwznmconsref") return STUBWZNMCONSREF;
	if (s == "stubwznmconstd") return STUBWZNMCONSTD;
	if (s == "stubwznmdlgstd") return STUBWZNMDLGSTD;
	if (s == "stubwznmchkstd") return STUBWZNMCHKSTD;
	if (s == "stubwznmcmpstd") return STUBWZNMCMPSTD;
	if (s == "stubwznmcapstd") return STUBWZNMCAPSTD;
	if (s == "stubwznmcpbstd") return STUBWZNMCPBSTD;
	if (s == "stubwznmctpstd") return STUBWZNMCTPSTD;
	if (s == "stubwznmcarstd") return STUBWZNMCARSTD;
	if (s == "stubwznmcalstd") return STUBWZNMCALSTD;
	if (s == "stubwznmappstd") return STUBWZNMAPPSTD;
	if (s == "stubwznmblkstd") return STUBWZNMBLKSTD;

	return(0);
};

string VecWznmVStub::getSref(
			const uint ix
		) {
	if (ix == STUBWZNMVERNO) return("StubWznmVerNo");
	if (ix == STUBWZNMVERSHORT) return("StubWznmVerShort");
	if (ix == STUBWZNMVERSTD) return("StubWznmVerStd");
	if (ix == STUBWZNMVECSTD) return("StubWznmVecStd");
	if (ix == STUBWZNMVITSREF) return("StubWznmVitSref");
	if (ix == STUBWZNMVITSTD) return("StubWznmVitStd");
	if (ix == STUBWZNMOWNER) return("StubWznmOwner");
	if (ix == STUBWZNMUSRSTD) return("StubWznmUsrStd");
	if (ix == STUBWZNMGROUP) return("StubWznmGroup");
	if (ix == STUBWZNMUSGSTD) return("StubWznmUsgStd");
	if (ix == STUBWZNMTCOSREF) return("StubWznmTcoSref");
	if (ix == STUBWZNMTCOSTD) return("StubWznmTcoStd");
	if (ix == STUBWZNMTAGSTD) return("StubWznmTagStd");
	if (ix == STUBWZNMSBSSTD) return("StubWznmSbsStd");
	if (ix == STUBWZNMTBLSTD) return("StubWznmTblStd");
	if (ix == STUBWZNMSTBSTD) return("StubWznmStbStd");
	if (ix == STUBWZNMSGESTD) return("StubWznmSgeStd");
	if (ix == STUBWZNMSTESTD) return("StubWznmSteStd");
	if (ix == STUBWZNMSESMENU) return("StubWznmSesMenu");
	if (ix == STUBWZNMSESSTD) return("StubWznmSesStd");
	if (ix == STUBWZNMSQKSTD) return("StubWznmSqkStd");
	if (ix == STUBWZNMSEQSTD) return("StubWznmSeqStd");
	if (ix == STUBWZNMRTDSTD) return("StubWznmRtdStd");
	if (ix == STUBWZNMRTJSTD) return("StubWznmRtjStd");
	if (ix == STUBWZNMRLSSTD) return("StubWznmRlsStd");
	if (ix == STUBWZNMRTBSTD) return("StubWznmRtbStd");
	if (ix == STUBWZNMQMDSTD) return("StubWznmQmdStd");
	if (ix == STUBWZNMRELSTD) return("StubWznmRelStd");
	if (ix == STUBWZNMQRYSTD) return("StubWznmQryStd");
	if (ix == STUBWZNMQCOSTD) return("StubWznmQcoStd");
	if (ix == STUBWZNMPSTSTD) return("StubWznmPstStd");
	if (ix == STUBWZNMPRJSHORT) return("StubWznmPrjShort");
	if (ix == STUBWZNMPRJSTD) return("StubWznmPrjStd");
	if (ix == STUBWZNMPNLSTD) return("StubWznmPnlStd");
	if (ix == STUBWZNMPRSSTD) return("StubWznmPrsStd");
	if (ix == STUBWZNMOPXSTD) return("StubWznmOpxStd");
	if (ix == STUBWZNMOPKSTD) return("StubWznmOpkStd");
	if (ix == STUBWZNMMTDSTD) return("StubWznmMtdStd");
	if (ix == STUBWZNMMDLSTD) return("StubWznmMdlStd");
	if (ix == STUBWZNMMCHSTD) return("StubWznmMchStd");
	if (ix == STUBWZNMMTYSTD) return("StubWznmMtyStd");
	if (ix == STUBWZNMLIBSREF) return("StubWznmLibSref");
	if (ix == STUBWZNMLIBSTD) return("StubWznmLibStd");
	if (ix == STUBWZNMLOCSREF) return("StubWznmLocSref");
	if (ix == STUBWZNMLOCSTD) return("StubWznmLocStd");
	if (ix == STUBWZNMIEXSTD) return("StubWznmIexStd");
	if (ix == STUBWZNMJOBSTD) return("StubWznmJobStd");
	if (ix == STUBWZNMIMESTD) return("StubWznmImeStd");
	if (ix == STUBWZNMIELSTD) return("StubWznmIelStd");
	if (ix == STUBWZNMFEDSREF) return("StubWznmFedSref");
	if (ix == STUBWZNMFEDSTD) return("StubWznmFedStd");
	if (ix == STUBWZNMFILSTD) return("StubWznmFilStd");
	if (ix == STUBWZNMEVTSTD) return("StubWznmEvtStd");
	if (ix == STUBWZNMCONSREF) return("StubWznmConSref");
	if (ix == STUBWZNMCONSTD) return("StubWznmConStd");
	if (ix == STUBWZNMDLGSTD) return("StubWznmDlgStd");
	if (ix == STUBWZNMCHKSTD) return("StubWznmChkStd");
	if (ix == STUBWZNMCMPSTD) return("StubWznmCmpStd");
	if (ix == STUBWZNMCAPSTD) return("StubWznmCapStd");
	if (ix == STUBWZNMCPBSTD) return("StubWznmCpbStd");
	if (ix == STUBWZNMCTPSTD) return("StubWznmCtpStd");
	if (ix == STUBWZNMCARSTD) return("StubWznmCarStd");
	if (ix == STUBWZNMCALSTD) return("StubWznmCalStd");
	if (ix == STUBWZNMAPPSTD) return("StubWznmAppStd");
	if (ix == STUBWZNMBLKSTD) return("StubWznmBlkStd");

	return("");
};

