/**
	* \file PnlWznmTblRec.cpp
	* API code for job PnlWznmTblRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWznmTblRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmTblRec::VecVDo
 ******************************************************************************/

uint PnlWznmTblRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWznmTblRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWznmTblRec::ContInf
 ******************************************************************************/

PnlWznmTblRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWznmTblRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWznmTblRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWznmTblRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWznmTblRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWznmTblRec::ContInf::diff(
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
 class PnlWznmTblRec::StatApp
 ******************************************************************************/

PnlWznmTblRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneALoadfct
			, const bool initdoneATitle
			, const bool initdoneFr1NRelation
			, const bool initdoneTo1NRelation
			, const bool initdone1NStub
			, const bool initdone1NSubset
			, const bool initdoneTbl1NTablecol
			, const bool initdone1NImpexp
			, const bool initdone1NCheck
			, const bool initdoneHk1NVector
			, const bool initdoneRef1NQuerymod
			, const bool initdoneRef1NRtblock
			, const bool initdoneFct1NTablecol
			, const bool initdoneRef1NPanel
			, const bool initdoneRef1NDialog
			, const bool initdoneRef1NCall
			, const bool initdoneSrc1NFeed
			, const bool initdonePst1NQuerymod
			, const bool initdoneMNVector
			, const bool initdoneMNQuery
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneALoadfct = initdoneALoadfct;
	this->initdoneATitle = initdoneATitle;
	this->initdoneFr1NRelation = initdoneFr1NRelation;
	this->initdoneTo1NRelation = initdoneTo1NRelation;
	this->initdone1NStub = initdone1NStub;
	this->initdone1NSubset = initdone1NSubset;
	this->initdoneTbl1NTablecol = initdoneTbl1NTablecol;
	this->initdone1NImpexp = initdone1NImpexp;
	this->initdone1NCheck = initdone1NCheck;
	this->initdoneHk1NVector = initdoneHk1NVector;
	this->initdoneRef1NQuerymod = initdoneRef1NQuerymod;
	this->initdoneRef1NRtblock = initdoneRef1NRtblock;
	this->initdoneFct1NTablecol = initdoneFct1NTablecol;
	this->initdoneRef1NPanel = initdoneRef1NPanel;
	this->initdoneRef1NDialog = initdoneRef1NDialog;
	this->initdoneRef1NCall = initdoneRef1NCall;
	this->initdoneSrc1NFeed = initdoneSrc1NFeed;
	this->initdonePst1NQuerymod = initdonePst1NQuerymod;
	this->initdoneMNVector = initdoneMNVector;
	this->initdoneMNQuery = initdoneMNQuery;

	mask = {INITDONEDETAIL, INITDONEALOADFCT, INITDONEATITLE, INITDONEFR1NRELATION, INITDONETO1NRELATION, INITDONE1NSTUB, INITDONE1NSUBSET, INITDONETBL1NTABLECOL, INITDONE1NIMPEXP, INITDONE1NCHECK, INITDONEHK1NVECTOR, INITDONEREF1NQUERYMOD, INITDONEREF1NRTBLOCK, INITDONEFCT1NTABLECOL, INITDONEREF1NPANEL, INITDONEREF1NDIALOG, INITDONEREF1NCALL, INITDONESRC1NFEED, INITDONEPST1NQUERYMOD, INITDONEMNVECTOR, INITDONEMNQUERY};
};

bool PnlWznmTblRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWznmTblRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWznmTblRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneALoadfct", initdoneALoadfct)) add(INITDONEALOADFCT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneATitle", initdoneATitle)) add(INITDONEATITLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFr1NRelation", initdoneFr1NRelation)) add(INITDONEFR1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTo1NRelation", initdoneTo1NRelation)) add(INITDONETO1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NStub", initdone1NStub)) add(INITDONE1NSTUB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NSubset", initdone1NSubset)) add(INITDONE1NSUBSET);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneTbl1NTablecol", initdoneTbl1NTablecol)) add(INITDONETBL1NTABLECOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NImpexp", initdone1NImpexp)) add(INITDONE1NIMPEXP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NCheck", initdone1NCheck)) add(INITDONE1NCHECK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", initdoneHk1NVector)) add(INITDONEHK1NVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NQuerymod", initdoneRef1NQuerymod)) add(INITDONEREF1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NRtblock", initdoneRef1NRtblock)) add(INITDONEREF1NRTBLOCK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneFct1NTablecol", initdoneFct1NTablecol)) add(INITDONEFCT1NTABLECOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NPanel", initdoneRef1NPanel)) add(INITDONEREF1NPANEL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NDialog", initdoneRef1NDialog)) add(INITDONEREF1NDIALOG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneRef1NCall", initdoneRef1NCall)) add(INITDONEREF1NCALL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSrc1NFeed", initdoneSrc1NFeed)) add(INITDONESRC1NFEED);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdonePst1NQuerymod", initdonePst1NQuerymod)) add(INITDONEPST1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNVector", initdoneMNVector)) add(INITDONEMNVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNQuery", initdoneMNQuery)) add(INITDONEMNQUERY);
	};

	return basefound;
};

