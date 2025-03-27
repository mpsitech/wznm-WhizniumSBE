/**
	* \file CrdWznmNav_blks.cpp
	* job handler for job CrdWznmNav (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void CrdWznmNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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

void CrdWznmNav::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxSesSes1"] = MtxSesSes1;
	me["MtxSesSes2"] = MtxSesSes2;
	me["MtxSesSes3"] = MtxSesSes3;
};

void CrdWznmNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
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

void CrdWznmNav::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVReqitmode
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVReqitmode"] = VecWznmVReqitmode::getSref(ixWznmVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = (Json::Value::UInt) widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdonePre"] = initdonePre;
	me["initdoneAdmin"] = initdoneAdmin;
	me["initdoneGlobal"] = initdoneGlobal;
	me["initdoneProject"] = initdoneProject;
	me["initdoneDbstr"] = initdoneDbstr;
	me["initdoneUix"] = initdoneUix;
	me["initdoneComp"] = initdoneComp;
	me["initdoneJob"] = initdoneJob;
	me["initdoneDeploy"] = initdoneDeploy;
	me["initdoneVisual"] = initdoneVisual;
	me["initdoneAppdev"] = initdoneAppdev;
	me["initdoneAuxfct"] = initdoneAuxfct;
};

void CrdWznmNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVReqitmode
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVReqitmode", VecWznmVReqitmode::getSref(ixWznmVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdonePre", initdonePre);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneGlobal", initdoneGlobal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneProject", initdoneProject);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDbstr", initdoneDbstr);
		writeBoolAttr(wr, itemtag, "sref", "initdoneUix", initdoneUix);
		writeBoolAttr(wr, itemtag, "sref", "initdoneComp", initdoneComp);
		writeBoolAttr(wr, itemtag, "sref", "initdoneJob", initdoneJob);
		writeBoolAttr(wr, itemtag, "sref", "initdoneDeploy", initdoneDeploy);
		writeBoolAttr(wr, itemtag, "sref", "initdoneVisual", initdoneVisual);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAppdev", initdoneAppdev);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAuxfct", initdoneAuxfct);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmNav::StatShr
 ******************************************************************************/

CrdWznmNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefDlgmnglic
			, const ubigint jrefHeadbar
			, const ubigint jrefPre
			, const bool pnlpreAvail
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefGlobal
			, const bool pnlglobalAvail
			, const ubigint jrefProject
			, const bool pnlprojectAvail
			, const ubigint jrefDbstr
			, const bool pnldbstrAvail
			, const ubigint jrefUix
			, const bool pnluixAvail
			, const ubigint jrefComp
			, const bool pnlcompAvail
			, const ubigint jrefJob
			, const bool pnljobAvail
			, const ubigint jrefDeploy
			, const bool pnldeployAvail
			, const ubigint jrefVisual
			, const bool pnlvisualAvail
			, const ubigint jrefAppdev
			, const bool pnlappdevAvail
			, const ubigint jrefAuxfct
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
			, jrefDlgloaini(jrefDlgloaini)
			, jrefDlgmnglic(jrefDlgmnglic)
			, jrefHeadbar(jrefHeadbar)
			, jrefPre(jrefPre)
			, pnlpreAvail(pnlpreAvail)
			, jrefAdmin(jrefAdmin)
			, pnladminAvail(pnladminAvail)
			, jrefGlobal(jrefGlobal)
			, pnlglobalAvail(pnlglobalAvail)
			, jrefProject(jrefProject)
			, pnlprojectAvail(pnlprojectAvail)
			, jrefDbstr(jrefDbstr)
			, pnldbstrAvail(pnldbstrAvail)
			, jrefUix(jrefUix)
			, pnluixAvail(pnluixAvail)
			, jrefComp(jrefComp)
			, pnlcompAvail(pnlcompAvail)
			, jrefJob(jrefJob)
			, pnljobAvail(pnljobAvail)
			, jrefDeploy(jrefDeploy)
			, pnldeployAvail(pnldeployAvail)
			, jrefVisual(jrefVisual)
			, pnlvisualAvail(pnlvisualAvail)
			, jrefAppdev(jrefAppdev)
			, pnlappdevAvail(pnlappdevAvail)
			, jrefAuxfct(jrefAuxfct)
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
	mask = {JREFDLGLOAINI, JREFDLGMNGLIC, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFGLOBAL, PNLGLOBALAVAIL, JREFPROJECT, PNLPROJECTAVAIL, JREFDBSTR, PNLDBSTRAVAIL, JREFUIX, PNLUIXAVAIL, JREFCOMP, PNLCOMPAVAIL, JREFJOB, PNLJOBAVAIL, JREFDEPLOY, PNLDEPLOYAVAIL, JREFVISUAL, PNLVISUALAVAIL, JREFAPPDEV, PNLAPPDEVAVAIL, JREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDLOCAVAIL, MITCRDTAGAVAIL, MITCRDCTPAVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDCAPAVAIL, MITCRDCAPACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MSPCRD4AVAIL, MITCRDTBLAVAIL, MITCRDTBLACTIVE, MITCRDTCOAVAIL, MITCRDTCOACTIVE, MITCRDSBSAVAIL, MITCRDSBSACTIVE, MITCRDRELAVAIL, MITCRDRELACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDVITAVAIL, MITCRDVITACTIVE, MITCRDCHKAVAIL, MITCRDCHKACTIVE, MITCRDSTBAVAIL, MITCRDSTBACTIVE, MITCRDIEXAVAIL, MITCRDIEXACTIVE, MITCRDIMEAVAIL, MITCRDIMEACTIVE, MSPCRD5AVAIL, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDMDLAVAIL, MITCRDMDLACTIVE, MITCRDCARAVAIL, MITCRDCARACTIVE, MITCRDDLGAVAIL, MITCRDDLGACTIVE, MITCRDPNLAVAIL, MITCRDPNLACTIVE, MITCRDQRYAVAIL, MITCRDQRYACTIVE, MITCRDQCOAVAIL, MITCRDQCOACTIVE, MITCRDQMDAVAIL, MITCRDQMDACTIVE, MITCRDCONAVAIL, MITCRDCONACTIVE, MSPCRD6AVAIL, MITCRDOPKAVAIL, MITCRDOPKACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MSPCRD7AVAIL, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDSGEAVAIL, MITCRDSGEACTIVE, MITCRDMTDAVAIL, MITCRDMTDACTIVE, MITCRDBLKAVAIL, MITCRDBLKACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MSPCRD8AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD9AVAIL, MITCRDVISAVAIL, MITCRDSHTAVAIL, MITCRDSHTACTIVE, MITCRDBOXAVAIL, MITCRDBOXACTIVE, MSPCRD10AVAIL, MITCRDAPPAVAIL, MITCRDRTJAVAIL, MITCRDRTJACTIVE, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDSEQAVAIL, MITCRDSEQACTIVE, MITCRDSTEAVAIL, MITCRDSTEACTIVE, MSPCRD11AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
};

