/**
	* \file WznmQRtjList.cpp
	* API code for table TblWznmQRtjList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRtjList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRtjList
 ******************************************************************************/

WznmQRtjList::WznmQRtjList(
			const uint jnum
			, const string sref
			, const string stubRefWznmMApp
			, const string stubSupRefWznmMRtjob
			, const string stubRefWznmMJob
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->stubRefWznmMApp = stubRefWznmMApp;
	this->stubSupRefWznmMRtjob = stubSupRefWznmMRtjob;
	this->stubRefWznmMJob = stubRefWznmMJob;
};

bool WznmQRtjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRtjList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWznmMApp", "app", stubRefWznmMApp);
		extractStringUclc(docctx, basexpath, "stubSupRefWznmMRtjob", "sup", stubSupRefWznmMRtjob);
		extractStringUclc(docctx, basexpath, "stubRefWznmMJob", "job", stubRefWznmMJob);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRtjList
 ******************************************************************************/

ListWznmQRtjList::ListWznmQRtjList() {
};

ListWznmQRtjList::ListWznmQRtjList(
			const ListWznmQRtjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtjList(*(src.nodes[i]));
};

ListWznmQRtjList& ListWznmQRtjList::operator=(
			const ListWznmQRtjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtjList(*(src.nodes[i]));

	return *this;
};

ListWznmQRtjList::~ListWznmQRtjList() {
	clear();
};

void ListWznmQRtjList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRtjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRtjList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRtjList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRtjList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRtjList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRtjList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

