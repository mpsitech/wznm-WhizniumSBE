/**
	* \file PnlWznmQmdDetail_blks.cpp
	* job handler for job PnlWznmQmdDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmQmdDetail::VecVDo
 ******************************************************************************/

uint PnlWznmQmdDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butqryviewclick") return BUTQRYVIEWCLICK;
	if (s == "butpstviewclick") return BUTPSTVIEWCLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;

	return(0);
};

string PnlWznmQmdDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTQRYVIEWCLICK) return("ButQryViewClick");
	if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmQmdDetail::ContIac
 ******************************************************************************/

PnlWznmQmdDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFPupRet
			, const string& TxfAvl
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->numFPupRet = numFPupRet;
	this->TxfAvl = TxfAvl;

	mask = {NUMFPUPTYP, NUMFPUPRET, TXFAVL};
};

bool PnlWznmQmdDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmQmdDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmQmdDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAvl", TxfAvl)) add(TXFAVL);
	};

	return basefound;
};

void PnlWznmQmdDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmQmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmQmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeStringAttr(wr, itemtag, "sref", "TxfAvl", TxfAvl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQmdDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (TxfAvl == comp->TxfAvl) insert(items, TXFAVL);

	return(items);
};

set<uint> PnlWznmQmdDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFPUPRET, TXFAVL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQmdDetail::ContInf
 ******************************************************************************/

PnlWznmQmdDetail::ContInf::ContInf(
			const string& TxtQry
			, const string& TxtPst
			, const string& TxtReu
		) :
			Block()
		{
	this->TxtQry = TxtQry;
	this->TxtPst = TxtPst;
	this->TxtReu = TxtReu;

	mask = {TXTQRY, TXTPST, TXTREU};
};

void PnlWznmQmdDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmQmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmQmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtQry", TxtQry);
		writeStringAttr(wr, itemtag, "sref", "TxtPst", TxtPst);
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQmdDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtQry == comp->TxtQry) insert(items, TXTQRY);
	if (TxtPst == comp->TxtPst) insert(items, TXTPST);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);

	return(items);
};

set<uint> PnlWznmQmdDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTQRY, TXTPST, TXTREU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQmdDetail::StatApp
 ******************************************************************************/

void PnlWznmQmdDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmQmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmQmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQmdDetail::StatShr
 ******************************************************************************/

PnlWznmQmdDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool PupTypActive
			, const bool TxtQryActive
			, const bool ButQryViewAvail
			, const bool ButQryViewActive
			, const bool TxtPstActive
			, const bool ButPstViewAvail
			, const bool ButPstViewActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxfAvlActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->PupTypActive = PupTypActive;
	this->TxtQryActive = TxtQryActive;
	this->ButQryViewAvail = ButQryViewAvail;
	this->ButQryViewActive = ButQryViewActive;
	this->TxtPstActive = TxtPstActive;
	this->ButPstViewAvail = ButPstViewAvail;
	this->ButPstViewActive = ButPstViewActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxfAvlActive = TxfAvlActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, PUPTYPACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXFAVLACTIVE};
};

void PnlWznmQmdDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmQmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmQmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtQryActive", TxtQryActive);
		writeBoolAttr(wr, itemtag, "sref", "ButQryViewAvail", ButQryViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButQryViewActive", ButQryViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstActive", TxtPstActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewAvail", ButPstViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewActive", ButPstViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAvlActive", TxfAvlActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQmdDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtQryActive == comp->TxtQryActive) insert(items, TXTQRYACTIVE);
	if (ButQryViewAvail == comp->ButQryViewAvail) insert(items, BUTQRYVIEWAVAIL);
	if (ButQryViewActive == comp->ButQryViewActive) insert(items, BUTQRYVIEWACTIVE);
	if (TxtPstActive == comp->TxtPstActive) insert(items, TXTPSTACTIVE);
	if (ButPstViewAvail == comp->ButPstViewAvail) insert(items, BUTPSTVIEWAVAIL);
	if (ButPstViewActive == comp->ButPstViewActive) insert(items, BUTPSTVIEWACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxfAvlActive == comp->TxfAvlActive) insert(items, TXFAVLACTIVE);

	return(items);
};

set<uint> PnlWznmQmdDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, PUPTYPACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXFAVLACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQmdDetail::Tag
 ******************************************************************************/

void PnlWznmQmdDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmQmdDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmQmdDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptQry", "query");
			writeStringAttr(wr, itemtag, "sref", "CptPst", "presetting");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptAvl", "availability rule");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQmdDetail::DpchAppData
 ******************************************************************************/

PnlWznmQmdDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQMDDETAILDATA)
		{
};

string PnlWznmQmdDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQmdDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmQmdDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWznmQmdDetail::DpchAppDo
 ******************************************************************************/

PnlWznmQmdDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQMDDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmQmdDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQmdDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmQmdDetailDo");
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
 class PnlWznmQmdDetail::DpchEngData
 ******************************************************************************/

PnlWznmQmdDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupRet
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMQMDDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPRET, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmQmdDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQmdDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmQmdDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmQmdDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
