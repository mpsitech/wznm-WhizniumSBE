/**
	* \file CrdWznmVer.cpp
	* API code for job CrdWznmVer (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWznmVer.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmVer::VecVDo
 ******************************************************************************/

uint CrdWznmVer::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitcrdnewclick") return MITCRDNEWCLICK;
	if (s == "mitcrdpcvclick") return MITCRDPCVCLICK;
	if (s == "mitcrdidpclick") return MITCRDIDPCLICK;
	if (s == "mitcrdigbclick") return MITCRDIGBCLICK;
	if (s == "mitcrdimdclick") return MITCRDIMDCLICK;
	if (s == "mitcrdidbclick") return MITCRDIDBCLICK;
	if (s == "mitcrdibuclick") return MITCRDIBUCLICK;
	if (s == "mitcrdiieclick") return MITCRDIIECLICK;
	if (s == "mitcrdiopclick") return MITCRDIOPCLICK;
	if (s == "mitcrdicjclick") return MITCRDICJCLICK;
	if (s == "mitcrdguiclick") return MITCRDGUICLICK;
	if (s == "mitcrdauiclick") return MITCRDAUICLICK;
	if (s == "mitcrdgjtclick") return MITCRDGJTCLICK;
	if (s == "mitcrdajtclick") return MITCRDAJTCLICK;
	if (s == "mitcrdfnmclick") return MITCRDFNMCLICK;

	return(0);
};

string CrdWznmVer::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
	if (ix == MITCRDPCVCLICK) return("MitCrdPcvClick");
	if (ix == MITCRDIDPCLICK) return("MitCrdIdpClick");
	if (ix == MITCRDIGBCLICK) return("MitCrdIgbClick");
	if (ix == MITCRDIMDCLICK) return("MitCrdImdClick");
	if (ix == MITCRDIDBCLICK) return("MitCrdIdbClick");
	if (ix == MITCRDIBUCLICK) return("MitCrdIbuClick");
	if (ix == MITCRDIIECLICK) return("MitCrdIieClick");
	if (ix == MITCRDIOPCLICK) return("MitCrdIopClick");
	if (ix == MITCRDICJCLICK) return("MitCrdIcjClick");
	if (ix == MITCRDGUICLICK) return("MitCrdGuiClick");
	if (ix == MITCRDAUICLICK) return("MitCrdAuiClick");
	if (ix == MITCRDGJTCLICK) return("MitCrdGjtClick");
	if (ix == MITCRDAJTCLICK) return("MitCrdAjtClick");
	if (ix == MITCRDFNMCLICK) return("MitCrdFnmClick");

	return("");
};

/******************************************************************************
 class CrdWznmVer::VecVSge
 ******************************************************************************/

uint CrdWznmVer::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;
	if (s == "alrcvw") return ALRCVW;
	if (s == "setprjcvr") return SETPRJCVR;

	return(0);
};

string CrdWznmVer::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");
	if (ix == ALRCVW) return("alrcvw");
	if (ix == SETPRJCVR) return("setprjcvr");

	return("");
};

/******************************************************************************
 class CrdWznmVer::ContInf
 ******************************************************************************/

CrdWznmVer::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxCrdVer
		) :
			Block()
		{
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxCrdVer = MtxCrdVer;

	mask = {NUMFSGE, MRLAPPHLP, MTXCRDVER};
};

bool CrdWznmVer::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmVer";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxCrdVer", MtxCrdVer)) add(MTXCRDVER);
	};

	return basefound;
};

set<uint> CrdWznmVer::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxCrdVer == comp->MtxCrdVer) insert(items, MTXCRDVER);

	return(items);
};

set<uint> CrdWznmVer::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXCRDVER};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVer::StatApp
 ******************************************************************************/

CrdWznmVer::StatApp::StatApp(
			const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) :
			Block()
		{
	this->ixWznmVReqitmode = ixWznmVReqitmode;
	this->latency = latency;
	this->shortMenu = shortMenu;
	this->widthMenu = widthMenu;
	this->initdoneHeadbar = initdoneHeadbar;
	this->initdoneList = initdoneList;
	this->initdoneRec = initdoneRec;

	mask = {IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC};
};

bool CrdWznmVer::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmVer";

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

