/**
	* \file PnlWznmTcoDetail_blks.cpp
	* job handler for job PnlWznmTcoDetail (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTcoDetail::VecVDo
 ******************************************************************************/

uint PnlWznmTcoDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "buttblviewclick") return BUTTBLVIEWCLICK;
	if (s == "butsbsviewclick") return BUTSBSVIEWCLICK;
	if (s == "butrelviewclick") return BUTRELVIEWCLICK;
	if (s == "butfcuviewclick") return BUTFCUVIEWCLICK;
	if (s == "butopteditclick") return BUTOPTEDITCLICK;

	return(0);
};

string PnlWznmTcoDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTTBLVIEWCLICK) return("ButTblViewClick");
	if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
	if (ix == BUTRELVIEWCLICK) return("ButRelViewClick");
	if (ix == BUTFCUVIEWCLICK) return("ButFcuViewClick");
	if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

	return("");
};

/******************************************************************************
 class PnlWznmTcoDetail::ContIac
 ******************************************************************************/

PnlWznmTcoDetail::ContIac::ContIac(
			const string& TxfSho
			, const uint numFPupTyp
			, const uint numFPupFct
			, const uint numFPupSty
			, const uint numFPupAxf
			, const vector<uint>& numsFLstOpt
			, const string& TxfOpt
			, const bool ChkPnc
			, const bool ChkEpo
		) :
			Block()
		{
	this->TxfSho = TxfSho;
	this->numFPupTyp = numFPupTyp;
	this->numFPupFct = numFPupFct;
	this->numFPupSty = numFPupSty;
	this->numFPupAxf = numFPupAxf;
	this->numsFLstOpt = numsFLstOpt;
	this->TxfOpt = TxfOpt;
	this->ChkPnc = ChkPnc;
	this->ChkEpo = ChkEpo;

	mask = {TXFSHO, NUMFPUPTYP, NUMFPUPFCT, NUMFPUPSTY, NUMFPUPAXF, NUMSFLSTOPT, TXFOPT, CHKPNC, CHKEPO};
};

bool PnlWznmTcoDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmTcoDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmTcoDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSho", TxfSho)) add(TXFSHO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupFct", numFPupFct)) add(NUMFPUPFCT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSty", numFPupSty)) add(NUMFPUPSTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupAxf", numFPupAxf)) add(NUMFPUPAXF);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOpt", TxfOpt)) add(TXFOPT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkPnc", ChkPnc)) add(CHKPNC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkEpo", ChkEpo)) add(CHKEPO);
	};

	return basefound;
};

void PnlWznmTcoDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmTcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmTcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSho", TxfSho);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFPupFct", numFPupFct);
		writeUintAttr(wr, itemtag, "sref", "numFPupSty", numFPupSty);
		writeUintAttr(wr, itemtag, "sref", "numFPupAxf", numFPupAxf);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfOpt", TxfOpt);
		writeBoolAttr(wr, itemtag, "sref", "ChkPnc", ChkPnc);
		writeBoolAttr(wr, itemtag, "sref", "ChkEpo", ChkEpo);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTcoDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSho == comp->TxfSho) insert(items, TXFSHO);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFPupFct == comp->numFPupFct) insert(items, NUMFPUPFCT);
	if (numFPupSty == comp->numFPupSty) insert(items, NUMFPUPSTY);
	if (numFPupAxf == comp->numFPupAxf) insert(items, NUMFPUPAXF);
	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (TxfOpt == comp->TxfOpt) insert(items, TXFOPT);
	if (ChkPnc == comp->ChkPnc) insert(items, CHKPNC);
	if (ChkEpo == comp->ChkEpo) insert(items, CHKEPO);

	return(items);
};

set<uint> PnlWznmTcoDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSHO, NUMFPUPTYP, NUMFPUPFCT, NUMFPUPSTY, NUMFPUPAXF, NUMSFLSTOPT, TXFOPT, CHKPNC, CHKEPO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoDetail::ContInf
 ******************************************************************************/

PnlWznmTcoDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTbl
			, const string& TxtSbs
			, const string& TxtRel
			, const string& TxtFcu
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTbl = TxtTbl;
	this->TxtSbs = TxtSbs;
	this->TxtRel = TxtRel;
	this->TxtFcu = TxtFcu;

	mask = {TXTSRF, TXTTBL, TXTSBS, TXTREL, TXTFCU};
};

void PnlWznmTcoDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmTcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmTcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTbl", TxtTbl);
		writeStringAttr(wr, itemtag, "sref", "TxtSbs", TxtSbs);
		writeStringAttr(wr, itemtag, "sref", "TxtRel", TxtRel);
		writeStringAttr(wr, itemtag, "sref", "TxtFcu", TxtFcu);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTcoDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTbl == comp->TxtTbl) insert(items, TXTTBL);
	if (TxtSbs == comp->TxtSbs) insert(items, TXTSBS);
	if (TxtRel == comp->TxtRel) insert(items, TXTREL);
	if (TxtFcu == comp->TxtFcu) insert(items, TXTFCU);

	return(items);
};

