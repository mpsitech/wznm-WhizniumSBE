/**
	* \file PnlWznmSteAAction.cpp
	* API code for job PnlWznmSteAAction (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmSteAAction.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSteAAction::VecVDo
 ******************************************************************************/

uint PnlWznmSteAAction::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWznmSteAAction::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWznmSteAAction::ContInf
 ******************************************************************************/

PnlWznmSteAAction::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

bool PnlWznmSteAAction::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmSteAAction");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmSteAAction";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFCsiQst", numFCsiQst)) add(NUMFCSIQST);
	};

	return basefound;
};

set<uint> PnlWznmSteAAction::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWznmSteAAction::ContInf::diff(
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
 class PnlWznmSteAAction::StatApp
 ******************************************************************************/

PnlWznmSteAAction::StatApp::StatApp(
			const uint ixWznmVExpstate
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;

	mask = {IXWZNMVEXPSTATE};
};

bool PnlWznmSteAAction::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmSteAAction");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmSteAAction";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWznmSteAAction::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);

	return(items);
};

set<uint> PnlWznmSteAAction::StatApp::diff(
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
 class PnlWznmSteAAction::StatShr
 ******************************************************************************/

PnlWznmSteAAction::StatShr::StatShr(
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

bool PnlWznmSteAAction::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmSteAAction");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmSteAAction";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButNewAvail", ButNewAvail)) add(BUTNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateAvail", ButDuplicateAvail)) add(BUTDUPLICATEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", ButDuplicateActive)) add(BUTDUPLICATEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", ButDeleteAvail)) add(BUTDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDeleteActive", ButDeleteActive)) add(BUTDELETEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmSteAAction::StatShr::comm(
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

set<uint> PnlWznmSteAAction::StatShr::diff(
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
 class PnlWznmSteAAction::StgIac
 ******************************************************************************/

PnlWznmSteAAction::StgIac::StgIac(
			const uint TcoSctWidth
			, const uint TcoTypWidth
			, const uint TcoTrjWidth
			, const uint TcoVecWidth
			, const uint TcoVitWidth
			, const uint TcoSnxWidth
			, const uint TcoSeqWidth
			, const uint TcoTr1Width
			, const uint TcoIp1Width
			, const uint TcoTr2Width
			, const uint TcoIp2Width
			, const uint TcoTr3Width
			, const uint TcoIp3Width
			, const uint TcoTr4Width
			, const uint TcoIp4Width
		) :
			Block()
		{
	this->TcoSctWidth = TcoSctWidth;
	this->TcoTypWidth = TcoTypWidth;
	this->TcoTrjWidth = TcoTrjWidth;
	this->TcoVecWidth = TcoVecWidth;
	this->TcoVitWidth = TcoVitWidth;
	this->TcoSnxWidth = TcoSnxWidth;
	this->TcoSeqWidth = TcoSeqWidth;
	this->TcoTr1Width = TcoTr1Width;
	this->TcoIp1Width = TcoIp1Width;
	this->TcoTr2Width = TcoTr2Width;
	this->TcoIp2Width = TcoIp2Width;
	this->TcoTr3Width = TcoTr3Width;
	this->TcoIp3Width = TcoIp3Width;
	this->TcoTr4Width = TcoTr4Width;
	this->TcoIp4Width = TcoIp4Width;

	mask = {TCOSCTWIDTH, TCOTYPWIDTH, TCOTRJWIDTH, TCOVECWIDTH, TCOVITWIDTH, TCOSNXWIDTH, TCOSEQWIDTH, TCOTR1WIDTH, TCOIP1WIDTH, TCOTR2WIDTH, TCOIP2WIDTH, TCOTR3WIDTH, TCOIP3WIDTH, TCOTR4WIDTH, TCOIP4WIDTH};
};

bool PnlWznmSteAAction::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWznmSteAAction");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWznmSteAAction";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSctWidth", TcoSctWidth)) add(TCOSCTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTypWidth", TcoTypWidth)) add(TCOTYPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTrjWidth", TcoTrjWidth)) add(TCOTRJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoVecWidth", TcoVecWidth)) add(TCOVECWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoVitWidth", TcoVitWidth)) add(TCOVITWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSnxWidth", TcoSnxWidth)) add(TCOSNXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSeqWidth", TcoSeqWidth)) add(TCOSEQWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTr1Width", TcoTr1Width)) add(TCOTR1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp1Width", TcoIp1Width)) add(TCOIP1WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTr2Width", TcoTr2Width)) add(TCOTR2WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp2Width", TcoIp2Width)) add(TCOIP2WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTr3Width", TcoTr3Width)) add(TCOTR3WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp3Width", TcoIp3Width)) add(TCOIP3WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTr4Width", TcoTr4Width)) add(TCOTR4WIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoIp4Width", TcoIp4Width)) add(TCOIP4WIDTH);
	};

	return basefound;
};

