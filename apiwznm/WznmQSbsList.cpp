/**
	* \file WznmQSbsList.cpp
	* API code for table TblWznmQSbsList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQSbsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsList
 ******************************************************************************/

WznmQSbsList::WznmQSbsList(
			const uint jnum
			, const string sref
			, const string Short
			, const string stubRefWznmMTable
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Short = Short;
	this->stubRefWznmMTable = stubRefWznmMTable;
};

bool WznmQSbsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQSbsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTable", "tbl", stubRefWznmMTable);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQSbsList
 ******************************************************************************/

ListWznmQSbsList::ListWznmQSbsList() {
};

ListWznmQSbsList::ListWznmQSbsList(
			const ListWznmQSbsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsList(*(src.nodes[i]));
};

ListWznmQSbsList& ListWznmQSbsList::operator=(
			const ListWznmQSbsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsList(*(src.nodes[i]));

	return *this;
};

ListWznmQSbsList::~ListWznmQSbsList() {
	clear();
};

void ListWznmQSbsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQSbsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQSbsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQSbsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQSbsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQSbsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQSbsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

