/**
	* \file DlgWznmRlsStareptr.cpp
	* API code for job DlgWznmRlsStareptr (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "DlgWznmRlsStareptr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmRlsStareptr::VecVDit
 ******************************************************************************/

uint DlgWznmRlsStareptr::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "ini") return INI;
	if (s == "ext") return EXT;
	if (s == "lfi") return LFI;

	return(0);
};

string DlgWznmRlsStareptr::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == INI) return("Ini");
	if (ix == EXT) return("Ext");
	if (ix == LFI) return("Lfi");

	return("");
};

/******************************************************************************
 class DlgWznmRlsStareptr::VecVDo
 ******************************************************************************/

uint DlgWznmRlsStareptr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmRlsStareptr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsStareptr::VecVDoDet
 ******************************************************************************/

uint DlgWznmRlsStareptr::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butstaclick") return BUTSTACLICK;

	return(0);
};

string DlgWznmRlsStareptr::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTSTACLICK) return("ButStaClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsStareptr::VecVDoExt
 ******************************************************************************/

uint DlgWznmRlsStareptr::VecVDoExt::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmRlsStareptr::VecVDoExt::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsStareptr::VecVDoIni
 ******************************************************************************/

uint DlgWznmRlsStareptr::VecVDoIni::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butclgclick") return BUTCLGCLICK;

	return(0);
};

string DlgWznmRlsStareptr::VecVDoIni::getSref(
			const uint ix
		) {
	if (ix == BUTCLGCLICK) return("ButClgClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsStareptr::VecVSge
 ******************************************************************************/

uint DlgWznmRlsStareptr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrgnf") return ALRGNF;
	if (s == "alrgad") return ALRGAD;
	if (s == "alrgve") return ALRGVE;
	if (s == "alrxer") return ALRXER;
	if (s == "stadone") return STADONE;
	if (s == "upkidle") return UPKIDLE;
	if (s == "unpack") return UNPACK;
	if (s == "upkdone") return UPKDONE;
	if (s == "clgidle") return CLGIDLE;
	if (s == "clonegit") return CLONEGIT;
	if (s == "clgdone") return CLGDONE;
	if (s == "extract") return EXTRACT;
	if (s == "pack") return PACK;
	if (s == "fail") return FAIL;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmRlsStareptr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRGNF) return("alrgnf");
	if (ix == ALRGAD) return("alrgad");
	if (ix == ALRGVE) return("alrgve");
	if (ix == ALRXER) return("alrxer");
	if (ix == STADONE) return("stadone");
	if (ix == UPKIDLE) return("upkidle");
	if (ix == UNPACK) return("unpack");
	if (ix == UPKDONE) return("upkdone");
	if (ix == CLGIDLE) return("clgidle");
	if (ix == CLONEGIT) return("clonegit");
	if (ix == CLGDONE) return("clgdone");
	if (ix == EXTRACT) return("extract");
	if (ix == PACK) return("pack");
	if (ix == FAIL) return("fail");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmRlsStareptr::ContIac
 ******************************************************************************/

DlgWznmRlsStareptr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWznmRlsStareptr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmRlsStareptr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmRlsStareptr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmRlsStareptr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmRlsStareptr::ContIac::diff(
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
 class DlgWznmRlsStareptr::ContIacDet
 ******************************************************************************/

DlgWznmRlsStareptr::ContIacDet::ContIacDet(
			const uint numFRbuBrt
			, const string& TxfGrl
		) :
			Block()
		{
	this->numFRbuBrt = numFRbuBrt;
	this->TxfGrl = TxfGrl;

	mask = {NUMFRBUBRT, TXFGRL};
};

bool DlgWznmRlsStareptr::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmRlsStareptrDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmRlsStareptrDet";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFRbuBrt", numFRbuBrt)) add(NUMFRBUBRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfGrl", TxfGrl)) add(TXFGRL);
	};

	return basefound;
};

