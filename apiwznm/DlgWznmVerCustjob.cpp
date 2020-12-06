/**
	* \file DlgWznmVerCustjob.cpp
	* API code for job DlgWznmVerCustjob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmVerCustjob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmVerCustjob::VecVDit
 ******************************************************************************/

uint DlgWznmVerCustjob::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ifi") return IFI;
	if (s == "imp") return IMP;
	if (s == "lfi") return LFI;

	return(0);
};

string DlgWznmVerCustjob::VecVDit::getSref(
			const uint ix
		) {
	if (ix == IFI) return("Ifi");
	if (ix == IMP) return("Imp");
	if (ix == LFI) return("Lfi");

	return("");
};

/******************************************************************************
 class DlgWznmVerCustjob::VecVDo
 ******************************************************************************/

uint DlgWznmVerCustjob::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmVerCustjob::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmVerCustjob::VecVDoImp
 ******************************************************************************/

uint DlgWznmVerCustjob::VecVDoImp::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmVerCustjob::VecVDoImp::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmVerCustjob::VecVSge
 ******************************************************************************/

uint DlgWznmVerCustjob::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "prsidle") return PRSIDLE;
	if (s == "parse") return PARSE;
	if (s == "alrwznmper") return ALRWZNMPER;
	if (s == "prsdone") return PRSDONE;
	if (s == "impidle") return IMPIDLE;
	if (s == "import") return IMPORT;
	if (s == "alrwznmier") return ALRWZNMIER;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmVerCustjob::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == PRSIDLE) return("prsidle");
	if (ix == PARSE) return("parse");
	if (ix == ALRWZNMPER) return("alrwznmper");
	if (ix == PRSDONE) return("prsdone");
	if (ix == IMPIDLE) return("impidle");
	if (ix == IMPORT) return("import");
	if (ix == ALRWZNMIER) return("alrwznmier");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmVerCustjob::ContIac
 ******************************************************************************/

DlgWznmVerCustjob::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWznmVerCustjob::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmVerCustjob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmVerCustjob";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmVerCustjob::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmVerCustjob";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmVerCustjob";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmVerCustjob::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmVerCustjob::ContIac::diff(
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
 class DlgWznmVerCustjob::ContInf
 ******************************************************************************/

DlgWznmVerCustjob::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWznmVerCustjob::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVerCustjob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVerCustjob";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmVerCustjob::ContInf::diff(
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
 class DlgWznmVerCustjob::ContInfImp
 ******************************************************************************/

DlgWznmVerCustjob::ContInfImp::ContInfImp(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgWznmVerCustjob::ContInfImp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVerCustjobImp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVerCustjobImp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::ContInfImp::comm(
			const ContInfImp* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmVerCustjob::ContInfImp::diff(
			const ContInfImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerCustjob::ContInfLfi
 ******************************************************************************/

DlgWznmVerCustjob::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmVerCustjob::ContInfLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmVerCustjobLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmVerCustjobLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmVerCustjob::ContInfLfi::diff(
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
 class DlgWznmVerCustjob::StatApp
 ******************************************************************************/

DlgWznmVerCustjob::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
		{
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgWznmVerCustjob::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmVerCustjob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmVerCustjob";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmVerCustjob::StatApp::diff(
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
 class DlgWznmVerCustjob::StatShr
 ******************************************************************************/

DlgWznmVerCustjob::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgWznmVerCustjob::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVerCustjob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVerCustjob";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmVerCustjob::StatShr::diff(
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
 class DlgWznmVerCustjob::StatShrIfi
 ******************************************************************************/

DlgWznmVerCustjob::StatShrIfi::StatShrIfi(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgWznmVerCustjob::StatShrIfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVerCustjobIfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVerCustjobIfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::StatShrIfi::comm(
			const StatShrIfi* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWznmVerCustjob::StatShrIfi::diff(
			const StatShrIfi* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerCustjob::StatShrImp
 ******************************************************************************/

DlgWznmVerCustjob::StatShrImp::StatShrImp(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWznmVerCustjob::StatShrImp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVerCustjobImp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVerCustjobImp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::StatShrImp::comm(
			const StatShrImp* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmVerCustjob::StatShrImp::diff(
			const StatShrImp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmVerCustjob::StatShrLfi
 ******************************************************************************/

DlgWznmVerCustjob::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgWznmVerCustjob::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmVerCustjobLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmVerCustjobLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmVerCustjob::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmVerCustjob::StatShrLfi::diff(
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
 class DlgWznmVerCustjob::Tag
 ******************************************************************************/

DlgWznmVerCustjob::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgWznmVerCustjob::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVerCustjob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVerCustjob";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVerCustjob::TagIfi
 ******************************************************************************/

DlgWznmVerCustjob::TagIfi::TagIfi(
			const string& Uld
			, const string& Cpt
		) :
			Block()
		{
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgWznmVerCustjob::TagIfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVerCustjobIfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVerCustjobIfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVerCustjob::TagImp
 ******************************************************************************/

DlgWznmVerCustjob::TagImp::TagImp(
			const string& CptPrg
			, const string& ButRun
			, const string& ButSto
		) :
			Block()
		{
	this->CptPrg = CptPrg;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTRUN, BUTSTO};
};

bool DlgWznmVerCustjob::TagImp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVerCustjobImp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVerCustjobImp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVerCustjob::TagLfi
 ******************************************************************************/

DlgWznmVerCustjob::TagLfi::TagLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmVerCustjob::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmVerCustjobLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmVerCustjobLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmVerCustjob::DpchAppData
 ******************************************************************************/

DlgWznmVerCustjob::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJOBDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmVerCustjob::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerCustjob::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVerCustjobData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerCustjob::DpchAppDo
 ******************************************************************************/

DlgWznmVerCustjob::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoImp
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJOBDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOIMP};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoImp = ixVDoImp;
};

string DlgWznmVerCustjob::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOIMP)) ss.push_back("ixVDoImp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerCustjob::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmVerCustjobDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOIMP)) writeString(wr, "srefIxVDoImp", VecVDoImp::getSref(ixVDoImp));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmVerCustjob::DpchEngData
 ******************************************************************************/

DlgWznmVerCustjob::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMVERCUSTJOBDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmVerCustjob::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFIMP)) ss.push_back("continfimp");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRIFI)) ss.push_back("statshrifi");
	if (has(STATSHRIMP)) ss.push_back("statshrimp");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGIFI)) ss.push_back("tagifi");
	if (has(TAGIMP)) ss.push_back("tagimp");
	if (has(TAGLFI)) ss.push_back("taglfi");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmVerCustjob::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmVerCustjobData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfimp.readXML(docctx, basexpath, true)) add(CONTINFIMP);
		if (continflfi.readXML(docctx, basexpath, true)) add(CONTINFLFI);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrifi.readXML(docctx, basexpath, true)) add(STATSHRIFI);
		if (statshrimp.readXML(docctx, basexpath, true)) add(STATSHRIMP);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagifi.readXML(docctx, basexpath, true)) add(TAGIFI);
		if (tagimp.readXML(docctx, basexpath, true)) add(TAGIMP);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continfimp = ContInfImp();
		continflfi = ContInfLfi();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrifi = StatShrIfi();
		statshrimp = StatShrImp();
		statshrlfi = StatShrLfi();
		tag = Tag();
		tagifi = TagIfi();
		tagimp = TagImp();
		taglfi = TagLfi();
	};
};
