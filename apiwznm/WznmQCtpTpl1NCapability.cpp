/**
	* \file WznmQCtpTpl1NCapability.cpp
	* API code for table TblWznmQCtpTpl1NCapability (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQCtpTpl1NCapability.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCtpTpl1NCapability
 ******************************************************************************/

WznmQCtpTpl1NCapability::WznmQCtpTpl1NCapability(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQCtpTpl1NCapability::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQCtpTpl1NCapability");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQCtpTpl1NCapability
 ******************************************************************************/

ListWznmQCtpTpl1NCapability::ListWznmQCtpTpl1NCapability() {
};

ListWznmQCtpTpl1NCapability::ListWznmQCtpTpl1NCapability(
			const ListWznmQCtpTpl1NCapability& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpTpl1NCapability(*(src.nodes[i]));
};

ListWznmQCtpTpl1NCapability& ListWznmQCtpTpl1NCapability::operator=(
			const ListWznmQCtpTpl1NCapability& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCtpTpl1NCapability(*(src.nodes[i]));

	return *this;
};

ListWznmQCtpTpl1NCapability::~ListWznmQCtpTpl1NCapability() {
	clear();
};

void ListWznmQCtpTpl1NCapability::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQCtpTpl1NCapability::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQCtpTpl1NCapability* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQCtpTpl1NCapability");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQCtpTpl1NCapability", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQCtpTpl1NCapability(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQCtpTpl1NCapability[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

