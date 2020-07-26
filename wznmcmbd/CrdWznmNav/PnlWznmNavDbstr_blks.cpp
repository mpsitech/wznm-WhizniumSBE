/**
	* \file PnlWznmNavDbstr_blks.cpp
	* job handler for job PnlWznmNavDbstr (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

void PnlWznmNavDbstr::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavDbstr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavDbstr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstTblAlt", LstTblAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstTcoAlt", LstTcoAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSbsAlt", LstSbsAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRelAlt", LstRelAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVecAlt", LstVecAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVitAlt", LstVitAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstChkAlt", LstChkAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstStbAlt", LstStbAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstIexAlt", LstIexAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstImeAlt", LstImeAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstIelAlt", LstIelAlt);
		writeUintAttr(wr, itemtag, "sref", "LstTblNumFirstdisp", LstTblNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTcoNumFirstdisp", LstTcoNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSbsNumFirstdisp", LstSbsNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRelNumFirstdisp", LstRelNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVecNumFirstdisp", LstVecNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVitNumFirstdisp", LstVitNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstChkNumFirstdisp", LstChkNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstStbNumFirstdisp", LstStbNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstIexNumFirstdisp", LstIexNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstImeNumFirstdisp", LstImeNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstIelNumFirstdisp", LstIelNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWznmNavDbstr::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavDbstr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavDbstr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstTblAvail", LstTblAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTblViewActive", ButTblViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTblNewcrdActive", ButTblNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstTcoAvail", LstTcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTcoViewActive", ButTcoViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTcoNewcrdActive", ButTcoNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSbsAvail", LstSbsAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSbsViewActive", ButSbsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSbsNewcrdActive", ButSbsNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRelAvail", LstRelAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRelViewActive", ButRelViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRelNewcrdActive", ButRelNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVecAvail", LstVecAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVecViewActive", ButVecViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVecNewcrdActive", ButVecNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVitAvail", LstVitAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVitViewActive", ButVitViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVitNewcrdActive", ButVitNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstChkAvail", LstChkAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButChkViewActive", ButChkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButChkNewcrdActive", ButChkNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstStbAvail", LstStbAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStbViewActive", ButStbViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStbNewcrdActive", ButStbNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstIexAvail", LstIexAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButIexViewActive", ButIexViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButIexNewcrdActive", ButIexNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstImeAvail", LstImeAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButImeViewActive", ButImeViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButImeNewcrdActive", ButImeNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstIelAvail", LstIelAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButIelViewActive", ButIelViewActive);
	xmlTextWriterEndElement(wr);
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

void PnlWznmNavDbstr::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavDbstr";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavDbstr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Database structure module");
			writeStringAttr(wr, itemtag, "sref", "CptTbl", "tables");
			writeStringAttr(wr, itemtag, "sref", "CptTco", "table columns");
			writeStringAttr(wr, itemtag, "sref", "CptSbs", "subsets");
			writeStringAttr(wr, itemtag, "sref", "CptRel", "relations");
			writeStringAttr(wr, itemtag, "sref", "CptVec", "vectors");
			writeStringAttr(wr, itemtag, "sref", "CptVit", "vector items");
			writeStringAttr(wr, itemtag, "sref", "CptChk", "feature checks");
			writeStringAttr(wr, itemtag, "sref", "CptStb", "stubs");
			writeStringAttr(wr, itemtag, "sref", "CptIex", "import/export complexes");
			writeStringAttr(wr, itemtag, "sref", "CptIme", "import/exports");
			writeStringAttr(wr, itemtag, "sref", "CptIel", "import/export columns");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavDbstr::DpchAppData
 ******************************************************************************/

PnlWznmNavDbstr::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDATA)
		{
};

string PnlWznmNavDbstr::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDbstr::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavDbstrData");
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
 class PnlWznmNavDbstr::DpchAppDo
 ******************************************************************************/

PnlWznmNavDbstr::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDO)
		{
	ixVDo = 0;
};

string PnlWznmNavDbstr::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavDbstr::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavDbstrDo");
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
 class PnlWznmNavDbstr::DpchEngData
 ******************************************************************************/

