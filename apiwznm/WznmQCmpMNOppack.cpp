/**
	* \file WznmQCmpMNOppack.cpp
	* API code for table TblWznmQCmpMNOppack (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQCmpMNOppack.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCmpMNOppack
 ******************************************************************************/

WznmQCmpMNOppack::WznmQCmpMNOppack(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool WznmQCmpMNOppack::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCmpMNOppack");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCmpMNOppack
 ******************************************************************************/

ListWznmQCmpMNOppack::ListWznmQCmpMNOppack() {
};

ListWznmQCmpMNOppack::ListWznmQCmpMNOppack(
			const ListWznmQCmpMNOppack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCmpMNOppack(*(src.nodes[i]));
};

ListWznmQCmpMNOppack& ListWznmQCmpMNOppack::operator=(
			const ListWznmQCmpMNOppack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCmpMNOppack(*(src.nodes[i]));

	return *this;
};

ListWznmQCmpMNOppack::~ListWznmQCmpMNOppack() {
	clear();
};

void ListWznmQCmpMNOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCmpMNOppack::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCmpMNOppack* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCmpMNOppack");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCmpMNOppack", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCmpMNOppack(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCmpMNOppack[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