set<uint> CrdWznmVer::StatApp::comm(
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

set<uint> CrdWznmVer::StatApp::diff(
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
 class CrdWznmVer::StatShr
 ******************************************************************************/

CrdWznmVer::StatShr::StatShr(
			const string& scrJrefDlgbscui
			, const string& scrJrefDlgcustjob
			, const string& scrJrefDlgcustjtr
			, const string& scrJrefDlgcustui
			, const string& scrJrefDlgdbstr
			, const string& scrJrefDlgdeploy
			, const string& scrJrefDlgfinmod
			, const string& scrJrefDlggenjtr
			, const string& scrJrefDlggenui
			, const string& scrJrefDlgglobal
			, const string& scrJrefDlgimpexp
			, const string& scrJrefDlgnew
			, const string& scrJrefDlgoppack
			, const string& scrJrefDlgwrinimdl
			, const string& scrJrefHeadbar
			, const string& scrJrefList
			, const string& scrJrefRec
			, const bool MspCrd1Avail
			, const bool MitCrdNewAvail
			, const bool MitCrdPcvAvail
			, const bool MitCrdPcvActive
			, const bool MspCrd3Avail
			, const bool MitCrdIdpAvail
			, const bool MitCrdIdpActive
			, const bool MitCrdIgbAvail
			, const bool MitCrdIgbActive
			, const bool MspCrd4Avail
			, const bool MitCrdImdAvail
			, const bool MitCrdImdActive
			, const bool MspCrd5Avail
			, const bool MitCrdIdbAvail
			, const bool MitCrdIdbActive
			, const bool MitCrdIbuAvail
			, const bool MitCrdIbuActive
			, const bool MitCrdIieAvail
			, const bool MitCrdIieActive
			, const bool MitCrdIopAvail
			, const bool MitCrdIopActive
			, const bool MitCrdIcjAvail
			, const bool MitCrdIcjActive
			, const bool MspCrd6Avail
			, const bool MitCrdGuiAvail
			, const bool MitCrdGuiActive
			, const bool MitCrdAuiAvail
			, const bool MitCrdAuiActive
			, const bool MitCrdGjtAvail
			, const bool MitCrdGjtActive
			, const bool MitCrdAjtAvail
			, const bool MitCrdAjtActive
			, const bool MspCrd7Avail
			, const bool MitCrdFnmAvail
			, const bool MitCrdFnmActive
		) :
			Block()
		{
	this->scrJrefDlgbscui = scrJrefDlgbscui;
	this->scrJrefDlgcustjob = scrJrefDlgcustjob;
	this->scrJrefDlgcustjtr = scrJrefDlgcustjtr;
	this->scrJrefDlgcustui = scrJrefDlgcustui;
	this->scrJrefDlgdbstr = scrJrefDlgdbstr;
	this->scrJrefDlgdeploy = scrJrefDlgdeploy;
	this->scrJrefDlgfinmod = scrJrefDlgfinmod;
	this->scrJrefDlggenjtr = scrJrefDlggenjtr;
	this->scrJrefDlggenui = scrJrefDlggenui;
	this->scrJrefDlgglobal = scrJrefDlgglobal;
	this->scrJrefDlgimpexp = scrJrefDlgimpexp;
	this->scrJrefDlgnew = scrJrefDlgnew;
	this->scrJrefDlgoppack = scrJrefDlgoppack;
	this->scrJrefDlgwrinimdl = scrJrefDlgwrinimdl;
	this->scrJrefHeadbar = scrJrefHeadbar;
	this->scrJrefList = scrJrefList;
	this->scrJrefRec = scrJrefRec;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdNewAvail = MitCrdNewAvail;
	this->MitCrdPcvAvail = MitCrdPcvAvail;
	this->MitCrdPcvActive = MitCrdPcvActive;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MitCrdIdpAvail = MitCrdIdpAvail;
	this->MitCrdIdpActive = MitCrdIdpActive;
	this->MitCrdIgbAvail = MitCrdIgbAvail;
	this->MitCrdIgbActive = MitCrdIgbActive;
	this->MspCrd4Avail = MspCrd4Avail;
	this->MitCrdImdAvail = MitCrdImdAvail;
	this->MitCrdImdActive = MitCrdImdActive;
	this->MspCrd5Avail = MspCrd5Avail;
	this->MitCrdIdbAvail = MitCrdIdbAvail;
	this->MitCrdIdbActive = MitCrdIdbActive;
	this->MitCrdIbuAvail = MitCrdIbuAvail;
	this->MitCrdIbuActive = MitCrdIbuActive;
	this->MitCrdIieAvail = MitCrdIieAvail;
	this->MitCrdIieActive = MitCrdIieActive;
	this->MitCrdIopAvail = MitCrdIopAvail;
	this->MitCrdIopActive = MitCrdIopActive;
	this->MitCrdIcjAvail = MitCrdIcjAvail;
	this->MitCrdIcjActive = MitCrdIcjActive;
	this->MspCrd6Avail = MspCrd6Avail;
	this->MitCrdGuiAvail = MitCrdGuiAvail;
	this->MitCrdGuiActive = MitCrdGuiActive;
	this->MitCrdAuiAvail = MitCrdAuiAvail;
	this->MitCrdAuiActive = MitCrdAuiActive;
	this->MitCrdGjtAvail = MitCrdGjtAvail;
	this->MitCrdGjtActive = MitCrdGjtActive;
	this->MitCrdAjtAvail = MitCrdAjtAvail;
	this->MitCrdAjtActive = MitCrdAjtActive;
	this->MspCrd7Avail = MspCrd7Avail;
	this->MitCrdFnmAvail = MitCrdFnmAvail;
	this->MitCrdFnmActive = MitCrdFnmActive;

	mask = {SCRJREFDLGBSCUI, SCRJREFDLGCUSTJOB, SCRJREFDLGCUSTJTR, SCRJREFDLGCUSTUI, SCRJREFDLGDBSTR, SCRJREFDLGDEPLOY, SCRJREFDLGFINMOD, SCRJREFDLGGENJTR, SCRJREFDLGGENUI, SCRJREFDLGGLOBAL, SCRJREFDLGIMPEXP, SCRJREFDLGNEW, SCRJREFDLGOPPACK, SCRJREFDLGWRINIMDL, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MITCRDIGBAVAIL, MITCRDIGBACTIVE, MSPCRD4AVAIL, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MSPCRD5AVAIL, MITCRDIDBAVAIL, MITCRDIDBACTIVE, MITCRDIBUAVAIL, MITCRDIBUACTIVE, MITCRDIIEAVAIL, MITCRDIIEACTIVE, MITCRDIOPAVAIL, MITCRDIOPACTIVE, MITCRDICJAVAIL, MITCRDICJACTIVE, MSPCRD6AVAIL, MITCRDGUIAVAIL, MITCRDGUIACTIVE, MITCRDAUIAVAIL, MITCRDAUIACTIVE, MITCRDGJTAVAIL, MITCRDGJTACTIVE, MITCRDAJTAVAIL, MITCRDAJTACTIVE, MSPCRD7AVAIL, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
};

bool CrdWznmVer::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmVer";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgbscui", scrJrefDlgbscui)) add(SCRJREFDLGBSCUI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustjob", scrJrefDlgcustjob)) add(SCRJREFDLGCUSTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustjtr", scrJrefDlgcustjtr)) add(SCRJREFDLGCUSTJTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustui", scrJrefDlgcustui)) add(SCRJREFDLGCUSTUI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgdbstr", scrJrefDlgdbstr)) add(SCRJREFDLGDBSTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgdeploy", scrJrefDlgdeploy)) add(SCRJREFDLGDEPLOY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgfinmod", scrJrefDlgfinmod)) add(SCRJREFDLGFINMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlggenjtr", scrJrefDlggenjtr)) add(SCRJREFDLGGENJTR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlggenui", scrJrefDlggenui)) add(SCRJREFDLGGENUI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgglobal", scrJrefDlgglobal)) add(SCRJREFDLGGLOBAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgimpexp", scrJrefDlgimpexp)) add(SCRJREFDLGIMPEXP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", scrJrefDlgnew)) add(SCRJREFDLGNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgoppack", scrJrefDlgoppack)) add(SCRJREFDLGOPPACK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrinimdl", scrJrefDlgwrinimdl)) add(SCRJREFDLGWRINIMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefList", scrJrefList)) add(SCRJREFLIST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRec", scrJrefRec)) add(SCRJREFREC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", MitCrdNewAvail)) add(MITCRDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPcvAvail", MitCrdPcvAvail)) add(MITCRDPCVAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPcvActive", MitCrdPcvActive)) add(MITCRDPCVACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", MspCrd3Avail)) add(MSPCRD3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdpAvail", MitCrdIdpAvail)) add(MITCRDIDPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdpActive", MitCrdIdpActive)) add(MITCRDIDPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIgbAvail", MitCrdIgbAvail)) add(MITCRDIGBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIgbActive", MitCrdIgbActive)) add(MITCRDIGBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", MspCrd4Avail)) add(MSPCRD4AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdImdAvail", MitCrdImdAvail)) add(MITCRDIMDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdImdActive", MitCrdImdActive)) add(MITCRDIMDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", MspCrd5Avail)) add(MSPCRD5AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdbAvail", MitCrdIdbAvail)) add(MITCRDIDBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIdbActive", MitCrdIdbActive)) add(MITCRDIDBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIbuAvail", MitCrdIbuAvail)) add(MITCRDIBUAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIbuActive", MitCrdIbuActive)) add(MITCRDIBUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIieAvail", MitCrdIieAvail)) add(MITCRDIIEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIieActive", MitCrdIieActive)) add(MITCRDIIEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIopAvail", MitCrdIopAvail)) add(MITCRDIOPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIopActive", MitCrdIopActive)) add(MITCRDIOPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIcjAvail", MitCrdIcjAvail)) add(MITCRDICJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIcjActive", MitCrdIcjActive)) add(MITCRDICJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd6Avail", MspCrd6Avail)) add(MSPCRD6AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGuiAvail", MitCrdGuiAvail)) add(MITCRDGUIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGuiActive", MitCrdGuiActive)) add(MITCRDGUIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdAuiAvail", MitCrdAuiAvail)) add(MITCRDAUIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdAuiActive", MitCrdAuiActive)) add(MITCRDAUIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGjtAvail", MitCrdGjtAvail)) add(MITCRDGJTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdGjtActive", MitCrdGjtActive)) add(MITCRDGJTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdAjtAvail", MitCrdAjtAvail)) add(MITCRDAJTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdAjtActive", MitCrdAjtActive)) add(MITCRDAJTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd7Avail", MspCrd7Avail)) add(MSPCRD7AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFnmAvail", MitCrdFnmAvail)) add(MITCRDFNMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFnmActive", MitCrdFnmActive)) add(MITCRDFNMACTIVE);
	};

	return basefound;
};

