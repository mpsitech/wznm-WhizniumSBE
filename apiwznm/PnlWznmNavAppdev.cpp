/**
	* \file PnlWznmNavAppdev.cpp
	* API code for job PnlWznmNavAppdev (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "PnlWznmNavAppdev.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavAppdev::VecVDo
 ******************************************************************************/

uint PnlWznmNavAppdev::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butappviewclick") return BUTAPPVIEWCLICK;
	if (s == "butappnewcrdclick") return BUTAPPNEWCRDCLICK;
	if (s == "butrtjviewclick") return BUTRTJVIEWCLICK;
	if (s == "butrtjnewcrdclick") return BUTRTJNEWCRDCLICK;
	if (s == "butevtviewclick") return BUTEVTVIEWCLICK;
	if (s == "butevtnewcrdclick") return BUTEVTNEWCRDCLICK;
	if (s == "butseqviewclick") return BUTSEQVIEWCLICK;
	if (s == "butseqnewcrdclick") return BUTSEQNEWCRDCLICK;
	if (s == "butsteviewclick") return BUTSTEVIEWCLICK;
	if (s == "butstenewcrdclick") return BUTSTENEWCRDCLICK;

	return(0);
};

string PnlWznmNavAppdev::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTAPPVIEWCLICK) return("ButAppViewClick");
	if (ix == BUTAPPNEWCRDCLICK) return("ButAppNewcrdClick");
	if (ix == BUTRTJVIEWCLICK) return("ButRtjViewClick");
	if (ix == BUTRTJNEWCRDCLICK) return("ButRtjNewcrdClick");
	if (ix == BUTEVTVIEWCLICK) return("ButEvtViewClick");
	if (ix == BUTEVTNEWCRDCLICK) return("ButEvtNewcrdClick");
	if (ix == BUTSEQVIEWCLICK) return("ButSeqViewClick");
	if (ix == BUTSEQNEWCRDCLICK) return("ButSeqNewcrdClick");
	if (ix == BUTSTEVIEWCLICK) return("ButSteViewClick");
	if (ix == BUTSTENEWCRDCLICK) return("ButSteNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavAppdev::ContIac
 ******************************************************************************/

PnlWznmNavAppdev::ContIac::ContIac(
			const uint numFLstApp
			, const uint numFLstRtj
			, const uint numFLstEvt
			, const uint numFLstSeq
			, const uint numFLstSte
		) :
			Block()
		{
	this->numFLstApp = numFLstApp;
	this->numFLstRtj = numFLstRtj;
	this->numFLstEvt = numFLstEvt;
	this->numFLstSeq = numFLstSeq;
	this->numFLstSte = numFLstSte;

	mask = {NUMFLSTAPP, NUMFLSTRTJ, NUMFLSTEVT, NUMFLSTSEQ, NUMFLSTSTE};
};

bool PnlWznmNavAppdev::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavAppdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavAppdev";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstApp", numFLstApp)) add(NUMFLSTAPP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRtj", numFLstRtj)) add(NUMFLSTRTJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstEvt", numFLstEvt)) add(NUMFLSTEVT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSeq", numFLstSeq)) add(NUMFLSTSEQ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSte", numFLstSte)) add(NUMFLSTSTE);
	};

	return basefound;
};

void PnlWznmNavAppdev::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavAppdev";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavAppdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstApp", numFLstApp);
		writeUintAttr(wr, itemtag, "sref", "numFLstRtj", numFLstRtj);
		writeUintAttr(wr, itemtag, "sref", "numFLstEvt", numFLstEvt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSeq", numFLstSeq);
		writeUintAttr(wr, itemtag, "sref", "numFLstSte", numFLstSte);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavAppdev::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstApp == comp->numFLstApp) insert(items, NUMFLSTAPP);
	if (numFLstRtj == comp->numFLstRtj) insert(items, NUMFLSTRTJ);
	if (numFLstEvt == comp->numFLstEvt) insert(items, NUMFLSTEVT);
	if (numFLstSeq == comp->numFLstSeq) insert(items, NUMFLSTSEQ);
	if (numFLstSte == comp->numFLstSte) insert(items, NUMFLSTSTE);

	return(items);
};

