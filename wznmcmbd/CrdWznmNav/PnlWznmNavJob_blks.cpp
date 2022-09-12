/**
	* \file PnlWznmNavJob_blks.cpp
	* job handler for job PnlWznmNavJob (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavJob::VecVDo
 ******************************************************************************/

uint PnlWznmNavJob::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "butjobnewcrdclick") return BUTJOBNEWCRDCLICK;
	if (s == "butsgeviewclick") return BUTSGEVIEWCLICK;
	if (s == "butsgenewcrdclick") return BUTSGENEWCRDCLICK;
	if (s == "butmtdviewclick") return BUTMTDVIEWCLICK;
	if (s == "butmtdnewcrdclick") return BUTMTDNEWCRDCLICK;
	if (s == "butblkviewclick") return BUTBLKVIEWCLICK;
	if (s == "butblknewcrdclick") return BUTBLKNEWCRDCLICK;
	if (s == "butcalviewclick") return BUTCALVIEWCLICK;
	if (s == "butcalnewcrdclick") return BUTCALNEWCRDCLICK;

	return(0);
};

string PnlWznmNavJob::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTJOBNEWCRDCLICK) return("ButJobNewcrdClick");
	if (ix == BUTSGEVIEWCLICK) return("ButSgeViewClick");
	if (ix == BUTSGENEWCRDCLICK) return("ButSgeNewcrdClick");
	if (ix == BUTMTDVIEWCLICK) return("ButMtdViewClick");
	if (ix == BUTMTDNEWCRDCLICK) return("ButMtdNewcrdClick");
	if (ix == BUTBLKVIEWCLICK) return("ButBlkViewClick");
	if (ix == BUTBLKNEWCRDCLICK) return("ButBlkNewcrdClick");
	if (ix == BUTCALVIEWCLICK) return("ButCalViewClick");
	if (ix == BUTCALNEWCRDCLICK) return("ButCalNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavJob::ContIac
 ******************************************************************************/

PnlWznmNavJob::ContIac::ContIac(
			const uint numFLstJob
			, const uint numFLstSge
			, const uint numFLstMtd
			, const uint numFLstBlk
			, const uint numFLstCal
		) :
			Block()
		{
	this->numFLstJob = numFLstJob;
	this->numFLstSge = numFLstSge;
	this->numFLstMtd = numFLstMtd;
	this->numFLstBlk = numFLstBlk;
	this->numFLstCal = numFLstCal;

	mask = {NUMFLSTJOB, NUMFLSTSGE, NUMFLSTMTD, NUMFLSTBLK, NUMFLSTCAL};
};

bool PnlWznmNavJob::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWznmNavJob"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFLstJob")) {numFLstJob = me["numFLstJob"].asUInt(); add(NUMFLSTJOB);};
		if (me.isMember("numFLstSge")) {numFLstSge = me["numFLstSge"].asUInt(); add(NUMFLSTSGE);};
		if (me.isMember("numFLstMtd")) {numFLstMtd = me["numFLstMtd"].asUInt(); add(NUMFLSTMTD);};
		if (me.isMember("numFLstBlk")) {numFLstBlk = me["numFLstBlk"].asUInt(); add(NUMFLSTBLK);};
		if (me.isMember("numFLstCal")) {numFLstCal = me["numFLstCal"].asUInt(); add(NUMFLSTCAL);};
	};

	return basefound;
};

bool PnlWznmNavJob::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavJob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavJob";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstJob", numFLstJob)) add(NUMFLSTJOB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstSge", numFLstSge)) add(NUMFLSTSGE);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMtd", numFLstMtd)) add(NUMFLSTMTD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstBlk", numFLstBlk)) add(NUMFLSTBLK);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCal", numFLstCal)) add(NUMFLSTCAL);
	};

	return basefound;
};

void PnlWznmNavJob::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavJob";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFLstJob"] = numFLstJob;
	me["numFLstSge"] = numFLstSge;
	me["numFLstMtd"] = numFLstMtd;
	me["numFLstBlk"] = numFLstBlk;
	me["numFLstCal"] = numFLstCal;
};

