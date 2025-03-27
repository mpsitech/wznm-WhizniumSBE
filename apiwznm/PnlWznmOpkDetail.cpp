/**
	* \file PnlWznmOpkDetail.cpp
	* API code for job PnlWznmOpkDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmOpkDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmOpkDetail::VecVDo
 ******************************************************************************/

uint PnlWznmOpkDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butsqknewclick") return BUTSQKNEWCLICK;
	if (s == "butsqkdeleteclick") return BUTSQKDELETECLICK;
	if (s == "butsqkjtieditclick") return BUTSQKJTIEDITCLICK;

	return(0);
};

string PnlWznmOpkDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTSQKNEWCLICK) return("ButSqkNewClick");
	if (ix == BUTSQKDELETECLICK) return("ButSqkDeleteClick");
	if (ix == BUTSQKJTIEDITCLICK) return("ButSqkJtiEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmOpkDetail::ContIac
 ******************************************************************************/

PnlWznmOpkDetail::ContIac::ContIac(
			const string& TxfTit
			, const uint numFPupTyp
			, const bool ChkShd
			, const string& TxfCmt
			, const uint numFPupSqkJti
			, const string& TxfSqkExa
		) :
			Block()
			, TxfTit(TxfTit)
			, numFPupTyp(numFPupTyp)
			, ChkShd(ChkShd)
			, TxfCmt(TxfCmt)
			, numFPupSqkJti(numFPupSqkJti)
			, TxfSqkExa(TxfSqkExa)
		{
	mask = {TXFTIT, NUMFPUPTYP, CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
};

bool PnlWznmOpkDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmOpkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmOpkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkShd", ChkShd)) add(CHKSHD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSqkJti", numFPupSqkJti)) add(NUMFPUPSQKJTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSqkExa", TxfSqkExa)) add(TXFSQKEXA);
	};

	return basefound;
};

void PnlWznmOpkDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmOpkDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmOpkDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeBoolAttr(wr, itemtag, "sref", "ChkShd", ChkShd);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupSqkJti", numFPupSqkJti);
		writeStringAttr(wr, itemtag, "sref", "TxfSqkExa", TxfSqkExa);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmOpkDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (ChkShd == comp->ChkShd) insert(items, CHKSHD);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupSqkJti == comp->numFPupSqkJti) insert(items, NUMFPUPSQKJTI);
	if (TxfSqkExa == comp->TxfSqkExa) insert(items, TXFSQKEXA);

	return(items);
};

set<uint> PnlWznmOpkDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMFPUPTYP, CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpkDetail::ContInf
 ******************************************************************************/

PnlWznmOpkDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVer
			, const string& TxtSqkTit
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtVer(TxtVer)
			, TxtSqkTit(TxtSqkTit)
		{
	mask = {TXTSRF, TXTVER, TXTSQKTIT};
};

bool PnlWznmOpkDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmOpkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmOpkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSqkTit", TxtSqkTit)) add(TXTSQKTIT);
	};

	return basefound;
};

set<uint> PnlWznmOpkDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtSqkTit == comp->TxtSqkTit) insert(items, TXTSQKTIT);

	return(items);
};

set<uint> PnlWznmOpkDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVER, TXTSQKTIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpkDetail::StatApp
 ******************************************************************************/

PnlWznmOpkDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
		{
	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmOpkDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmOpkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmOpkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmOpkDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmOpkDetail::StatApp::diff(
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
 class PnlWznmOpkDetail::StatShr
 ******************************************************************************/

PnlWznmOpkDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfTitActive
			, const bool PupTypActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
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
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, TxfTitActive(TxfTitActive)
			, PupTypActive(PupTypActive)
			, TxtVerActive(TxtVerActive)
			, ButVerViewAvail(ButVerViewAvail)
			, ButVerViewActive(ButVerViewActive)
			, ChkShdActive(ChkShdActive)
			, TxfCmtActive(TxfCmtActive)
			, ButSqkNewAvail(ButSqkNewAvail)
			, ButSqkDeleteAvail(ButSqkDeleteAvail)
			, PupSqkJtiAvail(PupSqkJtiAvail)
			, PupSqkJtiActive(PupSqkJtiActive)
			, ButSqkJtiEditAvail(ButSqkJtiEditAvail)
			, TxtSqkTitAvail(TxtSqkTitAvail)
			, TxtSqkTitActive(TxtSqkTitActive)
			, TxfSqkExaAvail(TxfSqkExaAvail)
			, TxfSqkExaActive(TxfSqkExaActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
};

bool PnlWznmOpkDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmOpkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmOpkDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTitActive", TxfTitActive)) add(TXFTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerActive", TxtVerActive)) add(TXTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", ButVerViewAvail)) add(BUTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
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

set<uint> PnlWznmOpkDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
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

set<uint> PnlWznmOpkDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpkDetail::Tag
 ******************************************************************************/

PnlWznmOpkDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptTyp
			, const string& CptVer
			, const string& CptShd
			, const string& CptCmt
			, const string& HdgSqk
			, const string& CptSqkTit
			, const string& CptSqkExa
		) :
			Block()
			, Cpt(Cpt)
			, CptSrf(CptSrf)
			, CptTit(CptTit)
			, CptTyp(CptTyp)
			, CptVer(CptVer)
			, CptShd(CptShd)
			, CptCmt(CptCmt)
			, HdgSqk(HdgSqk)
			, CptSqkTit(CptSqkTit)
			, CptSqkExa(CptSqkExa)
		{
	mask = {CPT, CPTSRF, CPTTIT, CPTTYP, CPTVER, CPTSHD, CPTCMT, HDGSQK, CPTSQKTIT, CPTSQKEXA};
};

bool PnlWznmOpkDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmOpkDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmOpkDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptShd", CptShd)) add(CPTSHD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgSqk", HdgSqk)) add(HDGSQK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSqkTit", CptSqkTit)) add(CPTSQKTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSqkExa", CptSqkExa)) add(CPTSQKEXA);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmOpkDetail::DpchAppData
 ******************************************************************************/

PnlWznmOpkDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPKDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmOpkDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpkDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmOpkDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpkDetail::DpchAppDo
 ******************************************************************************/

PnlWznmOpkDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPKDETAILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmOpkDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpkDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmOpkDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpkDetail::DpchEngData
 ******************************************************************************/

PnlWznmOpkDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMOPKDETAILDATA)
		{
	feedFPupSqkJti.tag = "FeedFPupSqkJti";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmOpkDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPSQKJTI)) ss.push_back("feedFPupSqkJti");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpkDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmOpkDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupSqkJti.readXML(docctx, basexpath, true)) add(FEEDFPUPSQKJTI);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupSqkJti.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
