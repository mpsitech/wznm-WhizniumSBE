/**
	* \file PnlWznmVerRec.cpp
	* API code for job PnlWznmVerRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmVerRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVerRec::VecVDo
 ******************************************************************************/

uint PnlWznmVerRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmVerRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmVerRec::ContInf
 ******************************************************************************/

PnlWznmVerRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmVerRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmVerRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmVerRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmVerRec::ContInf::diff(
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
 class PnlWznmVerRec::StatApp
 ******************************************************************************/

PnlWznmVerRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdone1NBlock
			, const bool initdoneBvr1NVersion
			, const bool initdone1NComponent
			, const bool initdone1NCall
			, const bool initdone1NImpexpcplx
			, const bool initdone1NJob
			, const bool initdone1NOppack
			, const bool initdoneVer1NModule
			, const bool initdone1NPreset
			, const bool initdone1NQuery
			, const bool initdone1NRelation
			, const bool initdone1NTable
			, const bool initdone1NVector
			, const bool initdone1NCapability
			, const bool initdoneVer1NApp
			, const bool initdoneVer1NError
			, const bool initdoneRef1NFile
			, const bool initdoneMNLocale
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdone1NBlock = initdone1NBlock;
	this->initdoneBvr1NVersion = initdoneBvr1NVersion;
	this->initdone1NComponent = initdone1NComponent;
	this->initdone1NCall = initdone1NCall;
	this->initdone1NImpexpcplx = initdone1NImpexpcplx;
	this->initdone1NJob = initdone1NJob;
	this->initdone1NOppack = initdone1NOppack;
	this->initdoneVer1NModule = initdoneVer1NModule;
	this->initdone1NPreset = initdone1NPreset;
	this->initdone1NQuery = initdone1NQuery;
	this->initdone1NRelation = initdone1NRelation;
	this->initdone1NTable = initdone1NTable;
	this->initdone1NVector = initdone1NVector;
	this->initdone1NCapability = initdone1NCapability;
	this->initdoneVer1NApp = initdoneVer1NApp;
	this->initdoneVer1NError = initdoneVer1NError;
	this->initdoneRef1NFile = initdoneRef1NFile;
	this->initdoneMNLocale = initdoneMNLocale;

	mask = {INITDONEDETAIL, INITDONE1NBLOCK, INITDONEBVR1NVERSION, INITDONE1NCOMPONENT, INITDONE1NCALL, INITDONE1NIMPEXPCPLX, INITDONE1NJOB, INITDONE1NOPPACK, INITDONEVER1NMODULE, INITDONE1NPRESET, INITDONE1NQUERY, INITDONE1NRELATION, INITDONE1NTABLE, INITDONE1NVECTOR, INITDONE1NCAPABILITY, INITDONEVER1NAPP, INITDONEVER1NERROR, INITDONEREF1NFILE, INITDONEMNLOCALE};
};

bool PnlWznmVerRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmVerRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NBlock", initdone1NBlock)) add(INITDONE1NBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneBvr1NVersion", initdoneBvr1NVersion)) add(INITDONEBVR1NVERSION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NComponent", initdone1NComponent)) add(INITDONE1NCOMPONENT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NCall", initdone1NCall)) add(INITDONE1NCALL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NImpexpcplx", initdone1NImpexpcplx)) add(INITDONE1NIMPEXPCPLX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NJob", initdone1NJob)) add(INITDONE1NJOB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NOppack", initdone1NOppack)) add(INITDONE1NOPPACK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneVer1NModule", initdoneVer1NModule)) add(INITDONEVER1NMODULE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NPreset", initdone1NPreset)) add(INITDONE1NPRESET);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NQuery", initdone1NQuery)) add(INITDONE1NQUERY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NRelation", initdone1NRelation)) add(INITDONE1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NTable", initdone1NTable)) add(INITDONE1NTABLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NVector", initdone1NVector)) add(INITDONE1NVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NCapability", initdone1NCapability)) add(INITDONE1NCAPABILITY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneVer1NApp", initdoneVer1NApp)) add(INITDONEVER1NAPP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneVer1NError", initdoneVer1NError)) add(INITDONEVER1NERROR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", initdoneRef1NFile)) add(INITDONEREF1NFILE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNLocale", initdoneMNLocale)) add(INITDONEMNLOCALE);
	};

	return basefound;
};

