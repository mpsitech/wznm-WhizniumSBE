/**
	* \file DlgWznmFilNew_blks.cpp
	* job handler for job DlgWznmFilNew (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmFilNew::VecVDit
 ******************************************************************************/

uint DlgWznmFilNew::VecVDit::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "det") return DET;
	if (s == "fil") return FIL;

	return(0);
};

string DlgWznmFilNew::VecVDit::getSref(
			const uint ix
		) {
	if (ix == DET) return("Det");
	if (ix == FIL) return("Fil");

	return("");
};

string DlgWznmFilNew::VecVDit::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == DET) return("Details");
		if (ix == FIL) return("File");
		return(getSref(ix));
	};

	return("");
};

void DlgWznmFilNew::VecVDit::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

/******************************************************************************
 class DlgWznmFilNew::VecVDo
 ******************************************************************************/

uint DlgWznmFilNew::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmFilNew::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmFilNew::VecVDoDet
 ******************************************************************************/

uint DlgWznmFilNew::VecVDoDet::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcreclick") return BUTCRECLICK;

	return(0);
};

string DlgWznmFilNew::VecVDoDet::getSref(
			const uint ix
		) {
	if (ix == BUTCRECLICK) return("ButCreClick");

	return("");
};

/******************************************************************************
 class DlgWznmFilNew::VecVSge
 ******************************************************************************/

uint DlgWznmFilNew::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "create") return CREATE;
	if (s == "credone") return CREDONE;
	if (s == "done") return DONE;

	return(0);
};

string DlgWznmFilNew::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CREATE) return("create");
	if (ix == CREDONE) return("credone");
	if (ix == DONE) return("done");

	return("");
};

void DlgWznmFilNew::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmFilNew::ContIac
 ******************************************************************************/

DlgWznmFilNew::ContIac::ContIac(
			const uint numFDse
		) :
			Block()
		{
	this->numFDse = numFDse;

	mask = {NUMFDSE};
};

bool DlgWznmFilNew::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmFilNew");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmFilNew";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFDse", numFDse)) add(NUMFDSE);
	};

	return basefound;
};

void DlgWznmFilNew::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmFilNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFDse", numFDse);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmFilNew::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFDse == comp->numFDse) insert(items, NUMFDSE);

	return(items);
};

