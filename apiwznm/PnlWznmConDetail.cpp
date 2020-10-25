/**
	* \file PnlWznmConDetail.cpp
	* API code for job PnlWznmConDetail (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "PnlWznmConDetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmConDetail::VecVDo
 ******************************************************************************/

uint PnlWznmConDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	if (s == "butjtieditclick") return BUTJTIEDITCLICK;
	if (s == "butcluviewclick") return BUTCLUVIEWCLICK;
	if (s == "butcluclusterclick") return BUTCLUCLUSTERCLICK;
	if (s == "butcluunclusterclick") return BUTCLUUNCLUSTERCLICK;
	if (s == "buthkuviewclick") return BUTHKUVIEWCLICK;
	if (s == "butreuviewclick") return BUTREUVIEWCLICK;
	if (s == "butsupviewclick") return BUTSUPVIEWCLICK;
	if (s == "buttagviewclick") return BUTTAGVIEWCLICK;
	if (s == "butstsviewclick") return BUTSTSVIEWCLICK;
	if (s == "butshsviewclick") return BUTSHSVIEWCLICK;
	if (s == "butopteditclick") return BUTOPTEDITCLICK;
	if (s == "butfednewclick") return BUTFEDNEWCLICK;
	if (s == "butfeddeleteclick") return BUTFEDDELETECLICK;
	if (s == "butfedsruviewclick") return BUTFEDSRUVIEWCLICK;
	if (s == "butfedvitviewclick") return BUTFEDVITVIEWCLICK;
	if (s == "butfedtagviewclick") return BUTFEDTAGVIEWCLICK;

	return(0);
};

string PnlWznmConDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
	if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
	if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
	if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
	if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
	if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
	if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
	if (ix == BUTTAGVIEWCLICK) return("ButTagViewClick");
	if (ix == BUTSTSVIEWCLICK) return("ButStsViewClick");
	if (ix == BUTSHSVIEWCLICK) return("ButShsViewClick");
	if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");
	if (ix == BUTFEDNEWCLICK) return("ButFedNewClick");
	if (ix == BUTFEDDELETECLICK) return("ButFedDeleteClick");
	if (ix == BUTFEDSRUVIEWCLICK) return("ButFedSruViewClick");
	if (ix == BUTFEDVITVIEWCLICK) return("ButFedVitViewClick");
	if (ix == BUTFEDTAGVIEWCLICK) return("ButFedTagViewClick");

	return("");
};

/******************************************************************************
 class PnlWznmConDetail::ContIac
 ******************************************************************************/

PnlWznmConDetail::ContIac::ContIac(
			const uint numFPupJti
			, const uint numFPupTyp
			, const uint numFLstClu
			, const uint numFPupHkt
			, const uint numFPupRet
			, const uint numFPupSco
			, const uint numFPupSty
			, const uint numFLstTag
			, const string& TxfTag
			, const string& TxfAvl
			, const string& TxfAct
			, const vector<uint>& numsFLstOpt
			, const string& TxfOpt
			, const uint numFPupFedSrt
			, const uint numFLstFedVit
			, const string& TxfFedVit
			, const uint numFLstFedTag
			, const string& TxfFedTag
			, const string& TxfFedCmt
		) :
			Block()
		{
	this->numFPupJti = numFPupJti;
	this->numFPupTyp = numFPupTyp;
	this->numFLstClu = numFLstClu;
	this->numFPupHkt = numFPupHkt;
	this->numFPupRet = numFPupRet;
	this->numFPupSco = numFPupSco;
	this->numFPupSty = numFPupSty;
	this->numFLstTag = numFLstTag;
	this->TxfTag = TxfTag;
	this->TxfAvl = TxfAvl;
	this->TxfAct = TxfAct;
	this->numsFLstOpt = numsFLstOpt;
	this->TxfOpt = TxfOpt;
	this->numFPupFedSrt = numFPupFedSrt;
	this->numFLstFedVit = numFLstFedVit;
	this->TxfFedVit = TxfFedVit;
	this->numFLstFedTag = numFLstFedTag;
	this->TxfFedTag = TxfFedTag;
	this->TxfFedCmt = TxfFedCmt;

	mask = {NUMFPUPJTI, NUMFPUPTYP, NUMFLSTCLU, NUMFPUPHKT, NUMFPUPRET, NUMFPUPSCO, NUMFPUPSTY, NUMFLSTTAG, TXFTAG, TXFAVL, TXFACT, NUMSFLSTOPT, TXFOPT, NUMFPUPFEDSRT, NUMFLSTFEDVIT, TXFFEDVIT, NUMFLSTFEDTAG, TXFFEDTAG, TXFFEDCMT};
};

