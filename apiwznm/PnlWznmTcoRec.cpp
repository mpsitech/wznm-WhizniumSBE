/**
	* \file PnlWznmTcoRec.cpp
	* API code for job PnlWznmTcoRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmTcoRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTcoRec::VecVDo
 ******************************************************************************/

uint PnlWznmTcoRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmTcoRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmTcoRec::ContInf
 ******************************************************************************/

PnlWznmTcoRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmTcoRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmTcoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmTcoRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmTcoRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmTcoRec::ContInf::diff(
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
 class PnlWznmTcoRec::StatApp
 ******************************************************************************/

PnlWznmTcoRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdone1NImpexpcol
			, const bool initdone1NQuerycol
			, const bool initdoneRef1NControl
			, const bool initdoneRef1NQuerymod
			, const bool initdone1NCheck
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneATitle = initdoneATitle;
	this->initdone1NImpexpcol = initdone1NImpexpcol;
	this->initdone1NQuerycol = initdone1NQuerycol;
	this->initdoneRef1NControl = initdoneRef1NControl;
	this->initdoneRef1NQuerymod = initdoneRef1NQuerymod;
	this->initdone1NCheck = initdone1NCheck;

	mask = {INITDONEDETAIL, INITDONEATITLE, INITDONE1NIMPEXPCOL, INITDONE1NQUERYCOL, INITDONEREF1NCONTROL, INITDONEREF1NQUERYMOD, INITDONE1NCHECK};
};

bool PnlWznmTcoRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmTcoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmTcoRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneATitle", initdoneATitle)) add(INITDONEATITLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NImpexpcol", initdone1NImpexpcol)) add(INITDONE1NIMPEXPCOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NQuerycol", initdone1NQuerycol)) add(INITDONE1NQUERYCOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NControl", initdoneRef1NControl)) add(INITDONEREF1NCONTROL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NQuerymod", initdoneRef1NQuerymod)) add(INITDONEREF1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NCheck", initdone1NCheck)) add(INITDONE1NCHECK);
	};

	return basefound;
};

set<uint> PnlWznmTcoRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneATitle == comp->initdoneATitle) insert(items, INITDONEATITLE);
	if (initdone1NImpexpcol == comp->initdone1NImpexpcol) insert(items, INITDONE1NIMPEXPCOL);
	if (initdone1NQuerycol == comp->initdone1NQuerycol) insert(items, INITDONE1NQUERYCOL);
	if (initdoneRef1NControl == comp->initdoneRef1NControl) insert(items, INITDONEREF1NCONTROL);
	if (initdoneRef1NQuerymod == comp->initdoneRef1NQuerymod) insert(items, INITDONEREF1NQUERYMOD);
	if (initdone1NCheck == comp->initdone1NCheck) insert(items, INITDONE1NCHECK);

	return(items);
};

set<uint> PnlWznmTcoRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEATITLE, INITDONE1NIMPEXPCOL, INITDONE1NQUERYCOL, INITDONEREF1NCONTROL, INITDONEREF1NQUERYMOD, INITDONE1NCHECK};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoRec::StatShr
 ******************************************************************************/

PnlWznmTcoRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefATitle
			, const bool pnlatitleAvail
			, const string& scrJref1NImpexpcol
			, const bool pnl1nimpexpcolAvail
			, const string& scrJref1NQuerycol
			, const bool pnl1nquerycolAvail
			, const string& scrJrefRef1NControl
			, const bool pnlref1ncontrolAvail
			, const string& scrJrefRef1NQuerymod
			, const bool pnlref1nquerymodAvail
			, const string& scrJref1NCheck
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefATitle = scrJrefATitle;
	this->pnlatitleAvail = pnlatitleAvail;
	this->scrJref1NImpexpcol = scrJref1NImpexpcol;
	this->pnl1nimpexpcolAvail = pnl1nimpexpcolAvail;
	this->scrJref1NQuerycol = scrJref1NQuerycol;
	this->pnl1nquerycolAvail = pnl1nquerycolAvail;
	this->scrJrefRef1NControl = scrJrefRef1NControl;
	this->pnlref1ncontrolAvail = pnlref1ncontrolAvail;
	this->scrJrefRef1NQuerymod = scrJrefRef1NQuerymod;
	this->pnlref1nquerymodAvail = pnlref1nquerymodAvail;
	this->scrJref1NCheck = scrJref1NCheck;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREF1NIMPEXPCOL, PNL1NIMPEXPCOLAVAIL, SCRJREF1NQUERYCOL, PNL1NQUERYCOLAVAIL, SCRJREFREF1NCONTROL, PNLREF1NCONTROLAVAIL, SCRJREFREF1NQUERYMOD, PNLREF1NQUERYMODAVAIL, SCRJREF1NCHECK, BUTREGULARIZEACTIVE};
};

