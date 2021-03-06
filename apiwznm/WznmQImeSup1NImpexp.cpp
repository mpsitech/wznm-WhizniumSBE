/**
	* \file WznmQImeSup1NImpexp.cpp
	* API code for table TblWznmQImeSup1NImpexp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQImeSup1NImpexp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeSup1NImpexp
 ******************************************************************************/

WznmQImeSup1NImpexp::WznmQImeSup1NImpexp(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQImeSup1NImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQImeSup1NImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQImeSup1NImpexp
 ******************************************************************************/

ListWznmQImeSup1NImpexp::ListWznmQImeSup1NImpexp() {
};

ListWznmQImeSup1NImpexp::ListWznmQImeSup1NImpexp(
			const ListWznmQImeSup1NImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeSup1NImpexp(*(src.nodes[i]));
};

ListWznmQImeSup1NImpexp& ListWznmQImeSup1NImpexp::operator=(
			const ListWznmQImeSup1NImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeSup1NImpexp(*(src.nodes[i]));

	return *this;
};

ListWznmQImeSup1NImpexp::~ListWznmQImeSup1NImpexp() {
	clear();
};

void ListWznmQImeSup1NImpexp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQImeSup1NImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQImeSup1NImpexp* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQImeSup1NImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQImeSup1NImpexp", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQImeSup1NImpexp(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQImeSup1NImpexp[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
