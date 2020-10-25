/**
	* \file PnlWznmMtyDetail_blks.cpp
	* job handler for job PnlWznmMtyDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmMtyDetail::VecVDo
 ******************************************************************************/

uint PnlWznmMtyDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butoseditclick") return BUTOSEDITCLICK;
	if (s == "butcchviewclick") return BUTCCHVIEWCLICK;
	if (s == "butpkmeditclick") return BUTPKMEDITCLICK;

	return(0);
};

string PnlWznmMtyDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTOSEDITCLICK) return("ButOsEditClick");
	if (ix == BUTCCHVIEWCLICK) return("ButCchViewClick");
	if (ix == BUTPKMEDITCLICK) return("ButPkmEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmMtyDetail::ContIac
 ******************************************************************************/

PnlWznmMtyDetail::ContIac::ContIac(
			const uint numFPupAch
			, const uint numFPupOs
			, const string& TxfOs
			, const uint numFPupPkm
			, const string& TxfPkm
			, const string& TxfCmt
		) :
			Block()
		{
	this->numFPupAch = numFPupAch;
	this->numFPupOs = numFPupOs;
	this->TxfOs = TxfOs;
	this->numFPupPkm = numFPupPkm;
	this->TxfPkm = TxfPkm;
	this->TxfCmt = TxfCmt;

	mask = {NUMFPUPACH, NUMFPUPOS, TXFOS, NUMFPUPPKM, TXFPKM, TXFCMT};
};

bool PnlWznmMtyDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmMtyDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmMtyDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAch", numFPupAch)) add(NUMFPUPACH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupOs", numFPupOs)) add(NUMFPUPOS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOs", TxfOs)) add(TXFOS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupPkm", numFPupPkm)) add(NUMFPUPPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPkm", TxfPkm)) add(TXFPKM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmMtyDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmMtyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmMtyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupAch", numFPupAch);
		writeUintAttr(wr, itemtag, "sref", "numFPupOs", numFPupOs);
		writeStringAttr(wr, itemtag, "sref", "TxfOs", TxfOs);
		writeUintAttr(wr, itemtag, "sref", "numFPupPkm", numFPupPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfPkm", TxfPkm);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMtyDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupAch == comp->numFPupAch) insert(items, NUMFPUPACH);
	if (numFPupOs == comp->numFPupOs) insert(items, NUMFPUPOS);
	if (TxfOs == comp->TxfOs) insert(items, TXFOS);
	if (numFPupPkm == comp->numFPupPkm) insert(items, NUMFPUPPKM);
	if (TxfPkm == comp->TxfPkm) insert(items, TXFPKM);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmMtyDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPACH, NUMFPUPOS, TXFOS, NUMFPUPPKM, TXFPKM, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMtyDetail::ContInf
 ******************************************************************************/

PnlWznmMtyDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtCch
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtCch = TxtCch;

	mask = {TXTSRF, TXTCCH};
};

void PnlWznmMtyDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmMtyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmMtyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtCch", TxtCch);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMtyDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtCch == comp->TxtCch) insert(items, TXTCCH);

	return(items);
};

set<uint> PnlWznmMtyDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTCCH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMtyDetail::StatApp
 ******************************************************************************/

void PnlWznmMtyDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool PupOsAlt
			, const bool PupPkmAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmMtyDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmMtyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupOsAlt", PupOsAlt);
		writeBoolAttr(wr, itemtag, "sref", "PupPkmAlt", PupPkmAlt);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMtyDetail::StatShr
 ******************************************************************************/

PnlWznmMtyDetail::StatShr::StatShr(
			const bool TxfOsValid
			, const bool TxfPkmValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupAchActive
			, const bool PupOsActive
			, const bool ButOsEditAvail
			, const bool TxtCchActive
			, const bool ButCchViewAvail
			, const bool ButCchViewActive
			, const bool PupPkmActive
			, const bool ButPkmEditAvail
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->TxfOsValid = TxfOsValid;
	this->TxfPkmValid = TxfPkmValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupAchActive = PupAchActive;
	this->PupOsActive = PupOsActive;
	this->ButOsEditAvail = ButOsEditAvail;
	this->TxtCchActive = TxtCchActive;
	this->ButCchViewAvail = ButCchViewAvail;
	this->ButCchViewActive = ButCchViewActive;
	this->PupPkmActive = PupPkmActive;
	this->ButPkmEditAvail = ButPkmEditAvail;
	this->TxfCmtActive = TxfCmtActive;

	mask = {TXFOSVALID, TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPACHACTIVE, PUPOSACTIVE, BUTOSEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE};
};

void PnlWznmMtyDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmMtyDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmMtyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfOsValid", TxfOsValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfPkmValid", TxfPkmValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupAchActive", PupAchActive);
		writeBoolAttr(wr, itemtag, "sref", "PupOsActive", PupOsActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOsEditAvail", ButOsEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtCchActive", TxtCchActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCchViewAvail", ButCchViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCchViewActive", ButCchViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupPkmActive", PupPkmActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPkmEditAvail", ButPkmEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmMtyDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfOsValid == comp->TxfOsValid) insert(items, TXFOSVALID);
	if (TxfPkmValid == comp->TxfPkmValid) insert(items, TXFPKMVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupAchActive == comp->PupAchActive) insert(items, PUPACHACTIVE);
	if (PupOsActive == comp->PupOsActive) insert(items, PUPOSACTIVE);
	if (ButOsEditAvail == comp->ButOsEditAvail) insert(items, BUTOSEDITAVAIL);
	if (TxtCchActive == comp->TxtCchActive) insert(items, TXTCCHACTIVE);
	if (ButCchViewAvail == comp->ButCchViewAvail) insert(items, BUTCCHVIEWAVAIL);
	if (ButCchViewActive == comp->ButCchViewActive) insert(items, BUTCCHVIEWACTIVE);
	if (PupPkmActive == comp->PupPkmActive) insert(items, PUPPKMACTIVE);
	if (ButPkmEditAvail == comp->ButPkmEditAvail) insert(items, BUTPKMEDITAVAIL);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmMtyDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFOSVALID, TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPACHACTIVE, PUPOSACTIVE, BUTOSEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmMtyDetail::Tag
 ******************************************************************************/

void PnlWznmMtyDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmMtyDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmMtyDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptAch", "architecture");
			writeStringAttr(wr, itemtag, "sref", "CptOs", "operating system");
			writeStringAttr(wr, itemtag, "sref", "CptCch", "cross-compile host");
			writeStringAttr(wr, itemtag, "sref", "CptPkm", "package manager");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmMtyDetail::DpchAppData
 ******************************************************************************/

PnlWznmMtyDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMTYDETAILDATA)
		{
};

string PnlWznmMtyDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMtyDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmMtyDetailData");
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
 class PnlWznmMtyDetail::DpchAppDo
 ******************************************************************************/

PnlWznmMtyDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMMTYDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmMtyDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMtyDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmMtyDetailDo");
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
 class PnlWznmMtyDetail::DpchEngData
 ******************************************************************************/

PnlWznmMtyDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupAch
			, Feed* feedFPupOs
			, Feed* feedFPupPkm
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMMTYDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPACH, FEEDFPUPOS, FEEDFPUPPKM, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPACH) && feedFPupAch) this->feedFPupAch = *feedFPupAch;
	if (find(this->mask, FEEDFPUPOS) && feedFPupOs) this->feedFPupOs = *feedFPupOs;
	if (find(this->mask, FEEDFPUPPKM) && feedFPupPkm) this->feedFPupPkm = *feedFPupPkm;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmMtyDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPACH)) ss.push_back("feedFPupAch");
	if (has(FEEDFPUPOS)) ss.push_back("feedFPupOs");
	if (has(FEEDFPUPPKM)) ss.push_back("feedFPupPkm");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmMtyDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPACH)) {feedFPupAch = src->feedFPupAch; add(FEEDFPUPACH);};
	if (src->has(FEEDFPUPOS)) {feedFPupOs = src->feedFPupOs; add(FEEDFPUPOS);};
	if (src->has(FEEDFPUPPKM)) {feedFPupPkm = src->feedFPupPkm; add(FEEDFPUPPKM);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmMtyDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmMtyDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPACH)) feedFPupAch.writeXML(wr);
		if (has(FEEDFPUPOS)) feedFPupOs.writeXML(wr);
		if (has(FEEDFPUPPKM)) feedFPupPkm.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

