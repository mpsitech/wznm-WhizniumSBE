/**
	* \file PnlWznmRelList_blks.cpp
	* job handler for job PnlWznmRelList (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmRelList::VecVDo
 ******************************************************************************/

uint PnlWznmRelList::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butfilterclick") return BUTFILTERCLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWznmRelList::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTFILTERCLICK) return("ButFilterClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWznmRelList::ContIac
 ******************************************************************************/

PnlWznmRelList::ContIac::ContIac(
			const uint numFTos
		) :
			Block()
		{
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlWznmRelList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmRelList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmRelList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlWznmRelList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmRelList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmRelList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlWznmRelList::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFTOS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelList::ContInf
 ******************************************************************************/

PnlWznmRelList::ContInf::ContInf(
			const string& TxtFor
			, const string& TxtPre
			, const bool ButFilterOn
			, const uint numFCsiQst
		) :
			Block()
		{
	this->TxtFor = TxtFor;
	this->TxtPre = TxtPre;
	this->ButFilterOn = ButFilterOn;
	this->numFCsiQst = numFCsiQst;

	mask = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
};

void PnlWznmRelList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmRelList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmRelList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFor", TxtFor);
		writeStringAttr(wr, itemtag, "sref", "TxtPre", TxtPre);
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor == comp->TxtFor) insert(items, TXTFOR);
	if (TxtPre == comp->TxtPre) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWznmRelList::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelList::StatShr
 ******************************************************************************/

PnlWznmRelList::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXWZNMVEXPSTATE, BUTDELETEACTIVE};
};

void PnlWznmRelList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmRelList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmRelList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWznmRelList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, BUTDELETEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelList::StgIac
 ******************************************************************************/

PnlWznmRelList::StgIac::StgIac(
			const uint TcoFrtWidth
			, const uint TcoFrsWidth
			, const uint TcoTotWidth
			, const uint TcoTosWidth
			, const uint TcoTypWidth
			, const uint TcoVerWidth
			, const uint TcoSupWidth
			, const uint TcoSrlWidth
			, const uint TcoTblWidth
			, const uint TcoPfxWidth
		) :
			Block()
		{
	this->TcoFrtWidth = TcoFrtWidth;
	this->TcoFrsWidth = TcoFrsWidth;
	this->TcoTotWidth = TcoTotWidth;
	this->TcoTosWidth = TcoTosWidth;
	this->TcoTypWidth = TcoTypWidth;
	this->TcoVerWidth = TcoVerWidth;
	this->TcoSupWidth = TcoSupWidth;
	this->TcoSrlWidth = TcoSrlWidth;
	this->TcoTblWidth = TcoTblWidth;
	this->TcoPfxWidth = TcoPfxWidth;
	mask = {TCOFRTWIDTH, TCOFRSWIDTH, TCOTOTWIDTH, TCOTOSWIDTH, TCOTYPWIDTH, TCOVERWIDTH, TCOSUPWIDTH, TCOSRLWIDTH, TCOTBLWIDTH, TCOPFXWIDTH};
};

bool PnlWznmRelList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWznmRelList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWznmRelList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFrtWidth", TcoFrtWidth)) add(TCOFRTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFrsWidth", TcoFrsWidth)) add(TCOFRSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTotWidth", TcoTotWidth)) add(TCOTOTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTosWidth", TcoTosWidth)) add(TCOTOSWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTypWidth", TcoTypWidth)) add(TCOTYPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoVerWidth", TcoVerWidth)) add(TCOVERWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSupWidth", TcoSupWidth)) add(TCOSUPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSrlWidth", TcoSrlWidth)) add(TCOSRLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoTblWidth", TcoTblWidth)) add(TCOTBLWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPfxWidth", TcoPfxWidth)) add(TCOPFXWIDTH);
	};

	return basefound;
};

void PnlWznmRelList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmRelList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWznmRelList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoFrtWidth", TcoFrtWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoFrsWidth", TcoFrsWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTotWidth", TcoTotWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTosWidth", TcoTosWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoVerWidth", TcoVerWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSupWidth", TcoSupWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSrlWidth", TcoSrlWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoTblWidth", TcoTblWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPfxWidth", TcoPfxWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoFrtWidth == comp->TcoFrtWidth) insert(items, TCOFRTWIDTH);
	if (TcoFrsWidth == comp->TcoFrsWidth) insert(items, TCOFRSWIDTH);
	if (TcoTotWidth == comp->TcoTotWidth) insert(items, TCOTOTWIDTH);
	if (TcoTosWidth == comp->TcoTosWidth) insert(items, TCOTOSWIDTH);
	if (TcoTypWidth == comp->TcoTypWidth) insert(items, TCOTYPWIDTH);
	if (TcoVerWidth == comp->TcoVerWidth) insert(items, TCOVERWIDTH);
	if (TcoSupWidth == comp->TcoSupWidth) insert(items, TCOSUPWIDTH);
	if (TcoSrlWidth == comp->TcoSrlWidth) insert(items, TCOSRLWIDTH);
	if (TcoTblWidth == comp->TcoTblWidth) insert(items, TCOTBLWIDTH);
	if (TcoPfxWidth == comp->TcoPfxWidth) insert(items, TCOPFXWIDTH);

	return(items);
};

