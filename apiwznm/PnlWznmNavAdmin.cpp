/**
	* \file PnlWznmNavAdmin.cpp
	* API code for job PnlWznmNavAdmin (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmNavAdmin.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavAdmin::VecVDo
 ******************************************************************************/

uint PnlWznmNavAdmin::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butusgviewclick") return BUTUSGVIEWCLICK;
	if (s == "butusgnewcrdclick") return BUTUSGNEWCRDCLICK;
	if (s == "butusrviewclick") return BUTUSRVIEWCLICK;
	if (s == "butusrnewcrdclick") return BUTUSRNEWCRDCLICK;
	if (s == "butprsviewclick") return BUTPRSVIEWCLICK;
	if (s == "butprsnewcrdclick") return BUTPRSNEWCRDCLICK;
	if (s == "butfilviewclick") return BUTFILVIEWCLICK;
	if (s == "butfilnewcrdclick") return BUTFILNEWCRDCLICK;

	return(0);
};

string PnlWznmNavAdmin::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
	if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
	if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
	if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
	if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
	if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
	if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
	if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavAdmin::ContIac
 ******************************************************************************/

PnlWznmNavAdmin::ContIac::ContIac(
			const uint numFLstUsg
			, const uint numFLstUsr
			, const uint numFLstPrs
			, const uint numFLstFil
		) :
			Block()
		{
	this->numFLstUsg = numFLstUsg;
	this->numFLstUsr = numFLstUsr;
	this->numFLstPrs = numFLstPrs;
	this->numFLstFil = numFLstFil;

	mask = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL};
};

bool PnlWznmNavAdmin::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavAdmin";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsg", numFLstUsg)) add(NUMFLSTUSG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstUsr", numFLstUsr)) add(NUMFLSTUSR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrs", numFLstPrs)) add(NUMFLSTPRS);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFil", numFLstFil)) add(NUMFLSTFIL);
	};

	return basefound;
};

void PnlWznmNavAdmin::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavAdmin";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavAdmin";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstUsg", numFLstUsg);
		writeUintAttr(wr, itemtag, "sref", "numFLstUsr", numFLstUsr);
		writeUintAttr(wr, itemtag, "sref", "numFLstPrs", numFLstPrs);
		writeUintAttr(wr, itemtag, "sref", "numFLstFil", numFLstFil);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavAdmin::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstUsg == comp->numFLstUsg) insert(items, NUMFLSTUSG);
	if (numFLstUsr == comp->numFLstUsr) insert(items, NUMFLSTUSR);
	if (numFLstPrs == comp->numFLstPrs) insert(items, NUMFLSTPRS);
	if (numFLstFil == comp->numFLstFil) insert(items, NUMFLSTFIL);

	return(items);
};

set<uint> PnlWznmNavAdmin::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAdmin::StatApp
 ******************************************************************************/

PnlWznmNavAdmin::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstUsgAlt
			, const bool LstUsrAlt
			, const bool LstPrsAlt
			, const bool LstFilAlt
			, const uint LstUsgNumFirstdisp
			, const uint LstUsrNumFirstdisp
			, const uint LstPrsNumFirstdisp
			, const uint LstFilNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstUsgAlt = LstUsgAlt;
	this->LstUsrAlt = LstUsrAlt;
	this->LstPrsAlt = LstPrsAlt;
	this->LstFilAlt = LstFilAlt;
	this->LstUsgNumFirstdisp = LstUsgNumFirstdisp;
	this->LstUsrNumFirstdisp = LstUsrNumFirstdisp;
	this->LstPrsNumFirstdisp = LstPrsNumFirstdisp;
	this->LstFilNumFirstdisp = LstFilNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTFILALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP, LSTFILNUMFIRSTDISP};
};

