/**
	* \file WznmQPnlHk1NControl.cpp
	* API code for table TblWznmQPnlHk1NControl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPnlHk1NControl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPnlHk1NControl
 ******************************************************************************/

WznmQPnlHk1NControl::WznmQPnlHk1NControl(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQPnlHk1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQPnlHk1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQPnlHk1NControl
 ******************************************************************************/

ListWznmQPnlHk1NControl::ListWznmQPnlHk1NControl() {
};

ListWznmQPnlHk1NControl::ListWznmQPnlHk1NControl(
			const ListWznmQPnlHk1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPnlHk1NControl(*(src.nodes[i]));
};

ListWznmQPnlHk1NControl& ListWznmQPnlHk1NControl::operator=(
			const ListWznmQPnlHk1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPnlHk1NControl(*(src.nodes[i]));

	return *this;
};

ListWznmQPnlHk1NControl::~ListWznmQPnlHk1NControl() {
	clear();
};

void ListWznmQPnlHk1NControl::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQPnlHk1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQPnlHk1NControl* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQPnlHk1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQPnlHk1NControl", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQPnlHk1NControl(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQPnlHk1NControl[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
