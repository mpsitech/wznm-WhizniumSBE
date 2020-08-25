/**
	* \file WznmQConFedRef1NRtblock.cpp
	* API code for table TblWznmQConFedRef1NRtblock (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQConFedRef1NRtblock.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQConFedRef1NRtblock
 ******************************************************************************/

WznmQConFedRef1NRtblock::WznmQConFedRef1NRtblock(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQConFedRef1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQConFedRef1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQConFedRef1NRtblock
 ******************************************************************************/

ListWznmQConFedRef1NRtblock::ListWznmQConFedRef1NRtblock() {
};

ListWznmQConFedRef1NRtblock::ListWznmQConFedRef1NRtblock(
			const ListWznmQConFedRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConFedRef1NRtblock(*(src.nodes[i]));
};

ListWznmQConFedRef1NRtblock& ListWznmQConFedRef1NRtblock::operator=(
			const ListWznmQConFedRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConFedRef1NRtblock(*(src.nodes[i]));

	return *this;
};

ListWznmQConFedRef1NRtblock::~ListWznmQConFedRef1NRtblock() {
	clear();
};

void ListWznmQConFedRef1NRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQConFedRef1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQConFedRef1NRtblock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQConFedRef1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQConFedRef1NRtblock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQConFedRef1NRtblock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQConFedRef1NRtblock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

