/**
	* \file WznmQImeHk1NVector.cpp
	* API code for table TblWznmQImeHk1NVector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQImeHk1NVector.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeHk1NVector
 ******************************************************************************/

WznmQImeHk1NVector::WznmQImeHk1NVector(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQImeHk1NVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQImeHk1NVector");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQImeHk1NVector
 ******************************************************************************/

ListWznmQImeHk1NVector::ListWznmQImeHk1NVector() {
};

ListWznmQImeHk1NVector::ListWznmQImeHk1NVector(
			const ListWznmQImeHk1NVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeHk1NVector(*(src.nodes[i]));
};

ListWznmQImeHk1NVector& ListWznmQImeHk1NVector::operator=(
			const ListWznmQImeHk1NVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeHk1NVector(*(src.nodes[i]));

	return *this;
};

ListWznmQImeHk1NVector::~ListWznmQImeHk1NVector() {
	clear();
};

void ListWznmQImeHk1NVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQImeHk1NVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQImeHk1NVector* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQImeHk1NVector");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQImeHk1NVector", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQImeHk1NVector(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQImeHk1NVector[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
