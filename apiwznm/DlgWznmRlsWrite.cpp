/**
	* \file DlgWznmRlsWrite.cpp
	* API code for job DlgWznmRlsWrite (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmRlsWrite.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmRlsWrite::VecVDit
 ******************************************************************************/

uint DlgWznmRlsWrite::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "cuc") return CUC;
	if (s == "wrc") return WRC;
	if (s == "lfi") return LFI;
	if (s == "fia") return FIA;

	return(0);
};

string DlgWznmRlsWrite::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == CUC) return("Cuc");
	if (ix == WRC) return("Wrc");
	if (ix == LFI) return("Lfi");
	if (ix == FIA) return("Fia");

	return("");
};

/******************************************************************************
 class DlgWznmRlsWrite::VecVDo
 ******************************************************************************/

uint DlgWznmRlsWrite::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmRlsWrite::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsWrite::VecVDoWrc
 ******************************************************************************/

uint DlgWznmRlsWrite::VecVDoWrc::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butautclick") return BUTAUTCLICK;
	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmRlsWrite::VecVDoWrc::getSref(
			const uint ix
		) {
	if (ix == BUTAUTCLICK) return("ButAutClick");
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsWrite::VecVSge
 ******************************************************************************/

uint DlgWznmRlsWrite::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alraer") return ALRAER;
	if (s == "alrmer") return ALRMER;
	if (s == "upkidle") return UPKIDLE;
	if (s == "unpack") return UNPACK;
	if (s == "upkdone") return UPKDONE;
	if (s == "auth") return AUTH;
	if (s == "autdone") return AUTDONE;
	if (s == "creidle") return CREIDLE;
	if (s == "create") return CREATE;
	if (s == "write") return WRITE;
	if (s == "mrggnr") return MRGGNR;
	if (s == "mrgspec") return MRGSPEC;
	if (s == "mrgctp") return MRGCTP;
	if (s == "mrgcust") return MRGCUST;
	if (s == "pack") return PACK;
	if (s == "fail") return FAIL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmRlsWrite::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRAER) return("alraer");
	if (ix == ALRMER) return("alrmer");
	if (ix == UPKIDLE) return("upkidle");
	if (ix == UNPACK) return("unpack");
	if (ix == UPKDONE) return("upkdone");
	if (ix == AUTH) return("auth");
	if (ix == AUTDONE) return("autdone");
	if (ix == CREIDLE) return("creidle");
	if (ix == CREATE) return("create");
	if (ix == WRITE) return("write");
	if (ix == MRGGNR) return("mrggnr");
	if (ix == MRGSPEC) return("mrgspec");
	if (ix == MRGCTP) return("mrgctp");
	if (ix == MRGCUST) return("mrgcust");
	if (ix == PACK) return("pack");
	if (ix == FAIL) return("fail");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmRlsWrite::ContIac
 ******************************************************************************/

DlgWznmRlsWrite::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWznmRlsWrite::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmRlsWrite";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmRlsWrite::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmRlsWrite";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmRlsWrite";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmRlsWrite::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmRlsWrite::ContIac::diff(
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
 class DlgWznmRlsWrite::ContIacDet
 ******************************************************************************/

DlgWznmRlsWrite::ContIacDet::ContIacDet(
			const bool ChkBso
		) :
			Block()
		{
	this->ChkBso = ChkBso;

	mask = {CHKBSO};
};

bool DlgWznmRlsWrite::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmRlsWriteDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmRlsWriteDet";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkBso", ChkBso)) add(CHKBSO);
	};

	return basefound;
};

void DlgWznmRlsWrite::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmRlsWriteDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmRlsWriteDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ChkBso", ChkBso);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmRlsWrite::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (ChkBso == comp->ChkBso) insert(items, CHKBSO);

	return(items);
};

set<uint> DlgWznmRlsWrite::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CHKBSO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsWrite::ContInf
 ******************************************************************************/

DlgWznmRlsWrite::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWznmRlsWrite::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsWrite";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmRlsWrite::ContInf::diff(
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
 class DlgWznmRlsWrite::ContInfFia
 ******************************************************************************/

