/**
	* \file PnlWznmJobMNOp_blks.cpp
	* job handler for job PnlWznmJobMNOp (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmJobMNOp::VecVDo
 ******************************************************************************/

uint PnlWznmJobMNOp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butviewclick") return BUTVIEWCLICK;
	if (s == "butaddclick") return BUTADDCLICK;
	if (s == "butsubclick") return BUTSUBCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWznmJobMNOp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVIEWCLICK) return("ButViewClick");
	if (ix == BUTADDCLICK) return("ButAddClick");
	if (ix == BUTSUBCLICK) return("ButSubClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWznmJobMNOp::ContInf
 ******************************************************************************/

PnlWznmJobMNOp::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlWznmJobMNOp::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmJobMNOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFCsiQst"] = numFCsiQst;
};

void PnlWznmJobMNOp::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmJobMNOp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmJobMNOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmJobMNOp::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWznmJobMNOp::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmJobMNOp::StatApp
 ******************************************************************************/

void PnlWznmJobMNOp::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmJobMNOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
};

void PnlWznmJobMNOp::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmJobMNOp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmJobMNOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmJobMNOp::StatShr
 ******************************************************************************/

PnlWznmJobMNOp::StatShr::StatShr(
			const bool ButViewAvail
			, const bool ButViewActive
			, const bool ButAddAvail
			, const bool ButSubAvail
			, const bool ButSubActive
		) :
			Block()
		{
	this->ButViewAvail = ButViewAvail;
	this->ButViewActive = ButViewActive;
	this->ButAddAvail = ButAddAvail;
	this->ButSubAvail = ButSubAvail;
	this->ButSubActive = ButSubActive;

	mask = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
};

void PnlWznmJobMNOp::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmJobMNOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButViewAvail"] = ButViewAvail;
	me["ButViewActive"] = ButViewActive;
	me["ButAddAvail"] = ButAddAvail;
	me["ButSubAvail"] = ButSubAvail;
	me["ButSubActive"] = ButSubActive;
};

void PnlWznmJobMNOp::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmJobMNOp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmJobMNOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButViewAvail", ButViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButViewActive", ButViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButAddAvail", ButAddAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSubAvail", ButSubAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSubActive", ButSubActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmJobMNOp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButViewAvail == comp->ButViewAvail) insert(items, BUTVIEWAVAIL);
	if (ButViewActive == comp->ButViewActive) insert(items, BUTVIEWACTIVE);
	if (ButAddAvail == comp->ButAddAvail) insert(items, BUTADDAVAIL);
	if (ButSubAvail == comp->ButSubAvail) insert(items, BUTSUBAVAIL);
	if (ButSubActive == comp->ButSubActive) insert(items, BUTSUBACTIVE);

	return(items);
};

set<uint> PnlWznmJobMNOp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTVIEWAVAIL, BUTVIEWACTIVE, BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmJobMNOp::StgIac
 ******************************************************************************/

PnlWznmJobMNOp::StgIac::StgIac(
			const uint TcoMrefWidth
		) :
			Block()
		{
	this->TcoMrefWidth = TcoMrefWidth;
	mask = {TCOMREFWIDTH};
};

bool PnlWznmJobMNOp::StgIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["StgIacWznmJobMNOp"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TcoMrefWidth")) {TcoMrefWidth = me["TcoMrefWidth"].asUInt(); add(TCOMREFWIDTH);};
	};

	return basefound;
};

bool PnlWznmJobMNOp::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWznmJobMNOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWznmJobMNOp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", TcoMrefWidth)) add(TCOMREFWIDTH);
	};

	return basefound;
};

void PnlWznmJobMNOp::StgIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmJobMNOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TcoMrefWidth"] = TcoMrefWidth;
};

void PnlWznmJobMNOp::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmJobMNOp";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWznmJobMNOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmJobMNOp::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoMrefWidth == comp->TcoMrefWidth) insert(items, TCOMREFWIDTH);

	return(items);
};

set<uint> PnlWznmJobMNOp::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOMREFWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmJobMNOp::Tag
 ******************************************************************************/

void PnlWznmJobMNOp::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmJobMNOp";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Operation invocations";
		me["TcoMref"] = "Op.";
	};
	me["TxtRecord1"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::REC, ixWznmVLocale));
	me["TxtRecord2"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale));
	me["Trs"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::GOTO, ixWznmVLocale)) + " ...";
	me["TxtShowing1"] = VecWznmVTag::getTitle(VecWznmVTag::SHOWSHORT, ixWznmVLocale);
	me["TxtShowing2"] = VecWznmVTag::getTitle(VecWznmVTag::EMPSHORT, ixWznmVLocale);
};

void PnlWznmJobMNOp::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmJobMNOp";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmJobMNOp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Operation invocations");
			writeStringAttr(wr, itemtag, "sref", "TcoMref", "Op.");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::REC, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::GOTO, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecWznmVTag::getTitle(VecWznmVTag::SHOWSHORT, ixWznmVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecWznmVTag::getTitle(VecWznmVTag::EMPSHORT, ixWznmVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmJobMNOp::DpchAppData
 ******************************************************************************/

PnlWznmJobMNOp::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMJOBMNOPDATA)
		{
};

string PnlWznmJobMNOp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmJobMNOp::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmJobMNOpData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (stgiac.readJSON(me, true)) add(STGIAC);
		if (stgiacqry.readJSON(me, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryWznmJobMNOp::StgIac();
	};
};

void PnlWznmJobMNOp::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmJobMNOpData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryWznmJobMNOp::StgIac();
	};
};

/******************************************************************************
 class PnlWznmJobMNOp::DpchAppDo
 ******************************************************************************/

PnlWznmJobMNOp::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMJOBMNOPDO)
		{
	ixVDo = 0;
};

string PnlWznmJobMNOp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmJobMNOp::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmJobMNOpDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmJobMNOp::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmJobMNOpDo");
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
 class PnlWznmJobMNOp::DpchEngData
 ******************************************************************************/

PnlWznmJobMNOp::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListWznmQJobMNOp* rst
			, QryWznmJobMNOp::StatShr* statshrqry
			, QryWznmJobMNOp::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMJOBMNOPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWznmJobMNOp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmJobMNOp::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlWznmJobMNOp::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmJobMNOpData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFCSIQST)) feedFCsiQst.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGIAC)) stgiac.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
	if (has(RST)) rst.writeJSON(me);
	if (has(STATAPPQRY)) QryWznmJobMNOp::StatApp::writeJSON(me);
	if (has(STATSHRQRY)) statshrqry.writeJSON(me);
	if (has(STGIACQRY)) stgiacqry.writeJSON(me);
};

void PnlWznmJobMNOp::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmJobMNOpData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWznmJobMNOp::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
