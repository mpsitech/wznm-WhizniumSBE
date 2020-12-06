/**
	* \file PnlWznmVitDetail.cpp
	* API code for job PnlWznmVitDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmVitDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVitDetail::VecVDo
 ******************************************************************************/

uint PnlWznmVitDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjeditclick") return BUTJEDITCLICK;
	if (s == "butvecviewclick") return BUTVECVIEWCLICK;

	return(0);
};

string PnlWznmVitDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJEDITCLICK) return("ButJEditClick");
	if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmVitDetail::ContIac
 ******************************************************************************/

PnlWznmVitDetail::ContIac::ContIac(
			const uint numFPupJ
			, const string& TxfAvl
			, const string& TxfImp
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupJ = numFPupJ;
	this->TxfAvl = TxfAvl;
	this->TxfImp = TxfImp;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPJ, TXFAVL, TXFIMP, TXFCMT};
};

bool PnlWznmVitDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmVitDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmVitDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAvl", TxfAvl)) add(TXFAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImp", TxfImp)) add(TXFIMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmVitDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmVitDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmVitDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeStringAttr(wr, itemtag, "sref", "TxfAvl", TxfAvl);
		writeStringAttr(wr, itemtag, "sref", "TxfImp", TxfImp);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVitDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (TxfAvl == comp->TxfAvl) insert(items, TXFAVL);
	if (TxfImp == comp->TxfImp) insert(items, TXFIMP);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmVitDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJ, TXFAVL, TXFIMP, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVitDetail::ContInf
 ******************************************************************************/

PnlWznmVitDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtVec
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtVec = TxtVec;

	mask = {TXTSRF, TXTTIT, TXTVEC};
};

bool PnlWznmVitDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmVitDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmVitDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTit", TxtTit)) add(TXTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVec", TxtVec)) add(TXTVEC);
	};

	return basefound;
};

set<uint> PnlWznmVitDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtVec == comp->TxtVec) insert(items, TXTVEC);

	return(items);
};

set<uint> PnlWznmVitDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTVEC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVitDetail::StatApp
 ******************************************************************************/

PnlWznmVitDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmVitDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmVitDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmVitDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmVitDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmVitDetail::StatApp::diff(
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
 class PnlWznmVitDetail::StatShr
 ******************************************************************************/

PnlWznmVitDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJActive
			, const bool ButJEditAvail
			, const bool TxtTitActive
			, const bool TxtVecActive
			, const bool ButVecViewAvail
			, const bool ButVecViewActive
			, const bool TxfAvlActive
			, const bool TxfImpActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupJActive = PupJActive;
	this->ButJEditAvail = ButJEditAvail;
	this->TxtTitActive = TxtTitActive;
	this->TxtVecActive = TxtVecActive;
	this->ButVecViewAvail = ButVecViewAvail;
	this->ButVecViewActive = ButVecViewActive;
	this->TxfAvlActive = TxfAvlActive;
	this->TxfImpActive = TxfImpActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTTITACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, TXFAVLACTIVE, TXFIMPACTIVE, TXFCMTACTIVE};
};

bool PnlWznmVitDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmVitDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmVitDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJActive", PupJActive)) add(PUPJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJEditAvail", ButJEditAvail)) add(BUTJEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTitActive", TxtTitActive)) add(TXTTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVecActive", TxtVecActive)) add(TXTVECACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVecViewAvail", ButVecViewAvail)) add(BUTVECVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVecViewActive", ButVecViewActive)) add(BUTVECVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAvlActive", TxfAvlActive)) add(TXFAVLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfImpActive", TxfImpActive)) add(TXFIMPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmVitDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJActive == comp->PupJActive) insert(items, PUPJACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (TxtVecActive == comp->TxtVecActive) insert(items, TXTVECACTIVE);
	if (ButVecViewAvail == comp->ButVecViewAvail) insert(items, BUTVECVIEWAVAIL);
	if (ButVecViewActive == comp->ButVecViewActive) insert(items, BUTVECVIEWACTIVE);
	if (TxfAvlActive == comp->TxfAvlActive) insert(items, TXFAVLACTIVE);
	if (TxfImpActive == comp->TxfImpActive) insert(items, TXFIMPACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmVitDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTTITACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, TXFAVLACTIVE, TXFIMPACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVitDetail::Tag
 ******************************************************************************/

PnlWznmVitDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptVec
			, const string& CptAvl
			, const string& CptImp
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptVec = CptVec;
	this->CptAvl = CptAvl;
	this->CptImp = CptImp;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTTIT, CPTVEC, CPTAVL, CPTIMP, CPTCMT};
};

bool PnlWznmVitDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmVitDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmVitDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVec", CptVec)) add(CPTVEC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAvl", CptAvl)) add(CPTAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptImp", CptImp)) add(CPTIMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmVitDetail::DpchAppData
 ******************************************************************************/

PnlWznmVitDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVITDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmVitDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVitDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVitDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVitDetail::DpchAppDo
 ******************************************************************************/

PnlWznmVitDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVITDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmVitDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVitDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVitDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVitDetail::DpchEngData
 ******************************************************************************/

PnlWznmVitDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVITDETAILDATA)
		{
	feedFPupJ.tag = "FeedFPupJ";
};

string PnlWznmVitDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVitDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmVitDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupJ.readXML(docctx, basexpath, true)) add(FEEDFPUPJ);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupJ.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
