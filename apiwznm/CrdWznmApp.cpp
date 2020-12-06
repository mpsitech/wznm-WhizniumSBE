/**
	* \file CrdWznmApp.cpp
	* API code for job CrdWznmApp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWznmApp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmApp::VecVDo
 ******************************************************************************/

uint CrdWznmApp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdistclick") return MITCRDISTCLICK;
	if (s == "mitcrdwrcclick") return MITCRDWRCCLICK;

	return(0);
};

string CrdWznmApp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDISTCLICK) return("MitCrdIstClick");
	if (ix == MITCRDWRCCLICK) return("MitCrdWrcClick");

	return("");
};

/******************************************************************************
 class CrdWznmApp::VecVSge
 ******************************************************************************/

uint CrdWznmApp::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmApp::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

/******************************************************************************
 class CrdWznmApp::ContInf
 ******************************************************************************/

CrdWznmApp::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdApp
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdApp = MtxCrdApp;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDAPP};
};

bool CrdWznmApp::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmApp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmApp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdApp", MtxCrdApp)) add(MTXCRDAPP);
	};

	return basefound;
};

set<uint> CrdWznmApp::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdApp == comp->MtxCrdApp) insert(items, MTXCRDAPP);

	return(items);
};

set<uint> CrdWznmApp::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDAPP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmApp::StatApp
 ******************************************************************************/

CrdWznmApp::StatApp::StatApp(
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

bool CrdWznmApp::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmApp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmApp";

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

set<uint> CrdWznmApp::StatApp::comm(
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

set<uint> CrdWznmApp::StatApp::diff(
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
 class CrdWznmApp::StatShr
 ******************************************************************************/

CrdWznmApp::StatShr::StatShr(
			const string& scrJrefDlgimpstr
			, const string& scrJrefDlgnew
			, const string& scrJrefDlgwrite
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdIstAvail
			, const bool MitCrdIstActive
			, const bool MitCrdWrcAvail
			, const bool MitCrdWrcActive
		) :
			Block()
		{
	this->scrJrefDlgimpstr = scrJrefDlgimpstr;
	this->scrJrefDlgnew = scrJrefDlgnew;
	this->scrJrefDlgwrite = scrJrefDlgwrite;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdIstAvail = MitCrdIstAvail;
	this->MitCrdIstActive = MitCrdIstActive;
	this->MitCrdWrcAvail = MitCrdWrcAvail;
	this->MitCrdWrcActive = MitCrdWrcActive;

	mask = {SCRJREFDLGIMPSTR, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDISTAVAIL, MITCRDISTACTIVE, MITCRDWRCAVAIL, MITCRDWRCACTIVE};
};

bool CrdWznmApp::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmApp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmApp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgimpstr", scrJrefDlgimpstr)) add(SCRJREFDLGIMPSTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrite", scrJrefDlgwrite)) add(SCRJREFDLGWRITE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIstAvail", MitCrdIstAvail)) add(MITCRDISTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIstActive", MitCrdIstActive)) add(MITCRDISTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWrcAvail", MitCrdWrcAvail)) add(MITCRDWRCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWrcActive", MitCrdWrcActive)) add(MITCRDWRCACTIVE);
	};

	return basefound;
};

set<uint> CrdWznmApp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgimpstr == comp->scrJrefDlgimpstr) insert(items, SCRJREFDLGIMPSTR);
	if (scrJrefDlgnew == comp->scrJrefDlgnew) insert(items, SCRJREFDLGNEW);
	if (scrJrefDlgwrite == comp->scrJrefDlgwrite) insert(items, SCRJREFDLGWRITE);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdIstAvail == comp->MitCrdIstAvail) insert(items, MITCRDISTAVAIL);
	if (MitCrdIstActive == comp->MitCrdIstActive) insert(items, MITCRDISTACTIVE);
	if (MitCrdWrcAvail == comp->MitCrdWrcAvail) insert(items, MITCRDWRCAVAIL);
	if (MitCrdWrcActive == comp->MitCrdWrcActive) insert(items, MITCRDWRCACTIVE);

	return(items);
};

set<uint> CrdWznmApp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGIMPSTR, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDISTAVAIL, MITCRDISTACTIVE, MITCRDWRCAVAIL, MITCRDWRCACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmApp::Tag
 ******************************************************************************/

CrdWznmApp::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
			, const string& MitCrdIst
			, const string& MitCrdWrc
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdNew = MitCrdNew;
	this->MitCrdIst = MitCrdIst;
	this->MitCrdWrc = MitCrdWrc;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDIST, MITCRDWRC};
};

bool CrdWznmApp::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmApp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmApp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIst", MitCrdIst)) add(MITCRDIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdWrc", MitCrdWrc)) add(MITCRDWRC);
	};

	return basefound;
};

/******************************************************************************
 class CrdWznmApp::DpchAppDo
 ******************************************************************************/

CrdWznmApp::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMAPPDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWznmApp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmApp::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmAppDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmApp::DpchEngData
 ******************************************************************************/

CrdWznmApp::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMAPPDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWznmApp::DpchEngData::getSrefsMask() {
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

void CrdWznmApp::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmAppData");
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