set<uint> CrdWznmVer::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgbscui == comp->scrJrefDlgbscui) insert(items, SCRJREFDLGBSCUI);
	if (scrJrefDlgcustjob == comp->scrJrefDlgcustjob) insert(items, SCRJREFDLGCUSTJOB);
	if (scrJrefDlgcustjtr == comp->scrJrefDlgcustjtr) insert(items, SCRJREFDLGCUSTJTR);
	if (scrJrefDlgcustui == comp->scrJrefDlgcustui) insert(items, SCRJREFDLGCUSTUI);
	if (scrJrefDlgdbstr == comp->scrJrefDlgdbstr) insert(items, SCRJREFDLGDBSTR);
	if (scrJrefDlgdeploy == comp->scrJrefDlgdeploy) insert(items, SCRJREFDLGDEPLOY);
	if (scrJrefDlgfinmod == comp->scrJrefDlgfinmod) insert(items, SCRJREFDLGFINMOD);
	if (scrJrefDlggenjtr == comp->scrJrefDlggenjtr) insert(items, SCRJREFDLGGENJTR);
	if (scrJrefDlggenui == comp->scrJrefDlggenui) insert(items, SCRJREFDLGGENUI);
	if (scrJrefDlgglobal == comp->scrJrefDlgglobal) insert(items, SCRJREFDLGGLOBAL);
	if (scrJrefDlgimpexp == comp->scrJrefDlgimpexp) insert(items, SCRJREFDLGIMPEXP);
	if (scrJrefDlgnew == comp->scrJrefDlgnew) insert(items, SCRJREFDLGNEW);
	if (scrJrefDlgoppack == comp->scrJrefDlgoppack) insert(items, SCRJREFDLGOPPACK);
	if (scrJrefDlgwrinimdl == comp->scrJrefDlgwrinimdl) insert(items, SCRJREFDLGWRINIMDL);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefList == comp->scrJrefList) insert(items, SCRJREFLIST);
	if (scrJrefRec == comp->scrJrefRec) insert(items, SCRJREFREC);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdNewAvail == comp->MitCrdNewAvail) insert(items, MITCRDNEWAVAIL);
	if (MitCrdPcvAvail == comp->MitCrdPcvAvail) insert(items, MITCRDPCVAVAIL);
	if (MitCrdPcvActive == comp->MitCrdPcvActive) insert(items, MITCRDPCVACTIVE);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdIdpAvail == comp->MitCrdIdpAvail) insert(items, MITCRDIDPAVAIL);
	if (MitCrdIdpActive == comp->MitCrdIdpActive) insert(items, MITCRDIDPACTIVE);
	if (MitCrdIgbAvail == comp->MitCrdIgbAvail) insert(items, MITCRDIGBAVAIL);
	if (MitCrdIgbActive == comp->MitCrdIgbActive) insert(items, MITCRDIGBACTIVE);
	if (MspCrd4Avail == comp->MspCrd4Avail) insert(items, MSPCRD4AVAIL);
	if (MitCrdImdAvail == comp->MitCrdImdAvail) insert(items, MITCRDIMDAVAIL);
	if (MitCrdImdActive == comp->MitCrdImdActive) insert(items, MITCRDIMDACTIVE);
	if (MspCrd5Avail == comp->MspCrd5Avail) insert(items, MSPCRD5AVAIL);
	if (MitCrdIdbAvail == comp->MitCrdIdbAvail) insert(items, MITCRDIDBAVAIL);
	if (MitCrdIdbActive == comp->MitCrdIdbActive) insert(items, MITCRDIDBACTIVE);
	if (MitCrdIbuAvail == comp->MitCrdIbuAvail) insert(items, MITCRDIBUAVAIL);
	if (MitCrdIbuActive == comp->MitCrdIbuActive) insert(items, MITCRDIBUACTIVE);
	if (MitCrdIieAvail == comp->MitCrdIieAvail) insert(items, MITCRDIIEAVAIL);
	if (MitCrdIieActive == comp->MitCrdIieActive) insert(items, MITCRDIIEACTIVE);
	if (MitCrdIopAvail == comp->MitCrdIopAvail) insert(items, MITCRDIOPAVAIL);
	if (MitCrdIopActive == comp->MitCrdIopActive) insert(items, MITCRDIOPACTIVE);
	if (MitCrdIcjAvail == comp->MitCrdIcjAvail) insert(items, MITCRDICJAVAIL);
	if (MitCrdIcjActive == comp->MitCrdIcjActive) insert(items, MITCRDICJACTIVE);
	if (MspCrd6Avail == comp->MspCrd6Avail) insert(items, MSPCRD6AVAIL);
	if (MitCrdGuiAvail == comp->MitCrdGuiAvail) insert(items, MITCRDGUIAVAIL);
	if (MitCrdGuiActive == comp->MitCrdGuiActive) insert(items, MITCRDGUIACTIVE);
	if (MitCrdAuiAvail == comp->MitCrdAuiAvail) insert(items, MITCRDAUIAVAIL);
	if (MitCrdAuiActive == comp->MitCrdAuiActive) insert(items, MITCRDAUIACTIVE);
	if (MitCrdGjtAvail == comp->MitCrdGjtAvail) insert(items, MITCRDGJTAVAIL);
	if (MitCrdGjtActive == comp->MitCrdGjtActive) insert(items, MITCRDGJTACTIVE);
	if (MitCrdAjtAvail == comp->MitCrdAjtAvail) insert(items, MITCRDAJTAVAIL);
	if (MitCrdAjtActive == comp->MitCrdAjtActive) insert(items, MITCRDAJTACTIVE);
	if (MspCrd7Avail == comp->MspCrd7Avail) insert(items, MSPCRD7AVAIL);
	if (MitCrdFnmAvail == comp->MitCrdFnmAvail) insert(items, MITCRDFNMAVAIL);
	if (MitCrdFnmActive == comp->MitCrdFnmActive) insert(items, MITCRDFNMACTIVE);

	return(items);
};

