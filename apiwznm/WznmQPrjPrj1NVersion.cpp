/**
	* \file WznmQPrjPrj1NVersion.cpp
	* API code for table TblWznmQPrjPrj1NVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPrjPrj1NVersion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrjPrj1NVersion
 ******************************************************************************/

WznmQPrjPrj1NVersion::WznmQPrjPrj1NVersion(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQPrjPrj1NVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQPrjPrj1NVersion");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQPrjPrj1NVersion
 ******************************************************************************/

ListWznmQPrjPrj1NVersion::ListWznmQPrjPrj1NVersion() {
};

ListWznmQPrjPrj1NVersion::ListWznmQPrjPrj1NVersion(
			const ListWznmQPrjPrj1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjPrj1NVersion(*(src.nodes[i]));
};

ListWznmQPrjPrj1NVersion& ListWznmQPrjPrj1NVersion::operator=(
			const ListWznmQPrjPrj1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrjPrj1NVersion(*(src.nodes[i]));

	return *this;
};

ListWznmQPrjPrj1NVersion::~ListWznmQPrjPrj1NVersion() {
	clear();
};

void ListWznmQPrjPrj1NVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQPrjPrj1NVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQPrjPrj1NVersion* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQPrjPrj1NVersion");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQPrjPrj1NVersion", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQPrjPrj1NVersion(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQPrjPrj1NVersion[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
