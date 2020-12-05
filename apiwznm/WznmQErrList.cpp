/**
	* \file WznmQErrList.cpp
	* API code for table TblWznmQErrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQErrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQErrList
 ******************************************************************************/

WznmQErrList::WznmQErrList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubVerRefWznmMVersion
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubVerRefWznmMVersion = stubVerRefWznmMVersion;
};

bool WznmQErrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQErrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubVerRefWznmMVersion", "ver", stubVerRefWznmMVersion);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQErrList
 ******************************************************************************/

ListWznmQErrList::ListWznmQErrList() {
};

ListWznmQErrList::ListWznmQErrList(
			const ListWznmQErrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQErrList(*(src.nodes[i]));
};

ListWznmQErrList& ListWznmQErrList::operator=(
			const ListWznmQErrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQErrList(*(src.nodes[i]));

	return *this;
};

ListWznmQErrList::~ListWznmQErrList() {
	clear();
};

void ListWznmQErrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQErrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQErrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQErrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQErrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQErrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQErrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

