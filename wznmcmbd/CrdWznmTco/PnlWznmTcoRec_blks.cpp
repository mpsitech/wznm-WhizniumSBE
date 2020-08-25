/**
	* \file PnlWznmTcoRec_blks.cpp
	* job handler for job PnlWznmTcoRec (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTcoRec::VecVDo
 ******************************************************************************/

uint PnlWznmTcoRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmTcoRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmTcoRec::ContInf
 ******************************************************************************/

PnlWznmTcoRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWznmTcoRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmTcoRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmTcoRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTcoRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmTcoRec::ContInf::diff(
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
 class PnlWznmTcoRec::StatApp
 ******************************************************************************/

void PnlWznmTcoRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdone1NImpexpcol
			, const bool initdone1NQuerycol
			, const bool initdoneRef1NQuerymod
			, const bool initdoneRef1NControl
			, const bool initdone1NCheck
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmTcoRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmTcoRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneATitle", initdoneATitle);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NImpexpcol", initdone1NImpexpcol);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NQuerycol", initdone1NQuerycol);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NQuerymod", initdoneRef1NQuerymod);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NControl", initdoneRef1NControl);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NCheck", initdone1NCheck);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTcoRec::StatShr
 ******************************************************************************/

PnlWznmTcoRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefATitle
			, const bool pnlatitleAvail
			, const ubigint jref1NImpexpcol
			, const bool pnl1nimpexpcolAvail
			, const ubigint jref1NQuerycol
			, const bool pnl1nquerycolAvail
			, const ubigint jrefRef1NQuerymod
			, const bool pnlref1nquerymodAvail
			, const ubigint jrefRef1NControl
			, const bool pnlref1ncontrolAvail
			, const ubigint jref1NCheck
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefATitle = jrefATitle;
	this->pnlatitleAvail = pnlatitleAvail;
	this->jref1NImpexpcol = jref1NImpexpcol;
	this->pnl1nimpexpcolAvail = pnl1nimpexpcolAvail;
	this->jref1NQuerycol = jref1NQuerycol;
	this->pnl1nquerycolAvail = pnl1nquerycolAvail;
	this->jrefRef1NQuerymod = jrefRef1NQuerymod;
	this->pnlref1nquerymodAvail = pnlref1nquerymodAvail;
	this->jrefRef1NControl = jrefRef1NControl;
	this->pnlref1ncontrolAvail = pnlref1ncontrolAvail;
	this->jref1NCheck = jref1NCheck;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, PNLATITLEAVAIL, JREF1NIMPEXPCOL, PNL1NIMPEXPCOLAVAIL, JREF1NQUERYCOL, PNL1NQUERYCOLAVAIL, JREFREF1NQUERYMOD, PNLREF1NQUERYMODAVAIL, JREFREF1NCONTROL, PNLREF1NCONTROLAVAIL, JREF1NCHECK, BUTREGULARIZEACTIVE};
};

void PnlWznmTcoRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmTcoRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmTcoRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefATitle", Scr::scramble(jrefATitle));
		writeBoolAttr(wr, itemtag, "sref", "pnlatitleAvail", pnlatitleAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NImpexpcol", Scr::scramble(jref1NImpexpcol));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nimpexpcolAvail", pnl1nimpexpcolAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NQuerycol", Scr::scramble(jref1NQuerycol));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nquerycolAvail", pnl1nquerycolAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NQuerymod", Scr::scramble(jrefRef1NQuerymod));
		writeBoolAttr(wr, itemtag, "sref", "pnlref1nquerymodAvail", pnlref1nquerymodAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NControl", Scr::scramble(jrefRef1NControl));
		writeBoolAttr(wr, itemtag, "sref", "pnlref1ncontrolAvail", pnlref1ncontrolAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NCheck", Scr::scramble(jref1NCheck));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTcoRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefATitle == comp->jrefATitle) insert(items, JREFATITLE);
	if (pnlatitleAvail == comp->pnlatitleAvail) insert(items, PNLATITLEAVAIL);
	if (jref1NImpexpcol == comp->jref1NImpexpcol) insert(items, JREF1NIMPEXPCOL);
	if (pnl1nimpexpcolAvail == comp->pnl1nimpexpcolAvail) insert(items, PNL1NIMPEXPCOLAVAIL);
	if (jref1NQuerycol == comp->jref1NQuerycol) insert(items, JREF1NQUERYCOL);
	if (pnl1nquerycolAvail == comp->pnl1nquerycolAvail) insert(items, PNL1NQUERYCOLAVAIL);
	if (jrefRef1NQuerymod == comp->jrefRef1NQuerymod) insert(items, JREFREF1NQUERYMOD);
	if (pnlref1nquerymodAvail == comp->pnlref1nquerymodAvail) insert(items, PNLREF1NQUERYMODAVAIL);
	if (jrefRef1NControl == comp->jrefRef1NControl) insert(items, JREFREF1NCONTROL);
	if (pnlref1ncontrolAvail == comp->pnlref1ncontrolAvail) insert(items, PNLREF1NCONTROLAVAIL);
	if (jref1NCheck == comp->jref1NCheck) insert(items, JREF1NCHECK);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmTcoRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, PNLATITLEAVAIL, JREF1NIMPEXPCOL, PNL1NIMPEXPCOLAVAIL, JREF1NQUERYCOL, PNL1NQUERYCOLAVAIL, JREFREF1NQUERYMOD, PNLREF1NQUERYMODAVAIL, JREFREF1NCONTROL, PNLREF1NCONTROLAVAIL, JREF1NCHECK, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoRec::Tag
 ******************************************************************************/

void PnlWznmTcoRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmTcoRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmTcoRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Table column");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTcoRec::DpchAppDo
 ******************************************************************************/

PnlWznmTcoRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTCORECDO)
		{
	ixVDo = 0;
};

string PnlWznmTcoRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTcoRecDo");
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
 class PnlWznmTcoRec::DpchEngData
 ******************************************************************************/

PnlWznmTcoRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTCORECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmTcoRec::DpchEngData::getSrefsMask() {
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

void PnlWznmTcoRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmTcoRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmTcoRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

