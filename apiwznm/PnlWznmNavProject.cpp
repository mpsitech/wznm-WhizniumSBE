/**
	* \file PnlWznmNavProject.cpp
	* API code for job PnlWznmNavProject (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmNavProject.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavProject::VecVDo
 ******************************************************************************/

uint PnlWznmNavProject::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	if (s == "butprjnewcrdclick") return BUTPRJNEWCRDCLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butvernewcrdclick") return BUTVERNEWCRDCLICK;
	if (s == "butcapviewclick") return BUTCAPVIEWCLICK;
	if (s == "butcapnewcrdclick") return BUTCAPNEWCRDCLICK;
	if (s == "buterrviewclick") return BUTERRVIEWCLICK;
	if (s == "buterrnewcrdclick") return BUTERRNEWCRDCLICK;

	return(0);
};

string PnlWznmNavProject::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTVERNEWCRDCLICK) return("ButVerNewcrdClick");
	if (ix == BUTCAPVIEWCLICK) return("ButCapViewClick");
	if (ix == BUTCAPNEWCRDCLICK) return("ButCapNewcrdClick");
	if (ix == BUTERRVIEWCLICK) return("ButErrViewClick");
	if (ix == BUTERRNEWCRDCLICK) return("ButErrNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavProject::ContIac
 ******************************************************************************/

PnlWznmNavProject::ContIac::ContIac(
			const uint numFLstPrj
			, const uint numFLstVer
			, const uint numFLstCap
			, const uint numFLstErr
		) :
			Block()
		{
	this->numFLstPrj = numFLstPrj;
	this->numFLstVer = numFLstVer;
	this->numFLstCap = numFLstCap;
	this->numFLstErr = numFLstErr;

	mask = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTCAP, NUMFLSTERR};
};

bool PnlWznmNavProject::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavProject");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavProject";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPrj", numFLstPrj)) add(NUMFLSTPRJ);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstVer", numFLstVer)) add(NUMFLSTVER);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCap", numFLstCap)) add(NUMFLSTCAP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstErr", numFLstErr)) add(NUMFLSTERR);
	};

	return basefound;
};

void PnlWznmNavProject::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavProject";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavProject";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPrj", numFLstPrj);
		writeUintAttr(wr, itemtag, "sref", "numFLstVer", numFLstVer);
		writeUintAttr(wr, itemtag, "sref", "numFLstCap", numFLstCap);
		writeUintAttr(wr, itemtag, "sref", "numFLstErr", numFLstErr);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavProject::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPrj == comp->numFLstPrj) insert(items, NUMFLSTPRJ);
	if (numFLstVer == comp->numFLstVer) insert(items, NUMFLSTVER);
	if (numFLstCap == comp->numFLstCap) insert(items, NUMFLSTCAP);
	if (numFLstErr == comp->numFLstErr) insert(items, NUMFLSTERR);

	return(items);
};

set<uint> PnlWznmNavProject::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPRJ, NUMFLSTVER, NUMFLSTCAP, NUMFLSTERR};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavProject::StatApp
 ******************************************************************************/

PnlWznmNavProject::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstPrjAlt
			, const bool LstVerAlt
			, const bool LstCapAlt
			, const bool LstErrAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstVerNumFirstdisp
			, const uint LstCapNumFirstdisp
			, const uint LstErrNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstPrjAlt = LstPrjAlt;
	this->LstVerAlt = LstVerAlt;
	this->LstCapAlt = LstCapAlt;
	this->LstErrAlt = LstErrAlt;
	this->LstPrjNumFirstdisp = LstPrjNumFirstdisp;
	this->LstVerNumFirstdisp = LstVerNumFirstdisp;
	this->LstCapNumFirstdisp = LstCapNumFirstdisp;
	this->LstErrNumFirstdisp = LstErrNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTPRJALT, LSTVERALT, LSTCAPALT, LSTERRALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTCAPNUMFIRSTDISP, LSTERRNUMFIRSTDISP};
};

