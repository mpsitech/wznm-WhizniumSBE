/**
	* \file WznmQBoxList.cpp
	* API code for table TblWznmQBoxList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQBoxList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBoxList
 ******************************************************************************/

WznmQBoxList::WznmQBoxList(
			const uint jnum
			, const string stubRefWznmMSheet
			, const string srefUnvIxWznmVMaintable
			, const string titUnvIxWznmVMaintable
			, const string stubUnvUref
		) :
			jnum(jnum)
			, stubRefWznmMSheet(stubRefWznmMSheet)
			, srefUnvIxWznmVMaintable(srefUnvIxWznmVMaintable)
			, titUnvIxWznmVMaintable(titUnvIxWznmVMaintable)
			, stubUnvUref(stubUnvUref)
		{
};

bool WznmQBoxList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQBoxList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWznmMSheet", "sht", stubRefWznmMSheet);
		extractStringUclc(docctx, basexpath, "srefUnvIxWznmVMaintable", "mtb", srefUnvIxWznmVMaintable);
		extractStringUclc(docctx, basexpath, "titUnvIxWznmVMaintable", "mtb2", titUnvIxWznmVMaintable);
		extractStringUclc(docctx, basexpath, "stubUnvUref", "unv", stubUnvUref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQBoxList
 ******************************************************************************/

ListWznmQBoxList::ListWznmQBoxList() {
};

ListWznmQBoxList::ListWznmQBoxList(
			const ListWznmQBoxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxList(*(src.nodes[i]));
};

ListWznmQBoxList& ListWznmQBoxList::operator=(
			const ListWznmQBoxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxList(*(src.nodes[i]));

	return *this;
};

ListWznmQBoxList::~ListWznmQBoxList() {
	clear();
};

void ListWznmQBoxList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQBoxList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQBoxList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQBoxList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQBoxList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQBoxList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQBoxList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