bool PnlWznmConDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWznmConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWznmConDetail";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJti", numFPupJti)) add(NUMFPUPJTI);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupTyp", numFPupTyp)) add(NUMFPUPTYP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstClu", numFLstClu)) add(NUMFLSTCLU);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupHkt", numFPupHkt)) add(NUMFPUPHKT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupRet", numFPupRet)) add(NUMFPUPRET);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSco", numFPupSco)) add(NUMFPUPSCO);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSty", numFPupSty)) add(NUMFPUPSTY);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstTag", numFLstTag)) add(NUMFLSTTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTag", TxfTag)) add(TXFTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAvl", TxfAvl)) add(TXFAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfAct", TxfAct)) add(TXFACT);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfOpt", TxfOpt)) add(TXFOPT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupFedSrt", numFPupFedSrt)) add(NUMFPUPFEDSRT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFedVit", numFLstFedVit)) add(NUMFLSTFEDVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFedVit", TxfFedVit)) add(TXFFEDVIT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFLstFedTag", numFLstFedTag)) add(NUMFLSTFEDTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFedTag", TxfFedTag)) add(TXFFEDTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFedCmt", TxfFedCmt)) add(TXFFEDCMT);
	};

	return basefound;
};

void PnlWznmConDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmConDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWznmConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFPupJti", numFPupJti);
		writeUintAttr(wr, itemtag, "sref", "numFPupTyp", numFPupTyp);
		writeUintAttr(wr, itemtag, "sref", "numFLstClu", numFLstClu);
		writeUintAttr(wr, itemtag, "sref", "numFPupHkt", numFPupHkt);
		writeUintAttr(wr, itemtag, "sref", "numFPupRet", numFPupRet);
		writeUintAttr(wr, itemtag, "sref", "numFPupSco", numFPupSco);
		writeUintAttr(wr, itemtag, "sref", "numFPupSty", numFPupSty);
		writeUintAttr(wr, itemtag, "sref", "numFLstTag", numFLstTag);
		writeStringAttr(wr, itemtag, "sref", "TxfTag", TxfTag);
		writeStringAttr(wr, itemtag, "sref", "TxfAvl", TxfAvl);
		writeStringAttr(wr, itemtag, "sref", "TxfAct", TxfAct);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
		writeStringAttr(wr, itemtag, "sref", "TxfOpt", TxfOpt);
		writeUintAttr(wr, itemtag, "sref", "numFPupFedSrt", numFPupFedSrt);
		writeUintAttr(wr, itemtag, "sref", "numFLstFedVit", numFLstFedVit);
		writeStringAttr(wr, itemtag, "sref", "TxfFedVit", TxfFedVit);
		writeUintAttr(wr, itemtag, "sref", "numFLstFedTag", numFLstFedTag);
		writeStringAttr(wr, itemtag, "sref", "TxfFedTag", TxfFedTag);
		writeStringAttr(wr, itemtag, "sref", "TxfFedCmt", TxfFedCmt);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmConDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (numFPupJti == comp->numFPupJti) insert(items, NUMFPUPJTI);
	if (numFPupTyp == comp->numFPupTyp) insert(items, NUMFPUPTYP);
	if (numFLstClu == comp->numFLstClu) insert(items, NUMFLSTCLU);
	if (numFPupHkt == comp->numFPupHkt) insert(items, NUMFPUPHKT);
	if (numFPupRet == comp->numFPupRet) insert(items, NUMFPUPRET);
	if (numFPupSco == comp->numFPupSco) insert(items, NUMFPUPSCO);
	if (numFPupSty == comp->numFPupSty) insert(items, NUMFPUPSTY);
	if (numFLstTag == comp->numFLstTag) insert(items, NUMFLSTTAG);
	if (TxfTag == comp->TxfTag) insert(items, TXFTAG);
	if (TxfAvl == comp->TxfAvl) insert(items, TXFAVL);
	if (TxfAct == comp->TxfAct) insert(items, TXFACT);
	if (compareUintvec(numsFLstOpt, comp->numsFLstOpt)) insert(items, NUMSFLSTOPT);
	if (TxfOpt == comp->TxfOpt) insert(items, TXFOPT);
	if (numFPupFedSrt == comp->numFPupFedSrt) insert(items, NUMFPUPFEDSRT);
	if (numFLstFedVit == comp->numFLstFedVit) insert(items, NUMFLSTFEDVIT);
	if (TxfFedVit == comp->TxfFedVit) insert(items, TXFFEDVIT);
	if (numFLstFedTag == comp->numFLstFedTag) insert(items, NUMFLSTFEDTAG);
	if (TxfFedTag == comp->TxfFedTag) insert(items, TXFFEDTAG);
	if (TxfFedCmt == comp->TxfFedCmt) insert(items, TXFFEDCMT);

	return(items);
};

set<uint> PnlWznmConDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFPUPJTI, NUMFPUPTYP, NUMFLSTCLU, NUMFPUPHKT, NUMFPUPRET, NUMFPUPSCO, NUMFPUPSTY, NUMFLSTTAG, TXFTAG, TXFAVL, TXFACT, NUMSFLSTOPT, TXFOPT, NUMFPUPFEDSRT, NUMFLSTFEDVIT, TXFFEDVIT, NUMFLSTFEDTAG, TXFFEDTAG, TXFFEDCMT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmConDetail::ContInf
 ******************************************************************************/

PnlWznmConDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTit
			, const string& TxtClu
			, const string& TxtHku
			, const string& TxtReu
			, const string& TxtSup
			, const string& TxtSts
			, const string& TxtShs
			, const string& TxtFedSrf
			, const string& TxtFedSru
		) :
			Block()
		{
	this->TxtSrf = TxtSrf;
	this->TxtTit = TxtTit;
	this->TxtClu = TxtClu;
	this->TxtHku = TxtHku;
	this->TxtReu = TxtReu;
	this->TxtSup = TxtSup;
	this->TxtSts = TxtSts;
	this->TxtShs = TxtShs;
	this->TxtFedSrf = TxtFedSrf;
	this->TxtFedSru = TxtFedSru;

	mask = {TXTSRF, TXTTIT, TXTCLU, TXTHKU, TXTREU, TXTSUP, TXTSTS, TXTSHS, TXTFEDSRF, TXTFEDSRU};
};

bool PnlWznmConDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTit", TxtTit)) add(TXTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtClu", TxtClu)) add(TXTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtHku", TxtHku)) add(TXTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtReu", TxtReu)) add(TXTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSup", TxtSup)) add(TXTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSts", TxtSts)) add(TXTSTS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtShs", TxtShs)) add(TXTSHS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFedSrf", TxtFedSrf)) add(TXTFEDSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtFedSru", TxtFedSru)) add(TXTFEDSRU);
	};

	return basefound;
};

set<uint> PnlWznmConDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTit == comp->TxtTit) insert(items, TXTTIT);
	if (TxtClu == comp->TxtClu) insert(items, TXTCLU);
	if (TxtHku == comp->TxtHku) insert(items, TXTHKU);
	if (TxtReu == comp->TxtReu) insert(items, TXTREU);
	if (TxtSup == comp->TxtSup) insert(items, TXTSUP);
	if (TxtSts == comp->TxtSts) insert(items, TXTSTS);
	if (TxtShs == comp->TxtShs) insert(items, TXTSHS);
	if (TxtFedSrf == comp->TxtFedSrf) insert(items, TXTFEDSRF);
	if (TxtFedSru == comp->TxtFedSru) insert(items, TXTFEDSRU);

	return(items);
};

set<uint> PnlWznmConDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTIT, TXTCLU, TXTHKU, TXTREU, TXTSUP, TXTSTS, TXTSHS, TXTFEDSRF, TXTFEDSRU};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmConDetail::StatApp
 ******************************************************************************/

PnlWznmConDetail::StatApp::StatApp(
			const uint ixWznmVExpstate
			, const bool LstCluAlt
			, const bool LstTagAlt
			, const bool LstOptAlt
			, const bool LstFedVitAlt
			, const bool LstFedTagAlt
			, const uint LstCluNumFirstdisp
			, const uint LstTagNumFirstdisp
			, const uint LstOptNumFirstdisp
			, const uint LstFedVitNumFirstdisp
			, const uint LstFedTagNumFirstdisp
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->LstCluAlt = LstCluAlt;
	this->LstTagAlt = LstTagAlt;
	this->LstOptAlt = LstOptAlt;
	this->LstFedVitAlt = LstFedVitAlt;
	this->LstFedTagAlt = LstFedTagAlt;
	this->LstCluNumFirstdisp = LstCluNumFirstdisp;
	this->LstTagNumFirstdisp = LstTagNumFirstdisp;
	this->LstOptNumFirstdisp = LstOptNumFirstdisp;
	this->LstFedVitNumFirstdisp = LstFedVitNumFirstdisp;
	this->LstFedTagNumFirstdisp = LstFedTagNumFirstdisp;

	mask = {IXWZNMVEXPSTATE, LSTCLUALT, LSTTAGALT, LSTOPTALT, LSTFEDVITALT, LSTFEDTAGALT, LSTCLUNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTOPTNUMFIRSTDISP, LSTFEDVITNUMFIRSTDISP, LSTFEDTAGNUMFIRSTDISP};
};

bool PnlWznmConDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluAlt", LstCluAlt)) add(LSTCLUALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTagAlt", LstTagAlt)) add(LSTTAGALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptAlt", LstOptAlt)) add(LSTOPTALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedVitAlt", LstFedVitAlt)) add(LSTFEDVITALT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedTagAlt", LstFedTagAlt)) add(LSTFEDTAGALT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp)) add(LSTCLUNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTagNumFirstdisp", LstTagNumFirstdisp)) add(LSTTAGNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp)) add(LSTOPTNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedVitNumFirstdisp", LstFedVitNumFirstdisp)) add(LSTFEDVITNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedTagNumFirstdisp", LstFedTagNumFirstdisp)) add(LSTFEDTAGNUMFIRSTDISP);
	};

	return basefound;
};

set<uint> PnlWznmConDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (LstCluAlt == comp->LstCluAlt) insert(items, LSTCLUALT);
	if (LstTagAlt == comp->LstTagAlt) insert(items, LSTTAGALT);
	if (LstOptAlt == comp->LstOptAlt) insert(items, LSTOPTALT);
	if (LstFedVitAlt == comp->LstFedVitAlt) insert(items, LSTFEDVITALT);
	if (LstFedTagAlt == comp->LstFedTagAlt) insert(items, LSTFEDTAGALT);
	if (LstCluNumFirstdisp == comp->LstCluNumFirstdisp) insert(items, LSTCLUNUMFIRSTDISP);
	if (LstTagNumFirstdisp == comp->LstTagNumFirstdisp) insert(items, LSTTAGNUMFIRSTDISP);
	if (LstOptNumFirstdisp == comp->LstOptNumFirstdisp) insert(items, LSTOPTNUMFIRSTDISP);
	if (LstFedVitNumFirstdisp == comp->LstFedVitNumFirstdisp) insert(items, LSTFEDVITNUMFIRSTDISP);
	if (LstFedTagNumFirstdisp == comp->LstFedTagNumFirstdisp) insert(items, LSTFEDTAGNUMFIRSTDISP);

	return(items);
};

