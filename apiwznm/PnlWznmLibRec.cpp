/**
	* \file PnlWznmLibRec.cpp
	* API code for job PnlWznmLibRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmLibRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmLibRec::VecVDo
 ******************************************************************************/

uint PnlWznmLibRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmLibRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmLibRec::ContInf
 ******************************************************************************/

PnlWznmLibRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmLibRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmLibRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmLibRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmLibRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmLibRec::ContInf::diff(
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
 class PnlWznmLibRec::StatApp
 ******************************************************************************/

PnlWznmLibRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneAPkglist
			, const bool initdoneAMakefile
			, const bool initdoneRef1NFile
			, const bool initdoneMNOppack
			, const bool initdoneMNComponent
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneAPkglist = initdoneAPkglist;
	this->initdoneAMakefile = initdoneAMakefile;
	this->initdoneRef1NFile = initdoneRef1NFile;
	this->initdoneMNOppack = initdoneMNOppack;
	this->initdoneMNComponent = initdoneMNComponent;

	mask = {INITDONEDETAIL, INITDONEAPKGLIST, INITDONEAMAKEFILE, INITDONEREF1NFILE, INITDONEMNOPPACK, INITDONEMNCOMPONENT};
};

bool PnlWznmLibRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmLibRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmLibRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPkglist", initdoneAPkglist)) add(INITDONEAPKGLIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAMakefile", initdoneAMakefile)) add(INITDONEAMAKEFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNOppack", initdoneMNOppack)) add(INITDONEMNOPPACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNComponent", initdoneMNComponent)) add(INITDONEMNCOMPONENT);
	};

	return basefound;
};

set<uint> PnlWznmLibRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneAPkglist == comp->initdoneAPkglist) insert(items, INITDONEAPKGLIST);
	if (initdoneAMakefile == comp->initdoneAMakefile) insert(items, INITDONEAMAKEFILE);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);
	if (initdoneMNOppack == comp->initdoneMNOppack) insert(items, INITDONEMNOPPACK);
	if (initdoneMNComponent == comp->initdoneMNComponent) insert(items, INITDONEMNCOMPONENT);

	return(items);
};

set<uint> PnlWznmLibRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEAPKGLIST, INITDONEAMAKEFILE, INITDONEREF1NFILE, INITDONEMNOPPACK, INITDONEMNCOMPONENT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibRec::StatShr
 ******************************************************************************/

PnlWznmLibRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefAPkglist
			, const string& scrJrefAMakefile
			, const string& scrJrefRef1NFile
			, const string& scrJrefMNOppack
			, const string& scrJrefMNComponent
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefAPkglist = scrJrefAPkglist;
	this->scrJrefAMakefile = scrJrefAMakefile;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->scrJrefMNOppack = scrJrefMNOppack;
	this->scrJrefMNComponent = scrJrefMNComponent;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAPKGLIST, SCRJREFAMAKEFILE, SCRJREFREF1NFILE, SCRJREFMNOPPACK, SCRJREFMNCOMPONENT, BUTREGULARIZEACTIVE};
};

bool PnlWznmLibRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmLibRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmLibRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPkglist", scrJrefAPkglist)) add(SCRJREFAPKGLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAMakefile", scrJrefAMakefile)) add(SCRJREFAMAKEFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNOppack", scrJrefMNOppack)) add(SCRJREFMNOPPACK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNComponent", scrJrefMNComponent)) add(SCRJREFMNCOMPONENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmLibRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefAPkglist == comp->scrJrefAPkglist) insert(items, SCRJREFAPKGLIST);
	if (scrJrefAMakefile == comp->scrJrefAMakefile) insert(items, SCRJREFAMAKEFILE);
	if (scrJrefRef1NFile == comp->scrJrefRef1NFile) insert(items, SCRJREFREF1NFILE);
	if (scrJrefMNOppack == comp->scrJrefMNOppack) insert(items, SCRJREFMNOPPACK);
	if (scrJrefMNComponent == comp->scrJrefMNComponent) insert(items, SCRJREFMNCOMPONENT);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmLibRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAPKGLIST, SCRJREFAMAKEFILE, SCRJREFREF1NFILE, SCRJREFMNOPPACK, SCRJREFMNCOMPONENT, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibRec::Tag
 ******************************************************************************/

PnlWznmLibRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmLibRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmLibRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmLibRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmLibRec::DpchAppDo
 ******************************************************************************/

PnlWznmLibRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMLIBRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmLibRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmLibRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmLibRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmLibRec::DpchEngData
 ******************************************************************************/

PnlWznmLibRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMLIBRECDATA)
		{
};

string PnlWznmLibRec::DpchEngData::getSrefsMask() {
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

void PnlWznmLibRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmLibRecData");
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
