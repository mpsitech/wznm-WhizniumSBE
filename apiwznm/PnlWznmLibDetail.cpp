/**
	* \file PnlWznmLibDetail.cpp
	* API code for job PnlWznmLibDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmLibDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmLibDetail::VecVDo
 ******************************************************************************/

uint PnlWznmLibDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butltyeditclick") return BUTLTYEDITCLICK;
	if (s == "butdepviewclick") return BUTDEPVIEWCLICK;

	return(0);
};

string PnlWznmLibDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTLTYEDITCLICK) return("ButLtyEditClick");
	if (ix == BUTDEPVIEWCLICK) return("ButDepViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmLibDetail::ContIac
 ******************************************************************************/

PnlWznmLibDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfVer
			, const uint numFPupLty
			, const string& TxfLty
			, const uint numFLstDep
			, const string& TxfDep
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfTit = TxfTit;
	this->TxfVer = TxfVer;
	this->numFPupLty = numFPupLty;
	this->TxfLty = TxfLty;
	this->numFLstDep = numFLstDep;
	this->TxfDep = TxfDep;
	this->TxfCmt = TxfCmt;

	mask = {TXFTIT, TXFVER, NUMFPUPLTY, TXFLTY, NUMFLSTDEP, TXFDEP, TXFCMT};
};

bool PnlWznmLibDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmLibDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmLibDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVer", TxfVer)) add(TXFVER);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLty", numFPupLty)) add(NUMFPUPLTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLty", TxfLty)) add(TXFLTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDep", numFLstDep)) add(NUMFLSTDEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDep", TxfDep)) add(TXFDEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmLibDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmLibDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmLibDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfVer", TxfVer);
		writeUintAttr(wr, itemtag, "sref", "numFPupLty", numFPupLty);
		writeStringAttr(wr, itemtag, "sref", "TxfLty", TxfLty);
		writeUintAttr(wr, itemtag, "sref", "numFLstDep", numFLstDep);
		writeStringAttr(wr, itemtag, "sref", "TxfDep", TxfDep);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmLibDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfVer == comp->TxfVer) insert(items, TXFVER);
	if (numFPupLty == comp->numFPupLty) insert(items, NUMFPUPLTY);
	if (TxfLty == comp->TxfLty) insert(items, TXFLTY);
	if (numFLstDep == comp->numFLstDep) insert(items, NUMFLSTDEP);
	if (TxfDep == comp->TxfDep) insert(items, TXFDEP);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmLibDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFVER, NUMFPUPLTY, TXFLTY, NUMFLSTDEP, TXFDEP, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibDetail::ContInf
 ******************************************************************************/

PnlWznmLibDetail::ContInf::ContInf(
			const string& TxtSrf
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;

	mask = {TXTSRF};
};

bool PnlWznmLibDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmLibDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmLibDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
	};

	return basefound;
};

set<uint> PnlWznmLibDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);

	return(items);
};

set<uint> PnlWznmLibDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibDetail::StatApp
 ******************************************************************************/

PnlWznmLibDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool PupLtyAlt
			, const bool LstDepAlt
			, const uint LstDepNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->PupLtyAlt = PupLtyAlt;
	this->LstDepAlt = LstDepAlt;
	this->LstDepNumFirstdisp = LstDepNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, PUPLTYALT, LSTDEPALT, LSTDEPNUMFIRSTDISP};
};

