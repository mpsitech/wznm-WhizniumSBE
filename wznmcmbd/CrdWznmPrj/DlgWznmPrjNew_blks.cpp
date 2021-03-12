/**
	* \file DlgWznmPrjNew_blks.cpp
	* job handler for job DlgWznmPrjNew (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmPrjNew::VecVDo
 ******************************************************************************/

uint DlgWznmPrjNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutautclick") return DETBUTAUTCLICK;
	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWznmPrjNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTAUTCLICK) return("DetButAutClick");
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWznmPrjNew::VecVSge
 ******************************************************************************/

uint DlgWznmPrjNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alraer") return ALRAER;
	if (s == "auth") return AUTH;
	if (s == "autdone") return AUTDONE;
	if (s == "create") return CREATE;
	if (s == "sync") return SYNC;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmPrjNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRAER) return("alraer");
	if (ix == AUTH) return("auth");
	if (ix == AUTDONE) return("autdone");
	if (ix == CREATE) return("create");
	if (ix == SYNC) return("sync");
	if (ix == DONE) return("done");

	return("");
};

void DlgWznmPrjNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmPrjNew::ContIac
 ******************************************************************************/

DlgWznmPrjNew::ContIac::ContIac(
			const string& DetTxfSho
			, const string& DetTxfTit
			, const string& DetTxfAbt
			, const vector<uint>& numsFDetLstDty
			, const vector<uint>& numsFDetLstLoc
			, const uint numFDetPupPlc
			, const uint numFDetPupPmc
		) :
			Block()
		{
	this->DetTxfSho = DetTxfSho;
	this->DetTxfTit = DetTxfTit;
	this->DetTxfAbt = DetTxfAbt;
	this->numsFDetLstDty = numsFDetLstDty;
	this->numsFDetLstLoc = numsFDetLstLoc;
	this->numFDetPupPlc = numFDetPupPlc;
	this->numFDetPupPmc = numFDetPupPmc;

	mask = {DETTXFSHO, DETTXFTIT, DETTXFABT, NUMSFDETLSTDTY, NUMSFDETLSTLOC, NUMFDETPUPPLC, NUMFDETPUPPMC};
};

bool DlgWznmPrjNew::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacDlgWznmPrjNew"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("DetTxfSho")) {DetTxfSho = me["DetTxfSho"].asString(); add(DETTXFSHO);};
		if (me.isMember("DetTxfTit")) {DetTxfTit = me["DetTxfTit"].asString(); add(DETTXFTIT);};
		if (me.isMember("DetTxfAbt")) {DetTxfAbt = me["DetTxfAbt"].asString(); add(DETTXFABT);};
		if (Jsonio::extractUintvec(me, "numsFDetLstDty", numsFDetLstDty)) add(NUMSFDETLSTDTY);
		if (Jsonio::extractUintvec(me, "numsFDetLstLoc", numsFDetLstLoc)) add(NUMSFDETLSTLOC);
		if (me.isMember("numFDetPupPlc")) {numFDetPupPlc = me["numFDetPupPlc"].asUInt(); add(NUMFDETPUPPLC);};
		if (me.isMember("numFDetPupPmc")) {numFDetPupPmc = me["numFDetPupPmc"].asUInt(); add(NUMFDETPUPPMC);};
	};

	return basefound;
};

bool DlgWznmPrjNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmPrjNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmPrjNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfSho", DetTxfSho)) add(DETTXFSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfTit", DetTxfTit)) add(DETTXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfAbt", DetTxfAbt)) add(DETTXFABT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFDetLstDty", numsFDetLstDty)) add(NUMSFDETLSTDTY);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFDetLstLoc", numsFDetLstLoc)) add(NUMSFDETLSTLOC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupPlc", numFDetPupPlc)) add(NUMFDETPUPPLC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupPmc", numFDetPupPmc)) add(NUMFDETPUPPMC);
	};

	return basefound;
};

void DlgWznmPrjNew::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmPrjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["DetTxfSho"] = DetTxfSho;
	me["DetTxfTit"] = DetTxfTit;
	me["DetTxfAbt"] = DetTxfAbt;
	Jsonio::writeUintvec(me, "numsFDetLstDty", numsFDetLstDty);
	Jsonio::writeUintvec(me, "numsFDetLstLoc", numsFDetLstLoc);
	me["numFDetPupPlc"] = numFDetPupPlc;
	me["numFDetPupPmc"] = numFDetPupPmc;
};

void DlgWznmPrjNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmPrjNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmPrjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "DetTxfSho", DetTxfSho);
		writeStringAttr(wr, itemtag, "sref", "DetTxfTit", DetTxfTit);
		writeStringAttr(wr, itemtag, "sref", "DetTxfAbt", DetTxfAbt);
		writeUintvecAttr(wr, itemtag, "sref", "numsFDetLstDty", numsFDetLstDty);
		writeUintvecAttr(wr, itemtag, "sref", "numsFDetLstLoc", numsFDetLstLoc);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupPlc", numFDetPupPlc);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupPmc", numFDetPupPmc);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmPrjNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (DetTxfSho == comp->DetTxfSho) insert(items, DETTXFSHO);
	if (DetTxfTit == comp->DetTxfTit) insert(items, DETTXFTIT);
	if (DetTxfAbt == comp->DetTxfAbt) insert(items, DETTXFABT);
	if (compareUintvec(numsFDetLstDty, comp->numsFDetLstDty)) insert(items, NUMSFDETLSTDTY);
	if (compareUintvec(numsFDetLstLoc, comp->numsFDetLstLoc)) insert(items, NUMSFDETLSTLOC);
	if (numFDetPupPlc == comp->numFDetPupPlc) insert(items, NUMFDETPUPPLC);
	if (numFDetPupPmc == comp->numFDetPupPmc) insert(items, NUMFDETPUPPMC);

	return(items);
};

set<uint> DlgWznmPrjNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETTXFSHO, DETTXFTIT, DETTXFABT, NUMSFDETLSTDTY, NUMSFDETLSTLOC, NUMFDETPUPPLC, NUMFDETPUPPMC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmPrjNew::ContInf
 ******************************************************************************/

DlgWznmPrjNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWznmPrjNew::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmPrjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = numFSge;
};

void DlgWznmPrjNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmPrjNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmPrjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmPrjNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmPrjNew::ContInf::diff(
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
 class DlgWznmPrjNew::StatApp
 ******************************************************************************/

void DlgWznmPrjNew::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const string& shortMenu
			, const uint DetLstDtyNumFirstdisp
			, const uint DetLstLocNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmPrjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["shortMenu"] = shortMenu;
	me["DetLstDtyNumFirstdisp"] = DetLstDtyNumFirstdisp;
	me["DetLstLocNumFirstdisp"] = DetLstLocNumFirstdisp;
};

void DlgWznmPrjNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
			, const uint DetLstDtyNumFirstdisp
			, const uint DetLstLocNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmPrjNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmPrjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "DetLstDtyNumFirstdisp", DetLstDtyNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "DetLstLocNumFirstdisp", DetLstLocNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmPrjNew::StatShr
 ******************************************************************************/

DlgWznmPrjNew::StatShr::StatShr(
			const bool DetButAutActive
			, const bool ButCncActive
			, const bool ButCreActive
		) :
			Block()
		{
	this->DetButAutActive = DetButAutActive;
	this->ButCncActive = ButCncActive;
	this->ButCreActive = ButCreActive;

	mask = {DETBUTAUTACTIVE, BUTCNCACTIVE, BUTCREACTIVE};
};

void DlgWznmPrjNew::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmPrjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["DetButAutActive"] = DetButAutActive;
	me["ButCncActive"] = ButCncActive;
	me["ButCreActive"] = ButCreActive;
};

void DlgWznmPrjNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmPrjNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmPrjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DetButAutActive", DetButAutActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCncActive", ButCncActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmPrjNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButAutActive == comp->DetButAutActive) insert(items, DETBUTAUTACTIVE);
	if (ButCncActive == comp->ButCncActive) insert(items, BUTCNCACTIVE);
	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWznmPrjNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTAUTACTIVE, BUTCNCACTIVE, BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmPrjNew::Tag
 ******************************************************************************/

void DlgWznmPrjNew::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmPrjNew";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Create new project";
		me["DetCptSho"] = "Acronym";
		me["DetCptTit"] = "Name";
		me["DetCptAbt"] = "About";
		me["DetCptDty"] = "DBMS types";
		me["DetCptLoc"] = "Locales";
		me["DetCptPlc"] = "Primary locale";
		me["DetCptTmc"] = "Target machine";
		me["DetButAut"] = "Authenticate";
	};
	me["ButCnc"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CANCEL, ixWznmVLocale));
	me["ButCre"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CREATE, ixWznmVLocale));
};

