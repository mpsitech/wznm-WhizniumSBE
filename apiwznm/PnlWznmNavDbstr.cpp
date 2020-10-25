/**
	* \file PnlWznmNavDbstr.cpp
	* API code for job PnlWznmNavDbstr (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmNavDbstr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavDbstr::VecVDo
 ******************************************************************************/

uint PnlWznmNavDbstr::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "buttblviewclick") return BUTTBLVIEWCLICK;
	if (s == "buttblnewcrdclick") return BUTTBLNEWCRDCLICK;
	if (s == "buttcoviewclick") return BUTTCOVIEWCLICK;
	if (s == "buttconewcrdclick") return BUTTCONEWCRDCLICK;
	if (s == "butsbsviewclick") return BUTSBSVIEWCLICK;
	if (s == "butsbsnewcrdclick") return BUTSBSNEWCRDCLICK;
	if (s == "butrelviewclick") return BUTRELVIEWCLICK;
	if (s == "butrelnewcrdclick") return BUTRELNEWCRDCLICK;
	if (s == "butvecviewclick") return BUTVECVIEWCLICK;
	if (s == "butvecnewcrdclick") return BUTVECNEWCRDCLICK;
	if (s == "butvitviewclick") return BUTVITVIEWCLICK;
	if (s == "butvitnewcrdclick") return BUTVITNEWCRDCLICK;
	if (s == "butchkviewclick") return BUTCHKVIEWCLICK;
	if (s == "butchknewcrdclick") return BUTCHKNEWCRDCLICK;
	if (s == "butstbviewclick") return BUTSTBVIEWCLICK;
	if (s == "butstbnewcrdclick") return BUTSTBNEWCRDCLICK;
	if (s == "butiexviewclick") return BUTIEXVIEWCLICK;
	if (s == "butiexnewcrdclick") return BUTIEXNEWCRDCLICK;
	if (s == "butimeviewclick") return BUTIMEVIEWCLICK;
	if (s == "butimenewcrdclick") return BUTIMENEWCRDCLICK;
	if (s == "butielviewclick") return BUTIELVIEWCLICK;

	return(0);
};

string PnlWznmNavDbstr::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTTBLVIEWCLICK) return("ButTblViewClick");
	if (ix == BUTTBLNEWCRDCLICK) return("ButTblNewcrdClick");
	if (ix == BUTTCOVIEWCLICK) return("ButTcoViewClick");
	if (ix == BUTTCONEWCRDCLICK) return("ButTcoNewcrdClick");
	if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
	if (ix == BUTSBSNEWCRDCLICK) return("ButSbsNewcrdClick");
	if (ix == BUTRELVIEWCLICK) return("ButRelViewClick");
	if (ix == BUTRELNEWCRDCLICK) return("ButRelNewcrdClick");
	if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
	if (ix == BUTVECNEWCRDCLICK) return("ButVecNewcrdClick");
	if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");
	if (ix == BUTVITNEWCRDCLICK) return("ButVitNewcrdClick");
	if (ix == BUTCHKVIEWCLICK) return("ButChkViewClick");
	if (ix == BUTCHKNEWCRDCLICK) return("ButChkNewcrdClick");
	if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");
	if (ix == BUTSTBNEWCRDCLICK) return("ButStbNewcrdClick");
	if (ix == BUTIEXVIEWCLICK) return("ButIexViewClick");
	if (ix == BUTIEXNEWCRDCLICK) return("ButIexNewcrdClick");
	if (ix == BUTIMEVIEWCLICK) return("ButImeViewClick");
	if (ix == BUTIMENEWCRDCLICK) return("ButImeNewcrdClick");
	if (ix == BUTIELVIEWCLICK) return("ButIelViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavDbstr::ContIac
 ******************************************************************************/

PnlWznmNavDbstr::ContIac::ContIac(
			const uint numFLstTbl
			, const uint numFLstTco
			, const uint numFLstSbs
			, const uint numFLstRel
			, const uint numFLstVec
			, const uint numFLstVit
			, const uint numFLstChk
			, const uint numFLstStb
			, const uint numFLstIex
			, const uint numFLstIme
			, const uint numFLstIel
		) :
			Block()
		{
	this->numFLstTbl = numFLstTbl;
	this->numFLstTco = numFLstTco;
	this->numFLstSbs = numFLstSbs;
	this->numFLstRel = numFLstRel;
	this->numFLstVec = numFLstVec;
	this->numFLstVit = numFLstVit;
	this->numFLstChk = numFLstChk;
	this->numFLstStb = numFLstStb;
	this->numFLstIex = numFLstIex;
	this->numFLstIme = numFLstIme;
	this->numFLstIel = numFLstIel;

	mask = {NUMFLSTTBL, NUMFLSTTCO, NUMFLSTSBS, NUMFLSTREL, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCHK, NUMFLSTSTB, NUMFLSTIEX, NUMFLSTIME, NUMFLSTIEL};
};

bool PnlWznmNavDbstr::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavDbstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavDbstr";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTbl", numFLstTbl)) add(NUMFLSTTBL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTco", numFLstTco)) add(NUMFLSTTCO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSbs", numFLstSbs)) add(NUMFLSTSBS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRel", numFLstRel)) add(NUMFLSTREL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVec", numFLstVec)) add(NUMFLSTVEC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVit", numFLstVit)) add(NUMFLSTVIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstChk", numFLstChk)) add(NUMFLSTCHK);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstStb", numFLstStb)) add(NUMFLSTSTB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstIex", numFLstIex)) add(NUMFLSTIEX);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstIme", numFLstIme)) add(NUMFLSTIME);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstIel", numFLstIel)) add(NUMFLSTIEL);
	};

	return basefound;
};

