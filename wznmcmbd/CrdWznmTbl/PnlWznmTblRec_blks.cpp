/**
	* \file PnlWznmTblRec_blks.cpp
	* job handler for job PnlWznmTblRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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

void PnlWznmTblRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWznmTblRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWznmTblRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
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

void PnlWznmTblRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneATitle
			, const bool initdoneALoadfct
			, const bool initdoneTbl1NTablecol
			, const bool initdone1NStub
			, const bool initdone1NSubset
			, const bool initdoneFr1NRelation
			, const bool initdoneTo1NRelation
			, const bool initdone1NImpexp
			, const bool initdone1NCheck
			, const bool initdoneFct1NTablecol
			, const bool initdoneSrc1NFeed
			, const bool initdoneRef1NPanel
			, const bool initdoneRef1NRtblock
			, const bool initdoneRef1NQuerymod
			, const bool initdoneHk1NVector
			, const bool initdoneRef1NCall
			, const bool initdoneRef1NDialog
			, const bool initdonePst1NQuerymod
			, const bool initdoneMNVector
			, const bool initdoneMNQuery
		) {
	if (difftag.length() == 0) difftag = "StatAppWznmTblRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWznmTblRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneATitle", initdoneATitle);
		writeBoolAttr(wr, itemtag, "sref", "initdoneALoadfct", initdoneALoadfct);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTbl1NTablecol", initdoneTbl1NTablecol);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NStub", initdone1NStub);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NSubset", initdone1NSubset);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFr1NRelation", initdoneFr1NRelation);
		writeBoolAttr(wr, itemtag, "sref", "initdoneTo1NRelation", initdoneTo1NRelation);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NImpexp", initdone1NImpexp);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NCheck", initdone1NCheck);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFct1NTablecol", initdoneFct1NTablecol);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSrc1NFeed", initdoneSrc1NFeed);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NPanel", initdoneRef1NPanel);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NRtblock", initdoneRef1NRtblock);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NQuerymod", initdoneRef1NQuerymod);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NVector", initdoneHk1NVector);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NCall", initdoneRef1NCall);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NDialog", initdoneRef1NDialog);
		writeBoolAttr(wr, itemtag, "sref", "initdonePst1NQuerymod", initdonePst1NQuerymod);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNVector", initdoneMNVector);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNQuery", initdoneMNQuery);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblRec::StatShr
 ******************************************************************************/

