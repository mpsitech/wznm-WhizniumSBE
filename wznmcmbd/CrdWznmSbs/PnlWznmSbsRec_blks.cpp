/**
	* \file PnlWznmSbsRec_blks.cpp
	* job handler for job PnlWznmSbsRec (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

void PnlWznmSbsRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmSbsRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmSbsRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWznmSbsRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdone1NStub
			, const bool initdone1NTablecol
			, const bool initdoneTos1NRelation
			, const bool initdoneFrs1NRelation
			, const bool initdonePst1NQuerymod
			, const bool initdoneAsbMNSubset
			, const bool initdoneBsbMNSubset
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmSbsRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmSbsRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneATitle", initdoneATitle);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NStub", initdone1NStub);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NTablecol", initdone1NTablecol);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTos1NRelation", initdoneTos1NRelation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFrs1NRelation", initdoneFrs1NRelation);
		writeBoolAttr(wr, itemtag, "sref", "initdonePst1NQuerymod", initdonePst1NQuerymod);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAsbMNSubset", initdoneAsbMNSubset);
		writeBoolAttr(wr, itemtag, "sref", "initdoneBsbMNSubset", initdoneBsbMNSubset);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSbsRec::StatShr
 ******************************************************************************/

PnlWznmSbsRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefATitle
			, const ubigint jref1NStub
			, const ubigint jref1NTablecol
			, const ubigint jrefTos1NRelation
			, const ubigint jrefFrs1NRelation
			, const ubigint jrefPst1NQuerymod
			, const bool pnlpst1nquerymodAvail
			, const ubigint jrefAsbMNSubset
			, const ubigint jrefBsbMNSubset
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefATitle = jrefATitle;
	this->jref1NStub = jref1NStub;
	this->jref1NTablecol = jref1NTablecol;
	this->jrefTos1NRelation = jrefTos1NRelation;
	this->jrefFrs1NRelation = jrefFrs1NRelation;
	this->jrefPst1NQuerymod = jrefPst1NQuerymod;
	this->pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
	this->jrefAsbMNSubset = jrefAsbMNSubset;
	this->jrefBsbMNSubset = jrefBsbMNSubset;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, JREF1NSTUB, JREF1NTABLECOL, JREFTOS1NRELATION, JREFFRS1NRELATION, JREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, JREFASBMNSUBSET, JREFBSBMNSUBSET, BUTREGULARIZEACTIVE};
};

void PnlWznmSbsRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmSbsRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmSbsRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefATitle", Scr::scramble(jrefATitle));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NStub", Scr::scramble(jref1NStub));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NTablecol", Scr::scramble(jref1NTablecol));
		writeStringAttr(wr, itemtag, "sref", "scrJrefTos1NRelation", Scr::scramble(jrefTos1NRelation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefFrs1NRelation", Scr::scramble(jrefFrs1NRelation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefPst1NQuerymod", Scr::scramble(jrefPst1NQuerymod));
		writeBoolAttr(wr, itemtag, "sref", "pnlpst1nquerymodAvail", pnlpst1nquerymodAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefAsbMNSubset", Scr::scramble(jrefAsbMNSubset));
		writeStringAttr(wr, itemtag, "sref", "scrJrefBsbMNSubset", Scr::scramble(jrefBsbMNSubset));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSbsRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefATitle == comp->jrefATitle) insert(items, JREFATITLE);
	if (jref1NStub == comp->jref1NStub) insert(items, JREF1NSTUB);
	if (jref1NTablecol == comp->jref1NTablecol) insert(items, JREF1NTABLECOL);
	if (jrefTos1NRelation == comp->jrefTos1NRelation) insert(items, JREFTOS1NRELATION);
	if (jrefFrs1NRelation == comp->jrefFrs1NRelation) insert(items, JREFFRS1NRELATION);
	if (jrefPst1NQuerymod == comp->jrefPst1NQuerymod) insert(items, JREFPST1NQUERYMOD);
	if (pnlpst1nquerymodAvail == comp->pnlpst1nquerymodAvail) insert(items, PNLPST1NQUERYMODAVAIL);
	if (jrefAsbMNSubset == comp->jrefAsbMNSubset) insert(items, JREFASBMNSUBSET);
	if (jrefBsbMNSubset == comp->jrefBsbMNSubset) insert(items, JREFBSBMNSUBSET);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmSbsRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, JREF1NSTUB, JREF1NTABLECOL, JREFTOS1NRELATION, JREFFRS1NRELATION, JREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, JREFASBMNSUBSET, JREFBSBMNSUBSET, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSbsRec::Tag
 ******************************************************************************/

void PnlWznmSbsRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmSbsRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmSbsRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Subset");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSbsRec::DpchAppDo
 ******************************************************************************/

PnlWznmSbsRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSBSRECDO)
		{
	ixVDo = 0;
};

string PnlWznmSbsRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSbsRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSbsRecDo");
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
 class PnlWznmSbsRec::DpchEngData
 ******************************************************************************/

PnlWznmSbsRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSBSRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmSbsRec::DpchEngData::getSrefsMask() {
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

void PnlWznmSbsRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmSbsRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmSbsRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

