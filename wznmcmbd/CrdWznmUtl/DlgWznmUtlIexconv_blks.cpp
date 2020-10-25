/**
	* \file DlgWznmUtlIexconv_blks.cpp
	* job handler for job DlgWznmUtlIexconv (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmUtlIexconv::VecVDit
 ******************************************************************************/

uint DlgWznmUtlIexconv::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "src") return SRC;
	if (s == "cnv") return CNV;
	if (s == "res") return RES;

	return(0);
};

string DlgWznmUtlIexconv::VecVDit::getSref(
			const uint ix
		) {
	if (ix == SRC) return("Src");
	if (ix == CNV) return("Cnv");
	if (ix == RES) return("Res");

	return("");
};

string DlgWznmUtlIexconv::VecVDit::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == SRC) return("Source");
		if (ix == CNV) return("Conversion");
		if (ix == RES) return("Result");
		return(getSref(ix));
	};

	return("");
};

void DlgWznmUtlIexconv::VecVDit::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DlgWznmUtlIexconv::VecVDo
 ******************************************************************************/

uint DlgWznmUtlIexconv::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmUtlIexconv::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmUtlIexconv::VecVDoCnv
 ******************************************************************************/

uint DlgWznmUtlIexconv::VecVDoCnv::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butrunclick") return BUTRUNCLICK;
	if (s == "butstoclick") return BUTSTOCLICK;

	return(0);
};

string DlgWznmUtlIexconv::VecVDoCnv::getSref(
			const uint ix
		) {
	if (ix == BUTRUNCLICK) return("ButRunClick");
	if (ix == BUTSTOCLICK) return("ButStoClick");

	return("");
};

/******************************************************************************
 class DlgWznmUtlIexconv::VecVSge
 ******************************************************************************/

uint DlgWznmUtlIexconv::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "upkidle") return UPKIDLE;
	if (s == "unpack") return UNPACK;
	if (s == "upkdone") return UPKDONE;
	if (s == "ulddone") return ULDDONE;
	if (s == "conv") return CONV;
	if (s == "pack") return PACK;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmUtlIexconv::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == UPKIDLE) return("upkidle");
	if (ix == UNPACK) return("unpack");
	if (ix == UPKDONE) return("upkdone");
	if (ix == ULDDONE) return("ulddone");
	if (ix == CONV) return("conv");
	if (ix == PACK) return("pack");
	if (ix == DONE) return("done");

	return("");
};

void DlgWznmUtlIexconv::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 8; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmUtlIexconv::ContIac
 ******************************************************************************/

DlgWznmUtlIexconv::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWznmUtlIexconv::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmUtlIexconv");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmUtlIexconv";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmUtlIexconv::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmUtlIexconv";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmUtlIexconv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmUtlIexconv::ContIac::diff(
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
 class DlgWznmUtlIexconv::ContInf
 ******************************************************************************/

DlgWznmUtlIexconv::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWznmUtlIexconv::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUtlIexconv";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUtlIexconv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmUtlIexconv::ContInf::diff(
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
 class DlgWznmUtlIexconv::ContInfCnv
 ******************************************************************************/

DlgWznmUtlIexconv::ContInfCnv::ContInfCnv(
			const string& TxtPrg
		) :
			Block()
		{
	this->TxtPrg = TxtPrg;

	mask = {TXTPRG};
};

void DlgWznmUtlIexconv::ContInfCnv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUtlIexconvCnv";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUtlIexconvCnv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrg", TxtPrg);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::ContInfCnv::comm(
			const ContInfCnv* comp
		) {
	set<uint> items;

	if (TxtPrg == comp->TxtPrg) insert(items, TXTPRG);

	return(items);
};

set<uint> DlgWznmUtlIexconv::ContInfCnv::diff(
			const ContInfCnv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRG};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlIexconv::ContInfRes
 ******************************************************************************/

DlgWznmUtlIexconv::ContInfRes::ContInfRes(
			const string& Dld
		) :
			Block()
		{
	this->Dld = Dld;

	mask = {DLD};
};

void DlgWznmUtlIexconv::ContInfRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUtlIexconvRes";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUtlIexconvRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Dld", Dld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::ContInfRes::comm(
			const ContInfRes* comp
		) {
	set<uint> items;

	if (Dld == comp->Dld) insert(items, DLD);

	return(items);
};

