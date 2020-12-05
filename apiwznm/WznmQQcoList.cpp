/**
	* \file WznmQQcoList.cpp
	* API code for table TblWznmQQcoList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQcoList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQcoList
 ******************************************************************************/

WznmQQcoList::WznmQQcoList(
			const uint jnum
			, const string sref
			, const string Short
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubQryRefWznmMQuery
			, const string stubRefWznmMTablecol
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Short = Short;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubQryRefWznmMQuery = stubQryRefWznmMQuery;
	this->stubRefWznmMTablecol = stubRefWznmMTablecol;
};

bool WznmQQcoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQcoList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubQryRefWznmMQuery", "qry", stubQryRefWznmMQuery);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTablecol", "tco", stubRefWznmMTablecol);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQcoList
 ******************************************************************************/

ListWznmQQcoList::ListWznmQQcoList() {
};

ListWznmQQcoList::ListWznmQQcoList(
			const ListWznmQQcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQcoList(*(src.nodes[i]));
};

ListWznmQQcoList& ListWznmQQcoList::operator=(
			const ListWznmQQcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQcoList(*(src.nodes[i]));

	return *this;
};

ListWznmQQcoList::~ListWznmQQcoList() {
	clear();
};

void ListWznmQQcoList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQcoList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQcoList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQcoList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQcoList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQcoList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQcoList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

