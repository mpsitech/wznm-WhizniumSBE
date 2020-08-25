/**
	* \file WznmQCmpMNLibrary.cpp
	* API code for table TblWznmQCmpMNLibrary (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQCmpMNLibrary.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCmpMNLibrary
 ******************************************************************************/

WznmQCmpMNLibrary::WznmQCmpMNLibrary(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool WznmQCmpMNLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCmpMNLibrary");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCmpMNLibrary
 ******************************************************************************/

ListWznmQCmpMNLibrary::ListWznmQCmpMNLibrary() {
};

ListWznmQCmpMNLibrary::ListWznmQCmpMNLibrary(
			const ListWznmQCmpMNLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCmpMNLibrary(*(src.nodes[i]));
};

ListWznmQCmpMNLibrary& ListWznmQCmpMNLibrary::operator=(
			const ListWznmQCmpMNLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCmpMNLibrary(*(src.nodes[i]));

	return *this;
};

ListWznmQCmpMNLibrary::~ListWznmQCmpMNLibrary() {
	clear();
};

void ListWznmQCmpMNLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCmpMNLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCmpMNLibrary* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCmpMNLibrary");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCmpMNLibrary", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCmpMNLibrary(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCmpMNLibrary[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