void PnlWznmSteAAction::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmSteAAction";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWznmSteAAction";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoSctWidth", TcoSctWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTrjWidth", TcoTrjWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoVecWidth", TcoVecWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoVitWidth", TcoVitWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSnxWidth", TcoSnxWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSeqWidth", TcoSeqWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTr1Width", TcoTr1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp1Width", TcoIp1Width);
		writeUintAttr(wr, itemtag, "sref", "TcoTr2Width", TcoTr2Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp2Width", TcoIp2Width);
		writeUintAttr(wr, itemtag, "sref", "TcoTr3Width", TcoTr3Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp3Width", TcoIp3Width);
		writeUintAttr(wr, itemtag, "sref", "TcoTr4Width", TcoTr4Width);
		writeUintAttr(wr, itemtag, "sref", "TcoIp4Width", TcoIp4Width);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSteAAction::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoSctWidth == comp->TcoSctWidth) insert(items, TCOSCTWIDTH);
	if (TcoTypWidth == comp->TcoTypWidth) insert(items, TCOTYPWIDTH);
	if (TcoTrjWidth == comp->TcoTrjWidth) insert(items, TCOTRJWIDTH);
	if (TcoVecWidth == comp->TcoVecWidth) insert(items, TCOVECWIDTH);
	if (TcoVitWidth == comp->TcoVitWidth) insert(items, TCOVITWIDTH);
	if (TcoSnxWidth == comp->TcoSnxWidth) insert(items, TCOSNXWIDTH);
	if (TcoSeqWidth == comp->TcoSeqWidth) insert(items, TCOSEQWIDTH);
	if (TcoTr1Width == comp->TcoTr1Width) insert(items, TCOTR1WIDTH);
	if (TcoIp1Width == comp->TcoIp1Width) insert(items, TCOIP1WIDTH);
	if (TcoTr2Width == comp->TcoTr2Width) insert(items, TCOTR2WIDTH);
	if (TcoIp2Width == comp->TcoIp2Width) insert(items, TCOIP2WIDTH);
	if (TcoTr3Width == comp->TcoTr3Width) insert(items, TCOTR3WIDTH);
	if (TcoIp3Width == comp->TcoIp3Width) insert(items, TCOIP3WIDTH);
	if (TcoTr4Width == comp->TcoTr4Width) insert(items, TCOTR4WIDTH);
	if (TcoIp4Width == comp->TcoIp4Width) insert(items, TCOIP4WIDTH);

	return(items);
};

set<uint> PnlWznmSteAAction::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOSCTWIDTH, TCOTYPWIDTH, TCOTRJWIDTH, TCOVECWIDTH, TCOVITWIDTH, TCOSNXWIDTH, TCOSEQWIDTH, TCOTR1WIDTH, TCOIP1WIDTH, TCOTR2WIDTH, TCOIP2WIDTH, TCOTR3WIDTH, TCOIP3WIDTH, TCOTR4WIDTH, TCOIP4WIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSteAAction::Tag
 ******************************************************************************/

