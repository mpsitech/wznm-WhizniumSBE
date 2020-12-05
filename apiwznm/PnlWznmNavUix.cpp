/**
	* \file PnlWznmNavUix.cpp
	* API code for job PnlWznmNavUix (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmNavUix.h"

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

PnlWznmNavUix::StatApp::StatApp(
			const uint ixWznmVExpstate
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
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstPstAlt = LstPstAlt;
	this->LstMdlAlt = LstMdlAlt;
	this->LstCarAlt = LstCarAlt;
	this->LstDlgAlt = LstDlgAlt;
	this->LstPnlAlt = LstPnlAlt;
	this->LstQryAlt = LstQryAlt;
	this->LstQcoAlt = LstQcoAlt;
	this->LstQmdAlt = LstQmdAlt;
	this->LstConAlt = LstConAlt;
	this->LstPstNumFirstdisp = LstPstNumFirstdisp;
	this->LstMdlNumFirstdisp = LstMdlNumFirstdisp;
	this->LstCarNumFirstdisp = LstCarNumFirstdisp;
	this->LstDlgNumFirstdisp = LstDlgNumFirstdisp;
	this->LstPnlNumFirstdisp = LstPnlNumFirstdisp;
	this->LstQryNumFirstdisp = LstQryNumFirstdisp;
	this->LstQcoNumFirstdisp = LstQcoNumFirstdisp;
	this->LstQmdNumFirstdisp = LstQmdNumFirstdisp;
	this->LstConNumFirstdisp = LstConNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTPSTALT, LSTMDLALT, LSTCARALT, LSTDLGALT, LSTPNLALT, LSTQRYALT, LSTQCOALT, LSTQMDALT, LSTCONALT, LSTPSTNUMFIRSTDISP, LSTMDLNUMFIRSTDISP, LSTCARNUMFIRSTDISP, LSTDLGNUMFIRSTDISP, LSTPNLNUMFIRSTDISP, LSTQRYNUMFIRSTDISP, LSTQCONUMFIRSTDISP, LSTQMDNUMFIRSTDISP, LSTCONNUMFIRSTDISP};
};

bool PnlWznmNavUix::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmNavUix");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmNavUix";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPstAlt", LstPstAlt)) add(LSTPSTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMdlAlt", LstMdlAlt)) add(LSTMDLALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCarAlt", LstCarAlt)) add(LSTCARALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDlgAlt", LstDlgAlt)) add(LSTDLGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPnlAlt", LstPnlAlt)) add(LSTPNLALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQryAlt", LstQryAlt)) add(LSTQRYALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQcoAlt", LstQcoAlt)) add(LSTQCOALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQmdAlt", LstQmdAlt)) add(LSTQMDALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstConAlt", LstConAlt)) add(LSTCONALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPstNumFirstdisp", LstPstNumFirstdisp)) add(LSTPSTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMdlNumFirstdisp", LstMdlNumFirstdisp)) add(LSTMDLNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCarNumFirstdisp", LstCarNumFirstdisp)) add(LSTCARNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDlgNumFirstdisp", LstDlgNumFirstdisp)) add(LSTDLGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPnlNumFirstdisp", LstPnlNumFirstdisp)) add(LSTPNLNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQryNumFirstdisp", LstQryNumFirstdisp)) add(LSTQRYNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQcoNumFirstdisp", LstQcoNumFirstdisp)) add(LSTQCONUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQmdNumFirstdisp", LstQmdNumFirstdisp)) add(LSTQMDNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstConNumFirstdisp", LstConNumFirstdisp)) add(LSTCONNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmNavUix::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstPstAlt == comp->LstPstAlt) insert(items, LSTPSTALT);
	if (LstMdlAlt == comp->LstMdlAlt) insert(items, LSTMDLALT);
	if (LstCarAlt == comp->LstCarAlt) insert(items, LSTCARALT);
	if (LstDlgAlt == comp->LstDlgAlt) insert(items, LSTDLGALT);
	if (LstPnlAlt == comp->LstPnlAlt) insert(items, LSTPNLALT);
	if (LstQryAlt == comp->LstQryAlt) insert(items, LSTQRYALT);
	if (LstQcoAlt == comp->LstQcoAlt) insert(items, LSTQCOALT);
	if (LstQmdAlt == comp->LstQmdAlt) insert(items, LSTQMDALT);
	if (LstConAlt == comp->LstConAlt) insert(items, LSTCONALT);
	if (LstPstNumFirstdisp == comp->LstPstNumFirstdisp) insert(items, LSTPSTNUMFIRSTDISP);
	if (LstMdlNumFirstdisp == comp->LstMdlNumFirstdisp) insert(items, LSTMDLNUMFIRSTDISP);
	if (LstCarNumFirstdisp == comp->LstCarNumFirstdisp) insert(items, LSTCARNUMFIRSTDISP);
	if (LstDlgNumFirstdisp == comp->LstDlgNumFirstdisp) insert(items, LSTDLGNUMFIRSTDISP);
	if (LstPnlNumFirstdisp == comp->LstPnlNumFirstdisp) insert(items, LSTPNLNUMFIRSTDISP);
	if (LstQryNumFirstdisp == comp->LstQryNumFirstdisp) insert(items, LSTQRYNUMFIRSTDISP);
	if (LstQcoNumFirstdisp == comp->LstQcoNumFirstdisp) insert(items, LSTQCONUMFIRSTDISP);
	if (LstQmdNumFirstdisp == comp->LstQmdNumFirstdisp) insert(items, LSTQMDNUMFIRSTDISP);
	if (LstConNumFirstdisp == comp->LstConNumFirstdisp) insert(items, LSTCONNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmNavUix::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTPSTALT, LSTMDLALT, LSTCARALT, LSTDLGALT, LSTPNLALT, LSTQRYALT, LSTQCOALT, LSTQMDALT, LSTCONALT, LSTPSTNUMFIRSTDISP, LSTMDLNUMFIRSTDISP, LSTCARNUMFIRSTDISP, LSTDLGNUMFIRSTDISP, LSTPNLNUMFIRSTDISP, LSTQRYNUMFIRSTDISP, LSTQCONUMFIRSTDISP, LSTQMDNUMFIRSTDISP, LSTCONNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
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

bool PnlWznmNavUix::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmNavUix");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmNavUix";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPstAvail", LstPstAvail)) add(LSTPSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstViewActive", ButPstViewActive)) add(BUTPSTVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPstNewcrdActive", ButPstNewcrdActive)) add(BUTPSTNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstMdlAvail", LstMdlAvail)) add(LSTMDLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", ButMdlViewActive)) add(BUTMDLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButMdlNewcrdActive", ButMdlNewcrdActive)) add(BUTMDLNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCarAvail", LstCarAvail)) add(LSTCARAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCarViewActive", ButCarViewActive)) add(BUTCARVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCarNewcrdActive", ButCarNewcrdActive)) add(BUTCARNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstDlgAvail", LstDlgAvail)) add(LSTDLGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDlgViewActive", ButDlgViewActive)) add(BUTDLGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButDlgNewcrdActive", ButDlgNewcrdActive)) add(BUTDLGNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstPnlAvail", LstPnlAvail)) add(LSTPNLAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPnlViewActive", ButPnlViewActive)) add(BUTPNLVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButPnlNewcrdActive", ButPnlNewcrdActive)) add(BUTPNLNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQryAvail", LstQryAvail)) add(LSTQRYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQryViewActive", ButQryViewActive)) add(BUTQRYVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQryNewcrdActive", ButQryNewcrdActive)) add(BUTQRYNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQcoAvail", LstQcoAvail)) add(LSTQCOAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQcoViewActive", ButQcoViewActive)) add(BUTQCOVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQcoNewcrdActive", ButQcoNewcrdActive)) add(BUTQCONEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstQmdAvail", LstQmdAvail)) add(LSTQMDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQmdViewActive", ButQmdViewActive)) add(BUTQMDVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButQmdNewcrdActive", ButQmdNewcrdActive)) add(BUTQMDNEWCRDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstConAvail", LstConAvail)) add(LSTCONAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButConViewActive", ButConViewActive)) add(BUTCONVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButConNewcrdActive", ButConNewcrdActive)) add(BUTCONNEWCRDACTIVE);
	};

	return basefound;
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

PnlWznmNavUix::Tag::Tag(
			const string& Cpt
			, const string& CptPst
			, const string& CptMdl
			, const string& CptCar
			, const string& CptDlg
			, const string& CptPnl
			, const string& CptQry
			, const string& CptQco
			, const string& CptQmd
			, const string& CptCon
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptPst = CptPst;
	this->CptMdl = CptMdl;
	this->CptCar = CptCar;
	this->CptDlg = CptDlg;
	this->CptPnl = CptPnl;
	this->CptQry = CptQry;
	this->CptQco = CptQco;
	this->CptQmd = CptQmd;
	this->CptCon = CptCon;

	mask = {CPT, CPTPST, CPTMDL, CPTCAR, CPTDLG, CPTPNL, CPTQRY, CPTQCO, CPTQMD, CPTCON};
};

bool PnlWznmNavUix::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmNavUix");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmNavUix";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPst", CptPst)) add(CPTPST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptMdl", CptMdl)) add(CPTMDL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCar", CptCar)) add(CPTCAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptDlg", CptDlg)) add(CPTDLG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptPnl", CptPnl)) add(CPTPNL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptQry", CptQry)) add(CPTQRY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptQco", CptQco)) add(CPTQCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptQmd", CptQmd)) add(CPTQMD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCon", CptCon)) add(CPTCON);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmNavUix::DpchAppData
 ******************************************************************************/

