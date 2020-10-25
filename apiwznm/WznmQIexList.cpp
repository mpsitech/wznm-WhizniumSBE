/**
	* \file WznmQIexList.cpp
	* API code for table TblWznmQIexList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQIexList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQIexList
 ******************************************************************************/

WznmQIexList::WznmQIexList(
			const uint jnum
			, const string sref
			, const string Short
			, const string Title
			, const string stubRefWznmMVersion
			, const string Minversion
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Short = Short;
	this->Title = Title;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->Minversion = Minversion;
};

bool WznmQIexList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQIexList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "Minversion", "miv", Minversion);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQIexList
 ******************************************************************************/

ListWznmQIexList::ListWznmQIexList() {
};

ListWznmQIexList::ListWznmQIexList(
			const ListWznmQIexList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIexList(*(src.nodes[i]));
};

ListWznmQIexList& ListWznmQIexList::operator=(
			const ListWznmQIexList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIexList(*(src.nodes[i]));

	return *this;
};

ListWznmQIexList::~ListWznmQIexList() {
	clear();
};

void ListWznmQIexList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQIexList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQIexList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQIexList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQIexList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQIexList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQIexList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

