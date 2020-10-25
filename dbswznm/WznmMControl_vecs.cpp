/**
	* \file WznmMControl_vecs.cpp
	* database access for table TblWznmMControl (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmMControl::VecVBasetype
 ******************************************************************************/

uint TblWznmMControl::VecVBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "alr") return ALR;
	if (s == "but") return BUT;
	if (s == "chk") return CHK;
	if (s == "cpt") return CPT;
	if (s == "csi") return CSI;
	if (s == "cus") return CUS;
	if (s == "dit") return DIT;
	if (s == "dld") return DLD;
	if (s == "dse") return DSE;
	if (s == "hdg") return HDG;
	if (s == "hsb") return HSB;
	if (s == "lsb") return LSB;
	if (s == "lst") return LST;
	if (s == "mcb") return MCB;
	if (s == "men") return MEN;
	if (s == "mit") return MIT;
	if (s == "msp") return MSP;
	if (s == "mrl") return MRL;
	if (s == "mtx") return MTX;
	if (s == "pup") return PUP;
	if (s == "rbu") return RBU;
	if (s == "sep") return SEP;
	if (s == "sge") return SGE;
	if (s == "sld") return SLD;
	if (s == "spc") return SPC;
	if (s == "tbl") return TBL;
	if (s == "tco") return TCO;
	if (s == "tos") return TOS;
	if (s == "trs") return TRS;
	if (s == "tsb") return TSB;
	if (s == "txf") return TXF;
	if (s == "txt") return TXT;
	if (s == "upd") return UPD;
	if (s == "uld") return ULD;
	if (s == "vsb") return VSB;

	return(0);
};

string TblWznmMControl::VecVBasetype::getSref(
			const uint ix
		) {
	if (ix == ALR) return("alr");
	if (ix == BUT) return("but");
	if (ix == CHK) return("chk");
	if (ix == CPT) return("cpt");
	if (ix == CSI) return("csi");
	if (ix == CUS) return("cus");
	if (ix == DIT) return("dit");
	if (ix == DLD) return("dld");
	if (ix == DSE) return("dse");
	if (ix == HDG) return("hdg");
	if (ix == HSB) return("hsb");
	if (ix == LSB) return("lsb");
	if (ix == LST) return("lst");
	if (ix == MCB) return("mcb");
	if (ix == MEN) return("men");
	if (ix == MIT) return("mit");
	if (ix == MSP) return("msp");
	if (ix == MRL) return("mrl");
	if (ix == MTX) return("mtx");
	if (ix == PUP) return("pup");
	if (ix == RBU) return("rbu");
	if (ix == SEP) return("sep");
	if (ix == SGE) return("sge");
	if (ix == SLD) return("sld");
	if (ix == SPC) return("spc");
	if (ix == TBL) return("tbl");
	if (ix == TCO) return("tco");
	if (ix == TOS) return("tos");
	if (ix == TRS) return("trs");
	if (ix == TSB) return("tsb");
	if (ix == TXF) return("txf");
	if (ix == TXT) return("txt");
	if (ix == UPD) return("upd");
	if (ix == ULD) return("uld");
	if (ix == VSB) return("vsb");

	return("");
};

string TblWznmMControl::VecVBasetype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == ALR) return("alert");
		if (ix == BUT) return("button");
		if (ix == CHK) return("checkbox");
		if (ix == CPT) return("caption");
		if (ix == CSI) return("color signal");
		if (ix == CUS) return("custom");
		if (ix == DIT) return("dialog item");
		if (ix == DLD) return("file download link");
		if (ix == DSE) return("dialog item selector");
		if (ix == HDG) return("heading");
		if (ix == HSB) return("horizontal scroll bar");
		if (ix == LSB) return("list scroll bar");
		if (ix == LST) return("list");
		if (ix == MCB) return("multiple-choice button");
		if (ix == MEN) return("menu");
		if (ix == MIT) return("menu item");
		if (ix == MSP) return("menu separator");
		if (ix == MRL) return("URL menu item");
		if (ix == MTX) return("menu item text display");
		if (ix == PUP) return("pop-up menu");
		if (ix == RBU) return("radio button");
		if (ix == SEP) return("separator");
		if (ix == SGE) return("stage information");
		if (ix == SLD) return("slider");
		if (ix == SPC) return("spacer");
		if (ix == TBL) return("table");
		if (ix == TCO) return("table column");
		if (ix == TOS) return("table order selector");
		if (ix == TRS) return("table row selector");
		if (ix == TSB) return("table scroll bar");
		if (ix == TXF) return("text field");
		if (ix == TXT) return("text display");
		if (ix == UPD) return("up/down");
		if (ix == ULD) return("file upload field");
		if (ix == VSB) return("vertical scroll bar");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMControl::VecVBasetype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 35; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMControl::VecVHkSection
 ******************************************************************************/

uint TblWznmMControl::VecVHkSection::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "mbar") return MBAR;
	if (s == "side") return SIDE;
	if (s == "hdr") return HDR;
	if (s == "hdrdetd") return HDRDETD;
	if (s == "hdrregd") return HDRREGD;
	if (s == "cont") return CONT;
	if (s == "contdetd") return CONTDETD;
	if (s == "contregd") return CONTREGD;
	if (s == "tbl") return TBL;
	if (s == "ftr") return FTR;

	return(0);
};

