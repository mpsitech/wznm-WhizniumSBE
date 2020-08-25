/**
	* \file QryWznmMtyList.cpp
	* API code for job QryWznmMtyList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "QryWznmMtyList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmMtyList::VecVOrd
 ******************************************************************************/

uint QryWznmMtyList::VecVOrd::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "srf") return SRF;

	return(0);
};

string QryWznmMtyList::VecVOrd::getSref(
			const uint ix
		) {
	if (ix == SRF) return("srf");

	return("");
};

/******************************************************************************
 class QryWznmMtyList::StatApp
 ******************************************************************************/

QryWznmMtyList::StatApp::StatApp(
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

bool QryWznmMtyList::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppQryWznmMtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppQryWznmMtyList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "firstcol", firstcol)) add(FIRSTCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstdisp", jnumFirstdisp)) add(JNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ncol", ncol)) add(NCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ndisp", ndisp)) add(NDISP);
	};

	return basefound;
};

set<uint> QryWznmMtyList::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (firstcol == comp->firstcol) insert(items, FIRSTCOL);
	if (jnumFirstdisp == comp->jnumFirstdisp) insert(items, JNUMFIRSTDISP);
	if (ncol == comp->ncol) insert(items, NCOL);
	if (ndisp == comp->ndisp) insert(items, NDISP);

	return(items);
};

set<uint> QryWznmMtyList::StatApp::diff(
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
 class QryWznmMtyList::StatShr
 ******************************************************************************/

QryWznmMtyList::StatShr::StatShr(
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

bool QryWznmMtyList::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryWznmMtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryWznmMtyList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

set<uint> QryWznmMtyList::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmMtyList::StatShr::diff(
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
 class QryWznmMtyList::StgIac
 ******************************************************************************/

QryWznmMtyList::StgIac::StgIac(
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

bool QryWznmMtyList::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmMtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmMtyList";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWznmMtyList::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmMtyList";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmMtyList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmMtyList::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmMtyList::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

