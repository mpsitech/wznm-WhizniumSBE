/**
	* \file CrdWznmUtl_blks.cpp
	* job handler for job CrdWznmUtl (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmUtl::VecVDo
 ******************************************************************************/

uint CrdWznmUtl::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdcifclick") return MITCRDCIFCLICK;
	if (s == "mitcrdxipclick") return MITCRDXIPCLICK;
	if (s == "mitcrdmipclick") return MITCRDMIPCLICK;

	return(0);
};

string CrdWznmUtl::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDCIFCLICK) return("MitCrdCifClick");
	if (ix == MITCRDXIPCLICK) return("MitCrdXipClick");
	if (ix == MITCRDMIPCLICK) return("MitCrdMipClick");

	return("");
};

/******************************************************************************
 class CrdWznmUtl::VecVSge
 ******************************************************************************/

uint CrdWznmUtl::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmUtl::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

void CrdWznmUtl::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWznmUtl::ContInf
 ******************************************************************************/

CrdWznmUtl::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;

	mask = {NUMFSGE, MRLAPPHLP};
};

void CrdWznmUtl::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmUtl";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmUtl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmUtl::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);

	return(items);
};

set<uint> CrdWznmUtl::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmUtl::StatApp
 ******************************************************************************/

void CrdWznmUtl::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmUtl";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmUtl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVReqitmode", VecWznmVReqitmode::getSref(ixWznmVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmUtl::StatShr
 ******************************************************************************/

CrdWznmUtl::StatShr::StatShr(
			const ubigint jrefDlgextrip
			, const ubigint jrefDlgiexconv
			, const ubigint jrefDlgmrgip
			, const ubigint jrefHeadbar
		) :
			Block()
		{
	this->jrefDlgextrip = jrefDlgextrip;
	this->jrefDlgiexconv = jrefDlgiexconv;
	this->jrefDlgmrgip = jrefDlgmrgip;
	this->jrefHeadbar = jrefHeadbar;

	mask = {JREFDLGEXTRIP, JREFDLGIEXCONV, JREFDLGMRGIP, JREFHEADBAR};
};

void CrdWznmUtl::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmUtl";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmUtl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgextrip", Scr::scramble(jrefDlgextrip));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgiexconv", Scr::scramble(jrefDlgiexconv));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgmrgip", Scr::scramble(jrefDlgmrgip));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmUtl::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgextrip == comp->jrefDlgextrip) insert(items, JREFDLGEXTRIP);
	if (jrefDlgiexconv == comp->jrefDlgiexconv) insert(items, JREFDLGIEXCONV);
	if (jrefDlgmrgip == comp->jrefDlgmrgip) insert(items, JREFDLGMRGIP);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);

	return(items);
};

set<uint> CrdWznmUtl::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGEXTRIP, JREFDLGIEXCONV, JREFDLGMRGIP, JREFHEADBAR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmUtl::Tag
 ******************************************************************************/

void CrdWznmUtl::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmUtl";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmUtl";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdCif", "Convert text import data ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdXip", "Extract insertion points ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMip", "Merge insertion points ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmUtl::DpchAppDo
 ******************************************************************************/

CrdWznmUtl::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMUTLDO)
		{
	ixVDo = 0;
};

string CrdWznmUtl::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmUtl::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmUtlDo");
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
 class CrdWznmUtl::DpchEngData
 ******************************************************************************/

CrdWznmUtl::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMUTLDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWznmUtl::DpchEngData::getSrefsMask() {
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

void CrdWznmUtl::DpchEngData::merge(
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

void CrdWznmUtl::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmUtlData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