set<uint> CrdWznmVer::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGBSCUI, SCRJREFDLGCUSTJOB, SCRJREFDLGCUSTJTR, SCRJREFDLGCUSTUI, SCRJREFDLGDBSTR, SCRJREFDLGDEPLOY, SCRJREFDLGFINMOD, SCRJREFDLGGENJTR, SCRJREFDLGGENUI, SCRJREFDLGGLOBAL, SCRJREFDLGIMPEXP, SCRJREFDLGNEW, SCRJREFDLGOPPACK, SCRJREFDLGWRINIMDL, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MITCRDIGBAVAIL, MITCRDIGBACTIVE, MSPCRD4AVAIL, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MSPCRD5AVAIL, MITCRDIDBAVAIL, MITCRDIDBACTIVE, MITCRDIBUAVAIL, MITCRDIBUACTIVE, MITCRDIIEAVAIL, MITCRDIIEACTIVE, MITCRDIOPAVAIL, MITCRDIOPACTIVE, MITCRDICJAVAIL, MITCRDICJACTIVE, MSPCRD6AVAIL, MITCRDGUIAVAIL, MITCRDGUIACTIVE, MITCRDAUIAVAIL, MITCRDAUIACTIVE, MITCRDGJTAVAIL, MITCRDGJTACTIVE, MITCRDAJTAVAIL, MITCRDAJTACTIVE, MSPCRD7AVAIL, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVer::Tag
 ******************************************************************************/

