/**
	* \file DlgWznmRlsStareptr_blks.cpp
	* job handler for job DlgWznmRlsStareptr (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

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

string DlgWznmRlsStareptr::VecVDit::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == DET) return("Details");
		if (ix == INI) return("Initialization");
		if (ix == EXT) return("Code extraction");
		if (ix == LFI) return("Log file");
		return(getSref(ix));
	};

	return("");
};

void DlgWznmRlsStareptr::VecVDit::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
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

void DlgWznmRlsStareptr::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 16; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void DlgWznmRlsStareptr::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::ContInfExt::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmRlsStareptrExt";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmRlsStareptrExt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::ContInfIni::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmRlsStareptrIni";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmRlsStareptrIni";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::ContInfLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmRlsStareptrLfi";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmRlsStareptrLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::StatShrDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsStareptrDet";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsStareptrDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfGrlAvail", TxfGrlAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStaActive", ButStaActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::StatShrExt::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsStareptrExt";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsStareptrExt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::StatShrIni::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsStareptrIni";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsStareptrIni";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldAvail", UldAvail);
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrgAvail", TxtPrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "Sep1Avail", Sep1Avail);
		writeBoolAttr(wr, itemtag, "sref", "ButClgAvail", ButClgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButClgActive", ButClgActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::StatShrLfi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmRlsStareptrLfi";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmRlsStareptrLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
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

void DlgWznmRlsStareptr::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsStareptr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsStareptr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Start repository transaction");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagDet
 ******************************************************************************/

void DlgWznmRlsStareptr::TagDet::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsStareptrDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsStareptrDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptBrt", "Base repository type");
			writeStringAttr(wr, itemtag, "sref", "CptGrl", "Git URL");
			writeStringAttr(wr, itemtag, "sref", "ButSta", "Start");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagExt
 ******************************************************************************/

void DlgWznmRlsStareptr::TagExt::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsStareptrExt";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsStareptrExt";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::RUN, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::STOP, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagIni
 ******************************************************************************/

void DlgWznmRlsStareptr::TagIni::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsStareptrIni";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsStareptrIni";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "ButClg", "Clone Git");
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::UPLOAD, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::FILENAME, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsStareptr::TagLfi
 ******************************************************************************/

void DlgWznmRlsStareptr::TagLfi::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmRlsStareptrLfi";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmRlsStareptrLfi";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DOWNLOAD, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmRlsStareptr::DpchAppData
 ******************************************************************************/

DlgWznmRlsStareptr::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDATA)
		{
};

string DlgWznmRlsStareptr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsStareptr::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmRlsStareptrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (contiacdet.readXML(docctx, basexpath, true)) add(CONTIACDET);
	} else {
		contiac = ContIac();
		contiacdet = ContIacDet();
	};
};

/******************************************************************************
 class DlgWznmRlsStareptr::DpchAppDo
 ******************************************************************************/

DlgWznmRlsStareptr::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDO)
		{
	ixVDo = 0;
	ixVDoDet = 0;
	ixVDoExt = 0;
	ixVDoIni = 0;
};

string DlgWznmRlsStareptr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");
	if (has(IXVDOEXT)) ss.push_back("ixVDoExt");
	if (has(IXVDOINI)) ss.push_back("ixVDoIni");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmRlsStareptr::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoDet;
	string srefIxVDoExt;
	string srefIxVDoIni;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmRlsStareptrDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoDet", "", srefIxVDoDet)) {
			ixVDoDet = VecVDoDet::getIx(srefIxVDoDet);
			add(IXVDODET);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoExt", "", srefIxVDoExt)) {
			ixVDoExt = VecVDoExt::getIx(srefIxVDoExt);
			add(IXVDOEXT);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDoIni", "", srefIxVDoIni)) {
			ixVDoIni = VecVDoIni::getIx(srefIxVDoIni);
			add(IXVDOINI);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWznmRlsStareptr::DpchEngData
 ******************************************************************************/

DlgWznmRlsStareptr::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, ContInfExt* continfext
			, ContInfIni* continfini
			, ContInfLfi* continflfi
			, Feed* feedFDetRbuBrt
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrDet* statshrdet
			, StatShrExt* statshrext
			, StatShrIni* statshrini
			, StatShrLfi* statshrlfi
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMRLSSTAREPTRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, CONTINFEXT, CONTINFINI, CONTINFLFI, FEEDFDETRBUBRT, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRDET, STATSHREXT, STATSHRINI, STATSHRLFI, TAG, TAGDET, TAGEXT, TAGINI, TAGLFI};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFEXT) && continfext) this->continfext = *continfext;
	if (find(this->mask, CONTINFINI) && continfini) this->continfini = *continfini;
	if (find(this->mask, CONTINFLFI) && continflfi) this->continflfi = *continflfi;
	if (find(this->mask, FEEDFDETRBUBRT) && feedFDetRbuBrt) this->feedFDetRbuBrt = *feedFDetRbuBrt;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRDET) && statshrdet) this->statshrdet = *statshrdet;
	if (find(this->mask, STATSHREXT) && statshrext) this->statshrext = *statshrext;
	if (find(this->mask, STATSHRINI) && statshrini) this->statshrini = *statshrini;
	if (find(this->mask, STATSHRLFI) && statshrlfi) this->statshrlfi = *statshrlfi;
};

string DlgWznmRlsStareptr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void DlgWznmRlsStareptr::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFEXT)) {continfext = src->continfext; add(CONTINFEXT);};
	if (src->has(CONTINFINI)) {continfini = src->continfini; add(CONTINFINI);};
	if (src->has(CONTINFLFI)) {continflfi = src->continflfi; add(CONTINFLFI);};
	if (src->has(FEEDFDETRBUBRT)) {feedFDetRbuBrt = src->feedFDetRbuBrt; add(FEEDFDETRBUBRT);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRDET)) {statshrdet = src->statshrdet; add(STATSHRDET);};
	if (src->has(STATSHREXT)) {statshrext = src->statshrext; add(STATSHREXT);};
	if (src->has(STATSHRINI)) {statshrini = src->statshrini; add(STATSHRINI);};
	if (src->has(STATSHRLFI)) {statshrlfi = src->statshrlfi; add(STATSHRLFI);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGDET)) add(TAGDET);
	if (src->has(TAGEXT)) add(TAGEXT);
	if (src->has(TAGINI)) add(TAGINI);
	if (src->has(TAGLFI)) add(TAGLFI);
};

void DlgWznmRlsStareptr::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmRlsStareptrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFEXT)) continfext.writeXML(wr);
		if (has(CONTINFINI)) continfini.writeXML(wr);
		if (has(CONTINFLFI)) continflfi.writeXML(wr);
		if (has(FEEDFDETRBUBRT)) feedFDetRbuBrt.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRDET)) statshrdet.writeXML(wr);
		if (has(STATSHREXT)) statshrext.writeXML(wr);
		if (has(STATSHRINI)) statshrini.writeXML(wr);
		if (has(STATSHRLFI)) statshrlfi.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixWznmVLocale, wr);
		if (has(TAGEXT)) TagExt::writeXML(ixWznmVLocale, wr);
		if (has(TAGINI)) TagIni::writeXML(ixWznmVLocale, wr);
		if (has(TAGLFI)) TagLfi::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

