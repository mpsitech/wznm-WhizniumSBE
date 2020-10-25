/**
	* \file WznmQTagList.cpp
	* API code for table TblWznmQTagList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQTagList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTagList
 ******************************************************************************/

WznmQTagList::WznmQTagList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubRefWznmMCapability
			, const string osrefWznmKTaggrp
			, const string titOsrefWznmKTaggrp
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubRefWznmMCapability = stubRefWznmMCapability;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->titOsrefWznmKTaggrp = titOsrefWznmKTaggrp;
};

bool WznmQTagList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQTagList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWznmMCapability", "cpb", stubRefWznmMCapability);
		extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "grp", osrefWznmKTaggrp);
		extractStringUclc(docctx, basexpath, "titOsrefWznmKTaggrp", "grp2", titOsrefWznmKTaggrp);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQTagList
 ******************************************************************************/

ListWznmQTagList::ListWznmQTagList() {
};

ListWznmQTagList::ListWznmQTagList(
			const ListWznmQTagList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTagList(*(src.nodes[i]));
};

ListWznmQTagList& ListWznmQTagList::operator=(
			const ListWznmQTagList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTagList(*(src.nodes[i]));

	return *this;
};

ListWznmQTagList::~ListWznmQTagList() {
	clear();
};

void ListWznmQTagList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQTagList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQTagList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQTagList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQTagList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQTagList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQTagList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

