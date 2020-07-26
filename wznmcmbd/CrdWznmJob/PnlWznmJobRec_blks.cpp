/**
	* \file PnlWznmJobRec_blks.cpp
	* job handler for job PnlWznmJobRec (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

void PnlWznmJobRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmJobRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWznmJobRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneAVar
			, const bool initdoneACmd
			, const bool initdone1NMethod
			, const bool initdone1NRtjob
			, const bool initdoneJob1NStage
			, const bool initdone1NSensitivity
			, const bool initdoneHk1NVector
			, const bool initdoneRef1NBlock
			, const bool initdoneMNOp
			, const bool initdoneMNOppack
			, const bool initdoneSupMNJob
			, const bool initdoneSubMNJob
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmJobRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAVar", initdoneAVar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneACmd", initdoneACmd);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NMethod", initdone1NMethod);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NRtjob", initdone1NRtjob);
		writeBoolAttr(wr, itemtag, "sref", "initdoneJob1NStage", initdoneJob1NStage);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NSensitivity", initdone1NSensitivity);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NVector", initdoneHk1NVector);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NBlock", initdoneRef1NBlock);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNOp", initdoneMNOp);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNOppack", initdoneMNOppack);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSupMNJob", initdoneSupMNJob);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSubMNJob", initdoneSubMNJob);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmJobRec::StatShr
 ******************************************************************************/

PnlWznmJobRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefAVar
			, const ubigint jrefACmd
			, const ubigint jref1NMethod
			, const ubigint jref1NRtjob
			, const ubigint jrefJob1NStage
			, const ubigint jref1NSensitivity
			, const ubigint jrefHk1NVector
			, const ubigint jrefRef1NBlock
			, const ubigint jrefMNOp
			, const ubigint jrefMNOppack
			, const ubigint jrefSupMNJob
			, const bool pnlsupmnjobAvail
			, const ubigint jrefSubMNJob
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefAVar = jrefAVar;
	this->jrefACmd = jrefACmd;
	this->jref1NMethod = jref1NMethod;
	this->jref1NRtjob = jref1NRtjob;
	this->jrefJob1NStage = jrefJob1NStage;
	this->jref1NSensitivity = jref1NSensitivity;
	this->jrefHk1NVector = jrefHk1NVector;
	this->jrefRef1NBlock = jrefRef1NBlock;
	this->jrefMNOp = jrefMNOp;
	this->jrefMNOppack = jrefMNOppack;
	this->jrefSupMNJob = jrefSupMNJob;
	this->pnlsupmnjobAvail = pnlsupmnjobAvail;
	this->jrefSubMNJob = jrefSubMNJob;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFAVAR, JREFACMD, JREF1NMETHOD, JREF1NRTJOB, JREFJOB1NSTAGE, JREF1NSENSITIVITY, JREFHK1NVECTOR, JREFREF1NBLOCK, JREFMNOP, JREFMNOPPACK, JREFSUPMNJOB, PNLSUPMNJOBAVAIL, JREFSUBMNJOB, BUTREGULARIZEACTIVE};
};

void PnlWznmJobRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmJobRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAVar", Scr::scramble(jrefAVar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefACmd", Scr::scramble(jrefACmd));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NMethod", Scr::scramble(jref1NMethod));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NRtjob", Scr::scramble(jref1NRtjob));
		writeStringAttr(wr, itemtag, "sref", "scrJrefJob1NStage", Scr::scramble(jrefJob1NStage));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NSensitivity", Scr::scramble(jref1NSensitivity));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NVector", Scr::scramble(jrefHk1NVector));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NBlock", Scr::scramble(jrefRef1NBlock));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNOp", Scr::scramble(jrefMNOp));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNOppack", Scr::scramble(jrefMNOppack));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSupMNJob", Scr::scramble(jrefSupMNJob));
		writeBoolAttr(wr, itemtag, "sref", "pnlsupmnjobAvail", pnlsupmnjobAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefSubMNJob", Scr::scramble(jrefSubMNJob));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmJobRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefAVar == comp->jrefAVar) insert(items, JREFAVAR);
	if (jrefACmd == comp->jrefACmd) insert(items, JREFACMD);
	if (jref1NMethod == comp->jref1NMethod) insert(items, JREF1NMETHOD);
	if (jref1NRtjob == comp->jref1NRtjob) insert(items, JREF1NRTJOB);
	if (jrefJob1NStage == comp->jrefJob1NStage) insert(items, JREFJOB1NSTAGE);
	if (jref1NSensitivity == comp->jref1NSensitivity) insert(items, JREF1NSENSITIVITY);
	if (jrefHk1NVector == comp->jrefHk1NVector) insert(items, JREFHK1NVECTOR);
	if (jrefRef1NBlock == comp->jrefRef1NBlock) insert(items, JREFREF1NBLOCK);
	if (jrefMNOp == comp->jrefMNOp) insert(items, JREFMNOP);
	if (jrefMNOppack == comp->jrefMNOppack) insert(items, JREFMNOPPACK);
	if (jrefSupMNJob == comp->jrefSupMNJob) insert(items, JREFSUPMNJOB);
	if (pnlsupmnjobAvail == comp->pnlsupmnjobAvail) insert(items, PNLSUPMNJOBAVAIL);
	if (jrefSubMNJob == comp->jrefSubMNJob) insert(items, JREFSUBMNJOB);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmJobRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFAVAR, JREFACMD, JREF1NMETHOD, JREF1NRTJOB, JREFJOB1NSTAGE, JREF1NSENSITIVITY, JREFHK1NVECTOR, JREFREF1NBLOCK, JREFMNOP, JREFMNOPPACK, JREFSUPMNJOB, PNLSUPMNJOBAVAIL, JREFSUBMNJOB, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmJobRec::Tag
 ******************************************************************************/

void PnlWznmJobRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmJobRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmJobRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Job");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmJobRec::DpchAppDo
 ******************************************************************************/

PnlWznmJobRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMJOBRECDO)
		{
	ixVDo = 0;
};

string PnlWznmJobRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmJobRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmJobRecDo");
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
 class PnlWznmJobRec::DpchEngData
 ******************************************************************************/

PnlWznmJobRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMJOBRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmJobRec::DpchEngData::getSrefsMask() {
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

void PnlWznmJobRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmJobRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmJobRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

