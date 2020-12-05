/**
	* \file WznmQVitList.cpp
	* API code for table TblWznmQVitList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVitList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVitList
 ******************************************************************************/

WznmQVitList::WznmQVitList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubVecRefWznmMVector
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubVecRefWznmMVector = stubVecRefWznmMVector;
};

bool WznmQVitList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVitList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubVecRefWznmMVector", "vec", stubVecRefWznmMVector);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVitList
 ******************************************************************************/

ListWznmQVitList::ListWznmQVitList() {
};

ListWznmQVitList::ListWznmQVitList(
			const ListWznmQVitList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVitList(*(src.nodes[i]));
};

ListWznmQVitList& ListWznmQVitList::operator=(
			const ListWznmQVitList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVitList(*(src.nodes[i]));

	return *this;
};

ListWznmQVitList::~ListWznmQVitList() {
	clear();
};

void ListWznmQVitList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVitList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVitList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVitList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVitList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVitList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVitList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

