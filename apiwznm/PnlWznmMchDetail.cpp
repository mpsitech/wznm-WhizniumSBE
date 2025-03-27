/**
	* \file PnlWznmMchDetail.cpp
	* API code for job PnlWznmMchDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmMchDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmMchDetail::VecVDo
 ******************************************************************************/

uint PnlWznmMchDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butcchviewclick") return BUTCCHVIEWCLICK;
	if (s == "butpkmeditclick") return BUTPKMEDITCLICK;

	return(0);
};

string PnlWznmMchDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTCCHVIEWCLICK) return("ButCchViewClick");
	if (ix == BUTPKMEDITCLICK) return("ButPkmEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmMchDetail::ContIac
 ******************************************************************************/

PnlWznmMchDetail::ContIac::ContIac(
			const uint numFPupPkm
			, const string& TxfPkm
			, const string& TxfCmt
		) :
			Block()
			, numFPupPkm(numFPupPkm)
			, TxfPkm(TxfPkm)
			, TxfCmt(TxfCmt)
		{
	mask = {NUMFPUPPKM, TXFPKM, TXFCMT};
};

bool PnlWznmMchDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmMchDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmMchDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPkm", numFPupPkm)) add(NUMFPUPPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPkm", TxfPkm)) add(TXFPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmMchDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmMchDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmMchDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupPkm", numFPupPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfPkm", TxfPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMchDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupPkm == comp->numFPupPkm) insert(items, NUMFPUPPKM);
	if (TxfPkm == comp->TxfPkm) insert(items, TXFPKM);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmMchDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPPKM, TXFPKM, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchDetail::ContInf
 ******************************************************************************/

PnlWznmMchDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtSup
			, const string& TxtCch
		) :
			Block()
			, TxtSrf(TxtSrf)
			, TxtSup(TxtSup)
			, TxtCch(TxtCch)
		{
	mask = {TXTSRF, TXTSUP, TXTCCH};
};

bool PnlWznmMchDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmMchDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmMchDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCch", TxtCch)) add(TXTCCH);
	};

	return basefound;
};

set<uint> PnlWznmMchDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtCch == comp->TxtCch) insert(items, TXTCCH);

	return(items);
};

set<uint> PnlWznmMchDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTSUP, TXTCCH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchDetail::StatApp
 ******************************************************************************/

PnlWznmMchDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool PupPkmAlt
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
			, PupPkmAlt(PupPkmAlt)
		{
	mask = {IXWZNMVEXPSTATE, PUPPKMALT};
};

bool PnlWznmMchDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmMchDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmMchDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPkmAlt", PupPkmAlt)) add(PUPPKMALT);
	};

	return basefound;
};

set<uint> PnlWznmMchDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (PupPkmAlt == comp->PupPkmAlt) insert(items, PUPPKMALT);

	return(items);
};

set<uint> PnlWznmMchDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, PUPPKMALT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchDetail::StatShr
 ******************************************************************************/

PnlWznmMchDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtCchActive
			, const bool ButCchViewAvail
			, const bool ButCchViewActive
			, const bool PupPkmActive
			, const bool TxfPkmValid
			, const bool ButPkmEditAvail
			, const bool TxfCmtActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, TxtSupActive(TxtSupActive)
			, ButSupViewAvail(ButSupViewAvail)
			, ButSupViewActive(ButSupViewActive)
			, TxtCchActive(TxtCchActive)
			, ButCchViewAvail(ButCchViewAvail)
			, ButCchViewActive(ButCchViewActive)
			, PupPkmActive(PupPkmActive)
			, TxfPkmValid(TxfPkmValid)
			, ButPkmEditAvail(ButPkmEditAvail)
			, TxfCmtActive(TxfCmtActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, TXFPKMVALID, BUTPKMEDITAVAIL, TXFCMTACTIVE};
};

bool PnlWznmMchDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmMchDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmMchDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCchActive", TxtCchActive)) add(TXTCCHACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCchViewAvail", ButCchViewAvail)) add(BUTCCHVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCchViewActive", ButCchViewActive)) add(BUTCCHVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPkmActive", PupPkmActive)) add(PUPPKMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPkmValid", TxfPkmValid)) add(TXFPKMVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPkmEditAvail", ButPkmEditAvail)) add(BUTPKMEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmMchDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtCchActive == comp->TxtCchActive) insert(items, TXTCCHACTIVE);
	if (ButCchViewAvail == comp->ButCchViewAvail) insert(items, BUTCCHVIEWAVAIL);
	if (ButCchViewActive == comp->ButCchViewActive) insert(items, BUTCCHVIEWACTIVE);
	if (PupPkmActive == comp->PupPkmActive) insert(items, PUPPKMACTIVE);
	if (TxfPkmValid == comp->TxfPkmValid) insert(items, TXFPKMVALID);
	if (ButPkmEditAvail == comp->ButPkmEditAvail) insert(items, BUTPKMEDITAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmMchDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, TXFPKMVALID, BUTPKMEDITAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchDetail::Tag
 ******************************************************************************/

PnlWznmMchDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSup
			, const string& CptCch
			, const string& CptPkm
			, const string& CptCmt
		) :
			Block()
			, Cpt(Cpt)
			, CptSrf(CptSrf)
			, CptSup(CptSup)
			, CptCch(CptCch)
			, CptPkm(CptPkm)
			, CptCmt(CptCmt)
		{
	mask = {CPT, CPTSRF, CPTSUP, CPTCCH, CPTPKM, CPTCMT};
};

bool PnlWznmMchDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmMchDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmMchDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCch", CptCch)) add(CPTCCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPkm", CptPkm)) add(CPTPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmMchDetail::DpchAppData
 ******************************************************************************/

PnlWznmMchDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMCHDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmMchDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMchDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmMchDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMchDetail::DpchAppDo
 ******************************************************************************/

PnlWznmMchDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMCHDETAILDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmMchDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMchDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmMchDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMchDetail::DpchEngData
 ******************************************************************************/

PnlWznmMchDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMMCHDETAILDATA)
		{
	feedFPupPkm.tag = "FeedFPupPkm";
};

string PnlWznmMchDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPPKM)) ss.push_back("feedFPupPkm");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMchDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmMchDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupPkm.readXML(docctx, basexpath, true)) add(FEEDFPUPPKM);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupPkm.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
