/**
	* \file PnlWznmSgeDetail_blks.cpp
	* job handler for job PnlWznmSgeDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmSgeDetail::VecVDo
 ******************************************************************************/

uint PnlWznmSgeDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjobviewclick") return BUTJOBVIEWCLICK;
	if (s == "butsnxviewclick") return BUTSNXVIEWCLICK;
	if (s == "butfnxviewclick") return BUTFNXVIEWCLICK;
	if (s == "butsqknewclick") return BUTSQKNEWCLICK;
	if (s == "butsqkdeleteclick") return BUTSQKDELETECLICK;
	if (s == "butsqkjtieditclick") return BUTSQKJTIEDITCLICK;

	return(0);
};

string PnlWznmSgeDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
	if (ix == BUTSNXVIEWCLICK) return("ButSnxViewClick");
	if (ix == BUTFNXVIEWCLICK) return("ButFnxViewClick");
	if (ix == BUTSQKNEWCLICK) return("ButSqkNewClick");
	if (ix == BUTSQKDELETECLICK) return("ButSqkDeleteClick");
	if (ix == BUTSQKJTIEDITCLICK) return("ButSqkJtiEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmSgeDetail::ContIac
 ******************************************************************************/

PnlWznmSgeDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const string& TxfMon
			, const string& TxfCmt
			, const uint numFPupSqkJti
			, const string& TxfSqkExa
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->TxfMon = TxfMon;
	this->TxfCmt = TxfCmt;
	this->numFPupSqkJti = numFPupSqkJti;
	this->TxfSqkExa = TxfSqkExa;

	mask = {NUMFPUPTYP, TXFMON, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
};

bool PnlWznmSgeDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmSgeDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmSgeDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMon", TxfMon)) add(TXFMON);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSqkJti", numFPupSqkJti)) add(NUMFPUPSQKJTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSqkExa", TxfSqkExa)) add(TXFSQKEXA);
	};

	return basefound;
};

void PnlWznmSgeDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmSgeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmSgeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeStringAttr(wr, itemtag, "sref", "TxfMon", TxfMon);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
		writeUintAttr(wr, itemtag, "sref", "numFPupSqkJti", numFPupSqkJti);
		writeStringAttr(wr, itemtag, "sref", "TxfSqkExa", TxfSqkExa);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSgeDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (TxfMon == comp->TxfMon) insert(items, TXFMON);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);
	if (numFPupSqkJti == comp->numFPupSqkJti) insert(items, NUMFPUPSQKJTI);
	if (TxfSqkExa == comp->TxfSqkExa) insert(items, TXFSQKEXA);

	return(items);
};

set<uint> PnlWznmSgeDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, TXFMON, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSgeDetail::ContInf
 ******************************************************************************/

PnlWznmSgeDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtJob
			, const string& TxtSnx
			, const string& TxtFnx
			, const string& TxtSqkTit
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtJob = TxtJob;
	this->TxtSnx = TxtSnx;
	this->TxtFnx = TxtFnx;
	this->TxtSqkTit = TxtSqkTit;

	mask = {TXTSRF, TXTJOB, TXTSNX, TXTFNX, TXTSQKTIT};
};

void PnlWznmSgeDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmSgeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmSgeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtJob", TxtJob);
		writeStringAttr(wr, itemtag, "sref", "TxtSnx", TxtSnx);
		writeStringAttr(wr, itemtag, "sref", "TxtFnx", TxtFnx);
		writeStringAttr(wr, itemtag, "sref", "TxtSqkTit", TxtSqkTit);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSgeDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtJob == comp->TxtJob) insert(items, TXTJOB);
	if (TxtSnx == comp->TxtSnx) insert(items, TXTSNX);
	if (TxtFnx == comp->TxtFnx) insert(items, TXTFNX);
	if (TxtSqkTit == comp->TxtSqkTit) insert(items, TXTSQKTIT);

	return(items);
};