void CrdWznmNav::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgloaini"] = Scr::scramble(jrefDlgloaini);
	me["scrJrefDlgmnglic"] = Scr::scramble(jrefDlgmnglic);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefPre"] = Scr::scramble(jrefPre);
	me["pnlpreAvail"] = pnlpreAvail;
	me["scrJrefAdmin"] = Scr::scramble(jrefAdmin);
	me["pnladminAvail"] = pnladminAvail;
	me["scrJrefGlobal"] = Scr::scramble(jrefGlobal);
	me["pnlglobalAvail"] = pnlglobalAvail;
	me["scrJrefProject"] = Scr::scramble(jrefProject);
	me["pnlprojectAvail"] = pnlprojectAvail;
	me["scrJrefDbstr"] = Scr::scramble(jrefDbstr);
	me["pnldbstrAvail"] = pnldbstrAvail;
	me["scrJrefUix"] = Scr::scramble(jrefUix);
	me["pnluixAvail"] = pnluixAvail;
	me["scrJrefComp"] = Scr::scramble(jrefComp);
	me["pnlcompAvail"] = pnlcompAvail;
	me["scrJrefJob"] = Scr::scramble(jrefJob);
	me["pnljobAvail"] = pnljobAvail;
	me["scrJrefDeploy"] = Scr::scramble(jrefDeploy);
	me["pnldeployAvail"] = pnldeployAvail;
	me["scrJrefVisual"] = Scr::scramble(jrefVisual);
	me["pnlvisualAvail"] = pnlvisualAvail;
	me["scrJrefAppdev"] = Scr::scramble(jrefAppdev);
	me["pnlappdevAvail"] = pnlappdevAvail;
	me["scrJrefAuxfct"] = Scr::scramble(jrefAuxfct);
	me["pnlauxfctAvail"] = pnlauxfctAvail;
	me["MitSesSpsAvail"] = MitSesSpsAvail;
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdUsgAvail"] = MitCrdUsgAvail;
	me["MitCrdUsrAvail"] = MitCrdUsrAvail;
	me["MitCrdPrsAvail"] = MitCrdPrsAvail;
	me["MitCrdFilAvail"] = MitCrdFilAvail;
	me["MspCrd2Avail"] = MspCrd2Avail;
	me["MitCrdLocAvail"] = MitCrdLocAvail;
	me["MitCrdTagAvail"] = MitCrdTagAvail;
	me["MitCrdCtpAvail"] = MitCrdCtpAvail;
	me["MitCrdMchAvail"] = MitCrdMchAvail;
	me["MitCrdLibAvail"] = MitCrdLibAvail;
	me["MspCrd3Avail"] = MspCrd3Avail;
	me["MitCrdPrjAvail"] = MitCrdPrjAvail;
	me["MitCrdVerAvail"] = MitCrdVerAvail;
	me["MitCrdCapAvail"] = MitCrdCapAvail;
	me["MitCrdCapActive"] = MitCrdCapActive;
	me["MitCrdErrAvail"] = MitCrdErrAvail;
	me["MitCrdErrActive"] = MitCrdErrActive;
	me["MspCrd4Avail"] = MspCrd4Avail;
	me["MitCrdTblAvail"] = MitCrdTblAvail;
	me["MitCrdTblActive"] = MitCrdTblActive;
	me["MitCrdTcoAvail"] = MitCrdTcoAvail;
	me["MitCrdTcoActive"] = MitCrdTcoActive;
	me["MitCrdSbsAvail"] = MitCrdSbsAvail;
	me["MitCrdSbsActive"] = MitCrdSbsActive;
	me["MitCrdRelAvail"] = MitCrdRelAvail;
	me["MitCrdRelActive"] = MitCrdRelActive;
	me["MitCrdVecAvail"] = MitCrdVecAvail;
	me["MitCrdVecActive"] = MitCrdVecActive;
	me["MitCrdVitAvail"] = MitCrdVitAvail;
	me["MitCrdVitActive"] = MitCrdVitActive;
	me["MitCrdChkAvail"] = MitCrdChkAvail;
	me["MitCrdChkActive"] = MitCrdChkActive;
	me["MitCrdStbAvail"] = MitCrdStbAvail;
	me["MitCrdStbActive"] = MitCrdStbActive;
	me["MitCrdIexAvail"] = MitCrdIexAvail;
	me["MitCrdIexActive"] = MitCrdIexActive;
	me["MitCrdImeAvail"] = MitCrdImeAvail;
	me["MitCrdImeActive"] = MitCrdImeActive;
	me["MspCrd5Avail"] = MspCrd5Avail;
	me["MitCrdPstAvail"] = MitCrdPstAvail;
	me["MitCrdPstActive"] = MitCrdPstActive;
	me["MitCrdMdlAvail"] = MitCrdMdlAvail;
	me["MitCrdMdlActive"] = MitCrdMdlActive;
	me["MitCrdCarAvail"] = MitCrdCarAvail;
	me["MitCrdCarActive"] = MitCrdCarActive;
	me["MitCrdDlgAvail"] = MitCrdDlgAvail;
	me["MitCrdDlgActive"] = MitCrdDlgActive;
	me["MitCrdPnlAvail"] = MitCrdPnlAvail;
	me["MitCrdPnlActive"] = MitCrdPnlActive;
	me["MitCrdQryAvail"] = MitCrdQryAvail;
	me["MitCrdQryActive"] = MitCrdQryActive;
	me["MitCrdQcoAvail"] = MitCrdQcoAvail;
	me["MitCrdQcoActive"] = MitCrdQcoActive;
	me["MitCrdQmdAvail"] = MitCrdQmdAvail;
	me["MitCrdQmdActive"] = MitCrdQmdActive;
	me["MitCrdConAvail"] = MitCrdConAvail;
	me["MitCrdConActive"] = MitCrdConActive;
	me["MspCrd6Avail"] = MspCrd6Avail;
	me["MitCrdOpkAvail"] = MitCrdOpkAvail;
	me["MitCrdOpkActive"] = MitCrdOpkActive;
	me["MitCrdOpxAvail"] = MitCrdOpxAvail;
	me["MitCrdOpxActive"] = MitCrdOpxActive;
	me["MspCrd7Avail"] = MspCrd7Avail;
	me["MitCrdJobAvail"] = MitCrdJobAvail;
	me["MitCrdJobActive"] = MitCrdJobActive;
	me["MitCrdSgeAvail"] = MitCrdSgeAvail;
	me["MitCrdSgeActive"] = MitCrdSgeActive;
	me["MitCrdMtdAvail"] = MitCrdMtdAvail;
	me["MitCrdMtdActive"] = MitCrdMtdActive;
	me["MitCrdBlkAvail"] = MitCrdBlkAvail;
	me["MitCrdBlkActive"] = MitCrdBlkActive;
	me["MitCrdCalAvail"] = MitCrdCalAvail;
	me["MitCrdCalActive"] = MitCrdCalActive;
	me["MspCrd8Avail"] = MspCrd8Avail;
	me["MitCrdCmpAvail"] = MitCrdCmpAvail;
	me["MitCrdRlsAvail"] = MitCrdRlsAvail;
	me["MitCrdRlsActive"] = MitCrdRlsActive;
	me["MspCrd9Avail"] = MspCrd9Avail;
	me["MitCrdVisAvail"] = MitCrdVisAvail;
	me["MitCrdShtAvail"] = MitCrdShtAvail;
	me["MitCrdShtActive"] = MitCrdShtActive;
	me["MitCrdBoxAvail"] = MitCrdBoxAvail;
	me["MitCrdBoxActive"] = MitCrdBoxActive;
	me["MspCrd10Avail"] = MspCrd10Avail;
	me["MitCrdAppAvail"] = MitCrdAppAvail;
	me["MitCrdRtjAvail"] = MitCrdRtjAvail;
	me["MitCrdRtjActive"] = MitCrdRtjActive;
	me["MitCrdEvtAvail"] = MitCrdEvtAvail;
	me["MitCrdEvtActive"] = MitCrdEvtActive;
	me["MitCrdSeqAvail"] = MitCrdSeqAvail;
	me["MitCrdSeqActive"] = MitCrdSeqActive;
	me["MitCrdSteAvail"] = MitCrdSteAvail;
	me["MitCrdSteActive"] = MitCrdSteActive;
	me["MspCrd11Avail"] = MspCrd11Avail;
	me["MitCrdUtlAvail"] = MitCrdUtlAvail;
	me["MspApp2Avail"] = MspApp2Avail;
	me["MitAppMlcAvail"] = MitAppMlcAvail;
	me["MitAppLoiAvail"] = MitAppLoiAvail;
};

