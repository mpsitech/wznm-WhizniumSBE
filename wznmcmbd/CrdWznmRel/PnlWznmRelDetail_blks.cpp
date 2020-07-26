/**
	* \file PnlWznmRelDetail_blks.cpp
	* job handler for job PnlWznmRelDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmRelDetail::VecVDo
 ******************************************************************************/

uint PnlWznmRelDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butfrsviewclick") return BUTFRSVIEWCLICK;
	if (s == "buttosviewclick") return BUTTOSVIEWCLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "butverviewclick") return BUTVERVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "butopteditclick") return BUTOPTEDITCLICK;

	return(0);
};

string PnlWznmRelDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTFRSVIEWCLICK) return("ButFrsViewClick");
	if (ix == BUTTOSVIEWCLICK) return("ButTosViewClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmRelDetail::ContIac
 ******************************************************************************/

PnlWznmRelDetail::ContIac::ContIac(
			const uint numFPupTyp
			, const uint numFLstClu
			, const string& TxfPfx
			, const vector<uint>& numsFLstOpt
			, const string& TxfOpt
		) :
			Block()
		{
	this->numFPupTyp = numFPupTyp;
	this->numFLstClu = numFLstClu;
	this->TxfPfx = TxfPfx;
	this->numsFLstOpt = numsFLstOpt;
	this->TxfOpt = TxfOpt;

	mask = {NUMFPUPTYP, NUMFLSTCLU, TXFPFX, NUMSFLSTOPT, TXFOPT};
};

bool PnlWznmRelDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmRelDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmRelDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfPfx", TxfPfx)) add(TXFPFX);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOpt", TxfOpt)) add(TXFOPT);
	};

	return basefound;
};

void PnlWznmRelDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmRelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmRelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeStringAttr(wr, itemtag, "sref", "TxfPfx", TxfPfx);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfOpt", TxfOpt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (TxfPfx == comp->TxfPfx) insert(items, TXFPFX);
	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (TxfOpt == comp->TxfOpt) insert(items, TXFOPT);

	return(items);
};

set<uint> PnlWznmRelDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPTYP, NUMFLSTCLU, TXFPFX, NUMSFLSTOPT, TXFOPT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelDetail::ContInf
 ******************************************************************************/

PnlWznmRelDetail::ContInf::ContInf(
			const string& TxtFrt
			, const string& TxtFrs
			, const string& TxtTot
			, const string& TxtTos
			, const string& TxtClu
			, const string& TxtVer
			, const string& TxtSup
			, const string& TxtTbl
		) :
			Block()
		{
	this->TxtFrt = TxtFrt;
	this->TxtFrs = TxtFrs;
	this->TxtTot = TxtTot;
	this->TxtTos = TxtTos;
	this->TxtClu = TxtClu;
	this->TxtVer = TxtVer;
	this->TxtSup = TxtSup;
	this->TxtTbl = TxtTbl;

	mask = {TXTFRT, TXTFRS, TXTTOT, TXTTOS, TXTCLU, TXTVER, TXTSUP, TXTTBL};
};

void PnlWznmRelDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmRelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmRelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtFrt", TxtFrt);
		writeStringAttr(wr, itemtag, "sref", "TxtFrs", TxtFrs);
		writeStringAttr(wr, itemtag, "sref", "TxtTot", TxtTot);
		writeStringAttr(wr, itemtag, "sref", "TxtTos", TxtTos);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
		writeStringAttr(wr, itemtag, "sref", "TxtVer", TxtVer);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtTbl", TxtTbl);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtFrt == comp->TxtFrt) insert(items, TXTFRT);
	if (TxtFrs == comp->TxtFrs) insert(items, TXTFRS);
	if (TxtTot == comp->TxtTot) insert(items, TXTTOT);
	if (TxtTos == comp->TxtTos) insert(items, TXTTOS);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtVer == comp->TxtVer) insert(items, TXTVER);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);

	return(items);
};

set<uint> PnlWznmRelDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTFRT, TXTFRS, TXTTOT, TXTTOS, TXTCLU, TXTVER, TXTSUP, TXTTBL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelDetail::StatApp
 ******************************************************************************/

void PnlWznmRelDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstCluAlt
			, const bool LstOptAlt
			, const uint LstCluNumFirstdisp
			, const uint LstOptNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmRelDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmRelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstOptAlt", LstOptAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelDetail::StatShr
 ******************************************************************************/

