/**
	* \file QryWznmTblHk1NVector.cpp
	* API code for job QryWznmTblHk1NVector (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "QryWznmTblHk1NVector.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmTblHk1NVector::StatApp
 ******************************************************************************/

QryWznmTblHk1NVector::StatApp::StatApp(
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

bool QryWznmTblHk1NVector::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppQryWznmTblHk1NVector");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppQryWznmTblHk1NVector";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "firstcol", firstcol)) add(FIRSTCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstdisp", jnumFirstdisp)) add(JNUMFIRSTDISP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ncol", ncol)) add(NCOL);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ndisp", ndisp)) add(NDISP);
	};

	return basefound;
};

set<uint> QryWznmTblHk1NVector::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (firstcol == comp->firstcol) insert(items, FIRSTCOL);
	if (jnumFirstdisp == comp->jnumFirstdisp) insert(items, JNUMFIRSTDISP);
	if (ncol == comp->ncol) insert(items, NCOL);
	if (ndisp == comp->ndisp) insert(items, NDISP);

	return(items);
};

set<uint> QryWznmTblHk1NVector::StatApp::diff(
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
 class QryWznmTblHk1NVector::StatShr
 ******************************************************************************/

QryWznmTblHk1NVector::StatShr::StatShr(
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

bool QryWznmTblHk1NVector::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryWznmTblHk1NVector");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryWznmTblHk1NVector";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

set<uint> QryWznmTblHk1NVector::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmTblHk1NVector::StatShr::diff(
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
 class QryWznmTblHk1NVector::StgIac
 ******************************************************************************/

QryWznmTblHk1NVector::StgIac::StgIac(
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

bool QryWznmTblHk1NVector::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmTblHk1NVector");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmTblHk1NVector";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnumFirstload", jnumFirstload)) add(JNUMFIRSTLOAD);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "nload", nload)) add(NLOAD);
	};

	return basefound;
};

void QryWznmTblHk1NVector::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmTblHk1NVector";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmTblHk1NVector";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
		writeUintAttr(wr, itemtag, "sref", "jnumFirstload", jnumFirstload);
		writeUintAttr(wr, itemtag, "sref", "nload", nload);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmTblHk1NVector::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);
	if (jnumFirstload == comp->jnumFirstload) insert(items, JNUMFIRSTLOAD);
	if (nload == comp->nload) insert(items, NLOAD);

	return(items);
};

set<uint> QryWznmTblHk1NVector::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM, JNUMFIRSTLOAD, NLOAD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