PnlWznmTblRec::StatShr::StatShr(
			const uint ixWznmVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefATitle
			, const bool pnlatitleAvail
			, const ubigint jrefALoadfct
			, const bool pnlaloadfctAvail
			, const ubigint jrefTbl1NTablecol
			, const ubigint jref1NStub
			, const bool pnl1nstubAvail
			, const ubigint jref1NSubset
			, const bool pnl1nsubsetAvail
			, const ubigint jrefFr1NRelation
			, const bool pnlfr1nrelationAvail
			, const ubigint jrefTo1NRelation
			, const bool pnlto1nrelationAvail
			, const ubigint jref1NImpexp
			, const bool pnl1nimpexpAvail
			, const ubigint jref1NCheck
			, const bool pnl1ncheckAvail
			, const ubigint jrefFct1NTablecol
			, const bool pnlfct1ntablecolAvail
			, const ubigint jrefSrc1NFeed
			, const ubigint jrefRef1NPanel
			, const ubigint jrefRef1NRtblock
			, const ubigint jrefRef1NQuerymod
			, const ubigint jrefHk1NVector
			, const ubigint jrefRef1NCall
			, const bool pnlref1ncallAvail
			, const ubigint jrefRef1NDialog
			, const bool pnlref1ndialogAvail
			, const ubigint jrefPst1NQuerymod
			, const bool pnlpst1nquerymodAvail
			, const ubigint jrefMNVector
			, const bool pnlmnvectorAvail
			, const ubigint jrefMNQuery
			, const bool pnlmnqueryAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWznmVExpstate = ixWznmVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefATitle = jrefATitle;
	this->pnlatitleAvail = pnlatitleAvail;
	this->jrefALoadfct = jrefALoadfct;
	this->pnlaloadfctAvail = pnlaloadfctAvail;
	this->jrefTbl1NTablecol = jrefTbl1NTablecol;
	this->jref1NStub = jref1NStub;
	this->pnl1nstubAvail = pnl1nstubAvail;
	this->jref1NSubset = jref1NSubset;
	this->pnl1nsubsetAvail = pnl1nsubsetAvail;
	this->jrefFr1NRelation = jrefFr1NRelation;
	this->pnlfr1nrelationAvail = pnlfr1nrelationAvail;
	this->jrefTo1NRelation = jrefTo1NRelation;
	this->pnlto1nrelationAvail = pnlto1nrelationAvail;
	this->jref1NImpexp = jref1NImpexp;
	this->pnl1nimpexpAvail = pnl1nimpexpAvail;
	this->jref1NCheck = jref1NCheck;
	this->pnl1ncheckAvail = pnl1ncheckAvail;
	this->jrefFct1NTablecol = jrefFct1NTablecol;
	this->pnlfct1ntablecolAvail = pnlfct1ntablecolAvail;
	this->jrefSrc1NFeed = jrefSrc1NFeed;
	this->jrefRef1NPanel = jrefRef1NPanel;
	this->jrefRef1NRtblock = jrefRef1NRtblock;
	this->jrefRef1NQuerymod = jrefRef1NQuerymod;
	this->jrefHk1NVector = jrefHk1NVector;
	this->jrefRef1NCall = jrefRef1NCall;
	this->pnlref1ncallAvail = pnlref1ncallAvail;
	this->jrefRef1NDialog = jrefRef1NDialog;
	this->pnlref1ndialogAvail = pnlref1ndialogAvail;
	this->jrefPst1NQuerymod = jrefPst1NQuerymod;
	this->pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
	this->jrefMNVector = jrefMNVector;
	this->pnlmnvectorAvail = pnlmnvectorAvail;
	this->jrefMNQuery = jrefMNQuery;
	this->pnlmnqueryAvail = pnlmnqueryAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, PNLATITLEAVAIL, JREFALOADFCT, PNLALOADFCTAVAIL, JREFTBL1NTABLECOL, JREF1NSTUB, PNL1NSTUBAVAIL, JREF1NSUBSET, PNL1NSUBSETAVAIL, JREFFR1NRELATION, PNLFR1NRELATIONAVAIL, JREFTO1NRELATION, PNLTO1NRELATIONAVAIL, JREF1NIMPEXP, PNL1NIMPEXPAVAIL, JREF1NCHECK, PNL1NCHECKAVAIL, JREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, JREFSRC1NFEED, JREFREF1NPANEL, JREFREF1NRTBLOCK, JREFREF1NQUERYMOD, JREFHK1NVECTOR, JREFREF1NCALL, PNLREF1NCALLAVAIL, JREFREF1NDIALOG, PNLREF1NDIALOGAVAIL, JREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, JREFMNVECTOR, PNLMNVECTORAVAIL, JREFMNQUERY, PNLMNQUERYAVAIL, BUTREGULARIZEACTIVE};
};

void PnlWznmTblRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmTblRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmTblRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWznmVExpstate", VecWznmVExpstate::getSref(ixWznmVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefATitle", Scr::scramble(jrefATitle));
		writeBoolAttr(wr, itemtag, "sref", "pnlatitleAvail", pnlatitleAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefALoadfct", Scr::scramble(jrefALoadfct));
		writeBoolAttr(wr, itemtag, "sref", "pnlaloadfctAvail", pnlaloadfctAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefTbl1NTablecol", Scr::scramble(jrefTbl1NTablecol));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NStub", Scr::scramble(jref1NStub));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nstubAvail", pnl1nstubAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NSubset", Scr::scramble(jref1NSubset));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nsubsetAvail", pnl1nsubsetAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefFr1NRelation", Scr::scramble(jrefFr1NRelation));
		writeBoolAttr(wr, itemtag, "sref", "pnlfr1nrelationAvail", pnlfr1nrelationAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefTo1NRelation", Scr::scramble(jrefTo1NRelation));
		writeBoolAttr(wr, itemtag, "sref", "pnlto1nrelationAvail", pnlto1nrelationAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NImpexp", Scr::scramble(jref1NImpexp));
		writeBoolAttr(wr, itemtag, "sref", "pnl1nimpexpAvail", pnl1nimpexpAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJref1NCheck", Scr::scramble(jref1NCheck));
		writeBoolAttr(wr, itemtag, "sref", "pnl1ncheckAvail", pnl1ncheckAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefFct1NTablecol", Scr::scramble(jrefFct1NTablecol));
		writeBoolAttr(wr, itemtag, "sref", "pnlfct1ntablecolAvail", pnlfct1ntablecolAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefSrc1NFeed", Scr::scramble(jrefSrc1NFeed));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NPanel", Scr::scramble(jrefRef1NPanel));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NRtblock", Scr::scramble(jrefRef1NRtblock));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NQuerymod", Scr::scramble(jrefRef1NQuerymod));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NVector", Scr::scramble(jrefHk1NVector));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NCall", Scr::scramble(jrefRef1NCall));
		writeBoolAttr(wr, itemtag, "sref", "pnlref1ncallAvail", pnlref1ncallAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NDialog", Scr::scramble(jrefRef1NDialog));
		writeBoolAttr(wr, itemtag, "sref", "pnlref1ndialogAvail", pnlref1ndialogAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefPst1NQuerymod", Scr::scramble(jrefPst1NQuerymod));
		writeBoolAttr(wr, itemtag, "sref", "pnlpst1nquerymodAvail", pnlpst1nquerymodAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNVector", Scr::scramble(jrefMNVector));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnvectorAvail", pnlmnvectorAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNQuery", Scr::scramble(jrefMNQuery));
		writeBoolAttr(wr, itemtag, "sref", "pnlmnqueryAvail", pnlmnqueryAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmTblRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWznmVExpstate == comp->ixWznmVExpstate) insert(items, IXWZNMVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefATitle == comp->jrefATitle) insert(items, JREFATITLE);
	if (pnlatitleAvail == comp->pnlatitleAvail) insert(items, PNLATITLEAVAIL);
	if (jrefALoadfct == comp->jrefALoadfct) insert(items, JREFALOADFCT);
	if (pnlaloadfctAvail == comp->pnlaloadfctAvail) insert(items, PNLALOADFCTAVAIL);
	if (jrefTbl1NTablecol == comp->jrefTbl1NTablecol) insert(items, JREFTBL1NTABLECOL);
	if (jref1NStub == comp->jref1NStub) insert(items, JREF1NSTUB);
	if (pnl1nstubAvail == comp->pnl1nstubAvail) insert(items, PNL1NSTUBAVAIL);
	if (jref1NSubset == comp->jref1NSubset) insert(items, JREF1NSUBSET);
	if (pnl1nsubsetAvail == comp->pnl1nsubsetAvail) insert(items, PNL1NSUBSETAVAIL);
	if (jrefFr1NRelation == comp->jrefFr1NRelation) insert(items, JREFFR1NRELATION);
	if (pnlfr1nrelationAvail == comp->pnlfr1nrelationAvail) insert(items, PNLFR1NRELATIONAVAIL);
	if (jrefTo1NRelation == comp->jrefTo1NRelation) insert(items, JREFTO1NRELATION);
	if (pnlto1nrelationAvail == comp->pnlto1nrelationAvail) insert(items, PNLTO1NRELATIONAVAIL);
	if (jref1NImpexp == comp->jref1NImpexp) insert(items, JREF1NIMPEXP);
	if (pnl1nimpexpAvail == comp->pnl1nimpexpAvail) insert(items, PNL1NIMPEXPAVAIL);
	if (jref1NCheck == comp->jref1NCheck) insert(items, JREF1NCHECK);
	if (pnl1ncheckAvail == comp->pnl1ncheckAvail) insert(items, PNL1NCHECKAVAIL);
	if (jrefFct1NTablecol == comp->jrefFct1NTablecol) insert(items, JREFFCT1NTABLECOL);
	if (pnlfct1ntablecolAvail == comp->pnlfct1ntablecolAvail) insert(items, PNLFCT1NTABLECOLAVAIL);
	if (jrefSrc1NFeed == comp->jrefSrc1NFeed) insert(items, JREFSRC1NFEED);
	if (jrefRef1NPanel == comp->jrefRef1NPanel) insert(items, JREFREF1NPANEL);
	if (jrefRef1NRtblock == comp->jrefRef1NRtblock) insert(items, JREFREF1NRTBLOCK);
	if (jrefRef1NQuerymod == comp->jrefRef1NQuerymod) insert(items, JREFREF1NQUERYMOD);
	if (jrefHk1NVector == comp->jrefHk1NVector) insert(items, JREFHK1NVECTOR);
	if (jrefRef1NCall == comp->jrefRef1NCall) insert(items, JREFREF1NCALL);
	if (pnlref1ncallAvail == comp->pnlref1ncallAvail) insert(items, PNLREF1NCALLAVAIL);
	if (jrefRef1NDialog == comp->jrefRef1NDialog) insert(items, JREFREF1NDIALOG);
	if (pnlref1ndialogAvail == comp->pnlref1ndialogAvail) insert(items, PNLREF1NDIALOGAVAIL);
	if (jrefPst1NQuerymod == comp->jrefPst1NQuerymod) insert(items, JREFPST1NQUERYMOD);
	if (pnlpst1nquerymodAvail == comp->pnlpst1nquerymodAvail) insert(items, PNLPST1NQUERYMODAVAIL);
	if (jrefMNVector == comp->jrefMNVector) insert(items, JREFMNVECTOR);
	if (pnlmnvectorAvail == comp->pnlmnvectorAvail) insert(items, PNLMNVECTORAVAIL);
	if (jrefMNQuery == comp->jrefMNQuery) insert(items, JREFMNQUERY);
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

	diffitems = {IXWZNMVEXPSTATE, JREFDETAIL, JREFATITLE, PNLATITLEAVAIL, JREFALOADFCT, PNLALOADFCTAVAIL, JREFTBL1NTABLECOL, JREF1NSTUB, PNL1NSTUBAVAIL, JREF1NSUBSET, PNL1NSUBSETAVAIL, JREFFR1NRELATION, PNLFR1NRELATIONAVAIL, JREFTO1NRELATION, PNLTO1NRELATIONAVAIL, JREF1NIMPEXP, PNL1NIMPEXPAVAIL, JREF1NCHECK, PNL1NCHECKAVAIL, JREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, JREFSRC1NFEED, JREFREF1NPANEL, JREFREF1NRTBLOCK, JREFREF1NQUERYMOD, JREFHK1NVECTOR, JREFREF1NCALL, PNLREF1NCALLAVAIL, JREFREF1NDIALOG, PNLREF1NDIALOGAVAIL, JREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, JREFMNVECTOR, PNLMNVECTORAVAIL, JREFMNQUERY, PNLMNQUERYAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmTblRec::Tag
 ******************************************************************************/

void PnlWznmTblRec::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmTblRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmTblRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Table");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmTblRec::DpchAppDo
 ******************************************************************************/

PnlWznmTblRec::DpchAppDo::DpchAppDo() :
			DpchAppWznm(VecWznmVDpch::DPCHAPPWZNMTBLRECDO)
		{
	ixVDo = 0;
};

string PnlWznmTblRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWznmTblRecDo");
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
 class PnlWznmTblRec::DpchEngData
 ******************************************************************************/

PnlWznmTblRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMTBLRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmTblRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmTblRec::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWznmTblRec::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmTblRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};



