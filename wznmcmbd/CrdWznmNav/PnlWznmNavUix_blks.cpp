/**
	* \file PnlWznmNavUix_blks.cpp
	* job handler for job PnlWznmNavUix (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavUix::VecVDo
 ******************************************************************************/

uint PnlWznmNavUix::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butpstviewclick") return BUTPSTVIEWCLICK;
	if (s == "butpstnewcrdclick") return BUTPSTNEWCRDCLICK;
	if (s == "butmdlviewclick") return BUTMDLVIEWCLICK;
	if (s == "butmdlnewcrdclick") return BUTMDLNEWCRDCLICK;
	if (s == "butcarviewclick") return BUTCARVIEWCLICK;
	if (s == "butcarnewcrdclick") return BUTCARNEWCRDCLICK;
	if (s == "butdlgviewclick") return BUTDLGVIEWCLICK;
	if (s == "butdlgnewcrdclick") return BUTDLGNEWCRDCLICK;
	if (s == "butpnlviewclick") return BUTPNLVIEWCLICK;
	if (s == "butpnlnewcrdclick") return BUTPNLNEWCRDCLICK;
	if (s == "butqryviewclick") return BUTQRYVIEWCLICK;
	if (s == "butqrynewcrdclick") return BUTQRYNEWCRDCLICK;
	if (s == "butqcoviewclick") return BUTQCOVIEWCLICK;
	if (s == "butqconewcrdclick") return BUTQCONEWCRDCLICK;
	if (s == "butqmdviewclick") return BUTQMDVIEWCLICK;
	if (s == "butqmdnewcrdclick") return BUTQMDNEWCRDCLICK;
	if (s == "butconviewclick") return BUTCONVIEWCLICK;
	if (s == "butconnewcrdclick") return BUTCONNEWCRDCLICK;

	return(0);
};

string PnlWznmNavUix::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
	if (ix == BUTPSTNEWCRDCLICK) return("ButPstNewcrdClick");
	if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
	if (ix == BUTMDLNEWCRDCLICK) return("ButMdlNewcrdClick");
	if (ix == BUTCARVIEWCLICK) return("ButCarViewClick");
	if (ix == BUTCARNEWCRDCLICK) return("ButCarNewcrdClick");
	if (ix == BUTDLGVIEWCLICK) return("ButDlgViewClick");
	if (ix == BUTDLGNEWCRDCLICK) return("ButDlgNewcrdClick");
	if (ix == BUTPNLVIEWCLICK) return("ButPnlViewClick");
	if (ix == BUTPNLNEWCRDCLICK) return("ButPnlNewcrdClick");
	if (ix == BUTQRYVIEWCLICK) return("ButQryViewClick");
	if (ix == BUTQRYNEWCRDCLICK) return("ButQryNewcrdClick");
	if (ix == BUTQCOVIEWCLICK) return("ButQcoViewClick");
	if (ix == BUTQCONEWCRDCLICK) return("ButQcoNewcrdClick");
	if (ix == BUTQMDVIEWCLICK) return("ButQmdViewClick");
	if (ix == BUTQMDNEWCRDCLICK) return("ButQmdNewcrdClick");
	if (ix == BUTCONVIEWCLICK) return("ButConViewClick");
	if (ix == BUTCONNEWCRDCLICK) return("ButConNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWznmNavUix::ContIac
 ******************************************************************************/

PnlWznmNavUix::ContIac::ContIac(
			const uint numFLstPst
			, const uint numFLstMdl
			, const uint numFLstCar
			, const uint numFLstDlg
			, const uint numFLstPnl
			, const uint numFLstQry
			, const uint numFLstQco
			, const uint numFLstQmd
			, const uint numFLstCon
		) :
			Block()
		{
	this->numFLstPst = numFLstPst;
	this->numFLstMdl = numFLstMdl;
	this->numFLstCar = numFLstCar;
	this->numFLstDlg = numFLstDlg;
	this->numFLstPnl = numFLstPnl;
	this->numFLstQry = numFLstQry;
	this->numFLstQco = numFLstQco;
	this->numFLstQmd = numFLstQmd;
	this->numFLstCon = numFLstCon;

	mask = {NUMFLSTPST, NUMFLSTMDL, NUMFLSTCAR, NUMFLSTDLG, NUMFLSTPNL, NUMFLSTQRY, NUMFLSTQCO, NUMFLSTQMD, NUMFLSTCON};
};

bool PnlWznmNavUix::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmNavUix");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmNavUix";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPst", numFLstPst)) add(NUMFLSTPST);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstMdl", numFLstMdl)) add(NUMFLSTMDL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCar", numFLstCar)) add(NUMFLSTCAR);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstDlg", numFLstDlg)) add(NUMFLSTDLG);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstPnl", numFLstPnl)) add(NUMFLSTPNL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstQry", numFLstQry)) add(NUMFLSTQRY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstQco", numFLstQco)) add(NUMFLSTQCO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstQmd", numFLstQmd)) add(NUMFLSTQMD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstCon", numFLstCon)) add(NUMFLSTCON);
	};

	return basefound;
};

