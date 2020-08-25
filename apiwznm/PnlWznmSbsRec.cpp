/**
	* \file PnlWznmSbsRec.cpp
	* API code for job PnlWznmSbsRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "PnlWznmSbsRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSbsRec::VecVDo
 ******************************************************************************/

uint PnlWznmSbsRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmSbsRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmSbsRec::ContInf
 ******************************************************************************/

PnlWznmSbsRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmSbsRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmSbsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmSbsRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmSbsRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmSbsRec::ContInf::diff(
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
 class PnlWznmSbsRec::StatApp
 ******************************************************************************/

PnlWznmSbsRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdone1NStub
			, const bool initdoneTos1NRelation
			, const bool initdoneFrs1NRelation
			, const bool initdone1NTablecol
			, const bool initdonePst1NQuerymod
			, const bool initdoneAsbMNSubset
			, const bool initdoneBsbMNSubset
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneATitle = initdoneATitle;
	this->initdone1NStub = initdone1NStub;
	this->initdoneTos1NRelation = initdoneTos1NRelation;
	this->initdoneFrs1NRelation = initdoneFrs1NRelation;
	this->initdone1NTablecol = initdone1NTablecol;
	this->initdonePst1NQuerymod = initdonePst1NQuerymod;
	this->initdoneAsbMNSubset = initdoneAsbMNSubset;
	this->initdoneBsbMNSubset = initdoneBsbMNSubset;

	mask = {INITDONEDETAIL, INITDONEATITLE, INITDONE1NSTUB, INITDONETOS1NRELATION, INITDONEFRS1NRELATION, INITDONE1NTABLECOL, INITDONEPST1NQUERYMOD, INITDONEASBMNSUBSET, INITDONEBSBMNSUBSET};
};

bool PnlWznmSbsRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmSbsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmSbsRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneATitle", initdoneATitle)) add(INITDONEATITLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NStub", initdone1NStub)) add(INITDONE1NSTUB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTos1NRelation", initdoneTos1NRelation)) add(INITDONETOS1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFrs1NRelation", initdoneFrs1NRelation)) add(INITDONEFRS1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NTablecol", initdone1NTablecol)) add(INITDONE1NTABLECOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePst1NQuerymod", initdonePst1NQuerymod)) add(INITDONEPST1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAsbMNSubset", initdoneAsbMNSubset)) add(INITDONEASBMNSUBSET);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneBsbMNSubset", initdoneBsbMNSubset)) add(INITDONEBSBMNSUBSET);
	};

	return basefound;
};

set<uint> PnlWznmSbsRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneATitle == comp->initdoneATitle) insert(items, INITDONEATITLE);
	if (initdone1NStub == comp->initdone1NStub) insert(items, INITDONE1NSTUB);
	if (initdoneTos1NRelation == comp->initdoneTos1NRelation) insert(items, INITDONETOS1NRELATION);
	if (initdoneFrs1NRelation == comp->initdoneFrs1NRelation) insert(items, INITDONEFRS1NRELATION);
	if (initdone1NTablecol == comp->initdone1NTablecol) insert(items, INITDONE1NTABLECOL);
	if (initdonePst1NQuerymod == comp->initdonePst1NQuerymod) insert(items, INITDONEPST1NQUERYMOD);
	if (initdoneAsbMNSubset == comp->initdoneAsbMNSubset) insert(items, INITDONEASBMNSUBSET);
	if (initdoneBsbMNSubset == comp->initdoneBsbMNSubset) insert(items, INITDONEBSBMNSUBSET);

	return(items);
};

set<uint> PnlWznmSbsRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEATITLE, INITDONE1NSTUB, INITDONETOS1NRELATION, INITDONEFRS1NRELATION, INITDONE1NTABLECOL, INITDONEPST1NQUERYMOD, INITDONEASBMNSUBSET, INITDONEBSBMNSUBSET};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSbsRec::StatShr
 ******************************************************************************/

PnlWznmSbsRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefATitle
			, const string& scrJref1NStub
			, const string& scrJrefTos1NRelation
			, const string& scrJrefFrs1NRelation
			, const string& scrJref1NTablecol
			, const string& scrJrefPst1NQuerymod
			, const bool pnlpst1nquerymodAvail
			, const string& scrJrefAsbMNSubset
			, const string& scrJrefBsbMNSubset
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefATitle = scrJrefATitle;
	this->scrJref1NStub = scrJref1NStub;
	this->scrJrefTos1NRelation = scrJrefTos1NRelation;
	this->scrJrefFrs1NRelation = scrJrefFrs1NRelation;
	this->scrJref1NTablecol = scrJref1NTablecol;
	this->scrJrefPst1NQuerymod = scrJrefPst1NQuerymod;
	this->pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
	this->scrJrefAsbMNSubset = scrJrefAsbMNSubset;
	this->scrJrefBsbMNSubset = scrJrefBsbMNSubset;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREF1NSTUB, SCRJREFTOS1NRELATION, SCRJREFFRS1NRELATION, SCRJREF1NTABLECOL, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFASBMNSUBSET, SCRJREFBSBMNSUBSET, BUTREGULARIZEACTIVE};
};

bool PnlWznmSbsRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmSbsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmSbsRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefATitle", scrJrefATitle)) add(SCRJREFATITLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NStub", scrJref1NStub)) add(SCRJREF1NSTUB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTos1NRelation", scrJrefTos1NRelation)) add(SCRJREFTOS1NRELATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFrs1NRelation", scrJrefFrs1NRelation)) add(SCRJREFFRS1NRELATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NTablecol", scrJref1NTablecol)) add(SCRJREF1NTABLECOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPst1NQuerymod", scrJrefPst1NQuerymod)) add(SCRJREFPST1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpst1nquerymodAvail", pnlpst1nquerymodAvail)) add(PNLPST1NQUERYMODAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAsbMNSubset", scrJrefAsbMNSubset)) add(SCRJREFASBMNSUBSET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefBsbMNSubset", scrJrefBsbMNSubset)) add(SCRJREFBSBMNSUBSET);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmSbsRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefATitle == comp->scrJrefATitle) insert(items, SCRJREFATITLE);
	if (scrJref1NStub == comp->scrJref1NStub) insert(items, SCRJREF1NSTUB);
	if (scrJrefTos1NRelation == comp->scrJrefTos1NRelation) insert(items, SCRJREFTOS1NRELATION);
	if (scrJrefFrs1NRelation == comp->scrJrefFrs1NRelation) insert(items, SCRJREFFRS1NRELATION);
	if (scrJref1NTablecol == comp->scrJref1NTablecol) insert(items, SCRJREF1NTABLECOL);
	if (scrJrefPst1NQuerymod == comp->scrJrefPst1NQuerymod) insert(items, SCRJREFPST1NQUERYMOD);
	if (pnlpst1nquerymodAvail == comp->pnlpst1nquerymodAvail) insert(items, PNLPST1NQUERYMODAVAIL);
	if (scrJrefAsbMNSubset == comp->scrJrefAsbMNSubset) insert(items, SCRJREFASBMNSUBSET);
	if (scrJrefBsbMNSubset == comp->scrJrefBsbMNSubset) insert(items, SCRJREFBSBMNSUBSET);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmSbsRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREF1NSTUB, SCRJREFTOS1NRELATION, SCRJREFFRS1NRELATION, SCRJREF1NTABLECOL, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFASBMNSUBSET, SCRJREFBSBMNSUBSET, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSbsRec::Tag
 ******************************************************************************/

PnlWznmSbsRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmSbsRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmSbsRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmSbsRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmSbsRec::DpchAppDo
 ******************************************************************************/

PnlWznmSbsRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSBSRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmSbsRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSbsRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmSbsRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSbsRec::DpchEngData
 ******************************************************************************/

PnlWznmSbsRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSBSRECDATA)
		{
};

string PnlWznmSbsRec::DpchEngData::getSrefsMask() {
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

void PnlWznmSbsRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmSbsRecData");
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

