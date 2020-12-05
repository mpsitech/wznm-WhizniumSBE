/**
	* \file DlgWznmRlsFinreptr_blks.cpp
	* job handler for job DlgWznmRlsFinreptr (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

string DlgWznmRlsFinreptr::VecVDit::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == FIN) return("Details");
		if (ix == RES) return("Result");
		return(getSref(ix));
	};

	return("");
};

void DlgWznmRlsFinreptr::VecVDit::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
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

void DlgWznmRlsFinreptr::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 10; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmRlsFinreptr::ContIac
 ******************************************************************************/

DlgWznmRlsFinreptr::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

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
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWznmRlsFinreptr::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWznmRlsFinreptr::ContInfFin::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmRlsFinreptrFin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmRlsFinreptrFin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
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
		{
	this->Dld = Dld;
	this->TxtPrg = TxtPrg;

	mask = {DLD, TXTPRG};
};

void DlgWznmRlsFinreptr::ContInfRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmRlsFinreptrRes";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmRlsFinreptrRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsFinreptr::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::StatShr
 ******************************************************************************/

DlgWznmRlsFinreptr::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWznmRlsFinreptr::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
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
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgWznmRlsFinreptr::StatShrFin::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsFinreptrFin";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsFinreptrFin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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
		{
	this->DldAvail = DldAvail;
	this->DldActive = DldActive;
	this->TxtPrgAvail = TxtPrgAvail;
	this->Sep1Avail = Sep1Avail;
	this->ButPsgAvail = ButPsgAvail;
	this->ButPsgActive = ButPsgActive;

	mask = {DLDAVAIL, DLDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTPSGAVAIL, BUTPSGACTIVE};
};

void DlgWznmRlsFinreptr::StatShrRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsFinreptrRes";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsFinreptrRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldAvail", DldAvail);
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrgAvail", TxtPrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "Sep1Avail", Sep1Avail);
		writeBoolAttr(wr, itemtag, "sref", "ButPsgAvail", ButPsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPsgActive", ButPsgActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsFinreptr::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsFinreptr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsFinreptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Finalize repository transaction");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::TagFin
 ******************************************************************************/

void DlgWznmRlsFinreptr::TagFin::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsFinreptrFin";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsFinreptrFin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::RUN, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::STOP, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::TagRes
 ******************************************************************************/

void DlgWznmRlsFinreptr::TagRes::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsFinreptrRes";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsFinreptrRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "ButPsg", "Push Git");
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DOWNLOAD, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsFinreptr::DpchAppData
 ******************************************************************************/

DlgWznmRlsFinreptr::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDATA)
		{
};

string DlgWznmRlsFinreptr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsFinreptr::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmRlsFinreptrData");
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
 class DlgWznmRlsFinreptr::DpchAppDo
 ******************************************************************************/

DlgWznmRlsFinreptr::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDO)
		{
	ixVDo = 0;
	ixVDoFin = 0;
	ixVDoRes = 0;
};

string DlgWznmRlsFinreptr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOFIN)) ss.push_back("ixVDoFin");
	if (has(IXVDORES)) ss.push_back("ixVDoRes");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsFinreptr::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoFin;
	string srefIxVDoRes;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmRlsFinreptrDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoFin", "", srefIxVDoFin)) {
			ixVDoFin = VecVDoFin::getIx(srefIxVDoFin);
			add(IXVDOFIN);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoRes", "", srefIxVDoRes)) {
			ixVDoRes = VecVDoRes::getIx(srefIxVDoRes);
			add(IXVDORES);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWznmRlsFinreptr::DpchEngData
 ******************************************************************************/

DlgWznmRlsFinreptr::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfFin* continffin
			, ContInfRes* continfres
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrFin* statshrfin
			, StatShrRes* statshrres
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMRLSFINREPTRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFFIN, CONTINFRES, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRFIN, STATSHRRES, TAG, TAGFIN, TAGRES};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFFIN) && continffin) this->continffin = *continffin;
	if (find(this->mask, CONTINFRES) && continfres) this->continfres = *continfres;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRFIN) && statshrfin) this->statshrfin = *statshrfin;
	if (find(this->mask, STATSHRRES) && statshrres) this->statshrres = *statshrres;
};

string DlgWznmRlsFinreptr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void DlgWznmRlsFinreptr::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFFIN)) {continffin = src->continffin; add(CONTINFFIN);};
	if (src->has(CONTINFRES)) {continfres = src->continfres; add(CONTINFRES);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRFIN)) {statshrfin = src->statshrfin; add(STATSHRFIN);};
	if (src->has(STATSHRRES)) {statshrres = src->statshrres; add(STATSHRRES);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGFIN)) add(TAGFIN);
	if (src->has(TAGRES)) add(TAGRES);
};

void DlgWznmRlsFinreptr::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmRlsFinreptrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFFIN)) continffin.writeXML(wr);
		if (has(CONTINFRES)) continfres.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRFIN)) statshrfin.writeXML(wr);
		if (has(STATSHRRES)) statshrres.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(TAGFIN)) TagFin::writeXML(ixWznmVLocale, wr);
		if (has(TAGRES)) TagRes::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};



