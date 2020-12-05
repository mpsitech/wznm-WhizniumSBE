/**
	* \file PnlWznmVecDetail.cpp
	* API code for job PnlWznmVecDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmVecDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVecDetail::VecVDo
 ******************************************************************************/

uint PnlWznmVecDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;
	if (s == "buttgreditclick") return BUTTGREDITCLICK;
	if (s == "butopteditclick") return BUTOPTEDITCLICK;
	if (s == "butpstnewclick") return BUTPSTNEWCLICK;
	if (s == "butpstdeleteclick") return BUTPSTDELETECLICK;
	if (s == "butpstjtieditclick") return BUTPSTJTIEDITCLICK;
	if (s == "butpstverviewclick") return BUTPSTVERVIEWCLICK;

	return(0);
};

string PnlWznmVecDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	if (ix == BUTTGREDITCLICK) return("ButTgrEditClick");
	if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");
	if (ix == BUTPSTNEWCLICK) return("ButPstNewClick");
	if (ix == BUTPSTDELETECLICK) return("ButPstDeleteClick");
	if (ix == BUTPSTJTIEDITCLICK) return("ButPstJtiEditClick");
	if (ix == BUTPSTVERVIEWCLICK) return("ButPstVerViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmVecDetail::ContIac
 ******************************************************************************/

PnlWznmVecDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFPupHkt
			, const uint numFPupTgr
			, const string& TxfTgr
			, const vector<uint>& numsFLstOpt
			, const string& TxfOpt
			, const uint numFPupPstJti
			, const uint numFPupPstSco
			, const uint numFPupPstAty
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->numFPupHkt = numFPupHkt;
	this->numFPupTgr = numFPupTgr;
	this->TxfTgr = TxfTgr;
	this->numsFLstOpt = numsFLstOpt;
	this->TxfOpt = TxfOpt;
	this->numFPupPstJti = numFPupPstJti;
	this->numFPupPstSco = numFPupPstSco;
	this->numFPupPstAty = numFPupPstAty;

	mask = {NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTGR, TXFTGR, NUMSFLSTOPT, TXFOPT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY};
};

bool PnlWznmVecDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmVecDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmVecDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTgr", numFPupTgr)) add(NUMFPUPTGR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTgr", TxfTgr)) add(TXFTGR);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOpt", TxfOpt)) add(TXFOPT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstJti", numFPupPstJti)) add(NUMFPUPPSTJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstSco", numFPupPstSco)) add(NUMFPUPPSTSCO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPstAty", numFPupPstAty)) add(NUMFPUPPSTATY);
	};

	return basefound;
};

void PnlWznmVecDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmVecDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmVecDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeUintAttr(wr, itemtag, "sref", "numFPupTgr", numFPupTgr);
		writeStringAttr(wr, itemtag, "sref", "TxfTgr", TxfTgr);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfOpt", TxfOpt);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstJti", numFPupPstJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstSco", numFPupPstSco);
		writeUintAttr(wr, itemtag, "sref", "numFPupPstAty", numFPupPstAty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVecDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (numFPupTgr == comp->numFPupTgr) insert(items, NUMFPUPTGR);
	if (TxfTgr == comp->TxfTgr) insert(items, TXFTGR);
	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (TxfOpt == comp->TxfOpt) insert(items, TXFOPT);
	if (numFPupPstJti == comp->numFPupPstJti) insert(items, NUMFPUPPSTJTI);
	if (numFPupPstSco == comp->numFPupPstSco) insert(items, NUMFPUPPSTSCO);
	if (numFPupPstAty == comp->numFPupPstAty) insert(items, NUMFPUPPSTATY);

	return(items);
};

set<uint> PnlWznmVecDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTGR, TXFTGR, NUMSFLSTOPT, TXFOPT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecDetail::ContInf
 ******************************************************************************/

PnlWznmVecDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVer
			, const string& TxtHku
			, const string& TxtPstSrf
			, const string& TxtPstTit
			, const string& TxtPstVer
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtVer = TxtVer;
	this->TxtHku = TxtHku;
	this->TxtPstSrf = TxtPstSrf;
	this->TxtPstTit = TxtPstTit;
	this->TxtPstVer = TxtPstVer;

	mask = {TXTSRF, TXTVER, TXTHKU, TXTPSTSRF, TXTPSTTIT, TXTPSTVER};
};

bool PnlWznmVecDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmVecDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmVecDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHku", TxtHku)) add(TXTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstSrf", TxtPstSrf)) add(TXTPSTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstTit", TxtPstTit)) add(TXTPSTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPstVer", TxtPstVer)) add(TXTPSTVER);
	};

	return basefound;
};

set<uint> PnlWznmVecDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtHku == comp->TxtHku) insert(items, TXTHKU);
	if (TxtPstSrf == comp->TxtPstSrf) insert(items, TXTPSTSRF);
	if (TxtPstTit == comp->TxtPstTit) insert(items, TXTPSTTIT);
	if (TxtPstVer == comp->TxtPstVer) insert(items, TXTPSTVER);

	return(items);
};

set<uint> PnlWznmVecDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVER, TXTHKU, TXTPSTSRF, TXTPSTTIT, TXTPSTVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecDetail::StatApp
 ******************************************************************************/

PnlWznmVecDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool PupTgrAlt
			, const bool LstOptAlt
			, const uint LstOptNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->PupTgrAlt = PupTgrAlt;
	this->LstOptAlt = LstOptAlt;
	this->LstOptNumFirstdisp = LstOptNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, PUPTGRALT, LSTOPTALT, LSTOPTNUMFIRSTDISP};
};

bool PnlWznmVecDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmVecDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmVecDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTgrAlt", PupTgrAlt)) add(PUPTGRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptAlt", LstOptAlt)) add(LSTOPTALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp)) add(LSTOPTNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmVecDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (PupTgrAlt == comp->PupTgrAlt) insert(items, PUPTGRALT);
	if (LstOptAlt == comp->LstOptAlt) insert(items, LSTOPTALT);
	if (LstOptNumFirstdisp == comp->LstOptNumFirstdisp) insert(items, LSTOPTNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmVecDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, PUPTGRALT, LSTOPTALT, LSTOPTNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecDetail::StatShr
 ******************************************************************************/

PnlWznmVecDetail::StatShr::StatShr(
			const bool TxfTgrValid
			, const bool TxfOptValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtHkuActive
			, const bool ButHkuViewAvail
			, const bool ButHkuViewActive
			, const bool PupTgrActive
			, const bool ButTgrEditAvail
			, const bool LstOptActive
			, const bool ButOptEditAvail
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
	this->TxfTgrValid = TxfTgrValid;
	this->TxfOptValid = TxfOptValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtHkuActive = TxtHkuActive;
	this->ButHkuViewAvail = ButHkuViewAvail;
	this->ButHkuViewActive = ButHkuViewActive;
	this->PupTgrActive = PupTgrActive;
	this->ButTgrEditAvail = ButTgrEditAvail;
	this->LstOptActive = LstOptActive;
	this->ButOptEditAvail = ButOptEditAvail;
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

	mask = {TXFTGRVALID, TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, PUPTGRACTIVE, BUTTGREDITAVAIL, LSTOPTACTIVE, BUTOPTEDITAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE};
};

bool PnlWznmVecDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmVecDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmVecDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTgrValid", TxfTgrValid)) add(TXFTGRVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOptValid", TxfOptValid)) add(TXFOPTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerActive", TxtVerActive)) add(TXTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", ButVerViewAvail)) add(BUTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtHkuActive", TxtHkuActive)) add(TXTHKUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHkuViewAvail", ButHkuViewAvail)) add(BUTHKUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHkuViewActive", ButHkuViewActive)) add(BUTHKUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTgrActive", PupTgrActive)) add(PUPTGRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTgrEditAvail", ButTgrEditAvail)) add(BUTTGREDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptActive", LstOptActive)) add(LSTOPTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", ButOptEditAvail)) add(BUTOPTEDITAVAIL);
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

set<uint> PnlWznmVecDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfTgrValid == comp->TxfTgrValid) insert(items, TXFTGRVALID);
	if (TxfOptValid == comp->TxfOptValid) insert(items, TXFOPTVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtHkuActive == comp->TxtHkuActive) insert(items, TXTHKUACTIVE);
	if (ButHkuViewAvail == comp->ButHkuViewAvail) insert(items, BUTHKUVIEWAVAIL);
	if (ButHkuViewActive == comp->ButHkuViewActive) insert(items, BUTHKUVIEWACTIVE);
	if (PupTgrActive == comp->PupTgrActive) insert(items, PUPTGRACTIVE);
	if (ButTgrEditAvail == comp->ButTgrEditAvail) insert(items, BUTTGREDITAVAIL);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (ButOptEditAvail == comp->ButOptEditAvail) insert(items, BUTOPTEDITAVAIL);
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

