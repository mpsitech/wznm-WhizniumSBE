/**
	* \file PnlWznmSteDetail_blks.cpp
	* job handler for job PnlWznmSteDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSteDetail::VecVDo
 ******************************************************************************/

uint PnlWznmSteDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butseqviewclick") return BUTSEQVIEWCLICK;
	if (s == "buterjviewclick") return BUTERJVIEWCLICK;
	if (s == "buteveviewclick") return BUTEVEVIEWCLICK;
	if (s == "buteviviewclick") return BUTEVIVIEWCLICK;
	if (s == "butesnviewclick") return BUTESNVIEWCLICK;

	return(0);
};

string PnlWznmSteDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSEQVIEWCLICK) return("ButSeqViewClick");
	if (ix == BUTERJVIEWCLICK) return("ButErjViewClick");
	if (ix == BUTEVEVIEWCLICK) return("ButEveViewClick");
	if (ix == BUTEVIVIEWCLICK) return("ButEviViewClick");
	if (ix == BUTESNVIEWCLICK) return("ButEsnViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmSteDetail::ContIac
 ******************************************************************************/

PnlWznmSteDetail::ContIac::ContIac(
			const uint numFPupEac
			, const uint numFPupLac
			, const bool ChkCst
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupEac = numFPupEac;
	this->numFPupLac = numFPupLac;
	this->ChkCst = ChkCst;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPEAC, NUMFPUPLAC, CHKCST, TXFCMT};
};

bool PnlWznmSteDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmSteDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmSteDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupEac", numFPupEac)) add(NUMFPUPEAC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLac", numFPupLac)) add(NUMFPUPLAC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCst", ChkCst)) add(CHKCST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmSteDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmSteDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmSteDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupEac", numFPupEac);
		writeUintAttr(wr, itemtag, "sref", "numFPupLac", numFPupLac);
		writeBoolAttr(wr, itemtag, "sref", "ChkCst", ChkCst);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupEac == comp->numFPupEac) insert(items, NUMFPUPEAC);
	if (numFPupLac == comp->numFPupLac) insert(items, NUMFPUPLAC);
	if (ChkCst == comp->ChkCst) insert(items, CHKCST);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmSteDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPEAC, NUMFPUPLAC, CHKCST, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::ContInf
 ******************************************************************************/

PnlWznmSteDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtSeq
			, const string& TxtErj
			, const string& TxtEve
			, const string& TxtEvi
			, const string& TxtEsn
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtSeq = TxtSeq;
	this->TxtErj = TxtErj;
	this->TxtEve = TxtEve;
	this->TxtEvi = TxtEvi;
	this->TxtEsn = TxtEsn;

	mask = {TXTSRF, TXTSEQ, TXTERJ, TXTEVE, TXTEVI, TXTESN};
};

void PnlWznmSteDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmSteDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmSteDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtSeq", TxtSeq);
		writeStringAttr(wr, itemtag, "sref", "TxtErj", TxtErj);
		writeStringAttr(wr, itemtag, "sref", "TxtEve", TxtEve);
		writeStringAttr(wr, itemtag, "sref", "TxtEvi", TxtEvi);
		writeStringAttr(wr, itemtag, "sref", "TxtEsn", TxtEsn);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtSeq == comp->TxtSeq) insert(items, TXTSEQ);
	if (TxtErj == comp->TxtErj) insert(items, TXTERJ);
	if (TxtEve == comp->TxtEve) insert(items, TXTEVE);
	if (TxtEvi == comp->TxtEvi) insert(items, TXTEVI);
	if (TxtEsn == comp->TxtEsn) insert(items, TXTESN);

	return(items);
};

set<uint> PnlWznmSteDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTSEQ, TXTERJ, TXTEVE, TXTEVI, TXTESN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::StatApp
 ******************************************************************************/

void PnlWznmSteDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmSteDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmSteDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteDetail::StatShr
 ******************************************************************************/

PnlWznmSteDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtSeqActive
			, const bool ButSeqViewAvail
			, const bool ButSeqViewActive
			, const bool PupEacActive
			, const bool TxtErjActive
			, const bool ButErjViewAvail
			, const bool ButErjViewActive
			, const bool TxtEveActive
			, const bool ButEveViewAvail
			, const bool ButEveViewActive
			, const bool TxtEviActive
			, const bool ButEviViewAvail
			, const bool ButEviViewActive
			, const bool TxtEsnActive
			, const bool ButEsnViewAvail
			, const bool ButEsnViewActive
			, const bool PupLacActive
			, const bool ChkCstActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtSeqActive = TxtSeqActive;
	this->ButSeqViewAvail = ButSeqViewAvail;
	this->ButSeqViewActive = ButSeqViewActive;
	this->PupEacActive = PupEacActive;
	this->TxtErjActive = TxtErjActive;
	this->ButErjViewAvail = ButErjViewAvail;
	this->ButErjViewActive = ButErjViewActive;
	this->TxtEveActive = TxtEveActive;
	this->ButEveViewAvail = ButEveViewAvail;
	this->ButEveViewActive = ButEveViewActive;
	this->TxtEviActive = TxtEviActive;
	this->ButEviViewAvail = ButEviViewAvail;
	this->ButEviViewActive = ButEviViewActive;
	this->TxtEsnActive = TxtEsnActive;
	this->ButEsnViewAvail = ButEsnViewAvail;
	this->ButEsnViewActive = ButEsnViewActive;
	this->PupLacActive = PupLacActive;
	this->ChkCstActive = ChkCstActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, PUPEACACTIVE, TXTERJACTIVE, BUTERJVIEWAVAIL, BUTERJVIEWACTIVE, TXTEVEACTIVE, BUTEVEVIEWAVAIL, BUTEVEVIEWACTIVE, TXTEVIACTIVE, BUTEVIVIEWAVAIL, BUTEVIVIEWACTIVE, TXTESNACTIVE, BUTESNVIEWAVAIL, BUTESNVIEWACTIVE, PUPLACACTIVE, CHKCSTACTIVE, TXFCMTACTIVE};
};

void PnlWznmSteDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmSteDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmSteDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSeqActive", TxtSeqActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSeqViewAvail", ButSeqViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSeqViewActive", ButSeqViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupEacActive", PupEacActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtErjActive", TxtErjActive);
		writeBoolAttr(wr, itemtag, "sref", "ButErjViewAvail", ButErjViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButErjViewActive", ButErjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtEveActive", TxtEveActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEveViewAvail", ButEveViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEveViewActive", ButEveViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtEviActive", TxtEviActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEviViewAvail", ButEviViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEviViewActive", ButEviViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtEsnActive", TxtEsnActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEsnViewAvail", ButEsnViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEsnViewActive", ButEsnViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupLacActive", PupLacActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkCstActive", ChkCstActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtSeqActive == comp->TxtSeqActive) insert(items, TXTSEQACTIVE);
	if (ButSeqViewAvail == comp->ButSeqViewAvail) insert(items, BUTSEQVIEWAVAIL);
	if (ButSeqViewActive == comp->ButSeqViewActive) insert(items, BUTSEQVIEWACTIVE);
	if (PupEacActive == comp->PupEacActive) insert(items, PUPEACACTIVE);
	if (TxtErjActive == comp->TxtErjActive) insert(items, TXTERJACTIVE);
	if (ButErjViewAvail == comp->ButErjViewAvail) insert(items, BUTERJVIEWAVAIL);
	if (ButErjViewActive == comp->ButErjViewActive) insert(items, BUTERJVIEWACTIVE);
	if (TxtEveActive == comp->TxtEveActive) insert(items, TXTEVEACTIVE);
	if (ButEveViewAvail == comp->ButEveViewAvail) insert(items, BUTEVEVIEWAVAIL);
	if (ButEveViewActive == comp->ButEveViewActive) insert(items, BUTEVEVIEWACTIVE);
	if (TxtEviActive == comp->TxtEviActive) insert(items, TXTEVIACTIVE);
	if (ButEviViewAvail == comp->ButEviViewAvail) insert(items, BUTEVIVIEWAVAIL);
	if (ButEviViewActive == comp->ButEviViewActive) insert(items, BUTEVIVIEWACTIVE);
	if (TxtEsnActive == comp->TxtEsnActive) insert(items, TXTESNACTIVE);
	if (ButEsnViewAvail == comp->ButEsnViewAvail) insert(items, BUTESNVIEWAVAIL);
	if (ButEsnViewActive == comp->ButEsnViewActive) insert(items, BUTESNVIEWACTIVE);
	if (PupLacActive == comp->PupLacActive) insert(items, PUPLACACTIVE);
	if (ChkCstActive == comp->ChkCstActive) insert(items, CHKCSTACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmSteDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, PUPEACACTIVE, TXTERJACTIVE, BUTERJVIEWAVAIL, BUTERJVIEWACTIVE, TXTEVEACTIVE, BUTEVEVIEWAVAIL, BUTEVEVIEWACTIVE, TXTEVIACTIVE, BUTEVIVIEWAVAIL, BUTEVIVIEWACTIVE, TXTESNACTIVE, BUTESNVIEWAVAIL, BUTESNVIEWACTIVE, PUPLACACTIVE, CHKCSTACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::Tag
 ******************************************************************************/

void PnlWznmSteDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmSteDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmSteDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSeq", "sequence");
			writeStringAttr(wr, itemtag, "sref", "CptEac", "action when entering");
			writeStringAttr(wr, itemtag, "sref", "CptErj", "run-time job for enter action");
			writeStringAttr(wr, itemtag, "sref", "CptEve", "do vector for enter action");
			writeStringAttr(wr, itemtag, "sref", "CptEvi", "do vector item for enter action");
			writeStringAttr(wr, itemtag, "sref", "CptEsn", "state to step to for enter action");
			writeStringAttr(wr, itemtag, "sref", "CptLac", "action when leaving");
			writeStringAttr(wr, itemtag, "sref", "CptCst", "Custstep");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteDetail::DpchAppData
 ******************************************************************************/

PnlWznmSteDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEDETAILDATA)
		{
};

string PnlWznmSteDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSteDetailData");
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
 class PnlWznmSteDetail::DpchAppDo
 ******************************************************************************/

PnlWznmSteDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmSteDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSteDetailDo");
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
 class PnlWznmSteDetail::DpchEngData
 ******************************************************************************/

PnlWznmSteDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupEac
			, Feed* feedFPupLac
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTEDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPEAC, FEEDFPUPLAC, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPEAC) && feedFPupEac) this->feedFPupEac = *feedFPupEac;
	if (find(this->mask, FEEDFPUPLAC) && feedFPupLac) this->feedFPupLac = *feedFPupLac;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmSteDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPEAC)) ss.push_back("feedFPupEac");
	if (has(FEEDFPUPLAC)) ss.push_back("feedFPupLac");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPEAC)) {feedFPupEac = src->feedFPupEac; add(FEEDFPUPEAC);};
	if (src->has(FEEDFPUPLAC)) {feedFPupLac = src->feedFPupLac; add(FEEDFPUPLAC);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmSteDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmSteDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPEAC)) feedFPupEac.writeXML(wr);
		if (has(FEEDFPUPLAC)) feedFPupLac.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

