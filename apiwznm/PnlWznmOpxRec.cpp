/**
	* \file PnlWznmOpxRec.cpp
	* API code for job PnlWznmOpxRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmOpxRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmOpxRec::VecVDo
 ******************************************************************************/

uint PnlWznmOpxRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmOpxRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmOpxRec::ContInf
 ******************************************************************************/

PnlWznmOpxRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmOpxRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmOpxRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmOpxRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmOpxRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmOpxRec::ContInf::diff(
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
 class PnlWznmOpxRec::StatApp
 ******************************************************************************/

PnlWznmOpxRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneARetval
			, const bool initdoneAInvarg
			, const bool initdoneRef1NBlock
			, const bool initdoneMNJob
			, const bool initdoneSqkMNStub
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneARetval = initdoneARetval;
	this->initdoneAInvarg = initdoneAInvarg;
	this->initdoneRef1NBlock = initdoneRef1NBlock;
	this->initdoneMNJob = initdoneMNJob;
	this->initdoneSqkMNStub = initdoneSqkMNStub;

	mask = {INITDONEDETAIL, INITDONEARETVAL, INITDONEAINVARG, INITDONEREF1NBLOCK, INITDONEMNJOB, INITDONESQKMNSTUB};
};

bool PnlWznmOpxRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmOpxRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmOpxRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneARetval", initdoneARetval)) add(INITDONEARETVAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAInvarg", initdoneAInvarg)) add(INITDONEAINVARG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NBlock", initdoneRef1NBlock)) add(INITDONEREF1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNJob", initdoneMNJob)) add(INITDONEMNJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSqkMNStub", initdoneSqkMNStub)) add(INITDONESQKMNSTUB);
	};

	return basefound;
};

set<uint> PnlWznmOpxRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneARetval == comp->initdoneARetval) insert(items, INITDONEARETVAL);
	if (initdoneAInvarg == comp->initdoneAInvarg) insert(items, INITDONEAINVARG);
	if (initdoneRef1NBlock == comp->initdoneRef1NBlock) insert(items, INITDONEREF1NBLOCK);
	if (initdoneMNJob == comp->initdoneMNJob) insert(items, INITDONEMNJOB);
	if (initdoneSqkMNStub == comp->initdoneSqkMNStub) insert(items, INITDONESQKMNSTUB);

	return(items);
};

set<uint> PnlWznmOpxRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEARETVAL, INITDONEAINVARG, INITDONEREF1NBLOCK, INITDONEMNJOB, INITDONESQKMNSTUB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxRec::StatShr
 ******************************************************************************/

PnlWznmOpxRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefARetval
			, const string& scrJrefAInvarg
			, const string& scrJrefRef1NBlock
			, const string& scrJrefMNJob
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
	this->scrJrefRef1NBlock = scrJrefRef1NBlock;
	this->scrJrefMNJob = scrJrefMNJob;
	this->scrJrefSqkMNStub = scrJrefSqkMNStub;
	this->pnlsqkmnstubAvail = pnlsqkmnstubAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFARETVAL, SCRJREFAINVARG, SCRJREFREF1NBLOCK, SCRJREFMNJOB, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWznmOpxRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmOpxRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmOpxRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefARetval", scrJrefARetval)) add(SCRJREFARETVAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAInvarg", scrJrefAInvarg)) add(SCRJREFAINVARG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NBlock", scrJrefRef1NBlock)) add(SCRJREFREF1NBLOCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNJob", scrJrefMNJob)) add(SCRJREFMNJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSqkMNStub", scrJrefSqkMNStub)) add(SCRJREFSQKMNSTUB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlsqkmnstubAvail", pnlsqkmnstubAvail)) add(PNLSQKMNSTUBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmOpxRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefARetval == comp->scrJrefARetval) insert(items, SCRJREFARETVAL);
	if (scrJrefAInvarg == comp->scrJrefAInvarg) insert(items, SCRJREFAINVARG);
	if (scrJrefRef1NBlock == comp->scrJrefRef1NBlock) insert(items, SCRJREFREF1NBLOCK);
	if (scrJrefMNJob == comp->scrJrefMNJob) insert(items, SCRJREFMNJOB);
	if (scrJrefSqkMNStub == comp->scrJrefSqkMNStub) insert(items, SCRJREFSQKMNSTUB);
	if (pnlsqkmnstubAvail == comp->pnlsqkmnstubAvail) insert(items, PNLSQKMNSTUBAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmOpxRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFARETVAL, SCRJREFAINVARG, SCRJREFREF1NBLOCK, SCRJREFMNJOB, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxRec::Tag
 ******************************************************************************/

PnlWznmOpxRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmOpxRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmOpxRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmOpxRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmOpxRec::DpchAppDo
 ******************************************************************************/

PnlWznmOpxRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPXRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmOpxRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpxRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmOpxRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpxRec::DpchEngData
 ******************************************************************************/

PnlWznmOpxRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMOPXRECDATA)
		{
};

string PnlWznmOpxRec::DpchEngData::getSrefsMask() {
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

void PnlWznmOpxRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmOpxRecData");
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