set<uint> PnlWznmConDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, LSTCLUALT, LSTTAGALT, LSTOPTALT, LSTFEDVITALT, LSTFEDTAGALT, LSTCLUNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTOPTNUMFIRSTDISP, LSTFEDVITNUMFIRSTDISP, LSTFEDTAGNUMFIRSTDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmConDetail::StatShr
 ******************************************************************************/

PnlWznmConDetail::StatShr::StatShr(
			const bool TxfTagValid
			, const bool TxfOptValid
			, const bool TxfFedVitValid
			, const bool TxfFedTagValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool PupJtiActive
			, const bool ButJtiEditAvail
			, const bool TxtTitActive
			, const bool PupTypActive
			, const bool LstCluActive
			, const bool ButCluViewActive
			, const bool ButCluClusterAvail
			, const bool ButCluUnclusterAvail
			, const bool TxtHkuActive
			, const bool ButHkuViewAvail
			, const bool ButHkuViewActive
			, const bool TxtReuActive
			, const bool ButReuViewAvail
			, const bool ButReuViewActive
			, const bool TxtSupActive
			, const bool ButSupViewAvail
			, const bool ButSupViewActive
			, const bool PupScoActive
			, const bool PupStyActive
			, const bool LstTagActive
			, const bool ButTagViewAvail
			, const bool ButTagViewActive
			, const bool TxtStsActive
			, const bool ButStsViewAvail
			, const bool ButStsViewActive
			, const bool TxtShsActive
			, const bool ButShsViewAvail
			, const bool ButShsViewActive
			, const bool TxfAvlActive
			, const bool TxfActActive
			, const bool LstOptActive
			, const bool ButOptEditAvail
			, const bool SepFedAvail
			, const bool HdgFedAvail
			, const bool ButFedNewAvail
			, const bool ButFedDeleteAvail
			, const bool TxtFedSrfAvail
			, const bool TxtFedSrfActive
			, const bool TxtFedSruAvail
			, const bool TxtFedSruActive
			, const bool ButFedSruViewAvail
			, const bool ButFedSruViewActive
			, const bool LstFedVitAvail
			, const bool LstFedVitActive
			, const bool ButFedVitViewAvail
			, const bool ButFedVitViewActive
			, const bool LstFedTagAvail
			, const bool LstFedTagActive
			, const bool ButFedTagViewAvail
			, const bool ButFedTagViewActive
			, const bool TxfFedCmtAvail
			, const bool TxfFedCmtActive
		) :
			Block()
		{
	this->TxfTagValid = TxfTagValid;
	this->TxfOptValid = TxfOptValid;
	this->TxfFedVitValid = TxfFedVitValid;
	this->TxfFedTagValid = TxfFedTagValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->PupJtiActive = PupJtiActive;
	this->ButJtiEditAvail = ButJtiEditAvail;
	this->TxtTitActive = TxtTitActive;
	this->PupTypActive = PupTypActive;
	this->LstCluActive = LstCluActive;
	this->ButCluViewActive = ButCluViewActive;
	this->ButCluClusterAvail = ButCluClusterAvail;
	this->ButCluUnclusterAvail = ButCluUnclusterAvail;
	this->TxtHkuActive = TxtHkuActive;
	this->ButHkuViewAvail = ButHkuViewAvail;
	this->ButHkuViewActive = ButHkuViewActive;
	this->TxtReuActive = TxtReuActive;
	this->ButReuViewAvail = ButReuViewAvail;
	this->ButReuViewActive = ButReuViewActive;
	this->TxtSupActive = TxtSupActive;
	this->ButSupViewAvail = ButSupViewAvail;
	this->ButSupViewActive = ButSupViewActive;
	this->PupScoActive = PupScoActive;
	this->PupStyActive = PupStyActive;
	this->LstTagActive = LstTagActive;
	this->ButTagViewAvail = ButTagViewAvail;
	this->ButTagViewActive = ButTagViewActive;
	this->TxtStsActive = TxtStsActive;
	this->ButStsViewAvail = ButStsViewAvail;
	this->ButStsViewActive = ButStsViewActive;
	this->TxtShsActive = TxtShsActive;
	this->ButShsViewAvail = ButShsViewAvail;
	this->ButShsViewActive = ButShsViewActive;
	this->TxfAvlActive = TxfAvlActive;
	this->TxfActActive = TxfActActive;
	this->LstOptActive = LstOptActive;
	this->ButOptEditAvail = ButOptEditAvail;
	this->SepFedAvail = SepFedAvail;
	this->HdgFedAvail = HdgFedAvail;
	this->ButFedNewAvail = ButFedNewAvail;
	this->ButFedDeleteAvail = ButFedDeleteAvail;
	this->TxtFedSrfAvail = TxtFedSrfAvail;
	this->TxtFedSrfActive = TxtFedSrfActive;
	this->TxtFedSruAvail = TxtFedSruAvail;
	this->TxtFedSruActive = TxtFedSruActive;
	this->ButFedSruViewAvail = ButFedSruViewAvail;
	this->ButFedSruViewActive = ButFedSruViewActive;
	this->LstFedVitAvail = LstFedVitAvail;
	this->LstFedVitActive = LstFedVitActive;
	this->ButFedVitViewAvail = ButFedVitViewAvail;
	this->ButFedVitViewActive = ButFedVitViewActive;
	this->LstFedTagAvail = LstFedTagAvail;
	this->LstFedTagActive = LstFedTagActive;
	this->ButFedTagViewAvail = ButFedTagViewAvail;
	this->ButFedTagViewActive = ButFedTagViewActive;
	this->TxfFedCmtAvail = TxfFedCmtAvail;
	this->TxfFedCmtActive = TxfFedCmtActive;

	mask = {TXFTAGVALID, TXFOPTVALID, TXFFEDVITVALID, TXFFEDTAGVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, PUPSCOACTIVE, PUPSTYACTIVE, LSTTAGACTIVE, BUTTAGVIEWAVAIL, BUTTAGVIEWACTIVE, TXTSTSACTIVE, BUTSTSVIEWAVAIL, BUTSTSVIEWACTIVE, TXTSHSACTIVE, BUTSHSVIEWAVAIL, BUTSHSVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, SEPFEDAVAIL, HDGFEDAVAIL, BUTFEDNEWAVAIL, BUTFEDDELETEAVAIL, TXTFEDSRFAVAIL, TXTFEDSRFACTIVE, TXTFEDSRUAVAIL, TXTFEDSRUACTIVE, BUTFEDSRUVIEWAVAIL, BUTFEDSRUVIEWACTIVE, LSTFEDVITAVAIL, LSTFEDVITACTIVE, BUTFEDVITVIEWAVAIL, BUTFEDVITVIEWACTIVE, LSTFEDTAGAVAIL, LSTFEDTAGACTIVE, BUTFEDTAGVIEWAVAIL, BUTFEDTAGVIEWACTIVE, TXFFEDCMTAVAIL, TXFFEDCMTACTIVE};
};

