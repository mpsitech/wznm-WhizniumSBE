/**
	* \file QryWznmConList.cpp
	* API code for job QryWznmConList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "QryWznmConList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmConList::VecVOrd
 ******************************************************************************/

uint QryWznmConList::VecVOrd::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "sup") return SUP;
	if (s == "reu") return REU;
	if (s == "ret") return RET;
	if (s == "hku") return HKU;
	if (s == "sct") return SCT;
	if (s == "hkt") return HKT;
	if (s == "typ") return TYP;
	if (s == "srf") return SRF;

	return(0);
};

string QryWznmConList::VecVOrd::getSref(
			const uint ix
		) {
	if (ix == SUP) return("sup");
	if (ix == REU) return("reu");
	if (ix == RET) return("ret");
	if (ix == HKU) return("hku");
	if (ix == SCT) return("sct");
	if (ix == HKT) return("hkt");
	if (ix == TYP) return("typ");
	if (ix == SRF) return("srf");

	return("");
};

/******************************************************************************
 class QryWznmConList::StatApp
 ******************************************************************************/

QryWznmConList::StatApp::StatApp(
			const uint firstcol
			, const uint jnumFirstdisp
			, const uint ncol
			, const uint ndisp
		) :
			Block()
		{
	this->firstcol = firstcol;
	this->jnumFirstdisp = jnumFirstdisp;
	this->ncol = ncol;
	this->ndisp = ndisp;

	mask = {FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP};
};

bool QryWznmConList::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppQryWznmConList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppQryWznmConList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "firstcol", firstcol)) add(FIRSTCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstdisp", jnumFirstdisp)) add(JNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ncol", ncol)) add(NCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ndisp", ndisp)) add(NDISP);
	};

	return basefound;
};

set<uint> QryWznmConList::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (firstcol == comp->firstcol) insert(items, FIRSTCOL);
	if (jnumFirstdisp == comp->jnumFirstdisp) insert(items, JNUMFIRSTDISP);
	if (ncol == comp->ncol) insert(items, NCOL);
	if (ndisp == comp->ndisp) insert(items, NDISP);

	return(items);
};

set<uint> QryWznmConList::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWznmConList::StatShr
 ******************************************************************************/

QryWznmConList::StatShr::StatShr(
			const uint ntot
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->ntot = ntot;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {NTOT, JNUMFIRSTLOAD, NLOAD};
};

bool QryWznmConList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryWznmConList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryWznmConList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

set<uint> QryWznmConList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmConList::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWznmConList::StgIac
 ******************************************************************************/

QryWznmConList::StgIac::StgIac(
			const uint jnum
			, const uint jnumFirstload
			, const uint nload
		) :
			Block()
		{
	this->jnum = jnum;
	this->jnumFirstload = jnumFirstload;
	this->nload = nload;

	mask = {JNUM, JNUMFIRSTLOAD, NLOAD};
};

bool QryWznmConList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmConList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmConList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWznmConList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmConList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmConList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmConList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmConList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