bool PnlWznmLibDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmLibDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmLibDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupLtyAlt", PupLtyAlt)) add(PUPLTYALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDepAlt", LstDepAlt)) add(LSTDEPALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDepNumFirstdisp", LstDepNumFirstdisp)) add(LSTDEPNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmLibDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (PupLtyAlt == comp->PupLtyAlt) insert(items, PUPLTYALT);
	if (LstDepAlt == comp->LstDepAlt) insert(items, LSTDEPALT);
	if (LstDepNumFirstdisp == comp->LstDepNumFirstdisp) insert(items, LSTDEPNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmLibDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, PUPLTYALT, LSTDEPALT, LSTDEPNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibDetail::StatShr
 ******************************************************************************/

PnlWznmLibDetail::StatShr::StatShr(
			const bool TxfLtyValid
			, const bool TxfDepValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfTitActive
			, const bool TxfVerActive
			, const bool PupLtyActive
			, const bool ButLtyEditAvail
			, const bool LstDepActive
			, const bool ButDepViewAvail
			, const bool ButDepViewActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfLtyValid = TxfLtyValid;
	this->TxfDepValid = TxfDepValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfTitActive = TxfTitActive;
	this->TxfVerActive = TxfVerActive;
	this->PupLtyActive = PupLtyActive;
	this->ButLtyEditAvail = ButLtyEditAvail;
	this->LstDepActive = LstDepActive;
	this->ButDepViewAvail = ButDepViewAvail;
	this->ButDepViewActive = ButDepViewActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFLTYVALID, TXFDEPVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFVERACTIVE, PUPLTYACTIVE, BUTLTYEDITAVAIL, LSTDEPACTIVE, BUTDEPVIEWAVAIL, BUTDEPVIEWACTIVE, TXFCMTACTIVE};
};

bool PnlWznmLibDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmLibDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmLibDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfLtyValid", TxfLtyValid)) add(TXFLTYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDepValid", TxfDepValid)) add(TXFDEPVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfVerActive", TxfVerActive)) add(TXFVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupLtyActive", PupLtyActive)) add(PUPLTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLtyEditAvail", ButLtyEditAvail)) add(BUTLTYEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDepActive", LstDepActive)) add(LSTDEPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDepViewAvail", ButDepViewAvail)) add(BUTDEPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDepViewActive", ButDepViewActive)) add(BUTDEPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmLibDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfLtyValid == comp->TxfLtyValid) insert(items, TXFLTYVALID);
	if (TxfDepValid == comp->TxfDepValid) insert(items, TXFDEPVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfVerActive == comp->TxfVerActive) insert(items, TXFVERACTIVE);
	if (PupLtyActive == comp->PupLtyActive) insert(items, PUPLTYACTIVE);
	if (ButLtyEditAvail == comp->ButLtyEditAvail) insert(items, BUTLTYEDITAVAIL);
	if (LstDepActive == comp->LstDepActive) insert(items, LSTDEPACTIVE);
	if (ButDepViewAvail == comp->ButDepViewAvail) insert(items, BUTDEPVIEWAVAIL);
	if (ButDepViewActive == comp->ButDepViewActive) insert(items, BUTDEPVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmLibDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFLTYVALID, TXFDEPVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFVERACTIVE, PUPLTYACTIVE, BUTLTYEDITAVAIL, LSTDEPACTIVE, BUTDEPVIEWAVAIL, BUTDEPVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibDetail::Tag
 ******************************************************************************/

PnlWznmLibDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptVer
			, const string& CptLty
			, const string& CptDep
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptVer = CptVer;
	this->CptLty = CptLty;
	this->CptDep = CptDep;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTTIT, CPTVER, CPTLTY, CPTDEP, CPTCMT};
};

bool PnlWznmLibDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmLibDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmLibDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLty", CptLty)) add(CPTLTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDep", CptDep)) add(CPTDEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmLibDetail::DpchAppData
 ******************************************************************************/

PnlWznmLibDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMLIBDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmLibDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmLibDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmLibDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmLibDetail::DpchAppDo
 ******************************************************************************/

PnlWznmLibDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMLIBDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmLibDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmLibDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmLibDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmLibDetail::DpchEngData
 ******************************************************************************/

PnlWznmLibDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMLIBDETAILDATA)
		{
	feedFLstDep.tag = "FeedFLstDep";
	feedFPupLty.tag = "FeedFPupLty";
};

string PnlWznmLibDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDEP)) ss.push_back("feedFLstDep");
	if (has(FEEDFPUPLTY)) ss.push_back("feedFPupLty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmLibDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmLibDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstDep.readXML(docctx, basexpath, true)) add(FEEDFLSTDEP);
		if (feedFPupLty.readXML(docctx, basexpath, true)) add(FEEDFPUPLTY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstDep.clear();
		feedFPupLty.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

