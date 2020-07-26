/**
	* \file WznmQMdlList.cpp
	* API code for table TblWznmQMdlList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQMdlList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMdlList
 ******************************************************************************/

WznmQMdlList::WznmQMdlList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubVerRefWznmMVersion
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubVerRefWznmMVersion = stubVerRefWznmMVersion;
};

bool WznmQMdlList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMdlList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubVerRefWznmMVersion", "ver", stubVerRefWznmMVersion);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMdlList
 ******************************************************************************/

ListWznmQMdlList::ListWznmQMdlList() {
};

ListWznmQMdlList::ListWznmQMdlList(
			const ListWznmQMdlList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMdlList(*(src.nodes[i]));
};

ListWznmQMdlList& ListWznmQMdlList::operator=(
			const ListWznmQMdlList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMdlList(*(src.nodes[i]));

	return *this;
};

ListWznmQMdlList::~ListWznmQMdlList() {
	clear();
};

void ListWznmQMdlList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMdlList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMdlList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMdlList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMdlList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMdlList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMdlList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

