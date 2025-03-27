/**
	* \file PnlWznmBoxDetail_blks.cpp
	* job handler for job PnlWznmBoxDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmBoxDetail::VecVDo
 ******************************************************************************/

uint PnlWznmBoxDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butshtviewclick") return BUTSHTVIEWCLICK;

	return(0);
};

string PnlWznmBoxDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmBoxDetail::ContIac
 ******************************************************************************/

PnlWznmBoxDetail::ContIac::ContIac(
			const uint numFPupY
			, const string& TxfX
			, const string& TxfY
		) :
			Block()
			, numFPupY(numFPupY)
			, TxfX(TxfX)
			, TxfY(TxfY)
		{
	mask = {NUMFPUPY, TXFX, TXFY};
};

bool PnlWznmBoxDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmBoxDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupY")) {numFPupY = me["numFPupY"].asUInt(); add(NUMFPUPY);};
		if (me.isMember("TxfX")) {TxfX = me["TxfX"].asString(); add(TXFX);};
		if (me.isMember("TxfY")) {TxfY = me["TxfY"].asString(); add(TXFY);};
	};

	return basefound;
};

bool PnlWznmBoxDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmBoxDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmBoxDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupY", numFPupY)) add(NUMFPUPY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfX", TxfX)) add(TXFX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfY", TxfY)) add(TXFY);
	};

	return basefound;
};

void PnlWznmBoxDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmBoxDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupY"] = (Json::Value::UInt) numFPupY;
	me["TxfX"] = TxfX;
	me["TxfY"] = TxfY;
};

void PnlWznmBoxDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmBoxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmBoxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupY", numFPupY);
		writeStringAttr(wr, itemtag, "sref", "TxfX", TxfX);
		writeStringAttr(wr, itemtag, "sref", "TxfY", TxfY);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmBoxDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupY == comp->numFPupY) insert(items, NUMFPUPY);
	if (TxfX == comp->TxfX) insert(items, TXFX);
	if (TxfY == comp->TxfY) insert(items, TXFY);

	return(items);
};

set<uint> PnlWznmBoxDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPY, TXFX, TXFY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmBoxDetail::ContInf
 ******************************************************************************/

PnlWznmBoxDetail::ContInf::ContInf(
			const string& TxtSht
			, const string& TxtUnv
		) :
			Block()
			, TxtSht(TxtSht)
			, TxtUnv(TxtUnv)
		{
	mask = {TXTSHT, TXTUNV};
};

void PnlWznmBoxDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmBoxDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSht"] = TxtSht;
	me["TxtUnv"] = TxtUnv;
};

void PnlWznmBoxDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmBoxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmBoxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSht", TxtSht);
		writeStringAttr(wr, itemtag, "sref", "TxtUnv", TxtUnv);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmBoxDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSht == comp->TxtSht) insert(items, TXTSHT);
	if (TxtUnv == comp->TxtUnv) insert(items, TXTUNV);

	return(items);
};

set<uint> PnlWznmBoxDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSHT, TXTUNV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmBoxDetail::StatApp
 ******************************************************************************/

void PnlWznmBoxDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmBoxDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
};

void PnlWznmBoxDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmBoxDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmBoxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmBoxDetail::StatShr
 ******************************************************************************/

PnlWznmBoxDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtShtActive
			, const bool ButShtViewAvail
			, const bool ButShtViewActive
			, const bool TxtUnvActive
			, const bool TxfXActive
			, const bool TxfYActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtShtActive(TxtShtActive)
			, ButShtViewAvail(ButShtViewAvail)
			, ButShtViewActive(ButShtViewActive)
			, TxtUnvActive(TxtUnvActive)
			, TxfXActive(TxfXActive)
			, TxfYActive(TxfYActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSHTACTIVE, BUTSHTVIEWAVAIL, BUTSHTVIEWACTIVE, TXTUNVACTIVE, TXFXACTIVE, TXFYACTIVE};
};

void PnlWznmBoxDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmBoxDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtShtActive"] = TxtShtActive;
	me["ButShtViewAvail"] = ButShtViewAvail;
	me["ButShtViewActive"] = ButShtViewActive;
	me["TxtUnvActive"] = TxtUnvActive;
	me["TxfXActive"] = TxfXActive;
	me["TxfYActive"] = TxfYActive;
};

void PnlWznmBoxDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmBoxDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmBoxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtShtActive", TxtShtActive);
		writeBoolAttr(wr, itemtag, "sref", "ButShtViewAvail", ButShtViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButShtViewActive", ButShtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtUnvActive", TxtUnvActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXActive", TxfXActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfYActive", TxfYActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmBoxDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtShtActive == comp->TxtShtActive) insert(items, TXTSHTACTIVE);
	if (ButShtViewAvail == comp->ButShtViewAvail) insert(items, BUTSHTVIEWAVAIL);
	if (ButShtViewActive == comp->ButShtViewActive) insert(items, BUTSHTVIEWACTIVE);
	if (TxtUnvActive == comp->TxtUnvActive) insert(items, TXTUNVACTIVE);
	if (TxfXActive == comp->TxfXActive) insert(items, TXFXACTIVE);
	if (TxfYActive == comp->TxfYActive) insert(items, TXFYACTIVE);

	return(items);
};

set<uint> PnlWznmBoxDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSHTACTIVE, BUTSHTVIEWAVAIL, BUTSHTVIEWACTIVE, TXTUNVACTIVE, TXFXACTIVE, TXFYACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmBoxDetail::Tag
 ******************************************************************************/

void PnlWznmBoxDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmBoxDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSht"] = "sheet";
		me["CptUnv"] = "unvUref";
		me["CptX"] = "x";
		me["CptY"] = "y";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmBoxDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmBoxDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmBoxDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSht", "sheet");
			writeStringAttr(wr, itemtag, "sref", "CptUnv", "unvUref");
			writeStringAttr(wr, itemtag, "sref", "CptX", "x");
			writeStringAttr(wr, itemtag, "sref", "CptY", "y");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmBoxDetail::DpchAppData
 ******************************************************************************/

PnlWznmBoxDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMBOXDETAILDATA)
		{
};

string PnlWznmBoxDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmBoxDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmBoxDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmBoxDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmBoxDetailData");
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
 class PnlWznmBoxDetail::DpchAppDo
 ******************************************************************************/

PnlWznmBoxDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMBOXDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmBoxDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmBoxDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmBoxDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmBoxDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmBoxDetailDo");
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
 class PnlWznmBoxDetail::DpchEngData
 ******************************************************************************/

PnlWznmBoxDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupY
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMBOXDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPY) && feedFPupY) this->feedFPupY = *feedFPupY;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmBoxDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPY)) ss.push_back("feedFPupY");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmBoxDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPY)) {feedFPupY = src->feedFPupY; add(FEEDFPUPY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmBoxDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmBoxDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPY)) feedFPupY.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmBoxDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmBoxDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPY)) feedFPupY.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