void PnlWznmNavJob::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavJob";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavJob";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstJob", numFLstJob);
		writeUintAttr(wr, itemtag, "sref", "numFLstSge", numFLstSge);
		writeUintAttr(wr, itemtag, "sref", "numFLstMtd", numFLstMtd);
		writeUintAttr(wr, itemtag, "sref", "numFLstBlk", numFLstBlk);
		writeUintAttr(wr, itemtag, "sref", "numFLstCal", numFLstCal);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavJob::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstJob == comp->numFLstJob) insert(items, NUMFLSTJOB);
	if (numFLstSge == comp->numFLstSge) insert(items, NUMFLSTSGE);
	if (numFLstMtd == comp->numFLstMtd) insert(items, NUMFLSTMTD);
	if (numFLstBlk == comp->numFLstBlk) insert(items, NUMFLSTBLK);
	if (numFLstCal == comp->numFLstCal) insert(items, NUMFLSTCAL);

	return(items);
};

set<uint> PnlWznmNavJob::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTJOB, NUMFLSTSGE, NUMFLSTMTD, NUMFLSTBLK, NUMFLSTCAL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavJob::StatApp
 ******************************************************************************/

void PnlWznmNavJob::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
			, const bool LstJobAlt
			, const bool LstSgeAlt
			, const bool LstMtdAlt
			, const bool LstBlkAlt
			, const bool LstCalAlt
			, const uint LstJobNumFirstdisp
			, const uint LstSgeNumFirstdisp
			, const uint LstMtdNumFirstdisp
			, const uint LstBlkNumFirstdisp
			, const uint LstCalNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavJob";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstJobAlt"] = LstJobAlt;
	me["LstSgeAlt"] = LstSgeAlt;
	me["LstMtdAlt"] = LstMtdAlt;
	me["LstBlkAlt"] = LstBlkAlt;
	me["LstCalAlt"] = LstCalAlt;
	me["LstJobNumFirstdisp"] = LstJobNumFirstdisp;
	me["LstSgeNumFirstdisp"] = LstSgeNumFirstdisp;
	me["LstMtdNumFirstdisp"] = LstMtdNumFirstdisp;
	me["LstBlkNumFirstdisp"] = LstBlkNumFirstdisp;
	me["LstCalNumFirstdisp"] = LstCalNumFirstdisp;
};

void PnlWznmNavJob::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstJobAlt
			, const bool LstSgeAlt
			, const bool LstMtdAlt
			, const bool LstBlkAlt
			, const bool LstCalAlt
			, const uint LstJobNumFirstdisp
			, const uint LstSgeNumFirstdisp
			, const uint LstMtdNumFirstdisp
			, const uint LstBlkNumFirstdisp
			, const uint LstCalNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavJob";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavJob";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstJobAlt", LstJobAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstSgeAlt", LstSgeAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstMtdAlt", LstMtdAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstBlkAlt", LstBlkAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCalAlt", LstCalAlt);
		writeUintAttr(wr, itemtag, "sref", "LstJobNumFirstdisp", LstJobNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstSgeNumFirstdisp", LstSgeNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstMtdNumFirstdisp", LstMtdNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstBlkNumFirstdisp", LstBlkNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCalNumFirstdisp", LstCalNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavJob::StatShr
 ******************************************************************************/

PnlWznmNavJob::StatShr::StatShr(
			const bool LstJobAvail
			, const bool ButJobViewActive
			, const bool ButJobNewcrdActive
			, const bool LstSgeAvail
			, const bool ButSgeViewActive
			, const bool ButSgeNewcrdActive
			, const bool LstMtdAvail
			, const bool ButMtdViewActive
			, const bool ButMtdNewcrdActive
			, const bool LstBlkAvail
			, const bool ButBlkViewActive
			, const bool ButBlkNewcrdActive
			, const bool LstCalAvail
			, const bool ButCalViewActive
			, const bool ButCalNewcrdActive
		) :
			Block()
		{
	this->LstJobAvail = LstJobAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->ButJobNewcrdActive = ButJobNewcrdActive;
	this->LstSgeAvail = LstSgeAvail;
	this->ButSgeViewActive = ButSgeViewActive;
	this->ButSgeNewcrdActive = ButSgeNewcrdActive;
	this->LstMtdAvail = LstMtdAvail;
	this->ButMtdViewActive = ButMtdViewActive;
	this->ButMtdNewcrdActive = ButMtdNewcrdActive;
	this->LstBlkAvail = LstBlkAvail;
	this->ButBlkViewActive = ButBlkViewActive;
	this->ButBlkNewcrdActive = ButBlkNewcrdActive;
	this->LstCalAvail = LstCalAvail;
	this->ButCalViewActive = ButCalViewActive;
	this->ButCalNewcrdActive = ButCalNewcrdActive;

	mask = {LSTJOBAVAIL, BUTJOBVIEWACTIVE, BUTJOBNEWCRDACTIVE, LSTSGEAVAIL, BUTSGEVIEWACTIVE, BUTSGENEWCRDACTIVE, LSTMTDAVAIL, BUTMTDVIEWACTIVE, BUTMTDNEWCRDACTIVE, LSTBLKAVAIL, BUTBLKVIEWACTIVE, BUTBLKNEWCRDACTIVE, LSTCALAVAIL, BUTCALVIEWACTIVE, BUTCALNEWCRDACTIVE};
};

void PnlWznmNavJob::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavJob";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["LstJobAvail"] = LstJobAvail;
	me["ButJobViewActive"] = ButJobViewActive;
	me["ButJobNewcrdActive"] = ButJobNewcrdActive;
	me["LstSgeAvail"] = LstSgeAvail;
	me["ButSgeViewActive"] = ButSgeViewActive;
	me["ButSgeNewcrdActive"] = ButSgeNewcrdActive;
	me["LstMtdAvail"] = LstMtdAvail;
	me["ButMtdViewActive"] = ButMtdViewActive;
	me["ButMtdNewcrdActive"] = ButMtdNewcrdActive;
	me["LstBlkAvail"] = LstBlkAvail;
	me["ButBlkViewActive"] = ButBlkViewActive;
	me["ButBlkNewcrdActive"] = ButBlkNewcrdActive;
	me["LstCalAvail"] = LstCalAvail;
	me["ButCalViewActive"] = ButCalViewActive;
	me["ButCalNewcrdActive"] = ButCalNewcrdActive;
};

