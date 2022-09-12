/**
	* \file PnlWznmOpkRec.cpp
	* API code for job PnlWznmOpkRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmOpkRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmOpkRec::VecVDo
 ******************************************************************************/

uint PnlWznmOpkRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmOpkRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmOpkRec::ContInf
 ******************************************************************************/

PnlWznmOpkRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmOpkRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmOpkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmOpkRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmOpkRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmOpkRec::ContInf::diff(
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
 class PnlWznmOpkRec::StatApp
 ******************************************************************************/

PnlWznmOpkRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneARetval
			, const bool initdoneAInvarg
			, const bool initdone1NOp
			, const bool initdoneRef1NBlock
			, const bool initdoneMNJob
			, const bool initdoneMNComponent
			, const bool initdoneMNLibrary
			, const bool initdoneSqkMNStub
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneARetval = initdoneARetval;
	this->initdoneAInvarg = initdoneAInvarg;
	this->initdone1NOp = initdone1NOp;
	this->initdoneRef1NBlock = initdoneRef1NBlock;
	this->initdoneMNJob = initdoneMNJob;
	this->initdoneMNComponent = initdoneMNComponent;
	this->initdoneMNLibrary = initdoneMNLibrary;
	this->initdoneSqkMNStub = initdoneSqkMNStub;

	mask = {INITDONEDETAIL, INITDONEARETVAL, INITDONEAINVARG, INITDONE1NOP, INITDONEREF1NBLOCK, INITDONEMNJOB, INITDONEMNCOMPONENT, INITDONEMNLIBRARY, INITDONESQKMNSTUB};
};

bool PnlWznmOpkRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmOpkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmOpkRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneARetval", initdoneARetval)) add(INITDONEARETVAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAInvarg", initdoneAInvarg)) add(INITDONEAINVARG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NOp", initdone1NOp)) add(INITDONE1NOP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NBlock", initdoneRef1NBlock)) add(INITDONEREF1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNJob", initdoneMNJob)) add(INITDONEMNJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNComponent", initdoneMNComponent)) add(INITDONEMNCOMPONENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLibrary", initdoneMNLibrary)) add(INITDONEMNLIBRARY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSqkMNStub", initdoneSqkMNStub)) add(INITDONESQKMNSTUB);
	};

	return basefound;
};

set<uint> PnlWznmOpkRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneARetval == comp->initdoneARetval) insert(items, INITDONEARETVAL);
	if (initdoneAInvarg == comp->initdoneAInvarg) insert(items, INITDONEAINVARG);
	if (initdone1NOp == comp->initdone1NOp) insert(items, INITDONE1NOP);
	if (initdoneRef1NBlock == comp->initdoneRef1NBlock) insert(items, INITDONEREF1NBLOCK);
	if (initdoneMNJob == comp->initdoneMNJob) insert(items, INITDONEMNJOB);
	if (initdoneMNComponent == comp->initdoneMNComponent) insert(items, INITDONEMNCOMPONENT);
	if (initdoneMNLibrary == comp->initdoneMNLibrary) insert(items, INITDONEMNLIBRARY);
	if (initdoneSqkMNStub == comp->initdoneSqkMNStub) insert(items, INITDONESQKMNSTUB);

	return(items);
};

set<uint> PnlWznmOpkRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEARETVAL, INITDONEAINVARG, INITDONE1NOP, INITDONEREF1NBLOCK, INITDONEMNJOB, INITDONEMNCOMPONENT, INITDONEMNLIBRARY, INITDONESQKMNSTUB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpkRec::StatShr
 ******************************************************************************/

PnlWznmOpkRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefARetval
			, const string& scrJrefAInvarg
			, const string& scrJref1NOp
			, const string& scrJrefRef1NBlock
			, const string& scrJrefMNJob
			, const string& scrJrefMNComponent
			, const string& scrJrefMNLibrary
			, const string& scrJrefSqkMNStub
			, const bool pnlsqkmnstubAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefARetval = scrJrefARetval;
	this->scrJrefAInvarg = scrJrefAInvarg;
	this->scrJref1NOp = scrJref1NOp;
	this->scrJrefRef1NBlock = scrJrefRef1NBlock;
	this->scrJrefMNJob = scrJrefMNJob;
	this->scrJrefMNComponent = scrJrefMNComponent;
	this->scrJrefMNLibrary = scrJrefMNLibrary;
	this->scrJrefSqkMNStub = scrJrefSqkMNStub;
	this->pnlsqkmnstubAvail = pnlsqkmnstubAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFARETVAL, SCRJREFAINVARG, SCRJREF1NOP, SCRJREFREF1NBLOCK, SCRJREFMNJOB, SCRJREFMNCOMPONENT, SCRJREFMNLIBRARY, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWznmOpkRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmOpkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmOpkRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefARetval", scrJrefARetval)) add(SCRJREFARETVAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAInvarg", scrJrefAInvarg)) add(SCRJREFAINVARG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NOp", scrJref1NOp)) add(SCRJREF1NOP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NBlock", scrJrefRef1NBlock)) add(SCRJREFREF1NBLOCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNJob", scrJrefMNJob)) add(SCRJREFMNJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNComponent", scrJrefMNComponent)) add(SCRJREFMNCOMPONENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLibrary", scrJrefMNLibrary)) add(SCRJREFMNLIBRARY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSqkMNStub", scrJrefSqkMNStub)) add(SCRJREFSQKMNSTUB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlsqkmnstubAvail", pnlsqkmnstubAvail)) add(PNLSQKMNSTUBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmOpkRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefARetval == comp->scrJrefARetval) insert(items, SCRJREFARETVAL);
	if (scrJrefAInvarg == comp->scrJrefAInvarg) insert(items, SCRJREFAINVARG);
	if (scrJref1NOp == comp->scrJref1NOp) insert(items, SCRJREF1NOP);
	if (scrJrefRef1NBlock == comp->scrJrefRef1NBlock) insert(items, SCRJREFREF1NBLOCK);
	if (scrJrefMNJob == comp->scrJrefMNJob) insert(items, SCRJREFMNJOB);
	if (scrJrefMNComponent == comp->scrJrefMNComponent) insert(items, SCRJREFMNCOMPONENT);
	if (scrJrefMNLibrary == comp->scrJrefMNLibrary) insert(items, SCRJREFMNLIBRARY);
	if (scrJrefSqkMNStub == comp->scrJrefSqkMNStub) insert(items, SCRJREFSQKMNSTUB);
	if (pnlsqkmnstubAvail == comp->pnlsqkmnstubAvail) insert(items, PNLSQKMNSTUBAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmOpkRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFARETVAL, SCRJREFAINVARG, SCRJREF1NOP, SCRJREFREF1NBLOCK, SCRJREFMNJOB, SCRJREFMNCOMPONENT, SCRJREFMNLIBRARY, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpkRec::Tag
 ******************************************************************************/

PnlWznmOpkRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmOpkRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmOpkRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmOpkRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmOpkRec::DpchAppDo
 ******************************************************************************/

PnlWznmOpkRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPKRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmOpkRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpkRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmOpkRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpkRec::DpchEngData
 ******************************************************************************/

PnlWznmOpkRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMOPKRECDATA)
		{
};

string PnlWznmOpkRec::DpchEngData::getSrefsMask() {
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

void PnlWznmOpkRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmOpkRecData");
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
