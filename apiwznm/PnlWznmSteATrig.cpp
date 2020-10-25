/**
	* \file PnlWznmSteATrig.cpp
	* API code for job PnlWznmSteATrig (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmSteATrig.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSteATrig::VecVDo
 ******************************************************************************/

uint PnlWznmSteATrig::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWznmSteATrig::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWznmSteATrig::ContInf
 ******************************************************************************/

PnlWznmSteATrig::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlWznmSteATrig::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmSteATrig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmSteATrig";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlWznmSteATrig::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWznmSteATrig::ContInf::diff(
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
 class PnlWznmSteATrig::StatApp
 ******************************************************************************/

PnlWznmSteATrig::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmSteATrig::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmSteATrig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmSteATrig";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmSteATrig::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmSteATrig::StatApp::diff(
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
 class PnlWznmSteATrig::StatShr
 ******************************************************************************/

PnlWznmSteATrig::StatShr::StatShr(
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

bool PnlWznmSteATrig::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmSteATrig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmSteATrig";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNewAvail", ButNewAvail)) add(BUTNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateAvail", ButDuplicateAvail)) add(BUTDUPLICATEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", ButDeleteAvail)) add(BUTDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmSteATrig::StatShr::comm(
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

set<uint> PnlWznmSteATrig::StatShr::diff(
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
 class PnlWznmSteATrig::StgIac
 ******************************************************************************/

PnlWznmSteATrig::StgIac::StgIac(
			const uint TcoSrfWidth
			, const uint TcoTypWidth
			, const uint TcoEvtWidth
			, const uint TcoRtjWidth
			, const uint TcoVitWidth
			, const uint TcoXsrWidth
			, const uint TcoRtdWidth
			, const uint TcoMskWidth
			, const uint TcoCndWidth
		) :
			Block()
		{
	this->TcoSrfWidth = TcoSrfWidth;
	this->TcoTypWidth = TcoTypWidth;
	this->TcoEvtWidth = TcoEvtWidth;
	this->TcoRtjWidth = TcoRtjWidth;
	this->TcoVitWidth = TcoVitWidth;
	this->TcoXsrWidth = TcoXsrWidth;
	this->TcoRtdWidth = TcoRtdWidth;
	this->TcoMskWidth = TcoMskWidth;
	this->TcoCndWidth = TcoCndWidth;

	mask = {TCOSRFWIDTH, TCOTYPWIDTH, TCOEVTWIDTH, TCORTJWIDTH, TCOVITWIDTH, TCOXSRWIDTH, TCORTDWIDTH, TCOMSKWIDTH, TCOCNDWIDTH};
};

bool PnlWznmSteATrig::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWznmSteATrig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWznmSteATrig";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", TcoSrfWidth)) add(TCOSRFWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTypWidth", TcoTypWidth)) add(TCOTYPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoEvtWidth", TcoEvtWidth)) add(TCOEVTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRtjWidth", TcoRtjWidth)) add(TCORTJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoVitWidth", TcoVitWidth)) add(TCOVITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoXsrWidth", TcoXsrWidth)) add(TCOXSRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoRtdWidth", TcoRtdWidth)) add(TCORTDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMskWidth", TcoMskWidth)) add(TCOMSKWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoCndWidth", TcoCndWidth)) add(TCOCNDWIDTH);
	};

	return basefound;
};

void PnlWznmSteATrig::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmSteATrig";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWznmSteATrig";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoEvtWidth", TcoEvtWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoRtjWidth", TcoRtjWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoVitWidth", TcoVitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoXsrWidth", TcoXsrWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoRtdWidth", TcoRtdWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMskWidth", TcoMskWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoCndWidth", TcoCndWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteATrig::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoSrfWidth == comp->TcoSrfWidth) insert(items, TCOSRFWIDTH);
	if (TcoTypWidth == comp->TcoTypWidth) insert(items, TCOTYPWIDTH);
	if (TcoEvtWidth == comp->TcoEvtWidth) insert(items, TCOEVTWIDTH);
	if (TcoRtjWidth == comp->TcoRtjWidth) insert(items, TCORTJWIDTH);
	if (TcoVitWidth == comp->TcoVitWidth) insert(items, TCOVITWIDTH);
	if (TcoXsrWidth == comp->TcoXsrWidth) insert(items, TCOXSRWIDTH);
	if (TcoRtdWidth == comp->TcoRtdWidth) insert(items, TCORTDWIDTH);
	if (TcoMskWidth == comp->TcoMskWidth) insert(items, TCOMSKWIDTH);
	if (TcoCndWidth == comp->TcoCndWidth) insert(items, TCOCNDWIDTH);

	return(items);
};

set<uint> PnlWznmSteATrig::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOSRFWIDTH, TCOTYPWIDTH, TCOEVTWIDTH, TCORTJWIDTH, TCOVITWIDTH, TCOXSRWIDTH, TCORTDWIDTH, TCOMSKWIDTH, TCOCNDWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteATrig::Tag
 ******************************************************************************/

PnlWznmSteATrig::Tag::Tag(
			const string& Cpt
			, const string& TxtRecord1
			, const string& TxtRecord2
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoSrf
			, const string& TcoTyp
			, const string& TcoEvt
			, const string& TcoRtj
			, const string& TcoVit
			, const string& TcoXsr
			, const string& TcoRtd
			, const string& TcoMsk
			, const string& TcoCnd
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->TxtRecord1 = TxtRecord1;
	this->TxtRecord2 = TxtRecord2;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoSrf = TcoSrf;
	this->TcoTyp = TcoTyp;
	this->TcoEvt = TcoEvt;
	this->TcoRtj = TcoRtj;
	this->TcoVit = TcoVit;
	this->TcoXsr = TcoXsr;
	this->TcoRtd = TcoRtd;
	this->TcoMsk = TcoMsk;
	this->TcoCnd = TcoCnd;

	mask = {CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTYP, TCOEVT, TCORTJ, TCOVIT, TCOXSR, TCORTD, TCOMSK, TCOCND};
};

bool PnlWznmSteATrig::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmSteATrig");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmSteATrig";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord1", TxtRecord1)) add(TXTRECORD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord2", TxtRecord2)) add(TXTRECORD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSrf", TcoSrf)) add(TCOSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTyp", TcoTyp)) add(TCOTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoEvt", TcoEvt)) add(TCOEVT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoRtj", TcoRtj)) add(TCORTJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoVit", TcoVit)) add(TCOVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoXsr", TcoXsr)) add(TCOXSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoRtd", TcoRtd)) add(TCORTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoMsk", TcoMsk)) add(TCOMSK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoCnd", TcoCnd)) add(TCOCND);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmSteATrig::DpchAppData
 ******************************************************************************/

PnlWznmSteATrig::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryWznmSteATrig::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEATRIGDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWznmSteATrig::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteATrig::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteATrigData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteATrig::DpchAppDo
 ******************************************************************************/

PnlWznmSteATrig::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEATRIGDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmSteATrig::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteATrig::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteATrigDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteATrig::DpchEngData
 ******************************************************************************/

PnlWznmSteATrig::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTEATRIGDATA)
		{
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlWznmSteATrig::DpchEngData::getSrefsMask() {
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

void PnlWznmSteATrig::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmSteATrigData");
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
		statappqry = QryWznmSteATrig::StatApp();
		statshrqry = QryWznmSteATrig::StatShr();
		stgiacqry = QryWznmSteATrig::StgIac();
	};
};

