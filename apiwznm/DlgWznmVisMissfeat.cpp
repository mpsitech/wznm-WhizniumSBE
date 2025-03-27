/**
	* \file DlgWznmVisMissfeat.cpp
	* API code for job DlgWznmVisMissfeat (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "DlgWznmVisMissfeat.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVisMissfeat::VecVDo
 ******************************************************************************/

uint DlgWznmVisMissfeat::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cmfbutrunclick") return CMFBUTRUNCLICK;
	if (s == "cmfbutstoclick") return CMFBUTSTOCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmVisMissfeat::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CMFBUTRUNCLICK) return("CmfButRunClick");
	if (ix == CMFBUTSTOCLICK) return("CmfButStoClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmVisMissfeat::VecVSge
 ******************************************************************************/

uint DlgWznmVisMissfeat::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "compl") return COMPL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVisMissfeat::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == COMPL) return("compl");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmVisMissfeat::ContInf
 ******************************************************************************/

DlgWznmVisMissfeat::ContInf::ContInf(
			const uint numFSge
			, const string& CmfTxtPrg
		) :
			Block()
			, numFSge(numFSge)
			, CmfTxtPrg(CmfTxtPrg)
		{
	mask = {NUMFSGE, CMFTXTPRG};
};

bool DlgWznmVisMissfeat::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVisMissfeat");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVisMissfeat";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "CmfTxtPrg", CmfTxtPrg)) add(CMFTXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmVisMissfeat::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (CmfTxtPrg == comp->CmfTxtPrg) insert(items, CMFTXTPRG);

	return(items);
};

set<uint> DlgWznmVisMissfeat::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, CMFTXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVisMissfeat::StatApp
 ******************************************************************************/

DlgWznmVisMissfeat::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
			, shortMenu(shortMenu)
		{
	mask = {SHORTMENU};
};

bool DlgWznmVisMissfeat::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmVisMissfeat");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmVisMissfeat";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmVisMissfeat::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmVisMissfeat::StatApp::diff(
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
 class DlgWznmVisMissfeat::StatShr
 ******************************************************************************/

DlgWznmVisMissfeat::StatShr::StatShr(
			const bool CmfButRunActive
			, const bool CmfButStoActive
			, const bool ButDneActive
		) :
			Block()
			, CmfButRunActive(CmfButRunActive)
			, CmfButStoActive(CmfButStoActive)
			, ButDneActive(ButDneActive)
		{
	mask = {CMFBUTRUNACTIVE, CMFBUTSTOACTIVE, BUTDNEACTIVE};
};

bool DlgWznmVisMissfeat::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVisMissfeat");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVisMissfeat";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "CmfButRunActive", CmfButRunActive)) add(CMFBUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "CmfButStoActive", CmfButStoActive)) add(CMFBUTSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVisMissfeat::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (CmfButRunActive == comp->CmfButRunActive) insert(items, CMFBUTRUNACTIVE);
	if (CmfButStoActive == comp->CmfButStoActive) insert(items, CMFBUTSTOACTIVE);
	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmVisMissfeat::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CMFBUTRUNACTIVE, CMFBUTSTOACTIVE, BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVisMissfeat::Tag
 ******************************************************************************/

DlgWznmVisMissfeat::Tag::Tag(
			const string& Cpt
			, const string& CmfCptPrg
			, const string& CmfButRun
			, const string& CmfButSto
			, const string& ButDne
		) :
			Block()
			, Cpt(Cpt)
			, CmfCptPrg(CmfCptPrg)
			, CmfButRun(CmfButRun)
			, CmfButSto(CmfButSto)
			, ButDne(ButDne)
		{
	mask = {CPT, CMFCPTPRG, CMFBUTRUN, CMFBUTSTO, BUTDNE};
};

bool DlgWznmVisMissfeat::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVisMissfeat");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVisMissfeat";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CmfCptPrg", CmfCptPrg)) add(CMFCPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CmfButRun", CmfButRun)) add(CMFBUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CmfButSto", CmfButSto)) add(CMFBUTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVisMissfeat::DpchAppDo
 ******************************************************************************/

DlgWznmVisMissfeat::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVISMISSFEATDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string DlgWznmVisMissfeat::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVisMissfeat::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVisMissfeatDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVisMissfeat::DpchEngData
 ******************************************************************************/

DlgWznmVisMissfeat::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVISMISSFEATDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string DlgWznmVisMissfeat::DpchEngData::getSrefsMask() {
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

void DlgWznmVisMissfeat::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmVisMissfeatData");
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
