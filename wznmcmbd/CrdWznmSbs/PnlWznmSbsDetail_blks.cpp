/**
	* \file PnlWznmSbsDetail_blks.cpp
	* job handler for job PnlWznmSbsDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSbsDetail::VecVDo
 ******************************************************************************/

uint PnlWznmSbsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butcarviewclick") return BUTCARVIEWCLICK;
	if (s == "butpstnewclick") return BUTPSTNEWCLICK;
	if (s == "butpstdeleteclick") return BUTPSTDELETECLICK;
	if (s == "butpstjtieditclick") return BUTPSTJTIEDITCLICK;
	if (s == "butpstverviewclick") return BUTPSTVERVIEWCLICK;

	return(0);
};

string PnlWznmSbsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTCARVIEWCLICK) return("ButCarViewClick");
	if (ix == BUTPSTNEWCLICK) return("ButPstNewClick");
	if (ix == BUTPSTDELETECLICK) return("ButPstDeleteClick");
	if (ix == BUTPSTJTIEDITCLICK) return("ButPstJtiEditClick");
	if (ix == BUTPSTVERVIEWCLICK) return("ButPstVerViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmSbsDetail::ContIac
 ******************************************************************************/

PnlWznmSbsDetail::ContIac::ContIac(
			const string& TxfSho
			, const string& TxfCnd
			, const string& TxfCmt
			, const uint numFPupPstJti
			, const uint numFPupPstSco
			, const uint numFPupPstAty
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->TxfCnd = TxfCnd;
	this->TxfCmt = TxfCmt;
	this->numFPupPstJti = numFPupPstJti;
	this->numFPupPstSco = numFPupPstSco;
	this->numFPupPstAty = numFPupPstAty;

	mask = {TXFSHO, TXFCND, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY};
};

bool PnlWznmSbsDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWznmSbsDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfSho")) {TxfSho = me["TxfSho"].asString(); add(TXFSHO);};
		if (me.isMember("TxfCnd")) {TxfCnd = me["TxfCnd"].asString(); add(TXFCND);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
		if (me.isMember("numFPupPstJti")) {numFPupPstJti = me["numFPupPstJti"].asUInt(); add(NUMFPUPPSTJTI);};
		if (me.isMember("numFPupPstSco")) {numFPupPstSco = me["numFPupPstSco"].asUInt(); add(NUMFPUPPSTSCO);};
		if (me.isMember("numFPupPstAty")) {numFPupPstAty = me["numFPupPstAty"].asUInt(); add(NUMFPUPPSTATY);};
	};

	return basefound;
};

bool PnlWznmSbsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmSbsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmSbsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCnd", TxfCnd)) add(TXFCND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstJti", numFPupPstJti)) add(NUMFPUPPSTJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstSco", numFPupPstSco)) add(NUMFPUPPSTSCO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstAty", numFPupPstAty)) add(NUMFPUPPSTATY);
	};

	return basefound;
};

void PnlWznmSbsDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmSbsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfSho"] = TxfSho;
	me["TxfCnd"] = TxfCnd;
	me["TxfCmt"] = TxfCmt;
	me["numFPupPstJti"] = numFPupPstJti;
	me["numFPupPstSco"] = numFPupPstSco;
	me["numFPupPstAty"] = numFPupPstAty;
};

void PnlWznmSbsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmSbsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmSbsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeStringAttr(wr, itemtag, "sref", "TxfCnd", TxfCnd);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstJti", numFPupPstJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstSco", numFPupPstSco);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstAty", numFPupPstAty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSbsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (TxfCnd == comp->TxfCnd) insert(items, TXFCND);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupPstJti == comp->numFPupPstJti) insert(items, NUMFPUPPSTJTI);
	if (numFPupPstSco == comp->numFPupPstSco) insert(items, NUMFPUPPSTSCO);
	if (numFPupPstAty == comp->numFPupPstAty) insert(items, NUMFPUPPSTATY);

	return(items);
};

set<uint> PnlWznmSbsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, TXFCND, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSbsDetail::ContInf
 ******************************************************************************/

PnlWznmSbsDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTbl
			, const string& TxtCar
			, const string& TxtPstSrf
			, const string& TxtPstTit
			, const string& TxtPstVer
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTbl = TxtTbl;
	this->TxtCar = TxtCar;
	this->TxtPstSrf = TxtPstSrf;
	this->TxtPstTit = TxtPstTit;
	this->TxtPstVer = TxtPstVer;

	mask = {TXTSRF, TXTTBL, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER};
};

void PnlWznmSbsDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmSbsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtTbl"] = TxtTbl;
	me["TxtCar"] = TxtCar;
	me["TxtPstSrf"] = TxtPstSrf;
	me["TxtPstTit"] = TxtPstTit;
	me["TxtPstVer"] = TxtPstVer;
};

void PnlWznmSbsDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmSbsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmSbsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTbl", TxtTbl);
		writeStringAttr(wr, itemtag, "sref", "TxtCar", TxtCar);
		writeStringAttr(wr, itemtag, "sref", "TxtPstSrf", TxtPstSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtPstTit", TxtPstTit);
		writeStringAttr(wr, itemtag, "sref", "TxtPstVer", TxtPstVer);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSbsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtCar == comp->TxtCar) insert(items, TXTCAR);
	if (TxtPstSrf == comp->TxtPstSrf) insert(items, TXTPSTSRF);
	if (TxtPstTit == comp->TxtPstTit) insert(items, TXTPSTTIT);
	if (TxtPstVer == comp->TxtPstVer) insert(items, TXTPSTVER);

	return(items);
};

set<uint> PnlWznmSbsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTBL, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSbsDetail::StatApp
 ******************************************************************************/

void PnlWznmSbsDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmSbsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
};

void PnlWznmSbsDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmSbsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmSbsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSbsDetail::StatShr
 ******************************************************************************/

PnlWznmSbsDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool TxtTblActive
			, const bool TxtCarActive
			, const bool ButCarViewAvail
			, const bool ButCarViewActive
			, const bool TxfCndActive
			, const bool TxfCmtActive
			, const bool ButPstNewAvail
			, const bool ButPstDeleteAvail
			, const bool TxtPstSrfAvail
			, const bool TxtPstSrfActive
			, const bool PupPstJtiAvail
			, const bool PupPstJtiActive
			, const bool ButPstJtiEditAvail
			, const bool TxtPstTitAvail
			, const bool TxtPstTitActive
			, const bool TxtPstVerAvail
			, const bool TxtPstVerActive
			, const bool ButPstVerViewAvail
			, const bool ButPstVerViewActive
			, const bool PupPstScoAvail
			, const bool PupPstScoActive
			, const bool PupPstAtyAvail
			, const bool PupPstAtyActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->TxtTblActive = TxtTblActive;
	this->TxtCarActive = TxtCarActive;
	this->ButCarViewAvail = ButCarViewAvail;
	this->ButCarViewActive = ButCarViewActive;
	this->TxfCndActive = TxfCndActive;
	this->TxfCmtActive = TxfCmtActive;
	this->ButPstNewAvail = ButPstNewAvail;
	this->ButPstDeleteAvail = ButPstDeleteAvail;
	this->TxtPstSrfAvail = TxtPstSrfAvail;
	this->TxtPstSrfActive = TxtPstSrfActive;
	this->PupPstJtiAvail = PupPstJtiAvail;
	this->PupPstJtiActive = PupPstJtiActive;
	this->ButPstJtiEditAvail = ButPstJtiEditAvail;
	this->TxtPstTitAvail = TxtPstTitAvail;
	this->TxtPstTitActive = TxtPstTitActive;
	this->TxtPstVerAvail = TxtPstVerAvail;
	this->TxtPstVerActive = TxtPstVerActive;
	this->ButPstVerViewAvail = ButPstVerViewAvail;
	this->ButPstVerViewActive = ButPstVerViewActive;
	this->PupPstScoAvail = PupPstScoAvail;
	this->PupPstScoActive = PupPstScoActive;
	this->PupPstAtyAvail = PupPstAtyAvail;
	this->PupPstAtyActive = PupPstAtyActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, TXTTBLACTIVE, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, TXFCNDACTIVE, TXFCMTACTIVE, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE};
};

void PnlWznmSbsDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmSbsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxfShoActive"] = TxfShoActive;
	me["TxtTblActive"] = TxtTblActive;
	me["TxtCarActive"] = TxtCarActive;
	me["ButCarViewAvail"] = ButCarViewAvail;
	me["ButCarViewActive"] = ButCarViewActive;
	me["TxfCndActive"] = TxfCndActive;
	me["TxfCmtActive"] = TxfCmtActive;
	me["ButPstNewAvail"] = ButPstNewAvail;
	me["ButPstDeleteAvail"] = ButPstDeleteAvail;
	me["TxtPstSrfAvail"] = TxtPstSrfAvail;
	me["TxtPstSrfActive"] = TxtPstSrfActive;
	me["PupPstJtiAvail"] = PupPstJtiAvail;
	me["PupPstJtiActive"] = PupPstJtiActive;
	me["ButPstJtiEditAvail"] = ButPstJtiEditAvail;
	me["TxtPstTitAvail"] = TxtPstTitAvail;
	me["TxtPstTitActive"] = TxtPstTitActive;
	me["TxtPstVerAvail"] = TxtPstVerAvail;
	me["TxtPstVerActive"] = TxtPstVerActive;
	me["ButPstVerViewAvail"] = ButPstVerViewAvail;
	me["ButPstVerViewActive"] = ButPstVerViewActive;
	me["PupPstScoAvail"] = PupPstScoAvail;
	me["PupPstScoActive"] = PupPstScoActive;
	me["PupPstAtyAvail"] = PupPstAtyAvail;
	me["PupPstAtyActive"] = PupPstAtyActive;
};

void PnlWznmSbsDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmSbsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmSbsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfShoActive", TxfShoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTblActive", TxtTblActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCarActive", TxtCarActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCarViewAvail", ButCarViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCarViewActive", ButCarViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCndActive", TxfCndActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstNewAvail", ButPstNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPstDeleteAvail", ButPstDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstSrfAvail", TxtPstSrfAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstSrfActive", TxtPstSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupPstJtiAvail", PupPstJtiAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupPstJtiActive", PupPstJtiActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstJtiEditAvail", ButPstJtiEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstTitAvail", TxtPstTitAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstTitActive", TxtPstTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstVerAvail", TxtPstVerAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstVerActive", TxtPstVerActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstVerViewAvail", ButPstVerViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPstVerViewActive", ButPstVerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupPstScoAvail", PupPstScoAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupPstScoActive", PupPstScoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupPstAtyAvail", PupPstAtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupPstAtyActive", PupPstAtyActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSbsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (TxtCarActive == comp->TxtCarActive) insert(items, TXTCARACTIVE);
	if (ButCarViewAvail == comp->ButCarViewAvail) insert(items, BUTCARVIEWAVAIL);
	if (ButCarViewActive == comp->ButCarViewActive) insert(items, BUTCARVIEWACTIVE);
	if (TxfCndActive == comp->TxfCndActive) insert(items, TXFCNDACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (ButPstNewAvail == comp->ButPstNewAvail) insert(items, BUTPSTNEWAVAIL);
	if (ButPstDeleteAvail == comp->ButPstDeleteAvail) insert(items, BUTPSTDELETEAVAIL);
	if (TxtPstSrfAvail == comp->TxtPstSrfAvail) insert(items, TXTPSTSRFAVAIL);
	if (TxtPstSrfActive == comp->TxtPstSrfActive) insert(items, TXTPSTSRFACTIVE);
	if (PupPstJtiAvail == comp->PupPstJtiAvail) insert(items, PUPPSTJTIAVAIL);
	if (PupPstJtiActive == comp->PupPstJtiActive) insert(items, PUPPSTJTIACTIVE);
	if (ButPstJtiEditAvail == comp->ButPstJtiEditAvail) insert(items, BUTPSTJTIEDITAVAIL);
	if (TxtPstTitAvail == comp->TxtPstTitAvail) insert(items, TXTPSTTITAVAIL);
	if (TxtPstTitActive == comp->TxtPstTitActive) insert(items, TXTPSTTITACTIVE);
	if (TxtPstVerAvail == comp->TxtPstVerAvail) insert(items, TXTPSTVERAVAIL);
	if (TxtPstVerActive == comp->TxtPstVerActive) insert(items, TXTPSTVERACTIVE);
	if (ButPstVerViewAvail == comp->ButPstVerViewAvail) insert(items, BUTPSTVERVIEWAVAIL);
	if (ButPstVerViewActive == comp->ButPstVerViewActive) insert(items, BUTPSTVERVIEWACTIVE);
	if (PupPstScoAvail == comp->PupPstScoAvail) insert(items, PUPPSTSCOAVAIL);
	if (PupPstScoActive == comp->PupPstScoActive) insert(items, PUPPSTSCOACTIVE);
	if (PupPstAtyAvail == comp->PupPstAtyAvail) insert(items, PUPPSTATYAVAIL);
	if (PupPstAtyActive == comp->PupPstAtyActive) insert(items, PUPPSTATYACTIVE);

	return(items);
};

