/**
	* \file WznmQSbsFrs1NRelation.cpp
	* API code for table TblWznmQSbsFrs1NRelation (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSbsFrs1NRelation.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsFrs1NRelation
 ******************************************************************************/

WznmQSbsFrs1NRelation::WznmQSbsFrs1NRelation(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQSbsFrs1NRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSbsFrs1NRelation");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSbsFrs1NRelation
 ******************************************************************************/

ListWznmQSbsFrs1NRelation::ListWznmQSbsFrs1NRelation() {
};

ListWznmQSbsFrs1NRelation::ListWznmQSbsFrs1NRelation(
			const ListWznmQSbsFrs1NRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsFrs1NRelation(*(src.nodes[i]));
};

ListWznmQSbsFrs1NRelation& ListWznmQSbsFrs1NRelation::operator=(
			const ListWznmQSbsFrs1NRelation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsFrs1NRelation(*(src.nodes[i]));

	return *this;
};

ListWznmQSbsFrs1NRelation::~ListWznmQSbsFrs1NRelation() {
	clear();
};

void ListWznmQSbsFrs1NRelation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSbsFrs1NRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSbsFrs1NRelation* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSbsFrs1NRelation");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSbsFrs1NRelation", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSbsFrs1NRelation(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSbsFrs1NRelation[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

