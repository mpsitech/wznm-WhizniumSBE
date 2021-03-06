/**
	* \file PnlWznmMchRec.cpp
	* API code for job PnlWznmMchRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmMchRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmMchRec::VecVDo
 ******************************************************************************/

uint PnlWznmMchRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmMchRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmMchRec::ContInf
 ******************************************************************************/

PnlWznmMchRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmMchRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmMchRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmMchRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmMchRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmMchRec::ContInf::diff(
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
 class PnlWznmMchRec::StatApp
 ******************************************************************************/

PnlWznmMchRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneAMakefile
			, const bool initdoneAPar
			, const bool initdone1NRelease
			, const bool initdoneSup1NMachine
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneAMakefile = initdoneAMakefile;
	this->initdoneAPar = initdoneAPar;
	this->initdone1NRelease = initdone1NRelease;
	this->initdoneSup1NMachine = initdoneSup1NMachine;

	mask = {INITDONEDETAIL, INITDONEAMAKEFILE, INITDONEAPAR, INITDONE1NRELEASE, INITDONESUP1NMACHINE};
};

bool PnlWznmMchRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmMchRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmMchRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAMakefile", initdoneAMakefile)) add(INITDONEAMAKEFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPar", initdoneAPar)) add(INITDONEAPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NRelease", initdone1NRelease)) add(INITDONE1NRELEASE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NMachine", initdoneSup1NMachine)) add(INITDONESUP1NMACHINE);
	};

	return basefound;
};

set<uint> PnlWznmMchRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneAMakefile == comp->initdoneAMakefile) insert(items, INITDONEAMAKEFILE);
	if (initdoneAPar == comp->initdoneAPar) insert(items, INITDONEAPAR);
	if (initdone1NRelease == comp->initdone1NRelease) insert(items, INITDONE1NRELEASE);
	if (initdoneSup1NMachine == comp->initdoneSup1NMachine) insert(items, INITDONESUP1NMACHINE);

	return(items);
};

set<uint> PnlWznmMchRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEAMAKEFILE, INITDONEAPAR, INITDONE1NRELEASE, INITDONESUP1NMACHINE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchRec::StatShr
 ******************************************************************************/

PnlWznmMchRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefAMakefile
			, const string& scrJrefAPar
			, const string& scrJref1NRelease
			, const string& scrJrefSup1NMachine
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefAMakefile = scrJrefAMakefile;
	this->scrJrefAPar = scrJrefAPar;
	this->scrJref1NRelease = scrJref1NRelease;
	this->scrJrefSup1NMachine = scrJrefSup1NMachine;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAMAKEFILE, SCRJREFAPAR, SCRJREF1NRELEASE, SCRJREFSUP1NMACHINE, BUTREGULARIZEACTIVE};
};

bool PnlWznmMchRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmMchRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmMchRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAMakefile", scrJrefAMakefile)) add(SCRJREFAMAKEFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPar", scrJrefAPar)) add(SCRJREFAPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NRelease", scrJref1NRelease)) add(SCRJREF1NRELEASE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NMachine", scrJrefSup1NMachine)) add(SCRJREFSUP1NMACHINE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmMchRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefAMakefile == comp->scrJrefAMakefile) insert(items, SCRJREFAMAKEFILE);
	if (scrJrefAPar == comp->scrJrefAPar) insert(items, SCRJREFAPAR);
	if (scrJref1NRelease == comp->scrJref1NRelease) insert(items, SCRJREF1NRELEASE);
	if (scrJrefSup1NMachine == comp->scrJrefSup1NMachine) insert(items, SCRJREFSUP1NMACHINE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmMchRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAMAKEFILE, SCRJREFAPAR, SCRJREF1NRELEASE, SCRJREFSUP1NMACHINE, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchRec::Tag
 ******************************************************************************/

PnlWznmMchRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmMchRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmMchRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmMchRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmMchRec::DpchAppDo
 ******************************************************************************/

PnlWznmMchRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMCHRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmMchRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMchRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmMchRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMchRec::DpchEngData
 ******************************************************************************/

PnlWznmMchRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMMCHRECDATA)
		{
};

string PnlWznmMchRec::DpchEngData::getSrefsMask() {
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

void PnlWznmMchRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmMchRecData");
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
