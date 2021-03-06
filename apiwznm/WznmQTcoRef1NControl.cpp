/**
	* \file WznmQTcoRef1NControl.cpp
	* API code for table TblWznmQTcoRef1NControl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTcoRef1NControl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTcoRef1NControl
 ******************************************************************************/

WznmQTcoRef1NControl::WznmQTcoRef1NControl(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTcoRef1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTcoRef1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTcoRef1NControl
 ******************************************************************************/

ListWznmQTcoRef1NControl::ListWznmQTcoRef1NControl() {
};

ListWznmQTcoRef1NControl::ListWznmQTcoRef1NControl(
			const ListWznmQTcoRef1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoRef1NControl(*(src.nodes[i]));
};

ListWznmQTcoRef1NControl& ListWznmQTcoRef1NControl::operator=(
			const ListWznmQTcoRef1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoRef1NControl(*(src.nodes[i]));

	return *this;
};

ListWznmQTcoRef1NControl::~ListWznmQTcoRef1NControl() {
	clear();
};

void ListWznmQTcoRef1NControl::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTcoRef1NControl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTcoRef1NControl* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTcoRef1NControl");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTcoRef1NControl", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTcoRef1NControl(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTcoRef1NControl[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
