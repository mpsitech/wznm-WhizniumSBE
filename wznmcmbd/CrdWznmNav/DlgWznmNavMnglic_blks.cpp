/**
	* \file DlgWznmNavMnglic_blks.cpp
	* job handler for job DlgWznmNavMnglic (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmNavMnglic::VecVDo
 ******************************************************************************/

uint DlgWznmNavMnglic::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutscnclick") return DETBUTSCNCLICK;
	if (s == "detbutsdcclick") return DETBUTSDCCLICK;
	if (s == "detbutactclick") return DETBUTACTCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmNavMnglic::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTSCNCLICK) return("DetButScnClick");
	if (ix == DETBUTSDCCLICK) return("DetButSdcClick");
	if (ix == DETBUTACTCLICK) return("DetButActClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmNavMnglic::VecVSge
 ******************************************************************************/

uint DlgWznmNavMnglic::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;

	return(0);
};

string DlgWznmNavMnglic::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");

	return("");
};

void DlgWznmNavMnglic::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmNavMnglic::ContIac
 ******************************************************************************/

DlgWznmNavMnglic::ContIac::ContIac(
			const uint numFDetPupFis
			, const bool DetChkFis
			, const uint numFDetLstLcs
		) :
			Block()
			, numFDetPupFis(numFDetPupFis)
			, DetChkFis(DetChkFis)
			, numFDetLstLcs(numFDetLstLcs)
		{
	mask = {NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS};
};

bool DlgWznmNavMnglic::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacDlgWznmNavMnglic"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDetPupFis")) {numFDetPupFis = me["numFDetPupFis"].asUInt(); add(NUMFDETPUPFIS);};
		if (me.isMember("DetChkFis")) {DetChkFis = me["DetChkFis"].asBool(); add(DETCHKFIS);};
		if (me.isMember("numFDetLstLcs")) {numFDetLstLcs = me["numFDetLstLcs"].asUInt(); add(NUMFDETLSTLCS);};
	};

	return basefound;
};

bool DlgWznmNavMnglic::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmNavMnglic");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmNavMnglic";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupFis", numFDetPupFis)) add(NUMFDETPUPFIS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetChkFis", DetChkFis)) add(DETCHKFIS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetLstLcs", numFDetLstLcs)) add(NUMFDETLSTLCS);
	};

	return basefound;
};

void DlgWznmNavMnglic::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDetPupFis"] = (Json::Value::UInt) numFDetPupFis;
	me["DetChkFis"] = DetChkFis;
	me["numFDetLstLcs"] = (Json::Value::UInt) numFDetLstLcs;
};

void DlgWznmNavMnglic::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupFis", numFDetPupFis);
		writeBoolAttr(wr, itemtag, "sref", "DetChkFis", DetChkFis);
		writeUintAttr(wr, itemtag, "sref", "numFDetLstLcs", numFDetLstLcs);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmNavMnglic::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupFis == comp->numFDetPupFis) insert(items, NUMFDETPUPFIS);
	if (DetChkFis == comp->DetChkFis) insert(items, DETCHKFIS);
	if (numFDetLstLcs == comp->numFDetLstLcs) insert(items, NUMFDETLSTLCS);

	return(items);
};

set<uint> DlgWznmNavMnglic::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmNavMnglic::ContInf
 ******************************************************************************/

DlgWznmNavMnglic::ContInf::ContInf(
			const uint numFSge
			, const string& DetTxtSip
			, const string& DetTxtScp
			, const string& DetTxtLsr
			, const string& DetTxtLar
			, const string& DetTxtLst
			, const string& DetTxtLex
		) :
			Block()
			, numFSge(numFSge)
			, DetTxtSip(DetTxtSip)
			, DetTxtScp(DetTxtScp)
			, DetTxtLsr(DetTxtLsr)
			, DetTxtLar(DetTxtLar)
			, DetTxtLst(DetTxtLst)
			, DetTxtLex(DetTxtLex)
		{
	mask = {NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX};
};

void DlgWznmNavMnglic::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["DetTxtSip"] = DetTxtSip;
	me["DetTxtScp"] = DetTxtScp;
	me["DetTxtLsr"] = DetTxtLsr;
	me["DetTxtLar"] = DetTxtLar;
	me["DetTxtLst"] = DetTxtLst;
	me["DetTxtLex"] = DetTxtLex;
};

void DlgWznmNavMnglic::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "DetTxtSip", DetTxtSip);
		writeStringAttr(wr, itemtag, "sref", "DetTxtScp", DetTxtScp);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLsr", DetTxtLsr);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLar", DetTxtLar);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLst", DetTxtLst);
		writeStringAttr(wr, itemtag, "sref", "DetTxtLex", DetTxtLex);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmNavMnglic::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (DetTxtSip == comp->DetTxtSip) insert(items, DETTXTSIP);
	if (DetTxtScp == comp->DetTxtScp) insert(items, DETTXTSCP);
	if (DetTxtLsr == comp->DetTxtLsr) insert(items, DETTXTLSR);
	if (DetTxtLar == comp->DetTxtLar) insert(items, DETTXTLAR);
	if (DetTxtLst == comp->DetTxtLst) insert(items, DETTXTLST);
	if (DetTxtLex == comp->DetTxtLex) insert(items, DETTXTLEX);

	return(items);
};

