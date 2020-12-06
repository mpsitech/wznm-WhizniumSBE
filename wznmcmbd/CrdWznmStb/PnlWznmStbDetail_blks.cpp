/**
	* \file PnlWznmStbDetail_blks.cpp
	* job handler for job PnlWznmStbDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmStbDetail::VecVDo
 ******************************************************************************/

uint PnlWznmStbDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butsbsviewclick") return BUTSBSVIEWCLICK;
	if (s == "buttcoviewclick") return BUTTCOVIEWCLICK;

	return(0);
};

string PnlWznmStbDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
	if (ix == BUTTCOVIEWCLICK) return("ButTcoViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmStbDetail::ContIac
 ******************************************************************************/

PnlWznmStbDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const bool ChkHrc
			, const bool ChkLcl
			, const string& TxfExa
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->ChkHrc = ChkHrc;
	this->ChkLcl = ChkLcl;
	this->TxfExa = TxfExa;

	mask = {NUMFPUPTYP, CHKHRC, CHKLCL, TXFEXA};
};

bool PnlWznmStbDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmStbDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmStbDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkHrc", ChkHrc)) add(CHKHRC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkLcl", ChkLcl)) add(CHKLCL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfExa", TxfExa)) add(TXFEXA);
	};

	return basefound;
};

void PnlWznmStbDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmStbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmStbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeBoolAttr(wr, itemtag, "sref", "ChkHrc", ChkHrc);
		writeBoolAttr(wr, itemtag, "sref", "ChkLcl", ChkLcl);
		writeStringAttr(wr, itemtag, "sref", "TxfExa", TxfExa);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmStbDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (ChkHrc == comp->ChkHrc) insert(items, CHKHRC);
	if (ChkLcl == comp->ChkLcl) insert(items, CHKLCL);
	if (TxfExa == comp->TxfExa) insert(items, TXFEXA);

	return(items);
};

set<uint> PnlWznmStbDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, CHKHRC, CHKLCL, TXFEXA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbDetail::ContInf
 ******************************************************************************/

PnlWznmStbDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTbl
			, const string& TxtSbs
			, const string& TxtTco
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTbl = TxtTbl;
	this->TxtSbs = TxtSbs;
	this->TxtTco = TxtTco;

	mask = {TXTSRF, TXTTBL, TXTSBS, TXTTCO};
};

void PnlWznmStbDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmStbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmStbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTbl", TxtTbl);
		writeStringAttr(wr, itemtag, "sref", "TxtSbs", TxtSbs);
		writeStringAttr(wr, itemtag, "sref", "TxtTco", TxtTco);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmStbDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtSbs == comp->TxtSbs) insert(items, TXTSBS);
	if (TxtTco == comp->TxtTco) insert(items, TXTTCO);

	return(items);
};

set<uint> PnlWznmStbDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTBL, TXTSBS, TXTTCO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbDetail::StatApp
 ******************************************************************************/

void PnlWznmStbDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmStbDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmStbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmStbDetail::StatShr
 ******************************************************************************/

PnlWznmStbDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool TxtTblActive
			, const bool TxtSbsActive
			, const bool ButSbsViewAvail
			, const bool ButSbsViewActive
			, const bool ChkHrcActive
			, const bool TxtTcoActive
			, const bool ButTcoViewAvail
			, const bool ButTcoViewActive
			, const bool ChkLclActive
			, const bool TxfExaActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->TxtTblActive = TxtTblActive;
	this->TxtSbsActive = TxtSbsActive;
	this->ButSbsViewAvail = ButSbsViewAvail;
	this->ButSbsViewActive = ButSbsViewActive;
	this->ChkHrcActive = ChkHrcActive;
	this->TxtTcoActive = TxtTcoActive;
	this->ButTcoViewAvail = ButTcoViewAvail;
	this->ButTcoViewActive = ButTcoViewActive;
	this->ChkLclActive = ChkLclActive;
	this->TxfExaActive = TxfExaActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, CHKHRCACTIVE, TXTTCOACTIVE, BUTTCOVIEWAVAIL, BUTTCOVIEWACTIVE, CHKLCLACTIVE, TXFEXAACTIVE};
};

void PnlWznmStbDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmStbDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmStbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTblActive", TxtTblActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSbsActive", TxtSbsActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSbsViewAvail", ButSbsViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSbsViewActive", ButSbsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkHrcActive", ChkHrcActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTcoActive", TxtTcoActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTcoViewAvail", ButTcoViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTcoViewActive", ButTcoViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkLclActive", ChkLclActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfExaActive", TxfExaActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmStbDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (TxtSbsActive == comp->TxtSbsActive) insert(items, TXTSBSACTIVE);
	if (ButSbsViewAvail == comp->ButSbsViewAvail) insert(items, BUTSBSVIEWAVAIL);
	if (ButSbsViewActive == comp->ButSbsViewActive) insert(items, BUTSBSVIEWACTIVE);
	if (ChkHrcActive == comp->ChkHrcActive) insert(items, CHKHRCACTIVE);
	if (TxtTcoActive == comp->TxtTcoActive) insert(items, TXTTCOACTIVE);
	if (ButTcoViewAvail == comp->ButTcoViewAvail) insert(items, BUTTCOVIEWAVAIL);
	if (ButTcoViewActive == comp->ButTcoViewActive) insert(items, BUTTCOVIEWACTIVE);
	if (ChkLclActive == comp->ChkLclActive) insert(items, CHKLCLACTIVE);
	if (TxfExaActive == comp->TxfExaActive) insert(items, TXFEXAACTIVE);

	return(items);
};

set<uint> PnlWznmStbDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, CHKHRCACTIVE, TXTTCOACTIVE, BUTTCOVIEWAVAIL, BUTTCOVIEWACTIVE, CHKLCLACTIVE, TXFEXAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmStbDetail::Tag
 ******************************************************************************/

void PnlWznmStbDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmStbDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmStbDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptTbl", "table");
			writeStringAttr(wr, itemtag, "sref", "CptSbs", "subset");
			writeStringAttr(wr, itemtag, "sref", "CptHrc", "hierarchical");
			writeStringAttr(wr, itemtag, "sref", "CptTco", "table column");
			writeStringAttr(wr, itemtag, "sref", "CptLcl", "localized");
			writeStringAttr(wr, itemtag, "sref", "CptExa", "example");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmStbDetail::DpchAppData
 ******************************************************************************/

PnlWznmStbDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTBDETAILDATA)
		{
};

string PnlWznmStbDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmStbDetailData");
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
 class PnlWznmStbDetail::DpchAppDo
 ******************************************************************************/

PnlWznmStbDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTBDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmStbDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmStbDetailDo");
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
 class PnlWznmStbDetail::DpchEngData
 ******************************************************************************/

PnlWznmStbDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTBDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmStbDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmStbDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmStbDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmStbDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
