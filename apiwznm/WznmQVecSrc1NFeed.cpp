/**
	* \file WznmQVecSrc1NFeed.cpp
	* API code for table TblWznmQVecSrc1NFeed (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQVecSrc1NFeed.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVecSrc1NFeed
 ******************************************************************************/

WznmQVecSrc1NFeed::WznmQVecSrc1NFeed(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WznmQVecSrc1NFeed::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WznmQVecSrc1NFeed");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWznmQVecSrc1NFeed
 ******************************************************************************/

ListWznmQVecSrc1NFeed::ListWznmQVecSrc1NFeed() {
};

ListWznmQVecSrc1NFeed::ListWznmQVecSrc1NFeed(
			const ListWznmQVecSrc1NFeed& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecSrc1NFeed(*(src.nodes[i]));
};

ListWznmQVecSrc1NFeed& ListWznmQVecSrc1NFeed::operator=(
			const ListWznmQVecSrc1NFeed& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecSrc1NFeed(*(src.nodes[i]));

	return *this;
};

ListWznmQVecSrc1NFeed::~ListWznmQVecSrc1NFeed() {
	clear();
};

void ListWznmQVecSrc1NFeed::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWznmQVecSrc1NFeed::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WznmQVecSrc1NFeed* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWznmQVecSrc1NFeed");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WznmQVecSrc1NFeed", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WznmQVecSrc1NFeed(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WznmQVecSrc1NFeed[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