CrdWznmVer::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitCrdNew
			, const string& MitCrdPcv
			, const string& MitCrdIdp
			, const string& MitCrdIgb
			, const string& MitCrdImd
			, const string& MitCrdIdb
			, const string& MitCrdIbu
			, const string& MitCrdIie
			, const string& MitCrdIop
			, const string& MitCrdIcj
			, const string& MitCrdGui
			, const string& MitCrdAui
			, const string& MitCrdGjt
			, const string& MitCrdAjt
			, const string& MitCrdFnm
		) :
			Block()
		{
	this->MitAppAbt = MitAppAbt;
	this->MrlAppHlp = MrlAppHlp;
	this->MitCrdNew = MitCrdNew;
	this->MitCrdPcv = MitCrdPcv;
	this->MitCrdIdp = MitCrdIdp;
	this->MitCrdIgb = MitCrdIgb;
	this->MitCrdImd = MitCrdImd;
	this->MitCrdIdb = MitCrdIdb;
	this->MitCrdIbu = MitCrdIbu;
	this->MitCrdIie = MitCrdIie;
	this->MitCrdIop = MitCrdIop;
	this->MitCrdIcj = MitCrdIcj;
	this->MitCrdGui = MitCrdGui;
	this->MitCrdAui = MitCrdAui;
	this->MitCrdGjt = MitCrdGjt;
	this->MitCrdAjt = MitCrdAjt;
	this->MitCrdFnm = MitCrdFnm;

	mask = {MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDPCV, MITCRDIDP, MITCRDIGB, MITCRDIMD, MITCRDIDB, MITCRDIBU, MITCRDIIE, MITCRDIOP, MITCRDICJ, MITCRDGUI, MITCRDAUI, MITCRDGJT, MITCRDAJT, MITCRDFNM};
};

