/**
	* \file PnlWznmSteDetail_blks.cpp
	* job handler for job PnlWznmSteDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

	return(0);
};

string PnlWznmSteDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSEQVIEWCLICK) return("ButSeqViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmSteDetail::ContIac
 ******************************************************************************/

PnlWznmSteDetail::ContIac::ContIac(
			const string& TxfCmt
		) :
			Block()
		{
	this->TxfCmt = TxfCmt;

	mask = {TXFCMT};
};

bool PnlWznmSteDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmSteDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
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
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmSteDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmSteDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfCmt"] = TxfCmt;
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
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmSteDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::ContInf
 ******************************************************************************/

PnlWznmSteDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtSeq
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtSeq = TxtSeq;

	mask = {TXTSRF, TXTSEQ};
};

void PnlWznmSteDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmSteDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtSeq"] = TxtSeq;
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
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtSeq == comp->TxtSeq) insert(items, TXTSEQ);

	return(items);
};

set<uint> PnlWznmSteDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTSEQ};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::StatApp
 ******************************************************************************/

void PnlWznmSteDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmSteDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
};

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
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, TXFCMTACTIVE};
};

void PnlWznmSteDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmSteDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxtSeqActive"] = TxtSeqActive;
	me["ButSeqViewAvail"] = ButSeqViewAvail;
	me["ButSeqViewActive"] = ButSeqViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
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
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmSteDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteDetail::Tag
 ******************************************************************************/

void PnlWznmSteDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmSteDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptSeq"] = "sequence";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

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

void PnlWznmSteDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmSteDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
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

void PnlWznmSteDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmSteDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
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
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTEDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmSteDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
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
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmSteDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmSteDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
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
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
