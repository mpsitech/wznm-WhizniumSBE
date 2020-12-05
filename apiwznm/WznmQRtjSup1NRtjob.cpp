/**
	* \file WznmQRtjSup1NRtjob.cpp
	* API code for table TblWznmQRtjSup1NRtjob (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRtjSup1NRtjob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRtjSup1NRtjob
 ******************************************************************************/

WznmQRtjSup1NRtjob::WznmQRtjSup1NRtjob(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQRtjSup1NRtjob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQRtjSup1NRtjob");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQRtjSup1NRtjob
 ******************************************************************************/

ListWznmQRtjSup1NRtjob::ListWznmQRtjSup1NRtjob() {
};

ListWznmQRtjSup1NRtjob::ListWznmQRtjSup1NRtjob(
			const ListWznmQRtjSup1NRtjob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtjSup1NRtjob(*(src.nodes[i]));
};

ListWznmQRtjSup1NRtjob& ListWznmQRtjSup1NRtjob::operator=(
			const ListWznmQRtjSup1NRtjob& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtjSup1NRtjob(*(src.nodes[i]));

	return *this;
};

ListWznmQRtjSup1NRtjob::~ListWznmQRtjSup1NRtjob() {
	clear();
};

void ListWznmQRtjSup1NRtjob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQRtjSup1NRtjob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQRtjSup1NRtjob* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQRtjSup1NRtjob");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQRtjSup1NRtjob", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQRtjSup1NRtjob(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQRtjSup1NRtjob[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

