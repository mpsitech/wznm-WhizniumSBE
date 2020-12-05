/**
	* \file PnlWznmOpxDetail_blks.cpp
	* job handler for job PnlWznmOpxDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmOpxDetail::VecVDo
 ******************************************************************************/

uint PnlWznmOpxDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butopkviewclick") return BUTOPKVIEWCLICK;
	if (s == "butsqknewclick") return BUTSQKNEWCLICK;
	if (s == "butsqkdeleteclick") return BUTSQKDELETECLICK;
	if (s == "butsqkjtieditclick") return BUTSQKJTIEDITCLICK;

	return(0);
};

string PnlWznmOpxDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTOPKVIEWCLICK) return("ButOpkViewClick");
	if (ix == BUTSQKNEWCLICK) return("ButSqkNewClick");
	if (ix == BUTSQKDELETECLICK) return("ButSqkDeleteClick");
	if (ix == BUTSQKJTIEDITCLICK) return("ButSqkJtiEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmOpxDetail::ContIac
 ******************************************************************************/

PnlWznmOpxDetail::ContIac::ContIac(
			const bool ChkShd
			, const string& TxfCmt
			, const uint numFPupSqkJti
			, const string& TxfSqkExa
		) :
			Block()
		{
	this->ChkShd = ChkShd;
	this->TxfCmt = TxfCmt;
	this->numFPupSqkJti = numFPupSqkJti;
	this->TxfSqkExa = TxfSqkExa;

	mask = {CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
};

bool PnlWznmOpxDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmOpxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmOpxDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkShd", ChkShd)) add(CHKSHD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSqkJti", numFPupSqkJti)) add(NUMFPUPSQKJTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSqkExa", TxfSqkExa)) add(TXFSQKEXA);
	};

	return basefound;
};

void PnlWznmOpxDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ChkShd", ChkShd);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupSqkJti", numFPupSqkJti);
		writeStringAttr(wr, itemtag, "sref", "TxfSqkExa", TxfSqkExa);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmOpxDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (ChkShd == comp->ChkShd) insert(items, CHKSHD);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupSqkJti == comp->numFPupSqkJti) insert(items, NUMFPUPSQKJTI);
	if (TxfSqkExa == comp->TxfSqkExa) insert(items, TXFSQKEXA);

	return(items);
};

set<uint> PnlWznmOpxDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxDetail::ContInf
 ******************************************************************************/

PnlWznmOpxDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtOpk
			, const string& TxtSqkTit
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtOpk = TxtOpk;
	this->TxtSqkTit = TxtSqkTit;

	mask = {TXTSRF, TXTOPK, TXTSQKTIT};
};

void PnlWznmOpxDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtOpk", TxtOpk);
		writeStringAttr(wr, itemtag, "sref", "TxtSqkTit", TxtSqkTit);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmOpxDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtOpk == comp->TxtOpk) insert(items, TXTOPK);
	if (TxtSqkTit == comp->TxtSqkTit) insert(items, TXTSQKTIT);

	return(items);
};

set<uint> PnlWznmOpxDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTOPK, TXTSQKTIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxDetail::StatApp
 ******************************************************************************/

void PnlWznmOpxDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpxDetail::StatShr
 ******************************************************************************/

PnlWznmOpxDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtOpkActive
			, const bool ButOpkViewAvail
			, const bool ButOpkViewActive
			, const bool ChkShdActive
			, const bool TxfCmtActive
			, const bool ButSqkNewAvail
			, const bool ButSqkDeleteAvail
			, const bool PupSqkJtiAvail
			, const bool PupSqkJtiActive
			, const bool ButSqkJtiEditAvail
			, const bool TxtSqkTitAvail
			, const bool TxtSqkTitActive
			, const bool TxfSqkExaAvail
			, const bool TxfSqkExaActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtOpkActive = TxtOpkActive;
	this->ButOpkViewAvail = ButOpkViewAvail;
	this->ButOpkViewActive = ButOpkViewActive;
	this->ChkShdActive = ChkShdActive;
	this->TxfCmtActive = TxfCmtActive;
	this->ButSqkNewAvail = ButSqkNewAvail;
	this->ButSqkDeleteAvail = ButSqkDeleteAvail;
	this->PupSqkJtiAvail = PupSqkJtiAvail;
	this->PupSqkJtiActive = PupSqkJtiActive;
	this->ButSqkJtiEditAvail = ButSqkJtiEditAvail;
	this->TxtSqkTitAvail = TxtSqkTitAvail;
	this->TxtSqkTitActive = TxtSqkTitActive;
	this->TxfSqkExaAvail = TxfSqkExaAvail;
	this->TxfSqkExaActive = TxfSqkExaActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTOPKACTIVE, BUTOPKVIEWAVAIL, BUTOPKVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
};

void PnlWznmOpxDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtOpkActive", TxtOpkActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOpkViewAvail", ButOpkViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButOpkViewActive", ButOpkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkShdActive", ChkShdActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSqkNewAvail", ButSqkNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSqkDeleteAvail", ButSqkDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSqkJtiAvail", PupSqkJtiAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSqkJtiActive", PupSqkJtiActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSqkJtiEditAvail", ButSqkJtiEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSqkTitAvail", TxtSqkTitAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSqkTitActive", TxtSqkTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSqkExaAvail", TxfSqkExaAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfSqkExaActive", TxfSqkExaActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmOpxDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtOpkActive == comp->TxtOpkActive) insert(items, TXTOPKACTIVE);
	if (ButOpkViewAvail == comp->ButOpkViewAvail) insert(items, BUTOPKVIEWAVAIL);
	if (ButOpkViewActive == comp->ButOpkViewActive) insert(items, BUTOPKVIEWACTIVE);
	if (ChkShdActive == comp->ChkShdActive) insert(items, CHKSHDACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (ButSqkNewAvail == comp->ButSqkNewAvail) insert(items, BUTSQKNEWAVAIL);
	if (ButSqkDeleteAvail == comp->ButSqkDeleteAvail) insert(items, BUTSQKDELETEAVAIL);
	if (PupSqkJtiAvail == comp->PupSqkJtiAvail) insert(items, PUPSQKJTIAVAIL);
	if (PupSqkJtiActive == comp->PupSqkJtiActive) insert(items, PUPSQKJTIACTIVE);
	if (ButSqkJtiEditAvail == comp->ButSqkJtiEditAvail) insert(items, BUTSQKJTIEDITAVAIL);
	if (TxtSqkTitAvail == comp->TxtSqkTitAvail) insert(items, TXTSQKTITAVAIL);
	if (TxtSqkTitActive == comp->TxtSqkTitActive) insert(items, TXTSQKTITACTIVE);
	if (TxfSqkExaAvail == comp->TxfSqkExaAvail) insert(items, TXFSQKEXAAVAIL);
	if (TxfSqkExaActive == comp->TxfSqkExaActive) insert(items, TXFSQKEXAACTIVE);

	return(items);
};

set<uint> PnlWznmOpxDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTOPKACTIVE, BUTOPKVIEWAVAIL, BUTOPKVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmOpxDetail::Tag
 ******************************************************************************/

void PnlWznmOpxDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmOpxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmOpxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptOpk", "operation pack");
			writeStringAttr(wr, itemtag, "sref", "CptShd", "shared data");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
			writeStringAttr(wr, itemtag, "sref", "HdgSqk", "Squawk");
			writeStringAttr(wr, itemtag, "sref", "CptSqkTit", "text");
			writeStringAttr(wr, itemtag, "sref", "CptSqkExa", "example");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmOpxDetail::DpchAppData
 ******************************************************************************/

PnlWznmOpxDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPXDETAILDATA)
		{
};

string PnlWznmOpxDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpxDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmOpxDetailData");
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
 class PnlWznmOpxDetail::DpchAppDo
 ******************************************************************************/

PnlWznmOpxDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMOPXDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmOpxDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpxDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmOpxDetailDo");
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
 class PnlWznmOpxDetail::DpchEngData
 ******************************************************************************/

PnlWznmOpxDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupSqkJti
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMOPXDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPSQKJTI, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPSQKJTI) && feedFPupSqkJti) this->feedFPupSqkJti = *feedFPupSqkJti;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmOpxDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPSQKJTI)) ss.push_back("feedFPupSqkJti");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmOpxDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPSQKJTI)) {feedFPupSqkJti = src->feedFPupSqkJti; add(FEEDFPUPSQKJTI);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmOpxDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmOpxDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPSQKJTI)) feedFPupSqkJti.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};