set<uint> PnlWznmNavAppdev::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTAPP, NUMFLSTRTJ, NUMFLSTEVT, NUMFLSTSEQ, NUMFLSTSTE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAppdev::StatApp
 ******************************************************************************/

PnlWznmNavAppdev::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstAppAlt
			, const bool LstRtjAlt
			, const bool LstEvtAlt
			, const bool LstSeqAlt
			, const bool LstSteAlt
			, const uint LstAppNumFirstdisp
			, const uint LstRtjNumFirstdisp
			, const uint LstEvtNumFirstdisp
			, const uint LstSeqNumFirstdisp
			, const uint LstSteNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstAppAlt = LstAppAlt;
	this->LstRtjAlt = LstRtjAlt;
	this->LstEvtAlt = LstEvtAlt;
	this->LstSeqAlt = LstSeqAlt;
	this->LstSteAlt = LstSteAlt;
	this->LstAppNumFirstdisp = LstAppNumFirstdisp;
	this->LstRtjNumFirstdisp = LstRtjNumFirstdisp;
	this->LstEvtNumFirstdisp = LstEvtNumFirstdisp;
	this->LstSeqNumFirstdisp = LstSeqNumFirstdisp;
	this->LstSteNumFirstdisp = LstSteNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTAPPALT, LSTRTJALT, LSTEVTALT, LSTSEQALT, LSTSTEALT, LSTAPPNUMFIRSTDISP, LSTRTJNUMFIRSTDISP, LSTEVTNUMFIRSTDISP, LSTSEQNUMFIRSTDISP, LSTSTENUMFIRSTDISP};
};

