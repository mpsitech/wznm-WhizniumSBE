/**
	* \file WznmQBlkRef1NRtblock.cpp
	* API code for table TblWznmQBlkRef1NRtblock (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQBlkRef1NRtblock.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBlkRef1NRtblock
 ******************************************************************************/

WznmQBlkRef1NRtblock::WznmQBlkRef1NRtblock(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQBlkRef1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQBlkRef1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQBlkRef1NRtblock
 ******************************************************************************/

ListWznmQBlkRef1NRtblock::ListWznmQBlkRef1NRtblock() {
};

ListWznmQBlkRef1NRtblock::ListWznmQBlkRef1NRtblock(
			const ListWznmQBlkRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlkRef1NRtblock(*(src.nodes[i]));
};

ListWznmQBlkRef1NRtblock& ListWznmQBlkRef1NRtblock::operator=(
			const ListWznmQBlkRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlkRef1NRtblock(*(src.nodes[i]));

	return *this;
};

ListWznmQBlkRef1NRtblock::~ListWznmQBlkRef1NRtblock() {
	clear();
};

void ListWznmQBlkRef1NRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQBlkRef1NRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQBlkRef1NRtblock* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQBlkRef1NRtblock");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQBlkRef1NRtblock", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQBlkRef1NRtblock(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQBlkRef1NRtblock[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
