/**
	* \file PnlWznmSteDetail.cpp
	* API code for job PnlWznmSteDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWznmSteDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSteDetail::VecVDo
 ******************************************************************************/

uint PnlWznmSteDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butseqviewclick") return BUTSEQVIEWCLICK;
	if (s == "buterjviewclick") return BUTERJVIEWCLICK;
	if (s == "buteveviewclick") return BUTEVEVIEWCLICK;
	if (s == "buteviviewclick") return BUTEVIVIEWCLICK;
	if (s == "butesnviewclick") return BUTESNVIEWCLICK;

	return(0);
};

string PnlWznmSteDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSEQVIEWCLICK) return("ButSeqViewClick");
	if (ix == BUTERJVIEWCLICK) return("ButErjViewClick");
	if (ix == BUTEVEVIEWCLICK) return("ButEveViewClick");
	if (ix == BUTEVIVIEWCLICK) return("ButEviViewClick");
	if (ix == BUTESNVIEWCLICK) return("ButEsnViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmSteDetail::ContIac
 ******************************************************************************/

PnlWznmSteDetail::ContIac::ContIac(
			const uint numFPupEac
			, const uint numFPupLac
			, const bool ChkCst
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupEac = numFPupEac;
	this->numFPupLac = numFPupLac;
	this->ChkCst = ChkCst;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPEAC, NUMFPUPLAC, CHKCST, TXFCMT};
};

bool PnlWznmSteDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmSteDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmSteDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupEac", numFPupEac)) add(NUMFPUPEAC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLac", numFPupLac)) add(NUMFPUPLAC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCst", ChkCst)) add(CHKCST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmSteDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmSteDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmSteDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupEac", numFPupEac);
		writeUintAttr(wr, itemtag, "sref", "numFPupLac", numFPupLac);
		writeBoolAttr(wr, itemtag, "sref", "ChkCst", ChkCst);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupEac == comp->numFPupEac) insert(items, NUMFPUPEAC);
	if (numFPupLac == comp->numFPupLac) insert(items, NUMFPUPLAC);
	if (ChkCst == comp->ChkCst) insert(items, CHKCST);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmSteDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPEAC, NUMFPUPLAC, CHKCST, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::ContInf
 ******************************************************************************/

PnlWznmSteDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtSeq
			, const string& TxtErj
			, const string& TxtEve
			, const string& TxtEvi
			, const string& TxtEsn
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtSeq = TxtSeq;
	this->TxtErj = TxtErj;
	this->TxtEve = TxtEve;
	this->TxtEvi = TxtEvi;
	this->TxtEsn = TxtEsn;

	mask = {TXTSRF, TXTSEQ, TXTERJ, TXTEVE, TXTEVI, TXTESN};
};

bool PnlWznmSteDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmSteDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmSteDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSeq", TxtSeq)) add(TXTSEQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtErj", TxtErj)) add(TXTERJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtEve", TxtEve)) add(TXTEVE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtEvi", TxtEvi)) add(TXTEVI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtEsn", TxtEsn)) add(TXTESN);
	};

	return basefound;
};

set<uint> PnlWznmSteDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtSeq == comp->TxtSeq) insert(items, TXTSEQ);
	if (TxtErj == comp->TxtErj) insert(items, TXTERJ);
	if (TxtEve == comp->TxtEve) insert(items, TXTEVE);
	if (TxtEvi == comp->TxtEvi) insert(items, TXTEVI);
	if (TxtEsn == comp->TxtEsn) insert(items, TXTESN);

	return(items);
};

set<uint> PnlWznmSteDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTSEQ, TXTERJ, TXTEVE, TXTEVI, TXTESN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::StatApp
 ******************************************************************************/

PnlWznmSteDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmSteDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmSteDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmSteDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmSteDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmSteDetail::StatApp::diff(
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
 class PnlWznmSteDetail::StatShr
 ******************************************************************************/

PnlWznmSteDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtSeqActive
			, const bool ButSeqViewAvail
			, const bool ButSeqViewActive
			, const bool PupEacActive
			, const bool TxtErjActive
			, const bool ButErjViewAvail
			, const bool ButErjViewActive
			, const bool TxtEveActive
			, const bool ButEveViewAvail
			, const bool ButEveViewActive
			, const bool TxtEviActive
			, const bool ButEviViewAvail
			, const bool ButEviViewActive
			, const bool TxtEsnActive
			, const bool ButEsnViewAvail
			, const bool ButEsnViewActive
			, const bool PupLacActive
			, const bool ChkCstActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtSeqActive = TxtSeqActive;
	this->ButSeqViewAvail = ButSeqViewAvail;
	this->ButSeqViewActive = ButSeqViewActive;
	this->PupEacActive = PupEacActive;
	this->TxtErjActive = TxtErjActive;
	this->ButErjViewAvail = ButErjViewAvail;
	this->ButErjViewActive = ButErjViewActive;
	this->TxtEveActive = TxtEveActive;
	this->ButEveViewAvail = ButEveViewAvail;
	this->ButEveViewActive = ButEveViewActive;
	this->TxtEviActive = TxtEviActive;
	this->ButEviViewAvail = ButEviViewAvail;
	this->ButEviViewActive = ButEviViewActive;
	this->TxtEsnActive = TxtEsnActive;
	this->ButEsnViewAvail = ButEsnViewAvail;
	this->ButEsnViewActive = ButEsnViewActive;
	this->PupLacActive = PupLacActive;
	this->ChkCstActive = ChkCstActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, PUPEACACTIVE, TXTERJACTIVE, BUTERJVIEWAVAIL, BUTERJVIEWACTIVE, TXTEVEACTIVE, BUTEVEVIEWAVAIL, BUTEVEVIEWACTIVE, TXTEVIACTIVE, BUTEVIVIEWAVAIL, BUTEVIVIEWACTIVE, TXTESNACTIVE, BUTESNVIEWAVAIL, BUTESNVIEWACTIVE, PUPLACACTIVE, CHKCSTACTIVE, TXFCMTACTIVE};
};

