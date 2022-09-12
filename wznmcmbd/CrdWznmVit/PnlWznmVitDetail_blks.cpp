/**
	* \file PnlWznmVitDetail_blks.cpp
	* job handler for job PnlWznmVitDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVitDetail::VecVDo
 ******************************************************************************/

uint PnlWznmVitDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjeditclick") return BUTJEDITCLICK;
	if (s == "butvecviewclick") return BUTVECVIEWCLICK;

	return(0);
};

string PnlWznmVitDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJEDITCLICK) return("ButJEditClick");
	if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmVitDetail::ContIac
 ******************************************************************************/

PnlWznmVitDetail::ContIac::ContIac(
			const uint numFPupJ
			, const string& TxfAvl
			, const string& TxfImp
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupJ = numFPupJ;
	this->TxfAvl = TxfAvl;
	this->TxfImp = TxfImp;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPJ, TXFAVL, TXFIMP, TXFCMT};
};

bool PnlWznmVitDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmVitDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupJ")) {numFPupJ = me["numFPupJ"].asUInt(); add(NUMFPUPJ);};
		if (me.isMember("TxfAvl")) {TxfAvl = me["TxfAvl"].asString(); add(TXFAVL);};
		if (me.isMember("TxfImp")) {TxfImp = me["TxfImp"].asString(); add(TXFIMP);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWznmVitDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmVitDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmVitDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAvl", TxfAvl)) add(TXFAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfImp", TxfImp)) add(TXFIMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmVitDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmVitDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupJ"] = numFPupJ;
	me["TxfAvl"] = TxfAvl;
	me["TxfImp"] = TxfImp;
	me["TxfCmt"] = TxfCmt;
};

void PnlWznmVitDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmVitDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmVitDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeStringAttr(wr, itemtag, "sref", "TxfAvl", TxfAvl);
		writeStringAttr(wr, itemtag, "sref", "TxfImp", TxfImp);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVitDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (TxfAvl == comp->TxfAvl) insert(items, TXFAVL);
	if (TxfImp == comp->TxfImp) insert(items, TXFIMP);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmVitDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJ, TXFAVL, TXFIMP, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVitDetail::ContInf
 ******************************************************************************/

PnlWznmVitDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtVec
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtVec = TxtVec;

	mask = {TXTSRF, TXTTIT, TXTVEC};
};

void PnlWznmVitDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVitDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtTit"] = TxtTit;
	me["TxtVec"] = TxtVec;
};

void PnlWznmVitDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVitDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmVitDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTit", TxtTit);
		writeStringAttr(wr, itemtag, "sref", "TxtVec", TxtVec);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVitDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtVec == comp->TxtVec) insert(items, TXTVEC);

	return(items);
};

set<uint> PnlWznmVitDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTVEC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVitDetail::StatApp
 ******************************************************************************/

void PnlWznmVitDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVitDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
};

void PnlWznmVitDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVitDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmVitDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVitDetail::StatShr
 ******************************************************************************/

PnlWznmVitDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJActive
			, const bool ButJEditAvail
			, const bool TxtTitActive
			, const bool TxtVecActive
			, const bool ButVecViewAvail
			, const bool ButVecViewActive
			, const bool TxfAvlActive
			, const bool TxfImpActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupJActive = PupJActive;
	this->ButJEditAvail = ButJEditAvail;
	this->TxtTitActive = TxtTitActive;
	this->TxtVecActive = TxtVecActive;
	this->ButVecViewAvail = ButVecViewAvail;
	this->ButVecViewActive = ButVecViewActive;
	this->TxfAvlActive = TxfAvlActive;
	this->TxfImpActive = TxfImpActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTTITACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, TXFAVLACTIVE, TXFIMPACTIVE, TXFCMTACTIVE};
};

void PnlWznmVitDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVitDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["PupJActive"] = PupJActive;
	me["ButJEditAvail"] = ButJEditAvail;
	me["TxtTitActive"] = TxtTitActive;
	me["TxtVecActive"] = TxtVecActive;
	me["ButVecViewAvail"] = ButVecViewAvail;
	me["ButVecViewActive"] = ButVecViewActive;
	me["TxfAvlActive"] = TxfAvlActive;
	me["TxfImpActive"] = TxfImpActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWznmVitDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVitDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmVitDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJActive", PupJActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtTitActive", TxtTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtVecActive", TxtVecActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVecViewAvail", ButVecViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVecViewActive", ButVecViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAvlActive", TxfAvlActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfImpActive", TxfImpActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVitDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJActive == comp->PupJActive) insert(items, PUPJACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (TxtVecActive == comp->TxtVecActive) insert(items, TXTVECACTIVE);
	if (ButVecViewAvail == comp->ButVecViewAvail) insert(items, BUTVECVIEWAVAIL);
	if (ButVecViewActive == comp->ButVecViewActive) insert(items, BUTVECVIEWACTIVE);
	if (TxfAvlActive == comp->TxfAvlActive) insert(items, TXFAVLACTIVE);
	if (TxfImpActive == comp->TxfImpActive) insert(items, TXFIMPACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmVitDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTTITACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, TXFAVLACTIVE, TXFIMPACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVitDetail::Tag
 ******************************************************************************/

void PnlWznmVitDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmVitDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptTit"] = "name";
		me["CptVec"] = "vector";
		me["CptAvl"] = "availability rule";
		me["CptImp"] = "rule for implied";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmVitDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmVitDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmVitDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptVec", "vector");
			writeStringAttr(wr, itemtag, "sref", "CptAvl", "availability rule");
			writeStringAttr(wr, itemtag, "sref", "CptImp", "rule for implied");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVitDetail::DpchAppData
 ******************************************************************************/

PnlWznmVitDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVITDETAILDATA)
		{
};

string PnlWznmVitDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVitDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmVitDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmVitDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVitDetailData");
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
 class PnlWznmVitDetail::DpchAppDo
 ******************************************************************************/

PnlWznmVitDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVITDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmVitDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVitDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmVitDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmVitDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVitDetailDo");
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
 class PnlWznmVitDetail::DpchEngData
 ******************************************************************************/

PnlWznmVitDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupJ
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVITDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPJ, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmVitDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVitDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPJ)) {feedFPupJ = src->feedFPupJ; add(FEEDFPUPJ);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmVitDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmVitDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPJ)) feedFPupJ.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmVitDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmVitDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPJ)) feedFPupJ.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
