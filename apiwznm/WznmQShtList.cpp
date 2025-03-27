/**
	* \file WznmQShtList.cpp
	* API code for table TblWznmQShtList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQShtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQShtList
 ******************************************************************************/

WznmQShtList::WznmQShtList(
			const uint jnum
			, const string Title
			, const string stubVisRefWznmMVisual
		) :
			jnum(jnum)
			, Title(Title)
			, stubVisRefWznmMVisual(stubVisRefWznmMVisual)
		{
};

bool WznmQShtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQShtList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubVisRefWznmMVisual", "vis", stubVisRefWznmMVisual);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQShtList
 ******************************************************************************/

ListWznmQShtList::ListWznmQShtList() {
};

ListWznmQShtList::ListWznmQShtList(
			const ListWznmQShtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQShtList(*(src.nodes[i]));
};

ListWznmQShtList& ListWznmQShtList::operator=(
			const ListWznmQShtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQShtList(*(src.nodes[i]));

	return *this;
};

ListWznmQShtList::~ListWznmQShtList() {
	clear();
};

void ListWznmQShtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQShtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQShtList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQShtList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQShtList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQShtList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQShtList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