bool PnlWznmConDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmConDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfTagValid", TxfTagValid)) add(TXFTAGVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfOptValid", TxfOptValid)) add(TXFOPTVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFedVitValid", TxfFedVitValid)) add(TXFFEDVITVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFedTagValid", TxfFedTagValid)) add(TXFFEDTAGVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupJtiActive", PupJtiActive)) add(PUPJTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", ButJtiEditAvail)) add(BUTJTIEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTitActive", TxtTitActive)) add(TXTTITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupTypActive", PupTypActive)) add(PUPTYPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstCluActive", LstCluActive)) add(LSTCLUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluViewActive", ButCluViewActive)) add(BUTCLUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", ButCluClusterAvail)) add(BUTCLUCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail)) add(BUTCLUUNCLUSTERAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtHkuActive", TxtHkuActive)) add(TXTHKUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHkuViewAvail", ButHkuViewAvail)) add(BUTHKUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButHkuViewActive", ButHkuViewActive)) add(BUTHKUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtReuActive", TxtReuActive)) add(TXTREUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", ButReuViewAvail)) add(BUTREUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButReuViewActive", ButReuViewActive)) add(BUTREUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSupActive", TxtSupActive)) add(TXTSUPACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", ButSupViewAvail)) add(BUTSUPVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSupViewActive", ButSupViewActive)) add(BUTSUPVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupScoActive", PupScoActive)) add(PUPSCOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupStyActive", PupStyActive)) add(PUPSTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstTagActive", LstTagActive)) add(LSTTAGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTagViewAvail", ButTagViewAvail)) add(BUTTAGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTagViewActive", ButTagViewActive)) add(BUTTAGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtStsActive", TxtStsActive)) add(TXTSTSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStsViewAvail", ButStsViewAvail)) add(BUTSTSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButStsViewActive", ButStsViewActive)) add(BUTSTSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtShsActive", TxtShsActive)) add(TXTSHSACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButShsViewAvail", ButShsViewAvail)) add(BUTSHSVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButShsViewActive", ButShsViewActive)) add(BUTSHSVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfAvlActive", TxfAvlActive)) add(TXFAVLACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfActActive", TxfActActive)) add(TXFACTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstOptActive", LstOptActive)) add(LSTOPTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", ButOptEditAvail)) add(BUTOPTEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "SepFedAvail", SepFedAvail)) add(SEPFEDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "HdgFedAvail", HdgFedAvail)) add(HDGFEDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedNewAvail", ButFedNewAvail)) add(BUTFEDNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedDeleteAvail", ButFedDeleteAvail)) add(BUTFEDDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFedSrfAvail", TxtFedSrfAvail)) add(TXTFEDSRFAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFedSrfActive", TxtFedSrfActive)) add(TXTFEDSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFedSruAvail", TxtFedSruAvail)) add(TXTFEDSRUAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtFedSruActive", TxtFedSruActive)) add(TXTFEDSRUACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedSruViewAvail", ButFedSruViewAvail)) add(BUTFEDSRUVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedSruViewActive", ButFedSruViewActive)) add(BUTFEDSRUVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedVitAvail", LstFedVitAvail)) add(LSTFEDVITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedVitActive", LstFedVitActive)) add(LSTFEDVITACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedVitViewAvail", ButFedVitViewAvail)) add(BUTFEDVITVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedVitViewActive", ButFedVitViewActive)) add(BUTFEDVITVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedTagAvail", LstFedTagAvail)) add(LSTFEDTAGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "LstFedTagActive", LstFedTagActive)) add(LSTFEDTAGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedTagViewAvail", ButFedTagViewAvail)) add(BUTFEDTAGVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFedTagViewActive", ButFedTagViewActive)) add(BUTFEDTAGVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFedCmtAvail", TxfFedCmtAvail)) add(TXFFEDCMTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFedCmtActive", TxfFedCmtActive)) add(TXFFEDCMTACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmConDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfTagValid == comp->TxfTagValid) insert(items, TXFTAGVALID);
	if (TxfOptValid == comp->TxfOptValid) insert(items, TXFOPTVALID);
	if (TxfFedVitValid == comp->TxfFedVitValid) insert(items, TXFFEDVITVALID);
	if (TxfFedTagValid == comp->TxfFedTagValid) insert(items, TXFFEDTAGVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (PupJtiActive == comp->PupJtiActive) insert(items, PUPJTIACTIVE);
	if (ButJtiEditAvail == comp->ButJtiEditAvail) insert(items, BUTJTIEDITAVAIL);
	if (TxtTitActive == comp->TxtTitActive) insert(items, TXTTITACTIVE);
	if (PupTypActive == comp->PupTypActive) insert(items, PUPTYPACTIVE);
	if (LstCluActive == comp->LstCluActive) insert(items, LSTCLUACTIVE);
	if (ButCluViewActive == comp->ButCluViewActive) insert(items, BUTCLUVIEWACTIVE);
	if (ButCluClusterAvail == comp->ButCluClusterAvail) insert(items, BUTCLUCLUSTERAVAIL);
	if (ButCluUnclusterAvail == comp->ButCluUnclusterAvail) insert(items, BUTCLUUNCLUSTERAVAIL);
	if (TxtHkuActive == comp->TxtHkuActive) insert(items, TXTHKUACTIVE);
	if (ButHkuViewAvail == comp->ButHkuViewAvail) insert(items, BUTHKUVIEWAVAIL);
	if (ButHkuViewActive == comp->ButHkuViewActive) insert(items, BUTHKUVIEWACTIVE);
	if (TxtReuActive == comp->TxtReuActive) insert(items, TXTREUACTIVE);
	if (ButReuViewAvail == comp->ButReuViewAvail) insert(items, BUTREUVIEWAVAIL);
	if (ButReuViewActive == comp->ButReuViewActive) insert(items, BUTREUVIEWACTIVE);
	if (TxtSupActive == comp->TxtSupActive) insert(items, TXTSUPACTIVE);
	if (ButSupViewAvail == comp->ButSupViewAvail) insert(items, BUTSUPVIEWAVAIL);
	if (ButSupViewActive == comp->ButSupViewActive) insert(items, BUTSUPVIEWACTIVE);
	if (PupScoActive == comp->PupScoActive) insert(items, PUPSCOACTIVE);
	if (PupStyActive == comp->PupStyActive) insert(items, PUPSTYACTIVE);
	if (LstTagActive == comp->LstTagActive) insert(items, LSTTAGACTIVE);
	if (ButTagViewAvail == comp->ButTagViewAvail) insert(items, BUTTAGVIEWAVAIL);
	if (ButTagViewActive == comp->ButTagViewActive) insert(items, BUTTAGVIEWACTIVE);
	if (TxtStsActive == comp->TxtStsActive) insert(items, TXTSTSACTIVE);
	if (ButStsViewAvail == comp->ButStsViewAvail) insert(items, BUTSTSVIEWAVAIL);
	if (ButStsViewActive == comp->ButStsViewActive) insert(items, BUTSTSVIEWACTIVE);
	if (TxtShsActive == comp->TxtShsActive) insert(items, TXTSHSACTIVE);
	if (ButShsViewAvail == comp->ButShsViewAvail) insert(items, BUTSHSVIEWAVAIL);
	if (ButShsViewActive == comp->ButShsViewActive) insert(items, BUTSHSVIEWACTIVE);
	if (TxfAvlActive == comp->TxfAvlActive) insert(items, TXFAVLACTIVE);
	if (TxfActActive == comp->TxfActActive) insert(items, TXFACTACTIVE);
	if (LstOptActive == comp->LstOptActive) insert(items, LSTOPTACTIVE);
	if (ButOptEditAvail == comp->ButOptEditAvail) insert(items, BUTOPTEDITAVAIL);
	if (SepFedAvail == comp->SepFedAvail) insert(items, SEPFEDAVAIL);
	if (HdgFedAvail == comp->HdgFedAvail) insert(items, HDGFEDAVAIL);
	if (ButFedNewAvail == comp->ButFedNewAvail) insert(items, BUTFEDNEWAVAIL);
	if (ButFedDeleteAvail == comp->ButFedDeleteAvail) insert(items, BUTFEDDELETEAVAIL);
	if (TxtFedSrfAvail == comp->TxtFedSrfAvail) insert(items, TXTFEDSRFAVAIL);
	if (TxtFedSrfActive == comp->TxtFedSrfActive) insert(items, TXTFEDSRFACTIVE);
	if (TxtFedSruAvail == comp->TxtFedSruAvail) insert(items, TXTFEDSRUAVAIL);
	if (TxtFedSruActive == comp->TxtFedSruActive) insert(items, TXTFEDSRUACTIVE);
	if (ButFedSruViewAvail == comp->ButFedSruViewAvail) insert(items, BUTFEDSRUVIEWAVAIL);
	if (ButFedSruViewActive == comp->ButFedSruViewActive) insert(items, BUTFEDSRUVIEWACTIVE);
	if (LstFedVitAvail == comp->LstFedVitAvail) insert(items, LSTFEDVITAVAIL);
	if (LstFedVitActive == comp->LstFedVitActive) insert(items, LSTFEDVITACTIVE);
	if (ButFedVitViewAvail == comp->ButFedVitViewAvail) insert(items, BUTFEDVITVIEWAVAIL);
	if (ButFedVitViewActive == comp->ButFedVitViewActive) insert(items, BUTFEDVITVIEWACTIVE);
	if (LstFedTagAvail == comp->LstFedTagAvail) insert(items, LSTFEDTAGAVAIL);
	if (LstFedTagActive == comp->LstFedTagActive) insert(items, LSTFEDTAGACTIVE);
	if (ButFedTagViewAvail == comp->ButFedTagViewAvail) insert(items, BUTFEDTAGVIEWAVAIL);
	if (ButFedTagViewActive == comp->ButFedTagViewActive) insert(items, BUTFEDTAGVIEWACTIVE);
	if (TxfFedCmtAvail == comp->TxfFedCmtAvail) insert(items, TXFFEDCMTAVAIL);
	if (TxfFedCmtActive == comp->TxfFedCmtActive) insert(items, TXFFEDCMTACTIVE);

	return(items);
};

