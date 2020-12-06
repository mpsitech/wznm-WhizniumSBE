/**
	* \file PnlWznmSgeDetail.cpp
	* API code for job PnlWznmSgeDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmSgeDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSgeDetail::VecVDo
 ******************************************************************************/

uint PnlWznmSgeDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "butsnxviewclick") return BUTSNXVIEWCLICK;
	if (s == "butfnxviewclick") return BUTFNXVIEWCLICK;
	if (s == "butsqknewclick") return BUTSQKNEWCLICK;
	if (s == "butsqkdeleteclick") return BUTSQKDELETECLICK;
	if (s == "butsqkjtieditclick") return BUTSQKJTIEDITCLICK;

	return(0);
};

string PnlWznmSgeDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTSNXVIEWCLICK) return("ButSnxViewClick");
	if (ix == BUTFNXVIEWCLICK) return("ButFnxViewClick");
	if (ix == BUTSQKNEWCLICK) return("ButSqkNewClick");
	if (ix == BUTSQKDELETECLICK) return("ButSqkDeleteClick");
	if (ix == BUTSQKJTIEDITCLICK) return("ButSqkJtiEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmSgeDetail::ContIac
 ******************************************************************************/

PnlWznmSgeDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const string& TxfMon
			, const string& TxfCmt
			, const uint numFPupSqkJti
			, const string& TxfSqkExa
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->TxfMon = TxfMon;
	this->TxfCmt = TxfCmt;
	this->numFPupSqkJti = numFPupSqkJti;
	this->TxfSqkExa = TxfSqkExa;

	mask = {NUMFPUPTYP, TXFMON, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
};

bool PnlWznmSgeDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmSgeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmSgeDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMon", TxfMon)) add(TXFMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSqkJti", numFPupSqkJti)) add(NUMFPUPSQKJTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSqkExa", TxfSqkExa)) add(TXFSQKEXA);
	};

	return basefound;
};

void PnlWznmSgeDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmSgeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmSgeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfMon", TxfMon);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupSqkJti", numFPupSqkJti);
		writeStringAttr(wr, itemtag, "sref", "TxfSqkExa", TxfSqkExa);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSgeDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfMon == comp->TxfMon) insert(items, TXFMON);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupSqkJti == comp->numFPupSqkJti) insert(items, NUMFPUPSQKJTI);
	if (TxfSqkExa == comp->TxfSqkExa) insert(items, TXFSQKEXA);

	return(items);
};

set<uint> PnlWznmSgeDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFMON, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSgeDetail::ContInf
 ******************************************************************************/

PnlWznmSgeDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtJob
			, const string& TxtSnx
			, const string& TxtFnx
			, const string& TxtSqkTit
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtJob = TxtJob;
	this->TxtSnx = TxtSnx;
	this->TxtFnx = TxtFnx;
	this->TxtSqkTit = TxtSqkTit;

	mask = {TXTSRF, TXTJOB, TXTSNX, TXTFNX, TXTSQKTIT};
};

bool PnlWznmSgeDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmSgeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmSgeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtJob", TxtJob)) add(TXTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSnx", TxtSnx)) add(TXTSNX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFnx", TxtFnx)) add(TXTFNX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSqkTit", TxtSqkTit)) add(TXTSQKTIT);
	};

	return basefound;
};

set<uint> PnlWznmSgeDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);
	if (TxtSnx == comp->TxtSnx) insert(items, TXTSNX);
	if (TxtFnx == comp->TxtFnx) insert(items, TXTFNX);
	if (TxtSqkTit == comp->TxtSqkTit) insert(items, TXTSQKTIT);

	return(items);
};

set<uint> PnlWznmSgeDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTJOB, TXTSNX, TXTFNX, TXTSQKTIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSgeDetail::StatApp
 ******************************************************************************/

PnlWznmSgeDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmSgeDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmSgeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmSgeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmSgeDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmSgeDetail::StatApp::diff(
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
 class PnlWznmSgeDetail::StatShr
 ******************************************************************************/

PnlWznmSgeDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool TxfMonActive
			, const bool TxtSnxActive
			, const bool ButSnxViewAvail
			, const bool ButSnxViewActive
			, const bool TxtFnxActive
			, const bool ButFnxViewAvail
			, const bool ButFnxViewActive
			, const bool TxfCmtActive
			, const bool ButSqkNewAvail
			, const bool ButSqkDeleteAvail
			, const bool PupSqkJtiAvail
			, const bool PupSqkJtiActive
			, const bool ButSqkJtiEditAvail
			, const bool TxtSqkTitAvail
			, const bool TxtSqkTitActive
			, const bool TxfSqkExaAvail
			, const bool TxfSqkExaActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->TxfMonActive = TxfMonActive;
	this->TxtSnxActive = TxtSnxActive;
	this->ButSnxViewAvail = ButSnxViewAvail;
	this->ButSnxViewActive = ButSnxViewActive;
	this->TxtFnxActive = TxtFnxActive;
	this->ButFnxViewAvail = ButFnxViewAvail;
	this->ButFnxViewActive = ButFnxViewActive;
	this->TxfCmtActive = TxfCmtActive;
	this->ButSqkNewAvail = ButSqkNewAvail;
	this->ButSqkDeleteAvail = ButSqkDeleteAvail;
	this->PupSqkJtiAvail = PupSqkJtiAvail;
	this->PupSqkJtiActive = PupSqkJtiActive;
	this->ButSqkJtiEditAvail = ButSqkJtiEditAvail;
	this->TxtSqkTitAvail = TxtSqkTitAvail;
	this->TxtSqkTitActive = TxtSqkTitActive;
	this->TxfSqkExaAvail = TxfSqkExaAvail;
	this->TxfSqkExaActive = TxfSqkExaActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMONACTIVE, TXTSNXACTIVE, BUTSNXVIEWAVAIL, BUTSNXVIEWACTIVE, TXTFNXACTIVE, BUTFNXVIEWAVAIL, BUTFNXVIEWACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
};

