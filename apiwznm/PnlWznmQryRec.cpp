/**
	* \file PnlWznmQryRec.cpp
	* API code for job PnlWznmQryRec (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmQryRec.h"

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

bool PnlWznmQryRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmQryRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmQryRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
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

PnlWznmQryRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneAOrder
			, const bool initdoneAClause
			, const bool initdoneSup1NQuery
			, const bool initdoneQry1NQuerycol
			, const bool initdone1NQuerymod
			, const bool initdoneMNTable
			, const bool initdoneMNDialog
			, const bool initdoneMNPanel
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneAOrder = initdoneAOrder;
	this->initdoneAClause = initdoneAClause;
	this->initdoneSup1NQuery = initdoneSup1NQuery;
	this->initdoneQry1NQuerycol = initdoneQry1NQuerycol;
	this->initdone1NQuerymod = initdone1NQuerymod;
	this->initdoneMNTable = initdoneMNTable;
	this->initdoneMNDialog = initdoneMNDialog;
	this->initdoneMNPanel = initdoneMNPanel;

	mask = {INITDONEDETAIL, INITDONEAORDER, INITDONEACLAUSE, INITDONESUP1NQUERY, INITDONEQRY1NQUERYCOL, INITDONE1NQUERYMOD, INITDONEMNTABLE, INITDONEMNDIALOG, INITDONEMNPANEL};
};

bool PnlWznmQryRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmQryRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmQryRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAOrder", initdoneAOrder)) add(INITDONEAORDER);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAClause", initdoneAClause)) add(INITDONEACLAUSE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NQuery", initdoneSup1NQuery)) add(INITDONESUP1NQUERY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneQry1NQuerycol", initdoneQry1NQuerycol)) add(INITDONEQRY1NQUERYCOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NQuerymod", initdone1NQuerymod)) add(INITDONE1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNTable", initdoneMNTable)) add(INITDONEMNTABLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNDialog", initdoneMNDialog)) add(INITDONEMNDIALOG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNPanel", initdoneMNPanel)) add(INITDONEMNPANEL);
	};

	return basefound;
};

set<uint> PnlWznmQryRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneAOrder == comp->initdoneAOrder) insert(items, INITDONEAORDER);
	if (initdoneAClause == comp->initdoneAClause) insert(items, INITDONEACLAUSE);
	if (initdoneSup1NQuery == comp->initdoneSup1NQuery) insert(items, INITDONESUP1NQUERY);
	if (initdoneQry1NQuerycol == comp->initdoneQry1NQuerycol) insert(items, INITDONEQRY1NQUERYCOL);
	if (initdone1NQuerymod == comp->initdone1NQuerymod) insert(items, INITDONE1NQUERYMOD);
	if (initdoneMNTable == comp->initdoneMNTable) insert(items, INITDONEMNTABLE);
	if (initdoneMNDialog == comp->initdoneMNDialog) insert(items, INITDONEMNDIALOG);
	if (initdoneMNPanel == comp->initdoneMNPanel) insert(items, INITDONEMNPANEL);

	return(items);
};

set<uint> PnlWznmQryRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEAORDER, INITDONEACLAUSE, INITDONESUP1NQUERY, INITDONEQRY1NQUERYCOL, INITDONE1NQUERYMOD, INITDONEMNTABLE, INITDONEMNDIALOG, INITDONEMNPANEL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryRec::StatShr
 ******************************************************************************/

PnlWznmQryRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefAOrder
			, const string& scrJrefAClause
			, const string& scrJrefSup1NQuery
			, const string& scrJrefQry1NQuerycol
			, const string& scrJref1NQuerymod
			, const string& scrJrefMNTable
			, const string& scrJrefMNDialog
			, const string& scrJrefMNPanel
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefAOrder = scrJrefAOrder;
	this->scrJrefAClause = scrJrefAClause;
	this->scrJrefSup1NQuery = scrJrefSup1NQuery;
	this->scrJrefQry1NQuerycol = scrJrefQry1NQuerycol;
	this->scrJref1NQuerymod = scrJref1NQuerymod;
	this->scrJrefMNTable = scrJrefMNTable;
	this->scrJrefMNDialog = scrJrefMNDialog;
	this->scrJrefMNPanel = scrJrefMNPanel;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAORDER, SCRJREFACLAUSE, SCRJREFSUP1NQUERY, SCRJREFQRY1NQUERYCOL, SCRJREF1NQUERYMOD, SCRJREFMNTABLE, SCRJREFMNDIALOG, SCRJREFMNPANEL, BUTREGULARIZEACTIVE};
};

bool PnlWznmQryRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmQryRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmQryRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAOrder", scrJrefAOrder)) add(SCRJREFAORDER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAClause", scrJrefAClause)) add(SCRJREFACLAUSE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NQuery", scrJrefSup1NQuery)) add(SCRJREFSUP1NQUERY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefQry1NQuerycol", scrJrefQry1NQuerycol)) add(SCRJREFQRY1NQUERYCOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NQuerymod", scrJref1NQuerymod)) add(SCRJREF1NQUERYMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNTable", scrJrefMNTable)) add(SCRJREFMNTABLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNDialog", scrJrefMNDialog)) add(SCRJREFMNDIALOG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNPanel", scrJrefMNPanel)) add(SCRJREFMNPANEL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmQryRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefAOrder == comp->scrJrefAOrder) insert(items, SCRJREFAORDER);
	if (scrJrefAClause == comp->scrJrefAClause) insert(items, SCRJREFACLAUSE);
	if (scrJrefSup1NQuery == comp->scrJrefSup1NQuery) insert(items, SCRJREFSUP1NQUERY);
	if (scrJrefQry1NQuerycol == comp->scrJrefQry1NQuerycol) insert(items, SCRJREFQRY1NQUERYCOL);
	if (scrJref1NQuerymod == comp->scrJref1NQuerymod) insert(items, SCRJREF1NQUERYMOD);
	if (scrJrefMNTable == comp->scrJrefMNTable) insert(items, SCRJREFMNTABLE);
	if (scrJrefMNDialog == comp->scrJrefMNDialog) insert(items, SCRJREFMNDIALOG);
	if (scrJrefMNPanel == comp->scrJrefMNPanel) insert(items, SCRJREFMNPANEL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmQryRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAORDER, SCRJREFACLAUSE, SCRJREFSUP1NQUERY, SCRJREFQRY1NQUERYCOL, SCRJREF1NQUERYMOD, SCRJREFMNTABLE, SCRJREFMNDIALOG, SCRJREFMNPANEL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmQryRec::Tag
 ******************************************************************************/

PnlWznmQryRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmQryRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmQryRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmQryRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmQryRec::DpchAppDo
 ******************************************************************************/

PnlWznmQryRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMQRYRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmQryRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmQryRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmQryRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmQryRec::DpchEngData
 ******************************************************************************/

PnlWznmQryRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMQRYRECDATA)
		{
};

string PnlWznmQryRec::DpchEngData::getSrefsMask() {
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

void PnlWznmQryRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmQryRecData");
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

