/**
	* \file PnlWznmNavGlobal_blks.cpp
	* job handler for job PnlWznmNavGlobal (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavGlobal::VecVDo
 ******************************************************************************/

uint PnlWznmNavGlobal::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butlocviewclick") return BUTLOCVIEWCLICK;
	if (s == "butlocnewcrdclick") return BUTLOCNEWCRDCLICK;
	if (s == "buttagviewclick") return BUTTAGVIEWCLICK;
	if (s == "buttagnewcrdclick") return BUTTAGNEWCRDCLICK;
	if (s == "butctpviewclick") return BUTCTPVIEWCLICK;
	if (s == "butctpnewcrdclick") return BUTCTPNEWCRDCLICK;
	if (s == "butmtyviewclick") return BUTMTYVIEWCLICK;
	if (s == "butmtynewcrdclick") return BUTMTYNEWCRDCLICK;
	if (s == "butmchviewclick") return BUTMCHVIEWCLICK;
	if (s == "butmchnewcrdclick") return BUTMCHNEWCRDCLICK;
	if (s == "butlibviewclick") return BUTLIBVIEWCLICK;
	if (s == "butlibnewcrdclick") return BUTLIBNEWCRDCLICK;

	return(0);
};

string PnlWznmNavGlobal::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTLOCVIEWCLICK) return("ButLocViewClick");
	if (ix == BUTLOCNEWCRDCLICK) return("ButLocNewcrdClick");
	if (ix == BUTTAGVIEWCLICK) return("ButTagViewClick");
	if (ix == BUTTAGNEWCRDCLICK) return("ButTagNewcrdClick");
	if (ix == BUTCTPVIEWCLICK) return("ButCtpViewClick");
	if (ix == BUTCTPNEWCRDCLICK) return("ButCtpNewcrdClick");
	if (ix == BUTMTYVIEWCLICK) return("ButMtyViewClick");
	if (ix == BUTMTYNEWCRDCLICK) return("ButMtyNewcrdClick");
	if (ix == BUTMCHVIEWCLICK) return("ButMchViewClick");
	if (ix == BUTMCHNEWCRDCLICK) return("ButMchNewcrdClick");
	if (ix == BUTLIBVIEWCLICK) return("ButLibViewClick");
	if (ix == BUTLIBNEWCRDCLICK) return("ButLibNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavGlobal::ContIac
 ******************************************************************************/

PnlWznmNavGlobal::ContIac::ContIac(
			const uint numFLstLoc
			, const uint numFLstTag
			, const uint numFLstCtp
			, const uint numFLstMty
			, const uint numFLstMch
			, const uint numFLstLib
		) :
			Block()
		{
	this->numFLstLoc = numFLstLoc;
	this->numFLstTag = numFLstTag;
	this->numFLstCtp = numFLstCtp;
	this->numFLstMty = numFLstMty;
	this->numFLstMch = numFLstMch;
	this->numFLstLib = numFLstLib;

	mask = {NUMFLSTLOC, NUMFLSTTAG, NUMFLSTCTP, NUMFLSTMTY, NUMFLSTMCH, NUMFLSTLIB};
};

bool PnlWznmNavGlobal::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavGlobal";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLoc", numFLstLoc)) add(NUMFLSTLOC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTag", numFLstTag)) add(NUMFLSTTAG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCtp", numFLstCtp)) add(NUMFLSTCTP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMty", numFLstMty)) add(NUMFLSTMTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMch", numFLstMch)) add(NUMFLSTMCH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstLib", numFLstLib)) add(NUMFLSTLIB);
	};

	return basefound;
};

void PnlWznmNavGlobal::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstLoc", numFLstLoc);
		writeUintAttr(wr, itemtag, "sref", "numFLstTag", numFLstTag);
		writeUintAttr(wr, itemtag, "sref", "numFLstCtp", numFLstCtp);
		writeUintAttr(wr, itemtag, "sref", "numFLstMty", numFLstMty);
		writeUintAttr(wr, itemtag, "sref", "numFLstMch", numFLstMch);
		writeUintAttr(wr, itemtag, "sref", "numFLstLib", numFLstLib);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavGlobal::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstLoc == comp->numFLstLoc) insert(items, NUMFLSTLOC);
	if (numFLstTag == comp->numFLstTag) insert(items, NUMFLSTTAG);
	if (numFLstCtp == comp->numFLstCtp) insert(items, NUMFLSTCTP);
	if (numFLstMty == comp->numFLstMty) insert(items, NUMFLSTMTY);
	if (numFLstMch == comp->numFLstMch) insert(items, NUMFLSTMCH);
	if (numFLstLib == comp->numFLstLib) insert(items, NUMFLSTLIB);

	return(items);
};