set<uint> DlgWznmNavMnglic::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmNavMnglic::StatApp
 ******************************************************************************/

void DlgWznmNavMnglic::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
			, const uint DetLstLcsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
	me["DetLstLcsNumFirstdisp"] = (Json::Value::UInt) DetLstLcsNumFirstdisp;
};

void DlgWznmNavMnglic::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
			, const uint DetLstLcsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "DetLstLcsNumFirstdisp", DetLstLcsNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmNavMnglic::StatShr
 ******************************************************************************/

DlgWznmNavMnglic::StatShr::StatShr(
			const bool DetButActActive
		) :
			Block()
			, DetButActActive(DetButActActive)
		{
	mask = {DETBUTACTACTIVE};
};

void DlgWznmNavMnglic::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["DetButActActive"] = DetButActActive;
};

void DlgWznmNavMnglic::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DetButActActive", DetButActActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmNavMnglic::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButActActive == comp->DetButActActive) insert(items, DETBUTACTACTIVE);

	return(items);
};

set<uint> DlgWznmNavMnglic::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTACTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmNavMnglic::Tag
 ******************************************************************************/

void DlgWznmNavMnglic::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmNavMnglic";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Manage licenses";
		me["DetHdgSrv"] = "Licensing server";
		me["DetCptSip"] = "IP address";
		me["DetCptScp"] = "Certificate path";
		me["DetButScn"] = "Connect";
		me["DetButSdc"] = "Disconnect";
		me["DetCptFis"] = "Filter by state";
		me["DetCptLcs"] = "Licenses";
		me["DetButAct"] = "Activate";
		me["DetHdgLic"] = "License";
		me["DetCptLsr"] = "Identifier";
		me["DetCptLar"] = "Article";
		me["DetCptLst"] = "State";
		me["DetCptLex"] = "Expiry";
	};
	me["ButDne"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale));
};

void DlgWznmNavMnglic::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Manage licenses");
			writeStringAttr(wr, itemtag, "sref", "DetHdgSrv", "Licensing server");
			writeStringAttr(wr, itemtag, "sref", "DetCptSip", "IP address");
			writeStringAttr(wr, itemtag, "sref", "DetCptScp", "Certificate path");
			writeStringAttr(wr, itemtag, "sref", "DetButScn", "Connect");
			writeStringAttr(wr, itemtag, "sref", "DetButSdc", "Disconnect");
			writeStringAttr(wr, itemtag, "sref", "DetCptFis", "Filter by state");
			writeStringAttr(wr, itemtag, "sref", "DetCptLcs", "Licenses");
			writeStringAttr(wr, itemtag, "sref", "DetButAct", "Activate");
			writeStringAttr(wr, itemtag, "sref", "DetHdgLic", "License");
			writeStringAttr(wr, itemtag, "sref", "DetCptLsr", "Identifier");
			writeStringAttr(wr, itemtag, "sref", "DetCptLar", "Article");
			writeStringAttr(wr, itemtag, "sref", "DetCptLst", "State");
			writeStringAttr(wr, itemtag, "sref", "DetCptLex", "Expiry");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmNavMnglic::DpchAppData
 ******************************************************************************/

DlgWznmNavMnglic::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMNAVMNGLICDATA)
		{
};

string DlgWznmNavMnglic::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmNavMnglic::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWznmNavMnglicData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWznmNavMnglic::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmNavMnglicData");
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
 class DlgWznmNavMnglic::DpchAppDo
 ******************************************************************************/

DlgWznmNavMnglic::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMNAVMNGLICDO)
		{
	ixVDo = 0;
};

string DlgWznmNavMnglic::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmNavMnglic::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppDlgWznmNavMnglicDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWznmNavMnglic::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmNavMnglicDo");
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
 class DlgWznmNavMnglic::DpchEngData
 ******************************************************************************/

DlgWznmNavMnglic::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFDetLstLcs
			, Feed* feedFDetPupFis
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMNAVMNGLICDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFDETLSTLCS, FEEDFDETPUPFIS, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETLSTLCS) && feedFDetLstLcs) this->feedFDetLstLcs = *feedFDetLstLcs;
	if (find(this->mask, FEEDFDETPUPFIS) && feedFDetPupFis) this->feedFDetPupFis = *feedFDetPupFis;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWznmNavMnglic::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETLSTLCS)) ss.push_back("feedFDetLstLcs");
	if (has(FEEDFDETPUPFIS)) ss.push_back("feedFDetPupFis");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmNavMnglic::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETLSTLCS)) {feedFDetLstLcs = src->feedFDetLstLcs; add(FEEDFDETLSTLCS);};
	if (src->has(FEEDFDETPUPFIS)) {feedFDetPupFis = src->feedFDetPupFis; add(FEEDFDETPUPFIS);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWznmNavMnglic::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWznmNavMnglicData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETLSTLCS)) feedFDetLstLcs.writeJSON(me);
	if (has(FEEDFDETPUPFIS)) feedFDetPupFis.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void DlgWznmNavMnglic::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmNavMnglicData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETLSTLCS)) feedFDetLstLcs.writeXML(wr);
		if (has(FEEDFDETPUPFIS)) feedFDetPupFis.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
