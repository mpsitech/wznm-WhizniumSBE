/**
	* \file WznmQImeList.cpp
	* API code for table TblWznmQImeList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQImeList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeList
 ******************************************************************************/

WznmQImeList::WznmQImeList(
			const uint jnum
			, const string sref
			, const string stubRefWznmMImpexpcplx
			, const string stubSupRefWznmMImpexp
			, const string stubRefWznmMTable
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWznmMImpexpcplx = stubRefWznmMImpexpcplx;
	this->stubSupRefWznmMImpexp = stubSupRefWznmMImpexp;
	this->stubRefWznmMTable = stubRefWznmMTable;
};

bool WznmQImeList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQImeList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMImpexpcplx", "iex", stubRefWznmMImpexpcplx);
		extractStringUclc(docctx, basexpath, "stubSupRefWznmMImpexp", "sup", stubSupRefWznmMImpexp);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTable", "tbl", stubRefWznmMTable);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQImeList
 ******************************************************************************/

ListWznmQImeList::ListWznmQImeList() {
};

ListWznmQImeList::ListWznmQImeList(
			const ListWznmQImeList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeList(*(src.nodes[i]));
};

ListWznmQImeList& ListWznmQImeList::operator=(
			const ListWznmQImeList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeList(*(src.nodes[i]));

	return *this;
};

ListWznmQImeList::~ListWznmQImeList() {
	clear();
};

void ListWznmQImeList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQImeList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQImeList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQImeList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQImeList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQImeList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQImeList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