void CrdWznmNav::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgmnglic", Scr::scramble(jrefDlgmnglic));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPre", Scr::scramble(jrefPre));
		writeBoolAttr(wr, itemtag, "sref", "pnlpreAvail", pnlpreAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefGlobal", Scr::scramble(jrefGlobal));
		writeBoolAttr(wr, itemtag, "sref", "pnlglobalAvail", pnlglobalAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefProject", Scr::scramble(jrefProject));
		writeBoolAttr(wr, itemtag, "sref", "pnlprojectAvail", pnlprojectAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDbstr", Scr::scramble(jrefDbstr));
		writeBoolAttr(wr, itemtag, "sref", "pnldbstrAvail", pnldbstrAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefUix", Scr::scramble(jrefUix));
		writeBoolAttr(wr, itemtag, "sref", "pnluixAvail", pnluixAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefComp", Scr::scramble(jrefComp));
		writeBoolAttr(wr, itemtag, "sref", "pnlcompAvail", pnlcompAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefJob", Scr::scramble(jrefJob));
		writeBoolAttr(wr, itemtag, "sref", "pnljobAvail", pnljobAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefDeploy", Scr::scramble(jrefDeploy));
		writeBoolAttr(wr, itemtag, "sref", "pnldeployAvail", pnldeployAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefVisual", Scr::scramble(jrefVisual));
		writeBoolAttr(wr, itemtag, "sref", "pnlvisualAvail", pnlvisualAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAppdev", Scr::scramble(jrefAppdev));
		writeBoolAttr(wr, itemtag, "sref", "pnlappdevAvail", pnlappdevAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAuxfct", Scr::scramble(jrefAuxfct));
		writeBoolAttr(wr, itemtag, "sref", "pnlauxfctAvail", pnlauxfctAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitSesSpsAvail", MitSesSpsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFilAvail", MitCrdFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLocAvail", MitCrdLocAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTagAvail", MitCrdTagAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCtpAvail", MitCrdCtpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMchAvail", MitCrdMchAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLibAvail", MitCrdLibAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrjAvail", MitCrdPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVerAvail", MitCrdVerAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCapAvail", MitCrdCapAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCapActive", MitCrdCapActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdErrAvail", MitCrdErrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdErrActive", MitCrdErrActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd4Avail", MspCrd4Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTblAvail", MitCrdTblAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTblActive", MitCrdTblActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTcoAvail", MitCrdTcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTcoActive", MitCrdTcoActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSbsAvail", MitCrdSbsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSbsActive", MitCrdSbsActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRelAvail", MitCrdRelAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRelActive", MitCrdRelActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVecAvail", MitCrdVecAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVecActive", MitCrdVecActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVitAvail", MitCrdVitAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVitActive", MitCrdVitActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdChkAvail", MitCrdChkAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdChkActive", MitCrdChkActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdStbAvail", MitCrdStbAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdStbActive", MitCrdStbActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIexAvail", MitCrdIexAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIexActive", MitCrdIexActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdImeAvail", MitCrdImeAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdImeActive", MitCrdImeActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd5Avail", MspCrd5Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPstAvail", MitCrdPstAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPstActive", MitCrdPstActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMdlAvail", MitCrdMdlAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMdlActive", MitCrdMdlActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCarAvail", MitCrdCarAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCarActive", MitCrdCarActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDlgAvail", MitCrdDlgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdDlgActive", MitCrdDlgActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPnlAvail", MitCrdPnlAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPnlActive", MitCrdPnlActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdQryAvail", MitCrdQryAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdQryActive", MitCrdQryActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdQcoAvail", MitCrdQcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdQcoActive", MitCrdQcoActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdQmdAvail", MitCrdQmdAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdQmdActive", MitCrdQmdActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdConAvail", MitCrdConAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdConActive", MitCrdConActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd6Avail", MspCrd6Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOpkAvail", MitCrdOpkAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOpkActive", MitCrdOpkActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOpxAvail", MitCrdOpxAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOpxActive", MitCrdOpxActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd7Avail", MspCrd7Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdJobAvail", MitCrdJobAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdJobActive", MitCrdJobActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSgeAvail", MitCrdSgeAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSgeActive", MitCrdSgeActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMtdAvail", MitCrdMtdAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdMtdActive", MitCrdMtdActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBlkAvail", MitCrdBlkAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBlkActive", MitCrdBlkActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCalAvail", MitCrdCalAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCalActive", MitCrdCalActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd8Avail", MspCrd8Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdCmpAvail", MitCrdCmpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRlsAvail", MitCrdRlsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRlsActive", MitCrdRlsActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd9Avail", MspCrd9Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdVisAvail", MitCrdVisAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdShtAvail", MitCrdShtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdShtActive", MitCrdShtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBoxAvail", MitCrdBoxAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdBoxActive", MitCrdBoxActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd10Avail", MspCrd10Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdAppAvail", MitCrdAppAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRtjAvail", MitCrdRtjAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRtjActive", MitCrdRtjActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdEvtAvail", MitCrdEvtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdEvtActive", MitCrdEvtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSeqAvail", MitCrdSeqAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSeqActive", MitCrdSeqActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSteAvail", MitCrdSteAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdSteActive", MitCrdSteActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd11Avail", MspCrd11Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUtlAvail", MitCrdUtlAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppMlcAvail", MitAppMlcAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefDlgmnglic == comp->jrefDlgmnglic) insert(items, JREFDLGMNGLIC);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefPre == comp->jrefPre) insert(items, JREFPRE);
	if (pnlpreAvail == comp->pnlpreAvail) insert(items, PNLPREAVAIL);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefGlobal == comp->jrefGlobal) insert(items, JREFGLOBAL);
	if (pnlglobalAvail == comp->pnlglobalAvail) insert(items, PNLGLOBALAVAIL);
	if (jrefProject == comp->jrefProject) insert(items, JREFPROJECT);
	if (pnlprojectAvail == comp->pnlprojectAvail) insert(items, PNLPROJECTAVAIL);
	if (jrefDbstr == comp->jrefDbstr) insert(items, JREFDBSTR);
	if (pnldbstrAvail == comp->pnldbstrAvail) insert(items, PNLDBSTRAVAIL);
	if (jrefUix == comp->jrefUix) insert(items, JREFUIX);
	if (pnluixAvail == comp->pnluixAvail) insert(items, PNLUIXAVAIL);
	if (jrefComp == comp->jrefComp) insert(items, JREFCOMP);
	if (pnlcompAvail == comp->pnlcompAvail) insert(items, PNLCOMPAVAIL);
	if (jrefJob == comp->jrefJob) insert(items, JREFJOB);
	if (pnljobAvail == comp->pnljobAvail) insert(items, PNLJOBAVAIL);
	if (jrefDeploy == comp->jrefDeploy) insert(items, JREFDEPLOY);
	if (pnldeployAvail == comp->pnldeployAvail) insert(items, PNLDEPLOYAVAIL);
	if (jrefVisual == comp->jrefVisual) insert(items, JREFVISUAL);
	if (pnlvisualAvail == comp->pnlvisualAvail) insert(items, PNLVISUALAVAIL);
	if (jrefAppdev == comp->jrefAppdev) insert(items, JREFAPPDEV);
	if (pnlappdevAvail == comp->pnlappdevAvail) insert(items, PNLAPPDEVAVAIL);
	if (jrefAuxfct == comp->jrefAuxfct) insert(items, JREFAUXFCT);
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

	diffitems = {JREFDLGLOAINI, JREFDLGMNGLIC, JREFHEADBAR, JREFPRE, PNLPREAVAIL, JREFADMIN, PNLADMINAVAIL, JREFGLOBAL, PNLGLOBALAVAIL, JREFPROJECT, PNLPROJECTAVAIL, JREFDBSTR, PNLDBSTRAVAIL, JREFUIX, PNLUIXAVAIL, JREFCOMP, PNLCOMPAVAIL, JREFJOB, PNLJOBAVAIL, JREFDEPLOY, PNLDEPLOYAVAIL, JREFVISUAL, PNLVISUALAVAIL, JREFAPPDEV, PNLAPPDEVAVAIL, JREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDLOCAVAIL, MITCRDTAGAVAIL, MITCRDCTPAVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDCAPAVAIL, MITCRDCAPACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MSPCRD4AVAIL, MITCRDTBLAVAIL, MITCRDTBLACTIVE, MITCRDTCOAVAIL, MITCRDTCOACTIVE, MITCRDSBSAVAIL, MITCRDSBSACTIVE, MITCRDRELAVAIL, MITCRDRELACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDVITAVAIL, MITCRDVITACTIVE, MITCRDCHKAVAIL, MITCRDCHKACTIVE, MITCRDSTBAVAIL, MITCRDSTBACTIVE, MITCRDIEXAVAIL, MITCRDIEXACTIVE, MITCRDIMEAVAIL, MITCRDIMEACTIVE, MSPCRD5AVAIL, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDMDLAVAIL, MITCRDMDLACTIVE, MITCRDCARAVAIL, MITCRDCARACTIVE, MITCRDDLGAVAIL, MITCRDDLGACTIVE, MITCRDPNLAVAIL, MITCRDPNLACTIVE, MITCRDQRYAVAIL, MITCRDQRYACTIVE, MITCRDQCOAVAIL, MITCRDQCOACTIVE, MITCRDQMDAVAIL, MITCRDQMDACTIVE, MITCRDCONAVAIL, MITCRDCONACTIVE, MSPCRD6AVAIL, MITCRDOPKAVAIL, MITCRDOPKACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MSPCRD7AVAIL, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDSGEAVAIL, MITCRDSGEACTIVE, MITCRDMTDAVAIL, MITCRDMTDACTIVE, MITCRDBLKAVAIL, MITCRDBLKACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MSPCRD8AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD9AVAIL, MITCRDVISAVAIL, MITCRDSHTAVAIL, MITCRDSHTACTIVE, MITCRDBOXAVAIL, MITCRDBOXACTIVE, MSPCRD10AVAIL, MITCRDAPPAVAIL, MITCRDRTJAVAIL, MITCRDRTJACTIVE, MITCRDEVTAVAIL, MITCRDEVTACTIVE, MITCRDSEQAVAIL, MITCRDSEQACTIVE, MITCRDSTEAVAIL, MITCRDSTEACTIVE, MSPCRD11AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmNav::Tag
 ******************************************************************************/

void CrdWznmNav::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmNav";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["MitCrdUsg"] = "User groups ...";
		me["MitCrdUsr"] = "Users ...";
		me["MitCrdPrs"] = "Persons ...";
		me["MitCrdFil"] = "Files ...";
		me["MitCrdLoc"] = "Locales ...";
		me["MitCrdTag"] = "Tags ...";
		me["MitCrdCtp"] = "Capability templates ...";
		me["MitCrdMch"] = "Machines ...";
		me["MitCrdLib"] = "Libraries ...";
		me["MitCrdPrj"] = "Projects ...";
		me["MitCrdVer"] = "Versions ...";
		me["MitCrdCap"] = "Capabilities ...";
		me["MitCrdErr"] = "Errors ...";
		me["MitCrdTbl"] = "Tables ...";
		me["MitCrdTco"] = "Table columns ...";
		me["MitCrdSbs"] = "Subsets ...";
		me["MitCrdRel"] = "Relations ...";
		me["MitCrdVec"] = "Vectors ...";
		me["MitCrdVit"] = "Vector items ...";
		me["MitCrdChk"] = "Feature checks ...";
		me["MitCrdStb"] = "Stubs ...";
		me["MitCrdIex"] = "Import/export complexes ...";
		me["MitCrdIme"] = "Import/exports ...";
		me["MitCrdPst"] = "Presettings ...";
		me["MitCrdMdl"] = "Modules ...";
		me["MitCrdCar"] = "Cards ...";
		me["MitCrdDlg"] = "Dialogs ...";
		me["MitCrdPnl"] = "Panels ...";
		me["MitCrdQry"] = "Queries ...";
		me["MitCrdQco"] = "Query columns ...";
		me["MitCrdQmd"] = "Query modifiers ...";
		me["MitCrdCon"] = "Controls ...";
		me["MitCrdOpk"] = "Operation packs ...";
		me["MitCrdOpx"] = "Operations ...";
		me["MitCrdJob"] = "Jobs ...";
		me["MitCrdSge"] = "Stages ...";
		me["MitCrdMtd"] = "Methods ...";
		me["MitCrdBlk"] = "Blocks ...";
		me["MitCrdCal"] = "Calls ...";
		me["MitCrdCmp"] = "Components ...";
		me["MitCrdRls"] = "Releases ...";
		me["MitCrdVis"] = "Visualizations ...";
		me["MitCrdSht"] = "Sheets ...";
		me["MitCrdBox"] = "Boxes ...";
		me["MitCrdApp"] = "Accessor apps ...";
		me["MitCrdRtj"] = "Run-time jobs ...";
		me["MitCrdEvt"] = "Events ...";
		me["MitCrdSeq"] = "Sequences ...";
		me["MitCrdSte"] = "States ...";
		me["MitCrdUtl"] = "Utilities ...";
		me["MitAppMlc"] = "Manage licenses ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...";
	me["MitSesSps"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::SUSPSESS, ixWznmVLocale));
	me["MitSesTrm"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CLSESS, ixWznmVLocale));
	me["MitAppLoi"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::LOAINI, ixWznmVLocale)) + " ...";
};

void CrdWznmNav::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Files ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLoc", "Locales ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTag", "Tags ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCtp", "Capability templates ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMch", "Machines ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLib", "Libraries ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrj", "Projects ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdVer", "Versions ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCap", "Capabilities ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdErr", "Errors ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTbl", "Tables ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTco", "Table columns ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSbs", "Subsets ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRel", "Relations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdVec", "Vectors ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdVit", "Vector items ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdChk", "Feature checks ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdStb", "Stubs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIex", "Import/export complexes ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIme", "Import/exports ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPst", "Presettings ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMdl", "Modules ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCar", "Cards ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdDlg", "Dialogs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPnl", "Panels ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdQry", "Queries ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdQco", "Query columns ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdQmd", "Query modifiers ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCon", "Controls ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOpk", "Operation packs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOpx", "Operations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdJob", "Jobs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSge", "Stages ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdMtd", "Methods ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdBlk", "Blocks ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCal", "Calls ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCmp", "Components ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRls", "Releases ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdVis", "Visualizations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSht", "Sheets ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdBox", "Boxes ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdApp", "Accessor apps ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdRtj", "Run-time jobs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdEvt", "Events ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSeq", "Sequences ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdSte", "States ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUtl", "Utilities ...");
			writeStringAttr(wr, itemtag, "sref", "MitAppMlc", "Manage licenses ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesSps", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::SUSPSESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::CLSESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::LOAINI, ixWznmVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmNav::DpchAppDo
 ******************************************************************************/

CrdWznmNav::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVDO)
		{
	ixVDo = 0;
};

string CrdWznmNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmNav::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWznmNav::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavDo");
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
 class CrdWznmNav::DpchEngData
 ******************************************************************************/

CrdWznmNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWznmNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmNav::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdWznmNav::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmNavData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void CrdWznmNav::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
