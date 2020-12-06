/**
	* \file PnlWznmTagDetail_blks.cpp
	* job handler for job PnlWznmTagDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTagDetail::VecVDo
 ******************************************************************************/

uint PnlWznmTagDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjtieditclick") return BUTJTIEDITCLICK;
	if (s == "butcpbviewclick") return BUTCPBVIEWCLICK;
	if (s == "butgrpeditclick") return BUTGRPEDITCLICK;

	return(0);
};

string PnlWznmTagDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
	if (ix == BUTCPBVIEWCLICK) return("ButCpbViewClick");
	if (ix == BUTGRPEDITCLICK) return("ButGrpEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmTagDetail::ContIac
 ******************************************************************************/

PnlWznmTagDetail::ContIac::ContIac(
			const uint numFPupJti
			, const uint numFPupGrp
			, const string& TxfGrp
		) :
			Block()
		{
	this->numFPupJti = numFPupJti;
	this->numFPupGrp = numFPupGrp;
	this->TxfGrp = TxfGrp;

	mask = {NUMFPUPJTI, NUMFPUPGRP, TXFGRP};
};

bool PnlWznmTagDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmTagDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmTagDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJti", numFPupJti)) add(NUMFPUPJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupGrp", numFPupGrp)) add(NUMFPUPGRP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfGrp", TxfGrp)) add(TXFGRP);
	};

	return basefound;
};

void PnlWznmTagDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmTagDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmTagDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJti", numFPupJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupGrp", numFPupGrp);
		writeStringAttr(wr, itemtag, "sref", "TxfGrp", TxfGrp);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTagDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJti == comp->numFPupJti) insert(items, NUMFPUPJTI);
	if (numFPupGrp == comp->numFPupGrp) insert(items, NUMFPUPGRP);
	if (TxfGrp == comp->TxfGrp) insert(items, TXFGRP);

	return(items);
};

set<uint> PnlWznmTagDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJTI, NUMFPUPGRP, TXFGRP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTagDetail::ContInf
 ******************************************************************************/

PnlWznmTagDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtCpb
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtCpb = TxtCpb;

	mask = {TXTSRF, TXTTIT, TXTCPB};
};

void PnlWznmTagDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmTagDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmTagDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTit", TxtTit);
		writeStringAttr(wr, itemtag, "sref", "TxtCpb", TxtCpb);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTagDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtCpb == comp->TxtCpb) insert(items, TXTCPB);

	return(items);
};

set<uint> PnlWznmTagDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTCPB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTagDetail::StatApp
 ******************************************************************************/

void PnlWznmTagDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool PupGrpAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmTagDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmTagDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupGrpAlt", PupGrpAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTagDetail::StatShr
 ******************************************************************************/

PnlWznmTagDetail::StatShr::StatShr(
			const bool TxfGrpValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJtiActive
			, const bool ButJtiEditAvail
			, const bool TxtTitActive
			, const bool TxtCpbActive
			, const bool ButCpbViewAvail
			, const bool ButCpbViewActive
			, const bool PupGrpActive
			, const bool ButGrpEditAvail
		) :
			Block()
		{
	this->TxfGrpValid = TxfGrpValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupJtiActive = PupJtiActive;
	this->ButJtiEditAvail = ButJtiEditAvail;
	this->TxtTitActive = TxtTitActive;
	this->TxtCpbActive = TxtCpbActive;
	this->ButCpbViewAvail = ButCpbViewAvail;
	this->ButCpbViewActive = ButCpbViewActive;
	this->PupGrpActive = PupGrpActive;
	this->ButGrpEditAvail = ButGrpEditAvail;

	mask = {TXFGRPVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTCPBACTIVE, BUTCPBVIEWAVAIL, BUTCPBVIEWACTIVE, PUPGRPACTIVE, BUTGRPEDITAVAIL};
};

void PnlWznmTagDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmTagDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmTagDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfGrpValid", TxfGrpValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJtiActive", PupJtiActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJtiEditAvail", ButJtiEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtTitActive", TxtTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtCpbActive", TxtCpbActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCpbViewAvail", ButCpbViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCpbViewActive", ButCpbViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupGrpActive", PupGrpActive);
		writeBoolAttr(wr, itemtag, "sref", "ButGrpEditAvail", ButGrpEditAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTagDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfGrpValid == comp->TxfGrpValid) insert(items, TXFGRPVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJtiActive == comp->PupJtiActive) insert(items, PUPJTIACTIVE);
	if (ButJtiEditAvail == comp->ButJtiEditAvail) insert(items, BUTJTIEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (TxtCpbActive == comp->TxtCpbActive) insert(items, TXTCPBACTIVE);
	if (ButCpbViewAvail == comp->ButCpbViewAvail) insert(items, BUTCPBVIEWAVAIL);
	if (ButCpbViewActive == comp->ButCpbViewActive) insert(items, BUTCPBVIEWACTIVE);
	if (PupGrpActive == comp->PupGrpActive) insert(items, PUPGRPACTIVE);
	if (ButGrpEditAvail == comp->ButGrpEditAvail) insert(items, BUTGRPEDITAVAIL);

	return(items);
};

set<uint> PnlWznmTagDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFGRPVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTCPBACTIVE, BUTCPBVIEWAVAIL, BUTCPBVIEWACTIVE, PUPGRPACTIVE, BUTGRPEDITAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTagDetail::Tag
 ******************************************************************************/

void PnlWznmTagDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmTagDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmTagDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "text");
			writeStringAttr(wr, itemtag, "sref", "CptCpb", "capability");
			writeStringAttr(wr, itemtag, "sref", "CptGrp", "group");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTagDetail::DpchAppData
 ******************************************************************************/

PnlWznmTagDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTAGDETAILDATA)
		{
};

string PnlWznmTagDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTagDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTagDetailData");
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
 class PnlWznmTagDetail::DpchAppDo
 ******************************************************************************/

PnlWznmTagDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTAGDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmTagDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTagDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTagDetailDo");
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
 class PnlWznmTagDetail::DpchEngData
 ******************************************************************************/

PnlWznmTagDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupGrp
			, Feed* feedFPupJti
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTAGDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPGRP, FEEDFPUPJTI, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPGRP) && feedFPupGrp) this->feedFPupGrp = *feedFPupGrp;
	if (find(this->mask, FEEDFPUPJTI) && feedFPupJti) this->feedFPupJti = *feedFPupJti;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmTagDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPGRP)) ss.push_back("feedFPupGrp");
	if (has(FEEDFPUPJTI)) ss.push_back("feedFPupJti");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTagDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPGRP)) {feedFPupGrp = src->feedFPupGrp; add(FEEDFPUPGRP);};
	if (src->has(FEEDFPUPJTI)) {feedFPupJti = src->feedFPupJti; add(FEEDFPUPJTI);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmTagDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmTagDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPGRP)) feedFPupGrp.writeXML(wr);
		if (has(FEEDFPUPJTI)) feedFPupJti.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