void PnlWznmNavDbstr::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavDbstr";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavDbstr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstTbl", numFLstTbl);
		writeUintAttr(wr, itemtag, "sref", "numFLstTco", numFLstTco);
		writeUintAttr(wr, itemtag, "sref", "numFLstSbs", numFLstSbs);
		writeUintAttr(wr, itemtag, "sref", "numFLstRel", numFLstRel);
		writeUintAttr(wr, itemtag, "sref", "numFLstVec", numFLstVec);
		writeUintAttr(wr, itemtag, "sref", "numFLstVit", numFLstVit);
		writeUintAttr(wr, itemtag, "sref", "numFLstChk", numFLstChk);
		writeUintAttr(wr, itemtag, "sref", "numFLstStb", numFLstStb);
		writeUintAttr(wr, itemtag, "sref", "numFLstIex", numFLstIex);
		writeUintAttr(wr, itemtag, "sref", "numFLstIme", numFLstIme);
		writeUintAttr(wr, itemtag, "sref", "numFLstIel", numFLstIel);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavDbstr::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstTbl == comp->numFLstTbl) insert(items, NUMFLSTTBL);
	if (numFLstTco == comp->numFLstTco) insert(items, NUMFLSTTCO);
	if (numFLstSbs == comp->numFLstSbs) insert(items, NUMFLSTSBS);
	if (numFLstRel == comp->numFLstRel) insert(items, NUMFLSTREL);
	if (numFLstVec == comp->numFLstVec) insert(items, NUMFLSTVEC);
	if (numFLstVit == comp->numFLstVit) insert(items, NUMFLSTVIT);
	if (numFLstChk == comp->numFLstChk) insert(items, NUMFLSTCHK);
	if (numFLstStb == comp->numFLstStb) insert(items, NUMFLSTSTB);
	if (numFLstIex == comp->numFLstIex) insert(items, NUMFLSTIEX);
	if (numFLstIme == comp->numFLstIme) insert(items, NUMFLSTIME);
	if (numFLstIel == comp->numFLstIel) insert(items, NUMFLSTIEL);

	return(items);
};

set<uint> PnlWznmNavDbstr::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTTBL, NUMFLSTTCO, NUMFLSTSBS, NUMFLSTREL, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCHK, NUMFLSTSTB, NUMFLSTIEX, NUMFLSTIME, NUMFLSTIEL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavDbstr::StatApp
 ******************************************************************************/

