/**
	* \file PnlWznmRtjHeadbar.cpp
	* API code for job PnlWznmRtjHeadbar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmRtjHeadbar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmRtjHeadbar::StgInf
 ******************************************************************************/

PnlWznmRtjHeadbar::StgInf::StgInf(
			const uint MenAppCptwidth
			, const uint MenAppWidth
			, const uint MenCrdCptwidth
			, const uint MenCrdWidth
		) :
			Block()
		{
	this->MenAppCptwidth = MenAppCptwidth;
	this->MenAppWidth = MenAppWidth;
	this->MenCrdCptwidth = MenCrdCptwidth;
	this->MenCrdWidth = MenCrdWidth;

	mask = {MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
};

bool PnlWznmRtjHeadbar::StgInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgInfWznmRtjHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemInfWznmRtjHeadbar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", MenAppCptwidth)) add(MENAPPCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppWidth", MenAppWidth)) add(MENAPPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdCptwidth", MenCrdCptwidth)) add(MENCRDCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdWidth", MenCrdWidth)) add(MENCRDWIDTH);
	};

	return basefound;
};

set<uint> PnlWznmRtjHeadbar::StgInf::comm(
			const StgInf* comp
		) {
	set<uint> items;

	if (MenAppCptwidth == comp->MenAppCptwidth) insert(items, MENAPPCPTWIDTH);
	if (MenAppWidth == comp->MenAppWidth) insert(items, MENAPPWIDTH);
	if (MenCrdCptwidth == comp->MenCrdCptwidth) insert(items, MENCRDCPTWIDTH);
	if (MenCrdWidth == comp->MenCrdWidth) insert(items, MENCRDWIDTH);

	return(items);
};

set<uint> PnlWznmRtjHeadbar::StgInf::diff(
			const StgInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRtjHeadbar::Tag
 ******************************************************************************/

PnlWznmRtjHeadbar::Tag::Tag(
			const string& MenApp
			, const string& MenCrd
		) :
			Block()
		{
	this->MenApp = MenApp;
	this->MenCrd = MenCrd;

	mask = {MENAPP, MENCRD};
};

bool PnlWznmRtjHeadbar::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmRtjHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmRtjHeadbar";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenApp", MenApp)) add(MENAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenCrd", MenCrd)) add(MENCRD);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmRtjHeadbar::DpchEngData
 ******************************************************************************/

PnlWznmRtjHeadbar::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRTJHEADBARDATA)
		{
};

string PnlWznmRtjHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRtjHeadbar::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmRtjHeadbarData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (stginf.readXML(docctx, basexpath, true)) add(STGINF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		stginf = StgInf();
		tag = Tag();
	};
};