void PnlWznmNavUix::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmNavUix";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmNavUix";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFLstPst", numFLstPst);
		writeUintAttr(wr, itemtag, "sref", "numFLstMdl", numFLstMdl);
		writeUintAttr(wr, itemtag, "sref", "numFLstCar", numFLstCar);
		writeUintAttr(wr, itemtag, "sref", "numFLstDlg", numFLstDlg);
		writeUintAttr(wr, itemtag, "sref", "numFLstPnl", numFLstPnl);
		writeUintAttr(wr, itemtag, "sref", "numFLstQry", numFLstQry);
		writeUintAttr(wr, itemtag, "sref", "numFLstQco", numFLstQco);
		writeUintAttr(wr, itemtag, "sref", "numFLstQmd", numFLstQmd);
		writeUintAttr(wr, itemtag, "sref", "numFLstCon", numFLstCon);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavUix::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFLstPst == comp->numFLstPst) insert(items, NUMFLSTPST);
	if (numFLstMdl == comp->numFLstMdl) insert(items, NUMFLSTMDL);
	if (numFLstCar == comp->numFLstCar) insert(items, NUMFLSTCAR);
	if (numFLstDlg == comp->numFLstDlg) insert(items, NUMFLSTDLG);
	if (numFLstPnl == comp->numFLstPnl) insert(items, NUMFLSTPNL);
	if (numFLstQry == comp->numFLstQry) insert(items, NUMFLSTQRY);
	if (numFLstQco == comp->numFLstQco) insert(items, NUMFLSTQCO);
	if (numFLstQmd == comp->numFLstQmd) insert(items, NUMFLSTQMD);
	if (numFLstCon == comp->numFLstCon) insert(items, NUMFLSTCON);

	return(items);
};

set<uint> PnlWznmNavUix::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFLSTPST, NUMFLSTMDL, NUMFLSTCAR, NUMFLSTDLG, NUMFLSTPNL, NUMFLSTQRY, NUMFLSTQCO, NUMFLSTQMD, NUMFLSTCON};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavUix::StatApp
 ******************************************************************************/

