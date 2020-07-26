/**
	* \file PnlWznmIelDetail.cpp
	* API code for job PnlWznmIelDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWznmIelDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmIelDetail::VecVDo
 ******************************************************************************/

uint PnlWznmIelDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butimeviewclick") return BUTIMEVIEWCLICK;
	if (s == "butim2viewclick") return BUTIM2VIEWCLICK;
	if (s == "butpstviewclick") return BUTPSTVIEWCLICK;
	if (s == "butstbviewclick") return BUTSTBVIEWCLICK;
	if (s == "butvitviewclick") return BUTVITVIEWCLICK;

	return(0);
};

string PnlWznmIelDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTIMEVIEWCLICK) return("ButImeViewClick");
	if (ix == BUTIM2VIEWCLICK) return("ButIm2ViewClick");
	if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
	if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");
	if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmIelDetail::ContIac
 ******************************************************************************/

PnlWznmIelDetail::ContIac::ContIac(
			const string& TxfSho
			, const uint numFPupTyp
			, const vector<uint>& numsFLstOcc
			, const uint numFPupCty
			, const string& TxfDfv
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->numFPupTyp = numFPupTyp;
	this->numsFLstOcc = numsFLstOcc;
	this->numFPupCty = numFPupCty;
	this->TxfDfv = TxfDfv;

	mask = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC, NUMFPUPCTY, TXFDFV};
};

bool PnlWznmIelDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmIelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmIelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOcc", numsFLstOcc)) add(NUMSFLSTOCC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCty", numFPupCty)) add(NUMFPUPCTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDfv", TxfDfv)) add(TXFDFV);
	};

	return basefound;
};

void PnlWznmIelDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmIelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmIelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOcc", numsFLstOcc);
		writeUintAttr(wr, itemtag, "sref", "numFPupCty", numFPupCty);
		writeStringAttr(wr, itemtag, "sref", "TxfDfv", TxfDfv);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmIelDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (compareUintvec(numsFLstOcc, comp->numsFLstOcc)) insert(items, NUMSFLSTOCC);
	if (numFPupCty == comp->numFPupCty) insert(items, NUMFPUPCTY);
	if (TxfDfv == comp->TxfDfv) insert(items, TXFDFV);

	return(items);
};

set<uint> PnlWznmIelDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC, NUMFPUPCTY, TXFDFV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmIelDetail::ContInf
 ******************************************************************************/

PnlWznmIelDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtOcc
			, const string& TxtIme
			, const string& TxtTco
			, const string& TxtIm2
			, const string& TxtPst
			, const string& TxtStb
			, const string& TxtVit
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtOcc = TxtOcc;
	this->TxtIme = TxtIme;
	this->TxtTco = TxtTco;
	this->TxtIm2 = TxtIm2;
	this->TxtPst = TxtPst;
	this->TxtStb = TxtStb;
	this->TxtVit = TxtVit;

	mask = {TXTSRF, TXTOCC, TXTIME, TXTTCO, TXTIM2, TXTPST, TXTSTB, TXTVIT};
};

bool PnlWznmIelDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmIelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmIelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtOcc", TxtOcc)) add(TXTOCC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIme", TxtIme)) add(TXTIME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTco", TxtTco)) add(TXTTCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtIm2", TxtIm2)) add(TXTIM2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtPst", TxtPst)) add(TXTPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtStb", TxtStb)) add(TXTSTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVit", TxtVit)) add(TXTVIT);
	};

	return basefound;
};

set<uint> PnlWznmIelDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtOcc == comp->TxtOcc) insert(items, TXTOCC);
	if (TxtIme == comp->TxtIme) insert(items, TXTIME);
	if (TxtTco == comp->TxtTco) insert(items, TXTTCO);
	if (TxtIm2 == comp->TxtIm2) insert(items, TXTIM2);
	if (TxtPst == comp->TxtPst) insert(items, TXTPST);
	if (TxtStb == comp->TxtStb) insert(items, TXTSTB);
	if (TxtVit == comp->TxtVit) insert(items, TXTVIT);

	return(items);
};

set<uint> PnlWznmIelDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTOCC, TXTIME, TXTTCO, TXTIM2, TXTPST, TXTSTB, TXTVIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmIelDetail::StatApp
 ******************************************************************************/

PnlWznmIelDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstOccAlt
			, const uint LstOccNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstOccAlt = LstOccAlt;
	this->LstOccNumFirstdisp = LstOccNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTOCCALT, LSTOCCNUMFIRSTDISP};
};

