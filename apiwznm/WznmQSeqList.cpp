/**
	* \file WznmQSeqList.cpp
	* API code for table TblWznmQSeqList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSeqList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSeqList
 ******************************************************************************/

WznmQSeqList::WznmQSeqList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubAppRefWznmMApp
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubAppRefWznmMApp = stubAppRefWznmMApp;
};

bool WznmQSeqList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSeqList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubAppRefWznmMApp", "app", stubAppRefWznmMApp);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSeqList
 ******************************************************************************/

ListWznmQSeqList::ListWznmQSeqList() {
};

ListWznmQSeqList::ListWznmQSeqList(
			const ListWznmQSeqList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSeqList(*(src.nodes[i]));
};

ListWznmQSeqList& ListWznmQSeqList::operator=(
			const ListWznmQSeqList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSeqList(*(src.nodes[i]));

	return *this;
};

ListWznmQSeqList::~ListWznmQSeqList() {
	clear();
};

void ListWznmQSeqList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSeqList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSeqList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSeqList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSeqList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSeqList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSeqList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