PnlWznmRelDetail::StatShr::StatShr(
			const bool TxfOptValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtFrtActive
			, const bool TxtFrsActive
			, const bool ButFrsViewAvail
			, const bool ButFrsViewActive
			, const bool TxtTotActive
			, const bool TxtTosActive
			, const bool ButTosViewAvail
			, const bool ButTosViewActive
			, const bool PupTypActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtVerActive
			, const bool ButVerViewAvail
			, const bool ButVerViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool TxtTblActive
			, const bool TxfPfxActive
			, const bool LstOptActive
			, const bool ButOptEditAvail
		) :
			Block()
		{
	this->TxfOptValid = TxfOptValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtFrtActive = TxtFrtActive;
	this->TxtFrsActive = TxtFrsActive;
	this->ButFrsViewAvail = ButFrsViewAvail;
	this->ButFrsViewActive = ButFrsViewActive;
	this->TxtTotActive = TxtTotActive;
	this->TxtTosActive = TxtTosActive;
	this->ButTosViewAvail = ButTosViewAvail;
	this->ButTosViewActive = ButTosViewActive;
	this->PupTypActive = PupTypActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtVerActive = TxtVerActive;
	this->ButVerViewAvail = ButVerViewAvail;
	this->ButVerViewActive = ButVerViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->TxtTblActive = TxtTblActive;
	this->TxfPfxActive = TxfPfxActive;
	this->LstOptActive = LstOptActive;
	this->ButOptEditAvail = ButOptEditAvail;

	mask = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFRTACTIVE, TXTFRSACTIVE, BUTFRSVIEWAVAIL, BUTFRSVIEWACTIVE, TXTTOTACTIVE, TXTTOSACTIVE, BUTTOSVIEWAVAIL, BUTTOSVIEWACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXFPFXACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL};
};

void PnlWznmRelDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmRelDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmRelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfOptValid", TxfOptValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFrtActive", TxtFrtActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFrsActive", TxtFrsActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFrsViewAvail", ButFrsViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFrsViewActive", ButFrsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTotActive", TxtTotActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTosActive", TxtTosActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTosViewAvail", ButTosViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTosViewActive", ButTosViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtVerActive", TxtVerActive);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewAvail", ButVerViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButVerViewActive", ButVerViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTblActive", TxtTblActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfPfxActive", TxfPfxActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOptActive", LstOptActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOptEditAvail", ButOptEditAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmRelDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfOptValid == comp->TxfOptValid) insert(items, TXFOPTVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtFrtActive == comp->TxtFrtActive) insert(items, TXTFRTACTIVE);
	if (TxtFrsActive == comp->TxtFrsActive) insert(items, TXTFRSACTIVE);
	if (ButFrsViewAvail == comp->ButFrsViewAvail) insert(items, BUTFRSVIEWAVAIL);
	if (ButFrsViewActive == comp->ButFrsViewActive) insert(items, BUTFRSVIEWACTIVE);
	if (TxtTotActive == comp->TxtTotActive) insert(items, TXTTOTACTIVE);
	if (TxtTosActive == comp->TxtTosActive) insert(items, TXTTOSACTIVE);
	if (ButTosViewAvail == comp->ButTosViewAvail) insert(items, BUTTOSVIEWAVAIL);
	if (ButTosViewActive == comp->ButTosViewActive) insert(items, BUTTOSVIEWACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtVerActive == comp->TxtVerActive) insert(items, TXTVERACTIVE);
	if (ButVerViewAvail == comp->ButVerViewAvail) insert(items, BUTVERVIEWAVAIL);
	if (ButVerViewActive == comp->ButVerViewActive) insert(items, BUTVERVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (TxfPfxActive == comp->TxfPfxActive) insert(items, TXFPFXACTIVE);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (ButOptEditAvail == comp->ButOptEditAvail) insert(items, BUTOPTEDITAVAIL);

	return(items);
};

set<uint> PnlWznmRelDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFRTACTIVE, TXTFRSACTIVE, BUTFRSVIEWAVAIL, BUTFRSVIEWACTIVE, TXTTOTACTIVE, TXTTOSACTIVE, BUTTOSVIEWAVAIL, BUTTOSVIEWACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXFPFXACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmRelDetail::Tag
 ******************************************************************************/

void PnlWznmRelDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmRelDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmRelDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptFrt", "from table");
			writeStringAttr(wr, itemtag, "sref", "CptFrs", "from subset");
			writeStringAttr(wr, itemtag, "sref", "CptTot", "to table");
			writeStringAttr(wr, itemtag, "sref", "CptTos", "to subset");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptVer", "version");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super relation");
			writeStringAttr(wr, itemtag, "sref", "CptTbl", "table");
			writeStringAttr(wr, itemtag, "sref", "CptPfx", "prefix");
			writeStringAttr(wr, itemtag, "sref", "CptOpt", "options");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecWznmVTag::getTitle(VecWznmVTag::CLUST, ixWznmVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmRelDetail::DpchAppData
 ******************************************************************************/

PnlWznmRelDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELDETAILDATA)
		{
};

string PnlWznmRelDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmRelDetailData");
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
 class PnlWznmRelDetail::DpchAppDo
 ******************************************************************************/

PnlWznmRelDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMRELDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmRelDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmRelDetailDo");
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
 class PnlWznmRelDetail::DpchEngData
 ******************************************************************************/

PnlWznmRelDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFLstOpt
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMRELDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFLSTOPT, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFLSTOPT) && feedFLstOpt) this->feedFLstOpt = *feedFLstOpt;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmRelDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmRelDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFLSTOPT)) {feedFLstOpt = src->feedFLstOpt; add(FEEDFLSTOPT);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmRelDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmRelDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFLSTOPT)) feedFLstOpt.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

