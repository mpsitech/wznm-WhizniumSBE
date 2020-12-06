/**
	* \file PnlWznmCarDetail.cpp
	* API code for job PnlWznmCarDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmCarDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmCarDetail::VecVDo
 ******************************************************************************/

uint PnlWznmCarDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjtieditclick") return BUTJTIEDITCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;

	return(0);
};

string PnlWznmCarDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmCarDetail::ContIac
 ******************************************************************************/

PnlWznmCarDetail::ContIac::ContIac(
			const uint numFPupJti
			, const uint numFPupRet
			, const string& TxfAvl
			, const string& TxfAct
		) :
			Block()
		{
	this->numFPupJti = numFPupJti;
	this->numFPupRet = numFPupRet;
	this->TxfAvl = TxfAvl;
	this->TxfAct = TxfAct;

	mask = {NUMFPUPJTI, NUMFPUPRET, TXFAVL, TXFACT};
};

bool PnlWznmCarDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmCarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmCarDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJti", numFPupJti)) add(NUMFPUPJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAvl", TxfAvl)) add(TXFAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAct", TxfAct)) add(TXFACT);
	};

	return basefound;
};

void PnlWznmCarDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmCarDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmCarDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJti", numFPupJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeStringAttr(wr, itemtag, "sref", "TxfAvl", TxfAvl);
		writeStringAttr(wr, itemtag, "sref", "TxfAct", TxfAct);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmCarDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJti == comp->numFPupJti) insert(items, NUMFPUPJTI);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (TxfAvl == comp->TxfAvl) insert(items, TXFAVL);
	if (TxfAct == comp->TxfAct) insert(items, TXFACT);

	return(items);
};

set<uint> PnlWznmCarDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJTI, NUMFPUPRET, TXFAVL, TXFACT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCarDetail::ContInf
 ******************************************************************************/

PnlWznmCarDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtMdl
			, const string& TxtReu
			, const string& TxtJob
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtMdl = TxtMdl;
	this->TxtReu = TxtReu;
	this->TxtJob = TxtJob;

	mask = {TXTSRF, TXTTIT, TXTMDL, TXTREU, TXTJOB};
};

bool PnlWznmCarDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmCarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmCarDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTit", TxtTit)) add(TXTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtMdl", TxtMdl)) add(TXTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtJob", TxtJob)) add(TXTJOB);
	};

	return basefound;
};

set<uint> PnlWznmCarDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtMdl == comp->TxtMdl) insert(items, TXTMDL);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);

	return(items);
};

set<uint> PnlWznmCarDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTMDL, TXTREU, TXTJOB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCarDetail::StatApp
 ******************************************************************************/

PnlWznmCarDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmCarDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmCarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmCarDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmCarDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmCarDetail::StatApp::diff(
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
 class PnlWznmCarDetail::StatShr
 ******************************************************************************/

PnlWznmCarDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJtiActive
			, const bool ButJtiEditAvail
			, const bool TxtTitActive
			, const bool TxtMdlActive
			, const bool ButMdlViewAvail
			, const bool ButMdlViewActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool TxfAvlActive
			, const bool TxfActActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupJtiActive = PupJtiActive;
	this->ButJtiEditAvail = ButJtiEditAvail;
	this->TxtTitActive = TxtTitActive;
	this->TxtMdlActive = TxtMdlActive;
	this->ButMdlViewAvail = ButMdlViewAvail;
	this->ButMdlViewActive = ButMdlViewActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->TxfAvlActive = TxfAvlActive;
	this->TxfActActive = TxfActActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE};
};

bool PnlWznmCarDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmCarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmCarDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJtiActive", PupJtiActive)) add(PUPJTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", ButJtiEditAvail)) add(BUTJTIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTitActive", TxtTitActive)) add(TXTTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtMdlActive", TxtMdlActive)) add(TXTMDLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", ButMdlViewAvail)) add(BUTMDLVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", ButMdlViewActive)) add(BUTMDLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtJobActive", TxtJobActive)) add(TXTJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", ButJobViewAvail)) add(BUTJOBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewActive", ButJobViewActive)) add(BUTJOBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAvlActive", TxfAvlActive)) add(TXFAVLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfActActive", TxfActActive)) add(TXFACTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmCarDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJtiActive == comp->PupJtiActive) insert(items, PUPJTIACTIVE);
	if (ButJtiEditAvail == comp->ButJtiEditAvail) insert(items, BUTJTIEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (TxtMdlActive == comp->TxtMdlActive) insert(items, TXTMDLACTIVE);
	if (ButMdlViewAvail == comp->ButMdlViewAvail) insert(items, BUTMDLVIEWAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (TxfAvlActive == comp->TxfAvlActive) insert(items, TXFAVLACTIVE);
	if (TxfActActive == comp->TxfActActive) insert(items, TXFACTACTIVE);

	return(items);
};

set<uint> PnlWznmCarDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmCarDetail::Tag
 ******************************************************************************/

PnlWznmCarDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptMdl
			, const string& CptReu
			, const string& CptJob
			, const string& CptAvl
			, const string& CptAct
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptMdl = CptMdl;
	this->CptReu = CptReu;
	this->CptJob = CptJob;
	this->CptAvl = CptAvl;
	this->CptAct = CptAct;

	mask = {CPT, CPTSRF, CPTTIT, CPTMDL, CPTREU, CPTJOB, CPTAVL, CPTACT};
};

bool PnlWznmCarDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmCarDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmCarDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAvl", CptAvl)) add(CPTAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAct", CptAct)) add(CPTACT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmCarDetail::DpchAppData
 ******************************************************************************/

PnlWznmCarDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCARDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmCarDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCarDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmCarDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCarDetail::DpchAppDo
 ******************************************************************************/

PnlWznmCarDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCARDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmCarDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCarDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmCarDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmCarDetail::DpchEngData
 ******************************************************************************/

PnlWznmCarDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCARDETAILDATA)
		{
	feedFPupJti.tag = "FeedFPupJti";
	feedFPupRet.tag = "FeedFPupRet";
};

string PnlWznmCarDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPJTI)) ss.push_back("feedFPupJti");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmCarDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmCarDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupJti.readXML(docctx, basexpath, true)) add(FEEDFPUPJTI);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupJti.clear();
		feedFPupRet.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
