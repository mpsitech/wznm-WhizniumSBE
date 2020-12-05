/**
	* \file SessWznm.cpp
	* API code for job SessWznm (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "SessWznm.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class SessWznm::StatShr
 ******************************************************************************/

SessWznm::StatShr::StatShr(
			const string& scrJrefCrdnav
		) :
			Block()
		{
	this->scrJrefCrdnav = scrJrefCrdnav;

	mask = {SCRJREFCRDNAV};
};

bool SessWznm::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrSessWznm");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrSessWznm";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCrdnav", scrJrefCrdnav)) add(SCRJREFCRDNAV);
	};

	return basefound;
};

set<uint> SessWznm::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefCrdnav == comp->scrJrefCrdnav) insert(items, SCRJREFCRDNAV);

	return(items);
};

set<uint> SessWznm::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFCRDNAV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessWznm::DpchEngData
 ******************************************************************************/

SessWznm::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGSESSWZNMDATA)
		{
	feedFEnsSec.tag = "FeedFEnsSec";
};

string SessWznm::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessWznm::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngSessWznmData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSec.readXML(docctx, basexpath, true)) add(FEEDFENSSEC);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		feedFEnsSec.clear();
		statshr = StatShr();
	};
};

