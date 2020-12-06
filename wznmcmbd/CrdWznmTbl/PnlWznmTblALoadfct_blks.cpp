/**
	* \file PnlWznmTblALoadfct_blks.cpp
	* job handler for job PnlWznmTblALoadfct (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTblALoadfct::VecVDo
 ******************************************************************************/

uint PnlWznmTblALoadfct::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butnewclick") return BUTNEWCLICK;
	if (s == "butduplicateclick") return BUTDUPLICATECLICK;
	if (s == "butdeleteclick") return BUTDELETECLICK;
	if (s == "butrefreshclick") return BUTREFRESHCLICK;

	return(0);
};

string PnlWznmTblALoadfct::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTNEWCLICK) return("ButNewClick");
	if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
	if (ix == BUTDELETECLICK) return("ButDeleteClick");
	if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

	return("");
};

/******************************************************************************
 class PnlWznmTblALoadfct::ContInf
 ******************************************************************************/

PnlWznmTblALoadfct::ContInf::ContInf(
			const uint numFCsiQst
		) :
			Block()
		{
	this->numFCsiQst = numFCsiQst;

	mask = {NUMFCSIQST};
};

void PnlWznmTblALoadfct::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmTblALoadfct";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmTblALoadfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTblALoadfct::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWznmTblALoadfct::ContInf::diff(
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
 class PnlWznmTblALoadfct::StatApp
 ******************************************************************************/

void PnlWznmTblALoadfct::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmTblALoadfct";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmTblALoadfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblALoadfct::StatShr
 ******************************************************************************/

PnlWznmTblALoadfct::StatShr::StatShr(
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

void PnlWznmTblALoadfct::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmTblALoadfct";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmTblALoadfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButNewAvail", ButNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateAvail", ButDuplicateAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDuplicateActive", ButDuplicateActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteAvail", ButDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTblALoadfct::StatShr::comm(
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

set<uint> PnlWznmTblALoadfct::StatShr::diff(
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
 class PnlWznmTblALoadfct::StgIac
 ******************************************************************************/

PnlWznmTblALoadfct::StgIac::StgIac(
			const uint TcoLotWidth
			, const uint TcoFnaWidth
			, const uint TcoLdxWidth
			, const uint TcoLbyWidth
			, const uint TcoOrdWidth
			, const uint TcoLitWidth
		) :
			Block()
		{
	this->TcoLotWidth = TcoLotWidth;
	this->TcoFnaWidth = TcoFnaWidth;
	this->TcoLdxWidth = TcoLdxWidth;
	this->TcoLbyWidth = TcoLbyWidth;
	this->TcoOrdWidth = TcoOrdWidth;
	this->TcoLitWidth = TcoLitWidth;
	mask = {TCOLOTWIDTH, TCOFNAWIDTH, TCOLDXWIDTH, TCOLBYWIDTH, TCOORDWIDTH, TCOLITWIDTH};
};

bool PnlWznmTblALoadfct::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWznmTblALoadfct");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWznmTblALoadfct";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLotWidth", TcoLotWidth)) add(TCOLOTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoFnaWidth", TcoFnaWidth)) add(TCOFNAWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLdxWidth", TcoLdxWidth)) add(TCOLDXWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLbyWidth", TcoLbyWidth)) add(TCOLBYWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOrdWidth", TcoOrdWidth)) add(TCOORDWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLitWidth", TcoLitWidth)) add(TCOLITWIDTH);
	};

	return basefound;
};

void PnlWznmTblALoadfct::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmTblALoadfct";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWznmTblALoadfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoLotWidth", TcoLotWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoFnaWidth", TcoFnaWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLdxWidth", TcoLdxWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLbyWidth", TcoLbyWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoOrdWidth", TcoOrdWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLitWidth", TcoLitWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTblALoadfct::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoLotWidth == comp->TcoLotWidth) insert(items, TCOLOTWIDTH);
	if (TcoFnaWidth == comp->TcoFnaWidth) insert(items, TCOFNAWIDTH);
	if (TcoLdxWidth == comp->TcoLdxWidth) insert(items, TCOLDXWIDTH);
	if (TcoLbyWidth == comp->TcoLbyWidth) insert(items, TCOLBYWIDTH);
	if (TcoOrdWidth == comp->TcoOrdWidth) insert(items, TCOORDWIDTH);
	if (TcoLitWidth == comp->TcoLitWidth) insert(items, TCOLITWIDTH);

	return(items);
};

set<uint> PnlWznmTblALoadfct::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOLOTWIDTH, TCOFNAWIDTH, TCOLDXWIDTH, TCOLBYWIDTH, TCOORDWIDTH, TCOLITWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTblALoadfct::Tag
 ******************************************************************************/

void PnlWznmTblALoadfct::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmTblALoadfct";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmTblALoadfct";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Load functions");
			writeStringAttr(wr, itemtag, "sref", "TcoLot", "Load type");
			writeStringAttr(wr, itemtag, "sref", "TcoFna", "Fct. name");
			writeStringAttr(wr, itemtag, "sref", "TcoLdx", "Load tbl. col.");
			writeStringAttr(wr, itemtag, "sref", "TcoLby", "Load by tbl. cols.");
			writeStringAttr(wr, itemtag, "sref", "TcoOrd", "Ord. by tbl. cols.");
			writeStringAttr(wr, itemtag, "sref", "TcoLit", "Limitation type");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::REC, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::GOTO, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", VecWznmVTag::getTitle(VecWznmVTag::SHOWSHORT, ixWznmVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", VecWznmVTag::getTitle(VecWznmVTag::EMPSHORT, ixWznmVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblALoadfct::DpchAppData
 ******************************************************************************/

PnlWznmTblALoadfct::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLALOADFCTDATA)
		{
};

string PnlWznmTblALoadfct::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblALoadfct::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTblALoadfctData");
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
		stgiacqry = QryWznmTblALoadfct::StgIac();
	};
};

/******************************************************************************
 class PnlWznmTblALoadfct::DpchAppDo
 ******************************************************************************/

PnlWznmTblALoadfct::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLALOADFCTDO)
		{
	ixVDo = 0;
};

string PnlWznmTblALoadfct::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblALoadfct::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTblALoadfctDo");
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
 class PnlWznmTblALoadfct::DpchEngData
 ******************************************************************************/

PnlWznmTblALoadfct::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFCsiQst
			, StatShr* statshr
			, StgIac* stgiac
			, ListWznmQTblALoadfct* rst
			, QryWznmTblALoadfct::StatShr* statshrqry
			, QryWznmTblALoadfct::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTBLALOADFCTDATA, jref)
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

string PnlWznmTblALoadfct::DpchEngData::getSrefsMask() {
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

void PnlWznmTblALoadfct::DpchEngData::merge(
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

void PnlWznmTblALoadfct::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmTblALoadfctData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFCSIQST)) feedFCsiQst.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGIAC)) stgiac.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
		if (has(RST)) rst.writeXML(wr);
		if (has(STATAPPQRY)) QryWznmTblALoadfct::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};