set<uint> DlgWznmFilNew::ContIac::diff(
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
 class DlgWznmFilNew::ContIacDet
 ******************************************************************************/

DlgWznmFilNew::ContIacDet::ContIacDet(
			const string& TxfFnm
			, const uint numFPupRet
			, const string& TxfReu
			, const uint numFPupCnt
			, const uint numFPupMim
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfFnm = TxfFnm;
	this->numFPupRet = numFPupRet;
	this->TxfReu = TxfReu;
	this->numFPupCnt = numFPupCnt;
	this->numFPupMim = numFPupMim;
	this->TxfCmt = TxfCmt;

	mask = {TXFFNM, NUMFPUPRET, TXFREU, NUMFPUPCNT, NUMFPUPMIM, TXFCMT};
};

bool DlgWznmFilNew::ContIacDet::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacDlgWznmFilNewDet");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacDlgWznmFilNewDet";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfReu", TxfReu)) add(TXFREU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCnt", numFPupCnt)) add(NUMFPUPCNT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupMim", numFPupMim)) add(NUMFPUPMIM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void DlgWznmFilNew::ContIacDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacDlgWznmFilNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacDlgWznmFilNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeStringAttr(wr, itemtag, "sref", "TxfReu", TxfReu);
		writeUintAttr(wr, itemtag, "sref", "numFPupCnt", numFPupCnt);
		writeUintAttr(wr, itemtag, "sref", "numFPupMim", numFPupMim);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmFilNew::ContIacDet::comm(
			const ContIacDet* comp
		) {
	set<uint> items;

	if (TxfFnm == comp->TxfFnm) insert(items, TXFFNM);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (TxfReu == comp->TxfReu) insert(items, TXFREU);
	if (numFPupCnt == comp->numFPupCnt) insert(items, NUMFPUPCNT);
	if (numFPupMim == comp->numFPupMim) insert(items, NUMFPUPMIM);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> DlgWznmFilNew::ContIacDet::diff(
			const ContIacDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFFNM, NUMFPUPRET, TXFREU, NUMFPUPCNT, NUMFPUPMIM, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmFilNew::ContInf
 ******************************************************************************/

DlgWznmFilNew::ContInf::ContInf(
			const uint numFSge
		) :
			Block()
		{
	this->numFSge = numFSge;

	mask = {NUMFSGE};
};

void DlgWznmFilNew::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmFilNew";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmFilNew::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);

	return(items);
};

set<uint> DlgWznmFilNew::ContInf::diff(
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
 class DlgWznmFilNew::StatApp
 ******************************************************************************/

void DlgWznmFilNew::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdone
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmFilNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdone", initdone);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmFilNew::StatShr
 ******************************************************************************/

DlgWznmFilNew::StatShr::StatShr(
			const bool ButDneActive
		) :
			Block()
		{
	this->ButDneActive = ButDneActive;

	mask = {BUTDNEACTIVE};
};

void DlgWznmFilNew::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmFilNew";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButDneActive", ButDneActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmFilNew::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButDneActive == comp->ButDneActive) insert(items, BUTDNEACTIVE);

	return(items);
};

set<uint> DlgWznmFilNew::StatShr::diff(
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
 class DlgWznmFilNew::StatShrDet
 ******************************************************************************/

DlgWznmFilNew::StatShrDet::StatShrDet(
			const bool ButCreActive
		) :
			Block()
		{
	this->ButCreActive = ButCreActive;

	mask = {BUTCREACTIVE};
};

void DlgWznmFilNew::StatShrDet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmFilNewDet";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmFilNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButCreActive", ButCreActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmFilNew::StatShrDet::comm(
			const StatShrDet* comp
		) {
	set<uint> items;

	if (ButCreActive == comp->ButCreActive) insert(items, BUTCREACTIVE);

	return(items);
};

set<uint> DlgWznmFilNew::StatShrDet::diff(
			const StatShrDet* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTCREACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmFilNew::StatShrFil
 ******************************************************************************/

DlgWznmFilNew::StatShrFil::StatShrFil(
			const bool UldActive
		) :
			Block()
		{
	this->UldActive = UldActive;

	mask = {ULDACTIVE};
};

void DlgWznmFilNew::StatShrFil::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmFilNewFil";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmFilNewFil";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "UldActive", UldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmFilNew::StatShrFil::comm(
			const StatShrFil* comp
		) {
	set<uint> items;

	if (UldActive == comp->UldActive) insert(items, ULDACTIVE);

	return(items);
};

set<uint> DlgWznmFilNew::StatShrFil::diff(
			const StatShrFil* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ULDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmFilNew::Tag
 ******************************************************************************/

void DlgWznmFilNew::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmFilNew";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmFilNew";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Upload new file");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmFilNew::TagDet
 ******************************************************************************/

void DlgWznmFilNew::TagDet::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmFilNewDet";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmFilNewDet";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptFnm", "File name");
			writeStringAttr(wr, itemtag, "sref", "CptRet", "Table of reference");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "Reference");
			writeStringAttr(wr, itemtag, "sref", "CptCnt", "Content");
			writeStringAttr(wr, itemtag, "sref", "CptMim", "MIME type");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "Comment");
		};
		writeStringAttr(wr, itemtag, "sref", "ButCre", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CREATE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmFilNew::TagFil
 ******************************************************************************/

void DlgWznmFilNew::TagFil::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmFilNewFil";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmFilNewFil";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		};
		writeStringAttr(wr, itemtag, "sref", "Uld", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::UPLOAD, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::FILENAME, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmFilNew::DpchAppData
 ******************************************************************************/

DlgWznmFilNew::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMFILNEWDATA)
		{
};

string DlgWznmFilNew::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmFilNew::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmFilNewData");
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
 class DlgWznmFilNew::DpchAppDo
 ******************************************************************************/

DlgWznmFilNew::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMFILNEWDO)
		{
	ixVDo = 0;
	ixVDoDet = 0;
};