set<uint> PnlWznmSgeDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTJOB, TXTSNX, TXTFNX, TXTSQKTIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSgeDetail::StatApp
 ******************************************************************************/

void PnlWznmSgeDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmSgeDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmSgeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSgeDetail::StatShr
 ******************************************************************************/

PnlWznmSgeDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupTypActive
			, const bool TxtJobActive
			, const bool ButJobViewAvail
			, const bool ButJobViewActive
			, const bool TxfMonActive
			, const bool TxtSnxActive
			, const bool ButSnxViewAvail
			, const bool ButSnxViewActive
			, const bool TxtFnxActive
			, const bool ButFnxViewAvail
			, const bool ButFnxViewActive
			, const bool TxfCmtActive
			, const bool ButSqkNewAvail
			, const bool ButSqkDeleteAvail
			, const bool PupSqkJtiAvail
			, const bool PupSqkJtiActive
			, const bool ButSqkJtiEditAvail
			, const bool TxtSqkTitAvail
			, const bool TxtSqkTitActive
			, const bool TxfSqkExaAvail
			, const bool TxfSqkExaActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupTypActive = PupTypActive;
	this->TxtJobActive = TxtJobActive;
	this->ButJobViewAvail = ButJobViewAvail;
	this->ButJobViewActive = ButJobViewActive;
	this->TxfMonActive = TxfMonActive;
	this->TxtSnxActive = TxtSnxActive;
	this->ButSnxViewAvail = ButSnxViewAvail;
	this->ButSnxViewActive = ButSnxViewActive;
	this->TxtFnxActive = TxtFnxActive;
	this->ButFnxViewAvail = ButFnxViewAvail;
	this->ButFnxViewActive = ButFnxViewActive;
	this->TxfCmtActive = TxfCmtActive;
	this->ButSqkNewAvail = ButSqkNewAvail;
	this->ButSqkDeleteAvail = ButSqkDeleteAvail;
	this->PupSqkJtiAvail = PupSqkJtiAvail;
	this->PupSqkJtiActive = PupSqkJtiActive;
	this->ButSqkJtiEditAvail = ButSqkJtiEditAvail;
	this->TxtSqkTitAvail = TxtSqkTitAvail;
	this->TxtSqkTitActive = TxtSqkTitActive;
	this->TxfSqkExaAvail = TxfSqkExaAvail;
	this->TxfSqkExaActive = TxfSqkExaActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMONACTIVE, TXTSNXACTIVE, BUTSNXVIEWAVAIL, BUTSNXVIEWACTIVE, TXTFNXACTIVE, BUTFNXVIEWAVAIL, BUTFNXVIEWACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
};

void PnlWznmSgeDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmSgeDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmSgeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtJobActive", TxtJobActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewAvail", ButJobViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButJobViewActive", ButJobViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMonActive", TxfMonActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSnxActive", TxtSnxActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSnxViewAvail", ButSnxViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSnxViewActive", ButSnxViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFnxActive", TxtFnxActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFnxViewAvail", ButFnxViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFnxViewActive", ButFnxViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSqkNewAvail", ButSqkNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSqkDeleteAvail", ButSqkDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSqkJtiAvail", PupSqkJtiAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSqkJtiActive", PupSqkJtiActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSqkJtiEditAvail", ButSqkJtiEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSqkTitAvail", TxtSqkTitAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSqkTitActive", TxtSqkTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSqkExaAvail", TxfSqkExaAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfSqkExaActive", TxfSqkExaActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmSgeDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtJobActive == comp->TxtJobActive) insert(items, TXTJOBACTIVE);
	if (ButJobViewAvail == comp->ButJobViewAvail) insert(items, BUTJOBVIEWAVAIL);
	if (ButJobViewActive == comp->ButJobViewActive) insert(items, BUTJOBVIEWACTIVE);
	if (TxfMonActive == comp->TxfMonActive) insert(items, TXFMONACTIVE);
	if (TxtSnxActive == comp->TxtSnxActive) insert(items, TXTSNXACTIVE);
	if (ButSnxViewAvail == comp->ButSnxViewAvail) insert(items, BUTSNXVIEWAVAIL);
	if (ButSnxViewActive == comp->ButSnxViewActive) insert(items, BUTSNXVIEWACTIVE);
	if (TxtFnxActive == comp->TxtFnxActive) insert(items, TXTFNXACTIVE);
	if (ButFnxViewAvail == comp->ButFnxViewAvail) insert(items, BUTFNXVIEWAVAIL);
	if (ButFnxViewActive == comp->ButFnxViewActive) insert(items, BUTFNXVIEWACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);
	if (ButSqkNewAvail == comp->ButSqkNewAvail) insert(items, BUTSQKNEWAVAIL);
	if (ButSqkDeleteAvail == comp->ButSqkDeleteAvail) insert(items, BUTSQKDELETEAVAIL);
	if (PupSqkJtiAvail == comp->PupSqkJtiAvail) insert(items, PUPSQKJTIAVAIL);
	if (PupSqkJtiActive == comp->PupSqkJtiActive) insert(items, PUPSQKJTIACTIVE);
	if (ButSqkJtiEditAvail == comp->ButSqkJtiEditAvail) insert(items, BUTSQKJTIEDITAVAIL);
	if (TxtSqkTitAvail == comp->TxtSqkTitAvail) insert(items, TXTSQKTITAVAIL);
	if (TxtSqkTitActive == comp->TxtSqkTitActive) insert(items, TXTSQKTITACTIVE);
	if (TxfSqkExaAvail == comp->TxfSqkExaAvail) insert(items, TXFSQKEXAAVAIL);
	if (TxfSqkExaActive == comp->TxfSqkExaActive) insert(items, TXFSQKEXAACTIVE);

	return(items);
};

set<uint> PnlWznmSgeDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMONACTIVE, TXTSNXACTIVE, BUTSNXVIEWAVAIL, BUTSNXVIEWACTIVE, TXTFNXACTIVE, BUTFNXVIEWAVAIL, BUTFNXVIEWACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmSgeDetail::Tag
 ******************************************************************************/

void PnlWznmSgeDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmSgeDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmSgeDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptJob", "job");
			writeStringAttr(wr, itemtag, "sref", "CptMon", "monitor interval [\\u00b5s]");
			writeStringAttr(wr, itemtag, "sref", "CptSnx", "next stage on success");
			writeStringAttr(wr, itemtag, "sref", "CptFnx", "next stage on failure");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
			writeStringAttr(wr, itemtag, "sref", "HdgSqk", "Squawk");
			writeStringAttr(wr, itemtag, "sref", "CptSqkTit", "text");
			writeStringAttr(wr, itemtag, "sref", "CptSqkExa", "example");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmSgeDetail::DpchAppData
 ******************************************************************************/

PnlWznmSgeDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSGEDETAILDATA)
		{
};

string PnlWznmSgeDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSgeDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSgeDetailData");
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
 class PnlWznmSgeDetail::DpchAppDo
 ******************************************************************************/

PnlWznmSgeDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMSGEDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmSgeDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSgeDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmSgeDetailDo");
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
 class PnlWznmSgeDetail::DpchEngData
 ******************************************************************************/

PnlWznmSgeDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupSqkJti
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMSGEDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPSQKJTI, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPSQKJTI) && feedFPupSqkJti) this->feedFPupSqkJti = *feedFPupSqkJti;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmSgeDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPSQKJTI)) ss.push_back("feedFPupSqkJti");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmSgeDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPSQKJTI)) {feedFPupSqkJti = src->feedFPupSqkJti; add(FEEDFPUPSQKJTI);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmSgeDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmSgeDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPSQKJTI)) feedFPupSqkJti.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

