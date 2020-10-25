/**
	* \file WznmQUsgList.cpp
	* API code for table TblWznmQUsgList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQUsgList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsgList
 ******************************************************************************/

WznmQUsgList::WznmQUsgList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string sref
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->sref = sref;
};

bool WznmQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQUsgList
 ******************************************************************************/

ListWznmQUsgList::ListWznmQUsgList() {
};

ListWznmQUsgList::ListWznmQUsgList(
			const ListWznmQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsgList(*(src.nodes[i]));
};

ListWznmQUsgList& ListWznmQUsgList::operator=(
			const ListWznmQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsgList(*(src.nodes[i]));

	return *this;
};

ListWznmQUsgList::~ListWznmQUsgList() {
	clear();
};

void ListWznmQUsgList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQUsgList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQUsgList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQUsgList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQUsgList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