set<uint> PnlWznmTcoDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTBL, TXTSBS, TXTREL, TXTFCU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoDetail::StatApp
 ******************************************************************************/

void PnlWznmTcoDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstOptAlt
			, const uint LstOptNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmTcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmTcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstOptAlt", LstOptAlt);
		writeUintAttr(wr, itemtag, "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTcoDetail::StatShr
 ******************************************************************************/

PnlWznmTcoDetail::StatShr::StatShr(
			const bool TxfOptValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxfShoActive
			, const bool PupTypActive
			, const bool TxtTblActive
			, const bool ButTblViewAvail
			, const bool ButTblViewActive
			, const bool TxtSbsAvail
			, const bool TxtSbsActive
			, const bool ButSbsViewAvail
			, const bool ButSbsViewActive
			, const bool TxtRelAvail
			, const bool TxtRelActive
			, const bool ButRelViewAvail
			, const bool ButRelViewActive
			, const bool TxtFcuAvail
			, const bool TxtFcuActive
			, const bool ButFcuViewAvail
			, const bool ButFcuViewActive
			, const bool PupStyActive
			, const bool PupAxfActive
			, const bool LstOptActive
			, const bool ButOptEditAvail
			, const bool ChkPncActive
			, const bool ChkEpoActive
		) :
			Block()
		{
	this->TxfOptValid = TxfOptValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxfShoActive = TxfShoActive;
	this->PupTypActive = PupTypActive;
	this->TxtTblActive = TxtTblActive;
	this->ButTblViewAvail = ButTblViewAvail;
	this->ButTblViewActive = ButTblViewActive;
	this->TxtSbsAvail = TxtSbsAvail;
	this->TxtSbsActive = TxtSbsActive;
	this->ButSbsViewAvail = ButSbsViewAvail;
	this->ButSbsViewActive = ButSbsViewActive;
	this->TxtRelAvail = TxtRelAvail;
	this->TxtRelActive = TxtRelActive;
	this->ButRelViewAvail = ButRelViewAvail;
	this->ButRelViewActive = ButRelViewActive;
	this->TxtFcuAvail = TxtFcuAvail;
	this->TxtFcuActive = TxtFcuActive;
	this->ButFcuViewAvail = ButFcuViewAvail;
	this->ButFcuViewActive = ButFcuViewActive;
	this->PupStyActive = PupStyActive;
	this->PupAxfActive = PupAxfActive;
	this->LstOptActive = LstOptActive;
	this->ButOptEditAvail = ButOptEditAvail;
	this->ChkPncActive = ChkPncActive;
	this->ChkEpoActive = ChkEpoActive;

	mask = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, BUTTBLVIEWAVAIL, BUTTBLVIEWACTIVE, TXTSBSAVAIL, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, TXTRELAVAIL, TXTRELACTIVE, BUTRELVIEWAVAIL, BUTRELVIEWACTIVE, TXTFCUAVAIL, TXTFCUACTIVE, BUTFCUVIEWAVAIL, BUTFCUVIEWACTIVE, PUPSTYACTIVE, PUPAXFACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, CHKPNCACTIVE, CHKEPOACTIVE};
};

void PnlWznmTcoDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmTcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmTcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfOptValid", TxfOptValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfShoActive", TxfShoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTblActive", TxtTblActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTblViewAvail", ButTblViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTblViewActive", ButTblViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSbsAvail", TxtSbsAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtSbsActive", TxtSbsActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSbsViewAvail", ButSbsViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSbsViewActive", ButSbsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtRelAvail", TxtRelAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtRelActive", TxtRelActive);
		writeBoolAttr(wr, itemtag, "sref", "ButRelViewAvail", ButRelViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRelViewActive", ButRelViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFcuAvail", TxtFcuAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtFcuActive", TxtFcuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFcuViewAvail", ButFcuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFcuViewActive", ButFcuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupStyActive", PupStyActive);
		writeBoolAttr(wr, itemtag, "sref", "PupAxfActive", PupAxfActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOptActive", LstOptActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOptEditAvail", ButOptEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ChkPncActive", ChkPncActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkEpoActive", ChkEpoActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTcoDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfOptValid == comp->TxfOptValid) insert(items, TXFOPTVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxfShoActive == comp->TxfShoActive) insert(items, TXFSHOACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (TxtTblActive == comp->TxtTblActive) insert(items, TXTTBLACTIVE);
	if (ButTblViewAvail == comp->ButTblViewAvail) insert(items, BUTTBLVIEWAVAIL);
	if (ButTblViewActive == comp->ButTblViewActive) insert(items, BUTTBLVIEWACTIVE);
	if (TxtSbsAvail == comp->TxtSbsAvail) insert(items, TXTSBSAVAIL);
	if (TxtSbsActive == comp->TxtSbsActive) insert(items, TXTSBSACTIVE);
	if (ButSbsViewAvail == comp->ButSbsViewAvail) insert(items, BUTSBSVIEWAVAIL);
	if (ButSbsViewActive == comp->ButSbsViewActive) insert(items, BUTSBSVIEWACTIVE);
	if (TxtRelAvail == comp->TxtRelAvail) insert(items, TXTRELAVAIL);
	if (TxtRelActive == comp->TxtRelActive) insert(items, TXTRELACTIVE);
	if (ButRelViewAvail == comp->ButRelViewAvail) insert(items, BUTRELVIEWAVAIL);
	if (ButRelViewActive == comp->ButRelViewActive) insert(items, BUTRELVIEWACTIVE);
	if (TxtFcuAvail == comp->TxtFcuAvail) insert(items, TXTFCUAVAIL);
	if (TxtFcuActive == comp->TxtFcuActive) insert(items, TXTFCUACTIVE);
	if (ButFcuViewAvail == comp->ButFcuViewAvail) insert(items, BUTFCUVIEWAVAIL);
	if (ButFcuViewActive == comp->ButFcuViewActive) insert(items, BUTFCUVIEWACTIVE);
	if (PupStyActive == comp->PupStyActive) insert(items, PUPSTYACTIVE);
	if (PupAxfActive == comp->PupAxfActive) insert(items, PUPAXFACTIVE);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (ButOptEditAvail == comp->ButOptEditAvail) insert(items, BUTOPTEDITAVAIL);
	if (ChkPncActive == comp->ChkPncActive) insert(items, CHKPNCACTIVE);
	if (ChkEpoActive == comp->ChkEpoActive) insert(items, CHKEPOACTIVE);

	return(items);
};

