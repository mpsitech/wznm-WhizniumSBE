/**
	* \file PnlWznmQryDetail_blks.cpp
	* job handler for job PnlWznmQryDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmQryDetail::VecVDo
 ******************************************************************************/

uint PnlWznmQryDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "butinoviewclick") return BUTINOVIEWCLICK;

	return(0);
};

string PnlWznmQryDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTINOVIEWCLICK) return("ButInoViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmQryDetail::ContIac
 ******************************************************************************/

PnlWznmQryDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const bool ChkLof
			, const uint numFLstIno
			, const string& TxfIno
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->ChkLof = ChkLof;
	this->numFLstIno = numFLstIno;
	this->TxfIno = TxfIno;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPTYP, CHKLOF, NUMFLSTINO, TXFINO, TXFCMT};
};

bool PnlWznmQryDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmQryDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupTyp")) {numFPupTyp = me["numFPupTyp"].asUInt(); add(NUMFPUPTYP);};
		if (me.isMember("ChkLof")) {ChkLof = me["ChkLof"].asBool(); add(CHKLOF);};
		if (me.isMember("numFLstIno")) {numFLstIno = me["numFLstIno"].asUInt(); add(NUMFLSTINO);};
		if (me.isMember("TxfIno")) {TxfIno = me["TxfIno"].asString(); add(TXFINO);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
	};

	return basefound;
};

bool PnlWznmQryDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmQryDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmQryDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkLof", ChkLof)) add(CHKLOF);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstIno", numFLstIno)) add(NUMFLSTINO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfIno", TxfIno)) add(TXFINO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmQryDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmQryDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupTyp"] = numFPupTyp;
	me["ChkLof"] = ChkLof;
	me["numFLstIno"] = numFLstIno;
	me["TxfIno"] = TxfIno;
	me["TxfCmt"] = TxfCmt;
};

void PnlWznmQryDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmQryDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmQryDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeBoolAttr(wr, itemtag, "sref", "ChkLof", ChkLof);
		writeUintAttr(wr, itemtag, "sref", "numFLstIno", numFLstIno);
		writeStringAttr(wr, itemtag, "sref", "TxfIno", TxfIno);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQryDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (ChkLof == comp->ChkLof) insert(items, CHKLOF);
	if (numFLstIno == comp->numFLstIno) insert(items, NUMFLSTINO);
	if (TxfIno == comp->TxfIno) insert(items, TXFINO);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmQryDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, CHKLOF, NUMFLSTINO, TXFINO, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryDetail::ContInf
 ******************************************************************************/

PnlWznmQryDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVer
			, const string& TxtSup
			, const string& TxtTbl
			, const string& TxtQtb
			, const string& TxtJob
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtVer = TxtVer;
	this->TxtSup = TxtSup;
	this->TxtTbl = TxtTbl;
	this->TxtQtb = TxtQtb;
	this->TxtJob = TxtJob;

	mask = {TXTSRF, TXTVER, TXTSUP, TXTTBL, TXTQTB, TXTJOB};
};

void PnlWznmQryDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmQryDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtVer"] = TxtVer;
	me["TxtSup"] = TxtSup;
	me["TxtTbl"] = TxtTbl;
	me["TxtQtb"] = TxtQtb;
	me["TxtJob"] = TxtJob;
};

void PnlWznmQryDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmQryDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmQryDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtVer", TxtVer);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtTbl", TxtTbl);
		writeStringAttr(wr, itemtag, "sref", "TxtQtb", TxtQtb);
		writeStringAttr(wr, itemtag, "sref", "TxtJob", TxtJob);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQryDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtQtb == comp->TxtQtb) insert(items, TXTQTB);
	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);

	return(items);
};

set<uint> PnlWznmQryDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVER, TXTSUP, TXTTBL, TXTQTB, TXTJOB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryDetail::StatApp
 ******************************************************************************/

void PnlWznmQryDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool LstInoAlt
			, const uint LstInoNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmQryDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstInoAlt"] = LstInoAlt;
	me["LstInoNumFirstdisp"] = LstInoNumFirstdisp;
};

void PnlWznmQryDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstInoAlt
			, const uint LstInoNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmQryDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmQryDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstInoAlt", LstInoAlt);
		writeUintAttr(wr, itemtag, "sref", "LstInoNumFirstdisp", LstInoNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQryDetail::StatShr
 ******************************************************************************/

PnlWznmQryDetail::StatShr::StatShr(
			const bool TxfInoValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtTblActive
			, const bool TxtQtbActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool ChkLofActive
			, const bool LstInoActive
			, const bool ButInoViewAvail
			, const bool ButInoViewActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfInoValid = TxfInoValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxtTblActive = TxtTblActive;
	this->TxtQtbActive = TxtQtbActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->ChkLofActive = ChkLofActive;
	this->LstInoActive = LstInoActive;
	this->ButInoViewAvail = ButInoViewAvail;
	this->ButInoViewActive = ButInoViewActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFINOVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXTQTBACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKLOFACTIVE, LSTINOACTIVE, BUTINOVIEWAVAIL, BUTINOVIEWACTIVE, TXFCMTACTIVE};
};

void PnlWznmQryDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmQryDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfInoValid"] = TxfInoValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["PupTypActive"] = PupTypActive;
	me["TxtVerActive"] = TxtVerActive;
	me["ButVerViewAvail"] = ButVerViewAvail;
	me["ButVerViewActive"] = ButVerViewActive;
	me["TxtSupActive"] = TxtSupActive;
	me["ButSupViewAvail"] = ButSupViewAvail;
	me["ButSupViewActive"] = ButSupViewActive;
	me["TxtTblActive"] = TxtTblActive;
	me["TxtQtbActive"] = TxtQtbActive;
	me["TxtJobActive"] = TxtJobActive;
	me["ButJobViewAvail"] = ButJobViewAvail;
	me["ButJobViewActive"] = ButJobViewActive;
	me["ChkLofActive"] = ChkLofActive;
	me["LstInoActive"] = LstInoActive;
	me["ButInoViewAvail"] = ButInoViewAvail;
	me["ButInoViewActive"] = ButInoViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
};

void PnlWznmQryDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmQryDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmQryDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfInoValid", TxfInoValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtVerActive", TxtVerActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewAvail", ButVerViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewActive", ButVerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTblActive", TxtTblActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtQtbActive", TxtQtbActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtJobActive", TxtJobActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewAvail", ButJobViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkLofActive", ChkLofActive);
		writeBoolAttr(wr, itemtag, "sref", "LstInoActive", LstInoActive);
		writeBoolAttr(wr, itemtag, "sref", "ButInoViewAvail", ButInoViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButInoViewActive", ButInoViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQryDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfInoValid == comp->TxfInoValid) insert(items, TXFINOVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (TxtQtbActive == comp->TxtQtbActive) insert(items, TXTQTBACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (ChkLofActive == comp->ChkLofActive) insert(items, CHKLOFACTIVE);
	if (LstInoActive == comp->LstInoActive) insert(items, LSTINOACTIVE);
	if (ButInoViewAvail == comp->ButInoViewAvail) insert(items, BUTINOVIEWAVAIL);
	if (ButInoViewActive == comp->ButInoViewActive) insert(items, BUTINOVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmQryDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFINOVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXTQTBACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKLOFACTIVE, LSTINOACTIVE, BUTINOVIEWAVAIL, BUTINOVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryDetail::Tag
 ******************************************************************************/

void PnlWznmQryDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmQryDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptTyp"] = "type";
		me["CptVer"] = "version";
		me["CptSup"] = "super query";
		me["CptTbl"] = "main source table";
		me["CptQtb"] = "table";
		me["CptJob"] = "job";
		me["CptLof"] = "Limofs";
		me["CptIno"] = "order by table columns";
		me["CptCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmQryDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmQryDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmQryDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "version");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super query");
			writeStringAttr(wr, itemtag, "sref", "CptTbl", "main source table");
			writeStringAttr(wr, itemtag, "sref", "CptQtb", "table");
			writeStringAttr(wr, itemtag, "sref", "CptJob", "job");
			writeStringAttr(wr, itemtag, "sref", "CptLof", "Limofs");
			writeStringAttr(wr, itemtag, "sref", "CptIno", "order by table columns");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQryDetail::DpchAppData
 ******************************************************************************/

PnlWznmQryDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQRYDETAILDATA)
		{
};

string PnlWznmQryDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmQryDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmQryDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmQryDetailData");
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
 class PnlWznmQryDetail::DpchAppDo
 ******************************************************************************/

PnlWznmQryDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQRYDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmQryDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmQryDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmQryDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmQryDetailDo");
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
 class PnlWznmQryDetail::DpchEngData
 ******************************************************************************/

PnlWznmQryDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstIno
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMQRYDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTINO, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTINO) && feedFLstIno) this->feedFLstIno = *feedFLstIno;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmQryDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTINO)) ss.push_back("feedFLstIno");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTINO)) {feedFLstIno = src->feedFLstIno; add(FEEDFLSTINO);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmQryDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmQryDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTINO)) feedFLstIno.writeJSON(me);
	if (has(FEEDFPUPTYP)) feedFPupTyp.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmQryDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmQryDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTINO)) feedFLstIno.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
