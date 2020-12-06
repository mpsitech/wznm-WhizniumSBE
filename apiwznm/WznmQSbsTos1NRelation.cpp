/**
	* \file WznmQSbsTos1NRelation.cpp
	* API code for table TblWznmQSbsTos1NRelation (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSbsTos1NRelation.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsTos1NRelation
 ******************************************************************************/

WznmQSbsTos1NRelation::WznmQSbsTos1NRelation(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQSbsTos1NRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSbsTos1NRelation");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSbsTos1NRelation
 ******************************************************************************/

ListWznmQSbsTos1NRelation::ListWznmQSbsTos1NRelation() {
};

ListWznmQSbsTos1NRelation::ListWznmQSbsTos1NRelation(
			const ListWznmQSbsTos1NRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsTos1NRelation(*(src.nodes[i]));
};

ListWznmQSbsTos1NRelation& ListWznmQSbsTos1NRelation::operator=(
			const ListWznmQSbsTos1NRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsTos1NRelation(*(src.nodes[i]));

	return *this;
};

ListWznmQSbsTos1NRelation::~ListWznmQSbsTos1NRelation() {
	clear();
};

void ListWznmQSbsTos1NRelation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSbsTos1NRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSbsTos1NRelation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSbsTos1NRelation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSbsTos1NRelation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSbsTos1NRelation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSbsTos1NRelation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
