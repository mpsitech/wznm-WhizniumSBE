/**
	* \file WznmQQryQry1NQuerycol.cpp
	* API code for table TblWznmQQryQry1NQuerycol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryQry1NQuerycol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryQry1NQuerycol
 ******************************************************************************/

WznmQQryQry1NQuerycol::WznmQQryQry1NQuerycol(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQQryQry1NQuerycol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQryQry1NQuerycol");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQryQry1NQuerycol
 ******************************************************************************/

ListWznmQQryQry1NQuerycol::ListWznmQQryQry1NQuerycol() {
};

ListWznmQQryQry1NQuerycol::ListWznmQQryQry1NQuerycol(
			const ListWznmQQryQry1NQuerycol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryQry1NQuerycol(*(src.nodes[i]));
};

ListWznmQQryQry1NQuerycol& ListWznmQQryQry1NQuerycol::operator=(
			const ListWznmQQryQry1NQuerycol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryQry1NQuerycol(*(src.nodes[i]));

	return *this;
};

ListWznmQQryQry1NQuerycol::~ListWznmQQryQry1NQuerycol() {
	clear();
};

void ListWznmQQryQry1NQuerycol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQryQry1NQuerycol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQryQry1NQuerycol* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQryQry1NQuerycol");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQryQry1NQuerycol", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQryQry1NQuerycol(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQryQry1NQuerycol[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
