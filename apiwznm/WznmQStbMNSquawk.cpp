/**
	* \file WznmQStbMNSquawk.cpp
	* API code for table TblWznmQStbMNSquawk (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQStbMNSquawk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQStbMNSquawk
 ******************************************************************************/

WznmQStbMNSquawk::WznmQStbMNSquawk(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool WznmQStbMNSquawk::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQStbMNSquawk");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQStbMNSquawk
 ******************************************************************************/

ListWznmQStbMNSquawk::ListWznmQStbMNSquawk() {
};

ListWznmQStbMNSquawk::ListWznmQStbMNSquawk(
			const ListWznmQStbMNSquawk& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQStbMNSquawk(*(src.nodes[i]));
};

ListWznmQStbMNSquawk& ListWznmQStbMNSquawk::operator=(
			const ListWznmQStbMNSquawk& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQStbMNSquawk(*(src.nodes[i]));

	return *this;
};

ListWznmQStbMNSquawk::~ListWznmQStbMNSquawk() {
	clear();
};

void ListWznmQStbMNSquawk::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQStbMNSquawk::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQStbMNSquawk* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQStbMNSquawk");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQStbMNSquawk", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQStbMNSquawk(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQStbMNSquawk[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

