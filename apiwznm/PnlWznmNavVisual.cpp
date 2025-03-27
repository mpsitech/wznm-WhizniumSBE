/**
	* \file PnlWznmNavVisual.cpp
	* API code for job PnlWznmNavVisual (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "PnlWznmNavVisual.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavVisual::VecVDo
 ******************************************************************************/

uint PnlWznmNavVisual::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butvisviewclick") return BUTVISVIEWCLICK;
	if (s == "butvisnewcrdclick") return BUTVISNEWCRDCLICK;
	if (s == "butshtviewclick") return BUTSHTVIEWCLICK;
	if (s == "butshtnewcrdclick") return BUTSHTNEWCRDCLICK;
	if (s == "butboxviewclick") return BUTBOXVIEWCLICK;
	if (s == "butboxnewcrdclick") return BUTBOXNEWCRDCLICK;

	return(0);
};

string PnlWznmNavVisual::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTVISVIEWCLICK) return("ButVisViewClick");
	if (ix == BUTVISNEWCRDCLICK) return("ButVisNewcrdClick");
	if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");
	if (ix == BUTSHTNEWCRDCLICK) return("ButShtNewcrdClick");
	if (ix == BUTBOXVIEWCLICK) return("ButBoxViewClick");
	if (ix == BUTBOXNEWCRDCLICK) return("ButBoxNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavVisual::ContIac
 ******************************************************************************/

PnlWznmNavVisual::ContIac::ContIac(
			const uint numFLstVis
			, const uint numFLstSht
			, const uint numFLstBox
		) :
			Block()
			, numFLstVis(numFLstVis)
			, numFLstSht(numFLstSht)
			, numFLstBox(numFLstBox)
		{
	mask = {NUMFLSTVIS, NUMFLSTSHT, NUMFLSTBOX};
};

bool PnlWznmNavVisual::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavVisual");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavVisual";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVis", numFLstVis)) add(NUMFLSTVIS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSht", numFLstSht)) add(NUMFLSTSHT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstBox", numFLstBox)) add(NUMFLSTBOX);
	};

	return basefound;
};

void PnlWznmNavVisual::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavVisual";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavVisual";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstVis", numFLstVis);
		writeUintAttr(wr, itemtag, "sref", "numFLstSht", numFLstSht);
		writeUintAttr(wr, itemtag, "sref", "numFLstBox", numFLstBox);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavVisual::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstVis == comp->numFLstVis) insert(items, NUMFLSTVIS);
	if (numFLstSht == comp->numFLstSht) insert(items, NUMFLSTSHT);
	if (numFLstBox == comp->numFLstBox) insert(items, NUMFLSTBOX);

	return(items);
};

set<uint> PnlWznmNavVisual::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTVIS, NUMFLSTSHT, NUMFLSTBOX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavVisual::StatApp
 ******************************************************************************/

PnlWznmNavVisual::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstVisAlt
			, const bool LstShtAlt
			, const bool LstBoxAlt
			, const uint LstVisNumFirstdisp
			, const uint LstShtNumFirstdisp
			, const uint LstBoxNumFirstdisp
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
			, LstVisAlt(LstVisAlt)
			, LstShtAlt(LstShtAlt)
			, LstBoxAlt(LstBoxAlt)
			, LstVisNumFirstdisp(LstVisNumFirstdisp)
			, LstShtNumFirstdisp(LstShtNumFirstdisp)
			, LstBoxNumFirstdisp(LstBoxNumFirstdisp)
		{
	mask = {IXWZNMVEXPSTATE, LSTVISALT, LSTSHTALT, LSTBOXALT, LSTVISNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTBOXNUMFIRSTDISP};
};

