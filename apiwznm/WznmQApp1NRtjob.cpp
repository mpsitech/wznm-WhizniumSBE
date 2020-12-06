/**
	* \file WznmQApp1NRtjob.cpp
	* API code for table TblWznmQApp1NRtjob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQApp1NRtjob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQApp1NRtjob
 ******************************************************************************/

WznmQApp1NRtjob::WznmQApp1NRtjob(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQApp1NRtjob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQApp1NRtjob");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQApp1NRtjob
 ******************************************************************************/

ListWznmQApp1NRtjob::ListWznmQApp1NRtjob() {
};

ListWznmQApp1NRtjob::ListWznmQApp1NRtjob(
			const ListWznmQApp1NRtjob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQApp1NRtjob(*(src.nodes[i]));
};

ListWznmQApp1NRtjob& ListWznmQApp1NRtjob::operator=(
			const ListWznmQApp1NRtjob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQApp1NRtjob(*(src.nodes[i]));

	return *this;
};

ListWznmQApp1NRtjob::~ListWznmQApp1NRtjob() {
	clear();
};

void ListWznmQApp1NRtjob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQApp1NRtjob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQApp1NRtjob* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQApp1NRtjob");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQApp1NRtjob", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQApp1NRtjob(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQApp1NRtjob[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
