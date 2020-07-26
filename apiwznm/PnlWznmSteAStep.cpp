/**
	* \file PnlWznmSteAStep.cpp
	* API code for job PnlWznmSteAStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "PnlWznmSteAStep.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSteAStep::VecVDo
 ******************************************************************************/

uint PnlWznmSteAStep::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWznmSteAStep::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWznmSteAStep::ContInf
 ******************************************************************************/

PnlWznmSteAStep::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlWznmSteAStep::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmSteAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmSteAStep";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlWznmSteAStep::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWznmSteAStep::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteAStep::StatApp
 ******************************************************************************/

PnlWznmSteAStep::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmSteAStep::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmSteAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmSteAStep";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmSteAStep::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmSteAStep::StatApp::diff(
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
 class PnlWznmSteAStep::StatShr
 ******************************************************************************/

PnlWznmSteAStep::StatShr::StatShr(
			const bool ButNewAvail
			, const bool ButDuplicateAvail
			, const bool ButDuplicateActive
			, const bool ButDeleteAvail
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ButNewAvail = ButNewAvail;
	this->ButDuplicateAvail = ButDuplicateAvail;
	this->ButDuplicateActive = ButDuplicateActive;
	this->ButDeleteAvail = ButDeleteAvail;
	this->ButDeleteActive = ButDeleteActive;

	mask = {BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
};

bool PnlWznmSteAStep::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmSteAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmSteAStep";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNewAvail", ButNewAvail)) add(BUTNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateAvail", ButDuplicateAvail)) add(BUTDUPLICATEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", ButDeleteAvail)) add(BUTDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmSteAStep::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButNewAvail == comp->ButNewAvail) insert(items, BUTNEWAVAIL);
	if (ButDuplicateAvail == comp->ButDuplicateAvail) insert(items, BUTDUPLICATEAVAIL);
	if (ButDuplicateActive == comp->ButDuplicateActive) insert(items, BUTDUPLICATEACTIVE);
	if (ButDeleteAvail == comp->ButDeleteAvail) insert(items, BUTDELETEAVAIL);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWznmSteAStep::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteAStep::StgIac
 ******************************************************************************/

PnlWznmSteAStep::StgIac::StgIac(
			const uint TcoSnxWidth
			, const uint TcoTrgWidth
			, const uint TcoRtjWidth
			, const uint TcoVitWidth
			, const uint TcoXsrWidth
			, const uint TcoRtdWidth
			, const uint TcoMskWidth
			, const uint TcoCndWidth
			, const uint TcoCcdWidth
		) :
			Block()
		{
	this->TcoSnxWidth = TcoSnxWidth;
	this->TcoTrgWidth = TcoTrgWidth;
	this->TcoRtjWidth = TcoRtjWidth;
	this->TcoVitWidth = TcoVitWidth;
	this->TcoXsrWidth = TcoXsrWidth;
	this->TcoRtdWidth = TcoRtdWidth;
	this->TcoMskWidth = TcoMskWidth;
	this->TcoCndWidth = TcoCndWidth;
	this->TcoCcdWidth = TcoCcdWidth;

	mask = {TCOSNXWIDTH, TCOTRGWIDTH, TCORTJWIDTH, TCOVITWIDTH, TCOXSRWIDTH, TCORTDWIDTH, TCOMSKWIDTH, TCOCNDWIDTH, TCOCCDWIDTH};
};

bool PnlWznmSteAStep::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWznmSteAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWznmSteAStep";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSnxWidth", TcoSnxWidth)) add(TCOSNXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTrgWidth", TcoTrgWidth)) add(TCOTRGWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRtjWidth", TcoRtjWidth)) add(TCORTJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoVitWidth", TcoVitWidth)) add(TCOVITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXsrWidth", TcoXsrWidth)) add(TCOXSRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRtdWidth", TcoRtdWidth)) add(TCORTDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMskWidth", TcoMskWidth)) add(TCOMSKWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCndWidth", TcoCndWidth)) add(TCOCNDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCcdWidth", TcoCcdWidth)) add(TCOCCDWIDTH);
	};

	return basefound;
};