string DlgWznmFilNew::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");
	if (has(IXVDODET)) ss.push_back("ixVDoDet");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmFilNew::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;
	string srefIxVDoDet;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmFilNewDo");
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
	} else {
	};
};

/******************************************************************************
 class DlgWznmFilNew::DpchEngData
 ******************************************************************************/

DlgWznmFilNew::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContIacDet* contiacdet
			, ContInf* continf
			, Feed* feedFDetPupCnt
			, Feed* feedFDetPupMim
			, Feed* feedFDetPupRet
			, Feed* feedFDse
			, Feed* feedFSge
			, StatShr* statshr
			, StatShrDet* statshrdet
			, StatShrFil* statshrfil
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMFILNEWDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTIACDET, CONTINF, FEEDFDETPUPCNT, FEEDFDETPUPMIM, FEEDFDETPUPRET, FEEDFDSE, FEEDFSGE, STATAPP, STATSHR, STATSHRDET, STATSHRFIL, TAG, TAGDET, TAGFIL};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTIACDET) && contiacdet) this->contiacdet = *contiacdet;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFDETPUPCNT) && feedFDetPupCnt) this->feedFDetPupCnt = *feedFDetPupCnt;
	if (find(this->mask, FEEDFDETPUPMIM) && feedFDetPupMim) this->feedFDetPupMim = *feedFDetPupMim;
	if (find(this->mask, FEEDFDETPUPRET) && feedFDetPupRet) this->feedFDetPupRet = *feedFDetPupRet;
	if (find(this->mask, FEEDFDSE) && feedFDse) this->feedFDse = *feedFDse;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STATSHRDET) && statshrdet) this->statshrdet = *statshrdet;
	if (find(this->mask, STATSHRFIL) && statshrfil) this->statshrfil = *statshrfil;
};

string DlgWznmFilNew::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTIACDET)) ss.push_back("contiacdet");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFDETPUPCNT)) ss.push_back("feedFDetPupCnt");
	if (has(FEEDFDETPUPMIM)) ss.push_back("feedFDetPupMim");
	if (has(FEEDFDETPUPRET)) ss.push_back("feedFDetPupRet");
	if (has(FEEDFDSE)) ss.push_back("feedFDse");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STATSHRDET)) ss.push_back("statshrdet");
	if (has(STATSHRFIL)) ss.push_back("statshrfil");
	if (has(TAG)) ss.push_back("tag");
	if (has(TAGDET)) ss.push_back("tagdet");
	if (has(TAGFIL)) ss.push_back("tagfil");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmFilNew::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTIACDET)) {contiacdet = src->contiacdet; add(CONTIACDET);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFDETPUPCNT)) {feedFDetPupCnt = src->feedFDetPupCnt; add(FEEDFDETPUPCNT);};
	if (src->has(FEEDFDETPUPMIM)) {feedFDetPupMim = src->feedFDetPupMim; add(FEEDFDETPUPMIM);};
	if (src->has(FEEDFDETPUPRET)) {feedFDetPupRet = src->feedFDetPupRet; add(FEEDFDETPUPRET);};
	if (src->has(FEEDFDSE)) {feedFDse = src->feedFDse; add(FEEDFDSE);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STATSHRDET)) {statshrdet = src->statshrdet; add(STATSHRDET);};
	if (src->has(STATSHRFIL)) {statshrfil = src->statshrfil; add(STATSHRFIL);};
	if (src->has(TAG)) add(TAG);
	if (src->has(TAGDET)) add(TAGDET);
	if (src->has(TAGFIL)) add(TAGFIL);
};

void DlgWznmFilNew::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmFilNewData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTIACDET)) contiacdet.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFDETPUPCNT)) feedFDetPupCnt.writeXML(wr);
		if (has(FEEDFDETPUPMIM)) feedFDetPupMim.writeXML(wr);
		if (has(FEEDFDETPUPRET)) feedFDetPupRet.writeXML(wr);
		if (has(FEEDFDSE)) feedFDse.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STATSHRDET)) statshrdet.writeXML(wr);
		if (has(STATSHRFIL)) statshrfil.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(TAGDET)) TagDet::writeXML(ixWznmVLocale, wr);
		if (has(TAGFIL)) TagFil::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

