/**
	* \file WznmQSteList.cpp
	* API code for table TblWznmQSteList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQSteList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSteList
 ******************************************************************************/

WznmQSteList::WznmQSteList(
			const uint jnum
			, const string sref
			, const string stubSeqRefWznmMSequence
		) :
			jnum(jnum)
			, sref(sref)
			, stubSeqRefWznmMSequence(stubSeqRefWznmMSequence)
		{
};

bool WznmQSteList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSteList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubSeqRefWznmMSequence", "seq", stubSeqRefWznmMSequence);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSteList
 ******************************************************************************/

ListWznmQSteList::ListWznmQSteList() {
};

ListWznmQSteList::ListWznmQSteList(
			const ListWznmQSteList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteList(*(src.nodes[i]));
};

ListWznmQSteList& ListWznmQSteList::operator=(
			const ListWznmQSteList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSteList(*(src.nodes[i]));

	return *this;
};

ListWznmQSteList::~ListWznmQSteList() {
	clear();
};

void ListWznmQSteList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSteList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSteList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSteList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSteList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSteList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSteList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
