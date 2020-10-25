/**
	* \file PnlWznmImeDetail.cpp
	* API code for job PnlWznmImeDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmImeDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmImeDetail::VecVDo
 ******************************************************************************/

uint PnlWznmImeDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butiexviewclick") return BUTIEXVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butrtrviewclick") return BUTRTRVIEWCLICK;

	return(0);
};

string PnlWznmImeDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTIEXVIEWCLICK) return("ButIexViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTRTRVIEWCLICK) return("ButRtrViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmImeDetail::ContIac
 ******************************************************************************/

PnlWznmImeDetail::ContIac::ContIac(
			const vector<uint>& numsFLstIop
			, const uint numFLstRtr
			, const string& TxfRtr
			, const string& TxfCmt
		) :
			Block()
		{
	this->numsFLstIop = numsFLstIop;
	this->numFLstRtr = numFLstRtr;
	this->TxfRtr = TxfRtr;
	this->TxfCmt = TxfCmt;

	mask = {NUMSFLSTIOP, NUMFLSTRTR, TXFRTR, TXFCMT};
};

bool PnlWznmImeDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmImeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmImeDetail";

	if (basefound) {
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstIop", numsFLstIop)) add(NUMSFLSTIOP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRtr", numFLstRtr)) add(NUMFLSTRTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfRtr", TxfRtr)) add(TXFRTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmImeDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmImeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmImeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstIop", numsFLstIop);
		writeUintAttr(wr, itemtag, "sref", "numFLstRtr", numFLstRtr);
		writeStringAttr(wr, itemtag, "sref", "TxfRtr", TxfRtr);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmImeDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (compareUintvec(numsFLstIop, comp->numsFLstIop)) insert(items, NUMSFLSTIOP);
	if (numFLstRtr == comp->numFLstRtr) insert(items, NUMFLSTRTR);
	if (TxfRtr == comp->TxfRtr) insert(items, TXFRTR);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmImeDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMSFLSTIOP, NUMFLSTRTR, TXFRTR, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmImeDetail::ContInf
 ******************************************************************************/

PnlWznmImeDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtIex
			, const string& TxtSup
			, const string& TxtTbl
			, const string& TxtIop
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtIex = TxtIex;
	this->TxtSup = TxtSup;
	this->TxtTbl = TxtTbl;
	this->TxtIop = TxtIop;

	mask = {TXTSRF, TXTIEX, TXTSUP, TXTTBL, TXTIOP};
};

bool PnlWznmImeDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmImeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmImeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIex", TxtIex)) add(TXTIEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTbl", TxtTbl)) add(TXTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIop", TxtIop)) add(TXTIOP);
	};

	return basefound;
};

set<uint> PnlWznmImeDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtIex == comp->TxtIex) insert(items, TXTIEX);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtIop == comp->TxtIop) insert(items, TXTIOP);

	return(items);
};

set<uint> PnlWznmImeDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTIEX, TXTSUP, TXTTBL, TXTIOP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmImeDetail::StatApp
 ******************************************************************************/

PnlWznmImeDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstIopAlt
			, const bool LstRtrAlt
			, const uint LstIopNumFirstdisp
			, const uint LstRtrNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstIopAlt = LstIopAlt;
	this->LstRtrAlt = LstRtrAlt;
	this->LstIopNumFirstdisp = LstIopNumFirstdisp;
	this->LstRtrNumFirstdisp = LstRtrNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTIOPALT, LSTRTRALT, LSTIOPNUMFIRSTDISP, LSTRTRNUMFIRSTDISP};
};