set<uint> PnlWznmConDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTAGVALID, TXFOPTVALID, TXFFEDVITVALID, TXFFEDTAGVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, PUPSCOACTIVE, PUPSTYACTIVE, LSTTAGACTIVE, BUTTAGVIEWAVAIL, BUTTAGVIEWACTIVE, TXTSTSACTIVE, BUTSTSVIEWAVAIL, BUTSTSVIEWACTIVE, TXTSHSACTIVE, BUTSHSVIEWAVAIL, BUTSHSVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, SEPFEDAVAIL, HDGFEDAVAIL, BUTFEDNEWAVAIL, BUTFEDDELETEAVAIL, TXTFEDSRFAVAIL, TXTFEDSRFACTIVE, TXTFEDSRUAVAIL, TXTFEDSRUACTIVE, BUTFEDSRUVIEWAVAIL, BUTFEDSRUVIEWACTIVE, LSTFEDVITAVAIL, LSTFEDVITACTIVE, BUTFEDVITVIEWAVAIL, BUTFEDVITVIEWACTIVE, LSTFEDTAGAVAIL, LSTFEDTAGACTIVE, BUTFEDTAGVIEWAVAIL, BUTFEDTAGVIEWACTIVE, TXFFEDCMTAVAIL, TXFFEDCMTACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmConDetail::Tag
 ******************************************************************************/

PnlWznmConDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTit
			, const string& CptTyp
			, const string& CptClu
			, const string& CptHku
			, const string& CptReu
			, const string& CptSup
			, const string& CptSco
			, const string& CptSty
			, const string& CptTag
			, const string& CptSts
			, const string& CptShs
			, const string& CptAvl
			, const string& CptAct
			, const string& CptOpt
			, const string& HdgFed
			, const string& CptFedSrf
			, const string& CptFedSru
			, const string& CptFedVit
			, const string& CptFedTag
			, const string& CptFedCmt
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTit = CptTit;
	this->CptTyp = CptTyp;
	this->CptClu = CptClu;
	this->CptHku = CptHku;
	this->CptReu = CptReu;
	this->CptSup = CptSup;
	this->CptSco = CptSco;
	this->CptSty = CptSty;
	this->CptTag = CptTag;
	this->CptSts = CptSts;
	this->CptShs = CptShs;
	this->CptAvl = CptAvl;
	this->CptAct = CptAct;
	this->CptOpt = CptOpt;
	this->HdgFed = HdgFed;
	this->CptFedSrf = CptFedSrf;
	this->CptFedSru = CptFedSru;
	this->CptFedVit = CptFedVit;
	this->CptFedTag = CptFedTag;
	this->CptFedCmt = CptFedCmt;

	mask = {CPT, CPTSRF, CPTTIT, CPTTYP, CPTCLU, CPTHKU, CPTREU, CPTSUP, CPTSCO, CPTSTY, CPTTAG, CPTSTS, CPTSHS, CPTAVL, CPTACT, CPTOPT, HDGFED, CPTFEDSRF, CPTFEDSRU, CPTFEDVIT, CPTFEDTAG, CPTFEDCMT};
};

