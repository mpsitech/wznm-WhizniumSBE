/**
	* \file PnlWznmCmpRec_blks.cpp
	* job handler for job PnlWznmCmpRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmCmpRec::VecVDo
 ******************************************************************************/

uint PnlWznmCmpRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmCmpRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmCmpRec::ContInf
 ******************************************************************************/

PnlWznmCmpRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWznmCmpRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmCmpRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlWznmCmpRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmCmpRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmCmpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmCmpRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmCmpRec::ContInf::diff(
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
 class PnlWznmCmpRec::StatApp
 ******************************************************************************/

void PnlWznmCmpRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdone1NRelease
			, const bool initdoneMNOppack
			, const bool initdoneMNLibrary
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmCmpRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdone1NRelease"] = initdone1NRelease;
	me["initdoneMNOppack"] = initdoneMNOppack;
	me["initdoneMNLibrary"] = initdoneMNLibrary;
};

void PnlWznmCmpRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdone1NRelease
			, const bool initdoneMNOppack
			, const bool initdoneMNLibrary
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmCmpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmCmpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NRelease", initdone1NRelease);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNOppack", initdoneMNOppack);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLibrary", initdoneMNLibrary);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCmpRec::StatShr
 ******************************************************************************/

PnlWznmCmpRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jref1NRelease
			, const ubigint jrefMNOppack
			, const bool pnlmnoppackAvail
			, const ubigint jrefMNLibrary
			, const bool pnlmnlibraryAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jref1NRelease = jref1NRelease;
	this->jrefMNOppack = jrefMNOppack;
	this->pnlmnoppackAvail = pnlmnoppackAvail;
	this->jrefMNLibrary = jrefMNLibrary;
	this->pnlmnlibraryAvail = pnlmnlibraryAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREF1NRELEASE, JREFMNOPPACK, PNLMNOPPACKAVAIL, JREFMNLIBRARY, PNLMNLIBRARYAVAIL, BUTREGULARIZEACTIVE};
};

void PnlWznmCmpRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmCmpRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJref1NRelease"] = Scr::scramble(jref1NRelease);
	me["scrJrefMNOppack"] = Scr::scramble(jrefMNOppack);
	me["pnlmnoppackAvail"] = pnlmnoppackAvail;
	me["scrJrefMNLibrary"] = Scr::scramble(jrefMNLibrary);
	me["pnlmnlibraryAvail"] = pnlmnlibraryAvail;
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlWznmCmpRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmCmpRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmCmpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NRelease", Scr::scramble(jref1NRelease));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNOppack", Scr::scramble(jrefMNOppack));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnoppackAvail", pnlmnoppackAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLibrary", Scr::scramble(jrefMNLibrary));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnlibraryAvail", pnlmnlibraryAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmCmpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jref1NRelease == comp->jref1NRelease) insert(items, JREF1NRELEASE);
	if (jrefMNOppack == comp->jrefMNOppack) insert(items, JREFMNOPPACK);
	if (pnlmnoppackAvail == comp->pnlmnoppackAvail) insert(items, PNLMNOPPACKAVAIL);
	if (jrefMNLibrary == comp->jrefMNLibrary) insert(items, JREFMNLIBRARY);
	if (pnlmnlibraryAvail == comp->pnlmnlibraryAvail) insert(items, PNLMNLIBRARYAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmCmpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREF1NRELEASE, JREFMNOPPACK, PNLMNOPPACKAVAIL, JREFMNLIBRARY, PNLMNLIBRARYAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCmpRec::Tag
 ******************************************************************************/

void PnlWznmCmpRec::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmCmpRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Component";
	};
};

void PnlWznmCmpRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmCmpRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmCmpRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Component");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCmpRec::DpchAppDo
 ******************************************************************************/

PnlWznmCmpRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCMPRECDO)
		{
	ixVDo = 0;
};

string PnlWznmCmpRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCmpRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmCmpRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmCmpRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmCmpRecDo");
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
 class PnlWznmCmpRec::DpchEngData
 ******************************************************************************/

PnlWznmCmpRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCMPRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmCmpRec::DpchEngData::getSrefsMask() {
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

void PnlWznmCmpRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmCmpRec::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmCmpRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmCmpRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmCmpRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