PnlWznmNavDbstr::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstTblAlt
			, const bool LstTcoAlt
			, const bool LstSbsAlt
			, const bool LstRelAlt
			, const bool LstVecAlt
			, const bool LstVitAlt
			, const bool LstChkAlt
			, const bool LstStbAlt
			, const bool LstIexAlt
			, const bool LstImeAlt
			, const bool LstIelAlt
			, const uint LstTblNumFirstdisp
			, const uint LstTcoNumFirstdisp
			, const uint LstSbsNumFirstdisp
			, const uint LstRelNumFirstdisp
			, const uint LstVecNumFirstdisp
			, const uint LstVitNumFirstdisp
			, const uint LstChkNumFirstdisp
			, const uint LstStbNumFirstdisp
			, const uint LstIexNumFirstdisp
			, const uint LstImeNumFirstdisp
			, const uint LstIelNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstTblAlt = LstTblAlt;
	this->LstTcoAlt = LstTcoAlt;
	this->LstSbsAlt = LstSbsAlt;
	this->LstRelAlt = LstRelAlt;
	this->LstVecAlt = LstVecAlt;
	this->LstVitAlt = LstVitAlt;
	this->LstChkAlt = LstChkAlt;
	this->LstStbAlt = LstStbAlt;
	this->LstIexAlt = LstIexAlt;
	this->LstImeAlt = LstImeAlt;
	this->LstIelAlt = LstIelAlt;
	this->LstTblNumFirstdisp = LstTblNumFirstdisp;
	this->LstTcoNumFirstdisp = LstTcoNumFirstdisp;
	this->LstSbsNumFirstdisp = LstSbsNumFirstdisp;
	this->LstRelNumFirstdisp = LstRelNumFirstdisp;
	this->LstVecNumFirstdisp = LstVecNumFirstdisp;
	this->LstVitNumFirstdisp = LstVitNumFirstdisp;
	this->LstChkNumFirstdisp = LstChkNumFirstdisp;
	this->LstStbNumFirstdisp = LstStbNumFirstdisp;
	this->LstIexNumFirstdisp = LstIexNumFirstdisp;
	this->LstImeNumFirstdisp = LstImeNumFirstdisp;
	this->LstIelNumFirstdisp = LstIelNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTTBLALT, LSTTCOALT, LSTSBSALT, LSTRELALT, LSTVECALT, LSTVITALT, LSTCHKALT, LSTSTBALT, LSTIEXALT, LSTIMEALT, LSTIELALT, LSTTBLNUMFIRSTDISP, LSTTCONUMFIRSTDISP, LSTSBSNUMFIRSTDISP, LSTRELNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCHKNUMFIRSTDISP, LSTSTBNUMFIRSTDISP, LSTIEXNUMFIRSTDISP, LSTIMENUMFIRSTDISP, LSTIELNUMFIRSTDISP};
};