set<uint> PnlWznmNavGlobal::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTLOC, NUMFLSTTAG, NUMFLSTCTP, NUMFLSTMTY, NUMFLSTMCH, NUMFLSTLIB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavGlobal::StatApp
 ******************************************************************************/

void PnlWznmNavGlobal::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstLocAlt
			, const bool LstTagAlt
			, const bool LstCtpAlt
			, const bool LstMtyAlt
			, const bool LstMchAlt
			, const bool LstLibAlt
			, const uint LstLocNumFirstdisp
			, const uint LstTagNumFirstdisp
			, const uint LstCtpNumFirstdisp
			, const uint LstMtyNumFirstdisp
			, const uint LstMchNumFirstdisp
			, const uint LstLibNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstLocAlt", LstLocAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstTagAlt", LstTagAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCtpAlt", LstCtpAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstMtyAlt", LstMtyAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstMchAlt", LstMchAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstLibAlt", LstLibAlt);
		writeUintAttr(wr, itemtag, "sref", "LstLocNumFirstdisp", LstLocNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTagNumFirstdisp", LstTagNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCtpNumFirstdisp", LstCtpNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstMtyNumFirstdisp", LstMtyNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstMchNumFirstdisp", LstMchNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstLibNumFirstdisp", LstLibNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavGlobal::StatShr
 ******************************************************************************/

PnlWznmNavGlobal::StatShr::StatShr(
			const bool LstLocAvail
			, const bool ButLocViewActive
			, const bool LstTagAvail
			, const bool ButTagViewActive
			, const bool LstCtpAvail
			, const bool ButCtpViewActive
			, const bool LstMtyAvail
			, const bool ButMtyViewActive
			, const bool LstMchAvail
			, const bool ButMchViewActive
			, const bool LstLibAvail
			, const bool ButLibViewActive
		) :
			Block()
		{
	this->LstLocAvail = LstLocAvail;
	this->ButLocViewActive = ButLocViewActive;
	this->LstTagAvail = LstTagAvail;
	this->ButTagViewActive = ButTagViewActive;
	this->LstCtpAvail = LstCtpAvail;
	this->ButCtpViewActive = ButCtpViewActive;
	this->LstMtyAvail = LstMtyAvail;
	this->ButMtyViewActive = ButMtyViewActive;
	this->LstMchAvail = LstMchAvail;
	this->ButMchViewActive = ButMchViewActive;
	this->LstLibAvail = LstLibAvail;
	this->ButLibViewActive = ButLibViewActive;

	mask = {LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTTAGAVAIL, BUTTAGVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMTYAVAIL, BUTMTYVIEWACTIVE, LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE};
};

void PnlWznmNavGlobal::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstLocAvail", LstLocAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLocViewActive", ButLocViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstTagAvail", LstTagAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTagViewActive", ButTagViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCtpAvail", LstCtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCtpViewActive", ButCtpViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstMtyAvail", LstMtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMtyViewActive", ButMtyViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstMchAvail", LstMchAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMchViewActive", ButMchViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstLibAvail", LstLibAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLibViewActive", ButLibViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavGlobal::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstLocAvail == comp->LstLocAvail) insert(items, LSTLOCAVAIL);
	if (ButLocViewActive == comp->ButLocViewActive) insert(items, BUTLOCVIEWACTIVE);
	if (LstTagAvail == comp->LstTagAvail) insert(items, LSTTAGAVAIL);
	if (ButTagViewActive == comp->ButTagViewActive) insert(items, BUTTAGVIEWACTIVE);
	if (LstCtpAvail == comp->LstCtpAvail) insert(items, LSTCTPAVAIL);
	if (ButCtpViewActive == comp->ButCtpViewActive) insert(items, BUTCTPVIEWACTIVE);
	if (LstMtyAvail == comp->LstMtyAvail) insert(items, LSTMTYAVAIL);
	if (ButMtyViewActive == comp->ButMtyViewActive) insert(items, BUTMTYVIEWACTIVE);
	if (LstMchAvail == comp->LstMchAvail) insert(items, LSTMCHAVAIL);
	if (ButMchViewActive == comp->ButMchViewActive) insert(items, BUTMCHVIEWACTIVE);
	if (LstLibAvail == comp->LstLibAvail) insert(items, LSTLIBAVAIL);
	if (ButLibViewActive == comp->ButLibViewActive) insert(items, BUTLIBVIEWACTIVE);

	return(items);
};

