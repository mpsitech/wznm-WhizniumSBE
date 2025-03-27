/**
	* \file CrdWznmVer_blks.cpp
	* job handler for job CrdWznmVer (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void CrdWznmVer::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
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
			, numFSge(numFSge)
			, MrlAppHlp(MrlAppHlp)
			, MtxCrdVer(MtxCrdVer)
		{
	mask = {NUMFSGE, MRLAPPHLP, MTXCRDVER};
};

void CrdWznmVer::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFSge"] = (Json::Value::UInt) numFSge;
	me["MrlAppHlp"] = MrlAppHlp;
	me["MtxCrdVer"] = MtxCrdVer;
};

void CrdWznmVer::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVer";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxCrdVer", MtxCrdVer);
	xmlTextWriterEndElement(wr);
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

void CrdWznmVer::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVReqitmode"] = VecWznmVReqitmode::getSref(ixWznmVReqitmode);
	me["latency"] = latency;
	me["shortMenu"] = shortMenu;
	me["widthMenu"] = (Json::Value::UInt) widthMenu;
	me["initdoneHeadbar"] = initdoneHeadbar;
	me["initdoneList"] = initdoneList;
	me["initdoneRec"] = initdoneRec;
};

void CrdWznmVer::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneList
			, const bool initdoneRec
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVReqitmode", VecWznmVReqitmode::getSref(ixWznmVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneList", initdoneList);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRec", initdoneRec);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmVer::StatShr
 ******************************************************************************/

