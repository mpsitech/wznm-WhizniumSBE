/**
	* \file PnlWznmNavPre.cpp
	* API code for job PnlWznmNavPre (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmNavPre.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavPre::VecVDo
 ******************************************************************************/

uint PnlWznmNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butappremoveclick") return BUTAPPREMOVECLICK;
	if (s == "butverremoveclick") return BUTVERREMOVECLICK;
	if (s == "butvisremoveclick") return BUTVISREMOVECLICK;

	return(0);
};

string PnlWznmNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTAPPREMOVECLICK) return("ButAppRemoveClick");
	if (ix == BUTVERREMOVECLICK) return("ButVerRemoveClick");
	if (ix == BUTVISREMOVECLICK) return("ButVisRemoveClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavPre::ContInf
 ******************************************************************************/

PnlWznmNavPre::ContInf::ContInf(
			const string& TxtApp
			, const string& TxtVer
			, const string& TxtVis
		) :
			Block()
			, TxtApp(TxtApp)
			, TxtVer(TxtVer)
			, TxtVis(TxtVis)
		{
	mask = {TXTAPP, TXTVER, TXTVIS};
};

bool PnlWznmNavPre::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtApp", TxtApp)) add(TXTAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVis", TxtVis)) add(TXTVIS);
	};

	return basefound;
};

set<uint> PnlWznmNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtApp == comp->TxtApp) insert(items, TXTAPP);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtVis == comp->TxtVis) insert(items, TXTVIS);

	return(items);
};

set<uint> PnlWznmNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTAPP, TXTVER, TXTVIS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavPre::StatShr
 ******************************************************************************/

PnlWznmNavPre::StatShr::StatShr(
			const bool TxtAppAvail
			, const bool TxtVerAvail
			, const bool TxtVisAvail
		) :
			Block()
			, TxtAppAvail(TxtAppAvail)
			, TxtVerAvail(TxtVerAvail)
			, TxtVisAvail(TxtVisAvail)
		{
	mask = {TXTAPPAVAIL, TXTVERAVAIL, TXTVISAVAIL};
};

bool PnlWznmNavPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavPre";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtAppAvail", TxtAppAvail)) add(TXTAPPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerAvail", TxtVerAvail)) add(TXTVERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVisAvail", TxtVisAvail)) add(TXTVISAVAIL);
	};

	return basefound;
};

set<uint> PnlWznmNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtAppAvail == comp->TxtAppAvail) insert(items, TXTAPPAVAIL);
	if (TxtVerAvail == comp->TxtVerAvail) insert(items, TXTVERAVAIL);
	if (TxtVisAvail == comp->TxtVisAvail) insert(items, TXTVISAVAIL);

	return(items);
};

set<uint> PnlWznmNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTAPPAVAIL, TXTVERAVAIL, TXTVISAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavPre::Tag
 ******************************************************************************/

PnlWznmNavPre::Tag::Tag(
			const string& CptApp
			, const string& CptVer
			, const string& CptVis
		) :
			Block()
			, CptApp(CptApp)
			, CptVer(CptVer)
			, CptVis(CptVis)
		{
	mask = {CPTAPP, CPTVER, CPTVIS};
};

bool PnlWznmNavPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptApp", CptApp)) add(CPTAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVis", CptVis)) add(CPTVIS);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavPre::DpchAppDo
 ******************************************************************************/

PnlWznmNavPre::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVPREDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavPre::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavPreDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavPre::DpchEngData
 ******************************************************************************/

PnlWznmNavPre::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVPREDATA)
		{
};

string PnlWznmNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};
