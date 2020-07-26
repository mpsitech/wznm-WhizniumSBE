/**
	* \file PnlWznmNavDeploy_blks.cpp
	* job handler for job PnlWznmNavDeploy (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavDeploy::VecVDo
 ******************************************************************************/

uint PnlWznmNavDeploy::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butcmpviewclick") return BUTCMPVIEWCLICK;
	if (s == "butcmpnewcrdclick") return BUTCMPNEWCRDCLICK;
	if (s == "butrlsviewclick") return BUTRLSVIEWCLICK;
	if (s == "butrlsnewcrdclick") return BUTRLSNEWCRDCLICK;

	return(0);
};

string PnlWznmNavDeploy::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTCMPVIEWCLICK) return("ButCmpViewClick");
	if (ix == BUTCMPNEWCRDCLICK) return("ButCmpNewcrdClick");
	if (ix == BUTRLSVIEWCLICK) return("ButRlsViewClick");
	if (ix == BUTRLSNEWCRDCLICK) return("ButRlsNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavDeploy::ContIac
 ******************************************************************************/

PnlWznmNavDeploy::ContIac::ContIac(
			const uint numFLstCmp
			, const uint numFLstRls
		) :
			Block()
		{
	this->numFLstCmp = numFLstCmp;
	this->numFLstRls = numFLstRls;

	mask = {NUMFLSTCMP, NUMFLSTRLS};
};

bool PnlWznmNavDeploy::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavDeploy");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavDeploy";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCmp", numFLstCmp)) add(NUMFLSTCMP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRls", numFLstRls)) add(NUMFLSTRLS);
	};

	return basefound;
};

void PnlWznmNavDeploy::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstCmp", numFLstCmp);
		writeUintAttr(wr, itemtag, "sref", "numFLstRls", numFLstRls);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavDeploy::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstCmp == comp->numFLstCmp) insert(items, NUMFLSTCMP);
	if (numFLstRls == comp->numFLstRls) insert(items, NUMFLSTRLS);

	return(items);
};

set<uint> PnlWznmNavDeploy::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTCMP, NUMFLSTRLS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavDeploy::StatApp
 ******************************************************************************/

void PnlWznmNavDeploy::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstCmpAlt
			, const bool LstRlsAlt
			, const uint LstCmpNumFirstdisp
			, const uint LstRlsNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCmpAlt", LstCmpAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRlsAlt", LstRlsAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCmpNumFirstdisp", LstCmpNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRlsNumFirstdisp", LstRlsNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavDeploy::StatShr
 ******************************************************************************/

PnlWznmNavDeploy::StatShr::StatShr(
			const bool LstCmpAvail
			, const bool ButCmpViewActive
			, const bool ButCmpNewcrdActive
			, const bool LstRlsAvail
			, const bool ButRlsViewActive
			, const bool ButRlsNewcrdActive
		) :
			Block()
		{
	this->LstCmpAvail = LstCmpAvail;
	this->ButCmpViewActive = ButCmpViewActive;
	this->ButCmpNewcrdActive = ButCmpNewcrdActive;
	this->LstRlsAvail = LstRlsAvail;
	this->ButRlsViewActive = ButRlsViewActive;
	this->ButRlsNewcrdActive = ButRlsNewcrdActive;

	mask = {LSTCMPAVAIL, BUTCMPVIEWACTIVE, BUTCMPNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
};

void PnlWznmNavDeploy::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstCmpAvail", LstCmpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCmpViewActive", ButCmpViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCmpNewcrdActive", ButCmpNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRlsAvail", LstRlsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRlsViewActive", ButRlsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRlsNewcrdActive", ButRlsNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavDeploy::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstCmpAvail == comp->LstCmpAvail) insert(items, LSTCMPAVAIL);
	if (ButCmpViewActive == comp->ButCmpViewActive) insert(items, BUTCMPVIEWACTIVE);
	if (ButCmpNewcrdActive == comp->ButCmpNewcrdActive) insert(items, BUTCMPNEWCRDACTIVE);
	if (LstRlsAvail == comp->LstRlsAvail) insert(items, LSTRLSAVAIL);
	if (ButRlsViewActive == comp->ButRlsViewActive) insert(items, BUTRLSVIEWACTIVE);
	if (ButRlsNewcrdActive == comp->ButRlsNewcrdActive) insert(items, BUTRLSNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavDeploy::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTCMPAVAIL, BUTCMPVIEWACTIVE, BUTCMPNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavDeploy::Tag
 ******************************************************************************/

void PnlWznmNavDeploy::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavDeploy";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavDeploy";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Deployment module");
			writeStringAttr(wr, itemtag, "sref", "CptCmp", "components");
			writeStringAttr(wr, itemtag, "sref", "CptRls", "releases");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavDeploy::DpchAppData
 ******************************************************************************/

PnlWznmNavDeploy::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDEPLOYDATA)
		{
};

string PnlWznmNavDeploy::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDeploy::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavDeployData");
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
 class PnlWznmNavDeploy::DpchAppDo
 ******************************************************************************/

PnlWznmNavDeploy::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDEPLOYDO)
		{
	ixVDo = 0;
};

string PnlWznmNavDeploy::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDeploy::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavDeployDo");
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
 class PnlWznmNavDeploy::DpchEngData
 ******************************************************************************/

PnlWznmNavDeploy::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCmp
			, Feed* feedFLstRls
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVDEPLOYDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCMP, FEEDFLSTRLS, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCMP) && feedFLstCmp) this->feedFLstCmp = *feedFLstCmp;
	if (find(this->mask, FEEDFLSTRLS) && feedFLstRls) this->feedFLstRls = *feedFLstRls;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavDeploy::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCMP)) ss.push_back("feedFLstCmp");
	if (has(FEEDFLSTRLS)) ss.push_back("feedFLstRls");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDeploy::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCMP)) {feedFLstCmp = src->feedFLstCmp; add(FEEDFLSTCMP);};
	if (src->has(FEEDFLSTRLS)) {feedFLstRls = src->feedFLstRls; add(FEEDFLSTRLS);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavDeploy::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavDeployData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCMP)) feedFLstCmp.writeXML(wr);
		if (has(FEEDFLSTRLS)) feedFLstRls.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

