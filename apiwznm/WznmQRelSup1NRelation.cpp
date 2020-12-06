/**
	* \file WznmQRelSup1NRelation.cpp
	* API code for table TblWznmQRelSup1NRelation (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRelSup1NRelation.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRelSup1NRelation
 ******************************************************************************/

WznmQRelSup1NRelation::WznmQRelSup1NRelation(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQRelSup1NRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRelSup1NRelation");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRelSup1NRelation
 ******************************************************************************/

ListWznmQRelSup1NRelation::ListWznmQRelSup1NRelation() {
};

ListWznmQRelSup1NRelation::ListWznmQRelSup1NRelation(
			const ListWznmQRelSup1NRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelSup1NRelation(*(src.nodes[i]));
};

ListWznmQRelSup1NRelation& ListWznmQRelSup1NRelation::operator=(
			const ListWznmQRelSup1NRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelSup1NRelation(*(src.nodes[i]));

	return *this;
};

ListWznmQRelSup1NRelation::~ListWznmQRelSup1NRelation() {
	clear();
};

void ListWznmQRelSup1NRelation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRelSup1NRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRelSup1NRelation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRelSup1NRelation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRelSup1NRelation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRelSup1NRelation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRelSup1NRelation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
