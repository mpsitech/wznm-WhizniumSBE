/**
	* \file WznmQTco1NQuerycol.cpp
	* API code for table TblWznmQTco1NQuerycol (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQTco1NQuerycol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTco1NQuerycol
 ******************************************************************************/

WznmQTco1NQuerycol::WznmQTco1NQuerycol(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTco1NQuerycol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTco1NQuerycol");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTco1NQuerycol
 ******************************************************************************/

ListWznmQTco1NQuerycol::ListWznmQTco1NQuerycol() {
};

ListWznmQTco1NQuerycol::ListWznmQTco1NQuerycol(
			const ListWznmQTco1NQuerycol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTco1NQuerycol(*(src.nodes[i]));
};

ListWznmQTco1NQuerycol& ListWznmQTco1NQuerycol::operator=(
			const ListWznmQTco1NQuerycol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTco1NQuerycol(*(src.nodes[i]));

	return *this;
};

ListWznmQTco1NQuerycol::~ListWznmQTco1NQuerycol() {
	clear();
};

void ListWznmQTco1NQuerycol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTco1NQuerycol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTco1NQuerycol* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTco1NQuerycol");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTco1NQuerycol", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTco1NQuerycol(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTco1NQuerycol[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