set<uint> PnlWznmSbsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, TXTTBLACTIVE, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, TXFCNDACTIVE, TXFCMTACTIVE, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSbsDetail::Tag
 ******************************************************************************/

void PnlWznmSbsDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmSbsDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptSho"] = "acronym";
		me["CptTbl"] = "table";
		me["CptCar"] = "card";
		me["CptCnd"] = "condition rule";
		me["CptCmt"] = "comment";
		me["HdgPst"] = "Presetting";
		me["CptPstSrf"] = "identifier";
		me["CptPstTit"] = "name";
		me["CptPstVer"] = "version";
		me["CptPstSco"] = "scope";
		me["CptPstAty"] = "argument type";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
};

void PnlWznmSbsDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmSbsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmSbsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSho", "acronym");
			writeStringAttr(wr, itemtag, "sref", "CptTbl", "table");
			writeStringAttr(wr, itemtag, "sref", "CptCar", "card");
			writeStringAttr(wr, itemtag, "sref", "CptCnd", "condition rule");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
			writeStringAttr(wr, itemtag, "sref", "HdgPst", "Presetting");
			writeStringAttr(wr, itemtag, "sref", "CptPstSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptPstTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptPstVer", "version");
			writeStringAttr(wr, itemtag, "sref", "CptPstSco", "scope");
			writeStringAttr(wr, itemtag, "sref", "CptPstAty", "argument type");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSbsDetail::DpchAppData
 ******************************************************************************/

PnlWznmSbsDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSBSDETAILDATA)
		{
};

string PnlWznmSbsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSbsDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmSbsDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmSbsDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSbsDetailData");
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
 class PnlWznmSbsDetail::DpchAppDo
 ******************************************************************************/

PnlWznmSbsDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSBSDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmSbsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSbsDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmSbsDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmSbsDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSbsDetailDo");
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
 class PnlWznmSbsDetail::DpchEngData
 ******************************************************************************/

PnlWznmSbsDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupPstAty
			, Feed* feedFPupPstJti
			, Feed* feedFPupPstSco
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSBSDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPPSTATY, FEEDFPUPPSTJTI, FEEDFPUPPSTSCO, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPPSTATY) && feedFPupPstAty) this->feedFPupPstAty = *feedFPupPstAty;
	if (find(this->mask, FEEDFPUPPSTJTI) && feedFPupPstJti) this->feedFPupPstJti = *feedFPupPstJti;
	if (find(this->mask, FEEDFPUPPSTSCO) && feedFPupPstSco) this->feedFPupPstSco = *feedFPupPstSco;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmSbsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPPSTATY)) ss.push_back("feedFPupPstAty");
	if (has(FEEDFPUPPSTJTI)) ss.push_back("feedFPupPstJti");
	if (has(FEEDFPUPPSTSCO)) ss.push_back("feedFPupPstSco");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSbsDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPPSTATY)) {feedFPupPstAty = src->feedFPupPstAty; add(FEEDFPUPPSTATY);};
	if (src->has(FEEDFPUPPSTJTI)) {feedFPupPstJti = src->feedFPupPstJti; add(FEEDFPUPPSTJTI);};
	if (src->has(FEEDFPUPPSTSCO)) {feedFPupPstSco = src->feedFPupPstSco; add(FEEDFPUPPSTSCO);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmSbsDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmSbsDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFPUPPSTATY)) feedFPupPstAty.writeJSON(me);
	if (has(FEEDFPUPPSTJTI)) feedFPupPstJti.writeJSON(me);
	if (has(FEEDFPUPPSTSCO)) feedFPupPstSco.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmSbsDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmSbsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPPSTATY)) feedFPupPstAty.writeXML(wr);
		if (has(FEEDFPUPPSTJTI)) feedFPupPstJti.writeXML(wr);
		if (has(FEEDFPUPPSTSCO)) feedFPupPstSco.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
