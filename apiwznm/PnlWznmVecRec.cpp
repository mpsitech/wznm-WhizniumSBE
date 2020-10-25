/**
	* \file PnlWznmVecRec.cpp
	* API code for job PnlWznmVecRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmVecRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVecRec::VecVDo
 ******************************************************************************/

uint PnlWznmVecRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmVecRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmVecRec::ContInf
 ******************************************************************************/

PnlWznmVecRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmVecRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmVecRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmVecRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmVecRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmVecRec::ContInf::diff(
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
 class PnlWznmVecRec::StatApp
 ******************************************************************************/

PnlWznmVecRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdoneVec1NVectoritem
			, const bool initdoneSrc1NFeed
			, const bool initdoneRef1NPanel
			, const bool initdoneFct1NTablecol
			, const bool initdonePst1NQuerymod
			, const bool initdoneMNTable
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneATitle = initdoneATitle;
	this->initdoneVec1NVectoritem = initdoneVec1NVectoritem;
	this->initdoneSrc1NFeed = initdoneSrc1NFeed;
	this->initdoneRef1NPanel = initdoneRef1NPanel;
	this->initdoneFct1NTablecol = initdoneFct1NTablecol;
	this->initdonePst1NQuerymod = initdonePst1NQuerymod;
	this->initdoneMNTable = initdoneMNTable;

	mask = {INITDONEDETAIL, INITDONEATITLE, INITDONEVEC1NVECTORITEM, INITDONESRC1NFEED, INITDONEREF1NPANEL, INITDONEFCT1NTABLECOL, INITDONEPST1NQUERYMOD, INITDONEMNTABLE};
};

bool PnlWznmVecRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmVecRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmVecRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneATitle", initdoneATitle)) add(INITDONEATITLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneVec1NVectoritem", initdoneVec1NVectoritem)) add(INITDONEVEC1NVECTORITEM);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSrc1NFeed", initdoneSrc1NFeed)) add(INITDONESRC1NFEED);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NPanel", initdoneRef1NPanel)) add(INITDONEREF1NPANEL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFct1NTablecol", initdoneFct1NTablecol)) add(INITDONEFCT1NTABLECOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePst1NQuerymod", initdonePst1NQuerymod)) add(INITDONEPST1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNTable", initdoneMNTable)) add(INITDONEMNTABLE);
	};

	return basefound;
};

set<uint> PnlWznmVecRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneATitle == comp->initdoneATitle) insert(items, INITDONEATITLE);
	if (initdoneVec1NVectoritem == comp->initdoneVec1NVectoritem) insert(items, INITDONEVEC1NVECTORITEM);
	if (initdoneSrc1NFeed == comp->initdoneSrc1NFeed) insert(items, INITDONESRC1NFEED);
	if (initdoneRef1NPanel == comp->initdoneRef1NPanel) insert(items, INITDONEREF1NPANEL);
	if (initdoneFct1NTablecol == comp->initdoneFct1NTablecol) insert(items, INITDONEFCT1NTABLECOL);
	if (initdonePst1NQuerymod == comp->initdonePst1NQuerymod) insert(items, INITDONEPST1NQUERYMOD);
	if (initdoneMNTable == comp->initdoneMNTable) insert(items, INITDONEMNTABLE);

	return(items);
};

set<uint> PnlWznmVecRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEATITLE, INITDONEVEC1NVECTORITEM, INITDONESRC1NFEED, INITDONEREF1NPANEL, INITDONEFCT1NTABLECOL, INITDONEPST1NQUERYMOD, INITDONEMNTABLE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecRec::StatShr
 ******************************************************************************/

PnlWznmVecRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefATitle
			, const string& scrJrefVec1NVectoritem
			, const string& scrJrefSrc1NFeed
			, const string& scrJrefRef1NPanel
			, const string& scrJrefFct1NTablecol
			, const bool pnlfct1ntablecolAvail
			, const string& scrJrefPst1NQuerymod
			, const bool pnlpst1nquerymodAvail
			, const string& scrJrefMNTable
			, const bool pnlmntableAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefATitle = scrJrefATitle;
	this->scrJrefVec1NVectoritem = scrJrefVec1NVectoritem;
	this->scrJrefSrc1NFeed = scrJrefSrc1NFeed;
	this->scrJrefRef1NPanel = scrJrefRef1NPanel;
	this->scrJrefFct1NTablecol = scrJrefFct1NTablecol;
	this->pnlfct1ntablecolAvail = pnlfct1ntablecolAvail;
	this->scrJrefPst1NQuerymod = scrJrefPst1NQuerymod;
	this->pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
	this->scrJrefMNTable = scrJrefMNTable;
	this->pnlmntableAvail = pnlmntableAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFVEC1NVECTORITEM, SCRJREFSRC1NFEED, SCRJREFREF1NPANEL, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNTABLE, PNLMNTABLEAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWznmVecRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmVecRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmVecRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefATitle", scrJrefATitle)) add(SCRJREFATITLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefVec1NVectoritem", scrJrefVec1NVectoritem)) add(SCRJREFVEC1NVECTORITEM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrc1NFeed", scrJrefSrc1NFeed)) add(SCRJREFSRC1NFEED);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NPanel", scrJrefRef1NPanel)) add(SCRJREFREF1NPANEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFct1NTablecol", scrJrefFct1NTablecol)) add(SCRJREFFCT1NTABLECOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlfct1ntablecolAvail", pnlfct1ntablecolAvail)) add(PNLFCT1NTABLECOLAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPst1NQuerymod", scrJrefPst1NQuerymod)) add(SCRJREFPST1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpst1nquerymodAvail", pnlpst1nquerymodAvail)) add(PNLPST1NQUERYMODAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNTable", scrJrefMNTable)) add(SCRJREFMNTABLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmntableAvail", pnlmntableAvail)) add(PNLMNTABLEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmVecRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefATitle == comp->scrJrefATitle) insert(items, SCRJREFATITLE);
	if (scrJrefVec1NVectoritem == comp->scrJrefVec1NVectoritem) insert(items, SCRJREFVEC1NVECTORITEM);
	if (scrJrefSrc1NFeed == comp->scrJrefSrc1NFeed) insert(items, SCRJREFSRC1NFEED);
	if (scrJrefRef1NPanel == comp->scrJrefRef1NPanel) insert(items, SCRJREFREF1NPANEL);
	if (scrJrefFct1NTablecol == comp->scrJrefFct1NTablecol) insert(items, SCRJREFFCT1NTABLECOL);
	if (pnlfct1ntablecolAvail == comp->pnlfct1ntablecolAvail) insert(items, PNLFCT1NTABLECOLAVAIL);
	if (scrJrefPst1NQuerymod == comp->scrJrefPst1NQuerymod) insert(items, SCRJREFPST1NQUERYMOD);
	if (pnlpst1nquerymodAvail == comp->pnlpst1nquerymodAvail) insert(items, PNLPST1NQUERYMODAVAIL);
	if (scrJrefMNTable == comp->scrJrefMNTable) insert(items, SCRJREFMNTABLE);
	if (pnlmntableAvail == comp->pnlmntableAvail) insert(items, PNLMNTABLEAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmVecRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFVEC1NVECTORITEM, SCRJREFSRC1NFEED, SCRJREFREF1NPANEL, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNTABLE, PNLMNTABLEAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecRec::Tag
 ******************************************************************************/

PnlWznmVecRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmVecRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmVecRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmVecRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmVecRec::DpchAppDo
 ******************************************************************************/

PnlWznmVecRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVECRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmVecRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVecRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVecRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVecRec::DpchEngData
 ******************************************************************************/

PnlWznmVecRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVECRECDATA)
		{
};

string PnlWznmVecRec::DpchEngData::getSrefsMask() {
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

void PnlWznmVecRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmVecRecData");
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

