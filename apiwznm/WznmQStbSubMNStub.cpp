/**
	* \file WznmQStbSubMNStub.cpp
	* API code for table TblWznmQStbSubMNStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQStbSubMNStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQStbSubMNStub
 ******************************************************************************/

WznmQStbSubMNStub::WznmQStbSubMNStub(
			const uint jnum
			, const string stubMref
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
};

bool WznmQStbSubMNStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQStbSubMNStub");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQStbSubMNStub
 ******************************************************************************/

ListWznmQStbSubMNStub::ListWznmQStbSubMNStub() {
};

ListWznmQStbSubMNStub::ListWznmQStbSubMNStub(
			const ListWznmQStbSubMNStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQStbSubMNStub(*(src.nodes[i]));
};

ListWznmQStbSubMNStub& ListWznmQStbSubMNStub::operator=(
			const ListWznmQStbSubMNStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQStbSubMNStub(*(src.nodes[i]));

	return *this;
};

ListWznmQStbSubMNStub::~ListWznmQStbSubMNStub() {
	clear();
};

void ListWznmQStbSubMNStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQStbSubMNStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQStbSubMNStub* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQStbSubMNStub");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQStbSubMNStub", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQStbSubMNStub(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQStbSubMNStub[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
