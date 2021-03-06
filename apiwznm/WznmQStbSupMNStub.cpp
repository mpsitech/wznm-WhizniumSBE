/**
	* \file WznmQStbSupMNStub.cpp
	* API code for table TblWznmQStbSupMNStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQStbSupMNStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQStbSupMNStub
 ******************************************************************************/

WznmQStbSupMNStub::WznmQStbSupMNStub(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool WznmQStbSupMNStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQStbSupMNStub");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQStbSupMNStub
 ******************************************************************************/

ListWznmQStbSupMNStub::ListWznmQStbSupMNStub() {
};

ListWznmQStbSupMNStub::ListWznmQStbSupMNStub(
			const ListWznmQStbSupMNStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQStbSupMNStub(*(src.nodes[i]));
};

ListWznmQStbSupMNStub& ListWznmQStbSupMNStub::operator=(
			const ListWznmQStbSupMNStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQStbSupMNStub(*(src.nodes[i]));

	return *this;
};

ListWznmQStbSupMNStub::~ListWznmQStbSupMNStub() {
	clear();
};

void ListWznmQStbSupMNStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQStbSupMNStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQStbSupMNStub* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQStbSupMNStub");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQStbSupMNStub", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQStbSupMNStub(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQStbSupMNStub[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
