/**
	* \file WznmQMchList.cpp
	* API code for table TblWznmQMchList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMchList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMchList
 ******************************************************************************/

WznmQMchList::WznmQMchList(
			const uint jnum
			, const string sref
			, const string stubSupRefWznmMMachine
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubSupRefWznmMMachine = stubSupRefWznmMMachine;
};

bool WznmQMchList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMchList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubSupRefWznmMMachine", "sup", stubSupRefWznmMMachine);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMchList
 ******************************************************************************/

ListWznmQMchList::ListWznmQMchList() {
};

ListWznmQMchList::ListWznmQMchList(
			const ListWznmQMchList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMchList(*(src.nodes[i]));
};

ListWznmQMchList& ListWznmQMchList::operator=(
			const ListWznmQMchList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMchList(*(src.nodes[i]));

	return *this;
};

ListWznmQMchList::~ListWznmQMchList() {
	clear();
};

void ListWznmQMchList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMchList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMchList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMchList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMchList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMchList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMchList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

