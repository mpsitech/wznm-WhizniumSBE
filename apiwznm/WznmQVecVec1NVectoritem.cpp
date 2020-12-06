/**
	* \file WznmQVecVec1NVectoritem.cpp
	* API code for table TblWznmQVecVec1NVectoritem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVecVec1NVectoritem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVecVec1NVectoritem
 ******************************************************************************/

WznmQVecVec1NVectoritem::WznmQVecVec1NVectoritem(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQVecVec1NVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVecVec1NVectoritem");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVecVec1NVectoritem
 ******************************************************************************/

ListWznmQVecVec1NVectoritem::ListWznmQVecVec1NVectoritem() {
};

ListWznmQVecVec1NVectoritem::ListWznmQVecVec1NVectoritem(
			const ListWznmQVecVec1NVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecVec1NVectoritem(*(src.nodes[i]));
};

ListWznmQVecVec1NVectoritem& ListWznmQVecVec1NVectoritem::operator=(
			const ListWznmQVecVec1NVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecVec1NVectoritem(*(src.nodes[i]));

	return *this;
};

ListWznmQVecVec1NVectoritem::~ListWznmQVecVec1NVectoritem() {
	clear();
};

void ListWznmQVecVec1NVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVecVec1NVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVecVec1NVectoritem* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVecVec1NVectoritem");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVecVec1NVectoritem", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVecVec1NVectoritem(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVecVec1NVectoritem[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
