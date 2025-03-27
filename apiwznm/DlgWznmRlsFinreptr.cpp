/**
	* \file DlgWznmRlsFinreptr.cpp
	* API code for job DlgWznmRlsFinreptr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "DlgWznmRlsFinreptr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmRlsFinreptr::VecVDit
 ******************************************************************************/

uint DlgWznmRlsFinreptr::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "fin") return FIN;
	if (s == "res") return RES;

	return(0);
};

string DlgWznmRlsFinreptr::VecVDit::getSref(
			const uint ix
		) {
	if (ix == FIN) return("Fin");
	if (ix == RES) return("Res");

	return("");
};

/******************************************************************************
 class DlgWznmRlsFinreptr::VecVDo
 ******************************************************************************/

uint DlgWznmRlsFinreptr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmRlsFinreptr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsFinreptr::VecVDoFin
 ******************************************************************************/

uint DlgWznmRlsFinreptr::VecVDoFin::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmRlsFinreptr::VecVDoFin::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsFinreptr::VecVDoRes
 ******************************************************************************/

uint DlgWznmRlsFinreptr::VecVDoRes::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butpsgclick") return BUTPSGCLICK;

	return(0);
};

string DlgWznmRlsFinreptr::VecVDoRes::getSref(
			const uint ix
		) {
	if (ix == BUTPSGCLICK) return("ButPsgClick");

	return("");
};

/******************************************************************************
 class DlgWznmRlsFinreptr::VecVSge
 ******************************************************************************/

uint DlgWznmRlsFinreptr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrgnf") return ALRGNF;
	if (s == "alrgad") return ALRGAD;
	if (s == "finidle") return FINIDLE;
	if (s == "pack") return PACK;
	if (s == "commit") return COMMIT;
	if (s == "findone") return FINDONE;
	if (s == "psgidle") return PSGIDLE;
	if (s == "pushgit") return PUSHGIT;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmRlsFinreptr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRGNF) return("alrgnf");
	if (ix == ALRGAD) return("alrgad");
	if (ix == FINIDLE) return("finidle");
	if (ix == PACK) return("pack");
	if (ix == COMMIT) return("commit");
	if (ix == FINDONE) return("findone");
	if (ix == PSGIDLE) return("psgidle");
	if (ix == PUSHGIT) return("pushgit");
	if (ix == DONE) return("done");

	return("");
};

/******************************************************************************
 class DlgWznmRlsFinreptr::ContIac
 ******************************************************************************/

DlgWznmRlsFinreptr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
			, numFDse(numFDse)
		{
	mask = {NUMFDSE};
};

bool DlgWznmRlsFinreptr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmRlsFinreptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmRlsFinreptr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmRlsFinreptr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmRlsFinreptr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::ContIac::diff(
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
 class DlgWznmRlsFinreptr::ContInf
 ******************************************************************************/

DlgWznmRlsFinreptr::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
			, numFSge(numFSge)
		{
	mask = {NUMFSGE};
};

bool DlgWznmRlsFinreptr::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsFinreptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsFinreptr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
	};

	return basefound;
};

set<uint> DlgWznmRlsFinreptr::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::ContInf::diff(
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
 class DlgWznmRlsFinreptr::ContInfFin
 ******************************************************************************/

DlgWznmRlsFinreptr::ContInfFin::ContInfFin(
			const string& TxtPrg
		) :
			Block()
			, TxtPrg(TxtPrg)
		{
	mask = {TXTPRG};
};

bool DlgWznmRlsFinreptr::ContInfFin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsFinreptrFin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsFinreptrFin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmRlsFinreptr::ContInfFin::comm(
			const ContInfFin* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::ContInfFin::diff(
			const ContInfFin* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::ContInfRes
 ******************************************************************************/

DlgWznmRlsFinreptr::ContInfRes::ContInfRes(
			const string& Dld
			, const string& TxtPrg
		) :
			Block()
			, Dld(Dld)
			, TxtPrg(TxtPrg)
		{
	mask = {DLD, TXTPRG};
};

bool DlgWznmRlsFinreptr::ContInfRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfDlgWznmRlsFinreptrRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfDlgWznmRlsFinreptrRes";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Dld", Dld)) add(DLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPrg", TxtPrg)) add(TXTPRG);
	};

	return basefound;
};

