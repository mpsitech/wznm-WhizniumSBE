/**
	* \file PnlWznmQryRec_blks.cpp
	* job handler for job PnlWznmQryRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmQryRec::VecVDo
 ******************************************************************************/

uint PnlWznmQryRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmQryRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmQryRec::ContInf
 ******************************************************************************/

PnlWznmQryRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWznmQryRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmQryRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmQryRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQryRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmQryRec::ContInf::diff(
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
 class PnlWznmQryRec::StatApp
 ******************************************************************************/

void PnlWznmQryRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneAClause
			, const bool initdoneAOrder
			, const bool initdoneSup1NQuery
			, const bool initdone1NQuerymod
			, const bool initdoneQry1NQuerycol
			, const bool initdoneMNTable
			, const bool initdoneMNPanel
			, const bool initdoneMNDialog
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmQryRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmQryRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAClause", initdoneAClause);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAOrder", initdoneAOrder);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NQuery", initdoneSup1NQuery);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NQuerymod", initdone1NQuerymod);
		writeBoolAttr(wr, itemtag, "sref", "initdoneQry1NQuerycol", initdoneQry1NQuerycol);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNTable", initdoneMNTable);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNPanel", initdoneMNPanel);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNDialog", initdoneMNDialog);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQryRec::StatShr
 ******************************************************************************/

PnlWznmQryRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefAClause
			, const ubigint jrefAOrder
			, const ubigint jrefSup1NQuery
			, const ubigint jref1NQuerymod
			, const ubigint jrefQry1NQuerycol
			, const ubigint jrefMNTable
			, const ubigint jrefMNPanel
			, const ubigint jrefMNDialog
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefAClause = jrefAClause;
	this->jrefAOrder = jrefAOrder;
	this->jrefSup1NQuery = jrefSup1NQuery;
	this->jref1NQuerymod = jref1NQuerymod;
	this->jrefQry1NQuerycol = jrefQry1NQuerycol;
	this->jrefMNTable = jrefMNTable;
	this->jrefMNPanel = jrefMNPanel;
	this->jrefMNDialog = jrefMNDialog;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFACLAUSE, JREFAORDER, JREFSUP1NQUERY, JREF1NQUERYMOD, JREFQRY1NQUERYCOL, JREFMNTABLE, JREFMNPANEL, JREFMNDIALOG, BUTREGULARIZEACTIVE};
};

void PnlWznmQryRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmQryRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmQryRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAClause", Scr::scramble(jrefAClause));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAOrder", Scr::scramble(jrefAOrder));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NQuery", Scr::scramble(jrefSup1NQuery));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NQuerymod", Scr::scramble(jref1NQuerymod));
		writeStringAttr(wr, itemtag, "sref", "scrJrefQry1NQuerycol", Scr::scramble(jrefQry1NQuerycol));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNTable", Scr::scramble(jrefMNTable));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNPanel", Scr::scramble(jrefMNPanel));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNDialog", Scr::scramble(jrefMNDialog));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmQryRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefAClause == comp->jrefAClause) insert(items, JREFACLAUSE);
	if (jrefAOrder == comp->jrefAOrder) insert(items, JREFAORDER);
	if (jrefSup1NQuery == comp->jrefSup1NQuery) insert(items, JREFSUP1NQUERY);
	if (jref1NQuerymod == comp->jref1NQuerymod) insert(items, JREF1NQUERYMOD);
	if (jrefQry1NQuerycol == comp->jrefQry1NQuerycol) insert(items, JREFQRY1NQUERYCOL);
	if (jrefMNTable == comp->jrefMNTable) insert(items, JREFMNTABLE);
	if (jrefMNPanel == comp->jrefMNPanel) insert(items, JREFMNPANEL);
	if (jrefMNDialog == comp->jrefMNDialog) insert(items, JREFMNDIALOG);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmQryRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFACLAUSE, JREFAORDER, JREFSUP1NQUERY, JREF1NQUERYMOD, JREFQRY1NQUERYCOL, JREFMNTABLE, JREFMNPANEL, JREFMNDIALOG, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryRec::Tag
 ******************************************************************************/

void PnlWznmQryRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmQryRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmQryRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Query");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQryRec::DpchAppDo
 ******************************************************************************/

PnlWznmQryRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQRYRECDO)
		{
	ixVDo = 0;
};

string PnlWznmQryRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmQryRecDo");
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
 class PnlWznmQryRec::DpchEngData
 ******************************************************************************/

PnlWznmQryRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMQRYRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmQryRec::DpchEngData::getSrefsMask() {
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

void PnlWznmQryRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmQryRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmQryRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
