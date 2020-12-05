/**
	* \file WznmQQry1NQuerymod.cpp
	* API code for table TblWznmQQry1NQuerymod (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQry1NQuerymod.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQry1NQuerymod
 ******************************************************************************/

WznmQQry1NQuerymod::WznmQQry1NQuerymod(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQQry1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQry1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQry1NQuerymod
 ******************************************************************************/

ListWznmQQry1NQuerymod::ListWznmQQry1NQuerymod() {
};

ListWznmQQry1NQuerymod::ListWznmQQry1NQuerymod(
			const ListWznmQQry1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQry1NQuerymod(*(src.nodes[i]));
};

ListWznmQQry1NQuerymod& ListWznmQQry1NQuerymod::operator=(
			const ListWznmQQry1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQry1NQuerymod(*(src.nodes[i]));

	return *this;
};

ListWznmQQry1NQuerymod::~ListWznmQQry1NQuerymod() {
	clear();
};

void ListWznmQQry1NQuerymod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQry1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQry1NQuerymod* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQry1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQry1NQuerymod", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQry1NQuerymod(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQry1NQuerymod[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

