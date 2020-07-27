/**
	* \file DlgWznmVerGenui_blks.cpp
	* job handler for job DlgWznmVerGenui (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVerGenui::VecVDit
 ******************************************************************************/

uint DlgWznmVerGenui::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "gui") return GUI;
	if (s == "lfi") return LFI;

	return(0);
};

string DlgWznmVerGenui::VecVDit::getSref(
			const uint ix
		) {
	if (ix == GUI) return("Gui");
	if (ix == LFI) return("Lfi");

	return("");
};

string DlgWznmVerGenui::VecVDit::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == GUI) return("Input file");
		if (ix == LFI) return("Log file");
		return(getSref(ix));
	};

	return("");
};

void DlgWznmVerGenui::VecVDit::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DlgWznmVerGenui::VecVDo
 ******************************************************************************/

uint DlgWznmVerGenui::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "guibutrunclick") return GUIBUTRUNCLICK;
	if (s == "guibutstoclick") return GUIBUTSTOCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmVerGenui::VecVDo::getSref(
			const uint ix
		) {
	if (ix == GUIBUTRUNCLICK) return("GuiButRunClick");
	if (ix == GUIBUTSTOCLICK) return("GuiButStoClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmVerGenui::VecVSge
 ******************************************************************************/

uint DlgWznmVerGenui::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrger") return ALRGER;
	if (s == "genui") return GENUI;
	if (s == "genctp") return GENCTP;
	if (s == "asmlfi") return ASMLFI;
	if (s == "fail") return FAIL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVerGenui::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRGER) return("alrger");
	if (ix == GENUI) return("genui");
	if (ix == GENCTP) return("genctp");
	if (ix == ASMLFI) return("asmlfi");
	if (ix == FAIL) return("fail");
	if (ix == DONE) return("done");

	return("");
};

void DlgWznmVerGenui::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmVerGenui::ContIac
 ******************************************************************************/

DlgWznmVerGenui::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWznmVerGenui::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmVerGenui");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmVerGenui";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmVerGenui::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmVerGenui";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmVerGenui";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerGenui::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmVerGenui::ContIac::diff(
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
 class DlgWznmVerGenui::ContInf
 ******************************************************************************/

DlgWznmVerGenui::ContInf::ContInf(
			const uint numFSge
			, const string& GuiTxtPrg
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->GuiTxtPrg = GuiTxtPrg;

	mask = {NUMFSGE, GUITXTPRG};
};

void DlgWznmVerGenui::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmVerGenui";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmVerGenui";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "GuiTxtPrg", GuiTxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerGenui::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (GuiTxtPrg == comp->GuiTxtPrg) insert(items, GUITXTPRG);

	return(items);
};

set<uint> DlgWznmVerGenui::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, GUITXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerGenui::ContInfLfi
 ******************************************************************************/

DlgWznmVerGenui::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgWznmVerGenui::ContInfLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmVerGenuiLfi";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmVerGenuiLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerGenui::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmVerGenui::ContInfLfi::diff(
			const ContInfLfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerGenui::StatApp
 ******************************************************************************/

void DlgWznmVerGenui::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmVerGenui";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmVerGenui";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerGenui::StatShr
 ******************************************************************************/

DlgWznmVerGenui::StatShr::StatShr(
			const bool GuiButRunActive
			, const bool GuiButStoActive
			, const bool ButDneActive
		) :
			Block()
		{
	this->GuiButRunActive = GuiButRunActive;
	this->GuiButStoActive = GuiButStoActive;
	this->ButDneActive = ButDneActive;

	mask = {GUIBUTRUNACTIVE, GUIBUTSTOACTIVE, BUTDNEACTIVE};
};

void DlgWznmVerGenui::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmVerGenui";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmVerGenui";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "GuiButRunActive", GuiButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "GuiButStoActive", GuiButStoActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerGenui::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (GuiButRunActive == comp->GuiButRunActive) insert(items, GUIBUTRUNACTIVE);
	if (GuiButStoActive == comp->GuiButStoActive) insert(items, GUIBUTSTOACTIVE);
	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmVerGenui::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {GUIBUTRUNACTIVE, GUIBUTSTOACTIVE, BUTDNEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerGenui::StatShrLfi
 ******************************************************************************/

DlgWznmVerGenui::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

void DlgWznmVerGenui::StatShrLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmVerGenuiLfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmVerGenuiLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerGenui::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmVerGenui::StatShrLfi::diff(
			const StatShrLfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerGenui::Tag
 ******************************************************************************/

void DlgWznmVerGenui::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmVerGenui";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmVerGenui";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Generate user interface");
		};
		writeStringAttr(wr, itemtag, "sref", "GuiButRun", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::RUN, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "GuiButSto", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::STOP, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerGenui::TagGui
 ******************************************************************************/

void DlgWznmVerGenui::TagGui::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmVerGenuiGui";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmVerGenuiGui";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerGenui::TagLfi
 ******************************************************************************/

void DlgWznmVerGenui::TagLfi::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmVerGenuiLfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmVerGenuiLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DOWNLOAD, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerGenui::DpchAppData
 ******************************************************************************/

DlgWznmVerGenui::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERGENUIDATA)
		{
};

string DlgWznmVerGenui::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerGenui::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmVerGenuiData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class DlgWznmVerGenui::DpchAppDo
 ******************************************************************************/

DlgWznmVerGenui::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERGENUIDO)
		{
	ixVDo = 0;
};

string DlgWznmVerGenui::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerGenui::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmVerGenuiDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWznmVerGenui::DpchEngData
 ******************************************************************************/

DlgWznmVerGenui::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfLfi* continflfi
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrLfi* statshrlfi
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVERGENUIDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFLFI, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRLFI, TAG, TAGGUI, TAGLFI};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFLFI) && continflfi) this->continflfi = *continflfi;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRLFI) && statshrlfi) this->statshrlfi = *statshrlfi;
};

string DlgWznmVerGenui::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGGUI)) ss.push_back("taggui");
	if (has(TAGLFI)) ss.push_back("taglfi");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerGenui::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFLFI)) {continflfi = src->continflfi; add(CONTINFLFI);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRLFI)) {statshrlfi = src->statshrlfi; add(STATSHRLFI);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGGUI)) add(TAGGUI);
	if (src->has(TAGLFI)) add(TAGLFI);
};

void DlgWznmVerGenui::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmVerGenuiData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFLFI)) continflfi.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRLFI)) statshrlfi.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(TAGGUI)) TagGui::writeXML(ixWznmVLocale, wr);
		if (has(TAGLFI)) TagLfi::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