bool PnlWznmNavVisual::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavVisual");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavVisual";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVisAlt", LstVisAlt)) add(LSTVISALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstShtAlt", LstShtAlt)) add(LSTSHTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBoxAlt", LstBoxAlt)) add(LSTBOXALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVisNumFirstdisp", LstVisNumFirstdisp)) add(LSTVISNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstShtNumFirstdisp", LstShtNumFirstdisp)) add(LSTSHTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBoxNumFirstdisp", LstBoxNumFirstdisp)) add(LSTBOXNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavVisual::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstVisAlt == comp->LstVisAlt) insert(items, LSTVISALT);
	if (LstShtAlt == comp->LstShtAlt) insert(items, LSTSHTALT);
	if (LstBoxAlt == comp->LstBoxAlt) insert(items, LSTBOXALT);
	if (LstVisNumFirstdisp == comp->LstVisNumFirstdisp) insert(items, LSTVISNUMFIRSTDISP);
	if (LstShtNumFirstdisp == comp->LstShtNumFirstdisp) insert(items, LSTSHTNUMFIRSTDISP);
	if (LstBoxNumFirstdisp == comp->LstBoxNumFirstdisp) insert(items, LSTBOXNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavVisual::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTVISALT, LSTSHTALT, LSTBOXALT, LSTVISNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTBOXNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavVisual::StatShr
 ******************************************************************************/

PnlWznmNavVisual::StatShr::StatShr(
			const bool LstVisAvail
			, const bool ButVisViewActive
			, const bool LstShtAvail
			, const bool ButShtViewActive
			, const bool ButShtNewcrdActive
			, const bool LstBoxAvail
			, const bool ButBoxViewActive
			, const bool ButBoxNewcrdActive
		) :
			Block()
			, LstVisAvail(LstVisAvail)
			, ButVisViewActive(ButVisViewActive)
			, LstShtAvail(LstShtAvail)
			, ButShtViewActive(ButShtViewActive)
			, ButShtNewcrdActive(ButShtNewcrdActive)
			, LstBoxAvail(LstBoxAvail)
			, ButBoxViewActive(ButBoxViewActive)
			, ButBoxNewcrdActive(ButBoxNewcrdActive)
		{
	mask = {LSTVISAVAIL, BUTVISVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, BUTSHTNEWCRDACTIVE, LSTBOXAVAIL, BUTBOXVIEWACTIVE, BUTBOXNEWCRDACTIVE};
};

bool PnlWznmNavVisual::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavVisual");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavVisual";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVisAvail", LstVisAvail)) add(LSTVISAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVisViewActive", ButVisViewActive)) add(BUTVISVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstShtAvail", LstShtAvail)) add(LSTSHTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButShtViewActive", ButShtViewActive)) add(BUTSHTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButShtNewcrdActive", ButShtNewcrdActive)) add(BUTSHTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBoxAvail", LstBoxAvail)) add(LSTBOXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBoxViewActive", ButBoxViewActive)) add(BUTBOXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBoxNewcrdActive", ButBoxNewcrdActive)) add(BUTBOXNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmNavVisual::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstVisAvail == comp->LstVisAvail) insert(items, LSTVISAVAIL);
	if (ButVisViewActive == comp->ButVisViewActive) insert(items, BUTVISVIEWACTIVE);
	if (LstShtAvail == comp->LstShtAvail) insert(items, LSTSHTAVAIL);
	if (ButShtViewActive == comp->ButShtViewActive) insert(items, BUTSHTVIEWACTIVE);
	if (ButShtNewcrdActive == comp->ButShtNewcrdActive) insert(items, BUTSHTNEWCRDACTIVE);
	if (LstBoxAvail == comp->LstBoxAvail) insert(items, LSTBOXAVAIL);
	if (ButBoxViewActive == comp->ButBoxViewActive) insert(items, BUTBOXVIEWACTIVE);
	if (ButBoxNewcrdActive == comp->ButBoxNewcrdActive) insert(items, BUTBOXNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavVisual::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTVISAVAIL, BUTVISVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, BUTSHTNEWCRDACTIVE, LSTBOXAVAIL, BUTBOXVIEWACTIVE, BUTBOXNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavVisual::Tag
 ******************************************************************************/

PnlWznmNavVisual::Tag::Tag(
			const string& Cpt
			, const string& CptVis
			, const string& CptSht
			, const string& CptBox
		) :
			Block()
			, Cpt(Cpt)
			, CptVis(CptVis)
			, CptSht(CptSht)
			, CptBox(CptBox)
		{
	mask = {CPT, CPTVIS, CPTSHT, CPTBOX};
};

bool PnlWznmNavVisual::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavVisual");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavVisual";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVis", CptVis)) add(CPTVIS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSht", CptSht)) add(CPTSHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBox", CptBox)) add(CPTBOX);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavVisual::DpchAppData
 ******************************************************************************/

PnlWznmNavVisual::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVVISUALDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavVisual::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavVisual::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavVisualData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavVisual::DpchAppDo
 ******************************************************************************/

PnlWznmNavVisual::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVVISUALDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmNavVisual::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavVisual::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavVisualDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavVisual::DpchEngData
 ******************************************************************************/

PnlWznmNavVisual::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVVISUALDATA)
		{
	feedFLstBox.tag = "FeedFLstBox";
	feedFLstSht.tag = "FeedFLstSht";
	feedFLstVis.tag = "FeedFLstVis";
};

string PnlWznmNavVisual::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBOX)) ss.push_back("feedFLstBox");
	if (has(FEEDFLSTSHT)) ss.push_back("feedFLstSht");
	if (has(FEEDFLSTVIS)) ss.push_back("feedFLstVis");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavVisual::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavVisualData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstBox.readXML(docctx, basexpath, true)) add(FEEDFLSTBOX);
		if (feedFLstSht.readXML(docctx, basexpath, true)) add(FEEDFLSTSHT);
		if (feedFLstVis.readXML(docctx, basexpath, true)) add(FEEDFLSTVIS);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstBox.clear();
		feedFLstSht.clear();
		feedFLstVis.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
