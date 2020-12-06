/**
	* \file WznmQTcoRef1NQuerymod.cpp
	* API code for table TblWznmQTcoRef1NQuerymod (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTcoRef1NQuerymod.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTcoRef1NQuerymod
 ******************************************************************************/

WznmQTcoRef1NQuerymod::WznmQTcoRef1NQuerymod(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTcoRef1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTcoRef1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTcoRef1NQuerymod
 ******************************************************************************/

ListWznmQTcoRef1NQuerymod::ListWznmQTcoRef1NQuerymod() {
};

ListWznmQTcoRef1NQuerymod::ListWznmQTcoRef1NQuerymod(
			const ListWznmQTcoRef1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoRef1NQuerymod(*(src.nodes[i]));
};

ListWznmQTcoRef1NQuerymod& ListWznmQTcoRef1NQuerymod::operator=(
			const ListWznmQTcoRef1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoRef1NQuerymod(*(src.nodes[i]));

	return *this;
};

ListWznmQTcoRef1NQuerymod::~ListWznmQTcoRef1NQuerymod() {
	clear();
};

void ListWznmQTcoRef1NQuerymod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTcoRef1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTcoRef1NQuerymod* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTcoRef1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTcoRef1NQuerymod", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTcoRef1NQuerymod(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTcoRef1NQuerymod[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
