/**
	* \file PnlWznmNavComp.cpp
	* API code for job PnlWznmNavComp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "PnlWznmNavComp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavComp::VecVDo
 ******************************************************************************/

uint PnlWznmNavComp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butopkviewclick") return BUTOPKVIEWCLICK;
	if (s == "butopknewcrdclick") return BUTOPKNEWCRDCLICK;
	if (s == "butopxviewclick") return BUTOPXVIEWCLICK;
	if (s == "butopxnewcrdclick") return BUTOPXNEWCRDCLICK;

	return(0);
};

string PnlWznmNavComp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTOPKVIEWCLICK) return("ButOpkViewClick");
	if (ix == BUTOPKNEWCRDCLICK) return("ButOpkNewcrdClick");
	if (ix == BUTOPXVIEWCLICK) return("ButOpxViewClick");
	if (ix == BUTOPXNEWCRDCLICK) return("ButOpxNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavComp::ContIac
 ******************************************************************************/

PnlWznmNavComp::ContIac::ContIac(
			const uint numFLstOpk
			, const uint numFLstOpx
		) :
			Block()
		{
	this->numFLstOpk = numFLstOpk;
	this->numFLstOpx = numFLstOpx;

	mask = {NUMFLSTOPK, NUMFLSTOPX};
};

bool PnlWznmNavComp::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavComp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavComp";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOpk", numFLstOpk)) add(NUMFLSTOPK);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstOpx", numFLstOpx)) add(NUMFLSTOPX);
	};

	return basefound;
};

void PnlWznmNavComp::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavComp";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavComp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstOpk", numFLstOpk);
		writeUintAttr(wr, itemtag, "sref", "numFLstOpx", numFLstOpx);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavComp::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstOpk == comp->numFLstOpk) insert(items, NUMFLSTOPK);
	if (numFLstOpx == comp->numFLstOpx) insert(items, NUMFLSTOPX);

	return(items);
};

set<uint> PnlWznmNavComp::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTOPK, NUMFLSTOPX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavComp::StatApp
 ******************************************************************************/

PnlWznmNavComp::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstOpkAlt
			, const bool LstOpxAlt
			, const uint LstOpkNumFirstdisp
			, const uint LstOpxNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstOpkAlt = LstOpkAlt;
	this->LstOpxAlt = LstOpxAlt;
	this->LstOpkNumFirstdisp = LstOpkNumFirstdisp;
	this->LstOpxNumFirstdisp = LstOpxNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTOPKALT, LSTOPXALT, LSTOPKNUMFIRSTDISP, LSTOPXNUMFIRSTDISP};
};

bool PnlWznmNavComp::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavComp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavComp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpkAlt", LstOpkAlt)) add(LSTOPKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpxAlt", LstOpxAlt)) add(LSTOPXALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpkNumFirstdisp", LstOpkNumFirstdisp)) add(LSTOPKNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpxNumFirstdisp", LstOpxNumFirstdisp)) add(LSTOPXNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavComp::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstOpkAlt == comp->LstOpkAlt) insert(items, LSTOPKALT);
	if (LstOpxAlt == comp->LstOpxAlt) insert(items, LSTOPXALT);
	if (LstOpkNumFirstdisp == comp->LstOpkNumFirstdisp) insert(items, LSTOPKNUMFIRSTDISP);
	if (LstOpxNumFirstdisp == comp->LstOpxNumFirstdisp) insert(items, LSTOPXNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavComp::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTOPKALT, LSTOPXALT, LSTOPKNUMFIRSTDISP, LSTOPXNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavComp::StatShr
 ******************************************************************************/

PnlWznmNavComp::StatShr::StatShr(
			const bool LstOpkAvail
			, const bool ButOpkViewActive
			, const bool ButOpkNewcrdActive
			, const bool LstOpxAvail
			, const bool ButOpxViewActive
			, const bool ButOpxNewcrdActive
		) :
			Block()
		{
	this->LstOpkAvail = LstOpkAvail;
	this->ButOpkViewActive = ButOpkViewActive;
	this->ButOpkNewcrdActive = ButOpkNewcrdActive;
	this->LstOpxAvail = LstOpxAvail;
	this->ButOpxViewActive = ButOpxViewActive;
	this->ButOpxNewcrdActive = ButOpxNewcrdActive;

	mask = {LSTOPKAVAIL, BUTOPKVIEWACTIVE, BUTOPKNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE};
};

bool PnlWznmNavComp::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavComp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavComp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpkAvail", LstOpkAvail)) add(LSTOPKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpkViewActive", ButOpkViewActive)) add(BUTOPKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpkNewcrdActive", ButOpkNewcrdActive)) add(BUTOPKNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOpxAvail", LstOpxAvail)) add(LSTOPXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpxViewActive", ButOpxViewActive)) add(BUTOPXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpxNewcrdActive", ButOpxNewcrdActive)) add(BUTOPXNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmNavComp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstOpkAvail == comp->LstOpkAvail) insert(items, LSTOPKAVAIL);
	if (ButOpkViewActive == comp->ButOpkViewActive) insert(items, BUTOPKVIEWACTIVE);
	if (ButOpkNewcrdActive == comp->ButOpkNewcrdActive) insert(items, BUTOPKNEWCRDACTIVE);
	if (LstOpxAvail == comp->LstOpxAvail) insert(items, LSTOPXAVAIL);
	if (ButOpxViewActive == comp->ButOpxViewActive) insert(items, BUTOPXVIEWACTIVE);
	if (ButOpxNewcrdActive == comp->ButOpxNewcrdActive) insert(items, BUTOPXNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavComp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTOPKAVAIL, BUTOPKVIEWACTIVE, BUTOPKNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavComp::Tag
 ******************************************************************************/

PnlWznmNavComp::Tag::Tag(
			const string& Cpt
			, const string& CptOpk
			, const string& CptOpx
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptOpk = CptOpk;
	this->CptOpx = CptOpx;

	mask = {CPT, CPTOPK, CPTOPX};
};

bool PnlWznmNavComp::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavComp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavComp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpk", CptOpk)) add(CPTOPK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpx", CptOpx)) add(CPTOPX);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavComp::DpchAppData
 ******************************************************************************/

PnlWznmNavComp::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVCOMPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavComp::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavComp::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavCompData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavComp::DpchAppDo
 ******************************************************************************/

PnlWznmNavComp::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVCOMPDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavComp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavComp::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavCompDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavComp::DpchEngData
 ******************************************************************************/

PnlWznmNavComp::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVCOMPDATA)
		{
	feedFLstOpk.tag = "FeedFLstOpk";
	feedFLstOpx.tag = "FeedFLstOpx";
};

string PnlWznmNavComp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTOPK)) ss.push_back("feedFLstOpk");
	if (has(FEEDFLSTOPX)) ss.push_back("feedFLstOpx");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavComp::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavCompData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstOpk.readXML(docctx, basexpath, true)) add(FEEDFLSTOPK);
		if (feedFLstOpx.readXML(docctx, basexpath, true)) add(FEEDFLSTOPX);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstOpk.clear();
		feedFLstOpx.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

