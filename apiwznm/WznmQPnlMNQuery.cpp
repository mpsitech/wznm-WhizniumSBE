/**
	* \file WznmQPnlMNQuery.cpp
	* API code for table TblWznmQPnlMNQuery (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPnlMNQuery.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPnlMNQuery
 ******************************************************************************/

WznmQPnlMNQuery::WznmQPnlMNQuery(
			const uint jnum
			, const string stubMref
		) :
			jnum(jnum)
			, stubMref(stubMref)
		{
};

bool WznmQPnlMNQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQPnlMNQuery");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQPnlMNQuery
 ******************************************************************************/

ListWznmQPnlMNQuery::ListWznmQPnlMNQuery() {
};

ListWznmQPnlMNQuery::ListWznmQPnlMNQuery(
			const ListWznmQPnlMNQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPnlMNQuery(*(src.nodes[i]));
};

ListWznmQPnlMNQuery& ListWznmQPnlMNQuery::operator=(
			const ListWznmQPnlMNQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPnlMNQuery(*(src.nodes[i]));

	return *this;
};

ListWznmQPnlMNQuery::~ListWznmQPnlMNQuery() {
	clear();
};

void ListWznmQPnlMNQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQPnlMNQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQPnlMNQuery* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQPnlMNQuery");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQPnlMNQuery", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQPnlMNQuery(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQPnlMNQuery[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