bool PnlWznmSteDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmSteDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmSteDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSeqActive", TxtSeqActive)) add(TXTSEQACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSeqViewAvail", ButSeqViewAvail)) add(BUTSEQVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSeqViewActive", ButSeqViewActive)) add(BUTSEQVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupEacActive", PupEacActive)) add(PUPEACACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtErjActive", TxtErjActive)) add(TXTERJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButErjViewAvail", ButErjViewAvail)) add(BUTERJVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButErjViewActive", ButErjViewActive)) add(BUTERJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEveActive", TxtEveActive)) add(TXTEVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEveViewAvail", ButEveViewAvail)) add(BUTEVEVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEveViewActive", ButEveViewActive)) add(BUTEVEVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEviActive", TxtEviActive)) add(TXTEVIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEviViewAvail", ButEviViewAvail)) add(BUTEVIVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEviViewActive", ButEviViewActive)) add(BUTEVIVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEsnActive", TxtEsnActive)) add(TXTESNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEsnViewAvail", ButEsnViewAvail)) add(BUTESNVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEsnViewActive", ButEsnViewActive)) add(BUTESNVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupLacActive", PupLacActive)) add(PUPLACACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkCstActive", ChkCstActive)) add(CHKCSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmSteDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtSeqActive == comp->TxtSeqActive) insert(items, TXTSEQACTIVE);
	if (ButSeqViewAvail == comp->ButSeqViewAvail) insert(items, BUTSEQVIEWAVAIL);
	if (ButSeqViewActive == comp->ButSeqViewActive) insert(items, BUTSEQVIEWACTIVE);
	if (PupEacActive == comp->PupEacActive) insert(items, PUPEACACTIVE);
	if (TxtErjActive == comp->TxtErjActive) insert(items, TXTERJACTIVE);
	if (ButErjViewAvail == comp->ButErjViewAvail) insert(items, BUTERJVIEWAVAIL);
	if (ButErjViewActive == comp->ButErjViewActive) insert(items, BUTERJVIEWACTIVE);
	if (TxtEveActive == comp->TxtEveActive) insert(items, TXTEVEACTIVE);
	if (ButEveViewAvail == comp->ButEveViewAvail) insert(items, BUTEVEVIEWAVAIL);
	if (ButEveViewActive == comp->ButEveViewActive) insert(items, BUTEVEVIEWACTIVE);
	if (TxtEviActive == comp->TxtEviActive) insert(items, TXTEVIACTIVE);
	if (ButEviViewAvail == comp->ButEviViewAvail) insert(items, BUTEVIVIEWAVAIL);
	if (ButEviViewActive == comp->ButEviViewActive) insert(items, BUTEVIVIEWACTIVE);
	if (TxtEsnActive == comp->TxtEsnActive) insert(items, TXTESNACTIVE);
	if (ButEsnViewAvail == comp->ButEsnViewAvail) insert(items, BUTESNVIEWAVAIL);
	if (ButEsnViewActive == comp->ButEsnViewActive) insert(items, BUTESNVIEWACTIVE);
	if (PupLacActive == comp->PupLacActive) insert(items, PUPLACACTIVE);
	if (ChkCstActive == comp->ChkCstActive) insert(items, CHKCSTACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmSteDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, PUPEACACTIVE, TXTERJACTIVE, BUTERJVIEWAVAIL, BUTERJVIEWACTIVE, TXTEVEACTIVE, BUTEVEVIEWAVAIL, BUTEVEVIEWACTIVE, TXTEVIACTIVE, BUTEVIVIEWAVAIL, BUTEVIVIEWACTIVE, TXTESNACTIVE, BUTESNVIEWAVAIL, BUTESNVIEWACTIVE, PUPLACACTIVE, CHKCSTACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::Tag
 ******************************************************************************/

PnlWznmSteDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSeq
			, const string& CptEac
			, const string& CptErj
			, const string& CptEve
			, const string& CptEvi
			, const string& CptEsn
			, const string& CptLac
			, const string& CptCst
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptSeq = CptSeq;
	this->CptEac = CptEac;
	this->CptErj = CptErj;
	this->CptEve = CptEve;
	this->CptEvi = CptEvi;
	this->CptEsn = CptEsn;
	this->CptLac = CptLac;
	this->CptCst = CptCst;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTSEQ, CPTEAC, CPTERJ, CPTEVE, CPTEVI, CPTESN, CPTLAC, CPTCST, CPTCMT};
};

bool PnlWznmSteDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmSteDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmSteDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSeq", CptSeq)) add(CPTSEQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEac", CptEac)) add(CPTEAC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptErj", CptErj)) add(CPTERJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEve", CptEve)) add(CPTEVE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEvi", CptEvi)) add(CPTEVI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEsn", CptEsn)) add(CPTESN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLac", CptLac)) add(CPTLAC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCst", CptCst)) add(CPTCST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmSteDetail::DpchAppData
 ******************************************************************************/

PnlWznmSteDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmSteDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteDetail::DpchAppDo
 ******************************************************************************/

PnlWznmSteDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmSteDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteDetail::DpchEngData
 ******************************************************************************/

PnlWznmSteDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTEDETAILDATA)
		{
	feedFPupEac.tag = "FeedFPupEac";
	feedFPupLac.tag = "FeedFPupLac";
};

string PnlWznmSteDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPEAC)) ss.push_back("feedFPupEac");
	if (has(FEEDFPUPLAC)) ss.push_back("feedFPupLac");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmSteDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupEac.readXML(docctx, basexpath, true)) add(FEEDFPUPEAC);
		if (feedFPupLac.readXML(docctx, basexpath, true)) add(FEEDFPUPLAC);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupEac.clear();
		feedFPupLac.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