string TblWznmMControl::VecVHkSection::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == MBAR) return("mbar");
	if (ix == SIDE) return("side");
	if (ix == HDR) return("hdr");
	if (ix == HDRDETD) return("hdrdetd");
	if (ix == HDRREGD) return("hdrregd");
	if (ix == CONT) return("cont");
	if (ix == CONTDETD) return("contdetd");
	if (ix == CONTREGD) return("contregd");
	if (ix == TBL) return("tbl");
	if (ix == FTR) return("ftr");

	return("");
};

string TblWznmMControl::VecVHkSection::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == MBAR) return("menu bar");
		if (ix == SIDE) return("side");
		if (ix == HDR) return("header");
		if (ix == HDRDETD) return("header when detached");
		if (ix == HDRREGD) return("header when regularized");
		if (ix == CONT) return("content");
		if (ix == CONTDETD) return("content when detached");
		if (ix == CONTREGD) return("content when regularized");
		if (ix == TBL) return("table");
		if (ix == FTR) return("footer");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMControl::VecVHkSection::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 11; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMControl::VecVHkTbl
 ******************************************************************************/

uint TblWznmMControl::VecVHkTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "car") return CAR;
	if (s == "dlg") return DLG;
	if (s == "pnl") return PNL;
	if (s == "ver") return VER;

	return(0);
};

string TblWznmMControl::VecVHkTbl::getSref(
			const uint ix
		) {
	if (ix == CAR) return("car");
	if (ix == DLG) return("dlg");
	if (ix == PNL) return("pnl");
	if (ix == VER) return("ver");

	return("");
};

string TblWznmMControl::VecVHkTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == CAR) return("card");
		if (ix == DLG) return("dialog");
		if (ix == PNL) return("panel");
		if (ix == VER) return("version");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMControl::VecVHkTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMControl::VecVRefTbl
 ******************************************************************************/

uint TblWznmMControl::VecVRefTbl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "dlg") return DLG;
	if (s == "qco") return QCO;
	if (s == "rel") return REL;
	if (s == "tbl") return TBL;
	if (s == "tco") return TCO;

	return(0);
};

string TblWznmMControl::VecVRefTbl::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == DLG) return("dlg");
	if (ix == QCO) return("qco");
	if (ix == REL) return("rel");
	if (ix == TBL) return("tbl");
	if (ix == TCO) return("tco");

	return("");
};

string TblWznmMControl::VecVRefTbl::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == DLG) return("dialog");
		if (ix == QCO) return("query column");
		if (ix == REL) return("relation");
		if (ix == TBL) return("table");
		if (ix == TCO) return("table column");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMControl::VecVRefTbl::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMControl::VecVScope
 ******************************************************************************/

uint TblWznmMControl::VecVScope::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "app") return APP;
	if (s == "shr") return SHR;

	return(0);
};

string TblWznmMControl::VecVScope::getSref(
			const uint ix
		) {
	if (ix == APP) return("app");
	if (ix == SHR) return("shr");

	return("");
};

string TblWznmMControl::VecVScope::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == APP) return("app only");
		if (ix == SHR) return("shared app/engine");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMControl::VecVScope::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMControl::VecVSubtype
 ******************************************************************************/

uint TblWznmMControl::VecVSubtype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "ditstd") return DITSTD;
	if (s == "ditarr") return DITARR;
	if (s == "ditdld") return DITDLD;
	if (s == "dituld") return DITULD;
	if (s == "ditprg") return DITPRG;

	return(0);
};

string TblWznmMControl::VecVSubtype::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == DITSTD) return("ditstd");
	if (ix == DITARR) return("ditarr");
	if (ix == DITDLD) return("ditdld");
	if (ix == DITULD) return("dituld");
	if (ix == DITPRG) return("ditprg");

	return("");
};

string TblWznmMControl::VecVSubtype::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == DITSTD) return("custom single");
		if (ix == DITARR) return("custom arrayed");
		if (ix == DITDLD) return("download");
		if (ix == DITULD) return("upload");
		if (ix == DITPRG) return("progress");
		return(getSref(ix));
	};

	return("");
};

void TblWznmMControl::VecVSubtype::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class TblWznmMControl::VecWSubset
 ******************************************************************************/

uint TblWznmMControl::VecWSubset::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sbswznmbmcontrolcai") ix |= SBSWZNMBMCONTROLCAI;
		else if (ss[i] == "sbswznmbmcontrolcfb") ix |= SBSWZNMBMCONTROLCFB;
	};

	return(ix);
};

void TblWznmMControl::VecWSubset::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SBSWZNMBMCONTROLCFB); i *= 2) if (ix & i) ics.insert(i);
};

string TblWznmMControl::VecWSubset::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SBSWZNMBMCONTROLCAI) ss.push_back("SbsWznmBMControlCai");
	if (ix & SBSWZNMBMCONTROLCFB) ss.push_back("SbsWznmBMControlCfb");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWznmMControl::VecWSubset::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SBSWZNMBMCONTROLCAI) return("action-invoking control");
		if (ix == SBSWZNMBMCONTROLCFB) return("feed-backed control");
		return(getSrefs(ix));
	};

	return("");
};