bool PnlWznmNavDbstr::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavDbstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavDbstr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTblAlt", LstTblAlt)) add(LSTTBLALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTcoAlt", LstTcoAlt)) add(LSTTCOALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSbsAlt", LstSbsAlt)) add(LSTSBSALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRelAlt", LstRelAlt)) add(LSTRELALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecAlt", LstVecAlt)) add(LSTVECALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitAlt", LstVitAlt)) add(LSTVITALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstChkAlt", LstChkAlt)) add(LSTCHKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStbAlt", LstStbAlt)) add(LSTSTBALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIexAlt", LstIexAlt)) add(LSTIEXALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstImeAlt", LstImeAlt)) add(LSTIMEALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIelAlt", LstIelAlt)) add(LSTIELALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTblNumFirstdisp", LstTblNumFirstdisp)) add(LSTTBLNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTcoNumFirstdisp", LstTcoNumFirstdisp)) add(LSTTCONUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSbsNumFirstdisp", LstSbsNumFirstdisp)) add(LSTSBSNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRelNumFirstdisp", LstRelNumFirstdisp)) add(LSTRELNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecNumFirstdisp", LstVecNumFirstdisp)) add(LSTVECNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitNumFirstdisp", LstVitNumFirstdisp)) add(LSTVITNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstChkNumFirstdisp", LstChkNumFirstdisp)) add(LSTCHKNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStbNumFirstdisp", LstStbNumFirstdisp)) add(LSTSTBNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIexNumFirstdisp", LstIexNumFirstdisp)) add(LSTIEXNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstImeNumFirstdisp", LstImeNumFirstdisp)) add(LSTIMENUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIelNumFirstdisp", LstIelNumFirstdisp)) add(LSTIELNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavDbstr::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstTblAlt == comp->LstTblAlt) insert(items, LSTTBLALT);
	if (LstTcoAlt == comp->LstTcoAlt) insert(items, LSTTCOALT);
	if (LstSbsAlt == comp->LstSbsAlt) insert(items, LSTSBSALT);
	if (LstRelAlt == comp->LstRelAlt) insert(items, LSTRELALT);
	if (LstVecAlt == comp->LstVecAlt) insert(items, LSTVECALT);
	if (LstVitAlt == comp->LstVitAlt) insert(items, LSTVITALT);
	if (LstChkAlt == comp->LstChkAlt) insert(items, LSTCHKALT);
	if (LstStbAlt == comp->LstStbAlt) insert(items, LSTSTBALT);
	if (LstIexAlt == comp->LstIexAlt) insert(items, LSTIEXALT);
	if (LstImeAlt == comp->LstImeAlt) insert(items, LSTIMEALT);
	if (LstIelAlt == comp->LstIelAlt) insert(items, LSTIELALT);
	if (LstTblNumFirstdisp == comp->LstTblNumFirstdisp) insert(items, LSTTBLNUMFIRSTDISP);
	if (LstTcoNumFirstdisp == comp->LstTcoNumFirstdisp) insert(items, LSTTCONUMFIRSTDISP);
	if (LstSbsNumFirstdisp == comp->LstSbsNumFirstdisp) insert(items, LSTSBSNUMFIRSTDISP);
	if (LstRelNumFirstdisp == comp->LstRelNumFirstdisp) insert(items, LSTRELNUMFIRSTDISP);
	if (LstVecNumFirstdisp == comp->LstVecNumFirstdisp) insert(items, LSTVECNUMFIRSTDISP);
	if (LstVitNumFirstdisp == comp->LstVitNumFirstdisp) insert(items, LSTVITNUMFIRSTDISP);
	if (LstChkNumFirstdisp == comp->LstChkNumFirstdisp) insert(items, LSTCHKNUMFIRSTDISP);
	if (LstStbNumFirstdisp == comp->LstStbNumFirstdisp) insert(items, LSTSTBNUMFIRSTDISP);
	if (LstIexNumFirstdisp == comp->LstIexNumFirstdisp) insert(items, LSTIEXNUMFIRSTDISP);
	if (LstImeNumFirstdisp == comp->LstImeNumFirstdisp) insert(items, LSTIMENUMFIRSTDISP);
	if (LstIelNumFirstdisp == comp->LstIelNumFirstdisp) insert(items, LSTIELNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavDbstr::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTTBLALT, LSTTCOALT, LSTSBSALT, LSTRELALT, LSTVECALT, LSTVITALT, LSTCHKALT, LSTSTBALT, LSTIEXALT, LSTIMEALT, LSTIELALT, LSTTBLNUMFIRSTDISP, LSTTCONUMFIRSTDISP, LSTSBSNUMFIRSTDISP, LSTRELNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCHKNUMFIRSTDISP, LSTSTBNUMFIRSTDISP, LSTIEXNUMFIRSTDISP, LSTIMENUMFIRSTDISP, LSTIELNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavDbstr::StatShr
 ******************************************************************************/

PnlWznmNavDbstr::StatShr::StatShr(
			const bool LstTblAvail
			, const bool ButTblViewActive
			, const bool ButTblNewcrdActive
			, const bool LstTcoAvail
			, const bool ButTcoViewActive
			, const bool ButTcoNewcrdActive
			, const bool LstSbsAvail
			, const bool ButSbsViewActive
			, const bool ButSbsNewcrdActive
			, const bool LstRelAvail
			, const bool ButRelViewActive
			, const bool ButRelNewcrdActive
			, const bool LstVecAvail
			, const bool ButVecViewActive
			, const bool ButVecNewcrdActive
			, const bool LstVitAvail
			, const bool ButVitViewActive
			, const bool ButVitNewcrdActive
			, const bool LstChkAvail
			, const bool ButChkViewActive
			, const bool ButChkNewcrdActive
			, const bool LstStbAvail
			, const bool ButStbViewActive
			, const bool ButStbNewcrdActive
			, const bool LstIexAvail
			, const bool ButIexViewActive
			, const bool ButIexNewcrdActive
			, const bool LstImeAvail
			, const bool ButImeViewActive
			, const bool ButImeNewcrdActive
			, const bool LstIelAvail
			, const bool ButIelViewActive
		) :
			Block()
		{
	this->LstTblAvail = LstTblAvail;
	this->ButTblViewActive = ButTblViewActive;
	this->ButTblNewcrdActive = ButTblNewcrdActive;
	this->LstTcoAvail = LstTcoAvail;
	this->ButTcoViewActive = ButTcoViewActive;
	this->ButTcoNewcrdActive = ButTcoNewcrdActive;
	this->LstSbsAvail = LstSbsAvail;
	this->ButSbsViewActive = ButSbsViewActive;
	this->ButSbsNewcrdActive = ButSbsNewcrdActive;
	this->LstRelAvail = LstRelAvail;
	this->ButRelViewActive = ButRelViewActive;
	this->ButRelNewcrdActive = ButRelNewcrdActive;
	this->LstVecAvail = LstVecAvail;
	this->ButVecViewActive = ButVecViewActive;
	this->ButVecNewcrdActive = ButVecNewcrdActive;
	this->LstVitAvail = LstVitAvail;
	this->ButVitViewActive = ButVitViewActive;
	this->ButVitNewcrdActive = ButVitNewcrdActive;
	this->LstChkAvail = LstChkAvail;
	this->ButChkViewActive = ButChkViewActive;
	this->ButChkNewcrdActive = ButChkNewcrdActive;
	this->LstStbAvail = LstStbAvail;
	this->ButStbViewActive = ButStbViewActive;
	this->ButStbNewcrdActive = ButStbNewcrdActive;
	this->LstIexAvail = LstIexAvail;
	this->ButIexViewActive = ButIexViewActive;
	this->ButIexNewcrdActive = ButIexNewcrdActive;
	this->LstImeAvail = LstImeAvail;
	this->ButImeViewActive = ButImeViewActive;
	this->ButImeNewcrdActive = ButImeNewcrdActive;
	this->LstIelAvail = LstIelAvail;
	this->ButIelViewActive = ButIelViewActive;

	mask = {LSTTBLAVAIL, BUTTBLVIEWACTIVE, BUTTBLNEWCRDACTIVE, LSTTCOAVAIL, BUTTCOVIEWACTIVE, BUTTCONEWCRDACTIVE, LSTSBSAVAIL, BUTSBSVIEWACTIVE, BUTSBSNEWCRDACTIVE, LSTRELAVAIL, BUTRELVIEWACTIVE, BUTRELNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, BUTVITNEWCRDACTIVE, LSTCHKAVAIL, BUTCHKVIEWACTIVE, BUTCHKNEWCRDACTIVE, LSTSTBAVAIL, BUTSTBVIEWACTIVE, BUTSTBNEWCRDACTIVE, LSTIEXAVAIL, BUTIEXVIEWACTIVE, BUTIEXNEWCRDACTIVE, LSTIMEAVAIL, BUTIMEVIEWACTIVE, BUTIMENEWCRDACTIVE, LSTIELAVAIL, BUTIELVIEWACTIVE};
};

bool PnlWznmNavDbstr::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavDbstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavDbstr";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTblAvail", LstTblAvail)) add(LSTTBLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTblViewActive", ButTblViewActive)) add(BUTTBLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTblNewcrdActive", ButTblNewcrdActive)) add(BUTTBLNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTcoAvail", LstTcoAvail)) add(LSTTCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTcoViewActive", ButTcoViewActive)) add(BUTTCOVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTcoNewcrdActive", ButTcoNewcrdActive)) add(BUTTCONEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSbsAvail", LstSbsAvail)) add(LSTSBSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSbsViewActive", ButSbsViewActive)) add(BUTSBSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSbsNewcrdActive", ButSbsNewcrdActive)) add(BUTSBSNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRelAvail", LstRelAvail)) add(LSTRELAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRelViewActive", ButRelViewActive)) add(BUTRELVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRelNewcrdActive", ButRelNewcrdActive)) add(BUTRELNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVecAvail", LstVecAvail)) add(LSTVECAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVecViewActive", ButVecViewActive)) add(BUTVECVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVecNewcrdActive", ButVecNewcrdActive)) add(BUTVECNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVitAvail", LstVitAvail)) add(LSTVITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVitViewActive", ButVitViewActive)) add(BUTVITVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVitNewcrdActive", ButVitNewcrdActive)) add(BUTVITNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstChkAvail", LstChkAvail)) add(LSTCHKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButChkViewActive", ButChkViewActive)) add(BUTCHKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButChkNewcrdActive", ButChkNewcrdActive)) add(BUTCHKNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstStbAvail", LstStbAvail)) add(LSTSTBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStbViewActive", ButStbViewActive)) add(BUTSTBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStbNewcrdActive", ButStbNewcrdActive)) add(BUTSTBNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIexAvail", LstIexAvail)) add(LSTIEXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIexViewActive", ButIexViewActive)) add(BUTIEXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIexNewcrdActive", ButIexNewcrdActive)) add(BUTIEXNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstImeAvail", LstImeAvail)) add(LSTIMEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButImeViewActive", ButImeViewActive)) add(BUTIMEVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButImeNewcrdActive", ButImeNewcrdActive)) add(BUTIMENEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstIelAvail", LstIelAvail)) add(LSTIELAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButIelViewActive", ButIelViewActive)) add(BUTIELVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmNavDbstr::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstTblAvail == comp->LstTblAvail) insert(items, LSTTBLAVAIL);
	if (ButTblViewActive == comp->ButTblViewActive) insert(items, BUTTBLVIEWACTIVE);
	if (ButTblNewcrdActive == comp->ButTblNewcrdActive) insert(items, BUTTBLNEWCRDACTIVE);
	if (LstTcoAvail == comp->LstTcoAvail) insert(items, LSTTCOAVAIL);
	if (ButTcoViewActive == comp->ButTcoViewActive) insert(items, BUTTCOVIEWACTIVE);
	if (ButTcoNewcrdActive == comp->ButTcoNewcrdActive) insert(items, BUTTCONEWCRDACTIVE);
	if (LstSbsAvail == comp->LstSbsAvail) insert(items, LSTSBSAVAIL);
	if (ButSbsViewActive == comp->ButSbsViewActive) insert(items, BUTSBSVIEWACTIVE);
	if (ButSbsNewcrdActive == comp->ButSbsNewcrdActive) insert(items, BUTSBSNEWCRDACTIVE);
	if (LstRelAvail == comp->LstRelAvail) insert(items, LSTRELAVAIL);
	if (ButRelViewActive == comp->ButRelViewActive) insert(items, BUTRELVIEWACTIVE);
	if (ButRelNewcrdActive == comp->ButRelNewcrdActive) insert(items, BUTRELNEWCRDACTIVE);
	if (LstVecAvail == comp->LstVecAvail) insert(items, LSTVECAVAIL);
	if (ButVecViewActive == comp->ButVecViewActive) insert(items, BUTVECVIEWACTIVE);
	if (ButVecNewcrdActive == comp->ButVecNewcrdActive) insert(items, BUTVECNEWCRDACTIVE);
	if (LstVitAvail == comp->LstVitAvail) insert(items, LSTVITAVAIL);
	if (ButVitViewActive == comp->ButVitViewActive) insert(items, BUTVITVIEWACTIVE);
	if (ButVitNewcrdActive == comp->ButVitNewcrdActive) insert(items, BUTVITNEWCRDACTIVE);
	if (LstChkAvail == comp->LstChkAvail) insert(items, LSTCHKAVAIL);
	if (ButChkViewActive == comp->ButChkViewActive) insert(items, BUTCHKVIEWACTIVE);
	if (ButChkNewcrdActive == comp->ButChkNewcrdActive) insert(items, BUTCHKNEWCRDACTIVE);
	if (LstStbAvail == comp->LstStbAvail) insert(items, LSTSTBAVAIL);
	if (ButStbViewActive == comp->ButStbViewActive) insert(items, BUTSTBVIEWACTIVE);
	if (ButStbNewcrdActive == comp->ButStbNewcrdActive) insert(items, BUTSTBNEWCRDACTIVE);
	if (LstIexAvail == comp->LstIexAvail) insert(items, LSTIEXAVAIL);
	if (ButIexViewActive == comp->ButIexViewActive) insert(items, BUTIEXVIEWACTIVE);
	if (ButIexNewcrdActive == comp->ButIexNewcrdActive) insert(items, BUTIEXNEWCRDACTIVE);
	if (LstImeAvail == comp->LstImeAvail) insert(items, LSTIMEAVAIL);
	if (ButImeViewActive == comp->ButImeViewActive) insert(items, BUTIMEVIEWACTIVE);
	if (ButImeNewcrdActive == comp->ButImeNewcrdActive) insert(items, BUTIMENEWCRDACTIVE);
	if (LstIelAvail == comp->LstIelAvail) insert(items, LSTIELAVAIL);
	if (ButIelViewActive == comp->ButIelViewActive) insert(items, BUTIELVIEWACTIVE);

	return(items);
};

