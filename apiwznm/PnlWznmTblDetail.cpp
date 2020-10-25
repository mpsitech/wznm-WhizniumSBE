/**
	* \file PnlWznmTblDetail.cpp
	* API code for job PnlWznmTblDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmTblDetail.h"

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

bool PnlWznmTblDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmTblDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmTblDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtCar", TxtCar)) add(TXTCAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstSrf", TxtPstSrf)) add(TXTPSTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstTit", TxtPstTit)) add(TXTPSTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstVer", TxtPstVer)) add(TXTPSTVER);
	};

	return basefound;
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

PnlWznmTblDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstUnqAlt
			, const uint LstUnqNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstUnqAlt = LstUnqAlt;
	this->LstUnqNumFirstdisp = LstUnqNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTUNQALT, LSTUNQNUMFIRSTDISP};
};

bool PnlWznmTblDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmTblDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmTblDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUnqAlt", LstUnqAlt)) add(LSTUNQALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUnqNumFirstdisp", LstUnqNumFirstdisp)) add(LSTUNQNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmTblDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstUnqAlt == comp->LstUnqAlt) insert(items, LSTUNQALT);
	if (LstUnqNumFirstdisp == comp->LstUnqNumFirstdisp) insert(items, LSTUNQNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmTblDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTUNQALT, LSTUNQNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlWznmTblDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmTblDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmTblDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfUnqValid", TxfUnqValid)) add(TXFUNQVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfShoActive", TxfShoActive)) add(TXFSHOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerActive", TxtVerActive)) add(TXTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", ButVerViewAvail)) add(BUTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCarAvail", TxtCarAvail)) add(TXTCARAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtCarActive", TxtCarActive)) add(TXTCARACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCarViewAvail", ButCarViewAvail)) add(BUTCARVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCarViewActive", ButCarViewActive)) add(BUTCARVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUnqAvail", LstUnqAvail)) add(LSTUNQAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUnqActive", LstUnqActive)) add(LSTUNQACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUnqViewAvail", ButUnqViewAvail)) add(BUTUNQVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUnqViewActive", ButUnqViewActive)) add(BUTUNQVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SepPstAvail", SepPstAvail)) add(SEPPSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "HdgPstAvail", HdgPstAvail)) add(HDGPSTAVAIL);
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

PnlWznmTblDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSho
			, const string& CptTyp
			, const string& CptVer
			, const string& CptReu
			, const string& CptCar
			, const string& CptUnq
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
	this->CptTyp = CptTyp;
	this->CptVer = CptVer;
	this->CptReu = CptReu;
	this->CptCar = CptCar;
	this->CptUnq = CptUnq;
	this->CptCmt = CptCmt;
	this->HdgPst = HdgPst;
	this->CptPstSrf = CptPstSrf;
	this->CptPstTit = CptPstTit;
	this->CptPstVer = CptPstVer;
	this->CptPstSco = CptPstSco;
	this->CptPstAty = CptPstAty;

	mask = {CPT, CPTSRF, CPTSHO, CPTTYP, CPTVER, CPTREU, CPTCAR, CPTUNQ, CPTCMT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY};
};

bool PnlWznmTblDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmTblDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmTblDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSho", CptSho)) add(CPTSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCar", CptCar)) add(CPTCAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUnq", CptUnq)) add(CPTUNQ);
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
 class PnlWznmTblDetail::DpchAppData
 ******************************************************************************/

PnlWznmTblDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmTblDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTblDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblDetail::DpchAppDo
 ******************************************************************************/

PnlWznmTblDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmTblDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTblDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblDetail::DpchEngData
 ******************************************************************************/

PnlWznmTblDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTBLDETAILDATA)
		{
	feedFLstUnq.tag = "FeedFLstUnq";
	feedFPupPstAty.tag = "FeedFPupPstAty";
	feedFPupPstJti.tag = "FeedFPupPstJti";
	feedFPupPstSco.tag = "FeedFPupPstSco";
	feedFPupRet.tag = "FeedFPupRet";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmTblDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWznmTblDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmTblDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstUnq.readXML(docctx, basexpath, true)) add(FEEDFLSTUNQ);
		if (feedFPupPstAty.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTATY);
		if (feedFPupPstJti.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTJTI);
		if (feedFPupPstSco.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTSCO);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstUnq.clear();
		feedFPupPstAty.clear();
		feedFPupPstJti.clear();
		feedFPupPstSco.clear();
		feedFPupRet.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

