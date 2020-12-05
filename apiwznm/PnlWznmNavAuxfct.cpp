/**
	* \file PnlWznmNavAuxfct.cpp
	* API code for job PnlWznmNavAuxfct (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmNavAuxfct.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavAuxfct::VecVDo
 ******************************************************************************/

uint PnlWznmNavAuxfct::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bututlnewcrdclick") return BUTUTLNEWCRDCLICK;

	return(0);
};

string PnlWznmNavAuxfct::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUTLNEWCRDCLICK) return("ButUtlNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavAuxfct::StatApp
 ******************************************************************************/

PnlWznmNavAuxfct::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmNavAuxfct::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavAuxfct");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavAuxfct";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmNavAuxfct::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmNavAuxfct::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAuxfct::StatShr
 ******************************************************************************/

PnlWznmNavAuxfct::StatShr::StatShr(
			const bool ButUtlNewcrdAvail
		) :
			Block()
		{
	this->ButUtlNewcrdAvail = ButUtlNewcrdAvail;

	mask = {BUTUTLNEWCRDAVAIL};
};

bool PnlWznmNavAuxfct::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavAuxfct");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavAuxfct";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUtlNewcrdAvail", ButUtlNewcrdAvail)) add(BUTUTLNEWCRDAVAIL);
	};

	return basefound;
};

set<uint> PnlWznmNavAuxfct::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButUtlNewcrdAvail == comp->ButUtlNewcrdAvail) insert(items, BUTUTLNEWCRDAVAIL);

	return(items);
};

set<uint> PnlWznmNavAuxfct::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTUTLNEWCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAuxfct::Tag
 ******************************************************************************/

PnlWznmNavAuxfct::Tag::Tag(
			const string& Cpt
			, const string& CptUtl
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptUtl = CptUtl;

	mask = {CPT, CPTUTL};
};

bool PnlWznmNavAuxfct::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavAuxfct");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavAuxfct";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUtl", CptUtl)) add(CPTUTL);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavAuxfct::DpchAppDo
 ******************************************************************************/

PnlWznmNavAuxfct::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVAUXFCTDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavAuxfct::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAuxfct::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavAuxfctDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAuxfct::DpchEngData
 ******************************************************************************/

PnlWznmNavAuxfct::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVAUXFCTDATA)
		{
};

string PnlWznmNavAuxfct::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAuxfct::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavAuxfctData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

