/**
	* \file PnlWznmImeDetail_blks.cpp
	* job handler for job PnlWznmImeDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmImeDetail::VecVDo
 ******************************************************************************/

uint PnlWznmImeDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butiexviewclick") return BUTIEXVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butrtrviewclick") return BUTRTRVIEWCLICK;

	return(0);
};

string PnlWznmImeDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTIEXVIEWCLICK) return("ButIexViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTRTRVIEWCLICK) return("ButRtrViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmImeDetail::ContIac
 ******************************************************************************/

PnlWznmImeDetail::ContIac::ContIac(
			const vector<uint>& numsFLstIop
			, const uint numFLstRtr
			, const string& TxfRtr
			, const string& TxfCmt
		) :
			Block()
			, numsFLstIop(numsFLstIop)
			, numFLstRtr(numFLstRtr)
			, TxfRtr(TxfRtr)
			, TxfCmt(TxfCmt)
		{
	mask = {NUMSFLSTIOP, NUMFLSTRTR, TXFRTR, TXFCMT};
};

bool PnlWznmImeDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmImeDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (Jsonio::extractUintvec(me, "numsFLstIop", numsFLstIop)) add(NUMSFLSTIOP);
		if (me.isMember("numFLstRtr")) {numFLstRtr = me["numFLstRtr"].asUInt(); add(NUMFLSTRTR);};
		if (me.isMember("TxfRtr")) {TxfRtr = me["TxfRtr"].asString(); add(TXFRTR);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWznmImeDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmImeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmImeDetail";

	if (basefound) {
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstIop", numsFLstIop)) add(NUMSFLSTIOP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRtr", numFLstRtr)) add(NUMFLSTRTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfRtr", TxfRtr)) add(TXFRTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmImeDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmImeDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	Jsonio::writeUintvec(me, "numsFLstIop", numsFLstIop);
	me["numFLstRtr"] = (Json::Value::UInt) numFLstRtr;
	me["TxfRtr"] = TxfRtr;
	me["TxfCmt"] = TxfCmt;
};

void PnlWznmImeDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmImeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmImeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstIop", numsFLstIop);
		writeUintAttr(wr, itemtag, "sref", "numFLstRtr", numFLstRtr);
		writeStringAttr(wr, itemtag, "sref", "TxfRtr", TxfRtr);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmImeDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareUintvec(numsFLstIop, comp->numsFLstIop)) insert(items, NUMSFLSTIOP);
	if (numFLstRtr == comp->numFLstRtr) insert(items, NUMFLSTRTR);
	if (TxfRtr == comp->TxfRtr) insert(items, TXFRTR);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmImeDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMSFLSTIOP, NUMFLSTRTR, TXFRTR, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmImeDetail::ContInf
 ******************************************************************************/

PnlWznmImeDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtIex
			, const string& TxtSup
			, const string& TxtTbl
			, const string& TxtIop
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtIex(TxtIex)
			, TxtSup(TxtSup)
			, TxtTbl(TxtTbl)
			, TxtIop(TxtIop)
		{
	mask = {TXTSRF, TXTIEX, TXTSUP, TXTTBL, TXTIOP};
};

void PnlWznmImeDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmImeDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtIex"] = TxtIex;
	me["TxtSup"] = TxtSup;
	me["TxtTbl"] = TxtTbl;
	me["TxtIop"] = TxtIop;
};

void PnlWznmImeDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmImeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmImeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtIex", TxtIex);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtTbl", TxtTbl);
		writeStringAttr(wr, itemtag, "sref", "TxtIop", TxtIop);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmImeDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtIex == comp->TxtIex) insert(items, TXTIEX);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtIop == comp->TxtIop) insert(items, TXTIOP);

	return(items);
};

set<uint> PnlWznmImeDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTIEX, TXTSUP, TXTTBL, TXTIOP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmImeDetail::StatApp
 ******************************************************************************/

void PnlWznmImeDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool LstIopAlt
			, const bool LstRtrAlt
			, const uint LstIopNumFirstdisp
			, const uint LstRtrNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmImeDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstIopAlt"] = LstIopAlt;
	me["LstRtrAlt"] = LstRtrAlt;
	me["LstIopNumFirstdisp"] = (Json::Value::UInt) LstIopNumFirstdisp;
	me["LstRtrNumFirstdisp"] = (Json::Value::UInt) LstRtrNumFirstdisp;
};

void PnlWznmImeDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstIopAlt
			, const bool LstRtrAlt
			, const uint LstIopNumFirstdisp
			, const uint LstRtrNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmImeDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmImeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstIopAlt", LstIopAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRtrAlt", LstRtrAlt);
		writeUintAttr(wr, itemtag, "sref", "LstIopNumFirstdisp", LstIopNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRtrNumFirstdisp", LstRtrNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmImeDetail::StatShr
 ******************************************************************************/

PnlWznmImeDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtIexActive
			, const bool ButIexViewAvail
			, const bool ButIexViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtTblActive
			, const bool LstIopActive
			, const bool LstRtrActive
			, const bool TxfRtrValid
			, const bool ButRtrViewAvail
			, const bool ButRtrViewActive
			, const bool TxfCmtActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, TxtIexActive(TxtIexActive)
			, ButIexViewAvail(ButIexViewAvail)
			, ButIexViewActive(ButIexViewActive)
			, TxtSupActive(TxtSupActive)
			, ButSupViewAvail(ButSupViewAvail)
			, ButSupViewActive(ButSupViewActive)
			, TxtTblActive(TxtTblActive)
			, LstIopActive(LstIopActive)
			, LstRtrActive(LstRtrActive)
			, TxfRtrValid(TxfRtrValid)
			, ButRtrViewAvail(ButRtrViewAvail)
			, ButRtrViewActive(ButRtrViewActive)
			, TxfCmtActive(TxfCmtActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTIEXACTIVE, BUTIEXVIEWAVAIL, BUTIEXVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, LSTIOPACTIVE, LSTRTRACTIVE, TXFRTRVALID, BUTRTRVIEWAVAIL, BUTRTRVIEWACTIVE, TXFCMTACTIVE};
};

void PnlWznmImeDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmImeDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxtIexActive"] = TxtIexActive;
	me["ButIexViewAvail"] = ButIexViewAvail;
	me["ButIexViewActive"] = ButIexViewActive;
	me["TxtSupActive"] = TxtSupActive;
	me["ButSupViewAvail"] = ButSupViewAvail;
	me["ButSupViewActive"] = ButSupViewActive;
	me["TxtTblActive"] = TxtTblActive;
	me["LstIopActive"] = LstIopActive;
	me["LstRtrActive"] = LstRtrActive;
	me["TxfRtrValid"] = TxfRtrValid;
	me["ButRtrViewAvail"] = ButRtrViewAvail;
	me["ButRtrViewActive"] = ButRtrViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWznmImeDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmImeDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmImeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtIexActive", TxtIexActive);
		writeBoolAttr(wr, itemtag, "sref", "ButIexViewAvail", ButIexViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButIexViewActive", ButIexViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTblActive", TxtTblActive);
		writeBoolAttr(wr, itemtag, "sref", "LstIopActive", LstIopActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRtrActive", LstRtrActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfRtrValid", TxfRtrValid);
		writeBoolAttr(wr, itemtag, "sref", "ButRtrViewAvail", ButRtrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRtrViewActive", ButRtrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmImeDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtIexActive == comp->TxtIexActive) insert(items, TXTIEXACTIVE);
	if (ButIexViewAvail == comp->ButIexViewAvail) insert(items, BUTIEXVIEWAVAIL);
	if (ButIexViewActive == comp->ButIexViewActive) insert(items, BUTIEXVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (LstIopActive == comp->LstIopActive) insert(items, LSTIOPACTIVE);
	if (LstRtrActive == comp->LstRtrActive) insert(items, LSTRTRACTIVE);
	if (TxfRtrValid == comp->TxfRtrValid) insert(items, TXFRTRVALID);
	if (ButRtrViewAvail == comp->ButRtrViewAvail) insert(items, BUTRTRVIEWAVAIL);
	if (ButRtrViewActive == comp->ButRtrViewActive) insert(items, BUTRTRVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmImeDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTIEXACTIVE, BUTIEXVIEWAVAIL, BUTIEXVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, LSTIOPACTIVE, LSTRTRACTIVE, TXFRTRVALID, BUTRTRVIEWAVAIL, BUTRTRVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmImeDetail::Tag
 ******************************************************************************/

void PnlWznmImeDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmImeDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptIex"] = "import/export complex";
		me["CptSup"] = "super import/export";
		me["CptTbl"] = "table";
		me["CptIop"] = "import operations";
		me["CptRtr"] = "record retrieval import/export columns";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmImeDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmImeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmImeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptIex", "import/export complex");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super import/export");
			writeStringAttr(wr, itemtag, "sref", "CptTbl", "table");
			writeStringAttr(wr, itemtag, "sref", "CptIop", "import operations");
			writeStringAttr(wr, itemtag, "sref", "CptRtr", "record retrieval import/export columns");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmImeDetail::DpchAppData
 ******************************************************************************/

PnlWznmImeDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIMEDETAILDATA)
		{
};

string PnlWznmImeDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmImeDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmImeDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmImeDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmImeDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWznmImeDetail::DpchAppDo
 ******************************************************************************/

PnlWznmImeDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIMEDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmImeDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmImeDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmImeDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmImeDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmImeDetailDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlWznmImeDetail::DpchEngData
 ******************************************************************************/

PnlWznmImeDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstIop
			, Feed* feedFLstRtr
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMIMEDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTIOP, FEEDFLSTRTR, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTIOP) && feedFLstIop) this->feedFLstIop = *feedFLstIop;
	if (find(this->mask, FEEDFLSTRTR) && feedFLstRtr) this->feedFLstRtr = *feedFLstRtr;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmImeDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTIOP)) ss.push_back("feedFLstIop");
	if (has(FEEDFLSTRTR)) ss.push_back("feedFLstRtr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmImeDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTIOP)) {feedFLstIop = src->feedFLstIop; add(FEEDFLSTIOP);};
	if (src->has(FEEDFLSTRTR)) {feedFLstRtr = src->feedFLstRtr; add(FEEDFLSTRTR);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmImeDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmImeDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTIOP)) feedFLstIop.writeJSON(me);
	if (has(FEEDFLSTRTR)) feedFLstRtr.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmImeDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmImeDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTIOP)) feedFLstIop.writeXML(wr);
		if (has(FEEDFLSTRTR)) feedFLstRtr.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
