/**
	* \file PnlWznmNavGlobal.cpp
	* API code for job PnlWznmNavGlobal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmNavGlobal.h"

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
			, const uint numFLstMch
			, const uint numFLstLib
		) :
			Block()
			, numFLstLoc(numFLstLoc)
			, numFLstTag(numFLstTag)
			, numFLstCtp(numFLstCtp)
			, numFLstMch(numFLstMch)
			, numFLstLib(numFLstLib)
		{
	mask = {NUMFLSTLOC, NUMFLSTTAG, NUMFLSTCTP, NUMFLSTMCH, NUMFLSTLIB};
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

	diffitems = {NUMFLSTLOC, NUMFLSTTAG, NUMFLSTCTP, NUMFLSTMCH, NUMFLSTLIB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavGlobal::StatApp
 ******************************************************************************/

PnlWznmNavGlobal::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstLocAlt
			, const bool LstTagAlt
			, const bool LstCtpAlt
			, const bool LstMchAlt
			, const bool LstLibAlt
			, const uint LstLocNumFirstdisp
			, const uint LstTagNumFirstdisp
			, const uint LstCtpNumFirstdisp
			, const uint LstMchNumFirstdisp
			, const uint LstLibNumFirstdisp
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
			, LstLocAlt(LstLocAlt)
			, LstTagAlt(LstTagAlt)
			, LstCtpAlt(LstCtpAlt)
			, LstMchAlt(LstMchAlt)
			, LstLibAlt(LstLibAlt)
			, LstLocNumFirstdisp(LstLocNumFirstdisp)
			, LstTagNumFirstdisp(LstTagNumFirstdisp)
			, LstCtpNumFirstdisp(LstCtpNumFirstdisp)
			, LstMchNumFirstdisp(LstMchNumFirstdisp)
			, LstLibNumFirstdisp(LstLibNumFirstdisp)
		{
	mask = {IXWZNMVEXPSTATE, LSTLOCALT, LSTTAGALT, LSTCTPALT, LSTMCHALT, LSTLIBALT, LSTLOCNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTCTPNUMFIRSTDISP, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP};
};

bool PnlWznmNavGlobal::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLocAlt", LstLocAlt)) add(LSTLOCALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTagAlt", LstTagAlt)) add(LSTTAGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCtpAlt", LstCtpAlt)) add(LSTCTPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMchAlt", LstMchAlt)) add(LSTMCHALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLibAlt", LstLibAlt)) add(LSTLIBALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLocNumFirstdisp", LstLocNumFirstdisp)) add(LSTLOCNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTagNumFirstdisp", LstTagNumFirstdisp)) add(LSTTAGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCtpNumFirstdisp", LstCtpNumFirstdisp)) add(LSTCTPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMchNumFirstdisp", LstMchNumFirstdisp)) add(LSTMCHNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLibNumFirstdisp", LstLibNumFirstdisp)) add(LSTLIBNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavGlobal::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstLocAlt == comp->LstLocAlt) insert(items, LSTLOCALT);
	if (LstTagAlt == comp->LstTagAlt) insert(items, LSTTAGALT);
	if (LstCtpAlt == comp->LstCtpAlt) insert(items, LSTCTPALT);
	if (LstMchAlt == comp->LstMchAlt) insert(items, LSTMCHALT);
	if (LstLibAlt == comp->LstLibAlt) insert(items, LSTLIBALT);
	if (LstLocNumFirstdisp == comp->LstLocNumFirstdisp) insert(items, LSTLOCNUMFIRSTDISP);
	if (LstTagNumFirstdisp == comp->LstTagNumFirstdisp) insert(items, LSTTAGNUMFIRSTDISP);
	if (LstCtpNumFirstdisp == comp->LstCtpNumFirstdisp) insert(items, LSTCTPNUMFIRSTDISP);
	if (LstMchNumFirstdisp == comp->LstMchNumFirstdisp) insert(items, LSTMCHNUMFIRSTDISP);
	if (LstLibNumFirstdisp == comp->LstLibNumFirstdisp) insert(items, LSTLIBNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavGlobal::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTLOCALT, LSTTAGALT, LSTCTPALT, LSTMCHALT, LSTLIBALT, LSTLOCNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTCTPNUMFIRSTDISP, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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
			, const bool LstMchAvail
			, const bool ButMchViewActive
			, const bool LstLibAvail
			, const bool ButLibViewActive
		) :
			Block()
			, LstLocAvail(LstLocAvail)
			, ButLocViewActive(ButLocViewActive)
			, LstTagAvail(LstTagAvail)
			, ButTagViewActive(ButTagViewActive)
			, LstCtpAvail(LstCtpAvail)
			, ButCtpViewActive(ButCtpViewActive)
			, LstMchAvail(LstMchAvail)
			, ButMchViewActive(ButMchViewActive)
			, LstLibAvail(LstLibAvail)
			, ButLibViewActive(ButLibViewActive)
		{
	mask = {LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTTAGAVAIL, BUTTAGVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE};
};

