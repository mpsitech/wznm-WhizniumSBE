/**
	* \file WznmQSeqSeq1NState.cpp
	* API code for table TblWznmQSeqSeq1NState (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSeqSeq1NState.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSeqSeq1NState
 ******************************************************************************/

WznmQSeqSeq1NState::WznmQSeqSeq1NState(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQSeqSeq1NState::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSeqSeq1NState");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSeqSeq1NState
 ******************************************************************************/

ListWznmQSeqSeq1NState::ListWznmQSeqSeq1NState() {
};

ListWznmQSeqSeq1NState::ListWznmQSeqSeq1NState(
			const ListWznmQSeqSeq1NState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSeqSeq1NState(*(src.nodes[i]));
};

ListWznmQSeqSeq1NState& ListWznmQSeqSeq1NState::operator=(
			const ListWznmQSeqSeq1NState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSeqSeq1NState(*(src.nodes[i]));

	return *this;
};

ListWznmQSeqSeq1NState::~ListWznmQSeqSeq1NState() {
	clear();
};

void ListWznmQSeqSeq1NState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSeqSeq1NState::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSeqSeq1NState* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSeqSeq1NState");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSeqSeq1NState", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSeqSeq1NState(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSeqSeq1NState[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
