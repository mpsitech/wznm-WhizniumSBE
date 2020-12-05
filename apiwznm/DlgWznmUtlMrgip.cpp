/**
	* \file DlgWznmUtlMrgip.cpp
	* API code for job DlgWznmUtlMrgip (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmUtlMrgip.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmUtlMrgip::VecVDit
 ******************************************************************************/

uint DlgWznmUtlMrgip::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "src") return SRC;
	if (s == "trg") return TRG;
	if (s == "mrg") return MRG;
	if (s == "lfi") return LFI;
	if (s == "res") return RES;

	return(0);
};

string DlgWznmUtlMrgip::VecVDit::getSref(
			const uint ix
		) {
	if (ix == SRC) return("Src");
	if (ix == TRG) return("Trg");
	if (ix == MRG) return("Mrg");
	if (ix == LFI) return("Lfi");
	if (ix == RES) return("Res");

	return("");
};

/******************************************************************************
 class DlgWznmUtlMrgip::VecVDo
 ******************************************************************************/

uint DlgWznmUtlMrgip::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmUtlMrgip::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmUtlMrgip::VecVDoMrg
 ******************************************************************************/

uint DlgWznmUtlMrgip::VecVDoMrg::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmUtlMrgip::VecVDoMrg::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmUtlMrgip::VecVSge
 ******************************************************************************/

uint DlgWznmUtlMrgip::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrmer") return ALRMER;
	if (s == "supidle") return SUPIDLE;
	if (s == "srcunpack") return SRCUNPACK;
	if (s == "supdone") return SUPDONE;
	if (s == "suldone") return SULDONE;
	if (s == "tupidle") return TUPIDLE;
	if (s == "trgunpack") return TRGUNPACK;
	if (s == "tupdone") return TUPDONE;
	if (s == "tuldone") return TULDONE;
	if (s == "merge") return MERGE;
	if (s == "pack") return PACK;
	if (s == "fail") return FAIL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmUtlMrgip::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRMER) return("alrmer");
	if (ix == SUPIDLE) return("supidle");
	if (ix == SRCUNPACK) return("srcunpack");
	if (ix == SUPDONE) return("supdone");
	if (ix == SULDONE) return("suldone");
	if (ix == TUPIDLE) return("tupidle");
	if (ix == TRGUNPACK) return("trgunpack");
	if (ix == TUPDONE) return("tupdone");
	if (ix == TULDONE) return("tuldone");
	if (ix == MERGE) return("merge");
	if (ix == PACK) return("pack");
	if (ix == FAIL) return("fail");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmUtlMrgip::ContIac
 ******************************************************************************/

DlgWznmUtlMrgip::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWznmUtlMrgip::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmUtlMrgip";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmUtlMrgip::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmUtlMrgip";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmUtlMrgip";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlMrgip::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::ContIac::diff(
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
 class DlgWznmUtlMrgip::ContInf
 ******************************************************************************/

DlgWznmUtlMrgip::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWznmUtlMrgip::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmUtlMrgip";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::ContInf::diff(
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
 class DlgWznmUtlMrgip::ContInfLfi
 ******************************************************************************/

