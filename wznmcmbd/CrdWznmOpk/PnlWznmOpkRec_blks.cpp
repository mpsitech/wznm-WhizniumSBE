/**
	* \file PnlWznmOpkRec_blks.cpp
	* job handler for job PnlWznmOpkRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmOpkRec::VecVDo
 ******************************************************************************/

uint PnlWznmOpkRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmOpkRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmOpkRec::ContInf
 ******************************************************************************/

PnlWznmOpkRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWznmOpkRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmOpkRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlWznmOpkRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmOpkRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmOpkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmOpkRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmOpkRec::ContInf::diff(
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
 class PnlWznmOpkRec::StatApp
 ******************************************************************************/

void PnlWznmOpkRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdoneAInvarg
			, const bool initdoneARetval
			, const bool initdone1NOp
			, const bool initdoneRef1NBlock
			, const bool initdoneMNJob
			, const bool initdoneMNComponent
			, const bool initdoneMNLibrary
			, const bool initdoneSqkMNStub
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmOpkRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdoneAInvarg"] = initdoneAInvarg;
	me["initdoneARetval"] = initdoneARetval;
	me["initdone1NOp"] = initdone1NOp;
	me["initdoneRef1NBlock"] = initdoneRef1NBlock;
	me["initdoneMNJob"] = initdoneMNJob;
	me["initdoneMNComponent"] = initdoneMNComponent;
	me["initdoneMNLibrary"] = initdoneMNLibrary;
	me["initdoneSqkMNStub"] = initdoneSqkMNStub;
};

void PnlWznmOpkRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneAInvarg
			, const bool initdoneARetval
			, const bool initdone1NOp
			, const bool initdoneRef1NBlock
			, const bool initdoneMNJob
			, const bool initdoneMNComponent
			, const bool initdoneMNLibrary
			, const bool initdoneSqkMNStub
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmOpkRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmOpkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAInvarg", initdoneAInvarg);
		writeBoolAttr(wr, itemtag, "sref", "initdoneARetval", initdoneARetval);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NOp", initdone1NOp);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NBlock", initdoneRef1NBlock);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNJob", initdoneMNJob);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNComponent", initdoneMNComponent);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLibrary", initdoneMNLibrary);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSqkMNStub", initdoneSqkMNStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpkRec::StatShr
 ******************************************************************************/

PnlWznmOpkRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefAInvarg
			, const ubigint jrefARetval
			, const ubigint jref1NOp
			, const ubigint jrefRef1NBlock
			, const ubigint jrefMNJob
			, const ubigint jrefMNComponent
			, const ubigint jrefMNLibrary
			, const ubigint jrefSqkMNStub
			, const bool pnlsqkmnstubAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefAInvarg = jrefAInvarg;
	this->jrefARetval = jrefARetval;
	this->jref1NOp = jref1NOp;
	this->jrefRef1NBlock = jrefRef1NBlock;
	this->jrefMNJob = jrefMNJob;
	this->jrefMNComponent = jrefMNComponent;
	this->jrefMNLibrary = jrefMNLibrary;
	this->jrefSqkMNStub = jrefSqkMNStub;
	this->pnlsqkmnstubAvail = pnlsqkmnstubAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFAINVARG, JREFARETVAL, JREF1NOP, JREFREF1NBLOCK, JREFMNJOB, JREFMNCOMPONENT, JREFMNLIBRARY, JREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE};
};

void PnlWznmOpkRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmOpkRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefAInvarg"] = Scr::scramble(jrefAInvarg);
	me["scrJrefARetval"] = Scr::scramble(jrefARetval);
	me["scrJref1NOp"] = Scr::scramble(jref1NOp);
	me["scrJrefRef1NBlock"] = Scr::scramble(jrefRef1NBlock);
	me["scrJrefMNJob"] = Scr::scramble(jrefMNJob);
	me["scrJrefMNComponent"] = Scr::scramble(jrefMNComponent);
	me["scrJrefMNLibrary"] = Scr::scramble(jrefMNLibrary);
	me["scrJrefSqkMNStub"] = Scr::scramble(jrefSqkMNStub);
	me["pnlsqkmnstubAvail"] = pnlsqkmnstubAvail;
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlWznmOpkRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmOpkRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmOpkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAInvarg", Scr::scramble(jrefAInvarg));
		writeStringAttr(wr, itemtag, "sref", "scrJrefARetval", Scr::scramble(jrefARetval));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NOp", Scr::scramble(jref1NOp));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NBlock", Scr::scramble(jrefRef1NBlock));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNJob", Scr::scramble(jrefMNJob));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNComponent", Scr::scramble(jrefMNComponent));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLibrary", Scr::scramble(jrefMNLibrary));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSqkMNStub", Scr::scramble(jrefSqkMNStub));
		writeBoolAttr(wr, itemtag, "sref", "pnlsqkmnstubAvail", pnlsqkmnstubAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmOpkRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefAInvarg == comp->jrefAInvarg) insert(items, JREFAINVARG);
	if (jrefARetval == comp->jrefARetval) insert(items, JREFARETVAL);
	if (jref1NOp == comp->jref1NOp) insert(items, JREF1NOP);
	if (jrefRef1NBlock == comp->jrefRef1NBlock) insert(items, JREFREF1NBLOCK);
	if (jrefMNJob == comp->jrefMNJob) insert(items, JREFMNJOB);
	if (jrefMNComponent == comp->jrefMNComponent) insert(items, JREFMNCOMPONENT);
	if (jrefMNLibrary == comp->jrefMNLibrary) insert(items, JREFMNLIBRARY);
	if (jrefSqkMNStub == comp->jrefSqkMNStub) insert(items, JREFSQKMNSTUB);
	if (pnlsqkmnstubAvail == comp->pnlsqkmnstubAvail) insert(items, PNLSQKMNSTUBAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmOpkRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFAINVARG, JREFARETVAL, JREF1NOP, JREFREF1NBLOCK, JREFMNJOB, JREFMNCOMPONENT, JREFMNLIBRARY, JREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpkRec::Tag
 ******************************************************************************/

void PnlWznmOpkRec::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmOpkRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Operation pack";
	};
};

void PnlWznmOpkRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmOpkRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmOpkRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Operation pack");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpkRec::DpchAppDo
 ******************************************************************************/

PnlWznmOpkRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPKRECDO)
		{
	ixVDo = 0;
};

string PnlWznmOpkRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpkRec::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmOpkRecDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmOpkRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmOpkRecDo");
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
 class PnlWznmOpkRec::DpchEngData
 ******************************************************************************/

PnlWznmOpkRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMOPKRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmOpkRec::DpchEngData::getSrefsMask() {
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

void PnlWznmOpkRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmOpkRec::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmOpkRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmOpkRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmOpkRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
