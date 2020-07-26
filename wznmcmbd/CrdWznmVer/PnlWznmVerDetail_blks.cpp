/**
	* \file PnlWznmVerDetail_blks.cpp
	* job handler for job PnlWznmVerDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmVerDetail::VecVDo
 ******************************************************************************/

uint PnlWznmVerDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butprjviewclick") return BUTPRJVIEWCLICK;
	if (s == "butbvrviewclick") return BUTBVRVIEWCLICK;
	if (s == "butlocviewclick") return BUTLOCVIEWCLICK;
	if (s == "butjsteditclick") return BUTJSTEDITCLICK;
	if (s == "butjeditclick") return BUTJEDITCLICK;

	return(0);
};

string PnlWznmVerDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
	if (ix == BUTBVRVIEWCLICK) return("ButBvrViewClick");
	if (ix == BUTLOCVIEWCLICK) return("ButLocViewClick");
	if (ix == BUTJSTEDITCLICK) return("ButJstEditClick");
	if (ix == BUTJEDITCLICK) return("ButJEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmVerDetail::ContIac
 ******************************************************************************/

PnlWznmVerDetail::ContIac::ContIac(
			const string& TxfMaj
			, const string& TxfMin
			, const string& TxfSub
			, const uint numFPupJst
			, const uint numFPupSte
			, const vector<uint>& numsFLstDty
			, const vector<uint>& numsFLstOpt
			, const uint numFPupJ
			, const string& TxfCmt
		) :
			Block()
		{
	this->TxfMaj = TxfMaj;
	this->TxfMin = TxfMin;
	this->TxfSub = TxfSub;
	this->numFPupJst = numFPupJst;
	this->numFPupSte = numFPupSte;
	this->numsFLstDty = numsFLstDty;
	this->numsFLstOpt = numsFLstOpt;
	this->numFPupJ = numFPupJ;
	this->TxfCmt = TxfCmt;

	mask = {TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTDTY, NUMSFLSTOPT, NUMFPUPJ, TXFCMT};
};

bool PnlWznmVerDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmVerDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmVerDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMaj", TxfMaj)) add(TXFMAJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfMin", TxfMin)) add(TXFMIN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSub", TxfSub)) add(TXFSUB);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJst", numFPupJst)) add(NUMFPUPJST);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSte", numFPupSte)) add(NUMFPUPSTE);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstDty", numsFLstDty)) add(NUMSFLSTDTY);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJ", numFPupJ)) add(NUMFPUPJ);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfCmt", TxfCmt)) add(TXFCMT);
	};

	return basefound;
};

void PnlWznmVerDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfMaj", TxfMaj);
		writeStringAttr(wr, itemtag, "sref", "TxfMin", TxfMin);
		writeStringAttr(wr, itemtag, "sref", "TxfSub", TxfSub);
		writeUintAttr(wr, itemtag, "sref", "numFPupJst", numFPupJst);
		writeUintAttr(wr, itemtag, "sref", "numFPupSte", numFPupSte);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstDty", numsFLstDty);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeUintAttr(wr, itemtag, "sref", "numFPupJ", numFPupJ);
		writeStringAttr(wr, itemtag, "sref", "TxfCmt", TxfCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfMaj == comp->TxfMaj) insert(items, TXFMAJ);
	if (TxfMin == comp->TxfMin) insert(items, TXFMIN);
	if (TxfSub == comp->TxfSub) insert(items, TXFSUB);
	if (numFPupJst == comp->numFPupJst) insert(items, NUMFPUPJST);
	if (numFPupSte == comp->numFPupSte) insert(items, NUMFPUPSTE);
	if (compareUintvec(numsFLstDty, comp->numsFLstDty)) insert(items, NUMSFLSTDTY);
	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (numFPupJ == comp->numFPupJ) insert(items, NUMFPUPJ);
	if (TxfCmt == comp->TxfCmt) insert(items, TXFCMT);

	return(items);
};

set<uint> PnlWznmVerDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTDTY, NUMSFLSTOPT, NUMFPUPJ, TXFCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVerDetail::ContInf
 ******************************************************************************/