PnlWznmNavDbstr::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstChk
			, Feed* feedFLstIel
			, Feed* feedFLstIex
			, Feed* feedFLstIme
			, Feed* feedFLstRel
			, Feed* feedFLstSbs
			, Feed* feedFLstStb
			, Feed* feedFLstTbl
			, Feed* feedFLstTco
			, Feed* feedFLstVec
			, Feed* feedFLstVit
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVDBSTRDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCHK, FEEDFLSTIEL, FEEDFLSTIEX, FEEDFLSTIME, FEEDFLSTREL, FEEDFLSTSBS, FEEDFLSTSTB, FEEDFLSTTBL, FEEDFLSTTCO, FEEDFLSTVEC, FEEDFLSTVIT, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCHK) && feedFLstChk) this->feedFLstChk = *feedFLstChk;
	if (find(this->mask, FEEDFLSTIEL) && feedFLstIel) this->feedFLstIel = *feedFLstIel;
	if (find(this->mask, FEEDFLSTIEX) && feedFLstIex) this->feedFLstIex = *feedFLstIex;
	if (find(this->mask, FEEDFLSTIME) && feedFLstIme) this->feedFLstIme = *feedFLstIme;
	if (find(this->mask, FEEDFLSTREL) && feedFLstRel) this->feedFLstRel = *feedFLstRel;
	if (find(this->mask, FEEDFLSTSBS) && feedFLstSbs) this->feedFLstSbs = *feedFLstSbs;
	if (find(this->mask, FEEDFLSTSTB) && feedFLstStb) this->feedFLstStb = *feedFLstStb;
	if (find(this->mask, FEEDFLSTTBL) && feedFLstTbl) this->feedFLstTbl = *feedFLstTbl;
	if (find(this->mask, FEEDFLSTTCO) && feedFLstTco) this->feedFLstTco = *feedFLstTco;
	if (find(this->mask, FEEDFLSTVEC) && feedFLstVec) this->feedFLstVec = *feedFLstVec;
	if (find(this->mask, FEEDFLSTVIT) && feedFLstVit) this->feedFLstVit = *feedFLstVit;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavDbstr::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWznmNavDbstr::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCHK)) {feedFLstChk = src->feedFLstChk; add(FEEDFLSTCHK);};
	if (src->has(FEEDFLSTIEL)) {feedFLstIel = src->feedFLstIel; add(FEEDFLSTIEL);};
	if (src->has(FEEDFLSTIEX)) {feedFLstIex = src->feedFLstIex; add(FEEDFLSTIEX);};
	if (src->has(FEEDFLSTIME)) {feedFLstIme = src->feedFLstIme; add(FEEDFLSTIME);};
	if (src->has(FEEDFLSTREL)) {feedFLstRel = src->feedFLstRel; add(FEEDFLSTREL);};
	if (src->has(FEEDFLSTSBS)) {feedFLstSbs = src->feedFLstSbs; add(FEEDFLSTSBS);};
	if (src->has(FEEDFLSTSTB)) {feedFLstStb = src->feedFLstStb; add(FEEDFLSTSTB);};
	if (src->has(FEEDFLSTTBL)) {feedFLstTbl = src->feedFLstTbl; add(FEEDFLSTTBL);};
	if (src->has(FEEDFLSTTCO)) {feedFLstTco = src->feedFLstTco; add(FEEDFLSTTCO);};
	if (src->has(FEEDFLSTVEC)) {feedFLstVec = src->feedFLstVec; add(FEEDFLSTVEC);};
	if (src->has(FEEDFLSTVIT)) {feedFLstVit = src->feedFLstVit; add(FEEDFLSTVIT);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavDbstr::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavDbstrData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCHK)) feedFLstChk.writeXML(wr);
		if (has(FEEDFLSTIEL)) feedFLstIel.writeXML(wr);
		if (has(FEEDFLSTIEX)) feedFLstIex.writeXML(wr);
		if (has(FEEDFLSTIME)) feedFLstIme.writeXML(wr);
		if (has(FEEDFLSTREL)) feedFLstRel.writeXML(wr);
		if (has(FEEDFLSTSBS)) feedFLstSbs.writeXML(wr);
		if (has(FEEDFLSTSTB)) feedFLstStb.writeXML(wr);
		if (has(FEEDFLSTTBL)) feedFLstTbl.writeXML(wr);
		if (has(FEEDFLSTTCO)) feedFLstTco.writeXML(wr);
		if (has(FEEDFLSTVEC)) feedFLstVec.writeXML(wr);
		if (has(FEEDFLSTVIT)) feedFLstVit.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

