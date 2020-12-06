/**
	* \file DlgWznmVerFinmod.cpp
	* API code for job DlgWznmVerFinmod (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmVerFinmod.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVerFinmod::VecVDo
 ******************************************************************************/

uint DlgWznmVerFinmod::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fnmbutrunclick") return FNMBUTRUNCLICK;
	if (s == "fnmbutstoclick") return FNMBUTSTOCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmVerFinmod::VecVDo::getSref(
			const uint ix
		) {
	if (ix == FNMBUTRUNCLICK) return("FnmButRunClick");
	if (ix == FNMBUTSTOCLICK) return("FnmButStoClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmVerFinmod::VecVSge
 ******************************************************************************/

uint DlgWznmVerFinmod::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "finmod") return FINMOD;
	if (s == "sync") return SYNC;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVerFinmod::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == FINMOD) return("finmod");
	if (ix == SYNC) return("sync");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmVerFinmod::ContInf
 ******************************************************************************/

DlgWznmVerFinmod::ContInf::ContInf(
			const uint numFSge
			, const string& FnmTxtPrg
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->FnmTxtPrg = FnmTxtPrg;

	mask = {NUMFSGE, FNMTXTPRG};
};

bool DlgWznmVerFinmod::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVerFinmod");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVerFinmod";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "FnmTxtPrg", FnmTxtPrg)) add(FNMTXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmVerFinmod::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (FnmTxtPrg == comp->FnmTxtPrg) insert(items, FNMTXTPRG);

	return(items);
};

set<uint> DlgWznmVerFinmod::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, FNMTXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerFinmod::StatApp
 ******************************************************************************/

DlgWznmVerFinmod::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
		{
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgWznmVerFinmod::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmVerFinmod");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmVerFinmod";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmVerFinmod::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmVerFinmod::StatApp::diff(
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
 class DlgWznmVerFinmod::StatShr
 ******************************************************************************/

DlgWznmVerFinmod::StatShr::StatShr(
			const bool FnmButRunActive
			, const bool FnmButStoActive
			, const bool ButDneActive
		) :
			Block()
		{
	this->FnmButRunActive = FnmButRunActive;
	this->FnmButStoActive = FnmButStoActive;
	this->ButDneActive = ButDneActive;

	mask = {FNMBUTRUNACTIVE, FNMBUTSTOACTIVE, BUTDNEACTIVE};
};

bool DlgWznmVerFinmod::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVerFinmod");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVerFinmod";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "FnmButRunActive", FnmButRunActive)) add(FNMBUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "FnmButStoActive", FnmButStoActive)) add(FNMBUTSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVerFinmod::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (FnmButRunActive == comp->FnmButRunActive) insert(items, FNMBUTRUNACTIVE);
	if (FnmButStoActive == comp->FnmButStoActive) insert(items, FNMBUTSTOACTIVE);
	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmVerFinmod::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {FNMBUTRUNACTIVE, FNMBUTSTOACTIVE, BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerFinmod::Tag
 ******************************************************************************/

DlgWznmVerFinmod::Tag::Tag(
			const string& Cpt
			, const string& FnmCptPrg
			, const string& FnmButRun
			, const string& FnmButSto
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->FnmCptPrg = FnmCptPrg;
	this->FnmButRun = FnmButRun;
	this->FnmButSto = FnmButSto;
	this->ButDne = ButDne;

	mask = {CPT, FNMCPTPRG, FNMBUTRUN, FNMBUTSTO, BUTDNE};
};

bool DlgWznmVerFinmod::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVerFinmod");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVerFinmod";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "FnmCptPrg", FnmCptPrg)) add(FNMCPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "FnmButRun", FnmButRun)) add(FNMBUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "FnmButSto", FnmButSto)) add(FNMBUTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVerFinmod::DpchAppDo
 ******************************************************************************/

DlgWznmVerFinmod::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERFINMODDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWznmVerFinmod::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerFinmod::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVerFinmodDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerFinmod::DpchEngData
 ******************************************************************************/

DlgWznmVerFinmod::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVERFINMODDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string DlgWznmVerFinmod::DpchEngData::getSrefsMask() {
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

void DlgWznmVerFinmod::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmVerFinmodData");
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