void PnlWznmSteAStep::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmSteAStep";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWznmSteAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoSnxWidth", TcoSnxWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTrgWidth", TcoTrgWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoRtjWidth", TcoRtjWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoVitWidth", TcoVitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoXsrWidth", TcoXsrWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoRtdWidth", TcoRtdWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMskWidth", TcoMskWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCndWidth", TcoCndWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCcdWidth", TcoCcdWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteAStep::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoSnxWidth == comp->TcoSnxWidth) insert(items, TCOSNXWIDTH);
	if (TcoTrgWidth == comp->TcoTrgWidth) insert(items, TCOTRGWIDTH);
	if (TcoRtjWidth == comp->TcoRtjWidth) insert(items, TCORTJWIDTH);
	if (TcoVitWidth == comp->TcoVitWidth) insert(items, TCOVITWIDTH);
	if (TcoXsrWidth == comp->TcoXsrWidth) insert(items, TCOXSRWIDTH);
	if (TcoRtdWidth == comp->TcoRtdWidth) insert(items, TCORTDWIDTH);
	if (TcoMskWidth == comp->TcoMskWidth) insert(items, TCOMSKWIDTH);
	if (TcoCndWidth == comp->TcoCndWidth) insert(items, TCOCNDWIDTH);
	if (TcoCcdWidth == comp->TcoCcdWidth) insert(items, TCOCCDWIDTH);

	return(items);
};

set<uint> PnlWznmSteAStep::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOSNXWIDTH, TCOTRGWIDTH, TCORTJWIDTH, TCOVITWIDTH, TCOXSRWIDTH, TCORTDWIDTH, TCOMSKWIDTH, TCOCNDWIDTH, TCOCCDWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteAStep::Tag
 ******************************************************************************/

PnlWznmSteAStep::Tag::Tag(
			const string& Cpt
			, const string& TxtRecord1
			, const string& TxtRecord2
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoSnx
			, const string& TcoTrg
			, const string& TcoRtj
			, const string& TcoVit
			, const string& TcoXsr
			, const string& TcoRtd
			, const string& TcoMsk
			, const string& TcoCnd
			, const string& TcoCcd
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->TxtRecord1 = TxtRecord1;
	this->TxtRecord2 = TxtRecord2;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoSnx = TcoSnx;
	this->TcoTrg = TcoTrg;
	this->TcoRtj = TcoRtj;
	this->TcoVit = TcoVit;
	this->TcoXsr = TcoXsr;
	this->TcoRtd = TcoRtd;
	this->TcoMsk = TcoMsk;
	this->TcoCnd = TcoCnd;
	this->TcoCcd = TcoCcd;

	mask = {CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSNX, TCOTRG, TCORTJ, TCOVIT, TCOXSR, TCORTD, TCOMSK, TCOCND, TCOCCD};
};

bool PnlWznmSteAStep::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmSteAStep");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmSteAStep";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord1", TxtRecord1)) add(TXTRECORD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord2", TxtRecord2)) add(TXTRECORD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSnx", TcoSnx)) add(TCOSNX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTrg", TcoTrg)) add(TCOTRG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoRtj", TcoRtj)) add(TCORTJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoVit", TcoVit)) add(TCOVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXsr", TcoXsr)) add(TCOXSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoRtd", TcoRtd)) add(TCORTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMsk", TcoMsk)) add(TCOMSK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCnd", TcoCnd)) add(TCOCND);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCcd", TcoCcd)) add(TCOCCD);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmSteAStep::DpchAppData
 ******************************************************************************/

PnlWznmSteAStep::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryWznmSteAStep::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEASTEPDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWznmSteAStep::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteAStep::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteAStepData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteAStep::DpchAppDo
 ******************************************************************************/

PnlWznmSteAStep::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEASTEPDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmSteAStep::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteAStep::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteAStepDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteAStep::DpchEngData
 ******************************************************************************/

PnlWznmSteAStep::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTEASTEPDATA)
		{
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlWznmSteAStep::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(TAG)) ss.push_back("tag");
	if (has(RST)) ss.push_back("rst");
	if (has(STATAPPQRY)) ss.push_back("statappqry");
	if (has(STATSHRQRY)) ss.push_back("statshrqry");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteAStep::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmSteAStepData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFCsiQst.readXML(docctx, basexpath, true)) add(FEEDFCSIQST);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
		if (rst.readXML(docctx, basexpath, true)) add(RST);
		if (statappqry.readXML(docctx, basexpath, true)) add(STATAPPQRY);
		if (statshrqry.readXML(docctx, basexpath, true)) add(STATSHRQRY);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		continf = ContInf();
		feedFCsiQst.clear();
		statapp = StatApp();
		statshr = StatShr();
		stgiac = StgIac();
		tag = Tag();
		rst.clear();
		statappqry = QryWznmSteAStep::StatApp();
		statshrqry = QryWznmSteAStep::StatShr();
		stgiacqry = QryWznmSteAStep::StgIac();
	};
};