bool CrdWznmVer::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmVer");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmVer";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdNew", MitCrdNew)) add(MITCRDNEW);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPcv", MitCrdPcv)) add(MITCRDPCV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIdp", MitCrdIdp)) add(MITCRDIDP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIgb", MitCrdIgb)) add(MITCRDIGB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdImd", MitCrdImd)) add(MITCRDIMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIdb", MitCrdIdb)) add(MITCRDIDB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIbu", MitCrdIbu)) add(MITCRDIBU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIie", MitCrdIie)) add(MITCRDIIE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIop", MitCrdIop)) add(MITCRDIOP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIcj", MitCrdIcj)) add(MITCRDICJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdGui", MitCrdGui)) add(MITCRDGUI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdAui", MitCrdAui)) add(MITCRDAUI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdGjt", MitCrdGjt)) add(MITCRDGJT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdAjt", MitCrdAjt)) add(MITCRDAJT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFnm", MitCrdFnm)) add(MITCRDFNM);
	};

	return basefound;
};

/******************************************************************************
 class CrdWznmVer::DpchAppDo
 ******************************************************************************/

CrdWznmVer::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string CrdWznmVer::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmVer::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVerDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmVer::DpchEngData
 ******************************************************************************/

CrdWznmVer::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVERDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWznmVer::DpchEngData::getSrefsMask() {
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

void CrdWznmVer::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmVerData");
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

