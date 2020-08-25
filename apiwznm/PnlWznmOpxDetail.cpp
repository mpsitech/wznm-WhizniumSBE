/**
	* \file PnlWznmOpxDetail.cpp
	* API code for job PnlWznmOpxDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "PnlWznmOpxDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmOpxDetail::VecVDo
 ******************************************************************************/

uint PnlWznmOpxDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butopkviewclick") return BUTOPKVIEWCLICK;
	if (s == "butsqknewclick") return BUTSQKNEWCLICK;
	if (s == "butsqkdeleteclick") return BUTSQKDELETECLICK;
	if (s == "butsqkjtieditclick") return BUTSQKJTIEDITCLICK;

	return(0);
};

string PnlWznmOpxDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTOPKVIEWCLICK) return("ButOpkViewClick");
	if (ix == BUTSQKNEWCLICK) return("ButSqkNewClick");
	if (ix == BUTSQKDELETECLICK) return("ButSqkDeleteClick");
	if (ix == BUTSQKJTIEDITCLICK) return("ButSqkJtiEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmOpxDetail::ContIac
 ******************************************************************************/

PnlWznmOpxDetail::ContIac::ContIac(
			const bool ChkShd
			, const string& TxfCmt
			, const uint numFPupSqkJti
			, const string& TxfSqkExa
		) :
			Block()
		{
	this->ChkShd = ChkShd;
	this->TxfCmt = TxfCmt;
	this->numFPupSqkJti = numFPupSqkJti;
	this->TxfSqkExa = TxfSqkExa;

	mask = {CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
};

bool PnlWznmOpxDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmOpxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmOpxDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkShd", ChkShd)) add(CHKSHD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSqkJti", numFPupSqkJti)) add(NUMFPUPSQKJTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSqkExa", TxfSqkExa)) add(TXFSQKEXA);
	};

	return basefound;
};

void PnlWznmOpxDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ChkShd", ChkShd);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupSqkJti", numFPupSqkJti);
		writeStringAttr(wr, itemtag, "sref", "TxfSqkExa", TxfSqkExa);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmOpxDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (ChkShd == comp->ChkShd) insert(items, CHKSHD);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupSqkJti == comp->numFPupSqkJti) insert(items, NUMFPUPSQKJTI);
	if (TxfSqkExa == comp->TxfSqkExa) insert(items, TXFSQKEXA);

	return(items);
};

set<uint> PnlWznmOpxDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxDetail::ContInf
 ******************************************************************************/

PnlWznmOpxDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtOpk
			, const string& TxtSqkTit
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtOpk = TxtOpk;
	this->TxtSqkTit = TxtSqkTit;

	mask = {TXTSRF, TXTOPK, TXTSQKTIT};
};

bool PnlWznmOpxDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmOpxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmOpxDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOpk", TxtOpk)) add(TXTOPK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSqkTit", TxtSqkTit)) add(TXTSQKTIT);
	};

	return basefound;
};

set<uint> PnlWznmOpxDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtOpk == comp->TxtOpk) insert(items, TXTOPK);
	if (TxtSqkTit == comp->TxtSqkTit) insert(items, TXTSQKTIT);

	return(items);
};

set<uint> PnlWznmOpxDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTOPK, TXTSQKTIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxDetail::StatApp
 ******************************************************************************/

PnlWznmOpxDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmOpxDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmOpxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmOpxDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmOpxDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmOpxDetail::StatApp::diff(
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
 class PnlWznmOpxDetail::StatShr
 ******************************************************************************/

PnlWznmOpxDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtOpkActive
			, const bool ButOpkViewAvail
			, const bool ButOpkViewActive
			, const bool ChkShdActive
			, const bool TxfCmtActive
			, const bool ButSqkNewAvail
			, const bool ButSqkDeleteAvail
			, const bool PupSqkJtiAvail
			, const bool PupSqkJtiActive
			, const bool ButSqkJtiEditAvail
			, const bool TxtSqkTitAvail
			, const bool TxtSqkTitActive
			, const bool TxfSqkExaAvail
			, const bool TxfSqkExaActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtOpkActive = TxtOpkActive;
	this->ButOpkViewAvail = ButOpkViewAvail;
	this->ButOpkViewActive = ButOpkViewActive;
	this->ChkShdActive = ChkShdActive;
	this->TxfCmtActive = TxfCmtActive;
	this->ButSqkNewAvail = ButSqkNewAvail;
	this->ButSqkDeleteAvail = ButSqkDeleteAvail;
	this->PupSqkJtiAvail = PupSqkJtiAvail;
	this->PupSqkJtiActive = PupSqkJtiActive;
	this->ButSqkJtiEditAvail = ButSqkJtiEditAvail;
	this->TxtSqkTitAvail = TxtSqkTitAvail;
	this->TxtSqkTitActive = TxtSqkTitActive;
	this->TxfSqkExaAvail = TxfSqkExaAvail;
	this->TxfSqkExaActive = TxfSqkExaActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTOPKACTIVE, BUTOPKVIEWAVAIL, BUTOPKVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
};