PnlWznmVerDetail::ContInf::ContInf(
			const string& TxtPrj
			, const string& TxtBvr
			, const string& TxtLoc
			, const string& TxtDty
			, const string& TxtOpt
			, const string& TxtAb1
			, const string& TxtAb2
			, const string& TxtAb3
		) :
			Block()
		{
	this->TxtPrj = TxtPrj;
	this->TxtBvr = TxtBvr;
	this->TxtLoc = TxtLoc;
	this->TxtDty = TxtDty;
	this->TxtOpt = TxtOpt;
	this->TxtAb1 = TxtAb1;
	this->TxtAb2 = TxtAb2;
	this->TxtAb3 = TxtAb3;

	mask = {TXTPRJ, TXTBVR, TXTLOC, TXTDTY, TXTOPT, TXTAB1, TXTAB2, TXTAB3};
};

void PnlWznmVerDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtPrj", TxtPrj);
		writeStringAttr(wr, itemtag, "sref", "TxtBvr", TxtBvr);
		writeStringAttr(wr, itemtag, "sref", "TxtLoc", TxtLoc);
		writeStringAttr(wr, itemtag, "sref", "TxtDty", TxtDty);
		writeStringAttr(wr, itemtag, "sref", "TxtOpt", TxtOpt);
		writeStringAttr(wr, itemtag, "sref", "TxtAb1", TxtAb1);
		writeStringAttr(wr, itemtag, "sref", "TxtAb2", TxtAb2);
		writeStringAttr(wr, itemtag, "sref", "TxtAb3", TxtAb3);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtPrj == comp->TxtPrj) insert(items, TXTPRJ);
	if (TxtBvr == comp->TxtBvr) insert(items, TXTBVR);
	if (TxtLoc == comp->TxtLoc) insert(items, TXTLOC);
	if (TxtDty == comp->TxtDty) insert(items, TXTDTY);
	if (TxtOpt == comp->TxtOpt) insert(items, TXTOPT);
	if (TxtAb1 == comp->TxtAb1) insert(items, TXTAB1);
	if (TxtAb2 == comp->TxtAb2) insert(items, TXTAB2);
	if (TxtAb3 == comp->TxtAb3) insert(items, TXTAB3);

	return(items);
};

set<uint> PnlWznmVerDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTPRJ, TXTBVR, TXTLOC, TXTDTY, TXTOPT, TXTAB1, TXTAB2, TXTAB3};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVerDetail::StatApp
 ******************************************************************************/

void PnlWznmVerDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstDtyAlt
			, const bool LstOptAlt
			, const uint LstDtyNumFirstdisp
			, const uint LstOptNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstDtyAlt", LstDtyAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstOptAlt", LstOptAlt);
		writeUintAttr(wr, itemtag, "sref", "LstDtyNumFirstdisp", LstDtyNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVerDetail::StatShr
 ******************************************************************************/

PnlWznmVerDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtPrjActive
			, const bool ButPrjViewAvail
			, const bool ButPrjViewActive
			, const bool TxfMajActive
			, const bool TxfMinActive
			, const bool TxfSubActive
			, const bool TxtBvrActive
			, const bool ButBvrViewAvail
			, const bool ButBvrViewActive
			, const bool TxtLocActive
			, const bool ButLocViewAvail
			, const bool ButLocViewActive
			, const bool PupJstActive
			, const bool ButJstEditAvail
			, const bool PupSteActive
			, const bool LstDtyActive
			, const bool LstOptActive
			, const bool PupJActive
			, const bool ButJEditAvail
			, const bool TxtAb1Active
			, const bool TxtAb2Active
			, const bool TxtAb3Active
			, const bool TxfCmtActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtPrjActive = TxtPrjActive;
	this->ButPrjViewAvail = ButPrjViewAvail;
	this->ButPrjViewActive = ButPrjViewActive;
	this->TxfMajActive = TxfMajActive;
	this->TxfMinActive = TxfMinActive;
	this->TxfSubActive = TxfSubActive;
	this->TxtBvrActive = TxtBvrActive;
	this->ButBvrViewAvail = ButBvrViewAvail;
	this->ButBvrViewActive = ButBvrViewActive;
	this->TxtLocActive = TxtLocActive;
	this->ButLocViewAvail = ButLocViewAvail;
	this->ButLocViewActive = ButLocViewActive;
	this->PupJstActive = PupJstActive;
	this->ButJstEditAvail = ButJstEditAvail;
	this->PupSteActive = PupSteActive;
	this->LstDtyActive = LstDtyActive;
	this->LstOptActive = LstOptActive;
	this->PupJActive = PupJActive;
	this->ButJEditAvail = ButJEditAvail;
	this->TxtAb1Active = TxtAb1Active;
	this->TxtAb2Active = TxtAb2Active;
	this->TxtAb3Active = TxtAb3Active;
	this->TxfCmtActive = TxfCmtActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, TXTLOCACTIVE, BUTLOCVIEWAVAIL, BUTLOCVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTDTYACTIVE, LSTOPTACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTAB1ACTIVE, TXTAB2ACTIVE, TXTAB3ACTIVE, TXFCMTACTIVE};
};

void PnlWznmVerDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPrjActive", TxtPrjActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewAvail", ButPrjViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPrjViewActive", ButPrjViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMajActive", TxfMajActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfMinActive", TxfMinActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSubActive", TxfSubActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtBvrActive", TxtBvrActive);
		writeBoolAttr(wr, itemtag, "sref", "ButBvrViewAvail", ButBvrViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButBvrViewActive", ButBvrViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtLocActive", TxtLocActive);
		writeBoolAttr(wr, itemtag, "sref", "ButLocViewAvail", ButLocViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButLocViewActive", ButLocViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJstActive", PupJstActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJstEditAvail", ButJstEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupSteActive", PupSteActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDtyActive", LstDtyActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOptActive", LstOptActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJActive", PupJActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJEditAvail", ButJEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtAb1Active", TxtAb1Active);
		writeBoolAttr(wr, itemtag, "sref", "TxtAb2Active", TxtAb2Active);
		writeBoolAttr(wr, itemtag, "sref", "TxtAb3Active", TxtAb3Active);
		writeBoolAttr(wr, itemtag, "sref", "TxfCmtActive", TxfCmtActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmVerDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtPrjActive == comp->TxtPrjActive) insert(items, TXTPRJACTIVE);
	if (ButPrjViewAvail == comp->ButPrjViewAvail) insert(items, BUTPRJVIEWAVAIL);
	if (ButPrjViewActive == comp->ButPrjViewActive) insert(items, BUTPRJVIEWACTIVE);
	if (TxfMajActive == comp->TxfMajActive) insert(items, TXFMAJACTIVE);
	if (TxfMinActive == comp->TxfMinActive) insert(items, TXFMINACTIVE);
	if (TxfSubActive == comp->TxfSubActive) insert(items, TXFSUBACTIVE);
	if (TxtBvrActive == comp->TxtBvrActive) insert(items, TXTBVRACTIVE);
	if (ButBvrViewAvail == comp->ButBvrViewAvail) insert(items, BUTBVRVIEWAVAIL);
	if (ButBvrViewActive == comp->ButBvrViewActive) insert(items, BUTBVRVIEWACTIVE);
	if (TxtLocActive == comp->TxtLocActive) insert(items, TXTLOCACTIVE);
	if (ButLocViewAvail == comp->ButLocViewAvail) insert(items, BUTLOCVIEWAVAIL);
	if (ButLocViewActive == comp->ButLocViewActive) insert(items, BUTLOCVIEWACTIVE);
	if (PupJstActive == comp->PupJstActive) insert(items, PUPJSTACTIVE);
	if (ButJstEditAvail == comp->ButJstEditAvail) insert(items, BUTJSTEDITAVAIL);
	if (PupSteActive == comp->PupSteActive) insert(items, PUPSTEACTIVE);
	if (LstDtyActive == comp->LstDtyActive) insert(items, LSTDTYACTIVE);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (PupJActive == comp->PupJActive) insert(items, PUPJACTIVE);
	if (ButJEditAvail == comp->ButJEditAvail) insert(items, BUTJEDITAVAIL);
	if (TxtAb1Active == comp->TxtAb1Active) insert(items, TXTAB1ACTIVE);
	if (TxtAb2Active == comp->TxtAb2Active) insert(items, TXTAB2ACTIVE);
	if (TxtAb3Active == comp->TxtAb3Active) insert(items, TXTAB3ACTIVE);
	if (TxfCmtActive == comp->TxfCmtActive) insert(items, TXFCMTACTIVE);

	return(items);
};