bool PnlWznmNavGlobal::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavGlobal";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLocAvail", LstLocAvail)) add(LSTLOCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLocViewActive", ButLocViewActive)) add(BUTLOCVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTagAvail", LstTagAvail)) add(LSTTAGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTagViewActive", ButTagViewActive)) add(BUTTAGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCtpAvail", LstCtpAvail)) add(LSTCTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCtpViewActive", ButCtpViewActive)) add(BUTCTPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMchAvail", LstMchAvail)) add(LSTMCHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMchViewActive", ButMchViewActive)) add(BUTMCHVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstLibAvail", LstLibAvail)) add(LSTLIBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLibViewActive", ButLibViewActive)) add(BUTLIBVIEWACTIVE);
	};

	return basefound;
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

	diffitems = {LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTTAGAVAIL, BUTTAGVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavGlobal::Tag
 ******************************************************************************/

PnlWznmNavGlobal::Tag::Tag(
			const string& Cpt
			, const string& CptLoc
			, const string& CptTag
			, const string& CptCtp
			, const string& CptMch
			, const string& CptLib
		) :
			Block()
			, Cpt(Cpt)
			, CptLoc(CptLoc)
			, CptTag(CptTag)
			, CptCtp(CptCtp)
			, CptMch(CptMch)
			, CptLib(CptLib)
		{
	mask = {CPT, CPTLOC, CPTTAG, CPTCTP, CPTMCH, CPTLIB};
};

bool PnlWznmNavGlobal::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavGlobal");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavGlobal";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLoc", CptLoc)) add(CPTLOC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTag", CptTag)) add(CPTTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCtp", CptCtp)) add(CPTCTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMch", CptMch)) add(CPTMCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLib", CptLib)) add(CPTLIB);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavGlobal::DpchAppData
 ******************************************************************************/

PnlWznmNavGlobal::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVGLOBALDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavGlobal::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavGlobal::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavGlobalData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavGlobal::DpchAppDo
 ******************************************************************************/

PnlWznmNavGlobal::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVGLOBALDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWznmNavGlobal::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavGlobal::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavGlobalDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavGlobal::DpchEngData
 ******************************************************************************/

PnlWznmNavGlobal::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVGLOBALDATA)
		{
	feedFLstCtp.tag = "FeedFLstCtp";
	feedFLstLib.tag = "FeedFLstLib";
	feedFLstLoc.tag = "FeedFLstLoc";
	feedFLstMch.tag = "FeedFLstMch";
	feedFLstTag.tag = "FeedFLstTag";
};

string PnlWznmNavGlobal::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCTP)) ss.push_back("feedFLstCtp");
	if (has(FEEDFLSTLIB)) ss.push_back("feedFLstLib");
	if (has(FEEDFLSTLOC)) ss.push_back("feedFLstLoc");
	if (has(FEEDFLSTMCH)) ss.push_back("feedFLstMch");
	if (has(FEEDFLSTTAG)) ss.push_back("feedFLstTag");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavGlobal::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavGlobalData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCtp.readXML(docctx, basexpath, true)) add(FEEDFLSTCTP);
		if (feedFLstLib.readXML(docctx, basexpath, true)) add(FEEDFLSTLIB);
		if (feedFLstLoc.readXML(docctx, basexpath, true)) add(FEEDFLSTLOC);
		if (feedFLstMch.readXML(docctx, basexpath, true)) add(FEEDFLSTMCH);
		if (feedFLstTag.readXML(docctx, basexpath, true)) add(FEEDFLSTTAG);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCtp.clear();
		feedFLstLib.clear();
		feedFLstLoc.clear();
		feedFLstMch.clear();
		feedFLstTag.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
