/**
	* \file PnlWznmNavAuxfct_blks.cpp
	* job handler for job PnlWznmNavAuxfct (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavAuxfct::VecVDo
 ******************************************************************************/

uint PnlWznmNavAuxfct::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bututlnewcrdclick") return BUTUTLNEWCRDCLICK;

	return(0);
};

string PnlWznmNavAuxfct::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUTLNEWCRDCLICK) return("ButUtlNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavAuxfct::StatApp
 ******************************************************************************/

void PnlWznmNavAuxfct::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavAuxfct";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
};

void PnlWznmNavAuxfct::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavAuxfct";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavAuxfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAuxfct::StatShr
 ******************************************************************************/

PnlWznmNavAuxfct::StatShr::StatShr(
			const bool ButUtlNewcrdAvail
		) :
			Block()
		{
	this->ButUtlNewcrdAvail = ButUtlNewcrdAvail;

	mask = {BUTUTLNEWCRDAVAIL};
};

void PnlWznmNavAuxfct::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavAuxfct";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButUtlNewcrdAvail"] = ButUtlNewcrdAvail;
};

void PnlWznmNavAuxfct::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavAuxfct";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavAuxfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButUtlNewcrdAvail", ButUtlNewcrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavAuxfct::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUtlNewcrdAvail == comp->ButUtlNewcrdAvail) insert(items, BUTUTLNEWCRDAVAIL);

	return(items);
};

set<uint> PnlWznmNavAuxfct::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUTLNEWCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAuxfct::Tag
 ******************************************************************************/

void PnlWznmNavAuxfct::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavAuxfct";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Auxiliary functionality";
		me["CptUtl"] = "utilities";
	};
};

void PnlWznmNavAuxfct::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavAuxfct";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavAuxfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Auxiliary functionality");
			writeStringAttr(wr, itemtag, "sref", "CptUtl", "utilities");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAuxfct::DpchAppDo
 ******************************************************************************/

PnlWznmNavAuxfct::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVAUXFCTDO)
		{
	ixVDo = 0;
};

string PnlWznmNavAuxfct::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAuxfct::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavAuxfctDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmNavAuxfct::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavAuxfctDo");
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
 class PnlWznmNavAuxfct::DpchEngData
 ******************************************************************************/

PnlWznmNavAuxfct::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVAUXFCTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavAuxfct::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAuxfct::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavAuxfct::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmNavAuxfctData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmNavAuxfct::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavAuxfctData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
