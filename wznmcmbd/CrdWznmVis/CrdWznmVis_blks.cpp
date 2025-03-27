/**
	* \file CrdWznmVis_blks.cpp
	* job handler for job CrdWznmVis (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmVis::VecVDo
 ******************************************************************************/

uint CrdWznmVis::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdistclick") return MITCRDISTCLICK;
	if (s == "mitcrdcmfclick") return MITCRDCMFCLICK;
	if (s == "mitcrdwrcclick") return MITCRDWRCCLICK;
	if (s == "mitcrdestclick") return MITCRDESTCLICK;

	return(0);
};

string CrdWznmVis::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDISTCLICK) return("MitCrdIstClick");
	if (ix == MITCRDCMFCLICK) return("MitCrdCmfClick");
	if (ix == MITCRDWRCCLICK) return("MitCrdWrcClick");
	if (ix == MITCRDESTCLICK) return("MitCrdEstClick");

	return("");
};

/******************************************************************************
 class CrdWznmVis::VecVSge
 ******************************************************************************/

uint CrdWznmVis::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmVis::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

void CrdWznmVis::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWznmVis::ContInf
 ******************************************************************************/

CrdWznmVis::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdVis
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxCrdVis(MtxCrdVis)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXCRDVIS};
};

void CrdWznmVis::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVis";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxCrdVis"] = MtxCrdVis;
};

void CrdWznmVis::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVis";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmVis";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdVis", MtxCrdVis);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmVis::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdVis == comp->MtxCrdVis) insert(items, MTXCRDVIS);

	return(items);
};

set<uint> CrdWznmVis::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDVIS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVis::StatApp
 ******************************************************************************/

void CrdWznmVis::StatApp::writeJSON(
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
	if (difftag.length() == 0) difftag = "StatAppWznmVis";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVReqitmode"] = VecWznmVReqitmode::getSref(ixWznmVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = (Json::Value::UInt) widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneList"] = initdoneList;
	me["initdoneRec"] = initdoneRec;
};

void CrdWznmVis::StatApp::writeXML(
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
	if (difftag.length() == 0) difftag = "StatAppWznmVis";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmVis";

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
 class CrdWznmVis::StatShr
 ******************************************************************************/

CrdWznmVis::StatShr::StatShr(
			const ubigint jrefDlgexpstr
			, const ubigint jrefDlgimpstr
			, const ubigint jrefDlgmissfeat
			, const ubigint jrefDlgnew
			, const ubigint jrefDlgwrite
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdIstAvail
			, const bool MitCrdIstActive
			, const bool MitCrdCmfAvail
			, const bool MitCrdCmfActive
			, const bool MitCrdWrcAvail
			, const bool MitCrdWrcActive
			, const bool MitCrdEstActive
		) :
			Block()
			, jrefDlgexpstr(jrefDlgexpstr)
			, jrefDlgimpstr(jrefDlgimpstr)
			, jrefDlgmissfeat(jrefDlgmissfeat)
			, jrefDlgnew(jrefDlgnew)
			, jrefDlgwrite(jrefDlgwrite)
			, jrefHeadbar(jrefHeadbar)
			, jrefList(jrefList)
			, jrefRec(jrefRec)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdNewAvail(MitCrdNewAvail)
			, MitCrdIstAvail(MitCrdIstAvail)
			, MitCrdIstActive(MitCrdIstActive)
			, MitCrdCmfAvail(MitCrdCmfAvail)
			, MitCrdCmfActive(MitCrdCmfActive)
			, MitCrdWrcAvail(MitCrdWrcAvail)
			, MitCrdWrcActive(MitCrdWrcActive)
			, MitCrdEstActive(MitCrdEstActive)
		{
	mask = {JREFDLGEXPSTR, JREFDLGIMPSTR, JREFDLGMISSFEAT, JREFDLGNEW, JREFDLGWRITE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDISTAVAIL, MITCRDISTACTIVE, MITCRDCMFAVAIL, MITCRDCMFACTIVE, MITCRDWRCAVAIL, MITCRDWRCACTIVE, MITCRDESTACTIVE};
};

void CrdWznmVis::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVis";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgexpstr"] = Scr::scramble(jrefDlgexpstr);
	me["scrJrefDlgimpstr"] = Scr::scramble(jrefDlgimpstr);
	me["scrJrefDlgmissfeat"] = Scr::scramble(jrefDlgmissfeat);
	me["scrJrefDlgnew"] = Scr::scramble(jrefDlgnew);
	me["scrJrefDlgwrite"] = Scr::scramble(jrefDlgwrite);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefList"] = Scr::scramble(jrefList);
	me["scrJrefRec"] = Scr::scramble(jrefRec);
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdNewAvail"] = MitCrdNewAvail;
	me["MitCrdIstAvail"] = MitCrdIstAvail;
	me["MitCrdIstActive"] = MitCrdIstActive;
	me["MitCrdCmfAvail"] = MitCrdCmfAvail;
	me["MitCrdCmfActive"] = MitCrdCmfActive;
	me["MitCrdWrcAvail"] = MitCrdWrcAvail;
	me["MitCrdWrcActive"] = MitCrdWrcActive;
	me["MitCrdEstActive"] = MitCrdEstActive;
};