void DlgWznmPrjNew::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmPrjNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmPrjNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Create new project");
			writeStringAttr(wr, itemtag, "sref", "DetCptSho", "Acronym");
			writeStringAttr(wr, itemtag, "sref", "DetCptTit", "Name");
			writeStringAttr(wr, itemtag, "sref", "DetCptAbt", "About");
			writeStringAttr(wr, itemtag, "sref", "DetCptDty", "DBMS types");
			writeStringAttr(wr, itemtag, "sref", "DetCptLoc", "Locales");
			writeStringAttr(wr, itemtag, "sref", "DetCptPlc", "Primary locale");
			writeStringAttr(wr, itemtag, "sref", "DetCptTmc", "Target machine");
			writeStringAttr(wr, itemtag, "sref", "DetButAut", "Authenticate");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCnc", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CANCEL, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CREATE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmPrjNew::DpchAppData
 ******************************************************************************/

DlgWznmPrjNew::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMPRJNEWDATA)
		{
};

string DlgWznmPrjNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmPrjNew::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWznmPrjNewData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void DlgWznmPrjNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmPrjNewData");
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
 class DlgWznmPrjNew::DpchAppDo
 ******************************************************************************/

DlgWznmPrjNew::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMPRJNEWDO)
		{
	ixVDo = 0;
};

string DlgWznmPrjNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmPrjNew::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppDlgWznmPrjNewDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void DlgWznmPrjNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmPrjNewDo");
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
 class DlgWznmPrjNew::DpchEngData
 ******************************************************************************/

DlgWznmPrjNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFDetLstDty
			, Feed* feedFDetLstLoc
			, Feed* feedFDetPupPlc
			, Feed* feedFDetPupPmc
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMPRJNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFDETLSTDTY, FEEDFDETLSTLOC, FEEDFDETPUPPLC, FEEDFDETPUPPMC, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETLSTDTY) && feedFDetLstDty) this->feedFDetLstDty = *feedFDetLstDty;
	if (find(this->mask, FEEDFDETLSTLOC) && feedFDetLstLoc) this->feedFDetLstLoc = *feedFDetLstLoc;
	if (find(this->mask, FEEDFDETPUPPLC) && feedFDetPupPlc) this->feedFDetPupPlc = *feedFDetPupPlc;
	if (find(this->mask, FEEDFDETPUPPMC) && feedFDetPupPmc) this->feedFDetPupPmc = *feedFDetPupPmc;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWznmPrjNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETLSTDTY)) ss.push_back("feedFDetLstDty");
	if (has(FEEDFDETLSTLOC)) ss.push_back("feedFDetLstLoc");
	if (has(FEEDFDETPUPPLC)) ss.push_back("feedFDetPupPlc");
	if (has(FEEDFDETPUPPMC)) ss.push_back("feedFDetPupPmc");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmPrjNew::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETLSTDTY)) {feedFDetLstDty = src->feedFDetLstDty; add(FEEDFDETLSTDTY);};
	if (src->has(FEEDFDETLSTLOC)) {feedFDetLstLoc = src->feedFDetLstLoc; add(FEEDFDETLSTLOC);};
	if (src->has(FEEDFDETPUPPLC)) {feedFDetPupPlc = src->feedFDetPupPlc; add(FEEDFDETPUPPLC);};
	if (src->has(FEEDFDETPUPPMC)) {feedFDetPupPmc = src->feedFDetPupPmc; add(FEEDFDETPUPPMC);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWznmPrjNew::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngDlgWznmPrjNewData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFDETLSTDTY)) feedFDetLstDty.writeJSON(me);
	if (has(FEEDFDETLSTLOC)) feedFDetLstLoc.writeJSON(me);
	if (has(FEEDFDETPUPPLC)) feedFDetPupPlc.writeJSON(me);
	if (has(FEEDFDETPUPPMC)) feedFDetPupPmc.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void DlgWznmPrjNew::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmPrjNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETLSTDTY)) feedFDetLstDty.writeXML(wr);
		if (has(FEEDFDETLSTLOC)) feedFDetLstLoc.writeXML(wr);
		if (has(FEEDFDETPUPPLC)) feedFDetPupPlc.writeXML(wr);
		if (has(FEEDFDETPUPPMC)) feedFDetPupPmc.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
