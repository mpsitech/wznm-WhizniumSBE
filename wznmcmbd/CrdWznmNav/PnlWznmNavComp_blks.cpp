/**
	* \file PnlWznmNavComp_blks.cpp
	* job handler for job PnlWznmNavComp (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavComp::VecVDo
 ******************************************************************************/

uint PnlWznmNavComp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butopkviewclick") return BUTOPKVIEWCLICK;
	if (s == "butopknewcrdclick") return BUTOPKNEWCRDCLICK;
	if (s == "butopxviewclick") return BUTOPXVIEWCLICK;
	if (s == "butopxnewcrdclick") return BUTOPXNEWCRDCLICK;

	return(0);
};

string PnlWznmNavComp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTOPKVIEWCLICK) return("ButOpkViewClick");
	if (ix == BUTOPKNEWCRDCLICK) return("ButOpkNewcrdClick");
	if (ix == BUTOPXVIEWCLICK) return("ButOpxViewClick");
	if (ix == BUTOPXNEWCRDCLICK) return("ButOpxNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavComp::ContIac
 ******************************************************************************/

PnlWznmNavComp::ContIac::ContIac(
			const uint numFLstOpk
			, const uint numFLstOpx
		) :
			Block()
		{
	this->numFLstOpk = numFLstOpk;
	this->numFLstOpx = numFLstOpx;

	mask = {NUMFLSTOPK, NUMFLSTOPX};
};

bool PnlWznmNavComp::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmNavComp"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstOpk")) {numFLstOpk = me["numFLstOpk"].asUInt(); add(NUMFLSTOPK);};
		if (me.isMember("numFLstOpx")) {numFLstOpx = me["numFLstOpx"].asUInt(); add(NUMFLSTOPX);};
	};

	return basefound;
};

bool PnlWznmNavComp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavComp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavComp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOpk", numFLstOpk)) add(NUMFLSTOPK);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOpx", numFLstOpx)) add(NUMFLSTOPX);
	};

	return basefound;
};

void PnlWznmNavComp::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavComp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstOpk"] = numFLstOpk;
	me["numFLstOpx"] = numFLstOpx;
};

void PnlWznmNavComp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavComp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavComp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstOpk", numFLstOpk);
		writeUintAttr(wr, itemtag, "sref", "numFLstOpx", numFLstOpx);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavComp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstOpk == comp->numFLstOpk) insert(items, NUMFLSTOPK);
	if (numFLstOpx == comp->numFLstOpx) insert(items, NUMFLSTOPX);

	return(items);
};

set<uint> PnlWznmNavComp::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTOPK, NUMFLSTOPX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavComp::StatApp
 ******************************************************************************/

void PnlWznmNavComp::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool LstOpkAlt
			, const bool LstOpxAlt
			, const uint LstOpkNumFirstdisp
			, const uint LstOpxNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavComp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstOpkAlt"] = LstOpkAlt;
	me["LstOpxAlt"] = LstOpxAlt;
	me["LstOpkNumFirstdisp"] = LstOpkNumFirstdisp;
	me["LstOpxNumFirstdisp"] = LstOpxNumFirstdisp;
};

void PnlWznmNavComp::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstOpkAlt
			, const bool LstOpxAlt
			, const uint LstOpkNumFirstdisp
			, const uint LstOpxNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavComp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavComp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstOpkAlt", LstOpkAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstOpxAlt", LstOpxAlt);
		writeUintAttr(wr, itemtag, "sref", "LstOpkNumFirstdisp", LstOpkNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstOpxNumFirstdisp", LstOpxNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavComp::StatShr
 ******************************************************************************/

PnlWznmNavComp::StatShr::StatShr(
			const bool LstOpkAvail
			, const bool ButOpkViewActive
			, const bool ButOpkNewcrdActive
			, const bool LstOpxAvail
			, const bool ButOpxViewActive
			, const bool ButOpxNewcrdActive
		) :
			Block()
		{
	this->LstOpkAvail = LstOpkAvail;
	this->ButOpkViewActive = ButOpkViewActive;
	this->ButOpkNewcrdActive = ButOpkNewcrdActive;
	this->LstOpxAvail = LstOpxAvail;
	this->ButOpxViewActive = ButOpxViewActive;
	this->ButOpxNewcrdActive = ButOpxNewcrdActive;

	mask = {LSTOPKAVAIL, BUTOPKVIEWACTIVE, BUTOPKNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE};
};

void PnlWznmNavComp::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavComp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstOpkAvail"] = LstOpkAvail;
	me["ButOpkViewActive"] = ButOpkViewActive;
	me["ButOpkNewcrdActive"] = ButOpkNewcrdActive;
	me["LstOpxAvail"] = LstOpxAvail;
	me["ButOpxViewActive"] = ButOpxViewActive;
	me["ButOpxNewcrdActive"] = ButOpxNewcrdActive;
};

