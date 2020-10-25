/**
	* \file PnlWznmPstDetail.cpp
	* API code for job PnlWznmPstDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmPstDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmPstDetail::VecVDo
 ******************************************************************************/

uint PnlWznmPstDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjtieditclick") return BUTJTIEDITCLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;

	return(0);
};

string PnlWznmPstDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmPstDetail::ContIac
 ******************************************************************************/

PnlWznmPstDetail::ContIac::ContIac(
			const uint numFPupJti
			, const uint numFPupRet
			, const uint numFPupSco
			, const uint numFPupAty
		) :
			Block()
		{
	this->numFPupJti = numFPupJti;
	this->numFPupRet = numFPupRet;
	this->numFPupSco = numFPupSco;
	this->numFPupAty = numFPupAty;

	mask = {NUMFPUPJTI, NUMFPUPRET, NUMFPUPSCO, NUMFPUPATY};
};

bool PnlWznmPstDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmPstDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmPstDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJti", numFPupJti)) add(NUMFPUPJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSco", numFPupSco)) add(NUMFPUPSCO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAty", numFPupAty)) add(NUMFPUPATY);
	};

	return basefound;
};

void PnlWznmPstDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmPstDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmPstDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJti", numFPupJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupSco", numFPupSco);
		writeUintAttr(wr, itemtag, "sref", "numFPupAty", numFPupAty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmPstDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJti == comp->numFPupJti) insert(items, NUMFPUPJTI);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupSco == comp->numFPupSco) insert(items, NUMFPUPSCO);
	if (numFPupAty == comp->numFPupAty) insert(items, NUMFPUPATY);

	return(items);
};

set<uint> PnlWznmPstDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJTI, NUMFPUPRET, NUMFPUPSCO, NUMFPUPATY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmPstDetail::ContInf
 ******************************************************************************/

PnlWznmPstDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtVer
			, const string& TxtReu
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtVer = TxtVer;
	this->TxtReu = TxtReu;

	mask = {TXTSRF, TXTTIT, TXTVER, TXTREU};
};

bool PnlWznmPstDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmPstDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmPstDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTit", TxtTit)) add(TXTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
	};

	return basefound;
};

set<uint> PnlWznmPstDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);

	return(items);
};

set<uint> PnlWznmPstDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTVER, TXTREU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmPstDetail::StatApp
 ******************************************************************************/

PnlWznmPstDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmPstDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmPstDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmPstDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmPstDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmPstDetail::StatApp::diff(
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
 class PnlWznmPstDetail::StatShr
 ******************************************************************************/

PnlWznmPstDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJtiActive
			, const bool ButJtiEditAvail
			, const bool TxtTitActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool PupScoActive
			, const bool PupAtyActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupJtiActive = PupJtiActive;
	this->ButJtiEditAvail = ButJtiEditAvail;
	this->TxtTitActive = TxtTitActive;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->PupScoActive = PupScoActive;
	this->PupAtyActive = PupAtyActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPSCOACTIVE, PUPATYACTIVE};
};

bool PnlWznmPstDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmPstDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmPstDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJtiActive", PupJtiActive)) add(PUPJTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", ButJtiEditAvail)) add(BUTJTIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTitActive", TxtTitActive)) add(TXTTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerActive", TxtVerActive)) add(TXTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", ButVerViewAvail)) add(BUTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupScoActive", PupScoActive)) add(PUPSCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAtyActive", PupAtyActive)) add(PUPATYACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmPstDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJtiActive == comp->PupJtiActive) insert(items, PUPJTIACTIVE);
	if (ButJtiEditAvail == comp->ButJtiEditAvail) insert(items, BUTJTIEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (PupScoActive == comp->PupScoActive) insert(items, PUPSCOACTIVE);
	if (PupAtyActive == comp->PupAtyActive) insert(items, PUPATYACTIVE);

	return(items);
};

set<uint> PnlWznmPstDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPSCOACTIVE, PUPATYACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmPstDetail::Tag
 ******************************************************************************/

PnlWznmPstDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptVer
			, const string& CptReu
			, const string& CptSco
			, const string& CptAty
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptVer = CptVer;
	this->CptReu = CptReu;
	this->CptSco = CptSco;
	this->CptAty = CptAty;

	mask = {CPT, CPTSRF, CPTTIT, CPTVER, CPTREU, CPTSCO, CPTATY};
};

bool PnlWznmPstDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmPstDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmPstDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSco", CptSco)) add(CPTSCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAty", CptAty)) add(CPTATY);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmPstDetail::DpchAppData
 ******************************************************************************/

PnlWznmPstDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMPSTDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmPstDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmPstDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmPstDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmPstDetail::DpchAppDo
 ******************************************************************************/

PnlWznmPstDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMPSTDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmPstDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmPstDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmPstDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmPstDetail::DpchEngData
 ******************************************************************************/

PnlWznmPstDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMPSTDETAILDATA)
		{
	feedFPupAty.tag = "FeedFPupAty";
	feedFPupJti.tag = "FeedFPupJti";
	feedFPupRet.tag = "FeedFPupRet";
	feedFPupSco.tag = "FeedFPupSco";
};

string PnlWznmPstDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPATY)) ss.push_back("feedFPupAty");
	if (has(FEEDFPUPJTI)) ss.push_back("feedFPupJti");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPSCO)) ss.push_back("feedFPupSco");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmPstDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmPstDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupAty.readXML(docctx, basexpath, true)) add(FEEDFPUPATY);
		if (feedFPupJti.readXML(docctx, basexpath, true)) add(FEEDFPUPJTI);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (feedFPupSco.readXML(docctx, basexpath, true)) add(FEEDFPUPSCO);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupAty.clear();
		feedFPupJti.clear();
		feedFPupRet.clear();
		feedFPupSco.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