set<uint> PnlWznmNavDbstr::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTTBLAVAIL, BUTTBLVIEWACTIVE, BUTTBLNEWCRDACTIVE, LSTTCOAVAIL, BUTTCOVIEWACTIVE, BUTTCONEWCRDACTIVE, LSTSBSAVAIL, BUTSBSVIEWACTIVE, BUTSBSNEWCRDACTIVE, LSTRELAVAIL, BUTRELVIEWACTIVE, BUTRELNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, BUTVITNEWCRDACTIVE, LSTCHKAVAIL, BUTCHKVIEWACTIVE, BUTCHKNEWCRDACTIVE, LSTSTBAVAIL, BUTSTBVIEWACTIVE, BUTSTBNEWCRDACTIVE, LSTIEXAVAIL, BUTIEXVIEWACTIVE, BUTIEXNEWCRDACTIVE, LSTIMEAVAIL, BUTIMEVIEWACTIVE, BUTIMENEWCRDACTIVE, LSTIELAVAIL, BUTIELVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavDbstr::Tag
 ******************************************************************************/

PnlWznmNavDbstr::Tag::Tag(
			const string& Cpt
			, const string& CptTbl
			, const string& CptTco
			, const string& CptSbs
			, const string& CptRel
			, const string& CptVec
			, const string& CptVit
			, const string& CptChk
			, const string& CptStb
			, const string& CptIex
			, const string& CptIme
			, const string& CptIel
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptTbl = CptTbl;
	this->CptTco = CptTco;
	this->CptSbs = CptSbs;
	this->CptRel = CptRel;
	this->CptVec = CptVec;
	this->CptVit = CptVit;
	this->CptChk = CptChk;
	this->CptStb = CptStb;
	this->CptIex = CptIex;
	this->CptIme = CptIme;
	this->CptIel = CptIel;

	mask = {CPT, CPTTBL, CPTTCO, CPTSBS, CPTREL, CPTVEC, CPTVIT, CPTCHK, CPTSTB, CPTIEX, CPTIME, CPTIEL};
};