bool PnlWznmImeDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmImeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmImeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIopAlt", LstIopAlt)) add(LSTIOPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtrAlt", LstRtrAlt)) add(LSTRTRALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIopNumFirstdisp", LstIopNumFirstdisp)) add(LSTIOPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtrNumFirstdisp", LstRtrNumFirstdisp)) add(LSTRTRNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmImeDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstIopAlt == comp->LstIopAlt) insert(items, LSTIOPALT);
	if (LstRtrAlt == comp->LstRtrAlt) insert(items, LSTRTRALT);
	if (LstIopNumFirstdisp == comp->LstIopNumFirstdisp) insert(items, LSTIOPNUMFIRSTDISP);
	if (LstRtrNumFirstdisp == comp->LstRtrNumFirstdisp) insert(items, LSTRTRNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmImeDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTIOPALT, LSTRTRALT, LSTIOPNUMFIRSTDISP, LSTRTRNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmImeDetail::StatShr
 ******************************************************************************/

PnlWznmImeDetail::StatShr::StatShr(
			const bool TxfRtrValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtIexActive
			, const bool ButIexViewAvail
			, const bool ButIexViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtTblActive
			, const bool LstIopActive
			, const bool LstRtrActive
			, const bool ButRtrViewAvail
			, const bool ButRtrViewActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfRtrValid = TxfRtrValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtIexActive = TxtIexActive;
	this->ButIexViewAvail = ButIexViewAvail;
	this->ButIexViewActive = ButIexViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxtTblActive = TxtTblActive;
	this->LstIopActive = LstIopActive;
	this->LstRtrActive = LstRtrActive;
	this->ButRtrViewAvail = ButRtrViewAvail;
	this->ButRtrViewActive = ButRtrViewActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFRTRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTIEXACTIVE, BUTIEXVIEWAVAIL, BUTIEXVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, LSTIOPACTIVE, LSTRTRACTIVE, BUTRTRVIEWAVAIL, BUTRTRVIEWACTIVE, TXFCMTACTIVE};
};

bool PnlWznmImeDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmImeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmImeDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfRtrValid", TxfRtrValid)) add(TXFRTRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtIexActive", TxtIexActive)) add(TXTIEXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIexViewAvail", ButIexViewAvail)) add(BUTIEXVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIexViewActive", ButIexViewActive)) add(BUTIEXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTblActive", TxtTblActive)) add(TXTTBLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIopActive", LstIopActive)) add(LSTIOPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtrActive", LstRtrActive)) add(LSTRTRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRtrViewAvail", ButRtrViewAvail)) add(BUTRTRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRtrViewActive", ButRtrViewActive)) add(BUTRTRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmImeDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfRtrValid == comp->TxfRtrValid) insert(items, TXFRTRVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtIexActive == comp->TxtIexActive) insert(items, TXTIEXACTIVE);
	if (ButIexViewAvail == comp->ButIexViewAvail) insert(items, BUTIEXVIEWAVAIL);
	if (ButIexViewActive == comp->ButIexViewActive) insert(items, BUTIEXVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (LstIopActive == comp->LstIopActive) insert(items, LSTIOPACTIVE);
	if (LstRtrActive == comp->LstRtrActive) insert(items, LSTRTRACTIVE);
	if (ButRtrViewAvail == comp->ButRtrViewAvail) insert(items, BUTRTRVIEWAVAIL);
	if (ButRtrViewActive == comp->ButRtrViewActive) insert(items, BUTRTRVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmImeDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFRTRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTIEXACTIVE, BUTIEXVIEWAVAIL, BUTIEXVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, LSTIOPACTIVE, LSTRTRACTIVE, BUTRTRVIEWAVAIL, BUTRTRVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmImeDetail::Tag
 ******************************************************************************/

PnlWznmImeDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptIex
			, const string& CptSup
			, const string& CptTbl
			, const string& CptIop
			, const string& CptRtr
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptIex = CptIex;
	this->CptSup = CptSup;
	this->CptTbl = CptTbl;
	this->CptIop = CptIop;
	this->CptRtr = CptRtr;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTIEX, CPTSUP, CPTTBL, CPTIOP, CPTRTR, CPTCMT};
};

bool PnlWznmImeDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmImeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmImeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIex", CptIex)) add(CPTIEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTbl", CptTbl)) add(CPTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIop", CptIop)) add(CPTIOP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRtr", CptRtr)) add(CPTRTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmImeDetail::DpchAppData
 ******************************************************************************/

PnlWznmImeDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIMEDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmImeDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmImeDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmImeDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmImeDetail::DpchAppDo
 ******************************************************************************/

PnlWznmImeDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIMEDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmImeDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmImeDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmImeDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmImeDetail::DpchEngData
 ******************************************************************************/

PnlWznmImeDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMIMEDETAILDATA)
		{
	feedFLstIop.tag = "FeedFLstIop";
	feedFLstRtr.tag = "FeedFLstRtr";
};

string PnlWznmImeDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTIOP)) ss.push_back("feedFLstIop");
	if (has(FEEDFLSTRTR)) ss.push_back("feedFLstRtr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmImeDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmImeDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstIop.readXML(docctx, basexpath, true)) add(FEEDFLSTIOP);
		if (feedFLstRtr.readXML(docctx, basexpath, true)) add(FEEDFLSTRTR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstIop.clear();
		feedFLstRtr.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