set<uint> PnlWznmTcoDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, BUTTBLVIEWAVAIL, BUTTBLVIEWACTIVE, TXTSBSAVAIL, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, TXTRELAVAIL, TXTRELACTIVE, BUTRELVIEWAVAIL, BUTRELVIEWACTIVE, TXTFCUAVAIL, TXTFCUACTIVE, BUTFCUVIEWAVAIL, BUTFCUVIEWACTIVE, PUPSTYACTIVE, PUPAXFACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, CHKPNCACTIVE, CHKEPOACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTcoDetail::Tag
 ******************************************************************************/

void PnlWznmTcoDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmTcoDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmTcoDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptSho", "acronym");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptTbl", "table");
			writeStringAttr(wr, itemtag, "sref", "CptSbs", "subset");
			writeStringAttr(wr, itemtag, "sref", "CptRel", "relation");
			writeStringAttr(wr, itemtag, "sref", "CptFcu", "functionality");
			writeStringAttr(wr, itemtag, "sref", "CptSty", "subtype");
			writeStringAttr(wr, itemtag, "sref", "CptAxf", "axis functionality");
			writeStringAttr(wr, itemtag, "sref", "CptOpt", "options");
			writeStringAttr(wr, itemtag, "sref", "CptPnc", "principal");
			writeStringAttr(wr, itemtag, "sref", "CptEpo", "eponymous for record");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTcoDetail::DpchAppData
 ******************************************************************************/

PnlWznmTcoDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTCODETAILDATA)
		{
};

string PnlWznmTcoDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTcoDetailData");
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
 class PnlWznmTcoDetail::DpchAppDo
 ******************************************************************************/

PnlWznmTcoDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTCODETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmTcoDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTcoDetailDo");
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
 class PnlWznmTcoDetail::DpchEngData
 ******************************************************************************/

PnlWznmTcoDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstOpt
			, Feed* feedFPupAxf
			, Feed* feedFPupFct
			, Feed* feedFPupSty
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTCODETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTOPT, FEEDFPUPAXF, FEEDFPUPFCT, FEEDFPUPSTY, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTOPT) && feedFLstOpt) this->feedFLstOpt = *feedFLstOpt;
	if (find(this->mask, FEEDFPUPAXF) && feedFPupAxf) this->feedFPupAxf = *feedFPupAxf;
	if (find(this->mask, FEEDFPUPFCT) && feedFPupFct) this->feedFPupFct = *feedFPupFct;
	if (find(this->mask, FEEDFPUPSTY) && feedFPupSty) this->feedFPupSty = *feedFPupSty;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmTcoDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(FEEDFPUPAXF)) ss.push_back("feedFPupAxf");
	if (has(FEEDFPUPFCT)) ss.push_back("feedFPupFct");
	if (has(FEEDFPUPSTY)) ss.push_back("feedFPupSty");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTcoDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTOPT)) {feedFLstOpt = src->feedFLstOpt; add(FEEDFLSTOPT);};
	if (src->has(FEEDFPUPAXF)) {feedFPupAxf = src->feedFPupAxf; add(FEEDFPUPAXF);};
	if (src->has(FEEDFPUPFCT)) {feedFPupFct = src->feedFPupFct; add(FEEDFPUPFCT);};
	if (src->has(FEEDFPUPSTY)) {feedFPupSty = src->feedFPupSty; add(FEEDFPUPSTY);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmTcoDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmTcoDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTOPT)) feedFLstOpt.writeXML(wr);
		if (has(FEEDFPUPAXF)) feedFPupAxf.writeXML(wr);
		if (has(FEEDFPUPFCT)) feedFPupFct.writeXML(wr);
		if (has(FEEDFPUPSTY)) feedFPupSty.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};

