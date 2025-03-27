/**
	* \file WznmQChkList.cpp
	* API code for table TblWznmQChkList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQChkList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQChkList
 ******************************************************************************/

WznmQChkList::WznmQChkList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWznmMTable
			, const string stubRefWznmMTablecol
		) :
			jnum(jnum)
			, sref(sref)
			, srefIxVBasetype(srefIxVBasetype)
			, titIxVBasetype(titIxVBasetype)
			, stubRefWznmMTable(stubRefWznmMTable)
			, stubRefWznmMTablecol(stubRefWznmMTablecol)
		{
};

bool WznmQChkList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQChkList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTable", "tbl", stubRefWznmMTable);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTablecol", "tco", stubRefWznmMTablecol);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQChkList
 ******************************************************************************/

ListWznmQChkList::ListWznmQChkList() {
};

ListWznmQChkList::ListWznmQChkList(
			const ListWznmQChkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQChkList(*(src.nodes[i]));
};

ListWznmQChkList& ListWznmQChkList::operator=(
			const ListWznmQChkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQChkList(*(src.nodes[i]));

	return *this;
};

ListWznmQChkList::~ListWznmQChkList() {
	clear();
};

void ListWznmQChkList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQChkList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQChkList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQChkList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQChkList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQChkList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQChkList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
