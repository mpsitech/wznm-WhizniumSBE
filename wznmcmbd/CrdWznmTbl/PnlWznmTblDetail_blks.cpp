/**
	* \file PnlWznmTblDetail_blks.cpp
	* job handler for job PnlWznmTblDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTblDetail::VecVDo
 ******************************************************************************/

uint PnlWznmTblDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butcarviewclick") return BUTCARVIEWCLICK;
	if (s == "butunqviewclick") return BUTUNQVIEWCLICK;
	if (s == "butpstnewclick") return BUTPSTNEWCLICK;
	if (s == "butpstdeleteclick") return BUTPSTDELETECLICK;
	if (s == "butpstjtieditclick") return BUTPSTJTIEDITCLICK;
	if (s == "butpstverviewclick") return BUTPSTVERVIEWCLICK;

	return(0);
};

string PnlWznmTblDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTCARVIEWCLICK) return("ButCarViewClick");
	if (ix == BUTUNQVIEWCLICK) return("ButUnqViewClick");
	if (ix == BUTPSTNEWCLICK) return("ButPstNewClick");
	if (ix == BUTPSTDELETECLICK) return("ButPstDeleteClick");
	if (ix == BUTPSTJTIEDITCLICK) return("ButPstJtiEditClick");
	if (ix == BUTPSTVERVIEWCLICK) return("ButPstVerViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmTblDetail::ContIac
 ******************************************************************************/

PnlWznmTblDetail::ContIac::ContIac(
			const string& TxfSho
			, const uint numFPupTyp
			, const uint numFPupRet
			, const uint numFLstUnq
			, const string& TxfUnq
			, const string& TxfCmt
			, const uint numFPupPstJti
			, const uint numFPupPstSco
			, const uint numFPupPstAty
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->numFPupTyp = numFPupTyp;
	this->numFPupRet = numFPupRet;
	this->numFLstUnq = numFLstUnq;
	this->TxfUnq = TxfUnq;
	this->TxfCmt = TxfCmt;
	this->numFPupPstJti = numFPupPstJti;
	this->numFPupPstSco = numFPupPstSco;
	this->numFPupPstAty = numFPupPstAty;

	mask = {TXFSHO, NUMFPUPTYP, NUMFPUPRET, NUMFLSTUNQ, TXFUNQ, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY};
};

bool PnlWznmTblDetail::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmTblDetail"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("TxfSho")) {TxfSho = me["TxfSho"].asString(); add(TXFSHO);};
		if (me.isMember("numFPupTyp")) {numFPupTyp = me["numFPupTyp"].asUInt(); add(NUMFPUPTYP);};
		if (me.isMember("numFPupRet")) {numFPupRet = me["numFPupRet"].asUInt(); add(NUMFPUPRET);};
		if (me.isMember("numFLstUnq")) {numFLstUnq = me["numFLstUnq"].asUInt(); add(NUMFLSTUNQ);};
		if (me.isMember("TxfUnq")) {TxfUnq = me["TxfUnq"].asString(); add(TXFUNQ);};
		if (me.isMember("TxfCmt")) {TxfCmt = me["TxfCmt"].asString(); add(TXFCMT);};
		if (me.isMember("numFPupPstJti")) {numFPupPstJti = me["numFPupPstJti"].asUInt(); add(NUMFPUPPSTJTI);};
		if (me.isMember("numFPupPstSco")) {numFPupPstSco = me["numFPupPstSco"].asUInt(); add(NUMFPUPPSTSCO);};
		if (me.isMember("numFPupPstAty")) {numFPupPstAty = me["numFPupPstAty"].asUInt(); add(NUMFPUPPSTATY);};
	};

	return basefound;
};

bool PnlWznmTblDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmTblDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmTblDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUnq", numFLstUnq)) add(NUMFLSTUNQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfUnq", TxfUnq)) add(TXFUNQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstJti", numFPupPstJti)) add(NUMFPUPPSTJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstSco", numFPupPstSco)) add(NUMFPUPPSTSCO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstAty", numFPupPstAty)) add(NUMFPUPPSTATY);
	};

	return basefound;
};

void PnlWznmTblDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmTblDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfSho"] = TxfSho;
	me["numFPupTyp"] = numFPupTyp;
	me["numFPupRet"] = numFPupRet;
	me["numFLstUnq"] = numFLstUnq;
	me["TxfUnq"] = TxfUnq;
	me["TxfCmt"] = TxfCmt;
	me["numFPupPstJti"] = numFPupPstJti;
	me["numFPupPstSco"] = numFPupPstSco;
	me["numFPupPstAty"] = numFPupPstAty;
};

void PnlWznmTblDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmTblDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmTblDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFLstUnq", numFLstUnq);
		writeStringAttr(wr, itemtag, "sref", "TxfUnq", TxfUnq);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstJti", numFPupPstJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstSco", numFPupPstSco);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstAty", numFPupPstAty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTblDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFLstUnq == comp->numFLstUnq) insert(items, NUMFLSTUNQ);
	if (TxfUnq == comp->TxfUnq) insert(items, TXFUNQ);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupPstJti == comp->numFPupPstJti) insert(items, NUMFPUPPSTJTI);
	if (numFPupPstSco == comp->numFPupPstSco) insert(items, NUMFPUPPSTSCO);
	if (numFPupPstAty == comp->numFPupPstAty) insert(items, NUMFPUPPSTATY);

	return(items);
};

set<uint> PnlWznmTblDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, NUMFPUPTYP, NUMFPUPRET, NUMFLSTUNQ, TXFUNQ, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTblDetail::ContInf
 ******************************************************************************/

PnlWznmTblDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVer
			, const string& TxtReu
			, const string& TxtCar
			, const string& TxtPstSrf
			, const string& TxtPstTit
			, const string& TxtPstVer
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtVer = TxtVer;
	this->TxtReu = TxtReu;
	this->TxtCar = TxtCar;
	this->TxtPstSrf = TxtPstSrf;
	this->TxtPstTit = TxtPstTit;
	this->TxtPstVer = TxtPstVer;

	mask = {TXTSRF, TXTVER, TXTREU, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER};
};

void PnlWznmTblDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmTblDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtVer"] = TxtVer;
	me["TxtReu"] = TxtReu;
	me["TxtCar"] = TxtCar;
	me["TxtPstSrf"] = TxtPstSrf;
	me["TxtPstTit"] = TxtPstTit;
	me["TxtPstVer"] = TxtPstVer;
};

void PnlWznmTblDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmTblDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmTblDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtVer", TxtVer);
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
		writeStringAttr(wr, itemtag, "sref", "TxtCar", TxtCar);
		writeStringAttr(wr, itemtag, "sref", "TxtPstSrf", TxtPstSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtPstTit", TxtPstTit);
		writeStringAttr(wr, itemtag, "sref", "TxtPstVer", TxtPstVer);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTblDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtCar == comp->TxtCar) insert(items, TXTCAR);
	if (TxtPstSrf == comp->TxtPstSrf) insert(items, TXTPSTSRF);
	if (TxtPstTit == comp->TxtPstTit) insert(items, TXTPSTTIT);
	if (TxtPstVer == comp->TxtPstVer) insert(items, TXTPSTVER);

	return(items);
};

set<uint> PnlWznmTblDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVER, TXTREU, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTblDetail::StatApp
 ******************************************************************************/

void PnlWznmTblDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool LstUnqAlt
			, const uint LstUnqNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmTblDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstUnqAlt"] = LstUnqAlt;
	me["LstUnqNumFirstdisp"] = LstUnqNumFirstdisp;
};

void PnlWznmTblDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstUnqAlt
			, const uint LstUnqNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmTblDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmTblDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstUnqAlt", LstUnqAlt);
		writeUintAttr(wr, itemtag, "sref", "LstUnqNumFirstdisp", LstUnqNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblDetail::StatShr
 ******************************************************************************/

PnlWznmTblDetail::StatShr::StatShr(
			const bool TxfUnqValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool PupTypActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxtCarAvail
			, const bool TxtCarActive
			, const bool ButCarViewAvail
			, const bool ButCarViewActive
			, const bool LstUnqAvail
			, const bool LstUnqActive
			, const bool ButUnqViewAvail
			, const bool ButUnqViewActive
			, const bool TxfCmtActive
			, const bool SepPstAvail
			, const bool HdgPstAvail
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
	this->TxfUnqValid = TxfUnqValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->PupTypActive = PupTypActive;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxtCarAvail = TxtCarAvail;
	this->TxtCarActive = TxtCarActive;
	this->ButCarViewAvail = ButCarViewAvail;
	this->ButCarViewActive = ButCarViewActive;
	this->LstUnqAvail = LstUnqAvail;
	this->LstUnqActive = LstUnqActive;
	this->ButUnqViewAvail = ButUnqViewAvail;
	this->ButUnqViewActive = ButUnqViewActive;
	this->TxfCmtActive = TxfCmtActive;
	this->SepPstAvail = SepPstAvail;
	this->HdgPstAvail = HdgPstAvail;
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

	mask = {TXFUNQVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTCARAVAIL, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, LSTUNQAVAIL, LSTUNQACTIVE, BUTUNQVIEWAVAIL, BUTUNQVIEWACTIVE, TXFCMTACTIVE, SEPPSTAVAIL, HDGPSTAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE};
};

void PnlWznmTblDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmTblDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfUnqValid"] = TxfUnqValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["TxfShoActive"] = TxfShoActive;
	me["PupTypActive"] = PupTypActive;
	me["TxtVerActive"] = TxtVerActive;
	me["ButVerViewAvail"] = ButVerViewAvail;
	me["ButVerViewActive"] = ButVerViewActive;
	me["TxtReuActive"] = TxtReuActive;
	me["ButReuViewAvail"] = ButReuViewAvail;
	me["ButReuViewActive"] = ButReuViewActive;
	me["TxtCarAvail"] = TxtCarAvail;
	me["TxtCarActive"] = TxtCarActive;
	me["ButCarViewAvail"] = ButCarViewAvail;
	me["ButCarViewActive"] = ButCarViewActive;
	me["LstUnqAvail"] = LstUnqAvail;
	me["LstUnqActive"] = LstUnqActive;
	me["ButUnqViewAvail"] = ButUnqViewAvail;
	me["ButUnqViewActive"] = ButUnqViewActive;
	me["TxfCmtActive"] = TxfCmtActive;
	me["SepPstAvail"] = SepPstAvail;
	me["HdgPstAvail"] = HdgPstAvail;
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

void PnlWznmTblDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmTblDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmTblDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfUnqValid", TxfUnqValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfShoActive", TxfShoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtVerActive", TxtVerActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewAvail", ButVerViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewActive", ButVerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCarAvail", TxtCarAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtCarActive", TxtCarActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCarViewAvail", ButCarViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCarViewActive", ButCarViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstUnqAvail", LstUnqAvail);
		writeBoolAttr(wr, itemtag, "sref", "LstUnqActive", LstUnqActive);
		writeBoolAttr(wr, itemtag, "sref", "ButUnqViewAvail", ButUnqViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButUnqViewActive", ButUnqViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
		writeBoolAttr(wr, itemtag, "sref", "SepPstAvail", SepPstAvail);
		writeBoolAttr(wr, itemtag, "sref", "HdgPstAvail", HdgPstAvail);
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

set<uint> PnlWznmTblDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfUnqValid == comp->TxfUnqValid) insert(items, TXFUNQVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxtCarAvail == comp->TxtCarAvail) insert(items, TXTCARAVAIL);
	if (TxtCarActive == comp->TxtCarActive) insert(items, TXTCARACTIVE);
	if (ButCarViewAvail == comp->ButCarViewAvail) insert(items, BUTCARVIEWAVAIL);
	if (ButCarViewActive == comp->ButCarViewActive) insert(items, BUTCARVIEWACTIVE);
	if (LstUnqAvail == comp->LstUnqAvail) insert(items, LSTUNQAVAIL);
	if (LstUnqActive == comp->LstUnqActive) insert(items, LSTUNQACTIVE);
	if (ButUnqViewAvail == comp->ButUnqViewAvail) insert(items, BUTUNQVIEWAVAIL);
	if (ButUnqViewActive == comp->ButUnqViewActive) insert(items, BUTUNQVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (SepPstAvail == comp->SepPstAvail) insert(items, SEPPSTAVAIL);
	if (HdgPstAvail == comp->HdgPstAvail) insert(items, HDGPSTAVAIL);
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

set<uint> PnlWznmTblDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFUNQVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTCARAVAIL, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, LSTUNQAVAIL, LSTUNQACTIVE, BUTUNQVIEWAVAIL, BUTUNQVIEWACTIVE, TXFCMTACTIVE, SEPPSTAVAIL, HDGPSTAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTblDetail::Tag
 ******************************************************************************/

void PnlWznmTblDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmTblDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptSho"] = "acronym";
		me["CptTyp"] = "type";
		me["CptVer"] = "version";
		me["CptReu"] = "reference";
		me["CptCar"] = "card";
		me["CptUnq"] = "unique record table columns";
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

void PnlWznmTblDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmTblDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmTblDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSho", "acronym");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "version");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptCar", "card");
			writeStringAttr(wr, itemtag, "sref", "CptUnq", "unique record table columns");
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
 class PnlWznmTblDetail::DpchAppData
 ******************************************************************************/

PnlWznmTblDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLDETAILDATA)
		{
};

string PnlWznmTblDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblDetail::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmTblDetailData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmTblDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTblDetailData");
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
 class PnlWznmTblDetail::DpchAppDo
 ******************************************************************************/

PnlWznmTblDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmTblDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblDetail::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmTblDetailDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmTblDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTblDetailDo");
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
 class PnlWznmTblDetail::DpchEngData
 ******************************************************************************/

PnlWznmTblDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstUnq
			, Feed* feedFPupPstAty
			, Feed* feedFPupPstJti
			, Feed* feedFPupPstSco
			, Feed* feedFPupRet
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTBLDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTUNQ, FEEDFPUPPSTATY, FEEDFPUPPSTJTI, FEEDFPUPPSTSCO, FEEDFPUPRET, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTUNQ) && feedFLstUnq) this->feedFLstUnq = *feedFLstUnq;
	if (find(this->mask, FEEDFPUPPSTATY) && feedFPupPstAty) this->feedFPupPstAty = *feedFPupPstAty;
	if (find(this->mask, FEEDFPUPPSTJTI) && feedFPupPstJti) this->feedFPupPstJti = *feedFPupPstJti;
	if (find(this->mask, FEEDFPUPPSTSCO) && feedFPupPstSco) this->feedFPupPstSco = *feedFPupPstSco;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmTblDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTUNQ)) ss.push_back("feedFLstUnq");
	if (has(FEEDFPUPPSTATY)) ss.push_back("feedFPupPstAty");
	if (has(FEEDFPUPPSTJTI)) ss.push_back("feedFPupPstJti");
	if (has(FEEDFPUPPSTSCO)) ss.push_back("feedFPupPstSco");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTUNQ)) {feedFLstUnq = src->feedFLstUnq; add(FEEDFLSTUNQ);};
	if (src->has(FEEDFPUPPSTATY)) {feedFPupPstAty = src->feedFPupPstAty; add(FEEDFPUPPSTATY);};
	if (src->has(FEEDFPUPPSTJTI)) {feedFPupPstJti = src->feedFPupPstJti; add(FEEDFPUPPSTJTI);};
	if (src->has(FEEDFPUPPSTSCO)) {feedFPupPstSco = src->feedFPupPstSco; add(FEEDFPUPPSTSCO);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmTblDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmTblDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTUNQ)) feedFLstUnq.writeJSON(me);
	if (has(FEEDFPUPPSTATY)) feedFPupPstAty.writeJSON(me);
	if (has(FEEDFPUPPSTJTI)) feedFPupPstJti.writeJSON(me);
	if (has(FEEDFPUPPSTSCO)) feedFPupPstSco.writeJSON(me);
	if (has(FEEDFPUPRET)) feedFPupRet.writeJSON(me);
	if (has(FEEDFPUPTYP)) feedFPupTyp.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmTblDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmTblDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTUNQ)) feedFLstUnq.writeXML(wr);
		if (has(FEEDFPUPPSTATY)) feedFPupPstAty.writeXML(wr);
		if (has(FEEDFPUPPSTJTI)) feedFPupPstJti.writeXML(wr);
		if (has(FEEDFPUPPSTSCO)) feedFPupPstSco.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
