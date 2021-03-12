/**
	* \file DlgWznmVerFinmod_blks.cpp
	* job handler for job DlgWznmVerFinmod (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVerFinmod::VecVDo
 ******************************************************************************/

uint DlgWznmVerFinmod::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fnmbutrunclick") return FNMBUTRUNCLICK;
	if (s == "fnmbutstoclick") return FNMBUTSTOCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmVerFinmod::VecVDo::getSref(
			const uint ix
		) {
	if (ix == FNMBUTRUNCLICK) return("FnmButRunClick");
	if (ix == FNMBUTSTOCLICK) return("FnmButStoClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmVerFinmod::VecVSge
 ******************************************************************************/

uint DlgWznmVerFinmod::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "finmod") return FINMOD;
	if (s == "sync") return SYNC;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVerFinmod::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == FINMOD) return("finmod");
	if (ix == SYNC) return("sync");
	if (ix == DONE) return("done");

	return("");
};

void DlgWznmVerFinmod::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmVerFinmod::ContInf
 ******************************************************************************/

DlgWznmVerFinmod::ContInf::ContInf(
			const uint numFSge
			, const string& FnmTxtPrg
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->FnmTxtPrg = FnmTxtPrg;

	mask = {NUMFSGE, FNMTXTPRG};
};

void DlgWznmVerFinmod::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmVerFinmod";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["FnmTxtPrg"] = FnmTxtPrg;
};

void DlgWznmVerFinmod::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmVerFinmod";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmVerFinmod";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "FnmTxtPrg", FnmTxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerFinmod::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (FnmTxtPrg == comp->FnmTxtPrg) insert(items, FNMTXTPRG);

	return(items);
};

set<uint> DlgWznmVerFinmod::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, FNMTXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerFinmod::StatApp
 ******************************************************************************/

void DlgWznmVerFinmod::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmVerFinmod";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
};

void DlgWznmVerFinmod::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmVerFinmod";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmVerFinmod";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerFinmod::StatShr
 ******************************************************************************/

DlgWznmVerFinmod::StatShr::StatShr(
			const bool FnmButRunActive
			, const bool FnmButStoActive
			, const bool ButDneActive
		) :
			Block()
		{
	this->FnmButRunActive = FnmButRunActive;
	this->FnmButStoActive = FnmButStoActive;
	this->ButDneActive = ButDneActive;

	mask = {FNMBUTRUNACTIVE, FNMBUTSTOACTIVE, BUTDNEACTIVE};
};

void DlgWznmVerFinmod::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmVerFinmod";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["FnmButRunActive"] = FnmButRunActive;
	me["FnmButStoActive"] = FnmButStoActive;
	me["ButDneActive"] = ButDneActive;
};

void DlgWznmVerFinmod::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmVerFinmod";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmVerFinmod";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "FnmButRunActive", FnmButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "FnmButStoActive", FnmButStoActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerFinmod::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (FnmButRunActive == comp->FnmButRunActive) insert(items, FNMBUTRUNACTIVE);
	if (FnmButStoActive == comp->FnmButStoActive) insert(items, FNMBUTSTOACTIVE);
	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmVerFinmod::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {FNMBUTRUNACTIVE, FNMBUTSTOACTIVE, BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerFinmod::Tag
 ******************************************************************************/

void DlgWznmVerFinmod::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmVerFinmod";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Finalize model";
	};
	me["FnmCptPrg"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale));
	me["FnmButRun"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::RUN, ixWznmVLocale));
	me["FnmButSto"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::STOP, ixWznmVLocale));
	me["ButDne"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale));
};

void DlgWznmVerFinmod::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmVerFinmod";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmVerFinmod";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Finalize model");
		};
		writeStringAttr(wr, itemtag, "sref", "FnmCptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "FnmButRun", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::RUN, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "FnmButSto", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::STOP, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerFinmod::DpchAppDo
 ******************************************************************************/

DlgWznmVerFinmod::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERFINMODDO)
		{
	ixVDo = 0;
};

string DlgWznmVerFinmod::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerFinmod::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWznmVerFinmodDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWznmVerFinmod::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmVerFinmodDo");
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
 class DlgWznmVerFinmod::DpchEngData
 ******************************************************************************/

DlgWznmVerFinmod::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVERFINMODDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWznmVerFinmod::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerFinmod::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWznmVerFinmod::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWznmVerFinmodData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void DlgWznmVerFinmod::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmVerFinmodData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
