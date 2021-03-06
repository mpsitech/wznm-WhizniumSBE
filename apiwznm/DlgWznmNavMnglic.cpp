/**
	* \file DlgWznmNavMnglic.cpp
	* API code for job DlgWznmNavMnglic (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmNavMnglic.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmNavMnglic::VecVDo
 ******************************************************************************/

uint DlgWznmNavMnglic::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutscnclick") return DETBUTSCNCLICK;
	if (s == "detbutsdcclick") return DETBUTSDCCLICK;
	if (s == "detbutactclick") return DETBUTACTCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmNavMnglic::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTSCNCLICK) return("DetButScnClick");
	if (ix == DETBUTSDCCLICK) return("DetButSdcClick");
	if (ix == DETBUTACTCLICK) return("DetButActClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmNavMnglic::VecVSge
 ******************************************************************************/

uint DlgWznmNavMnglic::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;

	return(0);
};

string DlgWznmNavMnglic::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");

	return("");
};

/******************************************************************************
 class DlgWznmNavMnglic::ContIac
 ******************************************************************************/

DlgWznmNavMnglic::ContIac::ContIac(
			const uint numFDetPupFis
			, const bool DetChkFis
			, const uint numFDetLstLcs
		) :
			Block()
		{
	this->numFDetPupFis = numFDetPupFis;
	this->DetChkFis = DetChkFis;
	this->numFDetLstLcs = numFDetLstLcs;

	mask = {NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS};
};

bool DlgWznmNavMnglic::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmNavMnglic");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmNavMnglic";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupFis", numFDetPupFis)) add(NUMFDETPUPFIS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetChkFis", DetChkFis)) add(DETCHKFIS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetLstLcs", numFDetLstLcs)) add(NUMFDETLSTLCS);
	};

	return basefound;
};

void DlgWznmNavMnglic::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmNavMnglic";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmNavMnglic";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupFis", numFDetPupFis);
		writeBoolAttr(wr, itemtag, "sref", "DetChkFis", DetChkFis);
		writeUintAttr(wr, itemtag, "sref", "numFDetLstLcs", numFDetLstLcs);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmNavMnglic::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupFis == comp->numFDetPupFis) insert(items, NUMFDETPUPFIS);
	if (DetChkFis == comp->DetChkFis) insert(items, DETCHKFIS);
	if (numFDetLstLcs == comp->numFDetLstLcs) insert(items, NUMFDETLSTLCS);

	return(items);
};

set<uint> DlgWznmNavMnglic::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmNavMnglic::ContInf
 ******************************************************************************/

DlgWznmNavMnglic::ContInf::ContInf(
			const uint numFSge
			, const string& DetTxtSip
			, const string& DetTxtScp
			, const string& DetTxtLsr
			, const string& DetTxtLar
			, const string& DetTxtLst
			, const string& DetTxtLex
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->DetTxtSip = DetTxtSip;
	this->DetTxtScp = DetTxtScp;
	this->DetTxtLsr = DetTxtLsr;
	this->DetTxtLar = DetTxtLar;
	this->DetTxtLst = DetTxtLst;
	this->DetTxtLex = DetTxtLex;

	mask = {NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX};
};

bool DlgWznmNavMnglic::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmNavMnglic");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmNavMnglic";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtSip", DetTxtSip)) add(DETTXTSIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtScp", DetTxtScp)) add(DETTXTSCP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtLsr", DetTxtLsr)) add(DETTXTLSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtLar", DetTxtLar)) add(DETTXTLAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtLst", DetTxtLst)) add(DETTXTLST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxtLex", DetTxtLex)) add(DETTXTLEX);
	};

	return basefound;
};

set<uint> DlgWznmNavMnglic::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (DetTxtSip == comp->DetTxtSip) insert(items, DETTXTSIP);
	if (DetTxtScp == comp->DetTxtScp) insert(items, DETTXTSCP);
	if (DetTxtLsr == comp->DetTxtLsr) insert(items, DETTXTLSR);
	if (DetTxtLar == comp->DetTxtLar) insert(items, DETTXTLAR);
	if (DetTxtLst == comp->DetTxtLst) insert(items, DETTXTLST);
	if (DetTxtLex == comp->DetTxtLex) insert(items, DETTXTLEX);

	return(items);
};

set<uint> DlgWznmNavMnglic::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmNavMnglic::StatApp
 ******************************************************************************/

DlgWznmNavMnglic::StatApp::StatApp(
			const string& shortMenu
			, const uint DetLstLcsNumFirstdisp
		) :
			Block()
		{
	this->shortMenu = shortMenu;
	this->DetLstLcsNumFirstdisp = DetLstLcsNumFirstdisp;

	mask = {SHORTMENU, DETLSTLCSNUMFIRSTDISP};
};

