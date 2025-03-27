/**
	* \file PnlWznmVerRec_blks.cpp
	* job handler for job PnlWznmVerRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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
			, TxtRef(TxtRef)
		{
	mask = {TXTREF};
};

void PnlWznmVerRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVerRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
};

void PnlWznmVerRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVerRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmVerRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWznmVerRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdoneVer1NVisual
			, const bool initdoneVer1NError
			, const bool initdoneVer1NApp
			, const bool initdone1NCapability
			, const bool initdone1NVector
			, const bool initdone1NTable
			, const bool initdone1NRelation
			, const bool initdone1NQuery
			, const bool initdone1NPreset
			, const bool initdoneVer1NModule
			, const bool initdone1NOppack
			, const bool initdone1NJob
			, const bool initdone1NImpexpcplx
			, const bool initdone1NCall
			, const bool initdone1NComponent
			, const bool initdoneBvr1NVersion
			, const bool initdone1NBlock
			, const bool initdoneRef1NFile
			, const bool initdoneMNLocale
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVerRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdoneVer1NVisual"] = initdoneVer1NVisual;
	me["initdoneVer1NError"] = initdoneVer1NError;
	me["initdoneVer1NApp"] = initdoneVer1NApp;
	me["initdone1NCapability"] = initdone1NCapability;
	me["initdone1NVector"] = initdone1NVector;
	me["initdone1NTable"] = initdone1NTable;
	me["initdone1NRelation"] = initdone1NRelation;
	me["initdone1NQuery"] = initdone1NQuery;
	me["initdone1NPreset"] = initdone1NPreset;
	me["initdoneVer1NModule"] = initdoneVer1NModule;
	me["initdone1NOppack"] = initdone1NOppack;
	me["initdone1NJob"] = initdone1NJob;
	me["initdone1NImpexpcplx"] = initdone1NImpexpcplx;
	me["initdone1NCall"] = initdone1NCall;
	me["initdone1NComponent"] = initdone1NComponent;
	me["initdoneBvr1NVersion"] = initdoneBvr1NVersion;
	me["initdone1NBlock"] = initdone1NBlock;
	me["initdoneRef1NFile"] = initdoneRef1NFile;
	me["initdoneMNLocale"] = initdoneMNLocale;
};

void PnlWznmVerRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneVer1NVisual
			, const bool initdoneVer1NError
			, const bool initdoneVer1NApp
			, const bool initdone1NCapability
			, const bool initdone1NVector
			, const bool initdone1NTable
			, const bool initdone1NRelation
			, const bool initdone1NQuery
			, const bool initdone1NPreset
			, const bool initdoneVer1NModule
			, const bool initdone1NOppack
			, const bool initdone1NJob
			, const bool initdone1NImpexpcplx
			, const bool initdone1NCall
			, const bool initdone1NComponent
			, const bool initdoneBvr1NVersion
			, const bool initdone1NBlock
			, const bool initdoneRef1NFile
			, const bool initdoneMNLocale
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVerRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmVerRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneVer1NVisual", initdoneVer1NVisual);
		writeBoolAttr(wr, itemtag, "sref", "initdoneVer1NError", initdoneVer1NError);
		writeBoolAttr(wr, itemtag, "sref", "initdoneVer1NApp", initdoneVer1NApp);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NCapability", initdone1NCapability);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NVector", initdone1NVector);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NTable", initdone1NTable);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NRelation", initdone1NRelation);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NQuery", initdone1NQuery);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NPreset", initdone1NPreset);
		writeBoolAttr(wr, itemtag, "sref", "initdoneVer1NModule", initdoneVer1NModule);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NOppack", initdone1NOppack);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NJob", initdone1NJob);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NImpexpcplx", initdone1NImpexpcplx);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NCall", initdone1NCall);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NComponent", initdone1NComponent);
		writeBoolAttr(wr, itemtag, "sref", "initdoneBvr1NVersion", initdoneBvr1NVersion);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NBlock", initdone1NBlock);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NFile", initdoneRef1NFile);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNLocale", initdoneMNLocale);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVerRec::StatShr
 ******************************************************************************/

PnlWznmVerRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefVer1NVisual
			, const ubigint jrefVer1NError
			, const ubigint jrefVer1NApp
			, const ubigint jref1NCapability
			, const ubigint jref1NVector
			, const ubigint jref1NTable
			, const ubigint jref1NRelation
			, const ubigint jref1NQuery
			, const ubigint jref1NPreset
			, const ubigint jrefVer1NModule
			, const ubigint jref1NOppack
			, const ubigint jref1NJob
			, const ubigint jref1NImpexpcplx
			, const ubigint jref1NCall
			, const ubigint jref1NComponent
			, const ubigint jrefBvr1NVersion
			, const ubigint jref1NBlock
			, const ubigint jrefRef1NFile
			, const ubigint jrefMNLocale
			, const bool ButRegularizeActive
		) :
			Block()
			, ixWznmVExpstate(ixWznmVExpstate)
			, jrefDetail(jrefDetail)
			, jrefVer1NVisual(jrefVer1NVisual)
			, jrefVer1NError(jrefVer1NError)
			, jrefVer1NApp(jrefVer1NApp)
			, jref1NCapability(jref1NCapability)
			, jref1NVector(jref1NVector)
			, jref1NTable(jref1NTable)
			, jref1NRelation(jref1NRelation)
			, jref1NQuery(jref1NQuery)
			, jref1NPreset(jref1NPreset)
			, jrefVer1NModule(jrefVer1NModule)
			, jref1NOppack(jref1NOppack)
			, jref1NJob(jref1NJob)
			, jref1NImpexpcplx(jref1NImpexpcplx)
			, jref1NCall(jref1NCall)
			, jref1NComponent(jref1NComponent)
			, jrefBvr1NVersion(jrefBvr1NVersion)
			, jref1NBlock(jref1NBlock)
			, jrefRef1NFile(jrefRef1NFile)
			, jrefMNLocale(jrefMNLocale)
			, ButRegularizeActive(ButRegularizeActive)
		{
	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFVER1NVISUAL, JREFVER1NERROR, JREFVER1NAPP, JREF1NCAPABILITY, JREF1NVECTOR, JREF1NTABLE, JREF1NRELATION, JREF1NQUERY, JREF1NPRESET, JREFVER1NMODULE, JREF1NOPPACK, JREF1NJOB, JREF1NIMPEXPCPLX, JREF1NCALL, JREF1NCOMPONENT, JREFBVR1NVERSION, JREF1NBLOCK, JREFREF1NFILE, JREFMNLOCALE, BUTREGULARIZEACTIVE};
};

void PnlWznmVerRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVerRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefVer1NVisual"] = Scr::scramble(jrefVer1NVisual);
	me["scrJrefVer1NError"] = Scr::scramble(jrefVer1NError);
	me["scrJrefVer1NApp"] = Scr::scramble(jrefVer1NApp);
	me["scrJref1NCapability"] = Scr::scramble(jref1NCapability);
	me["scrJref1NVector"] = Scr::scramble(jref1NVector);
	me["scrJref1NTable"] = Scr::scramble(jref1NTable);
	me["scrJref1NRelation"] = Scr::scramble(jref1NRelation);
	me["scrJref1NQuery"] = Scr::scramble(jref1NQuery);
	me["scrJref1NPreset"] = Scr::scramble(jref1NPreset);
	me["scrJrefVer1NModule"] = Scr::scramble(jrefVer1NModule);
	me["scrJref1NOppack"] = Scr::scramble(jref1NOppack);
	me["scrJref1NJob"] = Scr::scramble(jref1NJob);
	me["scrJref1NImpexpcplx"] = Scr::scramble(jref1NImpexpcplx);
	me["scrJref1NCall"] = Scr::scramble(jref1NCall);
	me["scrJref1NComponent"] = Scr::scramble(jref1NComponent);
	me["scrJrefBvr1NVersion"] = Scr::scramble(jrefBvr1NVersion);
	me["scrJref1NBlock"] = Scr::scramble(jref1NBlock);
	me["scrJrefRef1NFile"] = Scr::scramble(jrefRef1NFile);
	me["scrJrefMNLocale"] = Scr::scramble(jrefMNLocale);
	me["ButRegularizeActive"] = ButRegularizeActive;
};

void PnlWznmVerRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVerRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmVerRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefVer1NVisual", Scr::scramble(jrefVer1NVisual));
		writeStringAttr(wr, itemtag, "sref", "scrJrefVer1NError", Scr::scramble(jrefVer1NError));
		writeStringAttr(wr, itemtag, "sref", "scrJrefVer1NApp", Scr::scramble(jrefVer1NApp));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NCapability", Scr::scramble(jref1NCapability));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NVector", Scr::scramble(jref1NVector));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NTable", Scr::scramble(jref1NTable));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NRelation", Scr::scramble(jref1NRelation));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NQuery", Scr::scramble(jref1NQuery));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NPreset", Scr::scramble(jref1NPreset));
		writeStringAttr(wr, itemtag, "sref", "scrJrefVer1NModule", Scr::scramble(jrefVer1NModule));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NOppack", Scr::scramble(jref1NOppack));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NJob", Scr::scramble(jref1NJob));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NImpexpcplx", Scr::scramble(jref1NImpexpcplx));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NCall", Scr::scramble(jref1NCall));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NComponent", Scr::scramble(jref1NComponent));
		writeStringAttr(wr, itemtag, "sref", "scrJrefBvr1NVersion", Scr::scramble(jrefBvr1NVersion));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NBlock", Scr::scramble(jref1NBlock));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NFile", Scr::scramble(jrefRef1NFile));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNLocale", Scr::scramble(jrefMNLocale));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefVer1NVisual == comp->jrefVer1NVisual) insert(items, JREFVER1NVISUAL);
	if (jrefVer1NError == comp->jrefVer1NError) insert(items, JREFVER1NERROR);
	if (jrefVer1NApp == comp->jrefVer1NApp) insert(items, JREFVER1NAPP);
	if (jref1NCapability == comp->jref1NCapability) insert(items, JREF1NCAPABILITY);
	if (jref1NVector == comp->jref1NVector) insert(items, JREF1NVECTOR);
	if (jref1NTable == comp->jref1NTable) insert(items, JREF1NTABLE);
	if (jref1NRelation == comp->jref1NRelation) insert(items, JREF1NRELATION);
	if (jref1NQuery == comp->jref1NQuery) insert(items, JREF1NQUERY);
	if (jref1NPreset == comp->jref1NPreset) insert(items, JREF1NPRESET);
	if (jrefVer1NModule == comp->jrefVer1NModule) insert(items, JREFVER1NMODULE);
	if (jref1NOppack == comp->jref1NOppack) insert(items, JREF1NOPPACK);
	if (jref1NJob == comp->jref1NJob) insert(items, JREF1NJOB);
	if (jref1NImpexpcplx == comp->jref1NImpexpcplx) insert(items, JREF1NIMPEXPCPLX);
	if (jref1NCall == comp->jref1NCall) insert(items, JREF1NCALL);
	if (jref1NComponent == comp->jref1NComponent) insert(items, JREF1NCOMPONENT);
	if (jrefBvr1NVersion == comp->jrefBvr1NVersion) insert(items, JREFBVR1NVERSION);
	if (jref1NBlock == comp->jref1NBlock) insert(items, JREF1NBLOCK);
	if (jrefRef1NFile == comp->jrefRef1NFile) insert(items, JREFREF1NFILE);
	if (jrefMNLocale == comp->jrefMNLocale) insert(items, JREFMNLOCALE);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmVerRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFVER1NVISUAL, JREFVER1NERROR, JREFVER1NAPP, JREF1NCAPABILITY, JREF1NVECTOR, JREF1NTABLE, JREF1NRELATION, JREF1NQUERY, JREF1NPRESET, JREFVER1NMODULE, JREF1NOPPACK, JREF1NJOB, JREF1NIMPEXPCPLX, JREF1NCALL, JREF1NCOMPONENT, JREFBVR1NVERSION, JREF1NBLOCK, JREFREF1NFILE, JREFMNLOCALE, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVerRec::Tag
 ******************************************************************************/

void PnlWznmVerRec::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmVerRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["Cpt"] = "Version";
	};
};

void PnlWznmVerRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmVerRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmVerRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Version");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVerRec::DpchAppDo
 ******************************************************************************/

PnlWznmVerRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERRECDO)
		{
	ixVDo = 0;
};

string PnlWznmVerRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWznmVerRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmVerRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVerRecDo");
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
 class PnlWznmVerRec::DpchEngData
 ******************************************************************************/

PnlWznmVerRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVERRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmVerRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmVerRec::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmVerRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmVerRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmVerRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
