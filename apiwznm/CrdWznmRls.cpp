/**
	* \file CrdWznmRls.cpp
	* API code for job CrdWznmRls (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "CrdWznmRls.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmRls::VecVDo
 ******************************************************************************/

uint CrdWznmRls::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdsrtclick") return MITCRDSRTCLICK;
	if (s == "mitcrdcrtclick") return MITCRDCRTCLICK;
	if (s == "mitcrdfrtclick") return MITCRDFRTCLICK;
	if (s == "mitcrdwcoclick") return MITCRDWCOCLICK;

	return(0);
};

string CrdWznmRls::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDSRTCLICK) return("MitCrdSrtClick");
	if (ix == MITCRDCRTCLICK) return("MitCrdCrtClick");
	if (ix == MITCRDFRTCLICK) return("MitCrdFrtClick");
	if (ix == MITCRDWCOCLICK) return("MitCrdWcoClick");

	return("");
};

/******************************************************************************
 class CrdWznmRls::VecVSge
 ******************************************************************************/

uint CrdWznmRls::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmRls::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

/******************************************************************************
 class CrdWznmRls::ContInf
 ******************************************************************************/

CrdWznmRls::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdRls
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdRls = MtxCrdRls;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
};

bool CrdWznmRls::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmRls";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdRls", MtxCrdRls)) add(MTXCRDRLS);
	};

	return basefound;
};

set<uint> CrdWznmRls::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdRls == comp->MtxCrdRls) insert(items, MTXCRDRLS);

	return(items);
};

set<uint> CrdWznmRls::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmRls::StatApp
 ******************************************************************************/

CrdWznmRls::StatApp::StatApp(
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

bool CrdWznmRls::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmRls";

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

set<uint> CrdWznmRls::StatApp::comm(
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

set<uint> CrdWznmRls::StatApp::diff(
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
 class CrdWznmRls::StatShr
 ******************************************************************************/

CrdWznmRls::StatShr::StatShr(
			const string& scrJrefDlgfinreptr
			, const string& scrJrefDlgstareptr
			, const string& scrJrefDlgwrite
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdSrtAvail
			, const bool MitCrdSrtActive
			, const bool MitCrdCrtAvail
			, const bool MitCrdCrtActive
			, const bool MitCrdFrtAvail
			, const bool MitCrdFrtActive
			, const bool MitCrdWcoAvail
			, const bool MitCrdWcoActive
		) :
			Block()
		{
	this->scrJrefDlgfinreptr = scrJrefDlgfinreptr;
	this->scrJrefDlgstareptr = scrJrefDlgstareptr;
	this->scrJrefDlgwrite = scrJrefDlgwrite;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdSrtAvail = MitCrdSrtAvail;
	this->MitCrdSrtActive = MitCrdSrtActive;
	this->MitCrdCrtAvail = MitCrdCrtAvail;
	this->MitCrdCrtActive = MitCrdCrtActive;
	this->MitCrdFrtAvail = MitCrdFrtAvail;
	this->MitCrdFrtActive = MitCrdFrtActive;
	this->MitCrdWcoAvail = MitCrdWcoAvail;
	this->MitCrdWcoActive = MitCrdWcoActive;

	mask = {SCRJREFDLGFINREPTR, SCRJREFDLGSTAREPTR, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
};

bool CrdWznmRls::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmRls";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgfinreptr", scrJrefDlgfinreptr)) add(SCRJREFDLGFINREPTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgstareptr", scrJrefDlgstareptr)) add(SCRJREFDLGSTAREPTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrite", scrJrefDlgwrite)) add(SCRJREFDLGWRITE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSrtAvail", MitCrdSrtAvail)) add(MITCRDSRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSrtActive", MitCrdSrtActive)) add(MITCRDSRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCrtAvail", MitCrdCrtAvail)) add(MITCRDCRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCrtActive", MitCrdCrtActive)) add(MITCRDCRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFrtAvail", MitCrdFrtAvail)) add(MITCRDFRTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFrtActive", MitCrdFrtActive)) add(MITCRDFRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWcoAvail", MitCrdWcoAvail)) add(MITCRDWCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWcoActive", MitCrdWcoActive)) add(MITCRDWCOACTIVE);
	};

	return basefound;
};

set<uint> CrdWznmRls::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgfinreptr == comp->scrJrefDlgfinreptr) insert(items, SCRJREFDLGFINREPTR);
	if (scrJrefDlgstareptr == comp->scrJrefDlgstareptr) insert(items, SCRJREFDLGSTAREPTR);
	if (scrJrefDlgwrite == comp->scrJrefDlgwrite) insert(items, SCRJREFDLGWRITE);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdSrtAvail == comp->MitCrdSrtAvail) insert(items, MITCRDSRTAVAIL);
	if (MitCrdSrtActive == comp->MitCrdSrtActive) insert(items, MITCRDSRTACTIVE);
	if (MitCrdCrtAvail == comp->MitCrdCrtAvail) insert(items, MITCRDCRTAVAIL);
	if (MitCrdCrtActive == comp->MitCrdCrtActive) insert(items, MITCRDCRTACTIVE);
	if (MitCrdFrtAvail == comp->MitCrdFrtAvail) insert(items, MITCRDFRTAVAIL);
	if (MitCrdFrtActive == comp->MitCrdFrtActive) insert(items, MITCRDFRTACTIVE);
	if (MitCrdWcoAvail == comp->MitCrdWcoAvail) insert(items, MITCRDWCOAVAIL);
	if (MitCrdWcoActive == comp->MitCrdWcoActive) insert(items, MITCRDWCOACTIVE);

	return(items);
};

set<uint> CrdWznmRls::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGFINREPTR, SCRJREFDLGSTAREPTR, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmRls::Tag
 ******************************************************************************/

CrdWznmRls::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdSrt
			, const string& MitCrdCrt
			, const string& MitCrdFrt
			, const string& MitCrdWco
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdSrt = MitCrdSrt;
	this->MitCrdCrt = MitCrdCrt;
	this->MitCrdFrt = MitCrdFrt;
	this->MitCrdWco = MitCrdWco;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDSRT, MITCRDCRT, MITCRDFRT, MITCRDWCO};
};

bool CrdWznmRls::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmRls");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmRls";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSrt", MitCrdSrt)) add(MITCRDSRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCrt", MitCrdCrt)) add(MITCRDCRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFrt", MitCrdFrt)) add(MITCRDFRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdWco", MitCrdWco)) add(MITCRDWCO);
	};

	return basefound;
};

/******************************************************************************
 class CrdWznmRls::DpchAppDo
 ******************************************************************************/

CrdWznmRls::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRLSDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWznmRls::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmRls::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmRlsDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmRls::DpchEngData
 ******************************************************************************/

CrdWznmRls::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRLSDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWznmRls::DpchEngData::getSrefsMask() {
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

void CrdWznmRls::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmRlsData");
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

