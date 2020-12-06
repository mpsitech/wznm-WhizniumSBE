/**
	* \file DlgWznmAppNew.cpp
	* API code for job DlgWznmAppNew (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmAppNew.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmAppNew::VecVDo
 ******************************************************************************/

uint DlgWznmAppNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWznmAppNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWznmAppNew::VecVSge
 ******************************************************************************/

uint DlgWznmAppNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmAppNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmAppNew::ContIac
 ******************************************************************************/

DlgWznmAppNew::ContIac::ContIac(
			const uint numFDetPupTrg
			, const uint numFDetPupVer
			, const string& DetTxfSho
			, const string& DetTxfTit
		) :
			Block()
		{
	this->numFDetPupTrg = numFDetPupTrg;
	this->numFDetPupVer = numFDetPupVer;
	this->DetTxfSho = DetTxfSho;
	this->DetTxfTit = DetTxfTit;

	mask = {NUMFDETPUPTRG, NUMFDETPUPVER, DETTXFSHO, DETTXFTIT};
};

bool DlgWznmAppNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmAppNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmAppNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupTrg", numFDetPupTrg)) add(NUMFDETPUPTRG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupVer", numFDetPupVer)) add(NUMFDETPUPVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfSho", DetTxfSho)) add(DETTXFSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfTit", DetTxfTit)) add(DETTXFTIT);
	};

	return basefound;
};

void DlgWznmAppNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmAppNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmAppNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupTrg", numFDetPupTrg);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupVer", numFDetPupVer);
		writeStringAttr(wr, itemtag, "sref", "DetTxfSho", DetTxfSho);
		writeStringAttr(wr, itemtag, "sref", "DetTxfTit", DetTxfTit);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmAppNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupTrg == comp->numFDetPupTrg) insert(items, NUMFDETPUPTRG);
	if (numFDetPupVer == comp->numFDetPupVer) insert(items, NUMFDETPUPVER);
	if (DetTxfSho == comp->DetTxfSho) insert(items, DETTXFSHO);
	if (DetTxfTit == comp->DetTxfTit) insert(items, DETTXFTIT);

	return(items);
};

set<uint> DlgWznmAppNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPTRG, NUMFDETPUPVER, DETTXFSHO, DETTXFTIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmAppNew::ContInf
 ******************************************************************************/

DlgWznmAppNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWznmAppNew::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmAppNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmAppNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmAppNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmAppNew::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmAppNew::StatApp
 ******************************************************************************/

DlgWznmAppNew::StatApp::StatApp(
			const string& shortMenu
		) :
			Block()
		{
	this->shortMenu = shortMenu;

	mask = {SHORTMENU};
};

bool DlgWznmAppNew::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmAppNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmAppNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmAppNew::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmAppNew::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SHORTMENU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmAppNew::StatShr
 ******************************************************************************/

DlgWznmAppNew::StatShr::StatShr(
			const bool ButCncActive
			, const bool ButCreActive
		) :
			Block()
		{
	this->ButCncActive = ButCncActive;
	this->ButCreActive = ButCreActive;

	mask = {BUTCNCACTIVE, BUTCREACTIVE};
};

bool DlgWznmAppNew::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmAppNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmAppNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCncActive", ButCncActive)) add(BUTCNCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmAppNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCncActive == comp->ButCncActive) insert(items, BUTCNCACTIVE);
	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWznmAppNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCNCACTIVE, BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmAppNew::Tag
 ******************************************************************************/

DlgWznmAppNew::Tag::Tag(
			const string& Cpt
			, const string& DetCptTrg
			, const string& DetCptVer
			, const string& DetCptSho
			, const string& DetCptTit
			, const string& ButCnc
			, const string& ButCre
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->DetCptTrg = DetCptTrg;
	this->DetCptVer = DetCptVer;
	this->DetCptSho = DetCptSho;
	this->DetCptTit = DetCptTit;
	this->ButCnc = ButCnc;
	this->ButCre = ButCre;

	mask = {CPT, DETCPTTRG, DETCPTVER, DETCPTSHO, DETCPTTIT, BUTCNC, BUTCRE};
};

bool DlgWznmAppNew::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmAppNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmAppNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptTrg", DetCptTrg)) add(DETCPTTRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptVer", DetCptVer)) add(DETCPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptSho", DetCptSho)) add(DETCPTSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptTit", DetCptTit)) add(DETCPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCnc", ButCnc)) add(BUTCNC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmAppNew::DpchAppData
 ******************************************************************************/

DlgWznmAppNew::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMAPPNEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmAppNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmAppNew::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmAppNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmAppNew::DpchAppDo
 ******************************************************************************/

DlgWznmAppNew::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMAPPNEWDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string DlgWznmAppNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmAppNew::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmAppNewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmAppNew::DpchEngData
 ******************************************************************************/

DlgWznmAppNew::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMAPPNEWDATA)
		{
	feedFDetPupTrg.tag = "FeedFDetPupTrg";
	feedFDetPupVer.tag = "FeedFDetPupVer";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmAppNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETPUPTRG)) ss.push_back("feedFDetPupTrg");
	if (has(FEEDFDETPUPVER)) ss.push_back("feedFDetPupVer");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmAppNew::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmAppNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFDetPupTrg.readXML(docctx, basexpath, true)) add(FEEDFDETPUPTRG);
		if (feedFDetPupVer.readXML(docctx, basexpath, true)) add(FEEDFDETPUPVER);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFDetPupTrg.clear();
		feedFDetPupVer.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
