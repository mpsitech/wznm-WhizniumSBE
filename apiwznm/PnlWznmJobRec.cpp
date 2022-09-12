/**
	* \file PnlWznmJobRec.cpp
	* API code for job PnlWznmJobRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmJobRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmJobRec::VecVDo
 ******************************************************************************/

uint PnlWznmJobRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmJobRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmJobRec::ContInf
 ******************************************************************************/

PnlWznmJobRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmJobRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmJobRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmJobRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmJobRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmJobRec::StatApp
 ******************************************************************************/

PnlWznmJobRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneAVar
			, const bool initdoneACmd
			, const bool initdone1NMethod
			, const bool initdone1NRtjob
			, const bool initdoneJob1NStage
			, const bool initdone1NSensitivity
			, const bool initdoneHk1NVector
			, const bool initdoneRef1NBlock
			, const bool initdoneMNOppack
			, const bool initdoneMNOp
			, const bool initdoneSupMNJob
			, const bool initdoneSubMNJob
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneAVar = initdoneAVar;
	this->initdoneACmd = initdoneACmd;
	this->initdone1NMethod = initdone1NMethod;
	this->initdone1NRtjob = initdone1NRtjob;
	this->initdoneJob1NStage = initdoneJob1NStage;
	this->initdone1NSensitivity = initdone1NSensitivity;
	this->initdoneHk1NVector = initdoneHk1NVector;
	this->initdoneRef1NBlock = initdoneRef1NBlock;
	this->initdoneMNOppack = initdoneMNOppack;
	this->initdoneMNOp = initdoneMNOp;
	this->initdoneSupMNJob = initdoneSupMNJob;
	this->initdoneSubMNJob = initdoneSubMNJob;

	mask = {INITDONEDETAIL, INITDONEAVAR, INITDONEACMD, INITDONE1NMETHOD, INITDONE1NRTJOB, INITDONEJOB1NSTAGE, INITDONE1NSENSITIVITY, INITDONEHK1NVECTOR, INITDONEREF1NBLOCK, INITDONEMNOPPACK, INITDONEMNOP, INITDONESUPMNJOB, INITDONESUBMNJOB};
};

bool PnlWznmJobRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmJobRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAVar", initdoneAVar)) add(INITDONEAVAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneACmd", initdoneACmd)) add(INITDONEACMD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NMethod", initdone1NMethod)) add(INITDONE1NMETHOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NRtjob", initdone1NRtjob)) add(INITDONE1NRTJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneJob1NStage", initdoneJob1NStage)) add(INITDONEJOB1NSTAGE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NSensitivity", initdone1NSensitivity)) add(INITDONE1NSENSITIVITY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", initdoneHk1NVector)) add(INITDONEHK1NVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NBlock", initdoneRef1NBlock)) add(INITDONEREF1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNOppack", initdoneMNOppack)) add(INITDONEMNOPPACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNOp", initdoneMNOp)) add(INITDONEMNOP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSupMNJob", initdoneSupMNJob)) add(INITDONESUPMNJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSubMNJob", initdoneSubMNJob)) add(INITDONESUBMNJOB);
	};

	return basefound;
};

set<uint> PnlWznmJobRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneAVar == comp->initdoneAVar) insert(items, INITDONEAVAR);
	if (initdoneACmd == comp->initdoneACmd) insert(items, INITDONEACMD);
	if (initdone1NMethod == comp->initdone1NMethod) insert(items, INITDONE1NMETHOD);
	if (initdone1NRtjob == comp->initdone1NRtjob) insert(items, INITDONE1NRTJOB);
	if (initdoneJob1NStage == comp->initdoneJob1NStage) insert(items, INITDONEJOB1NSTAGE);
	if (initdone1NSensitivity == comp->initdone1NSensitivity) insert(items, INITDONE1NSENSITIVITY);
	if (initdoneHk1NVector == comp->initdoneHk1NVector) insert(items, INITDONEHK1NVECTOR);
	if (initdoneRef1NBlock == comp->initdoneRef1NBlock) insert(items, INITDONEREF1NBLOCK);
	if (initdoneMNOppack == comp->initdoneMNOppack) insert(items, INITDONEMNOPPACK);
	if (initdoneMNOp == comp->initdoneMNOp) insert(items, INITDONEMNOP);
	if (initdoneSupMNJob == comp->initdoneSupMNJob) insert(items, INITDONESUPMNJOB);
	if (initdoneSubMNJob == comp->initdoneSubMNJob) insert(items, INITDONESUBMNJOB);

	return(items);
};

set<uint> PnlWznmJobRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEAVAR, INITDONEACMD, INITDONE1NMETHOD, INITDONE1NRTJOB, INITDONEJOB1NSTAGE, INITDONE1NSENSITIVITY, INITDONEHK1NVECTOR, INITDONEREF1NBLOCK, INITDONEMNOPPACK, INITDONEMNOP, INITDONESUPMNJOB, INITDONESUBMNJOB};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmJobRec::StatShr
 ******************************************************************************/

PnlWznmJobRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefAVar
			, const string& scrJrefACmd
			, const string& scrJref1NMethod
			, const string& scrJref1NRtjob
			, const string& scrJrefJob1NStage
			, const string& scrJref1NSensitivity
			, const string& scrJrefHk1NVector
			, const string& scrJrefRef1NBlock
			, const string& scrJrefMNOppack
			, const string& scrJrefMNOp
			, const string& scrJrefSupMNJob
			, const string& scrJrefSubMNJob
			, const bool pnlsubmnjobAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefAVar = scrJrefAVar;
	this->scrJrefACmd = scrJrefACmd;
	this->scrJref1NMethod = scrJref1NMethod;
	this->scrJref1NRtjob = scrJref1NRtjob;
	this->scrJrefJob1NStage = scrJrefJob1NStage;
	this->scrJref1NSensitivity = scrJref1NSensitivity;
	this->scrJrefHk1NVector = scrJrefHk1NVector;
	this->scrJrefRef1NBlock = scrJrefRef1NBlock;
	this->scrJrefMNOppack = scrJrefMNOppack;
	this->scrJrefMNOp = scrJrefMNOp;
	this->scrJrefSupMNJob = scrJrefSupMNJob;
	this->scrJrefSubMNJob = scrJrefSubMNJob;
	this->pnlsubmnjobAvail = pnlsubmnjobAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAVAR, SCRJREFACMD, SCRJREF1NMETHOD, SCRJREF1NRTJOB, SCRJREFJOB1NSTAGE, SCRJREF1NSENSITIVITY, SCRJREFHK1NVECTOR, SCRJREFREF1NBLOCK, SCRJREFMNOPPACK, SCRJREFMNOP, SCRJREFSUPMNJOB, SCRJREFSUBMNJOB, PNLSUBMNJOBAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWznmJobRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmJobRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAVar", scrJrefAVar)) add(SCRJREFAVAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefACmd", scrJrefACmd)) add(SCRJREFACMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NMethod", scrJref1NMethod)) add(SCRJREF1NMETHOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NRtjob", scrJref1NRtjob)) add(SCRJREF1NRTJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefJob1NStage", scrJrefJob1NStage)) add(SCRJREFJOB1NSTAGE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NSensitivity", scrJref1NSensitivity)) add(SCRJREF1NSENSITIVITY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", scrJrefHk1NVector)) add(SCRJREFHK1NVECTOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NBlock", scrJrefRef1NBlock)) add(SCRJREFREF1NBLOCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNOppack", scrJrefMNOppack)) add(SCRJREFMNOPPACK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNOp", scrJrefMNOp)) add(SCRJREFMNOP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSupMNJob", scrJrefSupMNJob)) add(SCRJREFSUPMNJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSubMNJob", scrJrefSubMNJob)) add(SCRJREFSUBMNJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlsubmnjobAvail", pnlsubmnjobAvail)) add(PNLSUBMNJOBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmJobRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefAVar == comp->scrJrefAVar) insert(items, SCRJREFAVAR);
	if (scrJrefACmd == comp->scrJrefACmd) insert(items, SCRJREFACMD);
	if (scrJref1NMethod == comp->scrJref1NMethod) insert(items, SCRJREF1NMETHOD);
	if (scrJref1NRtjob == comp->scrJref1NRtjob) insert(items, SCRJREF1NRTJOB);
	if (scrJrefJob1NStage == comp->scrJrefJob1NStage) insert(items, SCRJREFJOB1NSTAGE);
	if (scrJref1NSensitivity == comp->scrJref1NSensitivity) insert(items, SCRJREF1NSENSITIVITY);
	if (scrJrefHk1NVector == comp->scrJrefHk1NVector) insert(items, SCRJREFHK1NVECTOR);
	if (scrJrefRef1NBlock == comp->scrJrefRef1NBlock) insert(items, SCRJREFREF1NBLOCK);
	if (scrJrefMNOppack == comp->scrJrefMNOppack) insert(items, SCRJREFMNOPPACK);
	if (scrJrefMNOp == comp->scrJrefMNOp) insert(items, SCRJREFMNOP);
	if (scrJrefSupMNJob == comp->scrJrefSupMNJob) insert(items, SCRJREFSUPMNJOB);
	if (scrJrefSubMNJob == comp->scrJrefSubMNJob) insert(items, SCRJREFSUBMNJOB);
	if (pnlsubmnjobAvail == comp->pnlsubmnjobAvail) insert(items, PNLSUBMNJOBAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmJobRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAVAR, SCRJREFACMD, SCRJREF1NMETHOD, SCRJREF1NRTJOB, SCRJREFJOB1NSTAGE, SCRJREF1NSENSITIVITY, SCRJREFHK1NVECTOR, SCRJREFREF1NBLOCK, SCRJREFMNOPPACK, SCRJREFMNOP, SCRJREFSUPMNJOB, SCRJREFSUBMNJOB, PNLSUBMNJOBAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmJobRec::Tag
 ******************************************************************************/

PnlWznmJobRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmJobRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmJobRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmJobRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmJobRec::DpchAppDo
 ******************************************************************************/

PnlWznmJobRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMJOBRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmJobRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmJobRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmJobRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmJobRec::DpchEngData
 ******************************************************************************/

PnlWznmJobRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMJOBRECDATA)
		{
};

string PnlWznmJobRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmJobRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmJobRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
