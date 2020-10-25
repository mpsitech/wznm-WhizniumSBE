/**
	* \file WznmQTblRef1NQuerymod.cpp
	* API code for table TblWznmQTblRef1NQuerymod (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQTblRef1NQuerymod.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblRef1NQuerymod
 ******************************************************************************/

WznmQTblRef1NQuerymod::WznmQTblRef1NQuerymod(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTblRef1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblRef1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblRef1NQuerymod
 ******************************************************************************/

ListWznmQTblRef1NQuerymod::ListWznmQTblRef1NQuerymod() {
};

ListWznmQTblRef1NQuerymod::ListWznmQTblRef1NQuerymod(
			const ListWznmQTblRef1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblRef1NQuerymod(*(src.nodes[i]));
};

ListWznmQTblRef1NQuerymod& ListWznmQTblRef1NQuerymod::operator=(
			const ListWznmQTblRef1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblRef1NQuerymod(*(src.nodes[i]));

	return *this;
};

ListWznmQTblRef1NQuerymod::~ListWznmQTblRef1NQuerymod() {
	clear();
};

void ListWznmQTblRef1NQuerymod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblRef1NQuerymod::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblRef1NQuerymod* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblRef1NQuerymod");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblRef1NQuerymod", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblRef1NQuerymod(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblRef1NQuerymod[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

