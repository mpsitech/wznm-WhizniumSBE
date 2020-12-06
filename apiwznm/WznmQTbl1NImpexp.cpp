/**
	* \file WznmQTbl1NImpexp.cpp
	* API code for table TblWznmQTbl1NImpexp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTbl1NImpexp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTbl1NImpexp
 ******************************************************************************/

WznmQTbl1NImpexp::WznmQTbl1NImpexp(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQTbl1NImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTbl1NImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTbl1NImpexp
 ******************************************************************************/

ListWznmQTbl1NImpexp::ListWznmQTbl1NImpexp() {
};

ListWznmQTbl1NImpexp::ListWznmQTbl1NImpexp(
			const ListWznmQTbl1NImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTbl1NImpexp(*(src.nodes[i]));
};

ListWznmQTbl1NImpexp& ListWznmQTbl1NImpexp::operator=(
			const ListWznmQTbl1NImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTbl1NImpexp(*(src.nodes[i]));

	return *this;
};

ListWznmQTbl1NImpexp::~ListWznmQTbl1NImpexp() {
	clear();
};

void ListWznmQTbl1NImpexp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTbl1NImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTbl1NImpexp* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTbl1NImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTbl1NImpexp", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTbl1NImpexp(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTbl1NImpexp[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
