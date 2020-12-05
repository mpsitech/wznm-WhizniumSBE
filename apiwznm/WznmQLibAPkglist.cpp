/**
	* \file WznmQLibAPkglist.cpp
	* API code for table TblWznmQLibAPkglist (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQLibAPkglist.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQLibAPkglist
 ******************************************************************************/

WznmQLibAPkglist::WznmQLibAPkglist(
			const uint jnum
			, const string stubX1RefWznmMMachine
			, const string Pkglist
		) {
	this->jnum = jnum;
	this->stubX1RefWznmMMachine = stubX1RefWznmMMachine;
	this->Pkglist = Pkglist;
};

bool WznmQLibAPkglist::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQLibAPkglist");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubX1RefWznmMMachine", "mch", stubX1RefWznmMMachine);
		extractStringUclc(docctx, basexpath, "Pkglist", "pkl", Pkglist);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQLibAPkglist
 ******************************************************************************/

ListWznmQLibAPkglist::ListWznmQLibAPkglist() {
};

ListWznmQLibAPkglist::ListWznmQLibAPkglist(
			const ListWznmQLibAPkglist& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAPkglist(*(src.nodes[i]));
};

ListWznmQLibAPkglist& ListWznmQLibAPkglist::operator=(
			const ListWznmQLibAPkglist& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAPkglist(*(src.nodes[i]));

	return *this;
};

ListWznmQLibAPkglist::~ListWznmQLibAPkglist() {
	clear();
};

void ListWznmQLibAPkglist::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQLibAPkglist::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQLibAPkglist* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQLibAPkglist");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQLibAPkglist", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQLibAPkglist(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQLibAPkglist[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