void DlgWznmRlsStareptr::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmRlsStareptrDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmRlsStareptrDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFRbuBrt", numFRbuBrt);
		writeStringAttr(wr, itemtag, "sref", "TxfGrl", TxfGrl);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmRlsStareptr::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (numFRbuBrt == comp->numFRbuBrt) insert(items, NUMFRBUBRT);
	if (TxfGrl == comp->TxfGrl) insert(items, TXFGRL);

	return(items);
};

set<uint> DlgWznmRlsStareptr::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFRBUBRT, TXFGRL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsStareptr::ContInf
 ******************************************************************************/

DlgWznmRlsStareptr::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

bool DlgWznmRlsStareptr::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsStareptr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmRlsStareptr::ContInf::diff(
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
 class DlgWznmRlsStareptr::ContInfExt
 ******************************************************************************/

DlgWznmRlsStareptr::ContInfExt::ContInfExt(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgWznmRlsStareptr::ContInfExt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsStareptrExt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsStareptrExt";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::ContInfExt::comm(
			const ContInfExt* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmRlsStareptr::ContInfExt::diff(
			const ContInfExt* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsStareptr::ContInfIni
 ******************************************************************************/

DlgWznmRlsStareptr::ContInfIni::ContInfIni(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

bool DlgWznmRlsStareptr::ContInfIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsStareptrIni");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsStareptrIni";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::ContInfIni::comm(
			const ContInfIni* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmRlsStareptr::ContInfIni::diff(
			const ContInfIni* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsStareptr::ContInfLfi
 ******************************************************************************/

DlgWznmRlsStareptr::ContInfLfi::ContInfLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmRlsStareptr::ContInfLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsStareptrLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsStareptrLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::ContInfLfi::comm(
			const ContInfLfi* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmRlsStareptr::ContInfLfi::diff(
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
 class DlgWznmRlsStareptr::StatApp
 ******************************************************************************/

DlgWznmRlsStareptr::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
		{
	this->initdone = initdone;
	this->shortMenu = shortMenu;

	mask = {INITDONE, SHORTMENU};
};

bool DlgWznmRlsStareptr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmRlsStareptr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmRlsStareptr::StatApp::diff(
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
 class DlgWznmRlsStareptr::StatShr
 ******************************************************************************/

DlgWznmRlsStareptr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

bool DlgWznmRlsStareptr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsStareptr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmRlsStareptr::StatShr::diff(
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
 class DlgWznmRlsStareptr::StatShrDet
 ******************************************************************************/

DlgWznmRlsStareptr::StatShrDet::StatShrDet(
			const bool TxfGrlAvail
			, const bool ButStaActive
		) :
			Block()
		{
	this->TxfGrlAvail = TxfGrlAvail;
	this->ButStaActive = ButStaActive;

	mask = {TXFGRLAVAIL, BUTSTAACTIVE};
};

bool DlgWznmRlsStareptr::StatShrDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsStareptrDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsStareptrDet";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfGrlAvail", TxfGrlAvail)) add(TXFGRLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStaActive", ButStaActive)) add(BUTSTAACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (TxfGrlAvail == comp->TxfGrlAvail) insert(items, TXFGRLAVAIL);
	if (ButStaActive == comp->ButStaActive) insert(items, BUTSTAACTIVE);

	return(items);
};

set<uint> DlgWznmRlsStareptr::StatShrDet::diff(
			const StatShrDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFGRLAVAIL, BUTSTAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsStareptr::StatShrExt
 ******************************************************************************/

DlgWznmRlsStareptr::StatShrExt::StatShrExt(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWznmRlsStareptr::StatShrExt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsStareptrExt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsStareptrExt";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::StatShrExt::comm(
			const StatShrExt* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmRlsStareptr::StatShrExt::diff(
			const StatShrExt* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsStareptr::StatShrIni
 ******************************************************************************/

DlgWznmRlsStareptr::StatShrIni::StatShrIni(
			const bool UldAvail
			, const bool UldActive
			, const bool TxtPrgAvail
			, const bool Sep1Avail
			, const bool ButClgAvail
			, const bool ButClgActive
		) :
			Block()
		{
	this->UldAvail = UldAvail;
	this->UldActive = UldActive;
	this->TxtPrgAvail = TxtPrgAvail;
	this->Sep1Avail = Sep1Avail;
	this->ButClgAvail = ButClgAvail;
	this->ButClgActive = ButClgActive;

	mask = {ULDAVAIL, ULDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTCLGAVAIL, BUTCLGACTIVE};
};

bool DlgWznmRlsStareptr::StatShrIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsStareptrIni");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsStareptrIni";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldAvail", UldAvail)) add(ULDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "UldActive", UldActive)) add(ULDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrgAvail", TxtPrgAvail)) add(TXTPRGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Sep1Avail", Sep1Avail)) add(SEP1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClgAvail", ButClgAvail)) add(BUTCLGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButClgActive", ButClgActive)) add(BUTCLGACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::StatShrIni::comm(
			const StatShrIni* comp
		) {
	set<uint> items;

	if (UldAvail == comp->UldAvail) insert(items, ULDAVAIL);
	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);
	if (TxtPrgAvail == comp->TxtPrgAvail) insert(items, TXTPRGAVAIL);
	if (Sep1Avail == comp->Sep1Avail) insert(items, SEP1AVAIL);
	if (ButClgAvail == comp->ButClgAvail) insert(items, BUTCLGAVAIL);
	if (ButClgActive == comp->ButClgActive) insert(items, BUTCLGACTIVE);

	return(items);
};

set<uint> DlgWznmRlsStareptr::StatShrIni::diff(
			const StatShrIni* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDAVAIL, ULDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTCLGAVAIL, BUTCLGACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsStareptr::StatShrLfi
 ******************************************************************************/

DlgWznmRlsStareptr::StatShrLfi::StatShrLfi(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

bool DlgWznmRlsStareptr::StatShrLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsStareptrLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsStareptrLfi";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsStareptr::StatShrLfi::comm(
			const StatShrLfi* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmRlsStareptr::StatShrLfi::diff(
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
 class DlgWznmRlsStareptr::Tag
 ******************************************************************************/

DlgWznmRlsStareptr::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->ButDne = ButDne;

	mask = {CPT, BUTDNE};
};

bool DlgWznmRlsStareptr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsStareptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsStareptr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagDet
 ******************************************************************************/

DlgWznmRlsStareptr::TagDet::TagDet(
			const string& CptBrt
			, const string& CptGrl
			, const string& ButSta
		) :
			Block()
		{
	this->CptBrt = CptBrt;
	this->CptGrl = CptGrl;
	this->ButSta = ButSta;

	mask = {CPTBRT, CPTGRL, BUTSTA};
};

bool DlgWznmRlsStareptr::TagDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsStareptrDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsStareptrDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBrt", CptBrt)) add(CPTBRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptGrl", CptGrl)) add(CPTGRL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSta", ButSta)) add(BUTSTA);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagExt
 ******************************************************************************/

DlgWznmRlsStareptr::TagExt::TagExt(
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

bool DlgWznmRlsStareptr::TagExt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsStareptrExt");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsStareptrExt";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagIni
 ******************************************************************************/

DlgWznmRlsStareptr::TagIni::TagIni(
			const string& Uld
			, const string& Cpt
			, const string& CptPrg
			, const string& ButClg
		) :
			Block()
		{
	this->Uld = Uld;
	this->Cpt = Cpt;
	this->CptPrg = CptPrg;
	this->ButClg = ButClg;

	mask = {ULD, CPT, CPTPRG, BUTCLG};
};

bool DlgWznmRlsStareptr::TagIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsStareptrIni");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsStareptrIni";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Uld", Uld)) add(ULD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButClg", ButClg)) add(BUTCLG);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagLfi
 ******************************************************************************/

DlgWznmRlsStareptr::TagLfi::TagLfi(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

bool DlgWznmRlsStareptr::TagLfi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsStareptrLfi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsStareptrLfi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsStareptr::DpchAppData
 ******************************************************************************/

DlgWznmRlsStareptr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC, CONTIACDET};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
		if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
};

string DlgWznmRlsStareptr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsStareptr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmRlsStareptrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsStareptr::DpchAppDo
 ******************************************************************************/

DlgWznmRlsStareptr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoDet
			, const uint ixVDoExt
			, const uint ixVDoIni
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDODET, IXVDOEXT, IXVDOINI};
	else this->mask = mask;

	this->ixVDo = ixVDo;
	this->ixVDoDet = ixVDoDet;
	this->ixVDoExt = ixVDoExt;
	this->ixVDoIni = ixVDoIni;
};

string DlgWznmRlsStareptr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");
	if (has(IXVDOEXT)) ss.push_back("ixVDoExt");
	if (has(IXVDOINI)) ss.push_back("ixVDoIni");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsStareptr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmRlsStareptrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDODET)) writeString(wr, "srefIxVDoDet", VecVDoDet::getSref(ixVDoDet));
		if (has(IXVDOEXT)) writeString(wr, "srefIxVDoExt", VecVDoExt::getSref(ixVDoExt));
		if (has(IXVDOINI)) writeString(wr, "srefIxVDoIni", VecVDoIni::getSref(ixVDoIni));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsStareptr::DpchEngData
 ******************************************************************************/

DlgWznmRlsStareptr::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMRLSSTAREPTRDATA)
		{
	feedFDetRbuBrt.tag = "FeedFDetRbuBrt";
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmRlsStareptr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFEXT)) ss.push_back("continfext");
	if (has(CONTINFINI)) ss.push_back("continfini");
	if (has(CONTINFLFI)) ss.push_back("continflfi");
	if (has(FEEDFDETRBUBRT)) ss.push_back("feedFDetRbuBrt");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(STATSHREXT)) ss.push_back("statshrext");
	if (has(STATSHRINI)) ss.push_back("statshrini");
	if (has(STATSHRLFI)) ss.push_back("statshrlfi");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGEXT)) ss.push_back("tagext");
	if (has(TAGINI)) ss.push_back("tagini");
	if (has(TAGLFI)) ss.push_back("taglfi");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsStareptr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmRlsStareptrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continfext.readXML(docctx, basexpath, true)) add(CONTINFEXT);
		if (continfini.readXML(docctx, basexpath, true)) add(CONTINFINI);
		if (continflfi.readXML(docctx, basexpath, true)) add(CONTINFLFI);
		if (feedFDetRbuBrt.readXML(docctx, basexpath, true)) add(FEEDFDETRBUBRT);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrdet.readXML(docctx, basexpath, true)) add(STATSHRDET);
		if (statshrext.readXML(docctx, basexpath, true)) add(STATSHREXT);
		if (statshrini.readXML(docctx, basexpath, true)) add(STATSHRINI);
		if (statshrlfi.readXML(docctx, basexpath, true)) add(STATSHRLFI);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagdet.readXML(docctx, basexpath, true)) add(TAGDET);
		if (tagext.readXML(docctx, basexpath, true)) add(TAGEXT);
		if (tagini.readXML(docctx, basexpath, true)) add(TAGINI);
		if (taglfi.readXML(docctx, basexpath, true)) add(TAGLFI);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
		continf = ContInf();
		continfext = ContInfExt();
		continfini = ContInfIni();
		continflfi = ContInfLfi();
		feedFDetRbuBrt.clear();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrdet = StatShrDet();
		statshrext = StatShrExt();
		statshrini = StatShrIni();
		statshrlfi = StatShrLfi();
		tag = Tag();
		tagdet = TagDet();
		tagext = TagExt();
		tagini = TagIni();
		taglfi = TagLfi();
	};
};

