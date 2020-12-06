/**
	* \file WznmQRtj1NRtblock.cpp
	* API code for table TblWznmQRtj1NRtblock (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRtj1NRtblock.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRtj1NRtblock
 ******************************************************************************/

WznmQRtj1NRtblock::WznmQRtj1NRtblock(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQRtj1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRtj1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRtj1NRtblock
 ******************************************************************************/

ListWznmQRtj1NRtblock::ListWznmQRtj1NRtblock() {
};

ListWznmQRtj1NRtblock::ListWznmQRtj1NRtblock(
			const ListWznmQRtj1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtj1NRtblock(*(src.nodes[i]));
};

ListWznmQRtj1NRtblock& ListWznmQRtj1NRtblock::operator=(
			const ListWznmQRtj1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtj1NRtblock(*(src.nodes[i]));

	return *this;
};

ListWznmQRtj1NRtblock::~ListWznmQRtj1NRtblock() {
	clear();
};

void ListWznmQRtj1NRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRtj1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRtj1NRtblock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRtj1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRtj1NRtblock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRtj1NRtblock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRtj1NRtblock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
