/**
	* \file QryWznmVisRowctx.cpp
	* API code for job QryWznmVisRowctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "QryWznmVisRowctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmVisRowctx::StatShr
 ******************************************************************************/

QryWznmVisRowctx::StatShr::StatShr(
			const uint ntot
		) :
			Block()
			, ntot(ntot)
		{
	mask = {NTOT};
};

bool QryWznmVisRowctx::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryWznmVisRowctx");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryWznmVisRowctx";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
	};

	return basefound;
};

set<uint> QryWznmVisRowctx::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryWznmVisRowctx::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NTOT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class QryWznmVisRowctx::StgIac
 ******************************************************************************/

QryWznmVisRowctx::StgIac::StgIac(
			const uint jnum
		) :
			Block()
			, jnum(jnum)
		{
	mask = {JNUM};
};

bool QryWznmVisRowctx::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmVisRowctx");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmVisRowctx";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryWznmVisRowctx::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmVisRowctx";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmVisRowctx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmVisRowctx::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryWznmVisRowctx::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
