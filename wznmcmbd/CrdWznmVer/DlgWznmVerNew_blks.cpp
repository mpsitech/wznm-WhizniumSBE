/**
	* \file DlgWznmVerNew_blks.cpp
	* job handler for job DlgWznmVerNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVerNew::VecVDo
 ******************************************************************************/

uint DlgWznmVerNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWznmVerNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWznmVerNew::VecVSge
 ******************************************************************************/

uint DlgWznmVerNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVerNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

void DlgWznmVerNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmVerNew::VecVVni
 ******************************************************************************/

uint DlgWznmVerNew::VecVVni::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "maj") return MAJ;
	if (s == "min") return MIN;
	if (s == "sub") return SUB;
	if (s == "void") return VOID;

	return(0);
};

string DlgWznmVerNew::VecVVni::getSref(
			const uint ix
		) {
	if (ix == MAJ) return("maj");
	if (ix == MIN) return("min");
	if (ix == SUB) return("sub");
	if (ix == VOID) return("void");

	return("");
};

string DlgWznmVerNew::VecVVni::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == MAJ) return("major");
		if (ix == MIN) return("minor");
		if (ix == SUB) return("sub");
		if (ix == VOID) return("none");
		return(getSref(ix));
	};

	return("");
};

void DlgWznmVerNew::VecVVni::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DlgWznmVerNew::ContIac
 ******************************************************************************/

DlgWznmVerNew::ContIac::ContIac(
			const uint numFDetPupPrj
			, const uint numFDetPupBvr
			, const uint numFDetRbuVni
			, const string& DetTxfCmt
			, const vector<uint>& numsFDetLstLoc
			, const uint numFDetPupPlc
		) :
			Block()
		{
	this->numFDetPupPrj = numFDetPupPrj;
	this->numFDetPupBvr = numFDetPupBvr;
	this->numFDetRbuVni = numFDetRbuVni;
	this->DetTxfCmt = DetTxfCmt;
	this->numsFDetLstLoc = numsFDetLstLoc;
	this->numFDetPupPlc = numFDetPupPlc;

	mask = {NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT, NUMSFDETLSTLOC, NUMFDETPUPPLC};
};

bool DlgWznmVerNew::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacDlgWznmVerNew"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFDetPupPrj")) {numFDetPupPrj = me["numFDetPupPrj"].asUInt(); add(NUMFDETPUPPRJ);};
		if (me.isMember("numFDetPupBvr")) {numFDetPupBvr = me["numFDetPupBvr"].asUInt(); add(NUMFDETPUPBVR);};
		if (me.isMember("numFDetRbuVni")) {numFDetRbuVni = me["numFDetRbuVni"].asUInt(); add(NUMFDETRBUVNI);};
		if (me.isMember("DetTxfCmt")) {DetTxfCmt = me["DetTxfCmt"].asString(); add(DETTXFCMT);};
		if (Jsonio::extractUintvec(me, "numsFDetLstLoc", numsFDetLstLoc)) add(NUMSFDETLSTLOC);
		if (me.isMember("numFDetPupPlc")) {numFDetPupPlc = me["numFDetPupPlc"].asUInt(); add(NUMFDETPUPPLC);};
	};

	return basefound;
};

bool DlgWznmVerNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmVerNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupPrj", numFDetPupPrj)) add(NUMFDETPUPPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupBvr", numFDetPupBvr)) add(NUMFDETPUPBVR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetRbuVni", numFDetRbuVni)) add(NUMFDETRBUVNI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfCmt", DetTxfCmt)) add(DETTXFCMT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFDetLstLoc", numsFDetLstLoc)) add(NUMSFDETLSTLOC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupPlc", numFDetPupPlc)) add(NUMFDETPUPPLC);
	};

	return basefound;
};

void DlgWznmVerNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFDetPupPrj"] = numFDetPupPrj;
	me["numFDetPupBvr"] = numFDetPupBvr;
	me["numFDetRbuVni"] = numFDetRbuVni;
	me["DetTxfCmt"] = DetTxfCmt;
	Jsonio::writeUintvec(me, "numsFDetLstLoc", numsFDetLstLoc);
	me["numFDetPupPlc"] = numFDetPupPlc;
};

void DlgWznmVerNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmVerNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupPrj", numFDetPupPrj);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupBvr", numFDetPupBvr);
		writeUintAttr(wr, itemtag, "sref", "numFDetRbuVni", numFDetRbuVni);
		writeStringAttr(wr, itemtag, "sref", "DetTxfCmt", DetTxfCmt);
		writeUintvecAttr(wr, itemtag, "sref", "numsFDetLstLoc", numsFDetLstLoc);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupPlc", numFDetPupPlc);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupPrj == comp->numFDetPupPrj) insert(items, NUMFDETPUPPRJ);
	if (numFDetPupBvr == comp->numFDetPupBvr) insert(items, NUMFDETPUPBVR);
	if (numFDetRbuVni == comp->numFDetRbuVni) insert(items, NUMFDETRBUVNI);
	if (DetTxfCmt == comp->DetTxfCmt) insert(items, DETTXFCMT);
	if (compareUintvec(numsFDetLstLoc, comp->numsFDetLstLoc)) insert(items, NUMSFDETLSTLOC);
	if (numFDetPupPlc == comp->numFDetPupPlc) insert(items, NUMFDETPUPPLC);

	return(items);
};

set<uint> DlgWznmVerNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT, NUMSFDETLSTLOC, NUMFDETPUPPLC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerNew::ContInf
 ******************************************************************************/

DlgWznmVerNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWznmVerNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgWznmVerNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmVerNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmVerNew::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerNew::StatApp
 ******************************************************************************/

void DlgWznmVerNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
			, const uint DetLstLocNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
	me["DetLstLocNumFirstdisp"] = DetLstLocNumFirstdisp;
};

void DlgWznmVerNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
			, const uint DetLstLocNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmVerNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "DetLstLocNumFirstdisp", DetLstLocNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerNew::StatShr
 ******************************************************************************/

DlgWznmVerNew::StatShr::StatShr(
			const bool ButCreActive
		) :
			Block()
		{
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

void DlgWznmVerNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButCreActive"] = ButCreActive;
};

void DlgWznmVerNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmVerNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWznmVerNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerNew::Tag
 ******************************************************************************/

void DlgWznmVerNew::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmVerNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Create new version";
		me["DetCptPrj"] = "Project";
		me["DetCptBvr"] = "Base version";
		me["DetCptVni"] = "Version number increment";
		me["DetCptCmt"] = "Comment";
		me["DetCptLoc"] = "Locales";
		me["DetCptPlc"] = "Primary locale";
	};
	me["ButCnc"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CANCEL, ixWznmVLocale));
	me["ButCre"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CREATE, ixWznmVLocale));
};

void DlgWznmVerNew::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmVerNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new version");
			writeStringAttr(wr, itemtag, "sref", "DetCptPrj", "Project");
			writeStringAttr(wr, itemtag, "sref", "DetCptBvr", "Base version");
			writeStringAttr(wr, itemtag, "sref", "DetCptVni", "Version number increment");
			writeStringAttr(wr, itemtag, "sref", "DetCptCmt", "Comment");
			writeStringAttr(wr, itemtag, "sref", "DetCptLoc", "Locales");
			writeStringAttr(wr, itemtag, "sref", "DetCptPlc", "Primary locale");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCnc", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CANCEL, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CREATE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerNew::DpchAppData
 ******************************************************************************/

DlgWznmVerNew::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDATA)
		{
};

string DlgWznmVerNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerNew::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWznmVerNewData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWznmVerNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmVerNewData");
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
 class DlgWznmVerNew::DpchAppDo
 ******************************************************************************/

DlgWznmVerNew::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDO)
		{
	ixVDo = 0;
};

string DlgWznmVerNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerNew::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWznmVerNewDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWznmVerNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmVerNewDo");
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
 class DlgWznmVerNew::DpchEngData
 ******************************************************************************/

DlgWznmVerNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFDetLstLoc
			, Feed* feedFDetPupBvr
			, Feed* feedFDetPupPlc
			, Feed* feedFDetPupPrj
			, Feed* feedFDetRbuVni
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVERNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFDETLSTLOC, FEEDFDETPUPBVR, FEEDFDETPUPPLC, FEEDFDETPUPPRJ, FEEDFDETRBUVNI, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETLSTLOC) && feedFDetLstLoc) this->feedFDetLstLoc = *feedFDetLstLoc;
	if (find(this->mask, FEEDFDETPUPBVR) && feedFDetPupBvr) this->feedFDetPupBvr = *feedFDetPupBvr;
	if (find(this->mask, FEEDFDETPUPPLC) && feedFDetPupPlc) this->feedFDetPupPlc = *feedFDetPupPlc;
	if (find(this->mask, FEEDFDETPUPPRJ) && feedFDetPupPrj) this->feedFDetPupPrj = *feedFDetPupPrj;
	if (find(this->mask, FEEDFDETRBUVNI) && feedFDetRbuVni) this->feedFDetRbuVni = *feedFDetRbuVni;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWznmVerNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETLSTLOC)) ss.push_back("feedFDetLstLoc");
	if (has(FEEDFDETPUPBVR)) ss.push_back("feedFDetPupBvr");
	if (has(FEEDFDETPUPPLC)) ss.push_back("feedFDetPupPlc");
	if (has(FEEDFDETPUPPRJ)) ss.push_back("feedFDetPupPrj");
	if (has(FEEDFDETRBUVNI)) ss.push_back("feedFDetRbuVni");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerNew::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETLSTLOC)) {feedFDetLstLoc = src->feedFDetLstLoc; add(FEEDFDETLSTLOC);};
	if (src->has(FEEDFDETPUPBVR)) {feedFDetPupBvr = src->feedFDetPupBvr; add(FEEDFDETPUPBVR);};
	if (src->has(FEEDFDETPUPPLC)) {feedFDetPupPlc = src->feedFDetPupPlc; add(FEEDFDETPUPPLC);};
	if (src->has(FEEDFDETPUPPRJ)) {feedFDetPupPrj = src->feedFDetPupPrj; add(FEEDFDETPUPPRJ);};
	if (src->has(FEEDFDETRBUVNI)) {feedFDetRbuVni = src->feedFDetRbuVni; add(FEEDFDETRBUVNI);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWznmVerNew::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWznmVerNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETLSTLOC)) feedFDetLstLoc.writeJSON(me);
	if (has(FEEDFDETPUPBVR)) feedFDetPupBvr.writeJSON(me);
	if (has(FEEDFDETPUPPLC)) feedFDetPupPlc.writeJSON(me);
	if (has(FEEDFDETPUPPRJ)) feedFDetPupPrj.writeJSON(me);
	if (has(FEEDFDETRBUVNI)) feedFDetRbuVni.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void DlgWznmVerNew::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmVerNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETLSTLOC)) feedFDetLstLoc.writeXML(wr);
		if (has(FEEDFDETPUPBVR)) feedFDetPupBvr.writeXML(wr);
		if (has(FEEDFDETPUPPLC)) feedFDetPupPlc.writeXML(wr);
		if (has(FEEDFDETPUPPRJ)) feedFDetPupPrj.writeXML(wr);
		if (has(FEEDFDETRBUVNI)) feedFDetRbuVni.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
