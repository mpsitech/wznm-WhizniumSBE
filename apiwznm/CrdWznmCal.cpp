/**
	* \file CrdWznmCal.cpp
	* API code for job CrdWznmCal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "CrdWznmCal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmCal::VecVDo
 ******************************************************************************/

uint CrdWznmCal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;

	return(0);
};

string CrdWznmCal::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");

	return("");
};

/******************************************************************************
 class CrdWznmCal::VecVSge
 ******************************************************************************/

uint CrdWznmCal::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmCal::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

/******************************************************************************
 class CrdWznmCal::ContInf
 ******************************************************************************/

CrdWznmCal::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdCal
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdCal = MtxCrdCal;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDCAL};
};

bool CrdWznmCal::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmCal";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdCal", MtxCrdCal)) add(MTXCRDCAL);
	};

	return basefound;
};

set<uint> CrdWznmCal::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdCal == comp->MtxCrdCal) insert(items, MTXCRDCAL);

	return(items);
};

set<uint> CrdWznmCal::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDCAL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmCal::StatApp
 ******************************************************************************/

CrdWznmCal::StatApp::StatApp(
			const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
		{
	this->ixWznmVReqitmode = ixWznmVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWznmCal::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmCal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVReqitmode", srefIxWznmVReqitmode)) {
			ixWznmVReqitmode = VecWznmVReqitmode::getIx(srefIxWznmVReqitmode);
			add(IXWZNMVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdWznmCal::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVReqitmode == comp->ixWznmVReqitmode) insert(items, IXWZNMVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdWznmCal::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmCal::StatShr
 ******************************************************************************/

CrdWznmCal::StatShr::StatShr(
			const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
		) :
			Block()
		{
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;

	mask = {SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC};
};

bool CrdWznmCal::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmCal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
	};

	return basefound;
};

set<uint> CrdWznmCal::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);

	return(items);
};

set<uint> CrdWznmCal::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmCal::Tag
 ******************************************************************************/

CrdWznmCal::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;

	mask = {MITAPPABT, MRLAPPHLP};
};

bool CrdWznmCal::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmCal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmCal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
	};

	return basefound;
};

/******************************************************************************
 class CrdWznmCal::DpchAppDo
 ******************************************************************************/

CrdWznmCal::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCALDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWznmCal::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmCal::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmCalDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmCal::DpchEngData
 ******************************************************************************/

CrdWznmCal::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCALDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWznmCal::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmCal::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmCalData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