set<uint> PnlWznmVerDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, TXTLOCACTIVE, BUTLOCVIEWAVAIL, BUTLOCVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTDTYACTIVE, LSTOPTACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTAB1ACTIVE, TXTAB2ACTIVE, TXTAB3ACTIVE, TXFCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmVerDetail::Tag
 ******************************************************************************/

void PnlWznmVerDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmVerDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmVerDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptPrj", "project");
			writeStringAttr(wr, itemtag, "sref", "CptMaj", "major version number");
			writeStringAttr(wr, itemtag, "sref", "CptMin", "minor version number");
			writeStringAttr(wr, itemtag, "sref", "CptSub", "sub version number");
			writeStringAttr(wr, itemtag, "sref", "CptBvr", "base version");
			writeStringAttr(wr, itemtag, "sref", "CptLoc", "primary locale");
			writeStringAttr(wr, itemtag, "sref", "CptSte", "state");
			writeStringAttr(wr, itemtag, "sref", "CptDty", "DBMS types");
			writeStringAttr(wr, itemtag, "sref", "CptOpt", "options");
			writeStringAttr(wr, itemtag, "sref", "CptAb1", "about text, part 1");
			writeStringAttr(wr, itemtag, "sref", "CptAb2", "about text, part 2");
			writeStringAttr(wr, itemtag, "sref", "CptAb3", "about text, part 3");
			writeStringAttr(wr, itemtag, "sref", "CptCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmVerDetail::DpchAppData
 ******************************************************************************/

PnlWznmVerDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERDETAILDATA)
		{
};

string PnlWznmVerDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVerDetailData");
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
 class PnlWznmVerDetail::DpchAppDo
 ******************************************************************************/

PnlWznmVerDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMVERDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmVerDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmVerDetailDo");
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
 class PnlWznmVerDetail::DpchEngData
 ******************************************************************************/

PnlWznmVerDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstDty
			, Feed* feedFLstOpt
			, Feed* feedFPupJ
			, Feed* feedFPupJst
			, Feed* feedFPupSte
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMVERDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTDTY, FEEDFLSTOPT, FEEDFPUPJ, FEEDFPUPJST, FEEDFPUPSTE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTDTY) && feedFLstDty) this->feedFLstDty = *feedFLstDty;
	if (find(this->mask, FEEDFLSTOPT) && feedFLstOpt) this->feedFLstOpt = *feedFLstOpt;
	if (find(this->mask, FEEDFPUPJ) && feedFPupJ) this->feedFPupJ = *feedFPupJ;
	if (find(this->mask, FEEDFPUPJST) && feedFPupJst) this->feedFPupJst = *feedFPupJst;
	if (find(this->mask, FEEDFPUPSTE) && feedFPupSte) this->feedFPupSte = *feedFPupSte;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmVerDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDTY)) ss.push_back("feedFLstDty");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(FEEDFPUPJ)) ss.push_back("feedFPupJ");
	if (has(FEEDFPUPJST)) ss.push_back("feedFPupJst");
	if (has(FEEDFPUPSTE)) ss.push_back("feedFPupSte");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmVerDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTDTY)) {feedFLstDty = src->feedFLstDty; add(FEEDFLSTDTY);};
	if (src->has(FEEDFLSTOPT)) {feedFLstOpt = src->feedFLstOpt; add(FEEDFLSTOPT);};
	if (src->has(FEEDFPUPJ)) {feedFPupJ = src->feedFPupJ; add(FEEDFPUPJ);};
	if (src->has(FEEDFPUPJST)) {feedFPupJst = src->feedFPupJst; add(FEEDFPUPJST);};
	if (src->has(FEEDFPUPSTE)) {feedFPupSte = src->feedFPupSte; add(FEEDFPUPSTE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmVerDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmVerDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTDTY)) feedFLstDty.writeXML(wr);
		if (has(FEEDFLSTOPT)) feedFLstOpt.writeXML(wr);
		if (has(FEEDFPUPJ)) feedFPupJ.writeXML(wr);
		if (has(FEEDFPUPJST)) feedFPupJst.writeXML(wr);
		if (has(FEEDFPUPSTE)) feedFPupSte.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

