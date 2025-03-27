/**
	* \file CrdWznmVis.cpp
	* API code for job CrdWznmVis (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "CrdWznmVis.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmVis::VecVDo
 ******************************************************************************/

uint CrdWznmVis::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdistclick") return MITCRDISTCLICK;
	if (s == "mitcrdcmfclick") return MITCRDCMFCLICK;
	if (s == "mitcrdwrcclick") return MITCRDWRCCLICK;
	if (s == "mitcrdestclick") return MITCRDESTCLICK;

	return(0);
};

string CrdWznmVis::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDISTCLICK) return("MitCrdIstClick");
	if (ix == MITCRDCMFCLICK) return("MitCrdCmfClick");
	if (ix == MITCRDWRCCLICK) return("MitCrdWrcClick");
	if (ix == MITCRDESTCLICK) return("MitCrdEstClick");

	return("");
};

/******************************************************************************
 class CrdWznmVis::VecVSge
 ******************************************************************************/

uint CrdWznmVis::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;

	return(0);
};

string CrdWznmVis::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");

	return("");
};

/******************************************************************************
 class CrdWznmVis::ContInf
 ******************************************************************************/

CrdWznmVis::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdVis
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxCrdVis(MtxCrdVis)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXCRDVIS};
};

bool CrdWznmVis::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmVis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmVis";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdVis", MtxCrdVis)) add(MTXCRDVIS);
	};

	return basefound;
};

set<uint> CrdWznmVis::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdVis == comp->MtxCrdVis) insert(items, MTXCRDVIS);

	return(items);
};

set<uint> CrdWznmVis::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDVIS};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVis::StatApp
 ******************************************************************************/

CrdWznmVis::StatApp::StatApp(
			const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
			, ixWznmVReqitmode(ixWznmVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneHeadbar(initdoneHeadbar)
			, initdoneList(initdoneList)
			, initdoneRec(initdoneRec)
		{
	mask = {IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWznmVis::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmVis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmVis";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVReqitmode", srefIxWznmVReqitmode)) {
			ixWznmVReqitmode = VecWznmVReqitmode::getIx(srefIxWznmVReqitmode);
			add(IXWZNMVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneList", initdoneList)) add(INITDONELIST);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRec", initdoneRec)) add(INITDONEREC);
	};

	return basefound;
};

set<uint> CrdWznmVis::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVReqitmode == comp->ixWznmVReqitmode) insert(items, IXWZNMVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdoneList == comp->initdoneList) insert(items, INITDONELIST);
	if (initdoneRec == comp->initdoneRec) insert(items, INITDONEREC);

	return(items);
};

set<uint> CrdWznmVis::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVis::StatShr
 ******************************************************************************/

CrdWznmVis::StatShr::StatShr(
			const string& scrJrefDlgexpstr
			, const string& scrJrefDlgimpstr
			, const string& scrJrefDlgmissfeat
			, const string& scrJrefDlgnew
			, const string& scrJrefDlgwrite
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdIstAvail
			, const bool MitCrdIstActive
			, const bool MitCrdCmfAvail
			, const bool MitCrdCmfActive
			, const bool MitCrdWrcAvail
			, const bool MitCrdWrcActive
			, const bool MitCrdEstActive
		) :
			Block()
			, scrJrefDlgexpstr(scrJrefDlgexpstr)
			, scrJrefDlgimpstr(scrJrefDlgimpstr)
			, scrJrefDlgmissfeat(scrJrefDlgmissfeat)
			, scrJrefDlgnew(scrJrefDlgnew)
			, scrJrefDlgwrite(scrJrefDlgwrite)
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefList(scrJrefList)
			, scrJrefRec(scrJrefRec)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdNewAvail(MitCrdNewAvail)
			, MitCrdIstAvail(MitCrdIstAvail)
			, MitCrdIstActive(MitCrdIstActive)
			, MitCrdCmfAvail(MitCrdCmfAvail)
			, MitCrdCmfActive(MitCrdCmfActive)
			, MitCrdWrcAvail(MitCrdWrcAvail)
			, MitCrdWrcActive(MitCrdWrcActive)
			, MitCrdEstActive(MitCrdEstActive)
		{
	mask = {SCRJREFDLGEXPSTR, SCRJREFDLGIMPSTR, SCRJREFDLGMISSFEAT, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDISTAVAIL, MITCRDISTACTIVE, MITCRDCMFAVAIL, MITCRDCMFACTIVE, MITCRDWRCAVAIL, MITCRDWRCACTIVE, MITCRDESTACTIVE};
};

