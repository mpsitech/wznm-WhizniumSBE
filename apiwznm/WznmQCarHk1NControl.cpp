/**
	* \file WznmQCarHk1NControl.cpp
	* API code for table TblWznmQCarHk1NControl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCarHk1NControl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCarHk1NControl
 ******************************************************************************/

WznmQCarHk1NControl::WznmQCarHk1NControl(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQCarHk1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCarHk1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCarHk1NControl
 ******************************************************************************/

ListWznmQCarHk1NControl::ListWznmQCarHk1NControl() {
};

ListWznmQCarHk1NControl::ListWznmQCarHk1NControl(
			const ListWznmQCarHk1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCarHk1NControl(*(src.nodes[i]));
};

ListWznmQCarHk1NControl& ListWznmQCarHk1NControl::operator=(
			const ListWznmQCarHk1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCarHk1NControl(*(src.nodes[i]));

	return *this;
};

ListWznmQCarHk1NControl::~ListWznmQCarHk1NControl() {
	clear();
};

void ListWznmQCarHk1NControl::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCarHk1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCarHk1NControl* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCarHk1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCarHk1NControl", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCarHk1NControl(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCarHk1NControl[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
