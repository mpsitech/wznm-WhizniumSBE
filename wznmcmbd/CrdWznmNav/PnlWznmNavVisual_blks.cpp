/**
	* \file PnlWznmNavVisual_blks.cpp
	* job handler for job PnlWznmNavVisual (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavVisual::VecVDo
 ******************************************************************************/

uint PnlWznmNavVisual::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butvisviewclick") return BUTVISVIEWCLICK;
	if (s == "butvisnewcrdclick") return BUTVISNEWCRDCLICK;
	if (s == "butshtviewclick") return BUTSHTVIEWCLICK;
	if (s == "butshtnewcrdclick") return BUTSHTNEWCRDCLICK;
	if (s == "butboxviewclick") return BUTBOXVIEWCLICK;
	if (s == "butboxnewcrdclick") return BUTBOXNEWCRDCLICK;

	return(0);
};

string PnlWznmNavVisual::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVISVIEWCLICK) return("ButVisViewClick");
	if (ix == BUTVISNEWCRDCLICK) return("ButVisNewcrdClick");
	if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");
	if (ix == BUTSHTNEWCRDCLICK) return("ButShtNewcrdClick");
	if (ix == BUTBOXVIEWCLICK) return("ButBoxViewClick");
	if (ix == BUTBOXNEWCRDCLICK) return("ButBoxNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavVisual::ContIac
 ******************************************************************************/

PnlWznmNavVisual::ContIac::ContIac(
			const uint numFLstVis
			, const uint numFLstSht
			, const uint numFLstBox
		) :
			Block()
			, numFLstVis(numFLstVis)
			, numFLstSht(numFLstSht)
			, numFLstBox(numFLstBox)
		{
	mask = {NUMFLSTVIS, NUMFLSTSHT, NUMFLSTBOX};
};

bool PnlWznmNavVisual::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmNavVisual"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstVis")) {numFLstVis = me["numFLstVis"].asUInt(); add(NUMFLSTVIS);};
		if (me.isMember("numFLstSht")) {numFLstSht = me["numFLstSht"].asUInt(); add(NUMFLSTSHT);};
		if (me.isMember("numFLstBox")) {numFLstBox = me["numFLstBox"].asUInt(); add(NUMFLSTBOX);};
	};

	return basefound;
};

bool PnlWznmNavVisual::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavVisual");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavVisual";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVis", numFLstVis)) add(NUMFLSTVIS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSht", numFLstSht)) add(NUMFLSTSHT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstBox", numFLstBox)) add(NUMFLSTBOX);
	};

	return basefound;
};

void PnlWznmNavVisual::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavVisual";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstVis"] = (Json::Value::UInt) numFLstVis;
	me["numFLstSht"] = (Json::Value::UInt) numFLstSht;
	me["numFLstBox"] = (Json::Value::UInt) numFLstBox;
};

void PnlWznmNavVisual::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavVisual";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavVisual";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstVis", numFLstVis);
		writeUintAttr(wr, itemtag, "sref", "numFLstSht", numFLstSht);
		writeUintAttr(wr, itemtag, "sref", "numFLstBox", numFLstBox);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavVisual::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstVis == comp->numFLstVis) insert(items, NUMFLSTVIS);
	if (numFLstSht == comp->numFLstSht) insert(items, NUMFLSTSHT);
	if (numFLstBox == comp->numFLstBox) insert(items, NUMFLSTBOX);

	return(items);
};

set<uint> PnlWznmNavVisual::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTVIS, NUMFLSTSHT, NUMFLSTBOX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavVisual::StatApp
 ******************************************************************************/

void PnlWznmNavVisual::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool LstVisAlt
			, const bool LstShtAlt
			, const bool LstBoxAlt
			, const uint LstVisNumFirstdisp
			, const uint LstShtNumFirstdisp
			, const uint LstBoxNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavVisual";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstVisAlt"] = LstVisAlt;
	me["LstShtAlt"] = LstShtAlt;
	me["LstBoxAlt"] = LstBoxAlt;
	me["LstVisNumFirstdisp"] = (Json::Value::UInt) LstVisNumFirstdisp;
	me["LstShtNumFirstdisp"] = (Json::Value::UInt) LstShtNumFirstdisp;
	me["LstBoxNumFirstdisp"] = (Json::Value::UInt) LstBoxNumFirstdisp;
};

void PnlWznmNavVisual::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstVisAlt
			, const bool LstShtAlt
			, const bool LstBoxAlt
			, const uint LstVisNumFirstdisp
			, const uint LstShtNumFirstdisp
			, const uint LstBoxNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavVisual";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavVisual";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstVisAlt", LstVisAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstShtAlt", LstShtAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstBoxAlt", LstBoxAlt);
		writeUintAttr(wr, itemtag, "sref", "LstVisNumFirstdisp", LstVisNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstShtNumFirstdisp", LstShtNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstBoxNumFirstdisp", LstBoxNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavVisual::StatShr
 ******************************************************************************/

PnlWznmNavVisual::StatShr::StatShr(
			const bool LstVisAvail
			, const bool ButVisViewActive
			, const bool LstShtAvail
			, const bool ButShtViewActive
			, const bool ButShtNewcrdActive
			, const bool LstBoxAvail
			, const bool ButBoxViewActive
			, const bool ButBoxNewcrdActive
		) :
			Block()
			, LstVisAvail(LstVisAvail)
			, ButVisViewActive(ButVisViewActive)
			, LstShtAvail(LstShtAvail)
			, ButShtViewActive(ButShtViewActive)
			, ButShtNewcrdActive(ButShtNewcrdActive)
			, LstBoxAvail(LstBoxAvail)
			, ButBoxViewActive(ButBoxViewActive)
			, ButBoxNewcrdActive(ButBoxNewcrdActive)
		{
	mask = {LSTVISAVAIL, BUTVISVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, BUTSHTNEWCRDACTIVE, LSTBOXAVAIL, BUTBOXVIEWACTIVE, BUTBOXNEWCRDACTIVE};
};

void PnlWznmNavVisual::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavVisual";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstVisAvail"] = LstVisAvail;
	me["ButVisViewActive"] = ButVisViewActive;
	me["LstShtAvail"] = LstShtAvail;
	me["ButShtViewActive"] = ButShtViewActive;
	me["ButShtNewcrdActive"] = ButShtNewcrdActive;
	me["LstBoxAvail"] = LstBoxAvail;
	me["ButBoxViewActive"] = ButBoxViewActive;
	me["ButBoxNewcrdActive"] = ButBoxNewcrdActive;
};

