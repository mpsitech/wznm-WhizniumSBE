/**
	* \file WznmQEvtList.cpp
	* API code for table TblWznmQEvtList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQEvtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQEvtList
 ******************************************************************************/

WznmQEvtList::WznmQEvtList(
			const uint jnum
			, const string sref
			, const string stubRefWznmMApp
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWznmMApp = stubRefWznmMApp;
};

bool WznmQEvtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQEvtList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMApp", "app", stubRefWznmMApp);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQEvtList
 ******************************************************************************/

ListWznmQEvtList::ListWznmQEvtList() {
};

ListWznmQEvtList::ListWznmQEvtList(
			const ListWznmQEvtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQEvtList(*(src.nodes[i]));
};

ListWznmQEvtList& ListWznmQEvtList::operator=(
			const ListWznmQEvtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQEvtList(*(src.nodes[i]));

	return *this;
};

ListWznmQEvtList::~ListWznmQEvtList() {
	clear();
};

void ListWznmQEvtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQEvtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQEvtList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQEvtList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQEvtList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQEvtList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQEvtList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

