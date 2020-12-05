/**
	* \file WznmQPstList.cpp
	* API code for table TblWznmQPstList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPstList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPstList
 ******************************************************************************/

WznmQPstList::WznmQPstList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubRefWznmMVersion
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const string stubRefUref
			, const string srefIxWznmWArgtype
			, const string titIxWznmWArgtype
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->stubRefUref = stubRefUref;
	this->srefIxWznmWArgtype = srefIxWznmWArgtype;
	this->titIxWznmWArgtype = titIxWznmWArgtype;
};

bool WznmQPstList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQPstList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl);
		extractStringUclc(docctx, basexpath, "titRefIxVTbl", "ret2", titRefIxVTbl);
		extractStringUclc(docctx, basexpath, "stubRefUref", "reu", stubRefUref);
		extractStringUclc(docctx, basexpath, "srefIxWznmWArgtype", "aty", srefIxWznmWArgtype);
		extractStringUclc(docctx, basexpath, "titIxWznmWArgtype", "aty2", titIxWznmWArgtype);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQPstList
 ******************************************************************************/

ListWznmQPstList::ListWznmQPstList() {
};

ListWznmQPstList::ListWznmQPstList(
			const ListWznmQPstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPstList(*(src.nodes[i]));
};

ListWznmQPstList& ListWznmQPstList::operator=(
			const ListWznmQPstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPstList(*(src.nodes[i]));

	return *this;
};

ListWznmQPstList::~ListWznmQPstList() {
	clear();
};

void ListWznmQPstList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQPstList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQPstList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQPstList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQPstList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQPstList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQPstList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

