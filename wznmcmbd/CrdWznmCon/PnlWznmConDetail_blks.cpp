/**
	* \file PnlWznmConDetail_blks.cpp
	* job handler for job PnlWznmConDetail (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

bool PnlWznmConDetail::ContIac::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["ContIacWznmConDetail"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("numFPupJti")) {numFPupJti = me["numFPupJti"].asUInt(); add(NUMFPUPJTI);};
		if (me.isMember("numFPupTyp")) {numFPupTyp = me["numFPupTyp"].asUInt(); add(NUMFPUPTYP);};
		if (me.isMember("numFLstClu")) {numFLstClu = me["numFLstClu"].asUInt(); add(NUMFLSTCLU);};
		if (me.isMember("numFPupHkt")) {numFPupHkt = me["numFPupHkt"].asUInt(); add(NUMFPUPHKT);};
		if (me.isMember("numFPupRet")) {numFPupRet = me["numFPupRet"].asUInt(); add(NUMFPUPRET);};
		if (me.isMember("numFPupSco")) {numFPupSco = me["numFPupSco"].asUInt(); add(NUMFPUPSCO);};
		if (me.isMember("numFPupSty")) {numFPupSty = me["numFPupSty"].asUInt(); add(NUMFPUPSTY);};
		if (me.isMember("numFLstTag")) {numFLstTag = me["numFLstTag"].asUInt(); add(NUMFLSTTAG);};
		if (me.isMember("TxfTag")) {TxfTag = me["TxfTag"].asString(); add(TXFTAG);};
		if (me.isMember("TxfAvl")) {TxfAvl = me["TxfAvl"].asString(); add(TXFAVL);};
		if (me.isMember("TxfAct")) {TxfAct = me["TxfAct"].asString(); add(TXFACT);};
		if (Jsonio::extractUintvec(me, "numsFLstOpt", numsFLstOpt)) add(NUMSFLSTOPT);
		if (me.isMember("TxfOpt")) {TxfOpt = me["TxfOpt"].asString(); add(TXFOPT);};
		if (me.isMember("numFPupFedSrt")) {numFPupFedSrt = me["numFPupFedSrt"].asUInt(); add(NUMFPUPFEDSRT);};
		if (me.isMember("numFLstFedVit")) {numFLstFedVit = me["numFLstFedVit"].asUInt(); add(NUMFLSTFEDVIT);};
		if (me.isMember("TxfFedVit")) {TxfFedVit = me["TxfFedVit"].asString(); add(TXFFEDVIT);};
		if (me.isMember("numFLstFedTag")) {numFLstFedTag = me["numFLstFedTag"].asUInt(); add(NUMFLSTFEDTAG);};
		if (me.isMember("TxfFedTag")) {TxfFedTag = me["TxfFedTag"].asString(); add(TXFFEDTAG);};
		if (me.isMember("TxfFedCmt")) {TxfFedCmt = me["TxfFedCmt"].asString(); add(TXFFEDCMT);};
	};

	return basefound;
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

void PnlWznmConDetail::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWznmConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["numFPupJti"] = numFPupJti;
	me["numFPupTyp"] = numFPupTyp;
	me["numFLstClu"] = numFLstClu;
	me["numFPupHkt"] = numFPupHkt;
	me["numFPupRet"] = numFPupRet;
	me["numFPupSco"] = numFPupSco;
	me["numFPupSty"] = numFPupSty;
	me["numFLstTag"] = numFLstTag;
	me["TxfTag"] = TxfTag;
	me["TxfAvl"] = TxfAvl;
	me["TxfAct"] = TxfAct;
	Jsonio::writeUintvec(me, "numsFLstOpt", numsFLstOpt);
	me["TxfOpt"] = TxfOpt;
	me["numFPupFedSrt"] = numFPupFedSrt;
	me["numFLstFedVit"] = numFLstFedVit;
	me["TxfFedVit"] = TxfFedVit;
	me["numFLstFedTag"] = numFLstFedTag;
	me["TxfFedTag"] = TxfFedTag;
	me["TxfFedCmt"] = TxfFedCmt;
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

void PnlWznmConDetail::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtSrf"] = TxtSrf;
	me["TxtTit"] = TxtTit;
	me["TxtClu"] = TxtClu;
	me["TxtHku"] = TxtHku;
	me["TxtReu"] = TxtReu;
	me["TxtSup"] = TxtSup;
	me["TxtSts"] = TxtSts;
	me["TxtShs"] = TxtShs;
	me["TxtFedSrf"] = TxtFedSrf;
	me["TxtFedSru"] = TxtFedSru;
};

void PnlWznmConDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmConDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTit", TxtTit);
		writeStringAttr(wr, itemtag, "sref", "TxtClu", TxtClu);
		writeStringAttr(wr, itemtag, "sref", "TxtHku", TxtHku);
		writeStringAttr(wr, itemtag, "sref", "TxtReu", TxtReu);
		writeStringAttr(wr, itemtag, "sref", "TxtSup", TxtSup);
		writeStringAttr(wr, itemtag, "sref", "TxtSts", TxtSts);
		writeStringAttr(wr, itemtag, "sref", "TxtShs", TxtShs);
		writeStringAttr(wr, itemtag, "sref", "TxtFedSrf", TxtFedSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtFedSru", TxtFedSru);
	xmlTextWriterEndElement(wr);
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

void PnlWznmConDetail::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const uint ixWznmVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWznmVExpstate"] = VecWznmVExpstate::getSref(ixWznmVExpstate);
	me["LstCluAlt"] = LstCluAlt;
	me["LstTagAlt"] = LstTagAlt;
	me["LstOptAlt"] = LstOptAlt;
	me["LstFedVitAlt"] = LstFedVitAlt;
	me["LstFedTagAlt"] = LstFedTagAlt;
	me["LstCluNumFirstdisp"] = LstCluNumFirstdisp;
	me["LstTagNumFirstdisp"] = LstTagNumFirstdisp;
	me["LstOptNumFirstdisp"] = LstOptNumFirstdisp;
	me["LstFedVitNumFirstdisp"] = LstFedVitNumFirstdisp;
	me["LstFedTagNumFirstdisp"] = LstFedTagNumFirstdisp;
};

void PnlWznmConDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixWznmVExpstate
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
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmConDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstCluAlt", LstCluAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstTagAlt", LstTagAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstOptAlt", LstOptAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFedVitAlt", LstFedVitAlt);
		writeBoolAttr(wr, itemtag, "sref", "LstFedTagAlt", LstFedTagAlt);
		writeUintAttr(wr, itemtag, "sref", "LstCluNumFirstdisp", LstCluNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstTagNumFirstdisp", LstTagNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstOptNumFirstdisp", LstOptNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFedVitNumFirstdisp", LstFedVitNumFirstdisp);
		writeUintAttr(wr, itemtag, "sref", "LstFedTagNumFirstdisp", LstFedTagNumFirstdisp);
	xmlTextWriterEndElement(wr);
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

void PnlWznmConDetail::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxfTagValid"] = TxfTagValid;
	me["TxfOptValid"] = TxfOptValid;
	me["TxfFedVitValid"] = TxfFedVitValid;
	me["TxfFedTagValid"] = TxfFedTagValid;
	me["ButSaveAvail"] = ButSaveAvail;
	me["ButSaveActive"] = ButSaveActive;
	me["TxtSrfActive"] = TxtSrfActive;
	me["PupJtiActive"] = PupJtiActive;
	me["ButJtiEditAvail"] = ButJtiEditAvail;
	me["TxtTitActive"] = TxtTitActive;
	me["PupTypActive"] = PupTypActive;
	me["LstCluActive"] = LstCluActive;
	me["ButCluViewActive"] = ButCluViewActive;
	me["ButCluClusterAvail"] = ButCluClusterAvail;
	me["ButCluUnclusterAvail"] = ButCluUnclusterAvail;
	me["TxtHkuActive"] = TxtHkuActive;
	me["ButHkuViewAvail"] = ButHkuViewAvail;
	me["ButHkuViewActive"] = ButHkuViewActive;
	me["TxtReuActive"] = TxtReuActive;
	me["ButReuViewAvail"] = ButReuViewAvail;
	me["ButReuViewActive"] = ButReuViewActive;
	me["TxtSupActive"] = TxtSupActive;
	me["ButSupViewAvail"] = ButSupViewAvail;
	me["ButSupViewActive"] = ButSupViewActive;
	me["PupScoActive"] = PupScoActive;
	me["PupStyActive"] = PupStyActive;
	me["LstTagActive"] = LstTagActive;
	me["ButTagViewAvail"] = ButTagViewAvail;
	me["ButTagViewActive"] = ButTagViewActive;
	me["TxtStsActive"] = TxtStsActive;
	me["ButStsViewAvail"] = ButStsViewAvail;
	me["ButStsViewActive"] = ButStsViewActive;
	me["TxtShsActive"] = TxtShsActive;
	me["ButShsViewAvail"] = ButShsViewAvail;
	me["ButShsViewActive"] = ButShsViewActive;
	me["TxfAvlActive"] = TxfAvlActive;
	me["TxfActActive"] = TxfActActive;
	me["LstOptActive"] = LstOptActive;
	me["ButOptEditAvail"] = ButOptEditAvail;
	me["SepFedAvail"] = SepFedAvail;
	me["HdgFedAvail"] = HdgFedAvail;
	me["ButFedNewAvail"] = ButFedNewAvail;
	me["ButFedDeleteAvail"] = ButFedDeleteAvail;
	me["TxtFedSrfAvail"] = TxtFedSrfAvail;
	me["TxtFedSrfActive"] = TxtFedSrfActive;
	me["TxtFedSruAvail"] = TxtFedSruAvail;
	me["TxtFedSruActive"] = TxtFedSruActive;
	me["ButFedSruViewAvail"] = ButFedSruViewAvail;
	me["ButFedSruViewActive"] = ButFedSruViewActive;
	me["LstFedVitAvail"] = LstFedVitAvail;
	me["LstFedVitActive"] = LstFedVitActive;
	me["ButFedVitViewAvail"] = ButFedVitViewAvail;
	me["ButFedVitViewActive"] = ButFedVitViewActive;
	me["LstFedTagAvail"] = LstFedTagAvail;
	me["LstFedTagActive"] = LstFedTagActive;
	me["ButFedTagViewAvail"] = ButFedTagViewAvail;
	me["ButFedTagViewActive"] = ButFedTagViewActive;
	me["TxfFedCmtAvail"] = TxfFedCmtAvail;
	me["TxfFedCmtActive"] = TxfFedCmtActive;
};

void PnlWznmConDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmConDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfTagValid", TxfTagValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfOptValid", TxfOptValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfFedVitValid", TxfFedVitValid);
		writeBoolAttr(wr, itemtag, "sref", "TxfFedTagValid", TxfFedTagValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJtiActive", PupJtiActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJtiEditAvail", ButJtiEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtTitActive", TxtTitActive);
		writeBoolAttr(wr, itemtag, "sref", "PupTypActive", PupTypActive);
		writeBoolAttr(wr, itemtag, "sref", "LstCluActive", LstCluActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluViewActive", ButCluViewActive);
		writeBoolAttr(wr, itemtag, "sref", "ButCluClusterAvail", ButCluClusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButCluUnclusterAvail", ButCluUnclusterAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtHkuActive", TxtHkuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButHkuViewAvail", ButHkuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButHkuViewActive", ButHkuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtReuActive", TxtReuActive);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewAvail", ButReuViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButReuViewActive", ButReuViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSupActive", TxtSupActive);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewAvail", ButSupViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSupViewActive", ButSupViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupScoActive", PupScoActive);
		writeBoolAttr(wr, itemtag, "sref", "PupStyActive", PupStyActive);
		writeBoolAttr(wr, itemtag, "sref", "LstTagActive", LstTagActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTagViewAvail", ButTagViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTagViewActive", ButTagViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtStsActive", TxtStsActive);
		writeBoolAttr(wr, itemtag, "sref", "ButStsViewAvail", ButStsViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButStsViewActive", ButStsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtShsActive", TxtShsActive);
		writeBoolAttr(wr, itemtag, "sref", "ButShsViewAvail", ButShsViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButShsViewActive", ButShsViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfAvlActive", TxfAvlActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfActActive", TxfActActive);
		writeBoolAttr(wr, itemtag, "sref", "LstOptActive", LstOptActive);
		writeBoolAttr(wr, itemtag, "sref", "ButOptEditAvail", ButOptEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "SepFedAvail", SepFedAvail);
		writeBoolAttr(wr, itemtag, "sref", "HdgFedAvail", HdgFedAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFedNewAvail", ButFedNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFedDeleteAvail", ButFedDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtFedSrfAvail", TxtFedSrfAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtFedSrfActive", TxtFedSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtFedSruAvail", TxtFedSruAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtFedSruActive", TxtFedSruActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFedSruViewAvail", ButFedSruViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFedSruViewActive", ButFedSruViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFedVitAvail", LstFedVitAvail);
		writeBoolAttr(wr, itemtag, "sref", "LstFedVitActive", LstFedVitActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFedVitViewAvail", ButFedVitViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFedVitViewActive", ButFedVitViewActive);
		writeBoolAttr(wr, itemtag, "sref", "LstFedTagAvail", LstFedTagAvail);
		writeBoolAttr(wr, itemtag, "sref", "LstFedTagActive", LstFedTagActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFedTagViewAvail", ButFedTagViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFedTagViewActive", ButFedTagViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFedCmtAvail", TxfFedCmtAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFedCmtActive", TxfFedCmtActive);
	xmlTextWriterEndElement(wr);
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

void PnlWznmConDetail::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmConDetail";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["CptSrf"] = "identifier";
		me["CptTit"] = "name";
		me["CptTyp"] = "type";
		me["CptHku"] = "hook";
		me["CptReu"] = "reference";
		me["CptSup"] = "super control";
		me["CptSco"] = "scope";
		me["CptSty"] = "subtype";
		me["CptTag"] = "tags";
		me["CptSts"] = "stub";
		me["CptShs"] = "stub";
		me["CptAvl"] = "availability rule";
		me["CptAct"] = "activation rule";
		me["CptOpt"] = "options";
		me["HdgFed"] = "Feed";
		me["CptFedSrf"] = "identifier";
		me["CptFedSru"] = "source";
		me["CptFedVit"] = "vector items";
		me["CptFedTag"] = "tags";
		me["CptFedCmt"] = "comment";
	};
	me["Cpt"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale));
	me["CptClu"] = VecWznmVTag::getTitle(VecWznmVTag::CLUST, ixWznmVLocale);
};

void PnlWznmConDetail::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmConDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmConDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTit", "name");
			writeStringAttr(wr, itemtag, "sref", "CptTyp", "type");
			writeStringAttr(wr, itemtag, "sref", "CptHku", "hook");
			writeStringAttr(wr, itemtag, "sref", "CptReu", "reference");
			writeStringAttr(wr, itemtag, "sref", "CptSup", "super control");
			writeStringAttr(wr, itemtag, "sref", "CptSco", "scope");
			writeStringAttr(wr, itemtag, "sref", "CptSty", "subtype");
			writeStringAttr(wr, itemtag, "sref", "CptTag", "tags");
			writeStringAttr(wr, itemtag, "sref", "CptSts", "stub");
			writeStringAttr(wr, itemtag, "sref", "CptShs", "stub");
			writeStringAttr(wr, itemtag, "sref", "CptAvl", "availability rule");
			writeStringAttr(wr, itemtag, "sref", "CptAct", "activation rule");
			writeStringAttr(wr, itemtag, "sref", "CptOpt", "options");
			writeStringAttr(wr, itemtag, "sref", "HdgFed", "Feed");
			writeStringAttr(wr, itemtag, "sref", "CptFedSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptFedSru", "source");
			writeStringAttr(wr, itemtag, "sref", "CptFedVit", "vector items");
			writeStringAttr(wr, itemtag, "sref", "CptFedTag", "tags");
			writeStringAttr(wr, itemtag, "sref", "CptFedCmt", "comment");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::DETAIL, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "CptClu", VecWznmVTag::getTitle(VecWznmVTag::CLUST, ixWznmVLocale));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmConDetail::DpchAppData
 ******************************************************************************/

