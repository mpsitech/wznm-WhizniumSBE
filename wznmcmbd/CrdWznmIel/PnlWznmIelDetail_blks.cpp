/**
	* \file PnlWznmIelDetail_blks.cpp
	* job handler for job PnlWznmIelDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmIelDetail::VecVDo
 ******************************************************************************/

uint PnlWznmIelDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butimeviewclick") return BUTIMEVIEWCLICK;
	if (s == "butim2viewclick") return BUTIM2VIEWCLICK;
	if (s == "butpstviewclick") return BUTPSTVIEWCLICK;
	if (s == "butstbviewclick") return BUTSTBVIEWCLICK;
	if (s == "butvitviewclick") return BUTVITVIEWCLICK;

	return(0);
};

string PnlWznmIelDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTIMEVIEWCLICK) return("ButImeViewClick");
	if (ix == BUTIM2VIEWCLICK) return("ButIm2ViewClick");
	if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
	if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");
	if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmIelDetail::ContIac
 ******************************************************************************/

PnlWznmIelDetail::ContIac::ContIac(
			const string& TxfSho
			, const uint numFPupTyp
			, const vector<uint>& numsFLstOcc
			, const uint numFPupCty
			, const string& TxfDfv
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->numFPupTyp = numFPupTyp;
	this->numsFLstOcc = numsFLstOcc;
	this->numFPupCty = numFPupCty;
	this->TxfDfv = TxfDfv;

	mask = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC, NUMFPUPCTY, TXFDFV};
};

bool PnlWznmIelDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmIelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmIelDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOcc", numsFLstOcc)) add(NUMSFLSTOCC);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupCty", numFPupCty)) add(NUMFPUPCTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfDfv", TxfDfv)) add(TXFDFV);
	};

	return basefound;
};

void PnlWznmIelDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmIelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmIelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOcc", numsFLstOcc);
		writeUintAttr(wr, itemtag, "sref", "numFPupCty", numFPupCty);
		writeStringAttr(wr, itemtag, "sref", "TxfDfv", TxfDfv);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmIelDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (compareUintvec(numsFLstOcc, comp->numsFLstOcc)) insert(items, NUMSFLSTOCC);
	if (numFPupCty == comp->numFPupCty) insert(items, NUMFPUPCTY);
	if (TxfDfv == comp->TxfDfv) insert(items, TXFDFV);

	return(items);
};

set<uint> PnlWznmIelDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, NUMFPUPTYP, NUMSFLSTOCC, NUMFPUPCTY, TXFDFV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmIelDetail::ContInf
 ******************************************************************************/

PnlWznmIelDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtOcc
			, const string& TxtIme
			, const string& TxtTco
			, const string& TxtIm2
			, const string& TxtPst
			, const string& TxtStb
			, const string& TxtVit
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtOcc = TxtOcc;
	this->TxtIme = TxtIme;
	this->TxtTco = TxtTco;
	this->TxtIm2 = TxtIm2;
	this->TxtPst = TxtPst;
	this->TxtStb = TxtStb;
	this->TxtVit = TxtVit;

	mask = {TXTSRF, TXTOCC, TXTIME, TXTTCO, TXTIM2, TXTPST, TXTSTB, TXTVIT};
};

void PnlWznmIelDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmIelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmIelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtOcc", TxtOcc);
		writeStringAttr(wr, itemtag, "sref", "TxtIme", TxtIme);
		writeStringAttr(wr, itemtag, "sref", "TxtTco", TxtTco);
		writeStringAttr(wr, itemtag, "sref", "TxtIm2", TxtIm2);
		writeStringAttr(wr, itemtag, "sref", "TxtPst", TxtPst);
		writeStringAttr(wr, itemtag, "sref", "TxtStb", TxtStb);
		writeStringAttr(wr, itemtag, "sref", "TxtVit", TxtVit);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmIelDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtOcc == comp->TxtOcc) insert(items, TXTOCC);
	if (TxtIme == comp->TxtIme) insert(items, TXTIME);
	if (TxtTco == comp->TxtTco) insert(items, TXTTCO);
	if (TxtIm2 == comp->TxtIm2) insert(items, TXTIM2);
	if (TxtPst == comp->TxtPst) insert(items, TXTPST);
	if (TxtStb == comp->TxtStb) insert(items, TXTSTB);
	if (TxtVit == comp->TxtVit) insert(items, TXTVIT);

	return(items);
};

