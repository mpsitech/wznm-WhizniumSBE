/**
	* \file DlgWznmVisExpstr.cpp
	* API code for job DlgWznmVisExpstr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "DlgWznmVisExpstr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVisExpstr::VecVDit
 ******************************************************************************/

uint DlgWznmVisExpstr::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "wri") return WRI;
	if (s == "mfi") return MFI;

	return(0);
};

string DlgWznmVisExpstr::VecVDit::getSref(
			const uint ix
		) {
	if (ix == WRI) return("Wri");
	if (ix == MFI) return("Mfi");

	return("");
};

/******************************************************************************
 class DlgWznmVisExpstr::VecVDo
 ******************************************************************************/

uint DlgWznmVisExpstr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmVisExpstr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmVisExpstr::VecVDoWri
 ******************************************************************************/

uint DlgWznmVisExpstr::VecVDoWri::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmVisExpstr::VecVDoWri::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmVisExpstr::VecVSge
 ******************************************************************************/

uint DlgWznmVisExpstr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "export") return EXPORT;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVisExpstr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == EXPORT) return("export");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmVisExpstr::ContIac
 ******************************************************************************/

DlgWznmVisExpstr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
			, numFDse(numFDse)
		{
	mask = {NUMFDSE};
};

bool DlgWznmVisExpstr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmVisExpstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmVisExpstr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmVisExpstr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmVisExpstr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmVisExpstr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVisExpstr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmVisExpstr::ContIac::diff(
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
 class DlgWznmVisExpstr::ContInf
 ******************************************************************************/

DlgWznmVisExpstr::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
			, numFSge(numFSge)
		{
	mask = {NUMFSGE};
};

bool DlgWznmVisExpstr::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVisExpstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVisExpstr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmVisExpstr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmVisExpstr::ContInf::diff(
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
 class DlgWznmVisExpstr::ContInfMfi
 ******************************************************************************/

DlgWznmVisExpstr::ContInfMfi::ContInfMfi(
			const string& Dld
		) :
			Block()
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWznmVisExpstr::ContInfMfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVisExpstrMfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVisExpstrMfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmVisExpstr::ContInfMfi::comm(
			const ContInfMfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmVisExpstr::ContInfMfi::diff(
			const ContInfMfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVisExpstr::ContInfWri
 ******************************************************************************/

DlgWznmVisExpstr::ContInfWri::ContInfWri(
			const string& TxtPrg
		) :
			Block()
			, TxtPrg(TxtPrg)
		{
	mask = {TXTPRG};
};

bool DlgWznmVisExpstr::ContInfWri::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVisExpstrWri");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVisExpstrWri";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmVisExpstr::ContInfWri::comm(
			const ContInfWri* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmVisExpstr::ContInfWri::diff(
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
 class DlgWznmVisExpstr::StatApp
 ******************************************************************************/

DlgWznmVisExpstr::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
			, initdone(initdone)
			, shortMenu(shortMenu)
		{
	mask = {INITDONE, SHORTMENU};
};

bool DlgWznmVisExpstr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmVisExpstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmVisExpstr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmVisExpstr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmVisExpstr::StatApp::diff(
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
 class DlgWznmVisExpstr::StatShr
 ******************************************************************************/

DlgWznmVisExpstr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
			, ButDneActive(ButDneActive)
		{
	mask = {BUTDNEACTIVE};
};

bool DlgWznmVisExpstr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVisExpstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVisExpstr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVisExpstr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmVisExpstr::StatShr::diff(
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
 class DlgWznmVisExpstr::StatShrMfi
 ******************************************************************************/

DlgWznmVisExpstr::StatShrMfi::StatShrMfi(
			const bool DldActive
		) :
			Block()
			, DldActive(DldActive)
		{
	mask = {DLDACTIVE};
};

bool DlgWznmVisExpstr::StatShrMfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVisExpstrMfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVisExpstrMfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVisExpstr::StatShrMfi::comm(
			const StatShrMfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmVisExpstr::StatShrMfi::diff(
			const StatShrMfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVisExpstr::StatShrWri
 ******************************************************************************/

DlgWznmVisExpstr::StatShrWri::StatShrWri(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
			, ButRunActive(ButRunActive)
			, ButStoActive(ButStoActive)
		{
	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWznmVisExpstr::StatShrWri::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVisExpstrWri");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVisExpstrWri";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVisExpstr::StatShrWri::comm(
			const StatShrWri* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmVisExpstr::StatShrWri::diff(
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
 class DlgWznmVisExpstr::Tag
 ******************************************************************************/

DlgWznmVisExpstr::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
			, Cpt(Cpt)
			, ButDne(ButDne)
		{
	mask = {CPT, BUTDNE};
};

bool DlgWznmVisExpstr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVisExpstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVisExpstr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVisExpstr::TagMfi
 ******************************************************************************/

DlgWznmVisExpstr::TagMfi::TagMfi(
			const string& Dld
		) :
			Block()
			, Dld(Dld)
		{
	mask = {DLD};
};

bool DlgWznmVisExpstr::TagMfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVisExpstrMfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVisExpstrMfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVisExpstr::TagWri
 ******************************************************************************/

DlgWznmVisExpstr::TagWri::TagWri(
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

bool DlgWznmVisExpstr::TagWri::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVisExpstrWri");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVisExpstrWri";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVisExpstr::DpchAppData
 ******************************************************************************/

DlgWznmVisExpstr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVISEXPSTRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmVisExpstr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVisExpstr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVisExpstrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVisExpstr::DpchAppDo
 ******************************************************************************/

DlgWznmVisExpstr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoWri
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVISEXPSTRDO, scrJref)
			, ixVDo(ixVDo)
			, ixVDoWri(ixVDoWri)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOWRI};
	else this->mask = mask;

};

string DlgWznmVisExpstr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOWRI)) ss.push_back("ixVDoWri");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVisExpstr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVisExpstrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOWRI)) writeString(wr, "srefIxVDoWri", VecVDoWri::getSref(ixVDoWri));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVisExpstr::DpchEngData
 ******************************************************************************/

DlgWznmVisExpstr::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVISEXPSTRDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmVisExpstr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFMFI)) ss.push_back("continfmfi");
	if (has(CONTINFWRI)) ss.push_back("continfwri");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRMFI)) ss.push_back("statshrmfi");
	if (has(STATSHRWRI)) ss.push_back("statshrwri");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGMFI)) ss.push_back("tagmfi");
	if (has(TAGWRI)) ss.push_back("tagwri");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVisExpstr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmVisExpstrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfmfi.readXML(docctx, basexpath, true)) add(CONTINFMFI);
		if (continfwri.readXML(docctx, basexpath, true)) add(CONTINFWRI);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrmfi.readXML(docctx, basexpath, true)) add(STATSHRMFI);
		if (statshrwri.readXML(docctx, basexpath, true)) add(STATSHRWRI);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagmfi.readXML(docctx, basexpath, true)) add(TAGMFI);
		if (tagwri.readXML(docctx, basexpath, true)) add(TAGWRI);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continfmfi = ContInfMfi();
		continfwri = ContInfWri();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrmfi = StatShrMfi();
		statshrwri = StatShrWri();
		tag = Tag();
		tagmfi = TagMfi();
		tagwri = TagWri();
	};
};