PnlWznmConDetail::DpchAppData::DpchAppData() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCONDETAILDATA)
		{
};

string PnlWznmConDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmConDetail::DpchAppData::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmConDetailData"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWznmConDetail::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmConDetailData");
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
 class PnlWznmConDetail::DpchAppDo
 ******************************************************************************/

PnlWznmConDetail::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMCONDETAILDO)
		{
	ixVDo = 0;
};

string PnlWznmConDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmConDetail::DpchAppDo::readJSON(
			Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	Json::Value& me = sup;
	if (addbasetag) me = sup["DpchAppWznmConDetailDo"];

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWznmConDetail::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmConDetailDo");
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
 class PnlWznmConDetail::DpchEngData
 ******************************************************************************/

PnlWznmConDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstClu
			, Feed* feedFLstFedTag
			, Feed* feedFLstFedVit
			, Feed* feedFLstOpt
			, Feed* feedFLstTag
			, Feed* feedFPupFedSrt
			, Feed* feedFPupHkt
			, Feed* feedFPupJti
			, Feed* feedFPupRet
			, Feed* feedFPupSco
			, Feed* feedFPupSty
			, Feed* feedFPupTyp
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMCONDETAILDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTCLU, FEEDFLSTFEDTAG, FEEDFLSTFEDVIT, FEEDFLSTOPT, FEEDFLSTTAG, FEEDFPUPFEDSRT, FEEDFPUPHKT, FEEDFPUPJTI, FEEDFPUPRET, FEEDFPUPSCO, FEEDFPUPSTY, FEEDFPUPTYP, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTCLU) && feedFLstClu) this->feedFLstClu = *feedFLstClu;
	if (find(this->mask, FEEDFLSTFEDTAG) && feedFLstFedTag) this->feedFLstFedTag = *feedFLstFedTag;
	if (find(this->mask, FEEDFLSTFEDVIT) && feedFLstFedVit) this->feedFLstFedVit = *feedFLstFedVit;
	if (find(this->mask, FEEDFLSTOPT) && feedFLstOpt) this->feedFLstOpt = *feedFLstOpt;
	if (find(this->mask, FEEDFLSTTAG) && feedFLstTag) this->feedFLstTag = *feedFLstTag;
	if (find(this->mask, FEEDFPUPFEDSRT) && feedFPupFedSrt) this->feedFPupFedSrt = *feedFPupFedSrt;
	if (find(this->mask, FEEDFPUPHKT) && feedFPupHkt) this->feedFPupHkt = *feedFPupHkt;
	if (find(this->mask, FEEDFPUPJTI) && feedFPupJti) this->feedFPupJti = *feedFPupJti;
	if (find(this->mask, FEEDFPUPRET) && feedFPupRet) this->feedFPupRet = *feedFPupRet;
	if (find(this->mask, FEEDFPUPSCO) && feedFPupSco) this->feedFPupSco = *feedFPupSco;
	if (find(this->mask, FEEDFPUPSTY) && feedFPupSty) this->feedFPupSty = *feedFPupSty;
	if (find(this->mask, FEEDFPUPTYP) && feedFPupTyp) this->feedFPupTyp = *feedFPupTyp;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmConDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
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

