/**
	* \file PnlWznmTcoDetail.cpp
	* API code for job PnlWznmTcoDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWznmTcoDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTcoDetail::VecVDo
 ******************************************************************************/

uint PnlWznmTcoDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "buttblviewclick") return BUTTBLVIEWCLICK;
	if (s == "butsbsviewclick") return BUTSBSVIEWCLICK;
	if (s == "butrelviewclick") return BUTRELVIEWCLICK;
	if (s == "butfcuviewclick") return BUTFCUVIEWCLICK;
	if (s == "butopteditclick") return BUTOPTEDITCLICK;

	return(0);
};

string PnlWznmTcoDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTTBLVIEWCLICK) return("ButTblViewClick");
	if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
	if (ix == BUTRELVIEWCLICK) return("ButRelViewClick");
	if (ix == BUTFCUVIEWCLICK) return("ButFcuViewClick");
	if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmTcoDetail::ContIac
 ******************************************************************************/

PnlWznmTcoDetail::ContIac::ContIac(
			const string& TxfSho
			, const uint numFPupTyp
			, const uint numFPupFct
			, const uint numFPupSty
			, const uint numFPupAxf
			, const vector<uint>& numsFLstOpt
			, const string& TxfOpt
			, const bool ChkPnc
			, const bool ChkEpo
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->numFPupTyp = numFPupTyp;
	this->numFPupFct = numFPupFct;
	this->numFPupSty = numFPupSty;
	this->numFPupAxf = numFPupAxf;
	this->numsFLstOpt = numsFLstOpt;
	this->TxfOpt = TxfOpt;
	this->ChkPnc = ChkPnc;
	this->ChkEpo = ChkEpo;

	mask = {TXFSHO, NUMFPUPTYP, NUMFPUPFCT, NUMFPUPSTY, NUMFPUPAXF, NUMSFLSTOPT, TXFOPT, CHKPNC, CHKEPO};
};

bool PnlWznmTcoDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmTcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmTcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupFct", numFPupFct)) add(NUMFPUPFCT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSty", numFPupSty)) add(NUMFPUPSTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAxf", numFPupAxf)) add(NUMFPUPAXF);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOpt", TxfOpt)) add(TXFOPT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkPnc", ChkPnc)) add(CHKPNC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkEpo", ChkEpo)) add(CHKEPO);
	};

	return basefound;
};

void PnlWznmTcoDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmTcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmTcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupFct", numFPupFct);
		writeUintAttr(wr, itemtag, "sref", "numFPupSty", numFPupSty);
		writeUintAttr(wr, itemtag, "sref", "numFPupAxf", numFPupAxf);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfOpt", TxfOpt);
		writeBoolAttr(wr, itemtag, "sref", "ChkPnc", ChkPnc);
		writeBoolAttr(wr, itemtag, "sref", "ChkEpo", ChkEpo);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTcoDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupFct == comp->numFPupFct) insert(items, NUMFPUPFCT);
	if (numFPupSty == comp->numFPupSty) insert(items, NUMFPUPSTY);
	if (numFPupAxf == comp->numFPupAxf) insert(items, NUMFPUPAXF);
	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (TxfOpt == comp->TxfOpt) insert(items, TXFOPT);
	if (ChkPnc == comp->ChkPnc) insert(items, CHKPNC);
	if (ChkEpo == comp->ChkEpo) insert(items, CHKEPO);

	return(items);
};

set<uint> PnlWznmTcoDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, NUMFPUPTYP, NUMFPUPFCT, NUMFPUPSTY, NUMFPUPAXF, NUMSFLSTOPT, TXFOPT, CHKPNC, CHKEPO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoDetail::ContInf
 ******************************************************************************/

PnlWznmTcoDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTbl
			, const string& TxtSbs
			, const string& TxtRel
			, const string& TxtFcu
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTbl = TxtTbl;
	this->TxtSbs = TxtSbs;
	this->TxtRel = TxtRel;
	this->TxtFcu = TxtFcu;

	mask = {TXTSRF, TXTTBL, TXTSBS, TXTREL, TXTFCU};
};

bool PnlWznmTcoDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmTcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmTcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTbl", TxtTbl)) add(TXTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSbs", TxtSbs)) add(TXTSBS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRel", TxtRel)) add(TXTREL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFcu", TxtFcu)) add(TXTFCU);
	};

	return basefound;
};

set<uint> PnlWznmTcoDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtSbs == comp->TxtSbs) insert(items, TXTSBS);
	if (TxtRel == comp->TxtRel) insert(items, TXTREL);
	if (TxtFcu == comp->TxtFcu) insert(items, TXTFCU);

	return(items);
};

set<uint> PnlWznmTcoDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTBL, TXTSBS, TXTREL, TXTFCU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoDetail::StatApp
 ******************************************************************************/

PnlWznmTcoDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstOptAlt
			, const uint LstOptNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstOptAlt = LstOptAlt;
	this->LstOptNumFirstdisp = LstOptNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTOPTALT, LSTOPTNUMFIRSTDISP};
};

