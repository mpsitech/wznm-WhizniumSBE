/**
	* \file WznmQTblRef1NRtblock.cpp
	* API code for table TblWznmQTblRef1NRtblock (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQTblRef1NRtblock.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblRef1NRtblock
 ******************************************************************************/

WznmQTblRef1NRtblock::WznmQTblRef1NRtblock(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTblRef1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTblRef1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTblRef1NRtblock
 ******************************************************************************/

ListWznmQTblRef1NRtblock::ListWznmQTblRef1NRtblock() {
};

ListWznmQTblRef1NRtblock::ListWznmQTblRef1NRtblock(
			const ListWznmQTblRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblRef1NRtblock(*(src.nodes[i]));
};

ListWznmQTblRef1NRtblock& ListWznmQTblRef1NRtblock::operator=(
			const ListWznmQTblRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblRef1NRtblock(*(src.nodes[i]));

	return *this;
};

ListWznmQTblRef1NRtblock::~ListWznmQTblRef1NRtblock() {
	clear();
};

void ListWznmQTblRef1NRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTblRef1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTblRef1NRtblock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTblRef1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTblRef1NRtblock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTblRef1NRtblock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTblRef1NRtblock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

