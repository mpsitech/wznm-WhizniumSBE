/**
	* \file WznmQVecMNTable.cpp
	* API code for table TblWznmQVecMNTable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVecMNTable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVecMNTable
 ******************************************************************************/

WznmQVecMNTable::WznmQVecMNTable(
			const uint jnum
			, const string stubMref
			, const string stubRefWznmMSubset
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->stubRefWznmMSubset = stubRefWznmMSubset;
};

bool WznmQVecMNTable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVecMNTable");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMSubset", "sbs", stubRefWznmMSubset);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVecMNTable
 ******************************************************************************/

ListWznmQVecMNTable::ListWznmQVecMNTable() {
};

ListWznmQVecMNTable::ListWznmQVecMNTable(
			const ListWznmQVecMNTable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecMNTable(*(src.nodes[i]));
};

ListWznmQVecMNTable& ListWznmQVecMNTable::operator=(
			const ListWznmQVecMNTable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecMNTable(*(src.nodes[i]));

	return *this;
};

ListWznmQVecMNTable::~ListWznmQVecMNTable() {
	clear();
};

void ListWznmQVecMNTable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVecMNTable::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVecMNTable* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVecMNTable");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVecMNTable", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVecMNTable(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVecMNTable[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
