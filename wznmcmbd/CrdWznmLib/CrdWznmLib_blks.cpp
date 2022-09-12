/**
	* \file CrdWznmLib_blks.cpp
	* job handler for job CrdWznmLib (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmLib::VecVDo
 ******************************************************************************/

uint CrdWznmLib::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdWznmLib::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdWznmLib::VecVSge
 ******************************************************************************/

uint CrdWznmLib::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmLib::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

void CrdWznmLib::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWznmLib::ContInf
 ******************************************************************************/

CrdWznmLib::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdLib
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdLib = MtxCrdLib;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDLIB};
};

void CrdWznmLib::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmLib";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxCrdLib"] = MtxCrdLib;
};

void CrdWznmLib::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmLib";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmLib";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdLib", MtxCrdLib);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmLib::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdLib == comp->MtxCrdLib) insert(items, MTXCRDLIB);

	return(items);
};

set<uint> CrdWznmLib::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDLIB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmLib::StatApp
 ******************************************************************************/

void CrdWznmLib::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmLib";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVReqitmode"] = VecWznmVReqitmode::getSref(ixWznmVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneList"] = initdoneList;
	me["initdoneRec"] = initdoneRec;
};

void CrdWznmLib::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmLib";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmLib";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVReqitmode", VecWznmVReqitmode::getSref(ixWznmVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmLib::StatShr
 ******************************************************************************/

CrdWznmLib::StatShr::StatShr(
			const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
		) :
			Block()
		{
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;

	mask = {JREFHEADBAR, JREFLIST, JREFREC};
};

void CrdWznmLib::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmLib";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefList"] = Scr::scramble(jrefList);
	me["scrJrefRec"] = Scr::scramble(jrefRec);
};

void CrdWznmLib::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmLib";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmLib";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmLib::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);

	return(items);
};

set<uint> CrdWznmLib::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFHEADBAR, JREFLIST, JREFREC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmLib::Tag
 ******************************************************************************/

void CrdWznmLib::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmLib";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
	};
	me["MitAppAbt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...";
};

void CrdWznmLib::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmLib";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmLib";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmLib::DpchAppDo
 ******************************************************************************/

CrdWznmLib::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMLIBDO)
		{
	ixVDo = 0;
};

string CrdWznmLib::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmLib::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmLibDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWznmLib::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmLibDo");
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
 class CrdWznmLib::DpchEngData
 ******************************************************************************/

CrdWznmLib::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMLIBDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWznmLib::DpchEngData::getSrefsMask() {
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

void CrdWznmLib::DpchEngData::merge(
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

void CrdWznmLib::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmLibData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void CrdWznmLib::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmLibData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
