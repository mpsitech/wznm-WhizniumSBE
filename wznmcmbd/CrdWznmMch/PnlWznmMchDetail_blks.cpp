/**
	* \file PnlWznmMchDetail_blks.cpp
	* job handler for job PnlWznmMchDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmMchDetail::VecVDo
 ******************************************************************************/

uint PnlWznmMchDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butcchviewclick") return BUTCCHVIEWCLICK;
	if (s == "butpkmeditclick") return BUTPKMEDITCLICK;

	return(0);
};

string PnlWznmMchDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTCCHVIEWCLICK) return("ButCchViewClick");
	if (ix == BUTPKMEDITCLICK) return("ButPkmEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmMchDetail::ContIac
 ******************************************************************************/

PnlWznmMchDetail::ContIac::ContIac(
			const uint numFPupPkm
			, const string& TxfPkm
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupPkm = numFPupPkm;
	this->TxfPkm = TxfPkm;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPPKM, TXFPKM, TXFCMT};
};

bool PnlWznmMchDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWznmMchDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupPkm")) {numFPupPkm = me["numFPupPkm"].asUInt(); add(NUMFPUPPKM);};
		if (me.isMember("TxfPkm")) {TxfPkm = me["TxfPkm"].asString(); add(TXFPKM);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWznmMchDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmMchDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmMchDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPkm", numFPupPkm)) add(NUMFPUPPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPkm", TxfPkm)) add(TXFPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmMchDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmMchDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupPkm"] = numFPupPkm;
	me["TxfPkm"] = TxfPkm;
	me["TxfCmt"] = TxfCmt;
};

void PnlWznmMchDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmMchDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmMchDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupPkm", numFPupPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfPkm", TxfPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMchDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupPkm == comp->numFPupPkm) insert(items, NUMFPUPPKM);
	if (TxfPkm == comp->TxfPkm) insert(items, TXFPKM);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmMchDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPPKM, TXFPKM, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchDetail::ContInf
 ******************************************************************************/

PnlWznmMchDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtSup
			, const string& TxtCch
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtSup = TxtSup;
	this->TxtCch = TxtCch;

	mask = {TXTSRF, TXTSUP, TXTCCH};
};

void PnlWznmMchDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmMchDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtSup"] = TxtSup;
	me["TxtCch"] = TxtCch;
};

void PnlWznmMchDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmMchDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmMchDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtCch", TxtCch);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMchDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtCch == comp->TxtCch) insert(items, TXTCCH);

	return(items);
};

set<uint> PnlWznmMchDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTSUP, TXTCCH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchDetail::StatApp
 ******************************************************************************/

void PnlWznmMchDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool PupPkmAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmMchDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["PupPkmAlt"] = PupPkmAlt;
};

void PnlWznmMchDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool PupPkmAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmMchDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmMchDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupPkmAlt", PupPkmAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMchDetail::StatShr
 ******************************************************************************/

PnlWznmMchDetail::StatShr::StatShr(
			const bool TxfPkmValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtCchActive
			, const bool ButCchViewAvail
			, const bool ButCchViewActive
			, const bool PupPkmActive
			, const bool ButPkmEditAvail
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfPkmValid = TxfPkmValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxtCchActive = TxtCchActive;
	this->ButCchViewAvail = ButCchViewAvail;
	this->ButCchViewActive = ButCchViewActive;
	this->PupPkmActive = PupPkmActive;
	this->ButPkmEditAvail = ButPkmEditAvail;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE};
};

void PnlWznmMchDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmMchDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfPkmValid"] = TxfPkmValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxtSupActive"] = TxtSupActive;
	me["ButSupViewAvail"] = ButSupViewAvail;
	me["ButSupViewActive"] = ButSupViewActive;
	me["TxtCchActive"] = TxtCchActive;
	me["ButCchViewAvail"] = ButCchViewAvail;
	me["ButCchViewActive"] = ButCchViewActive;
	me["PupPkmActive"] = PupPkmActive;
	me["ButPkmEditAvail"] = ButPkmEditAvail;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWznmMchDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmMchDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmMchDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfPkmValid", TxfPkmValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCchActive", TxtCchActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCchViewAvail", ButCchViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCchViewActive", ButCchViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupPkmActive", PupPkmActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPkmEditAvail", ButPkmEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMchDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfPkmValid == comp->TxfPkmValid) insert(items, TXFPKMVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtCchActive == comp->TxtCchActive) insert(items, TXTCCHACTIVE);
	if (ButCchViewAvail == comp->ButCchViewAvail) insert(items, BUTCCHVIEWAVAIL);
	if (ButCchViewActive == comp->ButCchViewActive) insert(items, BUTCCHVIEWACTIVE);
	if (PupPkmActive == comp->PupPkmActive) insert(items, PUPPKMACTIVE);
	if (ButPkmEditAvail == comp->ButPkmEditAvail) insert(items, BUTPKMEDITAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmMchDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMchDetail::Tag
 ******************************************************************************/

void PnlWznmMchDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmMchDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptSup"] = "base machine";
		me["CptCch"] = "cross-compile host";
		me["CptPkm"] = "package manager";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmMchDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmMchDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmMchDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "base machine");
			writeStringAttr(wr, itemtag, "sref", "CptCch", "cross-compile host");
			writeStringAttr(wr, itemtag, "sref", "CptPkm", "package manager");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMchDetail::DpchAppData
 ******************************************************************************/

PnlWznmMchDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMCHDETAILDATA)
		{
};

string PnlWznmMchDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMchDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmMchDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmMchDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmMchDetailData");
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
 class PnlWznmMchDetail::DpchAppDo
 ******************************************************************************/

PnlWznmMchDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMCHDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmMchDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMchDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmMchDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmMchDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmMchDetailDo");
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
 class PnlWznmMchDetail::DpchEngData
 ******************************************************************************/

PnlWznmMchDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupPkm
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMMCHDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPPKM, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPPKM) && feedFPupPkm) this->feedFPupPkm = *feedFPupPkm;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmMchDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPPKM)) ss.push_back("feedFPupPkm");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMchDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPPKM)) {feedFPupPkm = src->feedFPupPkm; add(FEEDFPUPPKM);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmMchDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmMchDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPPKM)) feedFPupPkm.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmMchDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmMchDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPPKM)) feedFPupPkm.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
