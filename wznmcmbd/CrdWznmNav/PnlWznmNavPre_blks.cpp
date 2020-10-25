/**
	* \file PnlWznmNavPre_blks.cpp
	* job handler for job PnlWznmNavPre (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavPre::VecVDo
 ******************************************************************************/

uint PnlWznmNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butappremoveclick") return BUTAPPREMOVECLICK;
	if (s == "butverremoveclick") return BUTVERREMOVECLICK;

	return(0);
};

string PnlWznmNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTAPPREMOVECLICK) return("ButAppRemoveClick");
	if (ix == BUTVERREMOVECLICK) return("ButVerRemoveClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavPre::ContInf
 ******************************************************************************/

PnlWznmNavPre::ContInf::ContInf(
			const string& TxtApp
			, const string& TxtVer
		) :
			Block()
		{
	this->TxtApp = TxtApp;
	this->TxtVer = TxtVer;

	mask = {TXTAPP, TXTVER};
};

void PnlWznmNavPre::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtApp", TxtApp);
		writeStringAttr(wr, itemtag, "sref", "TxtVer", TxtVer);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtApp == comp->TxtApp) insert(items, TXTAPP);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);

	return(items);
};

set<uint> PnlWznmNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTAPP, TXTVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavPre::StatShr
 ******************************************************************************/

PnlWznmNavPre::StatShr::StatShr(
			const bool TxtAppAvail
			, const bool TxtVerAvail
		) :
			Block()
		{
	this->TxtAppAvail = TxtAppAvail;
	this->TxtVerAvail = TxtVerAvail;

	mask = {TXTAPPAVAIL, TXTVERAVAIL};
};

void PnlWznmNavPre::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavPre";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxtAppAvail", TxtAppAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtVerAvail", TxtVerAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtAppAvail == comp->TxtAppAvail) insert(items, TXTAPPAVAIL);
	if (TxtVerAvail == comp->TxtVerAvail) insert(items, TXTVERAVAIL);

	return(items);
};

set<uint> PnlWznmNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTAPPAVAIL, TXTVERAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavPre::Tag
 ******************************************************************************/

void PnlWznmNavPre::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavPre";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavPre";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptApp", "accessor app");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "version");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavPre::DpchAppDo
 ******************************************************************************/

PnlWznmNavPre::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVPREDO)
		{
	ixVDo = 0;
};

string PnlWznmNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavPre::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavPreDo");
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
 class PnlWznmNavPre::DpchEngData
 ******************************************************************************/

PnlWznmNavPre::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVPREDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavPre::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavPre::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavPreData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