PnlWznmNavUix::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVUIXDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmNavUix::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavUix::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavUixData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavUix::DpchAppDo
 ******************************************************************************/

PnlWznmNavUix::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMNAVUIXDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmNavUix::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavUix::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmNavUixDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavUix::DpchEngData
 ******************************************************************************/

PnlWznmNavUix::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVUIXDATA)
		{
	feedFLstCar.tag = "FeedFLstCar";
	feedFLstCon.tag = "FeedFLstCon";
	feedFLstDlg.tag = "FeedFLstDlg";
	feedFLstMdl.tag = "FeedFLstMdl";
	feedFLstPnl.tag = "FeedFLstPnl";
	feedFLstPst.tag = "FeedFLstPst";
	feedFLstQco.tag = "FeedFLstQco";
	feedFLstQmd.tag = "FeedFLstQmd";
	feedFLstQry.tag = "FeedFLstQry";
};

string PnlWznmNavUix::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
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

void PnlWznmNavUix::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmNavUixData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFLstCar.readXML(docctx, basexpath, true)) add(FEEDFLSTCAR);
		if (feedFLstCon.readXML(docctx, basexpath, true)) add(FEEDFLSTCON);
		if (feedFLstDlg.readXML(docctx, basexpath, true)) add(FEEDFLSTDLG);
		if (feedFLstMdl.readXML(docctx, basexpath, true)) add(FEEDFLSTMDL);
		if (feedFLstPnl.readXML(docctx, basexpath, true)) add(FEEDFLSTPNL);
		if (feedFLstPst.readXML(docctx, basexpath, true)) add(FEEDFLSTPST);
		if (feedFLstQco.readXML(docctx, basexpath, true)) add(FEEDFLSTQCO);
		if (feedFLstQmd.readXML(docctx, basexpath, true)) add(FEEDFLSTQMD);
		if (feedFLstQry.readXML(docctx, basexpath, true)) add(FEEDFLSTQRY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFLstCar.clear();
		feedFLstCon.clear();
		feedFLstDlg.clear();
		feedFLstMdl.clear();
		feedFLstPnl.clear();
		feedFLstPst.clear();
		feedFLstQco.clear();
		feedFLstQmd.clear();
		feedFLstQry.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

