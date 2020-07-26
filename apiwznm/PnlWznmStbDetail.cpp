/**
	* \file PnlWznmStbDetail.cpp
	* API code for job PnlWznmStbDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWznmStbDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmStbDetail::VecVDo
 ******************************************************************************/

uint PnlWznmStbDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butsbsviewclick") return BUTSBSVIEWCLICK;
	if (s == "buttcoviewclick") return BUTTCOVIEWCLICK;

	return(0);
};

string PnlWznmStbDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
	if (ix == BUTTCOVIEWCLICK) return("ButTcoViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmStbDetail::ContIac
 ******************************************************************************/

PnlWznmStbDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const bool ChkHrc
			, const bool ChkLcl
			, const string& TxfExa
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->ChkHrc = ChkHrc;
	this->ChkLcl = ChkLcl;
	this->TxfExa = TxfExa;

	mask = {NUMFPUPTYP, CHKHRC, CHKLCL, TXFEXA};
};

bool PnlWznmStbDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmStbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmStbDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkHrc", ChkHrc)) add(CHKHRC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkLcl", ChkLcl)) add(CHKLCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfExa", TxfExa)) add(TXFEXA);
	};

	return basefound;
};

void PnlWznmStbDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmStbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmStbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeBoolAttr(wr, itemtag, "sref", "ChkHrc", ChkHrc);
		writeBoolAttr(wr, itemtag, "sref", "ChkLcl", ChkLcl);
		writeStringAttr(wr, itemtag, "sref", "TxfExa", TxfExa);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmStbDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (ChkHrc == comp->ChkHrc) insert(items, CHKHRC);
	if (ChkLcl == comp->ChkLcl) insert(items, CHKLCL);
	if (TxfExa == comp->TxfExa) insert(items, TXFEXA);

	return(items);
};

set<uint> PnlWznmStbDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, CHKHRC, CHKLCL, TXFEXA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbDetail::ContInf
 ******************************************************************************/

PnlWznmStbDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTbl
			, const string& TxtSbs
			, const string& TxtTco
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTbl = TxtTbl;
	this->TxtSbs = TxtSbs;
	this->TxtTco = TxtTco;

	mask = {TXTSRF, TXTTBL, TXTSBS, TXTTCO};
};

bool PnlWznmStbDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmStbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmStbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTbl", TxtTbl)) add(TXTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSbs", TxtSbs)) add(TXTSBS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTco", TxtTco)) add(TXTTCO);
	};

	return basefound;
};

set<uint> PnlWznmStbDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtSbs == comp->TxtSbs) insert(items, TXTSBS);
	if (TxtTco == comp->TxtTco) insert(items, TXTTCO);

	return(items);
};

set<uint> PnlWznmStbDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTBL, TXTSBS, TXTTCO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbDetail::StatApp
 ******************************************************************************/

PnlWznmStbDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmStbDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmStbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmStbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmStbDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmStbDetail::StatApp::diff(
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
 class PnlWznmStbDetail::StatShr
 ******************************************************************************/

PnlWznmStbDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool TxtTblActive
			, const bool TxtSbsActive
			, const bool ButSbsViewAvail
			, const bool ButSbsViewActive
			, const bool ChkHrcActive
			, const bool TxtTcoActive
			, const bool ButTcoViewAvail
			, const bool ButTcoViewActive
			, const bool ChkLclActive
			, const bool TxfExaActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->TxtTblActive = TxtTblActive;
	this->TxtSbsActive = TxtSbsActive;
	this->ButSbsViewAvail = ButSbsViewAvail;
	this->ButSbsViewActive = ButSbsViewActive;
	this->ChkHrcActive = ChkHrcActive;
	this->TxtTcoActive = TxtTcoActive;
	this->ButTcoViewAvail = ButTcoViewAvail;
	this->ButTcoViewActive = ButTcoViewActive;
	this->ChkLclActive = ChkLclActive;
	this->TxfExaActive = TxfExaActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, CHKHRCACTIVE, TXTTCOACTIVE, BUTTCOVIEWAVAIL, BUTTCOVIEWACTIVE, CHKLCLACTIVE, TXFEXAACTIVE};
};

bool PnlWznmStbDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmStbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmStbDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTblActive", TxtTblActive)) add(TXTTBLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSbsActive", TxtSbsActive)) add(TXTSBSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSbsViewAvail", ButSbsViewAvail)) add(BUTSBSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSbsViewActive", ButSbsViewActive)) add(BUTSBSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkHrcActive", ChkHrcActive)) add(CHKHRCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTcoActive", TxtTcoActive)) add(TXTTCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTcoViewAvail", ButTcoViewAvail)) add(BUTTCOVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTcoViewActive", ButTcoViewActive)) add(BUTTCOVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkLclActive", ChkLclActive)) add(CHKLCLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfExaActive", TxfExaActive)) add(TXFEXAACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmStbDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (TxtSbsActive == comp->TxtSbsActive) insert(items, TXTSBSACTIVE);
	if (ButSbsViewAvail == comp->ButSbsViewAvail) insert(items, BUTSBSVIEWAVAIL);
	if (ButSbsViewActive == comp->ButSbsViewActive) insert(items, BUTSBSVIEWACTIVE);
	if (ChkHrcActive == comp->ChkHrcActive) insert(items, CHKHRCACTIVE);
	if (TxtTcoActive == comp->TxtTcoActive) insert(items, TXTTCOACTIVE);
	if (ButTcoViewAvail == comp->ButTcoViewAvail) insert(items, BUTTCOVIEWAVAIL);
	if (ButTcoViewActive == comp->ButTcoViewActive) insert(items, BUTTCOVIEWACTIVE);
	if (ChkLclActive == comp->ChkLclActive) insert(items, CHKLCLACTIVE);
	if (TxfExaActive == comp->TxfExaActive) insert(items, TXFEXAACTIVE);

	return(items);
};

set<uint> PnlWznmStbDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, CHKHRCACTIVE, TXTTCOACTIVE, BUTTCOVIEWAVAIL, BUTTCOVIEWACTIVE, CHKLCLACTIVE, TXFEXAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbDetail::Tag
 ******************************************************************************/

PnlWznmStbDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptTbl
			, const string& CptSbs
			, const string& CptHrc
			, const string& CptTco
			, const string& CptLcl
			, const string& CptExa
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTyp = CptTyp;
	this->CptTbl = CptTbl;
	this->CptSbs = CptSbs;
	this->CptHrc = CptHrc;
	this->CptTco = CptTco;
	this->CptLcl = CptLcl;
	this->CptExa = CptExa;

	mask = {CPT, CPTSRF, CPTTYP, CPTTBL, CPTSBS, CPTHRC, CPTTCO, CPTLCL, CPTEXA};
};

bool PnlWznmStbDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmStbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmStbDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTbl", CptTbl)) add(CPTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSbs", CptSbs)) add(CPTSBS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHrc", CptHrc)) add(CPTHRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTco", CptTco)) add(CPTTCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLcl", CptLcl)) add(CPTLCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptExa", CptExa)) add(CPTEXA);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmStbDetail::DpchAppData
 ******************************************************************************/

PnlWznmStbDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTBDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmStbDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmStbDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmStbDetail::DpchAppDo
 ******************************************************************************/

PnlWznmStbDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTBDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmStbDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmStbDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmStbDetail::DpchEngData
 ******************************************************************************/

PnlWznmStbDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTBDETAILDATA)
		{
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmStbDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmStbDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