CrdWznmVer::StatShr::StatShr(
			const ubigint jrefDlgbscui
			, const ubigint jrefDlgcustjob
			, const ubigint jrefDlgcustjtr
			, const ubigint jrefDlgcustui
			, const ubigint jrefDlgdbstr
			, const ubigint jrefDlgdeploy
			, const ubigint jrefDlgfinmod
			, const ubigint jrefDlggenjtr
			, const ubigint jrefDlggenui
			, const ubigint jrefDlgglobal
			, const ubigint jrefDlgimpexp
			, const ubigint jrefDlgnew
			, const ubigint jrefDlgoppack
			, const ubigint jrefDlgwrinimdl
			, const ubigint jrefHeadbar
			, const ubigint jrefList
			, const ubigint jrefRec
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
			, jrefDlgbscui(jrefDlgbscui)
			, jrefDlgcustjob(jrefDlgcustjob)
			, jrefDlgcustjtr(jrefDlgcustjtr)
			, jrefDlgcustui(jrefDlgcustui)
			, jrefDlgdbstr(jrefDlgdbstr)
			, jrefDlgdeploy(jrefDlgdeploy)
			, jrefDlgfinmod(jrefDlgfinmod)
			, jrefDlggenjtr(jrefDlggenjtr)
			, jrefDlggenui(jrefDlggenui)
			, jrefDlgglobal(jrefDlgglobal)
			, jrefDlgimpexp(jrefDlgimpexp)
			, jrefDlgnew(jrefDlgnew)
			, jrefDlgoppack(jrefDlgoppack)
			, jrefDlgwrinimdl(jrefDlgwrinimdl)
			, jrefHeadbar(jrefHeadbar)
			, jrefList(jrefList)
			, jrefRec(jrefRec)
			, MspCrd1Avail(MspCrd1Avail)
			, MitCrdNewAvail(MitCrdNewAvail)
			, MitCrdPcvAvail(MitCrdPcvAvail)
			, MitCrdPcvActive(MitCrdPcvActive)
			, MspCrd3Avail(MspCrd3Avail)
			, MitCrdIdpAvail(MitCrdIdpAvail)
			, MitCrdIdpActive(MitCrdIdpActive)
			, MitCrdIgbAvail(MitCrdIgbAvail)
			, MitCrdIgbActive(MitCrdIgbActive)
			, MspCrd4Avail(MspCrd4Avail)
			, MitCrdImdAvail(MitCrdImdAvail)
			, MitCrdImdActive(MitCrdImdActive)
			, MspCrd5Avail(MspCrd5Avail)
			, MitCrdIdbAvail(MitCrdIdbAvail)
			, MitCrdIdbActive(MitCrdIdbActive)
			, MitCrdIbuAvail(MitCrdIbuAvail)
			, MitCrdIbuActive(MitCrdIbuActive)
			, MitCrdIieAvail(MitCrdIieAvail)
			, MitCrdIieActive(MitCrdIieActive)
			, MitCrdIopAvail(MitCrdIopAvail)
			, MitCrdIopActive(MitCrdIopActive)
			, MitCrdIcjAvail(MitCrdIcjAvail)
			, MitCrdIcjActive(MitCrdIcjActive)
			, MspCrd6Avail(MspCrd6Avail)
			, MitCrdGuiAvail(MitCrdGuiAvail)
			, MitCrdGuiActive(MitCrdGuiActive)
			, MitCrdAuiAvail(MitCrdAuiAvail)
			, MitCrdAuiActive(MitCrdAuiActive)
			, MitCrdGjtAvail(MitCrdGjtAvail)
			, MitCrdGjtActive(MitCrdGjtActive)
			, MitCrdAjtAvail(MitCrdAjtAvail)
			, MitCrdAjtActive(MitCrdAjtActive)
			, MspCrd7Avail(MspCrd7Avail)
			, MitCrdFnmAvail(MitCrdFnmAvail)
			, MitCrdFnmActive(MitCrdFnmActive)
		{
	mask = {JREFDLGBSCUI, JREFDLGCUSTJOB, JREFDLGCUSTJTR, JREFDLGCUSTUI, JREFDLGDBSTR, JREFDLGDEPLOY, JREFDLGFINMOD, JREFDLGGENJTR, JREFDLGGENUI, JREFDLGGLOBAL, JREFDLGIMPEXP, JREFDLGNEW, JREFDLGOPPACK, JREFDLGWRINIMDL, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MITCRDIGBAVAIL, MITCRDIGBACTIVE, MSPCRD4AVAIL, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MSPCRD5AVAIL, MITCRDIDBAVAIL, MITCRDIDBACTIVE, MITCRDIBUAVAIL, MITCRDIBUACTIVE, MITCRDIIEAVAIL, MITCRDIIEACTIVE, MITCRDIOPAVAIL, MITCRDIOPACTIVE, MITCRDICJAVAIL, MITCRDICJACTIVE, MSPCRD6AVAIL, MITCRDGUIAVAIL, MITCRDGUIACTIVE, MITCRDAUIAVAIL, MITCRDAUIACTIVE, MITCRDGJTAVAIL, MITCRDGJTACTIVE, MITCRDAJTAVAIL, MITCRDAJTACTIVE, MSPCRD7AVAIL, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
};

void CrdWznmVer::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["scrJrefDlgbscui"] = Scr::scramble(jrefDlgbscui);
	me["scrJrefDlgcustjob"] = Scr::scramble(jrefDlgcustjob);
	me["scrJrefDlgcustjtr"] = Scr::scramble(jrefDlgcustjtr);
	me["scrJrefDlgcustui"] = Scr::scramble(jrefDlgcustui);
	me["scrJrefDlgdbstr"] = Scr::scramble(jrefDlgdbstr);
	me["scrJrefDlgdeploy"] = Scr::scramble(jrefDlgdeploy);
	me["scrJrefDlgfinmod"] = Scr::scramble(jrefDlgfinmod);
	me["scrJrefDlggenjtr"] = Scr::scramble(jrefDlggenjtr);
	me["scrJrefDlggenui"] = Scr::scramble(jrefDlggenui);
	me["scrJrefDlgglobal"] = Scr::scramble(jrefDlgglobal);
	me["scrJrefDlgimpexp"] = Scr::scramble(jrefDlgimpexp);
	me["scrJrefDlgnew"] = Scr::scramble(jrefDlgnew);
	me["scrJrefDlgoppack"] = Scr::scramble(jrefDlgoppack);
	me["scrJrefDlgwrinimdl"] = Scr::scramble(jrefDlgwrinimdl);
	me["scrJrefHeadbar"] = Scr::scramble(jrefHeadbar);
	me["scrJrefList"] = Scr::scramble(jrefList);
	me["scrJrefRec"] = Scr::scramble(jrefRec);
	me["MspCrd1Avail"] = MspCrd1Avail;
	me["MitCrdNewAvail"] = MitCrdNewAvail;
	me["MitCrdPcvAvail"] = MitCrdPcvAvail;
	me["MitCrdPcvActive"] = MitCrdPcvActive;
	me["MspCrd3Avail"] = MspCrd3Avail;
	me["MitCrdIdpAvail"] = MitCrdIdpAvail;
	me["MitCrdIdpActive"] = MitCrdIdpActive;
	me["MitCrdIgbAvail"] = MitCrdIgbAvail;
	me["MitCrdIgbActive"] = MitCrdIgbActive;
	me["MspCrd4Avail"] = MspCrd4Avail;
	me["MitCrdImdAvail"] = MitCrdImdAvail;
	me["MitCrdImdActive"] = MitCrdImdActive;
	me["MspCrd5Avail"] = MspCrd5Avail;
	me["MitCrdIdbAvail"] = MitCrdIdbAvail;
	me["MitCrdIdbActive"] = MitCrdIdbActive;
	me["MitCrdIbuAvail"] = MitCrdIbuAvail;
	me["MitCrdIbuActive"] = MitCrdIbuActive;
	me["MitCrdIieAvail"] = MitCrdIieAvail;
	me["MitCrdIieActive"] = MitCrdIieActive;
	me["MitCrdIopAvail"] = MitCrdIopAvail;
	me["MitCrdIopActive"] = MitCrdIopActive;
	me["MitCrdIcjAvail"] = MitCrdIcjAvail;
	me["MitCrdIcjActive"] = MitCrdIcjActive;
	me["MspCrd6Avail"] = MspCrd6Avail;
	me["MitCrdGuiAvail"] = MitCrdGuiAvail;
	me["MitCrdGuiActive"] = MitCrdGuiActive;
	me["MitCrdAuiAvail"] = MitCrdAuiAvail;
	me["MitCrdAuiActive"] = MitCrdAuiActive;
	me["MitCrdGjtAvail"] = MitCrdGjtAvail;
	me["MitCrdGjtActive"] = MitCrdGjtActive;
	me["MitCrdAjtAvail"] = MitCrdAjtAvail;
	me["MitCrdAjtActive"] = MitCrdAjtActive;
	me["MspCrd7Avail"] = MspCrd7Avail;
	me["MitCrdFnmAvail"] = MitCrdFnmAvail;
	me["MitCrdFnmActive"] = MitCrdFnmActive;
};

void CrdWznmVer::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVer";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgbscui", Scr::scramble(jrefDlgbscui));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgcustjob", Scr::scramble(jrefDlgcustjob));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgcustjtr", Scr::scramble(jrefDlgcustjtr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgcustui", Scr::scramble(jrefDlgcustui));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgdbstr", Scr::scramble(jrefDlgdbstr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgdeploy", Scr::scramble(jrefDlgdeploy));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgfinmod", Scr::scramble(jrefDlgfinmod));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlggenjtr", Scr::scramble(jrefDlggenjtr));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlggenui", Scr::scramble(jrefDlggenui));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgglobal", Scr::scramble(jrefDlgglobal));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgimpexp", Scr::scramble(jrefDlgimpexp));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgnew", Scr::scramble(jrefDlgnew));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgoppack", Scr::scramble(jrefDlgoppack));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgwrinimdl", Scr::scramble(jrefDlgwrinimdl));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefList", Scr::scramble(jrefList));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRec", Scr::scramble(jrefRec));
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdNewAvail", MitCrdNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPcvAvail", MitCrdPcvAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPcvActive", MitCrdPcvActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdpAvail", MitCrdIdpAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdpActive", MitCrdIdpActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIgbAvail", MitCrdIgbAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIgbActive", MitCrdIgbActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd4Avail", MspCrd4Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdImdAvail", MitCrdImdAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdImdActive", MitCrdImdActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd5Avail", MspCrd5Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdbAvail", MitCrdIdbAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIdbActive", MitCrdIdbActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIbuAvail", MitCrdIbuAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIbuActive", MitCrdIbuActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIieAvail", MitCrdIieAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIieActive", MitCrdIieActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIopAvail", MitCrdIopAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIopActive", MitCrdIopActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIcjAvail", MitCrdIcjAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdIcjActive", MitCrdIcjActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd6Avail", MspCrd6Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGuiAvail", MitCrdGuiAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGuiActive", MitCrdGuiActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdAuiAvail", MitCrdAuiAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdAuiActive", MitCrdAuiActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGjtAvail", MitCrdGjtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdGjtActive", MitCrdGjtActive);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdAjtAvail", MitCrdAjtAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdAjtActive", MitCrdAjtActive);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd7Avail", MspCrd7Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFnmAvail", MitCrdFnmAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFnmActive", MitCrdFnmActive);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdWznmVer::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgbscui == comp->jrefDlgbscui) insert(items, JREFDLGBSCUI);
	if (jrefDlgcustjob == comp->jrefDlgcustjob) insert(items, JREFDLGCUSTJOB);
	if (jrefDlgcustjtr == comp->jrefDlgcustjtr) insert(items, JREFDLGCUSTJTR);
	if (jrefDlgcustui == comp->jrefDlgcustui) insert(items, JREFDLGCUSTUI);
	if (jrefDlgdbstr == comp->jrefDlgdbstr) insert(items, JREFDLGDBSTR);
	if (jrefDlgdeploy == comp->jrefDlgdeploy) insert(items, JREFDLGDEPLOY);
	if (jrefDlgfinmod == comp->jrefDlgfinmod) insert(items, JREFDLGFINMOD);
	if (jrefDlggenjtr == comp->jrefDlggenjtr) insert(items, JREFDLGGENJTR);
	if (jrefDlggenui == comp->jrefDlggenui) insert(items, JREFDLGGENUI);
	if (jrefDlgglobal == comp->jrefDlgglobal) insert(items, JREFDLGGLOBAL);
	if (jrefDlgimpexp == comp->jrefDlgimpexp) insert(items, JREFDLGIMPEXP);
	if (jrefDlgnew == comp->jrefDlgnew) insert(items, JREFDLGNEW);
	if (jrefDlgoppack == comp->jrefDlgoppack) insert(items, JREFDLGOPPACK);
	if (jrefDlgwrinimdl == comp->jrefDlgwrinimdl) insert(items, JREFDLGWRINIMDL);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefList == comp->jrefList) insert(items, JREFLIST);
	if (jrefRec == comp->jrefRec) insert(items, JREFREC);
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

	diffitems = {JREFDLGBSCUI, JREFDLGCUSTJOB, JREFDLGCUSTJTR, JREFDLGCUSTUI, JREFDLGDBSTR, JREFDLGDEPLOY, JREFDLGFINMOD, JREFDLGGENJTR, JREFDLGGENUI, JREFDLGGLOBAL, JREFDLGIMPEXP, JREFDLGNEW, JREFDLGOPPACK, JREFDLGWRINIMDL, JREFHEADBAR, JREFLIST, JREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MITCRDIGBAVAIL, MITCRDIGBACTIVE, MSPCRD4AVAIL, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MSPCRD5AVAIL, MITCRDIDBAVAIL, MITCRDIDBACTIVE, MITCRDIBUAVAIL, MITCRDIBUACTIVE, MITCRDIIEAVAIL, MITCRDIIEACTIVE, MITCRDIOPAVAIL, MITCRDIOPACTIVE, MITCRDICJAVAIL, MITCRDICJACTIVE, MSPCRD6AVAIL, MITCRDGUIAVAIL, MITCRDGUIACTIVE, MITCRDAUIAVAIL, MITCRDAUIACTIVE, MITCRDGJTAVAIL, MITCRDGJTACTIVE, MITCRDAJTAVAIL, MITCRDAJTACTIVE, MSPCRD7AVAIL, MITCRDFNMAVAIL, MITCRDFNMACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdWznmVer::Tag
 ******************************************************************************/

void CrdWznmVer::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmVer";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["MitCrdPcv"] = "Make project's current version";
		me["MitCrdIdp"] = "Import deployment information ...";
		me["MitCrdIgb"] = "Import global features ...";
		me["MitCrdImd"] = "Write initial model file set ...";
		me["MitCrdIdb"] = "Import database structure ...";
		me["MitCrdIbu"] = "Import basic user interface structure ...";
		me["MitCrdIie"] = "Import import/export structure ...";
		me["MitCrdIop"] = "Import operation pack structure ...";
		me["MitCrdIcj"] = "Import custom jobs ...";
		me["MitCrdGui"] = "Generate user interface ...";
		me["MitCrdAui"] = "Apply custom user interface features ...";
		me["MitCrdGjt"] = "Generate job tree ...";
		me["MitCrdAjt"] = "Apply custom job tree features ...";
		me["MitCrdFnm"] = "Finalize model ...";
	};
	me["MitAppAbt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...";
	me["MrlAppHlp"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...";
	me["MitCrdNew"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::NEW, ixWznmVLocale)) + " ...";
};

void CrdWznmVer::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmVer";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmVer";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdPcv", "Make project's current version");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIdp", "Import deployment information ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIgb", "Import global features ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdImd", "Write initial model file set ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIdb", "Import database structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIbu", "Import basic user interface structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIie", "Import import/export structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIop", "Import operation pack structure ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdIcj", "Import custom jobs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdGui", "Generate user interface ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAui", "Apply custom user interface features ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdGjt", "Generate job tree ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdAjt", "Apply custom job tree features ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFnm", "Finalize model ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::ABOUT, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::HELP, ixWznmVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitCrdNew", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::NEW, ixWznmVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdWznmVer::DpchAppDo
 ******************************************************************************/

CrdWznmVer::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERDO)
		{
	ixVDo = 0;
};

string CrdWznmVer::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdWznmVer::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmVerDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void CrdWznmVer::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVerDo");
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
 class CrdWznmVer::DpchEngData
 ******************************************************************************/

CrdWznmVer::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVERDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdWznmVer::DpchEngData::getSrefsMask() {
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

void CrdWznmVer::DpchEngData::merge(
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

void CrdWznmVer::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmVerData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFSGE)) feedFSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void CrdWznmVer::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmVerData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
