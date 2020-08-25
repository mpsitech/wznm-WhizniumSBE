/**
	* \file PnlWznmMtyDetail.cpp
	* API code for job PnlWznmMtyDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "PnlWznmMtyDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmMtyDetail::VecVDo
 ******************************************************************************/

uint PnlWznmMtyDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butoseditclick") return BUTOSEDITCLICK;
	if (s == "butcchviewclick") return BUTCCHVIEWCLICK;
	if (s == "butpkmeditclick") return BUTPKMEDITCLICK;

	return(0);
};

string PnlWznmMtyDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTOSEDITCLICK) return("ButOsEditClick");
	if (ix == BUTCCHVIEWCLICK) return("ButCchViewClick");
	if (ix == BUTPKMEDITCLICK) return("ButPkmEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmMtyDetail::ContIac
 ******************************************************************************/

PnlWznmMtyDetail::ContIac::ContIac(
			const uint numFPupAch
			, const uint numFPupOs
			, const string& TxfOs
			, const uint numFPupPkm
			, const string& TxfPkm
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupAch = numFPupAch;
	this->numFPupOs = numFPupOs;
	this->TxfOs = TxfOs;
	this->numFPupPkm = numFPupPkm;
	this->TxfPkm = TxfPkm;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPACH, NUMFPUPOS, TXFOS, NUMFPUPPKM, TXFPKM, TXFCMT};
};

bool PnlWznmMtyDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmMtyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmMtyDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAch", numFPupAch)) add(NUMFPUPACH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupOs", numFPupOs)) add(NUMFPUPOS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOs", TxfOs)) add(TXFOS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPkm", numFPupPkm)) add(NUMFPUPPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPkm", TxfPkm)) add(TXFPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmMtyDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmMtyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmMtyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupAch", numFPupAch);
		writeUintAttr(wr, itemtag, "sref", "numFPupOs", numFPupOs);
		writeStringAttr(wr, itemtag, "sref", "TxfOs", TxfOs);
		writeUintAttr(wr, itemtag, "sref", "numFPupPkm", numFPupPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfPkm", TxfPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMtyDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupAch == comp->numFPupAch) insert(items, NUMFPUPACH);
	if (numFPupOs == comp->numFPupOs) insert(items, NUMFPUPOS);
	if (TxfOs == comp->TxfOs) insert(items, TXFOS);
	if (numFPupPkm == comp->numFPupPkm) insert(items, NUMFPUPPKM);
	if (TxfPkm == comp->TxfPkm) insert(items, TXFPKM);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmMtyDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPACH, NUMFPUPOS, TXFOS, NUMFPUPPKM, TXFPKM, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMtyDetail::ContInf
 ******************************************************************************/

PnlWznmMtyDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtCch
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtCch = TxtCch;

	mask = {TXTSRF, TXTCCH};
};

bool PnlWznmMtyDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmMtyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmMtyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCch", TxtCch)) add(TXTCCH);
	};

	return basefound;
};

set<uint> PnlWznmMtyDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtCch == comp->TxtCch) insert(items, TXTCCH);

	return(items);
};

set<uint> PnlWznmMtyDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCCH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMtyDetail::StatApp
 ******************************************************************************/

PnlWznmMtyDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool PupOsAlt
			, const bool PupPkmAlt
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->PupOsAlt = PupOsAlt;
	this->PupPkmAlt = PupPkmAlt;

	mask = {IXWZNMVEXPSTATE, PUPOSALT, PUPPKMALT};
};

bool PnlWznmMtyDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmMtyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmMtyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupOsAlt", PupOsAlt)) add(PUPOSALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPkmAlt", PupPkmAlt)) add(PUPPKMALT);
	};

	return basefound;
};

set<uint> PnlWznmMtyDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (PupOsAlt == comp->PupOsAlt) insert(items, PUPOSALT);
	if (PupPkmAlt == comp->PupPkmAlt) insert(items, PUPPKMALT);

	return(items);
};

set<uint> PnlWznmMtyDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, PUPOSALT, PUPPKMALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMtyDetail::StatShr
 ******************************************************************************/