bool PnlWznmConDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmConDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmConDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTit", CptTit)) add(CPTTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTyp", CptTyp)) add(CPTTYP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptClu", CptClu)) add(CPTCLU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptHku", CptHku)) add(CPTHKU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptReu", CptReu)) add(CPTREU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSup", CptSup)) add(CPTSUP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSco", CptSco)) add(CPTSCO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSty", CptSty)) add(CPTSTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTag", CptTag)) add(CPTTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSts", CptSts)) add(CPTSTS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptShs", CptShs)) add(CPTSHS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAvl", CptAvl)) add(CPTAVL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptAct", CptAct)) add(CPTACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptOpt", CptOpt)) add(CPTOPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgFed", HdgFed)) add(HDGFED);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFedSrf", CptFedSrf)) add(CPTFEDSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFedSru", CptFedSru)) add(CPTFEDSRU);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFedVit", CptFedVit)) add(CPTFEDVIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFedTag", CptFedTag)) add(CPTFEDTAG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFedCmt", CptFedCmt)) add(CPTFEDCMT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmConDetail::DpchAppData
 ******************************************************************************/

PnlWznmConDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCONDETAILDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWznmConDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmConDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmConDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmConDetail::DpchAppDo
 ******************************************************************************/

PnlWznmConDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCONDETAILDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmConDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmConDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmConDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmConDetail::DpchEngData
 ******************************************************************************/

PnlWznmConDetail::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCONDETAILDATA)
		{
	feedFLstClu.tag = "FeedFLstClu";
	feedFLstFedTag.tag = "FeedFLstFedTag";
	feedFLstFedVit.tag = "FeedFLstFedVit";
	feedFLstOpt.tag = "FeedFLstOpt";
	feedFLstTag.tag = "FeedFLstTag";
	feedFPupFedSrt.tag = "FeedFPupFedSrt";
	feedFPupHkt.tag = "FeedFPupHkt";
	feedFPupJti.tag = "FeedFPupJti";
	feedFPupRet.tag = "FeedFPupRet";
	feedFPupSco.tag = "FeedFPupSco";
	feedFPupSty.tag = "FeedFPupSty";
	feedFPupTyp.tag = "FeedFPupTyp";
};

string PnlWznmConDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTCLU)) ss.push_back("feedFLstClu");
	if (has(FEEDFLSTFEDTAG)) ss.push_back("feedFLstFedTag");
	if (has(FEEDFLSTFEDVIT)) ss.push_back("feedFLstFedVit");
	if (has(FEEDFLSTOPT)) ss.push_back("feedFLstOpt");
	if (has(FEEDFLSTTAG)) ss.push_back("feedFLstTag");
	if (has(FEEDFPUPFEDSRT)) ss.push_back("feedFPupFedSrt");
	if (has(FEEDFPUPHKT)) ss.push_back("feedFPupHkt");
	if (has(FEEDFPUPJTI)) ss.push_back("feedFPupJti");
	if (has(FEEDFPUPRET)) ss.push_back("feedFPupRet");
	if (has(FEEDFPUPSCO)) ss.push_back("feedFPupSco");
	if (has(FEEDFPUPSTY)) ss.push_back("feedFPupSty");
	if (has(FEEDFPUPTYP)) ss.push_back("feedFPupTyp");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmConDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmConDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFLstClu.readXML(docctx, basexpath, true)) add(FEEDFLSTCLU);
		if (feedFLstFedTag.readXML(docctx, basexpath, true)) add(FEEDFLSTFEDTAG);
		if (feedFLstFedVit.readXML(docctx, basexpath, true)) add(FEEDFLSTFEDVIT);
		if (feedFLstOpt.readXML(docctx, basexpath, true)) add(FEEDFLSTOPT);
		if (feedFLstTag.readXML(docctx, basexpath, true)) add(FEEDFLSTTAG);
		if (feedFPupFedSrt.readXML(docctx, basexpath, true)) add(FEEDFPUPFEDSRT);
		if (feedFPupHkt.readXML(docctx, basexpath, true)) add(FEEDFPUPHKT);
		if (feedFPupJti.readXML(docctx, basexpath, true)) add(FEEDFPUPJTI);
		if (feedFPupRet.readXML(docctx, basexpath, true)) add(FEEDFPUPRET);
		if (feedFPupSco.readXML(docctx, basexpath, true)) add(FEEDFPUPSCO);
		if (feedFPupSty.readXML(docctx, basexpath, true)) add(FEEDFPUPSTY);
		if (feedFPupTyp.readXML(docctx, basexpath, true)) add(FEEDFPUPTYP);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFLstClu.clear();
		feedFLstFedTag.clear();
		feedFLstFedVit.clear();
		feedFLstOpt.clear();
		feedFLstTag.clear();
		feedFPupFedSrt.clear();
		feedFPupHkt.clear();
		feedFPupJti.clear();
		feedFPupRet.clear();
		feedFPupSco.clear();
		feedFPupSty.clear();
		feedFPupTyp.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

