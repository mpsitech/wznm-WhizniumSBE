/**
	* \file CrdWznmRls_blks.cpp
	* job handler for job CrdWznmRls (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmRls::VecVDo
 ******************************************************************************/

uint CrdWznmRls::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdsrtclick") return MITCRDSRTCLICK;
	if (s == "mitcrdcrtclick") return MITCRDCRTCLICK;
	if (s == "mitcrdfrtclick") return MITCRDFRTCLICK;
	if (s == "mitcrdwcoclick") return MITCRDWCOCLICK;

	return(0);
};

string CrdWznmRls::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDSRTCLICK) return("MitCrdSrtClick");
	if (ix == MITCRDCRTCLICK) return("MitCrdCrtClick");
	if (ix == MITCRDFRTCLICK) return("MitCrdFrtClick");
	if (ix == MITCRDWCOCLICK) return("MitCrdWcoClick");

	return("");
};

/******************************************************************************
 class CrdWznmRls::VecVSge
 ******************************************************************************/

uint CrdWznmRls::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmRls::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

void CrdWznmRls::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdWznmRls::ContInf
 ******************************************************************************/

CrdWznmRls::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdRls
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdRls = MtxCrdRls;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
};

void CrdWznmRls::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmRls";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdRls", MtxCrdRls);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmRls::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdRls == comp->MtxCrdRls) insert(items, MTXCRDRLS);

	return(items);
};

set<uint> CrdWznmRls::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmRls::StatApp
 ******************************************************************************/

void CrdWznmRls::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmRls";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVReqitmode", VecWznmVReqitmode::getSref(ixWznmVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmRls::StatShr
 ******************************************************************************/

CrdWznmRls::StatShr::StatShr(
			const ubigint jrefDlgfinreptr
			, const ubigint jrefDlgstareptr
			, const ubigint jrefDlgwrite
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdSrtAvail
			, const bool MitCrdSrtActive
			, const bool MitCrdCrtAvail
			, const bool MitCrdCrtActive
			, const bool MitCrdFrtAvail
			, const bool MitCrdFrtActive
			, const bool MitCrdWcoAvail
			, const bool MitCrdWcoActive
		) :
			Block()
		{
	this->jrefDlgfinreptr = jrefDlgfinreptr;
	this->jrefDlgstareptr = jrefDlgstareptr;
	this->jrefDlgwrite = jrefDlgwrite;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefList = jrefList;
	this->jrefRec = jrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdSrtAvail = MitCrdSrtAvail;
	this->MitCrdSrtActive = MitCrdSrtActive;
	this->MitCrdCrtAvail = MitCrdCrtAvail;
	this->MitCrdCrtActive = MitCrdCrtActive;
	this->MitCrdFrtAvail = MitCrdFrtAvail;
	this->MitCrdFrtActive = MitCrdFrtActive;
	this->MitCrdWcoAvail = MitCrdWcoAvail;
	this->MitCrdWcoActive = MitCrdWcoActive;

	mask = {JREFDLGFINREPTR, JREFDLGSTAREPTR, JREFDLGWRITE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
};

void CrdWznmRls::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmRls";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgfinreptr", Scr::scramble(jrefDlgfinreptr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgstareptr", Scr::scramble(jrefDlgstareptr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgwrite", Scr::scramble(jrefDlgwrite));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSrtAvail", MitCrdSrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSrtActive", MitCrdSrtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCrtAvail", MitCrdCrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCrtActive", MitCrdCrtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFrtAvail", MitCrdFrtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFrtActive", MitCrdFrtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdWcoAvail", MitCrdWcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdWcoActive", MitCrdWcoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmRls::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgfinreptr == comp->jrefDlgfinreptr) insert(items, JREFDLGFINREPTR);
	if (jrefDlgstareptr == comp->jrefDlgstareptr) insert(items, JREFDLGSTAREPTR);
	if (jrefDlgwrite == comp->jrefDlgwrite) insert(items, JREFDLGWRITE);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdSrtAvail == comp->MitCrdSrtAvail) insert(items, MITCRDSRTAVAIL);
	if (MitCrdSrtActive == comp->MitCrdSrtActive) insert(items, MITCRDSRTACTIVE);
	if (MitCrdCrtAvail == comp->MitCrdCrtAvail) insert(items, MITCRDCRTAVAIL);
	if (MitCrdCrtActive == comp->MitCrdCrtActive) insert(items, MITCRDCRTACTIVE);
	if (MitCrdFrtAvail == comp->MitCrdFrtAvail) insert(items, MITCRDFRTAVAIL);
	if (MitCrdFrtActive == comp->MitCrdFrtActive) insert(items, MITCRDFRTACTIVE);
	if (MitCrdWcoAvail == comp->MitCrdWcoAvail) insert(items, MITCRDWCOAVAIL);
	if (MitCrdWcoActive == comp->MitCrdWcoActive) insert(items, MITCRDWCOACTIVE);

	return(items);
};

set<uint> CrdWznmRls::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGFINREPTR, JREFDLGSTAREPTR, JREFDLGWRITE, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmRls::Tag
 ******************************************************************************/

void CrdWznmRls::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmRls";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmRls";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdSrt", "Start repository transaction ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCrt", "Cancel repository transaction");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFrt", "Finalize repository transaction ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdWco", "Write code ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmRls::DpchAppDo
 ******************************************************************************/

CrdWznmRls::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRLSDO)
		{
	ixVDo = 0;
};

string CrdWznmRls::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmRls::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmRlsDo");
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
 class CrdWznmRls::DpchEngData
 ******************************************************************************/

CrdWznmRls::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRLSDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWznmRls::DpchEngData::getSrefsMask() {
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

void CrdWznmRls::DpchEngData::merge(
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

void CrdWznmRls::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmRlsData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

