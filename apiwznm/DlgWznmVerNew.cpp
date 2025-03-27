/**
	* \file DlgWznmVerNew.cpp
	* API code for job DlgWznmVerNew (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmVerNew.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVerNew::VecVDo
 ******************************************************************************/

uint DlgWznmVerNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcncclick") return BUTCNCCLICK;
	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWznmVerNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCNCCLICK) return("ButCncClick");
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWznmVerNew::VecVSge
 ******************************************************************************/

uint DlgWznmVerNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVerNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmVerNew::VecVVni
 ******************************************************************************/

uint DlgWznmVerNew::VecVVni::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "maj") return MAJ;
	if (s == "min") return MIN;
	if (s == "sub") return SUB;
	if (s == "void") return VOID;

	return(0);
};

string DlgWznmVerNew::VecVVni::getSref(
			const uint ix
		) {
	if (ix == MAJ) return("maj");
	if (ix == MIN) return("min");
	if (ix == SUB) return("sub");
	if (ix == VOID) return("void");

	return("");
};

/******************************************************************************
 class DlgWznmVerNew::ContIac
 ******************************************************************************/

DlgWznmVerNew::ContIac::ContIac(
			const uint numFDetPupPrj
			, const uint numFDetPupBvr
			, const uint numFDetRbuVni
			, const string& DetTxfCmt
			, const vector<uint>& numsFDetLstLoc
			, const uint numFDetPupPlc
		) :
			Block()
			, numFDetPupPrj(numFDetPupPrj)
			, numFDetPupBvr(numFDetPupBvr)
			, numFDetRbuVni(numFDetRbuVni)
			, DetTxfCmt(DetTxfCmt)
			, numsFDetLstLoc(numsFDetLstLoc)
			, numFDetPupPlc(numFDetPupPlc)
		{
	mask = {NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT, NUMSFDETLSTLOC, NUMFDETPUPPLC};
};

bool DlgWznmVerNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmVerNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupPrj", numFDetPupPrj)) add(NUMFDETPUPPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupBvr", numFDetPupBvr)) add(NUMFDETPUPBVR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetRbuVni", numFDetRbuVni)) add(NUMFDETRBUVNI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "DetTxfCmt", DetTxfCmt)) add(DETTXFCMT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFDetLstLoc", numsFDetLstLoc)) add(NUMSFDETLSTLOC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDetPupPlc", numFDetPupPlc)) add(NUMFDETPUPPLC);
	};

	return basefound;
};

void DlgWznmVerNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmVerNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmVerNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDetPupPrj", numFDetPupPrj);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupBvr", numFDetPupBvr);
		writeUintAttr(wr, itemtag, "sref", "numFDetRbuVni", numFDetRbuVni);
		writeStringAttr(wr, itemtag, "sref", "DetTxfCmt", DetTxfCmt);
		writeUintvecAttr(wr, itemtag, "sref", "numsFDetLstLoc", numsFDetLstLoc);
		writeUintAttr(wr, itemtag, "sref", "numFDetPupPlc", numFDetPupPlc);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDetPupPrj == comp->numFDetPupPrj) insert(items, NUMFDETPUPPRJ);
	if (numFDetPupBvr == comp->numFDetPupBvr) insert(items, NUMFDETPUPBVR);
	if (numFDetRbuVni == comp->numFDetRbuVni) insert(items, NUMFDETRBUVNI);
	if (DetTxfCmt == comp->DetTxfCmt) insert(items, DETTXFCMT);
	if (compareUintvec(numsFDetLstLoc, comp->numsFDetLstLoc)) insert(items, NUMSFDETLSTLOC);
	if (numFDetPupPlc == comp->numFDetPupPlc) insert(items, NUMFDETPUPPLC);

	return(items);
};

set<uint> DlgWznmVerNew::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT, NUMSFDETLSTLOC, NUMFDETPUPPLC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerNew::ContInf
 ******************************************************************************/

DlgWznmVerNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
			, numFSge(numFSge)
		{
	mask = {NUMFSGE};
};

bool DlgWznmVerNew::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVerNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmVerNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmVerNew::ContInf::diff(
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
 class DlgWznmVerNew::StatApp
 ******************************************************************************/

DlgWznmVerNew::StatApp::StatApp(
			const string& shortMenu
			, const uint DetLstLocNumFirstdisp
		) :
			Block()
			, shortMenu(shortMenu)
			, DetLstLocNumFirstdisp(DetLstLocNumFirstdisp)
		{
	mask = {SHORTMENU, DETLSTLOCNUMFIRSTDISP};
};

bool DlgWznmVerNew::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmVerNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DetLstLocNumFirstdisp", DetLstLocNumFirstdisp)) add(DETLSTLOCNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> DlgWznmVerNew::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (DetLstLocNumFirstdisp == comp->DetLstLocNumFirstdisp) insert(items, DETLSTLOCNUMFIRSTDISP);

	return(items);
};

