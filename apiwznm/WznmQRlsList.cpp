/**
	* \file WznmQRlsList.cpp
	* API code for table TblWznmQRlsList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRlsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRlsList
 ******************************************************************************/

WznmQRlsList::WznmQRlsList(
			const uint jnum
			, const string sref
			, const string stubRefWznmMComponent
			, const string stubRefWznmMMachine
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWznmMComponent = stubRefWznmMComponent;
	this->stubRefWznmMMachine = stubRefWznmMMachine;
};

bool WznmQRlsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRlsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMComponent", "cmp", stubRefWznmMComponent);
		extractStringUclc(docctx, basexpath, "stubRefWznmMMachine", "mch", stubRefWznmMMachine);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRlsList
 ******************************************************************************/

ListWznmQRlsList::ListWznmQRlsList() {
};

ListWznmQRlsList::ListWznmQRlsList(
			const ListWznmQRlsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRlsList(*(src.nodes[i]));
};

ListWznmQRlsList& ListWznmQRlsList::operator=(
			const ListWznmQRlsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRlsList(*(src.nodes[i]));

	return *this;
};

ListWznmQRlsList::~ListWznmQRlsList() {
	clear();
};

void ListWznmQRlsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRlsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRlsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRlsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRlsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRlsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRlsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
