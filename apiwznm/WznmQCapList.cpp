/**
	* \file WznmQCapList.cpp
	* API code for table TblWznmQCapList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCapList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCapList
 ******************************************************************************/

WznmQCapList::WznmQCapList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubRefWznmMVersion
			, const string stubTplRefWznmMCapability
			, const string srefsIxWArtefact
			, const string titsIxWArtefact
		) :
			jnum(jnum)
			, sref(sref)
			, Title(Title)
			, stubRefWznmMVersion(stubRefWznmMVersion)
			, stubTplRefWznmMCapability(stubTplRefWznmMCapability)
			, srefsIxWArtefact(srefsIxWArtefact)
			, titsIxWArtefact(titsIxWArtefact)
		{
};

bool WznmQCapList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCapList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "stubTplRefWznmMCapability", "tpl", stubTplRefWznmMCapability);
		extractStringUclc(docctx, basexpath, "srefsIxWArtefact", "atf", srefsIxWArtefact);
		extractStringUclc(docctx, basexpath, "titsIxWArtefact", "atf2", titsIxWArtefact);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCapList
 ******************************************************************************/

ListWznmQCapList::ListWznmQCapList() {
};

ListWznmQCapList::ListWznmQCapList(
			const ListWznmQCapList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCapList(*(src.nodes[i]));
};

ListWznmQCapList& ListWznmQCapList::operator=(
			const ListWznmQCapList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCapList(*(src.nodes[i]));

	return *this;
};

ListWznmQCapList::~ListWznmQCapList() {
	clear();
};

void ListWznmQCapList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCapList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCapList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCapList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCapList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCapList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCapList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