void PnlWznmConDetail::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTCLU)) {feedFLstClu = src->feedFLstClu; add(FEEDFLSTCLU);};
	if (src->has(FEEDFLSTFEDTAG)) {feedFLstFedTag = src->feedFLstFedTag; add(FEEDFLSTFEDTAG);};
	if (src->has(FEEDFLSTFEDVIT)) {feedFLstFedVit = src->feedFLstFedVit; add(FEEDFLSTFEDVIT);};
	if (src->has(FEEDFLSTOPT)) {feedFLstOpt = src->feedFLstOpt; add(FEEDFLSTOPT);};
	if (src->has(FEEDFLSTTAG)) {feedFLstTag = src->feedFLstTag; add(FEEDFLSTTAG);};
	if (src->has(FEEDFPUPFEDSRT)) {feedFPupFedSrt = src->feedFPupFedSrt; add(FEEDFPUPFEDSRT);};
	if (src->has(FEEDFPUPHKT)) {feedFPupHkt = src->feedFPupHkt; add(FEEDFPUPHKT);};
	if (src->has(FEEDFPUPJTI)) {feedFPupJti = src->feedFPupJti; add(FEEDFPUPJTI);};
	if (src->has(FEEDFPUPRET)) {feedFPupRet = src->feedFPupRet; add(FEEDFPUPRET);};
	if (src->has(FEEDFPUPSCO)) {feedFPupSco = src->feedFPupSco; add(FEEDFPUPSCO);};
	if (src->has(FEEDFPUPSTY)) {feedFPupSty = src->feedFPupSty; add(FEEDFPUPSTY);};
	if (src->has(FEEDFPUPTYP)) {feedFPupTyp = src->feedFPupTyp; add(FEEDFPUPTYP);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmConDetail::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmConDetailData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(FEEDFLSTCLU)) feedFLstClu.writeJSON(me);
	if (has(FEEDFLSTFEDTAG)) feedFLstFedTag.writeJSON(me);
	if (has(FEEDFLSTFEDVIT)) feedFLstFedVit.writeJSON(me);
	if (has(FEEDFLSTOPT)) feedFLstOpt.writeJSON(me);
	if (has(FEEDFLSTTAG)) feedFLstTag.writeJSON(me);
	if (has(FEEDFPUPFEDSRT)) feedFPupFedSrt.writeJSON(me);
	if (has(FEEDFPUPHKT)) feedFPupHkt.writeJSON(me);
	if (has(FEEDFPUPJTI)) feedFPupJti.writeJSON(me);
	if (has(FEEDFPUPRET)) feedFPupRet.writeJSON(me);
	if (has(FEEDFPUPSCO)) feedFPupSco.writeJSON(me);
	if (has(FEEDFPUPSTY)) feedFPupSty.writeJSON(me);
	if (has(FEEDFPUPTYP)) feedFPupTyp.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmConDetail::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmConDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTCLU)) feedFLstClu.writeXML(wr);
		if (has(FEEDFLSTFEDTAG)) feedFLstFedTag.writeXML(wr);
		if (has(FEEDFLSTFEDVIT)) feedFLstFedVit.writeXML(wr);
		if (has(FEEDFLSTOPT)) feedFLstOpt.writeXML(wr);
		if (has(FEEDFLSTTAG)) feedFLstTag.writeXML(wr);
		if (has(FEEDFPUPFEDSRT)) feedFPupFedSrt.writeXML(wr);
		if (has(FEEDFPUPHKT)) feedFPupHkt.writeXML(wr);
		if (has(FEEDFPUPJTI)) feedFPupJti.writeXML(wr);
		if (has(FEEDFPUPRET)) feedFPupRet.writeXML(wr);
		if (has(FEEDFPUPSCO)) feedFPupSco.writeXML(wr);
		if (has(FEEDFPUPSTY)) feedFPupSty.writeXML(wr);
		if (has(FEEDFPUPTYP)) feedFPupTyp.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