bool PnlWznmTcoRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmTcoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmTcoRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefATitle", scrJrefATitle)) add(SCRJREFATITLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlatitleAvail", pnlatitleAvail)) add(PNLATITLEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NImpexpcol", scrJref1NImpexpcol)) add(SCRJREF1NIMPEXPCOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nimpexpcolAvail", pnl1nimpexpcolAvail)) add(PNL1NIMPEXPCOLAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NQuerycol", scrJref1NQuerycol)) add(SCRJREF1NQUERYCOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nquerycolAvail", pnl1nquerycolAvail)) add(PNL1NQUERYCOLAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NControl", scrJrefRef1NControl)) add(SCRJREFREF1NCONTROL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlref1ncontrolAvail", pnlref1ncontrolAvail)) add(PNLREF1NCONTROLAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NQuerymod", scrJrefRef1NQuerymod)) add(SCRJREFREF1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlref1nquerymodAvail", pnlref1nquerymodAvail)) add(PNLREF1NQUERYMODAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NCheck", scrJref1NCheck)) add(SCRJREF1NCHECK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmTcoRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefATitle == comp->scrJrefATitle) insert(items, SCRJREFATITLE);
	if (pnlatitleAvail == comp->pnlatitleAvail) insert(items, PNLATITLEAVAIL);
	if (scrJref1NImpexpcol == comp->scrJref1NImpexpcol) insert(items, SCRJREF1NIMPEXPCOL);
	if (pnl1nimpexpcolAvail == comp->pnl1nimpexpcolAvail) insert(items, PNL1NIMPEXPCOLAVAIL);
	if (scrJref1NQuerycol == comp->scrJref1NQuerycol) insert(items, SCRJREF1NQUERYCOL);
	if (pnl1nquerycolAvail == comp->pnl1nquerycolAvail) insert(items, PNL1NQUERYCOLAVAIL);
	if (scrJrefRef1NControl == comp->scrJrefRef1NControl) insert(items, SCRJREFREF1NCONTROL);
	if (pnlref1ncontrolAvail == comp->pnlref1ncontrolAvail) insert(items, PNLREF1NCONTROLAVAIL);
	if (scrJrefRef1NQuerymod == comp->scrJrefRef1NQuerymod) insert(items, SCRJREFREF1NQUERYMOD);
	if (pnlref1nquerymodAvail == comp->pnlref1nquerymodAvail) insert(items, PNLREF1NQUERYMODAVAIL);
	if (scrJref1NCheck == comp->scrJref1NCheck) insert(items, SCRJREF1NCHECK);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmTcoRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREF1NIMPEXPCOL, PNL1NIMPEXPCOLAVAIL, SCRJREF1NQUERYCOL, PNL1NQUERYCOLAVAIL, SCRJREFREF1NCONTROL, PNLREF1NCONTROLAVAIL, SCRJREFREF1NQUERYMOD, PNLREF1NQUERYMODAVAIL, SCRJREF1NCHECK, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoRec::Tag
 ******************************************************************************/

PnlWznmTcoRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmTcoRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmTcoRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmTcoRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmTcoRec::DpchAppDo
 ******************************************************************************/

PnlWznmTcoRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTCORECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmTcoRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTcoRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTcoRec::DpchEngData
 ******************************************************************************/

PnlWznmTcoRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTCORECDATA)
		{
};

string PnlWznmTcoRec::DpchEngData::getSrefsMask() {
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

void PnlWznmTcoRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmTcoRecData");
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

