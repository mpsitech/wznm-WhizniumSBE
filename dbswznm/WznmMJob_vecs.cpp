/**
	* \file WznmMJob_vecs.cpp
	* database access for table TblWznmMJob (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMJob::VecVBasetype
 ******************************************************************************/

uint TblWznmMJob::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "root") return ROOT;
	if (s == "crd") return CRD;
	if (s == "dlg") return DLG;
	if (s == "pnl") return PNL;
	if (s == "qry") return QRY;
	if (s == "sess") return SESS;
	if (s == "iex") return IEX;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmMJob::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == ROOT) return("root");
	if (ix == CRD) return("crd");
	if (ix == DLG) return("dlg");
	if (ix == PNL) return("pnl");
	if (ix == QRY) return("qry");
	if (ix == SESS) return("sess");
	if (ix == IEX) return("iex");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmMJob::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ROOT) return("engine root");
		if (ix == CRD) return("card processor");
		if (ix == DLG) return("dialog processor");
		if (ix == PNL) return("panel processor");
		if (ix == QRY) return("query processor");
		if (ix == SESS) return("session processor");
		if (ix == IEX) return("import/export processor");
		if (ix == CUST) return("custom processor");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMJob::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 8; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMJob::VecVRefTbl
 ******************************************************************************/

uint TblWznmMJob::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "car") return CAR;
	if (s == "dlg") return DLG;
	if (s == "pnl") return PNL;
	if (s == "qry") return QRY;
	if (s == "iex") return IEX;

	return(0);
};

string TblWznmMJob::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == CAR) return("car");
	if (ix == DLG) return("dlg");
	if (ix == PNL) return("pnl");
	if (ix == QRY) return("qry");
	if (ix == IEX) return("iex");

	return("");
};

string TblWznmMJob::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == CAR) return("card");
		if (ix == DLG) return("dialog");
		if (ix == PNL) return("panel");
		if (ix == QRY) return("query");
		if (ix == IEX) return("import/export complex");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMJob::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