bool PnlWznmNavAdmin::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAlt", LstUsgAlt)) add(LSTUSGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAlt", LstUsrAlt)) add(LSTUSRALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAlt", LstPrsAlt)) add(LSTPRSALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAlt", LstFilAlt)) add(LSTFILALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgNumFirstdisp", LstUsgNumFirstdisp)) add(LSTUSGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrNumFirstdisp", LstUsrNumFirstdisp)) add(LSTUSRNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsNumFirstdisp", LstPrsNumFirstdisp)) add(LSTPRSNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", LstFilNumFirstdisp)) add(LSTFILNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavAdmin::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstUsgAlt == comp->LstUsgAlt) insert(items, LSTUSGALT);
	if (LstUsrAlt == comp->LstUsrAlt) insert(items, LSTUSRALT);
	if (LstPrsAlt == comp->LstPrsAlt) insert(items, LSTPRSALT);
	if (LstFilAlt == comp->LstFilAlt) insert(items, LSTFILALT);
	if (LstUsgNumFirstdisp == comp->LstUsgNumFirstdisp) insert(items, LSTUSGNUMFIRSTDISP);
	if (LstUsrNumFirstdisp == comp->LstUsrNumFirstdisp) insert(items, LSTUSRNUMFIRSTDISP);
	if (LstPrsNumFirstdisp == comp->LstPrsNumFirstdisp) insert(items, LSTPRSNUMFIRSTDISP);
	if (LstFilNumFirstdisp == comp->LstFilNumFirstdisp) insert(items, LSTFILNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavAdmin::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTFILALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP, LSTFILNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAdmin::StatShr
 ******************************************************************************/

PnlWznmNavAdmin::StatShr::StatShr(
			const bool LstUsgAvail
			, const bool ButUsgViewActive
			, const bool LstUsrAvail
			, const bool ButUsrViewActive
			, const bool LstPrsAvail
			, const bool ButPrsViewActive
			, const bool LstFilAvail
			, const bool ButFilViewActive
		) :
			Block()
		{
	this->LstUsgAvail = LstUsgAvail;
	this->ButUsgViewActive = ButUsgViewActive;
	this->LstUsrAvail = LstUsrAvail;
	this->ButUsrViewActive = ButUsrViewActive;
	this->LstPrsAvail = LstPrsAvail;
	this->ButPrsViewActive = ButPrsViewActive;
	this->LstFilAvail = LstFilAvail;
	this->ButFilViewActive = ButFilViewActive;

	mask = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
};

bool PnlWznmNavAdmin::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavAdmin";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsgAvail", LstUsgAvail)) add(LSTUSGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", ButUsgViewActive)) add(BUTUSGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstUsrAvail", LstUsrAvail)) add(LSTUSRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", ButUsrViewActive)) add(BUTUSRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrsAvail", LstPrsAvail)) add(LSTPRSAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", ButPrsViewActive)) add(BUTPRSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFilAvail", LstFilAvail)) add(LSTFILAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFilViewActive", ButFilViewActive)) add(BUTFILVIEWACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmNavAdmin::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstUsgAvail == comp->LstUsgAvail) insert(items, LSTUSGAVAIL);
	if (ButUsgViewActive == comp->ButUsgViewActive) insert(items, BUTUSGVIEWACTIVE);
	if (LstUsrAvail == comp->LstUsrAvail) insert(items, LSTUSRAVAIL);
	if (ButUsrViewActive == comp->ButUsrViewActive) insert(items, BUTUSRVIEWACTIVE);
	if (LstPrsAvail == comp->LstPrsAvail) insert(items, LSTPRSAVAIL);
	if (ButPrsViewActive == comp->ButPrsViewActive) insert(items, BUTPRSVIEWACTIVE);
	if (LstFilAvail == comp->LstFilAvail) insert(items, LSTFILAVAIL);
	if (ButFilViewActive == comp->ButFilViewActive) insert(items, BUTFILVIEWACTIVE);

	return(items);
};

set<uint> PnlWznmNavAdmin::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavAdmin::Tag
 ******************************************************************************/

PnlWznmNavAdmin::Tag::Tag(
			const string& Cpt
			, const string& CptUsg
			, const string& CptUsr
			, const string& CptPrs
			, const string& CptFil
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptUsg = CptUsg;
	this->CptUsr = CptUsr;
	this->CptPrs = CptPrs;
	this->CptFil = CptFil;

	mask = {CPT, CPTUSG, CPTUSR, CPTPRS, CPTFIL};
};

bool PnlWznmNavAdmin::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavAdmin");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavAdmin";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsg", CptUsg)) add(CPTUSG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptUsr", CptUsr)) add(CPTUSR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrs", CptPrs)) add(CPTPRS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFil", CptFil)) add(CPTFIL);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavAdmin::DpchAppData
 ******************************************************************************/

PnlWznmNavAdmin::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVADMINDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavAdmin::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAdmin::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavAdminData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAdmin::DpchAppDo
 ******************************************************************************/

PnlWznmNavAdmin::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVADMINDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavAdmin::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAdmin::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavAdminDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavAdmin::DpchEngData
 ******************************************************************************/

PnlWznmNavAdmin::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVADMINDATA)
		{
	feedFLstFil.tag = "FeedFLstFil";
	feedFLstPrs.tag = "FeedFLstPrs";
	feedFLstUsg.tag = "FeedFLstUsg";
	feedFLstUsr.tag = "FeedFLstUsr";
};

string PnlWznmNavAdmin::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTFIL)) ss.push_back("feedFLstFil");
	if (has(FEEDFLSTPRS)) ss.push_back("feedFLstPrs");
	if (has(FEEDFLSTUSG)) ss.push_back("feedFLstUsg");
	if (has(FEEDFLSTUSR)) ss.push_back("feedFLstUsr");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavAdmin::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavAdminData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstFil.readXML(docctx, basexpath, true)) add(FEEDFLSTFIL);
		if (feedFLstPrs.readXML(docctx, basexpath, true)) add(FEEDFLSTPRS);
		if (feedFLstUsg.readXML(docctx, basexpath, true)) add(FEEDFLSTUSG);
		if (feedFLstUsr.readXML(docctx, basexpath, true)) add(FEEDFLSTUSR);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstFil.clear();
		feedFLstPrs.clear();
		feedFLstUsg.clear();
		feedFLstUsr.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