set<uint> PnlWznmTblRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneALoadfct == comp->initdoneALoadfct) insert(items, INITDONEALOADFCT);
	if (initdoneATitle == comp->initdoneATitle) insert(items, INITDONEATITLE);
	if (initdoneFr1NRelation == comp->initdoneFr1NRelation) insert(items, INITDONEFR1NRELATION);
	if (initdoneTo1NRelation == comp->initdoneTo1NRelation) insert(items, INITDONETO1NRELATION);
	if (initdone1NStub == comp->initdone1NStub) insert(items, INITDONE1NSTUB);
	if (initdone1NSubset == comp->initdone1NSubset) insert(items, INITDONE1NSUBSET);
	if (initdoneTbl1NTablecol == comp->initdoneTbl1NTablecol) insert(items, INITDONETBL1NTABLECOL);
	if (initdone1NImpexp == comp->initdone1NImpexp) insert(items, INITDONE1NIMPEXP);
	if (initdone1NCheck == comp->initdone1NCheck) insert(items, INITDONE1NCHECK);
	if (initdoneHk1NVector == comp->initdoneHk1NVector) insert(items, INITDONEHK1NVECTOR);
	if (initdoneRef1NQuerymod == comp->initdoneRef1NQuerymod) insert(items, INITDONEREF1NQUERYMOD);
	if (initdoneRef1NRtblock == comp->initdoneRef1NRtblock) insert(items, INITDONEREF1NRTBLOCK);
	if (initdoneFct1NTablecol == comp->initdoneFct1NTablecol) insert(items, INITDONEFCT1NTABLECOL);
	if (initdoneRef1NPanel == comp->initdoneRef1NPanel) insert(items, INITDONEREF1NPANEL);
	if (initdoneRef1NDialog == comp->initdoneRef1NDialog) insert(items, INITDONEREF1NDIALOG);
	if (initdoneRef1NCall == comp->initdoneRef1NCall) insert(items, INITDONEREF1NCALL);
	if (initdoneSrc1NFeed == comp->initdoneSrc1NFeed) insert(items, INITDONESRC1NFEED);
	if (initdonePst1NQuerymod == comp->initdonePst1NQuerymod) insert(items, INITDONEPST1NQUERYMOD);
	if (initdoneMNVector == comp->initdoneMNVector) insert(items, INITDONEMNVECTOR);
	if (initdoneMNQuery == comp->initdoneMNQuery) insert(items, INITDONEMNQUERY);

	return(items);
};

set<uint> PnlWznmTblRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEALOADFCT, INITDONEATITLE, INITDONEFR1NRELATION, INITDONETO1NRELATION, INITDONE1NSTUB, INITDONE1NSUBSET, INITDONETBL1NTABLECOL, INITDONE1NIMPEXP, INITDONE1NCHECK, INITDONEHK1NVECTOR, INITDONEREF1NQUERYMOD, INITDONEREF1NRTBLOCK, INITDONEFCT1NTABLECOL, INITDONEREF1NPANEL, INITDONEREF1NDIALOG, INITDONEREF1NCALL, INITDONESRC1NFEED, INITDONEPST1NQUERYMOD, INITDONEMNVECTOR, INITDONEMNQUERY};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTblRec::StatShr
 ******************************************************************************/

PnlWznmTblRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefALoadfct
			, const bool pnlaloadfctAvail
			, const string& scrJrefATitle
			, const bool pnlatitleAvail
			, const string& scrJrefFr1NRelation
			, const bool pnlfr1nrelationAvail
			, const string& scrJrefTo1NRelation
			, const bool pnlto1nrelationAvail
			, const string& scrJref1NStub
			, const bool pnl1nstubAvail
			, const string& scrJref1NSubset
			, const bool pnl1nsubsetAvail
			, const string& scrJrefTbl1NTablecol
			, const string& scrJref1NImpexp
			, const bool pnl1nimpexpAvail
			, const string& scrJref1NCheck
			, const bool pnl1ncheckAvail
			, const string& scrJrefHk1NVector
			, const string& scrJrefRef1NQuerymod
			, const string& scrJrefRef1NRtblock
			, const string& scrJrefFct1NTablecol
			, const bool pnlfct1ntablecolAvail
			, const string& scrJrefRef1NPanel
			, const string& scrJrefRef1NDialog
			, const bool pnlref1ndialogAvail
			, const string& scrJrefRef1NCall
			, const bool pnlref1ncallAvail
			, const string& scrJrefSrc1NFeed
			, const string& scrJrefPst1NQuerymod
			, const bool pnlpst1nquerymodAvail
			, const string& scrJrefMNVector
			, const bool pnlmnvectorAvail
			, const string& scrJrefMNQuery
			, const bool pnlmnqueryAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefALoadfct = scrJrefALoadfct;
	this->pnlaloadfctAvail = pnlaloadfctAvail;
	this->scrJrefATitle = scrJrefATitle;
	this->pnlatitleAvail = pnlatitleAvail;
	this->scrJrefFr1NRelation = scrJrefFr1NRelation;
	this->pnlfr1nrelationAvail = pnlfr1nrelationAvail;
	this->scrJrefTo1NRelation = scrJrefTo1NRelation;
	this->pnlto1nrelationAvail = pnlto1nrelationAvail;
	this->scrJref1NStub = scrJref1NStub;
	this->pnl1nstubAvail = pnl1nstubAvail;
	this->scrJref1NSubset = scrJref1NSubset;
	this->pnl1nsubsetAvail = pnl1nsubsetAvail;
	this->scrJrefTbl1NTablecol = scrJrefTbl1NTablecol;
	this->scrJref1NImpexp = scrJref1NImpexp;
	this->pnl1nimpexpAvail = pnl1nimpexpAvail;
	this->scrJref1NCheck = scrJref1NCheck;
	this->pnl1ncheckAvail = pnl1ncheckAvail;
	this->scrJrefHk1NVector = scrJrefHk1NVector;
	this->scrJrefRef1NQuerymod = scrJrefRef1NQuerymod;
	this->scrJrefRef1NRtblock = scrJrefRef1NRtblock;
	this->scrJrefFct1NTablecol = scrJrefFct1NTablecol;
	this->pnlfct1ntablecolAvail = pnlfct1ntablecolAvail;
	this->scrJrefRef1NPanel = scrJrefRef1NPanel;
	this->scrJrefRef1NDialog = scrJrefRef1NDialog;
	this->pnlref1ndialogAvail = pnlref1ndialogAvail;
	this->scrJrefRef1NCall = scrJrefRef1NCall;
	this->pnlref1ncallAvail = pnlref1ncallAvail;
	this->scrJrefSrc1NFeed = scrJrefSrc1NFeed;
	this->scrJrefPst1NQuerymod = scrJrefPst1NQuerymod;
	this->pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
	this->scrJrefMNVector = scrJrefMNVector;
	this->pnlmnvectorAvail = pnlmnvectorAvail;
	this->scrJrefMNQuery = scrJrefMNQuery;
	this->pnlmnqueryAvail = pnlmnqueryAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFALOADFCT, PNLALOADFCTAVAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREFFR1NRELATION, PNLFR1NRELATIONAVAIL, SCRJREFTO1NRELATION, PNLTO1NRELATIONAVAIL, SCRJREF1NSTUB, PNL1NSTUBAVAIL, SCRJREF1NSUBSET, PNL1NSUBSETAVAIL, SCRJREFTBL1NTABLECOL, SCRJREF1NIMPEXP, PNL1NIMPEXPAVAIL, SCRJREF1NCHECK, PNL1NCHECKAVAIL, SCRJREFHK1NVECTOR, SCRJREFREF1NQUERYMOD, SCRJREFREF1NRTBLOCK, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFREF1NPANEL, SCRJREFREF1NDIALOG, PNLREF1NDIALOGAVAIL, SCRJREFREF1NCALL, PNLREF1NCALLAVAIL, SCRJREFSRC1NFEED, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNVECTOR, PNLMNVECTORAVAIL, SCRJREFMNQUERY, PNLMNQUERYAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWznmTblRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWznmVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWznmTblRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWznmTblRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", srefIxWznmVExpstate)) {
			ixWznmVExpstate = VecWznmVExpstate::getIx(srefIxWznmVExpstate);
			add(IXWZNMVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefALoadfct", scrJrefALoadfct)) add(SCRJREFALOADFCT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlaloadfctAvail", pnlaloadfctAvail)) add(PNLALOADFCTAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefATitle", scrJrefATitle)) add(SCRJREFATITLE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlatitleAvail", pnlatitleAvail)) add(PNLATITLEAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFr1NRelation", scrJrefFr1NRelation)) add(SCRJREFFR1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlfr1nrelationAvail", pnlfr1nrelationAvail)) add(PNLFR1NRELATIONAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTo1NRelation", scrJrefTo1NRelation)) add(SCRJREFTO1NRELATION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlto1nrelationAvail", pnlto1nrelationAvail)) add(PNLTO1NRELATIONAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NStub", scrJref1NStub)) add(SCRJREF1NSTUB);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nstubAvail", pnl1nstubAvail)) add(PNL1NSTUBAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NSubset", scrJref1NSubset)) add(SCRJREF1NSUBSET);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nsubsetAvail", pnl1nsubsetAvail)) add(PNL1NSUBSETAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefTbl1NTablecol", scrJrefTbl1NTablecol)) add(SCRJREFTBL1NTABLECOL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NImpexp", scrJref1NImpexp)) add(SCRJREF1NIMPEXP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1nimpexpAvail", pnl1nimpexpAvail)) add(PNL1NIMPEXPAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NCheck", scrJref1NCheck)) add(SCRJREF1NCHECK);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnl1ncheckAvail", pnl1ncheckAvail)) add(PNL1NCHECKAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", scrJrefHk1NVector)) add(SCRJREFHK1NVECTOR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NQuerymod", scrJrefRef1NQuerymod)) add(SCRJREFREF1NQUERYMOD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NRtblock", scrJrefRef1NRtblock)) add(SCRJREFREF1NRTBLOCK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefFct1NTablecol", scrJrefFct1NTablecol)) add(SCRJREFFCT1NTABLECOL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlfct1ntablecolAvail", pnlfct1ntablecolAvail)) add(PNLFCT1NTABLECOLAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NPanel", scrJrefRef1NPanel)) add(SCRJREFREF1NPANEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NDialog", scrJrefRef1NDialog)) add(SCRJREFREF1NDIALOG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlref1ndialogAvail", pnlref1ndialogAvail)) add(PNLREF1NDIALOGAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefRef1NCall", scrJrefRef1NCall)) add(SCRJREFREF1NCALL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlref1ncallAvail", pnlref1ncallAvail)) add(PNLREF1NCALLAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrc1NFeed", scrJrefSrc1NFeed)) add(SCRJREFSRC1NFEED);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefPst1NQuerymod", scrJrefPst1NQuerymod)) add(SCRJREFPST1NQUERYMOD);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlpst1nquerymodAvail", pnlpst1nquerymodAvail)) add(PNLPST1NQUERYMODAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNVector", scrJrefMNVector)) add(SCRJREFMNVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnvectorAvail", pnlmnvectorAvail)) add(PNLMNVECTORAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNQuery", scrJrefMNQuery)) add(SCRJREFMNQUERY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlmnqueryAvail", pnlmnqueryAvail)) add(PNLMNQUERYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWznmTblRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefALoadfct == comp->scrJrefALoadfct) insert(items, SCRJREFALOADFCT);
	if (pnlaloadfctAvail == comp->pnlaloadfctAvail) insert(items, PNLALOADFCTAVAIL);
	if (scrJrefATitle == comp->scrJrefATitle) insert(items, SCRJREFATITLE);
	if (pnlatitleAvail == comp->pnlatitleAvail) insert(items, PNLATITLEAVAIL);
	if (scrJrefFr1NRelation == comp->scrJrefFr1NRelation) insert(items, SCRJREFFR1NRELATION);
	if (pnlfr1nrelationAvail == comp->pnlfr1nrelationAvail) insert(items, PNLFR1NRELATIONAVAIL);
	if (scrJrefTo1NRelation == comp->scrJrefTo1NRelation) insert(items, SCRJREFTO1NRELATION);
	if (pnlto1nrelationAvail == comp->pnlto1nrelationAvail) insert(items, PNLTO1NRELATIONAVAIL);
	if (scrJref1NStub == comp->scrJref1NStub) insert(items, SCRJREF1NSTUB);
	if (pnl1nstubAvail == comp->pnl1nstubAvail) insert(items, PNL1NSTUBAVAIL);
	if (scrJref1NSubset == comp->scrJref1NSubset) insert(items, SCRJREF1NSUBSET);
	if (pnl1nsubsetAvail == comp->pnl1nsubsetAvail) insert(items, PNL1NSUBSETAVAIL);
	if (scrJrefTbl1NTablecol == comp->scrJrefTbl1NTablecol) insert(items, SCRJREFTBL1NTABLECOL);
	if (scrJref1NImpexp == comp->scrJref1NImpexp) insert(items, SCRJREF1NIMPEXP);
	if (pnl1nimpexpAvail == comp->pnl1nimpexpAvail) insert(items, PNL1NIMPEXPAVAIL);
	if (scrJref1NCheck == comp->scrJref1NCheck) insert(items, SCRJREF1NCHECK);
	if (pnl1ncheckAvail == comp->pnl1ncheckAvail) insert(items, PNL1NCHECKAVAIL);
	if (scrJrefHk1NVector == comp->scrJrefHk1NVector) insert(items, SCRJREFHK1NVECTOR);
	if (scrJrefRef1NQuerymod == comp->scrJrefRef1NQuerymod) insert(items, SCRJREFREF1NQUERYMOD);
	if (scrJrefRef1NRtblock == comp->scrJrefRef1NRtblock) insert(items, SCRJREFREF1NRTBLOCK);
	if (scrJrefFct1NTablecol == comp->scrJrefFct1NTablecol) insert(items, SCRJREFFCT1NTABLECOL);
	if (pnlfct1ntablecolAvail == comp->pnlfct1ntablecolAvail) insert(items, PNLFCT1NTABLECOLAVAIL);
	if (scrJrefRef1NPanel == comp->scrJrefRef1NPanel) insert(items, SCRJREFREF1NPANEL);
	if (scrJrefRef1NDialog == comp->scrJrefRef1NDialog) insert(items, SCRJREFREF1NDIALOG);
	if (pnlref1ndialogAvail == comp->pnlref1ndialogAvail) insert(items, PNLREF1NDIALOGAVAIL);
	if (scrJrefRef1NCall == comp->scrJrefRef1NCall) insert(items, SCRJREFREF1NCALL);
	if (pnlref1ncallAvail == comp->pnlref1ncallAvail) insert(items, PNLREF1NCALLAVAIL);
	if (scrJrefSrc1NFeed == comp->scrJrefSrc1NFeed) insert(items, SCRJREFSRC1NFEED);
	if (scrJrefPst1NQuerymod == comp->scrJrefPst1NQuerymod) insert(items, SCRJREFPST1NQUERYMOD);
	if (pnlpst1nquerymodAvail == comp->pnlpst1nquerymodAvail) insert(items, PNLPST1NQUERYMODAVAIL);
	if (scrJrefMNVector == comp->scrJrefMNVector) insert(items, SCRJREFMNVECTOR);
	if (pnlmnvectorAvail == comp->pnlmnvectorAvail) insert(items, PNLMNVECTORAVAIL);
	if (scrJrefMNQuery == comp->scrJrefMNQuery) insert(items, SCRJREFMNQUERY);
	if (pnlmnqueryAvail == comp->pnlmnqueryAvail) insert(items, PNLMNQUERYAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWznmTblRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFALOADFCT, PNLALOADFCTAVAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREFFR1NRELATION, PNLFR1NRELATIONAVAIL, SCRJREFTO1NRELATION, PNLTO1NRELATIONAVAIL, SCRJREF1NSTUB, PNL1NSTUBAVAIL, SCRJREF1NSUBSET, PNL1NSUBSETAVAIL, SCRJREFTBL1NTABLECOL, SCRJREF1NIMPEXP, PNL1NIMPEXPAVAIL, SCRJREF1NCHECK, PNL1NCHECKAVAIL, SCRJREFHK1NVECTOR, SCRJREFREF1NQUERYMOD, SCRJREFREF1NRTBLOCK, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFREF1NPANEL, SCRJREFREF1NDIALOG, PNLREF1NDIALOGAVAIL, SCRJREFREF1NCALL, PNLREF1NCALLAVAIL, SCRJREFSRC1NFEED, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNVECTOR, PNLMNVECTORAVAIL, SCRJREFMNQUERY, PNLMNQUERYAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTblRec::Tag
 ******************************************************************************/

PnlWznmTblRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWznmTblRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWznmTblRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWznmTblRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWznmTblRec::DpchAppDo
 ******************************************************************************/

PnlWznmTblRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWznmTblRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWznmTblRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblRec::DpchEngData
 ******************************************************************************/

PnlWznmTblRec::DpchEngData::DpchEngData() :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTBLRECDATA)
		{
};

string PnlWznmTblRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWznmTblRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