set<uint> PnlWznmIelDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTOCC, TXTIME, TXTTCO, TXTIM2, TXTPST, TXTSTB, TXTVIT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmIelDetail::StatApp
 ******************************************************************************/

void PnlWznmIelDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstOccAlt
			, const uint LstOccNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmIelDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmIelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstOccAlt", LstOccAlt);
		writeUintAttr(wr, itemtag, "sref", "LstOccNumFirstdisp", LstOccNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmIelDetail::StatShr
 ******************************************************************************/

PnlWznmIelDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool PupTypActive
			, const bool LstOccActive
			, const bool TxtImeActive
			, const bool ButImeViewAvail
			, const bool ButImeViewActive
			, const bool TxtTcoActive
			, const bool TxtIm2Active
			, const bool ButIm2ViewAvail
			, const bool ButIm2ViewActive
			, const bool PupCtyActive
			, const bool TxfDfvActive
			, const bool TxtPstActive
			, const bool ButPstViewAvail
			, const bool ButPstViewActive
			, const bool TxtStbActive
			, const bool ButStbViewAvail
			, const bool ButStbViewActive
			, const bool TxtVitActive
			, const bool ButVitViewAvail
			, const bool ButVitViewActive
		) :
			Block()
		{
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->PupTypActive = PupTypActive;
	this->LstOccActive = LstOccActive;
	this->TxtImeActive = TxtImeActive;
	this->ButImeViewAvail = ButImeViewAvail;
	this->ButImeViewActive = ButImeViewActive;
	this->TxtTcoActive = TxtTcoActive;
	this->TxtIm2Active = TxtIm2Active;
	this->ButIm2ViewAvail = ButIm2ViewAvail;
	this->ButIm2ViewActive = ButIm2ViewActive;
	this->PupCtyActive = PupCtyActive;
	this->TxfDfvActive = TxfDfvActive;
	this->TxtPstActive = TxtPstActive;
	this->ButPstViewAvail = ButPstViewAvail;
	this->ButPstViewActive = ButPstViewActive;
	this->TxtStbActive = TxtStbActive;
	this->ButStbViewAvail = ButStbViewAvail;
	this->ButStbViewActive = ButStbViewActive;
	this->TxtVitActive = TxtVitActive;
	this->ButVitViewAvail = ButVitViewAvail;
	this->ButVitViewActive = ButVitViewActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTIMEACTIVE, BUTIMEVIEWAVAIL, BUTIMEVIEWACTIVE, TXTTCOACTIVE, TXTIM2ACTIVE, BUTIM2VIEWAVAIL, BUTIM2VIEWACTIVE, PUPCTYACTIVE, TXFDFVACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE, TXTVITACTIVE, BUTVITVIEWAVAIL, BUTVITVIEWACTIVE};
};

void PnlWznmIelDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmIelDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmIelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfShoActive", TxfShoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOccActive", LstOccActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtImeActive", TxtImeActive);
		writeBoolAttr(wr, itemtag, "sref", "ButImeViewAvail", ButImeViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButImeViewActive", ButImeViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTcoActive", TxtTcoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtIm2Active", TxtIm2Active);
		writeBoolAttr(wr, itemtag, "sref", "ButIm2ViewAvail", ButIm2ViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButIm2ViewActive", ButIm2ViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupCtyActive", PupCtyActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfDfvActive", TxfDfvActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtPstActive", TxtPstActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewAvail", ButPstViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewActive", ButPstViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtStbActive", TxtStbActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStbViewAvail", ButStbViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStbViewActive", ButStbViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtVitActive", TxtVitActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVitViewAvail", ButVitViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVitViewActive", ButVitViewActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmIelDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstOccActive == comp->LstOccActive) insert(items, LSTOCCACTIVE);
	if (TxtImeActive == comp->TxtImeActive) insert(items, TXTIMEACTIVE);
	if (ButImeViewAvail == comp->ButImeViewAvail) insert(items, BUTIMEVIEWAVAIL);
	if (ButImeViewActive == comp->ButImeViewActive) insert(items, BUTIMEVIEWACTIVE);
	if (TxtTcoActive == comp->TxtTcoActive) insert(items, TXTTCOACTIVE);
	if (TxtIm2Active == comp->TxtIm2Active) insert(items, TXTIM2ACTIVE);
	if (ButIm2ViewAvail == comp->ButIm2ViewAvail) insert(items, BUTIM2VIEWAVAIL);
	if (ButIm2ViewActive == comp->ButIm2ViewActive) insert(items, BUTIM2VIEWACTIVE);
	if (PupCtyActive == comp->PupCtyActive) insert(items, PUPCTYACTIVE);
	if (TxfDfvActive == comp->TxfDfvActive) insert(items, TXFDFVACTIVE);
	if (TxtPstActive == comp->TxtPstActive) insert(items, TXTPSTACTIVE);
	if (ButPstViewAvail == comp->ButPstViewAvail) insert(items, BUTPSTVIEWAVAIL);
	if (ButPstViewActive == comp->ButPstViewActive) insert(items, BUTPSTVIEWACTIVE);
	if (TxtStbActive == comp->TxtStbActive) insert(items, TXTSTBACTIVE);
	if (ButStbViewAvail == comp->ButStbViewAvail) insert(items, BUTSTBVIEWAVAIL);
	if (ButStbViewActive == comp->ButStbViewActive) insert(items, BUTSTBVIEWACTIVE);
	if (TxtVitActive == comp->TxtVitActive) insert(items, TXTVITACTIVE);
	if (ButVitViewAvail == comp->ButVitViewAvail) insert(items, BUTVITVIEWAVAIL);
	if (ButVitViewActive == comp->ButVitViewActive) insert(items, BUTVITVIEWACTIVE);

	return(items);
};

set<uint> PnlWznmIelDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTIMEACTIVE, BUTIMEVIEWAVAIL, BUTIMEVIEWACTIVE, TXTTCOACTIVE, TXTIM2ACTIVE, BUTIM2VIEWAVAIL, BUTIM2VIEWACTIVE, PUPCTYACTIVE, TXFDFVACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE, TXTVITACTIVE, BUTVITVIEWAVAIL, BUTVITVIEWACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmIelDetail::Tag
 ******************************************************************************/

void PnlWznmIelDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmIelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmIelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSho", "acronym");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptOcc", "occurrence");
			writeStringAttr(wr, itemtag, "sref", "CptIme", "import/export");
			writeStringAttr(wr, itemtag, "sref", "CptTco", "table column");
			writeStringAttr(wr, itemtag, "sref", "CptIm2", "import/export");
			writeStringAttr(wr, itemtag, "sref", "CptCty", "conversion type");
			writeStringAttr(wr, itemtag, "sref", "CptDfv", "default value");
			writeStringAttr(wr, itemtag, "sref", "CptPst", "presetting");
			writeStringAttr(wr, itemtag, "sref", "CptStb", "stub");
			writeStringAttr(wr, itemtag, "sref", "CptVit", "vector item");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmIelDetail::DpchAppData
 ******************************************************************************/

PnlWznmIelDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIELDETAILDATA)
		{
};

string PnlWznmIelDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmIelDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmIelDetailData");
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
 class PnlWznmIelDetail::DpchAppDo
 ******************************************************************************/

PnlWznmIelDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMIELDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmIelDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmIelDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmIelDetailDo");
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
 class PnlWznmIelDetail::DpchEngData
 ******************************************************************************/

PnlWznmIelDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstOcc
			, Feed* feedFPupCty
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMIELDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTOCC, FEEDFPUPCTY, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTOCC) && feedFLstOcc) this->feedFLstOcc = *feedFLstOcc;
	if (find(this->mask, FEEDFPUPCTY) && feedFPupCty) this->feedFPupCty = *feedFPupCty;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmIelDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOCC)) ss.push_back("feedFLstOcc");
	if (has(FEEDFPUPCTY)) ss.push_back("feedFPupCty");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmIelDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTOCC)) {feedFLstOcc = src->feedFLstOcc; add(FEEDFLSTOCC);};
	if (src->has(FEEDFPUPCTY)) {feedFPupCty = src->feedFPupCty; add(FEEDFPUPCTY);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmIelDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmIelDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTOCC)) feedFLstOcc.writeXML(wr);
		if (has(FEEDFPUPCTY)) feedFPupCty.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