set<uint> PnlWznmVerRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdone1NBlock == comp->initdone1NBlock) insert(items, INITDONE1NBLOCK);
	if (initdoneBvr1NVersion == comp->initdoneBvr1NVersion) insert(items, INITDONEBVR1NVERSION);
	if (initdone1NComponent == comp->initdone1NComponent) insert(items, INITDONE1NCOMPONENT);
	if (initdone1NCall == comp->initdone1NCall) insert(items, INITDONE1NCALL);
	if (initdone1NImpexpcplx == comp->initdone1NImpexpcplx) insert(items, INITDONE1NIMPEXPCPLX);
	if (initdone1NJob == comp->initdone1NJob) insert(items, INITDONE1NJOB);
	if (initdone1NOppack == comp->initdone1NOppack) insert(items, INITDONE1NOPPACK);
	if (initdoneVer1NModule == comp->initdoneVer1NModule) insert(items, INITDONEVER1NMODULE);
	if (initdone1NPreset == comp->initdone1NPreset) insert(items, INITDONE1NPRESET);
	if (initdone1NQuery == comp->initdone1NQuery) insert(items, INITDONE1NQUERY);
	if (initdone1NRelation == comp->initdone1NRelation) insert(items, INITDONE1NRELATION);
	if (initdone1NTable == comp->initdone1NTable) insert(items, INITDONE1NTABLE);
	if (initdone1NVector == comp->initdone1NVector) insert(items, INITDONE1NVECTOR);
	if (initdone1NCapability == comp->initdone1NCapability) insert(items, INITDONE1NCAPABILITY);
	if (initdoneVer1NApp == comp->initdoneVer1NApp) insert(items, INITDONEVER1NAPP);
	if (initdoneVer1NError == comp->initdoneVer1NError) insert(items, INITDONEVER1NERROR);
	if (initdoneRef1NFile == comp->initdoneRef1NFile) insert(items, INITDONEREF1NFILE);
	if (initdoneMNLocale == comp->initdoneMNLocale) insert(items, INITDONEMNLOCALE);

	return(items);
};

set<uint> PnlWznmVerRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONE1NBLOCK, INITDONEBVR1NVERSION, INITDONE1NCOMPONENT, INITDONE1NCALL, INITDONE1NIMPEXPCPLX, INITDONE1NJOB, INITDONE1NOPPACK, INITDONEVER1NMODULE, INITDONE1NPRESET, INITDONE1NQUERY, INITDONE1NRELATION, INITDONE1NTABLE, INITDONE1NVECTOR, INITDONE1NCAPABILITY, INITDONEVER1NAPP, INITDONEVER1NERROR, INITDONEREF1NFILE, INITDONEMNLOCALE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVerRec::StatShr
 ******************************************************************************/

PnlWznmVerRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJref1NBlock
			, const string& scrJrefBvr1NVersion
			, const string& scrJref1NComponent
			, const string& scrJref1NCall
			, const string& scrJref1NImpexpcplx
			, const string& scrJref1NJob
			, const string& scrJref1NOppack
			, const string& scrJrefVer1NModule
			, const string& scrJref1NPreset
			, const string& scrJref1NQuery
			, const string& scrJref1NRelation
			, const string& scrJref1NTable
			, const string& scrJref1NVector
			, const string& scrJref1NCapability
			, const string& scrJrefVer1NApp
			, const string& scrJrefVer1NError
			, const string& scrJrefRef1NFile
			, const string& scrJrefMNLocale
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJref1NBlock = scrJref1NBlock;
	this->scrJrefBvr1NVersion = scrJrefBvr1NVersion;
	this->scrJref1NComponent = scrJref1NComponent;
	this->scrJref1NCall = scrJref1NCall;
	this->scrJref1NImpexpcplx = scrJref1NImpexpcplx;
	this->scrJref1NJob = scrJref1NJob;
	this->scrJref1NOppack = scrJref1NOppack;
	this->scrJrefVer1NModule = scrJrefVer1NModule;
	this->scrJref1NPreset = scrJref1NPreset;
	this->scrJref1NQuery = scrJref1NQuery;
	this->scrJref1NRelation = scrJref1NRelation;
	this->scrJref1NTable = scrJref1NTable;
	this->scrJref1NVector = scrJref1NVector;
	this->scrJref1NCapability = scrJref1NCapability;
	this->scrJrefVer1NApp = scrJrefVer1NApp;
	this->scrJrefVer1NError = scrJrefVer1NError;
	this->scrJrefRef1NFile = scrJrefRef1NFile;
	this->scrJrefMNLocale = scrJrefMNLocale;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBLOCK, SCRJREFBVR1NVERSION, SCRJREF1NCOMPONENT, SCRJREF1NCALL, SCRJREF1NIMPEXPCPLX, SCRJREF1NJOB, SCRJREF1NOPPACK, SCRJREFVER1NMODULE, SCRJREF1NPRESET, SCRJREF1NQUERY, SCRJREF1NRELATION, SCRJREF1NTABLE, SCRJREF1NVECTOR, SCRJREF1NCAPABILITY, SCRJREFVER1NAPP, SCRJREFVER1NERROR, SCRJREFREF1NFILE, SCRJREFMNLOCALE, BUTREGULARIZEACTIVE};
};

