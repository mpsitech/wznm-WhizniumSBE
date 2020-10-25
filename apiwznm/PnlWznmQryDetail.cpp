/**
	* \file PnlWznmQryDetail.cpp
	* API code for job PnlWznmQryDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmQryDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmQryDetail::VecVDo
 ******************************************************************************/

uint PnlWznmQryDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "butinoviewclick") return BUTINOVIEWCLICK;

	return(0);
};

string PnlWznmQryDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTINOVIEWCLICK) return("ButInoViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmQryDetail::ContIac
 ******************************************************************************/

PnlWznmQryDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const bool ChkLof
			, const uint numFLstIno
			, const string& TxfIno
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->ChkLof = ChkLof;
	this->numFLstIno = numFLstIno;
	this->TxfIno = TxfIno;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPTYP, CHKLOF, NUMFLSTINO, TXFINO, TXFCMT};
};

bool PnlWznmQryDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmQryDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmQryDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkLof", ChkLof)) add(CHKLOF);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstIno", numFLstIno)) add(NUMFLSTINO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfIno", TxfIno)) add(TXFINO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmQryDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmQryDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmQryDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeBoolAttr(wr, itemtag, "sref", "ChkLof", ChkLof);
		writeUintAttr(wr, itemtag, "sref", "numFLstIno", numFLstIno);
		writeStringAttr(wr, itemtag, "sref", "TxfIno", TxfIno);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQryDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (ChkLof == comp->ChkLof) insert(items, CHKLOF);
	if (numFLstIno == comp->numFLstIno) insert(items, NUMFLSTINO);
	if (TxfIno == comp->TxfIno) insert(items, TXFINO);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmQryDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, CHKLOF, NUMFLSTINO, TXFINO, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryDetail::ContInf
 ******************************************************************************/

PnlWznmQryDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtVer
			, const string& TxtSup
			, const string& TxtTbl
			, const string& TxtQtb
			, const string& TxtJob
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtVer = TxtVer;
	this->TxtSup = TxtSup;
	this->TxtTbl = TxtTbl;
	this->TxtQtb = TxtQtb;
	this->TxtJob = TxtJob;

	mask = {TXTSRF, TXTVER, TXTSUP, TXTTBL, TXTQTB, TXTJOB};
};

bool PnlWznmQryDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmQryDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmQryDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtVer", TxtVer)) add(TXTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTbl", TxtTbl)) add(TXTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtQtb", TxtQtb)) add(TXTQTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtJob", TxtJob)) add(TXTJOB);
	};

	return basefound;
};

set<uint> PnlWznmQryDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtQtb == comp->TxtQtb) insert(items, TXTQTB);
	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);

	return(items);
};

set<uint> PnlWznmQryDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTVER, TXTSUP, TXTTBL, TXTQTB, TXTJOB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryDetail::StatApp
 ******************************************************************************/

PnlWznmQryDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstInoAlt
			, const uint LstInoNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstInoAlt = LstInoAlt;
	this->LstInoNumFirstdisp = LstInoNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTINOALT, LSTINONUMFIRSTDISP};
};

bool PnlWznmQryDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmQryDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmQryDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstInoAlt", LstInoAlt)) add(LSTINOALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstInoNumFirstdisp", LstInoNumFirstdisp)) add(LSTINONUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmQryDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstInoAlt == comp->LstInoAlt) insert(items, LSTINOALT);
	if (LstInoNumFirstdisp == comp->LstInoNumFirstdisp) insert(items, LSTINONUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmQryDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTINOALT, LSTINONUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryDetail::StatShr
 ******************************************************************************/

PnlWznmQryDetail::StatShr::StatShr(
			const bool TxfInoValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtTblActive
			, const bool TxtQtbActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool ChkLofActive
			, const bool LstInoActive
			, const bool ButInoViewAvail
			, const bool ButInoViewActive
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfInoValid = TxfInoValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxtTblActive = TxtTblActive;
	this->TxtQtbActive = TxtQtbActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->ChkLofActive = ChkLofActive;
	this->LstInoActive = LstInoActive;
	this->ButInoViewAvail = ButInoViewAvail;
	this->ButInoViewActive = ButInoViewActive;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFINOVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXTQTBACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKLOFACTIVE, LSTINOACTIVE, BUTINOVIEWAVAIL, BUTINOVIEWACTIVE, TXFCMTACTIVE};
};

bool PnlWznmQryDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmQryDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmQryDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfInoValid", TxfInoValid)) add(TXFINOVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtVerActive", TxtVerActive)) add(TXTVERACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", ButVerViewAvail)) add(BUTVERVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTblActive", TxtTblActive)) add(TXTTBLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtQtbActive", TxtQtbActive)) add(TXTQTBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtJobActive", TxtJobActive)) add(TXTJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", ButJobViewAvail)) add(BUTJOBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewActive", ButJobViewActive)) add(BUTJOBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkLofActive", ChkLofActive)) add(CHKLOFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstInoActive", LstInoActive)) add(LSTINOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButInoViewAvail", ButInoViewAvail)) add(BUTINOVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButInoViewActive", ButInoViewActive)) add(BUTINOVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmQryDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfInoValid == comp->TxfInoValid) insert(items, TXFINOVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (TxtQtbActive == comp->TxtQtbActive) insert(items, TXTQTBACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (ChkLofActive == comp->ChkLofActive) insert(items, CHKLOFACTIVE);
	if (LstInoActive == comp->LstInoActive) insert(items, LSTINOACTIVE);
	if (ButInoViewAvail == comp->ButInoViewAvail) insert(items, BUTINOVIEWAVAIL);
	if (ButInoViewActive == comp->ButInoViewActive) insert(items, BUTINOVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmQryDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFINOVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXTQTBACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKLOFACTIVE, LSTINOACTIVE, BUTINOVIEWAVAIL, BUTINOVIEWACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryDetail::Tag
 ******************************************************************************/

PnlWznmQryDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptVer
			, const string& CptSup
			, const string& CptTbl
			, const string& CptQtb
			, const string& CptJob
			, const string& CptLof
			, const string& CptIno
			, const string& CptCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTyp = CptTyp;
	this->CptVer = CptVer;
	this->CptSup = CptSup;
	this->CptTbl = CptTbl;
	this->CptQtb = CptQtb;
	this->CptJob = CptJob;
	this->CptLof = CptLof;
	this->CptIno = CptIno;
	this->CptCmt = CptCmt;

	mask = {CPT, CPTSRF, CPTTYP, CPTVER, CPTSUP, CPTTBL, CPTQTB, CPTJOB, CPTLOF, CPTINO, CPTCMT};
};

bool PnlWznmQryDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmQryDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmQryDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTbl", CptTbl)) add(CPTTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptQtb", CptQtb)) add(CPTQTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLof", CptLof)) add(CPTLOF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptIno", CptIno)) add(CPTINO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmQryDetail::DpchAppData
 ******************************************************************************/

PnlWznmQryDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQRYDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmQryDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmQryDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQryDetail::DpchAppDo
 ******************************************************************************/

PnlWznmQryDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQRYDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmQryDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmQryDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQryDetail::DpchEngData
 ******************************************************************************/

PnlWznmQryDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMQRYDETAILDATA)
		{
	feedFLstIno.tag = "FeedFLstIno";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmQryDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTINO)) ss.push_back("feedFLstIno");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmQryDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstIno.readXML(docctx, basexpath, true)) add(FEEDFLSTINO);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstIno.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