void PnlWznmNavUix::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
			, const bool LstPstAlt
			, const bool LstMdlAlt
			, const bool LstCarAlt
			, const bool LstDlgAlt
			, const bool LstPnlAlt
			, const bool LstQryAlt
			, const bool LstQcoAlt
			, const bool LstQmdAlt
			, const bool LstConAlt
			, const uint LstPstNumFirstdisp
			, const uint LstMdlNumFirstdisp
			, const uint LstCarNumFirstdisp
			, const uint LstDlgNumFirstdisp
			, const uint LstPnlNumFirstdisp
			, const uint LstQryNumFirstdisp
			, const uint LstQcoNumFirstdisp
			, const uint LstQmdNumFirstdisp
			, const uint LstConNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmNavUix";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmNavUix";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstPstAlt", LstPstAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstMdlAlt", LstMdlAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstCarAlt", LstCarAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstDlgAlt", LstDlgAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstPnlAlt", LstPnlAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstQryAlt", LstQryAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstQcoAlt", LstQcoAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstQmdAlt", LstQmdAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstConAlt", LstConAlt);
		writeUintAttr(wr, itemtag, "sref", "LstPstNumFirstdisp", LstPstNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstMdlNumFirstdisp", LstMdlNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstCarNumFirstdisp", LstCarNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstDlgNumFirstdisp", LstDlgNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstPnlNumFirstdisp", LstPnlNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstQryNumFirstdisp", LstQryNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstQcoNumFirstdisp", LstQcoNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstQmdNumFirstdisp", LstQmdNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstConNumFirstdisp", LstConNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavUix::StatShr
 ******************************************************************************/

PnlWznmNavUix::StatShr::StatShr(
			const bool LstPstAvail
			, const bool ButPstViewActive
			, const bool ButPstNewcrdActive
			, const bool LstMdlAvail
			, const bool ButMdlViewActive
			, const bool ButMdlNewcrdActive
			, const bool LstCarAvail
			, const bool ButCarViewActive
			, const bool ButCarNewcrdActive
			, const bool LstDlgAvail
			, const bool ButDlgViewActive
			, const bool ButDlgNewcrdActive
			, const bool LstPnlAvail
			, const bool ButPnlViewActive
			, const bool ButPnlNewcrdActive
			, const bool LstQryAvail
			, const bool ButQryViewActive
			, const bool ButQryNewcrdActive
			, const bool LstQcoAvail
			, const bool ButQcoViewActive
			, const bool ButQcoNewcrdActive
			, const bool LstQmdAvail
			, const bool ButQmdViewActive
			, const bool ButQmdNewcrdActive
			, const bool LstConAvail
			, const bool ButConViewActive
			, const bool ButConNewcrdActive
		) :
			Block()
		{
	this->LstPstAvail = LstPstAvail;
	this->ButPstViewActive = ButPstViewActive;
	this->ButPstNewcrdActive = ButPstNewcrdActive;
	this->LstMdlAvail = LstMdlAvail;
	this->ButMdlViewActive = ButMdlViewActive;
	this->ButMdlNewcrdActive = ButMdlNewcrdActive;
	this->LstCarAvail = LstCarAvail;
	this->ButCarViewActive = ButCarViewActive;
	this->ButCarNewcrdActive = ButCarNewcrdActive;
	this->LstDlgAvail = LstDlgAvail;
	this->ButDlgViewActive = ButDlgViewActive;
	this->ButDlgNewcrdActive = ButDlgNewcrdActive;
	this->LstPnlAvail = LstPnlAvail;
	this->ButPnlViewActive = ButPnlViewActive;
	this->ButPnlNewcrdActive = ButPnlNewcrdActive;
	this->LstQryAvail = LstQryAvail;
	this->ButQryViewActive = ButQryViewActive;
	this->ButQryNewcrdActive = ButQryNewcrdActive;
	this->LstQcoAvail = LstQcoAvail;
	this->ButQcoViewActive = ButQcoViewActive;
	this->ButQcoNewcrdActive = ButQcoNewcrdActive;
	this->LstQmdAvail = LstQmdAvail;
	this->ButQmdViewActive = ButQmdViewActive;
	this->ButQmdNewcrdActive = ButQmdNewcrdActive;
	this->LstConAvail = LstConAvail;
	this->ButConViewActive = ButConViewActive;
	this->ButConNewcrdActive = ButConNewcrdActive;

	mask = {LSTPSTAVAIL, BUTPSTVIEWACTIVE, BUTPSTNEWCRDACTIVE, LSTMDLAVAIL, BUTMDLVIEWACTIVE, BUTMDLNEWCRDACTIVE, LSTCARAVAIL, BUTCARVIEWACTIVE, BUTCARNEWCRDACTIVE, LSTDLGAVAIL, BUTDLGVIEWACTIVE, BUTDLGNEWCRDACTIVE, LSTPNLAVAIL, BUTPNLVIEWACTIVE, BUTPNLNEWCRDACTIVE, LSTQRYAVAIL, BUTQRYVIEWACTIVE, BUTQRYNEWCRDACTIVE, LSTQCOAVAIL, BUTQCOVIEWACTIVE, BUTQCONEWCRDACTIVE, LSTQMDAVAIL, BUTQMDVIEWACTIVE, BUTQMDNEWCRDACTIVE, LSTCONAVAIL, BUTCONVIEWACTIVE, BUTCONNEWCRDACTIVE};
};

void PnlWznmNavUix::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavUix";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavUix";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "LstPstAvail", LstPstAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPstViewActive", ButPstViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPstNewcrdActive", ButPstNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstMdlAvail", LstMdlAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlViewActive", ButMdlViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButMdlNewcrdActive", ButMdlNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCarAvail", LstCarAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCarViewActive", ButCarViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCarNewcrdActive", ButCarNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDlgAvail", LstDlgAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButDlgViewActive", ButDlgViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButDlgNewcrdActive", ButDlgNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstPnlAvail", LstPnlAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButPnlViewActive", ButPnlViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButPnlNewcrdActive", ButPnlNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstQryAvail", LstQryAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButQryViewActive", ButQryViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButQryNewcrdActive", ButQryNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstQcoAvail", LstQcoAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButQcoViewActive", ButQcoViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButQcoNewcrdActive", ButQcoNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstQmdAvail", LstQmdAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButQmdViewActive", ButQmdViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButQmdNewcrdActive", ButQmdNewcrdActive);
		writeBoolAttr(wr, itemtag, "sref", "LstConAvail", LstConAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButConViewActive", ButConViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButConNewcrdActive", ButConNewcrdActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavUix::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (LstPstAvail == comp->LstPstAvail) insert(items, LSTPSTAVAIL);
	if (ButPstViewActive == comp->ButPstViewActive) insert(items, BUTPSTVIEWACTIVE);
	if (ButPstNewcrdActive == comp->ButPstNewcrdActive) insert(items, BUTPSTNEWCRDACTIVE);
	if (LstMdlAvail == comp->LstMdlAvail) insert(items, LSTMDLAVAIL);
	if (ButMdlViewActive == comp->ButMdlViewActive) insert(items, BUTMDLVIEWACTIVE);
	if (ButMdlNewcrdActive == comp->ButMdlNewcrdActive) insert(items, BUTMDLNEWCRDACTIVE);
	if (LstCarAvail == comp->LstCarAvail) insert(items, LSTCARAVAIL);
	if (ButCarViewActive == comp->ButCarViewActive) insert(items, BUTCARVIEWACTIVE);
	if (ButCarNewcrdActive == comp->ButCarNewcrdActive) insert(items, BUTCARNEWCRDACTIVE);
	if (LstDlgAvail == comp->LstDlgAvail) insert(items, LSTDLGAVAIL);
	if (ButDlgViewActive == comp->ButDlgViewActive) insert(items, BUTDLGVIEWACTIVE);
	if (ButDlgNewcrdActive == comp->ButDlgNewcrdActive) insert(items, BUTDLGNEWCRDACTIVE);
	if (LstPnlAvail == comp->LstPnlAvail) insert(items, LSTPNLAVAIL);
	if (ButPnlViewActive == comp->ButPnlViewActive) insert(items, BUTPNLVIEWACTIVE);
	if (ButPnlNewcrdActive == comp->ButPnlNewcrdActive) insert(items, BUTPNLNEWCRDACTIVE);
	if (LstQryAvail == comp->LstQryAvail) insert(items, LSTQRYAVAIL);
	if (ButQryViewActive == comp->ButQryViewActive) insert(items, BUTQRYVIEWACTIVE);
	if (ButQryNewcrdActive == comp->ButQryNewcrdActive) insert(items, BUTQRYNEWCRDACTIVE);
	if (LstQcoAvail == comp->LstQcoAvail) insert(items, LSTQCOAVAIL);
	if (ButQcoViewActive == comp->ButQcoViewActive) insert(items, BUTQCOVIEWACTIVE);
	if (ButQcoNewcrdActive == comp->ButQcoNewcrdActive) insert(items, BUTQCONEWCRDACTIVE);
	if (LstQmdAvail == comp->LstQmdAvail) insert(items, LSTQMDAVAIL);
	if (ButQmdViewActive == comp->ButQmdViewActive) insert(items, BUTQMDVIEWACTIVE);
	if (ButQmdNewcrdActive == comp->ButQmdNewcrdActive) insert(items, BUTQMDNEWCRDACTIVE);
	if (LstConAvail == comp->LstConAvail) insert(items, LSTCONAVAIL);
	if (ButConViewActive == comp->ButConViewActive) insert(items, BUTCONVIEWACTIVE);
	if (ButConNewcrdActive == comp->ButConNewcrdActive) insert(items, BUTCONNEWCRDACTIVE);

	return(items);
};

set<uint> PnlWznmNavUix::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LSTPSTAVAIL, BUTPSTVIEWACTIVE, BUTPSTNEWCRDACTIVE, LSTMDLAVAIL, BUTMDLVIEWACTIVE, BUTMDLNEWCRDACTIVE, LSTCARAVAIL, BUTCARVIEWACTIVE, BUTCARNEWCRDACTIVE, LSTDLGAVAIL, BUTDLGVIEWACTIVE, BUTDLGNEWCRDACTIVE, LSTPNLAVAIL, BUTPNLVIEWACTIVE, BUTPNLNEWCRDACTIVE, LSTQRYAVAIL, BUTQRYVIEWACTIVE, BUTQRYNEWCRDACTIVE, LSTQCOAVAIL, BUTQCOVIEWACTIVE, BUTQCONEWCRDACTIVE, LSTQMDAVAIL, BUTQMDVIEWACTIVE, BUTQMDNEWCRDACTIVE, LSTCONAVAIL, BUTCONVIEWACTIVE, BUTCONNEWCRDACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavUix::Tag
 ******************************************************************************/

void PnlWznmNavUix::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavUix";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavUix";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "User interface module");
			writeStringAttr(wr, itemtag, "sref", "CptPst", "presettings");
			writeStringAttr(wr, itemtag, "sref", "CptMdl", "modules");
			writeStringAttr(wr, itemtag, "sref", "CptCar", "cards");
			writeStringAttr(wr, itemtag, "sref", "CptDlg", "dialogs");
			writeStringAttr(wr, itemtag, "sref", "CptPnl", "panels");
			writeStringAttr(wr, itemtag, "sref", "CptQry", "queries");
			writeStringAttr(wr, itemtag, "sref", "CptQco", "query columns");
			writeStringAttr(wr, itemtag, "sref", "CptQmd", "query modifiers");
			writeStringAttr(wr, itemtag, "sref", "CptCon", "controls");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavUix::DpchAppData
 ******************************************************************************/