bool PnlWznmTcoDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmTcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmTcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptAlt", LstOptAlt)) add(LSTOPTALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp)) add(LSTOPTNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmTcoDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstOptAlt == comp->LstOptAlt) insert(items, LSTOPTALT);
	if (LstOptNumFirstdisp == comp->LstOptNumFirstdisp) insert(items, LSTOPTNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmTcoDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTOPTALT, LSTOPTNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoDetail::StatShr
 ******************************************************************************/

PnlWznmTcoDetail::StatShr::StatShr(
			const bool TxfOptValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool PupTypActive
			, const bool TxtTblActive
			, const bool ButTblViewAvail
			, const bool ButTblViewActive
			, const bool TxtSbsAvail
			, const bool TxtSbsActive
			, const bool ButSbsViewAvail
			, const bool ButSbsViewActive
			, const bool TxtRelAvail
			, const bool TxtRelActive
			, const bool ButRelViewAvail
			, const bool ButRelViewActive
			, const bool TxtFcuAvail
			, const bool TxtFcuActive
			, const bool ButFcuViewAvail
			, const bool ButFcuViewActive
			, const bool PupStyActive
			, const bool PupAxfActive
			, const bool LstOptActive
			, const bool ButOptEditAvail
			, const bool ChkPncActive
			, const bool ChkEpoActive
		) :
			Block()
		{
	this->TxfOptValid = TxfOptValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->PupTypActive = PupTypActive;
	this->TxtTblActive = TxtTblActive;
	this->ButTblViewAvail = ButTblViewAvail;
	this->ButTblViewActive = ButTblViewActive;
	this->TxtSbsAvail = TxtSbsAvail;
	this->TxtSbsActive = TxtSbsActive;
	this->ButSbsViewAvail = ButSbsViewAvail;
	this->ButSbsViewActive = ButSbsViewActive;
	this->TxtRelAvail = TxtRelAvail;
	this->TxtRelActive = TxtRelActive;
	this->ButRelViewAvail = ButRelViewAvail;
	this->ButRelViewActive = ButRelViewActive;
	this->TxtFcuAvail = TxtFcuAvail;
	this->TxtFcuActive = TxtFcuActive;
	this->ButFcuViewAvail = ButFcuViewAvail;
	this->ButFcuViewActive = ButFcuViewActive;
	this->PupStyActive = PupStyActive;
	this->PupAxfActive = PupAxfActive;
	this->LstOptActive = LstOptActive;
	this->ButOptEditAvail = ButOptEditAvail;
	this->ChkPncActive = ChkPncActive;
	this->ChkEpoActive = ChkEpoActive;

	mask = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, BUTTBLVIEWAVAIL, BUTTBLVIEWACTIVE, TXTSBSAVAIL, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, TXTRELAVAIL, TXTRELACTIVE, BUTRELVIEWAVAIL, BUTRELVIEWACTIVE, TXTFCUAVAIL, TXTFCUACTIVE, BUTFCUVIEWAVAIL, BUTFCUVIEWACTIVE, PUPSTYACTIVE, PUPAXFACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, CHKPNCACTIVE, CHKEPOACTIVE};
};

bool PnlWznmTcoDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmTcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmTcoDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOptValid", TxfOptValid)) add(TXFOPTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfShoActive", TxfShoActive)) add(TXFSHOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTblActive", TxtTblActive)) add(TXTTBLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTblViewAvail", ButTblViewAvail)) add(BUTTBLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTblViewActive", ButTblViewActive)) add(BUTTBLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSbsAvail", TxtSbsAvail)) add(TXTSBSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSbsActive", TxtSbsActive)) add(TXTSBSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSbsViewAvail", ButSbsViewAvail)) add(BUTSBSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSbsViewActive", ButSbsViewActive)) add(BUTSBSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtRelAvail", TxtRelAvail)) add(TXTRELAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtRelActive", TxtRelActive)) add(TXTRELACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRelViewAvail", ButRelViewAvail)) add(BUTRELVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRelViewActive", ButRelViewActive)) add(BUTRELVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFcuAvail", TxtFcuAvail)) add(TXTFCUAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFcuActive", TxtFcuActive)) add(TXTFCUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFcuViewAvail", ButFcuViewAvail)) add(BUTFCUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFcuViewActive", ButFcuViewActive)) add(BUTFCUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupStyActive", PupStyActive)) add(PUPSTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupAxfActive", PupAxfActive)) add(PUPAXFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptActive", LstOptActive)) add(LSTOPTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", ButOptEditAvail)) add(BUTOPTEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkPncActive", ChkPncActive)) add(CHKPNCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkEpoActive", ChkEpoActive)) add(CHKEPOACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmTcoDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfOptValid == comp->TxfOptValid) insert(items, TXFOPTVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (ButTblViewAvail == comp->ButTblViewAvail) insert(items, BUTTBLVIEWAVAIL);
	if (ButTblViewActive == comp->ButTblViewActive) insert(items, BUTTBLVIEWACTIVE);
	if (TxtSbsAvail == comp->TxtSbsAvail) insert(items, TXTSBSAVAIL);
	if (TxtSbsActive == comp->TxtSbsActive) insert(items, TXTSBSACTIVE);
	if (ButSbsViewAvail == comp->ButSbsViewAvail) insert(items, BUTSBSVIEWAVAIL);
	if (ButSbsViewActive == comp->ButSbsViewActive) insert(items, BUTSBSVIEWACTIVE);
	if (TxtRelAvail == comp->TxtRelAvail) insert(items, TXTRELAVAIL);
	if (TxtRelActive == comp->TxtRelActive) insert(items, TXTRELACTIVE);
	if (ButRelViewAvail == comp->ButRelViewAvail) insert(items, BUTRELVIEWAVAIL);
	if (ButRelViewActive == comp->ButRelViewActive) insert(items, BUTRELVIEWACTIVE);
	if (TxtFcuAvail == comp->TxtFcuAvail) insert(items, TXTFCUAVAIL);
	if (TxtFcuActive == comp->TxtFcuActive) insert(items, TXTFCUACTIVE);
	if (ButFcuViewAvail == comp->ButFcuViewAvail) insert(items, BUTFCUVIEWAVAIL);
	if (ButFcuViewActive == comp->ButFcuViewActive) insert(items, BUTFCUVIEWACTIVE);
	if (PupStyActive == comp->PupStyActive) insert(items, PUPSTYACTIVE);
	if (PupAxfActive == comp->PupAxfActive) insert(items, PUPAXFACTIVE);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (ButOptEditAvail == comp->ButOptEditAvail) insert(items, BUTOPTEDITAVAIL);
	if (ChkPncActive == comp->ChkPncActive) insert(items, CHKPNCACTIVE);
	if (ChkEpoActive == comp->ChkEpoActive) insert(items, CHKEPOACTIVE);

	return(items);
};

