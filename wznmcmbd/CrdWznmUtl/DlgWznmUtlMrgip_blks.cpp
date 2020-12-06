/**
	* \file DlgWznmUtlMrgip_blks.cpp
	* job handler for job DlgWznmUtlMrgip (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

string DlgWznmUtlMrgip::VecVDit::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SRC) return("Source");
		if (ix == TRG) return("Target");
		if (ix == MRG) return("Merger");
		if (ix == LFI) return("Log file");
		if (ix == RES) return("Result");
		return(getSref(ix));
	};

	return("");
};

void DlgWznmUtlMrgip::VecVDit::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
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

void DlgWznmUtlMrgip::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 14; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void DlgWznmUtlMrgip::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUtlMrgip";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUtlMrgip";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::ContInfLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUtlMrgipLfi";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUtlMrgipLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::ContInfMrg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUtlMrgipMrg";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUtlMrgipMrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::ContInfRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUtlMrgipRes";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUtlMrgipRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmUtlMrgip";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmUtlMrgip";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlMrgip";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlMrgip";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::StatShrLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlMrgipLfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlMrgipLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::StatShrMrg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlMrgipMrg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlMrgipMrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::StatShrRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlMrgipRes";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlMrgipRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::StatShrSrc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlMrgipSrc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlMrgipSrc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::StatShrTrg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlMrgipTrg";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlMrgipTrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmUtlMrgip::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlMrgip";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlMrgip";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Merge insertion points");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagLfi
 ******************************************************************************/

void DlgWznmUtlMrgip::TagLfi::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlMrgipLfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlMrgipLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DOWNLOAD, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagMrg
 ******************************************************************************/

void DlgWznmUtlMrgip::TagMrg::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlMrgipMrg";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlMrgipMrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::RUN, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::STOP, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagRes
 ******************************************************************************/

void DlgWznmUtlMrgip::TagRes::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlMrgipRes";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlMrgipRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DOWNLOAD, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagSrc
 ******************************************************************************/

void DlgWznmUtlMrgip::TagSrc::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlMrgipSrc";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlMrgipSrc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::UPLOAD, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::FILENAME, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::TagTrg
 ******************************************************************************/

void DlgWznmUtlMrgip::TagTrg::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlMrgipTrg";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlMrgipTrg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::UPLOAD, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::FILENAME, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlMrgip::DpchAppData
 ******************************************************************************/

DlgWznmUtlMrgip::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDATA)
		{
};

string DlgWznmUtlMrgip::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlMrgip::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmUtlMrgipData");
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
 class DlgWznmUtlMrgip::DpchAppDo
 ******************************************************************************/

DlgWznmUtlMrgip::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDO)
		{
	ixVDo = 0;
	ixVDoMrg = 0;
};

string DlgWznmUtlMrgip::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOMRG)) ss.push_back("ixVDoMrg");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlMrgip::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoMrg;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmUtlMrgipDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoMrg", "", srefIxVDoMrg)) {
			ixVDoMrg = VecVDoMrg::getIx(srefIxVDoMrg);
			add(IXVDOMRG);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWznmUtlMrgip::DpchEngData
 ******************************************************************************/

DlgWznmUtlMrgip::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfLfi* continflfi
			, ContInfMrg* continfmrg
			, ContInfRes* continfres
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrLfi* statshrlfi
			, StatShrMrg* statshrmrg
			, StatShrRes* statshrres
			, StatShrSrc* statshrsrc
			, StatShrTrg* statshrtrg
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMUTLMRGIPDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFLFI, CONTINFMRG, CONTINFRES, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRLFI, STATSHRMRG, STATSHRRES, STATSHRSRC, STATSHRTRG, TAG, TAGLFI, TAGMRG, TAGRES, TAGSRC, TAGTRG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFLFI) && continflfi) this->continflfi = *continflfi;
	if (find(this->mask, CONTINFMRG) && continfmrg) this->continfmrg = *continfmrg;
	if (find(this->mask, CONTINFRES) && continfres) this->continfres = *continfres;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRLFI) && statshrlfi) this->statshrlfi = *statshrlfi;
	if (find(this->mask, STATSHRMRG) && statshrmrg) this->statshrmrg = *statshrmrg;
	if (find(this->mask, STATSHRRES) && statshrres) this->statshrres = *statshrres;
	if (find(this->mask, STATSHRSRC) && statshrsrc) this->statshrsrc = *statshrsrc;
	if (find(this->mask, STATSHRTRG) && statshrtrg) this->statshrtrg = *statshrtrg;
};

string DlgWznmUtlMrgip::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void DlgWznmUtlMrgip::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFLFI)) {continflfi = src->continflfi; add(CONTINFLFI);};
	if (src->has(CONTINFMRG)) {continfmrg = src->continfmrg; add(CONTINFMRG);};
	if (src->has(CONTINFRES)) {continfres = src->continfres; add(CONTINFRES);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRLFI)) {statshrlfi = src->statshrlfi; add(STATSHRLFI);};
	if (src->has(STATSHRMRG)) {statshrmrg = src->statshrmrg; add(STATSHRMRG);};
	if (src->has(STATSHRRES)) {statshrres = src->statshrres; add(STATSHRRES);};
	if (src->has(STATSHRSRC)) {statshrsrc = src->statshrsrc; add(STATSHRSRC);};
	if (src->has(STATSHRTRG)) {statshrtrg = src->statshrtrg; add(STATSHRTRG);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGLFI)) add(TAGLFI);
	if (src->has(TAGMRG)) add(TAGMRG);
	if (src->has(TAGRES)) add(TAGRES);
	if (src->has(TAGSRC)) add(TAGSRC);
	if (src->has(TAGTRG)) add(TAGTRG);
};

void DlgWznmUtlMrgip::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmUtlMrgipData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFLFI)) continflfi.writeXML(wr);
		if (has(CONTINFMRG)) continfmrg.writeXML(wr);
		if (has(CONTINFRES)) continfres.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRLFI)) statshrlfi.writeXML(wr);
		if (has(STATSHRMRG)) statshrmrg.writeXML(wr);
		if (has(STATSHRRES)) statshrres.writeXML(wr);
		if (has(STATSHRSRC)) statshrsrc.writeXML(wr);
		if (has(STATSHRTRG)) statshrtrg.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(TAGLFI)) TagLfi::writeXML(ixWznmVLocale, wr);
		if (has(TAGMRG)) TagMrg::writeXML(ixWznmVLocale, wr);
		if (has(TAGRES)) TagRes::writeXML(ixWznmVLocale, wr);
		if (has(TAGSRC)) TagSrc::writeXML(ixWznmVLocale, wr);
		if (has(TAGTRG)) TagTrg::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
