/**
	* \file WznmQCmp1NRelease.cpp
	* API code for table TblWznmQCmp1NRelease (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQCmp1NRelease.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCmp1NRelease
 ******************************************************************************/

WznmQCmp1NRelease::WznmQCmp1NRelease(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQCmp1NRelease::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCmp1NRelease");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCmp1NRelease
 ******************************************************************************/

ListWznmQCmp1NRelease::ListWznmQCmp1NRelease() {
};

ListWznmQCmp1NRelease::ListWznmQCmp1NRelease(
			const ListWznmQCmp1NRelease& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCmp1NRelease(*(src.nodes[i]));
};

ListWznmQCmp1NRelease& ListWznmQCmp1NRelease::operator=(
			const ListWznmQCmp1NRelease& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCmp1NRelease(*(src.nodes[i]));

	return *this;
};

ListWznmQCmp1NRelease::~ListWznmQCmp1NRelease() {
	clear();
};

void ListWznmQCmp1NRelease::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCmp1NRelease::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCmp1NRelease* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCmp1NRelease");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCmp1NRelease", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCmp1NRelease(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCmp1NRelease[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

