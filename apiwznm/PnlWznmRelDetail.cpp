/**
	* \file PnlWznmRelDetail.cpp
	* API code for job PnlWznmRelDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmRelDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmRelDetail::VecVDo
 ******************************************************************************/

uint PnlWznmRelDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butfrsviewclick") return BUTFRSVIEWCLICK;
	if (s == "buttosviewclick") return BUTTOSVIEWCLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butopteditclick") return BUTOPTEDITCLICK;

	return(0);
};

string PnlWznmRelDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTFRSVIEWCLICK) return("ButFrsViewClick");
	if (ix == BUTTOSVIEWCLICK) return("ButTosViewClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmRelDetail::ContIac
 ******************************************************************************/

PnlWznmRelDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFLstClu
			, const string& TxfPfx
			, const vector<uint>& numsFLstOpt
			, const string& TxfOpt
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->numFLstClu = numFLstClu;
	this->TxfPfx = TxfPfx;
	this->numsFLstOpt = numsFLstOpt;
	this->TxfOpt = TxfOpt;

	mask = {NUMFPUPTYP, NUMFLSTCLU, TXFPFX, NUMSFLSTOPT, TXFOPT};
};

bool PnlWznmRelDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmRelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmRelDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPfx", TxfPfx)) add(TXFPFX);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOpt", TxfOpt)) add(TXFOPT);
	};

	return basefound;
};

void PnlWznmRelDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmRelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmRelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeStringAttr(wr, itemtag, "sref", "TxfPfx", TxfPfx);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfOpt", TxfOpt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (TxfPfx == comp->TxfPfx) insert(items, TXFPFX);
	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (TxfOpt == comp->TxfOpt) insert(items, TXFOPT);

	return(items);
};

set<uint> PnlWznmRelDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFLSTCLU, TXFPFX, NUMSFLSTOPT, TXFOPT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelDetail::ContInf
 ******************************************************************************/

PnlWznmRelDetail::ContInf::ContInf(
			const string& TxtFrt
			, const string& TxtFrs
			, const string& TxtTot
			, const string& TxtTos
			, const string& TxtClu
			, const string& TxtVer
			, const string& TxtSup
			, const string& TxtTbl
		) :
			Block()
		{
	this->TxtFrt = TxtFrt;
	this->TxtFrs = TxtFrs;
	this->TxtTot = TxtTot;
	this->TxtTos = TxtTos;
	this->TxtClu = TxtClu;
	this->TxtVer = TxtVer;
	this->TxtSup = TxtSup;
	this->TxtTbl = TxtTbl;

	mask = {TXTFRT, TXTFRS, TXTTOT, TXTTOS, TXTCLU, TXTVER, TXTSUP, TXTTBL};
};

bool PnlWznmRelDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmRelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmRelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFrt", TxtFrt)) add(TXTFRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFrs", TxtFrs)) add(TXTFRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTot", TxtTot)) add(TXTTOT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTos", TxtTos)) add(TXTTOS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTbl", TxtTbl)) add(TXTTBL);
	};

	return basefound;
};

set<uint> PnlWznmRelDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFrt == comp->TxtFrt) insert(items, TXTFRT);
	if (TxtFrs == comp->TxtFrs) insert(items, TXTFRS);
	if (TxtTot == comp->TxtTot) insert(items, TXTTOT);
	if (TxtTos == comp->TxtTos) insert(items, TXTTOS);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);

	return(items);
};

set<uint> PnlWznmRelDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFRT, TXTFRS, TXTTOT, TXTTOS, TXTCLU, TXTVER, TXTSUP, TXTTBL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelDetail::StatApp
 ******************************************************************************/

PnlWznmRelDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstCluAlt
			, const bool LstOptAlt
			, const uint LstCluNumFirstdisp
			, const uint LstOptNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->LstOptAlt = LstOptAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;
	this->LstOptNumFirstdisp = LstOptNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTCLUALT, LSTOPTALT, LSTCLUNUMFIRSTDISP, LSTOPTNUMFIRSTDISP};
};

bool PnlWznmRelDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmRelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmRelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptAlt", LstOptAlt)) add(LSTOPTALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp)) add(LSTOPTNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmRelDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (LstOptAlt == comp->LstOptAlt) insert(items, LSTOPTALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);
	if (LstOptNumFirstdisp == comp->LstOptNumFirstdisp) insert(items, LSTOPTNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmRelDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTCLUALT, LSTOPTALT, LSTCLUNUMFIRSTDISP, LSTOPTNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelDetail::StatShr
 ******************************************************************************/

PnlWznmRelDetail::StatShr::StatShr(
			const bool TxfOptValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtFrtActive
			, const bool TxtFrsActive
			, const bool ButFrsViewAvail
			, const bool ButFrsViewActive
			, const bool TxtTotActive
			, const bool TxtTosActive
			, const bool ButTosViewAvail
			, const bool ButTosViewActive
			, const bool PupTypActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtTblActive
			, const bool TxfPfxActive
			, const bool LstOptActive
			, const bool ButOptEditAvail
		) :
			Block()
		{
	this->TxfOptValid = TxfOptValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtFrtActive = TxtFrtActive;
	this->TxtFrsActive = TxtFrsActive;
	this->ButFrsViewAvail = ButFrsViewAvail;
	this->ButFrsViewActive = ButFrsViewActive;
	this->TxtTotActive = TxtTotActive;
	this->TxtTosActive = TxtTosActive;
	this->ButTosViewAvail = ButTosViewAvail;
	this->ButTosViewActive = ButTosViewActive;
	this->PupTypActive = PupTypActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxtTblActive = TxtTblActive;
	this->TxfPfxActive = TxfPfxActive;
	this->LstOptActive = LstOptActive;
	this->ButOptEditAvail = ButOptEditAvail;

	mask = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFRTACTIVE, TXTFRSACTIVE, BUTFRSVIEWAVAIL, BUTFRSVIEWACTIVE, TXTTOTACTIVE, TXTTOSACTIVE, BUTTOSVIEWAVAIL, BUTTOSVIEWACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXFPFXACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL};
};

