/**
	* \file WznmQVerVer1NError.cpp
	* API code for table TblWznmQVerVer1NError (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVerVer1NError.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVerVer1NError
 ******************************************************************************/

WznmQVerVer1NError::WznmQVerVer1NError(
			const uint jnum
			, const string stubRef
		) :
			jnum(jnum)
			, stubRef(stubRef)
		{
};

bool WznmQVerVer1NError::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVerVer1NError");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVerVer1NError
 ******************************************************************************/

ListWznmQVerVer1NError::ListWznmQVerVer1NError() {
};

ListWznmQVerVer1NError::ListWznmQVerVer1NError(
			const ListWznmQVerVer1NError& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerVer1NError(*(src.nodes[i]));
};

ListWznmQVerVer1NError& ListWznmQVerVer1NError::operator=(
			const ListWznmQVerVer1NError& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerVer1NError(*(src.nodes[i]));

	return *this;
};

ListWznmQVerVer1NError::~ListWznmQVerVer1NError() {
	clear();
};

void ListWznmQVerVer1NError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVerVer1NError::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVerVer1NError* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVerVer1NError");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVerVer1NError", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVerVer1NError(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVerVer1NError[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