void PnlWznmNavJob::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavJob";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavJob";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstJobAvail", LstJobAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobNewcrdActive", ButJobNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstSgeAvail", LstSgeAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSgeViewActive", ButSgeViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSgeNewcrdActive", ButSgeNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstMtdAvail", LstMtdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMtdViewActive", ButMtdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMtdNewcrdActive", ButMtdNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstBlkAvail", LstBlkAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBlkViewActive", ButBlkViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBlkNewcrdActive", ButBlkNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCalAvail", LstCalAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCalViewActive", ButCalViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCalNewcrdActive", ButCalNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavJob::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstJobAvail == comp->LstJobAvail) insert(items, LSTJOBAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (ButJobNewcrdActive == comp->ButJobNewcrdActive) insert(items, BUTJOBNEWCRDACTIVE);
	if (LstSgeAvail == comp->LstSgeAvail) insert(items, LSTSGEAVAIL);
	if (ButSgeViewActive == comp->ButSgeViewActive) insert(items, BUTSGEVIEWACTIVE);
	if (ButSgeNewcrdActive == comp->ButSgeNewcrdActive) insert(items, BUTSGENEWCRDACTIVE);
	if (LstMtdAvail == comp->LstMtdAvail) insert(items, LSTMTDAVAIL);
	if (ButMtdViewActive == comp->ButMtdViewActive) insert(items, BUTMTDVIEWACTIVE);
	if (ButMtdNewcrdActive == comp->ButMtdNewcrdActive) insert(items, BUTMTDNEWCRDACTIVE);
	if (LstBlkAvail == comp->LstBlkAvail) insert(items, LSTBLKAVAIL);
	if (ButBlkViewActive == comp->ButBlkViewActive) insert(items, BUTBLKVIEWACTIVE);
	if (ButBlkNewcrdActive == comp->ButBlkNewcrdActive) insert(items, BUTBLKNEWCRDACTIVE);
	if (LstCalAvail == comp->LstCalAvail) insert(items, LSTCALAVAIL);
	if (ButCalViewActive == comp->ButCalViewActive) insert(items, BUTCALVIEWACTIVE);
	if (ButCalNewcrdActive == comp->ButCalNewcrdActive) insert(items, BUTCALNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavJob::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTJOBAVAIL, BUTJOBVIEWACTIVE, BUTJOBNEWCRDACTIVE, LSTSGEAVAIL, BUTSGEVIEWACTIVE, BUTSGENEWCRDACTIVE, LSTMTDAVAIL, BUTMTDVIEWACTIVE, BUTMTDNEWCRDACTIVE, LSTBLKAVAIL, BUTBLKVIEWACTIVE, BUTBLKNEWCRDACTIVE, LSTCALAVAIL, BUTCALVIEWACTIVE, BUTCALNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavJob::Tag
 ******************************************************************************/

void PnlWznmNavJob::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavJob";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Job tree module";
		me["CptJob"] = "jobs";
		me["CptSge"] = "stages";
		me["CptMtd"] = "methods";
		me["CptBlk"] = "blocks";
		me["CptCal"] = "calls";
	};
};

