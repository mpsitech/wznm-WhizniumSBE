/**
	* \file DlgWznmMchWriniscr.cpp
	* API code for job DlgWznmMchWriniscr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmMchWriniscr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmMchWriniscr::VecVDit
 ******************************************************************************/

uint DlgWznmMchWriniscr::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "wri") return WRI;
	if (s == "fia") return FIA;

	return(0);
};

string DlgWznmMchWriniscr::VecVDit::getSref(
			const uint ix
		) {
	if (ix == WRI) return("Wri");
	if (ix == FIA) return("Fia");

	return("");
};

/******************************************************************************
 class DlgWznmMchWriniscr::VecVDo
 ******************************************************************************/

uint DlgWznmMchWriniscr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmMchWriniscr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmMchWriniscr::VecVDoWri
 ******************************************************************************/

uint DlgWznmMchWriniscr::VecVDoWri::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmMchWriniscr::VecVDoWri::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmMchWriniscr::VecVSge
 ******************************************************************************/

uint DlgWznmMchWriniscr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "write") return WRITE;
	if (s == "pack") return PACK;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmMchWriniscr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == WRITE) return("write");
	if (ix == PACK) return("pack");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmMchWriniscr::ContIac
 ******************************************************************************/

DlgWznmMchWriniscr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
			, numFDse(numFDse)
		{
	mask = {NUMFDSE};
};

bool DlgWznmMchWriniscr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmMchWriniscr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmMchWriniscr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmMchWriniscr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmMchWriniscr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmMchWriniscr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmMchWriniscr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmMchWriniscr::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFDSE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmMchWriniscr::ContInf
 ******************************************************************************/

DlgWznmMchWriniscr::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
			, numFSge(numFSge)
		{
	mask = {NUMFSGE};
};

bool DlgWznmMchWriniscr::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmMchWriniscr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmMchWriniscr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmMchWriniscr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmMchWriniscr::ContInf::diff(
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
 class DlgWznmMchWriniscr::ContInfFia
 ******************************************************************************/

DlgWznmMchWriniscr::ContInfFia::ContInfFia(
			const string& Dld
		) :
			Block()
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWznmMchWriniscr::ContInfFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmMchWriniscrFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmMchWriniscrFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmMchWriniscr::ContInfFia::comm(
			const ContInfFia* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmMchWriniscr::ContInfFia::diff(
			const ContInfFia* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmMchWriniscr::ContInfWri
 ******************************************************************************/

DlgWznmMchWriniscr::ContInfWri::ContInfWri(
			const string& TxtPrg
		) :
			Block()
			, TxtPrg(TxtPrg)
		{
	mask = {TXTPRG};
};

bool DlgWznmMchWriniscr::ContInfWri::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmMchWriniscrWri");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmMchWriniscrWri";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmMchWriniscr::ContInfWri::comm(
			const ContInfWri* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmMchWriniscr::ContInfWri::diff(
			const ContInfWri* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmMchWriniscr::StatApp
 ******************************************************************************/

DlgWznmMchWriniscr::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
			, initdone(initdone)
			, shortMenu(shortMenu)
		{
	mask = {INITDONE, SHORTMENU};
};

bool DlgWznmMchWriniscr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmMchWriniscr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmMchWriniscr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmMchWriniscr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmMchWriniscr::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONE, SHORTMENU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmMchWriniscr::StatShr
 ******************************************************************************/

DlgWznmMchWriniscr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
			, ButDneActive(ButDneActive)
		{
	mask = {BUTDNEACTIVE};
};

bool DlgWznmMchWriniscr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmMchWriniscr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmMchWriniscr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmMchWriniscr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmMchWriniscr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmMchWriniscr::StatShrFia
 ******************************************************************************/

DlgWznmMchWriniscr::StatShrFia::StatShrFia(
			const bool DldActive
		) :
			Block()
			, DldActive(DldActive)
		{
	mask = {DLDACTIVE};
};

bool DlgWznmMchWriniscr::StatShrFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmMchWriniscrFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmMchWriniscrFia";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmMchWriniscr::StatShrFia::comm(
			const StatShrFia* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmMchWriniscr::StatShrFia::diff(
			const StatShrFia* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmMchWriniscr::StatShrWri
 ******************************************************************************/

DlgWznmMchWriniscr::StatShrWri::StatShrWri(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
			, ButRunActive(ButRunActive)
			, ButStoActive(ButStoActive)
		{
	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWznmMchWriniscr::StatShrWri::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmMchWriniscrWri");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmMchWriniscrWri";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmMchWriniscr::StatShrWri::comm(
			const StatShrWri* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmMchWriniscr::StatShrWri::diff(
			const StatShrWri* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmMchWriniscr::Tag
 ******************************************************************************/

DlgWznmMchWriniscr::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
			, Cpt(Cpt)
			, ButDne(ButDne)
		{
	mask = {CPT, BUTDNE};
};

bool DlgWznmMchWriniscr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmMchWriniscr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmMchWriniscr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmMchWriniscr::TagFia
 ******************************************************************************/

DlgWznmMchWriniscr::TagFia::TagFia(
			const string& Dld
		) :
			Block()
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWznmMchWriniscr::TagFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmMchWriniscrFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmMchWriniscrFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmMchWriniscr::TagWri
 ******************************************************************************/

DlgWznmMchWriniscr::TagWri::TagWri(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) :
			Block()
			, CptPrg(CptPrg)
			, ButRun(ButRun)
			, ButSto(ButSto)
		{
	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgWznmMchWriniscr::TagWri::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmMchWriniscrWri");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmMchWriniscrWri";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmMchWriniscr::DpchAppData
 ******************************************************************************/

DlgWznmMchWriniscr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMMCHWRINISCRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmMchWriniscr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmMchWriniscr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmMchWriniscrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmMchWriniscr::DpchAppDo
 ******************************************************************************/

DlgWznmMchWriniscr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoWri
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMMCHWRINISCRDO, scrJref)
			, ixVDo(ixVDo)
			, ixVDoWri(ixVDoWri)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOWRI};
	else this->mask = mask;

};

string DlgWznmMchWriniscr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOWRI)) ss.push_back("ixVDoWri");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmMchWriniscr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmMchWriniscrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOWRI)) writeString(wr, "srefIxVDoWri", VecVDoWri::getSref(ixVDoWri));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmMchWriniscr::DpchEngData
 ******************************************************************************/

DlgWznmMchWriniscr::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMMCHWRINISCRDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmMchWriniscr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFFIA)) ss.push_back("continffia");
	if (has(CONTINFWRI)) ss.push_back("continfwri");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRFIA)) ss.push_back("statshrfia");
	if (has(STATSHRWRI)) ss.push_back("statshrwri");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGFIA)) ss.push_back("tagfia");
	if (has(TAGWRI)) ss.push_back("tagwri");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmMchWriniscr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmMchWriniscrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continffia.readXML(docctx, basexpath, true)) add(CONTINFFIA);
		if (continfwri.readXML(docctx, basexpath, true)) add(CONTINFWRI);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrfia.readXML(docctx, basexpath, true)) add(STATSHRFIA);
		if (statshrwri.readXML(docctx, basexpath, true)) add(STATSHRWRI);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagfia.readXML(docctx, basexpath, true)) add(TAGFIA);
		if (tagwri.readXML(docctx, basexpath, true)) add(TAGWRI);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continffia = ContInfFia();
		continfwri = ContInfWri();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrfia = StatShrFia();
		statshrwri = StatShrWri();
		tag = Tag();
		tagfia = TagFia();
		tagwri = TagWri();
	};
};
