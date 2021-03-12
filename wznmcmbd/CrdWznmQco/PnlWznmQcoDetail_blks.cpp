/**
	* \file PnlWznmQcoDetail_blks.cpp
	* job handler for job PnlWznmQcoDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmQcoDetail::VecVDo
 ******************************************************************************/

uint PnlWznmQcoDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butqryviewclick") return BUTQRYVIEWCLICK;
	if (s == "butstbviewclick") return BUTSTBVIEWCLICK;

	return(0);
};

string PnlWznmQcoDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTQRYVIEWCLICK) return("ButQryViewClick");
	if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmQcoDetail::ContIac
 ******************************************************************************/

PnlWznmQcoDetail::ContIac::ContIac(
			const string& TxfSho
			, const uint numFPupTyp
			, const vector<uint>& numsFLstOcc
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->numFPupTyp = numFPupTyp;
	this->numsFLstOcc = numsFLstOcc;

	mask = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC};
};

bool PnlWznmQcoDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWznmQcoDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfSho")) {TxfSho = me["TxfSho"].asString(); add(TXFSHO);};
		if (me.isMember("numFPupTyp")) {numFPupTyp = me["numFPupTyp"].asUInt(); add(NUMFPUPTYP);};
		if (Jsonio::extractUintvec(me, "numsFLstOcc", numsFLstOcc)) add(NUMSFLSTOCC);
	};

	return basefound;
};

bool PnlWznmQcoDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmQcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmQcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOcc", numsFLstOcc)) add(NUMSFLSTOCC);
	};

	return basefound;
};

void PnlWznmQcoDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmQcoDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfSho"] = TxfSho;
	me["numFPupTyp"] = numFPupTyp;
	Jsonio::writeUintvec(me, "numsFLstOcc", numsFLstOcc);
};

void PnlWznmQcoDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmQcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmQcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOcc", numsFLstOcc);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQcoDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (compareUintvec(numsFLstOcc, comp->numsFLstOcc)) insert(items, NUMSFLSTOCC);

	return(items);
};

set<uint> PnlWznmQcoDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQcoDetail::ContInf
 ******************************************************************************/

PnlWznmQcoDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtOcc
			, const string& TxtQry
			, const string& TxtTco
			, const string& TxtStb
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtOcc = TxtOcc;
	this->TxtQry = TxtQry;
	this->TxtTco = TxtTco;
	this->TxtStb = TxtStb;

	mask = {TXTSRF, TXTOCC, TXTQRY, TXTTCO, TXTSTB};
};

void PnlWznmQcoDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmQcoDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtOcc"] = TxtOcc;
	me["TxtQry"] = TxtQry;
	me["TxtTco"] = TxtTco;
	me["TxtStb"] = TxtStb;
};

void PnlWznmQcoDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmQcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmQcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtOcc", TxtOcc);
		writeStringAttr(wr, itemtag, "sref", "TxtQry", TxtQry);
		writeStringAttr(wr, itemtag, "sref", "TxtTco", TxtTco);
		writeStringAttr(wr, itemtag, "sref", "TxtStb", TxtStb);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQcoDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtOcc == comp->TxtOcc) insert(items, TXTOCC);
	if (TxtQry == comp->TxtQry) insert(items, TXTQRY);
	if (TxtTco == comp->TxtTco) insert(items, TXTTCO);
	if (TxtStb == comp->TxtStb) insert(items, TXTSTB);

	return(items);
};

set<uint> PnlWznmQcoDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTOCC, TXTQRY, TXTTCO, TXTSTB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQcoDetail::StatApp
 ******************************************************************************/

void PnlWznmQcoDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool LstOccAlt
			, const uint LstOccNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmQcoDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstOccAlt"] = LstOccAlt;
	me["LstOccNumFirstdisp"] = LstOccNumFirstdisp;
};

void PnlWznmQcoDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstOccAlt
			, const uint LstOccNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmQcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmQcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstOccAlt", LstOccAlt);
		writeUintAttr(wr, itemtag, "sref", "LstOccNumFirstdisp", LstOccNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQcoDetail::StatShr
 ******************************************************************************/

PnlWznmQcoDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool PupTypActive
			, const bool LstOccActive
			, const bool TxtQryActive
			, const bool ButQryViewAvail
			, const bool ButQryViewActive
			, const bool TxtTcoActive
			, const bool TxtStbActive
			, const bool ButStbViewAvail
			, const bool ButStbViewActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->PupTypActive = PupTypActive;
	this->LstOccActive = LstOccActive;
	this->TxtQryActive = TxtQryActive;
	this->ButQryViewAvail = ButQryViewAvail;
	this->ButQryViewActive = ButQryViewActive;
	this->TxtTcoActive = TxtTcoActive;
	this->TxtStbActive = TxtStbActive;
	this->ButStbViewAvail = ButStbViewAvail;
	this->ButStbViewActive = ButStbViewActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTTCOACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE};
};

void PnlWznmQcoDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmQcoDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxfShoActive"] = TxfShoActive;
	me["PupTypActive"] = PupTypActive;
	me["LstOccActive"] = LstOccActive;
	me["TxtQryActive"] = TxtQryActive;
	me["ButQryViewAvail"] = ButQryViewAvail;
	me["ButQryViewActive"] = ButQryViewActive;
	me["TxtTcoActive"] = TxtTcoActive;
	me["TxtStbActive"] = TxtStbActive;
	me["ButStbViewAvail"] = ButStbViewAvail;
	me["ButStbViewActive"] = ButStbViewActive;
};

void PnlWznmQcoDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmQcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmQcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfShoActive", TxfShoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOccActive", LstOccActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtQryActive", TxtQryActive);
		writeBoolAttr(wr, itemtag, "sref", "ButQryViewAvail", ButQryViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButQryViewActive", ButQryViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTcoActive", TxtTcoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtStbActive", TxtStbActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStbViewAvail", ButStbViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStbViewActive", ButStbViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQcoDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstOccActive == comp->LstOccActive) insert(items, LSTOCCACTIVE);
	if (TxtQryActive == comp->TxtQryActive) insert(items, TXTQRYACTIVE);
	if (ButQryViewAvail == comp->ButQryViewAvail) insert(items, BUTQRYVIEWAVAIL);
	if (ButQryViewActive == comp->ButQryViewActive) insert(items, BUTQRYVIEWACTIVE);
	if (TxtTcoActive == comp->TxtTcoActive) insert(items, TXTTCOACTIVE);
	if (TxtStbActive == comp->TxtStbActive) insert(items, TXTSTBACTIVE);
	if (ButStbViewAvail == comp->ButStbViewAvail) insert(items, BUTSTBVIEWAVAIL);
	if (ButStbViewActive == comp->ButStbViewActive) insert(items, BUTSTBVIEWACTIVE);

	return(items);
};

set<uint> PnlWznmQcoDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTTCOACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQcoDetail::Tag
 ******************************************************************************/

void PnlWznmQcoDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmQcoDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptSho"] = "acronym";
		me["CptTyp"] = "type";
		me["CptOcc"] = "occurrence";
		me["CptQry"] = "query";
		me["CptTco"] = "table column";
		me["CptStb"] = "stub";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmQcoDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmQcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmQcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSho", "acronym");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptOcc", "occurrence");
			writeStringAttr(wr, itemtag, "sref", "CptQry", "query");
			writeStringAttr(wr, itemtag, "sref", "CptTco", "table column");
			writeStringAttr(wr, itemtag, "sref", "CptStb", "stub");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQcoDetail::DpchAppData
 ******************************************************************************/

PnlWznmQcoDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQCODETAILDATA)
		{
};

string PnlWznmQcoDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQcoDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmQcoDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmQcoDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmQcoDetailData");
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
 class PnlWznmQcoDetail::DpchAppDo
 ******************************************************************************/

PnlWznmQcoDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQCODETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmQcoDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQcoDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmQcoDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmQcoDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmQcoDetailDo");
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
 class PnlWznmQcoDetail::DpchEngData
 ******************************************************************************/

PnlWznmQcoDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstOcc
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMQCODETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTOCC, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTOCC) && feedFLstOcc) this->feedFLstOcc = *feedFLstOcc;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmQcoDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOCC)) ss.push_back("feedFLstOcc");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQcoDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTOCC)) {feedFLstOcc = src->feedFLstOcc; add(FEEDFLSTOCC);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmQcoDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmQcoDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTOCC)) feedFLstOcc.writeJSON(me);
	if (has(FEEDFPUPTYP)) feedFPupTyp.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmQcoDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmQcoDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTOCC)) feedFLstOcc.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