void PnlWznmNavComp::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavComp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavComp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstOpkAvail", LstOpkAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOpkViewActive", ButOpkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOpkNewcrdActive", ButOpkNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOpxAvail", LstOpxAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOpxViewActive", ButOpxViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOpxNewcrdActive", ButOpxNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavComp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstOpkAvail == comp->LstOpkAvail) insert(items, LSTOPKAVAIL);
	if (ButOpkViewActive == comp->ButOpkViewActive) insert(items, BUTOPKVIEWACTIVE);
	if (ButOpkNewcrdActive == comp->ButOpkNewcrdActive) insert(items, BUTOPKNEWCRDACTIVE);
	if (LstOpxAvail == comp->LstOpxAvail) insert(items, LSTOPXAVAIL);
	if (ButOpxViewActive == comp->ButOpxViewActive) insert(items, BUTOPXVIEWACTIVE);
	if (ButOpxNewcrdActive == comp->ButOpxNewcrdActive) insert(items, BUTOPXNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavComp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTOPKAVAIL, BUTOPKVIEWACTIVE, BUTOPKNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavComp::Tag
 ******************************************************************************/

void PnlWznmNavComp::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavComp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Computing module";
		me["CptOpk"] = "operation packs";
		me["CptOpx"] = "operations";
	};
};

void PnlWznmNavComp::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavComp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavComp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Computing module");
			writeStringAttr(wr, itemtag, "sref", "CptOpk", "operation packs");
			writeStringAttr(wr, itemtag, "sref", "CptOpx", "operations");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavComp::DpchAppData
 ******************************************************************************/

PnlWznmNavComp::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVCOMPDATA)
		{
};

string PnlWznmNavComp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavComp::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavCompData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmNavComp::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavCompData");
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
 class PnlWznmNavComp::DpchAppDo
 ******************************************************************************/

PnlWznmNavComp::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVCOMPDO)
		{
	ixVDo = 0;
};

string PnlWznmNavComp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavComp::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavCompDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmNavComp::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavCompDo");
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
 class PnlWznmNavComp::DpchEngData
 ******************************************************************************/

PnlWznmNavComp::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstOpk
			, Feed* feedFLstOpx
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVCOMPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTOPK, FEEDFLSTOPX, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTOPK) && feedFLstOpk) this->feedFLstOpk = *feedFLstOpk;
	if (find(this->mask, FEEDFLSTOPX) && feedFLstOpx) this->feedFLstOpx = *feedFLstOpx;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavComp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTOPK)) ss.push_back("feedFLstOpk");
	if (has(FEEDFLSTOPX)) ss.push_back("feedFLstOpx");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavComp::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTOPK)) {feedFLstOpk = src->feedFLstOpk; add(FEEDFLSTOPK);};
	if (src->has(FEEDFLSTOPX)) {feedFLstOpx = src->feedFLstOpx; add(FEEDFLSTOPX);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavComp::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmNavCompData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTOPK)) feedFLstOpk.writeJSON(me);
	if (has(FEEDFLSTOPX)) feedFLstOpx.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmNavComp::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavCompData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTOPK)) feedFLstOpk.writeXML(wr);
		if (has(FEEDFLSTOPX)) feedFLstOpx.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
