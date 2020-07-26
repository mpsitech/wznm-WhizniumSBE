/**
	* \file PnlWznmSbsDetail.cpp
	* API code for job PnlWznmSbsDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWznmSbsDetail.h"

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

bool PnlWznmSbsDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmSbsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmSbsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTbl", TxtTbl)) add(TXTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCar", TxtCar)) add(TXTCAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstSrf", TxtPstSrf)) add(TXTPSTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstTit", TxtPstTit)) add(TXTPSTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstVer", TxtPstVer)) add(TXTPSTVER);
	};

	return basefound;
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

PnlWznmSbsDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmSbsDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmSbsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmSbsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmSbsDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmSbsDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlWznmSbsDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmSbsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmSbsDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfShoActive", TxfShoActive)) add(TXFSHOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTblActive", TxtTblActive)) add(TXTTBLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCarActive", TxtCarActive)) add(TXTCARACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCarViewAvail", ButCarViewAvail)) add(BUTCARVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCarViewActive", ButCarViewActive)) add(BUTCARVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCndActive", TxfCndActive)) add(TXFCNDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstNewAvail", ButPstNewAvail)) add(BUTPSTNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstDeleteAvail", ButPstDeleteAvail)) add(BUTPSTDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstSrfAvail", TxtPstSrfAvail)) add(TXTPSTSRFAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstSrfActive", TxtPstSrfActive)) add(TXTPSTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPstJtiAvail", PupPstJtiAvail)) add(PUPPSTJTIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPstJtiActive", PupPstJtiActive)) add(PUPPSTJTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstJtiEditAvail", ButPstJtiEditAvail)) add(BUTPSTJTIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstTitAvail", TxtPstTitAvail)) add(TXTPSTTITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstTitActive", TxtPstTitActive)) add(TXTPSTTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstVerAvail", TxtPstVerAvail)) add(TXTPSTVERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstVerActive", TxtPstVerActive)) add(TXTPSTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstVerViewAvail", ButPstVerViewAvail)) add(BUTPSTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstVerViewActive", ButPstVerViewActive)) add(BUTPSTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPstScoAvail", PupPstScoAvail)) add(PUPPSTSCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPstScoActive", PupPstScoActive)) add(PUPPSTSCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPstAtyAvail", PupPstAtyAvail)) add(PUPPSTATYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupPstAtyActive", PupPstAtyActive)) add(PUPPSTATYACTIVE);
	};

	return basefound;
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

PnlWznmSbsDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSho
			, const string& CptTbl
			, const string& CptCar
			, const string& CptCnd
			, const string& CptCmt
			, const string& HdgPst
			, const string& CptPstSrf
			, const string& CptPstTit
			, const string& CptPstVer
			, const string& CptPstSco
			, const string& CptPstAty
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptSho = CptSho;
	this->CptTbl = CptTbl;
	this->CptCar = CptCar;
	this->CptCnd = CptCnd;
	this->CptCmt = CptCmt;
	this->HdgPst = HdgPst;
	this->CptPstSrf = CptPstSrf;
	this->CptPstTit = CptPstTit;
	this->CptPstVer = CptPstVer;
	this->CptPstSco = CptPstSco;
	this->CptPstAty = CptPstAty;

	mask = {CPT, CPTSRF, CPTSHO, CPTTBL, CPTCAR, CPTCND, CPTCMT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY};
};

bool PnlWznmSbsDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmSbsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmSbsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSho", CptSho)) add(CPTSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTbl", CptTbl)) add(CPTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCar", CptCar)) add(CPTCAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCnd", CptCnd)) add(CPTCND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgPst", HdgPst)) add(HDGPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPstSrf", CptPstSrf)) add(CPTPSTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPstTit", CptPstTit)) add(CPTPSTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPstVer", CptPstVer)) add(CPTPSTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPstSco", CptPstSco)) add(CPTPSTSCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPstAty", CptPstAty)) add(CPTPSTATY);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmSbsDetail::DpchAppData
 ******************************************************************************/

PnlWznmSbsDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSBSDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmSbsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSbsDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSbsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSbsDetail::DpchAppDo
 ******************************************************************************/

PnlWznmSbsDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSBSDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmSbsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSbsDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSbsDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSbsDetail::DpchEngData
 ******************************************************************************/

PnlWznmSbsDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSBSDETAILDATA)
		{
	feedFPupPstAty.tag = "FeedFPupPstAty";
	feedFPupPstJti.tag = "FeedFPupPstJti";
	feedFPupPstSco.tag = "FeedFPupPstSco";
};

string PnlWznmSbsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWznmSbsDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmSbsDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupPstAty.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTATY);
		if (feedFPupPstJti.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTJTI);
		if (feedFPupPstSco.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTSCO);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupPstAty.clear();
		feedFPupPstJti.clear();
		feedFPupPstSco.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