set<uint> DlgWznmRlsFinreptr::ContInfRes::comm(
			const ContInfRes* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);
	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::ContInfRes::diff(
			const ContInfRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLD, TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::StatApp
 ******************************************************************************/

DlgWznmRlsFinreptr::StatApp::StatApp(
			const bool initdone
			, const string& shortMenu
		) :
			Block()
			, initdone(initdone)
			, shortMenu(shortMenu)
		{
	mask = {INITDONE, SHORTMENU};
};

bool DlgWznmRlsFinreptr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppDlgWznmRlsFinreptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppDlgWznmRlsFinreptr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone", initdone)) add(INITDONE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
	};

	return basefound;
};

set<uint> DlgWznmRlsFinreptr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdone == comp->initdone) insert(items, INITDONE);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::StatApp::diff(
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
 class DlgWznmRlsFinreptr::StatShr
 ******************************************************************************/

DlgWznmRlsFinreptr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
			, ButDneActive(ButDneActive)
		{
	mask = {BUTDNEACTIVE};
};

bool DlgWznmRlsFinreptr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsFinreptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsFinreptr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDneActive", ButDneActive)) add(BUTDNEACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsFinreptr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::StatShr::diff(
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
 class DlgWznmRlsFinreptr::StatShrFin
 ******************************************************************************/

DlgWznmRlsFinreptr::StatShrFin::StatShrFin(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
			, ButRunActive(ButRunActive)
			, ButStoActive(ButStoActive)
		{
	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

bool DlgWznmRlsFinreptr::StatShrFin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsFinreptrFin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsFinreptrFin";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRunActive", ButRunActive)) add(BUTRUNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStoActive", ButStoActive)) add(BUTSTOACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsFinreptr::StatShrFin::comm(
			const StatShrFin* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::StatShrFin::diff(
			const StatShrFin* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::StatShrRes
 ******************************************************************************/

DlgWznmRlsFinreptr::StatShrRes::StatShrRes(
			const bool DldAvail
			, const bool DldActive
			, const bool TxtPrgAvail
			, const bool Sep1Avail
			, const bool ButPsgAvail
			, const bool ButPsgActive
		) :
			Block()
			, DldAvail(DldAvail)
			, DldActive(DldActive)
			, TxtPrgAvail(TxtPrgAvail)
			, Sep1Avail(Sep1Avail)
			, ButPsgAvail(ButPsgAvail)
			, ButPsgActive(ButPsgActive)
		{
	mask = {DLDAVAIL, DLDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTPSGAVAIL, BUTPSGACTIVE};
};

bool DlgWznmRlsFinreptr::StatShrRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrDlgWznmRlsFinreptrRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrDlgWznmRlsFinreptrRes";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldAvail", DldAvail)) add(DLDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "DldActive", DldActive)) add(DLDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPrgAvail", TxtPrgAvail)) add(TXTPRGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Sep1Avail", Sep1Avail)) add(SEP1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPsgAvail", ButPsgAvail)) add(BUTPSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPsgActive", ButPsgActive)) add(BUTPSGACTIVE);
	};

	return basefound;
};

set<uint> DlgWznmRlsFinreptr::StatShrRes::comm(
			const StatShrRes* comp
		) {
	set<uint> items;

	if (DldAvail == comp->DldAvail) insert(items, DLDAVAIL);
	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);
	if (TxtPrgAvail == comp->TxtPrgAvail) insert(items, TXTPRGAVAIL);
	if (Sep1Avail == comp->Sep1Avail) insert(items, SEP1AVAIL);
	if (ButPsgAvail == comp->ButPsgAvail) insert(items, BUTPSGAVAIL);
	if (ButPsgActive == comp->ButPsgActive) insert(items, BUTPSGACTIVE);

	return(items);
};

