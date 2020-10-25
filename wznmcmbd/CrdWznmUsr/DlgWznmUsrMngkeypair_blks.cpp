/**
	* \file DlgWznmUsrMngkeypair_blks.cpp
	* job handler for job DlgWznmUsrMngkeypair (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DlgWznmUsrMngkeypair::VecVDo
 ******************************************************************************/

uint DlgWznmUsrMngkeypair::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detbutdelclick") return DETBUTDELCLICK;
	if (s == "detbutgenclick") return DETBUTGENCLICK;
	if (s == "butdneclick") return BUTDNECLICK;

	return(0);
};

string DlgWznmUsrMngkeypair::VecVDo::getSref(
			const uint ix
		) {
	if (ix == DETBUTDELCLICK) return("DetButDelClick");
	if (ix == DETBUTGENCLICK) return("DetButGenClick");
	if (ix == BUTDNECLICK) return("ButDneClick");

	return("");
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::VecVSge
 ******************************************************************************/

uint DlgWznmUsrMngkeypair::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nf") return NF;
	if (s == "found") return FOUND;

	return(0);
};

string DlgWznmUsrMngkeypair::VecVSge::getSref(
			const uint ix
		) {
	if (ix == NF) return("nf");
	if (ix == FOUND) return("found");

	return("");
};

void DlgWznmUsrMngkeypair::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::ContInf
 ******************************************************************************/

DlgWznmUsrMngkeypair::ContInf::ContInf(
			const uint numFSge
			, const string& DetTxtSte
			, const string& DetDld
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->DetTxtSte = DetTxtSte;
	this->DetDld = DetDld;

	mask = {NUMFSGE, DETTXTSTE, DETDLD};
};

void DlgWznmUsrMngkeypair::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfDlgWznmUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfDlgWznmUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "DetTxtSte", DetTxtSte);
		writeStringAttr(wr, itemtag, "sref", "DetDld", DetDld);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUsrMngkeypair::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (DetTxtSte == comp->DetTxtSte) insert(items, DETTXTSTE);
	if (DetDld == comp->DetDld) insert(items, DETDLD);

	return(items);
};

set<uint> DlgWznmUsrMngkeypair::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, DETTXTSTE, DETDLD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::StatApp
 ******************************************************************************/

void DlgWznmUsrMngkeypair::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const string& shortMenu
		) {
	if (difftag.length() == 0) difftag = "StatAppDlgWznmUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppDlgWznmUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::StatShr
 ******************************************************************************/

DlgWznmUsrMngkeypair::StatShr::StatShr(
			const bool DetButDelAvail
			, const bool DetButGenAvail
			, const bool DetDldActive
		) :
			Block()
		{
	this->DetButDelAvail = DetButDelAvail;
	this->DetButGenAvail = DetButGenAvail;
	this->DetDldActive = DetDldActive;

	mask = {DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE};
};

void DlgWznmUsrMngkeypair::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrDlgWznmUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrDlgWznmUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "DetButDelAvail", DetButDelAvail);
		writeBoolAttr(wr, itemtag, "sref", "DetButGenAvail", DetButGenAvail);
		writeBoolAttr(wr, itemtag, "sref", "DetDldActive", DetDldActive);
	xmlTextWriterEndElement(wr);
};

set<uint> DlgWznmUsrMngkeypair::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (DetButDelAvail == comp->DetButDelAvail) insert(items, DETBUTDELAVAIL);
	if (DetButGenAvail == comp->DetButGenAvail) insert(items, DETBUTGENAVAIL);
	if (DetDldActive == comp->DetDldActive) insert(items, DETDLDACTIVE);

	return(items);
};

set<uint> DlgWznmUsrMngkeypair::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::Tag
 ******************************************************************************/

void DlgWznmUsrMngkeypair::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagDlgWznmUsrMngkeypair";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemDlgWznmUsrMngkeypair";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Manage SSH key pair");
			writeStringAttr(wr, itemtag, "sref", "DetCptSte", "State");
			writeStringAttr(wr, itemtag, "sref", "DetButDel", "Delete");
			writeStringAttr(wr, itemtag, "sref", "DetButGen", "Generate");
			writeStringAttr(wr, itemtag, "sref", "DetDld", "Download public key");
		};
		writeStringAttr(wr, itemtag, "sref", "ButDne", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DONE, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::DpchAppDo
 ******************************************************************************/

DlgWznmUsrMngkeypair::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPDLGWZNMUSRMNGKEYPAIRDO)
		{
	ixVDo = 0;
};

string DlgWznmUsrMngkeypair::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUsrMngkeypair::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppDlgWznmUsrMngkeypairDo");
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
	} else {
	};
};

/******************************************************************************
 class DlgWznmUsrMngkeypair::DpchEngData
 ******************************************************************************/

DlgWznmUsrMngkeypair::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGDLGWZNMUSRMNGKEYPAIRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string DlgWznmUsrMngkeypair::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void DlgWznmUsrMngkeypair::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void DlgWznmUsrMngkeypair::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngDlgWznmUsrMngkeypairData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

