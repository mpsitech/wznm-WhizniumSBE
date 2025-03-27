/**
	* \file PnlWznmTagDetail.cpp
	* API code for job PnlWznmTagDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmTagDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTagDetail::VecVDo
 ******************************************************************************/

uint PnlWznmTagDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjtieditclick") return BUTJTIEDITCLICK;
	if (s == "butcpbviewclick") return BUTCPBVIEWCLICK;
	if (s == "butgrpeditclick") return BUTGRPEDITCLICK;

	return(0);
};

string PnlWznmTagDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
	if (ix == BUTCPBVIEWCLICK) return("ButCpbViewClick");
	if (ix == BUTGRPEDITCLICK) return("ButGrpEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmTagDetail::ContIac
 ******************************************************************************/

PnlWznmTagDetail::ContIac::ContIac(
			const uint numFPupJti
			, const uint numFPupGrp
			, const string& TxfGrp
		) :
			Block()
			, numFPupJti(numFPupJti)
			, numFPupGrp(numFPupGrp)
			, TxfGrp(TxfGrp)
		{
	mask = {NUMFPUPJTI, NUMFPUPGRP, TXFGRP};
};

bool PnlWznmTagDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmTagDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmTagDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJti", numFPupJti)) add(NUMFPUPJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupGrp", numFPupGrp)) add(NUMFPUPGRP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfGrp", TxfGrp)) add(TXFGRP);
	};

	return basefound;
};

void PnlWznmTagDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmTagDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmTagDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJti", numFPupJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupGrp", numFPupGrp);
		writeStringAttr(wr, itemtag, "sref", "TxfGrp", TxfGrp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTagDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJti == comp->numFPupJti) insert(items, NUMFPUPJTI);
	if (numFPupGrp == comp->numFPupGrp) insert(items, NUMFPUPGRP);
	if (TxfGrp == comp->TxfGrp) insert(items, TXFGRP);

	return(items);
};

set<uint> PnlWznmTagDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJTI, NUMFPUPGRP, TXFGRP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTagDetail::ContInf
 ******************************************************************************/

PnlWznmTagDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtCpb
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtTit(TxtTit)
			, TxtCpb(TxtCpb)
		{
	mask = {TXTSRF, TXTTIT, TXTCPB};
};

bool PnlWznmTagDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmTagDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmTagDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTit", TxtTit)) add(TXTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCpb", TxtCpb)) add(TXTCPB);
	};

	return basefound;
};

set<uint> PnlWznmTagDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtCpb == comp->TxtCpb) insert(items, TXTCPB);

	return(items);
};

set<uint> PnlWznmTagDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTCPB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTagDetail::StatApp
 ******************************************************************************/

PnlWznmTagDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool PupGrpAlt
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
			, PupGrpAlt(PupGrpAlt)
		{
	mask = {IXWZNMVEXPSTATE, PUPGRPALT};
};

bool PnlWznmTagDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmTagDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmTagDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupGrpAlt", PupGrpAlt)) add(PUPGRPALT);
	};

	return basefound;
};

set<uint> PnlWznmTagDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (PupGrpAlt == comp->PupGrpAlt) insert(items, PUPGRPALT);

	return(items);
};

set<uint> PnlWznmTagDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, PUPGRPALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTagDetail::StatShr
 ******************************************************************************/

PnlWznmTagDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJtiActive
			, const bool ButJtiEditAvail
			, const bool TxtTitActive
			, const bool TxtCpbActive
			, const bool ButCpbViewAvail
			, const bool ButCpbViewActive
			, const bool PupGrpActive
			, const bool TxfGrpValid
			, const bool ButGrpEditAvail
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, PupJtiActive(PupJtiActive)
			, ButJtiEditAvail(ButJtiEditAvail)
			, TxtTitActive(TxtTitActive)
			, TxtCpbActive(TxtCpbActive)
			, ButCpbViewAvail(ButCpbViewAvail)
			, ButCpbViewActive(ButCpbViewActive)
			, PupGrpActive(PupGrpActive)
			, TxfGrpValid(TxfGrpValid)
			, ButGrpEditAvail(ButGrpEditAvail)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTCPBACTIVE, BUTCPBVIEWAVAIL, BUTCPBVIEWACTIVE, PUPGRPACTIVE, TXFGRPVALID, BUTGRPEDITAVAIL};
};

bool PnlWznmTagDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmTagDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmTagDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJtiActive", PupJtiActive)) add(PUPJTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", ButJtiEditAvail)) add(BUTJTIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTitActive", TxtTitActive)) add(TXTTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCpbActive", TxtCpbActive)) add(TXTCPBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCpbViewAvail", ButCpbViewAvail)) add(BUTCPBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCpbViewActive", ButCpbViewActive)) add(BUTCPBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupGrpActive", PupGrpActive)) add(PUPGRPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfGrpValid", TxfGrpValid)) add(TXFGRPVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButGrpEditAvail", ButGrpEditAvail)) add(BUTGRPEDITAVAIL);
	};

	return basefound;
};

set<uint> PnlWznmTagDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJtiActive == comp->PupJtiActive) insert(items, PUPJTIACTIVE);
	if (ButJtiEditAvail == comp->ButJtiEditAvail) insert(items, BUTJTIEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (TxtCpbActive == comp->TxtCpbActive) insert(items, TXTCPBACTIVE);
	if (ButCpbViewAvail == comp->ButCpbViewAvail) insert(items, BUTCPBVIEWAVAIL);
	if (ButCpbViewActive == comp->ButCpbViewActive) insert(items, BUTCPBVIEWACTIVE);
	if (PupGrpActive == comp->PupGrpActive) insert(items, PUPGRPACTIVE);
	if (TxfGrpValid == comp->TxfGrpValid) insert(items, TXFGRPVALID);
	if (ButGrpEditAvail == comp->ButGrpEditAvail) insert(items, BUTGRPEDITAVAIL);

	return(items);
};

set<uint> PnlWznmTagDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTCPBACTIVE, BUTCPBVIEWAVAIL, BUTCPBVIEWACTIVE, PUPGRPACTIVE, TXFGRPVALID, BUTGRPEDITAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTagDetail::Tag
 ******************************************************************************/

PnlWznmTagDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptCpb
			, const string& CptGrp
		) :
			Block()
			, Cpt(Cpt)
			, CptSrf(CptSrf)
			, CptTit(CptTit)
			, CptCpb(CptCpb)
			, CptGrp(CptGrp)
		{
	mask = {CPT, CPTSRF, CPTTIT, CPTCPB, CPTGRP};
};

bool PnlWznmTagDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmTagDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmTagDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCpb", CptCpb)) add(CPTCPB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptGrp", CptGrp)) add(CPTGRP);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmTagDetail::DpchAppData
 ******************************************************************************/

PnlWznmTagDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTAGDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmTagDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTagDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTagDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTagDetail::DpchAppDo
 ******************************************************************************/

PnlWznmTagDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTAGDETAILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmTagDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTagDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTagDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTagDetail::DpchEngData
 ******************************************************************************/

PnlWznmTagDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTAGDETAILDATA)
		{
	feedFPupGrp.tag = "FeedFPupGrp";
	feedFPupJti.tag = "FeedFPupJti";
};

string PnlWznmTagDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPGRP)) ss.push_back("feedFPupGrp");
	if (has(FEEDFPUPJTI)) ss.push_back("feedFPupJti");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTagDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmTagDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupGrp.readXML(docctx, basexpath, true)) add(FEEDFPUPGRP);
		if (feedFPupJti.readXML(docctx, basexpath, true)) add(FEEDFPUPJTI);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupGrp.clear();
		feedFPupJti.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