bool CrdWznmVis::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmVis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmVis";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgexpstr", scrJrefDlgexpstr)) add(SCRJREFDLGEXPSTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgimpstr", scrJrefDlgimpstr)) add(SCRJREFDLGIMPSTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgmissfeat", scrJrefDlgmissfeat)) add(SCRJREFDLGMISSFEAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrite", scrJrefDlgwrite)) add(SCRJREFDLGWRITE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIstAvail", MitCrdIstAvail)) add(MITCRDISTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIstActive", MitCrdIstActive)) add(MITCRDISTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCmfAvail", MitCrdCmfAvail)) add(MITCRDCMFAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCmfActive", MitCrdCmfActive)) add(MITCRDCMFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWrcAvail", MitCrdWrcAvail)) add(MITCRDWRCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdWrcActive", MitCrdWrcActive)) add(MITCRDWRCACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdEstActive", MitCrdEstActive)) add(MITCRDESTACTIVE);
	};

	return basefound;
};

set<uint> CrdWznmVis::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgexpstr == comp->scrJrefDlgexpstr) insert(items, SCRJREFDLGEXPSTR);
	if (scrJrefDlgimpstr == comp->scrJrefDlgimpstr) insert(items, SCRJREFDLGIMPSTR);
	if (scrJrefDlgmissfeat == comp->scrJrefDlgmissfeat) insert(items, SCRJREFDLGMISSFEAT);
	if (scrJrefDlgnew == comp->scrJrefDlgnew) insert(items, SCRJREFDLGNEW);
	if (scrJrefDlgwrite == comp->scrJrefDlgwrite) insert(items, SCRJREFDLGWRITE);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdIstAvail == comp->MitCrdIstAvail) insert(items, MITCRDISTAVAIL);
	if (MitCrdIstActive == comp->MitCrdIstActive) insert(items, MITCRDISTACTIVE);
	if (MitCrdCmfAvail == comp->MitCrdCmfAvail) insert(items, MITCRDCMFAVAIL);
	if (MitCrdCmfActive == comp->MitCrdCmfActive) insert(items, MITCRDCMFACTIVE);
	if (MitCrdWrcAvail == comp->MitCrdWrcAvail) insert(items, MITCRDWRCAVAIL);
	if (MitCrdWrcActive == comp->MitCrdWrcActive) insert(items, MITCRDWRCACTIVE);
	if (MitCrdEstActive == comp->MitCrdEstActive) insert(items, MITCRDESTACTIVE);

	return(items);
};

set<uint> CrdWznmVis::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGEXPSTR, SCRJREFDLGIMPSTR, SCRJREFDLGMISSFEAT, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDISTAVAIL, MITCRDISTACTIVE, MITCRDCMFAVAIL, MITCRDCMFACTIVE, MITCRDWRCAVAIL, MITCRDWRCACTIVE, MITCRDESTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVis::Tag
 ******************************************************************************/

CrdWznmVis::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
			, const string& MitCrdIst
			, const string& MitCrdCmf
			, const string& MitCrdWrc
			, const string& MitCrdEst
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
			, MitCrdNew(MitCrdNew)
			, MitCrdIst(MitCrdIst)
			, MitCrdCmf(MitCrdCmf)
			, MitCrdWrc(MitCrdWrc)
			, MitCrdEst(MitCrdEst)
		{
	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDIST, MITCRDCMF, MITCRDWRC, MITCRDEST};
};

bool CrdWznmVis::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmVis");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmVis";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIst", MitCrdIst)) add(MITCRDIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCmf", MitCrdCmf)) add(MITCRDCMF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdWrc", MitCrdWrc)) add(MITCRDWRC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdEst", MitCrdEst)) add(MITCRDEST);
	};

	return basefound;
};

/******************************************************************************
 class CrdWznmVis::DpchAppDo
 ******************************************************************************/

CrdWznmVis::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVISDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWznmVis::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmVis::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVisDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmVis::DpchEngData
 ******************************************************************************/

CrdWznmVis::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVISDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWznmVis::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmVis::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmVisData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFSge.readXML(docctx, basexpath, true)) add(FEEDFSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		feedFSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