void PnlWznmNavVisual::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavVisual";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavVisual";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstVisAvail", LstVisAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVisViewActive", ButVisViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstShtAvail", LstShtAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButShtViewActive", ButShtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButShtNewcrdActive", ButShtNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstBoxAvail", LstBoxAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBoxViewActive", ButBoxViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBoxNewcrdActive", ButBoxNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavVisual::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstVisAvail == comp->LstVisAvail) insert(items, LSTVISAVAIL);
	if (ButVisViewActive == comp->ButVisViewActive) insert(items, BUTVISVIEWACTIVE);
	if (LstShtAvail == comp->LstShtAvail) insert(items, LSTSHTAVAIL);
	if (ButShtViewActive == comp->ButShtViewActive) insert(items, BUTSHTVIEWACTIVE);
	if (ButShtNewcrdActive == comp->ButShtNewcrdActive) insert(items, BUTSHTNEWCRDACTIVE);
	if (LstBoxAvail == comp->LstBoxAvail) insert(items, LSTBOXAVAIL);
	if (ButBoxViewActive == comp->ButBoxViewActive) insert(items, BUTBOXVIEWACTIVE);
	if (ButBoxNewcrdActive == comp->ButBoxNewcrdActive) insert(items, BUTBOXNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavVisual::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTVISAVAIL, BUTVISVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, BUTSHTNEWCRDACTIVE, LSTBOXAVAIL, BUTBOXVIEWACTIVE, BUTBOXNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavVisual::Tag
 ******************************************************************************/

void PnlWznmNavVisual::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavVisual";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Visualization module";
		me["CptVis"] = "visualizations";
		me["CptSht"] = "sheets";
		me["CptBox"] = "boxes";
	};
};

void PnlWznmNavVisual::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavVisual";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavVisual";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Visualization module");
			writeStringAttr(wr, itemtag, "sref", "CptVis", "visualizations");
			writeStringAttr(wr, itemtag, "sref", "CptSht", "sheets");
			writeStringAttr(wr, itemtag, "sref", "CptBox", "boxes");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavVisual::DpchAppData
 ******************************************************************************/

PnlWznmNavVisual::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVVISUALDATA)
		{
};

string PnlWznmNavVisual::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavVisual::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavVisualData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmNavVisual::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavVisualData");
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
 class PnlWznmNavVisual::DpchAppDo
 ******************************************************************************/

PnlWznmNavVisual::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVVISUALDO)
		{
	ixVDo = 0;
};

string PnlWznmNavVisual::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavVisual::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavVisualDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmNavVisual::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavVisualDo");
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
 class PnlWznmNavVisual::DpchEngData
 ******************************************************************************/

PnlWznmNavVisual::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstBox
			, Feed* feedFLstSht
			, Feed* feedFLstVis
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVVISUALDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTBOX, FEEDFLSTSHT, FEEDFLSTVIS, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTBOX) && feedFLstBox) this->feedFLstBox = *feedFLstBox;
	if (find(this->mask, FEEDFLSTSHT) && feedFLstSht) this->feedFLstSht = *feedFLstSht;
	if (find(this->mask, FEEDFLSTVIS) && feedFLstVis) this->feedFLstVis = *feedFLstVis;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavVisual::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBOX)) ss.push_back("feedFLstBox");
	if (has(FEEDFLSTSHT)) ss.push_back("feedFLstSht");
	if (has(FEEDFLSTVIS)) ss.push_back("feedFLstVis");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavVisual::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTBOX)) {feedFLstBox = src->feedFLstBox; add(FEEDFLSTBOX);};
	if (src->has(FEEDFLSTSHT)) {feedFLstSht = src->feedFLstSht; add(FEEDFLSTSHT);};
	if (src->has(FEEDFLSTVIS)) {feedFLstVis = src->feedFLstVis; add(FEEDFLSTVIS);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavVisual::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmNavVisualData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTBOX)) feedFLstBox.writeJSON(me);
	if (has(FEEDFLSTSHT)) feedFLstSht.writeJSON(me);
	if (has(FEEDFLSTVIS)) feedFLstVis.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmNavVisual::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavVisualData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTBOX)) feedFLstBox.writeXML(wr);
		if (has(FEEDFLSTSHT)) feedFLstSht.writeXML(wr);
		if (has(FEEDFLSTVIS)) feedFLstVis.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
