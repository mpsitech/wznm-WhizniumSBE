/**
	* \file WznmQQryList.cpp
	* API code for table TblWznmQQryList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQQryList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryList
 ******************************************************************************/

WznmQQryList::WznmQQryList(
			const uint jnum
			, const string sref
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string stubRefWznmMVersion
			, const string stubSupRefWznmMQuery
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const string stubRefWznmMTable
			, const string stubQtbRefWznmMTable
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->stubSupRefWznmMQuery = stubSupRefWznmMQuery;
	this->srefSupIxVSubrole = srefSupIxVSubrole;
	this->titSupIxVSubrole = titSupIxVSubrole;
	this->stubRefWznmMTable = stubRefWznmMTable;
	this->stubQtbRefWznmMTable = stubQtbRefWznmMTable;
};

bool WznmQQryList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQryList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype);
		extractStringUclc(docctx, basexpath, "titIxVBasetype", "typ2", titIxVBasetype);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "stubSupRefWznmMQuery", "sup", stubSupRefWznmMQuery);
		extractStringUclc(docctx, basexpath, "srefSupIxVSubrole", "srl", srefSupIxVSubrole);
		extractStringUclc(docctx, basexpath, "titSupIxVSubrole", "srl2", titSupIxVSubrole);
		extractStringUclc(docctx, basexpath, "stubRefWznmMTable", "tbl", stubRefWznmMTable);
		extractStringUclc(docctx, basexpath, "stubQtbRefWznmMTable", "qtb", stubQtbRefWznmMTable);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQryList
 ******************************************************************************/

ListWznmQQryList::ListWznmQQryList() {
};

ListWznmQQryList::ListWznmQQryList(
			const ListWznmQQryList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryList(*(src.nodes[i]));
};

ListWznmQQryList& ListWznmQQryList::operator=(
			const ListWznmQQryList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryList(*(src.nodes[i]));

	return *this;
};

ListWznmQQryList::~ListWznmQQryList() {
	clear();
};

void ListWznmQQryList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQryList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQryList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQryList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQryList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQryList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQryList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

