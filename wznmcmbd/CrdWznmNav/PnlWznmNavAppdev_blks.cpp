/**
	* \file PnlWznmNavAppdev_blks.cpp
	* job handler for job PnlWznmNavAppdev (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavAppdev::VecVDo
 ******************************************************************************/

uint PnlWznmNavAppdev::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butappviewclick") return BUTAPPVIEWCLICK;
	if (s == "butappnewcrdclick") return BUTAPPNEWCRDCLICK;
	if (s == "butrtjviewclick") return BUTRTJVIEWCLICK;
	if (s == "butrtjnewcrdclick") return BUTRTJNEWCRDCLICK;
	if (s == "butevtviewclick") return BUTEVTVIEWCLICK;
	if (s == "butevtnewcrdclick") return BUTEVTNEWCRDCLICK;
	if (s == "butseqviewclick") return BUTSEQVIEWCLICK;
	if (s == "butseqnewcrdclick") return BUTSEQNEWCRDCLICK;
	if (s == "butsteviewclick") return BUTSTEVIEWCLICK;
	if (s == "butstenewcrdclick") return BUTSTENEWCRDCLICK;

	return(0);
};

string PnlWznmNavAppdev::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTAPPVIEWCLICK) return("ButAppViewClick");
	if (ix == BUTAPPNEWCRDCLICK) return("ButAppNewcrdClick");
	if (ix == BUTRTJVIEWCLICK) return("ButRtjViewClick");
	if (ix == BUTRTJNEWCRDCLICK) return("ButRtjNewcrdClick");
	if (ix == BUTEVTVIEWCLICK) return("ButEvtViewClick");
	if (ix == BUTEVTNEWCRDCLICK) return("ButEvtNewcrdClick");
	if (ix == BUTSEQVIEWCLICK) return("ButSeqViewClick");
	if (ix == BUTSEQNEWCRDCLICK) return("ButSeqNewcrdClick");
	if (ix == BUTSTEVIEWCLICK) return("ButSteViewClick");
	if (ix == BUTSTENEWCRDCLICK) return("ButSteNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavAppdev::ContIac
 ******************************************************************************/

PnlWznmNavAppdev::ContIac::ContIac(
			const uint numFLstApp
			, const uint numFLstRtj
			, const uint numFLstEvt
			, const uint numFLstSeq
			, const uint numFLstSte
		) :
			Block()
		{
	this->numFLstApp = numFLstApp;
	this->numFLstRtj = numFLstRtj;
	this->numFLstEvt = numFLstEvt;
	this->numFLstSeq = numFLstSeq;
	this->numFLstSte = numFLstSte;

	mask = {NUMFLSTAPP, NUMFLSTRTJ, NUMFLSTEVT, NUMFLSTSEQ, NUMFLSTSTE};
};

bool PnlWznmNavAppdev::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavAppdev");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavAppdev";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstApp", numFLstApp)) add(NUMFLSTAPP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstRtj", numFLstRtj)) add(NUMFLSTRTJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstEvt", numFLstEvt)) add(NUMFLSTEVT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSeq", numFLstSeq)) add(NUMFLSTSEQ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSte", numFLstSte)) add(NUMFLSTSTE);
	};

	return basefound;
};

void PnlWznmNavAppdev::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavAppdev";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavAppdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstApp", numFLstApp);
		writeUintAttr(wr, itemtag, "sref", "numFLstRtj", numFLstRtj);
		writeUintAttr(wr, itemtag, "sref", "numFLstEvt", numFLstEvt);
		writeUintAttr(wr, itemtag, "sref", "numFLstSeq", numFLstSeq);
		writeUintAttr(wr, itemtag, "sref", "numFLstSte", numFLstSte);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavAppdev::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstApp == comp->numFLstApp) insert(items, NUMFLSTAPP);
	if (numFLstRtj == comp->numFLstRtj) insert(items, NUMFLSTRTJ);
	if (numFLstEvt == comp->numFLstEvt) insert(items, NUMFLSTEVT);
	if (numFLstSeq == comp->numFLstSeq) insert(items, NUMFLSTSEQ);
	if (numFLstSte == comp->numFLstSte) insert(items, NUMFLSTSTE);

	return(items);
};

set<uint> PnlWznmNavAppdev::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTAPP, NUMFLSTRTJ, NUMFLSTEVT, NUMFLSTSEQ, NUMFLSTSTE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAppdev::StatApp
 ******************************************************************************/

