/**
	* \file PnlWznmNavJob.cpp
	* API code for job PnlWznmNavJob (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmNavJob.h"

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

PnlWznmNavJob::StatApp::StatApp(
			const uint ixWznmVExpstate
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
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstJobAlt = LstJobAlt;
	this->LstSgeAlt = LstSgeAlt;
	this->LstMtdAlt = LstMtdAlt;
	this->LstBlkAlt = LstBlkAlt;
	this->LstCalAlt = LstCalAlt;
	this->LstJobNumFirstdisp = LstJobNumFirstdisp;
	this->LstSgeNumFirstdisp = LstSgeNumFirstdisp;
	this->LstMtdNumFirstdisp = LstMtdNumFirstdisp;
	this->LstBlkNumFirstdisp = LstBlkNumFirstdisp;
	this->LstCalNumFirstdisp = LstCalNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTJOBALT, LSTSGEALT, LSTMTDALT, LSTBLKALT, LSTCALALT, LSTJOBNUMFIRSTDISP, LSTSGENUMFIRSTDISP, LSTMTDNUMFIRSTDISP, LSTBLKNUMFIRSTDISP, LSTCALNUMFIRSTDISP};
};

bool PnlWznmNavJob::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavJob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavJob";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstJobAlt", LstJobAlt)) add(LSTJOBALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSgeAlt", LstSgeAlt)) add(LSTSGEALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtdAlt", LstMtdAlt)) add(LSTMTDALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBlkAlt", LstBlkAlt)) add(LSTBLKALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCalAlt", LstCalAlt)) add(LSTCALALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstJobNumFirstdisp", LstJobNumFirstdisp)) add(LSTJOBNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSgeNumFirstdisp", LstSgeNumFirstdisp)) add(LSTSGENUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtdNumFirstdisp", LstMtdNumFirstdisp)) add(LSTMTDNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBlkNumFirstdisp", LstBlkNumFirstdisp)) add(LSTBLKNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCalNumFirstdisp", LstCalNumFirstdisp)) add(LSTCALNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavJob::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstJobAlt == comp->LstJobAlt) insert(items, LSTJOBALT);
	if (LstSgeAlt == comp->LstSgeAlt) insert(items, LSTSGEALT);
	if (LstMtdAlt == comp->LstMtdAlt) insert(items, LSTMTDALT);
	if (LstBlkAlt == comp->LstBlkAlt) insert(items, LSTBLKALT);
	if (LstCalAlt == comp->LstCalAlt) insert(items, LSTCALALT);
	if (LstJobNumFirstdisp == comp->LstJobNumFirstdisp) insert(items, LSTJOBNUMFIRSTDISP);
	if (LstSgeNumFirstdisp == comp->LstSgeNumFirstdisp) insert(items, LSTSGENUMFIRSTDISP);
	if (LstMtdNumFirstdisp == comp->LstMtdNumFirstdisp) insert(items, LSTMTDNUMFIRSTDISP);
	if (LstBlkNumFirstdisp == comp->LstBlkNumFirstdisp) insert(items, LSTBLKNUMFIRSTDISP);
	if (LstCalNumFirstdisp == comp->LstCalNumFirstdisp) insert(items, LSTCALNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavJob::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTJOBALT, LSTSGEALT, LSTMTDALT, LSTBLKALT, LSTCALALT, LSTJOBNUMFIRSTDISP, LSTSGENUMFIRSTDISP, LSTMTDNUMFIRSTDISP, LSTBLKNUMFIRSTDISP, LSTCALNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlWznmNavJob::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavJob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavJob";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstJobAvail", LstJobAvail)) add(LSTJOBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobViewActive", ButJobViewActive)) add(BUTJOBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJobNewcrdActive", ButJobNewcrdActive)) add(BUTJOBNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstSgeAvail", LstSgeAvail)) add(LSTSGEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSgeViewActive", ButSgeViewActive)) add(BUTSGEVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSgeNewcrdActive", ButSgeNewcrdActive)) add(BUTSGENEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMtdAvail", LstMtdAvail)) add(LSTMTDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMtdViewActive", ButMtdViewActive)) add(BUTMTDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMtdNewcrdActive", ButMtdNewcrdActive)) add(BUTMTDNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstBlkAvail", LstBlkAvail)) add(LSTBLKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBlkViewActive", ButBlkViewActive)) add(BUTBLKVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButBlkNewcrdActive", ButBlkNewcrdActive)) add(BUTBLKNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCalAvail", LstCalAvail)) add(LSTCALAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCalViewActive", ButCalViewActive)) add(BUTCALVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCalNewcrdActive", ButCalNewcrdActive)) add(BUTCALNEWCRDACTIVE);
	};

	return basefound;
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

PnlWznmNavJob::Tag::Tag(
			const string& Cpt
			, const string& CptJob
			, const string& CptSge
			, const string& CptMtd
			, const string& CptBlk
			, const string& CptCal
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptJob = CptJob;
	this->CptSge = CptSge;
	this->CptMtd = CptMtd;
	this->CptBlk = CptBlk;
	this->CptCal = CptCal;

	mask = {CPT, CPTJOB, CPTSGE, CPTMTD, CPTBLK, CPTCAL};
};

bool PnlWznmNavJob::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavJob");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavJob";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptJob", CptJob)) add(CPTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSge", CptSge)) add(CPTSGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMtd", CptMtd)) add(CPTMTD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptBlk", CptBlk)) add(CPTBLK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCal", CptCal)) add(CPTCAL);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavJob::DpchAppData
 ******************************************************************************/

PnlWznmNavJob::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVJOBDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavJob::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavJob::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavJobData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavJob::DpchAppDo
 ******************************************************************************/

PnlWznmNavJob::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVJOBDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavJob::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavJob::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavJobDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavJob::DpchEngData
 ******************************************************************************/

PnlWznmNavJob::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVJOBDATA)
		{
	feedFLstBlk.tag = "FeedFLstBlk";
	feedFLstCal.tag = "FeedFLstCal";
	feedFLstJob.tag = "FeedFLstJob";
	feedFLstMtd.tag = "FeedFLstMtd";
	feedFLstSge.tag = "FeedFLstSge";
};

string PnlWznmNavJob::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWznmNavJob::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavJobData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstBlk.readXML(docctx, basexpath, true)) add(FEEDFLSTBLK);
		if (feedFLstCal.readXML(docctx, basexpath, true)) add(FEEDFLSTCAL);
		if (feedFLstJob.readXML(docctx, basexpath, true)) add(FEEDFLSTJOB);
		if (feedFLstMtd.readXML(docctx, basexpath, true)) add(FEEDFLSTMTD);
		if (feedFLstSge.readXML(docctx, basexpath, true)) add(FEEDFLSTSGE);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstBlk.clear();
		feedFLstCal.clear();
		feedFLstJob.clear();
		feedFLstMtd.clear();
		feedFLstSge.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

