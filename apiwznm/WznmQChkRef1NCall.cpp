/**
	* \file WznmQChkRef1NCall.cpp
	* API code for table TblWznmQChkRef1NCall (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQChkRef1NCall.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQChkRef1NCall
 ******************************************************************************/

WznmQChkRef1NCall::WznmQChkRef1NCall(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQChkRef1NCall::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQChkRef1NCall");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQChkRef1NCall
 ******************************************************************************/

ListWznmQChkRef1NCall::ListWznmQChkRef1NCall() {
};

ListWznmQChkRef1NCall::ListWznmQChkRef1NCall(
			const ListWznmQChkRef1NCall& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQChkRef1NCall(*(src.nodes[i]));
};

ListWznmQChkRef1NCall& ListWznmQChkRef1NCall::operator=(
			const ListWznmQChkRef1NCall& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQChkRef1NCall(*(src.nodes[i]));

	return *this;
};

ListWznmQChkRef1NCall::~ListWznmQChkRef1NCall() {
	clear();
};

void ListWznmQChkRef1NCall::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQChkRef1NCall::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQChkRef1NCall* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQChkRef1NCall");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQChkRef1NCall", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQChkRef1NCall(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQChkRef1NCall[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
