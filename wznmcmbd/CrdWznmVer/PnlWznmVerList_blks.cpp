/**
	* \file PnlWznmVerList_blks.cpp
	* job handler for job PnlWznmVerList (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVerList::VecVDo
 ******************************************************************************/

uint PnlWznmVerList::VecVDo::getIx(
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

string PnlWznmVerList::VecVDo::getSref(
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
 class PnlWznmVerList::ContIac
 ******************************************************************************/

PnlWznmVerList::ContIac::ContIac(
			const uint numFTos
		) :
			Block()
		{
	this->numFTos = numFTos;

	mask = {NUMFTOS};
};

bool PnlWznmVerList::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmVerList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmVerList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFTos", numFTos)) add(NUMFTOS);
	};

	return basefound;
};

void PnlWznmVerList::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmVerList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmVerList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFTos", numFTos);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerList::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFTos == comp->numFTos) insert(items, NUMFTOS);

	return(items);
};

set<uint> PnlWznmVerList::ContIac::diff(
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
 class PnlWznmVerList::ContInf
 ******************************************************************************/

PnlWznmVerList::ContInf::ContInf(
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

void PnlWznmVerList::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVerList";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmVerList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFor", TxtFor);
		writeStringAttr(wr, itemtag, "sref", "TxtPre", TxtPre);
		writeBoolAttr(wr, itemtag, "sref", "ButFilterOn", ButFilterOn);
		writeUintAttr(wr, itemtag, "sref", "numFCsiQst", numFCsiQst);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerList::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFor == comp->TxtFor) insert(items, TXTFOR);
	if (TxtPre == comp->TxtPre) insert(items, TXTPRE);
	if (ButFilterOn == comp->ButFilterOn) insert(items, BUTFILTERON);
	if (numFCsiQst == comp->numFCsiQst) insert(items, NUMFCSIQST);

	return(items);
};

set<uint> PnlWznmVerList::ContInf::diff(
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
 class PnlWznmVerList::StatShr
 ******************************************************************************/

PnlWznmVerList::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const bool ButDeleteActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->ButDeleteActive = ButDeleteActive;

	mask = {IXWZNMVEXPSTATE, BUTDELETEACTIVE};
};

void PnlWznmVerList::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVerList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmVerList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "ButDeleteActive", ButDeleteActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (ButDeleteActive == comp->ButDeleteActive) insert(items, BUTDELETEACTIVE);

	return(items);
};

set<uint> PnlWznmVerList::StatShr::diff(
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
 class PnlWznmVerList::StgIac
 ******************************************************************************/

PnlWznmVerList::StgIac::StgIac(
			const uint TcoGrpWidth
			, const uint TcoOwnWidth
			, const uint TcoPrjWidth
			, const uint TcoMajWidth
			, const uint TcoMinWidth
			, const uint TcoSubWidth
			, const uint TcoBvrWidth
			, const uint TcoLocWidth
			, const uint TcoSteWidth
			, const uint TcoDtyWidth
		) :
			Block()
		{
	this->TcoGrpWidth = TcoGrpWidth;
	this->TcoOwnWidth = TcoOwnWidth;
	this->TcoPrjWidth = TcoPrjWidth;
	this->TcoMajWidth = TcoMajWidth;
	this->TcoMinWidth = TcoMinWidth;
	this->TcoSubWidth = TcoSubWidth;
	this->TcoBvrWidth = TcoBvrWidth;
	this->TcoLocWidth = TcoLocWidth;
	this->TcoSteWidth = TcoSteWidth;
	this->TcoDtyWidth = TcoDtyWidth;
	mask = {TCOGRPWIDTH, TCOOWNWIDTH, TCOPRJWIDTH, TCOMAJWIDTH, TCOMINWIDTH, TCOSUBWIDTH, TCOBVRWIDTH, TCOLOCWIDTH, TCOSTEWIDTH, TCODTYWIDTH};
};

bool PnlWznmVerList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacWznmVerList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacWznmVerList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoGrpWidth", TcoGrpWidth)) add(TCOGRPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoOwnWidth", TcoOwnWidth)) add(TCOOWNWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoPrjWidth", TcoPrjWidth)) add(TCOPRJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMajWidth", TcoMajWidth)) add(TCOMAJWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoMinWidth", TcoMinWidth)) add(TCOMINWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSubWidth", TcoSubWidth)) add(TCOSUBWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoBvrWidth", TcoBvrWidth)) add(TCOBVRWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoLocWidth", TcoLocWidth)) add(TCOLOCWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoSteWidth", TcoSteWidth)) add(TCOSTEWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TcoDtyWidth", TcoDtyWidth)) add(TCODTYWIDTH);
	};

	return basefound;
};

