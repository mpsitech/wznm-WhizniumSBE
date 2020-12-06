/**
	* \file PnlWznmCapDetail_blks.cpp
	* job handler for job PnlWznmCapDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmCapDetail::VecVDo
 ******************************************************************************/

uint PnlWznmCapDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "buttplviewclick") return BUTTPLVIEWCLICK;

	return(0);
};

string PnlWznmCapDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTTPLVIEWCLICK) return("ButTplViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmCapDetail::ContIac
 ******************************************************************************/

PnlWznmCapDetail::ContIac::ContIac(
			const string& TxfTit
			, const vector<uint>& numsFLstAtf
		) :
			Block()
		{
	this->TxfTit = TxfTit;
	this->numsFLstAtf = numsFLstAtf;

	mask = {TXFTIT, NUMSFLSTATF};
};

bool PnlWznmCapDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmCapDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmCapDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstAtf", numsFLstAtf)) add(NUMSFLSTATF);
	};

	return basefound;
};

void PnlWznmCapDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmCapDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmCapDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstAtf", numsFLstAtf);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmCapDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (compareUintvec(numsFLstAtf, comp->numsFLstAtf)) insert(items, NUMSFLSTATF);

	return(items);
};

set<uint> PnlWznmCapDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, NUMSFLSTATF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCapDetail::ContInf
 ******************************************************************************/

PnlWznmCapDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVer
			, const string& TxtTpl
			, const string& TxtAtf
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtVer = TxtVer;
	this->TxtTpl = TxtTpl;
	this->TxtAtf = TxtAtf;

	mask = {TXTSRF, TXTVER, TXTTPL, TXTATF};
};

void PnlWznmCapDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmCapDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmCapDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtVer", TxtVer);
		writeStringAttr(wr, itemtag, "sref", "TxtTpl", TxtTpl);
		writeStringAttr(wr, itemtag, "sref", "TxtAtf", TxtAtf);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmCapDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtTpl == comp->TxtTpl) insert(items, TXTTPL);
	if (TxtAtf == comp->TxtAtf) insert(items, TXTATF);

	return(items);
};

set<uint> PnlWznmCapDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVER, TXTTPL, TXTATF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCapDetail::StatApp
 ******************************************************************************/

void PnlWznmCapDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstAtfAlt
			, const uint LstAtfNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmCapDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmCapDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstAtfAlt", LstAtfAlt);
		writeUintAttr(wr, itemtag, "sref", "LstAtfNumFirstdisp", LstAtfNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCapDetail::StatShr
 ******************************************************************************/

PnlWznmCapDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfTitActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtTplActive
			, const bool ButTplViewAvail
			, const bool ButTplViewActive
			, const bool LstAtfActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfTitActive = TxfTitActive;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtTplActive = TxtTplActive;
	this->ButTplViewAvail = ButTplViewAvail;
	this->ButTplViewActive = ButTplViewActive;
	this->LstAtfActive = LstAtfActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, LSTATFACTIVE};
};

void PnlWznmCapDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmCapDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmCapDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtVerActive", TxtVerActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewAvail", ButVerViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewActive", ButVerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTplActive", TxtTplActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTplViewAvail", ButTplViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTplViewActive", ButTplViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstAtfActive", LstAtfActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmCapDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtTplActive == comp->TxtTplActive) insert(items, TXTTPLACTIVE);
	if (ButTplViewAvail == comp->ButTplViewAvail) insert(items, BUTTPLVIEWAVAIL);
	if (ButTplViewActive == comp->ButTplViewActive) insert(items, BUTTPLVIEWACTIVE);
	if (LstAtfActive == comp->LstAtfActive) insert(items, LSTATFACTIVE);

	return(items);
};

set<uint> PnlWznmCapDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, LSTATFACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCapDetail::Tag
 ******************************************************************************/

void PnlWznmCapDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmCapDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmCapDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "version");
			writeStringAttr(wr, itemtag, "sref", "CptTpl", "template");
			writeStringAttr(wr, itemtag, "sref", "CptAtf", "artefact");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCapDetail::DpchAppData
 ******************************************************************************/

PnlWznmCapDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCAPDETAILDATA)
		{
};

string PnlWznmCapDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCapDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmCapDetailData");
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
 class PnlWznmCapDetail::DpchAppDo
 ******************************************************************************/

PnlWznmCapDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCAPDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmCapDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCapDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmCapDetailDo");
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
 class PnlWznmCapDetail::DpchEngData
 ******************************************************************************/

PnlWznmCapDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstAtf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCAPDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTATF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTATF) && feedFLstAtf) this->feedFLstAtf = *feedFLstAtf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmCapDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTATF)) ss.push_back("feedFLstAtf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCapDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTATF)) {feedFLstAtf = src->feedFLstAtf; add(FEEDFLSTATF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmCapDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmCapDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTATF)) feedFLstAtf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