set<uint> DlgWznmVerNew::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SHORTMENU, DETLSTLOCNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerNew::StatShr
 ******************************************************************************/

DlgWznmVerNew::StatShr::StatShr(
			const bool ButCreActive
		) :
			Block()
			, ButCreActive(ButCreActive)
		{
	mask = {BUTCREACTIVE};
};

bool DlgWznmVerNew::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVerNew";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCreActive", ButCreActive)) add(BUTCREACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVerNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWznmVerNew::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerNew::Tag
 ******************************************************************************/

DlgWznmVerNew::Tag::Tag(
			const string& Cpt
			, const string& DetCptPrj
			, const string& DetCptBvr
			, const string& DetCptVni
			, const string& DetCptCmt
			, const string& DetCptLoc
			, const string& DetCptPlc
			, const string& ButCnc
			, const string& ButCre
		) :
			Block()
			, Cpt(Cpt)
			, DetCptPrj(DetCptPrj)
			, DetCptBvr(DetCptBvr)
			, DetCptVni(DetCptVni)
			, DetCptCmt(DetCptCmt)
			, DetCptLoc(DetCptLoc)
			, DetCptPlc(DetCptPlc)
			, ButCnc(ButCnc)
			, ButCre(ButCre)
		{
	mask = {CPT, DETCPTPRJ, DETCPTBVR, DETCPTVNI, DETCPTCMT, DETCPTLOC, DETCPTPLC, BUTCNC, BUTCRE};
};

bool DlgWznmVerNew::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVerNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVerNew";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptPrj", DetCptPrj)) add(DETCPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptBvr", DetCptBvr)) add(DETCPTBVR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptVni", DetCptVni)) add(DETCPTVNI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptCmt", DetCptCmt)) add(DETCPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptLoc", DetCptLoc)) add(DETCPTLOC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "DetCptPlc", DetCptPlc)) add(DETCPTPLC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCnc", ButCnc)) add(BUTCNC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButCre", ButCre)) add(BUTCRE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVerNew::DpchAppData
 ******************************************************************************/

DlgWznmVerNew::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmVerNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerNew::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVerNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerNew::DpchAppDo
 ******************************************************************************/

DlgWznmVerNew::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string DlgWznmVerNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerNew::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVerNewDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerNew::DpchEngData
 ******************************************************************************/

DlgWznmVerNew::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVERNEWDATA)
		{
	feedFDetLstLoc.tag = "FeedFDetLstLoc";
	feedFDetPupBvr.tag = "FeedFDetPupBvr";
	feedFDetPupPlc.tag = "FeedFDetPupPlc";
	feedFDetPupPrj.tag = "FeedFDetPupPrj";
	feedFDetRbuVni.tag = "FeedFDetRbuVni";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmVerNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETLSTLOC)) ss.push_back("feedFDetLstLoc");
	if (has(FEEDFDETPUPBVR)) ss.push_back("feedFDetPupBvr");
	if (has(FEEDFDETPUPPLC)) ss.push_back("feedFDetPupPlc");
	if (has(FEEDFDETPUPPRJ)) ss.push_back("feedFDetPupPrj");
	if (has(FEEDFDETRBUVNI)) ss.push_back("feedFDetRbuVni");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerNew::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmVerNewData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFDetLstLoc.readXML(docctx, basexpath, true)) add(FEEDFDETLSTLOC);
		if (feedFDetPupBvr.readXML(docctx, basexpath, true)) add(FEEDFDETPUPBVR);
		if (feedFDetPupPlc.readXML(docctx, basexpath, true)) add(FEEDFDETPUPPLC);
		if (feedFDetPupPrj.readXML(docctx, basexpath, true)) add(FEEDFDETPUPPRJ);
		if (feedFDetRbuVni.readXML(docctx, basexpath, true)) add(FEEDFDETRBUVNI);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFDetLstLoc.clear();
		feedFDetPupBvr.clear();
		feedFDetPupPlc.clear();
		feedFDetPupPrj.clear();
		feedFDetRbuVni.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
