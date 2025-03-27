/**
	* \file CrdWznmNav.cpp
	* API code for job CrdWznmNav (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "CrdWznmNav.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class CrdWznmNav::VecVDo
 ******************************************************************************/

uint CrdWznmNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	if (s == "mitappabtclick") return MITAPPABTCLICK;
	if (s == "mitsesspsclick") return MITSESSPSCLICK;
	if (s == "mitsestrmclick") return MITSESTRMCLICK;
	if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	if (s == "mitcrdlocclick") return MITCRDLOCCLICK;
	if (s == "mitcrdtagclick") return MITCRDTAGCLICK;
	if (s == "mitcrdctpclick") return MITCRDCTPCLICK;
	if (s == "mitcrdmchclick") return MITCRDMCHCLICK;
	if (s == "mitcrdlibclick") return MITCRDLIBCLICK;
	if (s == "mitcrdprjclick") return MITCRDPRJCLICK;
	if (s == "mitcrdverclick") return MITCRDVERCLICK;
	if (s == "mitcrdcapclick") return MITCRDCAPCLICK;
	if (s == "mitcrderrclick") return MITCRDERRCLICK;
	if (s == "mitcrdtblclick") return MITCRDTBLCLICK;
	if (s == "mitcrdtcoclick") return MITCRDTCOCLICK;
	if (s == "mitcrdsbsclick") return MITCRDSBSCLICK;
	if (s == "mitcrdrelclick") return MITCRDRELCLICK;
	if (s == "mitcrdvecclick") return MITCRDVECCLICK;
	if (s == "mitcrdvitclick") return MITCRDVITCLICK;
	if (s == "mitcrdchkclick") return MITCRDCHKCLICK;
	if (s == "mitcrdstbclick") return MITCRDSTBCLICK;
	if (s == "mitcrdiexclick") return MITCRDIEXCLICK;
	if (s == "mitcrdimeclick") return MITCRDIMECLICK;
	if (s == "mitcrdpstclick") return MITCRDPSTCLICK;
	if (s == "mitcrdmdlclick") return MITCRDMDLCLICK;
	if (s == "mitcrdcarclick") return MITCRDCARCLICK;
	if (s == "mitcrddlgclick") return MITCRDDLGCLICK;
	if (s == "mitcrdpnlclick") return MITCRDPNLCLICK;
	if (s == "mitcrdqryclick") return MITCRDQRYCLICK;
	if (s == "mitcrdqcoclick") return MITCRDQCOCLICK;
	if (s == "mitcrdqmdclick") return MITCRDQMDCLICK;
	if (s == "mitcrdconclick") return MITCRDCONCLICK;
	if (s == "mitcrdopkclick") return MITCRDOPKCLICK;
	if (s == "mitcrdopxclick") return MITCRDOPXCLICK;
	if (s == "mitcrdjobclick") return MITCRDJOBCLICK;
	if (s == "mitcrdsgeclick") return MITCRDSGECLICK;
	if (s == "mitcrdmtdclick") return MITCRDMTDCLICK;
	if (s == "mitcrdblkclick") return MITCRDBLKCLICK;
	if (s == "mitcrdcalclick") return MITCRDCALCLICK;
	if (s == "mitcrdcmpclick") return MITCRDCMPCLICK;
	if (s == "mitcrdrlsclick") return MITCRDRLSCLICK;
	if (s == "mitcrdvisclick") return MITCRDVISCLICK;
	if (s == "mitcrdshtclick") return MITCRDSHTCLICK;
	if (s == "mitcrdboxclick") return MITCRDBOXCLICK;
	if (s == "mitcrdappclick") return MITCRDAPPCLICK;
	if (s == "mitcrdrtjclick") return MITCRDRTJCLICK;
	if (s == "mitcrdevtclick") return MITCRDEVTCLICK;
	if (s == "mitcrdseqclick") return MITCRDSEQCLICK;
	if (s == "mitcrdsteclick") return MITCRDSTECLICK;
	if (s == "mitcrdutlclick") return MITCRDUTLCLICK;
	if (s == "mitappmlcclick") return MITAPPMLCCLICK;
	if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdWznmNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
	if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	if (ix == MITCRDLOCCLICK) return("MitCrdLocClick");
	if (ix == MITCRDTAGCLICK) return("MitCrdTagClick");
	if (ix == MITCRDCTPCLICK) return("MitCrdCtpClick");
	if (ix == MITCRDMCHCLICK) return("MitCrdMchClick");
	if (ix == MITCRDLIBCLICK) return("MitCrdLibClick");
	if (ix == MITCRDPRJCLICK) return("MitCrdPrjClick");
	if (ix == MITCRDVERCLICK) return("MitCrdVerClick");
	if (ix == MITCRDCAPCLICK) return("MitCrdCapClick");
	if (ix == MITCRDERRCLICK) return("MitCrdErrClick");
	if (ix == MITCRDTBLCLICK) return("MitCrdTblClick");
	if (ix == MITCRDTCOCLICK) return("MitCrdTcoClick");
	if (ix == MITCRDSBSCLICK) return("MitCrdSbsClick");
	if (ix == MITCRDRELCLICK) return("MitCrdRelClick");
	if (ix == MITCRDVECCLICK) return("MitCrdVecClick");
	if (ix == MITCRDVITCLICK) return("MitCrdVitClick");
	if (ix == MITCRDCHKCLICK) return("MitCrdChkClick");
	if (ix == MITCRDSTBCLICK) return("MitCrdStbClick");
	if (ix == MITCRDIEXCLICK) return("MitCrdIexClick");
	if (ix == MITCRDIMECLICK) return("MitCrdImeClick");
	if (ix == MITCRDPSTCLICK) return("MitCrdPstClick");
	if (ix == MITCRDMDLCLICK) return("MitCrdMdlClick");
	if (ix == MITCRDCARCLICK) return("MitCrdCarClick");
	if (ix == MITCRDDLGCLICK) return("MitCrdDlgClick");
	if (ix == MITCRDPNLCLICK) return("MitCrdPnlClick");
	if (ix == MITCRDQRYCLICK) return("MitCrdQryClick");
	if (ix == MITCRDQCOCLICK) return("MitCrdQcoClick");
	if (ix == MITCRDQMDCLICK) return("MitCrdQmdClick");
	if (ix == MITCRDCONCLICK) return("MitCrdConClick");
	if (ix == MITCRDOPKCLICK) return("MitCrdOpkClick");
	if (ix == MITCRDOPXCLICK) return("MitCrdOpxClick");
	if (ix == MITCRDJOBCLICK) return("MitCrdJobClick");
	if (ix == MITCRDSGECLICK) return("MitCrdSgeClick");
	if (ix == MITCRDMTDCLICK) return("MitCrdMtdClick");
	if (ix == MITCRDBLKCLICK) return("MitCrdBlkClick");
	if (ix == MITCRDCALCLICK) return("MitCrdCalClick");
	if (ix == MITCRDCMPCLICK) return("MitCrdCmpClick");
	if (ix == MITCRDRLSCLICK) return("MitCrdRlsClick");
	if (ix == MITCRDVISCLICK) return("MitCrdVisClick");
	if (ix == MITCRDSHTCLICK) return("MitCrdShtClick");
	if (ix == MITCRDBOXCLICK) return("MitCrdBoxClick");
	if (ix == MITCRDAPPCLICK) return("MitCrdAppClick");
	if (ix == MITCRDRTJCLICK) return("MitCrdRtjClick");
	if (ix == MITCRDEVTCLICK) return("MitCrdEvtClick");
	if (ix == MITCRDSEQCLICK) return("MitCrdSeqClick");
	if (ix == MITCRDSTECLICK) return("MitCrdSteClick");
	if (ix == MITCRDUTLCLICK) return("MitCrdUtlClick");
	if (ix == MITAPPMLCCLICK) return("MitAppMlcClick");
	if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdWznmNav::VecVSge
 ******************************************************************************/

