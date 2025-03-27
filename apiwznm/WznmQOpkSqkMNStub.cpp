/**
	* \file WznmQOpkSqkMNStub.cpp
	* API code for table TblWznmQOpkSqkMNStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpkSqkMNStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpkSqkMNStub
 ******************************************************************************/

WznmQOpkSqkMNStub::WznmQOpkSqkMNStub(
			const uint jnum
			, const string stubMref
		) :
			jnum(jnum)
			, stubMref(stubMref)
		{
};

bool WznmQOpkSqkMNStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQOpkSqkMNStub");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQOpkSqkMNStub
 ******************************************************************************/

ListWznmQOpkSqkMNStub::ListWznmQOpkSqkMNStub() {
};

ListWznmQOpkSqkMNStub::ListWznmQOpkSqkMNStub(
			const ListWznmQOpkSqkMNStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkSqkMNStub(*(src.nodes[i]));
};

ListWznmQOpkSqkMNStub& ListWznmQOpkSqkMNStub::operator=(
			const ListWznmQOpkSqkMNStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpkSqkMNStub(*(src.nodes[i]));

	return *this;
};

ListWznmQOpkSqkMNStub::~ListWznmQOpkSqkMNStub() {
	clear();
};

void ListWznmQOpkSqkMNStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQOpkSqkMNStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQOpkSqkMNStub* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQOpkSqkMNStub");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQOpkSqkMNStub", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQOpkSqkMNStub(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQOpkSqkMNStub[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
