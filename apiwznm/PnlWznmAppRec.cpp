/**
	* \file PnlWznmAppRec.cpp
	* API code for job PnlWznmAppRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmAppRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmAppRec::VecVDo
 ******************************************************************************/

uint PnlWznmAppRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmAppRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmAppRec::ContInf
 ******************************************************************************/

PnlWznmAppRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
			, TxtRef(TxtRef)
		{
	mask = {TXTREF};
};

bool PnlWznmAppRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmAppRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmAppRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmAppRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmAppRec::ContInf::diff(
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
 class PnlWznmAppRec::StatApp
 ******************************************************************************/

PnlWznmAppRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NEvent
			, const bool initdoneApp1NSequence
			, const bool initdone1NRtjob
			, const bool initdoneRef1NFile
		) :
			Block()
			, initdoneDetail(initdoneDetail)
			, initdone1NEvent(initdone1NEvent)
			, initdoneApp1NSequence(initdoneApp1NSequence)
			, initdone1NRtjob(initdone1NRtjob)
			, initdoneRef1NFile(initdoneRef1NFile)
		{
	mask = {INITDONEDETAIL, INITDONE1NEVENT, INITDONEAPP1NSEQUENCE, INITDONE1NRTJOB, INITDONEREF1NFILE};
};

bool PnlWznmAppRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmAppRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmAppRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NEvent", initdone1NEvent)) add(INITDONE1NEVENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneApp1NSequence", initdoneApp1NSequence)) add(INITDONEAPP1NSEQUENCE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NRtjob", initdone1NRtjob)) add(INITDONE1NRTJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
	};

	return basefound;
};

set<uint> PnlWznmAppRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NEvent == comp->initdone1NEvent) insert(items, INITDONE1NEVENT);
	if (initdoneApp1NSequence == comp->initdoneApp1NSequence) insert(items, INITDONEAPP1NSEQUENCE);
	if (initdone1NRtjob == comp->initdone1NRtjob) insert(items, INITDONE1NRTJOB);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);

	return(items);
};

set<uint> PnlWznmAppRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NEVENT, INITDONEAPP1NSEQUENCE, INITDONE1NRTJOB, INITDONEREF1NFILE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmAppRec::StatShr
 ******************************************************************************/

PnlWznmAppRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NEvent
			, const string& scrJrefApp1NSequence
			, const string& scrJref1NRtjob
			, const string& scrJrefRef1NFile
			, const bool ButRegularizeActive
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
			, scrJrefDetail(scrJrefDetail)
			, scrJref1NEvent(scrJref1NEvent)
			, scrJrefApp1NSequence(scrJrefApp1NSequence)
			, scrJref1NRtjob(scrJref1NRtjob)
			, scrJrefRef1NFile(scrJrefRef1NFile)
			, ButRegularizeActive(ButRegularizeActive)
		{
	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NEVENT, SCRJREFAPP1NSEQUENCE, SCRJREF1NRTJOB, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE};
};

bool PnlWznmAppRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmAppRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmAppRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NEvent", scrJref1NEvent)) add(SCRJREF1NEVENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefApp1NSequence", scrJrefApp1NSequence)) add(SCRJREFAPP1NSEQUENCE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NRtjob", scrJref1NRtjob)) add(SCRJREF1NRTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmAppRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJref1NEvent == comp->scrJref1NEvent) insert(items, SCRJREF1NEVENT);
	if (scrJrefApp1NSequence == comp->scrJrefApp1NSequence) insert(items, SCRJREFAPP1NSEQUENCE);
	if (scrJref1NRtjob == comp->scrJref1NRtjob) insert(items, SCRJREF1NRTJOB);
	if (scrJrefRef1NFile == comp->scrJrefRef1NFile) insert(items, SCRJREFREF1NFILE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmAppRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NEVENT, SCRJREFAPP1NSEQUENCE, SCRJREF1NRTJOB, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmAppRec::Tag
 ******************************************************************************/

PnlWznmAppRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
			, Cpt(Cpt)
		{
	mask = {CPT};
};

bool PnlWznmAppRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmAppRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmAppRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmAppRec::DpchAppDo
 ******************************************************************************/

PnlWznmAppRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMAPPRECDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmAppRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmAppRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmAppRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmAppRec::DpchEngData
 ******************************************************************************/

PnlWznmAppRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMAPPRECDATA)
		{
};

string PnlWznmAppRec::DpchEngData::getSrefsMask() {
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

void PnlWznmAppRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmAppRecData");
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
