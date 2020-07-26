/**
	* \file WznmQBlk1NRtdpch.cpp
	* API code for table TblWznmQBlk1NRtdpch (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQBlk1NRtdpch.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBlk1NRtdpch
 ******************************************************************************/

WznmQBlk1NRtdpch::WznmQBlk1NRtdpch(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQBlk1NRtdpch::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQBlk1NRtdpch");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQBlk1NRtdpch
 ******************************************************************************/

ListWznmQBlk1NRtdpch::ListWznmQBlk1NRtdpch() {
};

ListWznmQBlk1NRtdpch::ListWznmQBlk1NRtdpch(
			const ListWznmQBlk1NRtdpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlk1NRtdpch(*(src.nodes[i]));
};

ListWznmQBlk1NRtdpch& ListWznmQBlk1NRtdpch::operator=(
			const ListWznmQBlk1NRtdpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlk1NRtdpch(*(src.nodes[i]));

	return *this;
};

ListWznmQBlk1NRtdpch::~ListWznmQBlk1NRtdpch() {
	clear();
};

void ListWznmQBlk1NRtdpch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQBlk1NRtdpch::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQBlk1NRtdpch* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQBlk1NRtdpch");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQBlk1NRtdpch", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQBlk1NRtdpch(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQBlk1NRtdpch[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