bool DlgWznmNavMnglic::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmNavMnglic");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmNavMnglic";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetLstLcsNumFirstdisp", DetLstLcsNumFirstdisp)) add(DETLSTLCSNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> DlgWznmNavMnglic::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (DetLstLcsNumFirstdisp == comp->DetLstLcsNumFirstdisp) insert(items, DETLSTLCSNUMFIRSTDISP);

	return(items);
};

set<uint> DlgWznmNavMnglic::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SHORTMENU, DETLSTLCSNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmNavMnglic::StatShr
 ******************************************************************************/

DlgWznmNavMnglic::StatShr::StatShr(
			const bool DetButActActive
		) :
			Block()
		{
	this->DetButActActive = DetButActActive;

	mask = {DETBUTACTACTIVE};
};

bool DlgWznmNavMnglic::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmNavMnglic");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmNavMnglic";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetButActActive", DetButActActive)) add(DETBUTACTACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmNavMnglic::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButActActive == comp->DetButActActive) insert(items, DETBUTACTACTIVE);

	return(items);
};

set<uint> DlgWznmNavMnglic::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTACTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmNavMnglic::Tag
 ******************************************************************************/

DlgWznmNavMnglic::Tag::Tag(
			const string& Cpt
			, const string& DetHdgSrv
			, const string& DetCptSip
			, const string& DetCptScp
			, const string& DetButScn
			, const string& DetButSdc
			, const string& DetCptFis
			, const string& DetCptLcs
			, const string& DetButAct
			, const string& DetHdgLic
			, const string& DetCptLsr
			, const string& DetCptLar
			, const string& DetCptLst
			, const string& DetCptLex
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->DetHdgSrv = DetHdgSrv;
	this->DetCptSip = DetCptSip;
	this->DetCptScp = DetCptScp;
	this->DetButScn = DetButScn;
	this->DetButSdc = DetButSdc;
	this->DetCptFis = DetCptFis;
	this->DetCptLcs = DetCptLcs;
	this->DetButAct = DetButAct;
	this->DetHdgLic = DetHdgLic;
	this->DetCptLsr = DetCptLsr;
	this->DetCptLar = DetCptLar;
	this->DetCptLst = DetCptLst;
	this->DetCptLex = DetCptLex;
	this->ButDne = ButDne;

	mask = {CPT, DETHDGSRV, DETCPTSIP, DETCPTSCP, DETBUTSCN, DETBUTSDC, DETCPTFIS, DETCPTLCS, DETBUTACT, DETHDGLIC, DETCPTLSR, DETCPTLAR, DETCPTLST, DETCPTLEX, BUTDNE};
};

bool DlgWznmNavMnglic::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmNavMnglic");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmNavMnglic";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetHdgSrv", DetHdgSrv)) add(DETHDGSRV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptSip", DetCptSip)) add(DETCPTSIP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptScp", DetCptScp)) add(DETCPTSCP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButScn", DetButScn)) add(DETBUTSCN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButSdc", DetButSdc)) add(DETBUTSDC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptFis", DetCptFis)) add(DETCPTFIS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptLcs", DetCptLcs)) add(DETCPTLCS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetButAct", DetButAct)) add(DETBUTACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetHdgLic", DetHdgLic)) add(DETHDGLIC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptLsr", DetCptLsr)) add(DETCPTLSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptLar", DetCptLar)) add(DETCPTLAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptLst", DetCptLst)) add(DETCPTLST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptLex", DetCptLex)) add(DETCPTLEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmNavMnglic::DpchAppData
 ******************************************************************************/

DlgWznmNavMnglic::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMNAVMNGLICDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmNavMnglic::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmNavMnglic::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmNavMnglicData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmNavMnglic::DpchAppDo
 ******************************************************************************/

DlgWznmNavMnglic::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMNAVMNGLICDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWznmNavMnglic::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmNavMnglic::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmNavMnglicDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmNavMnglic::DpchEngData
 ******************************************************************************/

DlgWznmNavMnglic::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMNAVMNGLICDATA)
		{
	feedFDetLstLcs.tag = "FeedFDetLstLcs";
	feedFDetPupFis.tag = "FeedFDetPupFis";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmNavMnglic::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETLSTLCS)) ss.push_back("feedFDetLstLcs");
	if (has(FEEDFDETPUPFIS)) ss.push_back("feedFDetPupFis");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmNavMnglic::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmNavMnglicData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFDetLstLcs.readXML(docctx, basexpath, true)) add(FEEDFDETLSTLCS);
		if (feedFDetPupFis.readXML(docctx, basexpath, true)) add(FEEDFDETPUPFIS);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFDetLstLcs.clear();
		feedFDetPupFis.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