bool PnlWznmNavProject::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavProject");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavProject";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAlt", LstPrjAlt)) add(LSTPRJALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerAlt", LstVerAlt)) add(LSTVERALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCapAlt", LstCapAlt)) add(LSTCAPALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrAlt", LstErrAlt)) add(LSTERRALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp)) add(LSTPRJNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerNumFirstdisp", LstVerNumFirstdisp)) add(LSTVERNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCapNumFirstdisp", LstCapNumFirstdisp)) add(LSTCAPNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrNumFirstdisp", LstErrNumFirstdisp)) add(LSTERRNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavProject::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstPrjAlt == comp->LstPrjAlt) insert(items, LSTPRJALT);
	if (LstVerAlt == comp->LstVerAlt) insert(items, LSTVERALT);
	if (LstCapAlt == comp->LstCapAlt) insert(items, LSTCAPALT);
	if (LstErrAlt == comp->LstErrAlt) insert(items, LSTERRALT);
	if (LstPrjNumFirstdisp == comp->LstPrjNumFirstdisp) insert(items, LSTPRJNUMFIRSTDISP);
	if (LstVerNumFirstdisp == comp->LstVerNumFirstdisp) insert(items, LSTVERNUMFIRSTDISP);
	if (LstCapNumFirstdisp == comp->LstCapNumFirstdisp) insert(items, LSTCAPNUMFIRSTDISP);
	if (LstErrNumFirstdisp == comp->LstErrNumFirstdisp) insert(items, LSTERRNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavProject::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTPRJALT, LSTVERALT, LSTCAPALT, LSTERRALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTCAPNUMFIRSTDISP, LSTERRNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavProject::StatShr
 ******************************************************************************/

PnlWznmNavProject::StatShr::StatShr(
			const bool LstPrjAvail
			, const bool ButPrjViewActive
			, const bool LstVerAvail
			, const bool ButVerViewActive
			, const bool LstCapAvail
			, const bool ButCapViewActive
			, const bool ButCapNewcrdActive
			, const bool LstErrAvail
			, const bool ButErrViewActive
			, const bool ButErrNewcrdActive
		) :
			Block()
		{
	this->LstPrjAvail = LstPrjAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->LstVerAvail = LstVerAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->LstCapAvail = LstCapAvail;
	this->ButCapViewActive = ButCapViewActive;
	this->ButCapNewcrdActive = ButCapNewcrdActive;
	this->LstErrAvail = LstErrAvail;
	this->ButErrViewActive = ButErrViewActive;
	this->ButErrNewcrdActive = ButErrNewcrdActive;

	mask = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTCAPAVAIL, BUTCAPVIEWACTIVE, BUTCAPNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE};
};

bool PnlWznmNavProject::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavProject");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavProject";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPrjAvail", LstPrjAvail)) add(LSTPRJAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", ButPrjViewActive)) add(BUTPRJVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstVerAvail", LstVerAvail)) add(LSTVERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButVerViewActive", ButVerViewActive)) add(BUTVERVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCapAvail", LstCapAvail)) add(LSTCAPAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCapViewActive", ButCapViewActive)) add(BUTCAPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCapNewcrdActive", ButCapNewcrdActive)) add(BUTCAPNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstErrAvail", LstErrAvail)) add(LSTERRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButErrViewActive", ButErrViewActive)) add(BUTERRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButErrNewcrdActive", ButErrNewcrdActive)) add(BUTERRNEWCRDACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmNavProject::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPrjAvail == comp->LstPrjAvail) insert(items, LSTPRJAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (LstVerAvail == comp->LstVerAvail) insert(items, LSTVERAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (LstCapAvail == comp->LstCapAvail) insert(items, LSTCAPAVAIL);
	if (ButCapViewActive == comp->ButCapViewActive) insert(items, BUTCAPVIEWACTIVE);
	if (ButCapNewcrdActive == comp->ButCapNewcrdActive) insert(items, BUTCAPNEWCRDACTIVE);
	if (LstErrAvail == comp->LstErrAvail) insert(items, LSTERRAVAIL);
	if (ButErrViewActive == comp->ButErrViewActive) insert(items, BUTERRVIEWACTIVE);
	if (ButErrNewcrdActive == comp->ButErrNewcrdActive) insert(items, BUTERRNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavProject::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTCAPAVAIL, BUTCAPVIEWACTIVE, BUTCAPNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavProject::Tag
 ******************************************************************************/

PnlWznmNavProject::Tag::Tag(
			const string& Cpt
			, const string& CptPrj
			, const string& CptVer
			, const string& CptCap
			, const string& CptErr
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPrj = CptPrj;
	this->CptVer = CptVer;
	this->CptCap = CptCap;
	this->CptErr = CptErr;

	mask = {CPT, CPTPRJ, CPTVER, CPTCAP, CPTERR};
};

bool PnlWznmNavProject::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavProject");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavProject";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPrj", CptPrj)) add(CPTPRJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptVer", CptVer)) add(CPTVER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCap", CptCap)) add(CPTCAP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptErr", CptErr)) add(CPTERR);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavProject::DpchAppData
 ******************************************************************************/

PnlWznmNavProject::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavProject::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavProject::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavProjectData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavProject::DpchAppDo
 ******************************************************************************/

PnlWznmNavProject::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavProject::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavProject::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavProjectDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavProject::DpchEngData
 ******************************************************************************/

PnlWznmNavProject::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVPROJECTDATA)
		{
	feedFLstCap.tag = "FeedFLstCap";
	feedFLstErr.tag = "FeedFLstErr";
	feedFLstPrj.tag = "FeedFLstPrj";
	feedFLstVer.tag = "FeedFLstVer";
};

string PnlWznmNavProject::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCAP)) ss.push_back("feedFLstCap");
	if (has(FEEDFLSTERR)) ss.push_back("feedFLstErr");
	if (has(FEEDFLSTPRJ)) ss.push_back("feedFLstPrj");
	if (has(FEEDFLSTVER)) ss.push_back("feedFLstVer");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavProject::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavProjectData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCap.readXML(docctx, basexpath, true)) add(FEEDFLSTCAP);
		if (feedFLstErr.readXML(docctx, basexpath, true)) add(FEEDFLSTERR);
		if (feedFLstPrj.readXML(docctx, basexpath, true)) add(FEEDFLSTPRJ);
		if (feedFLstVer.readXML(docctx, basexpath, true)) add(FEEDFLSTVER);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCap.clear();
		feedFLstErr.clear();
		feedFLstPrj.clear();
		feedFLstVer.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

