/**
	* \file WznmQPrjList.cpp
	* API code for table TblWznmQPrjList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPrjList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrjList
 ******************************************************************************/

WznmQPrjList::WznmQPrjList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string Short
			, const string Title
			, const string stubRefWznmMVersion
			, const string Giturl
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->Short = Short;
	this->Title = Title;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->Giturl = Giturl;
};

bool WznmQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "Short", "sho", Short);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWznmMVersion", "ver", stubRefWznmMVersion);
		extractStringUclc(docctx, basexpath, "Giturl", "grl", Giturl);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQPrjList
 ******************************************************************************/

ListWznmQPrjList::ListWznmQPrjList() {
};

ListWznmQPrjList::ListWznmQPrjList(
			const ListWznmQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjList(*(src.nodes[i]));
};

ListWznmQPrjList& ListWznmQPrjList::operator=(
			const ListWznmQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjList(*(src.nodes[i]));

	return *this;
};

ListWznmQPrjList::~ListWznmQPrjList() {
	clear();
};

void ListWznmQPrjList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQPrjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQPrjList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQPrjList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQPrjList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQPrjList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQPrjList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