bool PnlWznmNavDbstr::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavDbstr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavDbstr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTbl", CptTbl)) add(CPTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTco", CptTco)) add(CPTTCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSbs", CptSbs)) add(CPTSBS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRel", CptRel)) add(CPTREL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVec", CptVec)) add(CPTVEC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVit", CptVit)) add(CPTVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptChk", CptChk)) add(CPTCHK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptStb", CptStb)) add(CPTSTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIex", CptIex)) add(CPTIEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIme", CptIme)) add(CPTIME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIel", CptIel)) add(CPTIEL);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavDbstr::DpchAppData
 ******************************************************************************/

PnlWznmNavDbstr::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavDbstr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDbstr::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavDbstrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavDbstr::DpchAppDo
 ******************************************************************************/

PnlWznmNavDbstr::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavDbstr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDbstr::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavDbstrDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavDbstr::DpchEngData
 ******************************************************************************/

PnlWznmNavDbstr::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVDBSTRDATA)
		{
	feedFLstChk.tag = "FeedFLstChk";
	feedFLstIel.tag = "FeedFLstIel";
	feedFLstIex.tag = "FeedFLstIex";
	feedFLstIme.tag = "FeedFLstIme";
	feedFLstRel.tag = "FeedFLstRel";
	feedFLstSbs.tag = "FeedFLstSbs";
	feedFLstStb.tag = "FeedFLstStb";
	feedFLstTbl.tag = "FeedFLstTbl";
	feedFLstTco.tag = "FeedFLstTco";
	feedFLstVec.tag = "FeedFLstVec";
	feedFLstVit.tag = "FeedFLstVit";
};