bool PnlWznmVerRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmVerRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NBlock", scrJref1NBlock)) add(SCRJREF1NBLOCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefBvr1NVersion", scrJrefBvr1NVersion)) add(SCRJREFBVR1NVERSION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NComponent", scrJref1NComponent)) add(SCRJREF1NCOMPONENT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NCall", scrJref1NCall)) add(SCRJREF1NCALL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NImpexpcplx", scrJref1NImpexpcplx)) add(SCRJREF1NIMPEXPCPLX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NJob", scrJref1NJob)) add(SCRJREF1NJOB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NOppack", scrJref1NOppack)) add(SCRJREF1NOPPACK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefVer1NModule", scrJrefVer1NModule)) add(SCRJREFVER1NMODULE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NPreset", scrJref1NPreset)) add(SCRJREF1NPRESET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NQuery", scrJref1NQuery)) add(SCRJREF1NQUERY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NRelation", scrJref1NRelation)) add(SCRJREF1NRELATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NTable", scrJref1NTable)) add(SCRJREF1NTABLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NVector", scrJref1NVector)) add(SCRJREF1NVECTOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NCapability", scrJref1NCapability)) add(SCRJREF1NCAPABILITY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefVer1NApp", scrJrefVer1NApp)) add(SCRJREFVER1NAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefVer1NError", scrJrefVer1NError)) add(SCRJREFVER1NERROR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", scrJrefRef1NFile)) add(SCRJREFREF1NFILE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNLocale", scrJrefMNLocale)) add(SCRJREFMNLOCALE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmVerRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJref1NBlock == comp->scrJref1NBlock) insert(items, SCRJREF1NBLOCK);
	if (scrJrefBvr1NVersion == comp->scrJrefBvr1NVersion) insert(items, SCRJREFBVR1NVERSION);
	if (scrJref1NComponent == comp->scrJref1NComponent) insert(items, SCRJREF1NCOMPONENT);
	if (scrJref1NCall == comp->scrJref1NCall) insert(items, SCRJREF1NCALL);
	if (scrJref1NImpexpcplx == comp->scrJref1NImpexpcplx) insert(items, SCRJREF1NIMPEXPCPLX);
	if (scrJref1NJob == comp->scrJref1NJob) insert(items, SCRJREF1NJOB);
	if (scrJref1NOppack == comp->scrJref1NOppack) insert(items, SCRJREF1NOPPACK);
	if (scrJrefVer1NModule == comp->scrJrefVer1NModule) insert(items, SCRJREFVER1NMODULE);
	if (scrJref1NPreset == comp->scrJref1NPreset) insert(items, SCRJREF1NPRESET);
	if (scrJref1NQuery == comp->scrJref1NQuery) insert(items, SCRJREF1NQUERY);
	if (scrJref1NRelation == comp->scrJref1NRelation) insert(items, SCRJREF1NRELATION);
	if (scrJref1NTable == comp->scrJref1NTable) insert(items, SCRJREF1NTABLE);
	if (scrJref1NVector == comp->scrJref1NVector) insert(items, SCRJREF1NVECTOR);
	if (scrJref1NCapability == comp->scrJref1NCapability) insert(items, SCRJREF1NCAPABILITY);
	if (scrJrefVer1NApp == comp->scrJrefVer1NApp) insert(items, SCRJREFVER1NAPP);
	if (scrJrefVer1NError == comp->scrJrefVer1NError) insert(items, SCRJREFVER1NERROR);
	if (scrJrefRef1NFile == comp->scrJrefRef1NFile) insert(items, SCRJREFREF1NFILE);
	if (scrJrefMNLocale == comp->scrJrefMNLocale) insert(items, SCRJREFMNLOCALE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmVerRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREF1NBLOCK, SCRJREFBVR1NVERSION, SCRJREF1NCOMPONENT, SCRJREF1NCALL, SCRJREF1NIMPEXPCPLX, SCRJREF1NJOB, SCRJREF1NOPPACK, SCRJREFVER1NMODULE, SCRJREF1NPRESET, SCRJREF1NQUERY, SCRJREF1NRELATION, SCRJREF1NTABLE, SCRJREF1NVECTOR, SCRJREF1NCAPABILITY, SCRJREFVER1NAPP, SCRJREFVER1NERROR, SCRJREFREF1NFILE, SCRJREFMNLOCALE, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVerRec::Tag
 ******************************************************************************/

PnlWznmVerRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmVerRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmVerRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmVerRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmVerRec::DpchAppDo
 ******************************************************************************/

PnlWznmVerRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmVerRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmVerRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVerRec::DpchEngData
 ******************************************************************************/

PnlWznmVerRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVERRECDATA)
		{
};

string PnlWznmVerRec::DpchEngData::getSrefsMask() {
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

void PnlWznmVerRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmVerRecData");
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