bool PnlWznmOpxDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmOpxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmOpxDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtOpkActive", TxtOpkActive)) add(TXTOPKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpkViewAvail", ButOpkViewAvail)) add(BUTOPKVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOpkViewActive", ButOpkViewActive)) add(BUTOPKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkShdActive", ChkShdActive)) add(CHKSHDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSqkNewAvail", ButSqkNewAvail)) add(BUTSQKNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSqkDeleteAvail", ButSqkDeleteAvail)) add(BUTSQKDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSqkJtiAvail", PupSqkJtiAvail)) add(PUPSQKJTIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSqkJtiActive", PupSqkJtiActive)) add(PUPSQKJTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSqkJtiEditAvail", ButSqkJtiEditAvail)) add(BUTSQKJTIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSqkTitAvail", TxtSqkTitAvail)) add(TXTSQKTITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSqkTitActive", TxtSqkTitActive)) add(TXTSQKTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSqkExaAvail", TxfSqkExaAvail)) add(TXFSQKEXAAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSqkExaActive", TxfSqkExaActive)) add(TXFSQKEXAACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmOpxDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtOpkActive == comp->TxtOpkActive) insert(items, TXTOPKACTIVE);
	if (ButOpkViewAvail == comp->ButOpkViewAvail) insert(items, BUTOPKVIEWAVAIL);
	if (ButOpkViewActive == comp->ButOpkViewActive) insert(items, BUTOPKVIEWACTIVE);
	if (ChkShdActive == comp->ChkShdActive) insert(items, CHKSHDACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (ButSqkNewAvail == comp->ButSqkNewAvail) insert(items, BUTSQKNEWAVAIL);
	if (ButSqkDeleteAvail == comp->ButSqkDeleteAvail) insert(items, BUTSQKDELETEAVAIL);
	if (PupSqkJtiAvail == comp->PupSqkJtiAvail) insert(items, PUPSQKJTIAVAIL);
	if (PupSqkJtiActive == comp->PupSqkJtiActive) insert(items, PUPSQKJTIACTIVE);
	if (ButSqkJtiEditAvail == comp->ButSqkJtiEditAvail) insert(items, BUTSQKJTIEDITAVAIL);
	if (TxtSqkTitAvail == comp->TxtSqkTitAvail) insert(items, TXTSQKTITAVAIL);
	if (TxtSqkTitActive == comp->TxtSqkTitActive) insert(items, TXTSQKTITACTIVE);
	if (TxfSqkExaAvail == comp->TxfSqkExaAvail) insert(items, TXFSQKEXAAVAIL);
	if (TxfSqkExaActive == comp->TxfSqkExaActive) insert(items, TXFSQKEXAACTIVE);

	return(items);
};

set<uint> PnlWznmOpxDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTOPKACTIVE, BUTOPKVIEWAVAIL, BUTOPKVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxDetail::Tag
 ******************************************************************************/

PnlWznmOpxDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptOpk
			, const string& CptShd
			, const string& CptCmt
			, const string& HdgSqk
			, const string& CptSqkTit
			, const string& CptSqkExa
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptOpk = CptOpk;
	this->CptShd = CptShd;
	this->CptCmt = CptCmt;
	this->HdgSqk = HdgSqk;
	this->CptSqkTit = CptSqkTit;
	this->CptSqkExa = CptSqkExa;

	mask = {CPT, CPTSRF, CPTOPK, CPTSHD, CPTCMT, HDGSQK, CPTSQKTIT, CPTSQKEXA};
};

bool PnlWznmOpxDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmOpxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmOpxDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpk", CptOpk)) add(CPTOPK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptShd", CptShd)) add(CPTSHD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgSqk", HdgSqk)) add(HDGSQK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSqkTit", CptSqkTit)) add(CPTSQKTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSqkExa", CptSqkExa)) add(CPTSQKEXA);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmOpxDetail::DpchAppData
 ******************************************************************************/

PnlWznmOpxDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPXDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmOpxDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpxDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmOpxDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpxDetail::DpchAppDo
 ******************************************************************************/

PnlWznmOpxDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPXDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmOpxDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpxDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmOpxDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpxDetail::DpchEngData
 ******************************************************************************/

PnlWznmOpxDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMOPXDETAILDATA)
		{
	feedFPupSqkJti.tag = "FeedFPupSqkJti";
};

string PnlWznmOpxDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPSQKJTI)) ss.push_back("feedFPupSqkJti");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpxDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmOpxDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupSqkJti.readXML(docctx, basexpath, true)) add(FEEDFPUPSQKJTI);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupSqkJti.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

