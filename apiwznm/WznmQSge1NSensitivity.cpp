/**
	* \file WznmQSge1NSensitivity.cpp
	* API code for table TblWznmQSge1NSensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSge1NSensitivity.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSge1NSensitivity
 ******************************************************************************/

WznmQSge1NSensitivity::WznmQSge1NSensitivity(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQSge1NSensitivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSge1NSensitivity");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSge1NSensitivity
 ******************************************************************************/

ListWznmQSge1NSensitivity::ListWznmQSge1NSensitivity() {
};

ListWznmQSge1NSensitivity::ListWznmQSge1NSensitivity(
			const ListWznmQSge1NSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSge1NSensitivity(*(src.nodes[i]));
};

ListWznmQSge1NSensitivity& ListWznmQSge1NSensitivity::operator=(
			const ListWznmQSge1NSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSge1NSensitivity(*(src.nodes[i]));

	return *this;
};

ListWznmQSge1NSensitivity::~ListWznmQSge1NSensitivity() {
	clear();
};

void ListWznmQSge1NSensitivity::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSge1NSensitivity::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSge1NSensitivity* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSge1NSensitivity");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSge1NSensitivity", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSge1NSensitivity(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSge1NSensitivity[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