string PnlWznmNavDbstr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCHK)) ss.push_back("feedFLstChk");
	if (has(FEEDFLSTIEL)) ss.push_back("feedFLstIel");
	if (has(FEEDFLSTIEX)) ss.push_back("feedFLstIex");
	if (has(FEEDFLSTIME)) ss.push_back("feedFLstIme");
	if (has(FEEDFLSTREL)) ss.push_back("feedFLstRel");
	if (has(FEEDFLSTSBS)) ss.push_back("feedFLstSbs");
	if (has(FEEDFLSTSTB)) ss.push_back("feedFLstStb");
	if (has(FEEDFLSTTBL)) ss.push_back("feedFLstTbl");
	if (has(FEEDFLSTTCO)) ss.push_back("feedFLstTco");
	if (has(FEEDFLSTVEC)) ss.push_back("feedFLstVec");
	if (has(FEEDFLSTVIT)) ss.push_back("feedFLstVit");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDbstr::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavDbstrData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstChk.readXML(docctx, basexpath, true)) add(FEEDFLSTCHK);
		if (feedFLstIel.readXML(docctx, basexpath, true)) add(FEEDFLSTIEL);
		if (feedFLstIex.readXML(docctx, basexpath, true)) add(FEEDFLSTIEX);
		if (feedFLstIme.readXML(docctx, basexpath, true)) add(FEEDFLSTIME);
		if (feedFLstRel.readXML(docctx, basexpath, true)) add(FEEDFLSTREL);
		if (feedFLstSbs.readXML(docctx, basexpath, true)) add(FEEDFLSTSBS);
		if (feedFLstStb.readXML(docctx, basexpath, true)) add(FEEDFLSTSTB);
		if (feedFLstTbl.readXML(docctx, basexpath, true)) add(FEEDFLSTTBL);
		if (feedFLstTco.readXML(docctx, basexpath, true)) add(FEEDFLSTTCO);
		if (feedFLstVec.readXML(docctx, basexpath, true)) add(FEEDFLSTVEC);
		if (feedFLstVit.readXML(docctx, basexpath, true)) add(FEEDFLSTVIT);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstChk.clear();
		feedFLstIel.clear();
		feedFLstIex.clear();
		feedFLstIme.clear();
		feedFLstRel.clear();
		feedFLstSbs.clear();
		feedFLstStb.clear();
		feedFLstTbl.clear();
		feedFLstTco.clear();
		feedFLstVec.clear();
		feedFLstVit.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