void PnlWznmVerList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacWznmVerList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacWznmVerList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "TcoGrpWidth", TcoGrpWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoOwnWidth", TcoOwnWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoPrjWidth", TcoPrjWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMajWidth", TcoMajWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoMinWidth", TcoMinWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSubWidth", TcoSubWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoBvrWidth", TcoBvrWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoLocWidth", TcoLocWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoSteWidth", TcoSteWidth);
		writeUintAttr(wr, itemtag, "sref", "TcoDtyWidth", TcoDtyWidth);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (TcoGrpWidth == comp->TcoGrpWidth) insert(items, TCOGRPWIDTH);
	if (TcoOwnWidth == comp->TcoOwnWidth) insert(items, TCOOWNWIDTH);
	if (TcoPrjWidth == comp->TcoPrjWidth) insert(items, TCOPRJWIDTH);
	if (TcoMajWidth == comp->TcoMajWidth) insert(items, TCOMAJWIDTH);
	if (TcoMinWidth == comp->TcoMinWidth) insert(items, TCOMINWIDTH);
	if (TcoSubWidth == comp->TcoSubWidth) insert(items, TCOSUBWIDTH);
	if (TcoBvrWidth == comp->TcoBvrWidth) insert(items, TCOBVRWIDTH);
	if (TcoLocWidth == comp->TcoLocWidth) insert(items, TCOLOCWIDTH);
	if (TcoSteWidth == comp->TcoSteWidth) insert(items, TCOSTEWIDTH);
	if (TcoDtyWidth == comp->TcoDtyWidth) insert(items, TCODTYWIDTH);

	return(items);
};

set<uint> PnlWznmVerList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TCOGRPWIDTH, TCOOWNWIDTH, TCOPRJWIDTH, TCOMAJWIDTH, TCOMINWIDTH, TCOSUBWIDTH, TCOBVRWIDTH, TCOLOCWIDTH, TCOSTEWIDTH, TCODTYWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVerList::Tag
 ******************************************************************************/

void PnlWznmVerList::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmVerList";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmVerList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Versions");
			writeStringAttr(wr, itemtag, "sref", "TcoPrj", "Project");
			writeStringAttr(wr, itemtag, "sref", "TcoMaj", "Major");
			writeStringAttr(wr, itemtag, "sref", "TcoMin", "Minor");
			writeStringAttr(wr, itemtag, "sref", "TcoSub", "Sub");
			writeStringAttr(wr, itemtag, "sref", "TcoBvr", "Base version");
			writeStringAttr(wr, itemtag, "sref", "TcoLoc", "Primary locale");
			writeStringAttr(wr, itemtag, "sref", "TcoSte", "State");
			writeStringAttr(wr, itemtag, "sref", "TcoDty", "DBMS types");
		};
		writeStringAttr(wr, itemtag, "sref", "TxtFor", VecWznmVTag::getTitle(VecWznmVTag::FOR, ixWznmVLocale));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord1", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::REC, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtRecord2", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "Trs", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::GOTO, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "TxtShowing1", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::SHOWLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TxtShowing2", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::EMPLONG, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TcoGrp", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::GRP, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "TcoOwn", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::OWN, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVerList::DpchAppData
 ******************************************************************************/

PnlWznmVerList::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERLISTDATA)
		{
};

string PnlWznmVerList::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(STGIAC)) ss.push_back("stgiac");
	if (has(STGIACQRY)) ss.push_back("stgiacqry");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerList::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVerListData");
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
		stgiacqry = QryWznmVerList::StgIac();
	};
};

/******************************************************************************
 class PnlWznmVerList::DpchAppDo
 ******************************************************************************/

PnlWznmVerList::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERLISTDO)
		{
	ixVDo = 0;
};

string PnlWznmVerList::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerList::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVerListDo");
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
 class PnlWznmVerList::DpchEngData
 ******************************************************************************/

PnlWznmVerList::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFCsiQst
			, Feed* feedFTos
			, StatShr* statshr
			, StgIac* stgiac
			, ListWznmQVerList* rst
			, QryWznmVerList::StatShr* statshrqry
			, QryWznmVerList::StgIac* stgiacqry
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVERLISTDATA, jref)
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

string PnlWznmVerList::DpchEngData::getSrefsMask() {
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

void PnlWznmVerList::DpchEngData::merge(
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

void PnlWznmVerList::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmVerListData");
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
		if (has(STATAPPQRY)) QryWznmVerList::StatApp::writeXML(wr);
		if (has(STATSHRQRY)) statshrqry.writeXML(wr);
		if (has(STGIACQRY)) stgiacqry.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

