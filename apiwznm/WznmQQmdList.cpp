/**
	* \file WznmQQmdList.cpp
	* API code for table TblWznmQQmdList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQmdList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQmdList
 ******************************************************************************/

WznmQQmdList::WznmQQmdList(
			const uint jnum
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubQryRefWznmMQuery
			, const string stubRefWznmMPreset
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
		) {
	this->jnum = jnum;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubQryRefWznmMQuery = stubQryRefWznmMQuery;
	this->stubRefWznmMPreset = stubRefWznmMPreset;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
};

bool WznmQQmdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQmdList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubQryRefWznmMQuery", "qry", stubQryRefWznmMQuery);
		extractStringUclc(docctx, basexpath, "stubRefWznmMPreset", "pst", stubRefWznmMPreset);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQmdList
 ******************************************************************************/

ListWznmQQmdList::ListWznmQQmdList() {
};

ListWznmQQmdList::ListWznmQQmdList(
			const ListWznmQQmdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQmdList(*(src.nodes[i]));
};

ListWznmQQmdList& ListWznmQQmdList::operator=(
			const ListWznmQQmdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQmdList(*(src.nodes[i]));

	return *this;
};

ListWznmQQmdList::~ListWznmQQmdList() {
	clear();
};

void ListWznmQQmdList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQmdList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQmdList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQmdList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQmdList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQmdList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQmdList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