bool PnlWznmIelDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmIelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmIelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOccAlt", LstOccAlt)) add(LSTOCCALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOccNumFirstdisp", LstOccNumFirstdisp)) add(LSTOCCNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmIelDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstOccAlt == comp->LstOccAlt) insert(items, LSTOCCALT);
	if (LstOccNumFirstdisp == comp->LstOccNumFirstdisp) insert(items, LSTOCCNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmIelDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTOCCALT, LSTOCCNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmIelDetail::StatShr
 ******************************************************************************/

PnlWznmIelDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool PupTypActive
			, const bool LstOccActive
			, const bool TxtImeActive
			, const bool ButImeViewAvail
			, const bool ButImeViewActive
			, const bool TxtTcoActive
			, const bool TxtIm2Active
			, const bool ButIm2ViewAvail
			, const bool ButIm2ViewActive
			, const bool PupCtyActive
			, const bool TxfDfvActive
			, const bool TxtPstActive
			, const bool ButPstViewAvail
			, const bool ButPstViewActive
			, const bool TxtStbActive
			, const bool ButStbViewAvail
			, const bool ButStbViewActive
			, const bool TxtVitActive
			, const bool ButVitViewAvail
			, const bool ButVitViewActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->PupTypActive = PupTypActive;
	this->LstOccActive = LstOccActive;
	this->TxtImeActive = TxtImeActive;
	this->ButImeViewAvail = ButImeViewAvail;
	this->ButImeViewActive = ButImeViewActive;
	this->TxtTcoActive = TxtTcoActive;
	this->TxtIm2Active = TxtIm2Active;
	this->ButIm2ViewAvail = ButIm2ViewAvail;
	this->ButIm2ViewActive = ButIm2ViewActive;
	this->PupCtyActive = PupCtyActive;
	this->TxfDfvActive = TxfDfvActive;
	this->TxtPstActive = TxtPstActive;
	this->ButPstViewAvail = ButPstViewAvail;
	this->ButPstViewActive = ButPstViewActive;
	this->TxtStbActive = TxtStbActive;
	this->ButStbViewAvail = ButStbViewAvail;
	this->ButStbViewActive = ButStbViewActive;
	this->TxtVitActive = TxtVitActive;
	this->ButVitViewAvail = ButVitViewAvail;
	this->ButVitViewActive = ButVitViewActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTIMEACTIVE, BUTIMEVIEWAVAIL, BUTIMEVIEWACTIVE, TXTTCOACTIVE, TXTIM2ACTIVE, BUTIM2VIEWAVAIL, BUTIM2VIEWACTIVE, PUPCTYACTIVE, TXFDFVACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE, TXTVITACTIVE, BUTVITVIEWAVAIL, BUTVITVIEWACTIVE};
};

bool PnlWznmIelDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmIelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmIelDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfShoActive", TxfShoActive)) add(TXFSHOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOccActive", LstOccActive)) add(LSTOCCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtImeActive", TxtImeActive)) add(TXTIMEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButImeViewAvail", ButImeViewAvail)) add(BUTIMEVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButImeViewActive", ButImeViewActive)) add(BUTIMEVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTcoActive", TxtTcoActive)) add(TXTTCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtIm2Active", TxtIm2Active)) add(TXTIM2ACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIm2ViewAvail", ButIm2ViewAvail)) add(BUTIM2VIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIm2ViewActive", ButIm2ViewActive)) add(BUTIM2VIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupCtyActive", PupCtyActive)) add(PUPCTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfDfvActive", TxfDfvActive)) add(TXFDFVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtPstActive", TxtPstActive)) add(TXTPSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstViewAvail", ButPstViewAvail)) add(BUTPSTVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstViewActive", ButPstViewActive)) add(BUTPSTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtStbActive", TxtStbActive)) add(TXTSTBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStbViewAvail", ButStbViewAvail)) add(BUTSTBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStbViewActive", ButStbViewActive)) add(BUTSTBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVitActive", TxtVitActive)) add(TXTVITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVitViewAvail", ButVitViewAvail)) add(BUTVITVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVitViewActive", ButVitViewActive)) add(BUTVITVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmIelDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstOccActive == comp->LstOccActive) insert(items, LSTOCCACTIVE);
	if (TxtImeActive == comp->TxtImeActive) insert(items, TXTIMEACTIVE);
	if (ButImeViewAvail == comp->ButImeViewAvail) insert(items, BUTIMEVIEWAVAIL);
	if (ButImeViewActive == comp->ButImeViewActive) insert(items, BUTIMEVIEWACTIVE);
	if (TxtTcoActive == comp->TxtTcoActive) insert(items, TXTTCOACTIVE);
	if (TxtIm2Active == comp->TxtIm2Active) insert(items, TXTIM2ACTIVE);
	if (ButIm2ViewAvail == comp->ButIm2ViewAvail) insert(items, BUTIM2VIEWAVAIL);
	if (ButIm2ViewActive == comp->ButIm2ViewActive) insert(items, BUTIM2VIEWACTIVE);
	if (PupCtyActive == comp->PupCtyActive) insert(items, PUPCTYACTIVE);
	if (TxfDfvActive == comp->TxfDfvActive) insert(items, TXFDFVACTIVE);
	if (TxtPstActive == comp->TxtPstActive) insert(items, TXTPSTACTIVE);
	if (ButPstViewAvail == comp->ButPstViewAvail) insert(items, BUTPSTVIEWAVAIL);
	if (ButPstViewActive == comp->ButPstViewActive) insert(items, BUTPSTVIEWACTIVE);
	if (TxtStbActive == comp->TxtStbActive) insert(items, TXTSTBACTIVE);
	if (ButStbViewAvail == comp->ButStbViewAvail) insert(items, BUTSTBVIEWAVAIL);
	if (ButStbViewActive == comp->ButStbViewActive) insert(items, BUTSTBVIEWACTIVE);
	if (TxtVitActive == comp->TxtVitActive) insert(items, TXTVITACTIVE);
	if (ButVitViewAvail == comp->ButVitViewAvail) insert(items, BUTVITVIEWAVAIL);
	if (ButVitViewActive == comp->ButVitViewActive) insert(items, BUTVITVIEWACTIVE);

	return(items);
};