set<uint> PnlWznmNavGlobal::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTTAGAVAIL, BUTTAGVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMTYAVAIL, BUTMTYVIEWACTIVE, LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavGlobal::Tag
 ******************************************************************************/

void PnlWznmNavGlobal::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavGlobal";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavGlobal";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Global data module");
			writeStringAttr(wr, itemtag, "sref", "CptLoc", "locales");
			writeStringAttr(wr, itemtag, "sref", "CptTag", "tags");
			writeStringAttr(wr, itemtag, "sref", "CptCtp", "capability templates");
			writeStringAttr(wr, itemtag, "sref", "CptMty", "machine types");
			writeStringAttr(wr, itemtag, "sref", "CptMch", "machines");
			writeStringAttr(wr, itemtag, "sref", "CptLib", "libraries");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavGlobal::DpchAppData
 ******************************************************************************/

PnlWznmNavGlobal::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVGLOBALDATA)
		{
};

string PnlWznmNavGlobal::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavGlobal::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavGlobalData");
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
 class PnlWznmNavGlobal::DpchAppDo
 ******************************************************************************/

PnlWznmNavGlobal::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVGLOBALDO)
		{
	ixVDo = 0;
};

string PnlWznmNavGlobal::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavGlobal::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavGlobalDo");
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
 class PnlWznmNavGlobal::DpchEngData
 ******************************************************************************/

PnlWznmNavGlobal::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCtp
			, Feed* feedFLstLib
			, Feed* feedFLstLoc
			, Feed* feedFLstMch
			, Feed* feedFLstMty
			, Feed* feedFLstTag
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVGLOBALDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCTP, FEEDFLSTLIB, FEEDFLSTLOC, FEEDFLSTMCH, FEEDFLSTMTY, FEEDFLSTTAG, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCTP) && feedFLstCtp) this->feedFLstCtp = *feedFLstCtp;
	if (find(this->mask, FEEDFLSTLIB) && feedFLstLib) this->feedFLstLib = *feedFLstLib;
	if (find(this->mask, FEEDFLSTLOC) && feedFLstLoc) this->feedFLstLoc = *feedFLstLoc;
	if (find(this->mask, FEEDFLSTMCH) && feedFLstMch) this->feedFLstMch = *feedFLstMch;
	if (find(this->mask, FEEDFLSTMTY) && feedFLstMty) this->feedFLstMty = *feedFLstMty;
	if (find(this->mask, FEEDFLSTTAG) && feedFLstTag) this->feedFLstTag = *feedFLstTag;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavGlobal::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCTP)) ss.push_back("feedFLstCtp");
	if (has(FEEDFLSTLIB)) ss.push_back("feedFLstLib");
	if (has(FEEDFLSTLOC)) ss.push_back("feedFLstLoc");
	if (has(FEEDFLSTMCH)) ss.push_back("feedFLstMch");
	if (has(FEEDFLSTMTY)) ss.push_back("feedFLstMty");
	if (has(FEEDFLSTTAG)) ss.push_back("feedFLstTag");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavGlobal::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCTP)) {feedFLstCtp = src->feedFLstCtp; add(FEEDFLSTCTP);};
	if (src->has(FEEDFLSTLIB)) {feedFLstLib = src->feedFLstLib; add(FEEDFLSTLIB);};
	if (src->has(FEEDFLSTLOC)) {feedFLstLoc = src->feedFLstLoc; add(FEEDFLSTLOC);};
	if (src->has(FEEDFLSTMCH)) {feedFLstMch = src->feedFLstMch; add(FEEDFLSTMCH);};
	if (src->has(FEEDFLSTMTY)) {feedFLstMty = src->feedFLstMty; add(FEEDFLSTMTY);};
	if (src->has(FEEDFLSTTAG)) {feedFLstTag = src->feedFLstTag; add(FEEDFLSTTAG);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavGlobal::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCTP)) feedFLstCtp.writeXML(wr);
		if (has(FEEDFLSTLIB)) feedFLstLib.writeXML(wr);
		if (has(FEEDFLSTLOC)) feedFLstLoc.writeXML(wr);
		if (has(FEEDFLSTMCH)) feedFLstMch.writeXML(wr);
		if (has(FEEDFLSTMTY)) feedFLstMty.writeXML(wr);
		if (has(FEEDFLSTTAG)) feedFLstTag.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

