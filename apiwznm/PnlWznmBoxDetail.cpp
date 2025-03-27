/**
	* \file PnlWznmBoxDetail.cpp
	* API code for job PnlWznmBoxDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "PnlWznmBoxDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmBoxDetail::VecVDo
 ******************************************************************************/

uint PnlWznmBoxDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butshtviewclick") return BUTSHTVIEWCLICK;

	return(0);
};

string PnlWznmBoxDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmBoxDetail::ContIac
 ******************************************************************************/

PnlWznmBoxDetail::ContIac::ContIac(
			const uint numFPupY
			, const string& TxfX
			, const string& TxfY
		) :
			Block()
			, numFPupY(numFPupY)
			, TxfX(TxfX)
			, TxfY(TxfY)
		{
	mask = {NUMFPUPY, TXFX, TXFY};
};

bool PnlWznmBoxDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmBoxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmBoxDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupY", numFPupY)) add(NUMFPUPY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX", TxfX)) add(TXFX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY", TxfY)) add(TXFY);
	};

	return basefound;
};

void PnlWznmBoxDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmBoxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmBoxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupY", numFPupY);
		writeStringAttr(wr, itemtag, "sref", "TxfX", TxfX);
		writeStringAttr(wr, itemtag, "sref", "TxfY", TxfY);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmBoxDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupY == comp->numFPupY) insert(items, NUMFPUPY);
	if (TxfX == comp->TxfX) insert(items, TXFX);
	if (TxfY == comp->TxfY) insert(items, TXFY);

	return(items);
};

set<uint> PnlWznmBoxDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPY, TXFX, TXFY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmBoxDetail::ContInf
 ******************************************************************************/

PnlWznmBoxDetail::ContInf::ContInf(
			const string& TxtSht
			, const string& TxtUnv
		) :
			Block()
			, TxtSht(TxtSht)
			, TxtUnv(TxtUnv)
		{
	mask = {TXTSHT, TXTUNV};
};

bool PnlWznmBoxDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmBoxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmBoxDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSht", TxtSht)) add(TXTSHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtUnv", TxtUnv)) add(TXTUNV);
	};

	return basefound;
};

set<uint> PnlWznmBoxDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSht == comp->TxtSht) insert(items, TXTSHT);
	if (TxtUnv == comp->TxtUnv) insert(items, TXTUNV);

	return(items);
};

set<uint> PnlWznmBoxDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSHT, TXTUNV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmBoxDetail::StatApp
 ******************************************************************************/

PnlWznmBoxDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
		{
	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmBoxDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmBoxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmBoxDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmBoxDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmBoxDetail::StatApp::diff(
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
 class PnlWznmBoxDetail::StatShr
 ******************************************************************************/

PnlWznmBoxDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtShtActive
			, const bool ButShtViewAvail
			, const bool ButShtViewActive
			, const bool TxtUnvActive
			, const bool TxfXActive
			, const bool TxfYActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtShtActive(TxtShtActive)
			, ButShtViewAvail(ButShtViewAvail)
			, ButShtViewActive(ButShtViewActive)
			, TxtUnvActive(TxtUnvActive)
			, TxfXActive(TxfXActive)
			, TxfYActive(TxfYActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSHTACTIVE, BUTSHTVIEWAVAIL, BUTSHTVIEWACTIVE, TXTUNVACTIVE, TXFXACTIVE, TXFYACTIVE};
};

bool PnlWznmBoxDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmBoxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmBoxDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtShtActive", TxtShtActive)) add(TXTSHTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButShtViewAvail", ButShtViewAvail)) add(BUTSHTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButShtViewActive", ButShtViewActive)) add(BUTSHTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtUnvActive", TxtUnvActive)) add(TXTUNVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXActive", TxfXActive)) add(TXFXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfYActive", TxfYActive)) add(TXFYACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmBoxDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtShtActive == comp->TxtShtActive) insert(items, TXTSHTACTIVE);
	if (ButShtViewAvail == comp->ButShtViewAvail) insert(items, BUTSHTVIEWAVAIL);
	if (ButShtViewActive == comp->ButShtViewActive) insert(items, BUTSHTVIEWACTIVE);
	if (TxtUnvActive == comp->TxtUnvActive) insert(items, TXTUNVACTIVE);
	if (TxfXActive == comp->TxfXActive) insert(items, TXFXACTIVE);
	if (TxfYActive == comp->TxfYActive) insert(items, TXFYACTIVE);

	return(items);
};

set<uint> PnlWznmBoxDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSHTACTIVE, BUTSHTVIEWAVAIL, BUTSHTVIEWACTIVE, TXTUNVACTIVE, TXFXACTIVE, TXFYACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmBoxDetail::Tag
 ******************************************************************************/

PnlWznmBoxDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSht
			, const string& CptUnv
			, const string& CptX
			, const string& CptY
		) :
			Block()
			, Cpt(Cpt)
			, CptSht(CptSht)
			, CptUnv(CptUnv)
			, CptX(CptX)
			, CptY(CptY)
		{
	mask = {CPT, CPTSHT, CPTUNV, CPTX, CPTY};
};

bool PnlWznmBoxDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmBoxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmBoxDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSht", CptSht)) add(CPTSHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUnv", CptUnv)) add(CPTUNV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptX", CptX)) add(CPTX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptY", CptY)) add(CPTY);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmBoxDetail::DpchAppData
 ******************************************************************************/

PnlWznmBoxDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMBOXDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmBoxDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmBoxDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmBoxDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmBoxDetail::DpchAppDo
 ******************************************************************************/

PnlWznmBoxDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMBOXDETAILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmBoxDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmBoxDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmBoxDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmBoxDetail::DpchEngData
 ******************************************************************************/

PnlWznmBoxDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMBOXDETAILDATA)
		{
	feedFPupY.tag = "FeedFPupY";
};

string PnlWznmBoxDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPY)) ss.push_back("feedFPupY");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmBoxDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmBoxDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupY.readXML(docctx, basexpath, true)) add(FEEDFPUPY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupY.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
