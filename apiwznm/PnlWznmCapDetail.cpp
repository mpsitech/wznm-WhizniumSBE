/**
	* \file PnlWznmCapDetail.cpp
	* API code for job PnlWznmCapDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmCapDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmCapDetail::VecVDo
 ******************************************************************************/

uint PnlWznmCapDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "buttplviewclick") return BUTTPLVIEWCLICK;

	return(0);
};

string PnlWznmCapDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTTPLVIEWCLICK) return("ButTplViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmCapDetail::ContIac
 ******************************************************************************/

PnlWznmCapDetail::ContIac::ContIac(
			const string& TxfTit
			, const vector<uint>& numsFLstAtf
		) :
			Block()
		{
	this->TxfTit = TxfTit;
	this->numsFLstAtf = numsFLstAtf;

	mask = {TXFTIT, NUMSFLSTATF};
};

bool PnlWznmCapDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmCapDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmCapDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstAtf", numsFLstAtf)) add(NUMSFLSTATF);
	};

	return basefound;
};

void PnlWznmCapDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmCapDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmCapDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstAtf", numsFLstAtf);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmCapDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (compareUintvec(numsFLstAtf, comp->numsFLstAtf)) insert(items, NUMSFLSTATF);

	return(items);
};

set<uint> PnlWznmCapDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMSFLSTATF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCapDetail::ContInf
 ******************************************************************************/

PnlWznmCapDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVer
			, const string& TxtTpl
			, const string& TxtAtf
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtVer = TxtVer;
	this->TxtTpl = TxtTpl;
	this->TxtAtf = TxtAtf;

	mask = {TXTSRF, TXTVER, TXTTPL, TXTATF};
};

bool PnlWznmCapDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmCapDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmCapDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTpl", TxtTpl)) add(TXTTPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtAtf", TxtAtf)) add(TXTATF);
	};

	return basefound;
};

set<uint> PnlWznmCapDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtTpl == comp->TxtTpl) insert(items, TXTTPL);
	if (TxtAtf == comp->TxtAtf) insert(items, TXTATF);

	return(items);
};

set<uint> PnlWznmCapDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVER, TXTTPL, TXTATF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCapDetail::StatApp
 ******************************************************************************/

PnlWznmCapDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstAtfAlt
			, const uint LstAtfNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstAtfAlt = LstAtfAlt;
	this->LstAtfNumFirstdisp = LstAtfNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTATFALT, LSTATFNUMFIRSTDISP};
};

bool PnlWznmCapDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmCapDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmCapDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAtfAlt", LstAtfAlt)) add(LSTATFALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAtfNumFirstdisp", LstAtfNumFirstdisp)) add(LSTATFNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmCapDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstAtfAlt == comp->LstAtfAlt) insert(items, LSTATFALT);
	if (LstAtfNumFirstdisp == comp->LstAtfNumFirstdisp) insert(items, LSTATFNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmCapDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTATFALT, LSTATFNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCapDetail::StatShr
 ******************************************************************************/

PnlWznmCapDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfTitActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtTplActive
			, const bool ButTplViewAvail
			, const bool ButTplViewActive
			, const bool LstAtfActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfTitActive = TxfTitActive;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtTplActive = TxtTplActive;
	this->ButTplViewAvail = ButTplViewAvail;
	this->ButTplViewActive = ButTplViewActive;
	this->LstAtfActive = LstAtfActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, LSTATFACTIVE};
};

bool PnlWznmCapDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmCapDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmCapDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerActive", TxtVerActive)) add(TXTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", ButVerViewAvail)) add(BUTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTplActive", TxtTplActive)) add(TXTTPLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTplViewAvail", ButTplViewAvail)) add(BUTTPLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTplViewActive", ButTplViewActive)) add(BUTTPLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAtfActive", LstAtfActive)) add(LSTATFACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmCapDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtTplActive == comp->TxtTplActive) insert(items, TXTTPLACTIVE);
	if (ButTplViewAvail == comp->ButTplViewAvail) insert(items, BUTTPLVIEWAVAIL);
	if (ButTplViewActive == comp->ButTplViewActive) insert(items, BUTTPLVIEWACTIVE);
	if (LstAtfActive == comp->LstAtfActive) insert(items, LSTATFACTIVE);

	return(items);
};

set<uint> PnlWznmCapDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, LSTATFACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCapDetail::Tag
 ******************************************************************************/

PnlWznmCapDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptVer
			, const string& CptTpl
			, const string& CptAtf
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptVer = CptVer;
	this->CptTpl = CptTpl;
	this->CptAtf = CptAtf;

	mask = {CPT, CPTSRF, CPTTIT, CPTVER, CPTTPL, CPTATF};
};

bool PnlWznmCapDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmCapDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmCapDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTpl", CptTpl)) add(CPTTPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAtf", CptAtf)) add(CPTATF);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmCapDetail::DpchAppData
 ******************************************************************************/

PnlWznmCapDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCAPDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmCapDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCapDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmCapDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCapDetail::DpchAppDo
 ******************************************************************************/

PnlWznmCapDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCAPDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmCapDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCapDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmCapDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCapDetail::DpchEngData
 ******************************************************************************/

PnlWznmCapDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCAPDETAILDATA)
		{
	feedFLstAtf.tag = "FeedFLstAtf";
};

string PnlWznmCapDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTATF)) ss.push_back("feedFLstAtf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCapDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmCapDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstAtf.readXML(docctx, basexpath, true)) add(FEEDFLSTATF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstAtf.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