bool PnlWznmSgeDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmSgeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmSgeDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtJobActive", TxtJobActive)) add(TXTJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", ButJobViewAvail)) add(BUTJOBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewActive", ButJobViewActive)) add(BUTJOBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfMonActive", TxfMonActive)) add(TXFMONACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSnxActive", TxtSnxActive)) add(TXTSNXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSnxViewAvail", ButSnxViewAvail)) add(BUTSNXVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSnxViewActive", ButSnxViewActive)) add(BUTSNXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFnxActive", TxtFnxActive)) add(TXTFNXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFnxViewAvail", ButFnxViewAvail)) add(BUTFNXVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFnxViewActive", ButFnxViewActive)) add(BUTFNXVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfCmtActive", TxfCmtActive)) add(TXFCMTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSqkNewAvail", ButSqkNewAvail)) add(BUTSQKNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSqkDeleteAvail", ButSqkDeleteAvail)) add(BUTSQKDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSqkJtiAvail", PupSqkJtiAvail)) add(PUPSQKJTIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupSqkJtiActive", PupSqkJtiActive)) add(PUPSQKJTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSqkJtiEditAvail", ButSqkJtiEditAvail)) add(BUTSQKJTIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSqkTitAvail", TxtSqkTitAvail)) add(TXTSQKTITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSqkTitActive", TxtSqkTitActive)) add(TXTSQKTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSqkExaAvail", TxfSqkExaAvail)) add(TXFSQKEXAAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfSqkExaActive", TxfSqkExaActive)) add(TXFSQKEXAACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmSgeDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (TxfMonActive == comp->TxfMonActive) insert(items, TXFMONACTIVE);
	if (TxtSnxActive == comp->TxtSnxActive) insert(items, TXTSNXACTIVE);
	if (ButSnxViewAvail == comp->ButSnxViewAvail) insert(items, BUTSNXVIEWAVAIL);
	if (ButSnxViewActive == comp->ButSnxViewActive) insert(items, BUTSNXVIEWACTIVE);
	if (TxtFnxActive == comp->TxtFnxActive) insert(items, TXTFNXACTIVE);
	if (ButFnxViewAvail == comp->ButFnxViewAvail) insert(items, BUTFNXVIEWAVAIL);
	if (ButFnxViewActive == comp->ButFnxViewActive) insert(items, BUTFNXVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (ButSqkNewAvail == comp->ButSqkNewAvail) insert(items, BUTSQKNEWAVAIL);
	if (ButSqkDeleteAvail == comp->ButSqkDeleteAvail) insert(items, BUTSQKDELETEAVAIL);
	if (PupSqkJtiAvail == comp->PupSqkJtiAvail) insert(items, PUPSQKJTIAVAIL);
	if (PupSqkJtiActive == comp->PupSqkJtiActive) insert(items, PUPSQKJTIACTIVE);
	if (ButSqkJtiEditAvail == comp->ButSqkJtiEditAvail) insert(items, BUTSQKJTIEDITAVAIL);
	if (TxtSqkTitAvail == comp->TxtSqkTitAvail) insert(items, TXTSQKTITAVAIL);
	if (TxtSqkTitActive == comp->TxtSqkTitActive) insert(items, TXTSQKTITACTIVE);
	if (TxfSqkExaAvail == comp->TxfSqkExaAvail) insert(items, TXFSQKEXAAVAIL);
	if (TxfSqkExaActive == comp->TxfSqkExaActive) insert(items, TXFSQKEXAACTIVE);

	return(items);
};

set<uint> PnlWznmSgeDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMONACTIVE, TXTSNXACTIVE, BUTSNXVIEWAVAIL, BUTSNXVIEWACTIVE, TXTFNXACTIVE, BUTFNXVIEWAVAIL, BUTFNXVIEWACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSgeDetail::Tag
 ******************************************************************************/

PnlWznmSgeDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTyp
			, const string& CptJob
			, const string& CptMon
			, const string& CptSnx
			, const string& CptFnx
			, const string& CptCmt
			, const string& HdgSqk
			, const string& CptSqkTit
			, const string& CptSqkExa
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTyp = CptTyp;
	this->CptJob = CptJob;
	this->CptMon = CptMon;
	this->CptSnx = CptSnx;
	this->CptFnx = CptFnx;
	this->CptCmt = CptCmt;
	this->HdgSqk = HdgSqk;
	this->CptSqkTit = CptSqkTit;
	this->CptSqkExa = CptSqkExa;

	mask = {CPT, CPTSRF, CPTTYP, CPTJOB, CPTMON, CPTSNX, CPTFNX, CPTCMT, HDGSQK, CPTSQKTIT, CPTSQKEXA};
};

bool PnlWznmSgeDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmSgeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmSgeDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMon", CptMon)) add(CPTMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSnx", CptSnx)) add(CPTSNX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFnx", CptFnx)) add(CPTFNX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCmt", CptCmt)) add(CPTCMT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgSqk", HdgSqk)) add(HDGSQK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSqkTit", CptSqkTit)) add(CPTSQKTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSqkExa", CptSqkExa)) add(CPTSQKEXA);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmSgeDetail::DpchAppData
 ******************************************************************************/

PnlWznmSgeDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSGEDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmSgeDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSgeDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSgeDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSgeDetail::DpchAppDo
 ******************************************************************************/

PnlWznmSgeDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSGEDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmSgeDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSgeDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSgeDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSgeDetail::DpchEngData
 ******************************************************************************/

PnlWznmSgeDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSGEDETAILDATA)
		{
	feedFPupSqkJti.tag = "FeedFPupSqkJti";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmSgeDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPSQKJTI)) ss.push_back("feedFPupSqkJti");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSgeDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmSgeDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupSqkJti.readXML(docctx, basexpath, true)) add(FEEDFPUPSQKJTI);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupSqkJti.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
