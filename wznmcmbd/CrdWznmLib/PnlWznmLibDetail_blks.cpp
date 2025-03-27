/**
	* \file PnlWznmLibDetail_blks.cpp
	* job handler for job PnlWznmLibDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmLibDetail::VecVDo
 ******************************************************************************/

uint PnlWznmLibDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butltyeditclick") return BUTLTYEDITCLICK;
	if (s == "butdepviewclick") return BUTDEPVIEWCLICK;

	return(0);
};

string PnlWznmLibDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTLTYEDITCLICK) return("ButLtyEditClick");
	if (ix == BUTDEPVIEWCLICK) return("ButDepViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmLibDetail::ContIac
 ******************************************************************************/

PnlWznmLibDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfVer
			, const uint numFPupLty
			, const string& TxfLty
			, const uint numFLstDep
			, const string& TxfDep
			, const string& TxfCmt
		) :
			Block()
			, TxfTit(TxfTit)
			, TxfVer(TxfVer)
			, numFPupLty(numFPupLty)
			, TxfLty(TxfLty)
			, numFLstDep(numFLstDep)
			, TxfDep(TxfDep)
			, TxfCmt(TxfCmt)
		{
	mask = {TXFTIT, TXFVER, NUMFPUPLTY, TXFLTY, NUMFLSTDEP, TXFDEP, TXFCMT};
};

bool PnlWznmLibDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmLibDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfTit")) {TxfTit = me["TxfTit"].asString(); add(TXFTIT);};
		if (me.isMember("TxfVer")) {TxfVer = me["TxfVer"].asString(); add(TXFVER);};
		if (me.isMember("numFPupLty")) {numFPupLty = me["numFPupLty"].asUInt(); add(NUMFPUPLTY);};
		if (me.isMember("TxfLty")) {TxfLty = me["TxfLty"].asString(); add(TXFLTY);};
		if (me.isMember("numFLstDep")) {numFLstDep = me["numFLstDep"].asUInt(); add(NUMFLSTDEP);};
		if (me.isMember("TxfDep")) {TxfDep = me["TxfDep"].asString(); add(TXFDEP);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWznmLibDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmLibDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmLibDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfVer", TxfVer)) add(TXFVER);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupLty", numFPupLty)) add(NUMFPUPLTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfLty", TxfLty)) add(TXFLTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDep", numFLstDep)) add(NUMFLSTDEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDep", TxfDep)) add(TXFDEP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmLibDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmLibDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfTit"] = TxfTit;
	me["TxfVer"] = TxfVer;
	me["numFPupLty"] = (Json::Value::UInt) numFPupLty;
	me["TxfLty"] = TxfLty;
	me["numFLstDep"] = (Json::Value::UInt) numFLstDep;
	me["TxfDep"] = TxfDep;
	me["TxfCmt"] = TxfCmt;
};

void PnlWznmLibDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmLibDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmLibDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfVer", TxfVer);
		writeUintAttr(wr, itemtag, "sref", "numFPupLty", numFPupLty);
		writeStringAttr(wr, itemtag, "sref", "TxfLty", TxfLty);
		writeUintAttr(wr, itemtag, "sref", "numFLstDep", numFLstDep);
		writeStringAttr(wr, itemtag, "sref", "TxfDep", TxfDep);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmLibDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfVer == comp->TxfVer) insert(items, TXFVER);
	if (numFPupLty == comp->numFPupLty) insert(items, NUMFPUPLTY);
	if (TxfLty == comp->TxfLty) insert(items, TXFLTY);
	if (numFLstDep == comp->numFLstDep) insert(items, NUMFLSTDEP);
	if (TxfDep == comp->TxfDep) insert(items, TXFDEP);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmLibDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFVER, NUMFPUPLTY, TXFLTY, NUMFLSTDEP, TXFDEP, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibDetail::ContInf
 ******************************************************************************/

PnlWznmLibDetail::ContInf::ContInf(
			const string& TxtSrf
		) :
			Block()
			, TxtSrf(TxtSrf)
		{
	mask = {TXTSRF};
};

void PnlWznmLibDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmLibDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
};

void PnlWznmLibDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmLibDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmLibDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmLibDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);

	return(items);
};

set<uint> PnlWznmLibDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibDetail::StatApp
 ******************************************************************************/

void PnlWznmLibDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool PupLtyAlt
			, const bool LstDepAlt
			, const uint LstDepNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmLibDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["PupLtyAlt"] = PupLtyAlt;
	me["LstDepAlt"] = LstDepAlt;
	me["LstDepNumFirstdisp"] = (Json::Value::UInt) LstDepNumFirstdisp;
};

void PnlWznmLibDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool PupLtyAlt
			, const bool LstDepAlt
			, const uint LstDepNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmLibDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmLibDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupLtyAlt", PupLtyAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstDepAlt", LstDepAlt);
		writeUintAttr(wr, itemtag, "sref", "LstDepNumFirstdisp", LstDepNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmLibDetail::StatShr
 ******************************************************************************/

PnlWznmLibDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfTitActive
			, const bool TxfVerActive
			, const bool PupLtyActive
			, const bool TxfLtyValid
			, const bool ButLtyEditAvail
			, const bool LstDepActive
			, const bool TxfDepValid
			, const bool ButDepViewAvail
			, const bool ButDepViewActive
			, const bool TxfCmtActive
		) :
			Block()
			, ButSaveAvail(ButSaveAvail)
			, ButSaveActive(ButSaveActive)
			, TxtSrfActive(TxtSrfActive)
			, TxfTitActive(TxfTitActive)
			, TxfVerActive(TxfVerActive)
			, PupLtyActive(PupLtyActive)
			, TxfLtyValid(TxfLtyValid)
			, ButLtyEditAvail(ButLtyEditAvail)
			, LstDepActive(LstDepActive)
			, TxfDepValid(TxfDepValid)
			, ButDepViewAvail(ButDepViewAvail)
			, ButDepViewActive(ButDepViewActive)
			, TxfCmtActive(TxfCmtActive)
		{
	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFVERACTIVE, PUPLTYACTIVE, TXFLTYVALID, BUTLTYEDITAVAIL, LSTDEPACTIVE, TXFDEPVALID, BUTDEPVIEWAVAIL, BUTDEPVIEWACTIVE, TXFCMTACTIVE};
};

void PnlWznmLibDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmLibDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxfTitActive"] = TxfTitActive;
	me["TxfVerActive"] = TxfVerActive;
	me["PupLtyActive"] = PupLtyActive;
	me["TxfLtyValid"] = TxfLtyValid;
	me["ButLtyEditAvail"] = ButLtyEditAvail;
	me["LstDepActive"] = LstDepActive;
	me["TxfDepValid"] = TxfDepValid;
	me["ButDepViewAvail"] = ButDepViewAvail;
	me["ButDepViewActive"] = ButDepViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWznmLibDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmLibDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmLibDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfVerActive", TxfVerActive);
		writeBoolAttr(wr, itemtag, "sref", "PupLtyActive", PupLtyActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfLtyValid", TxfLtyValid);
		writeBoolAttr(wr, itemtag, "sref", "ButLtyEditAvail", ButLtyEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "LstDepActive", LstDepActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDepValid", TxfDepValid);
		writeBoolAttr(wr, itemtag, "sref", "ButDepViewAvail", ButDepViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDepViewActive", ButDepViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmLibDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfVerActive == comp->TxfVerActive) insert(items, TXFVERACTIVE);
	if (PupLtyActive == comp->PupLtyActive) insert(items, PUPLTYACTIVE);
	if (TxfLtyValid == comp->TxfLtyValid) insert(items, TXFLTYVALID);
	if (ButLtyEditAvail == comp->ButLtyEditAvail) insert(items, BUTLTYEDITAVAIL);
	if (LstDepActive == comp->LstDepActive) insert(items, LSTDEPACTIVE);
	if (TxfDepValid == comp->TxfDepValid) insert(items, TXFDEPVALID);
	if (ButDepViewAvail == comp->ButDepViewAvail) insert(items, BUTDEPVIEWAVAIL);
	if (ButDepViewActive == comp->ButDepViewActive) insert(items, BUTDEPVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmLibDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFVERACTIVE, PUPLTYACTIVE, TXFLTYVALID, BUTLTYEDITAVAIL, LSTDEPACTIVE, TXFDEPVALID, BUTDEPVIEWAVAIL, BUTDEPVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmLibDetail::Tag
 ******************************************************************************/

void PnlWznmLibDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmLibDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptTit"] = "name";
		me["CptVer"] = "version";
		me["CptLty"] = "license type";
		me["CptDep"] = "libraries dependent on";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmLibDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmLibDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmLibDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "version");
			writeStringAttr(wr, itemtag, "sref", "CptLty", "license type");
			writeStringAttr(wr, itemtag, "sref", "CptDep", "libraries dependent on");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmLibDetail::DpchAppData
 ******************************************************************************/

PnlWznmLibDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMLIBDETAILDATA)
		{
};

string PnlWznmLibDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmLibDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmLibDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmLibDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmLibDetailData");
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
 class PnlWznmLibDetail::DpchAppDo
 ******************************************************************************/

PnlWznmLibDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMLIBDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmLibDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmLibDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmLibDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmLibDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmLibDetailDo");
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
 class PnlWznmLibDetail::DpchEngData
 ******************************************************************************/

PnlWznmLibDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstDep
			, Feed* feedFPupLty
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMLIBDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTDEP, FEEDFPUPLTY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTDEP) && feedFLstDep) this->feedFLstDep = *feedFLstDep;
	if (find(this->mask, FEEDFPUPLTY) && feedFPupLty) this->feedFPupLty = *feedFPupLty;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmLibDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDEP)) ss.push_back("feedFLstDep");
	if (has(FEEDFPUPLTY)) ss.push_back("feedFPupLty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmLibDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTDEP)) {feedFLstDep = src->feedFLstDep; add(FEEDFLSTDEP);};
	if (src->has(FEEDFPUPLTY)) {feedFPupLty = src->feedFPupLty; add(FEEDFPUPLTY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmLibDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmLibDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTDEP)) feedFLstDep.writeJSON(me);
	if (has(FEEDFPUPLTY)) feedFPupLty.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmLibDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmLibDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTDEP)) feedFLstDep.writeXML(wr);
		if (has(FEEDFPUPLTY)) feedFPupLty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