uint CrdWznmNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "alrwznmabt") return ALRWZNMABT;
	if (s == "alrwznmtrm") return ALRWZNMTRM;

	return(0);
};

string CrdWznmNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ALRWZNMABT) return("alrwznmabt");
	if (ix == ALRWZNMTRM) return("alrwznmtrm");

	return("");
};

/******************************************************************************
 class CrdWznmNav::ContInf
 ******************************************************************************/

CrdWznmNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) :
			Block()
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxSesSes1(MtxSesSes1)
			, MtxSesSes2(MtxSesSes2)
			, MtxSesSes3(MtxSesSes3)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

bool CrdWznmNav::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmNav";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFSge", numFSge)) add(NUMFSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", MtxSesSes1)) add(MTXSESSES1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", MtxSesSes2)) add(MTXSESSES2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", MtxSesSes3)) add(MTXSESSES3);
	};

	return basefound;
};

set<uint> CrdWznmNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdWznmNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmNav::StatApp
 ******************************************************************************/

CrdWznmNav::StatApp::StatApp(
			const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdonePre
			, const bool initdoneAdmin
			, const bool initdoneGlobal
			, const bool initdoneProject
			, const bool initdoneDbstr
			, const bool initdoneUix
			, const bool initdoneComp
			, const bool initdoneJob
			, const bool initdoneDeploy
			, const bool initdoneVisual
			, const bool initdoneAppdev
			, const bool initdoneAuxfct
		) :
			Block()
			, ixWznmVReqitmode(ixWznmVReqitmode)
			, latency(latency)
			, shortMenu(shortMenu)
			, widthMenu(widthMenu)
			, initdoneHeadbar(initdoneHeadbar)
			, initdonePre(initdonePre)
			, initdoneAdmin(initdoneAdmin)
			, initdoneGlobal(initdoneGlobal)
			, initdoneProject(initdoneProject)
			, initdoneDbstr(initdoneDbstr)
			, initdoneUix(initdoneUix)
			, initdoneComp(initdoneComp)
			, initdoneJob(initdoneJob)
			, initdoneDeploy(initdoneDeploy)
			, initdoneVisual(initdoneVisual)
			, initdoneAppdev(initdoneAppdev)
			, initdoneAuxfct(initdoneAuxfct)
		{
	mask = {IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEPROJECT, INITDONEDBSTR, INITDONEUIX, INITDONECOMP, INITDONEJOB, INITDONEDEPLOY, INITDONEVISUAL, INITDONEAPPDEV, INITDONEAUXFCT};
};

bool CrdWznmNav::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVReqitmode;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVReqitmode", srefIxWznmVReqitmode)) {
			ixWznmVReqitmode = VecWznmVReqitmode::getIx(srefIxWznmVReqitmode);
			add(IXWZNMVREQITMODE);
		};
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "latency", latency)) add(LATENCY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "shortMenu", shortMenu)) add(SHORTMENU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "widthMenu", widthMenu)) add(WIDTHMENU);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", initdoneHeadbar)) add(INITDONEHEADBAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePre", initdonePre)) add(INITDONEPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAdmin", initdoneAdmin)) add(INITDONEADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneGlobal", initdoneGlobal)) add(INITDONEGLOBAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneProject", initdoneProject)) add(INITDONEPROJECT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDbstr", initdoneDbstr)) add(INITDONEDBSTR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneUix", initdoneUix)) add(INITDONEUIX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneComp", initdoneComp)) add(INITDONECOMP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneJob", initdoneJob)) add(INITDONEJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDeploy", initdoneDeploy)) add(INITDONEDEPLOY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneVisual", initdoneVisual)) add(INITDONEVISUAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAppdev", initdoneAppdev)) add(INITDONEAPPDEV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAuxfct", initdoneAuxfct)) add(INITDONEAUXFCT);
	};

	return basefound;
};

set<uint> CrdWznmNav::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVReqitmode == comp->ixWznmVReqitmode) insert(items, IXWZNMVREQITMODE);
	if (latency == comp->latency) insert(items, LATENCY);
	if (shortMenu == comp->shortMenu) insert(items, SHORTMENU);
	if (widthMenu == comp->widthMenu) insert(items, WIDTHMENU);
	if (initdoneHeadbar == comp->initdoneHeadbar) insert(items, INITDONEHEADBAR);
	if (initdonePre == comp->initdonePre) insert(items, INITDONEPRE);
	if (initdoneAdmin == comp->initdoneAdmin) insert(items, INITDONEADMIN);
	if (initdoneGlobal == comp->initdoneGlobal) insert(items, INITDONEGLOBAL);
	if (initdoneProject == comp->initdoneProject) insert(items, INITDONEPROJECT);
	if (initdoneDbstr == comp->initdoneDbstr) insert(items, INITDONEDBSTR);
	if (initdoneUix == comp->initdoneUix) insert(items, INITDONEUIX);
	if (initdoneComp == comp->initdoneComp) insert(items, INITDONECOMP);
	if (initdoneJob == comp->initdoneJob) insert(items, INITDONEJOB);
	if (initdoneDeploy == comp->initdoneDeploy) insert(items, INITDONEDEPLOY);
	if (initdoneVisual == comp->initdoneVisual) insert(items, INITDONEVISUAL);
	if (initdoneAppdev == comp->initdoneAppdev) insert(items, INITDONEAPPDEV);
	if (initdoneAuxfct == comp->initdoneAuxfct) insert(items, INITDONEAUXFCT);

	return(items);
};

set<uint> CrdWznmNav::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEPROJECT, INITDONEDBSTR, INITDONEUIX, INITDONECOMP, INITDONEJOB, INITDONEDEPLOY, INITDONEVISUAL, INITDONEAPPDEV, INITDONEAUXFCT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmNav::StatShr
 ******************************************************************************/

