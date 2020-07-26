/**
	* \file PnlWznmRelRec_blks.cpp
	* job handler for job PnlWznmRelRec (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

void PnlWznmRelRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmRelRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmRelRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWznmRelRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdone1NTablecol
			, const bool initdoneSup1NRelation
			, const bool initdoneRef1NPanel
			, const bool initdoneRef1NControl
			, const bool initdoneRef1NDialog
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmRelRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmRelRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneATitle", initdoneATitle);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NTablecol", initdone1NTablecol);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NRelation", initdoneSup1NRelation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NPanel", initdoneRef1NPanel);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NControl", initdoneRef1NControl);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NDialog", initdoneRef1NDialog);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelRec::StatShr
 ******************************************************************************/

PnlWznmRelRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefATitle
			, const ubigint jref1NTablecol
			, const ubigint jrefSup1NRelation
			, const ubigint jrefRef1NPanel
			, const ubigint jrefRef1NControl
			, const ubigint jrefRef1NDialog
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefATitle = jrefATitle;
	this->jref1NTablecol = jref1NTablecol;
	this->jrefSup1NRelation = jrefSup1NRelation;
	this->jrefRef1NPanel = jrefRef1NPanel;
	this->jrefRef1NControl = jrefRef1NControl;
	this->jrefRef1NDialog = jrefRef1NDialog;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, JREF1NTABLECOL, JREFSUP1NRELATION, JREFREF1NPANEL, JREFREF1NCONTROL, JREFREF1NDIALOG, BUTREGULARIZEACTIVE};
};

void PnlWznmRelRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmRelRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmRelRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefATitle", Scr::scramble(jrefATitle));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NTablecol", Scr::scramble(jref1NTablecol));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NRelation", Scr::scramble(jrefSup1NRelation));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NPanel", Scr::scramble(jrefRef1NPanel));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NControl", Scr::scramble(jrefRef1NControl));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NDialog", Scr::scramble(jrefRef1NDialog));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefATitle == comp->jrefATitle) insert(items, JREFATITLE);
	if (jref1NTablecol == comp->jref1NTablecol) insert(items, JREF1NTABLECOL);
	if (jrefSup1NRelation == comp->jrefSup1NRelation) insert(items, JREFSUP1NRELATION);
	if (jrefRef1NPanel == comp->jrefRef1NPanel) insert(items, JREFREF1NPANEL);
	if (jrefRef1NControl == comp->jrefRef1NControl) insert(items, JREFREF1NCONTROL);
	if (jrefRef1NDialog == comp->jrefRef1NDialog) insert(items, JREFREF1NDIALOG);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmRelRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, JREF1NTABLECOL, JREFSUP1NRELATION, JREFREF1NPANEL, JREFREF1NCONTROL, JREFREF1NDIALOG, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelRec::Tag
 ******************************************************************************/

void PnlWznmRelRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmRelRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmRelRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Relation");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelRec::DpchAppDo
 ******************************************************************************/

PnlWznmRelRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELRECDO)
		{
	ixVDo = 0;
};

string PnlWznmRelRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmRelRecDo");
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
 class PnlWznmRelRec::DpchEngData
 ******************************************************************************/

PnlWznmRelRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRELRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmRelRec::DpchEngData::getSrefsMask() {
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

void PnlWznmRelRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmRelRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmRelRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

