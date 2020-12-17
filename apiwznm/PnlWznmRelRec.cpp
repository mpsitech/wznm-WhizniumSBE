/**
	* \file PnlWznmRelRec.cpp
	* API code for job PnlWznmRelRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmRelRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmRelRec::VecVDo
 ******************************************************************************/

uint PnlWznmRelRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmRelRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmRelRec::ContInf
 ******************************************************************************/

PnlWznmRelRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmRelRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmRelRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmRelRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmRelRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmRelRec::ContInf::diff(
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
 class PnlWznmRelRec::StatApp
 ******************************************************************************/

PnlWznmRelRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdoneSup1NRelation
			, const bool initdone1NTablecol
			, const bool initdoneRef1NPanel
			, const bool initdoneRef1NDialog
			, const bool initdoneRef1NControl
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneATitle = initdoneATitle;
	this->initdoneSup1NRelation = initdoneSup1NRelation;
	this->initdone1NTablecol = initdone1NTablecol;
	this->initdoneRef1NPanel = initdoneRef1NPanel;
	this->initdoneRef1NDialog = initdoneRef1NDialog;
	this->initdoneRef1NControl = initdoneRef1NControl;

	mask = {INITDONEDETAIL, INITDONEATITLE, INITDONESUP1NRELATION, INITDONE1NTABLECOL, INITDONEREF1NPANEL, INITDONEREF1NDIALOG, INITDONEREF1NCONTROL};
};

bool PnlWznmRelRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmRelRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmRelRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneATitle", initdoneATitle)) add(INITDONEATITLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NRelation", initdoneSup1NRelation)) add(INITDONESUP1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NTablecol", initdone1NTablecol)) add(INITDONE1NTABLECOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NPanel", initdoneRef1NPanel)) add(INITDONEREF1NPANEL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NDialog", initdoneRef1NDialog)) add(INITDONEREF1NDIALOG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NControl", initdoneRef1NControl)) add(INITDONEREF1NCONTROL);
	};

	return basefound;
};

set<uint> PnlWznmRelRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneATitle == comp->initdoneATitle) insert(items, INITDONEATITLE);
	if (initdoneSup1NRelation == comp->initdoneSup1NRelation) insert(items, INITDONESUP1NRELATION);
	if (initdone1NTablecol == comp->initdone1NTablecol) insert(items, INITDONE1NTABLECOL);
	if (initdoneRef1NPanel == comp->initdoneRef1NPanel) insert(items, INITDONEREF1NPANEL);
	if (initdoneRef1NDialog == comp->initdoneRef1NDialog) insert(items, INITDONEREF1NDIALOG);
	if (initdoneRef1NControl == comp->initdoneRef1NControl) insert(items, INITDONEREF1NCONTROL);

	return(items);
};

set<uint> PnlWznmRelRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEATITLE, INITDONESUP1NRELATION, INITDONE1NTABLECOL, INITDONEREF1NPANEL, INITDONEREF1NDIALOG, INITDONEREF1NCONTROL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelRec::StatShr
 ******************************************************************************/

PnlWznmRelRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefATitle
			, const string& scrJrefSup1NRelation
			, const string& scrJref1NTablecol
			, const string& scrJrefRef1NPanel
			, const string& scrJrefRef1NDialog
			, const string& scrJrefRef1NControl
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefATitle = scrJrefATitle;
	this->scrJrefSup1NRelation = scrJrefSup1NRelation;
	this->scrJref1NTablecol = scrJref1NTablecol;
	this->scrJrefRef1NPanel = scrJrefRef1NPanel;
	this->scrJrefRef1NDialog = scrJrefRef1NDialog;
	this->scrJrefRef1NControl = scrJrefRef1NControl;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFSUP1NRELATION, SCRJREF1NTABLECOL, SCRJREFREF1NPANEL, SCRJREFREF1NDIALOG, SCRJREFREF1NCONTROL, BUTREGULARIZEACTIVE};
};

bool PnlWznmRelRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmRelRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmRelRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefATitle", scrJrefATitle)) add(SCRJREFATITLE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NRelation", scrJrefSup1NRelation)) add(SCRJREFSUP1NRELATION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NTablecol", scrJref1NTablecol)) add(SCRJREF1NTABLECOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NPanel", scrJrefRef1NPanel)) add(SCRJREFREF1NPANEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NDialog", scrJrefRef1NDialog)) add(SCRJREFREF1NDIALOG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NControl", scrJrefRef1NControl)) add(SCRJREFREF1NCONTROL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmRelRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefATitle == comp->scrJrefATitle) insert(items, SCRJREFATITLE);
	if (scrJrefSup1NRelation == comp->scrJrefSup1NRelation) insert(items, SCRJREFSUP1NRELATION);
	if (scrJref1NTablecol == comp->scrJref1NTablecol) insert(items, SCRJREF1NTABLECOL);
	if (scrJrefRef1NPanel == comp->scrJrefRef1NPanel) insert(items, SCRJREFREF1NPANEL);
	if (scrJrefRef1NDialog == comp->scrJrefRef1NDialog) insert(items, SCRJREFREF1NDIALOG);
	if (scrJrefRef1NControl == comp->scrJrefRef1NControl) insert(items, SCRJREFREF1NCONTROL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmRelRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFSUP1NRELATION, SCRJREF1NTABLECOL, SCRJREFREF1NPANEL, SCRJREFREF1NDIALOG, SCRJREFREF1NCONTROL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelRec::Tag
 ******************************************************************************/

PnlWznmRelRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmRelRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmRelRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmRelRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmRelRec::DpchAppDo
 ******************************************************************************/

PnlWznmRelRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmRelRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmRelRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelRec::DpchEngData
 ******************************************************************************/

PnlWznmRelRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRELRECDATA)
		{
};

string PnlWznmRelRec::DpchEngData::getSrefsMask() {
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

void PnlWznmRelRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmRelRecData");
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
