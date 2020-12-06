/**
	* \file PnlWznmQcoDetail.cpp
	* API code for job PnlWznmQcoDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmQcoDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmQcoDetail::VecVDo
 ******************************************************************************/

uint PnlWznmQcoDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butqryviewclick") return BUTQRYVIEWCLICK;
	if (s == "butstbviewclick") return BUTSTBVIEWCLICK;

	return(0);
};

string PnlWznmQcoDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTQRYVIEWCLICK) return("ButQryViewClick");
	if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmQcoDetail::ContIac
 ******************************************************************************/

PnlWznmQcoDetail::ContIac::ContIac(
			const string& TxfSho
			, const uint numFPupTyp
			, const vector<uint>& numsFLstOcc
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->numFPupTyp = numFPupTyp;
	this->numsFLstOcc = numsFLstOcc;

	mask = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC};
};

bool PnlWznmQcoDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmQcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmQcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOcc", numsFLstOcc)) add(NUMSFLSTOCC);
	};

	return basefound;
};

void PnlWznmQcoDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmQcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmQcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOcc", numsFLstOcc);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQcoDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (compareUintvec(numsFLstOcc, comp->numsFLstOcc)) insert(items, NUMSFLSTOCC);

	return(items);
};

set<uint> PnlWznmQcoDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQcoDetail::ContInf
 ******************************************************************************/

PnlWznmQcoDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtOcc
			, const string& TxtQry
			, const string& TxtTco
			, const string& TxtStb
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtOcc = TxtOcc;
	this->TxtQry = TxtQry;
	this->TxtTco = TxtTco;
	this->TxtStb = TxtStb;

	mask = {TXTSRF, TXTOCC, TXTQRY, TXTTCO, TXTSTB};
};

bool PnlWznmQcoDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmQcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmQcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOcc", TxtOcc)) add(TXTOCC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtQry", TxtQry)) add(TXTQRY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTco", TxtTco)) add(TXTTCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtStb", TxtStb)) add(TXTSTB);
	};

	return basefound;
};

set<uint> PnlWznmQcoDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtOcc == comp->TxtOcc) insert(items, TXTOCC);
	if (TxtQry == comp->TxtQry) insert(items, TXTQRY);
	if (TxtTco == comp->TxtTco) insert(items, TXTTCO);
	if (TxtStb == comp->TxtStb) insert(items, TXTSTB);

	return(items);
};

set<uint> PnlWznmQcoDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTOCC, TXTQRY, TXTTCO, TXTSTB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQcoDetail::StatApp
 ******************************************************************************/

PnlWznmQcoDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstOccAlt
			, const uint LstOccNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstOccAlt = LstOccAlt;
	this->LstOccNumFirstdisp = LstOccNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTOCCALT, LSTOCCNUMFIRSTDISP};
};

bool PnlWznmQcoDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmQcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmQcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOccAlt", LstOccAlt)) add(LSTOCCALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOccNumFirstdisp", LstOccNumFirstdisp)) add(LSTOCCNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmQcoDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstOccAlt == comp->LstOccAlt) insert(items, LSTOCCALT);
	if (LstOccNumFirstdisp == comp->LstOccNumFirstdisp) insert(items, LSTOCCNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmQcoDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTOCCALT, LSTOCCNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQcoDetail::StatShr
 ******************************************************************************/

PnlWznmQcoDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool PupTypActive
			, const bool LstOccActive
			, const bool TxtQryActive
			, const bool ButQryViewAvail
			, const bool ButQryViewActive
			, const bool TxtTcoActive
			, const bool TxtStbActive
			, const bool ButStbViewAvail
			, const bool ButStbViewActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->PupTypActive = PupTypActive;
	this->LstOccActive = LstOccActive;
	this->TxtQryActive = TxtQryActive;
	this->ButQryViewAvail = ButQryViewAvail;
	this->ButQryViewActive = ButQryViewActive;
	this->TxtTcoActive = TxtTcoActive;
	this->TxtStbActive = TxtStbActive;
	this->ButStbViewAvail = ButStbViewAvail;
	this->ButStbViewActive = ButStbViewActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTTCOACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE};
};

bool PnlWznmQcoDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmQcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmQcoDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfShoActive", TxfShoActive)) add(TXFSHOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOccActive", LstOccActive)) add(LSTOCCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtQryActive", TxtQryActive)) add(TXTQRYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQryViewAvail", ButQryViewAvail)) add(BUTQRYVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQryViewActive", ButQryViewActive)) add(BUTQRYVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTcoActive", TxtTcoActive)) add(TXTTCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtStbActive", TxtStbActive)) add(TXTSTBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStbViewAvail", ButStbViewAvail)) add(BUTSTBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStbViewActive", ButStbViewActive)) add(BUTSTBVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmQcoDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstOccActive == comp->LstOccActive) insert(items, LSTOCCACTIVE);
	if (TxtQryActive == comp->TxtQryActive) insert(items, TXTQRYACTIVE);
	if (ButQryViewAvail == comp->ButQryViewAvail) insert(items, BUTQRYVIEWAVAIL);
	if (ButQryViewActive == comp->ButQryViewActive) insert(items, BUTQRYVIEWACTIVE);
	if (TxtTcoActive == comp->TxtTcoActive) insert(items, TXTTCOACTIVE);
	if (TxtStbActive == comp->TxtStbActive) insert(items, TXTSTBACTIVE);
	if (ButStbViewAvail == comp->ButStbViewAvail) insert(items, BUTSTBVIEWAVAIL);
	if (ButStbViewActive == comp->ButStbViewActive) insert(items, BUTSTBVIEWACTIVE);

	return(items);
};

set<uint> PnlWznmQcoDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTTCOACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQcoDetail::Tag
 ******************************************************************************/

PnlWznmQcoDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSho
			, const string& CptTyp
			, const string& CptOcc
			, const string& CptQry
			, const string& CptTco
			, const string& CptStb
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptSho = CptSho;
	this->CptTyp = CptTyp;
	this->CptOcc = CptOcc;
	this->CptQry = CptQry;
	this->CptTco = CptTco;
	this->CptStb = CptStb;

	mask = {CPT, CPTSRF, CPTSHO, CPTTYP, CPTOCC, CPTQRY, CPTTCO, CPTSTB};
};

bool PnlWznmQcoDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmQcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmQcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSho", CptSho)) add(CPTSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOcc", CptOcc)) add(CPTOCC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptQry", CptQry)) add(CPTQRY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTco", CptTco)) add(CPTTCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStb", CptStb)) add(CPTSTB);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmQcoDetail::DpchAppData
 ******************************************************************************/

PnlWznmQcoDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQCODETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmQcoDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQcoDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmQcoDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQcoDetail::DpchAppDo
 ******************************************************************************/

PnlWznmQcoDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQCODETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmQcoDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQcoDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmQcoDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQcoDetail::DpchEngData
 ******************************************************************************/

PnlWznmQcoDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMQCODETAILDATA)
		{
	feedFLstOcc.tag = "FeedFLstOcc";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmQcoDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOCC)) ss.push_back("feedFLstOcc");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQcoDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmQcoDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstOcc.readXML(docctx, basexpath, true)) add(FEEDFLSTOCC);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstOcc.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