void PnlWznmNavAppdev::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstAppAlt
			, const bool LstRtjAlt
			, const bool LstEvtAlt
			, const bool LstSeqAlt
			, const bool LstSteAlt
			, const uint LstAppNumFirstdisp
			, const uint LstRtjNumFirstdisp
			, const uint LstEvtNumFirstdisp
			, const uint LstSeqNumFirstdisp
			, const uint LstSteNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavAppdev";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavAppdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstAppAlt", LstAppAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstRtjAlt", LstRtjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstEvtAlt", LstEvtAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSeqAlt", LstSeqAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSteAlt", LstSteAlt);
		writeUintAttr(wr, itemtag, "sref", "LstAppNumFirstdisp", LstAppNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstRtjNumFirstdisp", LstRtjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstEvtNumFirstdisp", LstEvtNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSeqNumFirstdisp", LstSeqNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSteNumFirstdisp", LstSteNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAppdev::StatShr
 ******************************************************************************/

PnlWznmNavAppdev::StatShr::StatShr(
			const bool LstAppAvail
			, const bool ButAppViewActive
			, const bool LstRtjAvail
			, const bool ButRtjViewActive
			, const bool ButRtjNewcrdActive
			, const bool LstEvtAvail
			, const bool ButEvtViewActive
			, const bool ButEvtNewcrdActive
			, const bool LstSeqAvail
			, const bool ButSeqViewActive
			, const bool ButSeqNewcrdActive
			, const bool LstSteAvail
			, const bool ButSteViewActive
			, const bool ButSteNewcrdActive
		) :
			Block()
		{
	this->LstAppAvail = LstAppAvail;
	this->ButAppViewActive = ButAppViewActive;
	this->LstRtjAvail = LstRtjAvail;
	this->ButRtjViewActive = ButRtjViewActive;
	this->ButRtjNewcrdActive = ButRtjNewcrdActive;
	this->LstEvtAvail = LstEvtAvail;
	this->ButEvtViewActive = ButEvtViewActive;
	this->ButEvtNewcrdActive = ButEvtNewcrdActive;
	this->LstSeqAvail = LstSeqAvail;
	this->ButSeqViewActive = ButSeqViewActive;
	this->ButSeqNewcrdActive = ButSeqNewcrdActive;
	this->LstSteAvail = LstSteAvail;
	this->ButSteViewActive = ButSteViewActive;
	this->ButSteNewcrdActive = ButSteNewcrdActive;

	mask = {LSTAPPAVAIL, BUTAPPVIEWACTIVE, LSTRTJAVAIL, BUTRTJVIEWACTIVE, BUTRTJNEWCRDACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTSEQAVAIL, BUTSEQVIEWACTIVE, BUTSEQNEWCRDACTIVE, LSTSTEAVAIL, BUTSTEVIEWACTIVE, BUTSTENEWCRDACTIVE};
};

void PnlWznmNavAppdev::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavAppdev";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavAppdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstAppAvail", LstAppAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButAppViewActive", ButAppViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstRtjAvail", LstRtjAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRtjViewActive", ButRtjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRtjNewcrdActive", ButRtjNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstEvtAvail", LstEvtAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEvtViewActive", ButEvtViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEvtNewcrdActive", ButEvtNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSeqAvail", LstSeqAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSeqViewActive", ButSeqViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSeqNewcrdActive", ButSeqNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSteAvail", LstSteAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSteViewActive", ButSteViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSteNewcrdActive", ButSteNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavAppdev::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstAppAvail == comp->LstAppAvail) insert(items, LSTAPPAVAIL);
	if (ButAppViewActive == comp->ButAppViewActive) insert(items, BUTAPPVIEWACTIVE);
	if (LstRtjAvail == comp->LstRtjAvail) insert(items, LSTRTJAVAIL);
	if (ButRtjViewActive == comp->ButRtjViewActive) insert(items, BUTRTJVIEWACTIVE);
	if (ButRtjNewcrdActive == comp->ButRtjNewcrdActive) insert(items, BUTRTJNEWCRDACTIVE);
	if (LstEvtAvail == comp->LstEvtAvail) insert(items, LSTEVTAVAIL);
	if (ButEvtViewActive == comp->ButEvtViewActive) insert(items, BUTEVTVIEWACTIVE);
	if (ButEvtNewcrdActive == comp->ButEvtNewcrdActive) insert(items, BUTEVTNEWCRDACTIVE);
	if (LstSeqAvail == comp->LstSeqAvail) insert(items, LSTSEQAVAIL);
	if (ButSeqViewActive == comp->ButSeqViewActive) insert(items, BUTSEQVIEWACTIVE);
	if (ButSeqNewcrdActive == comp->ButSeqNewcrdActive) insert(items, BUTSEQNEWCRDACTIVE);
	if (LstSteAvail == comp->LstSteAvail) insert(items, LSTSTEAVAIL);
	if (ButSteViewActive == comp->ButSteViewActive) insert(items, BUTSTEVIEWACTIVE);
	if (ButSteNewcrdActive == comp->ButSteNewcrdActive) insert(items, BUTSTENEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavAppdev::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTAPPAVAIL, BUTAPPVIEWACTIVE, LSTRTJAVAIL, BUTRTJVIEWACTIVE, BUTRTJNEWCRDACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTSEQAVAIL, BUTSEQVIEWACTIVE, BUTSEQNEWCRDACTIVE, LSTSTEAVAIL, BUTSTEVIEWACTIVE, BUTSTENEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAppdev::Tag
 ******************************************************************************/

void PnlWznmNavAppdev::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavAppdev";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavAppdev";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "App development module");
			writeStringAttr(wr, itemtag, "sref", "CptApp", "accessor apps");
			writeStringAttr(wr, itemtag, "sref", "CptRtj", "run-time jobs");
			writeStringAttr(wr, itemtag, "sref", "CptEvt", "events");
			writeStringAttr(wr, itemtag, "sref", "CptSeq", "sequences");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "states");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAppdev::DpchAppData
 ******************************************************************************/

