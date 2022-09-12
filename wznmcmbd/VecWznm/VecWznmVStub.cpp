/**
	* \file VecWznmVStub.cpp
	* vector VecWznmVStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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
	if (s == "stubwznmvitsref") return STUBWZNMVITSREF;
	if (s == "stubwznmvitstd") return STUBWZNMVITSTD;
	if (s == "stubwznmvecstd") return STUBWZNMVECSTD;
	if (s == "stubwznmgroup") return STUBWZNMGROUP;
	if (s == "stubwznmusgstd") return STUBWZNMUSGSTD;
	if (s == "stubwznmtagstd") return STUBWZNMTAGSTD;
	if (s == "stubwznmowner") return STUBWZNMOWNER;
	if (s == "stubwznmusrstd") return STUBWZNMUSRSTD;
	if (s == "stubwznmtcosref") return STUBWZNMTCOSREF;
	if (s == "stubwznmtcostd") return STUBWZNMTCOSTD;
	if (s == "stubwznmtblstd") return STUBWZNMTBLSTD;
	if (s == "stubwznmsbsstd") return STUBWZNMSBSSTD;
	if (s == "stubwznmstestd") return STUBWZNMSTESTD;
	if (s == "stubwznmstbstd") return STUBWZNMSTBSTD;
	if (s == "stubwznmsgestd") return STUBWZNMSGESTD;
	if (s == "stubwznmsesmenu") return STUBWZNMSESMENU;
	if (s == "stubwznmsesstd") return STUBWZNMSESSTD;
	if (s == "stubwznmsqkstd") return STUBWZNMSQKSTD;
	if (s == "stubwznmseqstd") return STUBWZNMSEQSTD;
	if (s == "stubwznmrtjstd") return STUBWZNMRTJSTD;
	if (s == "stubwznmrtdstd") return STUBWZNMRTDSTD;
	if (s == "stubwznmrtbstd") return STUBWZNMRTBSTD;
	if (s == "stubwznmrlsstd") return STUBWZNMRLSSTD;
	if (s == "stubwznmrelstd") return STUBWZNMRELSTD;
	if (s == "stubwznmqmdstd") return STUBWZNMQMDSTD;
	if (s == "stubwznmqcostd") return STUBWZNMQCOSTD;
	if (s == "stubwznmqrystd") return STUBWZNMQRYSTD;
	if (s == "stubwznmprjshort") return STUBWZNMPRJSHORT;
	if (s == "stubwznmprjstd") return STUBWZNMPRJSTD;
	if (s == "stubwznmpststd") return STUBWZNMPSTSTD;
	if (s == "stubwznmprsstd") return STUBWZNMPRSSTD;
	if (s == "stubwznmpnlstd") return STUBWZNMPNLSTD;
	if (s == "stubwznmopkstd") return STUBWZNMOPKSTD;
	if (s == "stubwznmopxstd") return STUBWZNMOPXSTD;
	if (s == "stubwznmmdlstd") return STUBWZNMMDLSTD;
	if (s == "stubwznmmtdstd") return STUBWZNMMTDSTD;
	if (s == "stubwznmmchsref") return STUBWZNMMCHSREF;
	if (s == "stubwznmmchstd") return STUBWZNMMCHSTD;
	if (s == "stubwznmlocsref") return STUBWZNMLOCSREF;
	if (s == "stubwznmlocstd") return STUBWZNMLOCSTD;
	if (s == "stubwznmiexstd") return STUBWZNMIEXSTD;
	if (s == "stubwznmjobstd") return STUBWZNMJOBSTD;
	if (s == "stubwznmlibsref") return STUBWZNMLIBSREF;
	if (s == "stubwznmlibstd") return STUBWZNMLIBSTD;
	if (s == "stubwznmielstd") return STUBWZNMIELSTD;
	if (s == "stubwznmimestd") return STUBWZNMIMESTD;
	if (s == "stubwznmfilstd") return STUBWZNMFILSTD;
	if (s == "stubwznmappstd") return STUBWZNMAPPSTD;
	if (s == "stubwznmblkstd") return STUBWZNMBLKSTD;
	if (s == "stubwznmcalstd") return STUBWZNMCALSTD;
	if (s == "stubwznmcapstd") return STUBWZNMCAPSTD;
	if (s == "stubwznmcpbsref") return STUBWZNMCPBSREF;
	if (s == "stubwznmcpbstd") return STUBWZNMCPBSTD;
	if (s == "stubwznmctpsref") return STUBWZNMCTPSREF;
	if (s == "stubwznmctpstd") return STUBWZNMCTPSTD;
	if (s == "stubwznmcarstd") return STUBWZNMCARSTD;
	if (s == "stubwznmchkstd") return STUBWZNMCHKSTD;
	if (s == "stubwznmcmpstd") return STUBWZNMCMPSTD;
	if (s == "stubwznmconsref") return STUBWZNMCONSREF;
	if (s == "stubwznmconstd") return STUBWZNMCONSTD;
	if (s == "stubwznmfedsref") return STUBWZNMFEDSREF;
	if (s == "stubwznmfedstd") return STUBWZNMFEDSTD;
	if (s == "stubwznmevtstd") return STUBWZNMEVTSTD;
	if (s == "stubwznmdlgstd") return STUBWZNMDLGSTD;

	return(0);
};

string VecWznmVStub::getSref(
			const uint ix
		) {
	if (ix == STUBWZNMVERNO) return("StubWznmVerNo");
	if (ix == STUBWZNMVERSHORT) return("StubWznmVerShort");
	if (ix == STUBWZNMVERSTD) return("StubWznmVerStd");
	if (ix == STUBWZNMVITSREF) return("StubWznmVitSref");
	if (ix == STUBWZNMVITSTD) return("StubWznmVitStd");
	if (ix == STUBWZNMVECSTD) return("StubWznmVecStd");
	if (ix == STUBWZNMGROUP) return("StubWznmGroup");
	if (ix == STUBWZNMUSGSTD) return("StubWznmUsgStd");
	if (ix == STUBWZNMTAGSTD) return("StubWznmTagStd");
	if (ix == STUBWZNMOWNER) return("StubWznmOwner");
	if (ix == STUBWZNMUSRSTD) return("StubWznmUsrStd");
	if (ix == STUBWZNMTCOSREF) return("StubWznmTcoSref");
	if (ix == STUBWZNMTCOSTD) return("StubWznmTcoStd");
	if (ix == STUBWZNMTBLSTD) return("StubWznmTblStd");
	if (ix == STUBWZNMSBSSTD) return("StubWznmSbsStd");
	if (ix == STUBWZNMSTESTD) return("StubWznmSteStd");
	if (ix == STUBWZNMSTBSTD) return("StubWznmStbStd");
	if (ix == STUBWZNMSGESTD) return("StubWznmSgeStd");
	if (ix == STUBWZNMSESMENU) return("StubWznmSesMenu");
	if (ix == STUBWZNMSESSTD) return("StubWznmSesStd");
	if (ix == STUBWZNMSQKSTD) return("StubWznmSqkStd");
	if (ix == STUBWZNMSEQSTD) return("StubWznmSeqStd");
	if (ix == STUBWZNMRTJSTD) return("StubWznmRtjStd");
	if (ix == STUBWZNMRTDSTD) return("StubWznmRtdStd");
	if (ix == STUBWZNMRTBSTD) return("StubWznmRtbStd");
	if (ix == STUBWZNMRLSSTD) return("StubWznmRlsStd");
	if (ix == STUBWZNMRELSTD) return("StubWznmRelStd");
	if (ix == STUBWZNMQMDSTD) return("StubWznmQmdStd");
	if (ix == STUBWZNMQCOSTD) return("StubWznmQcoStd");
	if (ix == STUBWZNMQRYSTD) return("StubWznmQryStd");
	if (ix == STUBWZNMPRJSHORT) return("StubWznmPrjShort");
	if (ix == STUBWZNMPRJSTD) return("StubWznmPrjStd");
	if (ix == STUBWZNMPSTSTD) return("StubWznmPstStd");
	if (ix == STUBWZNMPRSSTD) return("StubWznmPrsStd");
	if (ix == STUBWZNMPNLSTD) return("StubWznmPnlStd");
	if (ix == STUBWZNMOPKSTD) return("StubWznmOpkStd");
	if (ix == STUBWZNMOPXSTD) return("StubWznmOpxStd");
	if (ix == STUBWZNMMDLSTD) return("StubWznmMdlStd");
	if (ix == STUBWZNMMTDSTD) return("StubWznmMtdStd");
	if (ix == STUBWZNMMCHSREF) return("StubWznmMchSref");
	if (ix == STUBWZNMMCHSTD) return("StubWznmMchStd");
	if (ix == STUBWZNMLOCSREF) return("StubWznmLocSref");
	if (ix == STUBWZNMLOCSTD) return("StubWznmLocStd");
	if (ix == STUBWZNMIEXSTD) return("StubWznmIexStd");
	if (ix == STUBWZNMJOBSTD) return("StubWznmJobStd");
	if (ix == STUBWZNMLIBSREF) return("StubWznmLibSref");
	if (ix == STUBWZNMLIBSTD) return("StubWznmLibStd");
	if (ix == STUBWZNMIELSTD) return("StubWznmIelStd");
	if (ix == STUBWZNMIMESTD) return("StubWznmImeStd");
	if (ix == STUBWZNMFILSTD) return("StubWznmFilStd");
	if (ix == STUBWZNMAPPSTD) return("StubWznmAppStd");
	if (ix == STUBWZNMBLKSTD) return("StubWznmBlkStd");
	if (ix == STUBWZNMCALSTD) return("StubWznmCalStd");
	if (ix == STUBWZNMCAPSTD) return("StubWznmCapStd");
	if (ix == STUBWZNMCPBSREF) return("StubWznmCpbSref");
	if (ix == STUBWZNMCPBSTD) return("StubWznmCpbStd");
	if (ix == STUBWZNMCTPSREF) return("StubWznmCtpSref");
	if (ix == STUBWZNMCTPSTD) return("StubWznmCtpStd");
	if (ix == STUBWZNMCARSTD) return("StubWznmCarStd");
	if (ix == STUBWZNMCHKSTD) return("StubWznmChkStd");
	if (ix == STUBWZNMCMPSTD) return("StubWznmCmpStd");
	if (ix == STUBWZNMCONSREF) return("StubWznmConSref");
	if (ix == STUBWZNMCONSTD) return("StubWznmConStd");
	if (ix == STUBWZNMFEDSREF) return("StubWznmFedSref");
	if (ix == STUBWZNMFEDSTD) return("StubWznmFedStd");
	if (ix == STUBWZNMEVTSTD) return("StubWznmEvtStd");
	if (ix == STUBWZNMDLGSTD) return("StubWznmDlgStd");

	return("");
};