void CrdWznmVis::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVis";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmVis";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgexpstr", Scr::scramble(jrefDlgexpstr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgimpstr", Scr::scramble(jrefDlgimpstr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgmissfeat", Scr::scramble(jrefDlgmissfeat));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgnew", Scr::scramble(jrefDlgnew));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgwrite", Scr::scramble(jrefDlgwrite));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNewAvail", MitCrdNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIstAvail", MitCrdIstAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIstActive", MitCrdIstActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCmfAvail", MitCrdCmfAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCmfActive", MitCrdCmfActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdWrcAvail", MitCrdWrcAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdWrcActive", MitCrdWrcActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdEstActive", MitCrdEstActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmVis::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgexpstr == comp->jrefDlgexpstr) insert(items, JREFDLGEXPSTR);
	if (jrefDlgimpstr == comp->jrefDlgimpstr) insert(items, JREFDLGIMPSTR);
	if (jrefDlgmissfeat == comp->jrefDlgmissfeat) insert(items, JREFDLGMISSFEAT);
	if (jrefDlgnew == comp->jrefDlgnew) insert(items, JREFDLGNEW);
	if (jrefDlgwrite == comp->jrefDlgwrite) insert(items, JREFDLGWRITE);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdIstAvail == comp->MitCrdIstAvail) insert(items, MITCRDISTAVAIL);
	if (MitCrdIstActive == comp->MitCrdIstActive) insert(items, MITCRDISTACTIVE);
	if (MitCrdCmfAvail == comp->MitCrdCmfAvail) insert(items, MITCRDCMFAVAIL);
	if (MitCrdCmfActive == comp->MitCrdCmfActive) insert(items, MITCRDCMFACTIVE);
	if (MitCrdWrcAvail == comp->MitCrdWrcAvail) insert(items, MITCRDWRCAVAIL);
	if (MitCrdWrcActive == comp->MitCrdWrcActive) insert(items, MITCRDWRCACTIVE);
	if (MitCrdEstActive == comp->MitCrdEstActive) insert(items, MITCRDESTACTIVE);

	return(items);
};

set<uint> CrdWznmVis::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGEXPSTR, JREFDLGIMPSTR, JREFDLGMISSFEAT, JREFDLGNEW, JREFDLGWRITE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDISTAVAIL, MITCRDISTACTIVE, MITCRDCMFAVAIL, MITCRDCMFACTIVE, MITCRDWRCAVAIL, MITCRDWRCACTIVE, MITCRDESTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVis::Tag
 ******************************************************************************/

void CrdWznmVis::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmVis";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["MitCrdIst"] = "Import structure ...";
		me["MitCrdCmf"] = "Complement missing features ...";
		me["MitCrdWrc"] = "Write code ...";
		me["MitCrdEst"] = "Export structure ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...";
	me["MitCrdNew"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::NEW, ixWznmVLocale)) + " ...";
};

void CrdWznmVis::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmVis";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmVis";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdIst", "Import structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCmf", "Complement missing features ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdWrc", "Write code ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdEst", "Export structure ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitCrdNew", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::NEW, ixWznmVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmVis::DpchAppDo
 ******************************************************************************/

CrdWznmVis::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVISDO)
		{
	ixVDo = 0;
};

string CrdWznmVis::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmVis::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmVisDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWznmVis::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVisDo");
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
 class CrdWznmVis::DpchEngData
 ******************************************************************************/

CrdWznmVis::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVISDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWznmVis::DpchEngData::getSrefsMask() {
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

void CrdWznmVis::DpchEngData::merge(
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

void CrdWznmVis::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmVisData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void CrdWznmVis::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmVisData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