bool PnlWznmNavAppdev::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavAppdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavAppdev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAppAlt", LstAppAlt)) add(LSTAPPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtjAlt", LstRtjAlt)) add(LSTRTJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEvtAlt", LstEvtAlt)) add(LSTEVTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSeqAlt", LstSeqAlt)) add(LSTSEQALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSteAlt", LstSteAlt)) add(LSTSTEALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAppNumFirstdisp", LstAppNumFirstdisp)) add(LSTAPPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtjNumFirstdisp", LstRtjNumFirstdisp)) add(LSTRTJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEvtNumFirstdisp", LstEvtNumFirstdisp)) add(LSTEVTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSeqNumFirstdisp", LstSeqNumFirstdisp)) add(LSTSEQNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSteNumFirstdisp", LstSteNumFirstdisp)) add(LSTSTENUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavAppdev::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstAppAlt == comp->LstAppAlt) insert(items, LSTAPPALT);
	if (LstRtjAlt == comp->LstRtjAlt) insert(items, LSTRTJALT);
	if (LstEvtAlt == comp->LstEvtAlt) insert(items, LSTEVTALT);
	if (LstSeqAlt == comp->LstSeqAlt) insert(items, LSTSEQALT);
	if (LstSteAlt == comp->LstSteAlt) insert(items, LSTSTEALT);
	if (LstAppNumFirstdisp == comp->LstAppNumFirstdisp) insert(items, LSTAPPNUMFIRSTDISP);
	if (LstRtjNumFirstdisp == comp->LstRtjNumFirstdisp) insert(items, LSTRTJNUMFIRSTDISP);
	if (LstEvtNumFirstdisp == comp->LstEvtNumFirstdisp) insert(items, LSTEVTNUMFIRSTDISP);
	if (LstSeqNumFirstdisp == comp->LstSeqNumFirstdisp) insert(items, LSTSEQNUMFIRSTDISP);
	if (LstSteNumFirstdisp == comp->LstSteNumFirstdisp) insert(items, LSTSTENUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavAppdev::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTAPPALT, LSTRTJALT, LSTEVTALT, LSTSEQALT, LSTSTEALT, LSTAPPNUMFIRSTDISP, LSTRTJNUMFIRSTDISP, LSTEVTNUMFIRSTDISP, LSTSEQNUMFIRSTDISP, LSTSTENUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAppdev::StatShr
 ******************************************************************************/

PnlWznmNavAppdev::StatShr::StatShr(
			const bool LstAppAvail
			, const bool ButAppViewActive
			, const bool LstRtjAvail
			, const bool ButRtjViewActive
			, const bool ButRtjNewcrdActive
			, const bool LstEvtAvail
			, const bool ButEvtViewActive
			, const bool ButEvtNewcrdActive
			, const bool LstSeqAvail
			, const bool ButSeqViewActive
			, const bool ButSeqNewcrdActive
			, const bool LstSteAvail
			, const bool ButSteViewActive
			, const bool ButSteNewcrdActive
		) :
			Block()
		{
	this->LstAppAvail = LstAppAvail;
	this->ButAppViewActive = ButAppViewActive;
	this->LstRtjAvail = LstRtjAvail;
	this->ButRtjViewActive = ButRtjViewActive;
	this->ButRtjNewcrdActive = ButRtjNewcrdActive;
	this->LstEvtAvail = LstEvtAvail;
	this->ButEvtViewActive = ButEvtViewActive;
	this->ButEvtNewcrdActive = ButEvtNewcrdActive;
	this->LstSeqAvail = LstSeqAvail;
	this->ButSeqViewActive = ButSeqViewActive;
	this->ButSeqNewcrdActive = ButSeqNewcrdActive;
	this->LstSteAvail = LstSteAvail;
	this->ButSteViewActive = ButSteViewActive;
	this->ButSteNewcrdActive = ButSteNewcrdActive;

	mask = {LSTAPPAVAIL, BUTAPPVIEWACTIVE, LSTRTJAVAIL, BUTRTJVIEWACTIVE, BUTRTJNEWCRDACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTSEQAVAIL, BUTSEQVIEWACTIVE, BUTSEQNEWCRDACTIVE, LSTSTEAVAIL, BUTSTEVIEWACTIVE, BUTSTENEWCRDACTIVE};
};

bool PnlWznmNavAppdev::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavAppdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavAppdev";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstAppAvail", LstAppAvail)) add(LSTAPPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButAppViewActive", ButAppViewActive)) add(BUTAPPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstRtjAvail", LstRtjAvail)) add(LSTRTJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRtjViewActive", ButRtjViewActive)) add(BUTRTJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRtjNewcrdActive", ButRtjNewcrdActive)) add(BUTRTJNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstEvtAvail", LstEvtAvail)) add(LSTEVTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEvtViewActive", ButEvtViewActive)) add(BUTEVTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEvtNewcrdActive", ButEvtNewcrdActive)) add(BUTEVTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSeqAvail", LstSeqAvail)) add(LSTSEQAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSeqViewActive", ButSeqViewActive)) add(BUTSEQVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSeqNewcrdActive", ButSeqNewcrdActive)) add(BUTSEQNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSteAvail", LstSteAvail)) add(LSTSTEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSteViewActive", ButSteViewActive)) add(BUTSTEVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSteNewcrdActive", ButSteNewcrdActive)) add(BUTSTENEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmNavAppdev::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstAppAvail == comp->LstAppAvail) insert(items, LSTAPPAVAIL);
	if (ButAppViewActive == comp->ButAppViewActive) insert(items, BUTAPPVIEWACTIVE);
	if (LstRtjAvail == comp->LstRtjAvail) insert(items, LSTRTJAVAIL);
	if (ButRtjViewActive == comp->ButRtjViewActive) insert(items, BUTRTJVIEWACTIVE);
	if (ButRtjNewcrdActive == comp->ButRtjNewcrdActive) insert(items, BUTRTJNEWCRDACTIVE);
	if (LstEvtAvail == comp->LstEvtAvail) insert(items, LSTEVTAVAIL);
	if (ButEvtViewActive == comp->ButEvtViewActive) insert(items, BUTEVTVIEWACTIVE);
	if (ButEvtNewcrdActive == comp->ButEvtNewcrdActive) insert(items, BUTEVTNEWCRDACTIVE);
	if (LstSeqAvail == comp->LstSeqAvail) insert(items, LSTSEQAVAIL);
	if (ButSeqViewActive == comp->ButSeqViewActive) insert(items, BUTSEQVIEWACTIVE);
	if (ButSeqNewcrdActive == comp->ButSeqNewcrdActive) insert(items, BUTSEQNEWCRDACTIVE);
	if (LstSteAvail == comp->LstSteAvail) insert(items, LSTSTEAVAIL);
	if (ButSteViewActive == comp->ButSteViewActive) insert(items, BUTSTEVIEWACTIVE);
	if (ButSteNewcrdActive == comp->ButSteNewcrdActive) insert(items, BUTSTENEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavAppdev::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTAPPAVAIL, BUTAPPVIEWACTIVE, LSTRTJAVAIL, BUTRTJVIEWACTIVE, BUTRTJNEWCRDACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTSEQAVAIL, BUTSEQVIEWACTIVE, BUTSEQNEWCRDACTIVE, LSTSTEAVAIL, BUTSTEVIEWACTIVE, BUTSTENEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAppdev::Tag
 ******************************************************************************/

PnlWznmNavAppdev::Tag::Tag(
			const string& Cpt
			, const string& CptApp
			, const string& CptRtj
			, const string& CptEvt
			, const string& CptSeq
			, const string& CptSte
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptApp = CptApp;
	this->CptRtj = CptRtj;
	this->CptEvt = CptEvt;
	this->CptSeq = CptSeq;
	this->CptSte = CptSte;

	mask = {CPT, CPTAPP, CPTRTJ, CPTEVT, CPTSEQ, CPTSTE};
};

bool PnlWznmNavAppdev::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavAppdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavAppdev";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptApp", CptApp)) add(CPTAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptRtj", CptRtj)) add(CPTRTJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEvt", CptEvt)) add(CPTEVT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSeq", CptSeq)) add(CPTSEQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSte", CptSte)) add(CPTSTE);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavAppdev::DpchAppData
 ******************************************************************************/

