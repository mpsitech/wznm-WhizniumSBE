/**
	* \file WznmQSbsPst1NQuerymod.cpp
	* API code for table TblWznmQSbsPst1NQuerymod (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSbsPst1NQuerymod.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsPst1NQuerymod
 ******************************************************************************/

WznmQSbsPst1NQuerymod::WznmQSbsPst1NQuerymod(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQSbsPst1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSbsPst1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSbsPst1NQuerymod
 ******************************************************************************/

ListWznmQSbsPst1NQuerymod::ListWznmQSbsPst1NQuerymod() {
};

ListWznmQSbsPst1NQuerymod::ListWznmQSbsPst1NQuerymod(
			const ListWznmQSbsPst1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsPst1NQuerymod(*(src.nodes[i]));
};

ListWznmQSbsPst1NQuerymod& ListWznmQSbsPst1NQuerymod::operator=(
			const ListWznmQSbsPst1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsPst1NQuerymod(*(src.nodes[i]));

	return *this;
};

ListWznmQSbsPst1NQuerymod::~ListWznmQSbsPst1NQuerymod() {
	clear();
};

void ListWznmQSbsPst1NQuerymod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSbsPst1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSbsPst1NQuerymod* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSbsPst1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSbsPst1NQuerymod", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSbsPst1NQuerymod(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSbsPst1NQuerymod[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