set<uint> PnlWznmTcoDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, BUTTBLVIEWAVAIL, BUTTBLVIEWACTIVE, TXTSBSAVAIL, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, TXTRELAVAIL, TXTRELACTIVE, BUTRELVIEWAVAIL, BUTRELVIEWACTIVE, TXTFCUAVAIL, TXTFCUACTIVE, BUTFCUVIEWAVAIL, BUTFCUVIEWACTIVE, PUPSTYACTIVE, PUPAXFACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, CHKPNCACTIVE, CHKEPOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoDetail::Tag
 ******************************************************************************/

PnlWznmTcoDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSho
			, const string& CptTyp
			, const string& CptTbl
			, const string& CptSbs
			, const string& CptRel
			, const string& CptFcu
			, const string& CptSty
			, const string& CptAxf
			, const string& CptOpt
			, const string& CptPnc
			, const string& CptEpo
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptSho = CptSho;
	this->CptTyp = CptTyp;
	this->CptTbl = CptTbl;
	this->CptSbs = CptSbs;
	this->CptRel = CptRel;
	this->CptFcu = CptFcu;
	this->CptSty = CptSty;
	this->CptAxf = CptAxf;
	this->CptOpt = CptOpt;
	this->CptPnc = CptPnc;
	this->CptEpo = CptEpo;

	mask = {CPT, CPTSRF, CPTSHO, CPTTYP, CPTTBL, CPTSBS, CPTREL, CPTFCU, CPTSTY, CPTAXF, CPTOPT, CPTPNC, CPTEPO};
};

bool PnlWznmTcoDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmTcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmTcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSho", CptSho)) add(CPTSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTbl", CptTbl)) add(CPTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSbs", CptSbs)) add(CPTSBS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRel", CptRel)) add(CPTREL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFcu", CptFcu)) add(CPTFCU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSty", CptSty)) add(CPTSTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAxf", CptAxf)) add(CPTAXF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpt", CptOpt)) add(CPTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPnc", CptPnc)) add(CPTPNC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEpo", CptEpo)) add(CPTEPO);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmTcoDetail::DpchAppData
 ******************************************************************************/

PnlWznmTcoDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTCODETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmTcoDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTcoDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTcoDetail::DpchAppDo
 ******************************************************************************/

PnlWznmTcoDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTCODETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmTcoDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTcoDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTcoDetail::DpchEngData
 ******************************************************************************/

PnlWznmTcoDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTCODETAILDATA)
		{
	feedFLstOpt.tag = "FeedFLstOpt";
	feedFPupAxf.tag = "FeedFPupAxf";
	feedFPupFct.tag = "FeedFPupFct";
	feedFPupSty.tag = "FeedFPupSty";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmTcoDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(FEEDFPUPAXF)) ss.push_back("feedFPupAxf");
	if (has(FEEDFPUPFCT)) ss.push_back("feedFPupFct");
	if (has(FEEDFPUPSTY)) ss.push_back("feedFPupSty");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmTcoDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstOpt.readXML(docctx, basexpath, true)) add(FEEDFLSTOPT);
		if (feedFPupAxf.readXML(docctx, basexpath, true)) add(FEEDFPUPAXF);
		if (feedFPupFct.readXML(docctx, basexpath, true)) add(FEEDFPUPFCT);
		if (feedFPupSty.readXML(docctx, basexpath, true)) add(FEEDFPUPSTY);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstOpt.clear();
		feedFPupAxf.clear();
		feedFPupFct.clear();
		feedFPupSty.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

