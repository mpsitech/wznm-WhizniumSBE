/**
	* \file QryWznmVisLinkctx.cpp
	* API code for job QryWznmVisLinkctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

#include "QryWznmVisLinkctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class QryWznmVisLinkctx::StatShr
 ******************************************************************************/

QryWznmVisLinkctx::StatShr::StatShr(
			const uint ntot
		) :
			Block()
			, ntot(ntot)
		{
	mask = {NTOT};
};

bool QryWznmVisLinkctx::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrQryWznmVisLinkctx");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrQryWznmVisLinkctx";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ntot", ntot)) add(NTOT);
	};

	return basefound;
};

set<uint> QryWznmVisLinkctx::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ntot == comp->ntot) insert(items, NTOT);

	return(items);
};

set<uint> QryWznmVisLinkctx::StatShr::diff(
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
 class QryWznmVisLinkctx::StgIac
 ******************************************************************************/

QryWznmVisLinkctx::StgIac::StgIac(
			const uint jnum
		) :
			Block()
			, jnum(jnum)
		{
	mask = {JNUM};
};

bool QryWznmVisLinkctx::StgIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgIacQryWznmVisLinkctx");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemIacQryWznmVisLinkctx";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jnum", jnum)) add(JNUM);
	};

	return basefound;
};

void QryWznmVisLinkctx::StgIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgIacQryWznmVisLinkctx";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemIacQryWznmVisLinkctx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "jnum", jnum);
	xmlTextWriterEndElement(wr);
};

set<uint> QryWznmVisLinkctx::StgIac::comm(
			const StgIac* comp
		) {
	set<uint> items;

	if (jnum == comp->jnum) insert(items, JNUM);

	return(items);
};

set<uint> QryWznmVisLinkctx::StgIac::diff(
			const StgIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JNUM};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
