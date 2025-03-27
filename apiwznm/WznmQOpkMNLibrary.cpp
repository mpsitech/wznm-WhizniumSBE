/**
	* \file WznmQOpkMNLibrary.cpp
	* API code for table TblWznmQOpkMNLibrary (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpkMNLibrary.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpkMNLibrary
 ******************************************************************************/

WznmQOpkMNLibrary::WznmQOpkMNLibrary(
			const uint jnum
			, const string stubMref
		) :
			jnum(jnum)
			, stubMref(stubMref)
		{
};

bool WznmQOpkMNLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpkMNLibrary");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQOpkMNLibrary
 ******************************************************************************/

ListWznmQOpkMNLibrary::ListWznmQOpkMNLibrary() {
};

ListWznmQOpkMNLibrary::ListWznmQOpkMNLibrary(
			const ListWznmQOpkMNLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkMNLibrary(*(src.nodes[i]));
};

ListWznmQOpkMNLibrary& ListWznmQOpkMNLibrary::operator=(
			const ListWznmQOpkMNLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkMNLibrary(*(src.nodes[i]));

	return *this;
};

ListWznmQOpkMNLibrary::~ListWznmQOpkMNLibrary() {
	clear();
};

void ListWznmQOpkMNLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpkMNLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpkMNLibrary* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpkMNLibrary");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpkMNLibrary", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpkMNLibrary(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpkMNLibrary[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
