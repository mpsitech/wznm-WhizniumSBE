/**
	* \file PnlWznmNavProject_blks.cpp
	* job handler for job PnlWznmNavProject (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void PnlWznmNavProject::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstPrjAlt
			, const bool LstVerAlt
			, const bool LstCapAlt
			, const bool LstErrAlt
			, const uint LstPrjNumFirstdisp
			, const uint LstVerNumFirstdisp
			, const uint LstCapNumFirstdisp
			, const uint LstErrNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavProject";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavProject";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAlt", LstPrjAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstVerAlt", LstVerAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCapAlt", LstCapAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstErrAlt", LstErrAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPrjNumFirstdisp", LstPrjNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstVerNumFirstdisp", LstVerNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCapNumFirstdisp", LstCapNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstErrNumFirstdisp", LstErrNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWznmNavProject::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavProject";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavProject";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstPrjAvail", LstPrjAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewActive", ButPrjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstVerAvail", LstVerAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewActive", ButVerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCapAvail", LstCapAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCapViewActive", ButCapViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCapNewcrdActive", ButCapNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstErrAvail", LstErrAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButErrViewActive", ButErrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButErrNewcrdActive", ButErrNewcrdActive);
	xmlTextWriterEndElement(wr);
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

void PnlWznmNavProject::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavProject";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavProject";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Project management module");
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "projects");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "versions");
			writeStringAttr(wr, itemtag, "sref", "CptCap", "capabilities");
			writeStringAttr(wr, itemtag, "sref", "CptErr", "errors");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavProject::DpchAppData
 ******************************************************************************/

PnlWznmNavProject::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDATA)
		{
};

string PnlWznmNavProject::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavProject::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavProjectData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWznmNavProject::DpchAppDo
 ******************************************************************************/

PnlWznmNavProject::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDO)
		{
	ixVDo = 0;
};

string PnlWznmNavProject::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavProject::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavProjectDo");
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
 class PnlWznmNavProject::DpchEngData
 ******************************************************************************/

PnlWznmNavProject::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCap
			, Feed* feedFLstErr
			, Feed* feedFLstPrj
			, Feed* feedFLstVer
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVPROJECTDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCAP, FEEDFLSTERR, FEEDFLSTPRJ, FEEDFLSTVER, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCAP) && feedFLstCap) this->feedFLstCap = *feedFLstCap;
	if (find(this->mask, FEEDFLSTERR) && feedFLstErr) this->feedFLstErr = *feedFLstErr;
	if (find(this->mask, FEEDFLSTPRJ) && feedFLstPrj) this->feedFLstPrj = *feedFLstPrj;
	if (find(this->mask, FEEDFLSTVER) && feedFLstVer) this->feedFLstVer = *feedFLstVer;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavProject::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWznmNavProject::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCAP)) {feedFLstCap = src->feedFLstCap; add(FEEDFLSTCAP);};
	if (src->has(FEEDFLSTERR)) {feedFLstErr = src->feedFLstErr; add(FEEDFLSTERR);};
	if (src->has(FEEDFLSTPRJ)) {feedFLstPrj = src->feedFLstPrj; add(FEEDFLSTPRJ);};
	if (src->has(FEEDFLSTVER)) {feedFLstVer = src->feedFLstVer; add(FEEDFLSTVER);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavProject::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavProjectData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCAP)) feedFLstCap.writeXML(wr);
		if (has(FEEDFLSTERR)) feedFLstErr.writeXML(wr);
		if (has(FEEDFLSTPRJ)) feedFLstPrj.writeXML(wr);
		if (has(FEEDFLSTVER)) feedFLstVer.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};