set<uint> PnlWznmVecDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTGRVALID, TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, PUPTGRACTIVE, BUTTGREDITAVAIL, LSTOPTACTIVE, BUTOPTEDITAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVecDetail::Tag
 ******************************************************************************/

PnlWznmVecDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptVer
			, const string& CptHku
			, const string& CptTgr
			, const string& CptOpt
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
	this->CptTyp = CptTyp;
	this->CptVer = CptVer;
	this->CptHku = CptHku;
	this->CptTgr = CptTgr;
	this->CptOpt = CptOpt;
	this->HdgPst = HdgPst;
	this->CptPstSrf = CptPstSrf;
	this->CptPstTit = CptPstTit;
	this->CptPstVer = CptPstVer;
	this->CptPstSco = CptPstSco;
	this->CptPstAty = CptPstAty;

	mask = {CPT, CPTSRF, CPTTYP, CPTVER, CPTHKU, CPTTGR, CPTOPT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY};
};

bool PnlWznmVecDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmVecDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmVecDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHku", CptHku)) add(CPTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTgr", CptTgr)) add(CPTTGR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpt", CptOpt)) add(CPTOPT);
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
 class PnlWznmVecDetail::DpchAppData
 ******************************************************************************/

PnlWznmVecDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVECDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmVecDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVecDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVecDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVecDetail::DpchAppDo
 ******************************************************************************/

PnlWznmVecDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVECDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmVecDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVecDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVecDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVecDetail::DpchEngData
 ******************************************************************************/

PnlWznmVecDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVECDETAILDATA)
		{
	feedFLstOpt.tag = "FeedFLstOpt";
	feedFPupHkt.tag = "FeedFPupHkt";
	feedFPupPstAty.tag = "FeedFPupPstAty";
	feedFPupPstJti.tag = "FeedFPupPstJti";
	feedFPupPstSco.tag = "FeedFPupPstSco";
	feedFPupTgr.tag = "FeedFPupTgr";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmVecDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(FEEDFPUPHKT)) ss.push_back("feedFPupHkt");
	if (has(FEEDFPUPPSTATY)) ss.push_back("feedFPupPstAty");
	if (has(FEEDFPUPPSTJTI)) ss.push_back("feedFPupPstJti");
	if (has(FEEDFPUPPSTSCO)) ss.push_back("feedFPupPstSco");
	if (has(FEEDFPUPTGR)) ss.push_back("feedFPupTgr");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVecDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmVecDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstOpt.readXML(docctx, basexpath, true)) add(FEEDFLSTOPT);
		if (feedFPupHkt.readXML(docctx, basexpath, true)) add(FEEDFPUPHKT);
		if (feedFPupPstAty.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTATY);
		if (feedFPupPstJti.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTJTI);
		if (feedFPupPstSco.readXML(docctx, basexpath, true)) add(FEEDFPUPPSTSCO);
		if (feedFPupTgr.readXML(docctx, basexpath, true)) add(FEEDFPUPTGR);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstOpt.clear();
		feedFPupHkt.clear();
		feedFPupPstAty.clear();
		feedFPupPstJti.clear();
		feedFPupPstSco.clear();
		feedFPupTgr.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