CrdWznmNav::StatShr::StatShr(
			const string& scrJrefDlgloaini
			, const string& scrJrefDlgmnglic
			, const string& scrJrefHeadbar
			, const string& scrJrefPre
			, const bool pnlpreAvail
			, const string& scrJrefAdmin
			, const bool pnladminAvail
			, const string& scrJrefGlobal
			, const bool pnlglobalAvail
			, const string& scrJrefProject
			, const bool pnlprojectAvail
			, const string& scrJrefDbstr
			, const bool pnldbstrAvail
			, const string& scrJrefUix
			, const bool pnluixAvail
			, const string& scrJrefComp
			, const bool pnlcompAvail
			, const string& scrJrefJob
			, const bool pnljobAvail
			, const string& scrJrefDeploy
			, const bool pnldeployAvail
			, const string& scrJrefVisual
			, const bool pnlvisualAvail
			, const string& scrJrefAppdev
			, const bool pnlappdevAvail
			, const string& scrJrefAuxfct
			, const bool pnlauxfctAvail
			, const bool MitSesSpsAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdFilAvail
			, const bool MspCrd2Avail
			, const bool MitCrdLocAvail
			, const bool MitCrdTagAvail
			, const bool MitCrdCtpAvail
			, const bool MitCrdMchAvail
			, const bool MitCrdLibAvail
			, const bool MspCrd3Avail
			, const bool MitCrdPrjAvail
			, const bool MitCrdVerAvail
			, const bool MitCrdCapAvail
			, const bool MitCrdCapActive
			, const bool MitCrdErrAvail
			, const bool MitCrdErrActive
			, const bool MspCrd4Avail
			, const bool MitCrdTblAvail
			, const bool MitCrdTblActive
			, const bool MitCrdTcoAvail
			, const bool MitCrdTcoActive
			, const bool MitCrdSbsAvail
			, const bool MitCrdSbsActive
			, const bool MitCrdRelAvail
			, const bool MitCrdRelActive
			, const bool MitCrdVecAvail
			, const bool MitCrdVecActive
			, const bool MitCrdVitAvail
			, const bool MitCrdVitActive
			, const bool MitCrdChkAvail
			, const bool MitCrdChkActive
			, const bool MitCrdStbAvail
			, const bool MitCrdStbActive
			, const bool MitCrdIexAvail
			, const bool MitCrdIexActive
			, const bool MitCrdImeAvail
			, const bool MitCrdImeActive
			, const bool MspCrd5Avail
			, const bool MitCrdPstAvail
			, const bool MitCrdPstActive
			, const bool MitCrdMdlAvail
			, const bool MitCrdMdlActive
			, const bool MitCrdCarAvail
			, const bool MitCrdCarActive
			, const bool MitCrdDlgAvail
			, const bool MitCrdDlgActive
			, const bool MitCrdPnlAvail
			, const bool MitCrdPnlActive
			, const bool MitCrdQryAvail
			, const bool MitCrdQryActive
			, const bool MitCrdQcoAvail
			, const bool MitCrdQcoActive
			, const bool MitCrdQmdAvail
			, const bool MitCrdQmdActive
			, const bool MitCrdConAvail
			, const bool MitCrdConActive
			, const bool MspCrd6Avail
			, const bool MitCrdOpkAvail
			, const bool MitCrdOpkActive
			, const bool MitCrdOpxAvail
			, const bool MitCrdOpxActive
			, const bool MspCrd7Avail
			, const bool MitCrdJobAvail
			, const bool MitCrdJobActive
			, const bool MitCrdSgeAvail
			, const bool MitCrdSgeActive
			, const bool MitCrdMtdAvail
			, const bool MitCrdMtdActive
			, const bool MitCrdBlkAvail
			, const bool MitCrdBlkActive
			, const bool MitCrdCalAvail
			, const bool MitCrdCalActive
			, const bool MspCrd8Avail
			, const bool MitCrdCmpAvail
			, const bool MitCrdRlsAvail
			, const bool MitCrdRlsActive
			, const bool MspCrd9Avail
			, const bool MitCrdVisAvail
			, const bool MitCrdShtAvail
			, const bool MitCrdShtActive
			, const bool MitCrdBoxAvail
			, const bool MitCrdBoxActive
			, const bool MspCrd10Avail
			, const bool MitCrdAppAvail
			, const bool MitCrdRtjAvail
			, const bool MitCrdRtjActive
			, const bool MitCrdEvtAvail
			, const bool MitCrdEvtActive
			, const bool MitCrdSeqAvail
			, const bool MitCrdSeqActive
			, const bool MitCrdSteAvail
			, const bool MitCrdSteActive
			, const bool MspCrd11Avail
			, const bool MitCrdUtlAvail
			, const bool MspApp2Avail
			, const bool MitAppMlcAvail
			, const bool MitAppLoiAvail
		) :
			Block()
			, scrJrefDlgloaini(scrJrefDlgloaini)
			, scrJrefDlgmnglic(scrJrefDlgmnglic)
			, scrJrefHeadbar(scrJrefHeadbar)
			, scrJrefPre(scrJrefPre)
			, pnlpreAvail(pnlpreAvail)
			, scrJrefAdmin(scrJrefAdmin)
			, pnladminAvail(pnladminAvail)
			, scrJrefGlobal(scrJrefGlobal)
			, pnlglobalAvail(pnlglobalAvail)
			, scrJrefProject(scrJrefProject)
			, pnlprojectAvail(pnlprojectAvail)
			, scrJrefDbstr(scrJrefDbstr)
			, pnldbstrAvail(pnldbstrAvail)
			, scrJrefUix(scrJrefUix)
			, pnluixAvail(pnluixAvail)
			, scrJrefComp(scrJrefComp)
			, pnlcompAvail(pnlcompAvail)
			, scrJrefJob(scrJrefJob)
			, pnljobAvail(pnljobAvail)
			, scrJrefDeploy(scrJrefDeploy)
			, pnldeployAvail(pnldeployAvail)
			, scrJrefVisual(scrJrefVisual)
			, pnlvisualAvail(pnlvisualAvail)
			, scrJrefAppdev(scrJrefAppdev)
			, pnlappdevAvail(pnlappdevAvail)
			, scrJrefAuxfct(scrJrefAuxfct)
			, pnlauxfctAvail(pnlauxfctAvail)
			, MitSesSpsAvail(MitSesSpsAvail)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdUsgAvail(MitCrdUsgAvail)
			, MitCrdUsrAvail(MitCrdUsrAvail)
			, MitCrdPrsAvail(MitCrdPrsAvail)
			, MitCrdFilAvail(MitCrdFilAvail)
			, MspCrd2Avail(MspCrd2Avail)
			, MitCrdLocAvail(MitCrdLocAvail)
			, MitCrdTagAvail(MitCrdTagAvail)
			, MitCrdCtpAvail(MitCrdCtpAvail)
			, MitCrdMchAvail(MitCrdMchAvail)
			, MitCrdLibAvail(MitCrdLibAvail)
			, MspCrd3Avail(MspCrd3Avail)
			, MitCrdPrjAvail(MitCrdPrjAvail)
			, MitCrdVerAvail(MitCrdVerAvail)
			, MitCrdCapAvail(MitCrdCapAvail)
			, MitCrdCapActive(MitCrdCapActive)
			, MitCrdErrAvail(MitCrdErrAvail)
			, MitCrdErrActive(MitCrdErrActive)
			, MspCrd4Avail(MspCrd4Avail)
			, MitCrdTblAvail(MitCrdTblAvail)
			, MitCrdTblActive(MitCrdTblActive)
			, MitCrdTcoAvail(MitCrdTcoAvail)
			, MitCrdTcoActive(MitCrdTcoActive)
			, MitCrdSbsAvail(MitCrdSbsAvail)
			, MitCrdSbsActive(MitCrdSbsActive)
			, MitCrdRelAvail(MitCrdRelAvail)
			, MitCrdRelActive(MitCrdRelActive)
			, MitCrdVecAvail(MitCrdVecAvail)
			, MitCrdVecActive(MitCrdVecActive)
			, MitCrdVitAvail(MitCrdVitAvail)
			, MitCrdVitActive(MitCrdVitActive)
			, MitCrdChkAvail(MitCrdChkAvail)
			, MitCrdChkActive(MitCrdChkActive)
			, MitCrdStbAvail(MitCrdStbAvail)
			, MitCrdStbActive(MitCrdStbActive)
			, MitCrdIexAvail(MitCrdIexAvail)
			, MitCrdIexActive(MitCrdIexActive)
			, MitCrdImeAvail(MitCrdImeAvail)
			, MitCrdImeActive(MitCrdImeActive)
			, MspCrd5Avail(MspCrd5Avail)
			, MitCrdPstAvail(MitCrdPstAvail)
			, MitCrdPstActive(MitCrdPstActive)
			, MitCrdMdlAvail(MitCrdMdlAvail)
			, MitCrdMdlActive(MitCrdMdlActive)
			, MitCrdCarAvail(MitCrdCarAvail)
			, MitCrdCarActive(MitCrdCarActive)
			, MitCrdDlgAvail(MitCrdDlgAvail)
			, MitCrdDlgActive(MitCrdDlgActive)
			, MitCrdPnlAvail(MitCrdPnlAvail)
			, MitCrdPnlActive(MitCrdPnlActive)
			, MitCrdQryAvail(MitCrdQryAvail)
			, MitCrdQryActive(MitCrdQryActive)
			, MitCrdQcoAvail(MitCrdQcoAvail)
			, MitCrdQcoActive(MitCrdQcoActive)
			, MitCrdQmdAvail(MitCrdQmdAvail)
			, MitCrdQmdActive(MitCrdQmdActive)
			, MitCrdConAvail(MitCrdConAvail)
			, MitCrdConActive(MitCrdConActive)
			, MspCrd6Avail(MspCrd6Avail)
			, MitCrdOpkAvail(MitCrdOpkAvail)
			, MitCrdOpkActive(MitCrdOpkActive)
			, MitCrdOpxAvail(MitCrdOpxAvail)
			, MitCrdOpxActive(MitCrdOpxActive)
			, MspCrd7Avail(MspCrd7Avail)
			, MitCrdJobAvail(MitCrdJobAvail)
			, MitCrdJobActive(MitCrdJobActive)
			, MitCrdSgeAvail(MitCrdSgeAvail)
			, MitCrdSgeActive(MitCrdSgeActive)
			, MitCrdMtdAvail(MitCrdMtdAvail)
			, MitCrdMtdActive(MitCrdMtdActive)
			, MitCrdBlkAvail(MitCrdBlkAvail)
			, MitCrdBlkActive(MitCrdBlkActive)
			, MitCrdCalAvail(MitCrdCalAvail)
			, MitCrdCalActive(MitCrdCalActive)
			, MspCrd8Avail(MspCrd8Avail)
			, MitCrdCmpAvail(MitCrdCmpAvail)
			, MitCrdRlsAvail(MitCrdRlsAvail)
			, MitCrdRlsActive(MitCrdRlsActive)
			, MspCrd9Avail(MspCrd9Avail)
			, MitCrdVisAvail(MitCrdVisAvail)
			, MitCrdShtAvail(MitCrdShtAvail)
			, MitCrdShtActive(MitCrdShtActive)
			, MitCrdBoxAvail(MitCrdBoxAvail)
			, MitCrdBoxActive(MitCrdBoxActive)
			, MspCrd10Avail(MspCrd10Avail)
			, MitCrdAppAvail(MitCrdAppAvail)
			, MitCrdRtjAvail(MitCrdRtjAvail)
			, MitCrdRtjActive(MitCrdRtjActive)
			, MitCrdEvtAvail(MitCrdEvtAvail)
			, MitCrdEvtActive(MitCrdEvtActive)
			, MitCrdSeqAvail(MitCrdSeqAvail)
			, MitCrdSeqActive(MitCrdSeqActive)
			, MitCrdSteAvail(MitCrdSteAvail)
			, MitCrdSteActive(MitCrdSteActive)
			, MspCrd11Avail(MspCrd11Avail)
			, MitCrdUtlAvail(MitCrdUtlAvail)
			, MspApp2Avail(MspApp2Avail)
			, MitAppMlcAvail(MitAppMlcAvail)
			, MitAppLoiAvail(MitAppLoiAvail)
		{
	mask = {SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFPROJECT, PNLPROJECTAVAIL, SCRJREFDBSTR, PNLDBSTRAVAIL, SCRJREFUIX, PNLUIXAVAIL, SCRJREFCOMP, PNLCOMPAVAIL, SCRJREFJOB, PNLJOBAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFVISUAL, PNLVISUALAVAIL, SCRJREFAPPDEV, PNLAPPDEVAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDLOCAVAIL, MITCRDTAGAVAIL, MITCRDCTPAVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDCAPAVAIL, MITCRDCAPACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MSPCRD4AVAIL, MITCRDTBLAVAIL, MITCRDTBLACTIVE, MITCRDTCOAVAIL, MITCRDTCOACTIVE, MITCRDSBSAVAIL, MITCRDSBSACTIVE, MITCRDRELAVAIL, MITCRDRELACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDVITAVAIL, MITCRDVITACTIVE, MITCRDCHKAVAIL, MITCRDCHKACTIVE, MITCRDSTBAVAIL, MITCRDSTBACTIVE, MITCRDIEXAVAIL, MITCRDIEXACTIVE, MITCRDIMEAVAIL, MITCRDIMEACTIVE, MSPCRD5AVAIL, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDMDLAVAIL, MITCRDMDLACTIVE, MITCRDCARAVAIL, MITCRDCARACTIVE, MITCRDDLGAVAIL, MITCRDDLGACTIVE, MITCRDPNLAVAIL, MITCRDPNLACTIVE, MITCRDQRYAVAIL, MITCRDQRYACTIVE, MITCRDQCOAVAIL, MITCRDQCOACTIVE, MITCRDQMDAVAIL, MITCRDQMDACTIVE, MITCRDCONAVAIL, MITCRDCONACTIVE, MSPCRD6AVAIL, MITCRDOPKAVAIL, MITCRDOPKACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MSPCRD7AVAIL, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDSGEAVAIL, MITCRDSGEACTIVE, MITCRDMTDAVAIL, MITCRDMTDACTIVE, MITCRDBLKAVAIL, MITCRDBLKACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MSPCRD8AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD9AVAIL, MITCRDVISAVAIL, MITCRDSHTAVAIL, MITCRDSHTACTIVE, MITCRDBOXAVAIL, MITCRDBOXACTIVE, MSPCRD10AVAIL, MITCRDAPPAVAIL, MITCRDRTJAVAIL, MITCRDRTJACTIVE, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDSEQAVAIL, MITCRDSEQACTIVE, MITCRDSTEAVAIL, MITCRDSTEACTIVE, MSPCRD11AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
};

bool CrdWznmNav::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", scrJrefDlgloaini)) add(SCRJREFDLGLOAINI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDlgmnglic", scrJrefDlgmnglic)) add(SCRJREFDLGMNGLIC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", scrJrefHeadbar)) add(SCRJREFHEADBAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPre", scrJrefPre)) add(SCRJREFPRE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpreAvail", pnlpreAvail)) add(PNLPREAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", scrJrefAdmin)) add(SCRJREFADMIN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnladminAvail", pnladminAvail)) add(PNLADMINAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefGlobal", scrJrefGlobal)) add(SCRJREFGLOBAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlglobalAvail", pnlglobalAvail)) add(PNLGLOBALAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefProject", scrJrefProject)) add(SCRJREFPROJECT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlprojectAvail", pnlprojectAvail)) add(PNLPROJECTAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDbstr", scrJrefDbstr)) add(SCRJREFDBSTR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnldbstrAvail", pnldbstrAvail)) add(PNLDBSTRAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefUix", scrJrefUix)) add(SCRJREFUIX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnluixAvail", pnluixAvail)) add(PNLUIXAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefComp", scrJrefComp)) add(SCRJREFCOMP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlcompAvail", pnlcompAvail)) add(PNLCOMPAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefJob", scrJrefJob)) add(SCRJREFJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnljobAvail", pnljobAvail)) add(PNLJOBAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDeploy", scrJrefDeploy)) add(SCRJREFDEPLOY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnldeployAvail", pnldeployAvail)) add(PNLDEPLOYAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefVisual", scrJrefVisual)) add(SCRJREFVISUAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlvisualAvail", pnlvisualAvail)) add(PNLVISUALAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAppdev", scrJrefAppdev)) add(SCRJREFAPPDEV);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlappdevAvail", pnlappdevAvail)) add(PNLAPPDEVAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAuxfct", scrJrefAuxfct)) add(SCRJREFAUXFCT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlauxfctAvail", pnlauxfctAvail)) add(PNLAUXFCTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitSesSpsAvail", MitSesSpsAvail)) add(MITSESSPSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", MspCrd1Avail)) add(MSPCRD1AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", MitCrdUsgAvail)) add(MITCRDUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", MitCrdUsrAvail)) add(MITCRDUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", MitCrdPrsAvail)) add(MITCRDPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", MitCrdFilAvail)) add(MITCRDFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", MspCrd2Avail)) add(MSPCRD2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLocAvail", MitCrdLocAvail)) add(MITCRDLOCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTagAvail", MitCrdTagAvail)) add(MITCRDTAGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCtpAvail", MitCrdCtpAvail)) add(MITCRDCTPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMchAvail", MitCrdMchAvail)) add(MITCRDMCHAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdLibAvail", MitCrdLibAvail)) add(MITCRDLIBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", MspCrd3Avail)) add(MSPCRD3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPrjAvail", MitCrdPrjAvail)) add(MITCRDPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVerAvail", MitCrdVerAvail)) add(MITCRDVERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCapAvail", MitCrdCapAvail)) add(MITCRDCAPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCapActive", MitCrdCapActive)) add(MITCRDCAPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdErrAvail", MitCrdErrAvail)) add(MITCRDERRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdErrActive", MitCrdErrActive)) add(MITCRDERRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", MspCrd4Avail)) add(MSPCRD4AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTblAvail", MitCrdTblAvail)) add(MITCRDTBLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTblActive", MitCrdTblActive)) add(MITCRDTBLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTcoAvail", MitCrdTcoAvail)) add(MITCRDTCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdTcoActive", MitCrdTcoActive)) add(MITCRDTCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSbsAvail", MitCrdSbsAvail)) add(MITCRDSBSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSbsActive", MitCrdSbsActive)) add(MITCRDSBSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRelAvail", MitCrdRelAvail)) add(MITCRDRELAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRelActive", MitCrdRelActive)) add(MITCRDRELACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVecAvail", MitCrdVecAvail)) add(MITCRDVECAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVecActive", MitCrdVecActive)) add(MITCRDVECACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVitAvail", MitCrdVitAvail)) add(MITCRDVITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVitActive", MitCrdVitActive)) add(MITCRDVITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdChkAvail", MitCrdChkAvail)) add(MITCRDCHKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdChkActive", MitCrdChkActive)) add(MITCRDCHKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdStbAvail", MitCrdStbAvail)) add(MITCRDSTBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdStbActive", MitCrdStbActive)) add(MITCRDSTBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIexAvail", MitCrdIexAvail)) add(MITCRDIEXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdIexActive", MitCrdIexActive)) add(MITCRDIEXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdImeAvail", MitCrdImeAvail)) add(MITCRDIMEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdImeActive", MitCrdImeActive)) add(MITCRDIMEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", MspCrd5Avail)) add(MSPCRD5AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPstAvail", MitCrdPstAvail)) add(MITCRDPSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPstActive", MitCrdPstActive)) add(MITCRDPSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMdlAvail", MitCrdMdlAvail)) add(MITCRDMDLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMdlActive", MitCrdMdlActive)) add(MITCRDMDLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCarAvail", MitCrdCarAvail)) add(MITCRDCARAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCarActive", MitCrdCarActive)) add(MITCRDCARACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDlgAvail", MitCrdDlgAvail)) add(MITCRDDLGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdDlgActive", MitCrdDlgActive)) add(MITCRDDLGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPnlAvail", MitCrdPnlAvail)) add(MITCRDPNLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdPnlActive", MitCrdPnlActive)) add(MITCRDPNLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdQryAvail", MitCrdQryAvail)) add(MITCRDQRYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdQryActive", MitCrdQryActive)) add(MITCRDQRYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdQcoAvail", MitCrdQcoAvail)) add(MITCRDQCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdQcoActive", MitCrdQcoActive)) add(MITCRDQCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdQmdAvail", MitCrdQmdAvail)) add(MITCRDQMDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdQmdActive", MitCrdQmdActive)) add(MITCRDQMDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdConAvail", MitCrdConAvail)) add(MITCRDCONAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdConActive", MitCrdConActive)) add(MITCRDCONACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd6Avail", MspCrd6Avail)) add(MSPCRD6AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOpkAvail", MitCrdOpkAvail)) add(MITCRDOPKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOpkActive", MitCrdOpkActive)) add(MITCRDOPKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOpxAvail", MitCrdOpxAvail)) add(MITCRDOPXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdOpxActive", MitCrdOpxActive)) add(MITCRDOPXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd7Avail", MspCrd7Avail)) add(MSPCRD7AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdJobAvail", MitCrdJobAvail)) add(MITCRDJOBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdJobActive", MitCrdJobActive)) add(MITCRDJOBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSgeAvail", MitCrdSgeAvail)) add(MITCRDSGEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSgeActive", MitCrdSgeActive)) add(MITCRDSGEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMtdAvail", MitCrdMtdAvail)) add(MITCRDMTDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdMtdActive", MitCrdMtdActive)) add(MITCRDMTDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBlkAvail", MitCrdBlkAvail)) add(MITCRDBLKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBlkActive", MitCrdBlkActive)) add(MITCRDBLKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCalAvail", MitCrdCalAvail)) add(MITCRDCALAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCalActive", MitCrdCalActive)) add(MITCRDCALACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd8Avail", MspCrd8Avail)) add(MSPCRD8AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdCmpAvail", MitCrdCmpAvail)) add(MITCRDCMPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRlsAvail", MitCrdRlsAvail)) add(MITCRDRLSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRlsActive", MitCrdRlsActive)) add(MITCRDRLSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd9Avail", MspCrd9Avail)) add(MSPCRD9AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdVisAvail", MitCrdVisAvail)) add(MITCRDVISAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdShtAvail", MitCrdShtAvail)) add(MITCRDSHTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdShtActive", MitCrdShtActive)) add(MITCRDSHTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBoxAvail", MitCrdBoxAvail)) add(MITCRDBOXAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdBoxActive", MitCrdBoxActive)) add(MITCRDBOXACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd10Avail", MspCrd10Avail)) add(MSPCRD10AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdAppAvail", MitCrdAppAvail)) add(MITCRDAPPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRtjAvail", MitCrdRtjAvail)) add(MITCRDRTJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdRtjActive", MitCrdRtjActive)) add(MITCRDRTJACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdEvtAvail", MitCrdEvtAvail)) add(MITCRDEVTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdEvtActive", MitCrdEvtActive)) add(MITCRDEVTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSeqAvail", MitCrdSeqAvail)) add(MITCRDSEQAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSeqActive", MitCrdSeqActive)) add(MITCRDSEQACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSteAvail", MitCrdSteAvail)) add(MITCRDSTEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdSteActive", MitCrdSteActive)) add(MITCRDSTEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspCrd11Avail", MspCrd11Avail)) add(MSPCRD11AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitCrdUtlAvail", MitCrdUtlAvail)) add(MITCRDUTLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MspApp2Avail", MspApp2Avail)) add(MSPAPP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppMlcAvail", MitAppMlcAvail)) add(MITAPPMLCAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", MitAppLoiAvail)) add(MITAPPLOIAVAIL);
	};

	return basefound;
};

