/**
	* \file DlgWznmUsrMngkeypair.cpp
	* API code for job DlgWznmUsrMngkeypair (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmUsrMngkeypair.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmUsrMngkeypair::VecVDo
 ******************************************************************************/

uint DlgWznmUsrMngkeypair::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutdelclick") return DETBUTDELCLICK;
	if (s == "detbutgenclick") return DETBUTGENCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmUsrMngkeypair::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTDELCLICK) return("DetButDelClick");
	if (ix == DETBUTGENCLICK) return("DetButGenClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::VecVSge
 ******************************************************************************/

uint DlgWznmUsrMngkeypair::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nf") return NF;
	if (s == "found") return FOUND;

	return(0);
};

string DlgWznmUsrMngkeypair::VecVSge::getSref(
			const uint ix
		) {
	if (ix == NF) return("nf");
	if (ix == FOUND) return("found");

	return("");
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::ContInf
 ******************************************************************************/

DlgWznmUsrMngkeypair::ContInf::ContInf(
			const uint numFSge
			, const string& DetTxtSte
			, const string& DetDld
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->DetTxtSte = DetTxtSte;
	this->DetDld = DetDld;

	mask = {NUMFSGE, DETTXTSTE, DETDLD};
};

bool DlgWznmUsrMngkeypair::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmUsrMngkeypair";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtSte", DetTxtSte)) add(DETTXTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetDld", DetDld)) add(DETDLD);
	};

	return basefound;
};

set<uint> DlgWznmUsrMngkeypair::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (DetTxtSte == comp->DetTxtSte) insert(items, DETTXTSTE);
	if (DetDld == comp->DetDld) insert(items, DETDLD);

	return(items);
};

set<uint> DlgWznmUsrMngkeypair::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, DETTXTSTE, DETDLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::StatApp
 ******************************************************************************/

DlgWznmUsrMngkeypair::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
		{
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgWznmUsrMngkeypair::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmUsrMngkeypair";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmUsrMngkeypair::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmUsrMngkeypair::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SHORTMENU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::StatShr
 ******************************************************************************/

DlgWznmUsrMngkeypair::StatShr::StatShr(
			const bool DetButDelAvail
			, const bool DetButGenAvail
			, const bool DetDldActive
		) :
			Block()
		{
	this->DetButDelAvail = DetButDelAvail;
	this->DetButGenAvail = DetButGenAvail;
	this->DetDldActive = DetDldActive;

	mask = {DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE};
};

bool DlgWznmUsrMngkeypair::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmUsrMngkeypair";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetButDelAvail", DetButDelAvail)) add(DETBUTDELAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetButGenAvail", DetButGenAvail)) add(DETBUTGENAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetDldActive", DetDldActive)) add(DETDLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmUsrMngkeypair::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButDelAvail == comp->DetButDelAvail) insert(items, DETBUTDELAVAIL);
	if (DetButGenAvail == comp->DetButGenAvail) insert(items, DETBUTGENAVAIL);
	if (DetDldActive == comp->DetDldActive) insert(items, DETDLDACTIVE);

	return(items);
};

set<uint> DlgWznmUsrMngkeypair::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::Tag
 ******************************************************************************/

DlgWznmUsrMngkeypair::Tag::Tag(
			const string& Cpt
			, const string& DetCptSte
			, const string& DetButDel
			, const string& DetButGen
			, const string& DetDld
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->DetCptSte = DetCptSte;
	this->DetButDel = DetButDel;
	this->DetButGen = DetButGen;
	this->DetDld = DetDld;
	this->ButDne = ButDne;

	mask = {CPT, DETCPTSTE, DETBUTDEL, DETBUTGEN, DETDLD, BUTDNE};
};

bool DlgWznmUsrMngkeypair::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmUsrMngkeypair");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmUsrMngkeypair";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptSte", DetCptSte)) add(DETCPTSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButDel", DetButDel)) add(DETBUTDEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButGen", DetButGen)) add(DETBUTGEN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetDld", DetDld)) add(DETDLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::DpchAppDo
 ******************************************************************************/

DlgWznmUsrMngkeypair::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUSRMNGKEYPAIRDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWznmUsrMngkeypair::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUsrMngkeypair::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmUsrMngkeypairDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::DpchEngData
 ******************************************************************************/

DlgWznmUsrMngkeypair::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMUSRMNGKEYPAIRDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string DlgWznmUsrMngkeypair::DpchEngData::getSrefsMask() {
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

void DlgWznmUsrMngkeypair::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmUsrMngkeypairData");
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

