/**
	* \file WznmQLibList.cpp
	* API code for table TblWznmQLibList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQLibList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQLibList
 ******************************************************************************/

WznmQLibList::WznmQLibList(
			const uint jnum
			, const string sref
			, const string Title
			, const string Version
			, const string srefKLictype
			, const string titSrefKLictype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->Version = Version;
	this->srefKLictype = srefKLictype;
	this->titSrefKLictype = titSrefKLictype;
};

bool WznmQLibList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQLibList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Version", "ver", Version);
		extractStringUclc(docctx, basexpath, "srefKLictype", "lty", srefKLictype);
		extractStringUclc(docctx, basexpath, "titSrefKLictype", "lty2", titSrefKLictype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQLibList
 ******************************************************************************/

ListWznmQLibList::ListWznmQLibList() {
};

ListWznmQLibList::ListWznmQLibList(
			const ListWznmQLibList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibList(*(src.nodes[i]));
};

ListWznmQLibList& ListWznmQLibList::operator=(
			const ListWznmQLibList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibList(*(src.nodes[i]));

	return *this;
};

ListWznmQLibList::~ListWznmQLibList() {
	clear();
};

void ListWznmQLibList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQLibList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQLibList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQLibList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQLibList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQLibList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQLibList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