DlgWznmUtlMrgip::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmUtlMrgip::ContInfLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmUtlMrgipLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmUtlMrgipLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmUtlMrgip::ContInfLfi::diff(
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
 class DlgWznmUtlMrgip::ContInfMrg
 ******************************************************************************/

DlgWznmUtlMrgip::ContInfMrg::ContInfMrg(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgWznmUtlMrgip::ContInfMrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmUtlMrgipMrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmUtlMrgipMrg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::ContInfMrg::comm(
			const ContInfMrg* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmUtlMrgip::ContInfMrg::diff(
			const ContInfMrg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlMrgip::ContInfRes
 ******************************************************************************/

DlgWznmUtlMrgip::ContInfRes::ContInfRes(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmUtlMrgip::ContInfRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmUtlMrgipRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmUtlMrgipRes";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::ContInfRes::comm(
			const ContInfRes* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmUtlMrgip::ContInfRes::diff(
			const ContInfRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlMrgip::StatApp
 ******************************************************************************/

DlgWznmUtlMrgip::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
		{
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgWznmUtlMrgip::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmUtlMrgip";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmUtlMrgip::StatApp::diff(
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
 class DlgWznmUtlMrgip::StatShr
 ******************************************************************************/

DlgWznmUtlMrgip::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgWznmUtlMrgip::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmUtlMrgip";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::StatShr::diff(
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
 class DlgWznmUtlMrgip::StatShrLfi
 ******************************************************************************/

DlgWznmUtlMrgip::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgWznmUtlMrgip::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmUtlMrgipLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmUtlMrgipLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::StatShrLfi::diff(
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
 class DlgWznmUtlMrgip::StatShrMrg
 ******************************************************************************/

DlgWznmUtlMrgip::StatShrMrg::StatShrMrg(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWznmUtlMrgip::StatShrMrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmUtlMrgipMrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmUtlMrgipMrg";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::StatShrMrg::comm(
			const StatShrMrg* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::StatShrMrg::diff(
			const StatShrMrg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlMrgip::StatShrRes
 ******************************************************************************/

DlgWznmUtlMrgip::StatShrRes::StatShrRes(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgWznmUtlMrgip::StatShrRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmUtlMrgipRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmUtlMrgipRes";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::StatShrRes::comm(
			const StatShrRes* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::StatShrRes::diff(
			const StatShrRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlMrgip::StatShrSrc
 ******************************************************************************/

DlgWznmUtlMrgip::StatShrSrc::StatShrSrc(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgWznmUtlMrgip::StatShrSrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmUtlMrgipSrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmUtlMrgipSrc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::StatShrSrc::comm(
			const StatShrSrc* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::StatShrSrc::diff(
			const StatShrSrc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlMrgip::StatShrTrg
 ******************************************************************************/

DlgWznmUtlMrgip::StatShrTrg::StatShrTrg(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

bool DlgWznmUtlMrgip::StatShrTrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmUtlMrgipTrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmUtlMrgipTrg";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmUtlMrgip::StatShrTrg::comm(
			const StatShrTrg* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWznmUtlMrgip::StatShrTrg::diff(
			const StatShrTrg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlMrgip::Tag
 ******************************************************************************/

DlgWznmUtlMrgip::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgWznmUtlMrgip::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmUtlMrgip");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmUtlMrgip";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagLfi
 ******************************************************************************/

DlgWznmUtlMrgip::TagLfi::TagLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmUtlMrgip::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmUtlMrgipLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmUtlMrgipLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagMrg
 ******************************************************************************/

DlgWznmUtlMrgip::TagMrg::TagMrg(
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

bool DlgWznmUtlMrgip::TagMrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmUtlMrgipMrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmUtlMrgipMrg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagRes
 ******************************************************************************/

DlgWznmUtlMrgip::TagRes::TagRes(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmUtlMrgip::TagRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmUtlMrgipRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmUtlMrgipRes";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagSrc
 ******************************************************************************/

DlgWznmUtlMrgip::TagSrc::TagSrc(
			const string& Uld
			, const string& Cpt
		) :
			Block()
		{
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgWznmUtlMrgip::TagSrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmUtlMrgipSrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmUtlMrgipSrc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagTrg
 ******************************************************************************/

DlgWznmUtlMrgip::TagTrg::TagTrg(
			const string& Uld
			, const string& Cpt
		) :
			Block()
		{
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgWznmUtlMrgip::TagTrg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmUtlMrgipTrg");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmUtlMrgipTrg";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmUtlMrgip::DpchAppData
 ******************************************************************************/

DlgWznmUtlMrgip::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmUtlMrgip::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlMrgip::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmUtlMrgipData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::DpchAppDo
 ******************************************************************************/

DlgWznmUtlMrgip::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoMrg
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOMRG};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoMrg = ixVDoMrg;
};

string DlgWznmUtlMrgip::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOMRG)) ss.push_back("ixVDoMrg");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlMrgip::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmUtlMrgipDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOMRG)) writeString(wr, "srefIxVDoMrg", VecVDoMrg::getSref(ixVDoMrg));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::DpchEngData
 ******************************************************************************/

DlgWznmUtlMrgip::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMUTLMRGIPDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmUtlMrgip::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(CONTINFMRG)) ss.push_back("continfmrg");
	if (has(CONTINFRES)) ss.push_back("continfres");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(STATSHRMRG)) ss.push_back("statshrmrg");
	if (has(STATSHRRES)) ss.push_back("statshrres");
	if (has(STATSHRSRC)) ss.push_back("statshrsrc");
	if (has(STATSHRTRG)) ss.push_back("statshrtrg");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGLFI)) ss.push_back("taglfi");
	if (has(TAGMRG)) ss.push_back("tagmrg");
	if (has(TAGRES)) ss.push_back("tagres");
	if (has(TAGSRC)) ss.push_back("tagsrc");
	if (has(TAGTRG)) ss.push_back("tagtrg");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlMrgip::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmUtlMrgipData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continflfi.readXML(docctx, basexpath, true)) add(CONTINFLFI);
		if (continfmrg.readXML(docctx, basexpath, true)) add(CONTINFMRG);
		if (continfres.readXML(docctx, basexpath, true)) add(CONTINFRES);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (statshrmrg.readXML(docctx, basexpath, true)) add(STATSHRMRG);
		if (statshrres.readXML(docctx, basexpath, true)) add(STATSHRRES);
		if (statshrsrc.readXML(docctx, basexpath, true)) add(STATSHRSRC);
		if (statshrtrg.readXML(docctx, basexpath, true)) add(STATSHRTRG);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
		if (tagmrg.readXML(docctx, basexpath, true)) add(TAGMRG);
		if (tagres.readXML(docctx, basexpath, true)) add(TAGRES);
		if (tagsrc.readXML(docctx, basexpath, true)) add(TAGSRC);
		if (tagtrg.readXML(docctx, basexpath, true)) add(TAGTRG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continflfi = ContInfLfi();
		continfmrg = ContInfMrg();
		continfres = ContInfRes();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrlfi = StatShrLfi();
		statshrmrg = StatShrMrg();
		statshrres = StatShrRes();
		statshrsrc = StatShrSrc();
		statshrtrg = StatShrTrg();
		tag = Tag();
		taglfi = TagLfi();
		tagmrg = TagMrg();
		tagres = TagRes();
		tagsrc = TagSrc();
		tagtrg = TagTrg();
	};
};