set<uint> PnlWznmRelList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOFRTWIDTH, TCOFRSWIDTH, TCOTOTWIDTH, TCOTOSWIDTH, TCOTYPWIDTH, TCOVERWIDTH, TCOSUPWIDTH, TCOSRLWIDTH, TCOTBLWIDTH, TCOPFXWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelList::Tag
 ******************************************************************************/

void PnlWznmRelList::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmRelList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmRelList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Relations");
			writeStringAttr(wr, itemtag, "sref", "TcoFrt", "From table");
			writeStringAttr(wr, itemtag, "sref", "TcoFrs", "From subset");
			writeStringAttr(wr, itemtag, "sref", "TcoTot", "To table");
			writeStringAttr(wr, itemtag, "sref", "TcoTos", "To subset");
			writeStringAttr(wr, itemtag, "sref", "TcoTyp", "Type");
			writeStringAttr(wr, itemtag, "sref", "TcoVer", "Version");
			writeStringAttr(wr, itemtag, "sref", "TcoSup", "Super relation");
			writeStringAttr(wr, itemtag, "sref", "TcoSrl", "Role of sub");
			writeStringAttr(wr, itemtag, "sref", "TcoTbl", "Table");
			writeStringAttr(wr, itemtag, "sref", "TcoPfx", "Prefix");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtFor", VecWznmVTag::getTitle(VecWznmVTag::FOR, ixWznmVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::REC, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::GOTO, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::SHOWLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelList::DpchAppData
 ******************************************************************************/

PnlWznmRelList::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELLISTDATA)
		{
};

string PnlWznmRelList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelList::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmRelListData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (stgiac.readXML(docctx, basexpath, true)) add(STGIAC);
		if (stgiacqry.readXML(docctx, basexpath, true)) add(STGIACQRY);
	} else {
		contiac = ContIac();
		stgiac = StgIac();
		stgiacqry = QryWznmRelList::StgIac();
	};
};

/******************************************************************************
 class PnlWznmRelList::DpchAppDo
 ******************************************************************************/

PnlWznmRelList::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELLISTDO)
		{
	ixVDo = 0;
};

string PnlWznmRelList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelList::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmRelListDo");
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
 class PnlWznmRelList::DpchEngData
 ******************************************************************************/

PnlWznmRelList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListWznmQRelList* rst
			, QryWznmRelList::StatShr* statshrqry
			, QryWznmRelList::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRELLISTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFCSIQST, FEEDFTOS, STATSHR, STGIAC, TAG, RST, STATAPPQRY, STATSHRQRY, STGIACQRY};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFCSIQST) && feedFCsiQst) this->feedFCsiQst = *feedFCsiQst;
	if (find(this->mask, FEEDFTOS) && feedFTos) this->feedFTos = *feedFTos;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
	if (find(this->mask, STGIAC) && stgiac) this->stgiac = *stgiac;
	if (find(this->mask, RST) && rst) this->rst = *rst;
	if (find(this->mask, STATSHRQRY) && statshrqry) this->statshrqry = *statshrqry;
	if (find(this->mask, STGIACQRY) && stgiacqry) this->stgiacqry = *stgiacqry;
};

string PnlWznmRelList::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFCSIQST)) ss.push_back("feedFCsiQst");
	if (has(FEEDFTOS)) ss.push_back("feedFTos");
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

void PnlWznmRelList::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFCSIQST)) {feedFCsiQst = src->feedFCsiQst; add(FEEDFCSIQST);};
	if (src->has(FEEDFTOS)) {feedFTos = src->feedFTos; add(FEEDFTOS);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGIAC)) {stgiac = src->stgiac; add(STGIAC);};
	if (src->has(TAG)) add(TAG);
	if (src->has(RST)) {rst = src->rst; add(RST);};
	if (src->has(STATAPPQRY)) add(STATAPPQRY);
	if (src->has(STATSHRQRY)) {statshrqry = src->statshrqry; add(STATSHRQRY);};
	if (src->has(STGIACQRY)) {stgiacqry = src->stgiacqry; add(STGIACQRY);};
};

void PnlWznmRelList::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmRelListData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(FEEDFTOS)) feedFTos.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWznmRelList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};