PnlWznmSteAAction::Tag::Tag(
			const string& Cpt
			, const string& TxtRecord1
			, const string& TxtRecord2
			, const string& Trs
			, const string& TxtShowing1
			, const string& TxtShowing2
			, const string& TcoSct
			, const string& TcoTyp
			, const string& TcoTrj
			, const string& TcoVec
			, const string& TcoVit
			, const string& TcoSnx
			, const string& TcoSeq
			, const string& TcoTr1
			, const string& TcoIp1
			, const string& TcoTr2
			, const string& TcoIp2
			, const string& TcoTr3
			, const string& TcoIp3
			, const string& TcoTr4
			, const string& TcoIp4
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->TxtRecord1 = TxtRecord1;
	this->TxtRecord2 = TxtRecord2;
	this->Trs = Trs;
	this->TxtShowing1 = TxtShowing1;
	this->TxtShowing2 = TxtShowing2;
	this->TcoSct = TcoSct;
	this->TcoTyp = TcoTyp;
	this->TcoTrj = TcoTrj;
	this->TcoVec = TcoVec;
	this->TcoVit = TcoVit;
	this->TcoSnx = TcoSnx;
	this->TcoSeq = TcoSeq;
	this->TcoTr1 = TcoTr1;
	this->TcoIp1 = TcoIp1;
	this->TcoTr2 = TcoTr2;
	this->TcoIp2 = TcoIp2;
	this->TcoTr3 = TcoTr3;
	this->TcoIp3 = TcoIp3;
	this->TcoTr4 = TcoTr4;
	this->TcoIp4 = TcoIp4;

	mask = {CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSCT, TCOTYP, TCOTRJ, TCOVEC, TCOVIT, TCOSNX, TCOSEQ, TCOTR1, TCOIP1, TCOTR2, TCOIP2, TCOTR3, TCOIP3, TCOTR4, TCOIP4};
};

bool PnlWznmSteAAction::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmSteAAction");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmSteAAction";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord1", TxtRecord1)) add(TXTRECORD1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtRecord2", TxtRecord2)) add(TXTRECORD2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Trs", Trs)) add(TRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing1", TxtShowing1)) add(TXTSHOWING1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TxtShowing2", TxtShowing2)) add(TXTSHOWING2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSct", TcoSct)) add(TCOSCT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTyp", TcoTyp)) add(TCOTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTrj", TcoTrj)) add(TCOTRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoVec", TcoVec)) add(TCOVEC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoVit", TcoVit)) add(TCOVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSnx", TcoSnx)) add(TCOSNX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoSeq", TcoSeq)) add(TCOSEQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTr1", TcoTr1)) add(TCOTR1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp1", TcoIp1)) add(TCOIP1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTr2", TcoTr2)) add(TCOTR2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp2", TcoIp2)) add(TCOIP2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTr3", TcoTr3)) add(TCOTR3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp3", TcoIp3)) add(TCOIP3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoTr4", TcoTr4)) add(TCOTR4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "TcoIp4", TcoIp4)) add(TCOIP4);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmSteAAction::DpchAppData
 ******************************************************************************/

PnlWznmSteAAction::DpchAppData::DpchAppData(
			const string& scrJref
			, StgIac* stgiac
			, QryWznmSteAAction::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEAACTIONDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, STGIAC, STGIACQRY};
	else this->mask = mask;

		if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
		if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWznmSteAAction::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteAAction::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteAActionData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteAAction::DpchAppDo
 ******************************************************************************/

PnlWznmSteAAction::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEAACTIONDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmSteAAction::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteAAction::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSteAActionDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteAAction::DpchEngData
 ******************************************************************************/

PnlWznmSteAAction::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTEAACTIONDATA)
		{
	feedFCsiQst.tag = "FeedFCsiQst";
};

string PnlWznmSteAAction::DpchEngData::getSrefsMask() {
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

void PnlWznmSteAAction::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmSteAActionData");
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
		statappqry = QryWznmSteAAction::StatApp();
		statshrqry = QryWznmSteAAction::StatShr();
		stgiacqry = QryWznmSteAAction::StgIac();
	};
};

