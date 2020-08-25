/**
	* \file WznmQRtj1NRtdpch.cpp
	* API code for table TblWznmQRtj1NRtdpch (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQRtj1NRtdpch.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRtj1NRtdpch
 ******************************************************************************/

WznmQRtj1NRtdpch::WznmQRtj1NRtdpch(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQRtj1NRtdpch::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRtj1NRtdpch");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRtj1NRtdpch
 ******************************************************************************/

ListWznmQRtj1NRtdpch::ListWznmQRtj1NRtdpch() {
};

ListWznmQRtj1NRtdpch::ListWznmQRtj1NRtdpch(
			const ListWznmQRtj1NRtdpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtj1NRtdpch(*(src.nodes[i]));
};

ListWznmQRtj1NRtdpch& ListWznmQRtj1NRtdpch::operator=(
			const ListWznmQRtj1NRtdpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtj1NRtdpch(*(src.nodes[i]));

	return *this;
};

ListWznmQRtj1NRtdpch::~ListWznmQRtj1NRtdpch() {
	clear();
};

void ListWznmQRtj1NRtdpch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRtj1NRtdpch::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRtj1NRtdpch* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRtj1NRtdpch");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRtj1NRtdpch", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRtj1NRtdpch(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRtj1NRtdpch[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

