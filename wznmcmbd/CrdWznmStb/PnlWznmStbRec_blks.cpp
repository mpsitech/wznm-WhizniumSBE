/**
	* \file PnlWznmStbRec_blks.cpp
	* job handler for job PnlWznmStbRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmStbRec::VecVDo
 ******************************************************************************/

uint PnlWznmStbRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmStbRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmStbRec::ContInf
 ******************************************************************************/

PnlWznmStbRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWznmStbRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmStbRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlWznmStbRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmStbRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmStbRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmStbRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmStbRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbRec::StatApp
 ******************************************************************************/

void PnlWznmStbRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdoneSupMNStub
			, const bool initdoneMNCall
			, const bool initdoneMNSquawk
			, const bool initdoneSubMNStub
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmStbRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdoneSupMNStub"] = initdoneSupMNStub;
	me["initdoneMNCall"] = initdoneMNCall;
	me["initdoneMNSquawk"] = initdoneMNSquawk;
	me["initdoneSubMNStub"] = initdoneSubMNStub;
};

void PnlWznmStbRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneSupMNStub
			, const bool initdoneMNCall
			, const bool initdoneMNSquawk
			, const bool initdoneSubMNStub
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmStbRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmStbRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSupMNStub", initdoneSupMNStub);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNCall", initdoneMNCall);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNSquawk", initdoneMNSquawk);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSubMNStub", initdoneSubMNStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmStbRec::StatShr
 ******************************************************************************/

PnlWznmStbRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefSupMNStub
			, const ubigint jrefMNCall
			, const ubigint jrefMNSquawk
			, const ubigint jrefSubMNStub
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefSupMNStub = jrefSupMNStub;
	this->jrefMNCall = jrefMNCall;
	this->jrefMNSquawk = jrefMNSquawk;
	this->jrefSubMNStub = jrefSubMNStub;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFSUPMNSTUB, JREFMNCALL, JREFMNSQUAWK, JREFSUBMNSTUB, BUTREGULARIZEACTIVE};
};

void PnlWznmStbRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmStbRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefSupMNStub"] = Scr::scramble(jrefSupMNStub);
	me["scrJrefMNCall"] = Scr::scramble(jrefMNCall);
	me["scrJrefMNSquawk"] = Scr::scramble(jrefMNSquawk);
	me["scrJrefSubMNStub"] = Scr::scramble(jrefSubMNStub);
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlWznmStbRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmStbRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmStbRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSupMNStub", Scr::scramble(jrefSupMNStub));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNCall", Scr::scramble(jrefMNCall));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNSquawk", Scr::scramble(jrefMNSquawk));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSubMNStub", Scr::scramble(jrefSubMNStub));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmStbRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefSupMNStub == comp->jrefSupMNStub) insert(items, JREFSUPMNSTUB);
	if (jrefMNCall == comp->jrefMNCall) insert(items, JREFMNCALL);
	if (jrefMNSquawk == comp->jrefMNSquawk) insert(items, JREFMNSQUAWK);
	if (jrefSubMNStub == comp->jrefSubMNStub) insert(items, JREFSUBMNSTUB);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmStbRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFSUPMNSTUB, JREFMNCALL, JREFMNSQUAWK, JREFSUBMNSTUB, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbRec::Tag
 ******************************************************************************/

void PnlWznmStbRec::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmStbRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Stub";
	};
};

void PnlWznmStbRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmStbRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmStbRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Stub");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmStbRec::DpchAppDo
 ******************************************************************************/

PnlWznmStbRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTBRECDO)
		{
	ixVDo = 0;
};

string PnlWznmStbRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbRec::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmStbRecDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmStbRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmStbRecDo");
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
 class PnlWznmStbRec::DpchEngData
 ******************************************************************************/

PnlWznmStbRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTBRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmStbRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmStbRec::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmStbRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmStbRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmStbRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
