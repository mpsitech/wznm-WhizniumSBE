/**
	* \file WznmQMtyList.cpp
	* API code for table TblWznmQMtyList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQMtyList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMtyList
 ******************************************************************************/

WznmQMtyList::WznmQMtyList(
			const uint jnum
			, const string sref
			, const string srefIxVArch
			, const string titIxVArch
			, const string srefKOs
			, const string titSrefKOs
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVArch = srefIxVArch;
	this->titIxVArch = titIxVArch;
	this->srefKOs = srefKOs;
	this->titSrefKOs = titSrefKOs;
};

bool WznmQMtyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQMtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVArch", "ach", srefIxVArch);
		extractStringUclc(docctx, basexpath, "titIxVArch", "ach2", titIxVArch);
		extractStringUclc(docctx, basexpath, "srefKOs", "os", srefKOs);
		extractStringUclc(docctx, basexpath, "titSrefKOs", "os2", titSrefKOs);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQMtyList
 ******************************************************************************/

ListWznmQMtyList::ListWznmQMtyList() {
};

ListWznmQMtyList::ListWznmQMtyList(
			const ListWznmQMtyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtyList(*(src.nodes[i]));
};

ListWznmQMtyList& ListWznmQMtyList::operator=(
			const ListWznmQMtyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtyList(*(src.nodes[i]));

	return *this;
};

ListWznmQMtyList::~ListWznmQMtyList() {
	clear();
};

void ListWznmQMtyList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQMtyList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQMtyList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQMtyList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQMtyList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQMtyList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQMtyList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