set<uint> CrdWznmNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefDlgloaini == comp->scrJrefDlgloaini) insert(items, SCRJREFDLGLOAINI);
	if (scrJrefDlgmnglic == comp->scrJrefDlgmnglic) insert(items, SCRJREFDLGMNGLIC);
	if (scrJrefHeadbar == comp->scrJrefHeadbar) insert(items, SCRJREFHEADBAR);
	if (scrJrefPre == comp->scrJrefPre) insert(items, SCRJREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (scrJrefAdmin == comp->scrJrefAdmin) insert(items, SCRJREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (scrJrefGlobal == comp->scrJrefGlobal) insert(items, SCRJREFGLOBAL);
	if (pnlglobalAvail == comp->pnlglobalAvail) insert(items, PNLGLOBALAVAIL);
	if (scrJrefProject == comp->scrJrefProject) insert(items, SCRJREFPROJECT);
	if (pnlprojectAvail == comp->pnlprojectAvail) insert(items, PNLPROJECTAVAIL);
	if (scrJrefDbstr == comp->scrJrefDbstr) insert(items, SCRJREFDBSTR);
	if (pnldbstrAvail == comp->pnldbstrAvail) insert(items, PNLDBSTRAVAIL);
	if (scrJrefUix == comp->scrJrefUix) insert(items, SCRJREFUIX);
	if (pnluixAvail == comp->pnluixAvail) insert(items, PNLUIXAVAIL);
	if (scrJrefComp == comp->scrJrefComp) insert(items, SCRJREFCOMP);
	if (pnlcompAvail == comp->pnlcompAvail) insert(items, PNLCOMPAVAIL);
	if (scrJrefJob == comp->scrJrefJob) insert(items, SCRJREFJOB);
	if (pnljobAvail == comp->pnljobAvail) insert(items, PNLJOBAVAIL);
	if (scrJrefDeploy == comp->scrJrefDeploy) insert(items, SCRJREFDEPLOY);
	if (pnldeployAvail == comp->pnldeployAvail) insert(items, PNLDEPLOYAVAIL);
	if (scrJrefVisual == comp->scrJrefVisual) insert(items, SCRJREFVISUAL);
	if (pnlvisualAvail == comp->pnlvisualAvail) insert(items, PNLVISUALAVAIL);
	if (scrJrefAppdev == comp->scrJrefAppdev) insert(items, SCRJREFAPPDEV);
	if (pnlappdevAvail == comp->pnlappdevAvail) insert(items, PNLAPPDEVAVAIL);
	if (scrJrefAuxfct == comp->scrJrefAuxfct) insert(items, SCRJREFAUXFCT);
	if (pnlauxfctAvail == comp->pnlauxfctAvail) insert(items, PNLAUXFCTAVAIL);
	if (MitSesSpsAvail == comp->MitSesSpsAvail) insert(items, MITSESSPSAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdLocAvail == comp->MitCrdLocAvail) insert(items, MITCRDLOCAVAIL);
	if (MitCrdTagAvail == comp->MitCrdTagAvail) insert(items, MITCRDTAGAVAIL);
	if (MitCrdCtpAvail == comp->MitCrdCtpAvail) insert(items, MITCRDCTPAVAIL);
	if (MitCrdMchAvail == comp->MitCrdMchAvail) insert(items, MITCRDMCHAVAIL);
	if (MitCrdLibAvail == comp->MitCrdLibAvail) insert(items, MITCRDLIBAVAIL);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdPrjAvail == comp->MitCrdPrjAvail) insert(items, MITCRDPRJAVAIL);
	if (MitCrdVerAvail == comp->MitCrdVerAvail) insert(items, MITCRDVERAVAIL);
	if (MitCrdCapAvail == comp->MitCrdCapAvail) insert(items, MITCRDCAPAVAIL);
	if (MitCrdCapActive == comp->MitCrdCapActive) insert(items, MITCRDCAPACTIVE);
	if (MitCrdErrAvail == comp->MitCrdErrAvail) insert(items, MITCRDERRAVAIL);
	if (MitCrdErrActive == comp->MitCrdErrActive) insert(items, MITCRDERRACTIVE);
	if (MspCrd4Avail == comp->MspCrd4Avail) insert(items, MSPCRD4AVAIL);
	if (MitCrdTblAvail == comp->MitCrdTblAvail) insert(items, MITCRDTBLAVAIL);
	if (MitCrdTblActive == comp->MitCrdTblActive) insert(items, MITCRDTBLACTIVE);
	if (MitCrdTcoAvail == comp->MitCrdTcoAvail) insert(items, MITCRDTCOAVAIL);
	if (MitCrdTcoActive == comp->MitCrdTcoActive) insert(items, MITCRDTCOACTIVE);
	if (MitCrdSbsAvail == comp->MitCrdSbsAvail) insert(items, MITCRDSBSAVAIL);
	if (MitCrdSbsActive == comp->MitCrdSbsActive) insert(items, MITCRDSBSACTIVE);
	if (MitCrdRelAvail == comp->MitCrdRelAvail) insert(items, MITCRDRELAVAIL);
	if (MitCrdRelActive == comp->MitCrdRelActive) insert(items, MITCRDRELACTIVE);
	if (MitCrdVecAvail == comp->MitCrdVecAvail) insert(items, MITCRDVECAVAIL);
	if (MitCrdVecActive == comp->MitCrdVecActive) insert(items, MITCRDVECACTIVE);
	if (MitCrdVitAvail == comp->MitCrdVitAvail) insert(items, MITCRDVITAVAIL);
	if (MitCrdVitActive == comp->MitCrdVitActive) insert(items, MITCRDVITACTIVE);
	if (MitCrdChkAvail == comp->MitCrdChkAvail) insert(items, MITCRDCHKAVAIL);
	if (MitCrdChkActive == comp->MitCrdChkActive) insert(items, MITCRDCHKACTIVE);
	if (MitCrdStbAvail == comp->MitCrdStbAvail) insert(items, MITCRDSTBAVAIL);
	if (MitCrdStbActive == comp->MitCrdStbActive) insert(items, MITCRDSTBACTIVE);
	if (MitCrdIexAvail == comp->MitCrdIexAvail) insert(items, MITCRDIEXAVAIL);
	if (MitCrdIexActive == comp->MitCrdIexActive) insert(items, MITCRDIEXACTIVE);
	if (MitCrdImeAvail == comp->MitCrdImeAvail) insert(items, MITCRDIMEAVAIL);
	if (MitCrdImeActive == comp->MitCrdImeActive) insert(items, MITCRDIMEACTIVE);
	if (MspCrd5Avail == comp->MspCrd5Avail) insert(items, MSPCRD5AVAIL);
	if (MitCrdPstAvail == comp->MitCrdPstAvail) insert(items, MITCRDPSTAVAIL);
	if (MitCrdPstActive == comp->MitCrdPstActive) insert(items, MITCRDPSTACTIVE);
	if (MitCrdMdlAvail == comp->MitCrdMdlAvail) insert(items, MITCRDMDLAVAIL);
	if (MitCrdMdlActive == comp->MitCrdMdlActive) insert(items, MITCRDMDLACTIVE);
	if (MitCrdCarAvail == comp->MitCrdCarAvail) insert(items, MITCRDCARAVAIL);
	if (MitCrdCarActive == comp->MitCrdCarActive) insert(items, MITCRDCARACTIVE);
	if (MitCrdDlgAvail == comp->MitCrdDlgAvail) insert(items, MITCRDDLGAVAIL);
	if (MitCrdDlgActive == comp->MitCrdDlgActive) insert(items, MITCRDDLGACTIVE);
	if (MitCrdPnlAvail == comp->MitCrdPnlAvail) insert(items, MITCRDPNLAVAIL);
	if (MitCrdPnlActive == comp->MitCrdPnlActive) insert(items, MITCRDPNLACTIVE);
	if (MitCrdQryAvail == comp->MitCrdQryAvail) insert(items, MITCRDQRYAVAIL);
	if (MitCrdQryActive == comp->MitCrdQryActive) insert(items, MITCRDQRYACTIVE);
	if (MitCrdQcoAvail == comp->MitCrdQcoAvail) insert(items, MITCRDQCOAVAIL);
	if (MitCrdQcoActive == comp->MitCrdQcoActive) insert(items, MITCRDQCOACTIVE);
	if (MitCrdQmdAvail == comp->MitCrdQmdAvail) insert(items, MITCRDQMDAVAIL);
	if (MitCrdQmdActive == comp->MitCrdQmdActive) insert(items, MITCRDQMDACTIVE);
	if (MitCrdConAvail == comp->MitCrdConAvail) insert(items, MITCRDCONAVAIL);
	if (MitCrdConActive == comp->MitCrdConActive) insert(items, MITCRDCONACTIVE);
	if (MspCrd6Avail == comp->MspCrd6Avail) insert(items, MSPCRD6AVAIL);
	if (MitCrdOpkAvail == comp->MitCrdOpkAvail) insert(items, MITCRDOPKAVAIL);
	if (MitCrdOpkActive == comp->MitCrdOpkActive) insert(items, MITCRDOPKACTIVE);
	if (MitCrdOpxAvail == comp->MitCrdOpxAvail) insert(items, MITCRDOPXAVAIL);
	if (MitCrdOpxActive == comp->MitCrdOpxActive) insert(items, MITCRDOPXACTIVE);
	if (MspCrd7Avail == comp->MspCrd7Avail) insert(items, MSPCRD7AVAIL);
	if (MitCrdJobAvail == comp->MitCrdJobAvail) insert(items, MITCRDJOBAVAIL);
	if (MitCrdJobActive == comp->MitCrdJobActive) insert(items, MITCRDJOBACTIVE);
	if (MitCrdSgeAvail == comp->MitCrdSgeAvail) insert(items, MITCRDSGEAVAIL);
	if (MitCrdSgeActive == comp->MitCrdSgeActive) insert(items, MITCRDSGEACTIVE);
	if (MitCrdMtdAvail == comp->MitCrdMtdAvail) insert(items, MITCRDMTDAVAIL);
	if (MitCrdMtdActive == comp->MitCrdMtdActive) insert(items, MITCRDMTDACTIVE);
	if (MitCrdBlkAvail == comp->MitCrdBlkAvail) insert(items, MITCRDBLKAVAIL);
	if (MitCrdBlkActive == comp->MitCrdBlkActive) insert(items, MITCRDBLKACTIVE);
	if (MitCrdCalAvail == comp->MitCrdCalAvail) insert(items, MITCRDCALAVAIL);
	if (MitCrdCalActive == comp->MitCrdCalActive) insert(items, MITCRDCALACTIVE);
	if (MspCrd8Avail == comp->MspCrd8Avail) insert(items, MSPCRD8AVAIL);
	if (MitCrdCmpAvail == comp->MitCrdCmpAvail) insert(items, MITCRDCMPAVAIL);
	if (MitCrdRlsAvail == comp->MitCrdRlsAvail) insert(items, MITCRDRLSAVAIL);
	if (MitCrdRlsActive == comp->MitCrdRlsActive) insert(items, MITCRDRLSACTIVE);
	if (MspCrd9Avail == comp->MspCrd9Avail) insert(items, MSPCRD9AVAIL);
	if (MitCrdVisAvail == comp->MitCrdVisAvail) insert(items, MITCRDVISAVAIL);
	if (MitCrdShtAvail == comp->MitCrdShtAvail) insert(items, MITCRDSHTAVAIL);
	if (MitCrdShtActive == comp->MitCrdShtActive) insert(items, MITCRDSHTACTIVE);
	if (MitCrdBoxAvail == comp->MitCrdBoxAvail) insert(items, MITCRDBOXAVAIL);
	if (MitCrdBoxActive == comp->MitCrdBoxActive) insert(items, MITCRDBOXACTIVE);
	if (MspCrd10Avail == comp->MspCrd10Avail) insert(items, MSPCRD10AVAIL);
	if (MitCrdAppAvail == comp->MitCrdAppAvail) insert(items, MITCRDAPPAVAIL);
	if (MitCrdRtjAvail == comp->MitCrdRtjAvail) insert(items, MITCRDRTJAVAIL);
	if (MitCrdRtjActive == comp->MitCrdRtjActive) insert(items, MITCRDRTJACTIVE);
	if (MitCrdEvtAvail == comp->MitCrdEvtAvail) insert(items, MITCRDEVTAVAIL);
	if (MitCrdEvtActive == comp->MitCrdEvtActive) insert(items, MITCRDEVTACTIVE);
	if (MitCrdSeqAvail == comp->MitCrdSeqAvail) insert(items, MITCRDSEQAVAIL);
	if (MitCrdSeqActive == comp->MitCrdSeqActive) insert(items, MITCRDSEQACTIVE);
	if (MitCrdSteAvail == comp->MitCrdSteAvail) insert(items, MITCRDSTEAVAIL);
	if (MitCrdSteActive == comp->MitCrdSteActive) insert(items, MITCRDSTEACTIVE);
	if (MspCrd11Avail == comp->MspCrd11Avail) insert(items, MSPCRD11AVAIL);
	if (MitCrdUtlAvail == comp->MitCrdUtlAvail) insert(items, MITCRDUTLAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppMlcAvail == comp->MitAppMlcAvail) insert(items, MITAPPMLCAVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdWznmNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFPROJECT, PNLPROJECTAVAIL, SCRJREFDBSTR, PNLDBSTRAVAIL, SCRJREFUIX, PNLUIXAVAIL, SCRJREFCOMP, PNLCOMPAVAIL, SCRJREFJOB, PNLJOBAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFVISUAL, PNLVISUALAVAIL, SCRJREFAPPDEV, PNLAPPDEVAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDLOCAVAIL, MITCRDTAGAVAIL, MITCRDCTPAVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDCAPAVAIL, MITCRDCAPACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MSPCRD4AVAIL, MITCRDTBLAVAIL, MITCRDTBLACTIVE, MITCRDTCOAVAIL, MITCRDTCOACTIVE, MITCRDSBSAVAIL, MITCRDSBSACTIVE, MITCRDRELAVAIL, MITCRDRELACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDVITAVAIL, MITCRDVITACTIVE, MITCRDCHKAVAIL, MITCRDCHKACTIVE, MITCRDSTBAVAIL, MITCRDSTBACTIVE, MITCRDIEXAVAIL, MITCRDIEXACTIVE, MITCRDIMEAVAIL, MITCRDIMEACTIVE, MSPCRD5AVAIL, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDMDLAVAIL, MITCRDMDLACTIVE, MITCRDCARAVAIL, MITCRDCARACTIVE, MITCRDDLGAVAIL, MITCRDDLGACTIVE, MITCRDPNLAVAIL, MITCRDPNLACTIVE, MITCRDQRYAVAIL, MITCRDQRYACTIVE, MITCRDQCOAVAIL, MITCRDQCOACTIVE, MITCRDQMDAVAIL, MITCRDQMDACTIVE, MITCRDCONAVAIL, MITCRDCONACTIVE, MSPCRD6AVAIL, MITCRDOPKAVAIL, MITCRDOPKACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MSPCRD7AVAIL, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDSGEAVAIL, MITCRDSGEACTIVE, MITCRDMTDAVAIL, MITCRDMTDACTIVE, MITCRDBLKAVAIL, MITCRDBLKACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MSPCRD8AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD9AVAIL, MITCRDVISAVAIL, MITCRDSHTAVAIL, MITCRDSHTACTIVE, MITCRDBOXAVAIL, MITCRDBOXACTIVE, MSPCRD10AVAIL, MITCRDAPPAVAIL, MITCRDRTJAVAIL, MITCRDRTJACTIVE, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDSEQAVAIL, MITCRDSEQACTIVE, MITCRDSTEAVAIL, MITCRDSTEACTIVE, MSPCRD11AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmNav::Tag
 ******************************************************************************/

CrdWznmNav::Tag::Tag(
			const string& MitAppAbt
			, const string& MrlAppHlp
			, const string& MitSesSps
			, const string& MitSesTrm
			, const string& MitCrdUsg
			, const string& MitCrdUsr
			, const string& MitCrdPrs
			, const string& MitCrdFil
			, const string& MitCrdLoc
			, const string& MitCrdTag
			, const string& MitCrdCtp
			, const string& MitCrdMch
			, const string& MitCrdLib
			, const string& MitCrdPrj
			, const string& MitCrdVer
			, const string& MitCrdCap
			, const string& MitCrdErr
			, const string& MitCrdTbl
			, const string& MitCrdTco
			, const string& MitCrdSbs
			, const string& MitCrdRel
			, const string& MitCrdVec
			, const string& MitCrdVit
			, const string& MitCrdChk
			, const string& MitCrdStb
			, const string& MitCrdIex
			, const string& MitCrdIme
			, const string& MitCrdPst
			, const string& MitCrdMdl
			, const string& MitCrdCar
			, const string& MitCrdDlg
			, const string& MitCrdPnl
			, const string& MitCrdQry
			, const string& MitCrdQco
			, const string& MitCrdQmd
			, const string& MitCrdCon
			, const string& MitCrdOpk
			, const string& MitCrdOpx
			, const string& MitCrdJob
			, const string& MitCrdSge
			, const string& MitCrdMtd
			, const string& MitCrdBlk
			, const string& MitCrdCal
			, const string& MitCrdCmp
			, const string& MitCrdRls
			, const string& MitCrdVis
			, const string& MitCrdSht
			, const string& MitCrdBox
			, const string& MitCrdApp
			, const string& MitCrdRtj
			, const string& MitCrdEvt
			, const string& MitCrdSeq
			, const string& MitCrdSte
			, const string& MitCrdUtl
			, const string& MitAppMlc
			, const string& MitAppLoi
		) :
			Block()
			, MitAppAbt(MitAppAbt)
			, MrlAppHlp(MrlAppHlp)
			, MitSesSps(MitSesSps)
			, MitSesTrm(MitSesTrm)
			, MitCrdUsg(MitCrdUsg)
			, MitCrdUsr(MitCrdUsr)
			, MitCrdPrs(MitCrdPrs)
			, MitCrdFil(MitCrdFil)
			, MitCrdLoc(MitCrdLoc)
			, MitCrdTag(MitCrdTag)
			, MitCrdCtp(MitCrdCtp)
			, MitCrdMch(MitCrdMch)
			, MitCrdLib(MitCrdLib)
			, MitCrdPrj(MitCrdPrj)
			, MitCrdVer(MitCrdVer)
			, MitCrdCap(MitCrdCap)
			, MitCrdErr(MitCrdErr)
			, MitCrdTbl(MitCrdTbl)
			, MitCrdTco(MitCrdTco)
			, MitCrdSbs(MitCrdSbs)
			, MitCrdRel(MitCrdRel)
			, MitCrdVec(MitCrdVec)
			, MitCrdVit(MitCrdVit)
			, MitCrdChk(MitCrdChk)
			, MitCrdStb(MitCrdStb)
			, MitCrdIex(MitCrdIex)
			, MitCrdIme(MitCrdIme)
			, MitCrdPst(MitCrdPst)
			, MitCrdMdl(MitCrdMdl)
			, MitCrdCar(MitCrdCar)
			, MitCrdDlg(MitCrdDlg)
			, MitCrdPnl(MitCrdPnl)
			, MitCrdQry(MitCrdQry)
			, MitCrdQco(MitCrdQco)
			, MitCrdQmd(MitCrdQmd)
			, MitCrdCon(MitCrdCon)
			, MitCrdOpk(MitCrdOpk)
			, MitCrdOpx(MitCrdOpx)
			, MitCrdJob(MitCrdJob)
			, MitCrdSge(MitCrdSge)
			, MitCrdMtd(MitCrdMtd)
			, MitCrdBlk(MitCrdBlk)
			, MitCrdCal(MitCrdCal)
			, MitCrdCmp(MitCrdCmp)
			, MitCrdRls(MitCrdRls)
			, MitCrdVis(MitCrdVis)
			, MitCrdSht(MitCrdSht)
			, MitCrdBox(MitCrdBox)
			, MitCrdApp(MitCrdApp)
			, MitCrdRtj(MitCrdRtj)
			, MitCrdEvt(MitCrdEvt)
			, MitCrdSeq(MitCrdSeq)
			, MitCrdSte(MitCrdSte)
			, MitCrdUtl(MitCrdUtl)
			, MitAppMlc(MitAppMlc)
			, MitAppLoi(MitAppLoi)
		{
	mask = {MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDLOC, MITCRDTAG, MITCRDCTP, MITCRDMCH, MITCRDLIB, MITCRDPRJ, MITCRDVER, MITCRDCAP, MITCRDERR, MITCRDTBL, MITCRDTCO, MITCRDSBS, MITCRDREL, MITCRDVEC, MITCRDVIT, MITCRDCHK, MITCRDSTB, MITCRDIEX, MITCRDIME, MITCRDPST, MITCRDMDL, MITCRDCAR, MITCRDDLG, MITCRDPNL, MITCRDQRY, MITCRDQCO, MITCRDQMD, MITCRDCON, MITCRDOPK, MITCRDOPX, MITCRDJOB, MITCRDSGE, MITCRDMTD, MITCRDBLK, MITCRDCAL, MITCRDCMP, MITCRDRLS, MITCRDVIS, MITCRDSHT, MITCRDBOX, MITCRDAPP, MITCRDRTJ, MITCRDEVT, MITCRDSEQ, MITCRDSTE, MITCRDUTL, MITAPPMLC, MITAPPLOI};
};

bool CrdWznmNav::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNav");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNav";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppAbt", MitAppAbt)) add(MITAPPABT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", MrlAppHlp)) add(MRLAPPHLP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesSps", MitSesSps)) add(MITSESSPS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitSesTrm", MitSesTrm)) add(MITSESTRM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", MitCrdUsg)) add(MITCRDUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", MitCrdUsr)) add(MITCRDUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", MitCrdPrs)) add(MITCRDPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdFil", MitCrdFil)) add(MITCRDFIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLoc", MitCrdLoc)) add(MITCRDLOC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTag", MitCrdTag)) add(MITCRDTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCtp", MitCrdCtp)) add(MITCRDCTP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdMch", MitCrdMch)) add(MITCRDMCH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdLib", MitCrdLib)) add(MITCRDLIB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPrj", MitCrdPrj)) add(MITCRDPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdVer", MitCrdVer)) add(MITCRDVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCap", MitCrdCap)) add(MITCRDCAP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdErr", MitCrdErr)) add(MITCRDERR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTbl", MitCrdTbl)) add(MITCRDTBL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdTco", MitCrdTco)) add(MITCRDTCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSbs", MitCrdSbs)) add(MITCRDSBS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdRel", MitCrdRel)) add(MITCRDREL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdVec", MitCrdVec)) add(MITCRDVEC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdVit", MitCrdVit)) add(MITCRDVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdChk", MitCrdChk)) add(MITCRDCHK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdStb", MitCrdStb)) add(MITCRDSTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIex", MitCrdIex)) add(MITCRDIEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdIme", MitCrdIme)) add(MITCRDIME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPst", MitCrdPst)) add(MITCRDPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdMdl", MitCrdMdl)) add(MITCRDMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCar", MitCrdCar)) add(MITCRDCAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdDlg", MitCrdDlg)) add(MITCRDDLG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdPnl", MitCrdPnl)) add(MITCRDPNL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdQry", MitCrdQry)) add(MITCRDQRY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdQco", MitCrdQco)) add(MITCRDQCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdQmd", MitCrdQmd)) add(MITCRDQMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCon", MitCrdCon)) add(MITCRDCON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdOpk", MitCrdOpk)) add(MITCRDOPK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdOpx", MitCrdOpx)) add(MITCRDOPX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdJob", MitCrdJob)) add(MITCRDJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSge", MitCrdSge)) add(MITCRDSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdMtd", MitCrdMtd)) add(MITCRDMTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdBlk", MitCrdBlk)) add(MITCRDBLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCal", MitCrdCal)) add(MITCRDCAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdCmp", MitCrdCmp)) add(MITCRDCMP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdRls", MitCrdRls)) add(MITCRDRLS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdVis", MitCrdVis)) add(MITCRDVIS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSht", MitCrdSht)) add(MITCRDSHT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdBox", MitCrdBox)) add(MITCRDBOX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdApp", MitCrdApp)) add(MITCRDAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdRtj", MitCrdRtj)) add(MITCRDRTJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdEvt", MitCrdEvt)) add(MITCRDEVT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSeq", MitCrdSeq)) add(MITCRDSEQ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdSte", MitCrdSte)) add(MITCRDSTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitCrdUtl", MitCrdUtl)) add(MITCRDUTL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppMlc", MitAppMlc)) add(MITAPPMLC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MitAppLoi", MitAppLoi)) add(MITAPPLOI);
	};

	return basefound;
};

/******************************************************************************
 class CrdWznmNav::DpchAppDo
 ******************************************************************************/

CrdWznmNav::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string CrdWznmNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmNav::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmNav::DpchEngData
 ******************************************************************************/

CrdWznmNav::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVDATA)
		{
	feedFSge.tag = "FeedFSge";
};

string CrdWznmNav::DpchEngData::getSrefsMask() {
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

void CrdWznmNav::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavData");
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