set<uint> DlgWznmRlsFinreptr::StatShrRes::diff(
			const StatShrRes* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLDAVAIL, DLDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTPSGAVAIL, BUTPSGACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::Tag
 ******************************************************************************/

DlgWznmRlsFinreptr::Tag::Tag(
			const string& Cpt
			, const string& ButDne
		) :
			Block()
			, Cpt(Cpt)
			, ButDne(ButDne)
		{
	mask = {CPT, BUTDNE};
};

bool DlgWznmRlsFinreptr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsFinreptr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsFinreptr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButDne", ButDne)) add(BUTDNE);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsFinreptr::TagFin
 ******************************************************************************/

DlgWznmRlsFinreptr::TagFin::TagFin(
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

bool DlgWznmRlsFinreptr::TagFin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsFinreptrFin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsFinreptrFin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButRun", ButRun)) add(BUTRUN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButSto", ButSto)) add(BUTSTO);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsFinreptr::TagRes
 ******************************************************************************/

DlgWznmRlsFinreptr::TagRes::TagRes(
			const string& Dld
			, const string& CptPrg
			, const string& ButPsg
		) :
			Block()
			, Dld(Dld)
			, CptPrg(CptPrg)
			, ButPsg(ButPsg)
		{
	mask = {DLD, CPTPRG, BUTPSG};
};

bool DlgWznmRlsFinreptr::TagRes::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagDlgWznmRlsFinreptrRes");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemDlgWznmRlsFinreptrRes";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Dld", Dld)) add(DLD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrg", CptPrg)) add(CPTPRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "ButPsg", ButPsg)) add(BUTPSG);
	};

	return basefound;
};

/******************************************************************************
 class DlgWznmRlsFinreptr::DpchAppData
 ******************************************************************************/

DlgWznmRlsFinreptr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string DlgWznmRlsFinreptr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsFinreptr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmRlsFinreptrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::DpchAppDo
 ******************************************************************************/

DlgWznmRlsFinreptr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const uint ixVDoFin
			, const uint ixVDoRes
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDO, scrJref)
			, ixVDo(ixVDo)
			, ixVDoFin(ixVDoFin)
			, ixVDoRes(ixVDoRes)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO, IXVDOFIN, IXVDORES};
	else this->mask = mask;

};

string DlgWznmRlsFinreptr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOFIN)) ss.push_back("ixVDoFin");
	if (has(IXVDORES)) ss.push_back("ixVDoRes");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsFinreptr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppDlgWznmRlsFinreptrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
		if (has(IXVDOFIN)) writeString(wr, "srefIxVDoFin", VecVDoFin::getSref(ixVDoFin));
		if (has(IXVDORES)) writeString(wr, "srefIxVDoRes", VecVDoRes::getSref(ixVDoRes));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::DpchEngData
 ******************************************************************************/

DlgWznmRlsFinreptr::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMRLSFINREPTRDATA)
		{
	feedFDse.tag = "FeedFDse";
	feedFSge.tag = "FeedFSge";
};

string DlgWznmRlsFinreptr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFFIN)) ss.push_back("continffin");
	if (has(CONTINFRES)) ss.push_back("continfres");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRFIN)) ss.push_back("statshrfin");
	if (has(STATSHRRES)) ss.push_back("statshrres");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGFIN)) ss.push_back("tagfin");
	if (has(TAGRES)) ss.push_back("tagres");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsFinreptr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngDlgWznmRlsFinreptrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (continffin.readXML(docctx, basexpath, true)) add(CONTINFFIN);
		if (continfres.readXML(docctx, basexpath, true)) add(CONTINFRES);
		if (feedFDse.readXML(docctx, basexpath, true)) add(FEEDFDSE);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (statshrfin.readXML(docctx, basexpath, true)) add(STATSHRFIN);
		if (statshrres.readXML(docctx, basexpath, true)) add(STATSHRRES);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (tagfin.readXML(docctx, basexpath, true)) add(TAGFIN);
		if (tagres.readXML(docctx, basexpath, true)) add(TAGRES);
	} else {
		contiac = ContIac();
		continf = ContInf();
		continffin = ContInfFin();
		continfres = ContInfRes();
		feedFDse.clear();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		statshrfin = StatShrFin();
		statshrres = StatShrRes();
		tag = Tag();
		tagfin = TagFin();
		tagres = TagRes();
	};
};
