/**
	* \file PnlWznmCmpRec.cpp
	* API code for job PnlWznmCmpRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmCmpRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmCmpRec::VecVDo
 ******************************************************************************/

uint PnlWznmCmpRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmCmpRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmCmpRec::ContInf
 ******************************************************************************/

PnlWznmCmpRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmCmpRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmCmpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmCmpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmCmpRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmCmpRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCmpRec::StatApp
 ******************************************************************************/

PnlWznmCmpRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NRelease
			, const bool initdoneMNOppack
			, const bool initdoneMNLibrary
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdone1NRelease = initdone1NRelease;
	this->initdoneMNOppack = initdoneMNOppack;
	this->initdoneMNLibrary = initdoneMNLibrary;

	mask = {INITDONEDETAIL, INITDONE1NRELEASE, INITDONEMNOPPACK, INITDONEMNLIBRARY};
};

bool PnlWznmCmpRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmCmpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmCmpRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NRelease", initdone1NRelease)) add(INITDONE1NRELEASE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNOppack", initdoneMNOppack)) add(INITDONEMNOPPACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLibrary", initdoneMNLibrary)) add(INITDONEMNLIBRARY);
	};

	return basefound;
};

set<uint> PnlWznmCmpRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NRelease == comp->initdone1NRelease) insert(items, INITDONE1NRELEASE);
	if (initdoneMNOppack == comp->initdoneMNOppack) insert(items, INITDONEMNOPPACK);
	if (initdoneMNLibrary == comp->initdoneMNLibrary) insert(items, INITDONEMNLIBRARY);

	return(items);
};

set<uint> PnlWznmCmpRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NRELEASE, INITDONEMNOPPACK, INITDONEMNLIBRARY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCmpRec::StatShr
 ******************************************************************************/

PnlWznmCmpRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NRelease
			, const string& scrJrefMNOppack
			, const bool pnlmnoppackAvail
			, const string& scrJrefMNLibrary
			, const bool pnlmnlibraryAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NRelease = scrJref1NRelease;
	this->scrJrefMNOppack = scrJrefMNOppack;
	this->pnlmnoppackAvail = pnlmnoppackAvail;
	this->scrJrefMNLibrary = scrJrefMNLibrary;
	this->pnlmnlibraryAvail = pnlmnlibraryAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NRELEASE, SCRJREFMNOPPACK, PNLMNOPPACKAVAIL, SCRJREFMNLIBRARY, PNLMNLIBRARYAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWznmCmpRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmCmpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmCmpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NRelease", scrJref1NRelease)) add(SCRJREF1NRELEASE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNOppack", scrJrefMNOppack)) add(SCRJREFMNOPPACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnoppackAvail", pnlmnoppackAvail)) add(PNLMNOPPACKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLibrary", scrJrefMNLibrary)) add(SCRJREFMNLIBRARY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnlibraryAvail", pnlmnlibraryAvail)) add(PNLMNLIBRARYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmCmpRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJref1NRelease == comp->scrJref1NRelease) insert(items, SCRJREF1NRELEASE);
	if (scrJrefMNOppack == comp->scrJrefMNOppack) insert(items, SCRJREFMNOPPACK);
	if (pnlmnoppackAvail == comp->pnlmnoppackAvail) insert(items, PNLMNOPPACKAVAIL);
	if (scrJrefMNLibrary == comp->scrJrefMNLibrary) insert(items, SCRJREFMNLIBRARY);
	if (pnlmnlibraryAvail == comp->pnlmnlibraryAvail) insert(items, PNLMNLIBRARYAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmCmpRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NRELEASE, SCRJREFMNOPPACK, PNLMNOPPACKAVAIL, SCRJREFMNLIBRARY, PNLMNLIBRARYAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCmpRec::Tag
 ******************************************************************************/

PnlWznmCmpRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmCmpRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmCmpRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmCmpRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmCmpRec::DpchAppDo
 ******************************************************************************/

PnlWznmCmpRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCMPRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmCmpRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCmpRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmCmpRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCmpRec::DpchEngData
 ******************************************************************************/

PnlWznmCmpRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCMPRECDATA)
		{
};

string PnlWznmCmpRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCmpRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmCmpRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
