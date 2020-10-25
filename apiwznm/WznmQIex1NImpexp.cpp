/**
	* \file WznmQIex1NImpexp.cpp
	* API code for table TblWznmQIex1NImpexp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQIex1NImpexp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQIex1NImpexp
 ******************************************************************************/

WznmQIex1NImpexp::WznmQIex1NImpexp(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQIex1NImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQIex1NImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQIex1NImpexp
 ******************************************************************************/

ListWznmQIex1NImpexp::ListWznmQIex1NImpexp() {
};

ListWznmQIex1NImpexp::ListWznmQIex1NImpexp(
			const ListWznmQIex1NImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIex1NImpexp(*(src.nodes[i]));
};

ListWznmQIex1NImpexp& ListWznmQIex1NImpexp::operator=(
			const ListWznmQIex1NImpexp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIex1NImpexp(*(src.nodes[i]));

	return *this;
};

ListWznmQIex1NImpexp::~ListWznmQIex1NImpexp() {
	clear();
};

void ListWznmQIex1NImpexp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQIex1NImpexp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQIex1NImpexp* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQIex1NImpexp");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQIex1NImpexp", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQIex1NImpexp(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQIex1NImpexp[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

