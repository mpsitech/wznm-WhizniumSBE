/**
	* \file PnlWznmSteAAction_blks.cpp
	* job handler for job PnlWznmSteAAction (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void PnlWznmSteAAction::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmSteAAction";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmSteAAction";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
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

void PnlWznmSteAAction::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmSteAAction";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmSteAAction";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
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

void PnlWznmSteAAction::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmSteAAction";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmSteAAction";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButNewAvail", ButNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateAvail", ButDuplicateAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteAvail", ButDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
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

void PnlWznmSteAAction::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmSteAAction";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmSteAAction";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Actions");
			writeStringAttr(wr, itemtag, "sref", "TcoSct", "Section");
			writeStringAttr(wr, itemtag, "sref", "TcoTyp", "Type");
			writeStringAttr(wr, itemtag, "sref", "TcoTrj", "Run-time job");
			writeStringAttr(wr, itemtag, "sref", "TcoVec", "UI action vector");
			writeStringAttr(wr, itemtag, "sref", "TcoVit", "UI action vector item");
			writeStringAttr(wr, itemtag, "sref", "TcoSnx", "Next state");
			writeStringAttr(wr, itemtag, "sref", "TcoSeq", "Next sequence");
			writeStringAttr(wr, itemtag, "sref", "TcoTr1", "Tr1SrefATrig");
			writeStringAttr(wr, itemtag, "sref", "TcoIp1", "Ip1");
			writeStringAttr(wr, itemtag, "sref", "TcoTr2", "Tr2SrefATrig");
			writeStringAttr(wr, itemtag, "sref", "TcoIp2", "Ip2");
			writeStringAttr(wr, itemtag, "sref", "TcoTr3", "Tr3SrefATrig");
			writeStringAttr(wr, itemtag, "sref", "TcoIp3", "Ip3");
			writeStringAttr(wr, itemtag, "sref", "TcoTr4", "Tr4SrefATrig");
			writeStringAttr(wr, itemtag, "sref", "TcoIp4", "Ip4");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::REC, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::GOTO, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecWznmVTag::getTitle(VecWznmVTag::SHOWSHORT, ixWznmVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecWznmVTag::getTitle(VecWznmVTag::EMPSHORT, ixWznmVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSteAAction::DpchAppData
 ******************************************************************************/

PnlWznmSteAAction::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEAACTIONDATA)
		{
};

string PnlWznmSteAAction::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteAAction::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSteAActionData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		stgiac = StgIac();
		stgiacqry = QryWznmSteAAction::StgIac();
	};
};

/******************************************************************************
 class PnlWznmSteAAction::DpchAppDo
 ******************************************************************************/

PnlWznmSteAAction::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSTEAACTIONDO)
		{
	ixVDo = 0;
};

string PnlWznmSteAAction::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSteAAction::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSteAActionDo");
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
 class PnlWznmSteAAction::DpchEngData
 ******************************************************************************/

PnlWznmSteAAction::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListWznmQSteAAction* rst
			, QryWznmSteAAction::StatShr* statshrqry
			, QryWznmSteAAction::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSTEAACTIONDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFCSIQST, STATAPP, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWznmSteAAction::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWznmSteAAction::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlWznmSteAAction::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmSteAActionData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWznmSteAAction::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
