/**
	* \file WznmQQrySup1NQuery.cpp
	* API code for table TblWznmQQrySup1NQuery (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQQrySup1NQuery.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQrySup1NQuery
 ******************************************************************************/

WznmQQrySup1NQuery::WznmQQrySup1NQuery(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQQrySup1NQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQQrySup1NQuery");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQQrySup1NQuery
 ******************************************************************************/

ListWznmQQrySup1NQuery::ListWznmQQrySup1NQuery() {
};

ListWznmQQrySup1NQuery::ListWznmQQrySup1NQuery(
			const ListWznmQQrySup1NQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQrySup1NQuery(*(src.nodes[i]));
};

ListWznmQQrySup1NQuery& ListWznmQQrySup1NQuery::operator=(
			const ListWznmQQrySup1NQuery& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQrySup1NQuery(*(src.nodes[i]));

	return *this;
};

ListWznmQQrySup1NQuery::~ListWznmQQrySup1NQuery() {
	clear();
};

void ListWznmQQrySup1NQuery::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQQrySup1NQuery::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQQrySup1NQuery* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQQrySup1NQuery");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQQrySup1NQuery", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQQrySup1NQuery(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQQrySup1NQuery[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