DlgWznmRlsWrite::ContInfFia::ContInfFia(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmRlsWrite::ContInfFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsWriteFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsWriteFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::ContInfFia::comm(
			const ContInfFia* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmRlsWrite::ContInfFia::diff(
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
 class DlgWznmRlsWrite::ContInfLfi
 ******************************************************************************/

DlgWznmRlsWrite::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmRlsWrite::ContInfLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsWriteLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsWriteLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmRlsWrite::ContInfLfi::diff(
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
 class DlgWznmRlsWrite::ContInfWrc
 ******************************************************************************/

DlgWznmRlsWrite::ContInfWrc::ContInfWrc(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgWznmRlsWrite::ContInfWrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsWriteWrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsWriteWrc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::ContInfWrc::comm(
			const ContInfWrc* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmRlsWrite::ContInfWrc::diff(
			const ContInfWrc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsWrite::StatApp
 ******************************************************************************/

DlgWznmRlsWrite::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
		{
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgWznmRlsWrite::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmRlsWrite";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmRlsWrite::StatApp::diff(
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
 class DlgWznmRlsWrite::StatShr
 ******************************************************************************/

DlgWznmRlsWrite::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgWznmRlsWrite::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsWrite";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmRlsWrite::StatShr::diff(
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
 class DlgWznmRlsWrite::StatShrCuc
 ******************************************************************************/

DlgWznmRlsWrite::StatShrCuc::StatShrCuc(
			const bool UldAvail
			, const bool UldActive
		) :
			Block()
		{
	this->UldAvail = UldAvail;
	this->UldActive = UldActive;

	mask = {ULDAVAIL, ULDACTIVE};
};

bool DlgWznmRlsWrite::StatShrCuc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsWriteCuc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsWriteCuc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldAvail", UldAvail)) add(ULDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::StatShrCuc::comm(
			const StatShrCuc* comp
		) {
	set<uint> items;

	if (UldAvail == comp->UldAvail) insert(items, ULDAVAIL);
	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWznmRlsWrite::StatShrCuc::diff(
			const StatShrCuc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDAVAIL, ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsWrite::StatShrFia
 ******************************************************************************/

DlgWznmRlsWrite::StatShrFia::StatShrFia(
			const bool DldAvail
			, const bool DldActive
		) :
			Block()
		{
	this->DldAvail = DldAvail;
	this->DldActive = DldActive;

	mask = {DLDAVAIL, DLDACTIVE};
};

bool DlgWznmRlsWrite::StatShrFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsWriteFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsWriteFia";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldAvail", DldAvail)) add(DLDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::StatShrFia::comm(
			const StatShrFia* comp
		) {
	set<uint> items;

	if (DldAvail == comp->DldAvail) insert(items, DLDAVAIL);
	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmRlsWrite::StatShrFia::diff(
			const StatShrFia* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDAVAIL, DLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsWrite::StatShrLfi
 ******************************************************************************/

DlgWznmRlsWrite::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgWznmRlsWrite::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsWriteLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsWriteLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmRlsWrite::StatShrLfi::diff(
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
 class DlgWznmRlsWrite::StatShrWrc
 ******************************************************************************/

DlgWznmRlsWrite::StatShrWrc::StatShrWrc(
			const bool ButAutActive
			, const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButAutActive = ButAutActive;
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTAUTACTIVE, BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWznmRlsWrite::StatShrWrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsWriteWrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsWriteWrc";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAutActive", ButAutActive)) add(BUTAUTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsWrite::StatShrWrc::comm(
			const StatShrWrc* comp
		) {
	set<uint> items;

	if (ButAutActive == comp->ButAutActive) insert(items, BUTAUTACTIVE);
	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmRlsWrite::StatShrWrc::diff(
			const StatShrWrc* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTAUTACTIVE, BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsWrite::Tag
 ******************************************************************************/

DlgWznmRlsWrite::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgWznmRlsWrite::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsWrite");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsWrite";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsWrite::TagCuc
 ******************************************************************************/

DlgWznmRlsWrite::TagCuc::TagCuc(
			const string& Uld
			, const string& Cpt
		) :
			Block()
		{
	this->Uld = Uld;
	this->Cpt = Cpt;

	mask = {ULD, CPT};
};

bool DlgWznmRlsWrite::TagCuc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsWriteCuc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsWriteCuc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsWrite::TagDet
 ******************************************************************************/

DlgWznmRlsWrite::TagDet::TagDet(
			const string& CptBso
		) :
			Block()
		{
	this->CptBso = CptBso;

	mask = {CPTBSO};
};

bool DlgWznmRlsWrite::TagDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsWriteDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsWriteDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBso", CptBso)) add(CPTBSO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsWrite::TagFia
 ******************************************************************************/

DlgWznmRlsWrite::TagFia::TagFia(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmRlsWrite::TagFia::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsWriteFia");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsWriteFia";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsWrite::TagLfi
 ******************************************************************************/

DlgWznmRlsWrite::TagLfi::TagLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmRlsWrite::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsWriteLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsWriteLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsWrite::TagWrc
 ******************************************************************************/

DlgWznmRlsWrite::TagWrc::TagWrc(
			const string& CptPrg
			, const string& ButAut
			, const string& ButRun
			, const string& ButSto
		) :
			Block()
		{
	this->CptPrg = CptPrg;
	this->ButAut = ButAut;
	this->ButRun = ButRun;
	this->ButSto = ButSto;

	mask = {CPTPRG, BUTAUT, BUTRUN, BUTSTO};
};

bool DlgWznmRlsWrite::TagWrc::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsWriteWrc");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsWriteWrc";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButAut", ButAut)) add(BUTAUT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsWrite::DpchAppData
 ******************************************************************************/

DlgWznmRlsWrite::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSWRITEDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACDET};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
};

string DlgWznmRlsWrite::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsWrite::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmRlsWriteData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsWrite::DpchAppDo
 ******************************************************************************/

DlgWznmRlsWrite::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoWrc
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSWRITEDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOWRC};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoWrc = ixVDoWrc;
};

string DlgWznmRlsWrite::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOWRC)) ss.push_back("ixVDoWrc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsWrite::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmRlsWriteDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOWRC)) writeString(wr, "srefIxVDoWrc", VecVDoWrc::getSref(ixVDoWrc));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsWrite::DpchEngData
 ******************************************************************************/

DlgWznmRlsWrite::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMRLSWRITEDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmRlsWrite::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFFIA)) ss.push_back("continffia");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(CONTINFWRC)) ss.push_back("continfwrc");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRCUC)) ss.push_back("statshrcuc");
	if (has(STATSHRFIA)) ss.push_back("statshrfia");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(STATSHRWRC)) ss.push_back("statshrwrc");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGCUC)) ss.push_back("tagcuc");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGFIA)) ss.push_back("tagfia");
	if (has(TAGLFI)) ss.push_back("taglfi");
	if (has(TAGWRC)) ss.push_back("tagwrc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsWrite::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmRlsWriteData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continffia.readXML(docctx, basexpath, true)) add(CONTINFFIA);
		if (continflfi.readXML(docctx, basexpath, true)) add(CONTINFLFI);
		if (continfwrc.readXML(docctx, basexpath, true)) add(CONTINFWRC);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrcuc.readXML(docctx, basexpath, true)) add(STATSHRCUC);
		if (statshrfia.readXML(docctx, basexpath, true)) add(STATSHRFIA);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (statshrwrc.readXML(docctx, basexpath, true)) add(STATSHRWRC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagcuc.readXML(docctx, basexpath, true)) add(TAGCUC);
		if (tagdet.readXML(docctx, basexpath, true)) add(TAGDET);
		if (tagfia.readXML(docctx, basexpath, true)) add(TAGFIA);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
		if (tagwrc.readXML(docctx, basexpath, true)) add(TAGWRC);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
		continf = ContInf();
		continffia = ContInfFia();
		continflfi = ContInfLfi();
		continfwrc = ContInfWrc();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrcuc = StatShrCuc();
		statshrfia = StatShrFia();
		statshrlfi = StatShrLfi();
		statshrwrc = StatShrWrc();
		tag = Tag();
		tagcuc = TagCuc();
		tagdet = TagDet();
		tagfia = TagFia();
		taglfi = TagLfi();
		tagwrc = TagWrc();
	};
};

