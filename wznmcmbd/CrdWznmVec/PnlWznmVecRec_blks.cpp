/**
	* \file PnlWznmVecRec_blks.cpp
	* job handler for job PnlWznmVecRec (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVecRec::VecVDo
 ******************************************************************************/

uint PnlWznmVecRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmVecRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmVecRec::ContInf
 ******************************************************************************/

PnlWznmVecRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWznmVecRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVecRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmVecRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVecRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmVecRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecRec::StatApp
 ******************************************************************************/

void PnlWznmVecRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdoneVec1NVectoritem
			, const bool initdoneFct1NTablecol
			, const bool initdoneRef1NPanel
			, const bool initdoneSrc1NFeed
			, const bool initdonePst1NQuerymod
			, const bool initdoneMNTable
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVecRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmVecRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneATitle", initdoneATitle);
		writeBoolAttr(wr, itemtag, "sref", "initdoneVec1NVectoritem", initdoneVec1NVectoritem);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFct1NTablecol", initdoneFct1NTablecol);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NPanel", initdoneRef1NPanel);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSrc1NFeed", initdoneSrc1NFeed);
		writeBoolAttr(wr, itemtag, "sref", "initdonePst1NQuerymod", initdonePst1NQuerymod);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNTable", initdoneMNTable);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVecRec::StatShr
 ******************************************************************************/

PnlWznmVecRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefATitle
			, const ubigint jrefVec1NVectoritem
			, const ubigint jrefFct1NTablecol
			, const bool pnlfct1ntablecolAvail
			, const ubigint jrefRef1NPanel
			, const ubigint jrefSrc1NFeed
			, const ubigint jrefPst1NQuerymod
			, const bool pnlpst1nquerymodAvail
			, const ubigint jrefMNTable
			, const bool pnlmntableAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefATitle = jrefATitle;
	this->jrefVec1NVectoritem = jrefVec1NVectoritem;
	this->jrefFct1NTablecol = jrefFct1NTablecol;
	this->pnlfct1ntablecolAvail = pnlfct1ntablecolAvail;
	this->jrefRef1NPanel = jrefRef1NPanel;
	this->jrefSrc1NFeed = jrefSrc1NFeed;
	this->jrefPst1NQuerymod = jrefPst1NQuerymod;
	this->pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
	this->jrefMNTable = jrefMNTable;
	this->pnlmntableAvail = pnlmntableAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, JREFVEC1NVECTORITEM, JREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, JREFREF1NPANEL, JREFSRC1NFEED, JREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, JREFMNTABLE, PNLMNTABLEAVAIL, BUTREGULARIZEACTIVE};
};

void PnlWznmVecRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVecRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmVecRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefATitle", Scr::scramble(jrefATitle));
		writeStringAttr(wr, itemtag, "sref", "scrJrefVec1NVectoritem", Scr::scramble(jrefVec1NVectoritem));
		writeStringAttr(wr, itemtag, "sref", "scrJrefFct1NTablecol", Scr::scramble(jrefFct1NTablecol));
		writeBoolAttr(wr, itemtag, "sref", "pnlfct1ntablecolAvail", pnlfct1ntablecolAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NPanel", Scr::scramble(jrefRef1NPanel));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrc1NFeed", Scr::scramble(jrefSrc1NFeed));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPst1NQuerymod", Scr::scramble(jrefPst1NQuerymod));
		writeBoolAttr(wr, itemtag, "sref", "pnlpst1nquerymodAvail", pnlpst1nquerymodAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNTable", Scr::scramble(jrefMNTable));
		writeBoolAttr(wr, itemtag, "sref", "pnlmntableAvail", pnlmntableAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVecRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefATitle == comp->jrefATitle) insert(items, JREFATITLE);
	if (jrefVec1NVectoritem == comp->jrefVec1NVectoritem) insert(items, JREFVEC1NVECTORITEM);
	if (jrefFct1NTablecol == comp->jrefFct1NTablecol) insert(items, JREFFCT1NTABLECOL);
	if (pnlfct1ntablecolAvail == comp->pnlfct1ntablecolAvail) insert(items, PNLFCT1NTABLECOLAVAIL);
	if (jrefRef1NPanel == comp->jrefRef1NPanel) insert(items, JREFREF1NPANEL);
	if (jrefSrc1NFeed == comp->jrefSrc1NFeed) insert(items, JREFSRC1NFEED);
	if (jrefPst1NQuerymod == comp->jrefPst1NQuerymod) insert(items, JREFPST1NQUERYMOD);
	if (pnlpst1nquerymodAvail == comp->pnlpst1nquerymodAvail) insert(items, PNLPST1NQUERYMODAVAIL);
	if (jrefMNTable == comp->jrefMNTable) insert(items, JREFMNTABLE);
	if (pnlmntableAvail == comp->pnlmntableAvail) insert(items, PNLMNTABLEAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmVecRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, JREFVEC1NVECTORITEM, JREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, JREFREF1NPANEL, JREFSRC1NFEED, JREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, JREFMNTABLE, PNLMNTABLEAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecRec::Tag
 ******************************************************************************/

void PnlWznmVecRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmVecRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmVecRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Vector");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVecRec::DpchAppDo
 ******************************************************************************/

PnlWznmVecRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVECRECDO)
		{
	ixVDo = 0;
};

string PnlWznmVecRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVecRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVecRecDo");
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
 class PnlWznmVecRec::DpchEngData
 ******************************************************************************/

PnlWznmVecRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVECRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmVecRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVecRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmVecRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmVecRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