PnlWznmNavAppdev::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVAPPDEVDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavAppdev::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAppdev::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavAppdevData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAppdev::DpchAppDo
 ******************************************************************************/

PnlWznmNavAppdev::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVAPPDEVDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavAppdev::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAppdev::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavAppdevDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAppdev::DpchEngData
 ******************************************************************************/

PnlWznmNavAppdev::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVAPPDEVDATA)
		{
	feedFLstApp.tag = "FeedFLstApp";
	feedFLstEvt.tag = "FeedFLstEvt";
	feedFLstRtj.tag = "FeedFLstRtj";
	feedFLstSeq.tag = "FeedFLstSeq";
	feedFLstSte.tag = "FeedFLstSte";
};

string PnlWznmNavAppdev::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTAPP)) ss.push_back("feedFLstApp");
	if (has(FEEDFLSTEVT)) ss.push_back("feedFLstEvt");
	if (has(FEEDFLSTRTJ)) ss.push_back("feedFLstRtj");
	if (has(FEEDFLSTSEQ)) ss.push_back("feedFLstSeq");
	if (has(FEEDFLSTSTE)) ss.push_back("feedFLstSte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAppdev::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavAppdevData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstApp.readXML(docctx, basexpath, true)) add(FEEDFLSTAPP);
		if (feedFLstEvt.readXML(docctx, basexpath, true)) add(FEEDFLSTEVT);
		if (feedFLstRtj.readXML(docctx, basexpath, true)) add(FEEDFLSTRTJ);
		if (feedFLstSeq.readXML(docctx, basexpath, true)) add(FEEDFLSTSEQ);
		if (feedFLstSte.readXML(docctx, basexpath, true)) add(FEEDFLSTSTE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstApp.clear();
		feedFLstEvt.clear();
		feedFLstRtj.clear();
		feedFLstSeq.clear();
		feedFLstSte.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