bool PnlWznmRelDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmRelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmRelDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOptValid", TxfOptValid)) add(TXFOPTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFrtActive", TxtFrtActive)) add(TXTFRTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFrsActive", TxtFrsActive)) add(TXTFRSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFrsViewAvail", ButFrsViewAvail)) add(BUTFRSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFrsViewActive", ButFrsViewActive)) add(BUTFRSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTotActive", TxtTotActive)) add(TXTTOTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTosActive", TxtTosActive)) add(TXTTOSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTosViewAvail", ButTosViewAvail)) add(BUTTOSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTosViewActive", ButTosViewActive)) add(BUTTOSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerActive", TxtVerActive)) add(TXTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", ButVerViewAvail)) add(BUTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTblActive", TxtTblActive)) add(TXTTBLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfPfxActive", TxfPfxActive)) add(TXFPFXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptActive", LstOptActive)) add(LSTOPTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", ButOptEditAvail)) add(BUTOPTEDITAVAIL);
	};

	return basefound;
};

set<uint> PnlWznmRelDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfOptValid == comp->TxfOptValid) insert(items, TXFOPTVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtFrtActive == comp->TxtFrtActive) insert(items, TXTFRTACTIVE);
	if (TxtFrsActive == comp->TxtFrsActive) insert(items, TXTFRSACTIVE);
	if (ButFrsViewAvail == comp->ButFrsViewAvail) insert(items, BUTFRSVIEWAVAIL);
	if (ButFrsViewActive == comp->ButFrsViewActive) insert(items, BUTFRSVIEWACTIVE);
	if (TxtTotActive == comp->TxtTotActive) insert(items, TXTTOTACTIVE);
	if (TxtTosActive == comp->TxtTosActive) insert(items, TXTTOSACTIVE);
	if (ButTosViewAvail == comp->ButTosViewAvail) insert(items, BUTTOSVIEWAVAIL);
	if (ButTosViewActive == comp->ButTosViewActive) insert(items, BUTTOSVIEWACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (TxfPfxActive == comp->TxfPfxActive) insert(items, TXFPFXACTIVE);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (ButOptEditAvail == comp->ButOptEditAvail) insert(items, BUTOPTEDITAVAIL);

	return(items);
};

set<uint> PnlWznmRelDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFRTACTIVE, TXTFRSACTIVE, BUTFRSVIEWAVAIL, BUTFRSVIEWACTIVE, TXTTOTACTIVE, TXTTOSACTIVE, BUTTOSVIEWAVAIL, BUTTOSVIEWACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXFPFXACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelDetail::Tag
 ******************************************************************************/

PnlWznmRelDetail::Tag::Tag(
			const string& Cpt
			, const string& CptFrt
			, const string& CptFrs
			, const string& CptTot
			, const string& CptTos
			, const string& CptTyp
			, const string& CptClu
			, const string& CptVer
			, const string& CptSup
			, const string& CptTbl
			, const string& CptPfx
			, const string& CptOpt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptFrt = CptFrt;
	this->CptFrs = CptFrs;
	this->CptTot = CptTot;
	this->CptTos = CptTos;
	this->CptTyp = CptTyp;
	this->CptClu = CptClu;
	this->CptVer = CptVer;
	this->CptSup = CptSup;
	this->CptTbl = CptTbl;
	this->CptPfx = CptPfx;
	this->CptOpt = CptOpt;

	mask = {CPT, CPTFRT, CPTFRS, CPTTOT, CPTTOS, CPTTYP, CPTCLU, CPTVER, CPTSUP, CPTTBL, CPTPFX, CPTOPT};
};

bool PnlWznmRelDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmRelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmRelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFrt", CptFrt)) add(CPTFRT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFrs", CptFrs)) add(CPTFRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTot", CptTot)) add(CPTTOT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTos", CptTos)) add(CPTTOS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTbl", CptTbl)) add(CPTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPfx", CptPfx)) add(CPTPFX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpt", CptOpt)) add(CPTOPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmRelDetail::DpchAppData
 ******************************************************************************/

PnlWznmRelDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmRelDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmRelDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelDetail::DpchAppDo
 ******************************************************************************/

PnlWznmRelDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmRelDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmRelDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelDetail::DpchEngData
 ******************************************************************************/

PnlWznmRelDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRELDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFLstOpt.tag = "FeedFLstOpt";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmRelDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmRelDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFLstOpt.readXML(docctx, basexpath, true)) add(FEEDFLSTOPT);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFLstOpt.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