set<uint> PnlWznmIelDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTIMEACTIVE, BUTIMEVIEWAVAIL, BUTIMEVIEWACTIVE, TXTTCOACTIVE, TXTIM2ACTIVE, BUTIM2VIEWAVAIL, BUTIM2VIEWACTIVE, PUPCTYACTIVE, TXFDFVACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE, TXTVITACTIVE, BUTVITVIEWAVAIL, BUTVITVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmIelDetail::Tag
 ******************************************************************************/

PnlWznmIelDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptSho
			, const string& CptTyp
			, const string& CptOcc
			, const string& CptIme
			, const string& CptTco
			, const string& CptIm2
			, const string& CptCty
			, const string& CptDfv
			, const string& CptPst
			, const string& CptStb
			, const string& CptVit
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptSho = CptSho;
	this->CptTyp = CptTyp;
	this->CptOcc = CptOcc;
	this->CptIme = CptIme;
	this->CptTco = CptTco;
	this->CptIm2 = CptIm2;
	this->CptCty = CptCty;
	this->CptDfv = CptDfv;
	this->CptPst = CptPst;
	this->CptStb = CptStb;
	this->CptVit = CptVit;

	mask = {CPT, CPTSRF, CPTSHO, CPTTYP, CPTOCC, CPTIME, CPTTCO, CPTIM2, CPTCTY, CPTDFV, CPTPST, CPTSTB, CPTVIT};
};

bool PnlWznmIelDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmIelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmIelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSho", CptSho)) add(CPTSHO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOcc", CptOcc)) add(CPTOCC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIme", CptIme)) add(CPTIME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTco", CptTco)) add(CPTTCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIm2", CptIm2)) add(CPTIM2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCty", CptCty)) add(CPTCTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDfv", CptDfv)) add(CPTDFV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPst", CptPst)) add(CPTPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStb", CptStb)) add(CPTSTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVit", CptVit)) add(CPTVIT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmIelDetail::DpchAppData
 ******************************************************************************/

PnlWznmIelDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIELDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmIelDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmIelDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmIelDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmIelDetail::DpchAppDo
 ******************************************************************************/

PnlWznmIelDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIELDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmIelDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmIelDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmIelDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmIelDetail::DpchEngData
 ******************************************************************************/

PnlWznmIelDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMIELDETAILDATA)
		{
	feedFLstOcc.tag = "FeedFLstOcc";
	feedFPupCty.tag = "FeedFPupCty";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmIelDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOCC)) ss.push_back("feedFLstOcc");
	if (has(FEEDFPUPCTY)) ss.push_back("feedFPupCty");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmIelDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmIelDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstOcc.readXML(docctx, basexpath, true)) add(FEEDFLSTOCC);
		if (feedFPupCty.readXML(docctx, basexpath, true)) add(FEEDFPUPCTY);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstOcc.clear();
		feedFPupCty.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