void PnlWznmNavJob::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavJob";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavJob";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Job tree module");
			writeStringAttr(wr, itemtag, "sref", "CptJob", "jobs");
			writeStringAttr(wr, itemtag, "sref", "CptSge", "stages");
			writeStringAttr(wr, itemtag, "sref", "CptMtd", "methods");
			writeStringAttr(wr, itemtag, "sref", "CptBlk", "blocks");
			writeStringAttr(wr, itemtag, "sref", "CptCal", "calls");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavJob::DpchAppData
 ******************************************************************************/

PnlWznmNavJob::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVJOBDATA)
		{
};

string PnlWznmNavJob::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavJob::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavJobData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmNavJob::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavJobData");
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
 class PnlWznmNavJob::DpchAppDo
 ******************************************************************************/

PnlWznmNavJob::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVJOBDO)
		{
	ixVDo = 0;
};

string PnlWznmNavJob::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavJob::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmNavJobDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmNavJob::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavJobDo");
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
 class PnlWznmNavJob::DpchEngData
 ******************************************************************************/

PnlWznmNavJob::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstBlk
			, Feed* feedFLstCal
			, Feed* feedFLstJob
			, Feed* feedFLstMtd
			, Feed* feedFLstSge
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVJOBDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTBLK, FEEDFLSTCAL, FEEDFLSTJOB, FEEDFLSTMTD, FEEDFLSTSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTBLK) && feedFLstBlk) this->feedFLstBlk = *feedFLstBlk;
	if (find(this->mask, FEEDFLSTCAL) && feedFLstCal) this->feedFLstCal = *feedFLstCal;
	if (find(this->mask, FEEDFLSTJOB) && feedFLstJob) this->feedFLstJob = *feedFLstJob;
	if (find(this->mask, FEEDFLSTMTD) && feedFLstMtd) this->feedFLstMtd = *feedFLstMtd;
	if (find(this->mask, FEEDFLSTSGE) && feedFLstSge) this->feedFLstSge = *feedFLstSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavJob::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTBLK)) ss.push_back("feedFLstBlk");
	if (has(FEEDFLSTCAL)) ss.push_back("feedFLstCal");
	if (has(FEEDFLSTJOB)) ss.push_back("feedFLstJob");
	if (has(FEEDFLSTMTD)) ss.push_back("feedFLstMtd");
	if (has(FEEDFLSTSGE)) ss.push_back("feedFLstSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavJob::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTBLK)) {feedFLstBlk = src->feedFLstBlk; add(FEEDFLSTBLK);};
	if (src->has(FEEDFLSTCAL)) {feedFLstCal = src->feedFLstCal; add(FEEDFLSTCAL);};
	if (src->has(FEEDFLSTJOB)) {feedFLstJob = src->feedFLstJob; add(FEEDFLSTJOB);};
	if (src->has(FEEDFLSTMTD)) {feedFLstMtd = src->feedFLstMtd; add(FEEDFLSTMTD);};
	if (src->has(FEEDFLSTSGE)) {feedFLstSge = src->feedFLstSge; add(FEEDFLSTSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavJob::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmNavJobData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFLSTBLK)) feedFLstBlk.writeJSON(me);
	if (has(FEEDFLSTCAL)) feedFLstCal.writeJSON(me);
	if (has(FEEDFLSTJOB)) feedFLstJob.writeJSON(me);
	if (has(FEEDFLSTMTD)) feedFLstMtd.writeJSON(me);
	if (has(FEEDFLSTSGE)) feedFLstSge.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmNavJob::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavJobData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTBLK)) feedFLstBlk.writeXML(wr);
		if (has(FEEDFLSTCAL)) feedFLstCal.writeXML(wr);
		if (has(FEEDFLSTJOB)) feedFLstJob.writeXML(wr);
		if (has(FEEDFLSTMTD)) feedFLstMtd.writeXML(wr);
		if (has(FEEDFLSTSGE)) feedFLstSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