PnlWznmMtyDetail::StatShr::StatShr(
			const bool TxfOsValid
			, const bool TxfPkmValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupAchActive
			, const bool PupOsActive
			, const bool ButOsEditAvail
			, const bool TxtCchActive
			, const bool ButCchViewAvail
			, const bool ButCchViewActive
			, const bool PupPkmActive
			, const bool ButPkmEditAvail
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfOsValid = TxfOsValid;
	this->TxfPkmValid = TxfPkmValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupAchActive = PupAchActive;
	this->PupOsActive = PupOsActive;
	this->ButOsEditAvail = ButOsEditAvail;
	this->TxtCchActive = TxtCchActive;
	this->ButCchViewAvail = ButCchViewAvail;
	this->ButCchViewActive = ButCchViewActive;
	this->PupPkmActive = PupPkmActive;
	this->ButPkmEditAvail = ButPkmEditAvail;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFOSVALID, TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPACHACTIVE, PUPOSACTIVE, BUTOSEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE};
};

bool PnlWznmMtyDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmMtyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmMtyDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOsValid", TxfOsValid)) add(TXFOSVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPkmValid", TxfPkmValid)) add(TXFPKMVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAchActive", PupAchActive)) add(PUPACHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupOsActive", PupOsActive)) add(PUPOSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOsEditAvail", ButOsEditAvail)) add(BUTOSEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCchActive", TxtCchActive)) add(TXTCCHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCchViewAvail", ButCchViewAvail)) add(BUTCCHVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCchViewActive", ButCchViewActive)) add(BUTCCHVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPkmActive", PupPkmActive)) add(PUPPKMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPkmEditAvail", ButPkmEditAvail)) add(BUTPKMEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmMtyDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfOsValid == comp->TxfOsValid) insert(items, TXFOSVALID);
	if (TxfPkmValid == comp->TxfPkmValid) insert(items, TXFPKMVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupAchActive == comp->PupAchActive) insert(items, PUPACHACTIVE);
	if (PupOsActive == comp->PupOsActive) insert(items, PUPOSACTIVE);
	if (ButOsEditAvail == comp->ButOsEditAvail) insert(items, BUTOSEDITAVAIL);
	if (TxtCchActive == comp->TxtCchActive) insert(items, TXTCCHACTIVE);
	if (ButCchViewAvail == comp->ButCchViewAvail) insert(items, BUTCCHVIEWAVAIL);
	if (ButCchViewActive == comp->ButCchViewActive) insert(items, BUTCCHVIEWACTIVE);
	if (PupPkmActive == comp->PupPkmActive) insert(items, PUPPKMACTIVE);
	if (ButPkmEditAvail == comp->ButPkmEditAvail) insert(items, BUTPKMEDITAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmMtyDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFOSVALID, TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPACHACTIVE, PUPOSACTIVE, BUTOSEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMtyDetail::Tag
 ******************************************************************************/

PnlWznmMtyDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptAch
			, const string& CptOs
			, const string& CptCch
			, const string& CptPkm
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptAch = CptAch;
	this->CptOs = CptOs;
	this->CptCch = CptCch;
	this->CptPkm = CptPkm;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTACH, CPTOS, CPTCCH, CPTPKM, CPTCMT};
};

bool PnlWznmMtyDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmMtyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmMtyDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAch", CptAch)) add(CPTACH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOs", CptOs)) add(CPTOS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCch", CptCch)) add(CPTCCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPkm", CptPkm)) add(CPTPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmMtyDetail::DpchAppData
 ******************************************************************************/

PnlWznmMtyDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMTYDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmMtyDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMtyDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmMtyDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMtyDetail::DpchAppDo
 ******************************************************************************/

PnlWznmMtyDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMTYDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmMtyDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMtyDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmMtyDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMtyDetail::DpchEngData
 ******************************************************************************/

PnlWznmMtyDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMMTYDETAILDATA)
		{
	feedFPupAch.tag = "FeedFPupAch";
	feedFPupOs.tag = "FeedFPupOs";
	feedFPupPkm.tag = "FeedFPupPkm";
};

string PnlWznmMtyDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPACH)) ss.push_back("feedFPupAch");
	if (has(FEEDFPUPOS)) ss.push_back("feedFPupOs");
	if (has(FEEDFPUPPKM)) ss.push_back("feedFPupPkm");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMtyDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmMtyDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupAch.readXML(docctx, basexpath, true)) add(FEEDFPUPACH);
		if (feedFPupOs.readXML(docctx, basexpath, true)) add(FEEDFPUPOS);
		if (feedFPupPkm.readXML(docctx, basexpath, true)) add(FEEDFPUPPKM);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupAch.clear();
		feedFPupOs.clear();
		feedFPupPkm.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

