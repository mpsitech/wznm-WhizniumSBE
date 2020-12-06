/**
	* \file WznmQTco1NImpexpcol.cpp
	* API code for table TblWznmQTco1NImpexpcol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTco1NImpexpcol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTco1NImpexpcol
 ******************************************************************************/

WznmQTco1NImpexpcol::WznmQTco1NImpexpcol(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTco1NImpexpcol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTco1NImpexpcol");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTco1NImpexpcol
 ******************************************************************************/

ListWznmQTco1NImpexpcol::ListWznmQTco1NImpexpcol() {
};

ListWznmQTco1NImpexpcol::ListWznmQTco1NImpexpcol(
			const ListWznmQTco1NImpexpcol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTco1NImpexpcol(*(src.nodes[i]));
};

ListWznmQTco1NImpexpcol& ListWznmQTco1NImpexpcol::operator=(
			const ListWznmQTco1NImpexpcol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTco1NImpexpcol(*(src.nodes[i]));

	return *this;
};

ListWznmQTco1NImpexpcol::~ListWznmQTco1NImpexpcol() {
	clear();
};

void ListWznmQTco1NImpexpcol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTco1NImpexpcol::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTco1NImpexpcol* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTco1NImpexpcol");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTco1NImpexpcol", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTco1NImpexpcol(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTco1NImpexpcol[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