PnlWznmNavAppdev::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVAPPDEVDATA)
		{
};

string PnlWznmNavAppdev::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAppdev::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavAppdevData");
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
 class PnlWznmNavAppdev::DpchAppDo
 ******************************************************************************/

PnlWznmNavAppdev::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVAPPDEVDO)
		{
	ixVDo = 0;
};

string PnlWznmNavAppdev::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAppdev::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavAppdevDo");
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
 class PnlWznmNavAppdev::DpchEngData
 ******************************************************************************/

PnlWznmNavAppdev::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstApp
			, Feed* feedFLstEvt
			, Feed* feedFLstRtj
			, Feed* feedFLstSeq
			, Feed* feedFLstSte
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVAPPDEVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTAPP, FEEDFLSTEVT, FEEDFLSTRTJ, FEEDFLSTSEQ, FEEDFLSTSTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTAPP) && feedFLstApp) this->feedFLstApp = *feedFLstApp;
	if (find(this->mask, FEEDFLSTEVT) && feedFLstEvt) this->feedFLstEvt = *feedFLstEvt;
	if (find(this->mask, FEEDFLSTRTJ) && feedFLstRtj) this->feedFLstRtj = *feedFLstRtj;
	if (find(this->mask, FEEDFLSTSEQ) && feedFLstSeq) this->feedFLstSeq = *feedFLstSeq;
	if (find(this->mask, FEEDFLSTSTE) && feedFLstSte) this->feedFLstSte = *feedFLstSte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavAppdev::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTAPP)) ss.push_back("feedFLstApp");
	if (has(FEEDFLSTEVT)) ss.push_back("feedFLstEvt");
	if (has(FEEDFLSTRTJ)) ss.push_back("feedFLstRtj");
	if (has(FEEDFLSTSEQ)) ss.push_back("feedFLstSeq");
	if (has(FEEDFLSTSTE)) ss.push_back("feedFLstSte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAppdev::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTAPP)) {feedFLstApp = src->feedFLstApp; add(FEEDFLSTAPP);};
	if (src->has(FEEDFLSTEVT)) {feedFLstEvt = src->feedFLstEvt; add(FEEDFLSTEVT);};
	if (src->has(FEEDFLSTRTJ)) {feedFLstRtj = src->feedFLstRtj; add(FEEDFLSTRTJ);};
	if (src->has(FEEDFLSTSEQ)) {feedFLstSeq = src->feedFLstSeq; add(FEEDFLSTSEQ);};
	if (src->has(FEEDFLSTSTE)) {feedFLstSte = src->feedFLstSte; add(FEEDFLSTSTE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavAppdev::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavAppdevData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTAPP)) feedFLstApp.writeXML(wr);
		if (has(FEEDFLSTEVT)) feedFLstEvt.writeXML(wr);
		if (has(FEEDFLSTRTJ)) feedFLstRtj.writeXML(wr);
		if (has(FEEDFLSTSEQ)) feedFLstSeq.writeXML(wr);
		if (has(FEEDFLSTSTE)) feedFLstSte.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