PnlWznmNavUix::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVUIXDATA)
		{
};

string PnlWznmNavUix::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavUix::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavUixData");
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
 class PnlWznmNavUix::DpchAppDo
 ******************************************************************************/

PnlWznmNavUix::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVUIXDO)
		{
	ixVDo = 0;
};

string PnlWznmNavUix::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavUix::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmNavUixDo");
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
 class PnlWznmNavUix::DpchEngData
 ******************************************************************************/

PnlWznmNavUix::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFLstCar
			, Feed* feedFLstCon
			, Feed* feedFLstDlg
			, Feed* feedFLstMdl
			, Feed* feedFLstPnl
			, Feed* feedFLstPst
			, Feed* feedFLstQco
			, Feed* feedFLstQmd
			, Feed* feedFLstQry
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVUIXDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFLSTCAR, FEEDFLSTCON, FEEDFLSTDLG, FEEDFLSTMDL, FEEDFLSTPNL, FEEDFLSTPST, FEEDFLSTQCO, FEEDFLSTQMD, FEEDFLSTQRY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFLSTCAR) && feedFLstCar) this->feedFLstCar = *feedFLstCar;
	if (find(this->mask, FEEDFLSTCON) && feedFLstCon) this->feedFLstCon = *feedFLstCon;
	if (find(this->mask, FEEDFLSTDLG) && feedFLstDlg) this->feedFLstDlg = *feedFLstDlg;
	if (find(this->mask, FEEDFLSTMDL) && feedFLstMdl) this->feedFLstMdl = *feedFLstMdl;
	if (find(this->mask, FEEDFLSTPNL) && feedFLstPnl) this->feedFLstPnl = *feedFLstPnl;
	if (find(this->mask, FEEDFLSTPST) && feedFLstPst) this->feedFLstPst = *feedFLstPst;
	if (find(this->mask, FEEDFLSTQCO) && feedFLstQco) this->feedFLstQco = *feedFLstQco;
	if (find(this->mask, FEEDFLSTQMD) && feedFLstQmd) this->feedFLstQmd = *feedFLstQmd;
	if (find(this->mask, FEEDFLSTQRY) && feedFLstQry) this->feedFLstQry = *feedFLstQry;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavUix::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFLSTCAR)) ss.push_back("feedFLstCar");
	if (has(FEEDFLSTCON)) ss.push_back("feedFLstCon");
	if (has(FEEDFLSTDLG)) ss.push_back("feedFLstDlg");
	if (has(FEEDFLSTMDL)) ss.push_back("feedFLstMdl");
	if (has(FEEDFLSTPNL)) ss.push_back("feedFLstPnl");
	if (has(FEEDFLSTPST)) ss.push_back("feedFLstPst");
	if (has(FEEDFLSTQCO)) ss.push_back("feedFLstQco");
	if (has(FEEDFLSTQMD)) ss.push_back("feedFLstQmd");
	if (has(FEEDFLSTQRY)) ss.push_back("feedFLstQry");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavUix::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFLSTCAR)) {feedFLstCar = src->feedFLstCar; add(FEEDFLSTCAR);};
	if (src->has(FEEDFLSTCON)) {feedFLstCon = src->feedFLstCon; add(FEEDFLSTCON);};
	if (src->has(FEEDFLSTDLG)) {feedFLstDlg = src->feedFLstDlg; add(FEEDFLSTDLG);};
	if (src->has(FEEDFLSTMDL)) {feedFLstMdl = src->feedFLstMdl; add(FEEDFLSTMDL);};
	if (src->has(FEEDFLSTPNL)) {feedFLstPnl = src->feedFLstPnl; add(FEEDFLSTPNL);};
	if (src->has(FEEDFLSTPST)) {feedFLstPst = src->feedFLstPst; add(FEEDFLSTPST);};
	if (src->has(FEEDFLSTQCO)) {feedFLstQco = src->feedFLstQco; add(FEEDFLSTQCO);};
	if (src->has(FEEDFLSTQMD)) {feedFLstQmd = src->feedFLstQmd; add(FEEDFLSTQMD);};
	if (src->has(FEEDFLSTQRY)) {feedFLstQry = src->feedFLstQry; add(FEEDFLSTQRY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavUix::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavUixData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFLSTCAR)) feedFLstCar.writeXML(wr);
		if (has(FEEDFLSTCON)) feedFLstCon.writeXML(wr);
		if (has(FEEDFLSTDLG)) feedFLstDlg.writeXML(wr);
		if (has(FEEDFLSTMDL)) feedFLstMdl.writeXML(wr);
		if (has(FEEDFLSTPNL)) feedFLstPnl.writeXML(wr);
		if (has(FEEDFLSTPST)) feedFLstPst.writeXML(wr);
		if (has(FEEDFLSTQCO)) feedFLstQco.writeXML(wr);
		if (has(FEEDFLSTQMD)) feedFLstQmd.writeXML(wr);
		if (has(FEEDFLSTQRY)) feedFLstQry.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};