set<uint> DlgWznmUtlIexconv::ContInfRes::diff(
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
 class DlgWznmUtlIexconv::StatApp
 ******************************************************************************/

void DlgWznmUtlIexconv::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmUtlIexconv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmUtlIexconv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlIexconv::StatShr
 ******************************************************************************/

DlgWznmUtlIexconv::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWznmUtlIexconv::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlIexconv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlIexconv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmUtlIexconv::StatShr::diff(
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
 class DlgWznmUtlIexconv::StatShrCnv
 ******************************************************************************/

DlgWznmUtlIexconv::StatShrCnv::StatShrCnv(
			const bool ButRunActive
			, const bool ButStoActive
		) :
			Block()
		{
	this->ButRunActive = ButRunActive;
	this->ButStoActive = ButStoActive;

	mask = {BUTRUNACTIVE, BUTSTOACTIVE};
};

void DlgWznmUtlIexconv::StatShrCnv::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlIexconvCnv";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlIexconvCnv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButRunActive", ButRunActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStoActive", ButStoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::StatShrCnv::comm(
			const StatShrCnv* comp
		) {
	set<uint> items;

	if (ButRunActive == comp->ButRunActive) insert(items, BUTRUNACTIVE);
	if (ButStoActive == comp->ButStoActive) insert(items, BUTSTOACTIVE);

	return(items);
};

set<uint> DlgWznmUtlIexconv::StatShrCnv::diff(
			const StatShrCnv* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTRUNACTIVE, BUTSTOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUtlIexconv::StatShrRes
 ******************************************************************************/

DlgWznmUtlIexconv::StatShrRes::StatShrRes(
			const bool DldActive
		) :
			Block()
		{
	this->DldActive = DldActive;

	mask = {DLDACTIVE};
};

void DlgWznmUtlIexconv::StatShrRes::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlIexconvRes";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlIexconvRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DldActive", DldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::StatShrRes::comm(
			const StatShrRes* comp
		) {
	set<uint> items;

	if (DldActive == comp->DldActive) insert(items, DLDACTIVE);

	return(items);
};

set<uint> DlgWznmUtlIexconv::StatShrRes::diff(
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
 class DlgWznmUtlIexconv::StatShrSrc
 ******************************************************************************/

DlgWznmUtlIexconv::StatShrSrc::StatShrSrc(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

void DlgWznmUtlIexconv::StatShrSrc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUtlIexconvSrc";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUtlIexconvSrc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUtlIexconv::StatShrSrc::comm(
			const StatShrSrc* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWznmUtlIexconv::StatShrSrc::diff(
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
 class DlgWznmUtlIexconv::Tag
 ******************************************************************************/

void DlgWznmUtlIexconv::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlIexconv";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlIexconv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Convert text import data");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlIexconv::TagCnv
 ******************************************************************************/

void DlgWznmUtlIexconv::TagCnv::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlIexconvCnv";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlIexconvCnv";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "CptPrg", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::PROGRESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButRun", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::RUN, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "ButSto", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::STOP, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlIexconv::TagRes
 ******************************************************************************/

void DlgWznmUtlIexconv::TagRes::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlIexconvRes";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlIexconvRes";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Dld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DOWNLOAD, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlIexconv::TagSrc
 ******************************************************************************/

void DlgWznmUtlIexconv::TagSrc::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUtlIexconvSrc";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUtlIexconvSrc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::UPLOAD, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::FILENAME, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUtlIexconv::DpchAppData
 ******************************************************************************/

DlgWznmUtlIexconv::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUTLIEXCONVDATA)
		{
};

string DlgWznmUtlIexconv::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlIexconv::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmUtlIexconvData");
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
 class DlgWznmUtlIexconv::DpchAppDo
 ******************************************************************************/

DlgWznmUtlIexconv::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUTLIEXCONVDO)
		{
	ixVDo = 0;
	ixVDoCnv = 0;
};

string DlgWznmUtlIexconv::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDOCNV)) ss.push_back("ixVDoCnv");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlIexconv::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoCnv;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmUtlIexconvDo");
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
		if (extractStringUclc(docctx, basexpath, "srefIxVDoCnv", "", srefIxVDoCnv)) {
			ixVDoCnv = VecVDoCnv::getIx(srefIxVDoCnv);
			add(IXVDOCNV);
		};
	} else {
	};
};

/******************************************************************************
 class DlgWznmUtlIexconv::DpchEngData
 ******************************************************************************/

DlgWznmUtlIexconv::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, ContInfCnv* continfcnv
			, ContInfRes* continfres
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrCnv* statshrcnv
			, StatShrRes* statshrres
			, StatShrSrc* statshrsrc
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMUTLIEXCONVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, CONTINFCNV, CONTINFRES, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRCNV, STATSHRRES, STATSHRSRC, TAG, TAGCNV, TAGRES, TAGSRC};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, CONTINFCNV) && continfcnv) this->continfcnv = *continfcnv;
	if (find(this->mask, CONTINFRES) && continfres) this->continfres = *continfres;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRCNV) && statshrcnv) this->statshrcnv = *statshrcnv;
	if (find(this->mask, STATSHRRES) && statshrres) this->statshrres = *statshrres;
	if (find(this->mask, STATSHRSRC) && statshrsrc) this->statshrsrc = *statshrsrc;
};

string DlgWznmUtlIexconv::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(CONTINFCNV)) ss.push_back("continfcnv");
	if (has(CONTINFRES)) ss.push_back("continfres");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRCNV)) ss.push_back("statshrcnv");
	if (has(STATSHRRES)) ss.push_back("statshrres");
	if (has(STATSHRSRC)) ss.push_back("statshrsrc");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGCNV)) ss.push_back("tagcnv");
	if (has(TAGRES)) ss.push_back("tagres");
	if (has(TAGSRC)) ss.push_back("tagsrc");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUtlIexconv::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(CONTINFCNV)) {continfcnv = src->continfcnv; add(CONTINFCNV);};
	if (src->has(CONTINFRES)) {continfres = src->continfres; add(CONTINFRES);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRCNV)) {statshrcnv = src->statshrcnv; add(STATSHRCNV);};
	if (src->has(STATSHRRES)) {statshrres = src->statshrres; add(STATSHRRES);};
	if (src->has(STATSHRSRC)) {statshrsrc = src->statshrsrc; add(STATSHRSRC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGCNV)) add(TAGCNV);
	if (src->has(TAGRES)) add(TAGRES);
	if (src->has(TAGSRC)) add(TAGSRC);
};

void DlgWznmUtlIexconv::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmUtlIexconvData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(CONTINFCNV)) continfcnv.writeXML(wr);
		if (has(CONTINFRES)) continfres.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRCNV)) statshrcnv.writeXML(wr);
		if (has(STATSHRRES)) statshrres.writeXML(wr);
		if (has(STATSHRSRC)) statshrsrc.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(TAGCNV)) TagCnv::writeXML(ixWznmVLocale, wr);
		if (has(TAGRES)) TagRes::writeXML(ixWznmVLocale, wr);
		if (has(TAGSRC)) TagSrc::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

