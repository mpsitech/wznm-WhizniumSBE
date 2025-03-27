/**
	* \file WznmQVerVer1NVisual.cpp
	* API code for table TblWznmQVerVer1NVisual (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVerVer1NVisual.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVerVer1NVisual
 ******************************************************************************/

WznmQVerVer1NVisual::WznmQVerVer1NVisual(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQVerVer1NVisual::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVerVer1NVisual");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVerVer1NVisual
 ******************************************************************************/

ListWznmQVerVer1NVisual::ListWznmQVerVer1NVisual() {
};

ListWznmQVerVer1NVisual::ListWznmQVerVer1NVisual(
			const ListWznmQVerVer1NVisual& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerVer1NVisual(*(src.nodes[i]));
};

ListWznmQVerVer1NVisual& ListWznmQVerVer1NVisual::operator=(
			const ListWznmQVerVer1NVisual& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerVer1NVisual(*(src.nodes[i]));

	return *this;
};

ListWznmQVerVer1NVisual::~ListWznmQVerVer1NVisual() {
	clear();
};

void ListWznmQVerVer1NVisual::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVerVer1NVisual::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVerVer1NVisual* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVerVer1NVisual");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVerVer1NVisual", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVerVer1NVisual(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVerVer1NVisual[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
