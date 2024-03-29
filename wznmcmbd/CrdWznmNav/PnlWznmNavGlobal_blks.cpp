/**
	* \file PnlWznmNavGlobal_blks.cpp
	* job handler for job PnlWznmNavGlobal (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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
		{
	this->numFLstLoc = numFLstLoc;
	this->numFLstTag = numFLstTag;
	this->numFLstCtp = numFLstCtp;
	this->numFLstMch = numFLstMch;
	this->numFLstLib = numFLstLib;

	mask = {NUMFLSTLOC, NUMFLSTTAG, NUMFLSTCTP, NUMFLSTMCH, NUMFLSTLIB};
};

bool PnlWznmNavGlobal::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmNavGlobal"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstLoc")) {numFLstLoc = me["numFLstLoc"].asUInt(); add(NUMFLSTLOC);};
		if (me.isMember("numFLstTag")) {numFLstTag = me["numFLstTag"].asUInt(); add(NUMFLSTTAG);};
		if (me.isMember("numFLstCtp")) {numFLstCtp = me["numFLstCtp"].asUInt(); add(NUMFLSTCTP);};
		if (me.isMember("numFLstMch")) {numFLstMch = me["numFLstMch"].asUInt(); add(NUMFLSTMCH);};
		if (me.isMember("numFLstLib")) {numFLstLib = me["numFLstLib"].asUInt(); add(NUMFLSTLIB);};
	};

	return basefound;
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

void PnlWznmNavGlobal::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstLoc"] = numFLstLoc;
	me["numFLstTag"] = numFLstTag;
	me["numFLstCtp"] = numFLstCtp;
	me["numFLstMch"] = numFLstMch;
	me["numFLstLib"] = numFLstLib;
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

void PnlWznmNavGlobal::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstLocAlt"] = LstLocAlt;
	me["LstTagAlt"] = LstTagAlt;
	me["LstCtpAlt"] = LstCtpAlt;
	me["LstMchAlt"] = LstMchAlt;
	me["LstLibAlt"] = LstLibAlt;
	me["LstLocNumFirstdisp"] = LstLocNumFirstdisp;
	me["LstTagNumFirstdisp"] = LstTagNumFirstdisp;
	me["LstCtpNumFirstdisp"] = LstCtpNumFirstdisp;
	me["LstMchNumFirstdisp"] = LstMchNumFirstdisp;
	me["LstLibNumFirstdisp"] = LstLibNumFirstdisp;
};

void PnlWznmNavGlobal::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
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
		writeBoolAttr(wr, itemtag, "sref", "LstMchAlt", LstMchAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstLibAlt", LstLibAlt);
		writeUintAttr(wr, itemtag, "sref", "LstLocNumFirstdisp", LstLocNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTagNumFirstdisp", LstTagNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCtpNumFirstdisp", LstCtpNumFirstdisp);
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
	this->LstMchAvail = LstMchAvail;
	this->ButMchViewActive = ButMchViewActive;
	this->LstLibAvail = LstLibAvail;
	this->ButLibViewActive = ButLibViewActive;

	mask = {LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTTAGAVAIL, BUTTAGVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE};
};

void PnlWznmNavGlobal::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstLocAvail"] = LstLocAvail;
	me["ButLocViewActive"] = ButLocViewActive;
	me["LstTagAvail"] = LstTagAvail;
	me["ButTagViewActive"] = ButTagViewActive;
	me["LstCtpAvail"] = LstCtpAvail;
	me["ButCtpViewActive"] = ButCtpViewActive;
	me["LstMchAvail"] = LstMchAvail;
	me["ButMchViewActive"] = ButMchViewActive;
	me["LstLibAvail"] = LstLibAvail;
	me["ButLibViewActive"] = ButLibViewActive;
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

void PnlWznmNavGlobal::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavGlobal";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Global data module";
		me["CptLoc"] = "locales";
		me["CptTag"] = "tags";
		me["CptCtp"] = "capability templates";
		me["CptMch"] = "machines";
		me["CptLib"] = "libraries";
	};
};

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

void PnlWznmNavGlobal::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavGlobalData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
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

void PnlWznmNavGlobal::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavGlobalDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
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
			, Feed* feedFLstTag
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVGLOBALDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCTP, FEEDFLSTLIB, FEEDFLSTLOC, FEEDFLSTMCH, FEEDFLSTTAG, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCTP) && feedFLstCtp) this->feedFLstCtp = *feedFLstCtp;
	if (find(this->mask, FEEDFLSTLIB) && feedFLstLib) this->feedFLstLib = *feedFLstLib;
	if (find(this->mask, FEEDFLSTLOC) && feedFLstLoc) this->feedFLstLoc = *feedFLstLoc;
	if (find(this->mask, FEEDFLSTMCH) && feedFLstMch) this->feedFLstMch = *feedFLstMch;
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
	if (src->has(FEEDFLSTTAG)) {feedFLstTag = src->feedFLstTag; add(FEEDFLSTTAG);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavGlobal::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmNavGlobalData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTCTP)) feedFLstCtp.writeJSON(me);
	if (has(FEEDFLSTLIB)) feedFLstLib.writeJSON(me);
	if (has(FEEDFLSTLOC)) feedFLstLoc.writeJSON(me);
	if (has(FEEDFLSTMCH)) feedFLstMch.writeJSON(me);
	if (has(FEEDFLSTTAG)) feedFLstTag.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
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
		if (has(FEEDFLSTTAG)) feedFLstTag.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
